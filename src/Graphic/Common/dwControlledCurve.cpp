//
// C++ Implementation: dwControlledCurve
//
// Description: Curve controlled by several points
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "dwControlledCurve.h"

void dwControlledCurve::ComputeCurve()
{
  dwCurve::ptr curve(new dwCurve());
/*  if (appliedlimits)
      curve->AddPoint(dwPoint2D((*_controlpoints)[0].GetX(),0));*/
  for(int i=0; i<(int)_controlpoints->size(); i++)
  {
    if (appliedlimits&&(i==0))
      curve->AddPoint(dwPoint2D((*_controlpoints)[i].GetX(),0));
    curve->AddPoint(dwPoint2D((*_controlpoints)[i].GetX(),(*_controlpoints)[i].GetY()));
    if (appliedlimits&&(i==_controlpoints->size()-1))
      curve->AddPoint(dwPoint2D((*_controlpoints)[i].GetX(),0));
  }
/*  if (appliedlimits)
    curve->AddPoint(dwPoint2D((*_controlpoints)[_controlpoints->size()-1].GetX(),0));*/
  _curve = curve;
}
