//
// C++ Interface: vtkwrap
//
// Description: Wrapping of some vtk functionalities
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _VTKWRAP_H
#define _VTKWRAP_H

//#include "WrapVTKConfigure.h"

//#include "surface.hpp"
class InrImage;
#include "surface.hpp"

//WrapVTK_EXPORT 
  InrImage*    Func_vtkMedianFilter3D( InrImage* im, int kx, int ky, int kz);

//WrapVTK_EXPORT 
  amilab::SurfacePoly* Func_vtkMarchingCubes( InrImage* im, float Threshold);

//WrapVTK_EXPORT 
  amilab::SurfacePoly* Func_decimate( amilab::SurfacePoly* , 
                                      float target_reduction=0.9);

//WrapVTK_EXPORT 
  amilab::SurfacePoly* Func_vtkSmooth( amilab::SurfacePoly*, int numiter );
  
//WrapVTK_EXPORT 
  amilab::SurfacePoly* Func_vtkWindowedSinc( amilab::SurfacePoly*, int numiter );

//WrapVTK_EXPORT 
  void         Func_ApplyvtkSmooth( amilab::SurfacePoly* surf , int numiter);

//WrapVTK_EXPORT 
  InrImage*    Func_vtkDist( InrImage* im);

//InrImage*    Func_vtkPropDanielsson( InrImage* im, float dmax);
//WrapVTK_EXPORT 
  InrImage*    Func_vtkPropDanielsson( InrImage* im, float dmin, float dmax);

//WrapVTK_EXPORT 
  InrImage*    Func_vtkPropDaniel2( InrImage* im, float threshold, 
                  float dmin, float dmax);

//WrapVTK_EXPORT 
  InrImage*    Func_vtkConvexHull( InrImage* im, int order, float resolution);

//WrapVTK_EXPORT 
  InrImage*    Func_vtkIsoContourDist( InrImage* im, float th);

/* moved to ami::vtkFastMarchingFunctions
 * 
InrImage*    Func_vtkFastMarching( InrImage* input, InrImage* init,  
                   float maxtime, int inittype=0);

InrImage*    Func_vtkFastMarchingTarget( InrImage* input, InrImage* init,
                    float maxtime, int x, int y, int z);

InrImage*  Func_vtkFastMarching(  
              InrImage* input, InrImage* init,
              InrImage* track,
              float mean, float sd, float maxtime, 
              int inittype=0);

InrImage*  Func_vtkFastMarching(  
              InrImage* input, InrImage* init,
              InrImage* track,
              float maxtime, 
              int inittype=0);

InrImage*    Func_vtkFastMarching( InrImage* input, InrImage* init,
                    float mean, float sd, float maxtime, 
                    int inittype=0,
                    int evol_scheme = 0);
*/

//WrapVTK_EXPORT 
  InrImage*    Func_vtkSignedBorgefors(InrImage* im, float dmax=10000);

//WrapVTK_EXPORT 
  InrImage*    Func_vtkSignedFMDist(   InrImage* im, float dmax=10000);

//WrapVTK_EXPORT 
  InrImage*    Func_vtkAnisoGS( InrImage* im, float sigma, float k, 
                                float beta, int nb_iter,
                                int nb_threads);

//WrapVTK_EXPORT 
  InrImage*    Func_vtkDicomRead( const char*);

//WrapVTK_EXPORT 
  InrImage*    Func_vtkMINCRead( const char*);

#endif // _VTKWRAP_H
