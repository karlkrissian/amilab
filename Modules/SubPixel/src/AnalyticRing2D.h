/*
 *  AnalyticRing2D.h
 *  AMILab
 */

#ifndef _AnalyticRing2D_h_
#define _AnalyticRing2D_h_

#include "DefineClass.hpp"
#include "AnalyticFunctionBase.h"

/**
 *  AnalyticRing2D class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Agustín Trujillo Pino (agustin@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticRing2D : public AnalyticFunctionBase {
  //Ash Nazg durbatulûk, ash Nazg gimbatul, 
  //ash Nazg thrakatulûk agh burzum-ishi krimpatul
  DEFINE_CLASS(AnalyticRing2D);
  
private:
  //Center
  float center[2];
  //Central radius
  float radius;
  //Thickness of the ring
  float thickness;
  
public:
  /**
   *  Creates a 2D analytic ring.
   *  @param x Component of the center. Default 50.0.
   *  @param y Component of the center. Default 50.0.
   *  @param r Central radius. Default 30.0.
   *  @param g Thickness of the ring. Default 2.0.
   */
  AnalyticRing2D(float x = 50.0, float y = 50.0, float r = 30.0, float g = 2.0);
  
  ~AnalyticRing2D();

  /**
   *  Operator () redefinition. Evaluates if a point is inside the ring.
   *  @param x Component of the point.
   *  @param y Component of the point.
   *  @param z Unused.
   *  @return double A double number that represents the value of the point in the
   *  ring image.
   */
  double operator () (const double& x, const double& y, const double& z) const;
  
  /**
   *  Get the center of the ring.
   *  @return float* A pointer to a float vector with the two components of the
   *  center.
   */
  float* getCenter();
  
  /**
   *  Set the center of the ring.
   *  @param x Component of the center.
   *  @param y Component of the center.
   */
  void setCenter(float x, float y);
  
  /**
   *  Get the central radius of the ring.
   *  @return float The value of the radius.
   */
  float getRadius();
  
  /**
   *  Set the central radius of the ring.
   *  @param r The new value for the radius.
   */
  void setRadius(float r);
  
  /**
   *  Get the thickness of the ring.
   *  @return float The value of the thickness.
   */
  float getThickness();
  
  /**
   *  Set the thickness of the ring.
   *  @param g The new value for the thickness.
   */
  void setThickness(float g);
  
};

#endif
