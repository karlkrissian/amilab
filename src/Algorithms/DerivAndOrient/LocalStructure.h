
#ifndef _LocalStructure_h_
#define _LocalStructure_h_

#include "style.hpp"
#include "inrimage.hpp"

namespace ami {

  unsigned char StructureTensorH( InrImage* image_initiale, 
  //            ----------------
                      const char* varname,
                      float sigma,
                      float beta,
                      InrImage* mask,
                      bool save_grad = false);

}

#endif 
// _LocalStructure_h_
