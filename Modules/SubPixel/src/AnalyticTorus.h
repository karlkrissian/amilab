/*
 *  AnalyticTorus.h
 *  AMILab
 */

#ifndef _AnalyticTorus_h_
#define _AnalyticTorus_h_

#include "DefineClass.hpp"

#include "AnalyticFunctionBase.h"

/**
 *  AnalyticTorus class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticTorus : public AnalyticFunctionBase {
  
  DEFINE_CLASS(AnalyticTorus);
  
private:
  //The center of the torus
  float center[3];
  // Minimum radius
  float rmin;
  // Maximum radius
  float rmax;
public:
  /**
   *  Creates an analytic torus.
   *  @param x Component of the center. Default 50.
   *  @param y Component of the center. Default 50.
   *  @param z Component of the center. Default 50.
   *  @param r Minimum radius. Default 3.
   *  @param R Maximum radius. Default 20.
   */
  AnalyticTorus(float x = 50, float y = 50, float z = 50,
                float r = 3, float R = 20);
  
  ~AnalyticTorus();
  
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
  float* getCenter();
  
  /**
   *  Set the minimum radius of the torus.
   *  @param rm The new minimum radius value.
   */
  void set_rmin(float rm);
  
  /**
   *  Get the minimum radius of the torus.
   *  @return float The minimum radius value.
   */
  float get_rmin();
  
  /**
   *  Set the maximum radius of the torus.
   *  @param rM The new maximum radius value.
   */
  void set_rmax(float rM);
  
  /**
   *  Get the maximum radius of the torus.
   *  @return float The maximum radius value.
   */
  float get_rmax();
};

#endif
