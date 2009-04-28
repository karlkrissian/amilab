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
//  bruit.hpp
//
// code dans Numerical Recipies of C
//
// But: Creer une librairie pour generer
// un bruit al�atoire verifiant une loi donnee
//


#ifndef _BRUIT_HPP
#define _BRUIT_HPP

#include "style.hpp"
#include "inrimage.hpp"


#define BRUIT_UNIFORME  0
#define BRUIT_GAUSSIEN	1


float ran1(int* idum);
//    ----
// Returns a uniform random deviate between 0.0 and 1.0.
// Set idum to any negative value to initialize or reinitialize the sequence.


float bruit_gaussien(int* idum);
//   --------------
//  return une variable aleatoire qui suit une loi gaussienne
//  de moyenne nulle et d'ecart type 1


float bruit_gaussien(int* idum, float moyenne, float ecart_type);
//   --------------
//  return une variable aleatoire qui suit une loi gaussienne
//  de moyenne et d'ecart type donnes


//===============================================================
class AjouteBruit
//     ===========
{

  int* _idnum;

public:

  Constructeur AjouteBruit();

  Destructeur AjouteBruit();

  void AjouteBruitGaussien(InrImage* im, float moy, float et);


}; // AjouteBruit

#endif // _BRUIT_HPP
