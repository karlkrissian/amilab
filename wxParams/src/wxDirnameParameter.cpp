//
// C++ Implementation: wxDirnameParameter
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wxDirnameParameter.h"

#ifdef _MSC_VER
  #define __func__ __FUNCTION__
  #define _CRT_SECURE_NO_WARNINGS
#endif

enum {
  wxID_DIRPATH = 1000,
};

BEGIN_EVENT_TABLE(myDirPickerCtrl, wxDirPickerCtrl)
  EVT_DIRPICKER_CHANGED(wxID_DIRPATH, myDirPickerCtrl::OnDir)
END_EVENT_TABLE();

 

//================================================================
//          Dirname Parameter
//================================================================

//wxID_HelpPath

wxDirnameParameter::wxDirnameParameter( wxWindow* parent,
                                          string_ptr param,
                                          const char* label): wxBoxSizer(wxHORIZONTAL),
                                          _parameter(param)
{
  // allocate a new string if needed
  if (!_parameter.get()) {
    std::cerr << __func__ << "Parameter not allocated, creating a new one" << std::endl;
    _parameter = string_ptr(new std::string(""));
  }

  this->_parent    = parent;
  this->_label     = new wxStaticText(this->_parent,
                                      wxID_ANY,
                                      wxString::FromAscii(label));
  _path = wxString::FromAscii(param->c_str());
  std::cout << "wxDirnameParameter, param = " << _path << std::endl;
  this->_dir_ctrl = new myDirPickerCtrl(this->_parent,
            wxID_DIRPATH,
            _path, 
            wxT("Select a folder"));
  this->_dir_ctrl->SetCallback((void*)wxDirnameParameter::OnDirUpdate,(void*) this);
  this->_dir_ctrl->SetPath(_path);

  this->Add(this->_label, 0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 2);
  this->Add(this->_dir_ctrl,  1, 0,5);
  UpdateParam();
}

void wxDirnameParameter::UpdateParam( ) 
{
  wxString path = _dir_ctrl->GetPath();
  SetValue((const char*)path.mb_str(wxConvUTF8));
}

void wxDirnameParameter::OnDirUpdate( void* data) 
{
  wxDirnameParameter* _this=(wxDirnameParameter*)data;
  _this->UpdateParam();
}

void wxDirnameParameter::SetToolTip( const wxString& tt)
{
   _label     ->SetToolTip(tt);
   _dir_ctrl  ->SetToolTip(tt);
}

// updating displayed value
void wxDirnameParameter::Update()
//   ------
{
  _path = wxString::FromAscii(this->_parameter->c_str());
  this->_dir_ctrl->SetPath(_path);
  this->_dir_ctrl->Update();
  this->_dir_ctrl->Refresh();
} // Update()
