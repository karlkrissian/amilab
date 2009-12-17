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

#include "dw_Curve.h"
#include "DefineClass.hpp"

/**
  * A wxWindow that draws 2D curves.
  */
class wxDrawingWindow : public wxScrolledWindow
{
  DEFINE_CLASS(wxDrawingWindow);

  //! axis limits in X
  double _xmin, _xmax;

  //! axis limits in Y
  double _ymin, _ymax;

  //! position in Y of X axis
  double _xaxis;

  //! position in X of Y axis
  double _yaxis;

  //! std::vector of the curves to draw
  std::vector<dw_Curve> _curves;

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

  /**
   * 
   * @return the current number of curves
   */
  int GetNumberOfCurves() 
  {
    return _curves.size();
  }

  /**
   * Adds a new curve
   * @param im 
   */
  void AddCurve( InrImage* im);

  /**
   * Changes the values of an existing curve
   * @param i 
   * @param im 
   * @return true/false for success/failure
   */
  bool SetCurve( int i, InrImage* im);


  /**
   * Set the curve number i color from the string, see wxColour for documentation
   * @param i 
   * @param color_string 
   */
  void SetCurveColor( int i, std::string color_string);

  /**
   * Sets the curve style.
   * @param i 
   * @param style 
   */
  void SetCurveStyle( int i, int style);

  /**
   * Sets the curve width.
   * @param i 
   * @param style 
   */
  void SetCurveWidth( int i, int width);

  /**
   * Draw a given curve in a given graphical context.
   * @param i  curve number
   * @param dc  context
   */
  void DrawCurve( int i, wxDC& dc );

  void OnPaint(          wxPaintEvent& event);
  //void OnSize(           wxSizeEvent& event);
  //void OnChar(           wxKeyEvent&  event);
  //void OnMouseEvent(     wxMouseEvent& event);

  DECLARE_EVENT_TABLE();
};

#endif // _wxDrawingWindow_h_
 