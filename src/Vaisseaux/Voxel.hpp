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
// fichier Voxel.hpp
//
// Karl Krissian Sophia Antipolis le 21-08-98
//
// Gestion d'un voxel et de ces faces

#ifndef VOXEL_HPP
#define VOXEL_HPP

#include "style.hpp"
#include "Erreurs.hpp"
#include <math.h>
#include <string.h>
#include "Coordonnees.hpp"

//@Include: /u/broca/0/kkrissia/Sources/Prog/Commun/include/Erreurs.doc /u/broca/0/kkrissia/Sources/Prog/Commun/include/chaine.doc 

#ifndef EPSILON
#define EPSILON 1E-2
#endif

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
}   EnumPosition;



/**
@name PtPosition
*/
typedef Point_3D<double> PtPosition;


/*
struct  { 

  ///
  double x;

  ///
  double y;

  ///
  double z;

} PtPosition;
*/


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
///   \TEX{  A partir de 2x4x6 valeurs \\   face 0 : 0 1 3 2\\   face 1 : 0 1 5 4\\   face 2 : 0 2 6 4\\   face 3 : 4 5 7 6\\    face 4 : 2 3 7 6\\   face 5 : 1 3 7 5\\    cherche l'intersection des isosurfaces � 0       \mbox{\epsfig{height=40mm,width=40mm,figure=/u/broca/0/kkrissia/MAKE/TEX/sommets_voxel.ps}} } 
class Voxel : public GestionErreurs
//     --------
{

protected:

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
    Revoie le num�ro du sommet associ� au point pt
    ou -1 si pt n'est pas un sommet
   */
  int  DetermineSommet( PtFace& pt);


public:

//@{
  /** {\em Constructeur }
   */
  Constructeur Voxel( );

  /** {\em Destructeur }
   */
  Destructeur Voxel();
//@}

//@{
  /** 
     Coordonnees X du sommet num_sommet de la face num_face
  */
  int PosX( int num_face, int num_sommet)
  //     ----
  {
    return (_face[num_face][num_sommet]&POS_X);
  }

  /** 
     Coordonnees Y du sommet num_sommet de la face num_face
  */
  int PosY( int num_face, int num_sommet)
  //     ----
  {
    return ((_face[num_face][num_sommet]&POS_Y)>>1);
  }


  /** 
     Coordonnees Z du sommet num_sommet de la face num_face
  */
  int PosZ( int num_face, int num_sommet)  
  //     ----
  {
    return ((_face[num_face][num_sommet]&POS_Z)>>2);
  }
//@}

//@{
  /** 
     Coordonnees X du sommet num_sommet 
  */
  int PosX( int num_sommet)
  //     ----
  {
    return (num_sommet&POS_X);
  }

  /** 
     Coordonnees Y du sommet num_sommet 
  */
  int PosY( int num_sommet)
  //     ----
  {
    return ((num_sommet&POS_Y)>>1);
  }


  /** 
     Coordonnees Z du sommet num_sommet 
  */
  int PosZ( int num_sommet)  
  //     ----
  {
    return ((num_sommet&POS_Z)>>2);
  }
//@}

  /** 
     Numero dans le voxel du sommet {\it num_sommet} de la face {\it num_face}.
  */
  int NumSommet( int num_face, int num_sommet)  
  //     ---------
  {
    return (_face[num_face][num_sommet]);
  }
  

};


#endif // VOXEL_HPP
