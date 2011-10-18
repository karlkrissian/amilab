
#pragma once
#ifndef _DiscSecDerGrad_h_
#define _DiscSecDerGrad_h_

#include "AlgorithmsConfigure.h"
#include "inrimage.hpp"

// TODO: dll_export ...

Algorithms_EXPORT void Func_DiscSecDerGrad( InrImage* im, InrImage* Isecder, InrImage* Inormgrad = NULL);



#endif // _DiscSecDerGrad_h_
