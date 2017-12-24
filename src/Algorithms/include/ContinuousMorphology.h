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

#ifndef _CONTINUOUSMORPHOLOGY_H_
#define _CONTINUOUSMORPHOLOGY_H_


#include <cmath>
#include "style.hpp"
#include "math1.hpp"
#include "inrimage.hpp"



class ContinuousMorphology {

public:
  enum numerical_scheme {
    SCHEMA_OS    = 1, // Osher    & Sethian
    SCHEMA_BM    = 2, // Brockett & Maragos
    SCHEMA_AUTRE = 3, //
  };
  
  enum operation {
    ERODE     = 1,
    DILATE    = 2,
    OUVERTURE = 3,
    FERMETURE = 4,
  };

private:

  long tx,ty,tz,txy;
  int     Schema;
  //   InrImage*  result;
  float         Imin,Imax;
  unsigned char use_limits;

  float interp( float* buf_image,  int dx, int dy);

  float NormGradient( float* buf_image, int x, int y, int z, float Vitesse);

  double Schema1D( float Dm, float Dp, float F);

  void Iteration( InrImage* image1, InrImage* image2, float dt, int type);

public:

  ContinuousMorphology() : Schema(SCHEMA_BM)
  {
    use_limits=0;
  }

  ~ContinuousMorphology() {}

  void SetScheme(int scheme) { Schema=scheme; }

  void SetLimits(float min, float max) { Imin = min; Imax=max; use_limits=1; }

  InrImage* EDP( InrImage* entree, float taille, float step, operation type);

  InrImage* Dilate(InrImage* entree, float taille, float step);
  InrImage* Erode( InrImage* entree, float taille, float step);
  InrImage* Open(  InrImage* entree, float taille, float step);
  InrImage* Close( InrImage* entree, float taille, float step);

};

#endif // _CONTINUOUSMORPHOLOGY_H_


