//
// C++ Implementation: wrap_wxEditor
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_wxEditor.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxEditor>::CreateVar( ParamList* p)
{
  WrapClass_wxEditor::wrap_wxEditor construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxEditor);

//
// static member for creating a variable from a pointer to wxEditor
//
Variable<AMIObject>::ptr WrapClass_wxEditor::CreateVar( wxEditor* sp)
{
  return 
    WrapClass<wxEditor>::CreateVar(
      new WrapClass_wxEditor(
        boost::shared_ptr<wxEditor>(sp,
        wxwindow_nodeleter<wxEditor>() 
        // deletion will be done by wxwidgets
        ))
    );
}



//---------------------------------------------------
//  wxEditor Constructor
//---------------------------------------------------
void  WrapClass_wxEditor::
      wrap_wxEditor::SetParametersComments() 
{
  ADDPARAMCOMMENT("wxWindow: parent");
  return_comments = "A wrapped wxEditor object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEditor::
      wrap_wxEditor::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  CLASS_GET_OBJECT_PARAM(wxWindow,var,parent);
  if (parent.get())
    return WrapClass_wxEditor::CreateVar(new wxEditor(parent.get()));
  else
    ClassHelpAndReturn;
}

//---------------------------------------------------
//  LoadFile
//---------------------------------------------------
void WrapClass_wxEditor::
      wrap_LoadFile::SetParametersComments() 
{
  ADDPARAMCOMMENT("string: filename.");
  return_comments = "boolean: success value.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEditor::
      wrap_LoadFile::CallMember( ParamList* p)
{
  std::string* filename = NULL;
  int n = 0;
  if (!get_val_ptr_param<std::string>( filename,  p, n))  ClassHelpAndReturn;

  int res = this->_objectptr->_obj->LoadFile(wxString::FromAscii(filename->c_str()));
  RETURN_VAR(int,res);
}

//---------------------------------------------------
//  ShowLineNumbers
//---------------------------------------------------
void WrapClass_wxEditor::
      wrap_ShowLineNumbers::SetParametersComments() 
{
  ADDPARAMCOMMENT("boolean: shows/hides line numbers.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEditor::
      wrap_ShowLineNumbers::CallMember( ParamList* p)
{
  int n = 0;
  int show = 1;
  get_int_param(show, p, n, false);
  this->_objectptr->_obj->ShowLineNumbers(show);
  return BasicVariable::ptr();
}

