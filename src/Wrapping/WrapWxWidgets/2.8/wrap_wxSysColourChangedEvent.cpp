/**
 * C++ Interface: wrap_wxSysColourChangedEvent
 *
 * Description: wrapping wxSysColourChangedEvent
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
#include "wrap_wxSysColourChangedEvent.h"
#include "wrap_wxEvent.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxSysColourChangedEvent.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxSysColourChangedEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxSysColourChangedEvent::wrap_wxSysColourChangedEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxSysColourChangedEvent);
AMI_DEFINE_VARFROMSMTPTR(wxSysColourChangedEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxSysColourChangedEvent
//
Variable<AMIObject>::ptr WrapClass_wxSysColourChangedEvent::CreateVar( wxSysColourChangedEvent* sp)
{
  boost::shared_ptr<wxSysColourChangedEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxSysColourChangedEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxSysColourChangedEvent>::CreateVar(
      new WrapClass_wxSysColourChangedEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxSysColourChangedEvent::AddMethods(WrapClass<wxSysColourChangedEvent>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Clone( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  

  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxEvent
  boost::shared_ptr<wxEvent > parent_wxEvent(  boost::dynamic_pointer_cast<wxEvent >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxEvent = AMILabType<wxEvent >::CreateVarFromSmtPtr(parent_wxEvent);
  context->AddVar("wxEvent",var_wxEvent);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxEvent = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxEvent);
  context->AddDefault(obj_wxEvent->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxSysColourChangedEvent::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxSysColourChangedEvent");
    WrapClass_wxSysColourChangedEvent::AddVar_wxSysColourChangedEvent_1(amiobject->GetContext());
  WrapClass_wxSysColourChangedEvent::AddVar_wxSysColourChangedEvent(amiobject->GetContext());
  WrapClass_wxSysColourChangedEvent::AddVar_wxSysColourChangedEvent_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxSysColourChangedEvent::wxSysColourChangedEvent(wxSysColourChangedEvent const & param0)
//---------------------------------------------------
void WrapClass_wxSysColourChangedEvent::
    wrap_wxSysColourChangedEvent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSysColourChangedEvent, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSysColourChangedEvent::
    wrap_wxSysColourChangedEvent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSysColourChangedEvent > param0_smtptr;
  if (!get_val_smtptr_param<wxSysColourChangedEvent >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxSysColourChangedEvent const & param0 = *param0_smtptr;

  wxSysColourChangedEvent* _newobj = new wxSysColourChangedEvent(param0);
  BasicVariable::ptr res = WrapClass_wxSysColourChangedEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxSysColourChangedEvent::wxSysColourChangedEvent(...)
//---------------------------------------------------
void WrapClass_wxSysColourChangedEvent::
    wrap_wxSysColourChangedEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSysColourChangedEvent::
    wrap_wxSysColourChangedEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSysColourChangedEvent::wrap_wxSysColourChangedEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSysColourChangedEvent::wrap_wxSysColourChangedEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxSysColourChangedEvent::wxSysColourChangedEvent()
//---------------------------------------------------
void WrapClass_wxSysColourChangedEvent::
    wrap_wxSysColourChangedEvent_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSysColourChangedEvent::
    wrap_wxSysColourChangedEvent_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxSysColourChangedEvent* _newobj = new wxSysColourChangedEvent();
  BasicVariable::ptr res = WrapClass_wxSysColourChangedEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxSysColourChangedEvent.
//---------------------------------------------------
void WrapClass_wxSysColourChangedEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxSysColourChangedEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSysColourChangedEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxSysColourChangedEvent >::CreateVar( new wxSysColourChangedEvent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxSysColourChangedEvent::Clone()
//---------------------------------------------------
void WrapClass_wxSysColourChangedEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSysColourChangedEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = WrapClass_wxEvent::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxSysColourChangedEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxSysColourChangedEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSysColourChangedEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

