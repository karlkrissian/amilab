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

#include "MainFrame.h"

#include "wrap_wxAuiManager.h"
#include "wrap_wxAuiNotebook.h"
#include "wrap_wxAuiPaneInfo.h"

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<MainFrame>::CreateVar( ParamList* p, bool quiet )
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
  ADDPARAMCOMMENT_TYPE(std::string,"Category of the script.");
  ADDPARAMCOMMENT_TYPE(std::string,"Menu label.");
  ADDPARAMCOMMENT_TYPE(std::string,"Script name.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_MainFrame::
      wrap_AddMenuScript::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(std::string,category,"");
  GET_PARAM(std::string,label,"");
  GET_PARAM(std::string,script,"");

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
  ADDPARAMCOMMENT_TYPE(std::string,"Name of the menu.");
  ADDPARAMCOMMENT_TYPE(std::string,"Category of the script.");
  ADDPARAMCOMMENT_TYPE(std::string,"Menu label.");
  ADDPARAMCOMMENT_TYPE(std::string,"Script name.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_MainFrame::
      wrap_AddToMenu::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(std::string,menuname,"");
  GET_PARAM(std::string,category,"");
  GET_PARAM(std::string,label,"");
  GET_PARAM(std::string,script,"");

  if ((menuname=="")||(category=="")||(label=="")||(script=="")) ClassHelpAndReturn;
  this->_objectptr->_obj->AddToMenu(menuname,category,label,script);
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  GetAuiManager
//---------------------------------------------------
void WrapClass_MainFrame::
      wrap_GetAuiManager::SetParametersComments() 
{
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_MainFrame::
      wrap_GetAuiManager::CallMember( ParamList* p)
{
  wxAuiManager& mgr =   this->_objectptr->_obj->GetAuiManager();
  return AMILabType<wxAuiManager>::CreateVar(&mgr,true);
}

//---------------------------------------------------
//  GetMainBook
//---------------------------------------------------
void WrapClass_MainFrame::
      wrap_GetMainBook::SetParametersComments() 
{
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_MainFrame::
      wrap_GetMainBook::CallMember( ParamList* p)
{
  wxAuiNotebook* nb =   this->_objectptr->_obj->GetMainBook();
  return AMILabType<wxAuiNotebook>::CreateVar(nb,true);
}

//---------------------------------------------------
//  GetAuiPaneInfo
//---------------------------------------------------
void WrapClass_MainFrame::
      wrap_GetAuiPaneInfo::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(std::string,"Name of the menu."); 
  return_comments = "Reference to the AuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_MainFrame::
      wrap_GetAuiPaneInfo::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(std::string,paneinfo_name,"");

  wxAuiPaneInfo* pi = &(this->_objectptr->_obj->GetAuiManager().GetPane(wxString(paneinfo_name.c_str(), wxConvUTF8)
));
  boost::shared_ptr<wxAuiPaneInfo> valptr = boost::shared_ptr<wxAuiPaneInfo>(pi,smartpointer_nodeleter<wxAuiPaneInfo>());
  return AMILabType<wxAuiPaneInfo>::CreateVarFromSmtPtr(valptr);
}
