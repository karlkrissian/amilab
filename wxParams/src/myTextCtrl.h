//
// C++ Interface: myTextCtrl
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _myTextCtrl_h_
#define _myTextCtrl_h_

//--------------------------------------------------
// includes for wxWidgets
//--------------------------------------------------
#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif


//---------------------------------------------------------
class MyTextCtrl : public wxTextCtrl
{
public:
  MyTextCtrl( wxWindow *parent, 
              wxWindowID id, 
              const wxString &value,
              const wxPoint &pos,
              const wxSize &size,
              int style = 0)  ;
  
  //    void OnKeyDown(wxKeyEvent& event);
  //    void OnKeyUp(wxKeyEvent& event);
  //    void OnChar(wxKeyEvent& event);
  
  //    void OnText(wxCommandEvent& event);
  //    void OnTextURL(wxTextUrlEvent& event);
  //    void OnTextMaxLen(wxCommandEvent& event);
  
  //    void OnMouseEvent(wxMouseEvent& event);
  
  //    void OnSetFocus(wxFocusEvent& event);
  void OnKillFocus(wxFocusEvent& event);

  //    static bool ms_logKey;
  //    static bool ms_logChar;
  //    static bool ms_logMouse;
  //    static bool ms_logText;
  //    static bool ms_logFocus;

  void SetCallback(void* cb,void* cd) { _callback=cb; _calldata=cd;}
  void OnText(wxCommandEvent& event);
  
protected:
  void* _callback;
  void* _calldata;

private:
  static inline wxChar GetChar(bool on, wxChar c) { return on ? c : _T('-'); }
  //    void LogKeyEvent(const wxChar *name, wxKeyEvent& event) const;
  
  //    bool m_hasCapture;

    DECLARE_EVENT_TABLE()
};


#endif // ifndef _myTextCtrl_h_
