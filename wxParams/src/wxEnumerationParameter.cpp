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

#include "slick/16x16/actions/reload.xpm"

#ifdef _MSC_VER
  #define __func__ __FUNCTION__
#endif

wxString GetwxStr(const char* str);
wxString GetwxStr(const string& str);

//==============================================================================
//      wxEnumerationParameter
//==============================================================================

BEGIN_EVENT_TABLE(myChoice, wxChoice)
  EVT_CHOICE    (wxID_ANY,  myChoice::OnChoiceUpdate)
END_EVENT_TABLE()


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
  this->Add(this->_choice,0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);

  if (tooltip!="") {
    _label->SetToolTip(GetwxStr(tooltip.c_str()));
    _choice->SetToolTip(GetwxStr(tooltip.c_str()));
  }

}


//---------------------------------------------------------------
wxEnumerationParameter::wxEnumerationParameter( wxWindow* parent, 
    string_ptr selection_param,
    const char* label,
    const std::string& tooltip
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
  this->_choice->SetCallback((void*)wxEnumerationParameter::OnEnumUpdate,(void*) this);

  this->Add(this->_label, 0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 2);
  this->Add(this->_choice,0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);

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

//----------------------------------------------
void wxEnumerationParameter::AddUpdateButton( void* update_cb,
  const std::string& tooltip)
{
  _update_button = new wxBitmapButtonParameter(
        this->_parent, 
        "update", 
        wxBitmap(reload),
        update_cb,
        (void*) this);
  _update_button->SetToolTip(GetwxStr(tooltip.c_str()));
  this->Add(this->_update_button,0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
}


//----------------------------------------------
void wxEnumerationParameter::AddChoice( int* choix_id, const char* label)
{
    *choix_id = this->_choice->Append(wxString::FromAscii(label));
}


//----------------------------------------------
void wxEnumerationParameter::SetChoices( const boost::shared_ptr<wxArrayString>& choices)
{
  // get the current selected name
  wxString currentselection = GetStringSelection();
  this->_choice->Clear();
  for(int i=0;i<choices->GetCount();i++) {
    this->_choice->Append((*choices)[i]);
  }

  if (!this->_choice->SetStringSelection(currentselection))
    // if not able to set the same selection, set to the first item
    if (choices->GetCount()>0)
      SetSelection(0);
}


//----------------------------------------------
wxString wxEnumerationParameter::GetStringSelection()
{
  return this->_choice->GetStringSelection();
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
    std::string res = std::string(_this->_choice->GetStringSelection().mb_str(wxConvUTF8));
    cout << __func__ << "setting selection string to " << res << endl;
    *_this->_selection_param = res;
  }
  _this->Callback();

}

//-------------------------------------------
void wxEnumerationParameter::Enable(bool enable)
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

