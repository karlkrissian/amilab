#include "AMILabConfig.h"

#ifndef _WITHOUT_ITK_
#include "itkLocalMeanImageFilter.h"
#endif // _WITHOUT_ITK_

#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkLocalMeanImageFilter.h"

InrImage* wrap_itkLocalMeanImageFilter2D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

	char functionname[] = "itkLocalMeanImageFilter2D";
  char description[]=" \n\
        Filter to compute a local mean solution in 2D.\n\
      ";
    
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          Window \n\
      ";
    
  InrImage* input = NULL;
  int window = 0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
  if (!get_int_param  (  window,     p, n)) HelpAndReturnNULL;
 
  typedef float       InternalPixelType;
  const unsigned int  Dimension = 2;
  typedef itk::Image< InternalPixelType, Dimension >    InternalImageType;
  InternalImageType::RegionType region;
  InternalImageType::Pointer image;
  InternalImageType::Pointer outimage;
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
    
  image = InrToITK<InternalPixelType,Dimension>(input,region);
  
  cout << "Conversión hecha" << endl;

  typedef itk::LocalMeanImageFilter< InternalImageType, InternalImageType > LocalMeanFilterType;
  LocalMeanFilterType::Pointer localmean = LocalMeanFilterType::New();
  
  localmean->SetInput( image );

  localmean->SetWindow( window );
  localmean->SetNumberOfThreads(1);
    
  localmean->Update();
  outimage = localmean->GetOutput();

  // Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

  res = ITKToInr<InternalPixelType,Dimension>(outimage, region);
  
  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkLocalMeanImageFilter2D


InrImage* wrap_itkLocalMeanImageFilter3D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

  char functionname[] = "itkLocalMeanImageFilter3D";
  char description[]=" \n\
        Filter to compute a local mean solution in 3D.\n\
      ";
    
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          Window \n\
      ";
    
  InrImage* input = NULL;
  int window = 0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
  if (!get_int_param  (  window,     p, n)) HelpAndReturnNULL;
 
  typedef float       InternalPixelType;
  const unsigned int  Dimension = 3;
  typedef itk::Image< InternalPixelType, Dimension >    InternalImageType;
  InternalImageType::RegionType region;
  InternalImageType::Pointer image;
  InternalImageType::Pointer outimage;
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
    
  image = InrToITK<InternalPixelType,Dimension>(input,region);
  
  cout << "Conversión hecha" << endl;

  typedef itk::LocalMeanImageFilter< InternalImageType, InternalImageType > LocalMeanFilterType;
  LocalMeanFilterType::Pointer localmean = LocalMeanFilterType::New();
  
  localmean->SetInput( image );

  localmean->SetWindow( window );
  localmean->SetNumberOfThreads(1);
    
  localmean->Update();
  outimage = localmean->GetOutput();

  // Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

  res = ITKToInr<InternalPixelType,Dimension>(outimage, region);
  
  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkLocalMeanImageFilter3D