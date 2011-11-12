/*
 *  AnalyticStraightVessel2D.cpp
 *  AMILab
 */

#include "AnalyticStraightVessel2D.h"
#include <cmath>
#ifndef M_PI
# define M_PI           3.14159265358979323846  /* pi */
#endif

//---------------------------------------------------
//AnalyticStraightVessel2D methods
//---------------------------------------------------
//Constructor
AnalyticStraightVessel2D::AnalyticStraightVessel2D(float x, float y, float g, 
                                                   float alpha)
{
  center[0] = x;
  center[1] = y;
  thickness = g;
  setAngle(alpha);
}

//Destructor
AnalyticStraightVessel2D::~AnalyticStraightVessel2D(){}

//Redefinition of the parenthesis operator
double AnalyticStraightVessel2D::operator () (const double& x, const double& y, 
                                              const double& z) const
{
  double ux = -ny;
  double uy = nx;
  double vx = x - center[0];
  double vy = y - center[1];
  double d = fabs(ux*vy-vx*uy) / sqrt(ux*ux+uy*uy);
  //Inside or outside of the vessel
  return ((d>thickness/2) ? -1 : 1);
}

//Get and set center methods
float* AnalyticStraightVessel2D::getCenter()
{
  return center;
}

void AnalyticStraightVessel2D::setCenter (float x, float y)
{
  center[0] = x;
  center[1] = y;
}

//Get and set thickness methods
float AnalyticStraightVessel2D::getThickness()
{
  return thickness;
}

void AnalyticStraightVessel2D::setThickness(float g)
{
  thickness = g;
}

//Get and set angle methods
float AnalyticStraightVessel2D::getAngle()
{
  return angle;
}

void AnalyticStraightVessel2D::setAngle(float alpha)
{
  angle = alpha;
  //Calculate normal components based on angle
  if (alpha<45)
  {
    nx=tan(alpha*M_PI/180);
    ny=1.0;
  }
  else
  {
    if (alpha<90)
    {
      ny=tan((90-alpha)*M_PI/180);
      nx=1.0;
    }
    else
    {
      if (alpha<135)
      {
        ny=-tan((alpha-90)*M_PI/180);
        nx=1.0;
      }
      else
      {
        if (alpha<180)
        {
          nx=tan((180-alpha)*M_PI/180);
          ny=-1.0;
        }
        else
        {
          if (alpha<225) 
          {
            nx=-tan((alpha-180)*M_PI/180);
            ny=-1.0;
          }
          else
          {
            if (alpha<270) 
            {
              ny=-tan((270-alpha)*M_PI/180);
              nx=-1.0;
            }
            else
            {
              if (alpha<315) 
              {
                ny=tan((alpha-270)*M_PI/180);
                nx=-1.0;
              }
              else
              {
                nx=-tan((360-alpha)*M_PI/180);
                ny=1.0;
              }
            }
          }
        }
      }
    }
  }
}

