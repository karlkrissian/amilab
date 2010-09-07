//
// C++ Implementation: wrap_MainFrame
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_MainFrame.h"
#include "wrap_wxStcFrame.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<MainFrame>::CreateVar( ParamList* p)
{
  WrapClass_MainFrame::wrap_MainFrame construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(MainFrame);

//
// static member for creating a variable from a pointer to MainFrame
//
Variable<AMIObject>::ptr WrapClass_MainFrame::CreateVar( MainFrame* sp)
{
  return 
    WrapClass<MainFrame>::CreateVar(
      new WrapClass_MainFrame(
        boost::shared_ptr<MainFrame>(sp,
        wxwindow_nodeleter<MainFrame>() 
        // deletion will be done by wxwidgets
        ))
    );
}

//---------------------------------------------------
//  MainFrame Constructor
//---------------------------------------------------
void  WrapClass_MainFrame::
  wrap_MainFrame::SetParametersComments() 
{
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_MainFrame::
  wrap_MainFrame::CallMember( ParamList* p)
{
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  GetAmilabEditor
//---------------------------------------------------
void WrapClass_MainFrame::
      wrap_GetAmilabEditor::SetParametersComments() 
{
  return_comments = "The current editor as a wxStcFrame object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_MainFrame::
      wrap_GetAmilabEditor::CallMember( ParamList* p)
{
  wxStcFrame* editor = this->_objectptr->_obj->GetAmilabEditor();
  return WrapClass_wxStcFrame::CreateVar(editor);
}

//---------------------------------------------------
//  AddMenuScript
//---------------------------------------------------
void WrapClass_MainFrame::
      wrap_AddMenuScript::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"Category of the script.");
  ADDPARAMCOMMENT_TYPE(string,"Menu label.");
  ADDPARAMCOMMENT_TYPE(string,"Script name.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_MainFrame::
      wrap_AddMenuScript::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,category,"");
  GET_PARAM(string,label,"");
  GET_PARAM(string,script,"");

  if ((category=="")||(label=="")||(script=="")) ClassHelpAndReturn;
  this->_objectptr->_obj->AddMenuScript(category,label,script);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  AddToMenu
//---------------------------------------------------
void WrapClass_MainFrame::
      wrap_AddToMenu::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"Name of the menu.");
  ADDPARAMCOMMENT_TYPE(string,"Category of the script.");
  ADDPARAMCOMMENT_TYPE(string,"Menu label.");
  ADDPARAMCOMMENT_TYPE(string,"Script name.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_MainFrame::
      wrap_AddToMenu::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,menuname,"");
  GET_PARAM(string,category,"");
  GET_PARAM(string,label,"");
  GET_PARAM(string,script,"");

  if ((menuname=="")||(category=="")||(label=="")||(script=="")) ClassHelpAndReturn;
  this->_objectptr->_obj->AddToMenu(menuname,category,label,script);
  return BasicVariable::ptr();
}
