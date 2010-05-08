#ifndef __itkTranslateImageFilter_txx
#define __itkTranslateImageFilter_txx

#include "itkTranslateImageFilter.h"
#include "itkImageLinearIteratorWithIndex.h"
#include "itkImageLinearConstIteratorWithIndex.h"
#include "math.h"
#include "stdio.h"

namespace itk
{

template< class TInputImage, class TOutputImage >
void TranslateImageFilter< TInputImage, TOutputImage >
::ThreadedGenerateData(const OutputImageRegionType& outputRegionForThread,int threadId)
{
  //float *add;
  //add = new float[2*m_Window+1];
  float ant=0.0;

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

  ax.SetDirection(0);
  out.SetDirection(0);
  for (int i=0;i<m_DisplaceX;i++)
  {
    for (ax.GoToBegin(), out.GoToBegin(); !ax.IsAtEnd(); ax.NextLine(), out.NextLine())
    {
      for (ax.GoToBeginOfLine(),out.GoToBeginOfLine(); !ax.IsAtEndOfLine(); ++ax)
      {
        ant = ax.Value();
        if (ax.GetIndex()[0] >= m_DisplaceX)
        {
          out.Set(ant);
          ++out;
        }
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
  
  ax.SetDirection(1);
  out.SetDirection(1);
  ant = 0.0;
  for (int i=0;i<m_DisplaceY;i++)
  {
    for (ax.GoToBegin(), out.GoToBegin(); !ax.IsAtEnd(); ax.NextLine(), out.NextLine())
    {
      for (ax.GoToBeginOfLine(),out.GoToBeginOfLine(); !ax.IsAtEndOfLine(); ++ax)
      {
        ant = ax.Value();
        if (ax.GetIndex()[1] >= m_DisplaceY)
        {
          out.Set(ant);
          ++out;
        }
      }
    }
  }
  
  if (this->InputImageDimension == 3){
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
  
  ax.SetDirection(2);
  out.SetDirection(2);
  ant = 0.0;
  for (int i=0;i<m_DisplaceZ;i++)
  {
    for (ax.GoToBegin(), out.GoToBegin(); !ax.IsAtEnd(); ax.NextLine(), out.NextLine())
    {
      for (ax.GoToBeginOfLine(),out.GoToBeginOfLine(); !ax.IsAtEndOfLine(); ++ax)
      {
        ant = ax.Value();
        if (ax.GetIndex()[2] >= m_DisplaceZ)
        {
          out.Set(ant);
          ++out;
        }
      }
    }
  }
  }
}

template< class TInputImage, class TOutputImage >
void
TranslateImageFilter<TInputImage, TOutputImage>
::PrintSelf(std::ostream& os, Indent indent) const
{
	Superclass::PrintSelf(os,indent);

  os << indent << "DisplaceX: " << m_DisplaceX << std::endl;
  os << indent << "DisplaceY: " << m_DisplaceY << std::endl;
  os << indent << "DisplaceZ: " << m_DisplaceZ << std::endl;
}

} // end namespace itk

#endif
