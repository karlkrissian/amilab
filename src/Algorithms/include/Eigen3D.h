
#pragma once
#ifndef _Eigen3D_h_
#define _Eigen3D_h_

#include "inrimage.hpp"

// TODO: dll_export ...

unsigned char  Func_Eigen2D(  char* varname,
                              InrImage* Mxx, InrImage* Mxy,
                              InrImage* Myy,
                              InrImage* mask = NULL);

unsigned char  Func_Eigen3D(  char* varname,
                              InrImage* Mxx, InrImage* Mxy, InrImage* Mxz,
                              InrImage* Myy, InrImage* Myz, InrImage* Mzz,
                              InrImage* mask = NULL);


#endif // _Eigen3D_h_
