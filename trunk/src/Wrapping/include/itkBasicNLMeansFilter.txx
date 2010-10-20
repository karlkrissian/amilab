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

#ifndef __itkBasicNLMeansFilter_txx
#define __itkBasicNLMeansFilter_txx

#include "itkBasicNLMeansFilter.h"
#include "itkConstNeighborhoodIterator.h"
#include "itkNeighborhoodIterator.h"
#include "itkImageRegionIterator.h"
#include "itkImageRegionConstIteratorWithIndex.h"
#include "itkNeighborhoodAlgorithm.h"


namespace itk
{
// Computes the weights
template < class TInputImage, class TOutputImage >
void BasicNLMeansFilter< TInputImage, TOutputImage >
::BeforeThreadedGenerateData()
{
  int                 i;
  int                 j;
  int                 p;
  int                 k;
  int                 f = m_Pattern[0];
  double              sum = 0;
  double              sigma = f/2.0;
  static unsigned int dimen;
  p = 0;

  typename TInputImage::ConstPointer input = this->GetInput();
  dimen = input->GetImageDimension();
  
  if (dimen == 2)
  {
    dist_weights = new double[(2*m_Pattern[0]+1)*(2*m_Pattern[0]+1)];
    for (j=-f;j<=f;j++)
    {
      for (i=-f;i<=f;i++)
      {
        dist_weights[p] = exp(-(i*i+j*j)/sigma/sigma);
        sum += dist_weights[p];
        p++;
      }
    }
    p = 0;
    for (j=-f;j<=f;j++)
    {
      for (i=-f;i<=f;i++)
      {
        dist_weights[p] /= sum;
        p++;
      }
    }
  }
  else
  {
    if (dimen == 3)
    {
      dist_weights = new double [(2*m_Pattern[0]+1)*(2*m_Pattern[0]+1)*(2*m_Pattern[0]+1)];
      for (k=-f;k<=f;k++)
      {
        for (j=-f;j<=f;j++)
        {
          for (i=-f;i<=f;i++)
          {
            dist_weights[p] = exp(-(i*i+j*j+k*k)/sigma/sigma);
            sum += dist_weights[p];
            p++;
          }
        }
      }
      p = 0;
      for (k=-f;k<=f;k++)
      {
        for (j=-f;j<=f;j++)
        {
          for (i=-f;i<=f;i++)
          {
            dist_weights[p] /= sum;
            p++;
          }
        }
      }
    }
  }
}

template< class TInputImage, class TOutputImage >
void BasicNLMeansFilter< TInputImage, TOutputImage >
::ThreadedGenerateData(const OutputImageRegionType& outputRegionForThread,int threadId)
{

  static unsigned int dimen;
  double              w;
  RealType            diff;
  double              dist = 0;
  double              wmax = 0;
  double              average = 0;
  double              total_weight = 0;
  int                 j_min;
  int                 j_max;
  int                 i_min;
  int                 i_max;
  int                 k_min;
  int                 k_max;
  
  // Iterator to walk the image
  ImageRegionConstIteratorWithIndex<TInputImage>  bit;
  ImageRegionIterator<TOutputImage>               it;
  ConstNeighborhoodIterator<TInputImage>          f_it;
  ConstNeighborhoodIterator<TInputImage>          faux_it;
  
  // Allocate output
  typename TOutputImage::Pointer output = this->GetOutput();
  typename TInputImage::ConstPointer input  = this->GetInput();
  dimen = input->GetImageDimension();
  
  // Find the data-set boundary "faces"
  typename NeighborhoodAlgorithm::ImageBoundaryFacesCalculator<TInputImage>::FaceListType faceList;
  NeighborhoodAlgorithm::ImageBoundaryFacesCalculator<TInputImage> bC;
  
  typename NeighborhoodAlgorithm::ImageBoundaryFacesCalculator<TInputImage>::FaceListType::iterator fit;
  
  // Region to compute the filter
  typename TInputImage::RegionType::IndexType inputStart;
  typename TInputImage::RegionType::IndexType test;
  typename TInputImage::RegionType::SizeType  size;
  typename TInputImage::RegionType region;

  bit = ImageRegionConstIteratorWithIndex<TInputImage>(input, outputRegionForThread);
  faux_it = ConstNeighborhoodIterator<TInputImage>(m_Pattern, input, outputRegionForThread);
  it = ImageRegionIterator<TOutputImage>(output, outputRegionForThread);
  
  /*
  For each pixel x {

    - We take a window centered in x and size 2t+1 x 2t+1, A(x,t).

      A(x,t) denotes the learning window of pixels which will be averaged. 
      Theoretically A(x,t) should be all the image but in practice t= 7, 9 g ives good results. 
      This means a learning window of 15x15 or 18x18.
    
    - We take a window centered in x and size 2f+1 x 2f+1, W(x,f).

      W(x,f) denotes the comparison window (f should be smaller than t). 
      In a non-noisy image it can be set to f=1 (3x3). The value of f increases with the amount of noise. 
      In general for noisy images, f=3, 4 is a good value. This means a window 7x7 or 9x9.
  */
	
  for (bit.GoToBegin(), faux_it.GoToBegin(), it.GoToBegin(); !bit.IsAtEnd(); ++bit, ++faux_it, ++it)//while ( ! bit.IsAtEnd() )
  {
    wmax = 0;
    average = 0;
    total_weight = 0;
    
    test = bit.GetIndex();
    
    // Checking limits
    #define macro_min(a,b) ((a)<(b)?(a):(b))
    #define macro_max(a,b) ((a)>(b)?(a):(b))
    i_min = (int)test[0]-(int)m_Searching;
    i_min = macro_max(i_min,0);
    
    i_max = (int)test[0]+(int)m_Searching;
    i_max = macro_min(i_max,(int)input->GetBufferedRegion().GetSize()[0]-1);
    
    j_min = (int)test[1]-(int)m_Searching;
    j_min = macro_max(j_min,0);
    
    j_max = (int)test[1]+(int)m_Searching;
    j_max = macro_min(j_max,(int)input->GetBufferedRegion().GetSize()[1]-1);
    
    if (dimen == 3)
    {
      k_min = (int)test[2]-(int)m_Searching;
      k_min = macro_max(k_min,0);
      
      k_max = (int)test[2]+(int)m_Searching;
      k_max = macro_min(k_max,(int)input->GetBufferedRegion().GetSize()[2]-1);
    }
    
    inputStart[0] = i_min;
    inputStart[1] = j_min;
    
    size[0] = i_max - i_min + 1;
    size[1] = j_max - j_min + 1;
    
    if (dimen == 3)
    {
      inputStart[2] = k_min;
      size[2] = k_max - k_min + 1;
    }
    
    region.SetIndex(inputStart);
    region.SetSize(size);
    
    faceList = bC(input, region, m_Pattern);
    
    /*
      The distance between x and itself is zero. This would concentrate the probaility distribution too much. 
      For this reason x is treated in a special way.
      For each pixel y in A(x,t) && y different from x {

      All the pixels inside A(x,t) are used even when W(y,f) is not totally contained in A(x,t). 
      We have all the image and so we can compute the window difference using the pixels outside A(x,t).
      We compute the difference between W(x,f) and W(y,f), d(x,y).

      This difference is based on the square euclidean distance of the two windows and detailed below.
    */
    /*
      We compute the weight from the distance d(x,y), w(x,y).
                  w(x,y) = exp(- d(x,y) / h);
      The weight is given by a decreasing function of the distance. The parameter h measures the degree 
      of filtering of the obtained image. When we know the standard deviation of the noise, sigma, the value of h should depend on it. 
      (a good value is between 10*sigma and 15*sigma).
    */
    // Compute the filter on the checking region
    for (fit=faceList.begin(); fit != faceList.end(); ++fit)
    {
      f_it = ConstNeighborhoodIterator<TInputImage>(m_Pattern, input, *fit);
      f_it.GoToBegin();
      while(!f_it.IsAtEnd())
      {
        unsigned int neighborhoodSize = f_it.Size();
        dist = 0;
        for (int i=0;i < (int)neighborhoodSize; i++)
        {
          diff = static_cast<RealType>(faux_it.GetPixel(i)) - static_cast<RealType>(f_it.GetPixel(i));
          dist += diff*diff*dist_weights[i];
        }

        w = exp(-dist/(m_Threshold*m_Threshold));
        
        /*
          If w(x,y) is bigger than wmax then
                  wmax = w(x,y);
          We compute the maximum weight obtained with a point different from x.
          We compute the average
                average + = w(x,y) * u(y);
          We carry the sum of the weights
                totalweight + = w( x, y);
            x has the maximum weight obtained by a point y different from it.
          }
        */
        
        if (w>wmax) wmax=w;
        
        switch (m_Noise)
        {
          case 0: average += w*static_cast<RealType>(f_it.GetCenterPixel());
              break;
          case 1: average += w*static_cast<RealType>(f_it.GetCenterPixel())*static_cast<RealType>(f_it.GetCenterPixel());
              break;
        }
        total_weight += w;
        
        ++f_it;
      }
    }
    
    switch (m_Noise)
    {
      case 0: average += wmax*static_cast<RealType>(bit.Get());
        total_weight += wmax;
        it.Set(static_cast<OutputPixelType>(average/total_weight));
      break;
      case 1: average += wmax*static_cast<RealType>(bit.Get())*static_cast<RealType>(bit.Get());
        total_weight += wmax;
        it.Set(static_cast<OutputPixelType>(sqrt(average/total_weight)));
      break;
    }
  }   
}

// Using for debugging
template< class TInputImage, class TOutputImage >
void
BasicNLMeansFilter<TInputImage, TOutputImage>
::PrintSelf(std::ostream& os, Indent indent) const
{
  Superclass::PrintSelf(os,indent);

  os << indent << "Searching window: " << m_Searching << std::endl;
  os << indent << "Pattern Window: " << m_Pattern << std::endl;
  os << indent << "Threshold: " << m_Threshold << std::endl;
  os << indent << "Noise: " << m_Noise << std::endl;
}

} // end namespace itk

#endif
