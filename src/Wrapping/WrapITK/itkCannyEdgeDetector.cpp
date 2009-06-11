/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

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

#include "itkCannyEdgeDetector.h"

#ifdef USE_ITK
#include "itkCannyEdgeDetectionImageFilter.h"
#include "itkImageLinearConstIteratorWithIndex.h"
#include "itkImageLinearIteratorWithIndex.h"
#include "itkImage.h"
#endif

template <unsigned int Dimension>
InrImage* Func_itkCannyEdgeDetector(InrImage* input, float var, float lowthreshold)
{

#ifdef USE_ITK
  typedef float            PixelType;  //  Operations
  //  unsigned int     Dimension;
  typedef itk::Image<PixelType, Dimension>                          ImageType;
  typedef itk::CannyEdgeDetectionImageFilter<ImageType, ImageType>  CannyFilter;
  typedef itk::ImageLinearIteratorWithIndex< ImageType >            IteratorType;
  typedef itk::ImageLinearConstIteratorWithIndex< ImageType >       ConstIteratorType;


  // Allocate itk Image
  ImageType::Pointer itkInput = ImageType::New();
  ImageType::IndexType start;
  start[0] =   0;  // first index on X
  start[1] =   0;  // first index on Y
  if (Dimension==3) start[2]=0;
  ImageType::SizeType  size;
  size[0]  = input->DimX();  // size along X
  size[1]  = input->DimY();  // size along Y
  if (Dimension==3) size[2]= input->DimZ(); // size along Z
  ImageType::RegionType region;
  region.SetSize( size );
  region.SetIndex( start );
  itkInput->SetRegions( region );
  itkInput->Allocate();

  // Copy itk Image
  IteratorType inputIt( itkInput, itkInput->GetRequestedRegion() );
  inputIt.SetDirection(0);
 
  input->InitBuffer();
  for ( inputIt.GoToBegin(); ! inputIt.IsAtEnd(); inputIt.NextLine())
    {
    inputIt.GoToBeginOfLine();
    while ( ! inputIt.IsAtEndOfLine() )
      {
      inputIt.Set( input->ValeurBuffer() );
      ++inputIt;
      input->IncBuffer();
      }
    }

  // Run the filter
  CannyFilter::Pointer cannyFilter = CannyFilter::New();
  cannyFilter->SetInput( itkInput );
  cannyFilter->SetVariance( var );
  cannyFilter->SetThreshold( lowthreshold );
  //  cannyFilter->SetUpperThreshold(highthreshold );
  cannyFilter->Update();
  ImageType::Pointer itkOutput =  cannyFilter->GetOutput();

  // Copy itk Image
  InrImage* output = new InrImage(WT_FLOAT,"itkCannyEdgeDetectorResult.ami.gz",input);

  ConstIteratorType outputIt( itkOutput, itkOutput->GetRequestedRegion() );
  outputIt.SetDirection(0);
 
  output->InitBuffer();
  for ( outputIt.GoToBegin(); ! outputIt.IsAtEnd(); outputIt.NextLine())
    {
    outputIt.GoToBeginOfLine();
    while ( ! outputIt.IsAtEndOfLine() )
      {
      output->FixeValeur(outputIt.Get());
      ++outputIt;
      output->IncBuffer();
      }
    }

  return output;
#else
    return input;
#endif
}


InrImage* Func_itkCannyEdgeDetector(InrImage* input, float var, float lowthreshold)
{
#ifdef USE_ITK
  if (input->DimZ()>1) 
    return Func_itkCannyEdgeDetector<3>(input,var,lowthreshold);
  else
    return Func_itkCannyEdgeDetector<2>(input,var,lowthreshold);
#else
  return input;
#endif
}

