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
/* Projet Epidaure
 * Fichier SNR.c
 *
 * Karl KRISSIAN              ULPGC 21-02-01
 */
 

#include "style.hpp"
#include "inrimage.hpp"


float Func_SNR( InrImage* image1, InrImage* image2)
//     ----
{

   
    double mean1, mean21;
    double var1,   var21;
    double tmp;
    unsigned long  size;


  size = image1->_tx*image1->_ty*image1->_tz;

  Si (unsigned long) (image2->_tx*image2->_ty*image2->_tz) != size Alors
    fprintf(stderr,"The images have different number of points \n");
    return(0);
  FinSi

  image1->InitBuffer();
  mean1 = 0;
  Repeter
    mean1+=image1->ValeurBuffer();
  JusquA Non(image1->IncBuffer()) FinRepeter
  mean1 /= size;

  image1->InitBuffer();
  var1 = 0;
  Repeter
    tmp = image1->ValeurBuffer() - mean1;
    var1+=tmp*tmp;
  JusquA Non(image1->IncBuffer()) FinRepeter
  var1 /= size;

  image1->InitBuffer();
  image2->InitBuffer();
  mean21 = 0;
  Repeter
    mean21 += image2->ValeurBuffer() - image1->ValeurBuffer();
    image2->IncBuffer();
  JusquA Non(image1->IncBuffer()) FinRepeter
  mean21 /= size;

  image1->InitBuffer();
  image2->InitBuffer();
  var21 = 0;
  Repeter
    tmp = image2->ValeurBuffer() - image1->ValeurBuffer() - mean21;
    var21 += tmp*tmp;
    image2->IncBuffer();
  JusquA Non(image1->IncBuffer()) FinRepeter
  var21 /= size;


  printf("\n \t mean I1    = %f \t var I1    = %f \n", mean1, var1  );
  printf(" \t mean I2-I1 = %f \t var I2-I1 = %f \n", mean21,var21 );
  printf(" \t Signal To Noise ratio = %f \n\n", 10* log(var1/var21)/log(10.0));

  return (10* log(var1/var21)/log(10.0));

}
