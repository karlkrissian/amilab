/*
 *  wrapBasicEdgeDetection.h
 *  AMILab
 *
 *  Created by administrador on 09/03/10.
 *  
 *  Some tests of basic edge detection filters
 *
 */
#include "inrimage.hpp"
#include "paramlist.h"
//Prototype basic edge detection functions
InrImage* wrapRoberts(ParamList* p);
InrImage* wrapPSF(ParamList* p);
InrImage* wrapGradient(ParamList* p);
InrImage* wrapLaplace(ParamList* p);
