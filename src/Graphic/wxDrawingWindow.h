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

#include <vector>
#include "inrimage.hpp"
#include "DefineClass.hpp"

#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

//#include "wx/msw/winundef.h"
#include "wx/window.h"
#include <wx/scrolwin.h>

#include "dw_Curve.h"
#include "wx/dcclient.h"
#include "CallBackBase.h"

class dw_ControlPoint
{
private:
  dw_Point2D pos;
  wxPoint    winpos;
  bool       selected;
  bool       has_focus;
  /// Point radius
  int        radius;
  /// Point colour
  wxColour   colour;

public:
  dw_ControlPoint()
  {
    selected = false;
    has_focus = false;
    radius = 3;
    colour = *wxGREEN;
  }

  dw_ControlPoint(const dw_Point2D& p)
  {
    pos = p;
    selected = false;
    has_focus = false;
    radius = 3;
    colour = *wxGREEN;
  }

  void operator = (const dw_Point2D& p )
  {
    pos = p;
  }

  double GetX() const { return pos.GetX(); }
  double GetY() const { return pos.GetY(); }

  int GetRadius() const { return radius; }
  void SetRadius(const int& r) { radius = r; }

  wxColour GetColour() const { return colour; }
  void SetColour(const wxColour& c) { colour = c; }

  void SetPos(double x, double y) { pos.SetX(x); pos.SetY(y); }

  wxPoint GetwxPoint() const { return winpos; }
  void SetwxPoint(const wxPoint& p) { winpos = p; }

  void SetFocus(bool act) { has_focus = act; }
  bool HasFocus()         { return has_focus; }
};


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

  bool _draw_grid;

  //! std::vector of the curves to draw
  std::vector<dw_Curve> _curves;

  //! std:vector of dw_Point2D: list of control points
  std::vector<dw_ControlPoint> _controlpoints;

  //! index of the control point having the focus if any, -1 otherwise
  int focus_pointid;

  int _mouse_x;
  int _mouse_y;
  bool _left_down;
  bool _previous_crosshair;

  /// device context in memory
  scoped_ptr<wxMemoryDC> _memory_dc;
  /// device context in memory
  scoped_ptr<wxBitmap>   _bitmap; 


  // Callback for the control point motion
  CallBackBase::ptr _ctrlpt_callback;

  void DrawingAreaInit( );

public:
   wxDrawingWindow(wxWindow *parent, wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = 0,
        const wxString& name = _T("wxDrawingWindow"));

  virtual ~wxDrawingWindow(){};

  void SetCtrlPointCallback( CallBackBase::ptr callback) {
    this->_ctrlpt_callback = callback;
  }

  int GetNumberOfCtrlPoints() 
  {
    return _controlpoints.size();
  }

  dw_ControlPoint GetControlPoint(int n)
  {
    if ((n>=0)&&(n<(int)_controlpoints.size()))
      return _controlpoints[n];
    else 
      return dw_ControlPoint();
  }

  void DrawingAreaDisplay( );

  void World2Window( double x, double y, 
                      wxCoord& wx, wxCoord& wy);

  void Window2World( wxCoord wx, wxCoord wy, double& x, double& y);

  void DrawAxes( );

  /**
   * Seach for the closest control point
   * and return its id or -1 if no control point is found
   */
  int CheckCtrlPoint();

  void SetDrawGrid(bool b) { _draw_grid = b; }
  bool GetDrawGrid() { return _draw_grid; }

  void SetXLimits(double xmin, double xmax)
  {
    _xmin = xmin; _xmax = xmax;
    if (xmax<xmin+1E-5) _xmax = xmin+1E-5;
  }

  void SetYLimits(double ymin, double ymax)
  {
    _ymin = ymin; _ymax = ymax;
    if (ymax<ymin+1E-5) _ymax = ymin+1E-5;
  }

  /**
   * Draws the line if all the coordinates are positive
   * @param dc drawing context 
   * @param x1 first point
   * @param y1 
   * @param x2 second point
   * @param y2
   */
  void DrawLine( int x1, int y1, int x2, int y2)
  {
    // not needed because of clipping ??
    //    wxCoord w,h;
    //    _memory_dc->GetSize(&w,&h);
    //    wxRect rect(0,0,w,h);
    //    if (rect.Contains(x1,y1)&&rect.Contains(x2,y2))
    _memory_dc->DrawLine(x1,y1,x2,y2);
  }

  /**
   * Draws the point if the coordinates are correct
   * @param dc drawing context 
   * @param x1 first point
   * @param y1 
   */
  void DrawPoint( int x1, int y1)
  {
//    wxCoord w,h;
//    _memory_dc->GetSize(&w,&h);
//    wxRect rect(0,0,w,h);
//    if (rect.Contains(x1,y1))
      _memory_dc->DrawCircle(x1,y1,2);
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
   * Adds the image points to the given curve,
   * if the image is scalar, use X world coordinates in abscissa
   * if the image is vectorial with 2 components, the first components are abscissa and the second are ordinates
   * @param im 
   */
  void AddImageToCurve( InrImage* im, dw_Curve& c);


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
   * Adds a new control point
   * @param control point
   */
  void AddControl( const dw_Point2D& pt);

  /**
   * Removes a control point
   * @param control point id
   */
  void RemoveControl( const int& pt_id);

  /**
   * Set the new position of a new control point
   * @param control point
   */
  void SetControl( int i, const dw_Point2D& pt);

  /**
   * 
   **/
  void SetCurveDrawPoints( int i, bool dp);

  /**
   * 
   **/
  void SetCurveDrawLines( int i, bool dp);

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
   * @param width 
   */
  void SetCurveWidth( int i, int width);

  /**
   * Draw a given curve in a given graphical context.
   * @param i  curve number
   * @param dc  context
   */
  void DrawCurve( int i );

  void WriteCurrentPosition( wxDC& dc);

  void DrawControls();

  void Paint( );
  void OnSize( wxSizeEvent& event);
  //void OnChar(           wxKeyEvent&  event);

  void OnPaint(wxPaintEvent& event);

  void OnLeftDown(      wxMouseEvent& event) 
  {
    _left_down = true;  event.Skip(); 
  }

  void OnLeftUp(        wxMouseEvent& event) 
  {
    cout << "OnLeftUp" << endl;
    _left_down = false; 
    _previous_crosshair = false;
    DrawingAreaDisplay();
    event.Skip(); 
  }

  void OnRightDown(     wxMouseEvent& event);
  void OnMotion(        wxMouseEvent& event);
  void OnWheel(         wxMouseEvent& event);

  void OnAddControl(    wxCommandEvent& event);
  void OnRemoveControl( wxCommandEvent& event);
  void OnControlColour( wxCommandEvent& event);
  void OnShowGrid(      wxCommandEvent& event);

  DECLARE_EVENT_TABLE();
};

#endif // _wxDrawingWindow_h_
 