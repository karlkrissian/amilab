//
// C++ Implementati/*on*/: wxDrawingWindow
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#include "wxDrawingWindow.h"

#include "amilab_messages.h"
#include "wx/dcclient.h"
#include <wx/menu.h>

#include <wx/cmndata.h>
#include <wx/colordlg.h>
#include <iostream>

#define macro_max(a,b) ((a)>(b)?(a):(b))

#if wxUSE_GRAPHICS_CONTEXT && wxCHECK_VERSION(2, 9, 0)
  #define AMI_USE_wxGC 1
#else
  #define AMI_USE_wxGC 0
#endif

#if AMI_USE_wxGC
  #include <wx/dcgraph.h> 
  #include <wx/graphics.h>
#endif

#if wxCHECK_VERSION(2, 9, 0)
  #define PENSTYLE_SOLID wxPENSTYLE_SOLID 
#else
  #define PENSTYLE_SOLID wxSOLID 
#endif

#include <limits>

enum {
  wxID_AddControlPoint = 2000,
  wxID_RemoveControl,
  wxID_DuplicateControl,
  wxID_AddControlledCurve,
  wxID_RemoveControlledCurve,
  wxID_ColormapControlledCurve,
  wxID_LimitControlledCurve,
//  wxID_ColormapPoint,
  wxID_VerticalLine,
  wxID_YLocked,
  wxID_SetControlColour,
  wxID_ShowGrid,
};

BEGIN_EVENT_TABLE(wxDrawingWindow, wxWindow)
  EVT_PAINT(        wxDrawingWindow::OnPaint)
  EVT_SIZE(         wxDrawingWindow::OnSize)
  EVT_RIGHT_DOWN(   wxDrawingWindow::OnRightDown)
  EVT_LEFT_DOWN(    wxDrawingWindow::OnLeftDown)
  EVT_LEFT_UP(      wxDrawingWindow::OnLeftUp)
  EVT_MOTION(       wxDrawingWindow::OnMotion)
  EVT_MOUSEWHEEL(   wxDrawingWindow::OnWheel)
  EVT_MENU(         wxID_AddControlPoint,    wxDrawingWindow::OnAddControlPoint)
  EVT_MENU(         wxID_AddControlledCurve, wxDrawingWindow::OnAddControlledCurve)
  EVT_MENU(         wxID_RemoveControlledCurve, wxDrawingWindow::OnRemoveControlledCurve)
  EVT_MENU(         wxID_ColormapControlledCurve, wxDrawingWindow::OnColormapControlledCurve)
  
  EVT_MENU(         wxID_LimitControlledCurve, wxDrawingWindow::OnLimitControlledCurve)
  
  EVT_MENU(         wxID_RemoveControl,      wxDrawingWindow::OnRemoveControl)
  EVT_MENU(         wxID_DuplicateControl,   wxDrawingWindow::OnDuplicateControl)
//  EVT_MENU(         wxID_ColormapPoint,    wxDrawingWindow::OnColormapPoint)
  EVT_MENU(         wxID_VerticalLine,       wxDrawingWindow::OnVerticalLine)
  EVT_MENU(         wxID_YLocked,            wxDrawingWindow::OnYLocked)
  EVT_MENU(         wxID_SetControlColour,   wxDrawingWindow::OnControlColour)
  EVT_MENU(         wxID_ShowGrid,           wxDrawingWindow::OnShowGrid)
END_EVENT_TABLE();

//------------------------------------------------
wxDrawingWindow::wxDrawingWindow(wxWindow *parent, wxWindowID id,
    const wxPoint& pos, const wxSize& size, long style,
    const wxString& name)
    :
#ifdef __APPLE__
  wxWindow(parent,id,pos,size,style)
#else
  wxScrolledWindow(parent, id, pos, size, style
    |wxFULL_REPAINT_ON_RESIZE
    //|wxDOUBLE_BORDER
    |wxBORDER_RAISED
    | wxHSCROLL | wxVSCROLL
    , 
    name) 
#endif
{
  this->_linearCM_uptodate = false;
  
#ifndef __APPLE__
  this->SetScrollbars(3,3,10,10);
  this->EnableScrolling(true,true);
#endif

  _focus_point.reset();
  _focus_pointset.reset();
  _focus_controlledcurve.reset();

  _left_down = false;
  _previous_crosshair = false;

  // default values
  _xaxis = _yaxis = 0;
  _xmin = _ymin = -10;
  _xmax = _ymax = 10;
  
  // set minimal range to 0.01
  _min_xrange = 1E-2;
  // set maximal range to 100 000
  _max_xrange = 1E5;

  _draw_grid = true;
  _draw_linearCM=true;
  _linearCM_margin_size = wxSize(0,7);

  // Create the list of control points within a smart pointer
  _controlpoints = boost::shared_ptr<vector_dwControlPoint>(new vector_dwControlPoint());
  _curves = boost::shared_ptr<vector_dwCurve>(new vector_dwCurve());
  _controlled_curves = boost::shared_ptr<vector_dwControlledCurve>(new vector_dwControlledCurve());
  
  _within_popupmenu = false;
}


//---------------------------------------------------------------------
void wxDrawingWindow::DrawingAreaInit( )
//                  --------------
{
  if (!this->IsShown())   return;

  int w = this->GetClientSize().GetWidth();
  int h = this->GetClientSize().GetHeight();
  
  // wx way
  boost::scoped_ptr<wxBitmap> bitmap(new wxBitmap( w,h,-1));
  swap(_bitmap,bitmap);

  wxMemoryDC* mdc = new wxMemoryDC();
  mdc->SelectObject(*_bitmap);

/*#if wxUSE_GRAPHICS_CONTEXT
  std::cout << "wxUSE_GRAPHICS_CONTEXT" << std::endl;
#endif
#if wxCHECK_VERSION(2, 8, 11)
  std::cout << "version >= 2.8.11" << std::endl;
#endif*/
  #if AMI_USE_wxGC
    // keep initial memory DC in a scoped pointer
    boost::scoped_ptr<wxMemoryDC> init_memory_dc(mdc);
    swap(_init_memory_dc, init_memory_dc);
    // use a Graphic Context to draw in memory
    wxGCDC* gdc = new wxGCDC( *mdc );
    boost::scoped_ptr<wxDC> memory_dc(gdc);
  #else
    boost::scoped_ptr<wxDC> memory_dc(mdc);
  #endif

  swap(_memory_dc, memory_dc);
  _memory_dc->SetBackgroundMode(wxTRANSPARENT);
} // DrawingAreaInit( )



//------------------------------------------------
void wxDrawingWindow::World2Window(  double x, double y, wxCoord& wx, wxCoord& wy) const
{
  wxSize _sz = GetClientSize();
  if (_draw_linearCM) _sz = _sz-_linearCM_margin_size;

  int px = 0,py = 0;
  px = (int) ((float)(_sz.x-1)/(_xmax-_xmin)*(x-_xmin)+0.5);
  py = (int) ((float)(_sz.y-1)-(float)(_sz.y-1)/(_ymax-_ymin)*(y-_ymin)+0.5);

  wx = px;
  wy = py;
/*
  wx = macro_max(-1,px);
  wy = macro_max(-1,py);
  if (wx>_sz.x) wx = _sz.x;
  if (wy>_sz.y) wy = _sz.y;
*/
}

//------------------------------------------------
wxCoord wxDrawingWindow::World2WindowX( double x) const
{
  wxSize _sz = GetClientSize();
  return (wxCoord) ((float)(_sz.x-1)/(_xmax-_xmin)*(x-_xmin)+0.5);
}


//------------------------------------------------
double wxDrawingWindow::Window2WorldX( const  wxCoord& wx ) const
{
  wxSize _sz = GetClientSize();
  return _xmin + ((float) wx)/(_sz.x-1)*(_xmax-_xmin);
}

//------------------------------------------------
void wxDrawingWindow::Window2World(  wxCoord wx, wxCoord wy, double& x, double& y) const
{
  wxSize _sz = GetClientSize();
  if (_draw_linearCM) _sz = _sz-_linearCM_margin_size;

  x = _xmin + ((float) wx)/(_sz.x-1)*(_xmax-_xmin);
  y = _ymin + ((float) (_sz.y-1-wy) )/(_sz.y-1)*(_ymax-_ymin);
}

//------------------------------------------------
void wxDrawingWindow::AddImageToCurve( InrImage* im, dwCurve& c)
{
  double x1,y1;
  if (im->GetVDim()==1) {
    // Go through the points and add them to the curve
    for(int x=0;x<im->DimX();x++) {
      x1 = im->SpacePosX(x);
      y1 = (*im)(x,0,0);
      c.AddPoint(dwPoint2D(x1,y1));
    }
  }

  if (im->GetVDim()==2) {
    // Go through the points and add them to the curve
    for(int x=0;x<im->DimX();x++) {
      x1 = (*im)(x,0,0.0);
      y1 = (*im)(x,0,0,1);
      c.AddPoint(dwPoint2D(x1,y1));
    }
  }

}

//------------------------------------------------
void wxDrawingWindow::AddCurve( InrImage* im)
{
  // new curve
  dwCurve c;

  AddImageToCurve(im,c);

  // Add the curve
  _curves->push_back(c);
}

//------------------------------------------------
bool wxDrawingWindow::SetCurve( int i, InrImage* im)
{

  if ((i>=0)&&(i<(int)_curves->size())) {
    // new curve
    dwCurve c;
  
    AddImageToCurve(im,c);
    (*_curves)[i].GetPoints() = c.GetPoints();
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
void wxDrawingWindow::AddControlPoint( const dwControlPoint& pt)
{
  _controlpoints->push_back(pt);
}

/**
  * Removes a new control point
  * @param control point id
  */
void wxDrawingWindow::RemoveControl()
{
  vector_dwControlPoint::iterator it;
  for ( it  = _focus_pointset->begin(); 
        it != _focus_pointset->end(); 
        it++) {
    if (_focus_point.get() == &(*it)) {
      it = _focus_pointset->erase(it);
      return;
    }
  }
  //  _controlpoints->erase(_controlpoints->begin()+pt_id);
}

/**
  * Duplicates a new control point
  */
void wxDrawingWindow::DuplicateControl()
{
  //int n1 = 0;
  vector_dwControlPoint::iterator it;
  //n1 = (int) _focus_pointset->size();
  _focus_pointset->push_back(_focus_pointset->back());
  //n1 = (int) _focus_pointset->size();
  it  = _focus_pointset->end(); // past to end
  it-=2; 

  while (
          (&(*it) != _focus_point.get()) &&
          (    it != _focus_pointset->begin())
        )
  { 
    (*it) = (*(it-1));
    it--;
  }
  if (&(*it) == _focus_point.get())
  {
    // displace a little bit the new point
    double x2 = it->GetX();
    double y2 = it->GetY();
    it++;
    if ((it+1) != _focus_pointset->end()) {
      it++;
      double x1 = it->GetX();
      double y1 = it->GetY();
      it--;
      SetCtrlPointPosition(*it,
                           x2+(x1-x2)/5.0,
                           y2+(y1-y2)/5.0);
    } else {
      SetCtrlPointPosition(*it,
                           Window2WorldX( World2WindowX(x2)+it->GetRadius()),
                           y2);
    }
  }
}

/**
  * Set the new position of a new control point
  * @param control point
  */
void wxDrawingWindow::SetControl( int i, const dwPoint2D& pt)
{
  if ((i>=0)&&(i<(int)_controlpoints->size())) {
    (*_controlpoints)[i] = pt;
  }
}


//------------------------------------------------
void wxDrawingWindow::SetCurveDrawPoints( int i, bool dp)
{
  if ((i>=0)&&(i<(int)_curves->size())) {
    (*_curves)[i].SetDrawPoints(dp);
  }
}

//------------------------------------------------
void wxDrawingWindow::SetCurveDrawLines( int i, bool dp)
{
  if ((i>=0)&&(i<(int)_curves->size())) {
    (*_curves)[i].SetDrawLines(dp);
  }
}

//------------------------------------------------
void wxDrawingWindow::SetCurveColor( int i, std::string color_string)
{
  if ((i>=0)&&(i<(int)_curves->size())) {
    (*_curves)[i].SetColour(wxColour(wxString(color_string.c_str(), wxConvUTF8)));
  }
}

//------------------------------------------------
void wxDrawingWindow::SetCurveStyle( int i, int style)
{
  if ((i>=0)&&(i<(int)_curves->size())) {
    (*_curves)[i].SetStyle(style);
  }
}

//------------------------------------------------
void wxDrawingWindow::SetCurveWidth( int i, int width)
{
  if ((i>=0)&&(i<(int)_curves->size())) {
    (*_curves)[i].SetWidth(width);
  }
}

//------------------------------------------------
void wxDrawingWindow::DrawCurve( dwCurve& curve )
{
  boost::scoped_ptr<wxPen> current_pen(
    new wxPen( *wxBLACK, 1, PENSTYLE_SOLID));
  current_pen->SetColour(curve.GetColour());
  /*
  0: wxSOLID   Solid style.
  1: wxDOT   Dotted style.
  2: wxLONG_DASH   Long dashed style.
  3: wxSHORT_DASH  Short dashed style.
  4: wxDOT_DASH  Dot and dash style. 
  */
  int wxstyle=wxSOLID;
  switch (curve.GetStyle()) {
    case 0: wxstyle=PENSTYLE_SOLID;       break;
    case 1: wxstyle=wxDOT;         break;
    case 2: wxstyle=wxLONG_DASH;   break;
    case 3: wxstyle=wxSHORT_DASH;  break;
    case 4: wxstyle=wxDOT_DASH;    break;
    default: wxstyle=wxSOLID;
  }
  current_pen->SetStyle( wxstyle);
  current_pen->SetWidth( curve.GetWidth());
  _memory_dc->SetPen(*current_pen);

  std::vector<dwPoint2D>& _points = curve.GetPoints();
  // iterate through the curves
  std::vector<dwPoint2D>::iterator it;
  wxCoord x1=0,y1=0,x2=0,y2=0;

  wxCoord mincoord = std::numeric_limits< short >::min();
  wxCoord maxcoord = std::numeric_limits< short >::max();

  for(it=_points.begin();it!=_points.end();it++)
  {
    // draw line from previous to current point
    World2Window(it->GetX(),it->GetY(),x2,y2);
    // seems to be a problem with values out of 'short int' range
    if (x2<mincoord) x2=mincoord;
    if (x2>maxcoord) x2=maxcoord;
    if (y2<mincoord) y2=mincoord;
    if (y2>maxcoord) y2=maxcoord;
    if (curve.GetDrawLines())
      if (it!=_points.begin()) {
        DrawLine(x1,y1,x2,y2);
      }
    if (curve.GetDrawPoints())
      DrawPoint(x1,y1);
    x1 = x2;
    y1 = y2;
  }

}


//------------------------------------------------
void wxDrawingWindow::DrawCurves(  )
{
  for (int i=0; i<GetNumberOfCurves(); i++)
    DrawCurve((*_curves)[i]);

  for (int i=0; i<(int)_controlled_curves->size(); i++) {
    // TODO: only recompute curve in case of motion of a point ...
    (*_controlled_curves)[i].ComputeCurve();
    dwCurve::ptr curve((*_controlled_curves)[i].GetCurve());
    if (curve.get()) DrawCurve(*curve);
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
  //cout << "xstep = " << xstep << std::endl;
  double xmintic = floor(_xmin/xstep)*xstep;
  //cout << "xmintic = " << xmintic << std::endl;

  // automatic step computation
  int ysizelog = floor(log10(_ymax-_ymin));
  double ybigstep = pow(10.0,ysizelog);
  double ystep    = ybigstep/10.0;
  double ymintic = floor(_ymin/ystep)*ystep;

  wxCoord x1,y1,x2,y2;
  double xpos,ypos;

  boost::scoped_ptr<wxPen> current_pen2( new wxPen( *wxLIGHT_GREY, 1, wxDOT));// PENSTYLE_SOLID));
  _memory_dc->SetPen(*current_pen2);

  if (_draw_grid)
  {
    xpos = xmintic;
    while (xpos<=_xmax) {
      World2Window(xpos,_yaxis,x1,y1);
      double tmp = xpos/xbigstep;
      //cout << " tmp " << tmp << std::endl;
      //cout << " tmp -round(tmp)" << tmp - round(tmp) << std::endl;
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


  boost::scoped_ptr<wxPen> current_pen( new wxPen( *wxBLACK, 1, PENSTYLE_SOLID));
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
    //cout << " tmp " << tmp << std::endl;
    //cout << " tmp -round(tmp)" << tmp - round(tmp) << std::endl;
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

inline double InterpolateAlpha( const double& a1,  const double& w1,const double& a2,  const double& w2)
{
  double sum = w1+w2;
  if (sum==0){
    //std::cout<< "Alpha == 0 " << std::endl;
    return 0;
  }
  return (a1*w1+a2*w2)/sum;
}

inline double InterpolateMidpoint( const double& a1,  const double& w1,const double& a2,  const double& w2)
{
  double sum = w1+w2;
  if (sum==0){
    //std::cout<< "Alpha == 0 " << std::endl;
    return a1;
  }
  return (a1*w1+a2*w2)/sum;
}


inline double InterpolateSharpness( const double& a1,  const double& w1,const double& a2,  const double& w2)
{
  double sum = w1+w2;
  if (sum==0){
    //std::cout<< "Alpha == 0 " << std::endl;
    return a1;
  }
  return (a1*w1+a2*w2)/sum;
}


inline wxColour InterpolateColour( const wxColour& c1, const double& w1, 
                            const wxColour& c2, const double& w2)
{
  double sum = w1+w2;
  if (sum==0){ 
    //std::cout<< "Colour == 0 " << std::endl;
    return c1;
  }
  return wxColour(  (unsigned char) ((w1*c1.Red()  +w2*c2.Red()  )/sum),
                    (unsigned char) ((w1*c1.Green()+w2*c2.Green())/sum),
                    (unsigned char) ((w1*c1.Blue() +w2*c2.Blue() )/sum)  );
}


//------------------------------------------------
// LinearColorMap wxDrawingWindow::GetLinearCM()
// {
//   return _linearCM;
// }

//------------------------------------------------
void wxDrawingWindow::DrawLinearCM(  )
{
  wxColour c1;
  wxColour c2;
  double coeff1;
  double coeff2;
  double w1;
  double w2;
  double e=0.01;

  if (!_draw_linearCM) return;

  wxSize _sz = GetClientSize();

  // need to 
  // 1: sort the points
  // 2: draw each rectangle between 2 successive points

  if (!_linearCM_uptodate) {
    // Add 2 points to the linearcolormap
    _linearCM.clear();
    // first fill the current colormap control points with their positions
    int ncolourcurves=0;
    for(int c=0; c<(int) _controlled_curves->size();c++)
    {
      if (!((*_controlled_curves)[c].GetType()==colormap_curve))
        continue;
      ncolourcurves++;
      boost::shared_ptr<vector_dwControlPoint> points_ptr = (*_controlled_curves)[c].GetControlPoints();
      vector_dwControlPoint points = (*points_ptr);
      if ((*_controlled_curves)[c].isLimited())
      {
        //Add limits
        dwControlPoint p_ant = points.front();
        dwControlPoint p_post = points.back();
        p_ant. SetPos(p_ant.GetX()-e,0.0);
        p_post.SetPos(p_post.GetX()+e,0.0);
        points.insert(points.begin(),p_ant);
        points.push_back(p_post);
      }
   
      for(int i = 0; i<(int) points.size(); i++) 
      {  
          _linearCM.AddPoint(LinearColorMapPoint(points[i].GetX(),points[i].GetY(),
                                                points[i].GetColour()));
      }
    }
    // second compute the left and right colours of each point
    int cm_size = _linearCM.size();
    //std::cout<< "cm_size = " << cm_size << std::endl;
    std::vector<wxColour> left_colours(cm_size,*wxBLACK);
    std::vector<wxColour> right_colours(cm_size,*wxBLACK);
    std::vector<double> alphas(cm_size,0.0); //Alpha
    std::vector<double> midpoint(cm_size,0.0);
    std::vector<double> sharpness(cm_size,0.0);
    std::vector<double> weights(cm_size,0.0);
    for(int c=0; c<(int) _controlled_curves->size();c++)
    {
      if (!((*_controlled_curves)[c].GetType()==colormap_curve))
        continue;

      //std::cout<< "c = " << c << std::endl;
      boost::shared_ptr<vector_dwControlPoint> points_ptr = (*_controlled_curves)[c].GetControlPoints();
      vector_dwControlPoint points = (*points_ptr);
      if ((*_controlled_curves)[c].isLimited())
      {
        //Add limits
        dwControlPoint p_ant = points.front();
        dwControlPoint p_post = points.back();
        p_ant. SetPos(p_ant.GetX()-e,0.0);
        p_post.SetPos(p_post.GetX()+e,0.0);
        points.insert(points.begin(),p_ant);
        points.push_back(p_post);
        //std::cout<< "Add limits = " << points_ptr->size() << " " << points.size() << std::endl;
      }

      int cmpt_id   = 0; // colormap point id
      int curvpt_id = 0; // curve point id
      // while it is possible:
      // get the current segment
      // fill all the points within the current segment
      while ((curvpt_id+1 < (int)points.size())&&(cmpt_id<cm_size)) {
        //std::cout<< "curvpt_id = " << curvpt_id << std::endl;
        // current segment is between points[curvpt_id] and points[curvpt_id+1]
        dwControlPoint p1 = points[curvpt_id];
        dwControlPoint p2 = points[curvpt_id+1];
        double pos = _linearCM.GetPoint(cmpt_id).GetPosition();
        
        while ((pos<p1.GetX())&&(cmpt_id<cm_size)) {
          cmpt_id++;
          pos = _linearCM.GetPoint(cmpt_id).GetPosition();
        }
        //std::cout<< "cmpt_id = " << cmpt_id << std::endl;
        //std::cout<< "pos = " << pos << std::endl;
        if (cmpt_id<cm_size) {
          while ((pos<=p2.GetX())&&(cmpt_id<cm_size)) {
            // pos is within p1 and p2, interpolate colour and weight
            c1 = p1.GetColour();
            c2 = p2.GetColour();
            coeff1 = p2.GetX()-pos;
            coeff2 = pos-p1.GetX();
            w1 = p1.GetY();
            w2 = p2.GetY();
            if (w1<0) w1=0;
            if (w2<0) w2=0;
            wxColour current_colour   = InterpolateColour(c1,coeff1,c2,coeff2);
            double current_sharpness  = InterpolateSharpness(p1.Getsharpness(),
                                               coeff1,p2.Getsharpness(),coeff2);
            double current_midpoint   =InterpolateMidpoint(p1.Getmidpoint(),
                                               coeff1,p2.Getmidpoint(),coeff2);
            double current_weight;
            if(coeff1+coeff2==0) current_weight=0;
            else current_weight= (w1*coeff1+w2*coeff2)/(coeff1+coeff2);
            //std::cout << "cmpt_id = " << cmpt_id << std::endl;
            //std::cout<< "current_colour = " << current_colour.GetAsString().ToAscii() << std::endl;
            left_colours[cmpt_id] =
                InterpolateColour(current_colour,current_weight,
                                  left_colours[cmpt_id], weights[cmpt_id]);
            //std::cout<< "left_colour = " << left_colours[cmpt_id].GetAsString().ToAscii() << std::endl;
            right_colours[cmpt_id] =
                InterpolateColour(current_colour,current_weight,
                                  right_colours[cmpt_id], weights[cmpt_id]);
            //std::cout<< "right_colour = " << right_colours[cmpt_id].GetAsString().ToAscii() << std::endl;
    
            //std::cout<< "p1.GetY() = " << p1.GetY() << std::endl;
            //std::cout<< "p2.GetY() = " << p2.GetY() << std::endl;      
                
            alphas[cmpt_id] =InterpolateAlpha(current_weight,current_weight,
                                              alphas[cmpt_id], weights[cmpt_id]);
   
            midpoint[cmpt_id] =InterpolateMidpoint(current_midpoint,current_weight,
                                  midpoint[cmpt_id], weights[cmpt_id]);
            
            sharpness[cmpt_id] =InterpolateSharpness(current_sharpness,current_weight,
                                  sharpness[cmpt_id], weights[cmpt_id]);       
            
            weights[cmpt_id] += current_weight;

            cmpt_id++;
        if (cmpt_id<cm_size)
            pos = _linearCM.GetPoint(cmpt_id).GetPosition();
          }
        }
        curvpt_id++;
      }
      
    }

    // now fill the colours
    for (int c=0; c<cm_size; c++)
    {
      _linearCM.GetPoint(c).SetLeftColour (left_colours [c]);
      _linearCM.GetPoint(c).SetRightColour(right_colours[c]);
      _linearCM.GetPoint(c).SetAlpha      (alphas[c]);
      _linearCM.GetPoint(c).SetMidpoint   (midpoint[c]);
      _linearCM.GetPoint(c).SetSharpness  (sharpness[c]);
    }

    // Call the events related to the update of the colormap
    if (ncolourcurves>0){
      _linearCM_uptodate = true;
      if (_linearcolormap_callback.get()) {
        bool ok = (*_linearcolormap_callback)();
        if (!ok) _linearcolormap_callback.reset();
      }
    }
  }
  
  // the points are already sorted
  //_linearCM.sort();

  // 
  if (_linearCM.size()>=2) {
    // just need x1 and x2 here
    wxCoord x1=0,x2=0;
    
    for (int i=0;i<_linearCM.size(); i++)
    {
      x2 = World2WindowX(_linearCM.GetPoint(i).GetPosition());

/*
    if (x2<0) {
        x2=0;
        current_colour = _linearCM.InterpolateColour(Window2WorldX(x2));
      } else 
      if (x2>=_sz.x) {
        x2=_sz.x-1;
        current_colour = _linearCM.InterpolateColour(Window2WorldX(x2));
      } else {
        current_colour = _linearCM.GetPoint(i).GetColour();
      }
*/
      if (i>0) {
        _memory_dc->GradientFillLinear(
          wxRect( wxPoint(x1,_sz.y-_linearCM_margin_size.GetHeight()),
                  wxPoint(x2,_sz.y-1)),
          _linearCM.GetPoint(i-1).GetRightColour(),
          _linearCM.GetPoint(i).GetLeftColour());
      }
      x1 = x2;
    }
  }
}


//------------------------------------------------
void wxDrawingWindow::DrawControlPoint( dwControlPoint& pt, 
                const wxColour& visible_colour, 
                const wxSize& _sz,
                bool colormap)
{
  wxCoord px,py;
  World2Window(pt.GetX(),pt.GetY(),px,py);
  if (colormap) {
    wxPen pen(visible_colour);
    pen.SetStyle(wxSHORT_DASH);
    _memory_dc->SetPen(pen);
    _memory_dc->DrawLine(px,py,px,_sz.y-_linearCM_margin_size.GetHeight());
  } else {
    if (pt.GetVerticalLine()) {
      _memory_dc->SetPen(wxPen(visible_colour));
      _memory_dc->DrawLine(px,0,px,_sz.y-_linearCM_margin_size.GetHeight());
    }
  }

  if (pt.HasFocus()) {
    _memory_dc->SetBrush(*wxTRANSPARENT_BRUSH);
    if (pt.GetColour()!=GetBackgroundColour()) {
      _memory_dc->SetPen(wxPen(pt.GetColour()));
    } else {
      _memory_dc->SetPen(wxPen(visible_colour));
    }
  }
  else {
    _memory_dc->SetBrush(wxBrush(pt.GetColour()));
    _memory_dc->SetPen(wxPen(visible_colour));
  }
  pt.SetwxPoint(wxPoint(px,py));
  _memory_dc->DrawCircle(px,py,pt.GetRadius());
}

//------------------------------------------------
void wxDrawingWindow::DrawControlPoints()
{
  boost::scoped_ptr<wxPen> current_pen( new wxPen( *wxBLACK, 1, PENSTYLE_SOLID));
  _memory_dc->SetPen(*current_pen);
  wxSize _sz = GetClientSize();

  wxColour c = GetBackgroundColour();
  wxColour visible_colour((128+c.Red()  )% 255,
                          (128+c.Green())% 255,
                          (128+c.Blue() )% 255);
  
  
  for(int i = 0; i<(int)_controlpoints->size(); i++) 
  {
    DrawControlPoint((*_controlpoints)[i],visible_colour, _sz);
  }

  // now draw control points that belong to a ControlledCurve
  for(int i = 0; i<(int)_controlled_curves->size(); i++) 
  {
    boost::shared_ptr<vector_dwControlPoint> points( (*_controlled_curves)[i].GetControlPoints());
    for(int j = 0; j<(int)points->size(); j++) 
    DrawControlPoint((*points)[j],visible_colour, _sz,
                      (*_controlled_curves)[i].GetType()==colormap_curve);
  }
}

//------------------------------------------------
//------------------------------------------------
void wxDrawingWindow::DrawControls()
{
  DrawControlPoints();
}

//----------------------------------------------------------------------
void wxDrawingWindow::SetCtrlPointPosition(dwControlPoint& p, 
                                           double x, double y)
{
  p.SetX(x);
  if (y<_y_epsilon) p.SetY(_y_epsilon);
    else if (y>_ymax-_y_epsilon) p.SetY(_ymax-_y_epsilon);
      else p.SetY(y);
}

  
//---------------------------------------------------------------------
void wxDrawingWindow::DrawingAreaDisplay( bool in_paint)
//                  ------------------
{
  if (_memory_dc.get()) {
/*    #if AMI_USE_wxGC
      wxGraphicsContext *gc = wxGraphicsContext::Create( this );
      if (gc) {
        gc->DrawBitmap(*_bitmap,0,0,_bitmap->GetWidth(),_bitmap->GetHeight());
      }
    #else*/
      wxDC* dc;
      if (in_paint)
        dc = new wxPaintDC(this);
      else
        dc = new wxClientDC(this);
#ifndef __APPLE__
      PrepareDC(*dc);
#endif

      //std::cout << " in paint " << in_paint << "  dc size is " << dc->GetSize().GetWidth() << "x" << dc->GetSize().GetHeight() << std::endl;
      if (dc->IsOk()) {
        #if AMI_USE_wxGC
          dc->DrawBitmap(*_bitmap,0,0);
        #else
          //std::cout << "Blit to dc " << std::endl;
          dc->Blit(0,0,
            _memory_dc->GetSize().GetWidth(),
            _memory_dc->GetSize().GetHeight(),
            _memory_dc.get(),
            0,0);
        #endif
      } else 
        CLASS_ERROR( "DC not OK");
      delete dc;
//     #endif

  } else {
    CLASS_ERROR("context not allocated" );
  }

} // DrawingAreaDisplay( )

//------------------------------------------------
void wxDrawingWindow::Paint( bool in_paint)
{

  if (!_curves.get()) return;
  
  if (!_memory_dc.get()) DrawingAreaInit( );
  // Clip the drawing
  wxRect rect(_memory_dc->GetSize());
  wxDCClipper clip(*_memory_dc,rect);
  boost::scoped_ptr<wxPen> current_pen(
    new wxPen( *wxBLACK, 1, PENSTYLE_SOLID));

  _memory_dc->SetPen(*current_pen);
  _memory_dc->SetAxisOrientation(true,false);
  _memory_dc->SetBrush(*wxRED_BRUSH);

  // Get window dimensions
  //wxSize _sz = GetClientSize();

  //_memory_dc->SelectObject(*_bitmap);
  _memory_dc->SetBackground(this->GetBackgroundColour());
  _memory_dc->Clear();

  //dc.DrawRectangle(rectToDraw);
  _memory_dc->SetPen(*wxBLACK_PEN);
  DrawAxes();
  DrawCurves();
  DrawControls();
  DrawLinearCM();
  if (this->IsShown())
    DrawingAreaDisplay(in_paint);
}


//-------------------------------------------------
void wxDrawingWindow::OnPaint(wxPaintEvent& event)
{
  //std::cout << "-- OnPaint begin" << std::endl;
  wxPaintDC pdc(this);
#ifndef __APPLE__
  PrepareDC(pdc);
#endif
  
  Paint(true);
  event.Skip();
  //std::cout << "-- OnPaint end" << std::endl;
}

//-------------------------------------------------
void wxDrawingWindow::OnSize(wxSizeEvent& event)
{
  DrawingAreaInit( );
  Paint();
  event.Skip();
}

//-------------------------------------------------
void wxDrawingWindow::OnLeftUp( wxMouseEvent& event)
{
  _left_down = false; 
  _previous_crosshair = false;
  DrawingAreaDisplay();
  event.Skip(); 
}

//-------------------------------------------------
void wxDrawingWindow::OnRightDown(wxMouseEvent& event)
{
  wxClientDC dc(this);
#ifndef __APPLE__
  PrepareDC(dc);
#endif
  
  _mouse_x = (int)event.GetX();
  _mouse_y = (int)event.GetY();

  CLASS_MESSAGE((boost::format("At position %1% %2%")%_mouse_x%_mouse_y).str().c_str());
  double x,y;
  Window2World(_mouse_x,_mouse_y,x,y);
  CLASS_MESSAGE((boost::format("world coord %1% %2%")%x%y).str().c_str());

  // check if we are at a control point
  //int closest = CheckCtrlPoint();

  // create the popup menu here
  wxMenu menu(_T("Menu"));
  if (!_focus_point.get()) {
    menu.Append(wxID_AddControlPoint, wxT("&Add control point"));
    menu.Append(wxID_AddControlledCurve, wxT("&Add controlled curve"));
    wxMenuItem* menu_showgrid = menu.AppendCheckItem(wxID_ShowGrid,wxT("Enable &Grid"));
    menu_showgrid->Check(this->_draw_grid);
  } else {
    menu.Append(wxID_RemoveControl, wxT("&Remove control point"));
    menu.Append(wxID_DuplicateControl, wxT("&Duplicate control point"));
    if (_focus_controlledcurve.get()) {
      menu.Append(wxID_RemoveControlledCurve, wxT("&Remove controlled curve"));

      wxMenuItem* menu_cmcc = menu.AppendCheckItem(wxID_ColormapControlledCurve, wxT("&Colormap Curve"));
      menu_cmcc->Check(_focus_controlledcurve->GetType()==colormap_curve);
      
      wxMenuItem* menu_cmcc2 = menu.AppendCheckItem(wxID_LimitControlledCurve, wxT("&Limited Curve"));
      menu_cmcc2->Check(_focus_controlledcurve->isLimited()==true);
    }
/*
    wxMenuItem* menu_cm = menu.AppendCheckItem(wxID_ColormapPoint, wxT("&Colormap"));
    menu_cm->Check(_focus_point->GetType()==colormap_point);
*/

    if (_focus_point->GetType()==normal_point) {
      wxMenuItem* menu_vl = menu.AppendCheckItem(wxID_VerticalLine, wxT("&Vertical Line"));
      menu_vl->Check(_focus_point->GetVerticalLine());
    }

    wxMenuItem* menu_ly =
      menu.AppendCheckItem(wxID_YLocked, wxT("&Lock Y coord."));
    menu_ly->Check(_focus_point->GetYLocked());

    menu.Append(wxID_SetControlColour, wxT("&Colour"));
   }
   _within_popupmenu = true;
   PopupMenu(&menu, _mouse_x,_mouse_y);
  _within_popupmenu = false;
   event.Skip();
}

//-------------------------------------------------
int wxDrawingWindow::CheckCtrlPoint( boost::shared_ptr<vector_dwControlPoint>& list)
{
  double mindist = 1000;
  int closest = -1;
  _focus_pointset = list;

  // search for closest controlpoint
  for(int i=0;i<(int)list->size();i++) {
    wxPoint p;
    p = (*list)[i].GetwxPoint();
    (*list)[i].SetFocus(false);
/*    std::cout << "point " << i 
              << "p.x=" << p.x
              << "p.y=" << p.y
              << std::endl;*/
    double tmp = (p.x-_mouse_x)*(p.x-_mouse_x)+(p.y-_mouse_y)*(p.y-_mouse_y);
    if (tmp<(*list)[i].GetRadius()*(*list)[i].GetRadius()) {
      if (closest==-1) {
        mindist = tmp;
        closest = i;
        _focus_point = dwControlPoint::ptr( &(*list)[i], smartpointer_nodeleter<dwControlPoint>());
      }
      else {
        if (tmp<mindist) {
          mindist = tmp;
          closest = i;
          _focus_point = dwControlPoint::ptr( &(*list)[i], smartpointer_nodeleter<dwControlPoint>());
        }
      }
    }
  }
  return closest;
}

//-------------------------------------------------
void wxDrawingWindow::CheckCtrlPoint()
{
  _focus_point.reset();
  _focus_controlledcurve.reset();
  int res;
  res = CheckCtrlPoint(_controlpoints);
  int i=0;
  while ((res==-1)&&(i<(int)_controlled_curves->size())) {
/*    std::cout << "curve " << i << std::endl;*/
    res = CheckCtrlPoint((*_controlled_curves)[i].GetControlPoints());
    if (res!=-1)
      // TODO: improve this "false" smart pointer
      _focus_controlledcurve = dwControlledCurve::ptr( &(*_controlled_curves)[i], smartpointer_nodeleter<dwControlledCurve>());
    i++;
  }
}

//-------------------------------------------------
void wxDrawingWindow::OnMotion(wxMouseEvent& event)
{
  if (_within_popupmenu) return;
  
  wxClientDC dc(this);
#ifndef __APPLE__
  PrepareDC(dc);
#endif
  
  int oldmouse_x = _mouse_x;
  int oldmouse_y = _mouse_y;
  _mouse_x = (int)event.GetX();
  _mouse_y = (int)event.GetY();

  //cout << "leftdown " << _left_down << std::endl;
  if (_left_down) {
    if ((_focus_point.get())&&(_left_down)) {
      // displace the current point
      //cout << "Displace ??" << std::endl;
      double new_x,new_y;
      Window2World(_mouse_x,_mouse_y,new_x,new_y);

      if (event.ShiftDown() && (_focus_controlledcurve.get()))
      {
        double x = _focus_point->GetX();
        double y = _focus_point->GetY();
        boost::shared_ptr<std::vector<dwControlPoint> > points = 
          _focus_controlledcurve->GetControlPoints();
        for(int i=0;i<(int)points->size();i++) {
          SetCtrlPointPosition((*points)[i],
                               (*points)[i].GetX()+new_x-x,
                               (*points)[i].GetY()+new_y-y);
        }
      } else {
        SetCtrlPointPosition(*_focus_point,new_x,new_y);
        _focus_point->SetwxPoint(wxPoint(_mouse_x,_mouse_y));
      }

      // Check if a Control point callback was set,
      // if so, call the function with its parameters
      if (_ctrlpt_callback.get()) {
        bool ok = (*_ctrlpt_callback)();
        if (!ok) _ctrlpt_callback.reset();
      }
      _linearCM_uptodate = false;

      //Refresh(false);
      Paint(false);
    }
    else 
    {
      boost::scoped_ptr<wxPen> current_pen(
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

//  int closest = 
  CheckCtrlPoint();
/*
  double mindist = 1000;
  int closest = -1;

  // search for closest controlpoints
  for(int i=0;i<(int)_controlpoints->size();i++) {
    wxPoint p;
    p = (*_controlpoints)[i].GetwxPoint();
    (*_controlpoints)[i].SetFocus(false);
    double tmp = (p.x-_mouse_x)*(p.x-_mouse_x)+(p.y-_mouse_y)*(p.y-_mouse_y);
    if (tmp<(*_controlpoints)[i].GetRadius()*(*_controlpoints)[i].GetRadius()) {
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
  if (_focus_point.get()) {
    _focus_point->SetFocus(true);
  }
//  focus_pointid = closest;
  Paint(false);
  //Refresh(false);
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
  int wr = event.GetWheelRotation();
  if (_focus_controlledcurve.get()) {
    // rescale the curve
    // find min/max of curve
    boost::shared_ptr<std::vector<dwControlPoint> > points = 
      _focus_controlledcurve->GetControlPoints();
    if (points->size()==0) return;
/*
    double xmin = (*points)[0].GetX();
    double ymin = (*points)[0].GetY();
    double xmax = (*points)[0].GetX();
    double ymax = (*points)[0].GetY();
    for(int i=1; i<points->size(); i++) {
      xmin = macro_min(xmin,(*points)[i].GetX());
      xmax = macro_max(xmax,(*points)[i].GetX());
      ymin = macro_min(ymin,(*points)[i].GetY());
      ymax = macro_max(ymax,(*points)[i].GetY());
    }
*/
    // now rescale the points
    double step  = ((double)wr)/(5.0*(double)event.GetWheelDelta());
    if (step > 7 ) step = 7;
    if (step < -7) step = -7;

#if (!defined(log2f)) 
 #define log2f(x)    (logf(x)/logf(2))
#endif

    double zoom_factor  = exp( step*log2f(2));
    double xref = _focus_point->GetX();
    double yref = _focus_point->GetY();
  
    for(int i=0; i<(int)points->size(); i++) {
      double x = (*points)[i].GetX();
      double y = (*points)[i].GetY();
      SetCtrlPointPosition((*points)[i],
                           xref+(x-xref)*zoom_factor,
                           yref+(y-yref)*zoom_factor);
    }
    _linearCM_uptodate = false;
  } else {
    wxClientDC dc(this);
#ifndef __APPLE__
    PrepareDC(dc);
#endif
    
    _mouse_x = (int)event.GetX();
    _mouse_y = (int)event.GetY();
    double x,y;
    Window2World(_mouse_x,_mouse_y,x,y);
  
    // now apply a zoom centered on the current position in X direction
//    double xmin = _xmin;
//    double xmax = _xmax;
  
    double step  = ((double)wr)/(5.0*(double)event.GetWheelDelta());
    if (step > 7 ) step = 7;
    if (step < -7) step = -7;

#if (!defined(log2f)) 
 #define log2f(x)    (logf(x)/logf(2))
#endif

    double zoom_factor  = exp( step*log2f(2));
  
    double newxmin = x - (x-_xmin)/zoom_factor;
    double newxmax = x + (_xmax - x)/zoom_factor;
    double range=newxmax-newxmin;
    if ((range>_min_xrange)&&(range<_max_xrange)) {
      _xmin = newxmin;
      _xmax = newxmax;
    }
  }


  Paint(false);
  //Refresh(false);
  // capture event ...
  event.Skip();

}

//-------------------------------------------------
void wxDrawingWindow::OnAddControlPoint(wxCommandEvent& event)
{
  double x,y;
  Window2World(_mouse_x,_mouse_y,x,y);
  AddControlPoint(dwControlPoint(dwPoint2D(x,y)));
  Paint(false);
  //Refresh(false);
}

//-------------------------------------------------
void wxDrawingWindow::OnAddControlledCurve(wxCommandEvent& event)
{
  double x,y;
  Window2World(_mouse_x,_mouse_y,x,y);
  double x1 = x+(_xmin-x)/2.0;
  double x2 = x+(_xmax-x)/2.0;
  dwControlledCurve c;
  c.GetControlPoints()->push_back(dwControlPoint(dwPoint2D(x1,y)));
  c.GetControlPoints()->push_back(dwControlPoint(dwPoint2D(x2,y)));
  _controlled_curves->push_back(c);
  Paint(false);
  //Refresh(false);
}

//-------------------------------------------------
void wxDrawingWindow::OnRemoveControlledCurve(wxCommandEvent& event)
{
  if (_focus_controlledcurve.get())
      // TODO: fix remove feature
//    _controlled_curves->erase(_controlled_curves->begin()+_focus_controlledcurve);
  Paint(false);
  //Refresh(false);
}

//-------------------------------------------------
void wxDrawingWindow::OnRemoveControl(wxCommandEvent& event)
{
  RemoveControl();
  _focus_point.reset();
  Paint(false);
  //Refresh(false);
}

//-------------------------------------------------
void wxDrawingWindow::OnDuplicateControl(wxCommandEvent& event)
{
  DuplicateControl();
  Paint(false);
  //Refresh(false);
}

/*
//-------------------------------------------------
void wxDrawingWindow::OnColormapPoint(wxCommandEvent& event)
{
  
  if (event.IsChecked())
    _focus_point->SetType(colormap_point);
  else
    _focus_point->SetType(normal_point);
  Refresh(false);
}
*/

//-------------------------------------------------
void wxDrawingWindow::OnColormapControlledCurve(wxCommandEvent& event)
{
  
  if (event.IsChecked())
    _focus_controlledcurve->SetType(colormap_curve);
  else
    _focus_controlledcurve->SetType(normal_curve);

  _linearCM_uptodate = false;
  Paint(false);
  //Refresh(false);
}

//-------------------------------------------------
void wxDrawingWindow::OnLimitControlledCurve(wxCommandEvent& event)
{
  
  if (event.IsChecked())
    _focus_controlledcurve->SetLimits(true);
  else
    _focus_controlledcurve->SetLimits(false);

  _linearCM_uptodate = false;
  Paint(false);
  //Refresh(false);
}

//-------------------------------------------------
void wxDrawingWindow::OnVerticalLine(wxCommandEvent& event)
{
  _focus_point->SetVerticalLine(event.IsChecked());
  Paint(false);
  //Refresh(false);
}

//-------------------------------------------------
void wxDrawingWindow::OnYLocked(wxCommandEvent& event)
{
  _focus_point->SetYLocked(event.IsChecked());
  Paint(false);
  //Refresh(false);
}

//-------------------------------------------------
void wxDrawingWindow::OnControlColour(wxCommandEvent& event)
{
  // Select the new colour
  wxColourData data;
  data.SetColour( _focus_point->GetColour());
  wxColourDialog dialog(this, &data);

  if ( dialog.ShowModal() == wxID_OK )
  {
    if (_focus_point.get())
    {
      _focus_point->SetColour( dialog.GetColourData().GetColour());  
    }
  }
  _linearCM_uptodate = false;
  Paint(false);
  //Refresh(false);
}

//-------------------------------------------------
void wxDrawingWindow::OnShowGrid(wxCommandEvent& event)
{
  this->_draw_grid = event.IsChecked();
  Paint(false);
  //Refresh(false);
}
