//
// C++ Interface: wxDirnameParameter
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wxDirnameParameter_h_
#define _wxDirnameParameter_h_

#include "widget.hpp"
#include <wx/filepicker.h>
#include <wx/filename.h>
#include <wx/stattext.h>

#include "StructParams.hpp"

#include <iostream>
#include <string>

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<std::string>     string_ptr;


//---------------------------------------------------------
class myDirPickerCtrl : public wxDirPickerCtrl
{
protected:
  void* _callback;
  void* _calldata;

public:
  myDirPickerCtrl( wxWindow *parent, 
              wxWindowID id, 
              const wxString& path = wxEmptyString, 
              const wxString& message = wxEmptyString, 
              const wxPoint& pos = wxDefaultPosition, 
              const wxSize& size = wxDefaultSize, 
              long style = wxDIRP_DEFAULT_STYLE)
    :wxDirPickerCtrl( parent,
                      id,
                      path,
                      message,
                      pos,
                      size,
                      style) 
  {
    std::cout << "myDirPickerCtrl, path = " << path.mb_str() << std::endl;
    std::cout << "exists ? = " << wxFileName::DirExists(path) << std::endl;
    _callback = _calldata = NULL;

  }
  
  void SetCallback(void* cb,void* cd) 
  {
    _callback=cb;
    _calldata=cd;
  }

  void OnDir(wxFileDirPickerEvent& event)
  {
    if (_callback==NULL) return;
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
  }


private:

    DECLARE_EVENT_TABLE();
};




/*!
  \brief wxDirnameParameter: GUI for a filename
*/
class wxDirnameParameter : public wxBoxSizer, public wxGenericWidget
{
  /// _parameter is a smart pointer to the string ... needs to be initialized in the constructor !!!
  string_ptr        _parameter;
  wxWindow*         _parent;
  wxStaticText*     _label;
  myDirPickerCtrl*  _dir_ctrl;

  wxString         _path;
  
  std::string   _label_name;
  std::string   _label_value;
  int           _type;
  
  public:
  
  wxDirnameParameter( wxWindow* parent, string_ptr value, const char* label);
  
  ~wxDirnameParameter() {}
  
  void UpdateParam(); 

  static void OnDirUpdate(void* data);
  
  ///
  void SetValue( const char* value) 
  { 
    // allocate a new string if needed
    if (!_parameter.get()) {
      std::cerr <<"wxDirnameParameter::SetValue() parameter not allocated, creating new one ... !" << std::endl;
      _parameter = string_ptr(new std::string());
    }
   (*_parameter) = value; 
  } 

  void SetToolTip( const wxString& tt);

  void Update();

  void EnableWidget(bool enable = true)
  {
    _label->Enable(enable);
    _dir_ctrl->Enable(enable);
    _enabled = enable;
  }

  
}; // wxDirnameParameter


#endif // _wxDirnameParameter_h_
