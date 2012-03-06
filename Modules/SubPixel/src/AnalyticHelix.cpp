/*
 *  AnalyticHelix.cpp
 *  AMILab
 */

#include "AnalyticHelix.h"
#include <cmath>


//Destructor
AnalyticHelix::~AnalyticHelix(){}

//Redefinition of the operator parenthesis
double AnalyticHelix::operator () (const double& x, const double& y, const double& z) const
{
  double x1 = x - center[0];
  double y1 = y - center[1];
  double z1 = z - center[2];
  double angle = z1*rotation_coeff;

  double d1 = x1*cos(angle)+y1*sin(angle);
  double d2 = sqrt(x1*x1+y1*y1);

  if ((abs(d1)<=thickness/2.0)&&(d2<radius)) 
  {
    return 1;
  } else {
    return -1;
  }
}

//Set and get center methods
void AnalyticHelix::setCenter(float c1, float c2, float c3)
{
  center[0] = c1;
  center[1] = c2;
  center[2] = c3;
}

