//
// C++ Interface: wxStringSelectionParameter
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _WX_StringSelectionParameter_H_
#define _WX_StringSelectionParameter_H_

#include "wxEnumerationParameter.h"

//==============================================================================
class wxStringSelectionParameter: public wxBoxSizer, public wxGenericWidget
{
  int*          _parameter;
  wxWindow*     _parent;
  wxStaticText* _label;
  myChoice*     _choice;

  public:
  
  wxStringSelectionParameter( wxWindow* parent, wxString* param, const char* label);
  
  ~wxStringSelectionParameter();
  
  void SetList( const wxArrayString& l);
  
  void SetSelection(int n);
  
  void Update();
  
  static void OnUpdate(void* data);

}; // wxStringSelectionParameter

#endif // _WX_StringSelectionParameter_H_
