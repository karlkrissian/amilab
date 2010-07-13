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
#include "wrap_wxColour.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "wrap_wxSize.h"

#define GET_PARAM(type,varname,defaultval) \
  type varname = defaultval; \
  if (!get_val_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_wxWindow(  WrapClass_wxWindow::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("HtmlWindow");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods(objectptr);

  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_wxWindow( wxWindow* si)
{
  // here wxColour can be deleted
  boost::shared_ptr<wxWindow> si_ptr(
    si,
    wxwindow_nodeleter<wxWindow>() // deletion will be done by wxwidgets
  );

  WrapClass_wxWindow::ptr sip(new WrapClass_wxWindow(si_ptr));
  AMIObject::ptr amiobject(AddWrap_wxWindow(sip));
  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
// Method that adds wrapping of wxWindow
//---------------------------------------------------

void  wrap_wxWindow::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(wxWindow,"Parent window");
  return_comments = "A wrapped wxWindow object.";
}
//---------------------------------------------------
BasicVariable::ptr wrap_wxWindow::CallMember( ParamList* p)
{
  int n = 0;
  std::string* title = NULL;

  if (!p) ClassHelpAndReturn;
  CLASS_GET_OBJECT_PARAM(wxWindow,var,parent);
  if (parent.get())
    return CreateVar_wxWindow(new wxWindow(parent.get(), wxID_ANY));
  else
    ClassHelpAndReturn;
}

//---------------------------------------------------
//  GetMinSize
//---------------------------------------------------
void WrapClass_wxWindow::
      wrap_GetMinSize::SetParametersComments() 
{
  return_comments = "wxSize object";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
      wrap_GetMinSize::CallMember( ParamList* p)
{
  wxSize size = this->_objectptr->_obj->GetMinSize();
  return CreateVar_wxSize(new wxSize(size));
}

//---------------------------------------------------
//  SetMinSize
//---------------------------------------------------
void WrapClass_wxWindow::
      wrap_SetMinSize::SetParametersComments() 
{
  ADDPARAMCOMMENT("wxSize object");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
      wrap_SetMinSize::CallMember( ParamList* p)
{
  int n=0;
  GET_OBJECT_PARAM(wxSize,size,_obj);
  if (!size.get()) ClassHelpAndReturn;
  this->_objectptr->_obj->SetMinSize(*size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Show
//---------------------------------------------------
void WrapClass_wxWindow::
      wrap_ShowWin::SetParametersComments() 
{
  ADDPARAMCOMMENT("integer: 1/0 for show/hide (def:1)");
  return_comments = "Success result (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
      wrap_ShowWin::CallMember( ParamList* p)
{
  int show = 1;
  int n = 0;

  get_int_param(show, p, n, false);
  int res = this->_objectptr->_obj->Show(show);

  RETURN_VAR(int, res);
}

//---------------------------------------------------
//  SetSize
//---------------------------------------------------
void WrapClass_wxWindow::
      wrap_SetSize::SetParametersComments() 
{
  ADDPARAMCOMMENT("integer: x");
  ADDPARAMCOMMENT("integer: y");
  ADDPARAMCOMMENT("integer: width");
  ADDPARAMCOMMENT("integer: height");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
      wrap_SetSize::CallMember( ParamList* p)
{
  int x;
  int y;
  int width;
  int height;
  int n = 0;

  if (!get_int_param(x, p, n)) ClassHelpAndReturn;
  if (!get_int_param(y, p, n)) ClassHelpAndReturn;
  if (!get_int_param(width, p, n)) ClassHelpAndReturn;
  if (!get_int_param(height, p, n)) ClassHelpAndReturn;
  this->_objectptr->_obj->SetSize(x,y,width,height);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetBackgroundColour
//---------------------------------------------------
void WrapClass_wxWindow::
      wrap_SetBackgroundColour::SetParametersComments() 
{
  ADDPARAMCOMMENT("wxColour: The colour to be used as the background colour, pass wxNullColour to reset to the default colour.");
  return_comments="bool";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
      wrap_SetBackgroundColour::CallMember( ParamList* p)
{
  int n = 0;

  GET_OBJECT_PARAM(wxColour,colour,_obj);
  if (!colour.get()) ClassHelpAndReturn;

  int res = this->_objectptr->_obj->SetBackgroundColour(*colour);
  RETURN_VAR(int,res);
}


