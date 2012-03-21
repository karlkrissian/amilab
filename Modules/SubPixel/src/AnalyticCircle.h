/*
 *  AnalyticCircle.h
 *  AMILab
 */

#ifndef _AnalyticCircle_h_
#define _AnalyticCircle_h_

#include "DefineClass.hpp"
#include "wrap_AnalyticFunctionBase.h"


/**
 *  AnalyticCircle class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticCircle : public AnalyticFunctionBase {
  
  DEFINE_CLASS(AnalyticCircle);
  
private:
  //Center of the circle
  float center[2];
  //Radius of the circle
  float radius;
  
public:
  /**
   *  Creates an analytic circle.
   *  @param x Component of the center. Default 50.
   *  @param y Component of the center. Default 50.
   *  @param r Radius of the circle. Default 20.
   */
  AnalyticCircle(float x = 50, float y = 50, float r = 20);
  
  ~AnalyticCircle();
  
  /**
   *  Operator () redefinition. Evaluates if a point is inside the circle.
   *  @param x Component of the point.
   *  @param y Component of the point.
   *  @param z Unused.
   *  @return double A double number that represents the value of the point in
   *  the circle image.
   */
  double operator () (const double& x, const double& y, const double& z) const;
  
  /**
   *  Set the center of the circle.
   *  @param c1 X component of the center.
   *  @param c2 Y component of the center.
   */
  void setCenter(float c1, float c2);
  
  /**
   *  Get the center of the circle.
   *  @return float* A pointer to a vector with the center value.
   */
  float* getCenter();
  
  /**
   *  Set the radius of the circle.
   *  @param r The value of the radius.
   */
  void setRadius(float r);
  
  /**
   *  Get the radius of the circle.
   *  @return float The radius value.
   */
  float getRadius();
};

#endif
