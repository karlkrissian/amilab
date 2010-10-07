/*
 *  AnalyticLine.cpp
 *  AMILab
 */

#include "AnalyticLine.h"
#include <cmath>

//---------------------------------------------------
//AnalyticLine methods
//---------------------------------------------------
//Constructor
AnalyticLine::AnalyticLine(float alpha, float n)
{
  _n   = n;
  setAngle(alpha);
}

//Destructor
AnalyticLine::~AnalyticLine(){}

//Redefinition of the operator parenthesis
double AnalyticLine::operator () (const double& x, const double& y, const double& z) const
{
  double xaux = x-50;
  return m[0]*xaux + m[1]*(y - _n);
}

//Set and get angle methods
void AnalyticLine::setAngle(float alpha)
{
  angle = alpha;
  //Calculate normal components based on angle
  if (alpha<45)
  {
    m[0]=tan(alpha*M_PI/180);
    m[1]=1.0;
  }
  else
  {
    if (alpha<90)
    {
      m[1]=tan((90-alpha)*M_PI/180);
      m[0]=1.0;
    }
    else
    {
      if (alpha<135)
      {
        m[1]=-tan((alpha-90)*M_PI/180);
        m[0]=1.0;
      }
      else
      {
        if (alpha<180)
        {
          m[0]=tan((180-alpha)*M_PI/180);
          m[1]=-1.0;
        }
        else
        {
          if (alpha<225) 
          {
            m[0]=-tan((alpha-180)*M_PI/180);
            m[1]=-1.0;
          }
          else
          {
            if (alpha<270) 
            {
              m[1]=-tan((270-alpha)*M_PI/180);
              m[0]=-1.0;
            }
            else
            {
              if (alpha<315) 
              {
                m[1]=tan((alpha-270)*M_PI/180);
                m[0]=-1.0;
              }
              else
              {
                m[0]=-tan((360-alpha)*M_PI/180);
                m[1]=1.0;
              }
            }
          }
        }
      }
    }
  }
}

float AnalyticLine::getAngle()
{
  return angle;
}

//Set and get the cut point on the y axis
void AnalyticLine::set_n(float n)
{
  _n = n;
}
float AnalyticLine::get_n()
{
  return _n;
}

