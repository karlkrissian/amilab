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
    _parent_window->SetMousePosition(_mouse_x,_mouse_y);

    if(event.LeftUp())      _parent_window->Boutton_Relache();
    if(event.MiddleUp())    _parent_window->Boutton2_Relache();
    if(event.RightUp())     _parent_window->Boutton3_Relache();

    if(event.LeftDown())    _parent_window->Boutton_Presse();
    if(event.MiddleDown())  _parent_window->Boutton2_Presse();
    if(event.RightDown())   _parent_window->Boutton3_Presse();

    if (event.Dragging()) {
      if (event.ShiftDown()) {
        if (event.LeftIsDown())   _parent_window->DeplaceSourisShiftBout1();
        if (event.MiddleIsDown()) _parent_window->DeplaceSourisShiftBout2();
        if (event.RightIsDown())  _parent_window->DeplaceSourisShiftBout3();
      } else {
        if (event.LeftIsDown())   _parent_window->DeplaceSourisBout1();
        if (event.MiddleIsDown()) _parent_window->DeplaceSourisBout2();
        if (event.RightIsDown())  _parent_window->DeplaceSourisBout3();
      }
    }
} // OnMouseEvent()
