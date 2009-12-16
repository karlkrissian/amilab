#ifndef __itkBasicNLMeansFilter_h
#define __itkBasicNLMeansFilter_h

#include "itkImageToImageFilter.h"
#include "itkImage.h"
#include "itkNumericTraits.h"

namespace itk
{

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
  typedef typename TOutputImage::PixelType OutputPixelType;
  typedef typename TInputImage::PixelType InputPixelType;
  typedef typename TInputImage::SizeType InputSizeType;
  typedef typename TInputImage::RegionType  InputImageRegionType;
  typedef typename TOutputImage::RegionType OutputImageRegionType;
  typedef typename TInputImage::IndexType InputIndexType;
  typedef typename TOutputImage::IndexType OutputIndexType;
  typedef typename NumericTraits<InputPixelType>::RealType RealType;
  
  itkSetMacro(Searching, int); //t
  itkGetMacro(Searching, int);
  
  itkSetMacro(Pattern, InputSizeType); //f
  itkGetMacro(Pattern, InputSizeType);
  
  itkSetMacro(Threshold, float); //h
  itkGetMacro(Threshold, float);
  
  itkSetMacro(Noise, int); //noise type
  itkGetMacro(Noise, int);
  
  //virtual void GenerateInputRequestedRegion() throw(InvalidRequestedRegionError);
  
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
  
  virtual void BeforeThreadedGenerateData();
  void ThreadedGenerateData(const OutputImageRegionType& outputRegionForThread,int threadId );

private:
  BasicNLMeansFilter(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented
  
  double *dist_weights;// wmax, total_weigth;
  int m_Searching;
  InputSizeType m_Pattern;
  float m_Threshold;
  int m_Noise;
  
};
  
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkBasicNLMeansFilter.txx"
#endif

#endif
