
#include "AMILabConfig.h"

#ifdef AMI_USE_ITK

#include "itkImage.h"
#include "itkImageIOBase.h"
#include "itkRecursiveGaussianImageFilter.h"

#endif // AMI_USE_ITK

#include "wrapfunctions.hpp" 
#include "wrapConversion.h"


InrImage* itkRecursiveGaussianImageFilter2D(ParamList* p)
{
  clock_t ITime = clock();

#ifdef AMI_USE_ITK

  char functionname[] = "itkRecursiGaussianImageFilter2d";
  char description[]=" \n\
        Filter to compute IIR convolution with an approximation of a Gaussian kernel.\n\
      ";
    
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          sigma \n\
          NormAcrossScale \n\
          order \n\
      ";
    
  InrImage* input = NULL;
  float sigma = 0.01;
  int N_A_S = 1;
  int order = 0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_var_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
  if (!get_param<float>(  sigma,    p, n)) HelpAndReturnNULL;
  if (!get_int_param(  N_A_S,      p, n)) HelpAndReturnNULL;
  if (!get_int_param( order,   p, n)) HelpAndReturnNULL;
 
  typedef float               PixelType;
  const   unsigned int        Dimension = 2;
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
    typedef itk::RecursiveGaussianImageFilter< ImageType, ImageType >  FilterType;
    FilterType::Pointer gaussianX = FilterType::New();
    FilterType::Pointer gaussianY = FilterType::New();
    
    gaussianX->SetDirection(0);
    gaussianY->SetDirection(1);
    
    switch(order){
      case 0:
        gaussianX->SetOrder(FilterType::ZeroOrder);
        gaussianY->SetOrder(FilterType::ZeroOrder);
        break;
      case 1:
        gaussianX->SetOrder(FilterType::FirstOrder);
        gaussianY->SetOrder(FilterType::FirstOrder);
        break;
      case 2:
        gaussianX->SetOrder(FilterType::SecondOrder);
        gaussianY->SetOrder(FilterType::SecondOrder);
        break;
    }
    
    if (N_A_S == 1)
    {
      gaussianX->SetNormalizeAcrossScale(true);
      gaussianY->SetNormalizeAcrossScale(true);
    }
    
    if (N_A_S == 0)
    {
      gaussianX->SetNormalizeAcrossScale(false);
      gaussianY->SetNormalizeAcrossScale(false);
    }
    
    gaussianX->SetInput( image );
    gaussianY->SetInput( gaussianX->GetOutput() );
    
    gaussianX->SetSigma(sigma);
    gaussianY->SetSigma(sigma);
    
    gaussianY->Update();
    
    image = gaussianY->GetOutput();
    
  } catch (itk::ExceptionObject & err )
    {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return NULL;
    }

  // Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

  res = ITKToInr<PixelType,Dimension>(image, region);
  clock_t FTime = clock();
  float seg = (FTime - ITime) / CLOCKS_PER_SEC;
//CLK_TCK;
  
  std::cout << "Time: " << seg << "seg" << std::endl;
  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // AMI_USE_ITK
} //itkRecursiveGaussianImageFilter2D


InrImage* itkRecursiveGaussianImageFilter3D(ParamList* p)
{
  clock_t ITime = clock();

#ifdef AMI_USE_ITK

  char functionname[] = "itkRecursiGaussianImageFilter2d";
  char description[]=" \n\
        Filter to compute IIR convolution with an approximation of a Gaussian kernel.\n\
      ";
    
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          sigma \n\
          NormAcrossScale \n\
          order \n\
      ";
    
  InrImage* input = NULL;
  float sigma = 0.01;
  int N_A_S = 1;
  int order = 0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_var_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
  if (!get_param<float>(  sigma,    p, n)) HelpAndReturnNULL;
  if (!get_int_param(  N_A_S,      p, n)) HelpAndReturnNULL;
  if (!get_int_param( order,   p, n)) HelpAndReturnNULL;
 
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
    typedef itk::RecursiveGaussianImageFilter< ImageType, ImageType >  FilterType;
    FilterType::Pointer gaussianX = FilterType::New();
    FilterType::Pointer gaussianY = FilterType::New();
    FilterType::Pointer gaussianZ = FilterType::New();
    
    gaussianX->SetDirection(0);
    gaussianY->SetDirection(1);
    gaussianZ->SetDirection(2);
    
    switch(order){
      case 0:
        gaussianX->SetOrder(FilterType::ZeroOrder);
        gaussianY->SetOrder(FilterType::ZeroOrder);
        gaussianZ->SetOrder(FilterType::ZeroOrder);
        break;
      case 1:
        gaussianX->SetOrder(FilterType::FirstOrder);
        gaussianY->SetOrder(FilterType::FirstOrder);
        gaussianZ->SetOrder(FilterType::FirstOrder);
        break;
      case 2:
        gaussianX->SetOrder(FilterType::SecondOrder);
        gaussianY->SetOrder(FilterType::SecondOrder);
        gaussianZ->SetOrder(FilterType::SecondOrder);
        break;
    }
    
    if (N_A_S == 1)
    {
      gaussianX->SetNormalizeAcrossScale(true);
      gaussianY->SetNormalizeAcrossScale(true);
      gaussianZ->SetNormalizeAcrossScale(true);
    }
    
    if (N_A_S == 0)
    {
      gaussianX->SetNormalizeAcrossScale(false);
      gaussianY->SetNormalizeAcrossScale(false);
      gaussianZ->SetNormalizeAcrossScale(false);
    }
    
    gaussianX->SetInput( image );
    gaussianY->SetInput( gaussianX->GetOutput() );
    gaussianZ->SetInput( gaussianY->GetOutput() );
    
    gaussianX->SetSigma(sigma);
    gaussianY->SetSigma(sigma);
    gaussianZ->SetSigma(sigma);
    
    gaussianZ->Update();
    
    image = gaussianZ->GetOutput();
    
  } catch (itk::ExceptionObject & err )
    {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return NULL;
    }

  // Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

  res = ITKToInr<PixelType,Dimension>(image, region);
  clock_t FTime = clock();
  float seg = (FTime - ITime) / CLOCKS_PER_SEC;
  //CLK_TCK;
  
  std::cout << "Time: " << seg << "seg" << std::endl;
  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // AMI_USE_ITK
} //itkRecursiveGaussianImageFilter3D
