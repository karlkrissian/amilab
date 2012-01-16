//
// C++ Interface: GrayscaleMorpho
//
// Description: Add a scalar value to each pixel/voxel of the image
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _GrayscaleMorpho_h_
#define _GrayscaleMorpho_h_

#include "inrimage.hpp"
//#include "amiImageExtent.h"
#include "amiImageToImageFilter.h"
#include <vector>
#include "DefineClass.hpp"

namespace ami {
// 
// ImageToImageFilterParam
// features needed:
//    - help
//    - gui
//
class GrayscaleMorpho : public ImageToImageFilter 
{
  DEFINE_CLASS(GrayscaleMorpho);

  float radius;
  
  enum Operation {
    Dilate,
    Erode
  };
  
  Operation morpho_operator;
  bool      use_intensity_range;
  double    intensity_min;
  double    intensity_max;
  
  InrImage::ptr output;

  /**
   * Information at each kernel point to speed-up the computation
   */
  struct kernel_info {
    short dx; // displacement in x
    short dy; // in y
    short dz; // in z
    int   inc; // displacement in the image vector 
               // (an integer should be enough!)
  };

public:

  
  /**
   * Process part of the image
   * @param threadid 
   */
  template <class T>
  void TemplateProcess( int threadid = 0);

  /**
   * Set the radius of the structuring disk
   * @param rad
   */  
  void SetRadius(float rad) { radius = rad; }
  float GetRadius()         { return radius; }
  
  /**
   * Sets an intensity range to apply the operation
   *  1. will apply the filter only to pixels within the range
   *  2. will only take into account neighbors within the range
   *     to compute the result
   */
  void SetIntensityRange( double Imin, double Imax)
  {
    intensity_min = Imin;
    intensity_max = Imax;
  }
  void GetIntensityRange( double& Imin, double& Imax)
  {
    Imin = intensity_min;
    Imax = intensity_max;
  }
  
  /**
   * Enable/Disable the use of intensity range
   */
  void UseIntensityRange(bool use) 
  {
    use_intensity_range = use;
  }
  bool GetUseIntensityRange() { return use_intensity_range; }
  
  /**
   * Set the morphological operation
   * @param op Dilate or Erode
   */
  void SetOperation( Operation op) { morpho_operator = op; }
  Operation GetOperation()         { return morpho_operator; }
  
  /**
   * Process part of the image
   * @param threadid 
   */
  void Process( int threadid = 0);
  
  void Run();

  InrImage::ptr& GetOutput()
  {
    return output;
  }

  
}; // ImageAddFilter

} // end namespace ami

#endif // _GrayscaleMorpho_h_

