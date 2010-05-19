#include "AMILabConfig.h"

#ifndef _WITHOUT_ITK_
#include "itkImage.h"
#include "itkMesh.h"
#include "itkBackTrackingMeshFilter.h"
#include "itkPointSet.h"
#endif // _WITHOUT_ITK_

#ifndef _WITHOUT_VTK_
#include <vtkPointData.h>
#endif // _WITHOUT_VTK_

//#include "vtk_common.h"
#include "surface.hpp"

#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkBackTrackingMeshFilter.h"

BasicVariable::ptr wrap_itkBackTrackingMeshFilter2D(ParamList* p)
{
  
#ifndef _WITHOUT_ITK_

  char functionname[] = "itkBackTrackingMeshFilter2D";
  char description[]=" \n\
        Filter to compute a backtracking solution in 2D.\n\
      ";
    
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          startX \n\
          startY \n\
          stepSize \n\
          maxLength \n\
          delta \n\
      ";
    
  InrImage* input = NULL;
  float startX = 0.0;
  float startY = 0.0;
  float stepSize = 0.0;
  float maxLength = 0.0;
  float delta = 0.0;
  //SurfacePoly* res = NULL;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnVarPtr;
  if (!get_val_param<float>(  startX,    p, n)) HelpAndReturnVarPtr;
  if (!get_val_param<float>(  startY,      p, n)) HelpAndReturnVarPtr;
  if (!get_val_param<float>(  stepSize,      p, n)) HelpAndReturnVarPtr;
  if (!get_val_param<float>(  maxLength,      p, n)) HelpAndReturnVarPtr;
  if (!get_val_param<float>(  delta,      p, n)) HelpAndReturnVarPtr; 

  typedef double       InternalPixelType;
  const   unsigned int        Dimension = 2;
  typedef itk::Image< InternalPixelType, Dimension >    InternalImageType;
  InternalImageType::RegionType region;
  InternalImageType::Pointer image;
  
  typedef itk::Mesh<InternalPixelType,Dimension> MeshType;

  MeshType::Pointer output = MeshType::New();
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
    
  image = InrToITK<InternalPixelType,Dimension>(input,region);
  
  cout << "Conversi�n hecha" << endl;

  typedef itk::BackTrackingMeshFilter<InternalImageType,MeshType,Dimension> BackTrackingFilterType;
  BackTrackingFilterType::Pointer BackTracking = BackTrackingFilterType::New();

  BackTracking->SetInput(0, image );
  BackTracking->SetstartX( startX );
  BackTracking->SetstartY( startY );
  BackTracking->SetstepSize( stepSize );
  BackTracking->SetmaxLength( maxLength );
  BackTracking->Setdelta( delta );
  BackTracking->Update();

  //vtkFloatingPointType triangle[2];
  typedef itk::PointSet<InternalPixelType,Dimension> PointSetType;
  PointSetType::PointIdentifier pointID;
  typedef PointSetType::PointType PointType;
  PointType pp;

  SurfacePoly* surf;
  surf = new SurfacePoly;
  //surf->NewSurface();
  surf->NewLine();
  int num_points=0;

  for (int i=0;i<BackTracking->GetOutput()->GetNumberOfPoints();i++)
  {
    pointID = i;
    bool pointExists = BackTracking->GetOutput()->GetPoint(pointID,&pp);
    surf->AddPoint(pp[0],pp[1],0);
    surf->LineAddPointNumber(num_points);
    num_points++;
  }
  surf->EndLine();

  Variable<SurfacePoly>::ptr varres(new Variable<SurfacePoly>("backtrack_mesh",SurfacePoly::ptr(surf)));

  return varres;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_ 
} // wrap_itkBackTrackingMeshFilter2D


//Variable::ptr wrap_itkBackTrackingMeshFilter3D(ParamList* p)
BasicVariable::ptr wrap_itkBackTrackingMeshFilter3D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

  char functionname[] = "itkBackTrackingMeshFilter3D";
  char description[]=" \n\
        Filter to compute a backtracking solution in 3D.\n\
      ";
    
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          startX \n\
          startY \n\
          startZ \n\
          stepSize \n\
          maxLength \n\
          delta \n\
      ";
    
  InrImage* input = NULL;
  float startX = 0.0;
  float startY = 0.0;
  float startZ = 0.0;
  float stepSize = 0.0;
  float maxLength = 0.0;
  float delta = 0.0;
  SurfacePoly* res = NULL;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnVarPtr;
  if (!get_val_param<float>(  startX,    p, n)) HelpAndReturnVarPtr;
  if (!get_val_param<float>(  startY,      p, n)) HelpAndReturnVarPtr;
  if (!get_val_param<float>(  startZ,      p, n)) HelpAndReturnVarPtr;
  if (!get_val_param<float>(  stepSize,      p, n)) HelpAndReturnVarPtr;
  if (!get_val_param<float>(  maxLength,      p, n)) HelpAndReturnVarPtr;
  if (!get_val_param<float>(  delta,      p, n)) HelpAndReturnVarPtr; 

  typedef double       InternalPixelType;
  const   unsigned int        Dimension = 3;
  typedef itk::Image< InternalPixelType, Dimension >    InternalImageType;
  InternalImageType::RegionType region;
  InternalImageType::Pointer image;
  
  typedef itk::Mesh<InternalPixelType,Dimension> MeshType;

  MeshType::Pointer output = MeshType::New();
   
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
    
  image = InrToITK<InternalPixelType,Dimension>(input,region);
  
  cout << "Conversi�n hecha" << endl;

  typedef itk::BackTrackingMeshFilter<InternalImageType,MeshType,Dimension> BackTrackingFilterType;
  BackTrackingFilterType::Pointer BackTracking = BackTrackingFilterType::New();

  BackTracking->SetInput(0, image );
  BackTracking->SetstartX( startX );
  BackTracking->SetstartY( startY );
  BackTracking->SetstartZ( startZ );
  BackTracking->SetstepSize( stepSize );
  BackTracking->SetmaxLength( maxLength );
  BackTracking->Setdelta( delta );
  BackTracking->Update();

  vtkFloatingPointType triangle[3];
  typedef itk::PointSet<InternalPixelType,Dimension> PointSetType;
  PointSetType::PointIdentifier pointID;
  typedef PointSetType::PointType PointType;
  PointType pp;

  SurfacePoly* surf;
  surf = new SurfacePoly;
  //surf->NewSurface();
  surf->NewLine();
  int num_points=0;

  for (int i=0;i<BackTracking->GetOutput()->GetNumberOfPoints();i++)
  {
    pointID = i;
    bool pointExists = BackTracking->GetOutput()->GetPoint(pointID,&pp);
    surf->AddPoint(pp[0],pp[1],pp[2]);
    surf->LineAddPointNumber(num_points);
    num_points++;
  }
  surf->EndLine();
  
  Variable<SurfacePoly>::ptr varres(new Variable<SurfacePoly>("backtrack_mesh",SurfacePoly::ptr(surf)));

  return varres;
 
#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_ 
} // wrap_itkBackTrackingMeshFilter3D
