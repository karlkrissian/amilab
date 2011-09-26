
#include "itkamiConvert.h"
//#include "wrapConversion.h"
#include "wrapConversion.tpp"


//--------------------------------------------------------------
// itk uchar 2D --> amilab
InrImage::ptr itk::amiConvert::FromITK_US2( Image_UC2_ptr input)
{
  Image_UC2::RegionType region = input->GetLargestPossibleRegion();
  InrImage::ptr res( ITKToInr<unsigned char, 2>(input,region));
  return res;
}

//--------------------------------------------------------------
// amilab --> itk uchar 2D
Image_UC2_ptr itk::amiConvert::ToITK_US2( InrImage::ptr input)
{
  Image_UC2::RegionType region;
  return InrToITK<unsigned char, 2>(input.get(),region);
}
