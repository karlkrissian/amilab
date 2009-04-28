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
// LevelSets.h
// AMILab
// Karl Krissian
//

#ifndef _LEVELSETSCURVES_H_
#define _LEVELSETSCURVES_H_

#include "inrimage.hpp"

//------- LevelSets (CURVES)

void Func_LevelSets_InitParam(			      
			      float gradtheshold,
			      int   iterations,
			      float attachcoeff,
			      float curvcoeff,
			      float dt,
			      int   ReinitFreq
			      );

// 1: use mean curvature; 0: use min curvature
void Func_LevelSets_SetMeanCurv( int meancurv);

// 1: use affine curvature; 0: use curvature
void Func_LevelSets_SetAffineCurvature( int affcurv);

void Func_LevelSets_SetBalloonScheme( int balloonscheme);

// initialize with a threshold
InrImage* Func_LevelSets_Init(InrImage* in, 
			      float threshold
			      );

// initialize with an image
InrImage* Func_LevelSets_Init(InrImage* in, 
			      InrImage* initimage
			      );

InrImage* Func_LevelSets_GetCurrentOutput();

int      Func_LevelSets_UpdateResult();			      

InrImage* Func_LevelSets_GetAttachVectors( InrImage* in);

void      Func_LevelSetsVelocity( InrImage* vel, float coeff);

void      Func_LevelSetsExpansion( float coeff);

void      Func_LevelSetsExpansionImage( InrImage* im);

void      Func_LevelSetsBandAndTube( int band, int tube);

void      Func_LevelSets_SetDMmethod( int m);

void      Func_LevelSets_SetThreads( int n);

void      Func_LevelSets_SetIsoContourBin( int b);

void      Func_LevelSets_SetProbThreshold( float th);

void      Func_LevelSets_SetIntensityLowThreshold(  float th);
void      Func_LevelSets_SetIntensityHighThreshold( float th);
void      Func_LevelSets_SetProbabilityHighThreshold( float th);

void      Func_LevelSets_SetNumGaussians( int n);
void      Func_LevelSets_SetGaussian( int n, float mean, float sd);

void      Func_LevelSets_SetNumInitPoints( int n);
void      Func_LevelSets_SetInitPoint( int n, int x, int y, int z, int radius);

int       Func_LevelSets_Iterate();

void      Func_LevelSetsGetDistanceMap( InrImage* im);
void      Func_LevelSetsGetCurvatureData( InrImage* im);
void      Func_LevelSetsGetAdvectionData( InrImage* im);
void      Func_LevelSetsGetVelocityData(  InrImage* im);
void      Func_LevelSetsGetExpansionData( InrImage* im);
void      Func_LevelSetsGetSkeleton( InrImage* im);

void      Func_LevelSetsSaveDistMap( int sdm);
void      Func_LevelSetsSaveSecDerGrad( int save);

void      Func_LevelSets_End();

void      Func_LevelSetsSetCurvWeights( InrImage* cw);

void      Func_LevelSetsSetAdvectionField( InrImage* adx, InrImage* ady, InrImage* adz);

#endif // _LEVELSETSCURVES_H_
 
