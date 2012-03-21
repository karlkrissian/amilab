/*
 *  AnalyticSphere.h
 *  AMILab
 */

#ifndef _AnalyticSphere_h_
#define _AnalyticSphere_h_

#include "DefineClass.hpp"

#include "wrap_AnalyticFunctionBase.h"

/**
 *  AnalyticSphere class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticSphere : public AnalyticFunctionBase {
  
  DEFINE_CLASS(AnalyticSphere);
  
private:
  //The center of the sphere
  float center[3];
  //Radius
  float radius;
  
public:
  /**
   *  Creates an analytic sphere.
   *  @param x Component of the center. Default 50.
   *  @param y Component of the center. Default 50.
   *  @param z Component of the center. Default 50.
   *  @param r Radius. Default 20.
   */
  AnalyticSphere(float x = 50, float y = 50, float z = 50, float r = 20);
  
  ~AnalyticSphere();
  
  /**
   *  Operator () redefinition. Evaluates if a point is inside the sphere.
   *  @param x Component of the point.
   *  @param y Component of the point.
   *  @param z Component of the point.
   *  @return double A double number that represents the value of the point in
   *  the sphere image.
   */
  double operator () (const double& x, const double& y, const double& z) const;
  
  /**
   *  Set the center of the sphere.
   *  @param c1 X component of the center.
   *  @param c2 Y component of the center.
   *  @param c3 Z component of the center.
   */
  void setCenter(float c1, float c2, float c3);
  
  /**
   *  Get the center of the sphere.
   *  @return float* A pointer to a vector with the center value.
   */
  float* getCenter();
  
  /**
   *  Set the radius of the sphere.
   *  @param r The new radius value.
   */
  void setRadius(float r);
  
  /**
   *  Get the radius of the sphere.
   *  @return float The radius value.
   */
  float getRadius();
};

#endif

