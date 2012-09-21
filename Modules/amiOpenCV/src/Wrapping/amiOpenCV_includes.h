
#pragma once

#include "PruebaClass.h"


// Some OpenCV features ...
#include <cv.h>
#include <highgui.h>
#include <math.h>


#ifdef __GCCXML__
  template class std::vector<cv::Vec3f>;

  template class cv::Point3_<int>;
  template class cv::Point3_<float>;
  template class cv::Point3_<double>;

  template class cv::Point_<int>;
  template class cv::Point_<float>;
  template class cv::Point_<double>;
  
  // need to instanciate template constructors ...  
  std::vector<cv::Vec3f> v_cv_vec3f;
  cv::_InputArray ia_v_cv_vec3f(v_cv_vec3f);
  cv::_OutputArray oa_v_cv_vec3f(v_cv_vec3f);

  std::vector<cv::Point_<double> > v_cv_ptd;
  cv::_InputArray ia_v_cv_ptd(v_cv_ptd);

  std::vector<cv::Point_<float> > v_cv_ptf;
  cv::_InputArray ia_v_cv_ptf(v_cv_ptf);
  
  
#endif  
