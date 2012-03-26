/*
 *  AnalyticCube.h
 *  AMILab
 */

#ifndef _AnalyticCube_h_
#define _AnalyticCube_h_

#include "DefineClass.hpp"

#include "AnalyticFunctionBase.h"

/**
 *  AnalyticCube class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Agustín Trujillo Pino (agustin@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticCube : public AnalyticFunctionBase {
  
  DEFINE_CLASS(AnalyticCube);
  
private:
  //x, y and z size
  float dimx;
  float dimy;
  float dimz;
  //Cube center
  float center[3];
  
public:
  /**
   *  Create an analytic cube.
   *  @param dx The size on X dimension.
   *  @param dy The size on Y dimension.
   *  @param dz The size on Z dimension.
   *  @param xc X coordinate of the center.
   *  @param yc Y coordinate of the center.
   *  @param zc Z coordinate of the center.
   */

  AnalyticCube(float dx = 10, float dy = 10, float dz = 10, float xc = 50, 
               float yc = 50, float zc = 50);
  
  ~AnalyticCube();
  
  /**
   *  Operator () redefinition. Evaluates if a point is inside the cube.
   *  @param x Component of the point.
   *  @param y Component of the point.
   *  @param z Component of the point.
   *  @return A double number that represents the value of the point in the cube.
   */
  double operator () (const double& x, const double& y, const double& z) const;
  
  /**
   *  Set the size of the x dimension.
   *  @param dx The new x size.
   */
  void setDimX(float dx);
  
  /**
   *  Get the size of the x dimension.
   *  @return The float value of the x size.
   */
  float getDimX();
  
  /**
   *  Set the size of the y dimension.
   *  @param The new y size.
   */
  void setDimY(float dy);
  
  /**
   *  Get the size of the y dimension.
   *  @return The float value of the y size.
   */
  float getDimY();
  
  /**
   *  Set the size of the z dimension.
   *  @param The new z size.
   */
  void setDimZ(float dz);
  
  /**
   *  Get the size of the z dimension.
   *  @return The float value of the z size.
   */
  float getDimZ();
  
  /**
   *  Set the center of the cube.
   *  @param xc X coordinate of the center.
   *  @param yc Y coordinate of the center.
   *  @param zc Z coordinate of the center.
   */
  void setCenter(float xc, float yc, float zc);
  
  /**
   *  Get the centor of the cube.
   *  @return A pointer to float vector with the three components of the center.
   */
  float* getCenter();

};

#endif
