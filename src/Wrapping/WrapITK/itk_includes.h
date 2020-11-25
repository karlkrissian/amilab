
#include "itkamiConvert.h"


#define INSTANTIATE(classname,varname) \
  classname::Pointer varname = classname::New();

// std classes: should not be here ...
#include <vector>
#include <set>  

// string should be recognized as builtin type
#include <string>


// VNL CLASSES
#include "vnl/vnl_matrix.h"
#include "vnl/vnl_vector.h"
#include "vnl/algo/vnl_symmetric_eigensystem.h"
#include "vnl/vnl_vector_fixed.h"
#include <vnl/vnl_diag_matrix.h>

#ifdef __GCCXML__
#define ITK_TEMPLATE_EXPLICIT_MetaDataObject
  template class vnl_matrix<double>;
  template class vnl_diag_matrix<double>;
  template class vnl_vector<double>;
  template class vnl_symmetric_eigensystem<double>;
  template class vnl_vector_fixed<double, 3>;
namespace itk_castxml {
  typedef vnl_matrix<double>                  v1;
  typedef vnl_diag_matrix<double>             v2;
  typedef vnl_vector<double>                  v3;
  typedef vnl_symmetric_eigensystem<double>   v4;
  typedef vnl_vector_fixed<double,3>          v5;
  v1 v1_var;
  v2 v2_var;
  v3 v3_var;
  //v4 v4_var;
  v5 v5_var;
};
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

namespace itk_castxml {
  // 
  typedef itk::ProgressEvent t0;
  typedef itk::Version t1;
  typedef itk::amiConvert t2;

  // Available Pixel types
  typedef itk::DefaultPixelAccessor<float>          v7;
  typedef itk::DefaultPixelAccessor<unsigned char>  v8;
  typedef itk::DefaultPixelAccessor<short>          v9;
  typedef itk::DefaultPixelAccessor<unsigned short> v10;
};
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
namespace itk_castxml {
  INSTANTIATE(itkAmiCommand, itkamicmd)
  typedef itk::MetaDataObject<std::string> v11;
}
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

namespace itk_castxml {

  // 2D Image types
  typedef itk::Image<float, 2u>       v20;
  typedef itk::SmartPointer<ImageF2>  v21;
  typedef itk::ImageSource<ImageF2>   v22;
  
  typedef itk::Image<unsigned char, 2u> v23;
  typedef itk::SmartPointer<ImageUC2>   v24;
  typedef itk::ImageSource<ImageUC2>    v25;

  // 3D Image types
  typedef itk::Image<float, 3u>         v26;
  typedef itk::SmartPointer<ImageF3>    v27;
  typedef itk::ImageSource<ImageF3>     v28;
  
  typedef itk::Image<short, 3u>         v29;
  typedef itk::SmartPointer<ImageS3>    v30;
  typedef itk::ImageSource<ImageS3>     V31;
  
  typedef itk::Image<unsigned short, 3u> v32;
  typedef itk::SmartPointer<ImageUS3>    v33;
  typedef itk::ImageSource<ImageUS3>     v34;

  typedef itk::Image<unsigned char, 3u>  v35;
  typedef itk::SmartPointer<ImageUC3>    v36;
  typedef itk::ImageSource<ImageUC3>     v37;
};
#endif

  
#include <itkImageFileReader.h>
#include <itkImageFileWriter.h>
  
#ifdef __GCCXML__
namespace itk_castxml {
  // Image reader/writer
  INSTANTIATE(itk::ImageFileReader<ImageUC2>, image_filter_reader_UC2)
  INSTANTIATE(itk::ImageFileWriter<ImageUC2>, image_filter_writer_UC2)

  INSTANTIATE(itk::ImageFileReader<ImageF2>, image_filter_reader_F2)
  INSTANTIATE(itk::ImageFileWriter<ImageF2>, image_filter_writer_F2)
};
#endif

#include <itkOrientImageFilter.h>
  
#ifdef __GCCXML__
namespace itk_castxml {
  typedef itk::OrientImageFilter<ImageUS3, ImageUS3>
    OrientImageFilter_US3_US3;
  INSTANTIATE(OrientImageFilter_US3_US3, orient_image_filter_US3)

    typedef itk::OrientImageFilter<ImageS3, ImageS3>
    OrientImageFilter_S3_S3;
  INSTANTIATE(OrientImageFilter_S3_S3, orient_image_filter_S3)
};
#endif // __GCCXML__
  
  
  
//#include "itkDICOMImageIO2.h"
#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"
#include "itkImageSeriesReader.h"
  
#ifdef __GCCXML__
namespace itk_castxml {
  // Image Series reader
  INSTANTIATE(itk::ImageSeriesReader<ImageUC3>, imageseries_reader_UC3)
    INSTANTIATE(itk::ImageSeriesReader<ImageS3>, imageseries_reader_S3)
    INSTANTIATE(itk::ImageSeriesReader<ImageF3>, imageseries_reader_F3)
};
#endif

#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"
  
#ifdef __GCCXML__
namespace itk_castxml {
  //  template class itk::SmartPointer<itk::DICOMImageIO2>;
  typedef itk::SmartPointer<itk::GDCMImageIO>  v40;
  typedef itk::SmartPointer<itk::GDCMSeriesFileNames> v41;
};
#endif
  
#include <itkBinaryThresholdImageFilter.h>
#include <itkTranslationTransform.h>
#include <itkResampleImageFilter.h>


#ifdef __GCCXML__
namespace itk_castxml {
  // BinaryThresholdImageFilter
  typedef itk::BinaryThresholdImageFilter<ImageUC2, ImageUC2>
    BinaryThresholdImageFilter_UC2_UC2;
  INSTANTIATE(BinaryThresholdImageFilter_UC2_UC2, thresholdFilter)

    // TranslationTransform
  typedef itk::Vector<double, 2> v50;
  typedef itk::TranslationTransform<double, 2> TranslationTransform_D2;
  INSTANTIATE(TranslationTransform_D2, translation_transform_d2)

    // ResampleImageFilter
    typedef itk::ResampleImageFilter<ImageUC2, ImageUC2> ResampleImageFilter_UC2_UC2;
  INSTANTIATE(ResampleImageFilter_UC2_UC2, resampleimagefilter_uc2_uc2)
};
#endif // __GCCXML__

#undef CABLE_CONFIGURATION
#include <itkGradientAnisotropicDiffusionImageFilter.h>

#ifdef __GCCXML__
namespace itk_castxml {
  typedef itk::GradientAnisotropicDiffusionImageFilter<ImageF2, ImageF2>
    GradientAnisotropicDiffusiondImageFilter_F2_F2;
  INSTANTIATE( GradientAnisotropicDiffusiondImageFilter_F2_F2, 
               gradientanisotropicdiffusionfilter_f2_f2)
  typedef itk::GradientAnisotropicDiffusionImageFilter<ImageF3, ImageF3> 
    GradientAnisotropicDiffusiondImageFilter_F3_F3;
  INSTANTIATE( GradientAnisotropicDiffusiondImageFilter_F3_F3, 
               gradientanisotropicdiffusionfilter_f3_f3)
}
#endif // __GCCXML__

#include <itkCannyEdgeDetectionImageFilter.h>
  
#ifdef __GCCXML__
namespace itk_castxml {
  typedef itk::CannyEdgeDetectionImageFilter<ImageF2, ImageF2>
    CannyEdgeDetectionImageFilter_F2_F2;
  INSTANTIATE( CannyEdgeDetectionImageFilter_F2_F2, 
               cannyedgedetectionfilter_f2_f2)
  typedef itk::CannyEdgeDetectionImageFilter<ImageF3, ImageF3> 
    CannyEdgeDetectionImageFilter_F3_F3;
  INSTANTIATE( CannyEdgeDetectionImageFilter_F3_F3, 
               cannyedgedetectionfilter_f3_f3)
}
#endif // __GCCXML__
  
// DICOM
  
#include "itkGDCMImageIO.h"
#include "itkMetaDataObject.h"
#include <gdcmGlobal.h>
#include <gdcmDicts.h>
#include <gdcmGroupDict.h>
#include <gdcmDictEntry.h>
#include <gdcmDict.h>
#include <gdcmImage.h>
#include <gdcmImageReader.h>
#include <gdcmReader.h>
#include <gdcmFile.h>
#include <gdcmFileMetaInformation.h>
#include <gdcmTag.h>
#include <gdcmPrivateTag.h>
#include <gdcmDataElement.h>
#include <gdcmDataSet.h>
#include <gdcmStringFilter.h>
#include <gdcmValue.h>
#include <gdcmByteValue.h>
#include <gdcmVL.h>

#include <gdcmDirectory.h>
#include <gdcmScanner.h>
#include <gdcmSimpleSubjectWatcher.h>
#include <gdcmVersion.h>
  
#if GDCM_MAJOR_VERSION < 2
#include "gdcmDictSet.h"
#endif

#include <set>
#include <utility>
#ifdef __GCCXML__
namespace itk_castxml {
    typedef std::set<gdcm::DataElement> v60;

    // instanciate typedefs
    gdcm::DataSet::Iterator dsi;

    //template class std::set<std::string>;
    //std::set<std::string>::iterator it;
    gdcm::Scanner::ValuesType scanner_vt;
    gdcm::Scanner::ValuesType::iterator scanner_vt_it;

    typedef std::map<gdcm::Tag, char const*> v61;

#ifndef WIN32
    // problem on windows with const for gdcm::Tag in std::pair
    typedef std::pair<gdcm::Tag const, char const*> v62;
#endif
    gdcm::Dict::MapDictEntry mde;
    gdcm::Dict::MapDictEntry::iterator  mde_iterator;
};
#endif
  