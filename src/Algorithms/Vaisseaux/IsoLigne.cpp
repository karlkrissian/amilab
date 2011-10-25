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
//
// fichier IsoLigne.cpp
//
// Karl Krissian Sophia Antipolis le 25-08-98
//
// A partir de 2x8 valeurs
// cherche l'intersection des isosurfaces � 0
//

#include "style.hpp"
#include <stdio.h>

#include "IsoLigne.hpp"


//============================================================================
//  MEMBRES PRIVES
//============================================================================

//-----------------------------------------------------------------------------------------
// 
PtPosition IsoLigne :: Face2Voxel( int num_face, PtFace pt0 )
//
{

  
    PtPosition pt;

  pt.x = PosX(num_face,0) +  pt0.x * (PosX(num_face,1) - PosX(num_face,0)) +
                             pt0.y * (PosX(num_face,3) - PosX(num_face,0));
  pt.y = PosY(num_face,0) +  pt0.x * (PosY(num_face,1) - PosY(num_face,0)) +
                             pt0.y * (PosY(num_face,3) - PosY(num_face,0));
  pt.z = PosZ(num_face,0) +  pt0.x * (PosZ(num_face,1) - PosZ(num_face,0)) +
                             pt0.y * (PosZ(num_face,3) - PosZ(num_face,0));

  return pt;

} // Face2Voxel()
  

//-----------------------------------------------------------------------------------------
// Initialisation des 4 positions des sommets de la face
void IsoLigne :: InitFace( int num, int s1, int s2, int s3, int s4)
//
{

  _face[num][0] = s1;
  _face[num][1] = s2;
  _face[num][2] = s3;
  _face[num][3] = s4;

} // InitFace()
  

//-----------------------------------------------------------------------------------------
//
float IsoLigne :: Distance( PtPosition& pt1, PtPosition& pt2)
//
{

  return (float) sqrt( (pt1.x-pt2.x)*(pt1.x-pt2.x) +
                 (pt1.y-pt2.y)*(pt1.y-pt2.y) +
                 (pt1.z-pt2.z)*(pt1.z-pt2.z) 
               );

} // Distance()


//-----------------------------------------------------------------------------------------
/**
  Distance euclidienne entre les 2 points
 */
float IsoLigne :: Distance( PtFace& pt1, PtFace& pt2)
//
{

  return (float) sqrt( (pt1.x-pt2.x)*(pt1.x-pt2.x) +
                 (pt1.y-pt2.y)*(pt1.y-pt2.y) 
               );

} // Distance()


//-----------------------------------------------------------------------------------------
/**
  Revoie le num�ro du sommet associ� au point pt
  ou -1 si pt n'est pas un sommet
 */
int IsoLigne :: DetermineSommet( PtFace& pt)
//
{

  Si fabs(pt.x) < EPSILON Alors
    Si fabs(pt.y) < EPSILON Alors
      return 0;
    Autrement
    Si fabs(pt.y-1) < EPSILON Alors
      return 3;
    Sinon
      return -1;
    FinSi
  Autrement
  Si fabs(pt.x-1) < EPSILON Alors
    Si fabs(pt.y) < EPSILON Alors
      return 1;
    Autrement
    Si fabs(pt.y-1) < EPSILON Alors
      return 2;
    Sinon
      return -1;
    FinSi
  Sinon
    return -1;
  FinSi

} // DetermineSommet()



//-----------------------------------------------------------------------------------------
/**
    Recherche les points de passage par zero de la face num�ro num_face,
    @param      num_face    num�ro de la face.
    @param      pts_trouves liste des points trouv�s.
    @return     nombre de points trouves ....
 */
int IsoLigne :: PointsFace( int num_face, PtPosition** pts_trouves)
//
{
  MethodeCourante("PointsFace");

   
    int n1,n2;
    int nb_lignes1,nb_lignes2;
    int i,j;
    PtFace*     pts1;
    PtFace*     pts2;
    PtFace      pt_inter;
    PtPosition* pts_trouves1;
    int      nb_pts_trouves;
//    char        texte[100];
//    char        mess[300];
    unsigned char     points_egaux;


  nb_pts_trouves = 0;
  pts1         = new PtFace[4];
  pts2         = new PtFace[4];
  pts_trouves1 = new PtPosition[8];

  n1 = RechercheLignes( num_face, VALEURS_1, & pts1);
  Si n1==0 Alors
    FinMethode();
    return 0;
  FinSi

  n2 = RechercheLignes( num_face, VALEURS_2, &pts2);
  Si n2==0 Alors
    FinMethode();
    return 0;
  FinSi

  Si n1==4 Ou n2 == 4 Alors
    AfficheWarning(WARNING_DIVERS," n1==4 ou n2 == 4");
  FinSi

  // Si un seul point est d�tect� pour val1, alors c'est un sommet null
  // On regarde s'il est nul pour val2
  Si n1 == 1 Alors
    Pour( j, 0, n2 - 1)
      Si (Distance(pts1[0],pts2[j]) < EPSILON) Alors
        pts_trouves1[nb_pts_trouves] = Face2Voxel(num_face, pts1[0]);
        nb_pts_trouves = 1;
        break;
      FinSi
    FinPour
    FinMethode();
    *pts_trouves = pts_trouves1;
    return nb_pts_trouves;    
  FinSi

  // Si un seul point est d�tect� pour val2, alors c'est un sommet null
  // On regarde s'il est nul pour val1
  Si n2 == 1 Alors
    Pour( i, 0, n1 - 1)
      Si (Distance(pts1[i],pts2[0]) < EPSILON) Alors
        pts_trouves1[nb_pts_trouves] = Face2Voxel(num_face, pts2[0]);
        nb_pts_trouves = 1;
        break;
      FinSi
    FinPour
    FinMethode();
    *pts_trouves = pts_trouves1;
    return nb_pts_trouves;    
  FinSi

  nb_lignes1 = n1 - 1;
  nb_lignes2 = n2 - 1;
  
  Pour( i, 0, nb_lignes1 - 1)
  Pour( j, 0, nb_lignes2 - 1)
    points_egaux = false;

    // Si les 2 points sont �gaux, on ajoute le point en question
    Si (Distance(pts1[i],pts2[j       ]) < EPSILON) Ou 
       (Distance(pts1[i],pts2[(j+1)%n2]) < EPSILON) Alors
      pts_trouves1[nb_pts_trouves] = Face2Voxel( num_face, pts1[i]);
      nb_pts_trouves++;
      points_egaux = true;
    FinSi

    Si (Distance(pts1[(i+1)%n1],pts2[j       ]) < EPSILON) Ou 
       (Distance(pts1[(i+1)%n1],pts2[(j+1)%n2]) < EPSILON) Alors
      pts_trouves1[nb_pts_trouves] = Face2Voxel( num_face, pts1[(i+1)%n1]);
      nb_pts_trouves++;
      points_egaux = true;
    FinSi

    // Sinon, on cherche l'intersection
    Si Non(points_egaux) AlorsFait
    Si Intersection( pts1[i], pts1[(i+1) % n1], pts2[j], pts2[(j+1) % n2], &pt_inter)
    Alors
      pts_trouves1[nb_pts_trouves] = Face2Voxel( num_face, pt_inter);
      nb_pts_trouves++;
    FinSi

  FinPour
  FinPour

  Si nb_pts_trouves > 0 Alors
    *pts_trouves = pts_trouves1;
  Sinon
    delete [] pts_trouves1;
    *pts_trouves = NULL;
  FinSi

  delete [] pts1;
  delete [] pts2;

  FinMethode();
  return nb_pts_trouves;

} // PointsFace()



//-----------------------------------------------------------------------------------------
/**
    Recherche les points o� les valeurs li�es au num�ro 'val'
    s'annulent sur un c�t� de la face num�ro num_face,
    @param      num_face    num�ro de la face.
    @param      val         num�ro des valeurs
    @param      pts_trouves liste des points trouv�s.
    @return     nombre de points trouv�s : 0,2 ou 4
 */
int IsoLigne :: RechercheLignes( int num_face, num_valeurs val, 
					     PtFace** pts_trouves)
//
{
  MethodeCourante("RechercheLignes");

  
    int     nb_pts_trouves;
    double val1 = 0,val2 = 0, pos;
    unsigned char    zero;
    PtFace*    pts_zero;
    int     i,j;
    unsigned char    sommet_dans_liste[4];

  Pour(i,0,3)
    sommet_dans_liste[i] = false;
  FinSi

  nb_pts_trouves = 0;
  pts_zero = new PtFace[4];

  Pour( i, 0, 3)
    j = (i+1)%4;
    zero = false;

    switch ( val ){
      case VALEURS_1:
        val1 = _valeurs1[_face[num_face][i]];
        val2 = _valeurs1[_face[num_face][j]];
      break;

      case VALEURS_2:
        val1 = _valeurs2[_face[num_face][i]];
        val2 = _valeurs2[_face[num_face][j]];
      break;
    } // end switch

    Si val1 > EPSILON Alors
      Si val2 < -EPSILON Alors
        zero = true;
        val2 = -val2;
      FinSi
    FinSi

    Si val1 < -EPSILON Alors
      Si val2 > EPSILON Alors
        zero = true;
        val1 = -val1;
      FinSi
    FinSi

    Si (fabs(val1) < EPSILON) Et (Non(sommet_dans_liste[i]))
    Alors
      pts_zero[nb_pts_trouves].x = _coord_sommet[i].x; 
      pts_zero[nb_pts_trouves].y = _coord_sommet[i].y;
      nb_pts_trouves++;
      sommet_dans_liste[i] = true;
    FinSi

    Si (fabs(val2) < EPSILON) Et (Non(sommet_dans_liste[j]))
    Alors
      pts_zero[nb_pts_trouves].x = _coord_sommet[j].x; 
      pts_zero[nb_pts_trouves].y = _coord_sommet[j].y;
      nb_pts_trouves++;
      sommet_dans_liste[j] = true;
    FinSi

    Si zero Alors
      pos = val1 / (val1+val2);
      Si (pos < 0) Ou (pos > 1) AlorsFait
        AfficheErreur(ERREUR_DIVERS," pos <0 ou pos > 1");
      pts_zero[nb_pts_trouves].x = _coord_sommet[i].x + 
                                   pos*( _coord_sommet[j].x -_coord_sommet[i].x);
      pts_zero[nb_pts_trouves].y = _coord_sommet[i].y + 
                                   pos*( _coord_sommet[j].y -_coord_sommet[i].y);
      nb_pts_trouves++;
    FinSi

  FinPour

  Si nb_pts_trouves == 0 Alors
    delete [] pts_zero;
    *pts_trouves = NULL;
  Sinon
    *pts_trouves = pts_zero;
  FinSi

  Si (nb_pts_trouves > 4) Alors
    AfficheErreur(ERREUR_DIVERS,"mauvais nombre de points");
    FinMethode();
    return 0;
  FinSi

  FinMethode();
  return nb_pts_trouves;

} // RechercheLignes()


//-----------------------------------------------------------------------------------------
/**
    Recherche le point d'intersection des segments [pt1,pt2] et [pt3,pt4]
    @param      pt_intersection  le r�sultat.
    @return     true si l'intersection existe, false sinon.
 */
unsigned char IsoLigne :: Intersection( PtFace pt1, PtFace pt2, 
					   PtFace pt3, PtFace pt4, PtFace* pt_intersection )
{
  MethodeCourante("Intersection");

// R�solution du syst�me 
// a1 x + b1 y = c1
// a2 x + b2 y = c2
//

  
    double a1,b1,c1;
    double a2,b2,c2;
    double det; // D�terminant du syst�me

  a1 = pt2.y -pt1.y;
  b1 = -(pt2.x -pt1.x);
  c1 = pt1.x * a1 + pt1.y * b1;

  a2 = pt4.y -pt3.y;
  b2 = -(pt4.x -pt3.x);
  c2 = pt3.x * a2 + pt3.y * b2;

  det = a1*b2 - a2*b1;

  Si fabs(det) < EPSILON Alors
    AfficheErreur(ERREUR_DIVERS,"D�terminant quasi nul ...");
    FinMethode();
    return false;
  FinSi

  // La matrice inverse:
  //          ( b2   -b1 ) 
  // 1/det *  ( -a2  a1  )

  pt_intersection->x = (c1 * b2  - c2* b1) / det;
  pt_intersection->y = (c1 * -a2 + c2* a1) / det;

  Si (pt_intersection->x < -EPSILON) Ou (pt_intersection->x > 1+EPSILON) Ou
     (pt_intersection->y < -EPSILON) Ou (pt_intersection->y > 1+EPSILON) 
  Alors
    FinMethode();
    return false;
  FinSi

  FinMethode();
  return true;

} // Intersection()

    

//============================================================================
//  MEMBRES PUBLICS
//============================================================================


//-----------------------------------------------------------------------------------------
/** <b> Constructor </b>
 */
IsoLigne ::  IsoLigne( double* val1, double* val2) 
  : GestionErreurs("IsoLigne")
//
{

  _valeurs1 = val1;
  _valeurs2 = val2;

  // Initialisation des 6 faces
  InitFace(0,0,1,3,2);
  InitFace(1,0,1,5,4);
  InitFace(2,0,2,6,4);
  InitFace(3,4,5,7,6);
  InitFace(4,2,3,7,6);
  InitFace(5,1,3,7,5);

  _coord_sommet[0].x = 0;
  _coord_sommet[0].y = 0;

  _coord_sommet[1].x = 1;
  _coord_sommet[1].y = 0;

  _coord_sommet[2].x = 1;
  _coord_sommet[2].y = 1;

  _coord_sommet[3].x = 0;
  _coord_sommet[3].y = 1;

}


//-----------------------------------------------------------------------------------------
/** <b> Destructor </b>
 */
IsoLigne :: ~IsoLigne()
//
{

}


//-----------------------------------------------------------------------------------------
/**
  Recherche la ou les lignes ou les deux isosurfaces seuill�es
  � z�ro s'intersectent
  @param      pts_trouves liste des points trouv�s sur les faces.
 */
int IsoLigne :: ExtractLignes( PtPosition** pts_trouves)
//                           -------------
{
  MethodeCourante("ExtractLignes");

  
    int      nb_points_trouves;
    int      i,j,k,n;
    int      nb_points_face[6];
    PtPosition* pts[6];
    char        mess[30];
    unsigned char     point_existe;

  nb_points_trouves = 0;

  // Parcours des faces
  Pour( i, 0, 5)
    nb_points_face[i] = PointsFace( i, &pts[i]);
    nb_points_trouves += nb_points_face[i];
  FinPour

  *pts_trouves = new PtPosition[ nb_points_trouves ];
  n = 0;
  Pour( i, 0, 5)
    Pour(j, 0, nb_points_face[i]-1)
      // On v�rifie que le point n'existe pas d�j�
      point_existe = false;
      k = 0;
      TantQue (k <n)Et(Non(point_existe)) Faire
        point_existe = ( Distance( (*pts_trouves)[k], pts[i][j]) < 0.01 );
        k++;
      FinTantQue
      Si Non(point_existe) AlorsFait (*pts_trouves)[n++] = pts[i][j];
    FinPour
  FinPour

  Si (n != 0) Et (n != 2) Alors
    sprintf(mess," Nombre de points trouves : %d",n);
    AfficheWarning(WARNING_DIVERS,mess);
  FinSi

  FinMethode();
  return n;

} // ExtractLignes()
