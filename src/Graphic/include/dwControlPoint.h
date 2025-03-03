//
// C++ Interface: dwControlPoint.h
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _dwControlPoint_h_
#define _dwControlPoint_h_

#include "DefineClass.hpp"

#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "dwPoint2D.h"

typedef enum {
 normal_point,
 colormap_point, // unused now this colormap is a property of the whole curve
} ControlPointType;

/**
  * Control point
  **/
class dwControlPoint
{
  DEFINE_CLASS(dwControlPoint);

private:
  dwPoint2D        pos;
  wxPoint          winpos;
  bool             selected;
  bool             has_focus;
  /// Point radius
  int              radius;
  /// Point colour
  wxColour         colour;
  ControlPointType type;
  /// other properties
  bool             horizontal_line;
  bool             vertical_line;
  bool             x_locked;
  bool             y_locked;
  
  /// midpoint as defined in vtkPiecewiseFunction
  double midpoint;
  /// sharpness as defined in vtkPiecewiseFunction
  double sharpness;

public:
  dwControlPoint()
  {
    DefaultInit();
  }

  dwControlPoint(const dwPoint2D& p)
  {
    DefaultInit();
    pos = p;
  }

  dwControlPoint(const dwPoint2D& p, ControlPointType t)
  {
    DefaultInit();
    pos = p;
    type = t;
  }

  void DefaultInit()
  {
    selected  = false;
    has_focus = false;
    radius    = 3;
    colour    = *wxGREEN;
    type      = normal_point;
    horizontal_line = false;
    vertical_line   = false;
    x_locked  = false;
    y_locked  = false;
    midpoint  = 0.5;
    sharpness = 0.0;
  }

  void operator = (const dwPoint2D& p )
  {
    pos = p;
  }

  double GetX() const { return pos.GetX(); }
  double GetY() const { return pos.GetY(); }

  void   SetX(double x)  { pos.SetX(x); }
  void   SetY(double y)  { if (!y_locked) pos.SetY(y); }

  double Getmidpoint() const { return midpoint; }
  double Getsharpness() const { return sharpness; }

  void Setmidpoint( double mp)  { midpoint=mp; }
  void Setsharpness(double s)   { sharpness=s; }

  int GetRadius() const { return radius; }
  void SetRadius(const int& r) { radius = r; }

  wxColour GetColour() const { return colour; }
  void SetColour(const wxColour& c) { colour = c; }

  void SetPos(double x, double y) { pos.SetX(x); pos.SetY(y); }

  wxPoint GetwxPoint() const { return winpos; }
  void SetwxPoint(const wxPoint& p) { 
    winpos = p; 
//     winpos.y = p.y; 
  }

  void SetFocus(bool act) { has_focus = act; }
  bool HasFocus()         { return has_focus; }
  
  ControlPointType GetType() const { return type; }
  void SetType( const int t) { type = (ControlPointType)t; }
  
  void SetHorizontalLine(bool hl)  { horizontal_line = hl; }
  bool GetHorizontalLine() const { return horizontal_line; }
  
  void SetVerticalLine(bool vl) { vertical_line = vl; }
  bool GetVerticalLine() const { return vertical_line; }

  void SetYLocked(bool yl) { y_locked = yl; }
  bool GetYLocked() const { return y_locked; }

};

#include <vector>

typedef std::vector<dwControlPoint>    vector_dwControlPoint;


#endif
// _dwControlPoint_h_
