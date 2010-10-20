//
// C++ Implementation: wxStringParameter
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wxStringParameter.h"

//==========================================================
//          String Parameter
//==========================================================

wxStringParameter::wxStringParameter( wxWindow* parent, string_ptr param,
                                      const char* label): wxBoxSizer(wxHORIZONTAL),
                                      _parameter(param)
{
  // allocate a new string if needed
  if (!_parameter.get()) 
    _parameter = string_ptr(new std::string(""));

  this->_parent    = parent;
  this->_label     = new wxStaticText(this->_parent, wxID_ANY, wxString::FromAscii(label));

  this->_text = new MyTextCtrl( this->_parent, wxID_ANY,
                              wxString::FromAscii(param->c_str()),
                              wxDefaultPosition, 
                              //wxSize(40, wxDefaultCoord),
                              wxDefaultSize,
                               wxTE_PROCESS_ENTER);
  //this->_text->SetSize(wxSIZE_AUTO_HEIGHT,10);
  this->_text->SetCallback((void*)wxStringParameter::OnStringUpdate,(void*) this);
  //this->_text->SetMinSize(wxSize(80,25));
  //this->_text->SetMinClientSize(wxSize(80,25));
  this->Add(this->_label, 0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 2);
  this->Add(this->_text,  1, wxALL | wxEXPAND,5 );
//wxALL, 5);
//wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
}


void wxStringParameter::OnStringUpdate( void* data) 
{
  wxStringParameter* _this=(wxStringParameter*)data;
  _this->SetValue((const char*) (_this->_text->GetValue()).mb_str(wxConvUTF8));

  _this->Callback();
  
}

// updating displayed value
void wxStringParameter::Update()
//   ------
{
  this->_text->SetValue(wxString::FromAscii(this->_parameter->c_str()));
} // Update()


void wxStringParameter::SetToolTip( const wxString& tt)
{
   _label  ->SetToolTip(tt);
   _text   ->SetToolTip(tt);
}

