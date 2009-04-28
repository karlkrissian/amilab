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

wxString GetwxStr(const char* str);
wxString GetwxStr(const string& str);

//==============================================================================
//      wxEnumerationParameter
//==============================================================================

BEGIN_EVENT_TABLE(myChoice, wxChoice)
  EVT_CHOICE    (wxID_ANY,  myChoice::OnChoiceUpdate)
END_EVENT_TABLE()


wxEnumerationParameter::wxEnumerationParameter( wxWindow* parent, int* param, const char* label): wxBoxSizer(wxHORIZONTAL)
{
  this->_parameter = param;
  this->_parent    = parent;

  this->_label     = new wxStaticText(this->_parent, wxID_ANY, wxString::FromAscii(label));

  this->_choice    = new myChoice(this->_parent,wxID_ANY);
  this->_choice->SetCallback((void*)wxEnumerationParameter::OnEnumUpdate,(void*) this);

  this->Add(this->_label, 0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
  this->Add(this->_choice,0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
}

wxEnumerationParameter::~wxEnumerationParameter()
{
 // printf("~wxEnumerationParameter()\n");
/*
    delete this->_label;  this->_label=NULL;
  delete this->_choice; this->_choice=NULL;
  */
  }

void wxEnumerationParameter::AddChoice( int* choix_id, const char* label)
{
    *choix_id = this->_choice->Append(wxString::FromAscii(label));
}

void wxEnumerationParameter::SetSelection( int n)
{
   this->_choice->SetSelection(n);
}

void wxEnumerationParameter::Update()
{
  this->SetSelection(*this->_parameter);
}

void wxEnumerationParameter::OnEnumUpdate(void* data)
{
  wxEnumerationParameter* _this = (wxEnumerationParameter*) data;
  
  (*_this->_parameter) = (int)_this->_choice->GetSelection();
  _this->Callback();
}

