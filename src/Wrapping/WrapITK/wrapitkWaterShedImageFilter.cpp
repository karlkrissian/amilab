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
#include "itkWatershedImageFilter.h"
#endif // _WITHOUT_ITK_

#include "paramlist.h"
#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkWaterShedImageFilter.h"
#include "message_dialog.h"

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
  WatershedFilterType::OutputImageType::Pointer outimage;

  // Convert from InrImage to ITK
  std::cout << "Converting image to ITK format " << std::endl;

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
 std::cout << "Converting back to InrImage " << std::endl;

  res = ITKToInr<itk::IdentifierType,Dimension>(outimage, region);

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

  WatershedFilterType::OutputImageType::Pointer outimage;

  // Convert from InrImage to ITK
  std::cout << "Converting image to ITK format " << std::endl;

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
 std::cout << "Converting back to InrImage " << std::endl;

  res = ITKToInr<itk::IdentifierType,Dimension>(outimage, region);

  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkWaterShedImageFilter3D

