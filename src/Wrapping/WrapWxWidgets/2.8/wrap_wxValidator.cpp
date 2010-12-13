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

/*
//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
*/

#include "wrap_wxValidator.h"

// get all the required includes
// #include "..."
#ifndef wxObject_declared
  #define wxObject_declared
  AMI_DECLARE_TYPE(wxObject)
#endif
#ifndef wxValidator_declared
  #define wxValidator_declared
  AMI_DECLARE_TYPE(wxValidator)
#endif
#ifndef wxWindow_declared
  #define wxWindow_declared
  AMI_DECLARE_TYPE(wxWindow)
#endif
#ifndef wxWindowBase_declared
  #define wxWindowBase_declared
  AMI_DECLARE_TYPE(wxWindowBase)
#endif
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

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
BasicVariable::ptr AMILabType<wxValidator>::CreateVar( wxValidator* val, bool nodeleter)
{ 
  boost::shared_ptr<wxValidator> obj_ptr(val,smartpointer_nodeleter<wxValidator>());
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
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Clone( this_ptr);
  AddVar_Copy( this_ptr);
  AddVar_Validate( this_ptr);
  AddVar_TransferToWindow( this_ptr);
  AddVar_TransferFromWindow( this_ptr);
  AddVar_GetWindow( this_ptr);
  AddVar_SetWindow( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxEvtHandler
  boost::shared_ptr<wxEvtHandler > parent_wxEvtHandler(  boost::dynamic_pointer_cast<wxEvtHandler >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxEvtHandler = AMILabType<wxEvtHandler >::CreateVarFromSmtPtr(parent_wxEvtHandler);
  context->AddVar("wxEvtHandler",var_wxEvtHandler);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxEvtHandler = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxEvtHandler);
  context->AddDefault(obj_wxEvtHandler->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxValidator_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxValidator");
    WrapClass_wxValidator::AddVar_wxValidator(amiobject->GetContext());


  // Static methods 
  WrapClass_wxValidator::AddVar_IsSilent(amiobject->GetContext());
  WrapClass_wxValidator::AddVar_SetBellOnError(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

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
//  Wrapping of bool wxValidator::IsSilent()
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_static_IsSilent::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_static_IsSilent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   wxValidator::IsSilent();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxValidator::SetBellOnError(bool doIt = true)
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_static_SetBellOnError::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'doIt' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_static_SetBellOnError::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool doIt = true;
  if (!get_val_param<bool >(doIt,_p,_n,false,false)) ClassHelpAndReturn;

  wxValidator::SetBellOnError(doIt);
  return BasicVariable::ptr();
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
  BasicVariable::ptr res_var = AMILabType<wxObject >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxValidator::Copy(wxValidator const & val)
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_Copy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxValidator, "parameter named 'val'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_Copy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxValidator > val_smtptr;
  if (!get_val_smtptr_param<wxValidator >(val_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxValidator const & val = *val_smtptr;

  bool res =   this->_objectptr->GetObj()->Copy(val);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxValidator::Validate(wxWindow * param0)
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_Validate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'param0'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_Validate::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxWindow* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > param0_smtptr;
    if (!get_val_smtptr_param<wxWindow >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  bool res =   this->_objectptr->GetObj()->Validate(param0);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxValidator::TransferToWindow()
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_TransferToWindow::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_TransferToWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->TransferToWindow();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxValidator::TransferFromWindow()
//---------------------------------------------------
void WrapClass_wxValidator::
    wrap_TransferFromWindow::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxValidator::
    wrap_TransferFromWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->TransferFromWindow();
  return AMILabType<bool >::CreateVar(res);
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
  BasicVariable::ptr res_var = AMILabType<wxWindow >::CreateVar(res,true);
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

  wxWindowBase* win;
  if (CheckNullVar(_p,_n))  {
    win=(wxWindowBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindowBase > win_smtptr;
    if (!get_val_smtptr_param<wxWindowBase >(win_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    win = win_smtptr.get();
  }

  this->_objectptr->GetObj()->SetWindow(win);
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
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

