//
// C++ Implementation: myTextCtrl
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "myTextCtrl.h"

BEGIN_EVENT_TABLE(MyTextCtrl, wxTextCtrl)
  //    EVT_KEY_DOWN(MyTextCtrl::OnKeyDown)
  //    EVT_KEY_UP(MyTextCtrl::OnKeyUp)
  //    EVT_CHAR(MyTextCtrl::OnChar)
  EVT_TEXT_ENTER(wxID_ANY, MyTextCtrl::OnText)
  //    EVT_TEXT_URL(wxID_ANY, MyTextCtrl::OnTextURL)
  //    EVT_TEXT_MAXLEN(wxID_ANY, MyTextCtrl::OnTextMaxLen)
  //    EVT_MOUSE_EVENTS(MyTextCtrl::OnMouseEvent)
  //    EVT_SET_FOCUS(MyTextCtrl::OnSetFocus)
  EVT_KILL_FOCUS(MyTextCtrl::OnKillFocus)
END_EVENT_TABLE()

MyTextCtrl::MyTextCtrl(wxWindow *parent, wxWindowID id, const wxString &value,
               const wxPoint &pos, const wxSize &size, int style)
        : wxTextCtrl(parent, id, value, pos, size, style)
{
}

void MyTextCtrl::OnText(wxCommandEvent& event)
{
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
}
 
void MyTextCtrl::OnKillFocus(wxFocusEvent& event)
{
  //printf("Kill Focus \n");
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
}
 
