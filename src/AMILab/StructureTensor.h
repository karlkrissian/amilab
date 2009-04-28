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

#include "style.hpp"
#include "inrimage.hpp"


unsigned char Func_StructureTensor2D( InrImage* image_initiale, 
//            ----------------------
                char* varname,
                float Sigma1, float Sigma2,
                InrImage* mask);


unsigned char Func_StructureTensor( InrImage* image_initiale, 
//            --------------------
                      char* varname,
                  float Sigma1, float Sigma2,
                  InrImage* mask);

unsigned char Func_StructureTensorHessian( InrImage* image_initiale, 
//      ---------------------------
                     char* varname,
                     float sigma,
                     float beta,
                     InrImage* mask,
                     bool save_grad = false);

//--------------------------------------------------------------------------
InrImage* Func_StructureTensorHessianNew( InrImage::ptr image_initiale, 
//        ------------------------------
                     float sigma,
                     float beta,
                     InrImage::ptr mask);

#endif // _StructureTensor_h_
