
#pragma once
#ifndef _NormGrad_h_
#define _NormGrad_h_

#include "AlgorithmsConfigure.h"
#include "inrimage.hpp"


Algorithms_EXPORT InrImage* Func_NormGrad( InrImage* im, float sigma, int support=4 );


#endif // _NormGrad_h_
