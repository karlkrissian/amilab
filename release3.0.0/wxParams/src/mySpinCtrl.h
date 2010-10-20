//
// C++ Interface: mySpinCtrl
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _mySpinCtrl_h_
#define _mySpinCtrl_h_

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


class mySpinCtrl: public wxSpinCtrl
{
  public:
    mySpinCtrl(wxWindow *parent,
               wxWindowID id = wxID_ANY,
               const wxString& value = wxEmptyString,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxSP_ARROW_KEYS,
               int min = 0, int max = 100, int initial = 0,
               const wxString& name = _T("wxSpinCtrl")):
        wxSpinCtrl(parent,id,value,pos,size,style,min,max,initial,name)
        {
        }
   
  void SetCallback(void* cb,void* cd) { _callback=cb; _calldata=cd;}
  void OnSpinCtrlUpdate( wxSpinEvent &WXUNUSED(event) )
  {
    printf("OnSpinCtrlUpdate\n");
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
  }
  
  void OnSpinCtrlTxtUpdate( wxCommandEvent& event)
  {
    printf("OnSpinCtrlTxtUpdate\n");
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
  }
protected:
  void* _callback;
  void* _calldata;
private:
    DECLARE_EVENT_TABLE();
};


#endif // ifndef _mySpinCtrl_h_
