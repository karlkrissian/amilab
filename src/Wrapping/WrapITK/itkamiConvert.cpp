
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
// itk float 2D --> amilab
InrImage::ptr itk::amiConvert::FromITK_float_2u( Image_float2_ptr input)
{
  Image_float2::RegionType region = input->GetLargestPossibleRegion();
  InrImage::ptr res( ITKToInr<float, 2>(input,region));
  return res;
}

//--------------------------------------------------------------
// amilab --> itk float 2D
Image_float2_ptr itk::amiConvert::ToITK_float_2u( InrImage::ptr input)
{
  Image_float2::RegionType region;
  return InrToITK<float, 2>(input.get(),region);
}

//--------------------------------------------------------------
// itk unsigned long 2D --> amilab
InrImage::ptr itk::amiConvert::FromITK_UL_2u( Image_ulong2_ptr input)
{
  Image_ulong2::RegionType region = input->GetLargestPossibleRegion();
  InrImage::ptr res( ITKToInr<unsigned long, 2>(input,region));
  return res;
}

//--------------------------------------------------------------
// amilab --> itk unsigned long 2D
Image_ulong2_ptr itk::amiConvert::ToITK_UL_2u( InrImage::ptr input)
{
  Image_ulong2::RegionType region;
  return InrToITK<unsigned long, 2>(input.get(),region);
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
InrImage::ptr itk::amiConvert::FromITK_float_3u( Image_float3_ptr input)
{
  Image_float3::RegionType region = input->GetLargestPossibleRegion();
  InrImage::ptr res( ITKToInr<float,3>(input,region));
  return res;
}

//--------------------------------------------------------------
// amilab --> itk float 3D
Image_float3_ptr itk::amiConvert::ToITK_float_3u( InrImage::ptr input)
{
  Image_float3::RegionType region;
  return InrToITK<float,3>(input.get(),region);
}

