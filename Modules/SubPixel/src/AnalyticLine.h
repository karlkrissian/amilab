/*
 *  AnalyticLine.h
 *  AMILab
 */

#ifndef _AnalyticLine_h_
#define _AnalyticLine_h_

#include "DefineClass.hpp"
#include "AnalyticFunctionBase.h"

/**
 *  AnalyticLine class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Agustín Trujillo Pino (agustin@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticLine : public AnalyticFunctionBase {
  
  DEFINE_CLASS(AnalyticLine);
  
private:
  /** Normal of the line, cut point on 'y' axis and angle */
  float m[2], _n, angle, xc;
  
public:
  /**
   *  Creates an analytic line.
   *  @param angle Line angle. Default 45.0.
   *  @param n Cut point value. Default 50.0.
   */
  AnalyticLine(float angle = 45.0, float n = 50.0, float xcen = 50);
  
  ~AnalyticLine();
  
  /**
   *  Operator () redefinition. Evaluates if a point is inside the line.
   *  @param x Component of the point.
   *  @param y Component of the point.
   *  @param z Unused.
   *  @return double A double number that represents the value of the point in the
   *  line image.
   */
  double operator () (const double& x, const double& y, const double& z) const;
  
  /**
   *  Set line angle.
   *  @param alpha The new angle value.
   */
  void setAngle(float alpha);
  
  /**
   *  Get line normal.
   *  @return float The value of the angle.
   */
  float getAngle();
  
  /**
   *  Set y axis cut point value.
   *  @param n Point value on y axis.
   */
  void set_n(float n);
  
  /**
   *  Get y axis cut point value.
   *  @return float The cut point value.
   */
  float get_n();
  
  void setXC(float xcen);
  float getXC();
};

#endif

