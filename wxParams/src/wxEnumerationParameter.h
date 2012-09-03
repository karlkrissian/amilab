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

#include "CallBackBase.h"


typedef boost::shared_ptr<std::string>     string_ptr;

#include <wx/choice.h>
#include <wx/combobox.h>
#include <wx/sizer.h>
#include "widget.hpp"


#if wxCHECK_VERSION(2,9,0)
  #define CHOICE_CLASS wxComboBox
  #define USING_COMBOBOX
#else
  #define CHOICE_CLASS wxChoice
#endif

class wxBitmapButtonParameter;

//==============================================================================
//==============================================================================
/*!
  \brief myChoice: inherit of CHOICE_CLASS to add a callback for any value change.
*/
class myChoice: public CHOICE_CLASS
{
  public:
    myChoice(wxWindow *parent, wxWindowID id,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        int n = 0, const wxString choices[] = NULL,
        long style = 0,
        const wxValidator& validator = wxDefaultValidator,
        const wxString& name = wxChoiceNameStr) :
        CHOICE_CLASS( parent,id,
#ifdef USING_COMBOBOX
                      _T(""),
#endif
                      pos,size,n,choices,\
                      style
#ifdef USING_COMBOBOX
                      |wxCB_READONLY
#endif
                      ,validator,name)
  { 
    _calldata = _callback = NULL;
    _updatelist_calldata = _updatelist_callback = NULL;
  }
    
  void SetCallback(void* cb, void* cd) { _callback=cb; _calldata=cd;}
  void SetUpdateListCallback(void* cb, void* cd) 
  {
     _updatelist_callback=cb;
     _updatelist_calldata=cd;
  }

  void SetUpdateListCallbackFunctor(CallBackBase::ptr cb) 
  {
     _updatelist_callback_functor=cb;
  }

  void OnChoiceUpdate( wxCommandEvent &WXUNUSED(event) )
  {
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
  }

  void Callback();

  void UpdateListCallback();

  void OnFocus( wxFocusEvent &event );
  void OnLeftDown( wxMouseEvent& event );
  void OnEnterWindow(wxMouseEvent& event);

protected:
  void* _callback;
  void* _calldata;

  void* _updatelist_callback;
  void* _updatelist_calldata;
  
  /// if available, use the callback functor
  CallBackBase::ptr _updatelist_callback_functor;
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
  string_ptr      _selection_param;
  wxWindow*       _parent;
  wxStaticText*   _label;
  myChoice*       _choice;
  wxBitmapButtonParameter* _update_button;

  public:
  
  wxEnumerationParameter( wxWindow* parent, int* param, 
    const char* label,
    const std::string& tooltip="");
  
  wxEnumerationParameter( wxWindow* parent,
    string_ptr selection_param,
    const char* label,
    const std::string& tooltip="",
    bool allowdrop=false
                        );
  
  ~wxEnumerationParameter();
  
  void AddChoice( int* choix_id, const char* label);

  void SetChoices( const boost::shared_ptr<wxArrayString>& choices);
  
  wxString GetStringSelection();

  void AddUpdateCallback(void* update_cb,
  const std::string& tooltip);

  void SetUpdateListCallbackFunctor(CallBackBase::ptr cb);

  void SetSelection(int n);
  
  void Update();
  
  static void OnEnumUpdate(void* data);

  void EnableWidget(bool enable = true);

///@cond wxCHECK
#if wxCHECK_VERSION(2,8,11)
  wxString GetAbsoluteName(const wxString& Name);
#endif
/// @endcond

//  void OnButtonUpdate( wxCommandEvent& data);

}; // wxEnumerationParameter

#endif // _WX_ENUMERATIONPARAMETER_H_
