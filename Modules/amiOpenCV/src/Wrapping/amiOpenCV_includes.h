
#pragma once

#include "PruebaClass.h"


// Some OpenCV features ...
#include <cv.h>
#include <highgui.h>
#include <math.h>


#ifdef __GCCXML__
  template class std::vector<cv::Vec3f>;
 
  // need to instanciate template constructors ...  
  std::vector<cv::Vec3f> v;
  cv::_InputArray ia(v);
  cv::_OutputArray oa(v);
#endif  
