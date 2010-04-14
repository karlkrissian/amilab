//
// C++ Implementation: wrap_wxWindow
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_wxWindow.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_wxWindow(  WrapClass_wxWindow::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("HtmlWindow");

  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);

  objectptr->AddVar_ShowWin(        objectptr);

  return amiobject;
}

//---------------------------------------------------
BasicVariable::ptr wrap_wxWindow( ParamList* p)
{
    char functionname[] = "wxWindow";
    char description[]=" \n\
      Wrapped wxWindow class. \n\
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
      parent = obj->_win.get();
    } else {
      FILE_ERROR("Could not cast dynamically the variable to wxWindow.")
      HelpAndReturnVarPtr;
    }
  }  else {
    FILE_ERROR("Need a wrapped wxWindow object as parameter.")
    HelpAndReturnVarPtr;
  }

  boost::shared_ptr<wxWindow> wxw_ptr(
    new wxWindow( parent, wxID_ANY),
      wxwindow_nodeleter<wxWindow>() // deletion will be done by wxwidgets
    );

  WrapClass_wxWindow::ptr wp(new WrapClass_wxWindow(wxw_ptr));
  AMIObject::ptr amiobject (AddWrap_wxWindow(wp));

  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));

  return varres;
}


//---------------------------------------------------
//  Show
//---------------------------------------------------
void WrapClass_wxWindow::
      wrap_ShowWin::SetParametersComments() 
{
  ADDPARAMCOMMENT("integer: 1/0 for show/hide");
  return_comments = "Success result (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
      wrap_ShowWin::CallMember( ParamList* p)
{
  int show;
  int n = 0;

  if (!get_int_param(show, p, n)) ClassHelpAndReturn;
  int res = this->_objectptr->_win->Show(show);

  RETURN_VAR(int, res);
}
