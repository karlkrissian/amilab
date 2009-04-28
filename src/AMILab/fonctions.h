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

//#include "AnisoGaussSeidel.h"
//#include "LevelSetsCURVES.h"
#include "EDPmorpho.h"
#include "Rudin.h"
#include "localstats.h"
#include "FluidProject.h"
#include "VectorImage2StructuredGrid.h"
#include "InterpolateTransform.h"
#include "Resize.hpp"

#include "StructureTensor.h"

#include "Chamfer.h"
//#include "vtkwrap.h"
//#include "Viewer3D.hpp"

#define MAX_SIZE     200

#define IDENT_MAX_SIZE 50

extern int yyERROR;
extern unsigned char GB_debug;


class ImageExtent {

  float xmin,xmax,ymin,ymax,zmin,zmax;

  unsigned char mode; // 0: absolute, 1: relative

 public:
  ImageExtent() {
    xmin=xmax=ymin=ymax=zmin=zmax=0;
    mode = 0;
  }

  ImageExtent(int x1,int x2, int y1=0, int y2=0, int z1=0, int z2=0) {
    xmin=x1;
    xmax=x2;
    ymin=y1;
    ymax=y2;
    zmin=z1;
    zmax=z2;
  }

  ImageExtent(float x1,float x2, float y1=0, float y2=0, float z1=0, float z2=0) {
    xmin=x1;
    xmax=x2;
    ymin=y1;
    ymax=y2;
    zmin=z1;
    zmax=z2;
  }

  float Xmin() { return xmin;}
  float Xmax() { return xmax;}
  float Ymin() { return ymin;}
  float Ymax() { return ymax;}
  float Zmin() { return zmin;}
  float Zmax() { return zmax;}

  void SetXmin(float val) {xmin=val;}
  void SetXmax(float val) {xmax=val;}
  void SetYmin(float val) {ymin=val;}
  void SetYmax(float val) {ymax=val;}
  void SetZmin(float val) {zmin=val;}
  void SetZmax(float val) {zmax=val;}

  unsigned char GetMode() {return mode;}
  void SetMode(unsigned char val) {mode = val;}

  void SetRelative( InrImage* im) {
    if (this->GetMode()==0) {
      xmin =  (int) (im->SpaceToVoxelX(xmin)+0.5);
      xmax =  (int) (im->SpaceToVoxelX(xmax)+0.5);
      ymin =  (int) (im->SpaceToVoxelY(ymin)+0.5);
      ymax =  (int) (im->SpaceToVoxelY(ymax)+0.5);
      zmin =  (int) (im->SpaceToVoxelZ(zmin)+0.5);
      zmax =  (int) (im->SpaceToVoxelZ(zmax)+0.5);

      if (xmin<0) xmin=0;
      if (ymin<0) ymin=0;
      if (zmin<0) zmin=0;
      if (xmax>im->DimX()-1) xmax=im->DimX()-1;
      if (ymax>im->DimY()-1) ymax=im->DimY()-1;
      if (zmax>im->DimZ()-1) zmax=im->DimZ()-1;
      if (xmax<xmin) xmax=xmin;
      if (ymax<ymin) ymax=ymin;
      if (zmax<zmin) zmax=zmin;

      if (GB_debug)
        printf("SetRelative (%02.2f->%02.2f, %02.2f->%02.2f, %02.2f->%02.2f) \n",xmin,xmax,ymin,ymax,zmin,zmax);

     mode = 1; // relative mode
    }
  }

  void print() {
    printf("extent [%3.3f:%3.3f] [%3.3f:%3.3f] [%3.3f:%3.3f] \n",xmin,xmax,ymin,ymax,zmin,zmax);
  }
};


//----------------------------------------------------------------------
// Image Stack: Allows operations on images
//
class ImageStack{
//    ----------
  InrImage* _images[MAX_SIZE];
  int       _num;

 public:

  ImageStack()
    {
      _num = 0;
    }

  ~ImageStack()
    {
    }

  void AddImage( char* name);

  void AddImage( InrImage* im)
    {

      if (_num>=MAX_SIZE-1) {
    fprintf(stderr,"ImageStack::AddImage(%s) too many images.\n",im->Nom());
    return;
      }

      _num++;
      _images[_num]=im;
    }

  InrImage* GetLastImage()
    {
      InrImage* tmp;

      tmp=_images[_num];
      _images[_num]=NULL;
      _num--;
      return tmp;
    }
}; // ImageStack



//----------------------------------------------------------------------
// Matrix Stack: Allows operations on matrices
//
class MatrixStack{
//    ----------
  FloatMatrix* _matrices[MAX_SIZE];
  int       _num;

 public:

  MatrixStack()
    {
      _num = 0;
    }

  ~MatrixStack()
    {
    }

  //  void AddMatrix( char* name);

  void AddMatrix( FloatMatrix* m)
    {

      if (_num>=MAX_SIZE-1) {
    fprintf(stderr,"MatrixStack::AddMatrix() too many matrices.\n");
    return;
      }

      _num++;
      _matrices[_num]=m;
    }

  FloatMatrix* GetLastMatrix()
    {
      FloatMatrix* tmp;

      tmp=_matrices[_num];
      _matrices[_num]=NULL;
      _num--;
      return tmp;
    }
}; // MatrixStack



//----------------------------------------------------------------------
// Matrix Stack: Allows operations on matrices
//
class GLTransformStack{
//    ----------
  GLTransfMatrix* _matrices[MAX_SIZE];
  int       _num;

 public:

  GLTransformStack()
    {
      _num = 0;
    }

  ~GLTransformStack()
    {
    }

  //  void AddMatrix( char* name);

  void AddMatrix( GLTransfMatrix* m)
    {

      if (_num>=MAX_SIZE-1) {
    fprintf(stderr,"GLTransformStack::AddMatrix() too many matrices.\n");
    return;
      }

      _num++;
      _matrices[_num]=m;
    }

  GLTransfMatrix* GetLastMatrix()
    {
      GLTransfMatrix* tmp;

      tmp=_matrices[_num];
      _matrices[_num]=NULL;
      _num--;
      return tmp;
    }
}; // GLTransformStack



class SurfStack{

  SurfacePoly* _surf[MAX_SIZE];
  int          _num;

 public:

  SurfStack()
    {
      _num = 0;
    }

  ~SurfStack()
    {
    }

  void AddSurf( char* name);

  void AddSurf( SurfacePoly* surf)
    {

      if (_num>=MAX_SIZE-1) {
        fprintf(stderr,"SurfStack::AddSurf( ) too many surfaces.\n");
        return;
      }

      _num++;
      _surf[_num]=surf;
      if (GB_debug) fprintf(stderr,"SurfStack::AddSurf() %p \n",surf);

    }

  SurfacePoly* GetLastSurf()
    {
      SurfacePoly* tmp;

      tmp=_surf[_num];
      _surf[_num]=NULL;
      _num--;
      return tmp;
    }
}; // SurfStack


InrImage* Func_OpImage( InrImage* im1, InrImage* im2, InrImage* im3,
            char* exprmath,
            int Format = WT_FLOAT);

InrImage* Func_Filter( InrImage* im, float sigma,
               int der_x, int der_y, int der_z);

InrImage* Func_NormGrad( InrImage* im, float sigma, int support=4 );

InrImage* Func_DiscNormGrad( InrImage* im );

InrImage* Func_DiscMeanCurvature( InrImage* im );

InrImage* Func_Gradient( InrImage* im, float sigma );


InrImage* Func_SecDerGrad( InrImage* im, float sigma );

// Don't use voxel size
InrImage* Func_SecDerGrad2( InrImage* im, float sigma );

void      Func_DiscSecDerGrad( InrImage* im, InrImage* Isecder, InrImage* Inormgrad = NULL);


int AskImage(       std::string& name);
int AskVarName(   wxWindow* parent, const string title, const string label, const string def, std::string& name);
int AskSurface(     std::string& name);
int AskScript(      std::string& name);


//------- Weickert

InrImage* Func_InitWeickert(InrImage* in,
                float p_sigma,
                float p_k,
                float p_dt
                );
void      Func_IterateWeickert();
int       Func_EndWeickert();

InrImage* Func_InitWeickertCoherence(InrImage* in,
                     float p_sigma,
                     float p_rho,
                     float p_C,
                     float p_alpha,
                     float p_dt
                     );


//----------- SRAD --------------
//
InrImage* Func_SRAD_qcoeff( InrImage* input);
//         ---------------

InrImage* Func_SRAD( InrImage* input, float dt, int numit, int mode, int neighborhood,
             ImageExtent* extent);
//        ---------

InrImage* Func_SRAD2( InrImage* input, float dt,  int numit, int mode, int neighborhood,
              ImageExtent* extent);
//        ---------

//----------------------------------------------------------------------

float        Func_SNR( InrImage* image1, InrImage* image2);

unsigned char      Func_Normalize( InrImage* im1);

float         Func_eccentricity( InrImage* im);

InrImage*    Func_rot2D( InrImage* im, float cx, float cy, float alpha,
             float tx, float ty );

SurfacePoly* Func_isosurf( InrImage::ptr im, float Threshold, InrImage* mask=NULL,
               int coord_system=0);


unsigned char      Func_HessianMatrix( InrImage* image_initiale,  char* varname,
                 float Sigma,  float Gamma, InrImage* mask);


//
// Get first and second order derivatives:
// H1: 1st eigenvector or eigenvalue of the Hessian matrix
// H2: 2nd eigenvector or eigenvalue of the Hessian matrix
// H3: 3rd eigenvector or eigenvalue of the Hessian matrix
// G : gradient vector
// values: 0 do not save
//         1 save the eigenvector (or vector)
//         2 save the eigenvalue
//         3 save both
//
unsigned char      Func_Derivatives( InrImage* image_initiale,
                   char* varname,
                   float Sigma,
                   float Gamma,
                   InrImage* mask,
                   int _H1,
                   int _H2,int _H3,int _G);


unsigned char      Func_HessianVap( InrImage* image_initiale, char* varname,
                  float Sigma,  float Gamma,
                  InrImage* mask, int vap_num);

InrImage* Func_2DFlux( InrImage* vectors, float radius);

InrImage*    Func_CircleIntegration( InrImage* grad, InrImage* vep0,
                     InrImage* vep1, float radius,
                     int type,
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
                  int mode);

InrImage*    Func_LocalExtrema( InrImage* im,
                InrImage* vep0,
                InrImage* vep1,
                InrImage* mask,
                int samples=16);

unsigned char      Func_Curvatures(  InrImage* im, char* varname, float sigma);
InrImage*    Func_Laplacian(   InrImage* im);

float         Func_PositiveArea(float val[4]);
float         Func_ComputePositiveArea( InrImage* im);

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

SurfacePoly* Func_Skeleton2lines( InrImage* im);

SurfacePoly* Func_SmoothLines( SurfacePoly* s, float alpha, float beta, int n );

SurfacePoly* Func_SmoothLinesToSplines(SurfacePoly* s, float samplingStep );

SurfacePoly* Func_ResampleLines( SurfacePoly* s, float dist );

SurfacePoly* Func_ConnectLines( SurfacePoly* s, float maxdist, float maxangle );

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

unsigned char      Func_Eigen2D( char* varname,
               InrImage* Mxx, InrImage* Mxy,
               InrImage* Myy,
               InrImage* mask = NULL);

unsigned char      Func_Eigen3D( char* varname,
               InrImage* Mxx, InrImage* Mxy, InrImage* Mxz,
               InrImage* Myy, InrImage* Myz, InrImage* Mzz,
               InrImage* mask = NULL);

InrImage*    Func_PropagationDistance(InrImage* input, float max_dist=1000);
InrImage*    Func_PropagationDistance2(InrImage* input, float max_dist=1000);

InrImage*    Func_PropagationDanielsson(InrImage* input, float max_dist=1000);

InrImage*    Func_ReSlice( InrImage* im1, InrImage* im2, FloatMatrix& m);

InrImage*    Func_Flip( InrImage::ptr& im, int axis);

SurfacePoly* Func_CreateEllipsoids(InrImage* v1, InrImage* v2, InrImage* v3,
                   int stepx, int stepy, int stepz, int res,
                   InrImage* colors = NULL,
                   InrImage* mask = NULL);


#endif







