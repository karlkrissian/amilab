//
// C++ Interface: StructureTensor
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef _StructureTensor_h_
#define _StructureTensor_h_

#include "AlgorithmsConfigure.h"
#include "style.hpp"
#include "inrimage.hpp"
#include <vector>


Algorithms_EXPORT unsigned char Func_StructureTensor2D( InrImage* image_initiale, 
//            ----------------------
               const char* varname,
                float Sigma1, float Sigma2,
                InrImage* mask);


Algorithms_EXPORT unsigned char Func_StructureTensor( InrImage* image_initiale, 
//            --------------------
                      const char* varname,
                  float Sigma1, float Sigma2,
                  InrImage* mask);

Algorithms_EXPORT unsigned char Func_StructureTensorHessian( InrImage* image_initiale, 
//      ---------------------------
                     const char* varname,
                     float sigma,
                     float beta,
                     InrImage* mask,
                     bool save_grad = false);

//--------------------------------------------------------------------------
Algorithms_EXPORT InrImage::ptr Func_StructureTensorHessianNew( InrImage::ptr image_initiale, 
//        ------------------------------
                      float sigma,
                      float beta,
                      InrImage::ptr mask = InrImage::ptr(),
                      InrImage::ptr imgrad = InrImage::ptr(),
                      std::vector<float> PSF = std::vector<float>(3,0),
                      int num_threads = -1
                     );

#endif // _StructureTensor_h_
