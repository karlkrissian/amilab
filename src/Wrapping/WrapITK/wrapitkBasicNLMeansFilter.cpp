#include "AMILabConfig.h"

#ifndef _WITHOUT_ITK_

#include "itkImage.h"
#include "itkImageIOBase.h"
#include "itkImageLinearConstIteratorWithIndex.h"
#include "itkImageLinearIteratorWithIndex.h"
#include "itkBasicNLMeansFilter.h"

#endif // _WITHOUT_ITK_

#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkBasicNLMeansFilter.h"


InrImage* wrap_itkBasicNLMeans2D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

  char functionname[] = "itkBasicNLMeans2D";
  char description[]=" \n\
        Reduces the noise of an image 2D trhough NLMeans filter.\n\
      ";
	  
  char parameters[] =" \n\
					Parameters:\n\
					input image \n\
					searching window (def:7) \n\
					pattern window (def:3) \n\
					threshold (def:10) \n\
					noise (def:0) \n\
      ";
			
  InrImage* input = NULL;
  int     searching = 7;
  int     pattern = 3;
  float   threshold = 10;
  int     noise = 0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
  if (!get_int_param(  searching,    p, n)) HelpAndReturnNULL;
  if (!get_int_param(  pattern,      p, n)) HelpAndReturnNULL;
  if (!get_float_param(	threshold, 	 p, n)) HelpAndReturnNULL;
  if (!get_int_param(	noise,	 	 p, n)) HelpAndReturnNULL;

  typedef float               PixelType;
  const   unsigned int        Dimension = 2;
  typedef itk::Image< PixelType, Dimension >    ImageType;
  ImageType::RegionType region;
  ImageType::Pointer image;
  typedef itk::ImageLinearConstIteratorWithIndex< ImageType >  ConstIteratorType;
  typedef itk::ImageLinearIteratorWithIndex< ImageType >       IteratorType;

  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
 
	image = InrToITK<PixelType,Dimension>(input,region);

  // Apply the filter
  // Set up  image filter
  cout << "Applying filter " << endl;

  try {
    typedef itk::BasicNLMeansFilter<ImageType,ImageType> NLMeansType;
    NLMeansType::Pointer nlmeans = NLMeansType::New();
	
		ImageType::SizeType i_f;
  
		i_f[0]=pattern;
		i_f[1]=pattern;

		nlmeans->SetInput( image );
    nlmeans->SetSearching(searching);
    nlmeans->SetPattern(i_f);
    nlmeans->SetThreshold(threshold);
    nlmeans->SetNoise(noise);
    nlmeans->Update();
    image = nlmeans->GetOutput();
  } catch (itk::ExceptionObject & err )
    {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return NULL;
    }

  // Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

  res = ITKToInr<PixelType,Dimension>(image, region);

  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_


} // wrap_itkBasicNLMeansFilter2D


//--------------------------------------------------------------------------
//
InrImage* wrap_itkBasicNLMeans3D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

  char functionname[] = "itkBasicNLMeans3D";
  char description[]=" \n\
        Reduces the noise of an image 3D trhough NLMeans filter.\n\
      ";
	  
  char parameters[] =" \n\
					Parameters:\n\
					input image \n\
					searching window (def:7) \n\
					pattern window (def:3) \n\
					threshold (def:10) \n\
					noise (def:0) \n\
      ";
    
  InrImage* input = NULL;
  int     searching = 7;
  int     pattern = 3;
  float   threshold = 10;
  int     noise = 0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
  if (!get_int_param(  searching,    p, n)) HelpAndReturnNULL;
  if (!get_int_param(  pattern,      p, n)) HelpAndReturnNULL;
  if (!get_float_param(	threshold, 	 p, n)) HelpAndReturnNULL;
  if (!get_int_param(	noise,	 	 p, n)) HelpAndReturnNULL;

  typedef float               PixelType;
  const   unsigned int        Dimension = 3;
  typedef itk::Image< PixelType, Dimension >    ImageType;
  ImageType::RegionType region;
  ImageType::Pointer image;
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
  	
	image = InrToITK<PixelType,Dimension>(input,region);

  // Apply the filter
  // Set up  image filter
  cout << "Applying filter " << endl;

  try {
    typedef itk::BasicNLMeansFilter<ImageType,ImageType> NLMeansType;
    NLMeansType::Pointer nlmeans = NLMeansType::New();
	
		ImageType::SizeType i_f;
  
		i_f[0]=pattern;
		i_f[1]=pattern;
		i_f[2]=pattern;

    nlmeans->SetInput( image );
    nlmeans->SetSearching(searching);
    nlmeans->SetPattern(i_f);
    nlmeans->SetThreshold(threshold);
    nlmeans->SetNoise(noise);
    nlmeans->Update();
    image = nlmeans->GetOutput();
  } catch (itk::ExceptionObject & err )
    {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return NULL;
    }

  // Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

  res = ITKToInr<PixelType,Dimension>(image, region);

	return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_

} // wrap_itkBasicNLMeansFilter3D