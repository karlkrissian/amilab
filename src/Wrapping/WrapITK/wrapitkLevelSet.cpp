#include "AMILabConfig.h"

#ifndef _WITHOUT_ITK_
#include "itkImage.h"
#include "itkGeodesicActiveContourLevelSetImageFilter.h"
#endif // _WITHOUT_ITK_

#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkLevelSet.h"

InrImage* wrap_itkLevelSetFilter2D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

	char functionname[] = "itkLevelSetFilter3D";
  char description[]=" \n\
        Filter to compute a level set solution in 2D.\n\
      ";
	  
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
					sigmoid image \n\
          curvatureScaling \n\
          propagationScaling \n\
          AdvectionScaling \n\
          MaximumRMSError \n\
          NumberOfIterations \n\
      ";
    
	InrImage* input = NULL;
  InrImage* sigmoidI = NULL;
	float curvatureScaling = 0.0;
	float propagationScaling = 0.0;
  float advectionScaling = 0.0;
  float maximumRMSError = 0.0;
  int numberOfIteration = 0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>( input,      p, n))  HelpAndReturnNULL;
  if (!get_val_ptr_param<InrImage>( sigmoidI,   p, n))  HelpAndReturnNULL;
  if (!get_val_param<float>( curvatureScaling, p, n))   HelpAndReturnNULL;
  if (!get_val_param<float>( propagationScaling, p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>( advectionScaling, p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>( maximumRMSError, p, n)) HelpAndReturnNULL;
  if (!get_int_param( numberOfIteration, p, n)) HelpAndReturnNULL;
 
  typedef float       InternalPixelType;
  const   unsigned int        Dimension = 2;
  typedef itk::Image< InternalPixelType, Dimension >    InternalImageType;
  InternalImageType::RegionType region;
	InternalImageType::RegionType region2;
  InternalImageType::Pointer image;
	InternalImageType::Pointer imageS;
  InternalImageType::Pointer outimage;
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
  	
	image = InrToITK<InternalPixelType,Dimension>(input,region);
	imageS = InrToITK<InternalPixelType,Dimension>(sigmoidI,region2);
	
	cout << "Conversi�n hecha" << endl;
  
  typedef itk::GeodesicActiveContourLevelSetImageFilter < InternalImageType, InternalImageType > GeodesicFilterType;
  //typedef  itk::ShapeDetectionLevelSetImageFilter ShapeDetectionFilterType;
  GeodesicFilterType::Pointer geodesic = GeodesicFilterType::New();  
  
	geodesic->SetInput( image );
  geodesic->SetFeatureImage( imageS );
  geodesic->SetPropagationScaling(  propagationScaling );
  geodesic->SetCurvatureScaling( curvatureScaling ); 
  geodesic->SetMaximumRMSError( maximumRMSError );
  geodesic->SetNumberOfIterations( numberOfIteration );
  geodesic->SetAdvectionScaling(advectionScaling);

	geodesic->Update();
  
	outimage = geodesic->GetOutput();

	// Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

	res = ITKToInr<InternalPixelType,Dimension>(outimage, region);
	
	return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkLevelSetFilter2D

InrImage* wrap_itkLevelSetFilter3D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

	char functionname[] = "itkLevelSetFilter3D";
  char description[]=" \n\
        Filter to compute a level set solution in 3D.\n\
      ";
	  
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
					sigmoid image \n\
          curvatureScaling \n\
          propagationScaling \n\
          AdvectionScaling \n\
          MaximumRMSError \n\
          NumberOfIterations \n\
      ";
    
	InrImage* input = NULL;
  InrImage* sigmoidI = NULL;
	float curvatureScaling = 0.0;
	float propagationScaling = 0.0;
  float advectionScaling = 0.0;
  float maximumRMSError = 0.0;
  int numberOfIteration = 0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>( input,      p, n))  HelpAndReturnNULL;
  if (!get_val_ptr_param<InrImage>( sigmoidI,   p, n))  HelpAndReturnNULL;
  if (!get_val_param<float>( curvatureScaling, p, n))   HelpAndReturnNULL;
  if (!get_val_param<float>( propagationScaling, p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>( advectionScaling, p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>( maximumRMSError, p, n)) HelpAndReturnNULL;
  if (!get_int_param( numberOfIteration, p, n)) HelpAndReturnNULL;
 
  typedef float       InternalPixelType;
  const   unsigned int        Dimension = 3;
  typedef itk::Image< InternalPixelType, Dimension >    InternalImageType;
  InternalImageType::RegionType region;
	InternalImageType::RegionType region2;
  InternalImageType::Pointer image;
	InternalImageType::Pointer imageS;
  InternalImageType::Pointer outimage;
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
  	
	image = InrToITK<InternalPixelType,Dimension>(input,region);
	imageS = InrToITK<InternalPixelType,Dimension>(sigmoidI,region2);
	
	cout << "Conversi�n hecha" << endl;
  
  typedef itk::GeodesicActiveContourLevelSetImageFilter < InternalImageType, InternalImageType > GeodesicFilterType;
  //typedef  itk::ShapeDetectionLevelSetImageFilter ShapeDetectionFilterType;
  GeodesicFilterType::Pointer geodesic = GeodesicFilterType::New();  
    
	geodesic->SetInput( image );
  geodesic->SetFeatureImage( imageS );
  geodesic->SetPropagationScaling(  propagationScaling );
  geodesic->SetCurvatureScaling( curvatureScaling ); 
  geodesic->SetMaximumRMSError( maximumRMSError );
  geodesic->SetNumberOfIterations( numberOfIteration );
  geodesic->SetAdvectionScaling(advectionScaling);

	geodesic->Update();
  
	outimage = geodesic->GetOutput();

	// Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

	res = ITKToInr<InternalPixelType,Dimension>(outimage, region);
	
	return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkLevelSetFilter3D