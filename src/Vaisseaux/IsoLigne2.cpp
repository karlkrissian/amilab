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
// fichier Isoligne2.cpp
//
// Karl Krissian Sophia Antipolis le 25-08-98
//
// A partir de 2x8 valeurs
// cherche l'intersection des isosurfaces � 0
//

#include "style.hpp"
#include "IsoLigne2.hpp"

DebutDeclareC
#include <stdio.h>
FinDeclareC

//============================================================================
//  MEMBRES PRIVES
//============================================================================

static Chaine ce_fichier="IsoLigne2.cpp   ";

//-----------------------------------------------------------------------------------------
/**
    @param      num_face    num�ro de la face.
    @param      val         num�ro des valeurs
    @param      pts_trouves liste des points trouv�s.
 */
int IsoLigne2 :: RechercheLignes( int num_face, num_valeurs val, 
                         LigneFace** lignes_trouvees)
  throw (ErreurDivers)

{
  MethodeCourante("RechercheLignes", ce_fichier);

  
    double val0 = 0, val1 = 0,val2 = 0, pos;
    unsigned char    zero;
    int     nb_pts_trouves;
    PtFace*    pts_zero;
    int     nb_lignes_trouvees;
    LigneFace* lignes_zero;
    int     i,j;
    unsigned char    sommet_dans_liste[4];
    double* valeurs=NULL;
    char        message[100];
    float        a,b,c,d,S,f;

  Pour(i,0,3)
    sommet_dans_liste[i] = false;
  FinSi

  nb_pts_trouves = 0;
  pts_zero = new PtFace[4];

  nb_lignes_trouvees = 0;
  lignes_zero = new LigneFace[4];

  SelonQue val Vaut
    Valeur VALEURS_1:      valeurs = _valeurs1[num_face];    FinValeur
    Valeur VALEURS_2:      valeurs = _valeurs2[num_face];    FinValeur
  FinSelonQue

  // val0 est la valeur au centre pour lever les ambiguites de 4 points detectes
  val0 = valeurs[4];

  // Boucle sur les 4 sommets
  Pour( i, 0, 3)
    j = (i+1)%4;
    zero = false;

    val1 = valeurs[i];
    val2 = valeurs[j];

    // Cas particulier des sommets
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

    // Detection d'une intersection
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

    Si zero Alors
      pos = val1 / (val1+val2);
      Si (pos < 0) Ou (pos > 1) Alors
         delete[] pts_zero;
         delete[] lignes_zero;
         throw ErreurDivers(" pos <0 ou pos > 1");
      FinSi

      pts_zero[nb_pts_trouves].x = _coord_sommet[i].x + 
                                   pos*( _coord_sommet[j].x -_coord_sommet[i].x);
      pts_zero[nb_pts_trouves].y = _coord_sommet[i].y + 
                                   pos*( _coord_sommet[j].y -_coord_sommet[i].y);
      nb_pts_trouves++;
    FinSi

  FinPour // Fin de la boucle sur les sommets

  // Aucun point detecte
  Si nb_pts_trouves == 0 Alors
    delete [] lignes_zero;
    *lignes_trouvees = NULL;
  Autrement

  // un seul point detecte on cree une ligne ne contenant que ce point
  Si nb_pts_trouves == 1 Alors
    lignes_zero[0].p1 = pts_zero[0];
    lignes_zero[0].p2 = pts_zero[0];
    *lignes_trouvees = lignes_zero;
    nb_lignes_trouvees++;
  Autrement

  // 2 points detectes
  Si nb_pts_trouves == 2 Alors
    lignes_zero[0].p1 = pts_zero[0];
    lignes_zero[0].p2 = pts_zero[1];
    *lignes_trouvees = lignes_zero;
    nb_lignes_trouvees++;
  Autrement

  // 4 points detectes: on essaie de lever l'ambiguite
  Si nb_pts_trouves == 4 Alors


    a = valeurs[0];
    b = valeurs[1];
    c = valeurs[2];
    d = valeurs[3];

    S = c+b-d-a;

    Si fabs((double)S)<1E-10 Alors
      fprintf(stderr,"IsoLigne2::RechercheLignes() \t fabsf(S) < 1E-10 \n");
      Pour( i, 0, 3)
        j = (i+1)%4;
        lignes_zero[i].p1 = pts_zero[i];
        lignes_zero[i].p2 = pts_zero[j];
      FinPour
      *lignes_trouvees = lignes_zero;
      nb_lignes_trouvees = 4;
      AfficheWarning( WARNING_DIVERS,"face avec 4 lignes");
    Sinon
      f = a + (c-a)*(b-a)/S;

      // If a and f have the same sign, connect a to d
      Si ((a>0)Et(f>0)) Ou ((a<0)Et(f<0)) Alors
        lignes_zero[0].p1 = pts_zero[0];
        lignes_zero[0].p2 = pts_zero[1];

        lignes_zero[1].p1 = pts_zero[2];
        lignes_zero[1].p2 = pts_zero[3];
      Sinon
        lignes_zero[0].p1 = pts_zero[0];
        lignes_zero[0].p2 = pts_zero[3];

        lignes_zero[1].p1 = pts_zero[1];
        lignes_zero[1].p2 = pts_zero[2];
      FinSi

      *lignes_trouvees = lignes_zero;
      nb_lignes_trouvees = 2;

    FinSi

  /*
    // !!!  BUG  !!! 
    // Je ne peux pas lever l'ambiguite avec la valeur au centre ...
    //
    Si fabs(val0) < EPSILON Alors      // la valeur au centre est trop faible pour lever
      // l'ambiguite
      Pour( i, 0, 3)
        j = (i+1)%4;
        lignes_zero[i].p1 = pts_zero[i];
        lignes_zero[i].p2 = pts_zero[j];
      FinPour
      *lignes_trouvees = lignes_zero;
      nb_lignes_trouvees = 4;
      AfficheWarning( WARNING_DIVERS,"face avec 4 lignes");
    Sinon
      Pour( i, 0, 3)
        j = (i+1)%4;
        // le point i est detecte dans l'arrete (i,j)
        // et le point j dans (j, j+1), on teste donc le
        // changement de signe entre le centre et le sommet j
        Si val0*valeurs[j] < 0 Alors
          lignes_zero[nb_lignes_trouvees].p1 = pts_zero[i];
          lignes_zero[nb_lignes_trouvees].p2 = pts_zero[j];
          nb_lignes_trouvees++;
        FinSi
      FinPour
      *lignes_trouvees = lignes_zero;
      Si nb_lignes_trouvees != 2 AlorsFait
        AfficheWarning(WARNING_DIVERS,"ambiguite levee et nombre lignes != 2 ...");
    FinSi
  */

  // Autrement erreur ...
  Sinon
    sprintf(message, "mauvais nombre de points %d " , nb_pts_trouves);
    AfficheWarning( WARNING_DIVERS, message);
  FinSi

  delete[] pts_zero;
//  delete[] lignes_zero;

  FinMethode();
  return nb_lignes_trouvees;

} // RechercheLignes()


//-----------------------------------------------------------------------------------------
/**
    Recherche le point d'intersection des segments [pt1,pt2] et [pt3,pt4]
    @param      pt_intersection  le r�sultat.
    @return     true si l'intersection existe, false sinon.
 */
unsigned char IsoLigne2 :: Intersection( PtFace pt1, PtFace pt2, 
                       PtFace pt3, PtFace pt4, PtFace* pt_intersection )
{
  MethodeCourante("Intersection", ce_fichier);

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
    throw WarningDivers("D�terminant quasi nul ...");
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
/** <b> Constructeur </b>
 */
IsoLigne2 :: Constructeur IsoLigne2( double** val1, double** val2) 
//
{

  SetNomClasse("IsoLigne2");

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
/** <b> Destructeur </b>
 */
IsoLigne2 :: Destructeur IsoLigne2()
//
{

}


//-----------------------------------------------------------------------------------------
void IsoLigne2 :: FixeValeursFace( int num_face, double* val1, double* val2)
//                          ---------------
{

  _valeurs1[num_face] = val1;
  _valeurs2[num_face] = val2;

} // FixeValeursFace()


//-----------------------------------------------------------------------------------------
/**
    Recherche les points de passage par zero de la face num�ro num_face,
    @param      num_face    num�ro de la face.
    @param      pts_trouves liste des points trouv�s.
    @return     nombre de points trouves ....
 */
int IsoLigne2 :: PointsFace( int num_face, PtPosition* pts_trouves)
//
{
  MethodeCourante("PointsFace", ce_fichier);

   
    int nb_lignes1,nb_lignes2;
    int i,j;
    LigneFace*  lignes1;
    LigneFace*  lignes2;
    PtFace      pt_inter;
    int      nb_pts_trouves;
    unsigned char     points_egaux;


  nb_pts_trouves = 0;

  nb_lignes1 = RechercheLignes( num_face, VALEURS_1, &lignes1);
  Si nb_lignes1==0 Alors
    FinMethode();
    return 0;
  FinSi

  nb_lignes2 = RechercheLignes( num_face, VALEURS_2, &lignes2);
  Si nb_lignes2==0 Alors
    FinMethode();
    return 0;
  FinSi

  // Si un seul point est d�tect� pour val1, alors c'est un sommet null
  // On regarde s'il est nul pour val2
  Si (nb_lignes1 == 1) Et (Distance(lignes1[0].p1,lignes1[0].p2) < EPSILON) Alors
    Pour( j, 0, nb_lignes2 -1)
      Si (Distance(lignes1[0].p1,lignes2[j].p1) < EPSILON) Ou
         (Distance(lignes1[0].p1,lignes2[j].p2) < EPSILON) 
      Alors
        pts_trouves[nb_pts_trouves] = Face2Voxel(num_face, lignes1[0].p1);
        nb_pts_trouves = 1;
        break;
      FinSi
    FinPour
    FinMethode();
    return nb_pts_trouves;    
  FinSi

  // Si un seul point est d�tect� pour val2, alors c'est un sommet null
  // On regarde s'il est nul pour val1
  Si (nb_lignes2 == 1) Et (Distance(lignes2[0].p1,lignes2[0].p2) < EPSILON) Alors
    Pour( i, 0, nb_lignes1 - 1)
      Si (Distance( lignes1[i].p1, lignes2[0].p1) < EPSILON) Ou 
         (Distance( lignes1[i].p2, lignes2[0].p1) < EPSILON) 
      Alors
        pts_trouves[nb_pts_trouves] = Face2Voxel(num_face, lignes2[0].p2);
        nb_pts_trouves = 1;
        break;
      FinSi
    FinPour
    FinMethode();
    return nb_pts_trouves;    
  FinSi

  Pour( i, 0, nb_lignes1 - 1)
  Pour( j, 0, nb_lignes2 - 1)

    points_egaux = false;

    // Si les 2 points sont �gaux, on ajoute le point en question
    Si (Distance( lignes1[i].p1, lignes2[j].p1) < EPSILON) Ou 
       (Distance( lignes1[i].p1, lignes2[j].p2) < EPSILON) Alors
      pts_trouves[nb_pts_trouves] = Face2Voxel( num_face, lignes1[i].p1);
      nb_pts_trouves++;
      points_egaux = true;
    FinSi

    Si (Distance( lignes1[i].p2, lignes2[j].p1) < EPSILON) Ou 
       (Distance( lignes1[i].p2, lignes2[j].p2) < EPSILON) Alors
      pts_trouves[nb_pts_trouves] = Face2Voxel( num_face, lignes1[i].p2);
      nb_pts_trouves++;
      points_egaux = true;
    FinSi

    // Sinon, on cherche l'intersection
    try {
    Si Non(points_egaux) AlorsFait
    Si Intersection( lignes1[i].p1, lignes1[i].p2, 
             lignes2[j].p1, lignes2[j].p2, &pt_inter)
    Alors
      pts_trouves[nb_pts_trouves] = Face2Voxel( num_face, pt_inter);
      nb_pts_trouves++;
    FinSi
    }
    catch ( WarningDivers w)
    {
      FinMethode();
    }  

  FinPour
  FinPour


  delete [] lignes1;
  delete [] lignes2;

  FinMethode();
  return nb_pts_trouves;

} // PointsFace()


//-----------------------------------------------------------------------------------------
/**
  Recherche la ou les lignes ou les deux isosurfaces seuill�es
  � z�ro s'intersectent
  @param      pts_trouves liste des points trouv�s sur les faces.
 */
int IsoLigne2 :: ExtractLignes( PtPosition** pts_trouves)
//                            -------------
  throw (WarningDivers)

{
  MethodeCourante("ExtractLignes", ce_fichier);

  
    int      nb_points_trouves;
    int      i,j,k,n;
    int      nb_points_face[6];
    PtPosition  pts[6][16];
    char        mess[30];
    unsigned char     point_existe;

  nb_points_trouves = 0;

  // Parcours des faces
  Pour( i, 0, 5)
    nb_points_face[i] = PointsFace( i, pts[i]);
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
    throw WarningDivers(mess);
  FinSi

  FinMethode();
  return n;

} // ExtractLignes()
