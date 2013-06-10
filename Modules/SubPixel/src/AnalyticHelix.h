/*
 *  AnalyticHelix.h
 *  AMILab
 */

#ifndef _AnalyticHelix_h_
#define _AnalyticHelix_h_

#include "DefineClass.hpp"
#include "AnalyticFunctionBase.h"

#ifndef PI
const double PI = 3.141592741;
#endif

#undef AddSetGetVar
#define AddSetGetVar( name, type) \
  type  name; \
  void Set##name( type _arg) \
  { \
    this->name = _arg; \
  };  \
  type Get##name() \
  { \
    return this->name; \
  };

/**
 *  AnalyticHelix class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticHelix : public AnalyticFunctionBase {
  
  DEFINE_CLASS(AnalyticHelix);
  
private:
  //The center of the torus
  float center[3];

public:
  /**
   *  Creates an analytic torus.
   */
  AnalyticHelix() 
  {
    center[0]=center[1]=center[2]=50;
    radius = 10;
    thickness=2;
    rotation_coeff=PI/20;
  }
  
  ~AnalyticHelix();
  
  /**
   *  Operator () redefinition. Evaluates if a point is inside the torus.
   *  @param x Component of the point.
   *  @param y Component of the point.
   *  @param z Component of the point.
   *  @return double A double number that represents the value of the point in
   *  the torus image.
   */
  double operator () (const double& x, const double& y, const double& z) const;
  
  /**
   *  Set the center of the torus.
   *  @param c1 X component of the center.
   *  @param c2 Y component of the center.
   *  @param c3 Z component of the center.
   */
  void setCenter(float c1, float c2, float c3);
  
  /**
   *  Get the center of the torus.
   *  @return float* A pointer to a vector with the center value.
   */
  float* getCenter()
  {
    return center;
  }
  
  AddSetGetVar(radius,        float)
  AddSetGetVar(thickness,     float)
  
  /**
   * the angle in XY plane will be rotation_coeff*z
   */
  AddSetGetVar(rotation_coeff,float)
};

#endif
