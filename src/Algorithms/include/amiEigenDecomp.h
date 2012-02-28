//
// C++ Interface: EigenDecomp
//
// Description: Add a scalar value to each pixel/voxel of the image
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _EigenDecomp_h_
#define _EigenDecomp_h_

#include "inrimage.hpp"
//#include "amiImageExtent.h"
#include "amiImageToImageFilter.h"
#include <vector>
#include "DefineClass.hpp"

#define AddSetGetVar( name, type) \
    type  name; \
    void Set##name( type _arg) \
    { \
      this->name = _arg; \
    };  \
    type Get##name() \
    { \
      return this->name; \
    };

namespace ami {
// 
// ImageToImageFilterParam
// features needed:
//    - help
//    - gui
//
class EigenDecomp : public ImageToImageFilter 
{
  DEFINE_CLASS(EigenDecomp);

  bool enable_eigenvalue1;
  bool enable_eigenvalue2;
  bool enable_eigenvalue3;

  bool enable_eigenvector1;
  bool enable_eigenvector2;
  bool enable_eigenvector3;
  
  InrImage::ptr eigenvalue1;
  InrImage::ptr eigenvalue2;
  InrImage::ptr eigenvalue3;

  InrImage::ptr eigenvector2;
  InrImage::ptr eigenvector2;
  InrImage::ptr eigenvector3;

public:

  AddSetGetVar(enable_eigenvalue1,bool)
  AddSetGetVar(enable_eigenvalue2,bool)
  AddSetGetVar(enable_eigenvalue3,bool)

  AddSetGetVar(enable_eigenvector1,bool)
  AddSetGetVar(enable_eigenvector2,bool)
  AddSetGetVar(enable_eigenvector3,bool)

  AddSetGetVar(eigenvalue1, InrImage::ptr)
  AddSetGetVar(eigenvalue2, InrImage::ptr)
  AddSetGetVar(eigenvalue3, InrImage::ptr)

  AddSetGetVar(eigenvector1, InrImage::ptr)
  AddSetGetVar(eigenvector2, InrImage::ptr)
  AddSetGetVar(eigenvector3, InrImage::ptr)
  
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
  
  void Run();

  
}; // EigenDecomp

} // end namespace ami

#endif // _EigenDecomp_h_

