/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/
/***************************************************************************
 * $Author: karl $
 * $Revision: 1.5 $
 * $Log: CreeCrest.cpp,v $
 * Revision 1.5  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.4  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
 *
 * Revision 1.3  2004/02/06 15:25:14  karl
 * bug not found, comme back to original saveVTK
 *
 * Revision 1.2  2004/02/04 22:39:49  karl
 * debugging (information, fixes, ...)
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:10:05  karl
 * Sources code
 *
 */
//
// Fichier CreeCrest.cpp
//
// Creation d'un fichier crest : centre estim�e des vaisseaux
// A partir d'un ensemble de points par voxel
//

#include "CreeCrest.hpp"

#include "CommonConfigure.h"
COMMON_VAR_IMPORT unsigned char GB_debug;

#ifndef EPSILON
#define EPSILON 1E-2
#endif

/**
  Cr�ation d'un ensemble de lignes dans un fichier '.crest' \\
  � partir d'un ensemble de points par voxel
 */

//=====================================================================
//  MEMBRES PRIVES
//=====================================================================


//---------------------------------------------------------------------
//
TableauDyn<Voisin27> 
CreeCrest :: Voisinage( pt3DReel p1, Point_3D<int> v1 )
//                      ---------
{

  
    TableauDyn<int>   pos_x, pos_y, pos_z;
    TableauDyn<Voisin27> liste_voisins1;
    int               i,j,k;

  // Recherche du voisinage de v1 qui touche le point p1
  pos_x += 0;
  Si fabs((p1.x-v1.x)-1) < EPSILON Alors
    Si v1.x < _image->_tx-1 AlorsFait pos_x += 1;
  Autrement
  Si fabs(p1.x-v1.x) < EPSILON Alors
    Si v1.x > 0 AlorsFait pos_x += -1;
  FinSi

  pos_y += 0;
  Si fabs((p1.y-v1.y)-1) < EPSILON Alors
    Si v1.y < _image->_ty-1 AlorsFait pos_y += 1;
  Autrement
  Si fabs(p1.y-v1.y) < EPSILON Alors
    Si v1.y > 0 AlorsFait pos_y += -1;
  FinSi

  pos_z += 0;
  Si fabs((p1.z-v1.z)-1) < EPSILON Alors
    Si v1.z < _image->_tz-1 AlorsFait pos_z += 1;
  Autrement
  Si fabs(p1.z-v1.z) < EPSILON Alors
    Si v1.z > 0 AlorsFait pos_z += -1;
  FinSi

  Pour(i,0,pos_x.NbElts()-1)
  Pour(j,0,pos_y.NbElts()-1)
  Pour(k,0,pos_z.NbElts()-1)
    liste_voisins1 += Voisin27(pos_x[i],pos_y[j],pos_z[k]);
  FinPour
  FinPour
  FinPour

  return liste_voisins1;

} // Voisinage()


//---------------------------------------------------------------------
//
unsigned char CreeCrest :: Voisinage_p1( TableauDyn<Voisin27> voisins,
//                              ------------
                         pt3DReel p1, Point_3D<int> v1, 
                         pt3DReel&              pt_proche,
                         pt3DReel&              pt_suivant,
                         Point_3D<int>&      voxel_suivant  )
{
 
  
    int               num_voisin; // numero du voisin de v1
                                     // contenant p1 et seulement 2 points
                                     // s'il existe et est unique
    tab_points           liste;
    pt3DReel             p2,p3;
//    TableauDyn<Voisin27> voisins2;
    int               i;
    int               j;
    int               n;
    int               point_a_supprimer=-1;
    Point_3D<int>     voxel;

  num_voisin = 0;
  i = 0;
  j = 0;

//  printf("Parcours des voisins\n");
  Pour( i, 0, voisins.NbElts()-1)

    voxel.x = v1.x + voisins[i].X();
    voxel.y = v1.y + voisins[i].Y();
    voxel.z = v1.z + voisins[i].Z();

//  printf("\t (%d %d %d)\n",voxel.x,voxel.y,voxel.z);
    n = (int) ((*_image)(voxel.x,voxel.y,voxel.z));
     Si n== NB_LISTES_MAX AlorsFait continue;

    liste = ListePoints( voxel.x, voxel.y, voxel.z);

    Pour( j, 0, liste.NbElts()-1 )

      p2 = liste[j];
//    printf("\t\t point (%f %f %f)\n",p2.x,p2.y,p2.z);
 
     // Si on traite le voxel v1 alors on passe au voisin suivant
      Si v1==voxel Alors
    // retrait de tous les points tres proches de p1, incluant p1 ?
        Si p1.ProcheDe( p2, 1E-10) AlorsFait
          ListePoints( voxel.x, voxel.y, voxel.z).Supprime(j);
        continue;
      FinSi

      Si p1.ProcheDe( p2,(float) EPSILON) Alors

        // On enleve p2 de la liste des points du voxel trouv�
        //
      //      printf("Voisinage_P1, suppression du point");
      //  printf("(%f %f %f) du voxel (%d %d %d)\n",
      //           p2.x,p2.y,p2.z,voxel.x,voxel.y,voxel.z);

        Si liste.NbElts() == 1 AlorsFait
          ListePoints( voxel.x, voxel.y, voxel.z).Supprime(j);

//        voisins2 += voisins[i];

        Si liste.NbElts() == 2 Alors
          Si num_voisin == 0 Alors
            num_voisin    = 1;
            pt_proche  = p2; 
            pt_suivant = liste[1-j]; 
            voxel_suivant = voxel;
            point_a_supprimer = j;
          Sinon
            num_voisin = 2;
          FinSi
        FinSi
        break;
      FinSi

    FinPour // j

  FinPour // i

  Si num_voisin == 1 Alors
    ListePoints( voxel_suivant.x, voxel_suivant.y, voxel_suivant.z).
      Supprime( point_a_supprimer);
  FinSi

  return (num_voisin == 1);

} // Voisinage_p1


//---------------------------------------------------------------------
//
void CreeCrest :: ProlongeDebut( LigneCrest& ligne, pt3DReel p1, 
//                         -------------
                      Point_3D<int> v1 )
{

  
    TableauDyn<Voisin27> liste_voisins1;
    pt3DReel             point_proche; // point
                                       // proche de p1 dans la liste des points
                                       // du voxel trouve
    pt3DReel             point_suivant;
    Point_3D<int>     voxel_suivant;
    Point_3D<int>     voxel;
    Point3D              pt;

if ((fabs(p1.x-v1.x)>1)||(fabs(p1.y-v1.y)>1)||(fabs(p1.z-v1.z)>1))
printf("ProlongeDebut() %d (%d,%d,%d) (%f %f %f)\n",_CREST_tab_points.NbElts()-1,v1.x,v1.y,v1.z,
     p1.x,p1.y,p1.z);
  // Recherche du voisinage de v1 qui touche le point p1
  liste_voisins1 = Voisinage( p1, v1);

  // Recherche dans cette liste des voxels contenant un point proche de p1

  Si Voisinage_p1( liste_voisins1, p1, v1,
           point_proche, point_suivant, voxel_suivant)
  Alors
  // Il existe un unique voxel dans le voisinage de v1 contenant
  // 2 points dont un est proche de p1
    ProlongeDebut( ligne, point_suivant, voxel_suivant);

    pt.x        = ( p1.x + point_proche.x ) / 2.0;
    pt.y        = ( p1.y + point_proche.y ) / 2.0;
    pt.z        = ( p1.z + point_proche.z ) / 2.0;
    pt.rayon    = ( p1.rayon + point_proche.rayon) / 2.0;
    pt.proba    = ( p1.proba + point_proche.proba) / 2.0;
    pt.nb_liens = 1;

  Sinon
  // 
    pt.x        = p1.x;
    pt.y        = p1.y;
    pt.z        = p1.z;
    pt.rayon    = p1.rayon;
    pt.proba    = p1.proba;
    pt.nb_liens = 1;

  FinSi  

  Crest::AddPoint(pt);
  ligne.liste_points += _CREST_tab_points.NbElts()-1;
  ligne.nb_points++;

  _image_lignes->BufferPos( v1.x, v1.y, v1.z);
  _image_lignes->FixeValeur( _CREST_tab_lignes.NbElts() );

} // ProlongeDebut()


//---------------------------------------------------------------------
//
void CreeCrest :: ProlongeFin( LigneCrest& ligne, pt3DReel p1, 
//                         -------------
                      Point_3D<int> v1 )
{

  
    TableauDyn<Voisin27> liste_voisins1;
    pt3DReel             point_proche; // point
                                       // proche de p1 dans la liste des points
                                       // du voxel trouve
    pt3DReel             point_suivant;
    Point_3D<int>     voxel_suivant;
    Point_3D<int>     voxel;
    Point3D              pt;

if ((fabs(p1.x-v1.x)>1)||(fabs(p1.y-v1.y)>1)||(fabs(p1.z-v1.z)>1))
printf("ProlongeFin() %d (%d,%d,%d) (%f %f %f)\n",_CREST_tab_points.NbElts()-1,v1.x,v1.y,v1.z,
     p1.x,p1.y,p1.z);

//  printf("ProlongeFin() (%d,%d,%d) (%f %f %f)\n",v1.x,v1.y,v1.z,
//   p1.x,p1.y,p1.z);
  // Recherche du voisinage de v1 qui touche le point p1
  liste_voisins1 = Voisinage( p1, v1);

  // Recherche dans cette liste des voxels contenant un point proche de p1

  Si Voisinage_p1( liste_voisins1, p1, v1,
           point_proche, point_suivant, voxel_suivant)
  Alors
  // Il existe un unique voxel dans le voisinage de v1 contenant
  // 2 points dont un est proche de p1

    pt.x        = ( p1.x + point_proche.x ) / 2.0;
    pt.y        = ( p1.y + point_proche.y ) / 2.0;
    pt.z        = ( p1.z + point_proche.z ) / 2.0;
    pt.rayon    = ( p1.rayon + point_proche.rayon) / 2.0;
    pt.proba    = ( p1.proba + point_proche.proba) / 2.0;
    pt.nb_liens = 1;

    Crest::AddPoint(pt);
    ligne.liste_points += _CREST_tab_points.NbElts()-1;
    ligne.nb_points++;

    _image_lignes->BufferPos( v1.x, v1.y, v1.z);
    _image_lignes->FixeValeur( _CREST_tab_lignes.NbElts() );

    ProlongeFin( ligne, point_suivant, voxel_suivant);

  Sinon
  // 
    pt.x        = p1.x;
    pt.y        = p1.y;
    pt.z        = p1.z;
    pt.rayon    = p1.rayon;
    pt.proba    = p1.proba;
    pt.nb_liens = 1;

    Crest::AddPoint(pt);
    ligne.liste_points += _CREST_tab_points.NbElts()-1;
    ligne.nb_points++;

    _image_lignes->BufferPos( v1.x, v1.y, v1.z);
    _image_lignes->FixeValeur( _CREST_tab_lignes.NbElts() );

  FinSi  

} // ProlongeFin()




//---------------------------------------------------------------------
//
void CreeCrest :: ConnecteLignes()
//                         --------------
{

  
    int               x,y,z;
    int               n;
    tab_points           liste;
    Point_3D<int>     voxel;
    int               i, j;
    TableauDyn<Voisin27> liste_voisins;

    int               ligne, ligne1, ligne2;
    TableauDyn<int>   lignes_connectees;
    TableauDyn<int>   extremites_a_connecter;

    Point3D              p1,p2;
    pt3DReel             pt1,pt2;

  i = j = 0;

  // Traitement des points a plus que 2  intersections
  // Traitement des points a 2 intersections
  Pour( x, 0, _image->_tx-1 )
  Pour( y, 0, _image->_ty-1 )
  Pour( z, 0, _image->_tz-1 )

    _image->BufferPos(x,y,z);
    n = (int) ((*_image)(x,y,z));
    Si n!= NB_LISTES_MAX Alors

      liste =  ListePoints(x,y,z);

      // Si un voxel a plusieurs points connect�s � des lignes
      // alors on peut 
      //   - soit connecter deux lignes
      //   - soit creer une jonction


      Si liste.NbElts() > 2 Alors

        lignes_connectees.VideTableau();
        extremites_a_connecter.VideTableau();

        Si GB_debug AlorsFait 
      fprintf(stderr, "CreeCrest::ConnecteLignes() trying for voxel (%d %d %d) with %d  points<\n",
          x,y,z,liste.NbElts());

        // Parcours des points du voxel
        Pour( i, 0, liste.NbElts()-1)

          Si GB_debug AlorsFait fprintf(stderr, " point number %d : \n",i); fflush(stderr);

          voxel.Init( x, y, z);
          liste_voisins = Voisinage( liste[i], voxel);

          // Parcours des voxels voisins du point courant
          Pour( j, 0, liste_voisins.NbElts() - 1)

            voxel.x = x + liste_voisins[j].X();
            voxel.y = y + liste_voisins[j].Y();
            voxel.z = z + liste_voisins[j].Z();

            ligne = (int) ((*_image_lignes)( voxel.x, voxel.y, voxel.z));

            Si ligne!= NB_LIGNES_MAX Et NbPoints(ligne)>=2 Alors

              Si GB_debug AlorsFait 
                fprintf(stderr, "  found neighbor within a line\n");

              p1 = Point( ligne, 0);
              p2 = Point( ligne, NbPoints(ligne) - 1);

              pt1.Init( p1.x, p1.y, p1.z);
              pt2.Init( p2.x, p2.y, p2.z);

              // connect to the closest first ...
              double dist1 = Norme(liste[i]-pt1);
              double dist2 = Norme(liste[i]-pt2);

              Si (dist1<dist2) Et (dist1<EPSILON) Et
                 Non(lignes_connectees.Existe(ligne))
              Alors
                lignes_connectees      += ligne;
                extremites_a_connecter += 0;
                Si GB_debug AlorsFait 
                  fprintf(stderr, " connection ext 0 \n");
              Autrement
              Si (dist2<dist1) Et (dist2<EPSILON) Et
                 Non(lignes_connectees.Existe(ligne))
              Alors
                lignes_connectees      += ligne;
                extremites_a_connecter += NbPoints(ligne) - 1;
                Si GB_debug AlorsFait 
                  fprintf(stderr, " connection ext 1 \n");
              FinSi

            FinSi

          FinPour // j

        FinPour // i


        Si lignes_connectees.NbElts() == 2 Alors

          Si GB_debug AlorsFait fprintf(stderr, "CreeCrest::ConnecteLignes() regroupe lignes \n");

      // On regroupe les 2 lignes par le segment trouve
          ligne1 = lignes_connectees[0];
          ligne2 = lignes_connectees[1];

          Si extremites_a_connecter[0] == 0 Alors
            ReOrienteLigne( ligne1 );
          FinSi

          Si extremites_a_connecter[1] != 0 Alors
            ReOrienteLigne( ligne2 );
          FinSi

      _CREST_tab_lignes[ligne1].liste_points += NumPoint( ligne2, 0);
          _CREST_tab_lignes[ligne1].nb_points++;

          RegroupeLignes( ligne1, ligne2 );

      /*
          p1 = Point( lignes_connectees[0], extremites_a_connecter[0]);

          pt1.Init( p1.x, p1.y, p1.z);

          AjouteSegment( pt1, pt2);
      */

        FinSi


        Si lignes_connectees.NbElts() > 2 Alors

        Si GB_debug AlorsFait fprintf(stderr, "CreeCrest::ConnecteLignes()  %d \n",lignes_connectees.NbElts());

          p1 = Point( lignes_connectees[0], extremites_a_connecter[0]);
          Pour( i, 1, lignes_connectees.NbElts() - 1)
            p2 = Point( lignes_connectees[i], extremites_a_connecter[i]);

            pt1.Init( p1.x, p1.y, p1.z);
            pt2.Init( p2.x, p2.y, p2.z);

            AjouteSegment( pt1, pt2);

          FinPour

        FinSi

      FinSi
    FinSi

  FinPour
  FinPour
  FinPour

} // ConnecteLignes()

      /*
//---------------------------------------------------------------------
//
void CreeCrest :: ReOrienteLigne( int l)
//                         --------------
{

  
    int              i,taille;
    TableauDyn<int>  liste_pts;

  taille =  NbPoints(l);
  Pour( i, 0, taille-1)    
    liste_pts += _CREST_tab_lignes[l].liste_points[ taille-1-i];
  FinPour

  Pour( i, 0, taille-1)    
   _CREST_tab_lignes[l].liste_points[i] = liste_pts[i];
  FinPour

} // ReOrienteLigne()
      */

//---------------------------------------------------------------------
//
void CreeCrest :: RegroupeLignes( int l1, int l2)
//                         --------------
{

  
    int              j,taille1, taille2;
    Point3D             p1,p2,p3,p4;
    pt3DReel            pt1,pt2,pt3,pt4;
    int              x,y,z;
    int              x1,y1,z1;

  taille1 = NbPoints(l1);
  taille2 = NbPoints(l2);

  p1 = Point( l1, 0           );
  p2 = Point( l1, taille1 - 1 );
  p3 = Point( l2, 0           );
  p4 = Point( l2, taille2 - 1 );

  pt1.Init( p1.x, p1.y, p1.z);
  pt2.Init( p2.x, p2.y, p2.z);
  pt3.Init( p3.x, p3.y, p3.z);
  pt4.Init( p4.x, p4.y, p4.z);

  Si Non(pt2.ProcheDe( pt3, EPSILON )) Alors
    Si pt2.ProcheDe( pt4, EPSILON) Alors
      ReOrienteLigne( l2);
    Autrement
    Si pt1.ProcheDe( pt3, EPSILON) Alors
      ReOrienteLigne( l1);
    Autrement
    Si pt1.ProcheDe( pt4, EPSILON) Alors
      ReOrienteLigne( l1);
      ReOrienteLigne( l2);
    Sinon
      fprintf(stderr, "CreeCrest::RegroupeLignes() \t WARNING, les 2 lignes ne sont pas proches\n");
      return;
    FinSi
  FinSi

  Pour( j, 1, taille2-1)

    _CREST_tab_lignes[l1].liste_points += NumPoint( l2, j);
    _CREST_tab_lignes[l1].nb_points++;

    p1 =  Point( l2, j);
    x = (int) p1.x;   y = (int) p1.y;    z = (int) p1.z;

#ifndef macro_min
  #define macro_min(n1,n2) ((n1)<(n2)?(n1):(n2))
#endif

#ifndef macro_max
  #define macro_max(n1,n2) ((n1)>(n2)?(n1):(n2))
#endif 

    Pour( x1, macro_max(0,(x-1)), macro_min((x+1),(_image_lignes->_tx-1)) )
    Pour( y1, macro_max(0,(y-1)), macro_min((y+1),(_image_lignes->_ty-1)) )
    Pour( z1, macro_max(0,(z-1)), macro_min((z+1),(_image_lignes->_tz-1)) )
      Si (*_image_lignes)(x1,y1,z1) == l2 Alors
        _image_lignes->BufferPos(x1,y1,z1);
        _image_lignes->FixeValeur( l1);
      FinSi
    FinPour
    FinPour
    FinPour

  FinPour

  _CREST_tab_lignes[l2].nb_points = 0;
  _CREST_tab_lignes[l2].liste_points.VideTableau();

} // RegroupeLignes()


//=====================================================================
//  MEMBRES PUBLICS
//=====================================================================

//---------------------------------------------------------------------
//
CreeCrest ::  CreeCrest( int tx, int ty, int tz) : Crest()
//
{

  
    int x,y,z;
    tab_points* liste;

  this->_image  = new InrImage( tx, ty, tz, WT_UNSIGNED_INT);
  _image_lignes = new InrImage( tx, ty, tz, WT_UNSIGNED_INT);

  Pour(x,0,tx-1)
  Pour(y,0,ty-1)
  Pour(z,0,tz-1)

    this->_image->BufferPos(x,y,z);
    this->_image->FixeValeur( NB_LISTES_MAX );

    _image_lignes->BufferPos(x,y,z);
    _image_lignes->FixeValeur( NB_LIGNES_MAX );

  FinPour
  FinPour
  FinPour

  // On met le premier elt de _tab_liste_points 
  // comme etant une liste vide
  liste = new tab_points;
  _tab_liste_points += (*liste);
  delete liste;

} // Constructor


//---------------------------------------------------------------------
///
CreeCrest :: ~CreeCrest()
//
{

  delete _image;
  delete _image_lignes;

} // Destructor


//---------------------------------------------------------------------
/**
  Ajoute au voxel (x,y,z) le point pt
 // Si il n'y a pas de liste au point (x,y,z),
 // cree une nouvelle liste
 // Verifie qu'il n'y a pas d'autre point très proche 
 // déjà dans ce voxel
 */
void CreeCrest :: AddPoint( int x, int y, int z, pt3DReel pt )
//                          --------
{

    tab_points* liste;
    tab_points  liste1;
    int      k,point_existe;


  if ((fabs(pt.x-x)>1.01)||(fabs(pt.y-y)>1.01)||(fabs(pt.z-z)>1.01))
  printf("AddPoint() (%d,%d,%d) (%f %f %f)\n",x,y,z,
     pt.x,pt.y,pt.z);


  if (_tab_liste_points.NbElts()>=NB_LISTES_MAX-1)  
    fprintf(stderr,"Too Many Points...\n");

  Si ((int)(*_image)(x,y,z) == NB_LISTES_MAX) Alors
    // Cr�ation d'une nouvelle liste
    liste = new tab_points;
    _tab_liste_points += (*liste);
    delete liste;

    // Ajout de cette liste
    _image->BufferPos(x,y,z);
    _image->FixeValeur( _tab_liste_points.NbElts()-1 );
  FinSi

  liste1 = ListePoints(x,y,z);
  point_existe = false;
  k = 0;
  TantQue (k < liste1.NbElts())Et(Non(point_existe)) Faire
    point_existe = liste1[k].ProcheDe( pt, 0.01);
    k++;
  FinTantQue

  Si Non(point_existe) Alors
     ListePoints(x,y,z) += pt;
  Sinon
    fprintf(stderr,"CreeCrest::AddPoint(%d,%d,%d,..) another point close exists \n",x,y,z);
  FinSi
  

} // AddPoint()

  
//---------------------------------------------------------------------
/**
  Tableau des points associ�s au voxel (x,y,z)
 */
tab_points& CreeCrest ::  ListePoints( int x, 
//                                               -----------
                         int y, int z)
{

   
    int n;

  n = (int) ((*_image)(x,y,z));

  Si (n<0) Ou (n>=_tab_liste_points.NbElts()) Alors
    fprintf(stderr,"ListePoints(x,y,z)\n erreur indice incorrect\n");
    return _tab_liste_points[0];
  FinSi
  
  return _tab_liste_points[ n];

} // ListePoints()


//---------------------------------------------------------------------
/**
  Cree les lignes pour les voxels ayant 2 points
 */
void  CreeCrest :: CreeLignes()
//                           ----------
{

  
    int               x,y,z;
    int               n;
    tab_points           liste;
    Point_3D<int>     voxel;
    int count[7];
    int i;

for(i=0;i<7;i++) count[i]=0;

  // Traitement des points a 2 intersections
  Pour( x, 0, _image->_tx-1 )
  Pour( y, 0, _image->_ty-1 )
  Pour( z, 0, _image->_tz-1 )
    _image->BufferPos(x,y,z);
    n = (int) ((*_image)(x,y,z));
    Si n!= NB_LISTES_MAX Alors

      liste =  ListePoints(x,y,z);
      count[liste.NbElts()]++;


      Si liste.NbElts() == 2 Alors
        voxel.Init( x, y, z);
        Si GB_debug AlorsFait fprintf(stderr,"AjouteLigne %d %d %d\n",x,y,z);
//        scanf("%d",&n);
        AjouteLigne( liste[0], liste[1], voxel);
      FinSi

      Si liste.NbElts() > 2 Alors
         Si GB_debug AlorsFait fprintf(stderr," more than 3 points at %d %d %d\n",x,y,z);
        int k;
        for(k=0;k<liste.NbElts();k++) 
            Si GB_debug AlorsFait 
                fprintf(stderr,"point  %3.3f %3.3f %3.3f \n",liste[k].x, liste[k].y, liste[k].z);
      FinSi

    FinSi
  FinPour
  FinPour
  FinPour

  // Traitement des points a + que 2 intersections
  Pour( x, 0, _image->_tx-1 )
  Pour( y, 0, _image->_ty-1 )
  Pour( z, 0, _image->_tz-1 )
    _image->BufferPos(x,y,z);
    n = (int) ((*_image)(x,y,z));
    Si n!= NB_LISTES_MAX Alors

      liste =  ListePoints(x,y,z);

      Si liste.NbElts() > 2 Alors
         Si GB_debug AlorsFait fprintf(stderr,"trying to connect between %d points\n",liste.NbElts());
        // connect only points having existing lines ? or non-endpoints?
        int k,l;
        double dist;
        for(k=0;k<liste.NbElts();k++) 
            for(l=k+1;l<liste.NbElts();l++) {
            dist = Norme(liste[k]-liste[l]);
             Si GB_debug AlorsFait fprintf(stderr,"dist = %3.3f \n",dist);
            if (dist<0.05) {
                //voxel.Init( x, y, z);
                Si GB_debug AlorsFait fprintf(stderr," A unifier  %3.3f %3.3f %3.3f et %3.3f %3.3f %3.3f\n",
                liste[0].x,liste[0].y,liste[0].z,
                liste[1].x,liste[1].y,liste[1].z);
                //AjouteLigne( liste[0], liste[1], voxel);
            }
        }
      FinSi

    FinSi
  FinPour
  FinPour
  FinPour

      //  Si GB_debug Alors
      fprintf(stderr, "Statiques du nombre de points \n");
        for(i=0;i<7;i++)
          fprintf(stderr,"nb voxels with %d points : %d \n",i,count[i]);
//  FinSi
      fprintf(stderr,"CreeLignes() NbPoints %d \n",NbPoints());
  Si GB_debug AlorsFait fprintf(stderr, "CreeLignes() \t ConnecteLignes() \n");
  ConnecteLignes();
  fprintf(stderr,"CreeLignes() NbPoints %d \n",NbPoints());

} // CreeLignes()


//---------------------------------------------------------------------
/**
    Ajoute un segment constitu� des points p1 et p2
 */
void  CreeCrest :: AjouteSegment( pt3DReel& p1, pt3DReel& p2 )
//                           -------------
{

  
    LigneCrest  ligne_crest;
    Point3D     pt;       
    int      pos1, pos2;

  pt.x        = p1.x;
  pt.y        = p1.y;
  pt.z        = p1.z;
  pt.rayon    = p1.rayon;
  pt.proba    = p1.proba;
  pt.nb_liens = 1;

  pos1 = _CREST_tab_points.NbElts();
  Crest::AddPoint(pt);

  pt.x        = p2.x;
  pt.y        = p2.y;
  pt.z        = p2.z;
  pt.rayon    = p2.rayon;
  pt.proba    = p1.proba;
  pt.nb_liens = 1;

  pos2 = _CREST_tab_points.NbElts();
  Crest::AddPoint( pt);

  ligne_crest.liste_points += pos1;
  ligne_crest.liste_points += pos2;
  ligne_crest.nb_points+=2;

  _CREST_tab_lignes += ligne_crest;

} // AjouteSegment()


//---------------------------------------------------------------------
/**
    Ajoute une ligne constitu�e des points p1 et p2
 */
void  CreeCrest :: AjouteLigne( pt3DReel& p1, pt3DReel& p2, 
//                           -----------
                      Point_3D<int> voxel)
{

  
    LigneCrest  ligne_crest;

  Si GB_debug AlorsFait fprintf(stderr,"AjouteLigne begin \n");

/*
    Point3D     pt;       
    int      pos1, pos2;

  pt.x        = p1.x;
  pt.y        = p1.y;
  pt.z        = p1.z;
  pt.nb_liens = 1;

  pos1 = _CREST_tab_points.NbElts();
  _CREST_tab_points += pt;

  pt.x        = p2.x;
  pt.y        = p2.y;
  pt.z        = p2.z;
  pt.nb_liens = 1;

  pos2 = _CREST_tab_points.NbElts();
  _CREST_tab_points += pt;

  ligne_crest.liste_points += pos1;
  ligne_crest.liste_points += pos2;
  ligne_crest.nb_points+=2;
*/

  // Pour gerer les doublons, 
  // Si cette ligne existe dans plusieurs voxels, on
  // la rend unique


//printf("AjouteLigne()  (%f %f %f) (%f %f %f) (%d,%d,%d) \n",
//       p1.x,p1.y,p1.z,
//       p2.x,p2.y,p2.z,
//       voxel.x,voxel.y,voxel.z
//   );

  ProlongeDebut( ligne_crest, p1, voxel);
  ProlongeFin( ligne_crest, p2, voxel);


  _CREST_tab_lignes += ligne_crest;

  Si GB_debug AlorsFait fprintf(stderr,"AjouteLigne end \n");

} // AjouteLigne()
