/*
 *  AnalyticPlane.cpp
 *  AMILab
 */

#include "AnalyticPlane.h"

//---------------------------------------------------
//AnalyticPlane methods
//---------------------------------------------------
//Constructor
//AnalyticPlane::AnalyticPlane(double normX, double normY, double normZ, 
//                             int separation)
//{
//  Nx  = normX;
//  Ny  = normY;
//  Nz  = normZ;
//  sep = separation;
//}

AnalyticPlane::AnalyticPlane(float a1, float b1, float c1,
                             float a2, float b2, float c2,
                             float a3, float b3, float c3)
{
  x1 = a1; y1 = b1; z1 = c1;
  x2 = a2; y2 = b2; z2 = c2;
  x3 = a3; y3 = b3; z3 = c3;
}

//Destructor
AnalyticPlane::~AnalyticPlane(){}

//#define DentroRampa3D(x,y,z) ((x)*EJEX+(y)*EJEY+(z)*EJEZ>=CENTROX*EJEX+CENTROY*EJEY+CENTROZ*EJEZ)?0:1
//Redefinition of the parenthesis operator
double AnalyticPlane::operator () (const double& x, const double& y, 
                                   const double&z) const
{
  //Supongo tres puntos A B y C (que son x1,y1,z1 x2,y2,z2 & x3,y3,z3 respectivamente)
  //Vector AB
  float AB1 = x2 - x1; 
  float AB2 = y2 - y1;
  float AB3 = z2 - y1;
  //Vector AC
  float AC1 = x3 - x1;
  float AC2 = y3 - y1;
  float AC3 = z3 - z1;
  
  //Producto vectorial: N =  AB x AC
  float N1 = AB2*AC3 - AC2*AB3;
  float N2 = -1 * (AB1*AC3 - AC1*AB3);
  float N3 = AB1*AC2 - AC1*AB2;
  
  //Ahora mi ecuación será A * N:
  float xp  = N1 * x;
  float yp  = N2 * y;
  float zp  = N3 * z;
  float ind = N1*-x1 + N2*-y1 + N3*-z1;
  
  //Devolvemos el valor de la ecuación del plano
  if (xp + yp + zp + ind == 0)
    return 1.0;
  else 
    return -1.0;
}


void AnalyticPlane::setP1(float x, float y, float z)
{
  x1 = x;
  y1 = y;
  z1 = z;
}
void AnalyticPlane::getP1(float &x, float &y, float &z)
{
  x = x1;
  y = y1;
  z = z1;
}
void AnalyticPlane::setP2(float x, float y, float z)
{
  x2 = x;
  y2 = y;
  z2 = z; 
}
void AnalyticPlane::getP2(float &x, float &y, float &z)
{
  x = x2;
  y = y2;
  z = z2;
}
void AnalyticPlane::setP3(float x, float y, float z)
{
  x3 = x;
  y3 = y;
  z3 = z;
}
void AnalyticPlane::getP3(float &x, float &y, float &z)
{
  x = x3;
  y = y3;
  z = z3;
}


//Set and get normals methods
//void AnalyticPlane::setNormals(double normX, double normY, double normZ)
//{
//  Nx = normX;
//  Ny = normY;
//  Nz = normZ;
//}
//void AnalyticPlane::getNormals(double &normX, double &normY, double &normZ)
//{
//  normX = Nx;
//  normY = Ny;
//  normZ = Nz;
//}

//Set and get separation methods
//void AnalyticPlane::setSeparation(int separation)
//{
//  sep = separation;
//}
//int AnalyticPlane::getSeparation()
//{
//  return sep;
//}
