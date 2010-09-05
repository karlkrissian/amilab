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
  for(int i=0; i<_controlpoints->size(); i++)
  {
    curve->AddPoint(dwPoint2D((*_controlpoints)[i].GetX(),(*_controlpoints)[i].GetY()));
  }
  _curve = curve;
}
