/*
 *  wrapSubPixel2D.h
 */

#ifndef SUBPIXEL2D
#define SUBPIXEL2D

/*class subpixel2D {
public:
  subpixel2D(long size) {
    gx = new float[size];
    gy = new float[size];
    displacement = new float[size];
    edge = new unsigned char[size];
  }
  ~subpixel2D() {
    delete gx;
    delete gy;
    delete displacement;
    delete edge;
  }
private:
  float* gx;
  float* gy;
  float* displacement;
  unsigned char* edge;
};*/

#include "BasicVariable.h"
class ParamList;

BasicVariable::ptr wrapSubpixel2D (ParamList* p);

#endif
