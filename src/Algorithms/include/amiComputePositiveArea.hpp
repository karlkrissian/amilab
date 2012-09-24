
#ifndef _ami_ComputePositiveArea_hpp_
#define _ami_ComputePositiveArea_hpp_

#include "inrimage.hpp"

namespace ami {

  float PositiveArea(float val[4]);

  float ComputePositiveArea( InrImage* im);
  
} // end of namespace ami

#endif // _ami_ComputePositiveArea_hpp_
