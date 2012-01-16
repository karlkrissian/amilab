
#ifndef ami_itkImageConversion_h_
#define ami_itkImageConversion_h_

#include "inrimage.hpp"
#include <itkImage.h>

typedef  itk::Image<unsigned char,2> Image_UC2;
typedef  itk::Image<unsigned char,2>::Pointer Image_UC2_ptr;
typedef  itk::Image<unsigned char,2>::RegionType Image_UC2_region;

typedef  itk::Image<short,3> Image_short3;
typedef  itk::Image<short,3>::Pointer Image_short3_ptr;

typedef  itk::Image<float,3> Image_float3;
typedef  itk::Image<float,3>::Pointer Image_float3_ptr;

namespace itk {
  
// start with only one type
class amiConvert {
  
public:
  
  // itk uchar 2D <--> amilab
  static InrImage::ptr FromITK_UC2( Image_UC2_ptr );
  static Image_UC2_ptr ToITK_UC2( InrImage::ptr);
  
  // itk short 3D <--> amilab
  static InrImage::ptr FromITK_short3( Image_short3_ptr );
  static Image_short3_ptr ToITK_short3( InrImage::ptr);

  // itk float 3D <--> amilab
  static InrImage::ptr FromITK_float3( Image_float3_ptr );
  static Image_float3_ptr ToITK_float3( InrImage::ptr);
};

};

#endif //  ami_itkImageConversion_h_