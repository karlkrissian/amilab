//
// C++ Implementation: wrapAMIFluid
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "paramlist.h"
#include "surface.hpp"
using namespace amilab;

#include "VarContexts.hpp"
#include "wrapfunctions.hpp" 
#include "wrapVTK.h"
#include "vtk_common.h"

#include "wrap_SurfacePoly.h"

extern VarContexts  Vars;

#ifndef _WITHOUT_VTK_

// all the needed vtk files

// standard VTK
#include "vtkPolyData.h"
#include "vtkPoints.h"
#include "vtkCellArray.h"
#include "vtkDecimate.h"
#include "vtkTriangleFilter.h"
#include "vtkImageMarchingCubes.h"
#include "vtkSmoothPolyDataFilter.h"
#include "vtkWindowedSincPolyDataFilter.h"
#include "vtkPolyDataWriter.h"
#include "vtkImageCityBlockDistance.h"
#include "vtkImageMedian3D.h"
#include "vtkDICOMImageReader.h"
#include "vtkSphereSource.h"

// files from myVTK library
#include "vtkMINCImageReader.h"
#include "vtkImageIsoContourDist.h"
#include "vtkImageFastSignedChamfer.h"
#include "vtkLevelSetFastMarching.h"
#include "vtkImagePropagateDist.h"
#include "vtkImagePropagateDist2.h"
#include "vtkConvexHull.h"
#include "vtkAnisoGaussSeidel.h"
#include "vtkSkeleton2Lines.h"

#include "vtkwrap.h"

#endif // _WITHOUT_VTK_



//---------------------------------------------------------
void AddWrapVTK()
{

  ADDVAR_NAME( C_wrap_imagefunction, "vtkAnisoGaussSeidel",  vtkAnisoGS);

  ADDVAR_NAME( C_wrap_imagefunction, "vtkImageFFT",   wrap_vtkImageFFT);
  ADDVAR_NAME( C_wrap_imagefunction, "vtkImageRFFT",  wrap_vtkImageRFFT);
  ADDVAR_NAME( C_wrap_imagefunction, "vtkImageFourierCenter",  wrap_vtkImageFourierCenter);

  ADDVAR_NAME( C_wrap_imagefunction, "vtkAnisoGaussSeidel",  vtkAnisoGS);
  
  ADDVAR_NAME( C_wrap_varfunction,   "vtkSkeleton2Lines",    Wrap_vtkSkeleton2Lines);
  ADDVAR_NAME(C_wrap_varfunction,    "vtkSphere",            Wrap_vtkSphere);

}


/** Read a 3D Flow from an ASCII file **/
InrImage* vtkAnisoGS(ParamList* p)
{

#ifndef _WITHOUT_VTK_
  char functionname[] = "vtkAnisoGaussSeidel";
  char description[]=" \n\
    Runs Anisotropic Diffusion Filter based on the \n\
    Flux Diffusion and using the Gauss-Seidel\n\
    numerical scheme\n\
      ";
  char parameters[] =" \n\
          Parameters:\n\
              input image\n\
              standard deviation for Gaussian smoothing sigma\n\
              threshold on the gradient magnitude\n\
              data attachment coefficient\n\
              number of iterations\n\
              number of threads (def: 1)\n\
      ";
    
    InrImage* input;
    float sd;
    float threshold;
    float data_coeff;
    int iterations;
    int threads = 1;
    int n=0;

  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(  sd,         p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(  threshold,  p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(  data_coeff, p, n)) HelpAndReturnNULL;
  if (!get_int_param(    iterations, p, n)) HelpAndReturnNULL;
  if (!get_int_param(    threads   , p, n)) HelpAndReturnNULL;


  vtkImageData_ptr                vtk_image;
  InrImage*                       res;
  shared_ptr<vtkAnisoGaussSeidel> vtk_aniso;
  //  printf("1 \n");
  vtk_image = vtk_new<vtkImageData>()((vtkImageData*) (*input));
  //    printf("2 \n");

  vtk_aniso = vtk_new<vtkAnisoGaussSeidel>()();
  vtk_aniso->SetInput(              vtk_image.get());
  vtk_aniso->Setmode(               3);
  vtk_aniso->Setsigma(              sd);
  vtk_aniso->Setk(                  threshold);
  vtk_aniso->Setbeta(               data_coeff);
  vtk_aniso->SetIsoCoeff(           0.2);
  vtk_aniso->SetNumberOfIterations( iterations);
  vtk_aniso->SetNumberOfThreads(    threads);

  vtk_aniso->Update();

  //    printf("3 \n");
  res = new InrImage( vtk_aniso->GetOutput());
  //    printf("4 \n");
  return res;

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // _WITHOUT_VTK_

} // vtkAnisoGS()


//
InrImage* wrap_vtkImageFFT(ParamList* p)
{

#ifndef _WITHOUT_VTK_
  char functionname[] = "vtkImageFFT";
  char description[]=" \n\
    Fast Fourier Transform      ";
  char parameters[] =" \n\
          Parameters:\n\
              input image\n\
      ";
    
    InrImage* input;
    int n=0;

  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
  return Func_vtkImageFFT(input);

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // _WITHOUT_VTK_

} // wrap_vtkImageFFT()

//
InrImage* wrap_vtkImageRFFT(ParamList* p)
{

#ifndef _WITHOUT_VTK_
  char functionname[] = "vtkImageRFFT";
  char description[]=" \n\
    Inverse Fast Fourier Transform      ";
  char parameters[] =" \n\
          Parameters:\n\
              input image\n\
      ";
    
    InrImage* input;
    int n=0;

  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
  return Func_vtkImageRFFT(input);

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // _WITHOUT_VTK_

} // wrap_vtkImageRFFT()

//
InrImage* wrap_vtkImageFourierCenter(ParamList* p)
{

#ifndef _WITHOUT_VTK_
  char functionname[] = "vtkImageFourierCenter";
  char description[]=" \n\
    Shift FFT results for display      ";
  char parameters[] =" \n\
          Parameters:\n\
              input image\n\
      ";
    
    InrImage* input;
    int n=0;

  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
  return Func_vtkImageFourierCenter(input);

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // _WITHOUT_VTK_

} // wrap_vtkImageFourierCenter()

/** Read a 3D Flow from an ASCII file **/
BasicVariable::ptr Wrap_vtkSkeleton2Lines(ParamList* p)
{

  char functionname[] = "vtkSkeleton2Lines";
  char description[]=" \n\
      Creates lines from a skeleton\n\
      ";
  char parameters[] =" \n\
          Parameters:\n\
              input image\n\
          Return:\n\
              Resulting polydata as set of lines\n\
      ";
    
    InrImage* input;
    int n=0;

  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnVarPtr;


  vtkImageData_ptr                vtk_image;
  shared_ptr<vtkSkeleton2Lines>   vtk_skel2lines;
  //  printf("1 \n");
  vtk_image = (vtkImageData_ptr) (*input);
  //    printf("2 \n");

  vtk_skel2lines = vtk_new<vtkSkeleton2Lines>()();
  vtk_skel2lines->SetInput( vtk_image.get());
  vtk_skel2lines->GetOutput();


  return WrapClass_SurfacePoly::CreateVar(new SurfacePoly(vtk_skel2lines->GetOutput()));

/*
  SurfacePoly::ptr surf_result( new SurfacePoly(vtk_skel2lines->GetOutput()));

  Variable<SurfacePoly>::ptr varres(
    new Variable<SurfacePoly>("vtkSkeleton2lines_result",surf_result));

  return varres;
*/


} // Wrap_vtkSkeleton2Lines()


//---------------------------------------------------------------------------
BasicVariable::ptr Wrap_vtkSphere( ParamList* p)
//            --------------
{

  char functionname[] = "vtkSphere";
  char description[]=" \n\
      Create a sphere as a polydata\n\
      ";
  char parameters[] =" \n\
          Parameters:\n\
              - radius           (def 0.5)\n\
              - Theta resolution (def 8)\n\
              - Phi resolution   (def 8)\n\
              - Sphere center : 3 float values (def 0,0,0) \n\
          Return:\n\
              A sphere polydata\n\
      ";

    float radius    = 0.5;
    int thetares    = 8;
    int phires      = 8;
    float center[3] = {0,0,0};
    int n=0;

  if (!get_val_param<float>(         radius,      p, n)) HelpAndReturnVarPtr;
  if (!get_int_param(           thetares,    p, n)) HelpAndReturnVarPtr;
  if (!get_int_param(           phires,      p, n)) HelpAndReturnVarPtr;
  if (!get_several_params<float,3>(  center,      p, n)) HelpAndReturnVarPtr;

  shared_ptr<vtkSphereSource>   vtk_sphere;

  vtk_sphere = vtk_new<vtkSphereSource>()();

  vtk_sphere->SetRadius           (radius);
  vtk_sphere->SetThetaResolution  (thetares);
  vtk_sphere->SetPhiResolution    (phires);
  vtk_sphere->SetCenter           (center[0],center[1],center[2]);

  vtk_sphere->Update();

  return WrapClass_SurfacePoly::CreateVar(new SurfacePoly(vtk_sphere->GetOutput()));


} // Wrap_vtkSphere()

