//
// C++ Interface: EigenDecomp_NRAD
//
// Description: Add a scalar value to each pixel/voxel of the image
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _EigenDecomp_NRAD_h_
#define _EigenDecomp_NRAD_h_

#include "inrimage.hpp"
//#include "amiImageExtent.h"
#include "amiImageToImageFilter.h"
#include <vector>
#include "DefineClass.hpp"
#include "FloatMatrix.hpp"
#include "amiEigenDecomp.h"

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
class EigenDecomp_NRAD : public EigenDecomp 
{
  DEFINE_CLASS(EigenDecomp_NRAD);

    enum HalfDisplacement {
      HALF_DISPL_X,
      HALF_DISPL_Y,
      HALF_DISPL_Z
    };
    int inc_x,inc_y,inc_z;
    
  public:
    
    AddSetGetVar(half_displ,HalfDisplacement)
    
    void InitIncrements();
    
    virtual void FillMatrix(FloatMatrix & matrix, float* in_ptr, int vdim);

    virtual void Run();

  
}; // EigenDecomp_NRAD

} // end namespace ami

#endif // _EigenDecomp_NRAD_h_

