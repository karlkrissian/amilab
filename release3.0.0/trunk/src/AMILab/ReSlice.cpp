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

#include "fonctions.h"

InrImage*    Func_ReSlice( InrImage* im1, InrImage* im2,FloatMatrix& m)
{

  int   x,y,z;
  float xt,yt,zt;
  InrImage* res;

  res = new InrImage(WT_FLOAT,"reslice.ami.gz",im1);

  res->InitImage(0.0);

  res->InitBuffer();
  Pour( z, 0, res->DimZ() - 1)
    Pour( y, 0, res->DimY() - 1)
    Pour( x, 0, res->DimX() - 1)

      xt = m[0][0]*x+m[0][1]*y+m[0][2]*z+m[0][3];
      yt = m[1][0]*x+m[1][1]*y+m[1][2]*z+m[1][3];
      zt = m[2][0]*x+m[2][1]*y+m[2][2]*z+m[2][3];

      res->FixeValeur(im2->InterpLinIntensite(xt,yt,zt));

      res->IncBuffer();

    FinPour
    FinPour

    Si z > 0 Alors 
      printf("\b\b\b");
    Sinon
      printf("Calcul du résultat : ");
    FinSi
    printf("%3d",z); 
    fflush(stdout);
  FinPour

  return res;
}
