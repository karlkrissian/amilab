//
// C++ Implementation: wxFilenameParameter
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wxFilenameParameter.h"

#ifdef _MSC_VER
  #define __func__ __FUNCTION__
  #define _CRT_SECURE_NO_WARNINGS
#endif

//================================================================
//          Filename Parameter
//================================================================

BEGIN_EVENT_TABLE(myButton, wxButton)
    EVT_BUTTON(  wxID_ANY,myButton::OnButton)
END_EVENT_TABLE();

wxFilenameParameter::wxFilenameParameter( wxWindow* parent,
                                          string_ptr param,
                                          const char* label,
                                          type_label type): wxBoxSizer(wxHORIZONTAL),
                                          _parameter(param)
{
  // allocate a new string if needed
  if (!_parameter.get()) {
    std::cerr << __func__ << "Parameter not allocated, creating a new one" << std::endl;
    _parameter = string_ptr(new std::string(""));
  }

  this->_default_path      = wxString::FromAscii("");
  this->_default_filename  = wxString::FromAscii("");
  this->_default_extension = wxString::FromAscii("");
  this->_wildcard          = wxString::FromAscii("*.*");
  
  this->_parent    = parent;
  this->_label     = new wxStaticText(this->_parent,
                                      wxID_ANY,
                                      wxString::FromAscii(label));

  this->_text = new MyTextCtrl( this->_parent,
                                wxID_ANY,
                                wxString::FromAscii(param->c_str()),
                                wxDefaultPosition, 
                                wxSize(40, wxDefaultCoord),
                                wxTE_PROCESS_ENTER);
  this->_text->SetCallback((void*)wxFilenameParameter::OnStringUpdate,(void*) this);
 //   this->_text->SetCallback((void*)wxFloatParameter::OnTextUpdate,(void*) this);
  this->_button = new myButton( this->_parent,
                                wxID_ANY,
                                wxString::FromAscii("Browse"));
  this->_button->SetCallback((void*)wxFilenameParameter::BrowseFile, (void*) this);

  this->Add(this->_label, 0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 2);
  this->Add(this->_text,  1, 0,5);
//wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
  this->Add(this->_button,0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
}

void wxFilenameParameter::BrowseFile(void* data)
{
  wxFilenameParameter* _this = (wxFilenameParameter*) data;
  wxString filename = wxFileSelector(
    wxString::FromAscii("Choose a file to open"),
    _this->_default_path,
    _this->_default_filename,
    _this->_default_extension,
    _this->_wildcard);
    
  if ( !filename.empty() )
  {
     _this->_text->SetValue(filename);
     _this->SetValue((const char*)filename.mb_str(wxConvUTF8));
  }
}
 

void wxFilenameParameter::OnStringUpdate( void* data) 
{
  wxFilenameParameter* _this=(wxFilenameParameter*)data;
  _this->SetValue((const char*)_this->_text->GetValue().mb_str(wxConvUTF8));
  
}

void wxFilenameParameter::SetToolTip( const wxString& tt)
{
   _label  ->SetToolTip(tt);
   _text   ->SetToolTip(tt);
}

// updating displayed value
void wxFilenameParameter::Update()
//   ------
{
  this->_text->SetValue(wxString::FromAscii(this->_parameter->c_str()));
} // Update()
