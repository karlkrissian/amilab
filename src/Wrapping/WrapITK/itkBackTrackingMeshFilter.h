#ifndef __itkBackTrackingImageFilter_h
#define __itkBackTrackingImageFilter_h

//#include "itkImageToImageFilter.h"
#include "itkImageToMeshFilter.h"
#include "itkImage.h"
#include "itkMesh.h"

namespace itk
{

template <class TInputImage, class TOutputMesh, unsigned int TDimension>
class ITK_EXPORT BackTrackingMeshFilter :
    public ImageToMeshFilter< TInputImage, TOutputMesh>
{
public:
  /** Standard class typedefs. */
	typedef BackTrackingMeshFilter                     Self;
  typedef ImageToMeshFilter< TInputImage, TOutputMesh > Superclass;
  typedef SmartPointer<Self>                              Pointer;
  typedef SmartPointer<const Self>                        ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(BackTrackingMeshFilter, ImageToMeshFilter);

  /** Image type information. */
  typedef TInputImage  InputImageType;
  typedef TInputImage  OutputImageType;
  typedef TOutputMesh OutputMeshType;
  
  /** Extract some information from the image types.  Dimensionality
   * of the two images is assumed to be the same. */
  //typedef typename TOutputMesh::PixelType OutputPixelType;
  //typedef typename TInputImage::PixelType InputPixelType;
  //typedef typename TInputImage::RegionType  InputImageRegionType;
  /*typedef typename TOutputMesh::RegionType OutputImageRegionType;
  typedef typename TOutputMesh::Pointer PointerType;*/
  
  itkSetMacro(startX, double); // start X
  itkGetMacro(startX, double);
  
  itkSetMacro(startY, double); // start Y
  itkGetMacro(startY, double);
  
  itkSetMacro(startZ, double); // start Z
  itkGetMacro(startZ, double);
  
  itkSetMacro(stepSize, double); // stepSize
  itkGetMacro(stepSize, double);
  
  itkSetMacro(maxLength, double); // maxLength
  itkGetMacro(maxLength, double);
  
  itkSetMacro(delta, double); // delta
  itkGetMacro(delta, double);
  
protected:
	BackTrackingMeshFilter()
  {
    m_startX = 0.0;
    m_startY = 0.0;
    m_startZ = 0.0;
    
    m_stepSize = 0.1;
    m_maxLength = 500;
    
    m_delta = 0.05;
  }
  virtual ~BackTrackingMeshFilter() {}
  void PrintSelf(std::ostream& os, Indent indent) const;

  void GenerateData();

private:
  BackTrackingMeshFilter(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  double m_startX;
  double m_startY;
  double m_startZ;
  
  double m_stepSize;
  double m_maxLength;
  double m_delta;

};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkBackTrackingMeshFilter.txx"
#endif

#endif
