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
 * $Revision: 1.10 $ 
 * $Log: Crest.cpp,v $
 * Revision 1.10  2005/12/19 19:41:34  karl
 * Fluid project visualization
 *
 * Revision 1.9  2005/11/16 17:46:36  karl
 * fixed pbs
 *
 * Revision 1.8  2005/11/16 15:46:42  karl
 * vtkFloatingType
 *
 * Revision 1.7  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.6  2005/08/08 17:29:56  karl
 * few changes in Crest and inrimage
 *
 * Revision 1.5  2005/04/04 05:05:30  karl
 * Improving Skeletonization: better line connextion and avoiding some local loops
 *
 * Revision 1.4  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
 *
 * Revision 1.3  2004/02/06 15:34:03  karl
 * *** empty log message ***
 *
 * Revision 1.2  2004/02/06 15:25:14  karl
 * bug not found, comme back to original saveVTK
 *
 * Revision 1.1.1.1  2003/08/14 07:16:03  karl
 * Source code
 *
 * Revision 1.1.1.1  2000/04/07 16:10:04  karl
 * Sources code
 *
 */
//
// fichier Crest.cpp
//
// Karl KRISSIAN 
//
// Sophia Antipolis le 02-09-97
//


#ifndef _WITHOUT_VTK_

#include "vtkPoints.h"
#include "vtkPolyData.h"
#include "vtkPointData.h"
#include "vtkPolyDataWriter.h"
#include "vtkCellArray.h"
#include "vtkPolyDataReader.h"

#endif // _WITHOUT_VTK_


#include "Crest.hpp"

#ifdef _use_vrml97_
#include "SceneGraph.h"
#endif

#include "StringUtils.hpp"

LigneCrest Crest::_lignecrest_defaut;



//==========================================================================
// MEMBRES PRIVES
//==========================================================================

//--------------------------------------------------------------------------
unsigned char Crest ::  AlloueCrest( )
//                         -----------
{

  
    FILE*   fichier;
    char c;
    int  i,j;    // indices pour les boucles
    int  longueur; // longueur en nb de points d'une ligne
    Point3D pt;       
    int  pos;      // indice d'un point dans le tableau de points
    float    tmp;
    LigneCrest  ligne_crest;
    int  n,nb_points,nb_lignes;

  Si CheckEndString( _CREST_nom_image, ".corr") AlorsFait
    return ReadJulio(_CREST_nom_image);

  Si CheckEndString(_CREST_nom_image,".wrl") AlorsFait
    return ReadVRML(_CREST_nom_image);

#ifndef _WITHOUT_VTK_
  Si CheckEndString(_CREST_nom_image,".vtk") AlorsFait
    return ReadVTK(_CREST_nom_image);
#endif // _WITHOUT_VTK_

  fichier = fopen( _CREST_nom_image, "r");
  Si fichier == NULL Alors
    printf(" Erreur dans l'ouverture du fichier de parametres %s \n"
           , _CREST_nom_image);
    return false;
  FinSi

  //---------------------------------------------
  //----- Calcul du nombre de lignes  
  //---------------------------------------------

  //----- Debut
  fscanf( fichier, "%c\n", &c);
  Si c != '(' Alors
    printf("erreur \n");
  FinSi
  nb_lignes = 0;
  nb_points = 0;

  fscanf( fichier, "%c\n", &c);
  TantQue c=='(' Faire

    nb_lignes++;
    fscanf( fichier, "%c", &c);
    TantQue c == 'O' Faire
      nb_points++;
      fscanf( fichier, "4 ");
      fscanf( fichier, "%f %f %f\n", &pt.x, &pt.y, &pt.z);
      fscanf( fichier, "%f %f %f\n",&pt.rayon,
                                &pt.proba,
                                &pt.jonction);
      fscanf( fichier, "%f %f %f\n",&pt.vecteur.x,&pt.vecteur.y,&pt.vecteur.z);
      fscanf( fichier, "%f %f %f\n",&tmp,&tmp,&tmp);
      fscanf( fichier, "%c", &c);
    FinTantQue
    fscanf( fichier, "\n");

    fscanf( fichier, "%c\n", &c);
  FinTantQue

  printf( "nb de ligne %d \n", nb_lignes);

  //----- Fin
  //  fscanf( fichier, "\n");

  //---------------------------------------------
  //----- Calcul du nombre de points par ligne  
  //---------------------------------------------
  rewind(fichier);

  _CREST_tab_points.Resize(nb_points);
  _CREST_tab_lignes.Resize(nb_lignes);

  //----- Debut
  fscanf( fichier, "(\n");

  Pour( i, 0, nb_lignes-1)

    fscanf( fichier, "(\n");

    longueur = 0;

    fscanf( fichier, "%c", &c);
    TantQue c == 'O' Faire
      longueur++;
      fscanf( fichier, "4 ");
      fscanf( fichier, "%f %f %f\n", &pt.x, &pt.y, &pt.z);
      fscanf( fichier, "%f %f %f\n",&pt.rayon, &pt.proba, &pt.jonction);
      fscanf( fichier, "%f %f %f\n",&pt.vecteur.x,&pt.vecteur.y,&pt.vecteur.z);
      fscanf( fichier, "%f %f %f\n",&tmp,&tmp,&tmp);
      fscanf( fichier, "%c", &c);
    FinTantQue
    //    printf(" %d %d \t",i,longueur);   
    //    fflush(stdout);
    ligne_crest.nb_points = longueur;
    ligne_crest.liste_points.VideTableau();
    ligne_crest.liste_points.Resize(longueur);

    _CREST_tab_lignes += ligne_crest;

    fscanf( fichier, "\n");
  FinPour

  printf("nb points par lignes OK\n");
  //---------------------------------------------
  //----- Memorisation des points
  //---------------------------------------------
  rewind(fichier);

  nb_points = 0;

  //----- Debut
  fscanf( fichier, "(\n");

  Pour( i, 0, NbLignes()-1)

    fscanf( fichier, "(\n");

    longueur = 0;

    Pour( j, 0, _CREST_tab_lignes[i].nb_points -1)
      fscanf( fichier, "O4 ");
      fscanf( fichier, "%f %f %f\n", &pt.x, &pt.y, &pt.z);
      fscanf( fichier, "%f %f %f\n",&pt.rayon,&pt.proba,&pt.jonction);
      fscanf( fichier, "%f %f %f\n",&pt.vecteur.x,&pt.vecteur.y,&pt.vecteur.z);
      fscanf( fichier, "%f %f %f\n",&tmp,&tmp,&tmp);

      // Ajout d'un point dans le tableau de points
      pos = -1;
/* Pour l'instant, la variable nb_liens ne sert a rien et
   ralentie considerablement la lecture ...
*/
      Pour( n, 0, NbPoints() - 1)
        Si _CREST_tab_points[n] == pt Alors
          pos = n;
        FinSi
      FinPour // n


      Si pos == -1 Alors
        // le point n'existe pas
        pos = NbPoints();
        _CREST_tab_points += pt;
        _CREST_tab_points[pos].nb_liens = 1;
      Sinon
        _CREST_tab_points[pos].nb_liens++;
      FinSi

      _CREST_tab_lignes[i].liste_points += pos;

    FinPour // j

    fscanf( fichier, ")\n");
//      Si verbose Alors
        Si i > 0 Alors 
          printf("\b\b\b\b\b");
        Sinon
          printf("Lecture de la ligne : ");
        FinSi
        printf("%5d",i); 
        fflush(stdout);
//      FinSi
//    Si i%100 == 0 AlorsFait
//      cout << "ligne " << i+1 << " / " << _nb_lignes << endl;
  FinPour // i

  //---------------------------------------------
  //----- Fermeture du fichier
  //---------------------------------------------
  printf("Fichier %s lu \n", _CREST_nom_image);

  fclose(fichier);

//  Pour(i, 0, _nb_points-1)
//    Si _CREST_tab_points[i].nb_liens > 1 Alors
//      printf("Jonction point %d avec %d liens\n",i,_CREST_tab_points[i].nb_liens);
//    FinSi
//  FinPour

  return true;

} // AlloueCrest()


//---------------------------------------------------------------------------
void Crest ::  AlloueLissage( )
//                      -------------
{

  
    int      i,j;
    LigneCrest  ligne_crest;

  _LISSE_tab_points.Resize(NbPoints());
  _LISSE_tab_lignes.Resize(NbLignes());

  Pour( i, 0, NbPoints()-1)
    _LISSE_tab_points += _CREST_tab_points[i];
  FinPour // i

  Pour( i, 0, NbLignes()-1)
    ligne_crest.nb_points = _CREST_tab_lignes[i].nb_points;
    ligne_crest.liste_points.VideTableau();
    ligne_crest.liste_points.Resize( ligne_crest.nb_points);
    Pour( j, 0, _CREST_tab_lignes[i].nb_points -1)
      ligne_crest.liste_points += _CREST_tab_lignes[i].liste_points[j];
    FinPour // j

    _LISSE_tab_lignes += ligne_crest;

  FinPour // i

  _lissage_alloue = true;

} // AlloueLissage()


//---------------------------------------------------------------------------
void Crest ::  LibereCrest( )
//                      -----------
{

//  
//    int i;

//  Pour( i, 0, _nb_lignes-1)
//    delete[] _CREST_tab_lignes[i].liste_points;
//  FinPour // i

} // LibereCrest()


//---------------------------------------------------------------------------
void Crest ::  LibereLissage( )
//                      -------------
{

//  
//    int i;

//  Pour( i, 0, _nb_lignes-1)
//    delete[] _LISSE_tab_lignes[i].liste_points;
//  FinPour // i

} // LibereLissage()


//==========================================================================
// MEMBRES PUBLICS
//==========================================================================

//--------------------------------------------------------------------------
Crest :: Constructeur Crest(char* nom_fichier )
//                              -----
{

  strcpy( _CREST_nom_image, nom_fichier);

  //_nb_points = 0;
  //_nb_lignes = 0;

  AlloueCrest();

  _lissage_alloue = false;
  _sauve_lissage = false;

  _connexion_dist_max    = 12; 
  _connexion_tangent_max = 0.5;
  
} // Constructeur 


//--------------------------------------------------------------------------
Crest :: Constructeur Crest( )
//                              -----
{

  strcpy( _CREST_nom_image, "noname.crest");

  //_nb_points = 0;
  //_nb_lignes = 0;

  _lissage_alloue = false;
  _sauve_lissage = false;

  _connexion_dist_max    = 12;
  _connexion_tangent_max = 0.5;
  
} // Constructeur 


//--------------------------------------------------------------------------
Crest :: Destructeur Crest()
//                             -----
{

//  LibereCrest();

//  Si _lissage_alloue AlorsFait LibereLissage();

} // Constructeur 


//---------------------------------------------------------------------------
void Crest ::  ResizeVoxel(  float tx, float ty, float tz, float vx, float vy, float vz)
//                       -----------
// Change les positions en fonction de la taille des voxels
//
{

  
    register int i;

  Pour( i, 0, _CREST_tab_points.NbElts()-1)

      // voxel size 
      Point(i).x *= vx;
      Point(i).y *= vy;
      Point(i).z *= vz;

      // translation
      Point(i).x += tx;
      Point(i).y += ty;
      Point(i).z += tz;


  FinPour // i

} // ResizeVoxel()


//---------------------------------------------------------------------------
void Crest ::  LisseLignes(  int N, float alpha, float beta)
//                       -----------
// Lissage de chacune des lignes
// par minimisation de l'integrale de la norme de la derivee au carre
// avec regularisation
// N:     nombre d'iterations
// alpha: parametre de vitesse d'evolution
// beta:  parametre de la regularisation
{

#define lisse(l,m) PointLisse(l,m)
#define init(l,m)  Point(l,m)

  
    register int t,i,j;
    register float   a,b;

  a = alpha;
  b = beta;
  Si Non(_lissage_alloue) AlorsFait AlloueLissage();

  Pour( t, 1, N)
    Pour( i, 0, NbLignes()-1)
    Pour( j, 1, NbPoints(i)-2)

      lisse(i,j).x +=  a * ( lisse(i,j-1).x - 2*lisse(i,j).x + lisse(i,j+1).x) +
                       b * ( init(i,j).x - lisse(i,j).x );

      lisse(i,j).y +=  a * ( lisse(i,j-1).y - 2*lisse(i,j).y + lisse(i,j+1).y) +
                       b * ( init(i,j).y - lisse(i,j).y );

      lisse(i,j).z +=  a * ( lisse(i,j-1).z - 2*lisse(i,j).z + lisse(i,j+1).z) +
                       b * ( init(i,j).z - lisse(i,j).z );
    FinPour
    FinPour // i
  FinPour // t

} // LisseLignes()


//--------------------------------------------------------------------------
void Crest::SupprimeBarbules( int taille)
//          ----------------
{
  int l;

  Pour( l, 0, NbLignes()-1)
    Si LongueurLigne(l) <= taille Alors
      // check the number of line connected at the extremities ??
      _CREST_tab_lignes[l].liste_points.VideTableau();
      _CREST_tab_lignes[l].nb_points = 0;
    FinSi
  FinPour

} //  SupprimeBarbules()


//--------------------------------------------------------------------------
unsigned char Crest::ReadJulio( char* nom )
//                   ----------
{

  
    FILE*       fichier;
    int      i,j;    // indices pour les boucles
    Point3D     pt;       
    int      pos;      // indice d'un point dans le tableau de points
    LigneCrest  ligne_crest;
    int      n,res;
    char        ch[50];

  fichier = fopen( nom, "r");
  Si fichier == NULL Alors
    printf(" Erreur dans l'ouverture du fichier de %s \n", nom);
    return false;
  FinSi

  //---------------------------------------------
  //----- Calcul du nombre de lignes  
  //---------------------------------------------

  //----- Debut

  int nb_lignes = 0;
  int nb_points = 0;

  res = fscanf( fichier, "%d\n", &n);
  res = fscanf( fichier, "%s\n", ch);

  TantQue (res!=0)Et(res!=EOF) Faire

    Pour(i,1,n)
      fscanf( fichier, "%f %f %f\n", &pt.x, &pt.y, &pt.z);
    FinPour
    nb_lignes++;
    nb_points += n;

    res = fscanf( fichier, "%d\n", &n);
    res = fscanf( fichier, "%s\n", ch);

  FinTantQue

  Si res == 0 Alors
    fprintf(stderr,"Crest::ReadJulio()\t Error \n");
    return false;
  FinSi

  printf( "nb de ligne %d \n", nb_lignes);

  _CREST_tab_points.Resize(nb_points);
  _CREST_tab_lignes.Resize(nb_lignes);

  //---------------------------------------------
  //----- Calcul du nombre de points par ligne  
  //---------------------------------------------
  rewind(fichier);

  Pour( i, 0, nb_lignes-1)

    res = fscanf( fichier, "%d\n", &n);
    res = fscanf( fichier, "%s\n", ch);

    Pour(j,1,n)
      fscanf( fichier, "%f %f %f\n", &pt.x, &pt.y, &pt.z);
    FinPour

    ligne_crest.nb_points = n;
    ligne_crest.liste_points.VideTableau();
    ligne_crest.liste_points.Resize(n);

    _CREST_tab_lignes += ligne_crest;

  FinPour

  //---------------------------------------------
  //----- Memorisation des points
  //---------------------------------------------

  rewind(fichier);

  nb_points = 0;

  Pour( i, 0, NbLignes()-1)

    res = fscanf( fichier, "%d\n", &n);
    res = fscanf( fichier, "%s\n", ch);

    Pour(j,1,n)
      fscanf( fichier, "%f %f %f\n", &pt.x, &pt.y, &pt.z);
      // le point n'existe pas
      pos = nb_points;
      nb_points++;
      _CREST_tab_points += pt;
      _CREST_tab_points[NbPoints()-1].nb_liens = 1;
      _CREST_tab_lignes[i].liste_points += NbPoints()-1;
    FinPour // j

  FinPour // i

  //---------------------------------------------
  //----- Fermeture du fichier
  //---------------------------------------------

  fclose(fichier);

  return true;
    
} // ReadJulio()


//--------------------------------------------------------------------------
unsigned char Crest ::  SaveJulio( char* nom, unsigned char lissage )
//                          ---------
{

  
    FILE*   fichier;
    int  i,j;
    Point3D pt;

  fichier = fopen( nom, "w");
  Si fichier == NULL Alors
    printf("Crest::SaveJulio() \t Error opening file %s \n", nom);
    return false;
  FinSi

  //----- Debut
  Pour( i, 0, NbLignes()-1)

    Si _CREST_tab_lignes[i].nb_points == 0 AlorsFait continue;
    fprintf(fichier,"%d\n",_CREST_tab_lignes[i].nb_points);
    Si i==0 Alors
      fprintf(fichier,"m\n");
    Sinon
      fprintf(fichier,"%d\n",i);
    FinSi

    Pour( j, 0, _CREST_tab_lignes[i].nb_points -1)
      Si lissage Alors
        pt = PointLisse(i,j);
      Sinon
        pt = Point(i,j);
      FinSi
      fprintf( fichier, "%f %f %f\n", pt.x, pt.y, pt.z);
    FinPour //j
  FinPour  //i

  fclose(fichier);

  return true;
    
} // SaveJulio()



//--------------------------------------------------------------------------
unsigned char Crest ::  SauveLissage( char* nom )
//                          ------------
{


  Si CheckEndString(nom,".wrl") Alors
    return SaveVRML(nom,true);
  FinSi

  Si CheckEndString(nom,".corr") Alors
    return SaveJulio(nom,true);
  FinSi

  return Sauve(nom,true);

} // SauveLissage()


//--------------------------------------------------------------------------
unsigned char Crest ::  SauveSousImage( int x_min, int x_max, int y_min, int y_max,
//                          --------------
                        int z_min, int z_max, char* nom)
{

  
    FILE*  fichier;
    int i,j;
    float   epsilon = 1E-4;

  fichier = fopen( nom, "w");
  Si fichier == NULL Alors
    printf(" Erreur dans l'ouverture du fichier %s \n", nom);
    return false;
  FinSi


  //----- Debut
  fprintf( fichier, "(\n");

  Pour( i, 0, NbLignes()-1)
    Si _CREST_tab_lignes[i].nb_points == 0 AlorsFait continue;
    fprintf( fichier, "(\n");
    Pour( j, 0, _CREST_tab_lignes[i].nb_points -1)
      Si (Point(i,j).x >= x_min-epsilon) Et (Point(i,j).x <= x_max+epsilon) Et
         (Point(i,j).y >= y_min-epsilon) Et (Point(i,j).y <= y_max+epsilon) Et
         (Point(i,j).z >= z_min-epsilon) Et (Point(i,j).z <= z_max+epsilon) 
      Alors
        fprintf( fichier, "O4 ");
        fprintf( fichier, "%f %f %f\n", Point(i,j).x - x_min, 
         Point(i,j).y - y_min, Point(i,j).z - z_min);
        fprintf( fichier, "%f %f %f\n", Point(i,j).rayon, Point(i,j).proba,
                          Point(i,j).jonction);
        fprintf( fichier, "%f %f %f\n", Point(i,j).vecteur.x, 
         Point(i,j).vecteur.y, 
         Point(i,j).vecteur.z 
         );
        fprintf( fichier, "0.000000 0.000000 0.000000\n");
      FinSi
    FinPour //j
    fprintf( fichier, ")\n");
  FinPour  //i

  fprintf( fichier, ")\n");

  fclose(fichier);

  return true;

} // SauveSousImage()


//--------------------------------------------------------------------------
unsigned char Crest ::  Sauve( char* nom, unsigned char lissage)
//                          -----
{

  
    FILE*   fichier;
    int  i,j;
    Point3D pt;

  Si CheckEndString(nom,".wrl") AlorsFait
    return SaveVRML(nom);

#ifndef _WITHOUT_VTK_
  Si CheckEndString(nom,".vtk") AlorsFait
    return SaveVTK(nom);
#endif // _WITHOUT_VTK_

  Si CheckEndString(nom,".corr") AlorsFait
    return SaveJulio(nom);

  fichier = fopen( nom, "w");
  Si fichier == NULL Alors
    printf(" Erreur dans l'ouverture du fichier %s \n", nom);
    return false;
  FinSi


  //----- Debut
  fprintf( fichier, "(\n");

  Pour( i, 0, NbLignes()-1)
    Si _CREST_tab_lignes[i].nb_points == 0 AlorsFait continue;
    fprintf( fichier, "(\n");
    Pour( j, 0, _CREST_tab_lignes[i].nb_points -1)
      
      Si lissage Alors
        pt = PointLisse(i,j);
      Sinon
        pt = Point(i,j);
      FinSi

      fprintf( fichier, "O4 ");
      fprintf( fichier, "%f %f %f\n", pt.x, pt.y, pt.z);
      fprintf( fichier, "%f %f %f\n", 
           pt.rayon,
           pt.proba,
           pt.jonction);
      fprintf( fichier, "%f %f %f\n", pt.vecteur.x, 
           pt.vecteur.y, 
           pt.vecteur.z 
           );
      fprintf( fichier, "0.000000 0.000000 0.000000\n");
    FinPour //j
    fprintf( fichier, ")\n");
  FinPour  //i

  fprintf( fichier, ")\n");

  fclose(fichier);

  return true;

} // Sauve()


//--------------------------------------------------------------------------
unsigned char Crest ::  SauveWireFrame( int ligne, float voxel_size,
//                          --------------
                        char* nom)
{

  
    FILE*  fichier;
    int i,j;

  fichier = fopen( nom, "w");
  Si fichier == NULL Alors
    printf(" Erreur dans l'ouverture du fichier %s \n", nom);
    return false;
  FinSi

  //---------------------------------------------
  //----- Calcul du nombre de lignes  
  //---------------------------------------------

  //----- Debut
  fprintf( fichier, "WFVERSION0.3\n");
  fprintf( fichier, "VXTLWF.1 VXTLWF.1\n"); 
  fprintf( fichier, "red open ls\n");

  i = ligne;
 
  Si _CREST_tab_lignes[i].nb_points != 0 Alors
    Pour( j, 0, _CREST_tab_lignes[i].nb_points -1)
        fprintf( fichier, "%f %f %f\n", 
                Point(i,j).y *voxel_size ,
                Point(i,j).z *voxel_size ,
         -1.0*( Point(i,j).x *voxel_size)); 
    FinPour //j
  FinSi

  fprintf( fichier, "Xend_of_wf\n");

  fclose(fichier);

  return true;

} // SauveWireFrame()


//--------------------------------------------------------------------------
unsigned char Crest ::  ReadVRML( char* name)
//                          --------
                    
{

#ifdef _use_vrml97_
  
    SceneGraph sg; 
    Point3D    pt;       
    int        n,i,j,l,pos;
    float      p[3];
    LigneCrest ligne_crest;

  sg.load(name); 

  if (!(sg.isOK())) {
    printf("Crest::ReadVRML() \t Error while reading %s \n", name);
    return false;
  }

  IndexedLineSetNode *indexlineset = sg.findIndexedLineSetNode();
  CoordinateNode     *coord        = sg.findCoordinateNode();

  Si (coord != NULL) Et (indexlineset != NULL) Alors
    
    _CREST_tab_points.Resize(coord->getNPoints());
    int nb_points = 0;

    //
    // Ajout des points
    //

    Pour(i,0,coord->getNPoints()-1)

      if (i%10 == 0)
    {
      if (i>0) printf("\b\b\b\b\b\b");
          printf("%6d",i);
      fflush(stdout);
    }

      // Ajout du point
      coord->getPoint(i, p);
      pt.x = p[0];
      pt.y = p[1];
      pt.z = p[2];

      pos = NbPoints();
      _CREST_tab_points += pt;
      _CREST_tab_points[pos].nb_liens = 1;

    FinPour

    printf("\b\b\b\b\b\b");
    fflush(stdout);

    //
    // Calcul du nombre de lignes
    //

    pos = -1;
    int nb_lignes=0;
    for (i=0;i<indexlineset->getNCoordIndexes();i++) {
      pos = indexlineset->getCoordIndex(i);
      if (pos==-1) nb_lignes++;
    }
    _CREST_tab_lignes.Resize(nb_lignes);

    //
    // Calcul du nombre de points par ligne  
    //

    l = 0;
    n = 0;

    Pour( i, 0, indexlineset->getNCoordIndexes()-1)
      pos = indexlineset->getCoordIndex(i);
      Si pos>=0 Alors
        n++;
      Sinon 
        ligne_crest.nb_points = n;
        ligne_crest.liste_points.VideTableau();
        ligne_crest.liste_points.Resize(n);
        _CREST_tab_lignes += ligne_crest;
        n = 0;
      FinSi
    FinPour

    //
    // Memorisation des points
    //


    n = 0;
    Pour( i, 0, NbLignes()-1)
      Pour( j, 0, _CREST_tab_lignes[i].nb_points -1)
        pos = indexlineset->getCoordIndex(n);
        n++;
        Si pos < 0 Alors
      fprintf(stderr,"Crest::ReadVRML() \t error in reading \n");
        Sinon
          _CREST_tab_lignes[i].liste_points += pos;
        FinSi
      FinPour // j
      n++;
    FinPour

  FinSi

  return sg.isOK();
#else
  return 0;
#endif // _use_vrml97_

} // ReadVRML()


//--------------------------------------------------------------------------
unsigned char Crest ::  SaveVRML( char* name, unsigned char lissage)
//                          --------
                    
{

#ifdef _use_vrml97_
  
    SceneGraph sg; 
    int     i,j;
    Point3D    pt;

  // Add a new shape 
  ShapeNode *shape = new ShapeNode(); 
  sg.addNode(shape);

  IndexedLineSetNode *indexlineset = new IndexedLineSetNode();
  shape->addChildNode(indexlineset);

  // Coordinates

  CoordinateNode *coord = new CoordinateNode();
  indexlineset->addChildNode(coord);

  Pour( i, 0, NbPoints()-1)
    Si lissage Alors
      pt = PointLisse(i);
    Sinon
      pt = Point(i);
    FinSi
    coord->addPoint( pt.x, pt.y, pt.z);
  FinPour  //i

  // Lines

  Pour( i, 0, NbLignes()-1)
    Pour(j,0,NbPoints(i)-1)
      indexlineset->addCoordIndex( NumPoint(i,j));
    FinPour
    indexlineset->addCoordIndex( -1);
  FinPour  //i

  sg.save(name); 

  return sg.isOK();

#else
  return 0;
#endif // _use_vrml97_

} // SaveVRML()


#ifndef _WITHOUT_VTK_
//--------------------------------------------------------------------------
unsigned char Crest ::  ImportVTK( vtkPolyData* poly)
//                          ---------
                    
{

  
    vtkFloatingPointType             p[3];
    Point3D            pt;       
    vtkCellArray*      lines;
    vtkDataArray*      vtk_colors;
    unsigned char      get_colors;
    int                i,j;
    vtkIdType                nb_pts=0;
    vtkIdType*               res_points=NULL;
    LigneCrest         ligne_crest;


  _CREST_tab_points.Resize(poly->GetNumberOfPoints());

  printf("Number of points: %d \n",(int)poly->GetNumberOfPoints());

  vtk_colors = poly->GetPointData()->GetScalars();
  get_colors = ((vtk_colors!=NULL)&&(vtk_colors->GetDataType()==VTK_UNSIGNED_CHAR));

  Pour(i,0,poly->GetNumberOfPoints()-1)
    poly->GetPoint(i,p);
    pt.x = p[0];
    pt.y = p[1];
    pt.z = p[2];
    if (get_colors) {
      pt.rayon = (vtk_colors->GetComponent(i,0))/10.0;
    }
    _CREST_tab_points += pt;
    _CREST_tab_points[NbPoints()-1].nb_liens = 1;
  FinPour

  // Get the lines
  lines = poly->GetLines();

  int nb_lignes = 0;
  _CREST_tab_lignes.Resize(lines->GetNumberOfCells());

  printf("Number of lines: %d \n",(int)lines->GetNumberOfCells());

  lines->SetTraversalLocation(0); 
  Pour(i,0,lines->GetNumberOfCells()-1)

    lines->GetNextCell(nb_pts,res_points);
    ligne_crest.nb_points = nb_pts;
    ligne_crest.liste_points.VideTableau();
    ligne_crest.liste_points.Resize(nb_pts);

    Si nb_pts==0 AlorsFait continue;
    Pour(j,0,nb_pts-1)
      ligne_crest.liste_points += res_points[j];
    FinPour
    _CREST_tab_lignes += ligne_crest;
  FinPour


  return true;

} // ImportVTK()


//--------------------------------------------------------------------------
unsigned char Crest ::  ReadVTK( char* name)
//                          -------
                    
{

  
    vtkPolyDataReader* reader;
    vtkPolyData* poly; 
    vtkFloatingPointType              p[3];
    Point3D            pt;       
    vtkCellArray*      lines;
    vtkDataArray*      vtk_colors;
    unsigned char      get_colors;
    int                i,j;
    vtkIdType                nb_pts=0;
    vtkIdType*               res_points=NULL;
    LigneCrest         ligne_crest;

  reader = vtkPolyDataReader::New();
  reader->SetFileName(name);
  reader->Update();

  poly = reader->GetOutput();

  _CREST_tab_points.Resize(poly->GetNumberOfPoints());

  printf("Number of points: %d \n",(int)poly->GetNumberOfPoints());

  vtk_colors = poly->GetPointData()->GetScalars();
  get_colors = ((vtk_colors!=NULL)&&(vtk_colors->GetDataType()==VTK_UNSIGNED_CHAR));


  Pour(i,0,poly->GetNumberOfPoints()-1)
    poly->GetPoint(i,p);
    pt.x = p[0];
    pt.y = p[1];
    pt.z = p[2];
    if (get_colors) {
      pt.rayon = (vtk_colors->GetComponent(i,0))/10.0;
    }
    _CREST_tab_points += pt;
    _CREST_tab_points[NbPoints()-1].nb_liens = 1;
  FinPour

  // Get the lines
  lines = poly->GetLines();

  _CREST_tab_lignes.Resize(lines->GetNumberOfCells());

  printf("Number of lines: %d \n",(int)lines->GetNumberOfCells());

  lines->SetTraversalLocation(0); 
  Pour(i,0,lines->GetNumberOfCells()-1)

    lines->GetNextCell(nb_pts,res_points);
    ligne_crest.nb_points = nb_pts;
    ligne_crest.liste_points.VideTableau();
    ligne_crest.liste_points.Resize(nb_pts);

    Si nb_pts==0 AlorsFait continue;
    Pour(j,0,nb_pts-1)
      ligne_crest.liste_points += res_points[j];
    FinPour
    _CREST_tab_lignes += ligne_crest;
  FinPour

  reader->Delete();

  return true;

} // ReadVTK()

//----------------------------------------------------------------------
Crest :: operator vtkPolyData* (void) 
//
{

#define MAX_POINTS 30000

  
    vtkPoints*         points;
    vtkCellArray*      lines;
    vtkPolyData*       vtk_lines;
    Point3D            pt;
    int                i,j;
    vtkIdType          pts[MAX_POINTS];


  // Write the points
  points = vtkPoints::New();

//  points->SetTraversalLocation(0); 
  fprintf(stderr,"Nb Points %d \n",_CREST_tab_points.NbElts());
  Pour( i, 0, _CREST_tab_points.NbElts()-1)
    Si _sauve_lissage Alors
      pt = PointLisse(i);
    Sinon
      pt = Point(i);
    FinSi
     points->InsertPoint(i, pt.x, pt.y, pt.z);
  FinPour  //i

  // Write the lines
  lines = vtkCellArray::New();

  lines->SetTraversalLocation(0); 
  Pour( i, 0, NbLignes()-1)
    Si (NbPoints(i)>0) && (NbPoints(i)<MAX_POINTS) Alors
      Pour(j,0,NbPoints(i)-1)
        pts[j] = NumPoint(i,j);
      FinPour
      lines->InsertNextCell(NbPoints(i), pts);
    Sinon
      fprintf(stderr,"Crest operator vtkPolyData* \t Too many points or no point in line %d : %d. \n",i,NbPoints(i));
    FinSi
  FinPour  //i

  vtk_lines = vtkPolyData::New(); 
  vtk_lines->SetPoints(points);
  vtk_lines->SetLines(lines);

// Pb BUG ???
//  lines    ->Delete();
//  points   ->Delete();

  return vtk_lines;

} //  operator vtkPolyData* (void) 


//----------------------------------------------------------------------
void Crest :: ToPolyData(vtkPolyData** vtk_lines,
                   vtkPoints** points,
                   vtkCellArray** lines)
//
{

  
//    vtkPoints*         points;
//    vtkCellArray*      lines;
//    vtkPolyData*       vtk_lines;
    Point3D            pt;
    int                i,j;
    vtkIdType          pts[1000];


  // Write the points
//  points = vtkPoints::New();

//  points->SetTraversalLocation(0); 
fprintf(stderr,"Nb Points %d \n",_CREST_tab_points.NbElts());
  Pour( i, 0, _CREST_tab_points.NbElts()-1)
    Si _sauve_lissage Alors
      pt = PointLisse(i);  
    Sinon
      pt = Point(i);
    FinSi
     (*points)->InsertPoint(i, pt.x, pt.y, pt.z);
  FinPour  //i

  // Write the lines
  //  lines = vtkCellArray::New();

  (*lines)->SetTraversalLocation(0); 
  Pour( i, 0, NbLignes()-1)
    Si NbPoints(i)==0 Alors
      fprintf(stderr,"Crest operator vtkPolyData* \t empty line %d \n",i);
      continue;
    FinSi
    Si NbPoints(i)<1000 Alors
      Pour(j,0,NbPoints(i)-1)
        pts[j] = NumPoint(i,j);
      FinPour
      (*lines)->InsertNextCell(NbPoints(i), pts);
    Sinon
      fprintf(stderr,"Crest operator vtkPolyData* \t Too many points in line. \n");
    FinSi
  FinPour  //i

    //  *vtk_lines = vtkPolyData::New(); 
//(*vtk_lines)->SetPoints(points);
// (*vtk_lines)->SetLines(lines);

// Pb BUG ???
//  lines    ->Delete();
//  points   ->Delete();

//  return vtk_lines;

} // ToPolyData()



//--------------------------------------------------------------------------
unsigned char Crest ::  SaveVTK( char* name, unsigned char lissage)
//                          -------
                    
{

  
    vtkPoints*         points;
    vtkCellArray*      lines;
    vtkPolyData*       vtk_lines;
    vtkPolyDataWriter* writer;
    Point3D            pt;
    int                i,j;
    vtkIdType          pts[1000];


  // Write the points
  points = vtkPoints::New();

//  points->SetTraversalLocation(0); 
fprintf(stderr,"Nb Points %d \n",_CREST_tab_points.NbElts());
  Pour( i, 0, _CREST_tab_points.NbElts()-1)
    Si lissage Alors
      pt = PointLisse(i);
    Sinon
      pt = Point(i);
    FinSi
     points->InsertPoint(i, pt.x, pt.y, pt.z);
  FinPour  //i

  // Write the lines
  lines = vtkCellArray::New();

  lines->SetTraversalLocation(0); 
  Pour( i, 0, NbLignes()-1)
    Si (NbPoints(i)>0) && (NbPoints(i)<1000) Alors
      Pour(j,0,NbPoints(i)-1)
        pts[j] = NumPoint(i,j);
      FinPour
      lines->InsertNextCell(NbPoints(i), pts);
//    Sinon
//      fprintf(stderr,"Crest::SaveVTK() \t Too many points in line. \n");
    FinSi
  FinPour  //i

  vtk_lines = vtkPolyData::New(); 
  vtk_lines->SetPoints(points);
   vtk_lines->SetLines(lines);

  writer = vtkPolyDataWriter::New();

  writer->SetInput( vtk_lines);
  writer->SetFileTypeToBinary();
  //  writer->SetFileTypeToASCII();
  writer->SetFileName(name);
  writer->Write();

  lines    ->Delete();
  points   ->Delete();
  writer   ->Delete();
  vtk_lines->Delete();

  return 1;

} // SaveVTK()

    /*
//--------------------------------------------------------------------------
unsigned char Crest ::  SaveVTK( char* name, unsigned char lissage)
//                          -------
                    
{

  
    vtkPoints*         points;
    vtkCellArray*      lines;
    vtkPolyData*       vtk_lines;
    vtkPolyDataWriter* writer;

  _sauve_lissage = lissage;

//  vtk_lines = (vtkPolyData*) (*this);
  points = vtkPoints::New();
  lines = vtkCellArray::New();
  vtk_lines = vtkPolyData::New(); 


this->ToPolyData(&vtk_lines,&points,&lines);


  vtk_lines->SetPoints(points);
  vtk_lines->SetLines(lines);

  writer->SetInput( vtk_lines);
  writer->SetFileTypeToBinary();
   //  writer->SetFileTypeToASCII();
  writer->SetFileName(name);
  writer->Write();

   lines    ->Delete();
   points   ->Delete();
   writer   ->Delete();
   vtk_lines->Delete();

  return 1;

} // SaveVTK()
    */
#endif // _WITHOUT_VTK_

//--------------------------------------------------------------------------
unsigned char Crest :: Proche( Point3D p1, Point3D p2)
//                         ------
{

   float d;

  // don't reconnect junction points
  if (p1.jonction>2) return 0;
  if (p2.jonction>2) return 0;

  d = (p1.x - p2.x)*(p1.x - p2.x) +
      (p1.y - p2.y)*(p1.y - p2.y) +
      (p1.z - p2.z)*(p1.z - p2.z);

// cout << " distance " << d << "\t max " << _connexion_dist_max << endl;
  return (d < _connexion_dist_max);

} // Proche() 

//--------------------------------------------------------------------------
unsigned char Crest :: Proche( Vect3D<float> v1, Vect3D<float> v2)
//                         ------
{

  

  // les deux vecteurs doivent etre opposes
//  Si v1*v2 > 0 AlorsFait return false;

  try {
    v1.Normalise();
    v2.Normalise();
  }
  catch (NormeFaible)
  {
    return 0;
  }

// cout << " distance " << r << "\t max " << _connexion_tangent_max << endl;
  return ( (v1+v2)*(v1+v2) < _connexion_tangent_max);

} // Proche() 


//--------------------------------------------------------------------------
double Crest :: LongueurLigne( int ligne)
//                            -------------
{

  
    double l;
    int     i;
    Point3D    p0,p1;

  l=0;

  Pour( i, 1, NbPoints(ligne)-1)
    p0 = Point(ligne,i-1);
    p1 = Point(ligne,i);

    l += sqrt( (p0.x-p1.x)*(p0.x-p1.x) +
               (p0.y-p1.y)*(p0.y-p1.y) +
               (p0.z-p1.z)*(p0.z-p1.z) 
         );
  FinPour

  return l;

} // LongueurLigne()


//--------------------------------------------------------------------------
double Crest :: AbscisseCurv( int ligne, int point)
//                            ------------
{

  
    double l;
    int     i;
    Point3D    p0,p1;

  l=0;

  Si point <= 0 AlorsFait return 0.0;
  Si point >= NbPoints(ligne)-1 AlorsFait point = NbPoints(ligne)-1;

  Pour( i, 1, point)
    p0 = Point(ligne,i-1);
    p1 = Point(ligne,i);

    l += sqrt( (p0.x-p1.x)*(p0.x-p1.x) +
               (p0.y-p1.y)*(p0.y-p1.y) +
               (p0.z-p1.z)*(p0.z-p1.z) 
         );
  FinPour

  return l;

} // AbscisseCurv()


//--------------------------------------------------------------------------
int Crest :: Position( int ligne, float abscisse, Point3D& pt)
//                        --------
{

  
    double l,l_prec;
    int     i;
    Point3D    p0,p1;
    float       c0,c1;

  Si abscisse < 1E-5 Alors
    p0 = Point( ligne, 0);
    pt = p0;
    return 0;
  FinSi

  l_prec = l = 0;
  i = 1;

  TantQue (l < abscisse) Et (i <= NbPoints(ligne)-1)
  Faire
    p0 = Point(ligne,i-1);
    p1 = Point(ligne,i);

    l_prec = l;
    l += sqrt( (p0.x-p1.x)*(p0.x-p1.x) +
               (p0.y-p1.y)*(p0.y-p1.y) +
               (p0.z-p1.z)*(p0.z-p1.z) 
         );
    i++;
  FinTantQue

  Si (i == NbPoints(ligne))Et (l<=abscisse) Alors
    p0 = Point(ligne,i-1);
    pt = p0;
    return (i-1);        
  Sinon
    // interpolation lineaire de l'abscisse
    c0 = (l-abscisse)/(l-l_prec);
    c1 = 1.0 - c0;
    
    pt.x = c0*p0.x + c1*p1.x;
    pt.y = c0*p0.y + c1*p1.y;
    pt.z = c0*p0.z + c1*p1.z;

    pt.vecteur.x = c0*p0.vecteur.x + c1*p1.vecteur.x;
    pt.vecteur.y = c0*p0.vecteur.y + c1*p1.vecteur.y;
    pt.vecteur.z = c0*p0.vecteur.z + c1*p1.vecteur.z;

    pt.rayon = c0*p0. rayon+ c1*p1.rayon;

    Si i-2 < 0 Alors 
      return 0;
    Sinon
      return i-2;
    FinSi
  FinSi

} // Position()


//---------------------------------------------------------------------
//
void Crest :: ReOrienteLigne( int l)
//                    --------------
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


//--------------------------------------------------------------------------
unsigned char Crest :: ConnecteLigne(int l1, int l2, int e1, int e2)
//                         -------------
// l1 et l2 indices des lignes a connecter,
// e1 et e2 indique quelles extremites doivent etre connectees
{

   
    LigneCrest aux;
    int     i,j,n1,n2;

  n1 = NbPoints(l1);
  n2 = NbPoints(l2);

  aux.nb_points     = n1 + n2;
  aux.liste_points.Resize(aux.nb_points);

  i = 0;

  Si e1 == LAST Alors
    Pour( j, 0, n1 - 1)
      aux.liste_points += NumPoint( l1, j);
      i++;
    FinPour // j
  Sinon
    Pour( j, 1, n1)
      aux.liste_points += NumPoint( l1, n1 - j);
      i++;
    FinPour // j
  FinSi

  Si e2 == FIRST Alors
    Pour( j, 0, n2 - 1)
      aux.liste_points += NumPoint( l2, j);
      i++;
    FinPour  // j
  Sinon
    Pour( j, 1, n2)
      aux.liste_points += NumPoint( l2, n2 - j);
      i++;
    FinPour  // j
  FinSi

  _CREST_tab_lignes[l1] = aux;

  _CREST_tab_lignes[l2].liste_points.VideTableau();
  _CREST_tab_lignes[l2].nb_points = 0;

  return true;

} // ConnecteLigne()

//--------------------------------------------------------------------------
int Crest ::  ConnecteLignes( )
//                         --------------
// Pour connecter deux lignes: a(1)->a(n) et b(1)->b(m)
// deux extremites doivent entre proches d(ai,bj) < seuil
// et les tangentes des lignes a ces extremites doivent avoir 
// des orientations proches || Ti + Tj || < seuil
{

  
    int   i,j;
    int   n,n1,n2;
    int   total_connexions;
    int   total_jonctions;

    Point3D  e1,e2;
    Vect3D<float>   T1,T2;

    Point3D  e3,e4;
    Vect3D<float>   T3,T4;

    Vect3D<float>   T_connect;
    unsigned char  connexion;

  total_connexions = 0;
  total_jonctions  = 0;

  ComputeLinks();

  i = 0;
  printf("ligne %5d",i);

  Pour( i, 0, NbLignes()-1)

    printf("\b\b\b\b\b");
    printf("%5d",i);
    fflush(stdout);

    n = NbPoints(i) - 1;
    Si n < 1 AlorsFait continue;

    e1 = Point(i,0);
    e2 = Point(i,n);
    T1 = e1 - Point(i,  1);
    T2 = e2 - Point(i,n-1);

    Pour(j,i + 1,NbLignes()-1)

      n = NbPoints(j) - 1;
      Si n < 1 AlorsFait continue;

      e3 = Point(j,0);
      e4 = Point(j,n);
      T3 = e3 - Point(j,1);
      T4 = e4 - Point(j,n-1);

      connexion = false;

      Si Proche(e3,e1) Alors
        T_connect = e3-e1;
        Si Proche(T3,T1) Et Proche(T3,T_connect) Alors
          n1 = NumPoint(i,0);
          n2 = NumPoint(j,0);
          printf("connexion FF %3d %3d points %5d(%1d) %5d(%1d)\n",i,j,
                 n1,NbLiens(n1),n2, NbLiens(n2));
          ConnecteLigne(j,i,FIRST,FIRST);
          total_connexions++;
          connexion = true;
        FinSi
      Autrement
      Si Proche(e4,e1) Alors
        T_connect = e4-e1;
        Si Proche(T4,T1) Et Proche(T4,T_connect) Alors
          n1 = NumPoint(i,0);
          n2 = NumPoint(j,NbPoints(j) - 1);
          printf("connexion FL %3d %3d points %5d(%1d) %5d(%1d)\n",i,j,
                 n1,NbLiens(n1),n2, NbLiens(n2));
          ConnecteLigne(j,i,LAST,FIRST);
          total_connexions++;
          connexion = true;
        FinSi
      Autrement
      Si Proche(e3,e2) Alors
        T_connect = e3-e2;
        Si Proche(T3,T2) Et Proche(T3,T_connect)  Alors
          n1 = NumPoint(i,NbPoints(i) - 1);
          n2 = NumPoint(j,0);
          printf("connexion LF %3d %3d points %5d(%1d) %5d(%1d)\n",i,j,
                 n1,NbLiens(n1),n2, NbLiens(n2));
          ConnecteLigne(j,i,FIRST,LAST);
          total_connexions++;
          connexion = true;
        FinSi
      Autrement
      Si Proche(e4,e2) Alors
        T_connect = e4-e2;
        Si Proche(T4,T2) Et Proche(T4,T_connect) Alors
          n1 = NumPoint(i,NbPoints(i) - 1);
          n2 = NumPoint(j,NbPoints(j) - 1);
          printf("connexion LL %3d %3d points %5d(%1d) %5d(%1d)\n",i,j,
                 n1,NbLiens(n1),n2, NbLiens(n2));
          connexion = true;
          ConnecteLigne(j,i,LAST,LAST);
          total_connexions++;
        FinSi
      FinSi

      Si connexion Alors
        break;
      FinSi

    FinPour
  FinPour // i

  printf("nb connexions %d \t nb jonctions %d\n",total_connexions, total_jonctions);
  return (total_connexions+total_jonctions);

} // ConnecteLignes()


//--------------------------------------------------------------------------
int Crest ::  SupprimePointsMultiples()
//                         -----------------------
{

  

/*
  Pour( n, 0, _nb_points - 1)
        Si _CREST_tab_points[n] == pt Alors
          pos = n;
        FinSi
  FinPour // n
*/

  return 0;

} // SupprimePointsMultiples()

//--------------------------------------------------------------------------
int Crest ::  RegroupeLignesConnectees(  int l1, int l2)
//                         ------------------------
{

   
    int j;
    int t1,t2;
    Point3D e11,e12,e21,e22; // 4 extremites des 2 lignes

  t1 = NbPoints(l1);
  t2 = NbPoints(l2);

  Si t1==0 Ou t2==0 AlorsRetourne false;

  e11 = Point( l1, 0           );
  e12 = Point( l1, t1 - 1 );
  e21 = Point( l2, 0           );
  e22 = Point( l2, t2 - 1 );

  Si (e11==e21) Ou (e11==e22) AlorsFait ReOrienteLigne(l1);
  Si (e22==e11) Ou (e22==e12) AlorsFait ReOrienteLigne(l2);

  _CREST_tab_points[NumPoint(l1,NbPoints(l1)-1)].jonction -= 1;

  Pour( j, 1, t2-1)

    _CREST_tab_lignes[l1].liste_points += NumPoint( l2, j);
    _CREST_tab_lignes[l1].nb_points++;

  FinPour

  _CREST_tab_lignes[l2].nb_points = 0;
  _CREST_tab_lignes[l2].liste_points.VideTableau();

  return true;

} // RegroupeLignesConnectees()


//--------------------------------------------------------------------------
void Crest ::  ComputeLinks( )
//                       ------------
{

   
    int  l,l1=0,l2=0,k;
    Point3D p1, p2;
    int  n1, n2;
    int     regroup;


  Pour(l,0,NbLignes()-1)

    Si NbPoints(l) == 0 AlorsFait continue;
    p1 = Point( l,  0);
    p2 = Point( l,  NbPoints(l)-1);
    n1 = 1;
    n2 = 1;

    Pour(k, l+1, NbLignes()-1)
      Si NbPoints(k) == 0 AlorsFait continue;
      Si (p1 == Point( k,  0)) Ou (p1 == Point( k, NbPoints(k)-1)) Alors
        n1++;
        printf("%d n1=%d\n",l,n1);
        l1 = k;
      FinSi
    FinPour

    Pour(k, l+1, NbLignes()-1)
      Si NbPoints(k) == 0 AlorsFait continue;
      Si (p2 == Point( k,  0)) Ou (p2 == Point( k, NbPoints(k)-1)) Alors
        n2++;
        printf("%d n2=%d\n",l,n2);
        l2 = k;
      FinSi
    FinPour

    regroup=0;
    if (p1.jonction<n1) {
      _CREST_tab_points[NumPoint(l,0)].jonction = n1;
      //      printf("%d --> %d \n",NumPoint(l,0), n1);
      if (n1==2) { RegroupeLignesConnectees(l,l1); regroup=1; }
    }
    if (p2.jonction<n2) {
      _CREST_tab_points[NumPoint(l,NbPoints(l)-1)].jonction = n2;
      //printf("%d --> %d \n",NumPoint(l,NbPoints(l)-1),n2);
      if (n2==2) { RegroupeLignesConnectees(l,l2); regroup=1; }
    }
    if (regroup) l--;

  FinPour

} // ComputeLinks()


//--------------------------------------------------------------------------
int Crest ::  ConnecteJonction( )
//                         ----------------
{

   
    int  l,l1,l2,k;
    Point3D p1, p2;
    int  n1, n2;


  Pour(l,0,NbLignes()-1)

    Si NbPoints(l) == 0 AlorsFait continue;
    p1 = Point( l,  0);
    p2 = Point( l,  NbPoints(l)-1);
    n1 = n2 = 1;

    Pour(k, l+1, NbLignes()-1)
      Si NbPoints(k) == 0 AlorsFait continue;
      Si (p1 == Point( k,  0)) Ou (p1 == Point( k, NbPoints(k)-1)) Alors
        n1++;
        l1 = k;
      FinSi
    FinPour

    Pour(k, l+1, NbLignes()-1)
      Si NbPoints(k) == 0 AlorsFait continue;
      Si (p2 == Point( k,  0)) Ou (p2 == Point( k, NbPoints(k)-1)) Alors
        n2++;
        l2 = k;
      FinSi
    FinPour

      /*
    Si n1>2 Alors
      cout << " Point " << p1 << " nb liens " 
           << n1 << "ligne " << l << endl;
      _CREST_tab_points[NumPoint(l,0)].jonction = n1;
    Sinon
      _CREST_tab_points[NumPoint(l,0)].jonction = 0;
    FinSi

    Si n2>2 Alors
      cout << " Point " << p2 << " nb liens " 
           << n2 << "ligne " << l << endl;
      _CREST_tab_points[NumPoint(l,NbPoints(l)-1)].jonction = n2;
    Sinon
      _CREST_tab_points[NumPoint(l,NbPoints(l)-1)].jonction = 0;
    FinSi
      */

    Si n1==2 Alors
      cout << " Point " << p1 << " 2 liens "  << endl;
      _CREST_tab_points[NumPoint(l,0)].jonction = n1;
//      RegroupeLignesConnectees(l,l1);
    FinSi
    Si n2==2 Alors
      cout << " Point " << p2 << " 2 liens "  << endl;
      _CREST_tab_points[NumPoint(l,NbPoints(l)-1)].jonction = n2;
//      RegroupeLignesConnectees(l,l2);
    FinSi

    Si (n1==2) Ou (n2==2) AlorsFait l--;

  FinPour


  return true;

} // ConnecteJonction()


//--------------------------------------------------------------------------
void Crest ::  ProbaMinMax( float* min, float* max )
//                       -----------
{

  
    int i,j;
    float   proba;

  *min = *max = -1;

  Pour( i, 0, NbLignes()-1)
    Si _CREST_tab_lignes[i].nb_points == 0 AlorsFait continue;
    Pour( j, 0, _CREST_tab_lignes[i].nb_points -1)
        proba = Point(i,j).proba;
        Si *min == -1 Alors
          *min = *max = proba;
        FinSi
        Si proba < *min AlorsFait *min = proba;  
        Si proba > *max AlorsFait *max = proba;  
    FinPour
  FinPour

} // ProbaMinMax()


//--------------------------------------------------------------------------
void Crest ::  RayonMinMax( float* min, float* max )
//                       -----------
{

  
    int i,j;
    float   rayon;

  *min = *max = -1;

  Pour( i, 0, NbLignes()-1)
    Si _CREST_tab_lignes[i].nb_points == 0 AlorsFait continue;
    Pour( j, 0, _CREST_tab_lignes[i].nb_points -1)
        rayon = Point(i,j).rayon;
        Si *min == -1 Alors
          *min = *max = rayon;
        FinSi
        Si rayon < *min AlorsFait *min = rayon;  
        Si rayon > *max AlorsFait *max = rayon;  
    FinPour
  FinPour

} // RayonMinMax()


//--------------------------------------------------------------------------
void Crest ::  SupprimeLigne( int l)
//                       -------------
{

    Si (l>=0) Et (l<NbLignes()) Alors
      _CREST_tab_lignes.Supprime(l);
      Si _lissage_alloue AlorsFait
        _LISSE_tab_lignes.Supprime(l); 
    FinSi

} // SupprimeLigne()


//--------------------------------------------------------------------------
void Crest ::  VideLigne( int l)
//                       ---------
{

  _CREST_tab_lignes[l].liste_points.VideTableau();
  _CREST_tab_lignes[l].nb_points = 0;

} // SupprimeLigne()


//--------------------------------------------------------------------------
int Crest ::  AjouteLigne( const LigneCrest& ligne)
//                         -----------
{

   _CREST_tab_lignes += ligne;
   return (NbLignes()-1);

} // AjouteLigne()


//--------------------------------------------------------------------------
int Crest ::  AjouteLigne( const Crest& crest, int numligne)
//                         -----------
{

  
    int           p, numpoint;
    Point3D          pt;
    LigneCrest       ligne;

  Pour( p, 0, crest.NbPoints(numligne) -1)

    pt = crest.Point(numligne,p);
    // Ajout du point
    numpoint = AddPoint( pt);
    ligne += numpoint;
  FinPour

  return AjouteLigne(ligne);

} // AjouteLigne()


//--------------------------------------------------------------------------
int Crest ::  AddPoint( const Point3D& pt)
//                         --------
{

  _CREST_tab_points += pt;
  _CREST_tab_points[NbPoints()-1].nb_liens = 1;
  return NbPoints()-1;

} // AddPoint()


//--------------------------------------------------------------------------
Crest& Crest ::  operator +=( const Point3D& pt)
//                         -----------
{

  _CREST_tab_points += pt;
  _CREST_tab_points[NbPoints()-1].nb_liens = 1;
  return (*this);

} // +=(const Point3D&)



//--------------------------------------------------------------------------
Crest& Crest ::  operator +=( const LigneCrest& ligne)
//                         -----------
{

  _CREST_tab_lignes += ligne;
  return (*this);

} // +=( const LigneCrest&)

