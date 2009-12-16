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
    _curves[i] = c;
  } else {
    CLASS_ERROR("Wrong curve number");
    return false;
  }
  return true;
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
  wxCoord x1,y1,x2,y2;
  // from xmin,yaxis to xmax,yaxis
  World2Window(dc,_xmin,_yaxis,x1,y1);
  World2Window(dc,_xmax,_yaxis,x2,y2);
  dc.DrawLine(x1,y1,x2,y2);
  // from xaxis,ymin to xaxis,ymax
  World2Window(dc,_xaxis,_ymin,x1,y1);
  World2Window(dc,_xaxis,_ymax,x2,y2);
  dc.DrawLine(x1,y1,x2,y2);
}

//------------------------------------------------
void wxDrawingWindow::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);

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
      dc.SetPen(*wxRED_PEN);
      for (int i=0; i<GetNumberOfCurves(); i++)
        DrawCurve(i,dc);
    }
}
