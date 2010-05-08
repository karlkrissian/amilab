#ifndef __itkLocalMeanImageFilter_h
#define __itkLocalMeanImageFilter_h

#include "itkImageToImageFilter.h"
#include "itkImage.h"

namespace itk
{

template <class TInputImage, class TOutputImage >
class ITK_EXPORT LocalMeanImageFilter :
    public ImageToImageFilter< TInputImage, TOutputImage >
{
public:
  /** Standard class typedefs. */
	typedef LocalMeanImageFilter                     Self;
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
  typedef typename TOutputImage::PixelType OutputPixelType;
  typedef typename TInputImage::PixelType InputPixelType;
  typedef typename TInputImage::RegionType  InputImageRegionType;
  typedef typename TOutputImage::RegionType OutputImageRegionType;
  
  itkSetMacro(Window, int); // size of the window
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
