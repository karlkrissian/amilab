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
 * $Revision: 1.3 $
 * $Log: CalculBoules.cpp,v $
 * Revision 1.3  2005/11/16 14:03:10  karl
 * added LGPL license
 *
 * Revision 1.2  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
 *
 * Revision 1.1.1.1  2004/02/02 20:47:09  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:11:33  karl
 * Sources code
 *
 */

#include "CalculBoules.hpp"
#include "Eigen.hpp"

#ifndef min
  #define min(a,b) ((a)<(b)?(a):(b))
#endif

static Chaine     ce_fichier = "CalculBoules.cpp";


//---------------------------------------------------------
/**
 Moyenne au centre de la face _face � partir du buffer courant
 */

double CalculBoule :: MoyenneFace( InrImage* image )
//                               -----------
{

  
    double moy;
    int s;

  moy = 0;
  Pour( s, 0, 3)
    moy += (*image)( _x + _voxel.PosX(_face,s), 
		     _y + _voxel.PosY(_face,s), 
		     _z + _voxel.PosZ(_face,s));
  FinPour

  moy /= 4.0;

  return moy;

} // MoyenneFace()




//---------------------------------------------------------
/**
 Moyenne au centre de la face _face � partir du buffer courant
 */
inline double CalculBoule :: MoyenneArete(  InrImage* image) 
//                                     -------------
{

  
    double moy;

   moy = ( (*image)( _x+arete_p1.x, _y+arete_p1.y, _z+arete_p1.z) * 0.5
	  //          (1-coeff_arete) 
          +
	   (*image)( _x+arete_p2.x, _y+arete_p2.y, _z+arete_p2.z)  * 0.5
	   //          coeff_arete
        );

  return moy;

} // MoyenneArete()


//---------------------------------------------------------
/**
  Vecteurs propres du hessien au centre d'une face
 */
unsigned char CalculBoule :: CalculVepFace( Vect3D<double> *vep_face)
//                                ------------
{

  
    unsigned char         VapHessien;
    int             num_rot;


  Si type_filtre == FILTRE_CONV Alors
    grad.x = - MoyenneFace( (*filtre)(IMx_sigma) );
    grad.y = - MoyenneFace( (*filtre)(IMy_sigma) );
    grad.z = - MoyenneFace( (*filtre)(IMz_sigma) );
  Sinon
    grad.x =  MoyenneFace(  (*filtre)(IMx_sigma) );
    grad.y =  MoyenneFace(  (*filtre)(IMy_sigma) );
    grad.z =  MoyenneFace(  (*filtre)(IMz_sigma) );
  FinSi

  H_3D[0][0] =               MoyenneFace( (*filtre)(IMxx_sigma) );
  H_3D[0][1] = H_3D[1][0] =  MoyenneFace( (*filtre)(IMxy_sigma) );
  H_3D[0][2] = H_3D[2][0] =  MoyenneFace( (*filtre)(IMzx_sigma) );
  H_3D[1][1] =               MoyenneFace( (*filtre)(IMyy_sigma) );
  H_3D[1][2] = H_3D[2][1] =  MoyenneFace( (*filtre)(IMzy_sigma) );
  H_3D[2][2] =               MoyenneFace( (*filtre)(IMzz_sigma) );

  // les valeurs propres sont class�e par ordre croissant dans 'vap'
  // par rapport � l'article de Sato:

  VapHessien = jacobi( H_3D, 3, vap, VP_3D, &num_rot );

  eigsrt_inc(vap, VP_3D, 3);

  vep_face[0].Init( VP_3D[0][0], VP_3D[1][0], VP_3D[2][0]);
  vep_face[1].Init( VP_3D[0][1], VP_3D[1][1], VP_3D[2][1]);
  vep_face[2].Init( VP_3D[0][2], VP_3D[1][2], VP_3D[2][2]);

/*
  VapHessien = E_DMVVpropresMatSym( hessien, vap, vec_propre, (int)3 );


  vep_face[0].Init( vec_propre[0], vec_propre[3], vec_propre[6]);
  vep_face[1].Init( vec_propre[1], vec_propre[4], vec_propre[7]);
  vep_face[2].Init( vec_propre[2], vec_propre[5], vec_propre[8]);
*/

  return VapHessien;

} // CalculVepFace()




//---------------------------------------------------------
/**
  Vecteurs propres du hessien au centre d'une face
 */
unsigned char CalculBoule :: CalculVepArete( Vect3D<double> *vep_arete)
//                                   ---------------
{

  
    double          ps1,ps2;
    unsigned char         VapHessien;
    int             num_rot;


  Si type_filtre == FILTRE_CONV Alors
    grad.x = - MoyenneArete( (*filtre)(IMx_sigma) );
    grad.y = - MoyenneArete( (*filtre)(IMy_sigma) );
    grad.z = - MoyenneArete( (*filtre)(IMz_sigma) );
  Sinon
    grad.x =  MoyenneArete( (*filtre)(IMx_sigma) );
    grad.y =  MoyenneArete( (*filtre)(IMy_sigma) );
    grad.z =  MoyenneArete( (*filtre)(IMz_sigma) );
  FinSi

  H_3D[0][0] =               MoyenneArete( (*filtre)(IMxx_sigma) );
  H_3D[0][1] = H_3D[1][0] =  MoyenneArete( (*filtre)(IMxy_sigma) );
  H_3D[0][2] = H_3D[2][0] =  MoyenneArete( (*filtre)(IMzx_sigma) );
  H_3D[1][1] =               MoyenneArete( (*filtre)(IMyy_sigma) );
  H_3D[1][2] = H_3D[2][1] =  MoyenneArete( (*filtre)(IMzy_sigma) );
  H_3D[2][2] =               MoyenneArete( (*filtre)(IMzz_sigma) );

  // les valeurs propres sont class�e par ordre croissant dans 'vap'
  // par rapport � l'article de Sato:


  VapHessien = jacobi( H_3D, 3, vap, VP_3D, &num_rot );

  eigsrt_inc(vap, VP_3D, 3);

  vep_arete[0].Init( VP_3D[0][0], VP_3D[1][0], VP_3D[2][0]);
  vep_arete[1].Init( VP_3D[0][1], VP_3D[1][1], VP_3D[2][1]);
  vep_arete[2].Init( VP_3D[0][2], VP_3D[1][2], VP_3D[2][2]);

  // Essayer d'assurer la continuite des vecteurs propres,
  // en definissant le deuxi�me vecteur propre comme celui,
  // parmis les 2 dont les valeurs propres sont maximale,
  // dont le produit scalaire avec la direction du gradient
  // en valeur absolue

  // Cependant si la norme du gradient est faible et
  // la direction du gradient n'a plus de sens ...
  // Ou si les 2 valeurs propres les + petites sont proches

  Si Non((vap[1] < -1E-5) Et (vap[1]/vap[0] > 0.5) Et 
 (fabs(vap[2])<fabs(vap[1]))   ) 
  Alors

    ps1 = grad * vep_arete[1];
    ps2 = grad * vep_arete[2];

    Si fabs(ps2) > fabs(ps1) Alors
    /*
      macro_permute( vap[1], vap[2]);
      macro_permute( vep_arete[1].x, vep_arete[2].x);
      macro_permute( vep_arete[1].y, vep_arete[2].y);
      macro_permute( vep_arete[1].z, vep_arete[2].z);
    */
    FinSi

  FinSi

  return VapHessien;

} // CalculVepArete()


//---------------------------------------------------------
inline unsigned char  CalculBoule :: PassageParZero( int& signe, 
//                                         --------------
							   double valeur)
{

  Si valeur > 1E-5 Alors 
    Si signe == 0 AlorsFait signe = 1;
    Si signe == -1 Alors
      return true;
    FinSi
  FinSi
  Si valeur < -1E-5 Alors 
    Si signe == 0 AlorsFait signe = -1;
    Si signe == 1 Alors
      return true;
    FinSi
  FinSi
  Si fabs(valeur) < 1E-5 Alors 
     return true;
  FinSi

  return false;

} // PassageParZero()




//---------------------------------------------------------
void CalculBoule :: CalculeArete( PtPosition* pt)
//                                -------------

{

  MethodeCourante("CalculeArete", ce_fichier);

  
    int          sommet,centre;
    int          som;

    PtPosition     pts_trouves[16];
    int          nb_points;

    int          pos_min,i;
    float            d,d_min;

  // On prend les vecteurs propres estimes au centre de l'arete
  // pour calculer les intersections de la face
  CalculVepArete( vep_face );
  centre = 4;
  val1[_face][centre] = grad * vep_face[0];
  val2[_face][centre] = grad * vep_face[1];

  Pour( sommet, 0, 3)
    // numero du sommet dans le voxel
    som = _voxel.NumSommet(_face,sommet);
    // produit scalaire (gradient, vecteur propre)
    val1[_face][sommet] = gradient_voisins[som]*vep_face[0];
    val2[_face][sommet] = gradient_voisins[som]*vep_face[1];
  FinPour // sommet


  iso_ligne->FixeValeursFace( _face, val1[_face], val2[_face] );
  nb_points = iso_ligne->PointsFace( _face, pts_trouves);

  Si nb_points == 0 Alors
    AfficheWarning( WARNING_DIVERS ,"aucun point trouve ...");
    FinMethode();
    return;
  FinSi

  // On cherche le point le plus pres de *pt et on verifie
  // qu'il est tres proche ...
  d_min = Norme( *pt - pts_trouves[0]);
  pos_min = 0;
  Pour( i, 1, nb_points-1)
    d = Norme( *pt - pts_trouves[i]);
    Si d<d_min Alors
      d = d_min;
      pos_min = i;
    FinSi
  FinPour

  Si d_min > 0.1 Alors

    char message[30];

    sprintf(message,"  d_min > 0.1, %f", d_min); 
    AfficheWarning( WARNING_DIVERS , message);
    FinMethode();
    return;
  FinSi

  *pt = pts_trouves[pos_min];

  FinMethode();

} // CalculeArete()


//---------------------------------------------------------
void CalculBoule :: ReEvalue( PtPosition* pt)
//                                --------
{

  
    double       min1, min2;

  switch ( _face ){

    case 0: 
      // z = 0 
      min1 = min( pt->x, 1-pt->x);
      min2 = min( pt->y, 1-pt->y);
      Si (min1 < min2) Et (min1 < 0.25) Alors
        arete_p1.Init( (int) (pt->x+0.5), 0, 0);
        arete_p2.Init( (int) (pt->x+0.5), 1, 0);
        coeff_arete = pt->y;
        CalculeArete( pt);
      FinSi
      Si (min2 < min1) Et (min2 < 0.25) Alors
        arete_p1.Init( 0, (int) (pt->y+0.5), 0);
        arete_p2.Init( 1, (int) (pt->y+0.5), 0);
        coeff_arete = pt->x;
        CalculeArete( pt);
      FinSi
    break;

    case 1: 
      // y = 0 
      min1 = min( pt->x, 1-pt->x);
      min2 = min( pt->z, 1-pt->z);
      Si (min1 < min2) Et (min1 < 0.25) Alors
        arete_p1.Init( (int) (pt->x+0.5), 0, 0);
        arete_p2.Init( (int) (pt->x+0.5), 0, 1);
        coeff_arete = pt->z;
        CalculeArete( pt);
      FinSi
      Si (min2 < min1) Et (min2 < 0.25) Alors
        arete_p1.Init( 0, 0, (int) (pt->z+0.5) );
        arete_p2.Init( 1, 0, (int) (pt->z+0.5) );
        coeff_arete = pt->x;
        CalculeArete( pt);
      FinSi
    break;

    case 2: 
      // x = 0 
      min1 = min( pt->y, 1-pt->y);
      min2 = min( pt->z, 1-pt->z);
      Si (min1 < min2) Et (min1 < 0.25) Alors
        arete_p1.Init( 0, (int) (pt->y+0.5), 0);
        arete_p2.Init( 0, (int) (pt->y+0.5), 1);
        coeff_arete = pt->z;
        CalculeArete( pt);
      FinSi
      Si (min2 < min1) Et (min2 < 0.25) Alors
        arete_p1.Init( 0, 0, (int) (pt->z+0.5) );
        arete_p2.Init( 0, 1, (int) (pt->z+0.5) );
        coeff_arete = pt->y;
        CalculeArete( pt);
      FinSi
    break;

  } // end switch

} // ReEvalue();


//----------------------------------------------------------------------------
unsigned char CalculBoule :: CalculZeros( int vec1, int vec2, 
//                                -----------
  					       CreeCrest* crest)
{

  MethodeCourante("CalculZeros", ce_fichier);

  
    int          signe, zero_detecte, zero_face;
    int          nb_points=0;
    PtPosition      pts_trouves[16];
    PtPosition      pt;
    pt3DReel        p1;
    int          sommet,i;
    int          som,centre;


  zero_detecte = false;

  // Pour eviter de parcourir deux fois chaque face,
  // On associe a chaque voxel ces 3 premieres faces
  Pour( _face, 0, 2)

    // Calcul des vecteurs propres et des valeurs propres pour la face 
    CalculVepFace( vep_face);

    // Valeurs 1 et 2 au centre de la face
    centre = 4;
    val1[_face][centre] = grad * vep_face[vec1];
    val2[_face][centre] = grad * vep_face[vec2];

    zero_face = false;
    // Produits scalaires avec vec0
    signe = 0;
    Pour( sommet, 0, 3)
      // numero du sommet dans le voxel
      som = _voxel.NumSommet(_face,sommet);
      // produit scalaire (gradient, vecteur propre)
      val1[_face][sommet] = gradient_voisins[som]*vep_face[vec1];
      Si PassageParZero( signe, val1[_face][sommet]) AlorsFait
          zero_face = true;
    FinPour // sommet

    Si zero_face Alors

      zero_face = false;
      // Produits scalaires avec vec1
      signe = 0;
      Pour( sommet, 0, 3)
        // numero du sommet dans le voxel
        som = _voxel.NumSommet(_face,sommet);
        // produit scalaire (gradient, vecteur propre)
        val2[_face][sommet] = gradient_voisins[som]*vep_face[vec2];
        Si PassageParZero( signe, val2[_face][sommet]) AlorsFait
            zero_face = true;
      FinPour // sommet

    FinSi

    // On a detecte un zero sur une des faces
    Si zero_face Alors
      zero_detecte = true;
      iso_ligne->FixeValeursFace( _face, val1[_face], val2[_face] );
      try {
        nb_points = iso_ligne->PointsFace( _face, pts_trouves);
      }
      catch (ExceptionErreur e)
      {
      }
      catch (ExceptionWarning w)
      {
      }

      Pour( i, 0, nb_points-1)

        // Tester si le point est proche d'une arete
        // ou d'un sommet,
        // Si c'est le cas, r�-estimer le point ... pour trouver un autre point
        // proche mais plus pr�cis
        pt = pts_trouves[i];

        ReEvalue( &pt);

        p1.Init( _x+pt.x, _y+pt.y, _z+pt.z);
        p1.rayon = 1.0;
        p1.proba = 1.0;
        crest ->AddPoint( _x,_y,_z, p1); 

        switch ( _face ){
	    case 0: 
              Si _z>0 AlorsFait crest->AddPoint( _x,   _y,   _z-1, p1);  
            break;
	    case 1: 
              Si _y>0 AlorsFait crest->AddPoint( _x,   _y-1, _z,   p1);  
            break;
	    case 2: 
              Si _x>0 AlorsFait crest->AddPoint( _x-1, _y,   _z,   p1);  
            break;
        } // end switch

      FinPour

    FinSi

  FinPour // _face

  FinMethode();
  return zero_detecte;

} // CalculZeros()


//---------------------------------------------------------------------------
float CalculBoule :: GradZero(  Vect3D<double> *vep, 
//                             --------
					  double* vap,
					  int x, int y, int z)
{

  MethodeCourante("GradZero", ce_fichier);

  
    int          zero_detecte;
    int          sommet,x1,y1,z1;

//  printf(" Debut GradZero\n");

  _x = x;
  _y = y;
  _z = z;

  zero_detecte = false;

  Si ( x < image->_tx - 1 ) Et
     ( y < image->_ty - 1 ) Et
     ( z < image->_tz - 1 ) Et
     ( vap[0] < -1 )        Et
     ( vap[1] < -1 )        Et
     ( vap[2] < -1 ) 
  Alors

    // Pour les images de GE, si l'un des points a une intensit� nulle,
    // je ne considere pas le point en question
    Si fabs((*image)(x  ,y  ,z  )) < 1E-5 Ou
       fabs((*image)(x+1,y  ,z  )) < 1E-5 Ou
       fabs((*image)(x  ,y+1,z  )) < 1E-5 Ou
       fabs((*image)(x+1,y+1,z  )) < 1E-5 Ou
       fabs((*image)(x  ,y  ,z+1)) < 1E-5 Ou
       fabs((*image)(x+1,y  ,z+1)) < 1E-5 Ou
       fabs((*image)(x  ,y+1,z+1)) < 1E-5 Ou
       fabs((*image)(x+1,y+1,z+1)) < 1E-5  Alors

      FinMethode();
      return -1;
    FinSi

    Pour( sommet, 0, 7)

      x1 = x + _voxel.PosX(sommet);
      y1 = y + _voxel.PosY(sommet);
      z1 = z + _voxel.PosZ(sommet);

      gradient_voisins[sommet].x = (*(*filtre)(IMx_sigma))(x1,y1,z1);
      gradient_voisins[sommet].y = (*(*filtre)(IMy_sigma))(x1,y1,z1);
      gradient_voisins[sommet].z = (*(*filtre)(IMz_sigma))(x1,y1,z1);

    FinPour

    zero_detecte = CalculZeros(0,1, crest_lignes);
    zero_detecte = zero_detecte & CalculZeros(0,2, crest_lignes2);

  FinSi
 
  Si zero_detecte Alors

    FinMethode();
    return 1;

  Sinon

    FinMethode();
    return -3;
  FinSi

  FinMethode();
  return -4;

} // GradZero()
