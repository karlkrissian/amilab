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

#include <list>
#include <string>
#include <boost/shared_ptr.hpp>
//#include "wxParamTypes.hpp"

typedef boost::shared_ptr<std::string>     string_ptr;


class wxBitmapButtonParameter;

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
  /// if the result is given as a integer
  int*            _parameter;
  /// if the result is given as a string
  string_ptr*     _selection_param;
  wxWindow*       _parent;
  wxStaticText*   _label;
  myChoice*       _choice;
  wxBitmapButtonParameter* _update_button;

  public:
  
  wxEnumerationParameter( wxWindow* parent, int* param, 
    const char* label,
    const std::string& tooltip="");
  
  wxEnumerationParameter( wxWindow* parent,
    string_ptr* selection_param,
    const char* label,
    const std::string& tooltip="");
  
  ~wxEnumerationParameter();
  
  void AddChoice( int* choix_id, const char* label);

  void SetChoices( const boost::shared_ptr<wxArrayString>& choices);
  
  wxString GetStringSelection();

  void AddUpdateButton(void* update_cb);

  void SetSelection(int n);
  
  void Update();
  
  static void OnEnumUpdate(void* data);

  bool Enable(bool enable = true);

//  void OnButtonUpdate( wxCommandEvent& data);

}; // wxEnumerationParameter

#endif // _WX_ENUMERATIONPARAMETER_H_
