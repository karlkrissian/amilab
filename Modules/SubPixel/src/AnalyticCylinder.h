/*
 *  AnalyticCylinder.h
 *  AMILab
 */

#ifndef _AnalyticCylinder_h_
#define _AnalyticCylinder_h_

#include "DefineClass.hpp"

#include "AnalyticFunctionBase.h"

#undef AddSetGetVar
#define AddSetGetVar( name, type) \
  type  name; \
  void set##name( type _arg) \
  { \
    this->name = _arg; \
  };  \
  type get##name() \
  { \
    return this->name; \
  };


/**
 *  AnalyticCylinder class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Agustín Trujillo Pino (agustin@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticCylinder : public AnalyticFunctionBase {
  
  DEFINE_CLASS(AnalyticCylinder);
  
private:

  
  
public:
  /**
   *  Creates an analytic cylinder.
   *  @param r The radius of the cylinder. Default 25.0.
   *  @param xd The x direction of the cylinder. Default 0.0.
   *  @param yd The y direction of the cylinder. Default 0.0.
   *  @param zd The z direction of the cylinder. Default 9.0.
   */
  AnalyticCylinder(float r = 25.0, float xd = 0.0, float yd = 0.0, 
                   float zd = 9.0);
  
  ~AnalyticCylinder();
  
  /// X coordinate of the center 
  AddSetGetVar(Center_x,float)
  /// Y coordinate of the center 
  AddSetGetVar(Center_y,float)
  /// Z coordinate of the center 
  AddSetGetVar(Center_z,float)

  /// Cylinder radius
  AddSetGetVar(Radius,float)

  /// Cylinder axis direction in X
  AddSetGetVar(Xdir,float)
  /// Cylinder axis direction in Y
  AddSetGetVar(Ydir,float)
  /// Cylinder axis direction in Z
  AddSetGetVar(Zdir,float)

  /// Elliptic sections
  AddSetGetVar(Elliptic,bool)
  
  /// if elliptic section: 2nd axis and radius
  /// Ellipse main axis direction in X
  AddSetGetVar(EllipseXdir,float)
  /// Ellipse main axis direction in Y
  AddSetGetVar(EllipseYdir,float)
  /// Ellipse main axis direction in Z
  AddSetGetVar(EllipseZdir,float)

  /// Ellipse radius ratio (small rad)/(big rad)
  AddSetGetVar(RadiusRatio,float)

  /**
   *  Operator () redefinition. Evaluates if a point is inside the cylinder.
   *  @param x Component of the point.
   *  @param y Component of the point.
   *  @param z Component of the point.
   *  @return double A double number that represents the value of the point in
   *  the cylinder image.
   */
  double operator () (const double& x, const double& y, const double& z) const;
    
};

#endif
