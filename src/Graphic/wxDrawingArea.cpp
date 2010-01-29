//
// C++ Implementation: wxDrawingArea
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wxDrawingArea.h"
#include "FenetreDessin.hpp"

extern unsigned char      GB_debug;
extern unsigned char      GB_verbose;

BEGIN_EVENT_TABLE(wxDrawingArea, wxWindow)
    EVT_PAINT       ( wxDrawingArea::OnPaint      )
    EVT_SIZE        ( wxDrawingArea::OnSize       )
    EVT_MOUSE_EVENTS( wxDrawingArea::OnMouseEvent )
    EVT_CHAR        ( wxDrawingArea::OnChar       )
END_EVENT_TABLE()


wxDrawingArea::wxDrawingArea(wxWindow *parent, wxWindowID id,
    const wxPoint& pos, const wxSize& size, long style,
    const wxString& name)
    : wxWindow(parent, id, pos, size, style
    |wxFULL_REPAINT_ON_RESIZE
    //|wxDOUBLE_BORDER
    |wxBORDER_RAISED
    , 
    name)
{
    _parent_window = (FenetreDessin*) parent;
}

//-------------------------------------------------
void wxDrawingArea::OnPaint( wxPaintEvent& event)
{
  wxPaintDC pdc(this);
  PrepareDC(pdc);

  //cout << "wxDrawingArea::OnPaint()" << endl;
  _parent_window->Paint();

} // OnPaint()

//-------------------------------------------------
void wxDrawingArea::OnSize(wxSizeEvent& event)
{
  if (GB_debug) cerr << "wxDrawingArea::OnSize()" << endl;
  if (_parent_window->UpdateDrawingDimensions()) {
    //_parent_window->EffaceEcran( false);
    if (GB_debug) cerr << "Calling ReDimensionne()" << endl;
    _parent_window->ReDimensionne();
  }
} // OnSize()

//-------------------------------------------------
void wxDrawingArea::OnChar(wxKeyEvent& event)
{
  _mouse_x = (int)event.GetX();
  _mouse_y = (int)event.GetY();
  _parent_window->SetMousePosition(_mouse_x,_mouse_y);
  _parent_window->OnChar(event);
}


//-------------------------------------------------
void wxDrawingArea::OnMouseEvent(wxMouseEvent& event)
{

    _mouse_x = (int)event.GetX();
    _mouse_y = (int)event.GetY();

    bool ld = event.LeftDown();
    bool md = event.MiddleDown();
    bool rd = event.RightDown();

    bool lid = event.LeftIsDown();
    bool mid = event.MiddleIsDown();
    bool rid = event.RightIsDown();

    bool lu = event.LeftUp();
    bool mu = event.MiddleUp();
    bool ru = event.RightUp();

    bool drag  = event.Dragging();
    bool shift = event.ShiftDown();
    bool ctrl  = event.ControlDown();
    bool alt   = event.AltDown();

    int wr = event.GetWheelRotation();
    if (wr != 0) {
      cout << "wheel rotation " << wr << endl;
      cout << " mouse "<< _mouse_x << " " << _mouse_y << endl;
      _parent_window->OnWheel(event);
    }

    _parent_window->SetMousePosition(_mouse_x,_mouse_y);

    if (lu)  _parent_window->Boutton_Relache();
    else
    if (mu)  _parent_window->Boutton2_Relache();
    else
    if (ru)  _parent_window->Boutton3_Relache();
    else
    if(ld)   _parent_window->Boutton_Presse();
    else
    if(md)   _parent_window->Boutton2_Presse();
    else
    if(rd)   _parent_window->Boutton3_Presse();
    else
    if (drag) {
      if (shift) {
        if (lid)  _parent_window->DeplaceSourisShiftBout1();
        else
        if (mid)  _parent_window->DeplaceSourisShiftBout2();
        else
        if (rid)  _parent_window->DeplaceSourisShiftBout3();
      } else {
        if (lid)  _parent_window->DeplaceSourisBout1();
        else
        if (mid)  _parent_window->DeplaceSourisBout2();
        else
        if (rid)  _parent_window->DeplaceSourisBout3();
      }
    }
} // OnMouseEvent()
