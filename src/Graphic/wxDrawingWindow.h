//
// C++ Interface: wxDrawingWindow
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wxDrawingWindow_h_
#define _wxDrawingWindow_h_


#include "wx/window.h"
#include <wx/scrolwin.h>
#include <vector>
#include "inrimage.hpp"

class dw_Point2D {
  double _x;
  double _y;
public:
  dw_Point2D() :_x(0),_y(0) {}
  dw_Point2D(double x, double y) :_x(x),_y(y) {}
  double GetX() { return _x;}
  double GetY() { return _y;}
  void SetX(double x) { _x = x; }
  void SetY(double y) { _y = y; }
};


class wxDrawingWindow : public wxScrolledWindow
{
  // curve drawing parameters
  double _xmin, _xmax;
  double _ymin, _ymax;
  double _xaxis,_yaxis;

  // curve
  std::vector<dw_Point2D> _points;

public:
   wxDrawingWindow(wxWindow *parent, wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = 0,
        const wxString& name = _T("wxDrawingWindow"));

  virtual ~wxDrawingWindow(){};

  void World2Window( wxDC& dc, double x, double y, 
                      wxCoord& wx, wxCoord& wy);

  void DrawAxes( wxDC& dc );

  void SetXLimits(double xmin, double xmax)
  {
    _xmin = xmin; _xmax = xmax;
  }

  void SetYLimits(double ymin, double ymax)
  {
    _ymin = ymin; _ymax = ymax;
  }

  void AddFunction( InrImage* im);

  void DrawFunction( wxDC& dc );

  void OnPaint(          wxPaintEvent& event);
  //void OnSize(           wxSizeEvent& event);
  //void OnChar(           wxKeyEvent&  event);
  //void OnMouseEvent(     wxMouseEvent& event);

  DECLARE_EVENT_TABLE()
};

#endif // _wxDrawingWindow_h_
 