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
    SetMinSize(wxSize(20,-1));
      // default behaviour callback during dragging
      _drag_callback = true;
    }
    
  void SetCallback(void* cb, void* cd) { _callback=cb; _calldata=cd;}

  virtual void OnSliderChanged( wxScrollEvent &WXUNUSED(event) )
  {
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
  }

  void SetDragCallback(bool dcb)
  {
    _drag_callback = dcb;
  }

  virtual void OnThumbTrack( wxScrollEvent &WXUNUSED(event) )
  {
    if (_drag_callback) {
      void (*cbf)( void*) = (void (*)(void*)) this->_callback;
      cbf(this->_calldata);
    }
  }
  

protected:
  void* _callback;
  void* _calldata;

  bool _drag_callback;
private:
    DECLARE_EVENT_TABLE();
};


#endif // ifndef _mySlider_h_
