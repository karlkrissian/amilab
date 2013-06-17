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
  if (!centerline_circle) {
    double angle = z1*rotation_coeff;

    double d1 = x1*cos(angle)+y1*sin(angle);
    double d2 = sqrt(x1*x1+y1*y1);

    double current_radius = radius;
    if (radius_change_amplitude>0) {
      current_radius += radius_change_amplitude*sin(z1/radius_change_period*2*PI);
    }

    if (dissection)
      return ((d2<current_radius)&&(abs(d1)>thickness/2.0)?1:-1);
    else
      if (containing_object)
        return ((d2<current_radius)?1:-1);
      else
        if ((abs(d1)<=thickness/2.0)&&(d2<current_radius)) 
        {
          return 1;
        } else {
          return -1;
        }
  } else {
    
    double center_angle;
    if (z1==0) {
      if (y1>0)
        center_angle= PI/2;
      else
        center_angle= -PI/2;
    } else {
      if (z1>0)
        center_angle= atan(y1/z1);
      else
        center_angle= atan(y1/z1)+PI;
    }
    double center_dist = center_angle*centerline_radius;
    double angle = center_dist*rotation_coeff;
    
    double section_x1 = x1;
    double section_y1 = centerline_radius - sqrt(y1*y1+z1*z1);

    double d1 = section_x1*cos(angle)+section_y1*sin(angle);
    double d2 = sqrt(section_x1*section_x1+section_y1*section_y1);

    double current_radius = radius;
    if (radius_change_amplitude>0) {
      current_radius += radius_change_amplitude*sin(z1/radius_change_period*2*PI);
    }

    if (dissection)
      return ((d2<current_radius)&&(abs(d1)>thickness/2.0)?1:-1);
    else
      if (containing_object)
        return ((d2<current_radius)?1:-1);
      else
        if ((abs(d1)<=thickness/2.0)&&(d2<current_radius)) 
        {
          return 1;
        } else {
          return -1;
        }
  }
}

//Set and get center methods
void AnalyticHelix::setCenter(float c1, float c2, float c3)
{
  center[0] = c1;
  center[1] = c2;
  center[2] = c3;
}

