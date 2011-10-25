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

#ifndef __itkBasicNLMeansFilter_h
#define __itkBasicNLMeansFilter_h

#include <stddef.h>
#include "itkImageToImageFilter.h"
#include "itkImage.h"
#include "itkNumericTraits.h"

namespace itk
{

/** \class BasicNLMeansFilter
 *  This filter compute a basic and slow non local means solution. 
 *  NL-Means is an algorithm for image denoising. It is based on the
 *  neighborhood pixel.
 *  This filter support multithreaded.
 *
 *  \par Inputs and Outputs
 *  This is an image-to-image filter. The requirements for data types and
 *  dimensionality of the input and output are defined by subclasses.  In
 *  general, these filters expect images of real-valued types.  This means
 *  pixel types of floats, doubles, or a user-defined type with floating 
 *  point accuracy and arithmetic operations.
 *
 *  \par Parameters
 *  Set/Get Searching window, this is "t" window. It�s bigger than pattern
 *  window. Define a window of size (2t+1)^n used to search for similar 
 *  pixels/voxels. "n" is the dimension of the image.
 *
 *  \par
 *  Set/Get Pattern window, this is "f" window. Define a window of size
 *  (2f+1)^n for the pixel/voxel pattern to match (f<t). "n" is the
 *  dimension of the image.
 *
 *  \par
 *  Set/Get Threshold value for the distance between patches, 
 *  suggested 10*standard deviation of the noise.
 *
 *  \par
 *  Set/Get type of noise. It could be additive Gaussian noise or Rician noise.
 *  
 *  \par How to use this filter
 *  This filter require an input image on 2D or 3D. Then, need to 
 *  define searching and pattern window value, threshold value
 *  and type of noise.
*/

template <class TInputImage, class TOutputImage >
class ITK_EXPORT BasicNLMeansFilter :
    public ImageToImageFilter< TInputImage, TOutputImage > 
{
public:
  /** Standard class typedefs. */
  typedef BasicNLMeansFilter                     Self;
  typedef ImageToImageFilter< TInputImage, TOutputImage > Superclass;
  typedef SmartPointer<Self>                              Pointer;
  typedef SmartPointer<const Self>                        ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(BasicNLMeansFilter, ImageToImageFilter);
  
  /** Image type information. */
  typedef TInputImage  InputImageType;
  typedef TOutputImage OutputImageType;

  /** Extract some information from the image types.  Dimensionality
   * of the two images is assumed to be the same. */
  typedef typename TOutputImage::PixelType                  OutputPixelType;
  typedef typename TInputImage::PixelType                   InputPixelType;
  typedef typename TInputImage::SizeType                    InputSizeType;
  typedef typename TInputImage::RegionType                  InputImageRegionType;
  typedef typename TOutputImage::RegionType                 OutputImageRegionType;
  typedef typename TInputImage::IndexType                   InputIndexType;
  typedef typename TOutputImage::IndexType                  OutputIndexType;
  typedef typename NumericTraits<InputPixelType>::RealType  RealType;
  
  /** Set/Get Searching window value (t) */
  itkSetMacro(Searching, int); 
  itkGetMacro(Searching, int);
  
  /** Set/Get Pattern window value (f) */
  itkSetMacro(Pattern, InputSizeType);
  itkGetMacro(Pattern, InputSizeType);
  
  /** Set/Get Threshold value (t) */
  itkSetMacro(Threshold, float);
  itkGetMacro(Threshold, float);
  
  /** Set/Get Type of noise */
  itkSetMacro(Noise, int);
  itkGetMacro(Noise, int);
  
protected:
  BasicNLMeansFilter()
    {
    m_Searching = 7;
    m_Pattern.Fill(3);
    m_Threshold = 10.0;
    m_Noise = 0;
    }
  virtual ~BasicNLMeansFilter() {}
  void PrintSelf(std::ostream& os, Indent indent) const;
  
  // Make the necessary operations before applying the primary filter
  virtual void BeforeThreadedGenerateData();
  void         ThreadedGenerateData(const OutputImageRegionType& outputRegionForThread,int threadId );

private:
  BasicNLMeansFilter(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented
  
  double          *dist_weights;
  int             m_Searching;
  InputSizeType   m_Pattern;
  float           m_Threshold;
  int             m_Noise;
  
};
  
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkBasicNLMeansFilter.txx"
#endif

#endif
