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
  void setBorderPixelValues(double intA, double intB, unsigned char bord,
                            double coef_a, double coef_b, double coef_c,
                            double cu, int posx, int posy);
  double        getAIntensity();
  double        getBIntensity();
  unsigned char getBorder();
  double        getCoefficient_a();
  double        getCoefficient_b();
  double        getCoefficient_c();
  double        getCurvature();
  int           getPosX();
  int           getPosY();
  void          printBorderPixel(int linear_case);
  
private:
  //Intensity values
  double A;
  double B;
  //Border type
  unsigned char border;
  //Curve coefficients (y = a + bx + cx^2)
  double a;
  double b;
  double c;
  //Curvature
  double curvature;
  //Position
  int px;
  int py;

};

#include "BasicVariable.h"
class ParamList;

BasicVariable::ptr wrapSubpixel2D (ParamList* p);

BasicVariable::ptr wrapGaussianSubpixel2D (ParamList* p);

void wrapDrawBorder (ParamList* p);

#endif
