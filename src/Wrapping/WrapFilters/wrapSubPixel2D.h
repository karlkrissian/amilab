/*
 *  wrapSubPixel2D.h
 */

#ifndef SUBPIXEL2D
#define SUBPIXEL2D

//New class for a pixel that is a border member
class borderPixel {
public:
  borderPixel() {}
  ~borderPixel() {}
  void setBorderPixelValues(float gradx, float grady, float disp,
                            float curv, unsigned char bord, int x, int y);
  float         getGradX();
  float         getGradY();
  float         getDisplacement();
  float         getCurvature();
  unsigned char getBorder();
  int           getXPosition();
  int           getYPosition();
  void          printBorderPixel();
  
private:
  float         gx;
  float         gy;
  float         displacement;
  float         curvature;
  unsigned char border;
  int           px;
  int           py;
};

#include "BasicVariable.h"
class ParamList;

BasicVariable::ptr wrapSubpixel2D (ParamList* p);

#endif
