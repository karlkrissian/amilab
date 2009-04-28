//
// C++ Interface: wxDrawingArea
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wxDrawingArea_h_
#define _wxDrawingArea_h_

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/window.h"


class FenetreDessin;

class wxDrawingArea : public wxWindow
{

  FenetreDessin* _parent_window;
  int _mouse_x;
  int _mouse_y;

public:
   wxDrawingArea(wxWindow *parent, wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = 0,
        const wxString& name = _T("ami_wxGLCanvas"));

   virtual ~wxDrawingArea(){};

  void Boutton_Presse() {}
  void ShiftBout1_Presse() {}
  void Boutton_Relache() {}
  void DeplaceSourisBout1() {}

  void Boutton2_Presse() {}
  void DeplaceSourisBout2() {}
  void Boutton2_Relache() {}
  void DeplaceSourisShiftBout2() {}

  void Boutton3_Presse() {}
  void Boutton3_Relache() {}
  void DeplaceSourisBout3() {}

  void OnPaint(          wxPaintEvent& event);
  void OnSize(           wxSizeEvent& event);
  void OnChar(           wxKeyEvent&  event);
  void OnMouseEvent(     wxMouseEvent& event);

  DECLARE_EVENT_TABLE()
};

#endif // _wxDrawingArea_h_
