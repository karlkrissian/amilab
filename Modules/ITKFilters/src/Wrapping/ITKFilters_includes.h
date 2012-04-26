
#pragma once

#include "PruebaClass.h"

#include <itkImage.h>
#include <itkSmartPointer.h>
#include <itkDefaultPixelAccessor.h>
#include <itkImageRegion.h>


#include <itkGradientAnisotropicDiffusionImageFilter.h>

typedef itk::Image<unsigned char, 2u>  ImageUC2;
typedef itk::Image<float, 2u>  ImageF2;

#define INSTANTIATE(classname,varname) \
  classname::Pointer varname = classname::New();


#ifdef __GCCXML__
  // 2D images
  template class itk::ImageRegion<2u>;

  // Declaring Image float 2
  template class itk::Image<float,2>;
  template class itk::SmartPointer<ImageF2>;
  template class itk::DefaultPixelAccessor<float>;

  // Declaring Image unsigned char 2
  template class itk::Image<unsigned char,2>;
  template class itk::SmartPointer<itk::Image<unsigned char, 2u> >;
  template class itk::DefaultPixelAccessor<unsigned char>;

    // GradientAnisotropicDiffusionImageFilter
  typedef itk::GradientAnisotropicDiffusionImageFilter<ImageUC2, ImageUC2> 
    GradientAnisotropicDiffusionImageFilter_UC2_UC2;
  INSTANTIATE( GradientAnisotropicDiffusionImageFilter_UC2_UC2, ADFilter_UC2UC2)

  typedef itk::GradientAnisotropicDiffusionImageFilter<ImageF2, ImageF2> 
    GradientAnisotropicDiffusionImageFilter_F2_F2;
  INSTANTIATE( GradientAnisotropicDiffusionImageFilter_F2_F2, ADFilter_F2F2)

#endif 
