
#include "itkamiConvert.h"

// VNL CLASSES

#include "vnl/vnl_matrix.h"
#include "vnl/vnl_vector.h"
#include "vnl/algo/vnl_symmetric_eigensystem.h"
#include "vnl/vnl_vector_fixed.h"

#ifdef __GCCXML__
  template class vnl_matrix<double>;
  template class vnl_vector<double>;
  template class vnl_symmetric_eigensystem<double>;
  template class vnl_vector_fixed<double,3>;
#endif // __GCCXML__

// ITK CLASSES

#include <itkImage.h>
#include <itkSmartPointer.h>
#include <itkDefaultPixelAccessor.h>
#include <itkImageRegion.h>

#include <itkImageFileReader.h>
#include <itkImageFileWriter.h>
#include <itkBinaryThresholdImageFilter.h>
#include <itkTranslationTransform.h>
#include <itkResampleImageFilter.h>

typedef itk::Image<unsigned char, 2u>  ImageUC2;
typedef itk::Image<float, 2u>  ImageF2;
typedef itk::Image<float, 3u>  ImageF3;
typedef itk::Image<unsigned long, 2u>  ImageUL2;

#define INSTANTIATE(classname,varname) \
  classname::Pointer varname = classname::New();

#ifdef __GCCXML__
  // 2D images
  template class itk::ImageRegion<2u>;

  // Declaring Image float 2
  template class itk::Image<float,2>;
  template class itk::SmartPointer<ImageF2>;
  template class itk::DefaultPixelAccessor<float>;

  // Declaring Image float 3
  template class itk::Image<float,3>;
  template class itk::SmartPointer<ImageF3>;

  // Declaring Image unsigned char 2
  template class itk::Image<unsigned char,2>;
  template class itk::SmartPointer<itk::Image<unsigned char, 2u> >;
  template class itk::DefaultPixelAccessor<unsigned char>;
  
  // Declaring Image unsigned long 2
  template class itk::Image<unsigned long,2>;
  template class itk::SmartPointer<itk::Image<unsigned long, 2u> >;
  template class itk::DefaultPixelAccessor<unsigned long>;
  
  // Image reader/writer
  INSTANTIATE(itk::ImageFileReader<ImageUC2>,image_filter_reader_UC2)
  INSTANTIATE(itk::ImageFileWriter<ImageUC2>,image_filter_writer_UC2)

  INSTANTIATE(itk::ImageFileReader<ImageF2>,image_filter_reader_F2)
  INSTANTIATE(itk::ImageFileWriter<ImageF2>,image_filter_writer_F2)

  // BinaryThresholdImageFilter
  typedef itk::BinaryThresholdImageFilter<ImageUC2, ImageUC2> 
    BinaryThresholdImageFilter_UC2_UC2;
  INSTANTIATE( BinaryThresholdImageFilter_UC2_UC2, thresholdFilter)

  // TranslationTransform
  template class itk::Vector<double,2>;
  typedef itk::TranslationTransform<double,2> TranslationTransform_D2;
  INSTANTIATE( TranslationTransform_D2, translation_transform_d2)

  // ResampleImageFilter
  typedef itk::ResampleImageFilter<ImageUC2, ImageUC2> ResampleImageFilter_UC2_UC2;
  INSTANTIATE( ResampleImageFilter_UC2_UC2, resampleimagefilter_uc2_uc2)

#endif // __GCCXML__



 