//
// C++ Interface: wxEnumerationParameter
//
// Description: 
//
//
// Author:   <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

/*!
  \file 
  \brief this file is a GUI class for enumerations

*/

#ifndef _WX_ENUMERATIONPARAMETER_H_
#define _WX_ENUMERATIONPARAMETER_H_

//==============================================================================
//==============================================================================
/*!
  \brief myChoice: inherit of wxChoice to add a callback for any value change.
*/
class myChoice: public wxChoice
{
  public:
    myChoice(wxWindow *parent, wxWindowID id,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        int n = 0, const wxString choices[] = NULL,
        long style = 0,
        const wxValidator& validator = wxDefaultValidator,
        const wxString& name = wxChoiceNameStr) :
        wxChoice(parent,id,pos,size,n,choices,style,validator,name) 
    {}
    
  void SetCallback(void* cb, void* cd) { _callback=cb; _calldata=cd;}
  void OnChoiceUpdate( wxCommandEvent &WXUNUSED(event) )
  {
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
  }
protected:
  void* _callback;
  void* _calldata;
private:
    DECLARE_EVENT_TABLE()
};




//==============================================================================
/*!
  \brief wxEnumerationParameter: creates an gui selecting a value of an enumeration.
*/
class wxEnumerationParameter: public wxBoxSizer, public wxGenericWidget
{
  int*          _parameter;
  wxWindow*     _parent;
  wxStaticText* _label;
  myChoice*     _choice;

  public:
  
  wxEnumerationParameter( wxWindow* parent, int* param, const char* label);
  
  ~wxEnumerationParameter();
  
  void AddChoice( int* choix_id, const char* label);
  
  void SetSelection(int n);
  
  void Update();
  
  static void OnEnumUpdate(void* data);

}; // wxEnumerationParameter

#endif // _WX_ENUMERATIONPARAMETER_H_
