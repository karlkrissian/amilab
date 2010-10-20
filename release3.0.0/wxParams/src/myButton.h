//
// C++ Interface: myButton
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _myButton_h_
#define _myButton_h_

//
class myButton: public wxButton
{
  public:
     myButton(wxWindow* parent, 
              wxWindowID id, 
              const wxString& label = wxEmptyString, 
              const wxPoint& pos = wxDefaultPosition, 
              const wxSize& size = wxDefaultSize, 
              long style = 0, 
              const wxValidator& validator = wxDefaultValidator, 
              const wxString& name = _T("button")) :
        wxButton(parent, id, label, pos, size, style, validator, name)
    {
    }
    
  void SetCallback(void* cb, void* cd) { _callback=cb; _calldata=cd;}
  void OnButton( wxCommandEvent &WXUNUSED(event) )
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


#endif // _myButton_h_
