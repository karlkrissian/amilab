/**
 * C++ Interface: wrap_wxActivateEvent
 *
 * Description: wrapping wxActivateEvent
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
#include "wrap_wxActivateEvent.h"
#include "wrap_wxEvent.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxActivateEvent.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxActivateEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxActivateEvent::wrap_wxActivateEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxActivateEvent);
AMI_DEFINE_VARFROMSMTPTR(wxActivateEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxActivateEvent
//
Variable<AMIObject>::ptr WrapClass_wxActivateEvent::CreateVar( wxActivateEvent* sp)
{
  boost::shared_ptr<wxActivateEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxActivateEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxActivateEvent>::CreateVar(
      new WrapClass_wxActivateEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxActivateEvent::AddMethods(WrapClass<wxActivateEvent>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_GetActive( this_ptr);
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
void WrapClass_wxActivateEvent::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxActivateEvent");
    WrapClass_wxActivateEvent::AddVar_wxActivateEvent_1(amiobject->GetContext());
  WrapClass_wxActivateEvent::AddVar_wxActivateEvent(amiobject->GetContext());
  WrapClass_wxActivateEvent::AddVar_wxActivateEvent_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxActivateEvent::wxActivateEvent(wxEventType type = wxEVT_NULL, bool active = true, int Id = 0)
//---------------------------------------------------
void WrapClass_wxActivateEvent::
    wrap_wxActivateEvent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type' (def:wxEVT_NULL)")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'active' (def:true)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'Id' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxActivateEvent::
    wrap_wxActivateEvent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int type = wxEVT_NULL;
  if (!get_val_param<int >(type,_p,_n,false,true)) ClassReturnEmptyVar;

  bool active = true;
  if (!get_val_param<bool >(active,_p,_n,false,true)) ClassReturnEmptyVar;

  int Id = 0;
  if (!get_val_param<int >(Id,_p,_n,false,true)) ClassReturnEmptyVar;

  wxActivateEvent* _newobj = new wxActivateEvent(type, active, Id);
  BasicVariable::ptr res = WrapClass_wxActivateEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxActivateEvent::wxActivateEvent(...)
//---------------------------------------------------
void WrapClass_wxActivateEvent::
    wrap_wxActivateEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxActivateEvent::
    wrap_wxActivateEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxActivateEvent::wrap_wxActivateEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxActivateEvent::wrap_wxActivateEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxActivateEvent::wxActivateEvent(wxActivateEvent const & event)
//---------------------------------------------------
void WrapClass_wxActivateEvent::
    wrap_wxActivateEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxActivateEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxActivateEvent::
    wrap_wxActivateEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxActivateEvent > event_smtptr;
  if (!get_val_smtptr_param<wxActivateEvent >(event_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxActivateEvent const & event = *event_smtptr;

  wxActivateEvent* _newobj = new wxActivateEvent(event);
  BasicVariable::ptr res = WrapClass_wxActivateEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxActivateEvent.
//---------------------------------------------------
void WrapClass_wxActivateEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxActivateEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxActivateEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxActivateEvent >::CreateVar( new wxActivateEvent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxActivateEvent::GetActive()
//---------------------------------------------------
void WrapClass_wxActivateEvent::
    wrap_GetActive::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxActivateEvent::
    wrap_GetActive::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetActive();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxActivateEvent::Clone()
//---------------------------------------------------
void WrapClass_wxActivateEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxActivateEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = WrapClass_wxEvent::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxActivateEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxActivateEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxActivateEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

