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

#ifndef _WITHOUT_ITK_
#include <stddef.h>
#include "itkImage.h"
#include "itkImageIOBase.h"
#include "itkImageLinearConstIteratorWithIndex.h"
#include "itkImageLinearIteratorWithIndex.h"
#include "itkBasicNLMeansFilter.h"

#endif // _WITHOUT_ITK_

#include "paramlist.h"
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

  InrImage*   input = NULL;
  int         searching = 7;
  int         pattern = 3;
  float       threshold = 10;
  int         noise = 0;
  InrImage*   res = NULL;
  int         n=0;
  
  if (!get_val_ptr_param<InrImage>( input,     p, n)) HelpAndReturnNULL;
  if (!get_int_param              ( searching, p, n)) HelpAndReturnNULL;
  if (!get_int_param              ( pattern,   p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( threshold, p, n)) HelpAndReturnNULL;
  if (!get_int_param              ( noise,     p, n)) HelpAndReturnNULL;

  typedef float               PixelType;
  const unsigned int          Dimension = 2;
  
  typedef itk::Image< PixelType, Dimension > ImageType;
  ImageType::RegionType region;
  ImageType::Pointer image;
  typedef itk::ImageLinearConstIteratorWithIndex< ImageType > ConstIteratorType;
  typedef itk::ImageLinearIteratorWithIndex< ImageType > IteratorType;

  // Convert from InrImage to ITK
  std::cout << "Converting image to ITK format " << std::endl;
 
  image = InrToITK<PixelType,Dimension>(input,region);

  // Apply the filter
  // Set up image filter
 std::cout << "Applying filter " << std::endl;

  try {
    typedef itk::BasicNLMeansFilter<ImageType,ImageType> NLMeansType;
    NLMeansType::Pointer nlmeans = NLMeansType::New();

    ImageType::SizeType i_f;
  
    //Need to use a SizeType to pass then to SetPattern
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
 std::cout << "Converting back to InrImage " << std::endl;

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
  int       searching = 7;
  int       pattern = 3;
  float     threshold = 10;
  int       noise = 0;
  InrImage* res = NULL;
  int       n=0;
  
  if (!get_val_ptr_param<InrImage>( input,     p, n)) HelpAndReturnNULL;
  if (!get_int_param              ( searching, p, n)) HelpAndReturnNULL;
  if (!get_int_param              ( pattern,   p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( threshold, p, n)) HelpAndReturnNULL;
  if (!get_int_param              ( noise,     p, n)) HelpAndReturnNULL;

  typedef float               PixelType;
  const unsigned int          Dimension = 3;
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
 std::cout << "Converting back to InrImage " << std::endl;

  res = ITKToInr<PixelType,Dimension>(image, region);

  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_

} // wrap_itkBasicNLMeansFilter3D
