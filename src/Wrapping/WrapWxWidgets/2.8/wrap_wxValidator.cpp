/**
 * C++ Interface: wrap_wxValidator
 *
 * Description: wrapping wxValidator
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxObject.h"
#include "wrap_wxValidator.h"
#include "wrap_wxWindow.h"
#include "wrap_wxWindowBase.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxValidator.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxValidator>::CreateVar( ParamList* p)
{
  WrapClass_wxValidator::wrap_wxValidator construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxValidator);
AMI_DEFINE_VARFROMSMTPTR(wxValidator);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxValidator>::CreateVar( wxValidator* val)
{ 
  boost::shared_ptr<wxValidator> obj_ptr(val,wxwindow_nodeleter<wxValidator>());
  return AMILabType<wxValidator>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxValidator
//
Variable<AMIObject>::ptr WrapClass_wxValidator::CreateVar( wxValidator* sp)
{
  boost::shared_ptr<wxValidator> di_ptr(
    sp,
    wxwindow_nodeleter<wxValidator>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxValidator>::CreateVar(
      new WrapClass_wxValidator(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxValidator::AddMethods(WrapClass<wxValidator>::ptr this_ptr )
{
  /*
      // Add members from wxEvtHandler
      WrapClass_wxEvtHandler::ptr parent_wxEvtHandler(        boost::dynamic_pointer_cast<WrapClass_wxEvtHandler >(this_ptr));
      parent_wxEvtHandler->AddMethods(parent_wxEvtHandler);
      */


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_Clone( this_ptr);
      AddVar_Copy( this_ptr);
      AddVar_Validate( this_ptr);
      AddVar_TransferToWindow( this_ptr);
      AddVar_TransferFromWindow( this_ptr);
      AddVar_GetWindow( this_ptr);
      AddVar_SetWindow( this_ptr);
      AddVar_IsSilent( this_ptr);
      AddVar_SetBellOnError( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxValidator::wxValidator()
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_wxValidator::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_wxValidator::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxValidator* _newobj = new wxValidator();
  BasicVariable::ptr res = WrapClass_wxValidator::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxObject * wxValidator::Clone()
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxObject * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = WrapClass_wxObject::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxValidator::Copy(wxValidator const & val)
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_Copy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxValidator, "parameter named 'val'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_Copy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxValidator > val_smtptr;
  if (!get_val_smtptr_param<wxValidator >(val_smtptr,_p,_n)) ClassHelpAndReturn;
  wxValidator const & val = *val_smtptr;

  bool res =   this->_objectptr->GetObj()->Copy(val);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxValidator::Validate(wxWindow * param0)
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_Validate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'param0'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_Validate::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > param0_smtptr;
  if (!get_val_smtptr_param<wxWindow >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* param0 = param0_smtptr.get();

  bool res =   this->_objectptr->GetObj()->Validate(param0);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxValidator::TransferToWindow()
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_TransferToWindow::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_TransferToWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->TransferToWindow();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxValidator::TransferFromWindow()
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_TransferFromWindow::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_TransferFromWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->TransferFromWindow();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxValidator::GetWindow()
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_GetWindow::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_GetWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetWindow();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxValidator::SetWindow(wxWindowBase * win)
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_SetWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'win'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_SetWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowBase > win_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(win_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindowBase* win = win_smtptr.get();

  this->_objectptr->GetObj()->SetWindow(win);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxValidator::IsSilent()
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_IsSilent::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_IsSilent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsSilent();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxValidator::SetBellOnError(bool doIt = true)
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_SetBellOnError::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'doIt' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_SetBellOnError::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int doIt_int = ((true==true)?1:0);;
  if (!get_val_param<int >(doIt_int,_p,_n)) ClassHelpAndReturn;
  bool doIt = (bool) (doIt_int>0.5);

  this->_objectptr->GetObj()->SetBellOnError(doIt);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxValidator::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

