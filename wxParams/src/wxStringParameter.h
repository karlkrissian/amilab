//
// C++ Interface: wxStringParameter
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wxStringParameter_h_
#define _wxStringParameter_h_

#include "myTextCtrl.h"
#include "widget.hpp"
#include <string>

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<std::string>     string_ptr;

//==============================================================================
/*!
  \brief wxStringParameter: GUI for a string
*/
class wxStringParameter : public wxBoxSizer, public wxGenericWidget
{
  string_ptr    _parameter;
  wxWindow*     _parent;
  wxStaticText* _label;
  MyTextCtrl*   _text;
  
  std::string   _label_name;
  std::string   _label_value;
  int           _type;
  
  public:
  
  wxStringParameter( wxWindow* parent, string_ptr value, const char* label);
  
  ~wxStringParameter() {}
    
  ///
  void SetValue( const char* value) 
  { 
    // allocate a new string if needed
    if (!_parameter.get()) 
      _parameter = string_ptr(new std::string());
    *_parameter = value; 
  }
  
  static void OnStringUpdate(void* data);

  // updating displayed value
  void Update();
  //   ------

  void SetToolTip( const wxString& tt);

}; // wxStringParameter



#endif // _wxStringParameter_h_
