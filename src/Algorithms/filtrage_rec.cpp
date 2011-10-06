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
 * $Log: filtrage_rec.cpp,v $
 * Revision 1.2  2005/11/16 14:03:08  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1  2000/10/02 17:03:53  karl
 * *** empty log message ***
 *
 *
 */

#include "filtrage_rec.hpp"

#include "CommonConfigure.h"
COMMON_VAR_IMPORT unsigned char GB_verbose;

//--------------------------------------------------
void FiltrageRec :: 
     FiltreRecX( float* entree, double mu, double lambda)
//   ----------
{

  
    register int      i;
    register float*       entree1;
    register float*       entree2;
    register double  coeff,val;
  
//  printf("FiltreRecX() \n");

  entree1 = entree;
  entree2 = entree+pas_x;

  (*entree1) /= (1.0 - mu);

  Pour(i,1,tx-2)
    (*entree2) = (*entree2) + mu*(*entree1);
    entree1 = entree2;
    entree2+=pas_x;
  FinPour

  val = (*entree2);
  (*entree2) = (*entree2) + mu*(*entree1);

  entree1 = entree2;
  entree2 = entree1-pas_x;

  (*entree1) = (*entree1)/(1.0-mu*mu) + val*mu/(1.0-mu)/(1.0-mu*mu);

  Pour(i,1,tx-1)
    (*entree2) = (*entree2) + mu*(*entree1);
    entree1  = entree2;
    entree2 -= pas_x;
  FinPour

  coeff = mu/lambda;

  entree2 = entree;

  Pour(i,0,tx-1)
    (*entree2) *= coeff;
    entree2 += pas_x;
  FinPour  

} // FiltreRecX()


//--------------------------------------------------
void FiltrageRec :: 
     FiltreRecY( float* entree, double mu, double lambda)
//   ----------
{

  
    register int      i;
    register float*       entree1;
    register float*       entree2;
    register double  coeff,val;
  
//  printf("FiltreRecY() \n");

  entree1 = entree;
  entree2 = entree+pas_y;

  (*entree1) /= (1.0 - mu);

  Pour(i,1,ty-2)
    (*entree2) = (*entree2) + mu*(*entree1);
    entree1  = entree2;
    entree2 += pas_y;
  FinPour

  val = (*entree2);
  (*entree2) = (*entree2) + mu*(*entree1);

  entree1 = entree2;
  entree2 = entree1-pas_y;

  (*entree1) = (*entree1)/(1.0-mu*mu) + val*mu/(1.0-mu)/(1.0-mu*mu);

  Pour(i,1,ty-1)
    (*entree2) = (*entree2) + mu*(*entree1);
    entree1  = entree2;
    entree2 -= pas_y;
  FinPour

  coeff = mu/lambda;

  entree2 = entree;

  Pour(i,0,ty-1)
    (*entree2) *= coeff;
    entree2 += pas_y;
  FinPour  

} // FiltreRecY()



//--------------------------------------------------
void FiltrageRec :: 
     FiltreRecZ( float* entree, double mu, double lambda)
//   ----------
{

  
    register int      i;
    register float*       entree1;
    register float*       entree2;
    register double  coeff,val;
  
//  printf("FiltreRecZ() \n");

  entree1 = entree;
  entree2 = entree+pas_z;
  
  (*entree1) /= (1.0 - mu);

  Pour(i,1,tz-2)
    (*entree2) = (*entree2) + mu*(*entree1);
    entree1  = entree2;
    entree2 += pas_z;
  FinPour

  val = (*entree2);
  (*entree2) = (*entree2) + mu*(*entree1);

  entree1 = entree2;
  entree2 = entree1-pas_z;

  (*entree1) = (*entree1)/(1.0-mu*mu) + val*mu/(1.0-mu)/(1.0-mu*mu);

  Pour(i,1,tz-1)
    (*entree2) = (*entree2) + mu*(*entree1);
    entree1  = entree2;
    entree2 -= pas_z;
  FinPour

  coeff = mu/lambda;

  entree2 = entree;

  Pour(i,0,tz-1)
    (*entree2) *= coeff;
    entree2 += pas_z;
  FinPour  

} // FiltreRecZ()


//--------------------------------------------------
void FiltrageRec ::
     Filtre( float sigma, int nb_iter)
//   ------
{

  
    register float*       entree;
    int   x,y,z;
    int   i; 
    double mu;
    float       lambda;

  lambda = sigma*sigma/(2.0*nb_iter);

  mu = (1.0+2.0*lambda-sqrt(1.0+4.0*lambda))/(2.0*lambda);
  printf("mu = %f \n", mu);

  Pour(i,1,nb_iter)

    Si GB_verbose Alors
      Si i==1 Alors
        printf("i = %3d",i);
        fflush(stdout);
      Sinon 
        printf("\b\b\b");
        printf("%3d",i);
        fflush(stdout);
      FinSi
    FinSi

    entree = (float*) _image->Buffer();
 
    Pour(z,0,tz-1)
    Pour(y,0,ty-1)

      FiltreRecX(entree, mu, lambda);

      entree += tx;

    FinPour
    FinPour


    Pour(z,0,tz-1)
    Pour(x,0,tx-1)

      _image->BufferPos(x,0,z);
      entree = (float*) _image->BufferPtr();

      FiltreRecY(entree, mu, lambda);

    FinPour
    FinPour

    Si tz>1 Alors
      Pour(y,0,ty-1)
      Pour(x,0,tx-1)

        _image->BufferPos(x,y,0);
        entree = (float*) _image->BufferPtr();

        FiltreRecZ(entree, mu, lambda);

      FinPour
      FinPour
    FinSi

  FinPour

} // GeneralGaussianFilter()
