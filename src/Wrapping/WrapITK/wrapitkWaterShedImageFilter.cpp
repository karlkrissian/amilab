
#include "AMILabConfig.h"

#ifndef _WITHOUT_ITK_
#include "itkWatershedImageFilter.h"
#endif // _WITHOUT_ITK_

#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkWaterShedImageFilter.h"

InrImage* wrap_itkWaterShedImageFilter2D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

	char functionname[] = "itkWaterShedImageFilter2D";
  char description[]=" \n\
        Filter to compute a watershed solution in 2D.\n\
      ";
	  
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          lowerThreshold \n\
          outputScaleLevel \n\
			";
			
	InrImage* input = NULL;
	float lowerThreshold = 0.0;
	float outputScaleLevel = 0.0;
  InrImage* res = NULL;
  int n=0;
	
  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(  lowerThreshold,    p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(  outputScaleLevel,  p, n)) HelpAndReturnNULL;
	
	typedef float               PixelType;
  const   unsigned int        Dimension = 2;
  typedef itk::Image< PixelType, Dimension >    ImageType;
  ImageType::RegionType region;
  ImageType::Pointer image;
	
	typedef itk::WatershedImageFilter<ImageType> WatershedFilterType;
	
	typedef unsigned long OutputPixelType;
	typedef itk::Image< OutputPixelType,Dimension > OutputImageType;
	OutputImageType::Pointer outimage;
	
	// Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
  	
	image = InrToITK<PixelType,Dimension>(input,region);
	
	WatershedFilterType::Pointer watershed = WatershedFilterType::New();
	// We set up the watershed filter. There are two parameters.
  // Level controls watershed depth, and Threshold controls the
  // lower thresholding of the input. Both parameters are set as a
  // percentage (0.0 - 1.0) of the maximum depth in the input image.
  watershed->SetLevel( outputScaleLevel );
  watershed->SetThreshold( lowerThreshold );
	watershed->SetInput(image);
	watershed->Update();

	outimage = watershed->GetOutput();
   
	// Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

	res = ITKToInr<OutputPixelType,Dimension>(outimage, region);

	return res;
			
#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkWaterShedImageFilter2D

InrImage* wrap_itkWaterShedImageFilter3D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

	char functionname[] = "itkWaterShedImageFilter3D";
  char description[]=" \n\
        Filter to compute a watershed solution in 3D.\n\
      ";
	  
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          lowerThreshold \n\
          outputScaleLevel \n\
			";
			
	InrImage* input = NULL;
	float lowerThreshold = 0.0;
	float outputScaleLevel = 0.0;
  InrImage* res = NULL;
  int n=0;
	
  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(  lowerThreshold,    p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(  outputScaleLevel,  p, n)) HelpAndReturnNULL;
	
	typedef float               PixelType;
  const   unsigned int        Dimension = 3;
  typedef itk::Image< PixelType, Dimension >    ImageType;
  ImageType::RegionType region;
  ImageType::Pointer image;
	
	typedef itk::WatershedImageFilter<ImageType> WatershedFilterType;
	
	typedef unsigned long OutputPixelType;
	typedef itk::Image< OutputPixelType,Dimension > OutputImageType;
	OutputImageType::Pointer outimage;
	
	// Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
  	
	image = InrToITK<PixelType,Dimension>(input,region);
	
	WatershedFilterType::Pointer watershed = WatershedFilterType::New();
	// We set up the watershed filter. There are two parameters.
  // Level controls watershed depth, and Threshold controls the
  // lower thresholding of the input. Both parameters are set as a
  // percentage (0.0 - 1.0) of the maximum depth in the input image.
  watershed->SetLevel( outputScaleLevel );
  watershed->SetThreshold( lowerThreshold );
	watershed->SetInput(image);
	watershed->Update();
	
	outimage = watershed->GetOutput();
   
	// Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

	res = ITKToInr<OutputPixelType,Dimension>(outimage, region);

	return res;
			
#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkWaterShedImageFilter3D

