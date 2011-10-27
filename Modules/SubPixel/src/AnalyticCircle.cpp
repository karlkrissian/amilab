/*
 *  AnalyticCircle.cpp
 *  AMILab
 */

#include "AnalyticCircle.h"

//---------------------------------------------------
//AnalyticCircle methods
//---------------------------------------------------
//Constructor
AnalyticCircle::AnalyticCircle(float x, float y, float r)
{
  center[0] = x; center[1] = y;
  radius = r;
}

//Destructor
AnalyticCircle::~AnalyticCircle(){}

//Redefinition of operator parenthesis
double AnalyticCircle::operator () (const double& x, const double& y, const double& z) const
{
  double x1 = x - center[0];
  double y1 = y - center[1];
  return radius*radius - (x1*x1 + y1*y1);
}

//Set and get center methods
void AnalyticCircle::setCenter(float c1, float c2)
{
  center[0] = c1;
  center[1] = c2;
}
float* AnalyticCircle::getCenter()
{
  return center;
}

//Set and get radius methods
void AnalyticCircle::setRadius(float r)
{
  radius = r;
}
float AnalyticCircle::getRadius()
{
  return radius;
}

