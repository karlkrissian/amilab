/*
 *  AnalyticCylinder.cpp
 *  AMILab
 */

#include "AnalyticCylinder.h"
#include <math.h>

//---------------------------------------------------
//AnalyticCylinder methods
//---------------------------------------------------
//Constructor
AnalyticCylinder::AnalyticCylinder(float r, float xd, float yd, float zd)
{
  radius = r;
  Xdir   = xd;
  Ydir   = yd;
  Zdir   = zd;
}

//Destructor
AnalyticCylinder::~AnalyticCylinder(){}

//Redefinition of the parenthesis operator
double AnalyticCylinder::operator () (const double& x, const double& y, 
                                      const double& z) const
{  
  float mod   = sqrt(Xdir*Xdir + Ydir*Ydir + Zdir*Zdir);
  float xaxis = Xdir/mod;
  float yaxis = Ydir/mod;
  float zaxis = Zdir/mod;
  int dim     = (radius>10) ? (int) (4*radius) : 40;
  int center  = dim/2;
  
  float pqx = x - center;
  float pqy = y - center;
  float pqz = z - center; 

  float vx = pqy*zaxis - pqz*yaxis;
  float vy = pqz*xaxis - pqx*zaxis;
  float vz = pqx*yaxis - pqy*xaxis;
  
  return radius*radius - (vx*vx + vy*vy +vz*vz);
}

//Set and get radius methods
void AnalyticCylinder::setRadius(float r)
{
  radius = r;
}
float AnalyticCylinder::getRadius()
{
  return radius;
}

//Set and get x direction methods
void AnalyticCylinder::setXdir(float xd)
{
  Xdir = xd;
}
float AnalyticCylinder::getXdir()
{
  return Xdir;
}

//Set and get y direction methods
void AnalyticCylinder::setYdir(float yd)
{
  Ydir = yd;
}
float AnalyticCylinder::getYdir()
{
  return Ydir;
}

//Set and get z direction methods
void AnalyticCylinder::setZdir(float zd)
{
  Zdir = zd;
}
float AnalyticCylinder::getZdir()
{
  return Zdir;
}
