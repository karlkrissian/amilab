//
// C++ Implementation: wxEnumerationParameter
//
// Description: 
//
//
// Author:  <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <iostream>
//--------------------------------------------------
// includes for wxWidgets
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/progdlg.h"

#if wxUSE_SPINCTRL
    #include "wx/spinctrl.h"
#endif // wxUSE_SPINCTRL

#include "widget.hpp"
#include "StructParams.hpp"
#include "couleur.hpp"
#include "wxEnumerationParameter.h"
#include "wxParamTypes.hpp"

#include "DndChoiceTextDropTarget.h"
#include <iostream>

//#include "slick/16x16/actions/reload.xpm"

#ifdef _MSC_VER
  #define __func__ __FUNCTION__
#endif

wxString GetwxStr(const char* str);
wxString GetwxStr(const std::string& str);


// //==============================================================================
// //      ListViewComboPopup
// //==============================================================================
// BEGIN_EVENT_TABLE(ListViewComboPopup, wxListView)
//     EVT_MOTION(ListViewComboPopup::OnMouseMove)
//     // NOTE: Left down event is used instead of left up right now
//     //       since MSW wxListCtrl doesn't seem to emit left ups
//     //       consistently.
//     EVT_LEFT_DOWN(ListViewComboPopup::OnMouseClick)
// END_EVENT_TABLE()

//==============================================================================
//      wxEnumerationParameter
//==============================================================================


BEGIN_EVENT_TABLE(myChoice, CHOICE_CLASS)
#ifdef USING_COMBOBOX
  EVT_COMBOBOX         ( wxID_ANY,  myChoice::OnChoiceUpdate)
  #if (!__WXMAC)
    EVT_COMBOBOX_DROPDOWN( wxID_ANY,  myChoice::OnDropDown)
  #else
    EVT_LEFT_DOWN    (myChoice::OnLeftDown)
    EVT_ENTER_WINDOW (myChoice::OnEnterWindow)
  #endif
#else
  EVT_CHOICE       (wxID_ANY,  myChoice::OnChoiceUpdate)
  //EVT_SET_FOCUS    (myChoice::OnFocus)
  EVT_LEFT_DOWN    (myChoice::OnLeftDown)
  EVT_ENTER_WINDOW (myChoice::OnEnterWindow)
#endif
END_EVENT_TABLE()

//---------------------------------------------------------------
void myChoice::OnFocus(wxFocusEvent& event)
{
  std::cout << "Focus ..." << std::endl;
  event.Skip();
}

//---------------------------------------------------------------
void myChoice::OnLeftDown(wxMouseEvent& event)
{
  std::cout << "Left down ..." << std::endl;
  this->UpdateListCallback();
//void (*cbf)( void*) = (void (*)(void*)) this->_callback;
//  cbf(this->_calldata);
  event.Skip();
}

//---------------------------------------------------------------
void myChoice::OnEnterWindow(wxMouseEvent& event)
{
  std::cout << "Enter Window..." << std::endl;
  this->UpdateListCallback();
//void (*cbf)( void*) = (void (*)(void*)) this->_callback;
//  cbf(this->_calldata);
  event.Skip();
}


  //---------------------------------------------------------------
void myChoice::Callback()
//
{
  if (this->_callback!=NULL) {
    void (*pf)( void*) = (void (*)(void*)) this->_callback;
    pf( this->_calldata);
  }
}

//---------------------------------------------------------------
void myChoice::UpdateListCallback()
//
{
  if (this->_updatelist_callback_functor.get()) {
    (*_updatelist_callback_functor)();
  } else 
    if (this->_updatelist_callback!=NULL) {
      void (*pf)( void*) = (void (*)(void*)) this->_updatelist_callback;
      pf( this->_updatelist_calldata);
    }
}

//---------------------------------------------------------------
wxEnumerationParameter::wxEnumerationParameter( wxWindow* parent, 
    int* param, const char* label,
    const std::string& tooltip
    ): wxBoxSizer(wxHORIZONTAL)
{
  this->_parameter       = param;
  this->_selection_param = string_ptr();
  this->_parent          = parent;
  this->_update_button   = NULL;

  this->_label     = new wxStaticText(this->_parent, wxID_ANY, wxString::FromAscii(label),
                        wxDefaultPosition,
                        wxDefaultSize,
                        wxALIGN_LEFT );

  this->_choice    = new myChoice(this->_parent,wxID_ANY);
  this->_choice->SetCallback((void*)wxEnumerationParameter::OnEnumUpdate,(void*) this);

  this->Add(this->_label, 0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 2);
  this->Add(this->_choice,1, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);

  if (tooltip!="") {
    _label->SetToolTip(GetwxStr(tooltip.c_str()));
    _choice->SetToolTip(GetwxStr(tooltip.c_str()));
  }

}


//---------------------------------------------------------------
wxEnumerationParameter::wxEnumerationParameter( wxWindow* parent, 
    string_ptr selection_param,
    const char* label,
    const std::string& tooltip,
    bool allowdrop
    ):  wxBoxSizer(wxHORIZONTAL), 
        _selection_param(selection_param)
{
  this->_parent          = parent;
  this->_parameter       = NULL;

  // allocate a new string if needed
  if (!_selection_param.get()) 
    _selection_param = string_ptr(new std::string(""));
  this->_update_button   = NULL;

  this->_label     = new wxStaticText(this->_parent, wxID_ANY, wxString::FromAscii(label));

  this->_choice    = new myChoice(this->_parent,wxID_ANY);
  if (allowdrop) {
    DndChoiceTextDropTarget* ChoiceTextImage = new DndChoiceTextDropTarget(this);
    this->_choice->SetDropTarget(ChoiceTextImage);
  }
  this->_choice->SetCallback((void*)wxEnumerationParameter::OnEnumUpdate,(void*) this);

  this->Add(this->_label, 0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 2);
  this->Add(this->_choice,1, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);

  if (tooltip!="") {
    _label->SetToolTip(GetwxStr(tooltip.c_str()));
    _choice->SetToolTip(GetwxStr(tooltip.c_str()));
  }

}


//---------------------------------------------------------------
wxEnumerationParameter::~wxEnumerationParameter()
{
 // printf("~wxEnumerationParameter()\n");
/*
    delete this->_label;  this->_label=NULL;
  delete this->_choice; this->_choice=NULL;
  */
  }

//------------------------------------------------------------------------------
void wxEnumerationParameter::AddUpdateCallback( void* update_cb,
  const std::string& tooltip)
{
/*
  _update_button = new wxBitmapButtonParameter(
        this->_parent, 
        "update", 
        wxBitmap(reload),
        update_cb,
        (void*) this);
  _update_button->SetToolTip(GetwxStr(tooltip.c_str()));
  this->Add(this->_update_button,0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
*/

  _choice->SetUpdateListCallback(update_cb,(void*) this);
}

//------------------------------------------------------------------------------
void wxEnumerationParameter::SetUpdateListCallbackFunctor(CallBackBase::ptr cb)
{
  _choice->SetUpdateListCallbackFunctor(cb);
}


//----------------------------------------------
void wxEnumerationParameter::AddChoice( int* choix_id, const char* label)
{
  int Pos = this->_choice->FindString(wxString::FromAscii(label), true);
  if (Pos != wxNOT_FOUND)
    *choix_id = Pos;
  else
    *choix_id = this->_choice->Append(wxString::FromAscii(label));
}


//----------------------------------------------
void wxEnumerationParameter::SetChoices( const boost::shared_ptr<wxArrayString>& choices)
{
  // get the current selected name
  wxString currentselection = GetStringSelection();
  
//   std::cout << "wxEnumerationParameter::SetChoices"
//             << " Current Item: "
//             << currentselection << std::endl;

  this->_choice->Clear();
  for(int i=0;i<(int)choices->GetCount();i++) {
    this->_choice->Append((*choices)[i]);
/*    std::cout << "wxEnumerationParameter::SetChoices"
              << " Added Item:"
              << (*choices)[i] << std::endl;*/
  }

  if (!this->_choice->SetStringSelection(currentselection))
    // if not able to set the same selection, set to the first item
    if (choices->GetCount()>0)
      SetSelection(0);

//   std::cout << "wxEnumerationParameter::SetChoices"
//             << " Current Item: "
//             << this->_choice->GetString(this->_choice->GetCurrentSelection())
//             << std::endl;
}

//----------------------------------------------
wxString wxEnumerationParameter::GetStringSelection()
{
#ifdef USING_COMBOBOX
  return this->_choice->GetValue();
#else
  return this->_choice->GetStringSelection();
#endif
}

//----------------------------------------------
void wxEnumerationParameter::SetSelection( int n)
{
  this->_choice->SetSelection(n);
  this->OnEnumUpdate(this);
}

//----------------------------------------------
void wxEnumerationParameter::Update()
{
  if (this->_parameter!=NULL)
    this->_choice->SetSelection(*this->_parameter);
  //  this->SetSelection(*this->_parameter);

  if (this->_selection_param.get()) {
    // eventually call update button callback function
    if (_update_button!=NULL) {
      _update_button->Callback();
    }
    wxString wxcp = wxString(_selection_param->c_str(),wxConvUTF8);
    this->_choice->SetStringSelection(wxcp);
    //this->OnEnumUpdate(this);
  }

}

void wxEnumerationParameter::OnEnumUpdate(void* data)
{
  wxEnumerationParameter* _this = (wxEnumerationParameter*) data;
  
  if (_this->_parameter!=NULL)
    (*_this->_parameter) = (int)_this->_choice->GetSelection();
  if (_this->_selection_param.get()) 
  {
    std::string res = std::string(_this->GetStringSelection().mb_str(wxConvUTF8));
    std::cout << __func__ << "setting selection string to " << res << std::endl;
    *_this->_selection_param = res;
  }
  _this->Callback();

}

//-------------------------------------------
void wxEnumerationParameter::EnableWidget(bool enable)
{
  if (enable!=_enabled) {
    _label         ->Enable(enable);
    _choice        ->Enable(enable);
    if (_update_button!=NULL)
      ((wxBitmapButton*)_update_button) ->Enable(enable);
    _enabled = enable;
  }
}

//---------------------------------------------
//void wxEnumerationParameter::OnButtonUpdate( wxCommandEvent& data)
//{
//}

///@cond wxCHECK
#if wxCHECK_VERSION(2,8,11)
//---------------------------------------------
wxString wxEnumerationParameter::GetAbsoluteName(const wxString& Name)
{
  wxString Result= wxT("");
  wxString Text;
  wxArrayString choices;
  std::string Simb;
  int Pos, Size;

  // eventually call update button callback function
  if (_update_button!=NULL)
    _update_button->Callback();

  choices = this->_choice->GetStrings();

  for(int i=0;i<(int)choices.GetCount();i++) {
      Text = choices[i];
      Pos = Text.Find(Name);
      if(Pos != wxNOT_FOUND)
      {
        Size = Pos + Name.Len();
        Simb = Text.SubString(Pos-2, Pos-1).ToAscii();

        if(Size == (int) Text.Len())
        {
          if(Simb == "::")
          {
            Result = Text;
            break;
          }
          else
          {
            Simb = Text.SubString(Pos-1, Pos-1).ToAscii();
            if(Simb == ".")
            {
              Result = Text;
              break;
            }
          }
        }
      }
  }
/*  std::cout << "wxEnumerationParameter::GetAbsoluteName->Obtained name: "
            << Result.ToAscii()
            << std::endl;*/
  return Result;
}
#endif
/// @endcond

