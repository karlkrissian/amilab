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

//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_wxHtmlWindow(  WrapClass_wxHtmlWindow::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("HtmlWindow");

  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);

  objectptr->AddVar_LoadFile(        objectptr);
  objectptr->AddVar_HistoryBack(     objectptr);
  objectptr->AddVar_HistoryForward(  objectptr);

  return amiobject;
}

//---------------------------------------------------
BasicVariable::ptr wrap_wxHtmlWindow( ParamList* p)
{
    char functionname[] = "HtmlWindow";
    char description[]=" \n\
      Wrapped wxHtmlWindow class. \n\
            ";
    char parameters[] =" \n\
      - Parent window ... \n\
            ";

  int n = 0;
  std::string* title = NULL;

  Variable<AMIObject>::ptr var;
  wxWindow* parent = NULL;

  if (get_var_param<AMIObject>(var, p, n)) 
  {
    WrapClassBase::ptr object( var->Pointer()->GetWrappedObject());
    WrapClass_wxWindow::ptr obj( boost::dynamic_pointer_cast<WrapClass_wxWindow>(object));
    if (obj.get()) {
      parent = obj->_obj.get();
    } else {
      FILE_ERROR("Could not cast dynamically the variable to wxWindow.")
      HelpAndReturnVarPtr;
    }
  }  else {
    FILE_ERROR("Need a wrapped wxWindow object as parameter.")
    HelpAndReturnVarPtr;
  }

  boost::shared_ptr<wxHtmlWindow> wxw_ptr(
    new wxHtmlWindow( parent),
      wxwindow_nodeleter<wxHtmlWindow>() // deletion will be done by wxwidgets
    );

  WrapClass_wxHtmlWindow::ptr wp(new WrapClass_wxHtmlWindow(wxw_ptr));


  AMIObject::ptr amiobject (AddWrap_wxHtmlWindow(wp));

  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));

  return varres;
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
  if (!get_val_ptr_param<string>( filename,  p, n)) 
    ClassHelpAndReturn;

  wxFileName wxfilename(wxString::FromAscii(filename->c_str())); 
  int res = this->_objectptr->_obj->LoadFile(wxfilename);

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
