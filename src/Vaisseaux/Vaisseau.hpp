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
// Description de la classe Vaisseau
// fichier Vaisseau.hpp
//
// Karl KRISSIAN 
//
// Sophia Antipolis le 21-05-97
//

#ifndef _VAISSEAU_HPP
#define _VAISSEAU_HPP

#include "style.hpp"

#define MAX_POINTS 500

//============================================================================
Structure Point3D
//        =======
DebutStructure

  float x,y,z;

FinStructure



//=================================================================
class Vaisseau
//     --------
{

  int   _nb_points;
  Point3D  _trajectoire[MAX_POINTS];
  float     _rayon[MAX_POINTS];

public:

  Constructeur Vaisseau();
  //           --------

  Destructeur Vaisseau();
  //          --------

  void Construit( Point3D depart);
  //   ---------

  unsigned char Contient( Point3D pt);
  //      --------

  float Distance( Point3D pt);
  //   --------

}; // Vaisseau


#endif // _VAISSEAU_HPP
    
