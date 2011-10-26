/*
 *  AnalyticStraightVessel2D.h
 *  AMILab
 */

#ifndef _AnalyticStraightVessel2D_h_
#define _AnalyticStraightVessel2D_h_

#include "DefineClass.hpp"
#include "AnalyticFunctionBase.h"

/**
 *  AnalyticStraightVessel2D class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Agustín Trujillo Pino (agustin@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticStraightVessel2D : public AnalyticFunctionBase {
  DEFINE_CLASS(AnalyticStraightVessel2D);

private:
  //Center of the vessel
  float center[2];
  //Thickness
  float thickness;
  //Angle 
  float angle;
  //Components of the normal
  double nx;
  double ny;

public:
  /**
   *  Creates a 2D analytic straight vessel.
   *  @param x Component of the center. Default 50.0.
   *  @param y Component of the center. Default 50.0.
   *  @param g Thickness of the vessel. Default 4.0.
   *  @param alpha Angle of the vessel. Default 20.0.
   */
  AnalyticStraightVessel2D(float x = 50.0, float y = 50.0, float g = 4.0, 
                           float alpha = 20.0);
  
  ~AnalyticStraightVessel2D();

  /**
   *  Operator () redefinition. Evaluates if a point is inside the vessel.
   *  @param x Component of the point.
   *  @param y Component of the point.
   *  @param z Unused.
   *  @return double A double number that represents the value of the point in the
   *  vessel image.
   */
  double operator () (const double& x, const double& y, const double& z) const;
  
  /**
   *  Get the center of the vessel.
   *  @return float* A pointer to a float vector with the two components of the
   *  center.
   */
  float* getCenter();
  
  /**
   *  Set the center of the vessel.
   *  @param x Component of the center.
   *  @param y Component of the center.
   */
  void setCenter(float x, float y);
  
  /**
   *  Get the thickness of the vessel.
   *  @return float The value of the thickness.
   */
  float getThickness();
  
  /**
   *  Set the thickness of the vessel.
   *  @param g The new thickness value.
   */
  void setThickness(float g);
  
  /**
   *  Get the angle of the vessel.
   *  @return float The value of the angle.
   */
  float getAngle();
  
  /**
   *  Set the angle of the vessel.
   *  @param alpha The new value of the angle.
   */
  void setAngle(float alpha);
};

#endif
