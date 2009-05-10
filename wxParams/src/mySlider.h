//
// C++ Interface: mySlider
//
// Description: 
//
//
// Author: Karl Krissian  <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _mySlider_h_
#define _mySlider_h_

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


//=======================================================
class mySlider: public wxSlider
{
  public:
     mySlider(wxWindow *parent, wxWindowID id,
        int value, int minValue, int maxValue,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxSL_HORIZONTAL,
        const wxValidator& validator = wxDefaultValidator,
        const wxString& name = wxSliderNameStr) :
        wxSlider(parent,id,value,minValue,maxValue,pos,size,style,validator,name)
    {
    }
    
  void SetCallback(void* cb, void* cd) { _callback=cb; _calldata=cd;}
  virtual void OnSliderUpdate( wxScrollEvent &WXUNUSED(event) )
  {
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
  }
protected:
  void* _callback;
  void* _calldata;
private:
    DECLARE_EVENT_TABLE();
};


#endif // ifndef _mySlider_h_
