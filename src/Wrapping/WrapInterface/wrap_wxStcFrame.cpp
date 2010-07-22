//
// C++ Implementation: wrap_wxStcFrame
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_wxStcFrame.h"
#include "wrap_wxEditor.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include <wx/string.h>

//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_wxStcFrame(  WrapClass_wxStcFrame::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("wxStcFrame");

  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods( objectptr);

  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_wxStcFrame( wxStcFrame* si)
{
  // here wxStcFrame can be deleted
  boost::shared_ptr<wxStcFrame> _si_ptr( 
        si,
        wxwindow_nodeleter<wxStcFrame>() // deletion will be done by wxwidgets
      );

  WrapClass_wxStcFrame::ptr sip( new WrapClass_wxStcFrame(_si_ptr) );
  AMIObject::ptr amiobject(AddWrap_wxStcFrame(sip));

  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
//  wxStcFrame Constructor
//---------------------------------------------------
void  wrap_wxStcFrame::SetParametersComments() 
{
  ADDPARAMCOMMENT("wxWindow: parent");
  ADDPARAMCOMMENT("string: title");
  return_comments = "A wrapped wxStcFrame object.";
}
//---------------------------------------------------
BasicVariable::ptr wrap_wxStcFrame::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;

  std::string* title = NULL;
  int n=0;
  CLASS_GET_OBJECT_PARAM(wxWindow,var,parent);
  if (!get_val_ptr_param<string>( title, p, n))   ClassHelpAndReturn;

  if (parent.get() && title!=NULL)
    return CreateVar_wxStcFrame(
      new wxStcFrame(parent.get(), wxString(title->c_str(),wxConvUTF8)));
  else
    ClassHelpAndReturn;
    
}

//---------------------------------------------------
//  GetActiveEditor
//---------------------------------------------------
void WrapClass_wxStcFrame::
      wrap_GetActiveEditor::SetParametersComments() 
{
  return_comments = "The current active editor as a wxEditor object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStcFrame::
      wrap_GetActiveEditor::CallMember( ParamList* p)
{
  wxEditor* editor = this->_objectptr->_obj->GetActiveEditor();
  return CreateVar_wxEditor(editor);
}

//---------------------------------------------------
//  FileOpen
//---------------------------------------------------
void WrapClass_wxStcFrame::
      wrap_FileOpen::SetParametersComments() 
{
  ADDPARAMCOMMENT("string: filename.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStcFrame::
      wrap_FileOpen::CallMember( ParamList* p)
{
  std::string* filename = NULL;
  int n = 0;
  if (!get_val_ptr_param<string>( filename,  p, n))  ClassHelpAndReturn;

  this->_objectptr->_obj->FileOpen(
    wxString::FromAscii(filename->c_str())
    );

  return BasicVariable::ptr();
}

