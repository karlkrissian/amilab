//
// C++ Interface: wxFilenameParameter
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wxFilenameParameter_h_
#define _wxFilenameParameter_h_

#include "widget.hpp"
#include "myButton.h"
#include "myTextCtrl.h"
#include "StructParams.hpp"
#include <string>
#include <boost/shared_ptr.hpp>
#include <iostream.h>
typedef boost::shared_ptr<std::string>     string_ptr;

/*!
  \brief wxFilenameParameter: GUI for a filename
*/
class wxFilenameParameter : public wxBoxSizer, public wxGenericWidget
{
  /// _parameter is a smart pointer to the string ... needs to be initialized in the constructor !!!
  string_ptr    _parameter;
  wxWindow*     _parent;
  wxStaticText* _label;
  MyTextCtrl*   _text;
  myButton*     _button;
  
  std::string   _label_name;
  std::string   _label_value;
  int           _type;
  
  wxString      _default_path;
  wxString      _default_filename;
  wxString      _default_extension;
  wxString      _wildcard;

  public:
  
  wxFilenameParameter( wxWindow* parent, string_ptr value, const char* label,  type_label type=LabelLabel );
  
  ~wxFilenameParameter() {}
  
  static void BrowseFile( void* data);
  
  void SetDefaultPath(    const char* path) 
  { 
    _default_path = wxString::FromAscii(path);
  }

  void SetDefaultExtension(const char* ext)  
  {
    _default_extension=wxString::FromAscii(ext);
  }
  void SetWildcard(        const char* w)    
  {
    _wildcard=wxString::FromAscii(w);
  }
  
  static void OnStringUpdate(void* data);
  
  ///
  void SetValue( const char* value) 
  { 
    // allocate a new string if needed
    if (!_parameter.get()) {
      std::cerr <<"wxFilenameParameter::SetValue() parameter not allocated, creating new one ... !" << std::endl;
      _parameter = string_ptr(new std::string());
    }
   (*_parameter) = value; 
  } 

  void SetToolTip( const wxString& tt);

  void Update();

}; // wxFilenameParameter


#endif // _wxFilenameParameter_h_
