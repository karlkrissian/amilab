//
// C++ Interface: LeastSquares
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _LeastSquares_h_
#define _LeastSquares_h_

#include "inrimage.hpp"

//--------------------------------------------------
//
// inputs:
// 1. input image to fit locally
// 2. input vectorial image, the size of the vector is the 
//    number of parameters and the values are the parameters to fit
//    for example the position in Y, X and 1
// 3. weights image, smaller image representing the weights for the
//    Least Square minimization, its size is the local fitting size
//

InrImage*   Func_LeastSquares( 
InrImage* _input, 
InrImage* _basis, 
InrImage* _weights, 
InrImage* _mask = NULL,
bool process_border=false);

#endif // _LeastSquares_h_
