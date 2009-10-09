
#include "AMILabConfig.h"

#ifdef AMI_USE_ITK

#include "itkImage.h"
#include "itkImageIOBase.h"
#include "itkFastMarchingImageFilter.h"

#endif // AMI_USE_ITK

#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkFastMarchingImageFilter.h"

InrImage* itkFastMarchingImageFilter2D(ParamList* p)
{
  clock_t ITime = clock();

#ifdef AMI_USE_ITK

  char functionname[] = "itkFastMarchingImageFilter2D";
  char description[]=" \n\
        Filter to compute a fast marching solution in 2D.\n\
      ";
    
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          seedX \n\
          seedY \n\
      ";
    
  InrImage* input = NULL;
  int seedX = 0;
  int seedY = 0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
  if (!get_int_param(  seedX,    p, n)) HelpAndReturnNULL;
  if (!get_int_param(  seedY,      p, n)) HelpAndReturnNULL;
 
 
  typedef float               PixelType;
  const   unsigned int        Dimension = 2;
  typedef itk::Image< PixelType, Dimension >    ImageType;
  ImageType::RegionType region;
  ImageType::Pointer image;

  typedef float OutputPixelType;
  typedef itk::Image< OutputPixelType,Dimension > outType;
  outType::Pointer outimage;
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
    
  image = InrToITK<PixelType,Dimension>(input,region);
  
  cout << "Conversi�n hecha" << endl;

  // Apply the filter
  // Set up  image filter
  cout << "Applying filter " << endl;
  try {
    typedef itk::FastMarchingImageFilter< ImageType, ImageType >  FilterType;
    FilterType::Pointer fastMarching = FilterType::New();
    
    fastMarching->SetInput(image);
    
    typedef FilterType::NodeContainer NodeContainer;
    typedef FilterType::NodeType NodeType;
    NodeContainer::Pointer seeds = NodeContainer::New();
    
    ImageType::IndexType seedPosition;
    
    seedPosition[0] = seedX;
    seedPosition[1] = seedY;
    
    NodeType node;
    const double seedValue = 0.0;
    
    node.SetValue(seedValue);
    node.SetIndex(seedPosition);
    
    seeds->Initialize();
    seeds->InsertElement(0,node);
    
    fastMarching->SetTrialPoints(seeds);

    fastMarching->SetOutputSize(image->GetBufferedRegion().GetSize());

    fastMarching->Update();

    outimage = fastMarching->GetOutput();
    
  } catch (itk::ExceptionObject & err )
    {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return NULL;
    }

  // Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

  res = ITKToInr<PixelType,Dimension>(outimage, region);
//  cout << "Sale ?" << endl;
//  clock_t FTime = clock();
//  float seg = (FTime - ITime) / CLK_TCK;
  
//  std::cout << "Time: " << seg << "seg" << std::endl;
  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // AMI_USE_ITK 
} //itkFastMarchingImageFilter2D


InrImage* itkFastMarchingImageFilter3D(ParamList* p)
{
  clock_t ITime = clock();

#ifdef AMI_USE_ITK

  char functionname[] = "itkFastMarchingImageFilter3D";
  char description[]=" \n\
        Filter to compute a fast marching solution in 3D.\n\
      ";
    
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          seedX \n\
          seedY \n\
          seedZ \n\
      ";
    
  InrImage* input = NULL;
  int seedX = 0;
  int seedY = 0;
  int seedZ = 0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
  if (!get_int_param(  seedX,    p, n)) HelpAndReturnNULL;
  if (!get_int_param(  seedY,      p, n)) HelpAndReturnNULL;
  if (!get_int_param(  seedZ,      p, n)) HelpAndReturnNULL;
 
 
  typedef float               PixelType;
  const   unsigned int        Dimension = 3;
  typedef itk::Image< PixelType, Dimension >    ImageType;
  ImageType::RegionType region;
  ImageType::Pointer image;

  typedef float OutputPixelType;
  typedef itk::Image< OutputPixelType,Dimension > outType;
  outType::Pointer outimage;
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
    
  image = InrToITK<PixelType,Dimension>(input,region);
  
  cout << "Conversi�n hecha" << endl;

  // Apply the filter
  // Set up  image filter
  cout << "Applying filter " << endl;
  try {
    typedef itk::FastMarchingImageFilter< ImageType, ImageType >  FilterType;
    FilterType::Pointer fastMarching = FilterType::New();
    
    fastMarching->SetInput(image);
    
    typedef FilterType::NodeContainer NodeContainer;
    typedef FilterType::NodeType NodeType;
    NodeContainer::Pointer seeds = NodeContainer::New();
    
    ImageType::IndexType seedPosition;
    
    seedPosition[0] = seedX;
    seedPosition[1] = seedY;
    seedPosition[2] = seedZ;
    
    NodeType node;
    const double seedValue = 0.0;
    
    node.SetValue(seedValue);
    node.SetIndex(seedPosition);
    
    seeds->Initialize();
    seeds->InsertElement(0,node);
    
    fastMarching->SetTrialPoints(seeds);

    fastMarching->SetOutputSize(image->GetBufferedRegion().GetSize());

    fastMarching->Update();

    outimage = fastMarching->GetOutput();
    
  } catch (itk::ExceptionObject & err )
    {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return NULL;
    }

  // Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

  res = ITKToInr<PixelType,Dimension>(outimage, region);
//  cout << "Sale ?" << endl;
//  clock_t FTime = clock();
//  float seg = (FTime - ITime) / CLK_TCK;
  
//  std::cout << "Time: " << seg << "seg" << std::endl;
  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // AMI_USE_ITK 
} //itkFastMarchingImageFilter3D
