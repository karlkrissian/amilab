/**
 * C++ Interface: wrap_wxIdleEvent
 *
 * Description: wrapping wxIdleEvent
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

#include "wrap_wxIdleEvent.h"

// get all the required includes
// #include "..."
#ifndef wxIdleEvent_declared
  #define wxIdleEvent_declared
  AMI_DECLARE_TYPE(wxIdleEvent)
#endif
#ifndef wxWindow_declared
  #define wxWindow_declared
  AMI_DECLARE_TYPE(wxWindow)
#endif
#ifndef wxEvent_declared
  #define wxEvent_declared
  AMI_DECLARE_TYPE(wxEvent)
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
BasicVariable::ptr WrapClass<wxIdleEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxIdleEvent::wrap_wxIdleEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxIdleEvent);
AMI_DEFINE_VARFROMSMTPTR(wxIdleEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxIdleEvent
//
Variable<AMIObject>::ptr WrapClass_wxIdleEvent::CreateVar( wxIdleEvent* sp)
{
  boost::shared_ptr<wxIdleEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxIdleEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxIdleEvent>::CreateVar(
      new WrapClass_wxIdleEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxIdleEvent::AddMethods(WrapClass<wxIdleEvent>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_RequestMore( this_ptr);
  AddVar_MoreRequested( this_ptr);
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
void WrapClasswxIdleEvent_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxIdleEvent");
    WrapClass_wxIdleEvent::AddVar_wxIdleEvent_1(amiobject->GetContext());
  WrapClass_wxIdleEvent::AddVar_wxIdleEvent(amiobject->GetContext());
  WrapClass_wxIdleEvent::AddVar_wxIdleEvent_2(amiobject->GetContext());


  // Static methods 
  WrapClass_wxIdleEvent::AddVar_SetMode(amiobject->GetContext());
  WrapClass_wxIdleEvent::AddVar_GetMode(amiobject->GetContext());
  WrapClass_wxIdleEvent::AddVar_CanSend(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxIdleEvent::wxIdleEvent()
//---------------------------------------------------
void WrapClass_wxIdleEvent::
    wrap_wxIdleEvent_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIdleEvent::
    wrap_wxIdleEvent_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxIdleEvent* _newobj = new wxIdleEvent();
  BasicVariable::ptr res = WrapClass_wxIdleEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxIdleEvent::wxIdleEvent(...)
//---------------------------------------------------
void WrapClass_wxIdleEvent::
    wrap_wxIdleEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIdleEvent::
    wrap_wxIdleEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxIdleEvent::wrap_wxIdleEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxIdleEvent::wrap_wxIdleEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxIdleEvent::wxIdleEvent(wxIdleEvent const & event)
//---------------------------------------------------
void WrapClass_wxIdleEvent::
    wrap_wxIdleEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIdleEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIdleEvent::
    wrap_wxIdleEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxIdleEvent > event_smtptr;
  if (!get_val_smtptr_param<wxIdleEvent >(event_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxIdleEvent const & event = *event_smtptr;

  wxIdleEvent* _newobj = new wxIdleEvent(event);
  BasicVariable::ptr res = WrapClass_wxIdleEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxIdleEvent::SetMode(wxIdleMode mode)
//---------------------------------------------------
void WrapClass_wxIdleEvent::
    wrap_static_SetMode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'mode'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIdleEvent::
    wrap_static_SetMode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int mode_int;
  if (!get_val_param<int >(mode_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxIdleMode mode = (wxIdleMode) mode_int;

  wxIdleEvent::SetMode(mode);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxIdleMode wxIdleEvent::GetMode()
//---------------------------------------------------
void WrapClass_wxIdleEvent::
    wrap_static_GetMode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIdleEvent::
    wrap_static_GetMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxIdleMode res =   wxIdleEvent::GetMode();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxIdleEvent::CanSend(wxWindow * win)
//---------------------------------------------------
void WrapClass_wxIdleEvent::
    wrap_static_CanSend::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'win'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIdleEvent::
    wrap_static_CanSend::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxWindow* win;
  if (CheckNullVar(_p,_n))  {
    win=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > win_smtptr;
    if (!get_val_smtptr_param<wxWindow >(win_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    win = win_smtptr.get();
  }

  bool res =   wxIdleEvent::CanSend(win);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxIdleEvent.
//---------------------------------------------------
void WrapClass_wxIdleEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxIdleEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIdleEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxIdleEvent >::CreateVar( new wxIdleEvent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxIdleEvent::RequestMore(bool needMore = true)
//---------------------------------------------------
void WrapClass_wxIdleEvent::
    wrap_RequestMore::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'needMore' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIdleEvent::
    wrap_RequestMore::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool needMore = true;
  if (!get_val_param<bool >(needMore,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RequestMore(needMore);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxIdleEvent::MoreRequested()
//---------------------------------------------------
void WrapClass_wxIdleEvent::
    wrap_MoreRequested::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIdleEvent::
    wrap_MoreRequested::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->MoreRequested();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxIdleEvent::Clone()
//---------------------------------------------------
void WrapClass_wxIdleEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIdleEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = AMILabType<wxEvent >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxIdleEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxIdleEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIdleEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

