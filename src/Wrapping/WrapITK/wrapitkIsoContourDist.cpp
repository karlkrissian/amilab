#ifndef _WITHOUT_ITK_

#include "itkImage.h"
#include "itkImageIOBase.h"
#include "itkImageLinearConstIteratorWithIndex.h"
#include "itkImageLinearIteratorWithIndex.h"
#include "itkIsoContourDistanceImageFilter.h"

#endif // _WITHOUT_ITK_

#include "wrapfunctions.hpp" 
#include "wrapConversion.h"
#include "wrapitkIsoContourDist.h"


InrImage* itkIsoContourDist(ParamList* p)
{

#ifndef _WITHOUT_ITK_

  char functionname[] = "itkIsoContourDist";
  char description[]=" \n\
        Computes an approximation of the distance to the isocontour\n\
      ";
  char parameters[] =" \n\
					Parameters:\n\
          input image \n\
          isocontour threshold (def:0)\n\
          far value (def:10)\n\
      ";
    
  //std::string*  filename_param = NULL;
  InrImage* input = NULL;
  float     threshold = 0;
  float     farvalue = 10;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
  if (!get_float_param(  threshold,  p, n)) HelpAndReturnNULL;
  if (!get_float_param(  farvalue,   p, n)) HelpAndReturnNULL;

  typedef float               PixelType;
  const   unsigned int        Dimension = 3;
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
    typedef itk::IsoContourDistanceImageFilter<ImageType,ImageType> IsoContourType;
    IsoContourType::Pointer isocontour = IsoContourType::New();
    isocontour->SetInput( image );
    isocontour->SetFarValue(farvalue);
    isocontour->SetLevelSetValue(threshold );
    isocontour->NarrowBandingOff();
    isocontour->SetNumberOfThreads(1);
    isocontour->Update();
    image = isocontour->GetOutput();
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

} // itkIsoContourDist