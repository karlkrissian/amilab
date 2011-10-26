/*
 *  AnalyticRing2D.cpp
 *  AMILab
 */

#include "AnalyticRing2D.h"
#include <cmath>

//---------------------------------------------------
//AnalyticRing2D methods
//---------------------------------------------------
//Constructor
AnalyticRing2D::AnalyticRing2D(float x, float y, float r, float g)
{
  center[0] = x;
  center[1] = y;
  radius    = r;
  thickness = g;
}

//Destructor
AnalyticRing2D::~AnalyticRing2D(){}

//Redefinition of the operator parenthesis
double AnalyticRing2D::operator () (const double& x, const double& y, 
                                              const double& z) const
{
  double d;
  
  //Calculate distance to the ring center
  d = sqrt((x-center[0])*(x-center[0]) + (y-center[1])*(y-center[1]));
  
  //If is between radius and radius+thickness is inside. Else, is outside of the 
  //ring
  return (d>radius && d<radius+thickness) ? 1 : -1;
}

//Get and set center methods
float* AnalyticRing2D::getCenter()
{
  return center;
}

void AnalyticRing2D::setCenter(float x, float y)
{
  center[0] = x;
  center[1] = y;
}

//Get and set radius methods
float AnalyticRing2D::getRadius()
{
  return radius;
}

void AnalyticRing2D::setRadius(float r)
{
  radius = r;
}

//Get and set thickness methods
float AnalyticRing2D::getThickness()
{
  return thickness;
}

void AnalyticRing2D::setThickness(float g)
{
  thickness = g;
}
