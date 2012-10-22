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

#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif


#include "Variable.hpp"
#include "Variables.hpp"
#include "FloatMatrix.hpp"
#include "paramlist.h"

//#include <stdio.h>
//#include "DessinImage.hpp"
#include "func_imagebasictools.h"
#include "func_globalstats.h"

//#include "LevelSetsCURVES.h"
//#include "EDPmorpho.h"
#include "Rudin.h"
//#include "localstats.h"
#include "FluidProject.h"
#include "VectorImage2StructuredGrid.h"
#include "InterpolateTransform.h"
#include "Resize.hpp"
#include "Curvatures.h"

#include "Chamfer.h"
//#include "vtkwrap.h"
//#include "Viewer3D.hpp"

#define MAX_SIZE     200


extern int yyERROR;

#include "CommonConfigure.h"
COMMON_VAR_IMPORT unsigned char GB_debug;


InrImage* Func_OpImage( InrImage* im1, InrImage* im2, InrImage* im3,
            char* exprmath,
            int Format = WT_FLOAT);


int AskImage   (  std::string& name);
int AskFilename(  std::string& name);
int AskVarName (   wxWindow* parent, 
                   const std::string title, 
                   const std::string label, 
                   const std::string def, 
                   std::string& name);
int AskSurface (  std::string& name);
int AskScript  (  std::string& name);


//------- Weickert


/**
  * @brief Anisotropic Diffusion using Weickert AOS scheme 
  * use Func_IterateWeickert and Func_EndWeickert
  *
  * @param in input image
  * @param p_sigma Gaussian kernel standard deviation for smoothing
  * @param p_k gradient parameter 
  * @param p_dt evolution step
  * @return InrImage* image that will contain the result
  **/
InrImage* Func_InitWeickert(InrImage* in,
                            float p_sigma,
                            float p_k,
                            float p_dt
                            );

void      Func_IterateWeickert();
int       Func_EndWeickert();


/**
 * @brief Weickert Coherence diffusion
 * use Func_IterateWeickert and Func_EndWeickert
 *
 * @param in input image
 * @param p_sigma first Gaussian convolution
 * @param p_rho second Gaussian convolution
 * @param p_C threshold for the coherence
 * @param p_alpha lowest diffusion coefficient
 * @param p_dt evolution step
 * @return InrImage*
 *
 **/
InrImage* Func_InitWeickertCoherence(InrImage* in,
                     float p_sigma,
                     float p_rho,
                     float p_C,
                     float p_alpha,
                     float p_dt
                     );



//----------------------------------------------------------------------

float        Func_SNR( InrImage* image1, InrImage* image2);

unsigned char      Func_Normalize( InrImage* im1);

float         Func_eccentricity( InrImage* im);

InrImage*    Func_rot2D( InrImage* im, float cx, float cy, float alpha,
             float tx, float ty );

amilab::SurfacePoly* Func_isosurf( InrImage::ptr im, float Threshold, InrImage* mask=NULL,
               int coord_system=0);


InrImage* Func_2DFlux( InrImage* vectors, float radius);

#include "CalculRepCercle.hpp"

InrImage*    Func_CircleIntegration( InrImage* grad, InrImage* vep0,
                     InrImage* vep1, float radius,
                     CalculRepCercle::CircleResponseType type,
                     InrImage* mask);

// Compute the response along the circle using
// the following criteria:
// mean, standard deviation, excentricity of the gradient
// in the cross-section
InrImage*    Func_CircleIntSdExc( InrImage* grad, InrImage* vep0,
                  InrImage* vep1, float radius,
                  InrImage* mask,
                  float th_sd,
                  float th_exc,
                  int pairs_mode,
                  int highest_percentage,
                  CalculRepCercle::CircleResponseType mode);

InrImage*    Func_LocalExtrema( InrImage* im,
                InrImage* vep0,
                InrImage* vep1,
                InrImage* mask,
                int samples=16);

// Connected Components
InrImage*    Func_CC(InrImage* im,  float background_threshold=0, int topology=1);

InrImage*    Func_OutFlux(       InrImage* im);
InrImage*    Func_OutFluxScalar( InrImage* im);

InrImage*    Func_OrientationRatio2D( InrImage* im);

InrImage*    Func_Thinning( InrImage* im, InrImage* criterion, float min_threshold, float max_threshold, int endpoint_type=1) ;

InrImage*    Func_SimplePoints( InrImage* im);

InrImage*    Func_NormalSmoothField( InrImage* im, InrImage* mask = NULL);

void         Func_OrientField( InrImage* im, InrImage* mask);

void         Func_OrientPositive( InrImage* im, InrImage* mask);

InrImage*    Func_DirConnectivity( InrImage* im, InrImage* mask = NULL);

amilab::SurfacePoly* Func_Skeleton2lines( InrImage* im);

amilab::SurfacePoly* Func_SmoothLines( amilab::SurfacePoly* s, float alpha, 
                                       float beta, int n );

amilab::SurfacePoly* Func_SmoothLinesToSplines(amilab::SurfacePoly* s, 
                                               float samplingStep );

amilab::SurfacePoly* Func_ResampleLines( amilab::SurfacePoly* s, float dist );

amilab::SurfacePoly* Func_ConnectLines( amilab::SurfacePoly* s, 
                                        float maxdist, float maxangle );

InrImage*    Func_ThresholdCrossing( InrImage* im, float th);

InrImage*    Func_IsocontourPoints( InrImage* im, float th);

InrImage*    Func_IsosurfDist( InrImage* im, float th);

InrImage*    Func_Convolve( InrImage* in, InrImage* kernel );

InrImage*    Func_ConvolveMask( InrImage* in,
                InrImage* kernel,
                InrImage* mask );

void         Func_Pad( InrImage* im1, InrImage* im2,
               int stepx, int posx,
               int stepy, int posy,
               int stepz, int posz
               );

int          Func_GenRead(char* fname);


InrImage*    Func_ReSlice( InrImage* im1, InrImage* im2, FloatMatrix& m);

InrImage*    Func_Flip( InrImage::ptr& im, int axis);

amilab::SurfacePoly* Func_CreateEllipsoids(InrImage* v1, InrImage* v2, InrImage* v3,
                   int stepx, int stepy, int stepz, int res,
                   InrImage* colors = NULL,
                   InrImage* mask = NULL);


#endif







