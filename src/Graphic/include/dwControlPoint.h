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
 colormap_point,
} ControlPointType;

/**
  * Control point
  **/
class dwControlPoint
{
  DEFINE_CLASS(dwControlPoint);

private:
  dwPoint2D       pos;
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
    selected = false;
    has_focus = false;
    radius = 3;
    colour = *wxGREEN;
    type = normal_point;
    horizontal_line = false;
    vertical_line = false;
  }

  void operator = (const dwPoint2D& p )
  {
    pos = p;
  }

  double GetX() const { return pos.GetX(); }
  double GetY() const { return pos.GetY(); }

  void   SetX(double x)  { pos.SetX(x); }
  void   SetY(double y)  { pos.SetY(y); }

  int GetRadius() const { return radius; }
  void SetRadius(const int& r) { radius = r; }

  wxColour GetColour() const { return colour; }
  void SetColour(const wxColour& c) { colour = c; }

  void SetPos(double x, double y) { pos.SetX(x); pos.SetY(y); }

  wxPoint GetwxPoint() const { return winpos; }
  void SetwxPoint(const wxPoint& p) { winpos = p; }

  void SetFocus(bool act) { has_focus = act; }
  bool HasFocus()         { return has_focus; }
  
  ControlPointType GetType() const { return type; }
  void SetType( const int t) { type = (ControlPointType)t; }
  
  void SetHorizontalLine(bool hl)  { horizontal_line = hl; }
  bool GetHorizontalLine() const { return horizontal_line; }
  
  void SetVerticalLine(bool vl) { vertical_line = vl; }
  bool GetVerticalLine() const { return vertical_line; }
};

typedef std::vector<dwControlPoint>    vector_dwControlPoint;


#endif
// _dwControlPoint_h_
