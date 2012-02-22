
#include "itkamiConvert.h"


#define INSTANTIATE(classname,varname) \
  classname::Pointer varname = classname::New();

// std classes: should not be here ...
#include <vector>
// string should be recognized as builtin type
#include <string>

template class std::vector<std::string>;

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

#include <itkVersion.h>
#include <itkSmartPointer.h>
  
#include <itkDefaultPixelAccessor.h>

// Needed? yes
#ifdef __GCCXML__
  // Available Pixel types
  template class itk::DefaultPixelAccessor<float>;
  template class itk::DefaultPixelAccessor<unsigned char>;
  template class itk::DefaultPixelAccessor<short>;
  template class itk::DefaultPixelAccessor<unsigned short>;
#endif

#include <itkImageRegion.h>

/*
 * // Needed?
#ifdef __GCCXML__
  // Available image dimensions
  template class itk::ImageRegion<2u>;
  template class itk::ImageRegion<3u>;
#endif
  */

#include <itkImage.h>
#include <itkImageSource.h>
#include <itkProcessObject.h>
#include <itkObject.h>
#include <itkLightObject.h>
#include <itkEventObject.h>
#include <itkCommand.h>
#include "itkAmiCommand.h"

#include <itkMetaDataDictionary.h>
#include <itkMetaDataObject.h>

#ifdef __GCCXML__
  INSTANTIATE(itkAmiCommand, itkamicmd)
  template class itk::MetaDataObject<std::string>;
#endif

  // Typedefs
typedef itk::Image<float, 2u>          ImageF2;
typedef itk::Image<short, 2u>          ImageUS2;
typedef itk::Image<unsigned short, 2u> ImageS2;
typedef itk::Image<unsigned char, 2u>  ImageUC2;

typedef itk::Image<float, 3u>          ImageF3;
typedef itk::Image<short, 3u>          ImageS3;
typedef itk::Image<unsigned short, 3u> ImageUS3;
typedef itk::Image<unsigned char, 3u>  ImageUC3;


#ifdef __GCCXML__
  // 2D Image types
  template class itk::Image<float, 2u>;
  template class itk::SmartPointer<ImageF2>;
  template class itk::ImageSource<ImageF2>;
  
  template class itk::Image<unsigned char, 2u>;
  template class itk::SmartPointer<ImageUC2>;
  template class itk::ImageSource<ImageUC2>;

  // 3D Image types
  template class itk::Image<float, 3u>;
  template class itk::SmartPointer<ImageF3>;
  template class itk::ImageSource<ImageF3>;
  
  template class itk::Image<short, 3u>;
  template class itk::SmartPointer<ImageS3>;
  template class itk::ImageSource<ImageS3>;
  
  template class itk::Image<unsigned short, 3u>;
  template class itk::SmartPointer<ImageUS3>;
  template class itk::ImageSource<ImageUS3>;

  template class itk::Image<unsigned char, 3u>;
  template class itk::SmartPointer<ImageUC3>;
  template class itk::ImageSource<ImageUC3>;
  
#endif

  
#include <itkImageFileReader.h>
#include <itkImageFileWriter.h>
  
#ifdef __GCCXML__
  // Image reader/writer
  INSTANTIATE(itk::ImageFileReader<ImageUC2>,image_filter_reader_UC2)
  INSTANTIATE(itk::ImageFileWriter<ImageUC2>,image_filter_writer_UC2)

  INSTANTIATE(itk::ImageFileReader<ImageF2>,image_filter_reader_F2)
  INSTANTIATE(itk::ImageFileWriter<ImageF2>,image_filter_writer_F2)
#endif
  
  
#include "itkDICOMImageIO2.h"
#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"
#include "itkImageSeriesReader.h"
  
#ifdef __GCCXML__
  // Image Series reader
  INSTANTIATE(itk::ImageSeriesReader<ImageUC3>,imageseries_reader_UC3)
  INSTANTIATE(itk::ImageSeriesReader<ImageS3>,imageseries_reader_S3)
  INSTANTIATE(itk::ImageSeriesReader<ImageF3>,imageseries_reader_F3)
#endif

#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"
  
#ifdef __GCCXML__
  template class itk::SmartPointer<itk::DICOMImageIO2>;
  template class itk::SmartPointer<itk::GDCMImageIO>;
  template class itk::SmartPointer<itk::GDCMSeriesFileNames>;
#endif
  
#include <itkBinaryThresholdImageFilter.h>
#include <itkTranslationTransform.h>
#include <itkResampleImageFilter.h>


#ifdef __GCCXML__
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

#undef CABLE_CONFIGURATION
#include <itkGradientAnisotropicDiffusionImageFilter.h>

#ifdef __GCCXML__
  typedef itk::GradientAnisotropicDiffusionImageFilter<ImageF2, ImageF2> 
    GradientAnisotropicDiffusiondImageFilter_F2_F2;
  INSTANTIATE( GradientAnisotropicDiffusiondImageFilter_F2_F2, 
               gradientanisotropicdiffusionfilter_f2_f2)
  typedef itk::GradientAnisotropicDiffusionImageFilter<ImageF3, ImageF3> 
    GradientAnisotropicDiffusiondImageFilter_F3_F3;
  INSTANTIATE( GradientAnisotropicDiffusiondImageFilter_F3_F3, 
               gradientanisotropicdiffusionfilter_f3_f3)
#endif // __GCCXML__

 