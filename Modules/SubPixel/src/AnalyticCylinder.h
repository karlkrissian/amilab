/*
 *  AnalyticCylinder.h
 *  AMILab
 */

#ifndef _AnalyticCylinder_h_
#define _AnalyticCylinder_h_

#include "DefineClass.hpp"
#include "AnalyticFunctionBase.h"

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
 *  AnalyticCylinder class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Agustín Trujillo Pino (agustin@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticCylinder : public AnalyticFunctionBase {
  
  DEFINE_CLASS(AnalyticCylinder);
  
private:
  //Cylinder radius
  float radius;
  //Cylinder X direction
  float Xdir;
  //Cylinder Y direction
  float Ydir;
  //Cylinder Z direction
  float Zdir;
  
  
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
  
  /**
   *  Operator () redefinition. Evaluates if a point is inside the cylinder.
   *  @param x Component of the point.
   *  @param y Component of the point.
   *  @param z Component of the point.
   *  @return double A double number that represents the value of the point in
   *  the cylinder image.
   */
  double operator () (const double& x, const double& y, const double& z) const;
  
  /**
   *  Set the radius of the cylinder.
   *  @para r The new value for the radius of the cylinder.
   */
  void setRadius(float r);
  
  /**
   *  Get the radius of the cylinder.
   *  @return float The radius value. 
   */
  float getRadius();
  
  /**
   *  Set the x direction of the cylinder.
   *  @param xd The new value for the x direction.
   */
  void setXdir(float xd);
  
  /**
   *  Get the x direction of the cylinder.
   *  @return float The x direction value.
   */
  float getXdir();
  
  /**
   *  Set the y direction of the cylinder.
   *  @param yd The new value for the y direction.
   */
  void setYdir(float yd);
  
  /**
   *  Get the y direction of the cylinder.
   *  @return float The y direction value.
   */
  float getYdir();
  
  /**
   *  Set the z direction of the cylinder.
   *  @param zd The new value for the z direction.
   */
  void setZdir(float zd);
  
  /**
   *  Get the z direction of the cylinder.
   *  @return float The z direction value.
   */
  float getZdir();

  /// X coordinate of the center 
  AddSetGetVar(center_x,float)
  /// Y coordinate of the center 
  AddSetGetVar(center_y,float)
  /// Z coordinate of the center 
  AddSetGetVar(center_z,float)
  
};

#endif
