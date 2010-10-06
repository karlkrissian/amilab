#ifndef __itkTranslateImageFilter_h
#define __itkTranslateImageFilter_h

#include "itkImageToImageFilter.h"
#include "itkImage.h"

namespace itk
{

/** \class TranslateImageFilter
 *  This filter is used to translate an image from its initial
 *  position to another due to a displacement.
 *  This filter support multithreaded.
 *
 *  \par Inputs and Outputs
 *  This is an image-to-mesh filter.  The requirements for data types and
 *  dimensionality of the input and output are defined by subclasses.  In
 *  general, these filters expect images of real-valued types.  This means
 *  pixel types of floats, doubles, or a user-defined type with floating point
 *  accuracy and arithmetic operations.
 *
 *  \par Parameters
 *  Set/Get the displace on the x-axis.
 *  \par 
 *  Set/Get the displace on the y-axis.
 *  \par
 *  Set/Get the displace on the z-axis.
 *
 *  \par How to use this filter
 *  Load the input image, specify the displace for each axis and then you obtain 
 *  the translate image.
*/

template <class TInputImage, class TOutputImage >
class ITK_EXPORT TranslateImageFilter :
    public ImageToImageFilter< TInputImage, TOutputImage >
{
public:
  /** Standard class typedefs. */
  typedef TranslateImageFilter                            Self;
  typedef ImageToImageFilter< TInputImage, TOutputImage > Superclass;
  typedef SmartPointer<Self>                              Pointer;
  typedef SmartPointer<const Self>                        ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(TranslateImageFilter, ImageToImageFilter);

  /** Image type information. */
  typedef TInputImage  InputImageType;
  typedef TOutputImage OutputImageType;

  /** Extract some information from the image types.  Dimensionality
   * of the two images is assumed to be the same. */
  typedef typename TOutputImage::PixelType  OutputPixelType;
  typedef typename TInputImage::PixelType   InputPixelType;
  typedef typename TInputImage::RegionType  InputImageRegionType;
  typedef typename TOutputImage::RegionType OutputImageRegionType;
  
  /** Set/Get the displace on the x-axis.*/
  itkSetMacro(DisplaceX, int); // displacement X
  itkGetMacro(DisplaceX, int);
  
  /** Set/Get the displace on the y-axis.*/
  itkSetMacro(DisplaceY, int); // displacement Y
  itkGetMacro(DisplaceY, int);
  
  /** Set/Get the displace on the z-axis.*/
  itkSetMacro(DisplaceZ, int); // displacement Z
  itkGetMacro(DisplaceZ, int);

protected:
  TranslateImageFilter()
  {
    m_DisplaceX = 0;
    m_DisplaceY = 0;
    m_DisplaceZ = 0;
  }
  virtual ~TranslateImageFilter() {}
  void PrintSelf(std::ostream& os, Indent indent) const;

  void ThreadedGenerateData(const OutputImageRegionType& outputRegionForThread,int threadId );

private:
  TranslateImageFilter(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  int m_DisplaceX;
  int m_DisplaceY;
  int m_DisplaceZ;

};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkTranslateImageFilter.txx"
#endif

#endif
