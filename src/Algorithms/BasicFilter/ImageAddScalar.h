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
#include "imageextent.h"
#include "ImageToImageFilter.h"
#include <vector>

// use amilab namespace here ??

// 
// ImageToImageFilterParam
// features needed:
//    - help
//    - gui
//
class ImageAddScalar : public ImageToImageFilter 
{
  double scalar;
  typedef ImageExtent<int> extenttype;
  std::vector<extenttype> extents;

public:

  /**
   * Creates the extents for each thread
   */
  void Init();

  /**
   * Set the scalar value to add to the image
   * @param val 
   */
  void SetScalarValue( double val) { scalar=val;}

  
  /**
   * Process part of the image
   * @param threadid 
   * @param numthreads 
   */
  void Process( int threadid = 0);

}; // ImageAddFilter

#endif // _ImageAddScalar_h_
