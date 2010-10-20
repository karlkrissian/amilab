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


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxStcFrame>::CreateVar( ParamList* p)
{
  WrapClass_wxStcFrame::wrap_wxStcFrame construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxStcFrame);

//
// static member for creating a variable from a pointer to wxStcFrame
//
Variable<AMIObject>::ptr WrapClass_wxStcFrame::CreateVar( wxStcFrame* sp)
{
  return 
    WrapClass<wxStcFrame>::CreateVar(
      new WrapClass_wxStcFrame(
        boost::shared_ptr<wxStcFrame>(sp,
        wxwindow_nodeleter<wxStcFrame>() 
        // deletion will be done by wxwidgets
        ))
    );
}



//---------------------------------------------------
//  wxStcFrame Constructor
//---------------------------------------------------
void WrapClass_wxStcFrame::
wrap_wxStcFrame::SetParametersComments() 
{
  ADDPARAMCOMMENT("wxWindow: parent");
  ADDPARAMCOMMENT("string: title");
  return_comments = "A wrapped wxStcFrame object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStcFrame::
wrap_wxStcFrame::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;

  std::string* title = NULL;
  int n=0;
  CLASS_GET_OBJECT_PARAM(wxWindow,var,parent);
  if (!get_val_ptr_param<string>( title, p, n))   ClassHelpAndReturn;

  if (parent.get() && title!=NULL)
    return WrapClass_wxStcFrame::CreateVar(
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
  return WrapClass_wxEditor::CreateVar(editor);
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
    wxString(filename->c_str(),wxConvUTF8)
    );

  return BasicVariable::ptr();
}

