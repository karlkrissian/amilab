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
#include "itkSigmoidImageFilter.h"
#include "itkImage.h"
#endif // _WITHOUT_ITK_

#include "paramlist.h"
#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkSigmoidImageFilter.h"
#include "message_dialog.h"

InrImage* wrap_itkSigmoidImageFilter2D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

  char functionname[] = "itkSigmoidImageFilter2D";
  char description[]=" \n\
        Filter to compute a sigmoid solution in 2D.\n\
      ";
    
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          outputMin \n\
          outputMax \n\
          SigmoidAlpha \n\
          SigmoidBeta \n\
      ";
    
  InrImage* input = NULL;
  float outputMin = 0.0;
  float outputMax = 0.0;
  float alpha = 0.0;
  float beta = 0.0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>( input,      p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( outputMin,  p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( outputMax,  p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( alpha,      p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( beta,       p, n)) HelpAndReturnNULL;
 
  typedef float       InternalPixelType;
  const unsigned int  Dimension = 2;
  typedef itk::Image< InternalPixelType, Dimension >    InternalImageType;
  InternalImageType::RegionType region;
  InternalImageType::Pointer image;

  typedef float OutputPixelType;
  typedef itk::Image< OutputPixelType,Dimension > OutputImageType;
  OutputImageType::Pointer outimage;
 
  // Convert from InrImage to ITK
 std::cout << "Converting image to ITK format " << std::endl;

  image = InrToITK<InternalPixelType,Dimension>(input,region);

 std::cout << "Conversion done" << std::endl;

  typedef itk::SigmoidImageFilter< InternalImageType, InternalImageType >  SigmoidFilterType;
  SigmoidFilterType::Pointer sigmoidFilter = SigmoidFilterType::New();

  sigmoidFilter->SetOutputMinimum( outputMin );
  sigmoidFilter->SetOutputMaximum( outputMax );

  sigmoidFilter->SetAlpha( alpha );
  sigmoidFilter->SetBeta( beta );

  sigmoidFilter->SetInput( image );
  sigmoidFilter->Update();

  outimage = sigmoidFilter->GetOutput();
  
  // Convert from ITK to InrImage
 std::cout << "Converting back to InrImage " << std::endl;

  res = ITKToInr<OutputPixelType,Dimension>(outimage, region);
  
  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkSigmoidImageFilter2D


InrImage* wrap_itkSigmoidImageFilter3D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

  char functionname[] = "itkSigmoidImageFilter3D";
  char description[]=" \n\
        Filter to compute a sigmoid solution in 3D.\n\
      ";

  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          outputMin \n\
          outputMax \n\
          SigmoidAlpha \n\
          SigmoidBeta \n\
      ";
    
  InrImage* input = NULL;
  float outputMin = 0.0;
  float outputMax = 0.0;
  float alpha = 0.0;
  float beta = 0.0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>( input,      p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( outputMin,  p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( outputMax,  p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( alpha,      p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( beta,       p, n)) HelpAndReturnNULL;
 
  typedef float       InternalPixelType;
  const unsigned int  Dimension = 3;
  typedef itk::Image< InternalPixelType, Dimension >    InternalImageType;
  InternalImageType::RegionType region;
  InternalImageType::Pointer image;

  typedef float OutputPixelType;
  typedef itk::Image< OutputPixelType,Dimension > OutputImageType;
  OutputImageType::Pointer outimage;
 
  // Convert from InrImage to ITK
 std::cout << "Converting image to ITK format " << std::endl;

  image = InrToITK<InternalPixelType,Dimension>(input,region);

 std::cout << "Conversion done" << std::endl;

  typedef itk::SigmoidImageFilter< InternalImageType, InternalImageType >  SigmoidFilterType;
  SigmoidFilterType::Pointer sigmoidFilter = SigmoidFilterType::New();

  sigmoidFilter->SetOutputMinimum( outputMin );
  sigmoidFilter->SetOutputMaximum( outputMax );

  sigmoidFilter->SetAlpha( alpha );
  sigmoidFilter->SetBeta( beta );

  sigmoidFilter->SetInput( image );
  sigmoidFilter->Update();

  outimage = sigmoidFilter->GetOutput();
  
  // Convert from ITK to InrImage
 std::cout << "Converting back to InrImage " << std::endl;

  res = ITKToInr<OutputPixelType,Dimension>(outimage, region);

  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkSigmoidImageFilter3D
