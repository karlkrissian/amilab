/*
 *  AnalyticPlane.h
 *  AMILab
 */

#ifndef _AnalyticPlane_h_
#define _AnalyticPlane_h_

#include "DefineClass.hpp"
#include "AnalyticFunctionBase.h"

/**
 *  AnalyticPlane class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Agustín Trujillo Pino (agustin@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticPlane : public AnalyticFunctionBase {
  
  DEFINE_CLASS(AnalyticPlane);
  
private:
//  //Plane Nx normal
//  double Nx;
//  //Plane Ny normal
//  double Ny;
//  //Plane Nz normal
//  double Nz;
//  //Separation
//  int    sep;
  float x1, y1, z1;
  float x2, y2, z2;
  float x3, y3, z3;
  
public:
  /**
   *  Create an analytic plane.
   *  @param X normal. Default 0.
   *  @param Y normal. Default 1.
   *  @param Z normal. Default 0.
   *  @param Separation of the plane. Default 0.
   */
//  AnalyticPlane(double normX = 0, double normY = 1, double normZ = 0, 
//                int separation = 0);
  AnalyticPlane(float a1 = 25, float b1 = 0, float c1 = 0,
                float a2 = 0,  float b2 = 25,float c2 = 0,
                float a3 = 0,  float b3 = 0, float c3 = 25);
  
  ~AnalyticPlane();
  
  /**
   *  Operator () redefinition. Evaluates if a point is inside the plane.
   *  @param x Component of the point.
   *  @param y Component of the point.
   *  @param z Component of the point.
   *  @return A double number that represents the value of the point in the plane.
   */
  double operator () (const double& x, const double& y, const double& z) const;
  
  /**
   *  Set the normals of the plane.
   *  @param X normal.
   *  @param Y normal.
   *  @param Z normal.
   */
  //void setNormals(double normX, double normY, double normZ);
  void setP1(float x, float y, float z);
  void getP1(float &x, float &y, float &z);
  void setP2(float x, float y, float z);
  void getP2(float &x, float &y, float &z);
  void setP3(float x, float y, float z);
  void getP3(float &x, float &y, float &z);
  /**
   *  Get the normals of the plane in the parameters.
   *  @param Variable for X normal.
   *  @param Variable for Y normal.
   *  @param Varialbe for Z normal.
   */
  //void getNormals(double &normX, double &normY, double &normZ);
  
  /**
   *  Set the separation of the plane.
   *  @param The separation value.
   */
  //void setSeparation(int separation);
  
  /**
   *  Get the separation of the plane.
   *  @return The value of the separation of the plane.
   */
  //int getSeparation();
  
};

#endif
