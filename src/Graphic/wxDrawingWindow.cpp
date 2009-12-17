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

BEGIN_EVENT_TABLE(wxDrawingWindow, wxWindow)
  EVT_PAINT(wxDrawingWindow::OnPaint)
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

  // default values
  _xaxis = _yaxis = 0;
  _xmin = _ymin = -10;
  _xmax = _ymax = 10;
}

//------------------------------------------------
void wxDrawingWindow::World2Window( wxDC& dc, double x, double y, wxCoord& wx, wxCoord& wy)
{
  wxSize _sz = GetClientSize();

  if ((x>=_xmin)&&(x<=_xmax)) {
    wx = (int) (_sz.x/(_xmax-_xmin)*(x-_xmin)+0.5);
  }
  if ((y>=_ymin)&&(y<=_ymax)) {
    wy = (int) (_sz.y-_sz.y/(_ymax-_ymin)*(y-_ymin)+0.5);
  }
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
    World2Window(dc,it->GetX(),it->GetY(),x2,y2);
    if (it!=_points.begin()) {
      dc.DrawLine(x1,y1,x2,y2);
    }
    x1 = x2;
    y1 = y2;
  }

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
  World2Window(dc,_xmin,_yaxis,x1,y1);
  World2Window(dc,_xmax,_yaxis,x2,y2);
  dc.DrawLine(x1,y1,x2,y2);

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
    World2Window(dc,xpos,_yaxis,x1,y1);
    double tmp = xpos/xbigstep;
    //cout << " tmp " << tmp << endl;
    //cout << " tmp -round(tmp)" << tmp - round(tmp) << endl;
    if ( fabs(tmp - round(tmp))<epsilon ) {
      dc.DrawLine(x1,y1-bigticsize,x1,y1+bigticsize);
    }
    if ( fabs(tmp-0.5 - (round(tmp-0.5)))<epsilon ) {
      dc.DrawLine(x1,y1-mediumticsize,x1,y1+mediumticsize);
    }
    else {
      dc.DrawLine(x1,y1-smallticsize,x1,y1+smallticsize);
    }
    xpos += xstep;
  }

  // from xaxis,ymin to xaxis,ymax
  World2Window(dc,_xaxis,_ymin,x1,y1);
  World2Window(dc,_xaxis,_ymax,x2,y2);
  dc.DrawLine(x1,y1,x2,y2);

  // draw tics
  // automatic step computation
  int ysizelog = floor(log10(_ymax-_ymin));
  double ybigstep = pow(10.0,ysizelog);
  double ystep    = ybigstep/10.0;
  double ymintic = floor(_ymin/ystep)*ystep;
  double ypos = ymintic;
  while (ypos<=_ymax) {
    World2Window(dc,_xaxis,ypos,x1,y1);
    double tmp = ypos/ybigstep;
    if ( fabs(tmp - round(tmp))<epsilon ) {
      dc.DrawLine(x1-bigticsize,y1,x1+bigticsize,y1);
    }
    else 
    if ( fabs(tmp-0.5 - (round(tmp-0.5)))<epsilon ) {
      dc.DrawLine(x1-mediumticsize,y1,x1+mediumticsize,y1);
    }
    else 
      dc.DrawLine(x1-smallticsize,y1,x1+smallticsize,y1);
    ypos += ystep;
  }

}

//------------------------------------------------
void wxDrawingWindow::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
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
}
