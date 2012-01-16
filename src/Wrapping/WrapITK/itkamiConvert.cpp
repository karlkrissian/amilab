
#include "itkamiConvert.h"
//#include "wrapConversion.h"
#include "wrapConversion.tpp"


//--------------------------------------------------------------
// itk uchar 2D --> amilab
InrImage::ptr itk::amiConvert::FromITK_UC2( Image_UC2_ptr input)
{
  Image_UC2::RegionType region = input->GetLargestPossibleRegion();
  InrImage::ptr res( ITKToInr<unsigned char, 2>(input,region));
  return res;
}

//--------------------------------------------------------------
// amilab --> itk uchar 2D
Image_UC2_ptr itk::amiConvert::ToITK_UC2( InrImage::ptr input)
{
  Image_UC2::RegionType region;
  return InrToITK<unsigned char, 2>(input.get(),region);
}

//--------------------------------------------------------------
// itk short 3D --> amilab
InrImage::ptr itk::amiConvert::FromITK_short3( Image_short3_ptr input)
{
  Image_short3::RegionType region = input->GetLargestPossibleRegion();
  InrImage::ptr res( ITKToInr<short,3>(input,region));
  return res;
}

//--------------------------------------------------------------
// amilab --> itk short 3D
Image_short3_ptr itk::amiConvert::ToITK_short3( InrImage::ptr input)
{
  Image_short3::RegionType region;
  return InrToITK<short,3>(input.get(),region);
}

//--------------------------------------------------------------
// itk float 3D --> amilab
InrImage::ptr itk::amiConvert::FromITK_float3( Image_float3_ptr input)
{
  Image_float3::RegionType region = input->GetLargestPossibleRegion();
  InrImage::ptr res( ITKToInr<float,3>(input,region));
  return res;
}

//--------------------------------------------------------------
// amilab --> itk float 3D
Image_float3_ptr itk::amiConvert::ToITK_float3( InrImage::ptr input)
{
  Image_float3::RegionType region;
  return InrToITK<float,3>(input.get(),region);
}

