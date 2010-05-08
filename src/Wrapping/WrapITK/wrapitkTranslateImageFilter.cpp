#include "AMILabConfig.h"

#ifndef _WITHOUT_ITK_
#include "itkTranslateImageFilter.h"
#endif // _WITHOUT_ITK_

#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkTranslateImageFilter.h"

InrImage* wrap_itkTranslateImageFilter2D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

  char functionname[] = "itkTranslateImageFilter2D";
  char description[]=" \n\
        Filter to translate an image in 2D.\n\
      ";
    
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          DisplaceX \n\
          DisplaceY \n\
      ";
    
  InrImage* input = NULL;
  int displaceX = 0;
  int displaceY = 0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
  if (!get_int_param  (  displaceX,   p, n)) HelpAndReturnNULL;
  if (!get_int_param  (  displaceY,   p, n)) HelpAndReturnNULL;
 
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

  typedef itk::TranslateImageFilter< InternalImageType, InternalImageType > TranslateImageFilterType;
  TranslateImageFilterType::Pointer translate = TranslateImageFilterType::New();
  
  translate->SetInput( image );

  translate->SetDisplaceX(displaceX);
  translate->SetDisplaceY(displaceY);

  translate->Update();
  outimage = translate->GetOutput();

  // Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

  res = ITKToInr<InternalPixelType,Dimension>(outimage, region);
  
  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkTranslateImageFilter2D


InrImage* wrap_itkTranslateImageFilter3D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

  char functionname[] = "itkTranslateImageFilter2D";
  char description[]=" \n\
        Filter to translate an image in 2D.\n\
      ";
    
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          DisplaceX \n\
          DisplaceY \n\
          DisplaceZ \n\
      ";
    
  InrImage* input = NULL;
  int displaceX = 0;
  int displaceY = 0;
  int displaceZ = 0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
  if (!get_int_param  (  displaceX,   p, n)) HelpAndReturnNULL;
  if (!get_int_param  (  displaceY,   p, n)) HelpAndReturnNULL;
  if (!get_int_param  (  displaceZ,   p, n)) HelpAndReturnNULL;
 
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

  typedef itk::TranslateImageFilter< InternalImageType, InternalImageType > TranslateImageFilterType;
  TranslateImageFilterType::Pointer translate = TranslateImageFilterType::New();
  
  translate->SetInput( image );

  translate->SetDisplaceX(displaceX);
  translate->SetDisplaceY(displaceY);
  translate->SetDisplaceZ(displaceZ);

  translate->Update();
  outimage = translate->GetOutput();

  // Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

  res = ITKToInr<InternalPixelType,Dimension>(outimage, region);
  
  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkTranslateImageFilter3D