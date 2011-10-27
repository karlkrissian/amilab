/*
 *  AnalyticSphere.cpp
 *  AMILab
 */

#include "AnalyticSphere.h"

//---------------------------------------------------
//AnalyticSphere methods
//---------------------------------------------------
//Constructor
AnalyticSphere::AnalyticSphere(float x, float y, float z, float r)
{
  center[0] = x; center[1] = y; center[2] = z;
  radius = r;
}

//Destructor
AnalyticSphere::~AnalyticSphere(){}

//Redefinition of the parenthesis operator 
double AnalyticSphere::operator () (const double& x, const double& y, const double& z) const
{
  double x1 = x - center[0]; 
  double y1 = y - center[1];
  double z1 = z - center[2];
  return radius*radius - (x1*x1 + y1*y1 + z1*z1);
}

//Set and get center methods
void AnalyticSphere::setCenter(float c1, float c2, float c3)
{
  center[0] = c1;
  center[1] = c2;
  center[2] = c3;
}
float* AnalyticSphere::getCenter()
{
  return center;
}

//Set and get radius methods
void AnalyticSphere::setRadius(float r)
{
  radius = r;
}
float AnalyticSphere::getRadius()
{
  return radius;
}
