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

#ifndef __itkLocalMeanImageFilter_h
#define __itkLocalMeanImageFilter_h

#include "itkImageToImageFilter.h"
#include "itkImage.h"

namespace itk
{

/** \class LocalMeanImageFilter
 *  This filter compute a fast (compare to original ITK mean) local mean, 
 *  based on compute the mean in each axis separatly.
 *  This filter support 
 *
 *  \par Inputs and Outputs
 *  This is an image-to-image filter. The requirements for data types and
 *  dimensionality of the input and output are defined by subclasses.  In
 *  general, these filters expect images of real-valued types.  This means
 *  pixel types of floats, doubles, or a user-defined type with floating point
 *  accuracy and arithmetic operations.
 *
 *  \par Parameters
 *  Set/Get the size of window to compute local mean.
 *
 *  \par How to use this filter
 *  
*/

template <class TInputImage, class TOutputImage >
class ITK_EXPORT LocalMeanImageFilter :
    public ImageToImageFilter< TInputImage, TOutputImage >
{
public:
  /** Standard class typedefs. */
	typedef LocalMeanImageFilter                            Self;
  typedef ImageToImageFilter< TInputImage, TOutputImage > Superclass;
  typedef SmartPointer<Self>                              Pointer;
  typedef SmartPointer<const Self>                        ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(LocalMeanImageFilter, ImageToImageFilter);

  /** Image type information. */
  typedef TInputImage  InputImageType;
  typedef TOutputImage OutputImageType;

  /** Extract some information from the image types.  Dimensionality
   * of the two images is assumed to be the same. */
  typedef typename TOutputImage::PixelType  OutputPixelType;
  typedef typename TInputImage::PixelType   InputPixelType;
  typedef typename TInputImage::RegionType  InputImageRegionType;
  typedef typename TOutputImage::RegionType OutputImageRegionType;
  
  /** Set/Get size of the window to compute the local mean */
  itkSetMacro(Window, int);
  itkGetMacro(Window, int);

protected:
	LocalMeanImageFilter()
  {
    m_Window = 4;
  }
  virtual ~LocalMeanImageFilter() {}
  void PrintSelf(std::ostream& os, Indent indent) const;

  void ThreadedGenerateData(const OutputImageRegionType& outputRegionForThread,int threadId );

private:
  LocalMeanImageFilter(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  int m_Window;

};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkLocalMeanImageFilter.txx"
#endif

#endif
