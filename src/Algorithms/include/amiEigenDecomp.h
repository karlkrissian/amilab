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
#include "FloatMatrix.hpp"

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

  bool check_eigenvalue_image(InrImage::ptr im);
  bool check_eigenvector_image(InrImage::ptr im);

  // allow storing the eigenvector as SIGNED SHORT
//  short convert_short(double val);

public:
  
  EigenDecomp() : diag_algorithm(JACOBI_INITIAL) {}
  
  enum DiagAlgorithm {
    JACOBI_INITIAL,
    KOPP_JACOBI,
    KOPP_QL,
    KOPP_CUPPEN,
    KOPP_CARDANO,
    KOPP_ANALYTICAL,
    KOPP_HYBRID
  };
  
  AddSetGetVar(diag_algorithm, DiagAlgorithm)

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

  AddSetGetVar(mask,         InrImage::ptr)
  
  /**
   * Process part of the image
   * @param threadid 
   */
  template <class T, class U>
  void TemplateProcess( int threadid = 0);

  /**
   * Special feature: allow changing the way the matrix is filled
   * with this virtual member
   */
  template <class T>
  void FillMatrix( FloatMatrix & matrix, T* in_ptr, int vdim);

  //template <>
  virtual void FillMatrix(FloatMatrix & matrix, float* in_ptr, int vdim);

  /**
   * Process part of the image
   * @param threadid 
   */
  void Process( int threadid = 0);
  
  void Run();

  
}; // EigenDecomp

} // end namespace ami

#endif // _EigenDecomp_h_

