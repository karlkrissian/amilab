//
// C++ Implementation: wxDrawingWindow
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wxDrawingWindow.h"

#include "amilab_messages.h"
#include "wx/dcclient.h"
#include <wx/menu.h>

#define macro_max(a,b) ((a)>(b)?(a):(b))


enum {
  wxID_AddControl = 1000,
};

BEGIN_EVENT_TABLE(wxDrawingWindow, wxWindow)
  EVT_PAINT(        wxDrawingWindow::OnPaint)
  EVT_RIGHT_DOWN(   wxDrawingWindow::OnRightDown )
  EVT_LEFT_DOWN(    wxDrawingWindow::OnLeftDown )
  EVT_LEFT_UP(      wxDrawingWindow::OnLeftUp )
  EVT_MOTION(       wxDrawingWindow::OnMotion )
  EVT_MENU(         wxID_AddControl, wxDrawingWindow::OnAddControl)
END_EVENT_TABLE();

//------------------------------------------------
wxDrawingWindow::wxDrawingWindow(wxWindow *parent, wxWindowID id,
    const wxPoint& pos, const wxSize& size, long style,
    const wxString& name)
    : wxScrolledWindow(parent, id, pos, size, style
    |wxFULL_REPAINT_ON_RESIZE
    //|wxDOUBLE_BORDER
    |wxBORDER_RAISED
    | wxHSCROLL | wxVSCROLL
    , 
    name)
{
  this->SetScrollbars(3,3,10,10);
  this->EnableScrolling(true,true);

  focus_pointid = -1;
  _left_down = false;
  _previous_crosshair = false;

  // default values
  _xaxis = _yaxis = 0;
  _xmin = _ymin = -10;
  _xmax = _ymax = 10;
}

//------------------------------------------------
void wxDrawingWindow::World2Window(  double x, double y, wxCoord& wx, wxCoord& wy)
{
  wxSize _sz = GetClientSize();
  int px = 0,py = 0;
  px = (int) ((float)(_sz.x-1)/(_xmax-_xmin)*(x-_xmin)+0.5);
  py = (int) ((float)(_sz.y-1)-(float)(_sz.y-1)/(_ymax-_ymin)*(y-_ymin)+0.5);

  wx = macro_max(-1,px);
  wy = macro_max(-1,py);
  if (wx>_sz.x) wx = _sz.x;
  if (wy>_sz.y) wy = _sz.y;
}


//------------------------------------------------
void wxDrawingWindow::Window2World(  wxCoord wx, wxCoord wy, double& x, double& y)
{
  wxSize _sz = GetClientSize();

  x = _xmin + ((float) wx)/(_sz.x-1)*(_xmax-_xmin);
  y = _ymin + ((float) (_sz.y-1-wy) )/(_sz.y-1)*(_ymax-_ymin);
}

//------------------------------------------------
void wxDrawingWindow::AddCurve( InrImage* im)
{
  // new curve
  dw_Curve c;

  double x1,y1;
  // Go through the points and add them to the curve
  for(int x=0;x<im->DimX();x++) {
    x1 = im->SpacePosX(x);
    y1 = (*im)(x,0,0);
    c.AddPoint(dw_Point2D(x1,y1));
  }

  // Add the curve
  _curves.push_back(c);
}

//------------------------------------------------
bool wxDrawingWindow::SetCurve( int i, InrImage* im)
{

  if ((i>=0)&&(i<_curves.size())) {
    // new curve
    dw_Curve c;
  
    double x1,y1;
    // Go through the points and add them to the curve
    for(int x=0;x<im->DimX();x++) {
      x1 = im->SpacePosX(x);
      y1 = (*im)(x,0,0);
      c.AddPoint(dw_Point2D(x1,y1));
    }
    _curves[i].GetPoints() = c.GetPoints();
  } else {
    CLASS_ERROR("Wrong curve number");
    return false;
  }
  return true;
}

/**
  * Adds a new control point
  * @param control point
  */
void wxDrawingWindow::AddControl( const dw_Point2D& pt)
{
  _controlpoints.push_back(dw_ControlPoint(pt));
}

/**
  * Set the new position of a new control point
  * @param control point
  */
void wxDrawingWindow::SetControl( int i, const dw_Point2D& pt)
{
  if ((i>=0)&&(i<_controlpoints.size())) {
    _controlpoints[i] = pt;
  }
}


//------------------------------------------------
void wxDrawingWindow::SetCurveColor( int i, std::string color_string)
{
  if ((i>=0)&&(i<_curves.size())) {
    _curves[i].SetColor(wxColour(wxString(color_string.c_str(), wxConvUTF8)));
  }
}

//------------------------------------------------
void wxDrawingWindow::SetCurveStyle( int i, int style)
{
  if ((i>=0)&&(i<_curves.size())) {
    _curves[i].SetStyle(style);
  }
}

//------------------------------------------------
void wxDrawingWindow::SetCurveWidth( int i, int width)
{
  if ((i>=0)&&(i<_curves.size())) {
    _curves[i].SetWidth(width);
  }
}

//------------------------------------------------
void wxDrawingWindow::DrawCurve(int i, wxDC& dc )
{
  std::vector<dw_Point2D>& _points = _curves[i].GetPoints();
  // iterate through the curves
  std::vector<dw_Point2D>::iterator it;
  wxCoord x1,y1,x2,y2;

  
  for(it=_points.begin();it!=_points.end();it++)
  {
    // draw line from previous to current point
    World2Window(it->GetX(),it->GetY(),x2,y2);
    if (it!=_points.begin()) {
      DrawLine(dc,x1,y1,x2,y2);
    }
    x1 = x2;
    y1 = y2;
  }

}

//------------------------------------------------
void wxDrawingWindow::WriteCurrentPosition()
{
  wxClientDC dc(this);
  
  double x,y;
  Window2World(_mouse_x,_mouse_y,x,y);
  wxString text((boost::format("%1$+2.2f, %2$+2.2f")%x%y).str().c_str(),
                wxConvUTF8);
  wxSize txtsize = dc.GetTextExtent(text);
  wxSize dcsize = dc.GetSize();
  wxSize pos = dcsize-txtsize;
  dc.SetBackgroundMode(wxSOLID);
  // fill previous text with background ???
  dc.DrawText(text,pos.GetWidth()-3,pos.GetHeight()-3);
}

//------------------------------------------------
void wxDrawingWindow::DrawAxes( wxDC& dc )
{
  int bigticsize   = 4;
  int mediumticsize = 2;
  int smallticsize = 1;
  double epsilon = 1E-5;

  wxCoord x1,y1,x2,y2;
  // from xmin,yaxis to xmax,yaxis
  World2Window(_xmin,_yaxis,x1,y1);
  World2Window(_xmax,_yaxis,x2,y2);
  DrawLine(dc,x1,y1,x2,y2);

  // draw tics
  // automatic step computation
  int xsizelog = floor(log10(_xmax-_xmin));
  double xbigstep = pow(10.0,xsizelog);
  double xstep    = xbigstep/10.0;
  //cout << "xstep = " << xstep << endl;
  double xmintic = floor(_xmin/xstep)*xstep;
  //cout << "xmintic = " << xmintic << endl;
  double xpos = xmintic;
  while (xpos<=_xmax) {
    World2Window(xpos,_yaxis,x1,y1);
    double tmp = xpos/xbigstep;
    //cout << " tmp " << tmp << endl;
    //cout << " tmp -round(tmp)" << tmp - round(tmp) << endl;
    if ( fabs(tmp - round(tmp))<epsilon ) {
      DrawLine(dc,x1,y1-bigticsize,x1,y1+bigticsize);
    }
    if ( fabs(tmp-0.5 - (round(tmp-0.5)))<epsilon ) {
      DrawLine(dc,x1,y1-mediumticsize,x1,y1+mediumticsize);
    }
    else {
      DrawLine(dc,x1,y1-smallticsize,x1,y1+smallticsize);
    }
    xpos += xstep;
  }

  // from xaxis,ymin to xaxis,ymax
  World2Window(_xaxis,_ymin,x1,y1);
  World2Window(_xaxis,_ymax,x2,y2);
  DrawLine(dc,x1,y1,x2,y2);

  // draw tics
  // automatic step computation
  int ysizelog = floor(log10(_ymax-_ymin));
  double ybigstep = pow(10.0,ysizelog);
  double ystep    = ybigstep/10.0;
  double ymintic = floor(_ymin/ystep)*ystep;
  double ypos = ymintic;
  while (ypos<=_ymax) {
    World2Window(_xaxis,ypos,x1,y1);
    double tmp = ypos/ybigstep;
    if ( fabs(tmp - round(tmp))<epsilon ) {
      DrawLine(dc,x1-bigticsize,y1,x1+bigticsize,y1);
    }
    else 
    if ( fabs(tmp-0.5 - (round(tmp-0.5)))<epsilon ) {
      DrawLine(dc,x1-mediumticsize,y1,x1+mediumticsize,y1);
    }
    else 
      DrawLine(dc,x1-smallticsize,y1,x1+smallticsize,y1);
    ypos += ystep;
  }

}


//------------------------------------------------
void wxDrawingWindow::DrawControls(wxDC& dc)
{
  scoped_ptr<wxPen> current_pen( new wxPen( *wxBLACK, 1, wxSOLID));
  dc.SetPen(*current_pen);
  
  for(int i = 0; i<_controlpoints.size(); i++) 
  {
    if (_controlpoints[i].HasFocus())
      dc.SetBrush(*wxGREEN_BRUSH);
    else
      dc.SetBrush(*wxTRANSPARENT_BRUSH);
    wxCoord px,py;
    World2Window(_controlpoints[i].GetX(),_controlpoints[i].GetY(),px,py);
    _controlpoints[i].SetwxPoint(wxPoint(px,py));
    dc.DrawCircle(px,py,_controlpoints[i].GetRadius());
  }
}

//------------------------------------------------
void wxDrawingWindow::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);

    // Clip the drawing
    wxRect rect(dc.GetSize());
    wxDCClipper clip(dc,rect);

    scoped_ptr<wxPen> current_pen(
      new wxPen( *wxBLACK, 1, wxSOLID));

    dc.SetPen(*current_pen);

    dc.SetAxisOrientation(true,false);
    dc.SetBrush(*wxRED_BRUSH);

    // Get window dimensions
    wxSize _sz = GetClientSize();

    // Our rectangle dimensions
    wxCoord w = 100, h = 50;

    // Center the rectangle on the window, but never
    // draw at a negative position.

/*
    int x = (((_sz.x—w)/2>0)?((_sz.x-w)/2):0);
    int y = (((_sz.y—h)/2>0)?((_sz.y—h)/2):0);
*/
   int x;
   if (((_sz.x-w)/2)>0)
    x = (_sz.x-w)/2;
   else x=0;
   int y;
   if (((_sz.y-h)/2)>0)
    y = (_sz.y-h)/2;
   else y=0;

    wxRect rectToDraw(x, y, w, h);

    // For efficiency, do not draw if not exposed
    if (IsExposed(rectToDraw)) {
      //dc.DrawRectangle(rectToDraw);
      dc.SetPen(*wxBLACK_PEN);
      DrawAxes(dc);
      for (int i=0; i<GetNumberOfCurves(); i++)
      {
        current_pen->SetColour(_curves[i].GetColor());
/*
0: wxSOLID   Solid style.
1: wxDOT   Dotted style.
2: wxLONG_DASH   Long dashed style.
3: wxSHORT_DASH  Short dashed style.
4: wxDOT_DASH  Dot and dash style. 
*/
        int wxstyle=wxSOLID;
        switch (_curves[i].GetStyle()) {
          case 0: wxstyle=wxSOLID;       break;
          case 1: wxstyle=wxDOT;         break;
          case 2: wxstyle=wxLONG_DASH;   break;
          case 3: wxstyle=wxSHORT_DASH;  break;
          case 4: wxstyle=wxDOT_DASH;    break;
          default: wxstyle=wxSOLID;
        }
        current_pen->SetStyle( wxstyle);
        current_pen->SetWidth( _curves[i].GetWidth());
        dc.SetPen(*current_pen);
        DrawCurve(i,dc);
      }
    }

    DrawControls(dc);
}

//-------------------------------------------------
void wxDrawingWindow::OnRightDown(wxMouseEvent& event)
{
  wxClientDC dc(this);

  _mouse_x = (int)event.GetX();
  _mouse_y = (int)event.GetY();

  CLASS_MESSAGE(boost::format("At position %1% %2%")%_mouse_x%_mouse_y);
  double x,y;
  Window2World(_mouse_x,_mouse_y,x,y);
  CLASS_MESSAGE(boost::format("world coord %1% %2%")%x%y);

  // create the popup menu here
  wxMenu menu(_T("Menu"));
  wxMenuItem* item = menu.Append(wxID_AddControl, wxT("&Add control point"));
  PopupMenu(&menu, _mouse_x,_mouse_y);

}

//-------------------------------------------------
void wxDrawingWindow::OnMotion(wxMouseEvent& event)
{
  wxClientDC dc(this);

  int oldmouse_x = _mouse_x;
  int oldmouse_y = _mouse_y;
  _mouse_x = (int)event.GetX();
  _mouse_y = (int)event.GetY();

  //cout << "leftdown " << _left_down << endl;
  if (_left_down) {
    if ((focus_pointid!=-1)&&(_left_down)) {
      // displace the current point
      //cout << "Displace ??" << endl;
      double x,y;
      Window2World(_mouse_x,_mouse_y,x,y);
      _controlpoints[focus_pointid].SetPos(x,y);
      _controlpoints[focus_pointid].SetwxPoint(wxPoint(_mouse_x,_mouse_y));
      Refresh();
    }
    else 
    {
      scoped_ptr<wxPen> current_pen(
        new wxPen( *wxBLACK, 1, wxDOT));
      dc.SetPen(*current_pen);

      dc.SetLogicalFunction( wxINVERT );
      if (_previous_crosshair)
        dc.CrossHair( oldmouse_x, oldmouse_y );
      dc.CrossHair( _mouse_x, _mouse_y );
      _previous_crosshair = true;
      dc.SetLogicalFunction( wxCOPY );
      WriteCurrentPosition();
    }
    return;
  }

  double mindist = 1000;
  int closest = -1;

  // search for closest controlpoints
  for(int i=0;i<_controlpoints.size();i++) {
    wxPoint p;
    p = _controlpoints[i].GetwxPoint();
    _controlpoints[i].SetFocus(false);
    double tmp = (p.x-_mouse_x)*(p.x-_mouse_x)+(p.y-_mouse_y)*(p.y-_mouse_y);
    if (tmp<_controlpoints[i].GetRadius()*_controlpoints[i].GetRadius()) {
      if (closest==-1) {
        mindist = tmp;
        closest = i;
      }
      else {
        if (tmp<mindist) {
          mindist = tmp;
          closest = i;
        }
      }
    }
  }

  if (closest!=-1) {
    _controlpoints[closest].SetFocus(true);
  }
  focus_pointid = closest;
  Refresh();
  
/*
  CLASS_MESSAGE(boost::format("At position %1% %2%")%_mouse_x%_mouse_y);
  double x,y;
  Window2World(_mouse_x,_mouse_y,x,y);
  CLASS_MESSAGE(boost::format("world coord %1% %2%")%x%y);
*/
}

//-------------------------------------------------
void wxDrawingWindow::OnAddControl(wxCommandEvent& event)
{
  double x,y;
  Window2World(_mouse_x,_mouse_y,x,y);
  AddControl(dw_Point2D(x,y));
  Refresh();
}

