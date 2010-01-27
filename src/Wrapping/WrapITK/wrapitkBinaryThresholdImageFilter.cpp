#include "AMILabConfig.h"

#ifndef _WITHOUT_ITK_
#include "itkBinaryThresholdImageFilter.h"
#endif // _WITHOUT_ITK_

#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkBinaryThresholdImageFilter.h"

InrImage* wrap_itkBinaryThresholdImageFilter2D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

	char functionname[] = "itkBinaryThresholdImageFilter2D";
  char description[]=" \n\
        Filter to compute a thresholding solution in 2D.\n\
      ";
	  
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
					LowerThreshold \n\
					UpperThreshold \n\
      ";
    
	InrImage* input = NULL;
	float LowerThreshold = 0.0;
	float UpperThreshold = 0.0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
	if (!get_float_param(  LowerThreshold,      p, n)) HelpAndReturnNULL;
	if (!get_float_param(  UpperThreshold,      p, n)) HelpAndReturnNULL;
 
  typedef float       InternalPixelType;
  const   unsigned int        Dimension = 2;
  typedef itk::Image< InternalPixelType, Dimension >    InternalImageType;
  InternalImageType::RegionType region;
  InternalImageType::Pointer image;
  InternalImageType::Pointer outimage;
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
  	
	image = InrToITK<InternalPixelType,Dimension>(input,region);
	
	cout << "Conversión hecha" << endl;

	typedef itk::BinaryThresholdImageFilter< InternalImageType, InternalImageType > ThresholdingFilterType;
  ThresholdingFilterType::Pointer thresholder = ThresholdingFilterType::New();

  thresholder->SetLowerThreshold( LowerThreshold  );
  thresholder->SetUpperThreshold( UpperThreshold  );

  thresholder->SetOutsideValue(  0  );
  thresholder->SetInsideValue(  255 );

  thresholder->SetInput( image );
  
 	thresholder->Update();
	outimage = thresholder->GetOutput();

	// Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

	res = ITKToInr<InternalPixelType,Dimension>(outimage, region);
	
	return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkBinaryThresholdImageFilter2D


InrImage* wrap_itkBinaryThresholdImageFilter3D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

	char functionname[] = "itkBinaryThresholdImageFilter3D";
  char description[]=" \n\
        Filter to compute a thresholding solution in 3D.\n\
      ";
	  
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
					LowerThreshold \n\
					UpperThreshold \n\
      ";
    
	InrImage* input = NULL;
	float LowerThreshold = 0.0;
	float UpperThreshold = 0.0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
	if (!get_float_param(  LowerThreshold,      p, n)) HelpAndReturnNULL;
	if (!get_float_param(  UpperThreshold,      p, n)) HelpAndReturnNULL;
 
  typedef float       InternalPixelType;
  const   unsigned int        Dimension = 3;
  typedef itk::Image< InternalPixelType, Dimension >    InternalImageType;
  InternalImageType::RegionType region;
  InternalImageType::Pointer image;
  InternalImageType::Pointer outimage;
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
  	
	image = InrToITK<InternalPixelType,Dimension>(input,region);
	
	cout << "Conversión hecha" << endl;

	typedef itk::BinaryThresholdImageFilter< InternalImageType, InternalImageType > ThresholdingFilterType;
  ThresholdingFilterType::Pointer thresholder = ThresholdingFilterType::New();

  thresholder->SetLowerThreshold( LowerThreshold  );
  thresholder->SetUpperThreshold( UpperThreshold  );

  thresholder->SetOutsideValue(  0  );
  thresholder->SetInsideValue(  255 );

  thresholder->SetInput( image );
  
 	thresholder->Update();
	outimage = thresholder->GetOutput();

	// Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

	res = ITKToInr<InternalPixelType,Dimension>(outimage, region);
	
	return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkBinaryThresholdImageFilter3D