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

#include "inrimage.hpp"
//#include <math.h>
#include "math1.hpp"

double Integral(double beta, double a, double b,double c,double d) 
{
    Si fabsf(c)<1E-4 Alors              
      Si fabsf(a)< 1E-4 Alors           
        return b/d;            
      Sinon                    
        return 0.5*a/d*(b*b/a/a)+b/d*(-b/a); 
      FinSi                    
    Sinon                      
      return a/c*(beta)  +     
             (b*c-a*d)/c/c*(log(fabs(c*beta+d))-log(fabs(d))); 
    FinSi
      
} // Integral()


//----------------------------------------------------------------------
float Func_PositiveArea(float val[4])
//
{

   
    int np; // number of positive points
    int i,j=0;
    float   val1[4];
    float a,b,c,d;
    float i1,i2;

  np = 0;
  Pour(i,0,3)
    Si val[i]>0 AlorsFait np++;
  FinPour

  // Cas 1: tout negatif
  Si np == 0  AlorsFait return 0.0;
 
  // Cas 2: tout positif
  Si np == 4   AlorsFait return 1.0;
 
  // Cas 3: 1 positif 3 negatifs
  Si np == 1 Alors
    // selectionner la valeur positive en 0
    Pour(i,0,3)
      Si val[i]>0 Alors
        j = i;
        break;
      FinSi
    FinPour
    Pour(i,0,3)
      val1[i] = val[(i+j)%4]; 
    FinPour

    a = -(val1[1]-val1[0]);
    b = -val1[0];
    c = (val1[2]-val1[3]-val1[1]+val1[0]);
    d = val1[3]-val1[0];

    return Integral(val1[0]/(val1[0]-val1[1]),
		    a,b,c,d);

  FinSi

  // Cas 4: 3 positifs 1 negatif
  Si np == 3 Alors
    // selectionner la valeur negative en 0
    Pour(i,0,3)
      Si val[i]<=0 Alors
        j = i;
        break;
      FinSi
    FinPour
    Pour(i,0,3)
      val[i] = -val[i]; 
    FinPour
    return 1.0-Func_PositiveArea(val);
  FinSi

  Si np == 2 Alors
    Pour(i,0,3)
      Si (val[i]>0)&&(val[(i+3)%4]<=0) Alors
        j = i;
        break;
      FinSi
    FinPour
    Pour(i,0,3)
      val1[i] = val[(i+j)%4]; 
    FinPour

    // Cas 5: 2 negatifs voisins 2 positifs voisins
    Si val1[1]>0 Alors  

      a = -(val1[1]-val1[0]);
      b = -val1[0];
      c = (val1[2]-val1[3]-val1[1]+val1[0]);
      d = val1[3]-val1[0];

      return Integral(1,a,b,c,d);

    // Cas 6: 2 negatifs opposes 2 positifs opposes
    Sinon

      a = -(val1[1]-val1[0]);
      b = -val1[0];
      c = (val1[2]-val1[3]-val1[1]+val1[0]);
      d = val1[3]-val1[0];

      i1 = Integral(val1[0]/(val1[0]-val1[1]),a,b,c,d);

      Pour(i,0,3)
        val1[i] = val[(i+j+2)%4]; 
      FinPour

      a = -(val1[1]-val1[0]);
      b = -val1[0];
      c = (val1[2]-val1[3]-val1[1]+val1[0]);
      d = val1[3]-val1[0];

      i2 = Integral(val1[0]/(val1[0]-val1[1]),a,b,c,d);

      return i1+i2;

    FinSi
  FinSi

  fprintf(stderr,"Func_PositiveArea() \t case not found \n");
  return 0;
 
} // Func_PositiveArea()


//----------------------------------------------------------------------
float Func_ComputePositiveArea( InrImage* im)
//   ------------------------
{

  
    int x,y;
    float   val[4];
    double sum;

  sum = 0;

  im->InitBuffer();
  
  Pour(y,0,im->_ty-2)
  Pour(x,0,im->_tx-2)

     val[0] = (*im)(x,  y,  0);
     val[1] = (*im)(x+1,y,  0);
     val[2] = (*im)(x+1,y+1,0);
     val[3] = (*im)(x,  y+1,0);
    
     sum += Func_PositiveArea(val);

  FinPour
  FinPour

  return sum;

} // Func_ComputePositiveArea()
