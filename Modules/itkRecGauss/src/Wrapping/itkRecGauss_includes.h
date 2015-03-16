
#pragma once

#include "PruebaClass.h"
#include "itkSmoothingRecursiveYvvGaussianImageFilter.h"
#include "itkSmoothingRecursiveGaussianImageFilter.h"

#define INSTANTIATE(classname,varname) \
  classname::Pointer varname = classname::New();

  // Typedefs
typedef itk::Image<float, 2u>          ImageF2;
typedef itk::Image<short, 2u>          ImageUS2;
typedef itk::Image<unsigned short, 2u> ImageS2;
typedef itk::Image<unsigned char, 2u>  ImageUC2;

typedef itk::Image<float, 3u>          ImageF3;
typedef itk::Image<short, 3u>          ImageS3;
typedef itk::Image<unsigned short, 3u> ImageUS3;
typedef itk::Image<unsigned char, 3u>  ImageUC3;


// Recursive Gaussian Yvv algorithm
#ifdef __GCCXML__
  typedef itk::SmoothingRecursiveYvvGaussianImageFilter<ImageF2, ImageF2> 
    SmoothingRecursiveYvvGaussianImageFilter_F2_F2;
  INSTANTIATE( SmoothingRecursiveYvvGaussianImageFilter_F2_F2, 
               smoothingrecursiveyvvgaussianimagefilter_f2_f2)

  typedef itk::SmoothingRecursiveYvvGaussianImageFilter<ImageF3, ImageF3> 
    SmoothingRecursiveYvvGaussianImageFilter_F3_F3;
  INSTANTIATE( SmoothingRecursiveYvvGaussianImageFilter_F3_F3, 
               smoothingrecursiveyvvgaussianimagefilter_f3_f3)
#endif // __GCCXML__

// Recursive Gaussian Deriche algorithm
#ifdef __GCCXML__
  typedef itk::SmoothingRecursiveGaussianImageFilter<ImageF2, ImageF2> 
    SmoothingRecursiveGaussianImageFilter_F2_F2;
  INSTANTIATE( SmoothingRecursiveGaussianImageFilter_F2_F2, 
               smoothingrecursivegaussianimagefilter_f2_f2)

  typedef itk::SmoothingRecursiveGaussianImageFilter<ImageF3, ImageF3> 
    SmoothingRecursiveGaussianImageFilter_F3_F3;
  INSTANTIATE( SmoothingRecursiveGaussianImageFilter_F3_F3, 
               smoothingrecursivegaussianimagefilter_f3_f3)
#endif // __GCCXML__
  
#include "itkLevenbergMarquardtOptimizer.h"
typedef itk::LevenbergMarquardtOptimizer::InternalOptimizerType vnlOptimizerType;


#include "RecGaussCostFunction.h"
// instantiate smart pointer 
RecGaussCostFunction::Pointer recgaussCF_ptr;

