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
// AnisoGaussSeidel.h
// AMILab
// Karl Krissian
//

#ifndef _ANISOGAUSSSEIDEL_H_
#define _ANISOGAUSSSEIDEL_H_


#include "inrimage.hpp"

//------- AnisoGS

void Func_InitAnisoGS(InrImage* in, 
          float p_sigma, 
          float p_k,
          float p_beta
          );

void      Func_SetCoeffAnisoGS(
             float p_tang
             );

void      Func_SetCoeffAnisoGS3D(
         float cmin,
         float cmax
         );

void      Func_SetSmoothedParam( unsigned char sp  );

void      Func_SetLocalStructureMode( int local_struct_mode);
void      Func_SetEigenvaluesMode(    int diff_eigenvalues_mode);

void      Func_AnisoGS_SetNoiseType( int nt);

void      Func_AnisoGS_SetNoiseSD( float noiseSD);

float      Func_AnisoGS_GetNoiseSD( );
float      Func_AnisoGS_GetDAcoeff( );

void      Func_AnisoGS_SetDistanceMap( unsigned char dm  );

void      Func_AnisoGS_SetMask( InrImage* m  );

void      Func_AnisoGS_SetSRAD_ROI( InrImage* subvol  );

void      Func_AnisoGS_SetRNRAD_ROI( InrImage* subvol  );

void      Func_AnisoGS_SetRNRAD_ROI_NEW( InrImage* subvol  );

void      Func_AnisoGS_SetDataCoeff( float datacoeff  );

float      Func_ItereAnisoGS();

float      Func_ItereFlux( InrImage* vect, float coeff);

void      Func_AnisoGS_Setneighborhood( int n);

void      Func_AnisoGS_Setdt( float dt);

int       Func_EndAnisoGS();

InrImage* Func_AnisoGS_GetOutput();

InrImage* Func_AnisoGS_GetDiffusionCoeff();

#endif //  _ANISOGAUSSSEIDEL_H_
