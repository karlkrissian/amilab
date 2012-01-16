//
// C++ Interface: ImageAddScalar
//
// Description: Add a scalar value to each pixel/voxel of the image
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _ImageAddScalar_h_
#define _ImageAddScalar_h_

#include "inrimage.hpp"
#include "amiImageExtent.h"
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
class ImageAddScalar : public ImageToImageFilter 
{

  DEFINE_CLASS(ImageAddScalar);

  double scalar;

  /// filter mode: 1 or 2, trying different code for optimization; 1: use iterators, 2: use pointers
  int _mode;

public:

  ImageAddScalar(): _mode(1) 
  { 
  }


  void SetMode( int mode) { _mode = mode; }

  /**
   * Set the scalar value to add to the image
   * @param val 
   */
  void SetScalarValue( double val) { scalar=val;}

  
  /**
   * Process part of the image
   * @param threadid 
   */
  template <class T>
  void TemplateProcess( int threadid = 0);

  /**
   * Process part of the image
   * @param threadid 
   */
  void Process( int threadid = 0);

}; // ImageAddFilter

} // end namespace ami

#endif // _ImageAddScalar_h_
