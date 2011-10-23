
#pragma once
#ifndef _ImageDerivatives_h_
#define _ImageDerivatives_h_

#include "AlgorithmsConfigure.h"
#include "inrimage.hpp"


Algorithms_EXPORT InrImage* Func_Laplacian(   InrImage* im);

Algorithms_EXPORT InrImage* Func_SecDerGrad(  InrImage* im, 
                                              float sigma );

// Don't use voxel size
Algorithms_EXPORT InrImage* Func_SecDerGrad2( InrImage* im, 
                                              float sigma );

Algorithms_EXPORT InrImage* Func_Gradient(    InrImage* im, 
                                              float sigma );

/**
 * Apply a Gaussian (or its derivatives) convolution to the input image
 * @param im input image
 * @param sigma Gaussian standard deviation
 * @param der_x derivation order in X (-1: no convolution, 0: Gaussian smoothing, 1: first order derivative, 2:second order der.)
 * @param der_y same in Y
 * @param der_z same in Z
 * @return pointer to the resulting image
 */
Algorithms_EXPORT InrImage* Func_Filter(      InrImage* im, 
                                              float sigma,
                                              int der_x, 
                                              int der_y, 
                                              int der_z);

#endif // _ImageDerivatives_h_
