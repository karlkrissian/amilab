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
class ImageCos : public ImageToImageFilter 
{
  DEFINE_CLASS(ImageCos);


public:

  
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

#endif // _ImageCos_h_

