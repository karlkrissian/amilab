/**
 * C++ Interface: wrap_wxStdDialogButtonSizer
 *
 * Description: wrapping wxStdDialogButtonSizer
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

#include "wrap_wxStdDialogButtonSizer.h"

// get all the required includes
// #include "..."
#ifndef wxButton_declared
  #define wxButton_declared
  AMI_DECLARE_TYPE(wxButton)
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
BasicVariable::ptr WrapClass<wxStdDialogButtonSizer>::CreateVar( ParamList* p)
{
  WrapClass_wxStdDialogButtonSizer::wrap_wxStdDialogButtonSizer construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxStdDialogButtonSizer);
AMI_DEFINE_VARFROMSMTPTR(wxStdDialogButtonSizer);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxStdDialogButtonSizer>::CreateVar( wxStdDialogButtonSizer* val, bool nodeleter)
{ 
  boost::shared_ptr<wxStdDialogButtonSizer> obj_ptr(val,smartpointer_nodeleter<wxStdDialogButtonSizer>());
  return AMILabType<wxStdDialogButtonSizer>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxStdDialogButtonSizer
//
Variable<AMIObject>::ptr WrapClass_wxStdDialogButtonSizer::CreateVar( wxStdDialogButtonSizer* sp)
{
  boost::shared_ptr<wxStdDialogButtonSizer> di_ptr(
    sp,
    wxwindow_nodeleter<wxStdDialogButtonSizer>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxStdDialogButtonSizer>::CreateVar(
      new WrapClass_wxStdDialogButtonSizer(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxStdDialogButtonSizer::AddMethods(WrapClass<wxStdDialogButtonSizer>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_AddButton( this_ptr);
  AddVar_SetAffirmativeButton( this_ptr);
  AddVar_SetNegativeButton( this_ptr);
  AddVar_SetCancelButton( this_ptr);
  AddVar_Realize( this_ptr);
  AddVar_GetAffirmativeButton( this_ptr);
  AddVar_GetApplyButton( this_ptr);
  AddVar_GetNegativeButton( this_ptr);
  AddVar_GetCancelButton( this_ptr);
  AddVar_GetHelpButton( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxBoxSizer
  boost::shared_ptr<wxBoxSizer > parent_wxBoxSizer(  boost::dynamic_pointer_cast<wxBoxSizer >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxBoxSizer = AMILabType<wxBoxSizer >::CreateVarFromSmtPtr(parent_wxBoxSizer);
  context->AddVar("wxBoxSizer",var_wxBoxSizer);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxBoxSizer = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxBoxSizer);
  context->AddDefault(obj_wxBoxSizer->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxStdDialogButtonSizer_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxStdDialogButtonSizer");
    WrapClass_wxStdDialogButtonSizer::AddVar_wxStdDialogButtonSizer(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxStdDialogButtonSizer::wxStdDialogButtonSizer()
//---------------------------------------------------
void WrapClass_wxStdDialogButtonSizer::
    wrap_wxStdDialogButtonSizer::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStdDialogButtonSizer::
    wrap_wxStdDialogButtonSizer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxStdDialogButtonSizer* _newobj = new wxStdDialogButtonSizer();
  BasicVariable::ptr res = WrapClass_wxStdDialogButtonSizer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxStdDialogButtonSizer::AddButton(wxButton * button)
//---------------------------------------------------
void WrapClass_wxStdDialogButtonSizer::
    wrap_AddButton::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxButton, "parameter named 'button'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStdDialogButtonSizer::
    wrap_AddButton::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxButton* button;
  if (CheckNullVar(_p,_n))  {
    button=(wxButton*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxButton > button_smtptr;
    if (!get_val_smtptr_param<wxButton >(button_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    button = button_smtptr.get();
  }

  this->_objectptr->GetObj()->AddButton(button);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxStdDialogButtonSizer::SetAffirmativeButton(wxButton * button)
//---------------------------------------------------
void WrapClass_wxStdDialogButtonSizer::
    wrap_SetAffirmativeButton::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxButton, "parameter named 'button'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStdDialogButtonSizer::
    wrap_SetAffirmativeButton::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxButton* button;
  if (CheckNullVar(_p,_n))  {
    button=(wxButton*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxButton > button_smtptr;
    if (!get_val_smtptr_param<wxButton >(button_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    button = button_smtptr.get();
  }

  this->_objectptr->GetObj()->SetAffirmativeButton(button);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxStdDialogButtonSizer::SetNegativeButton(wxButton * button)
//---------------------------------------------------
void WrapClass_wxStdDialogButtonSizer::
    wrap_SetNegativeButton::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxButton, "parameter named 'button'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStdDialogButtonSizer::
    wrap_SetNegativeButton::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxButton* button;
  if (CheckNullVar(_p,_n))  {
    button=(wxButton*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxButton > button_smtptr;
    if (!get_val_smtptr_param<wxButton >(button_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    button = button_smtptr.get();
  }

  this->_objectptr->GetObj()->SetNegativeButton(button);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxStdDialogButtonSizer::SetCancelButton(wxButton * button)
//---------------------------------------------------
void WrapClass_wxStdDialogButtonSizer::
    wrap_SetCancelButton::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxButton, "parameter named 'button'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStdDialogButtonSizer::
    wrap_SetCancelButton::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxButton* button;
  if (CheckNullVar(_p,_n))  {
    button=(wxButton*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxButton > button_smtptr;
    if (!get_val_smtptr_param<wxButton >(button_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    button = button_smtptr.get();
  }

  this->_objectptr->GetObj()->SetCancelButton(button);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxStdDialogButtonSizer::Realize()
//---------------------------------------------------
void WrapClass_wxStdDialogButtonSizer::
    wrap_Realize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStdDialogButtonSizer::
    wrap_Realize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Realize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxButton * wxStdDialogButtonSizer::GetAffirmativeButton()
//---------------------------------------------------
void WrapClass_wxStdDialogButtonSizer::
    wrap_GetAffirmativeButton::SetParametersComments()
{
  return_comments="returning a variable of type wxButton";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStdDialogButtonSizer::
    wrap_GetAffirmativeButton::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxButton * res =   this->_objectptr->GetObj()->GetAffirmativeButton();
  BasicVariable::ptr res_var = AMILabType<wxButton >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxButton * wxStdDialogButtonSizer::GetApplyButton()
//---------------------------------------------------
void WrapClass_wxStdDialogButtonSizer::
    wrap_GetApplyButton::SetParametersComments()
{
  return_comments="returning a variable of type wxButton";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStdDialogButtonSizer::
    wrap_GetApplyButton::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxButton * res =   this->_objectptr->GetObj()->GetApplyButton();
  BasicVariable::ptr res_var = AMILabType<wxButton >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxButton * wxStdDialogButtonSizer::GetNegativeButton()
//---------------------------------------------------
void WrapClass_wxStdDialogButtonSizer::
    wrap_GetNegativeButton::SetParametersComments()
{
  return_comments="returning a variable of type wxButton";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStdDialogButtonSizer::
    wrap_GetNegativeButton::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxButton * res =   this->_objectptr->GetObj()->GetNegativeButton();
  BasicVariable::ptr res_var = AMILabType<wxButton >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxButton * wxStdDialogButtonSizer::GetCancelButton()
//---------------------------------------------------
void WrapClass_wxStdDialogButtonSizer::
    wrap_GetCancelButton::SetParametersComments()
{
  return_comments="returning a variable of type wxButton";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStdDialogButtonSizer::
    wrap_GetCancelButton::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxButton * res =   this->_objectptr->GetObj()->GetCancelButton();
  BasicVariable::ptr res_var = AMILabType<wxButton >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxButton * wxStdDialogButtonSizer::GetHelpButton()
//---------------------------------------------------
void WrapClass_wxStdDialogButtonSizer::
    wrap_GetHelpButton::SetParametersComments()
{
  return_comments="returning a variable of type wxButton";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStdDialogButtonSizer::
    wrap_GetHelpButton::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxButton * res =   this->_objectptr->GetObj()->GetHelpButton();
  BasicVariable::ptr res_var = AMILabType<wxButton >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxStdDialogButtonSizer::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxStdDialogButtonSizer::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStdDialogButtonSizer::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

