
#pragma once
#ifndef _Eigen3D_h_
#define _Eigen3D_h_

#include "AlgorithmsConfigure.h"
#include "inrimage.hpp"

// TODO: dll_export ...

Algorithms_EXPORT unsigned char  Func_Eigen2D(  const char* varname,
                              InrImage* Mxx, InrImage* Mxy,
                              InrImage* Myy,
                              InrImage* mask = NULL);

Algorithms_EXPORT unsigned char  Func_Eigen3D(  const char* varname,
                              InrImage* Mxx, InrImage* Mxy, InrImage* Mxz,
                              InrImage* Myy, InrImage* Myz, InrImage* Mzz,
                              InrImage* mask = NULL);


#endif // _Eigen3D_h_
