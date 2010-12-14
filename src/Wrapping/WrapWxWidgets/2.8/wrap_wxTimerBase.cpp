/**
 * C++ Interface: wrap_wxTimerBase
 *
 * Description: wrapping wxTimerBase
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

#include "wrap_wxTimerBase.h"

// get all the required includes
// #include "..."
#ifndef wxEvtHandler_declared
  #define wxEvtHandler_declared
  AMI_DECLARE_TYPE(wxEvtHandler)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxTimerBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxTimerBase);
AMI_DEFINE_VARFROMSMTPTR(wxTimerBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxTimerBase>::CreateVar( wxTimerBase* val, bool nodeleter)
{ 
  boost::shared_ptr<wxTimerBase> obj_ptr(val,smartpointer_nodeleter<wxTimerBase>());
  return AMILabType<wxTimerBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxTimerBase
//
Variable<AMIObject>::ptr WrapClass_wxTimerBase::CreateVar( wxTimerBase* sp)
{
  boost::shared_ptr<wxTimerBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxTimerBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxTimerBase>::CreateVar(
      new WrapClass_wxTimerBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxTimerBase::AddMethods(WrapClass<wxTimerBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_SetOwner( this_ptr);
  AddVar_GetOwner( this_ptr);
  AddVar_Start( this_ptr);
  AddVar_Notify( this_ptr);
  AddVar_GetId( this_ptr);
  AddVar_GetInterval( this_ptr);
  AddVar_IsOneShot( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

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
void WrapClasswxTimerBase_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxTimerBase");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of void wxTimerBase::SetOwner(wxEvtHandler * owner, int timerid = wxID_ANY)
//---------------------------------------------------
void WrapClass_wxTimerBase::
    wrap_SetOwner::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEvtHandler, "parameter named 'owner'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'timerid' (def:wxID_ANY)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimerBase::
    wrap_SetOwner::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  wxEvtHandler* owner;
  if (CheckNullVar(_p,_n))  {
    owner=(wxEvtHandler*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxEvtHandler > owner_smtptr;
    if (!get_val_smtptr_param<wxEvtHandler >(owner_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    owner = owner_smtptr.get();
  }

  int timerid = wxID_ANY;
  if (!get_val_param<int >(timerid,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetOwner(owner, timerid);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxEvtHandler * wxTimerBase::GetOwner()
//---------------------------------------------------
void WrapClass_wxTimerBase::
    wrap_GetOwner::SetParametersComments()
{
  return_comments="returning a variable of type wxEvtHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimerBase::
    wrap_GetOwner::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvtHandler * res =   this->_objectptr->GetObj()->GetOwner();
  BasicVariable::ptr res_var = AMILabType<wxEvtHandler >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxTimerBase::Start(int milliseconds = -0x00000000000000001, bool oneShot = false)
//---------------------------------------------------
void WrapClass_wxTimerBase::
    wrap_Start::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'milliseconds' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'oneShot' (def:false)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimerBase::
    wrap_Start::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int milliseconds = -0x00000000000000001;
  if (!get_val_param<int >(milliseconds,_p,_n,false,false)) ClassHelpAndReturn;

  bool oneShot = false;
  if (!get_val_param<bool >(oneShot,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Start(milliseconds, oneShot);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxTimerBase::Notify()
//---------------------------------------------------
void WrapClass_wxTimerBase::
    wrap_Notify::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimerBase::
    wrap_Notify::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Notify();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxTimerBase::GetId()
//---------------------------------------------------
void WrapClass_wxTimerBase::
    wrap_GetId::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimerBase::
    wrap_GetId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetId();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxTimerBase::GetInterval()
//---------------------------------------------------
void WrapClass_wxTimerBase::
    wrap_GetInterval::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimerBase::
    wrap_GetInterval::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetInterval();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxTimerBase::IsOneShot()
//---------------------------------------------------
void WrapClass_wxTimerBase::
    wrap_IsOneShot::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimerBase::
    wrap_IsOneShot::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOneShot();
  return AMILabType<bool >::CreateVar(res);
}

