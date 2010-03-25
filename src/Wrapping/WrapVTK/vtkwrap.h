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

#include "Viewer3D.hpp"


InrImage*    Func_vtkMedianFilter3D( InrImage* im, int kx, int ky, int kz);

SurfacePoly* Func_vtkMarchingCubes( InrImage* im, float Threshold);

SurfacePoly* Func_decimate( SurfacePoly* , float target_reduction=0.9);

SurfacePoly* Func_vtkSmooth( SurfacePoly*, int numiter );
SurfacePoly* Func_vtkWindowedSinc( SurfacePoly*, int numiter );

void         Func_ApplyvtkSmooth( SurfacePoly* surf , int numiter);

InrImage*    Func_vtkDist( InrImage* im);

//InrImage*    Func_vtkPropDanielsson( InrImage* im, float dmax);
InrImage*    Func_vtkPropDanielsson( InrImage* im, float dmin, float dmax);

InrImage*    Func_vtkPropDaniel2( InrImage* im, float threshold, 
                  float dmin, float dmax);

InrImage*    Func_vtkConvexHull( InrImage* im, int order, float resolution);

InrImage*    Func_vtkIsoContourDist( InrImage* im, float th);

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


InrImage*    Func_vtkSignedBorgefors(InrImage* im, float dmax=10000);

InrImage*    Func_vtkSignedFMDist(   InrImage* im, float dmax=10000);

InrImage*    Func_vtkAnisoGS( InrImage* im, float sigma, float k, float beta, int nb_iter,
                              int nb_threads);

InrImage*    Func_vtkDicomRead( const char*);

InrImage*    Func_vtkMINCRead( const char*);

#endif // _VTKWRAP_H
