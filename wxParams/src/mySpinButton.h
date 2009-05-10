//
// C++ Interface: mySpinButton
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _mySpinButton_h_
#define _mySpinButton_h_

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

#if wxUSE_SPINCTRL
    #include "wx/spinctrl.h"
#endif // wxUSE_SPINCTRL

/**
*/
class mySpinButton: public wxSpinButton
{
  public:
    mySpinButton(wxWindow *parent,
               wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxSP_ARROW_KEYS,
               const wxString& name = _T("wxSpinCtrl")):
        wxSpinButton(parent,id,pos,size,style,name)
        {
        }
   
  void SetCallback(void* cb,void* cd) { _callback=cb; _calldata=cd;}
  void OnSpinCtrlUpdate( wxSpinEvent &WXUNUSED(event) )
  {
    //printf("OnSpinCtrlUpdate\n");
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
  }
  
protected:
  void* _callback;
  void* _calldata;
private:
    DECLARE_EVENT_TABLE();
};


#endif // ifndef _mySpinButton_h_
