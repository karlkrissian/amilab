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
//#include "itkRescaleIntensityImageFilter.h"
#include "itkImage.h"
#include "itkHessian3DToVesselnessMeasureImageFilter.h"
#include "itkMultiScaleHessianBasedMeasureImageFilter.h"
#include "itkHessianToObjectnessMeasureImageFilter.h"
#endif // _WITHOUT_ITK_

#include "paramlist.h"
#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkMultiScaleVesselnessFilter.h"

InrImage* wrap_itkMultiScaleVesselnessFilter2D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

  char functionname[] = "itkMultiScaleVesselnessFilter2D";
  char description[]=" \n\
        Filter to compute a multiscale vesselness measure in 2D.\n\
      ";
    
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          sigmaMin \n\
          sigmaMax \n\
          numberOfScales \n\
      ";

  InrImage* input = NULL;
  InrImage* res = NULL;
  float sigmaMin = 0.0;
  float sigmaMax = 0.0;
  int numberOfScales = 0;
  int n=0;

  if (!get_val_ptr_param<InrImage>( input,          p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( sigmaMin,       p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( sigmaMax,       p, n)) HelpAndReturnNULL;
  if (!get_int_param              ( numberOfScales, p, n)) HelpAndReturnNULL;
  
  const unsigned char Dimension = 2;

  typedef float PixelType;

  // Declare the types of the images
  typedef itk::Image<PixelType,Dimension> ImageType;

  ImageType::Pointer outimage;

  //typedef itk::RescaleIntensityImageFilter<ImageType> RescaleFilterType;
 
  // Declare the type of enhancement filter
  typedef itk::HessianToObjectnessMeasureImageFilter<double,Dimension> ObjectnessFilterType;
  
  // Declare the type of multiscale enhancement filter
  typedef itk::MultiScaleHessianBasedMeasureImageFilter<ImageType,ObjectnessFilterType> MultiScaleEnhancementFilterType;

  // Convert from InrImage to ITK
  ImageType::RegionType region;
  ImageType::Pointer image;
  std::cout << "Converting image to ITK format " << std::endl;

  image = InrToITK<PixelType,Dimension>(input,region);

  std::cout << "Conversion done" << std::endl;

  MultiScaleEnhancementFilterType::Pointer multiScaleEnhancementFilter = MultiScaleEnhancementFilterType::New();
  multiScaleEnhancementFilter->SetInput(image);

  ObjectnessFilterType* objectnessFilter = multiScaleEnhancementFilter->GetHessianToMeasureFilter();
  objectnessFilter->SetScaleObjectnessMeasure(false);
  objectnessFilter->SetBrightObject(false);
  objectnessFilter->SetGamma(5.0);

  multiScaleEnhancementFilter->SetSigmaMin( sigmaMin  );
  multiScaleEnhancementFilter->SetSigmaMax( sigmaMax );
  multiScaleEnhancementFilter->SetNumberOfSigmaSteps( numberOfScales );

  multiScaleEnhancementFilter->Update();

  outimage = multiScaleEnhancementFilter->GetOutput();
  
 std::cout << "Converting back to InrImage " << std::endl;

  res = ITKToInr<PixelType,Dimension>(outimage, region);

  return res;
#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkMultiScaleVesselnessFilter2D

InrImage* wrap_itkMultiScaleVesselnessFilter3D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

char functionname[] = "itkMultiScaleVesselnessFilter3D";
  char description[]=" \n\
        Filter to compute a multiscale vesselness measure in 3D.\n\
      ";

  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          sigmaMin \n\
          sigmaMax \n\
          numberOfScales \n\
      ";

  InrImage* input = NULL;
  InrImage* res = NULL;
  float sigmaMin = 0.0;
  float sigmaMax = 0.0;
  int numberOfScales = 0;
  int n=0;

  if (!get_val_ptr_param<InrImage>( input,          p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( sigmaMin,       p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( sigmaMax,       p, n)) HelpAndReturnNULL;
  if (!get_int_param              ( numberOfScales, p, n)) HelpAndReturnNULL;


  const unsigned char Dimension = 3;

  typedef float PixelType;

  // Declare the types of the images
  typedef itk::Image<PixelType,Dimension> ImageType;

  ImageType::Pointer outimage;

  // Declare the type of enhancement filter - use ITK's 3D vesselness
  typedef itk::Hessian3DToVesselnessMeasureImageFilter<double> VesselnessFilterType;
  
  // Declare the type of multiscale enhancement filter
  typedef itk::MultiScaleHessianBasedMeasureImageFilter<ImageType,VesselnessFilterType> MultiScaleEnhancementFilterType;

  // Convert from InrImage to ITK
  ImageType::RegionType region;
  ImageType::Pointer image;
 std::cout << "Converting image to ITK format " << std::endl;

  image = InrToITK<PixelType,Dimension>(input,region);

 std::cout << "Conversion done" << std::endl;

  // Instantiate the multiscale filter and set the input image
  MultiScaleEnhancementFilterType::Pointer multiScaleEnhancementFilter = MultiScaleEnhancementFilterType::New();
  multiScaleEnhancementFilter->SetInput(image);
  multiScaleEnhancementFilter->SetSigmaMin(sigmaMin);
  multiScaleEnhancementFilter->SetSigmaMax(sigmaMax);
  multiScaleEnhancementFilter->SetNumberOfSigmaSteps(numberOfScales);

  // Get the vesselness filter and set the parameters
  VesselnessFilterType* vesselnessFilter = multiScaleEnhancementFilter->GetHessianToMeasureFilter();
  vesselnessFilter->SetAlpha1(0.5);
  vesselnessFilter->SetAlpha2(0.5);

  multiScaleEnhancementFilter->Update();

  outimage = multiScaleEnhancementFilter->GetOutput();

 std::cout << "Converting back to InrImage " << std::endl;

  res = ITKToInr<PixelType,Dimension>(outimage, region);

  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkMultiScaleVesselnessFilter3D
