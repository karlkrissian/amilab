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
  Radius = r;
  Xdir   = xd;
  Ydir   = yd;
  Zdir   = zd;
  Elliptic = false;
  
  EllipseXdir = 1;
  EllipseYdir = 0;
  EllipseZdir = 0;
  RadiusRatio = 0.5;
}

//Destructor
AnalyticCylinder::~AnalyticCylinder(){}

//Redefinition of the parenthesis operator
double AnalyticCylinder::operator () (const double& x, const double& y, 
                                      const double& z) const
{  
  if (!Elliptic) {
    float mod   = sqrt(Xdir*Xdir + Ydir*Ydir + Zdir*Zdir);
    float xaxis = Xdir/mod;
    float yaxis = Ydir/mod;
    float zaxis = Zdir/mod;
    int dim     = (Radius>10) ? (int) (4*Radius) : 40;
    
    float pqx = x - Center_x;
    float pqy = y - Center_y;
    float pqz = z - Center_z; 

    float vx = pqy*zaxis - pqz*yaxis;
    float vy = pqz*xaxis - pqx*zaxis;
    float vz = pqx*yaxis - pqy*xaxis;
    
    return Radius*Radius - (vx*vx + vy*vy +vz*vz);
  } else {
    // M(x,y,z), O(center_x,center_y,center_z), v(Xdir,Ydir,Zdir)
    // 1. project OM orthogonal to v
    double OMx = x-Center_x;
    double OMy = y-Center_y;
    double OMz = z-Center_z;
    
    double dir2 = Xdir*Xdir + Ydir*Ydir + Zdir*Zdir;

    if (dir2<1E-10) 
      // axis too small ...
      return 0.0;
    // get scalar product
    double ps = OMx*Xdir+OMy*Ydir+OMz*Zdir;
    
    // projection
    double OMpx = OMx-ps*Xdir/dir2;
    double OMpy = OMy-ps*Ydir/dir2;
    double OMpz = OMz-ps*Zdir/dir2;
    
    // split in 2 coordinates: vectorial product
    double ellipsedir2x = Ydir*EllipseZdir-Zdir*EllipseYdir;
    double ellipsedir2y = Zdir*EllipseXdir-Xdir*EllipseZdir;
    double ellipsedir2z = Xdir*EllipseYdir-Ydir*EllipseXdir;
    // normalize
    double norm = sqrt( ellipsedir2x*ellipsedir2x+
                        ellipsedir2y*ellipsedir2y+
                        ellipsedir2z*ellipsedir2z);
    ellipsedir2x /=norm;
    ellipsedir2y /=norm;
    ellipsedir2z /=norm;
    
    double ellipsedir1x = ellipsedir2y*Zdir-ellipsedir2z*EllipseYdir;
    double ellipsedir1y = ellipsedir2z*Xdir-ellipsedir2x*EllipseZdir;
    double ellipsedir1z = ellipsedir2x*Ydir-ellipsedir2y*EllipseXdir;
    // normalize
    norm = sqrt(  ellipsedir1x*ellipsedir1x+
                  ellipsedir1y*ellipsedir1y+
                  ellipsedir1z*ellipsedir1z);
    ellipsedir1x /=norm;
    ellipsedir1y /=norm;
    ellipsedir1z /=norm;
    
    double c1 = OMpx*ellipsedir1x+OMpy*ellipsedir1y+OMpz*ellipsedir1z;
    double c2 = OMpx*ellipsedir2x+OMpy*ellipsedir2y+OMpz*ellipsedir2z;
    c2 /= RadiusRatio;
    return Radius*Radius- (c1*c1+c2*c2);
  }
}

