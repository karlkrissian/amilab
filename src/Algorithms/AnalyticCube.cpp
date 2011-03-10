/*
 *  AnalyticCube.cpp
 *  AMILab
 */

#include "AnalyticCube.h"
#include <math.h>
#include <iostream.h>
using namespace std;

//---------------------------------------------------
//AnalyticCube methods
//---------------------------------------------------
//Constructor
AnalyticCube::AnalyticCube(float dx, float dy, float dz, float xc, float yc, 
                           float zc)
{
  dimx      = dx;
  dimy      = dy;
  dimz      = dz;
  center[0] = xc;
  center[1] = yc;
  center[2] = zc;
}

//Destructor
AnalyticCube::~AnalyticCube(){}

//Redefinition of the parenthesis operator
double AnalyticCube::operator () (const double& x, const double& y, 
                                  const double& z) const
{
  //Compute the distance between the given point and the cube center
//  float xd = fabs(x - center[0]);
//  float yd = fabs(y - center[1]);
//  float zd = fabs(z - center[2]);
//  
//  //Compute the distance limits (x, y and z)
//  float xm = dimx/2;
//  float ym = dimy/2;
//  float zm = dimz/2;
//  
//  //Return if the point is inside the cube or not
//  if ((xd <= xm) && (yd <= ym) && (zd <= zm))
//    cout << "Dentro. X = " << x << " Y = " << y << " Z = " << z << endl;
////  else 
////    cout << "Fuera. X = " << x << " Y = " << y << " Z = " << z  << endl;
//  return ((xd <= xm) && (yd <= ym) && (zd <= zm));
  float xmin = center[0] - dimx/2;
  float xmax = center[0] + dimx/2;
  float ymin = center[1] - dimy/2;
  float ymax = center[1] + dimy/2;
  float zmin = center[2] - dimz/2;
  float zmax = center[2] + dimz/2;
  
  return ((x<=xmax && x>=xmin) && (y<=ymax && y>=ymin) && (z<=zmax && z>=zmin));
}
  
void AnalyticCube::setDimX(float dx)
{
  dimx = dx;
}
  
float AnalyticCube::getDimX()
{
  return dimx;
}
  
void AnalyticCube::setDimY(float dy)
{
  dimy = dy;
}
  
float AnalyticCube::getDimY()
{
  return dimy;
}
  
void AnalyticCube::setDimZ(float dz)
{
  dimz = dz;
}
  
float AnalyticCube::getDimZ()
{
  return dimz;
}
  
void AnalyticCube::setCenter(float xc, float yc, float zc)
{
  center[0] = xc;
  center[1] = yc;
  center[2] = zc;
}
  
float* AnalyticCube::getCenter()
{
  return center;
}
