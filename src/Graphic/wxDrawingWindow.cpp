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

#include <wx/cmndata.h>
#include <wx/colordlg.h>


#define macro_max(a,b) ((a)>(b)?(a):(b))

#if ((wxMAJOR_VERSION==2)&&(wxMINOR_VERSION>=9))||(wxMAJOR_VERSION>=3)
  #define PENSTYLE_SOLID wxPENSTYLE_SOLID 
#else
  #define PENSTYLE_SOLID wxSOLID 
#endif


enum {
  wxID_AddControl = 2000,
  wxID_RemoveControl,
  wxID_SetControlColour,
  wxID_ShowGrid,
};

BEGIN_EVENT_TABLE(wxDrawingWindow, wxWindow)
  EVT_PAINT(        wxDrawingWindow::OnPaint)
  EVT_SIZE        ( wxDrawingWindow::OnSize      )
  EVT_RIGHT_DOWN(   wxDrawingWindow::OnRightDown )
  EVT_LEFT_DOWN(    wxDrawingWindow::OnLeftDown )
  EVT_LEFT_UP(      wxDrawingWindow::OnLeftUp )
  EVT_MOTION(       wxDrawingWindow::OnMotion )
  EVT_MOUSEWHEEL(   wxDrawingWindow::OnWheel )
  EVT_MENU(         wxID_AddControl,       wxDrawingWindow::OnAddControl)
  EVT_MENU(         wxID_RemoveControl,    wxDrawingWindow::OnRemoveControl)
  EVT_MENU(         wxID_SetControlColour, wxDrawingWindow::OnControlColour)
  EVT_MENU(         wxID_ShowGrid,         wxDrawingWindow::OnShowGrid)
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

  _draw_grid = true;
}


//---------------------------------------------------------------------
void wxDrawingWindow::DrawingAreaInit( )
//                  --------------
{
  if (!this->IsShown())   return;

  int w = this->GetClientSize().GetWidth();
  int h = this->GetClientSize().GetHeight();

  // wx way
  scoped_ptr<wxBitmap> bitmap(new wxBitmap( w,h,-1));
  swap(_bitmap,bitmap);
  scoped_ptr<wxMemoryDC> memory_dc(new wxMemoryDC);

  swap(_memory_dc, memory_dc);
  _memory_dc->SelectObject(*_bitmap);
  _memory_dc->SetBackgroundMode(wxTRANSPARENT);
} // DrawingAreaInit( )



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
void wxDrawingWindow::AddImageToCurve( InrImage* im, dw_Curve& c)
{
  double x1,y1;
  if (im->GetVDim()==1) {
    // Go through the points and add them to the curve
    for(int x=0;x<im->DimX();x++) {
      x1 = im->SpacePosX(x);
      y1 = (*im)(x,0,0);
      c.AddPoint(dw_Point2D(x1,y1));
    }
  }

  if (im->GetVDim()==2) {
    // Go through the points and add them to the curve
    for(int x=0;x<im->DimX();x++) {
      x1 = (*im)(x,0,0.0);
      y1 = (*im)(x,0,0,1);
      c.AddPoint(dw_Point2D(x1,y1));
    }
  }

}

//------------------------------------------------
void wxDrawingWindow::AddCurve( InrImage* im)
{
  // new curve
  dw_Curve c;

  AddImageToCurve(im,c);

  // Add the curve
  _curves.push_back(c);
}

//------------------------------------------------
bool wxDrawingWindow::SetCurve( int i, InrImage* im)
{

  if ((i>=0)&&(i<(int)_curves.size())) {
    // new curve
    dw_Curve c;
  
    AddImageToCurve(im,c);
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
  * Removes a new control point
  * @param control point id
  */
void wxDrawingWindow::RemoveControl( const int& pt_id)
{
  _controlpoints.erase(_controlpoints.begin()+pt_id);  
}

/**
  * Set the new position of a new control point
  * @param control point
  */
void wxDrawingWindow::SetControl( int i, const dw_Point2D& pt)
{
  if ((i>=0)&&(i<(int)_controlpoints.size())) {
    _controlpoints[i] = pt;
  }
}


//------------------------------------------------
void wxDrawingWindow::SetCurveDrawPoints( int i, bool dp)
{
  if ((i>=0)&&(i<(int)_curves.size())) {
    _curves[i].SetDrawPoints(dp);
  }
}

//------------------------------------------------
void wxDrawingWindow::SetCurveDrawLines( int i, bool dp)
{
  if ((i>=0)&&(i<(int)_curves.size())) {
    _curves[i].SetDrawLines(dp);
  }
}

//------------------------------------------------
void wxDrawingWindow::SetCurveColor( int i, std::string color_string)
{
  if ((i>=0)&&(i<(int)_curves.size())) {
    _curves[i].SetColor(wxColour(wxString(color_string.c_str(), wxConvUTF8)));
  }
}

//------------------------------------------------
void wxDrawingWindow::SetCurveStyle( int i, int style)
{
  if ((i>=0)&&(i<(int)_curves.size())) {
    _curves[i].SetStyle(style);
  }
}

//------------------------------------------------
void wxDrawingWindow::SetCurveWidth( int i, int width)
{
  if ((i>=0)&&(i<(int)_curves.size())) {
    _curves[i].SetWidth(width);
  }
}

//------------------------------------------------
void wxDrawingWindow::DrawCurve(int i )
{
  std::vector<dw_Point2D>& _points = _curves[i].GetPoints();
  // iterate through the curves
  std::vector<dw_Point2D>::iterator it;
  wxCoord x1,y1,x2,y2;

  for(it=_points.begin();it!=_points.end();it++)
  {
    // draw line from previous to current point
    World2Window(it->GetX(),it->GetY(),x2,y2);
    if (_curves[i].GetDrawLines())
      if (it!=_points.begin()) {
        DrawLine(x1,y1,x2,y2);
      }
    if (_curves[i].GetDrawPoints())
      DrawPoint(x1,y1);
    x1 = x2;
    y1 = y2;
  }

}

//------------------------------------------------
void wxDrawingWindow::WriteCurrentPosition( wxDC& dc)
{
  
  double x,y;
  Window2World(_mouse_x,_mouse_y,x,y);
  wxString text((boost::format("%1$+2.2f, %2$+2.2f")%x%y).str().c_str(),
                wxConvUTF8);
  wxSize txtsize = dc.GetTextExtent(text);
  wxSize dcsize = dc.GetSize();
  wxSize pos = dcsize-txtsize;
  dc.SetBackgroundMode(PENSTYLE_SOLID);
  // fill previous text with background ???
  dc.DrawText(text,pos.GetWidth()-3,pos.GetHeight()-3);
}

//------------------------------------------------
void wxDrawingWindow::DrawAxes(  )
{
  int bigticsize   = 4;
  int mediumticsize = 2;
  int smallticsize = 1;
  double epsilon = 1E-5;

  // automatic step computation
  int xsizelog = floor(log10(_xmax-_xmin));
  double xbigstep = pow(10.0,xsizelog);
  double xstep    = xbigstep/10.0;
  //cout << "xstep = " << xstep << endl;
  double xmintic = floor(_xmin/xstep)*xstep;
  //cout << "xmintic = " << xmintic << endl;

  // automatic step computation
  int ysizelog = floor(log10(_ymax-_ymin));
  double ybigstep = pow(10.0,ysizelog);
  double ystep    = ybigstep/10.0;
  double ymintic = floor(_ymin/ystep)*ystep;

  wxCoord x1,y1,x2,y2;
  double xpos,ypos;

  scoped_ptr<wxPen> current_pen2( new wxPen( *wxLIGHT_GREY, 1, PENSTYLE_SOLID));
  _memory_dc->SetPen(*current_pen2);

  if (_draw_grid)
  {
    xpos = xmintic;
    while (xpos<=_xmax) {
      World2Window(xpos,_yaxis,x1,y1);
      double tmp = xpos/xbigstep;
      //cout << " tmp " << tmp << endl;
      //cout << " tmp -round(tmp)" << tmp - round(tmp) << endl;
      if (tmp!=0) {
        if (fabs(tmp - round(tmp))<epsilon) {
          World2Window(xpos,_ymin,x1,y1);
          World2Window(xpos,_ymax,x2,y2);
          DrawLine(x1,y1,x2,y2);
        } else
        if ( fabs(tmp-0.5 - (round(tmp-0.5)))<epsilon ) {
          World2Window(xpos,_ymin,x1,y1);
          World2Window(xpos,_ymax,x2,y2);
          DrawLine(x1,y1,x2,y2);
        }
      }
   /*
      else {
        DrawLine(dc,x1,y1-smallticsize,x1,y1+smallticsize);
      }
  */
      xpos += xstep;
    }
  
  
    ypos = ymintic;
    while (ypos<=_ymax) {
      World2Window(_xaxis,ypos,x1,y1);
      double tmp = ypos/ybigstep;
      if (tmp!=0) {
        if ( fabs(tmp - round(tmp))<epsilon ) {
          if (_draw_grid) {
            World2Window(_xmin,ypos,x1,y1);
            World2Window(_xmax,ypos,x2,y2);
            DrawLine(x1,y1,x2,y2);
          }
        }
        else 
        if ( fabs(tmp-0.5 - (round(tmp-0.5)))<epsilon ) {
          World2Window(_xmin,ypos,x1,y1);
          World2Window(_xmax,ypos,x2,y2);
          DrawLine(x1,y1,x2,y2);
        }
      }
/*
      else 
        DrawLine(x1-smallticsize,y1,x1+smallticsize,y1);
  */
      ypos += ystep;
    }
  }


  scoped_ptr<wxPen> current_pen( new wxPen( *wxBLACK, 1, PENSTYLE_SOLID));
  _memory_dc->SetPen(*current_pen);

  // from xmin,yaxis to xmax,yaxis
  World2Window(_xmin,_yaxis,x1,y1);
  World2Window(_xmax,_yaxis,x2,y2);
  DrawLine(x1,y1,x2,y2);

  // draw tics
  xpos = xmintic;
  while (xpos<=_xmax) {
    World2Window(xpos,_yaxis,x1,y1);
    double tmp = xpos/xbigstep;
    //cout << " tmp " << tmp << endl;
    //cout << " tmp -round(tmp)" << tmp - round(tmp) << endl;
    if ( fabs(tmp - round(tmp))<epsilon ) {
      DrawLine(x1,y1-bigticsize,x1,y1+bigticsize);
    }
    if ( fabs(tmp-0.5 - (round(tmp-0.5)))<epsilon ) {
      DrawLine(x1,y1-mediumticsize,x1,y1+mediumticsize);
    }
    else {
      DrawLine(x1,y1-smallticsize,x1,y1+smallticsize);
    }
    xpos += xstep;
  }

  // from xaxis,ymin to xaxis,ymax
  World2Window(_xaxis,_ymin,x1,y1);
  World2Window(_xaxis,_ymax,x2,y2);
  DrawLine(x1,y1,x2,y2);

  // draw tics
  ypos = ymintic;
  while (ypos<=_ymax) {
    World2Window(_xaxis,ypos,x1,y1);
    double tmp = ypos/ybigstep;
    if ( fabs(tmp - round(tmp))<epsilon ) {
      DrawLine(x1-bigticsize,y1,x1+bigticsize,y1);
    }
    else 
    if ( fabs(tmp-0.5 - (round(tmp-0.5)))<epsilon ) {
      DrawLine(x1-mediumticsize,y1,x1+mediumticsize,y1);
    }
    else 
      DrawLine(x1-smallticsize,y1,x1+smallticsize,y1);
    ypos += ystep;
  }



}


//------------------------------------------------
void wxDrawingWindow::DrawControls()
{
  scoped_ptr<wxPen> current_pen( new wxPen( *wxBLACK, 1, PENSTYLE_SOLID));
  _memory_dc->SetPen(*current_pen);
  
  for(int i = 0; i<(int)_controlpoints.size(); i++) 
  {
    if (_controlpoints[i].HasFocus()) {
      _memory_dc->SetBrush(*wxTRANSPARENT_BRUSH);
      _memory_dc->SetPen(wxPen(_controlpoints[i].GetColour()));
    }
    else {
      _memory_dc->SetBrush(wxBrush(_controlpoints[i].GetColour()));
//      _memory_dc->SetLogicalFunction(wxOR_REVERSE);
//      _memory_dc->SetBrush(*wxTRANSPARENT_BRUSH);
//      _memory_dc->SetPen(wxPen(_controlpoints[i].GetColour()));
      _memory_dc->SetPen(wxPen(*wxBLACK));
    }
    wxCoord px,py;
    World2Window(_controlpoints[i].GetX(),_controlpoints[i].GetY(),px,py);
    _controlpoints[i].SetwxPoint(wxPoint(px,py));
    _memory_dc->DrawCircle(px,py,_controlpoints[i].GetRadius());
//    _memory_dc->SetLogicalFunction(wxCOPY);
  }
}


//---------------------------------------------------------------------
void wxDrawingWindow::DrawingAreaDisplay( )
//                  ------------------
{
  if (_memory_dc.get()) {
    wxClientDC dc(this);
    if (dc.IsOk()) {

      dc.Blit(0,0,
        _memory_dc->GetSize().GetWidth(),
        _memory_dc->GetSize().GetHeight(),
        _memory_dc.get(),
        0,0);

    } else 
      CLASS_ERROR( "DC not OK");

  } else {
    CLASS_ERROR("context not allocated" );
  }

} // DrawingAreaDisplay( )

//------------------------------------------------
void wxDrawingWindow::Paint()
{

  if (!_memory_dc.get()) DrawingAreaInit( );
  // Clip the drawing
  wxRect rect(_memory_dc->GetSize());
  wxDCClipper clip(*_memory_dc,rect);
  scoped_ptr<wxPen> current_pen(
    new wxPen( *wxBLACK, 1, PENSTYLE_SOLID));

  _memory_dc->SetPen(*current_pen);
  _memory_dc->SetAxisOrientation(true,false);
  _memory_dc->SetBrush(*wxRED_BRUSH);

  // Get window dimensions
  wxSize _sz = GetClientSize();

  //_memory_dc->SelectObject(*_bitmap);
  _memory_dc->SetBackground(this->GetBackgroundColour());
  _memory_dc->Clear();

  //dc.DrawRectangle(rectToDraw);
  _memory_dc->SetPen(*wxBLACK_PEN);
  DrawAxes();
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
      case 0: wxstyle=PENSTYLE_SOLID;       break;
      case 1: wxstyle=wxDOT;         break;
      case 2: wxstyle=wxLONG_DASH;   break;
      case 3: wxstyle=wxSHORT_DASH;  break;
      case 4: wxstyle=wxDOT_DASH;    break;
      default: wxstyle=wxSOLID;
    }
    current_pen->SetStyle( wxstyle);
    current_pen->SetWidth( _curves[i].GetWidth());
    _memory_dc->SetPen(*current_pen);
    DrawCurve(i);
  }
  DrawControls();
  DrawingAreaDisplay();
}


//-------------------------------------------------
void wxDrawingWindow::OnPaint(wxPaintEvent& event)
{
  wxPaintDC pdc(this);
  PrepareDC(pdc);

  //DrawingAreaInit( );
  Paint();
  event.Skip();
}

//-------------------------------------------------
void wxDrawingWindow::OnSize(wxSizeEvent& event)
{
  DrawingAreaInit( );
  Paint();
  event.Skip();
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

  // check if we are at a control point
  //int closest = CheckCtrlPoint();

  // create the popup menu here
  wxMenu menu(_T("Menu"));
  if (focus_pointid==-1) {
    menu.Append(wxID_AddControl, wxT("&Add control point"));
    wxMenuItem* menu_showgrid = menu.AppendCheckItem(wxID_ShowGrid,wxT("Enable &Grid"));
    menu_showgrid->Check(this->_draw_grid);
  } else {
    menu.Append(wxID_RemoveControl, wxT("&Remove control point"));
    menu.Append(wxID_SetControlColour, wxT("&Colour"));
   }
  PopupMenu(&menu, _mouse_x,_mouse_y);
  event.Skip();

}

//-------------------------------------------------
int wxDrawingWindow::CheckCtrlPoint()
{
  double mindist = 1000;
  int closest = -1;

  // search for closest controlpoints
  for(int i=0;i<(int)_controlpoints.size();i++) {
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

  return closest;
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

      // Check if a Control point callback was set,
      // if so, call the function with its parameters
      if (_ctrlpt_callback.get()) {
        bool ok = (*_ctrlpt_callback)();
        if (!ok) _ctrlpt_callback.reset();
      }

      Refresh(false);
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
      WriteCurrentPosition(dc);
    }
    event.Skip();
    return;
  }

  int closest = CheckCtrlPoint();
/*
  double mindist = 1000;
  int closest = -1;

  // search for closest controlpoints
  for(int i=0;i<(int)_controlpoints.size();i++) {
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
*/
  if (closest!=-1) {
    _controlpoints[closest].SetFocus(true);
  }
  focus_pointid = closest;
  Refresh(false);
  
  event.Skip();
/*
  CLASS_MESSAGE(boost::format("At position %1% %2%")%_mouse_x%_mouse_y);
  double x,y;
  Window2World(_mouse_x,_mouse_y,x,y);
  CLASS_MESSAGE(boost::format("world coord %1% %2%")%x%y);
*/
}

//-------------------------------------------------
void wxDrawingWindow::OnWheel(wxMouseEvent& event)
{
  wxClientDC dc(this);
  int wr = event.GetWheelRotation();

  _mouse_x = (int)event.GetX();
  _mouse_y = (int)event.GetY();
  double x,y;
  Window2World(_mouse_x,_mouse_y,x,y);

  // now apply a zoom centered on the current position in X direction
  double xmin = _xmin;
  double xmax = _xmax;

  double step  = ((double)wr)/(5.0*(double)event.GetWheelDelta());
  if (step > 7 ) step = 7;
  if (step < -7) step = -7;
  double zoom_factor  = exp( step*log2f(2));

  _xmin = x - (x-_xmin)/zoom_factor;
  _xmax = x + (_xmax - x)/zoom_factor;

  Refresh(false);
  event.Skip();

}

//-------------------------------------------------
void wxDrawingWindow::OnAddControl(wxCommandEvent& event)
{
  double x,y;
  Window2World(_mouse_x,_mouse_y,x,y);
  AddControl(dw_Point2D(x,y));
  Refresh(false);
}

//-------------------------------------------------
void wxDrawingWindow::OnRemoveControl(wxCommandEvent& event)
{
  RemoveControl(focus_pointid);
  Refresh(false);
}

//-------------------------------------------------
void wxDrawingWindow::OnControlColour(wxCommandEvent& event)
{
  // Select the new colour
  wxColourData data;
  data.SetColour( _controlpoints[focus_pointid].GetColour());
  wxColourDialog dialog(this, &data);

  if ( dialog.ShowModal() == wxID_OK )
  {
    _controlpoints[focus_pointid].SetColour( dialog.GetColourData().GetColour());
  }
  Refresh(false);
}

//-------------------------------------------------
void wxDrawingWindow::OnShowGrid(wxCommandEvent& event)
{
  this->_draw_grid = event.IsChecked();
  Refresh(false);
}
