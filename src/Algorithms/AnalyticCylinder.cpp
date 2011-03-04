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


//inline int DentroCilindro (float qx, float qy, float qz)
///* calculo si el el punto (qx,qy,qz) está dentro del cilindro.
//  Para ello calculo la distancia del punto al eje del cilindro.
//  Si es menor que el radio estoy dentro */
//{
//float pqx = qx - CENTRO;
//float pqy = qy - CENTRO;
//float pqz = qz - CENTRO; 
//float vx, vy, vz;
//float dist;
//
//vx = pqy*EJEZ - pqz*EJEY;
//vy = pqz*EJEX - pqx*EJEZ;
//vz = pqx*EJEY - pqy*EJEX;
//dist = vx*vx + vy*vy +vz*vz;
//return ((dist>=RADIO*RADIO)?0:1);
//}




//Redefinition of the parenthesis operator
double AnalyticCylinder::operator () (const double& x, const double& y, 
                                      const double& z) const
{
  //return 0.0;
  
  //Usando lo de la función de Agustín
  
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
