/**
 * C++ Interface: wrap_wxCloseEvent
 *
 * Description: wrapping wxCloseEvent
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
#include "wrap_wxCloseEvent.h"
#include "wrap_wxEvent.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxCloseEvent.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxCloseEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxCloseEvent::wrap_wxCloseEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxCloseEvent);
AMI_DEFINE_VARFROMSMTPTR(wxCloseEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxCloseEvent
//
Variable<AMIObject>::ptr WrapClass_wxCloseEvent::CreateVar( wxCloseEvent* sp)
{
  boost::shared_ptr<wxCloseEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxCloseEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxCloseEvent>::CreateVar(
      new WrapClass_wxCloseEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxCloseEvent::AddMethods(WrapClass<wxCloseEvent>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_SetLoggingOff( this_ptr);
      AddVar_GetLoggingOff( this_ptr);
      AddVar_Veto( this_ptr);
      AddVar_SetCanVeto( this_ptr);
      AddVar_CanVeto( this_ptr);
      AddVar_GetVeto( this_ptr);
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
void WrapClass_wxCloseEvent::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxCloseEvent");
    WrapClass_wxCloseEvent::AddVar_wxCloseEvent_1(amiobject->GetContext());
  WrapClass_wxCloseEvent::AddVar_wxCloseEvent(amiobject->GetContext());
  WrapClass_wxCloseEvent::AddVar_wxCloseEvent_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxCloseEvent::wxCloseEvent(wxEventType type = wxEVT_NULL, int winid = 0)
//---------------------------------------------------
void WrapClass_wxCloseEvent::
    wrap_wxCloseEvent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type' (def:wxEVT_NULL)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCloseEvent::
    wrap_wxCloseEvent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int type = wxEVT_NULL;
  if (!get_val_param<int >(type,_p,_n,false,true)) ClassReturnEmptyVar;

  int winid = 0;
  if (!get_val_param<int >(winid,_p,_n,false,true)) ClassReturnEmptyVar;

  wxCloseEvent* _newobj = new wxCloseEvent(type, winid);
  BasicVariable::ptr res = WrapClass_wxCloseEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxCloseEvent::wxCloseEvent(...)
//---------------------------------------------------
void WrapClass_wxCloseEvent::
    wrap_wxCloseEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCloseEvent::
    wrap_wxCloseEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxCloseEvent::wrap_wxCloseEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxCloseEvent::wrap_wxCloseEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxCloseEvent::wxCloseEvent(wxCloseEvent const & event)
//---------------------------------------------------
void WrapClass_wxCloseEvent::
    wrap_wxCloseEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCloseEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCloseEvent::
    wrap_wxCloseEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCloseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxCloseEvent >(event_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxCloseEvent const & event = *event_smtptr;

  wxCloseEvent* _newobj = new wxCloseEvent(event);
  BasicVariable::ptr res = WrapClass_wxCloseEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxCloseEvent.
//---------------------------------------------------
void WrapClass_wxCloseEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxCloseEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCloseEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxCloseEvent >::CreateVar( new wxCloseEvent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxCloseEvent::SetLoggingOff(bool logOff)
//---------------------------------------------------
void WrapClass_wxCloseEvent::
    wrap_SetLoggingOff::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'logOff'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCloseEvent::
    wrap_SetLoggingOff::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool logOff;
  if (!get_val_param<bool >(logOff,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetLoggingOff(logOff);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxCloseEvent::GetLoggingOff()
//---------------------------------------------------
void WrapClass_wxCloseEvent::
    wrap_GetLoggingOff::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCloseEvent::
    wrap_GetLoggingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetLoggingOff();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxCloseEvent::Veto(bool veto = true)
//---------------------------------------------------
void WrapClass_wxCloseEvent::
    wrap_Veto::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'veto' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCloseEvent::
    wrap_Veto::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool veto = true;
  if (!get_val_param<bool >(veto,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Veto(veto);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxCloseEvent::SetCanVeto(bool canVeto)
//---------------------------------------------------
void WrapClass_wxCloseEvent::
    wrap_SetCanVeto::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'canVeto'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCloseEvent::
    wrap_SetCanVeto::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool canVeto;
  if (!get_val_param<bool >(canVeto,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCanVeto(canVeto);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxCloseEvent::CanVeto()
//---------------------------------------------------
void WrapClass_wxCloseEvent::
    wrap_CanVeto::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCloseEvent::
    wrap_CanVeto::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->CanVeto();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxCloseEvent::GetVeto()
//---------------------------------------------------
void WrapClass_wxCloseEvent::
    wrap_GetVeto::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCloseEvent::
    wrap_GetVeto::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetVeto();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxCloseEvent::Clone()
//---------------------------------------------------
void WrapClass_wxCloseEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCloseEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = WrapClass_wxEvent::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxCloseEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxCloseEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCloseEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

