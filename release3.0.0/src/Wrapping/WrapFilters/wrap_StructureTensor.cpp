//
// C++ Implementation: wrap_StructureTensor
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_StructureTensor.h"
#include "StructureTensor.h"

#include "wrapfunctions.hpp"

InrImage* wrap_StructureTensorHessianNew(ParamList* p)
{
    char functionname[] = "wrap_StructureTensorHessianNew";
    char description[]=" \n\
      Local orientation extraction\n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input       initial image\n\
              sigma       Gaussian convolution standard deviation \n\
              beta        weight of the square Hessian matrix \n\
              mask        mask image\n\
              gradient    gradient image, get the computed smoothed gradient\n\
          Return:\n\
              A vectorial image representing the tensor as a symmetric matrix (6 components in 3D)\n\
            ";

    InrImage::ptr input;
    float     sigma;
    float     beta;
    InrImage::ptr mask;
    InrImage::ptr imgrad; // get the smoothed gradient
    int n=0;

   if (!get_val_smtptr_param<InrImage>( input,  p, n)) HelpAndReturnNULL;
   if (!get_val_param<float>(           sigma,  p, n)) HelpAndReturnNULL;
   if (!get_val_param<float>(           beta,   p, n)) HelpAndReturnNULL;
   // mask is not required
   if (!get_val_smtptr_param<InrImage>( mask,   p, n, false)) HelpAndReturnNULL;
   // gradient image is not required
   if (!get_val_smtptr_param<InrImage>( imgrad, p, n, false)) HelpAndReturnNULL;

  InrImage* result = Func_StructureTensorHessianNew( input, sigma, beta, mask, imgrad);


  return result;
}
