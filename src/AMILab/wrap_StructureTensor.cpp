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


   if (!(input = p->GetParamPtr<InrImage>(type_image,n++)))
      HelpAndReturnNULL;

   if (!get_float_param(         sigma,       p, n)) HelpAndReturnNULL;
   if (!get_float_param(         beta,        p, n)) HelpAndReturnNULL;

   mask = p->GetParamPtr<InrImage>(type_image,n++);
   if (mask==NULL) mask = InrImage::ptr();

   imgrad = p->GetParamPtr<InrImage>(type_image,n++);
   if (imgrad==NULL) imgrad = InrImage::ptr();

  InrImage* result = Func_StructureTensorHessianNew( input, sigma, beta, mask, imgrad);


  return result;
}
