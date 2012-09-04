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
#include <wx/combo.h>
#include "wx/odcombo.h"
#include <wx/sizer.h>
#include "widget.hpp"
#include <wx/listctrl.h>


// //------------------------------------------------------------------------------
// // Create own combo list: events work better
// //------------------------------------------------------------------------------
// 
// class ListViewComboPopup : public wxListView, public wxComboPopup
// {
// public:
// 
//     virtual void Init()
//     {
//         m_value = -1;
//         m_itemHere = -1; // hot item in list
//     }
// 
//     virtual bool Create( wxWindow* parent )
//     {
//         return wxListView::Create(parent,1,
//                                   wxPoint(0,0),wxDefaultSize,
//                                   wxLC_LIST|wxLC_SINGLE_SEL|
//                                   wxLC_SORT_ASCENDING|wxSIMPLE_BORDER);
//     }
// 
//     virtual wxWindow *GetControl() { return this; }
// 
//     virtual void SetStringValue( const wxString& s )
//     {
//         int n = wxListView::FindItem(-1,s);
//         if ( n >= 0 && n < GetItemCount() )
//             wxListView::Select(n);
//     }
// 
//     virtual wxString GetStringValue() const
//     {
//         if ( m_value >= 0 )
//             return wxListView::GetItemText(m_value);
//         return wxEmptyString;
//     }
// 
//     //
//     // Popup event handlers
//     //
// 
//     // Mouse hot-tracking
//     void OnMouseMove(wxMouseEvent& event)
//     {
//         // Move selection to cursor if it is inside the popup
// 
//         int resFlags;
//         int itemHere = HitTest(event.GetPosition(),resFlags);
//         if ( itemHere >= 0 )
//         {
//             wxListView::Select(itemHere,true);
//             m_itemHere = itemHere;
//         }
//         event.Skip();
//     }
// 
//     // On mouse left, set the value and close the popup
//     void OnMouseClick(wxMouseEvent& WXUNUSED(event))
//     {
//         m_value = m_itemHere;
//         // TODO: Send event
//         Dismiss();
//     }
// 
//     //
//     // Utilies for item manipulation
//     //
// 
//     void AddSelection( const wxString& selstr )
//     {
//         wxListView::InsertItem(GetItemCount(),selstr);
//     }
// 
// protected:
// 
//     int             m_value; // current item index
//     int             m_itemHere; // hot item in popup
// 
// private:
//     DECLARE_EVENT_TABLE()
// };
// 


//------------------------------------------------------------------------------

#if wxCHECK_VERSION(2,9,0)
  #define CHOICE_CLASS wxOwnerDrawnComboBox
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
//                      |wxCB_READONLY
#endif
                      ,validator,name)
  { 
    _calldata = _callback = NULL;
    _updatelist_calldata = _updatelist_callback = NULL;
#ifdef USING_COMBOBOX
    this->GetTextCtrl()->SetWindowStyle(
      this->GetTextCtrl()->GetWindowStyle()|wxTE_READONLY|wxTE_RIGHT);
#endif
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

  void OnChoiceUpdate( wxCommandEvent &event )
  {
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
    event.Skip();
  }

  void OnDropDown( wxCommandEvent & event )
  {
    this->UpdateListCallback();
    event.Skip();
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
