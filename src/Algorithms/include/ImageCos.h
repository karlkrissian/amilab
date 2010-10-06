//
// C++ Interface: ImageCos
//
// Description: Add a scalar value to each pixel/voxel of the image
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _ImageCos_h_
#define _ImageCos_h_

#include "inrimage.hpp"
#include "imageextent.h"
#include "ImageToImageFilter.h"
#include <vector>
#include "DefineClass.hpp"

// use amilab namespace here ??

// 
// ImageToImageFilterParam
// features needed:
//    - help
//    - gui
//
class ImageCos : public ImageToImageFilter 
{
  DEFINE_CLASS(ImageCos);

protected:
  double scalar;
  typedef ImageExtent<int> extenttype;
  std::vector<extenttype> extents;

public:

  /**
   * Creates the extents for each thread
   */
  void Init();

  
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

#endif // _ImageCos_h_
