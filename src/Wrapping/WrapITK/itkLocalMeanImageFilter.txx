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

#ifndef __itkLocalMeanImageFilter_txx
#define __itkLocalMeanImageFilter_txx

#include "itkLocalMeanImageFilter.h"
#include "itkImageLinearIteratorWithIndex.h"
#include "itkImageLinearConstIteratorWithIndex.h"
#include "math.h"
#include "stdio.h"

namespace itk
{

template< class TInputImage, class TOutputImage >
void LocalMeanImageFilter< TInputImage, TOutputImage >
::ThreadedGenerateData(const OutputImageRegionType& outputRegionForThread,int threadId)
{
  float *add;
  add = new float[2*m_Window+1];
  float mean=0.0;

  ImageLinearConstIteratorWithIndex<TInputImage> in;
  ImageLinearIteratorWithIndex<TOutputImage> out;
  ImageLinearIteratorWithIndex<TOutputImage> ax;
  
  // Allocate output
  typename TOutputImage::Pointer output = this->GetOutput();
  typename TOutputImage::Pointer tmp = this->GetOutput();
  typename TInputImage::ConstPointer input  = this->GetInput();
  
  in = ImageLinearConstIteratorWithIndex<TInputImage>(input, outputRegionForThread);
  out = ImageLinearIteratorWithIndex<TOutputImage>(output, outputRegionForThread);
  ax = ImageLinearIteratorWithIndex<TOutputImage>(tmp, outputRegionForThread);
  
  int index,j=0;
  int aux = 2*m_Window+1;

  // Make a copy
  for (in.GoToBegin(),ax.GoToBegin();!in.IsAtEnd();in.NextLine(),ax.NextLine())
    {
      in.GoToBeginOfLine();
      ax.GoToBeginOfLine();
      while(!in.IsAtEndOfLine())
      {
        ax.Set(in.Value());
        ++in;
        ++ax;
      }
    }

  // Compute the local mean for each axis
  for (j=0;j<(int)input->GetImageDimension();j++)
  {
    index=0;
    ax.SetDirection(j);
    out.SetDirection(j);
    for (ax.GoToBegin(), out.GoToBegin(); !ax.IsAtEnd(); ax.NextLine(), out.NextLine())
    {
      mean = 0;
      for (int i=0;i<2*m_Window+1;i++)
      {
        add[i] = ax.Value();
        mean += add[i];
      }
      for (ax.GoToBeginOfLine(),out.GoToBeginOfLine(); !ax.IsAtEndOfLine(); ++ax)
      {
        mean -= add[index];
        add[index] = ax.Value();
        mean += add[index];
        index = (index+1)%aux;

        if (ax.GetIndex()[j] >= m_Window)
        {
          out.Set(mean/(2*m_Window+1));
          ++out;
        }
      }
    }
    for (ax.GoToBegin(),out.GoToBegin();!ax.IsAtEnd();ax.NextLine(),out.NextLine())
    {
      ax.GoToBeginOfLine();
      out.GoToBeginOfLine();
      while(!ax.IsAtEndOfLine())
      {
        ax.Set(out.Value());
        ++ax;
        ++out;
      }
    }
  }    
}

// Using for debugging
template< class TInputImage, class TOutputImage >
void
LocalMeanImageFilter<TInputImage, TOutputImage>
::PrintSelf(std::ostream& os, Indent indent) const
{
	Superclass::PrintSelf(os,indent);

  os << indent << "Window: " << m_Window << std::endl;
}

} // end namespace itk

#endif
