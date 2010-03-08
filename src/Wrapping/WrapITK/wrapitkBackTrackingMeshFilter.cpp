#include "AMILabConfig.h"

#ifndef _WITHOUT_ITK_
#include "itkImage.h"
#include "itkMesh.h"
#include "itkBackTrackingMeshFilter.h"
#endif // _WITHOUT_ITK_

#ifndef _WITHOUT_VTK_
//#include "vtkTriangleFilter.h"
#endif // _WITHOUT_VTK_

//#include "vtk_common.h"

#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkBackTrackingMeshFilter.h"

Variable::ptr wrap_itkBackTrackingMeshFilter2D(ParamList* p)
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
  SurfacePoly* res = NULL;
  int n=0;
  
  if (!get_image_param(  input,      p, n)) HelpAndReturnVarPtr;
  if (!get_float_param(  startX,    p, n)) HelpAndReturnVarPtr;
  if (!get_float_param(  startY,      p, n)) HelpAndReturnVarPtr;
	if (!get_float_param(  stepSize,      p, n)) HelpAndReturnVarPtr;
	if (!get_float_param(  maxLength,      p, n)) HelpAndReturnVarPtr;
	if (!get_float_param(  delta,      p, n)) HelpAndReturnVarPtr; 

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
	
	cout << "Conversión hecha" << endl;

  typedef itk::BackTrackingMeshFilter<InternalImageType,MeshType,Dimension> BackTrackingFilterType;
  BackTrackingFilterType::Pointer BackTracking = BackTrackingFilterType::New();

  BackTracking->SetInput(0, image );
  BackTracking->SetstartX( startX );
  BackTracking->SetstartY( startY );
  BackTracking->SetstepSize( stepSize );
  BackTracking->SetmaxLength( maxLength );
  BackTracking->Setdelta( delta );
  BackTracking->Update();

  //vtkTriangleFilter* triangle_filter=NULL;
 
  /*SurfacePoly* surf_result = new SurfacePoly((vtkPolyData*)BackTracking->GetOutput());

  Variable::ptr varres(new Variable());
  varres->Init(type_surface,"backTracking_result",surf_result);*/

  //res = new SurfacePoly((vtkPolyData*)(BackTracking->GetOutput()));
   
  //res = BackTracking->GetOutput();
	
	///return varres;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkBackTrackingMeshFilter2D


Variable::ptr wrap_itkBackTrackingMeshFilter3D(ParamList* p)
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
  
  if (!get_image_param(  input,      p, n)) HelpAndReturnVarPtr;
  if (!get_float_param(  startX,    p, n)) HelpAndReturnVarPtr;
  if (!get_float_param(  startY,      p, n)) HelpAndReturnVarPtr;
  if (!get_float_param(  startZ,      p, n)) HelpAndReturnVarPtr;
	if (!get_float_param(  stepSize,      p, n)) HelpAndReturnVarPtr;
	if (!get_float_param(  maxLength,      p, n)) HelpAndReturnVarPtr;
	if (!get_float_param(  delta,      p, n)) HelpAndReturnVarPtr; 

  typedef double       InternalPixelType;
  const   unsigned int        Dimension = 3;
  typedef itk::Image< InternalPixelType, Dimension >    InternalImageType;
  InternalImageType::RegionType region;
  InternalImageType::Pointer image;
  
  typedef itk::Mesh<InternalPixelType,Dimension> MeshType;

	MeshType::Pointer output = MeshType::New();
  /*typedef itk::VTKPolyDataWriter<MeshType> VTKWriterType;
  VTKWriterType::Pointer writer = VTKWriterType::New();*/
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
  	
	image = InrToITK<InternalPixelType,Dimension>(input,region);
	
	cout << "Conversión hecha" << endl;

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
  /*writer->SetInput(BackTracking->GetOutput());
  writer->SetFileName("pes.vtk");
  writer->Update();*/

  /*SurfacePoly* surf_result = new SurfacePoly((vtkPolyData*)BackTracking->GetOutput());

  Variable::ptr varres(new Variable());
  varres->Init(type_surface,"backTracking_result",surf_result);

  //res = new SurfacePoly((vtkPolyData*)(BackTracking->GetOutput()));
   
  return varres;*/

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkBackTrackingMeshFilter3D