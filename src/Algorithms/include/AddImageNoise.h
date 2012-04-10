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
//  AddImageNoise.h
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

namespace ami {

//===============================================================
class AddImageNoise
//     ===========
{

private:
   AddImageNoise() {}

public:
  
  static void InitRand(int* _idnum);
  
  /**
   * @brief Returns a uniform random deviate between 0.0 and 1.0.
   *
   * @param idum Set idum to any negative value to initialize or reinitialize the sequence.
   * @return float
   **/
  static float ran1(int* idum);


  /**
   * @brief return une variable aleatoire qui suit une loi gaussienne de 
   * moyenne nulle et d'ecart type 1.
   *
   * @param idum ...
   * @return float
   **/
  static float bruit_gaussien(int* idum);


  /**
   * @brief return une variable aleatoire qui suit une loi gaussienne
   *  de moyenne et d'ecart type donnes
   *
   * @param idum ...
   * @param moyenne ...
   * @param ecart_type ...
   * @return float
   **/
  static float bruit_gaussien(int* idum, float moyenne, float ecart_type);

public:

  /**
   * @brief Add Gaussian Noise to the image
   *
   * @param im input image
   * @param moy mean of the Gaussian
   * @param et standard deviation of the Gaussian
   * @return void
   **/
  static void AddGaussianNoise(InrImage* im, float moy, float et);
  
  /**
   * @brief Add uniformly distributed noise between 0 and valmax
   *
   * @param im ...
   * @param valmax ...
   * @return void
   **/
  static void AddUniformNoise(InrImage* im, float valmax);
  
  /**
   * @brief Adds Salt and Pepper Noise to the image
   *
   * @param im input image
   * @param salt salt probability low threshold in [0,1]
   * @param pepper pepper probability high threshold in [0,1]
   * @param imin minimal intensity for pepper noise
   * @param imax maximal intensity for salt noise
   * @return void 
   **/
  static void AddSaltAndPepper(InrImage* im, double pepper, double salt,
                               double imin=0, double imax=255);


}; // AddImageNoise

} // namespace ami

#endif // _BRUIT_HPP
