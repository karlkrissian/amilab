/*
 *  wrapBasicEdgeDetection.h
 *  AMILab
 *
 *  Created by administrador on 09/03/10.
 *  
 *  Some tests of basic edge detection filters
 *
 */

#ifndef BASICEDGEDETECTION
#define BASICEDGEDETECTION

class InrImage;
class ParamList;

//Prototype basic edge detection functions
InrImage* wrapRoberts(ParamList* p);
InrImage* wrapPSF(ParamList* p);
InrImage* wrapGradient(ParamList* p);
InrImage* wrapLaplace(ParamList* p);

#endif
