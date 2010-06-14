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

//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_wxEditor(  WrapClass_wxEditor::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("wxEditor");

  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods( objectptr);

  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_wxEditor( wxEditor* si)
{
  // here wxEditor can be deleted
  boost::shared_ptr<wxEditor> si_ptr( 
        si,
        wxwindow_nodeleter<wxEditor>() // deletion will be done by wxwidgets
      );

  WrapClass_wxEditor::ptr sip( new WrapClass_wxEditor(si_ptr) );
  AMIObject::ptr amiobject(AddWrap_wxEditor(sip));

  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
//  wxEditor Constructor
//---------------------------------------------------
void  wrap_wxEditor::SetParametersComments() 
{
  ADDPARAMCOMMENT("wxWindow: parent");
  return_comments = "A wrapped wxEditor object.";
}
//---------------------------------------------------
BasicVariable::ptr wrap_wxEditor::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  CLASS_GET_OBJECT_PARAM(wxWindow,var,parent);
  if (parent.get())
    return CreateVar_wxEditor(new wxEditor(parent.get()));
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
  if (!get_val_ptr_param<string>( filename,  p, n))  ClassHelpAndReturn;

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

