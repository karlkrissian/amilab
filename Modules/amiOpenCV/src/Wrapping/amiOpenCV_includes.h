
#pragma once

#include "PruebaClass.h"


// Some OpenCV features ...
#include <cv.h>
#include <highgui.h>
#include <math.h>


#ifdef __GCCXML__
  template class std::vector<cv::Vec3f>;
  template class std::vector<cv::Vec4i>;

  template class cv::Point3_<int>;
  template class cv::Point3_<float>;
  template class cv::Point3_<double>;

  template class cv::Point_<int>;
  template class cv::Point_<float>;
  template class cv::Point_<double>;
  
  // need to instanciate template constructors ...  
  typedef std::vector<cv::Vec3f> vvec3f;
  vvec3f v_cv_vec3f;
  cv::_InputArray   ia_v_cv_vec3f(v_cv_vec3f);
  cv::_OutputArray  oa_v_cv_vec3f(v_cv_vec3f);
  
  typedef std::vector<cv::Vec4i> vvec4i;
  vvec4i v_cv_vec4i;
  cv::_InputArray   ia_v_cv_vec4i(v_cv_vec4i);
  cv::_OutputArray  oa_v_cv_vec4i(v_cv_vec4i);

  typedef std::vector<cv::Point_<double> > vptd;
  vptd v_cv_ptd;
  cv::_InputArray   ia_v_cv_ptd(v_cv_ptd);

  typedef std::vector<cv::Point_<float> > vptf;
  vptf v_cv_ptf;
  cv::_InputArray   ia_v_cv_ptf(v_cv_ptf);
  
  typedef std::vector<cv::Vec2f> vvec2f;
  vvec4i v_cv_vec2f;
  cv::_OutputArray  oa_v_cv_vec2f(v_cv_vec2f);
  
#endif  
