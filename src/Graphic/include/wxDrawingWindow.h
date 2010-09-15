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

#include "dwCurve.h"
#include "wx/dcclient.h"
#include "CallBackBase.h"
#include "LinearColorMap.h"

#include "dwControlPoint.h"
#include "dwControlledCurve.h"


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
  boost::shared_ptr<vector_dwCurve> _curves;

  /** std:vector of dwPoint2D: list of control points
     within a shared pointer to facilitate the wrapping
    */
  boost::shared_ptr<vector_dwControlPoint>    _controlpoints;

  boost::shared_ptr<vector_dwControlledCurve> _controlled_curves;

  //! LinearColorMap functionality
  LinearColorMap _linearCM;
  bool   _draw_linearCM;
  wxSize _linearCM_margin_size;

//  //! index of the control point having the focus if any, -1 otherwise
//  int focus_pointid;
  //! Risky trick for the moment, we use a shared_ptr with no deleter that references to the control point found (if the control point is deleted, the program will crash)
  dwControlPoint::ptr _focus_point;
  /// smart pointer to the vector of points to which the current focus point belongs
  boost::shared_ptr<vector_dwControlPoint> _focus_pointset;
  int _focus_controlledcurve;

  bool _within_popupmenu;
  
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


  boost::shared_ptr<vector_dwControlPoint>& GetControlPoints() {
    return _controlpoints;
  }

  boost::shared_ptr<vector_dwCurve>& GetCurves() {
    return _curves;
  }

  boost::shared_ptr<vector_dwControlledCurve>& GetControlledCurves() {
    return _controlled_curves;
  }

  void SetCtrlPointCallback( CallBackBase::ptr callback) {
    this->_ctrlpt_callback = callback;
  }

  int GetNumberOfCtrlPoints() const
  {
    return _controlpoints->size();
  }

  dwControlPoint GetControlPoint(int n) const
  {
    if ((n>=0)&&(n<(int)_controlpoints->size()))
      return (*_controlpoints)[n];
    else 
      return dwControlPoint();
  }

/*
  void SetCtrlPointCallback( CallBackBase::ptr callback) {
    this->_ctrlpt_callback = callback;
  }
*/

  void DrawingAreaDisplay( );

  void World2Window( double x, double y, 
                      wxCoord& wx, wxCoord& wy) const;

  wxCoord World2WindowX( double x) const;

  void Window2World( wxCoord wx, wxCoord wy, double& x, double& y) const;

  double Window2WorldX(const wxCoord& wx ) const;

  void DrawAxes( );

  void DrawLinearCM( );

  /**
   * Seach for the closest control point within a list
   * and return its id or -1 if no control point is found
   * and updates the shared_ptr _focus_point
   */
  int CheckCtrlPoint( boost::shared_ptr<vector_dwControlPoint>& list);

  /**
   * Seach for the closest control point in all the lists
   * and updates the shared_ptr _focus_point
   */
  void CheckCtrlPoint();

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
    return _curves->size();
  }

  /**
   * Adds the image points to the given curve,
   * if the image is scalar, use X world coordinates in abscissa
   * if the image is vectorial with 2 components, the first components are abscissa and the second are ordinates
   * @param im 
   */
  void AddImageToCurve( InrImage* im, dwCurve& c);


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
  void AddControlPoint( const dwControlPoint& pt);

  /**
   * Removes the current control point with focus
   */
  void RemoveControl();

  /**
   * Duplicates the current control point with focus
   */
  void DuplicateControl();

  /**
   * Set the new position of a new control point
   * @param control point
   */
  void SetControl( int i, const dwPoint2D& pt);

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
   * Returns the image of the colormap, image of type UNSIGNED CHAR with 3 components and 256 values in X.
   * @return 
   */
  InrImage::ptr GetColormapImage() 
  {
    return _linearCM.CreateColormapImage();
  }

  /**
   * Draw a given curve in the graphical context.
   */
  void DrawCurve( dwCurve& curve );

  /**
   * Draw all the curves
   */
  void DrawCurves();

  void WriteCurrentPosition( wxDC& dc);

  void DrawControlPoint(  dwControlPoint& pt, 
                          const wxColour& visible_colour,
                          const wxSize& _sz);
  void DrawControlPoints();
  void DrawControls();

  void Paint( );
  void OnSize( wxSizeEvent& event);
  //void OnChar(           wxKeyEvent&  event);

  void OnPaint(wxPaintEvent& event);

  void OnLeftDown(      wxMouseEvent& event) 
  {
    _left_down = true;  event.Skip(); 
  }

  void OnLeftUp(        wxMouseEvent& event);
/*
  {
   std::cout << "OnLeftUp" << std::endl;
    _left_down = false; 
    _previous_crosshair = false;
    DrawingAreaDisplay();
    event.Skip(); 
  }
*/

  void OnRightDown(     wxMouseEvent& event);
  void OnRightUp(       wxMouseEvent& event);
  void OnMotion(        wxMouseEvent& event);
  void OnWheel(         wxMouseEvent& event);

  void OnAddControlledCurve( wxCommandEvent& event);
  void OnRemoveControlledCurve( wxCommandEvent& event);
  void OnAddControlPoint(    wxCommandEvent& event);
  void OnRemoveControl(      wxCommandEvent& event);
  void OnDuplicateControl(   wxCommandEvent& event);
  void OnColormapPoint(      wxCommandEvent& event);
  void OnVerticalLine(       wxCommandEvent& event);
  void OnControlColour(      wxCommandEvent& event);
  void OnShowGrid(           wxCommandEvent& event);

  DECLARE_EVENT_TABLE();
};

#endif // _wxDrawingWindow_h_
 
