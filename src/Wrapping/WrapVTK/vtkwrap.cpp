
#include "vtkwrap.h"
#include "paramlist.h"

#ifdef AMI_USE_VTK

#include "surface.hpp"
using namespace amilab;

// all the needed vtk files

// standard VTK
#include "vtkPolyData.h"
#include "vtkPoints.h"
#include "vtkCellArray.h"
#include "vtkTriangleFilter.h"
#include "vtkImageMarchingCubes.h"
#include "vtkSmoothPolyDataFilter.h"
#include "vtkWindowedSincPolyDataFilter.h"
#include "vtkPolyDataWriter.h"
#include "vtkImageCityBlockDistance.h"
#include "vtkImageMedian3D.h"
#include "vtkDICOMImageReader.h"

// files from myVTK library
#include "vtkDecimate.h"
#include "vtkMINCImageReader.h"
#include "vtkImageIsoContourDist.h"
#include "vtkImageFastSignedChamfer.h"
#include "vtkLevelSetFastMarching.h"
#include "vtkImagePropagateDist.h"
#include "vtkImagePropagateDist2.h"
#include "vtkConvexHull.h"
#include "vtkAnisoGaussSeidel.h"

#endif // AMI_USE_VTK

#include "CommonConfigure.h"
COMMON_VAR_IMPORT unsigned char GB_debug;

//---------------------------------------------------------------------------
InrImage* Func_vtkMedianFilter3D( InrImage* im, int kx, int ky, int kz)
//        ----------------------
{

#ifdef AMI_USE_VTK
  
  vtkImageData_ptr           vtk_image;
  vtkImageMedian3D*          vtk_median;
  InrImage*                  res;

  // Convert InrImage to vtkImageData
  vtk_image = vtk_new<vtkImageData>()((vtkImageData*) (*im));

  vtk_median = vtkImageMedian3D::New();

  vtk_median->SetInput(vtk_image.get());
  vtk_median->SetKernelSize(kx,ky,kz);

  vtk_median->Update();

  res = new InrImage( vtk_median->GetOutput());

  vtk_median->Delete();

  return res;
#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkMedianFilter3D()

//---------------------------------------------------------------------------
SurfacePoly* Func_vtkMarchingCubes( InrImage* im, float Threshold)
//           ---------------------
{

#ifdef AMI_USE_VTK

  
  vtkImageData_ptr       vtk_image;
  vtkImageMarchingCubes* vtk_mc;
  SurfacePoly*           res;

  // Convert InrImage to vtkImageData
  vtk_image = vtk_new<vtkImageData>()((vtkImageData*) (*im));

  vtk_mc = vtkImageMarchingCubes::New();
  vtk_mc->SetInput(vtk_image.get());
  vtk_mc->SetValue(0,Threshold);

  vtk_mc->ComputeNormalsOff();
  vtk_mc->ComputeScalarsOff();
  vtk_mc->ComputeGradientsOff();

  vtk_mc->Update();

  res = new SurfacePoly( vtk_mc->GetOutput());

  vtk_mc->Delete();

  return res;
#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkMarchingCubes()

//---------------------------------------------------------------------------
SurfacePoly* Func_decimate( SurfacePoly* surf, float target_reduction )
//           -------------
{
#ifdef AMI_USE_VTK

  
  vtkPolyData*       vtk_surf;
  vtkTriangleFilter* triangle_filter;
  SurfacePoly*       surf_result;
  vtkDecimate*       deci;


  vtk_surf = (vtkPolyData*) (*surf);


  // Triangularization
  //
  triangle_filter = vtkTriangleFilter::New();
  triangle_filter->SetInput(vtk_surf);
  triangle_filter->Update();

  // Run the decimation
  //
  deci = vtkDecimate::New();
  deci->SetInput(triangle_filter->GetOutput());
  deci->SetTargetReduction(target_reduction);
  deci->SetAspectRatio(20);
  deci->SetInitialError(0.0002);
  deci->SetErrorIncrement(0.0005);
  deci->SetMaximumIterations(6);
  deci->SetInitialFeatureAngle(45);

  deci->Update();

  surf_result = new SurfacePoly(deci->GetOutput());

  printf("Resulting image: %d points \n",(int)deci->GetOutput()->GetNumberOfPoints());

  triangle_filter  ->Delete();
  deci             ->Delete();

  return surf_result;
#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_decimate()



//---------------------------------------------------------------------------
SurfacePoly* Func_vtkSmooth( SurfacePoly* surf , int numiter)
//           --------------
{
#ifdef AMI_USE_VTK
  
  vtkPolyData*              vtk_surf;
  vtkSmoothPolyDataFilter*  vtk_smooth;
  SurfacePoly*              surf_result;

  Si GB_debug AlorsFait fprintf(stderr,"Func_vtkSmooth() 1 \n");

  vtk_surf = (vtkPolyData*) (*surf);

  vtk_smooth = vtkSmoothPolyDataFilter::New();
  vtk_smooth->SetInput(vtk_surf);
  vtk_smooth->SetNumberOfIterations(numiter);
  vtk_smooth->BoundarySmoothingOn();
  vtk_smooth->SetFeatureAngle(120);
  vtk_smooth->SetEdgeAngle(90);
  vtk_smooth->SetRelaxationFactor(.025);

  vtk_smooth->Update();

  Si GB_debug AlorsFait fprintf(stderr,"Func_vtkSmooth() 2 \n");

  surf_result = new SurfacePoly(vtk_smooth->GetOutput());

  vtk_smooth->Delete();
  vtk_surf  ->Delete();

  Si GB_debug AlorsFait fprintf(stderr,"Func_vtkSmooth() 3 \n");

  return surf_result;
#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkSmooth()


//---------------------------------------------------------------------------
SurfacePoly* Func_vtkWindowedSinc( SurfacePoly* surf , int numiter)
//           --------------
{
#ifdef AMI_USE_VTK
  
  vtkPolyData*              vtk_surf;
  vtkWindowedSincPolyDataFilter*  vtk_smooth;
  SurfacePoly*              surf_result;

  Si GB_debug AlorsFait fprintf(stderr,"Func_vtkSmooth() 1 \n");

  vtk_surf = (vtkPolyData*) (*surf);

  vtk_smooth = vtkWindowedSincPolyDataFilter::New();
  vtk_smooth->SetInput(vtk_surf);
  vtk_smooth->SetNumberOfIterations(numiter);
  vtk_smooth->BoundarySmoothingOn();
  vtk_smooth->SetFeatureAngle(120);
  vtk_smooth->SetEdgeAngle(90);
  vtk_smooth->SetPassBand(0.1);

  vtk_smooth->Update();

  Si GB_debug AlorsFait fprintf(stderr,"Func_vtkSmooth() 2 \n");

  surf_result = new SurfacePoly(vtk_smooth->GetOutput());

  vtk_smooth->Delete();
  vtk_surf  ->Delete();

  Si GB_debug AlorsFait fprintf(stderr,"Func_vtkSmooth() 3 \n");

  return surf_result;
#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkWindowedSinc()


//---------------------------------------------------------------------------
void Func_ApplyvtkSmooth( SurfacePoly* surf , int numiter)
//   -------------------
{
#ifdef AMI_USE_VTK

  
  vtkPolyData*              vtk_surf;
  vtkPolyData*              vtk_res;
  vtkSmoothPolyDataFilter*  vtk_smooth;
  int                    i;
  vtkFloatingPointType                     point[3];

  Si GB_debug AlorsFait fprintf(stderr,"Func_vtkSmooth() 1 \n");

  vtk_surf = (vtkPolyData*) (*surf);

  vtk_smooth = vtkSmoothPolyDataFilter::New();
  vtk_smooth->SetInput(vtk_surf);
  vtk_smooth->SetNumberOfIterations(numiter);
  vtk_smooth->BoundarySmoothingOn();
  vtk_smooth->SetFeatureAngle(120);
  vtk_smooth->SetEdgeAngle(90);
  vtk_smooth->SetRelaxationFactor(.025);

  vtk_smooth->Update();

  Si GB_debug AlorsFait fprintf(stderr,"Func_vtkSmooth() 2 \n");

  vtk_res = vtk_smooth->GetOutput();
  //  surf_result = new SurfacePoly(vtk_smooth->GetOutput());

  // Copy the new position of the points
  Pour(i,0,surf->GetNumberOfPoints()-1)
  vtk_res->GetPoint(i,point);
  (*surf)[i].pt.Init(point[0],point[1],point[2]);
  FinPour


  Si GB_debug AlorsFait fprintf(stderr,"Func_vtkSmooth() 3 \n");

  vtk_smooth->Delete();
  vtk_surf  ->Delete();
  vtk_res   ->Delete();
#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
#endif // AMI_USE_VTK

} // Func_ApplyvtkSmooth()


//---------------------------------------------------------------------------
InrImage* Func_vtkDist( InrImage* im)
//        ------------
{
#ifdef AMI_USE_VTK

  vtkImageData_ptr           vtk_image;
  vtkImageCityBlockDistance* vtk_dist;
  InrImage*                  res;

  // Convert InrImage to vtkImageData
  vtk_image = vtk_new<vtkImageData>()((vtkImageData*) (*im));

  vtk_dist = vtkImageCityBlockDistance::New();

  if (im->_tz>1)  vtk_dist->SetDimensionality(3);
  else
    if (im->_ty>1)  vtk_dist->SetDimensionality(2);
    else            vtk_dist->SetDimensionality(1);

  vtk_dist->SetInput(vtk_image.get());

  vtk_dist->Update();

  res = new InrImage( vtk_dist->GetOutput());

  vtk_dist->Delete();

  return res;
  return NULL;

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkDist()

//---------------------------------------------------------------------------
InrImage* Func_vtkPropDanielsson( InrImage* im, float dmin, float dmax)
//        ------------
{
#ifdef AMI_USE_VTK

  vtkImageData_ptr           vtk_image;
  vtkImagePropagateDist*     vtk_prop;
  InrImage*                  res;

  // Convert InrImage to vtkImageData

  vtk_image = vtk_new<vtkImageData>()((vtkImageData*) (*im));
  vtk_prop  = vtkImagePropagateDist::New();

  vtk_prop->SetInput(   vtk_image.get());
  vtk_prop->Setmindist( dmin);
  vtk_prop->Setmaxdist( dmax);

  vtk_prop->Update();

  res = new InrImage( vtk_prop->GetOutput());

  vtk_prop->Delete();
  vtk_image->Delete();

  return res;

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkPropDanielsson()



//---------------------------------------------------------------------------
InrImage* Func_vtkPropDaniel2( InrImage* im,
                               //        ------------
                               float threshold, float dmin, float dmax)
{
#ifdef AMI_USE_VTK

  vtkImageData_ptr            vtk_image;
  vtkImagePropagateDist2*     vtk_prop;
  InrImage*                   res;

  // Convert InrImage to vtkImageData

  vtk_image = vtk_new<vtkImageData>()((vtkImageData*) (*im));
  vtk_prop  = vtkImagePropagateDist2::New();

  vtk_prop->SetInput(   vtk_image.get());
  vtk_prop->Setthreshold( threshold);
  vtk_prop->Setmindist(   dmin);
  vtk_prop->Setmaxdist(   dmax);

  vtk_prop->Update();

  res = new InrImage( vtk_prop->GetOutput());

//  vtk_prop->UnregisterAllOutputs();
  vtk_prop->Delete();
  vtk_image->Delete();

  return res;

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkPropDaniel2()



//---------------------------------------------------------------------------
InrImage*    Func_vtkConvexHull( InrImage* im, int angles, float resolution)
{
#ifdef AMI_USE_VTK

  vtkImageData_ptr  vtk_image;
  vtkConvexHull*    vtk_CH;
  InrImage*         res;

  // Convert InrImage to vtkImageData
  vtk_image = vtk_new<vtkImageData>()((vtkImageData*) (*im));
  vtk_CH = vtkConvexHull::New();
  vtk_CH->SetInput(vtk_image.get());
  vtk_CH->SetAngles(angles);
  vtk_CH->SetResolution(resolution);
  vtk_CH->Update();
  res = new InrImage( vtk_CH->GetOutput());
  vtk_CH->Delete();

  return res;

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkConvexHull()



//---------------------------------------------------------------------------
InrImage*    Func_vtkIsoContourDist( InrImage* im, float th)
{
#ifdef AMI_USE_VTK
  
  vtkImageData_ptr           vtk_image;
  vtkImageIsoContourDist*    vtk_isodist;
  InrImage*                  res;

  fprintf(stderr,"fonctions.c:Func_vtkIsoContourDist() \t begin \n");

  fprintf(stderr,"fonctions.c:Func_vtkIsoContourDist() \t conversion vtkImageData \n");
  // Convert InrImage to vtkImageData
  vtk_image = vtk_new<vtkImageData>()((vtkImageData*) (*im));

  fprintf(stderr,"fonctions.c:Func_vtkIsoContourDist() \t conversion vtkImageIsoContourDist \n");
  vtk_isodist = vtkImageIsoContourDist::New();

  vtk_isodist->SetInput(     vtk_image.get());
  vtk_isodist->Setthreshold( th);

  vtk_isodist->Update();

  fprintf(stderr,"fonctions.c:Func_vtkIsoContourDist() \t conversion InrImage \n");

  res = new InrImage( vtk_isodist->GetOutput());

  vtk_isodist->Delete();

  fprintf(stderr,"fonctions.c:Func_vtkIsoContourDist() \t end \n");
  return res;

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkIsoContourDist()



//---------------------------------------------------------------------------
// inittype 0: InitIsoSurf
// inittype 1: InitWithImage
InrImage*    Func_vtkFastMarching( InrImage* input, InrImage* init,
                                   float maxtime, int inittype)
{
#ifdef AMI_USE_VTK
  
  vtkImageData_ptr           vtk_input;
  vtkImageData_ptr           vtk_init;
  vtkLevelSetFastMarching*   vtk_FM;
  InrImage*                  res;

  // Convert InrImage to vtkImageData
  vtk_input = vtk_new<vtkImageData>()((vtkImageData*) (*input));
  vtk_init  = vtk_new<vtkImageData>()((vtkImageData*) (*init));

  vtk_FM = vtkLevelSetFastMarching::New();

  vtk_FM->SetInput(     vtk_input.get());

  vtk_FM->Setinitimage( vtk_init.get());
  // if we set initiso to a different value than -1E10 (default value)
  // the it will call InitIsoSurf which recomputes the distance close to the surface
  // otherwise, it call InitWithImage which is much faster, and
  // all values lower than initmaxdist will be accepted to start with.

  switch (inittype)
  {
  case 0:
    vtk_FM->Setinitiso(   0);
    break;
  }
  vtk_FM->Setinitmaxdist(1+1E-3);
  vtk_FM->SetmaxTime( maxtime);

  vtk_FM->Update();

  if (GB_debug) 
    fprintf(stderr,"Func_vtkFastMarching() \t conversion InrImage \n");

  res = new InrImage( vtk_FM->GetOutput());

  vtk_FM->Delete();

  if (GB_debug) 
    fprintf(stderr,"Func_vtkFastMarching() \t end \n");
  return res;

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkFastMarching()


//---------------------------------------------------------------------------
// inittype 0: InitIsoSurf
// inittype 1: InitWithImage
InrImage*    Func_vtkFastMarchingTarget(  InrImage* input, InrImage* init,
                                    float maxtime, 
                                    int x, int y, int z)
{
#ifdef AMI_USE_VTK
  
  vtkImageData_ptr           vtk_input;
  vtkImageData_ptr           vtk_init;

  // Convert InrImage to vtkImageData
  vtk_input = vtk_new<vtkImageData>()((vtkImageData*) (*input));
  vtk_init  = vtk_new<vtkImageData>()((vtkImageData*) (*init));
 
  vtkLevelSetFastMarching*   vtk_FM;
  InrImage*                  res;


  vtk_FM = vtkLevelSetFastMarching::New();

  for (int i=-1; i<=1; i++)
  for (int j=-1; j<=1; j++)
  for (int k=-1; k<=1; k++) {
   if (input->CoordOK(x+i,y+j,z+k)) 
     vtk_FM->AddTargetPoint( x+i,y+j,z+k);
  }

  vtk_FM->SetInput(     vtk_input.get());

  vtk_FM->Setinitimage( vtk_init.get());
  // if we set initiso to a different value than -1E10 (default value)
  // the it will call InitIsoSurf which recomputes the distance close to the surface
  // otherwise, it call InitWithImage which is much faster, and
  // all values lower than initmaxdist will be accepted to start with.

  vtk_FM->Setinitiso(   0);

  vtk_FM->Setinitmaxdist(1+1E-3);
  vtk_FM->SetmaxTime( maxtime);

  vtk_FM->Update();

  if (GB_debug) 
    fprintf(stderr,"Func_vtkFastMarchingTarget() \t conversion InrImage \n");

  res = new InrImage( vtk_FM->GetOutput());

  vtk_FM->Delete();

  if (GB_debug) 
    fprintf(stderr,"Func_vtkFastMarchingTarget() \t end \n");
  return res;

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkFastMarchingTarget()


//---------------------------------------------------------------------------
InrImage*  Func_vtkFastMarching(  InrImage* input, InrImage* init,
                                  float mean, float sd, float maxtime, 
                                  int inittype,
                                  int evol_scheme)
{
#ifdef AMI_USE_VTK
  
  vtkImageData_ptr           vtk_input;
  vtkImageData_ptr           vtk_init;

  // Convert InrImage to vtkImageData
  vtk_input = vtk_new<vtkImageData>()((vtkImageData*) (*input));
  vtk_init  = vtk_new<vtkImageData>()((vtkImageData*) (*init));

  vtkLevelSetFastMarching*   vtk_FM;
  InrImage*                  res;

  vtk_FM = vtkLevelSetFastMarching::New();

  vtk_FM->SetInput(     vtk_input.get());
  vtk_FM->SetEvolutionScheme( evol_scheme);

  vtk_FM->Setinitimage( vtk_init.get());
  switch (inittype)
  {
  case 0:
    vtk_FM->Setinitiso(   0);
    break;
  }
  vtk_FM->Setinitmaxdist(1+1E-3);
  vtk_FM->SetmaxTime( maxtime);
  vtk_FM->SetGaussianForce(mean,sd);

  vtk_FM->Update();

  if (GB_debug) 
    fprintf(stderr,"Func_vtkFastMarching() \t conversion InrImage \n");

  res = new InrImage( vtk_FM->GetOutput());

  vtk_FM->Delete();

  if (GB_debug) 
    fprintf(stderr,"Func_vtkFastMarching \t end \n");
  return res;

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkFastMarching()



//---------------------------------------------------------------------------
InrImage*  Func_vtkFastMarching(  
              InrImage* input, InrImage* init,
              InrImage* track,
              float mean, float sd, float maxtime, 
              int inittype)
{
#ifdef AMI_USE_VTK
  vtkImageData_ptr           vtk_input;
  vtkImageData_ptr           vtk_init;
  vtkImageData_ptr           vtk_track;
  vtkLevelSetFastMarching*   vtk_FM;
  InrImage*                  res;

  // Convert InrImage to vtkImageData
  vtk_input = vtk_new<vtkImageData>()((vtkImageData*) (*input));
  vtk_init  = vtk_new<vtkImageData>()((vtkImageData*) (*init));
  vtk_track = vtk_new<vtkImageData>()((vtkImageData*) (*track));

  vtk_FM = vtkLevelSetFastMarching::New();

  vtk_FM->SetInput          (vtk_input.get());
  vtk_FM->SetEvolutionScheme(1); // Dijkstra
  vtk_FM->Settrack          (vtk_track.get());

  vtk_FM->Setinitimage( vtk_init.get());
  switch (inittype)
  {
  case 0:
    vtk_FM->Setinitiso(   0);
    break;
  }
  vtk_FM->Setinitmaxdist(1+1E-3);
  vtk_FM->SetmaxTime( maxtime);
  vtk_FM->SetGaussianForce(mean,sd);

  vtk_FM->Update();

  if (GB_debug) 
    fprintf(stderr,"Func_vtkFastMarching() \t conversion InrImage \n");

  res = new InrImage( vtk_FM->GetOutput());

  InrImage* tmp_track = new InrImage(vtk_track.get());
  (*track) = (*tmp_track);
  delete tmp_track;
 
  vtk_FM->Delete();
  if (GB_debug) 
    fprintf(stderr,"Func_vtkFastMarching() \t end \n");
  return res;

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkFastMarching()


//---------------------------------------------------------------------------
InrImage*  Func_vtkFastMarching(  
              InrImage* input, InrImage* init,
              InrImage* track,
              float maxtime,
              int inittype)
{
#ifdef AMI_USE_VTK
  vtkImageData_ptr           vtk_input;
  vtkImageData_ptr           vtk_init;
  vtkImageData_ptr           vtk_track;
  vtkLevelSetFastMarching*   vtk_FM;
  InrImage*                  res;

  // Convert InrImage to vtkImageData
  vtk_input = vtk_new<vtkImageData>()((vtkImageData*) (*input));
  vtk_init  = vtk_new<vtkImageData>()((vtkImageData*) (*init));
  vtk_track = vtk_new<vtkImageData>()((vtkImageData*) (*track));

  vtk_FM = vtkLevelSetFastMarching::New();

  vtk_FM->SetInput          (vtk_input.get());
  vtk_FM->SetEvolutionScheme(1); // Dijkstra
  vtk_FM->Settrack          (vtk_track.get());

  vtk_FM->Setinitimage( vtk_init.get());
  switch (inittype)
  {
  case 0:
    vtk_FM->Setinitiso(   0);
    break;
  }
  vtk_FM->Setinitmaxdist(1+1E-3);
  vtk_FM->SetmaxTime( maxtime);

  vtk_FM->Update();

  if (GB_debug) 
    fprintf(stderr,"Func_vtkFastMarching() \t conversion InrImage \n");

  res = new InrImage( vtk_FM->GetOutput());

  InrImage* tmp_track = new InrImage(vtk_track.get());
  (*track) = (*tmp_track);
  delete tmp_track;
 
  vtk_FM->Delete();

  if (GB_debug) 
    fprintf(stderr,"Func_vtkFastMarching() \t end \n");
  return res;

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkFastMarching()


//---------------------------------------------------------------------------
InrImage*    Func_vtkSignedBorgefors(InrImage* im, float dmax)
{
#ifdef AMI_USE_VTK
  
  vtkImageData*              vtk_image;
  vtkImageFastSignedChamfer* vtk_SDT;
  InrImage*                  res;

  //  fprintf(stderr,"Func_vtkSignedBorgefors() \t begin \n");

  //  fprintf(stderr,"Func_vtkSignedBorgefors() \t conversion vtkImageData \n");
  // Convert InrImage to vtkImageData
  vtk_image = (vtkImageData*) (*im);

  //  fprintf(stderr,"Func_vtkSignedBorgefors() \t conversion vtkImageSignedBorgefors \n");
  vtk_SDT = vtkImageFastSignedChamfer::New();

  vtk_SDT->SetInput(   vtk_image);
  vtk_SDT->Setmaxdist( dmax);
  vtk_SDT->Setnoborder(1);

  vtk_SDT->Update();

  //  fprintf(stderr,"Func_vtkSignedBorgefors() \t conversion InrImage \n");

  res = new InrImage( vtk_SDT->GetOutput());

  vtk_SDT->Delete();

  //  fprintf(stderr,"Func_vtkSignedBorgefors() \t end \n");
  return res;

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkSignedBorgefors()



//---------------------------------------------------------------------------
InrImage*    Func_vtkSignedFMDist(InrImage* im, float dmax)
{
#ifdef AMI_USE_VTK
  
  vtkImageData*              vtk_image;
  vtkLevelSetFastMarching*           vtk_FM;
  InrImage*                  res;

  //  fprintf(stderr,"Func_vtkSignedFMDist() \t begin \n");

  //  fprintf(stderr,"Func_vtkSignedFMDist() \t conversion vtkImageData \n");
  // Convert InrImage to vtkImageData
  vtk_image = (vtkImageData*) (*im);

  //  fprintf(stderr,"Func_vtkSignedFMDist() \t conversion vtkImageSignedFMDist \n");
  vtk_FM = vtkLevelSetFastMarching::New();

  vtk_FM->SetInput(       vtk_image);
  vtk_FM->Setinitimage(   vtk_image);
  vtk_FM->Setinitiso(     0);
  vtk_FM->SetmaxTime(     dmax);

  vtk_FM->Update();

  //  fprintf(stderr,"Func_vtkSignedFMDist() \t conversion InrImage \n");

  res = new InrImage( vtk_FM->GetOutput());

  vtk_FM->Delete();

  //  fprintf(stderr,"Func_vtkSignedFMDist() \t end \n");
  return res;

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkSignedFMDist()


//---------------------------------------------------------------------------
InrImage*    Func_vtkAnisoGS(   InrImage* in, float sigma, float k, float beta, int nb_iter, int nb_threads)
{
#ifdef AMI_USE_VTK

  std::cerr << "deprecated: use import_vtk and corresponding function" << std::endl;
  return NULL;
/*
  vtkImageData*         vtk_image;
  InrImage*             res;
  vtkAnisoGaussSeidel*  vtk_aniso;
  //  printf("1 \n");
  vtk_image = (vtkImageData*) (*in);
  //	  printf("2 \n");

  vtk_aniso = vtkAnisoGaussSeidel::New();
  vtk_aniso->SetInput(              vtk_image);
  vtk_aniso->Setmode(               3);
  vtk_aniso->Setsigma(              sigma);
  vtk_aniso->Setk(                  k);
  vtk_aniso->Setbeta(               beta);
  vtk_aniso->SetIsoCoeff(           0.2);
  vtk_aniso->SetNumberOfIterations( nb_iter);
  vtk_aniso->SetNumberOfThreads(    nb_threads);

  vtk_aniso->Update();

  //	  printf("3 \n");
  res = new InrImage( vtk_aniso->GetOutput());
  //	  printf("4 \n");
  vtk_aniso->Delete();
  
  return res;
*/
#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK

} // Func_vtkAnisoGS()


InrImage*    Func_vtkDicomRead( const char* directoryname)
{
#ifdef AMI_USE_VTK
  InrImage* res;
  vtkDICOMImageReader* reader;

  reader = (vtkDICOMImageReader*) vtkDICOMImageReader::New();
  reader->SetDirectoryName(directoryname);
  reader->Update();
  res = new InrImage( reader->GetOutput());
  reader->Delete();
  return res;

#else
  fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
  return NULL;
#endif // AMI_USE_VTK
}

InrImage*    Func_vtkMINCRead( const char* filename)
{
#ifdef AMI_USE_VTK
  InrImage* res;
  vtkMINCImageReader* reader;

  reader = (vtkMINCImageReader*) vtkMINCImageReader::New();
  reader->SetFileName(filename);
  reader->RescaleRealValuesOn();
  reader->Update();
  res = new InrImage( reader->GetOutput());
  reader->Delete();
  return res;

#else
  fprintf(stderr," VTK  not available , you need to compile with VTK...\n");
  return NULL;
#endif // AMI_USE_VTK

}

