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
// fichier IsoLigne2.hpp
//
// Karl Krissian Sophia Antipolis le 21-08-98
//
// A partir de 2x8 valeurs
// cherche l'intersection des isosurfaces � 0
//

#ifndef ISOLIGNE2_HPP
#define ISOLIGNE2_HPP

#include "style.hpp"

#include <math.h>
#include <string.h>

#include "Erreurs.hpp"
#include "Voxel.hpp"


#ifdef EPSILON
#undef EPSILON
#endif
#define EPSILON 1E-2

//@Include: /u/broca/0/kkrissia/Sources/Prog/Commun/include/Erreurs.doc /u/broca/0/kkrissia/Sources/Prog/Commun/include/chaine.doc 

typedef 
/**
@name num_valeurs
 */
enum { 
  ///
  VALEURS_1,
  ///
  VALEURS_2
}  num_valeurs;


typedef 
/**
@name LigneFace
*/
struct  { 

  ///
  PtFace p1;

  ///
  PtFace p2;

} LigneFace;


// -------------------------------------------------------
/** Recherche des Centre de Vaisseaux par intersection sur 
    les faces d'un voxel des isosufaces � zero de valeurs donnees
*/
class IsoLigne2 : public Voxel
//     ---------
{

  // 6x5 valeurs (5 valeurs par face, 4 sommets + centre pour lever certaines ambiguites)
  double** _valeurs1; 

  //  6x5 valeurs (5 valeurs par face, 4 sommets + centre pour lever certaines ambiguites)
  double** _valeurs2;

private:

  /**
    Revoie le num�ro du sommet associ� au point pt
    ou -1 si pt n'est pas un sommet
   */
  int  DetermineSommet( PtFace& pt);


  /**
    Recherche les lignes ou les valeurs li�es au num�ro 'val'
    s'annulent pour chaque cot� de la face num�ro num_face,
    @param      num_face    num�ro de la face.
    @param      val         num�ro des valeurs
    @param      pts_trouves liste des points trouv�s.
    @return     nombre de lignes trouv�s: 0,1 ou 2
   */
  int RechercheLignes( int num_face, num_valeurs val, LigneFace** lignes_trouvees)
    throw (ErreurDivers);


  /**
    Recherche le point d'intersection des segments [pt1,pt2] et [pt3,pt4]
    @param      pt_intersection  le r�sultat.
    @return     true si l'intersection existe, false sinon.
   */
  unsigned char Intersection( PtFace pt1, PtFace pt2, 
      PtFace pt3, PtFace pt4, PtFace* pt_intersection );
  
    

public:

  /** {\em Constructor }
    @param      val1  valeurs 1 sur les 4 sommets de chaque face.
    @param      val2  valeurs 2 sur les 4 sommets de chaque face.
   */
   IsoLigne2( double** val1, double** val2);

  /** {\em Destructor }
   */
  ~IsoLigne2();


  /** Fixe les valeurs 1 et 2 aux sommets de la face num_face
   */
  void FixeValeursFace( int num_face, double* val1, double* val2);


  /**
    Recherche les points de passage par zero de la face num�ro num_face,
    @param      num_face    num�ro de la face.
    @param      pts_trouves liste des points trouv�s.
    @return     nombre de points trouves ....
   */
  int PointsFace( int num_face, PtPosition* pts_trouves);


  /**
    Recherche la ou les lignes ou les deux isosurfaces seuill�es
    � z�ro s'intersectent
    @param      pts_trouves liste des points trouv�s sur les faces.
   */
  int ExtractLignes( PtPosition** pts_trouves)
    throw (WarningDivers);
  //


};


#endif // ISOLIGNE2_HPP
