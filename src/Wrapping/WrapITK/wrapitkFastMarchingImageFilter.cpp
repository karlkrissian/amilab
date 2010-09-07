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
#include "itkImage.h"
#include "itkFastMarchingImageFilter.h"
#endif // _WITHOUT_ITK_

#include "paramlist.h"
#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkFastMarchingImageFilter.h"

InrImage* wrap_itkFastMarchingImageFilter2D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

  char functionname[] = "itkFastMarchingImageFilter2D";
  char description[]=" \n\
        Filter to compute a fast marching solution in 2D.\n\
      ";

  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          seedX \n\
          seedY \n\
          StoppingValue \n\
          seedValue \n\
      ";
    
  InrImage* input = NULL;
  float     seedX = 0.0;
  float     seedY = 0.0;
  float     stoppingTime = 0.0;
  float     seedValue = 0.0;
  InrImage* res = NULL;
  int       n=0;
  
  if (!get_val_ptr_param<InrImage>( input,        p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( seedX,        p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( seedY,        p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( stoppingTime, p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( seedValue,    p, n)) HelpAndReturnNULL;


  typedef float         InternalPixelType;
  const   unsigned int  Dimension = 2;
  typedef itk::Image< InternalPixelType, Dimension >    InternalImageType;
  InternalImageType::RegionType region;
  InternalImageType::Pointer image;

  typedef float OutputPixelType;
  typedef itk::Image< OutputPixelType,Dimension > OutputImageType;
  OutputImageType::Pointer outimage;
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;

  image = InrToITK<InternalPixelType,Dimension>(input,region);

  cout << "Conversion done" << endl;

  typedef  itk::FastMarchingImageFilter< InternalImageType, InternalImageType > FastMarchingFilterType;

  FastMarchingFilterType::Pointer fastMarching = FastMarchingFilterType::New();

  fastMarching->SetInput( image );
 
  typedef FastMarchingFilterType::NodeContainer NodeContainer;
  typedef FastMarchingFilterType::NodeType      NodeType;
  NodeContainer::Pointer seeds = NodeContainer::New();
 
  InternalImageType::IndexType seedPosition;
 
  // Fast Marching solution begin at one start point
  seedPosition[0] = seedX;
  seedPosition[1] = seedY;
  
  std::cout << "seedPosition: " << seedPosition << std::endl;

  NodeType node;
   
  node.SetValue( seedValue );
  node.SetIndex( seedPosition );

  seeds->Initialize();
  seeds->InsertElement( 0, node );
  
  fastMarching->SetTrialPoints( seeds );

  fastMarching->SetOutputSize( image->GetBufferedRegion().GetSize() );
  
  fastMarching->SetStoppingValue( stoppingTime );
 
  fastMarching->Update();

  outimage = fastMarching->GetOutput();

  // Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

  res = ITKToInr<OutputPixelType,Dimension>(outimage, region);

  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkFastMarchingImageFilter2D


InrImage* wrap_itkFastMarchingImageFilter3D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

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
          StoppingValue \n\
          seedValue \n\
      ";
    
  InrImage* input = NULL;
  float     seedX = 0.0;
  float     seedY = 0.0;
  float     seedZ = 0.0;
  float     stoppingTime = 0.0;
  float     seedValue = 0.0;
  InrImage* res = NULL;
  int       n=0;
  
  if (!get_val_ptr_param<InrImage>( input,        p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( seedX,        p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( seedY,        p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( seedZ,        p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( stoppingTime, p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>       ( seedValue,    p, n)) HelpAndReturnNULL;

  typedef float               InternalPixelType;
  const   unsigned int        Dimension = 3;
  typedef itk::Image< InternalPixelType, Dimension > InternalImageType;
  InternalImageType::RegionType region;
  InternalImageType::Pointer image;

  typedef float OutputPixelType;
  typedef itk::Image< OutputPixelType,Dimension > OutputImageType;
  OutputImageType::Pointer outimage;
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;

  image = InrToITK<InternalPixelType,Dimension>(input,region);

  cout << "Conversion done" << endl;

  typedef  itk::FastMarchingImageFilter< InternalImageType, InternalImageType > FastMarchingFilterType;

  FastMarchingFilterType::Pointer  fastMarching = FastMarchingFilterType::New();

  fastMarching->SetInput( image );
  
  typedef FastMarchingFilterType::NodeContainer NodeContainer;
  typedef FastMarchingFilterType::NodeType      NodeType;
  NodeContainer::Pointer seeds = NodeContainer::New();
 
  InternalImageType::IndexType  seedPosition;
 
  seedPosition[0] = seedX;
  seedPosition[1] = seedY;
  seedPosition[2] = seedZ;

  std::cout << "seedPosition: " << seedPosition << std::endl;

  NodeType node;
  //const double seedValue;
  
  node.SetValue( seedValue );
  node.SetIndex( seedPosition );

  seeds->Initialize();
  seeds->InsertElement( 0, node );

  fastMarching->SetTrialPoints( seeds );

  fastMarching->SetOutputSize( image->GetBufferedRegion().GetSize() );
  
  fastMarching->SetStoppingValue( stoppingTime );
  
  fastMarching->Update();
  
  outimage = fastMarching->GetOutput();
   
  // Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

  res = ITKToInr<OutputPixelType,Dimension>(outimage, region);

  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} 
// wrap_itkFastMarchingImageFilter3D

