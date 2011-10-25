
#pragma once
#ifndef _DistanceTransforms_h_
#define _DistanceTransforms_h_

#include "AlgorithmsConfigure.h"
#include "inrimage.hpp"


//Algorithms_EXPORT InrImage* Func_Laplacian(   InrImage* im);


Algorithms_EXPORT InrImage* Func_PropagationDistance(InrImage* input, 
                                                     float max_dist=1000);

Algorithms_EXPORT InrImage* Func_PropagationDistance2(InrImage* input, 
                                                      float max_dist=1000);

Algorithms_EXPORT InrImage* Func_PropagationDanielsson(InrImage* input, 
                                                       float max_dist=1000);

#endif // _DistanceTransforms_h_
