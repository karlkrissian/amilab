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
  this->_selection_param = NULL,
  this->_parent          = parent;

  this->_label     = new wxStaticText(this->_parent, wxID_ANY, wxString::FromAscii(label));
  if (tooltip!="") _label->SetToolTip(GetwxStr(tooltip.c_str()));

  this->_choice    = new myChoice(this->_parent,wxID_ANY);
  this->_choice->SetCallback((void*)wxEnumerationParameter::OnEnumUpdate,(void*) this);

  this->Add(this->_label, 0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
  this->Add(this->_choice,0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
}


//---------------------------------------------------------------
wxEnumerationParameter::wxEnumerationParameter( wxWindow* parent, 
    std::string* selection_param,
    const char* label,
    const std::string& tooltip
    ): wxBoxSizer(wxHORIZONTAL)
{
  this->_parent          = parent;
  this->_parameter       = NULL;
  this->_selection_param = selection_param,

  this->_label     = new wxStaticText(this->_parent, wxID_ANY, wxString::FromAscii(label));
  if (tooltip!="") _label->SetToolTip(GetwxStr(tooltip.c_str()));

  this->_choice    = new myChoice(this->_parent,wxID_ANY);
  this->_choice->SetCallback((void*)wxEnumerationParameter::OnEnumUpdate,(void*) this);

  this->Add(this->_label, 0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
  this->Add(this->_choice,0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
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
void wxEnumerationParameter::AddUpdateButton( void* update_cb)
{
  _update_button = new wxBitmapButtonParameter(
        this->_parent, 
        "update", 
        wxBitmap(reload),
        update_cb,
        (void*) this);
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
  this->_choice->Clear();
  for(int i=0;i<choices->GetCount();i++) {
    this->_choice->Append((*choices)[i]);
  }
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
}

void wxEnumerationParameter::Update()
{
  if (this->_parameter!=NULL)
    this->SetSelection(*this->_parameter);
}

void wxEnumerationParameter::OnEnumUpdate(void* data)
{
  wxEnumerationParameter* _this = (wxEnumerationParameter*) data;
  
  if (_this->_parameter!=NULL)
    (*_this->_parameter) = (int)_this->_choice->GetSelection();
  if (_this->_selection_param!=NULL)
    (*_this->_selection_param) = _this->_choice->GetStringSelection().mb_str(wxConvUTF8);
  _this->Callback();
}

//---------------------------------------------
//void wxEnumerationParameter::OnButtonUpdate( wxCommandEvent& data)
//{
//}

