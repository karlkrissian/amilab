
#ifndef ami_itkImageConversion_h_
#define ami_itkImageConversion_h_

#include "inrimage.hpp"
#include <itkImage.h>

typedef  itk::Image<unsigned char,2> Image_UC2;
typedef  itk::Image<unsigned char,2>::Pointer Image_UC2_ptr;
typedef  itk::Image<unsigned char,2>::RegionType Image_UC2_region;

namespace itk {
  
// start with only one type
class amiConvert {
  
public:
  
  // itk uchar 2D --> amilab
  static InrImage::ptr FromITK_US2( Image_UC2_ptr );

  // amilab --> itk uchar 2D
  static Image_UC2_ptr ToITK_US2( InrImage::ptr);
  
};

};

#endif //  ami_itkImageConversion_h_