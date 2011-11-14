/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
               Sara Arencibia
    Email    : karl@bwh.harvard.edu
               darkmind@gmail.com

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/

#include "AMILabConfig.h"

#ifdef AMI_USE_ITK

#include <stddef.h>
#include "itkImage.h"
#include "itkImageIOBase.h"
#include "itkRecursiveGaussianImageFilter.h"

#endif // AMI_USE_ITK

#include "paramlist.h"
#include "wrapfunctions.hpp" 
#include "wrapConversion.h"
#include "wrapitkRecursiveGaussianImageFilter.h"


//---------------------------------------------------------------------------------
InrImage* wrap_itkRecursiveGaussianImageFilter2D(ParamList* p)
{

  char functionname[] = "itkRecursiGaussianImageFilter2d";
  char description[]=" \n\
        Filter to compute IIR convolution with an approximation of a Gaussian kernel.\n\
      ";
    
  char parameters[] =" \n\
          Parameters:\n\
           - input image \n\
           - sigma (def:1): Gaussian standard deviation.\n\
           - NormAcrossScale: scale normalization.\n\
           - order in X (def:0) order of the Gaussian derivative in X.\n\
           - order in Y (def:0) order of the Gaussian derivative in Y.\n\
      ";
    
  InrImage* input = NULL;
  float sigma = 1;
  int N_A_S = 1;
  int order_x = 0;
  int order_y = 0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>( input, p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( sigma, p, n)) HelpAndReturnNULL;
  if (!get_val_param<int>         ( N_A_S, p, n)) HelpAndReturnNULL;
  if (!get_val_param<int>         ( order_x, p, n)) HelpAndReturnNULL;
  if (!get_val_param<int>         ( order_y, p, n)) HelpAndReturnNULL;
 
  typedef float               PixelType;
  const   unsigned int        Dimension = 2;
  typedef itk::Image< PixelType, Dimension > ImageType;
  ImageType::RegionType region;
  ImageType::Pointer image;
  
  // Convert from InrImage to ITK
  std::cout << "Converting image to ITK format " << std::endl;
    
  image = InrToITK<PixelType,Dimension>(input,region);

  // Apply the filter
  // Set up  image filter
  std::cout << "Applying filter " << std::endl;

  try {
    typedef itk::RecursiveGaussianImageFilter< ImageType, ImageType >  FilterType;
    FilterType::Pointer gaussianX = FilterType::New();
    FilterType::Pointer gaussianY = FilterType::New();
    
    gaussianX->SetDirection(0);
    gaussianY->SetDirection(1);
    
    gaussianX->SetOrder(FilterType::OrderEnumType(order_x));
    gaussianY->SetOrder(FilterType::OrderEnumType(order_y));
    
    gaussianX->SetNormalizeAcrossScale(N_A_S);
    gaussianY->SetNormalizeAcrossScale(N_A_S);
    
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
 std::cout << "Converting back to InrImage " << std::endl;

  res = ITKToInr<PixelType,Dimension>(image, region);

  return res;

} // wrap_itkRecursiveGaussianImageFilter2D


//---------------------------------------------------------------------------------
InrImage* wrap_itkRecursiveGaussianImageFilter3D(ParamList* p)
{

  char functionname[] = "itkRecursiGaussianImageFilter3D";
  char description[]=" \n\
        Filter to compute IIR convolution with an approximation of a Gaussian kernel.\n\
      ";
    
  char parameters[] =" \n\
          Parameters:\n\
           - input image \n\
           - sigma (def:1): Gaussian standard deviation.\n\
           - NormAcrossScale: scale normalization.\n\
           - order in X (def:0) order of the Gaussian derivative in X.\n\
           - order in Y (def:0) order of the Gaussian derivative in Y.\n\
           - order in Z (def:0) order of the Gaussian derivative in Z.\n\
      ";
    
  InrImage* input = NULL;
  float sigma = 0.01;
  int N_A_S = 1;
  int order_x = 0;
  int order_y = 0;
  int order_z = 0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>( input, p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( sigma, p, n)) HelpAndReturnNULL;
  if (!get_val_param<int>         ( N_A_S, p, n)) HelpAndReturnNULL;
  if (!get_val_param<int>         ( order_x, p, n)) HelpAndReturnNULL;
  if (!get_val_param<int>         ( order_y, p, n)) HelpAndReturnNULL;
  if (!get_val_param<int>         ( order_z, p, n)) HelpAndReturnNULL;
 
  typedef float               PixelType;
  const   unsigned int        Dimension = 3;
  typedef itk::Image< PixelType, Dimension > ImageType;
  ImageType::RegionType region;
  ImageType::Pointer image;
  
  // Convert from InrImage to ITK
  std::cout << "Converting image to ITK format " << std::endl;
    
  image = InrToITK<PixelType,Dimension>(input,region);

  // Apply the filter
  // Set up  image filter
  std::cout << "Applying filter " << std::endl;

  try {
    typedef itk::RecursiveGaussianImageFilter< ImageType, ImageType >  FilterType;
    FilterType::Pointer gaussianX = FilterType::New();
    FilterType::Pointer gaussianY = FilterType::New();
    FilterType::Pointer gaussianZ = FilterType::New();
    
    gaussianX->SetDirection(0);
    gaussianY->SetDirection(1);
    gaussianZ->SetDirection(2);
    
    gaussianX->SetOrder(FilterType::OrderEnumType(order_x));
    gaussianY->SetOrder(FilterType::OrderEnumType(order_y));
    gaussianZ->SetOrder(FilterType::OrderEnumType(order_z));
    
    gaussianX->SetSigma(sigma);
    gaussianY->SetSigma(sigma);
    gaussianZ->SetSigma(sigma);

    gaussianX->SetNormalizeAcrossScale(N_A_S);
    gaussianY->SetNormalizeAcrossScale(N_A_S);
    gaussianZ->SetNormalizeAcrossScale(N_A_S);
    
    gaussianX->SetInput( image );
    gaussianY->SetInput( gaussianX->GetOutput() );
    gaussianZ->SetInput( gaussianY->GetOutput() );
        
    gaussianZ->Update();
    
    image = gaussianZ->GetOutput();
    
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

} // wrap_itkRecursiveGaussianImageFilter3D
