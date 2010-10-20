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
 * $Revision: 1.2 $
 * $Log: IsoLigne.hpp,v $
 * Revision 1.2  2005/11/16 14:03:10  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:09  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:11:37  karl
 * Sources code
 *
 * Revision 1.2.0.1  1998/10/02 21:20:54  kkrissia
 * Calcul des centres de vaisseaux
 ***************************************************************************/
//
// fichier IsoLigne.hpp
//
// Karl Krissian Sophia Antipolis le 21-08-98
//
// A partir de 2x8 valeurs
// cherche l'intersection des isosurfaces � 0
//

#ifndef ISOLIGNE_HPP
#define ISOLIGNE_HPP

#include "style.hpp"
#include "Erreurs.hpp"
#include <math.h>
#include <string.h>

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
@name Position
 */
enum { 
  ///
  POS_X = 1,
  ///
  POS_Y = 2,
  ///
  POS_Z = 4
}   Position;



typedef 
/**
@name PtPosition
*/
struct  { 

  ///
  double x;

  ///
  double y;

  ///
  double z;

} PtPosition;


typedef 
/**
@name PtFace
position d'un point � l'int�rieur d'une face
*/
struct  { 

  ///
  double x;

  ///
  double y;

} PtFace;




// -------------------------------------------------------
///   \TEX{  A partir de 2x8 valeurs \\       cherche l'intersection des isosurfaces � 0       \mbox{\epsfig{height=40mm,width=40mm,figure=/u/broca/0/kkrissia/MAKE/TEX/sommets_voxel.ps}} }
class IsoLigne : public GestionErreurs
//     --------
{

  // 8 valeurs
  double* _valeurs1; 

  // 8 valeurs
  double* _valeurs2;

  // 6 faces, 4 positions par face
  int  _face[6][4];

  /** coordonnees de chaque sommet d'une face 
     Une face a son propre syst�me de coordonn�es,
     le premier point (0,0)
     le 2eme          (1,0)
     le 3eme          (1,1)
     le 4eme          (0,1)
  */
  PtFace  _coord_sommet[4]; 

private:

  /** 
     Coordonnees X du sommet num_sommet de la face num_face
  */
  double PosX( int num_face, int num_sommet)
  //         ----
  {

    return (_face[num_face][num_sommet]&POS_X);

  }

  /** 
     Coordonnees Y du sommet num_sommet de la face num_face
  */
  double PosY( int num_face, int num_sommet)
  //         ----
  {
    return ((_face[num_face][num_sommet]&POS_Y)>>1);
  }


  /** 
     Coordonnees Z du sommet num_sommet de la face num_face
  */
  double PosZ( int num_face, int num_sommet)  
  //         ----
  {
    return ((_face[num_face][num_sommet]&POS_Z)>>2);
  }


  /** 
    Convertit les coordonnes de pt0 dans la face num_face
    en coordonnees dans le voxel
  */
  PtPosition Face2Voxel( int num_face, PtFace pt0 );

  /** 
     Initialisation des 4 positions des sommets de la face.
  */
  void InitFace( int num, int s1, int s2, int s3, int s4);
  
  /**
    Distance euclidienne entre les 2 points
   */
  float Distance( PtPosition& pt1, PtPosition& pt2);

  /**
    Distance euclidienne entre les 2 points
   */
  float Distance( PtFace& pt1, PtFace& pt2);

  /**
    Recherche les points de passage par zero de la face num�ro num_face,
    @param      num_face    num�ro de la face.
    @param      pts_trouves liste des points trouv�s.
    @return     nombre de points trouves ....
   */
  int PointsFace( int num_face, PtPosition** pts_trouves);


  /**
    Revoie le num�ro du sommet associ� au point pt
    ou -1 si pt n'est pas un sommet
   */
  int  DetermineSommet( PtFace& pt);


  /**
    Recherche les points ou les valeurs li�es au num�ro 'val'
    s'annulent pour chaque cot� de la face num�ro num_face,
    @param      num_face    num�ro de la face.
    @param      val         num�ro des valeurs
    @param      pts_trouves liste des points trouv�s.
    @return     nombre de points trouv�s: 0,2 ou 4
   */
  int RechercheLignes( int num_face, num_valeurs val, PtFace** pts_trouves);


  /**
    Recherche le point d'intersection des segments [pt1,pt2] et [pt3,pt4]
    @param      pt_intersection  le r�sultat.
    @return     true si l'intersection existe, false sinon.
   */
  unsigned char Intersection( PtFace pt1, PtFace pt2, 
			PtFace pt3, PtFace pt4, PtFace* pt_intersection );
  
    

public:

  /** <b> Constructor </b>
    @param      val1  valeurs 1 sur les 8 sommets du cube.
    @param      val2  valeurs 2 sur les 8 sommets du cube.
   */
   IsoLigne( double* val1, double* val2);

  /** <b> Destructor </b>
   */
  ~IsoLigne();

  /**
    Recherche la ou les lignes ou les deux isosurfaces seuill�es
    � z�ro s'intersectent
    @param      pts_trouves liste des points trouv�s sur les faces.
   */
  int ExtractLignes( PtPosition** pts_trouves);
  //


};


#endif // ISOLIGNE_HPP
