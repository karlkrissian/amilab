/*
 *  AnalyticTorus.cpp
 *  AMILab
 */

#include "AnalyticTorus.h"
#include <cmath>

//---------------------------------------------------
//AnalyticTorus methods
//---------------------------------------------------
//Constructor
AnalyticTorus::AnalyticTorus(float x, float y, float z,
                float r, float R)
{
  center[0] = x; center[1] = y; center[2] = z;
  rmin = r;
  rmax = R;
}

//Destructor
AnalyticTorus::~AnalyticTorus(){}

//Redefinition of the operator parenthesis
double AnalyticTorus::operator () (const double& x, const double& y, const double& z) const
{
  double x1 = x - center[0];
  double y1 = y - center[1];
  double z1 = z - center[2];
  double tmp = rmax-sqrt(x1*x1+y1*y1);
  return rmin*rmin - (tmp*tmp + z1*z1); 
}

//Set and get center methods
void AnalyticTorus::setCenter(float c1, float c2, float c3)
{
  center[0] = c1;
  center[1] = c2;
  center[2] = c3;
}

float* AnalyticTorus::getCenter()
{
  return center;
}

//Set and get rmin methods
void AnalyticTorus::set_rmin(float rm)
{
  rmin = rm;
}

float AnalyticTorus::get_rmin()
{
  return rmin;
}

//Set and get rmax methods
void AnalyticTorus::set_rmax(float rM)
{
  rmax = rM;
}

float AnalyticTorus::get_rmax()
{
  return rmax;
}
