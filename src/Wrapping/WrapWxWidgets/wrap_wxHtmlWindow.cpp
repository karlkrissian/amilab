//
// C++ Implementation: wrap_wxHtmlWindow
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_wxHtmlWindow.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "wrap_wxWindow.h"
#include "myHtmlWindow.h"

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHtmlWindow>::CreateVar( ParamList* p)
{
  WrapClass_wxHtmlWindow::wrap_wxHtmlWindow construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxHtmlWindow);

//
// static member for creating a variable from a pointer to wxHtmlWindow
//
Variable<AMIObject>::ptr WrapClass_wxHtmlWindow::CreateVar( wxHtmlWindow* sp)
{
  
  boost::shared_ptr<wxHtmlWindow> obj_ptr(sp,
        // deletion will be done by wxwidgets
        wxwindow_nodeleter<wxHtmlWindow>());

  return 
    WrapClass<wxHtmlWindow>::CreateVar(
      new WrapClass_wxHtmlWindow( obj_ptr));
}



//---------------------------------------------------
// Method that adds wrapping of wxHtmlWindow
//---------------------------------------------------

void  WrapClass_wxHtmlWindow::
      wrap_wxHtmlWindow::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(wxWindow,"Parent window.");
  return_comments = "A wrapped wxHtmlWindow object.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
      wrap_wxHtmlWindow::CallMember( ParamList* p)
{
  int n = 0;
//  std::string* title = NULL;

  CLASS_GET_OBJECT_PARAM(wxWindow,var,parent);

  if (parent.get()){
    return WrapClass_wxHtmlWindow::CreateVar(
      new myHtmlWindow(parent.get()));
  }
  else
    ClassHelpAndReturn;
}



//---------------------------------------------------
//  LoadFile
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
      wrap_LoadFile::SetParametersComments() 
{
  ADDPARAMCOMMENT("string: filename to load.");
  return_comments = "Success result (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
      wrap_LoadFile::CallMember( ParamList* p)
{
  std::string* filename = NULL;
  int n = 0;
  if (!get_val_ptr_param<std::string>( filename,  p, n)) 
    ClassHelpAndReturn;

  wxFileName wxfilename(wxString(filename->c_str(),wxConvUTF8)); 
  int res = this->_objectptr->_obj->LoadFile(wxfilename);

  RETURN_VAR(int, res);
}

//---------------------------------------------------
//  LoadPage
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
      wrap_LoadPage::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(std::string,"string: filename to load.");
  return_comments = "Success result (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
      wrap_LoadPage::CallMember( ParamList* p)
{
  int n = 0;
  GET_PARAM(std::string,page,"");
  wxString wxstPage(page.c_str(), wxConvUTF8);
  int res = this->_objectptr->_obj->LoadPage(wxstPage);
  RETURN_VAR(int, res);
}

//---------------------------------------------------
//  HistoryBack
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
      wrap_HistoryBack::SetParametersComments() 
{
  return_comments = "Success result (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
      wrap_HistoryBack::CallMember( ParamList* p)
{
  int res = this->_objectptr->_obj->HistoryBack();
  RETURN_VAR(int, res);
}

//---------------------------------------------------
//  HistoryForward
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
      wrap_HistoryForward::SetParametersComments() 
{
  return_comments = "Success result (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
      wrap_HistoryForward::CallMember( ParamList* p)
{
  int res = this->_objectptr->_obj->HistoryForward();
  RETURN_VAR(int, res);
}
