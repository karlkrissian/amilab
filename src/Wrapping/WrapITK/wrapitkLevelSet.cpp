#include "AMILabConfig.h"

#ifndef _WITHOUT_ITK_
#include "itkImage.h"
#include "itkShapeDetectionLevelSetImageFilter.h"
#endif // _WITHOUT_ITK_

#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkLevelSet.h"

InrImage* wrap_itkLevelSetFilter2D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

	char functionname[] = "itkLevelSetFilter2D";
  char description[]=" \n\
        Filter to compute a level set solution in 2D.\n\
      ";
	  
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
					sigmoid image \n\
          curvatureScaling \n\
          propagationScaling \n\
      ";
    
	InrImage* input = NULL;
  InrImage* sigmoidI = NULL;
	float curvatureScaling = 0.0;
	float propagationScaling = 0.0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_val_param<float>( curvatureScaling, p, n))          HelpAndReturnNULL;
 
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
  
  typedef  itk::ShapeDetectionLevelSetImageFilter< InternalImageType, InternalImageType > ShapeDetectionFilterType;
  ShapeDetectionFilterType::Pointer shapeDetection = ShapeDetectionFilterType::New();  
    
	shapeDetection->SetInput( image );
  shapeDetection->SetFeatureImage( imageS );
  shapeDetection->SetPropagationScaling(  propagationScaling );
  shapeDetection->SetCurvatureScaling( curvatureScaling ); 
  shapeDetection->SetMaximumRMSError( 0.02 );
  shapeDetection->SetNumberOfIterations( 200 );

	shapeDetection->Update();
  
	outimage = shapeDetection->GetOutput();

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
      ";
    
	InrImage* input = NULL;
  InrImage* sigmoidI = NULL;
	float curvatureScaling = 0.0;
	float propagationScaling = 0.0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>( input,      p, n))  HelpAndReturnNULL;
  if (!get_val_ptr_param<InrImage>( sigmoidI,   p, n))  HelpAndReturnNULL;
  if (!get_val_param<float>( curvatureScaling, p, n))   HelpAndReturnNULL;
  if (!get_val_param<float>( propagationScaling, p, n)) HelpAndReturnNULL;
 
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
  
  typedef  itk::ShapeDetectionLevelSetImageFilter< InternalImageType, InternalImageType > ShapeDetectionFilterType;
  ShapeDetectionFilterType::Pointer shapeDetection = ShapeDetectionFilterType::New();  
    
	shapeDetection->SetInput( image );
  shapeDetection->SetFeatureImage( imageS );
  shapeDetection->SetPropagationScaling(  propagationScaling );
  shapeDetection->SetCurvatureScaling( curvatureScaling ); 
  shapeDetection->SetMaximumRMSError( 0.02 );
  shapeDetection->SetNumberOfIterations( 500 );

	shapeDetection->Update();
  
	outimage = shapeDetection->GetOutput();

	// Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

	res = ITKToInr<InternalPixelType,Dimension>(outimage, region);
	
	return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkLevelSetFilter3D