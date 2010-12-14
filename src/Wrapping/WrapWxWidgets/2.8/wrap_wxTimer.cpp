/**
 * C++ Interface: wrap_wxTimer
 *
 * Description: wrapping wxTimer
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

#include "wrap_wxTimer.h"

// get all the required includes
// #include "..."
#ifndef wxEvtHandler_declared
  #define wxEvtHandler_declared
  AMI_DECLARE_TYPE(wxEvtHandler)
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
BasicVariable::ptr WrapClass<wxTimer>::CreateVar( ParamList* p)
{
  WrapClass_wxTimer::wrap_wxTimer construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxTimer);
AMI_DEFINE_VARFROMSMTPTR(wxTimer);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxTimer>::CreateVar( wxTimer* val, bool nodeleter)
{ 
  boost::shared_ptr<wxTimer> obj_ptr(val,smartpointer_nodeleter<wxTimer>());
  return AMILabType<wxTimer>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxTimer
//
Variable<AMIObject>::ptr WrapClass_wxTimer::CreateVar( wxTimer* sp)
{
  boost::shared_ptr<wxTimer> di_ptr(
    sp,
    wxwindow_nodeleter<wxTimer>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxTimer>::CreateVar(
      new WrapClass_wxTimer(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxTimer::AddMethods(WrapClass<wxTimer>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Start( this_ptr);
  AddVar_Stop( this_ptr);
  AddVar_IsRunning( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxTimerBase
  boost::shared_ptr<wxTimerBase > parent_wxTimerBase(  boost::dynamic_pointer_cast<wxTimerBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxTimerBase = AMILabType<wxTimerBase >::CreateVarFromSmtPtr(parent_wxTimerBase);
  context->AddVar("wxTimerBase",var_wxTimerBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxTimerBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxTimerBase);
  context->AddDefault(obj_wxTimerBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxTimer_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxTimer");
    WrapClass_wxTimer::AddVar_wxTimer_1(amiobject->GetContext());
  WrapClass_wxTimer::AddVar_wxTimer(amiobject->GetContext());
  WrapClass_wxTimer::AddVar_wxTimer_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxTimer::wxTimer()
//---------------------------------------------------
void WrapClass_wxTimer::
    wrap_wxTimer_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimer::
    wrap_wxTimer_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxTimer* _newobj = new wxTimer();
  BasicVariable::ptr res = WrapClass_wxTimer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxTimer::wxTimer(...)
//---------------------------------------------------
void WrapClass_wxTimer::
    wrap_wxTimer::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimer::
    wrap_wxTimer::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxTimer::wrap_wxTimer_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxTimer::wrap_wxTimer_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxTimer::wxTimer(wxEvtHandler * owner, int id = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxTimer::
    wrap_wxTimer_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEvtHandler, "parameter named 'owner'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id' (def:-0x00000000000000001)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimer::
    wrap_wxTimer_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxEvtHandler* owner;
  if (CheckNullVar(_p,_n))  {
    owner=(wxEvtHandler*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxEvtHandler > owner_smtptr;
    if (!get_val_smtptr_param<wxEvtHandler >(owner_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    owner = owner_smtptr.get();
  }

  int id = -0x00000000000000001;
  if (!get_val_param<int >(id,_p,_n,false,true)) ClassReturnEmptyVar;

  wxTimer* _newobj = new wxTimer(owner, id);
  BasicVariable::ptr res = WrapClass_wxTimer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of bool wxTimer::Start(int millisecs = -0x00000000000000001, bool oneShot = 0)
//---------------------------------------------------
void WrapClass_wxTimer::
    wrap_Start::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'millisecs' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'oneShot' (def:0)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimer::
    wrap_Start::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int millisecs = -0x00000000000000001;
  if (!get_val_param<int >(millisecs,_p,_n,false,false)) ClassHelpAndReturn;

  bool oneShot = 0;
  if (!get_val_param<bool >(oneShot,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Start(millisecs, oneShot);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxTimer::Stop()
//---------------------------------------------------
void WrapClass_wxTimer::
    wrap_Stop::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimer::
    wrap_Stop::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Stop();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxTimer::IsRunning()
//---------------------------------------------------
void WrapClass_wxTimer::
    wrap_IsRunning::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimer::
    wrap_IsRunning::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsRunning();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxTimer::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxTimer::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimer::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

