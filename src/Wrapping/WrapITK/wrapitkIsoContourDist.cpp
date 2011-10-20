#include "AMILabConfig.h"

#ifdef AMI_USE_ITK

//#include "inrimage.hpp"
#include <stddef.h>
#include "itkImage.h"
#include "itkImageIOBase.h"
#include "itkImageLinearConstIteratorWithIndex.h"
#include "itkImageLinearIteratorWithIndex.h"
#include "itkIsoContourDistanceImageFilter.h"

#endif // AMI_USE_ITK

#include "paramlist.h"

#include "wrapfunctions.hpp" 
#include "wrapConversion.h"
#include "wrapitkIsoContourDist.h"


InrImage* wrap_itkIsoContourDist2D(ParamList* p)
{

#ifdef AMI_USE_ITK

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
  
  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(  threshold,  p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(  farvalue,   p, n)) HelpAndReturnNULL;

  typedef float               PixelType;
  const   unsigned int        Dimension = 2;
  typedef itk::Image< PixelType, Dimension >    ImageType;
  ImageType::RegionType region;
  ImageType::Pointer image;
  typedef itk::ImageLinearConstIteratorWithIndex< ImageType >  ConstIteratorType;
  typedef itk::ImageLinearIteratorWithIndex< ImageType >       IteratorType;

  // Convert from InrImage to ITK
  std::cout << "Converting image to ITK format " << std::endl;

  image = InrToITK<PixelType,Dimension>(input,region);

  // Apply the filter
  // Set up  image filter
 std::cout << "Applying filter " << std::endl;

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
 std::cout << "Converting back to InrImage " << std::endl;

  res = ITKToInr<PixelType,Dimension>(image, region);

  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // AMI_USE_ITK

} // wrap_itkIsoContourDist2D


InrImage* wrap_itkIsoContourDist3D(ParamList* p)
{

#ifdef AMI_USE_ITK

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
  
  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(  threshold,  p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(  farvalue,   p, n)) HelpAndReturnNULL;

  typedef float               PixelType;
  const   unsigned int        Dimension = 3;
  typedef itk::Image< PixelType, Dimension >    ImageType;
  ImageType::RegionType region;
  ImageType::Pointer image;
  typedef itk::ImageLinearConstIteratorWithIndex< ImageType >  ConstIteratorType;
  typedef itk::ImageLinearIteratorWithIndex< ImageType >       IteratorType;

  // Convert from InrImage to ITK
  std::cout << "Converting image to ITK format " << std::endl;

  image = InrToITK<PixelType,Dimension>(input,region);

  // Apply the filter
  // Set up  image filter
 std::cout << "Applying filter " << std::endl;

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
 std::cout << "Converting back to InrImage " << std::endl;

  res = ITKToInr<PixelType,Dimension>(image, region);

  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // AMI_USE_ITK

} // wrap_itkIsoContourDist3D
