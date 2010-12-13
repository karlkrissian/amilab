/**
 * C++ Interface: wrap_wxEvtHandler
 *
 * Description: wrapping wxEvtHandler
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

#include "wrap_wxEvtHandler.h"

// get all the required includes
// #include "..."
#ifndef wxEventTableEntryBase_declared
  #define wxEventTableEntryBase_declared
  AMI_DECLARE_TYPE(wxEventTableEntryBase)
#endif
#ifndef wxEvtHandler_declared
  #define wxEvtHandler_declared
  AMI_DECLARE_TYPE(wxEvtHandler)
#endif
#ifndef wxEvent_declared
  #define wxEvent_declared
  AMI_DECLARE_TYPE(wxEvent)
#endif
#ifndef wxObjectEventFunction_declared
  #define wxObjectEventFunction_declared
  AMI_DECLARE_TYPE(wxObjectEventFunction)
#endif
#ifndef wxObject_declared
  #define wxObject_declared
  AMI_DECLARE_TYPE(wxObject)
#endif
#ifndef wxList_declared
  #define wxList_declared
  AMI_DECLARE_TYPE(wxList)
#endif
#ifndef wxClientData_declared
  #define wxClientData_declared
  AMI_DECLARE_TYPE(wxClientData)
#endif
#ifndef wxEventTable_declared
  #define wxEventTable_declared
  AMI_DECLARE_TYPE(wxEventTable)
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
BasicVariable::ptr WrapClass<wxEvtHandler>::CreateVar( ParamList* p)
{
  WrapClass_wxEvtHandler::wrap_wxEvtHandler construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxEvtHandler);
AMI_DEFINE_VARFROMSMTPTR(wxEvtHandler);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxEvtHandler>::CreateVar( wxEvtHandler* val, bool nodeleter)
{ 
  boost::shared_ptr<wxEvtHandler> obj_ptr(val,smartpointer_nodeleter<wxEvtHandler>());
  return AMILabType<wxEvtHandler>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxEvtHandler
//
Variable<AMIObject>::ptr WrapClass_wxEvtHandler::CreateVar( wxEvtHandler* sp)
{
  boost::shared_ptr<wxEvtHandler> di_ptr(
    sp,
    wxwindow_nodeleter<wxEvtHandler>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxEvtHandler>::CreateVar(
      new WrapClass_wxEvtHandler(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxEvtHandler::AddMethods(WrapClass<wxEvtHandler>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_GetNextHandler( this_ptr);
  AddVar_GetPreviousHandler( this_ptr);
  AddVar_SetNextHandler( this_ptr);
  AddVar_SetPreviousHandler( this_ptr);
  AddVar_SetEvtHandlerEnabled( this_ptr);
  AddVar_GetEvtHandlerEnabled( this_ptr);
  AddVar_ProcessEvent( this_ptr);
  AddVar_AddPendingEvent( this_ptr);
  AddVar_ProcessPendingEvents( this_ptr);
  AddVar_ProcessThreadEvent( this_ptr);
  AddVar_Connect_1( this_ptr);
  AddVar_Connect( this_ptr);
  AddVar_Connect_2( this_ptr);
  AddVar_Connect_3( this_ptr);
  AddVar_Disconnect_1( this_ptr);
  AddVar_Disconnect( this_ptr);
  AddVar_Disconnect_2( this_ptr);
  AddVar_Disconnect_3( this_ptr);
  AddVar_GetDynamicEventTable( this_ptr);
  AddVar_SetClientObject( this_ptr);
  AddVar_GetClientObject( this_ptr);
/* The following types are missing: void
  AddVar_SetClientData( this_ptr);
*/
  AddVar_GetClientData( this_ptr);
  AddVar_SearchEventTable( this_ptr);
  AddVar_SearchDynamicEventTable( this_ptr);
  AddVar_ClearEventLocker( this_ptr);
  AddVar_ClearEventHashTable( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxObject
  boost::shared_ptr<wxObject > parent_wxObject(  boost::dynamic_pointer_cast<wxObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxObject = AMILabType<wxObject >::CreateVarFromSmtPtr(parent_wxObject);
  context->AddVar("wxObject",var_wxObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxObject);
  context->AddDefault(obj_wxObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxEvtHandler_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxEvtHandler");
    WrapClass_wxEvtHandler::AddVar_wxEvtHandler(amiobject->GetContext());


  // Static methods 
  WrapClass_wxEvtHandler::AddVar_ProcessEventIfMatches(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxEvtHandler::wxEvtHandler()
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_wxEvtHandler::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_wxEvtHandler::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvtHandler* _newobj = new wxEvtHandler();
  BasicVariable::ptr res = WrapClass_wxEvtHandler::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of bool wxEvtHandler::ProcessEventIfMatches(wxEventTableEntryBase const & tableEntry, wxEvtHandler * handler, wxEvent & event)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_static_ProcessEventIfMatches::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEventTableEntryBase, "parameter named 'tableEntry'")
  ADDPARAMCOMMENT_TYPE( wxEvtHandler, "parameter named 'handler'")
  ADDPARAMCOMMENT_TYPE( wxEvent, "parameter named 'event'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_static_ProcessEventIfMatches::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxEventTableEntryBase > tableEntry_smtptr;
  if (!get_val_smtptr_param<wxEventTableEntryBase >(tableEntry_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxEventTableEntryBase const & tableEntry = *tableEntry_smtptr;

  wxEvtHandler* handler;
  if (CheckNullVar(_p,_n))  {
    handler=(wxEvtHandler*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxEvtHandler > handler_smtptr;
    if (!get_val_smtptr_param<wxEvtHandler >(handler_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    handler = handler_smtptr.get();
  }

  boost::shared_ptr<wxEvent > event_smtptr;
  if (!get_val_smtptr_param<wxEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxEvent & event = *event_smtptr;

  bool res =   wxEvtHandler::ProcessEventIfMatches(tableEntry, handler, event);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxEvtHandler * wxEvtHandler::GetNextHandler()
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_GetNextHandler::SetParametersComments()
{
  return_comments="returning a variable of type wxEvtHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_GetNextHandler::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvtHandler * res =   this->_objectptr->GetObj()->GetNextHandler();
  BasicVariable::ptr res_var = AMILabType<wxEvtHandler >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxEvtHandler * wxEvtHandler::GetPreviousHandler()
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_GetPreviousHandler::SetParametersComments()
{
  return_comments="returning a variable of type wxEvtHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_GetPreviousHandler::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvtHandler * res =   this->_objectptr->GetObj()->GetPreviousHandler();
  BasicVariable::ptr res_var = AMILabType<wxEvtHandler >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxEvtHandler::SetNextHandler(wxEvtHandler * handler)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_SetNextHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEvtHandler, "parameter named 'handler'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_SetNextHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxEvtHandler* handler;
  if (CheckNullVar(_p,_n))  {
    handler=(wxEvtHandler*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxEvtHandler > handler_smtptr;
    if (!get_val_smtptr_param<wxEvtHandler >(handler_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    handler = handler_smtptr.get();
  }

  this->_objectptr->GetObj()->SetNextHandler(handler);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxEvtHandler::SetPreviousHandler(wxEvtHandler * handler)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_SetPreviousHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEvtHandler, "parameter named 'handler'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_SetPreviousHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxEvtHandler* handler;
  if (CheckNullVar(_p,_n))  {
    handler=(wxEvtHandler*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxEvtHandler > handler_smtptr;
    if (!get_val_smtptr_param<wxEvtHandler >(handler_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    handler = handler_smtptr.get();
  }

  this->_objectptr->GetObj()->SetPreviousHandler(handler);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxEvtHandler::SetEvtHandlerEnabled(bool enabled)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_SetEvtHandlerEnabled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'enabled'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_SetEvtHandlerEnabled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool enabled;
  if (!get_val_param<bool >(enabled,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetEvtHandlerEnabled(enabled);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxEvtHandler::GetEvtHandlerEnabled()
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_GetEvtHandlerEnabled::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_GetEvtHandlerEnabled::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetEvtHandlerEnabled();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxEvtHandler::ProcessEvent(wxEvent & event)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_ProcessEvent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEvent, "parameter named 'event'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_ProcessEvent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxEvent > event_smtptr;
  if (!get_val_smtptr_param<wxEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxEvent & event = *event_smtptr;

  bool res =   this->_objectptr->GetObj()->ProcessEvent(event);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxEvtHandler::AddPendingEvent(wxEvent & event)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_AddPendingEvent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_AddPendingEvent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxEvent > event_smtptr;
  if (!get_val_smtptr_param<wxEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->AddPendingEvent(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxEvtHandler::ProcessPendingEvents()
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_ProcessPendingEvents::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_ProcessPendingEvents::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ProcessPendingEvents();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxEvtHandler::ProcessThreadEvent(wxEvent & event)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_ProcessThreadEvent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEvent, "parameter named 'event'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_ProcessThreadEvent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxEvent > event_smtptr;
  if (!get_val_smtptr_param<wxEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxEvent & event = *event_smtptr;

  bool res =   this->_objectptr->GetObj()->ProcessThreadEvent(event);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxEvtHandler::Connect(int winid, int lastId, int eventType, wxObjectEventFunction func, wxObject * userData = 0u, wxEvtHandler * eventSink = 0u)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_Connect_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'lastId'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'eventType'")
  ADDPARAMCOMMENT_TYPE( wxObjectEventFunction, "parameter named 'func'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxEvtHandler, "parameter named 'eventSink' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_Connect_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  int winid;
  if (!get_val_param<int >(winid,_p,_n,true,true)) ClassReturnEmptyVar;

  int lastId;
  if (!get_val_param<int >(lastId,_p,_n,true,true)) ClassReturnEmptyVar;

  int eventType;
  if (!get_val_param<int >(eventType,_p,_n,true,true)) ClassReturnEmptyVar;

  wxObjectEventFunction func;
  if (!get_val_param<wxObjectEventFunction >(func,_p,_n,true,true)) ClassReturnEmptyVar;

  wxObject* userData = 0u;
  if (CheckNullVar(_p,_n))  {
    userData=(wxObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObject > userData_smtptr;
    if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
    userData = userData_smtptr.get();
  }

  wxEvtHandler* eventSink = 0u;
  if (CheckNullVar(_p,_n))  {
    eventSink=(wxEvtHandler*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxEvtHandler > eventSink_smtptr;
    if (!get_val_smtptr_param<wxEvtHandler >(eventSink_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
    eventSink = eventSink_smtptr.get();
  }

  this->_objectptr->GetObj()->Connect(winid, lastId, eventType, func, userData, eventSink);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxEvtHandler::Connect(...)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_Connect::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_Connect::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxEvtHandler::wrap_Connect_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxEvtHandler::wrap_Connect_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxEvtHandler::wrap_Connect_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxEvtHandler::Connect(int winid, int eventType, wxObjectEventFunction func, wxObject * userData = 0u, wxEvtHandler * eventSink = 0u)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_Connect_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'eventType'")
  ADDPARAMCOMMENT_TYPE( wxObjectEventFunction, "parameter named 'func'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxEvtHandler, "parameter named 'eventSink' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_Connect_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  int winid;
  if (!get_val_param<int >(winid,_p,_n,true,true)) ClassReturnEmptyVar;

  int eventType;
  if (!get_val_param<int >(eventType,_p,_n,true,true)) ClassReturnEmptyVar;

  wxObjectEventFunction func;
  if (!get_val_param<wxObjectEventFunction >(func,_p,_n,true,true)) ClassReturnEmptyVar;

  wxObject* userData = 0u;
  if (CheckNullVar(_p,_n))  {
    userData=(wxObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObject > userData_smtptr;
    if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
    userData = userData_smtptr.get();
  }

  wxEvtHandler* eventSink = 0u;
  if (CheckNullVar(_p,_n))  {
    eventSink=(wxEvtHandler*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxEvtHandler > eventSink_smtptr;
    if (!get_val_smtptr_param<wxEvtHandler >(eventSink_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
    eventSink = eventSink_smtptr.get();
  }

  this->_objectptr->GetObj()->Connect(winid, eventType, func, userData, eventSink);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxEvtHandler::Connect(int eventType, wxObjectEventFunction func, wxObject * userData = 0u, wxEvtHandler * eventSink = 0u)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_Connect_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'eventType'")
  ADDPARAMCOMMENT_TYPE( wxObjectEventFunction, "parameter named 'func'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxEvtHandler, "parameter named 'eventSink' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_Connect_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int eventType;
  if (!get_val_param<int >(eventType,_p,_n,true,true)) ClassReturnEmptyVar;

  wxObjectEventFunction func;
  if (!get_val_param<wxObjectEventFunction >(func,_p,_n,true,true)) ClassReturnEmptyVar;

  wxObject* userData = 0u;
  if (CheckNullVar(_p,_n))  {
    userData=(wxObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObject > userData_smtptr;
    if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
    userData = userData_smtptr.get();
  }

  wxEvtHandler* eventSink = 0u;
  if (CheckNullVar(_p,_n))  {
    eventSink=(wxEvtHandler*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxEvtHandler > eventSink_smtptr;
    if (!get_val_smtptr_param<wxEvtHandler >(eventSink_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
    eventSink = eventSink_smtptr.get();
  }

  this->_objectptr->GetObj()->Connect(eventType, func, userData, eventSink);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxEvtHandler::Disconnect(int winid, int lastId, wxEventType eventType, wxObjectEventFunction func = 0l, wxObject * userData = 0u, wxEvtHandler * eventSink = 0u)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_Disconnect_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'lastId'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'eventType'")
  ADDPARAMCOMMENT_TYPE( wxObjectEventFunction, "parameter named 'func' (def:0l)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxEvtHandler, "parameter named 'eventSink' (def:0u)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_Disconnect_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  int winid;
  if (!get_val_param<int >(winid,_p,_n,true,true)) ClassReturnEmptyVar;

  int lastId;
  if (!get_val_param<int >(lastId,_p,_n,true,true)) ClassReturnEmptyVar;

  int eventType;
  if (!get_val_param<int >(eventType,_p,_n,true,true)) ClassReturnEmptyVar;

  wxObjectEventFunction func = 0l;
  if (!get_val_param<wxObjectEventFunction >(func,_p,_n,false,true)) ClassReturnEmptyVar;

  wxObject* userData = 0u;
  if (CheckNullVar(_p,_n))  {
    userData=(wxObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObject > userData_smtptr;
    if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
    userData = userData_smtptr.get();
  }

  wxEvtHandler* eventSink = 0u;
  if (CheckNullVar(_p,_n))  {
    eventSink=(wxEvtHandler*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxEvtHandler > eventSink_smtptr;
    if (!get_val_smtptr_param<wxEvtHandler >(eventSink_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
    eventSink = eventSink_smtptr.get();
  }

  bool res =   this->_objectptr->GetObj()->Disconnect(winid, lastId, eventType, func, userData, eventSink);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxEvtHandler::Disconnect(...)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_Disconnect::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_Disconnect::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxEvtHandler::wrap_Disconnect_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxEvtHandler::wrap_Disconnect_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxEvtHandler::wrap_Disconnect_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxEvtHandler::Disconnect(int winid = wxID_ANY, wxEventType eventType = wxEVT_NULL, wxObjectEventFunction func = 0l, wxObject * userData = 0u, wxEvtHandler * eventSink = 0u)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_Disconnect_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid' (def:wxID_ANY)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'eventType' (def:wxEVT_NULL)")
  ADDPARAMCOMMENT_TYPE( wxObjectEventFunction, "parameter named 'func' (def:0l)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxEvtHandler, "parameter named 'eventSink' (def:0u)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_Disconnect_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  int winid = wxID_ANY;
  if (!get_val_param<int >(winid,_p,_n,false,true)) ClassReturnEmptyVar;

  int eventType = wxEVT_NULL;
  if (!get_val_param<int >(eventType,_p,_n,false,true)) ClassReturnEmptyVar;

  wxObjectEventFunction func = 0l;
  if (!get_val_param<wxObjectEventFunction >(func,_p,_n,false,true)) ClassReturnEmptyVar;

  wxObject* userData = 0u;
  if (CheckNullVar(_p,_n))  {
    userData=(wxObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObject > userData_smtptr;
    if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
    userData = userData_smtptr.get();
  }

  wxEvtHandler* eventSink = 0u;
  if (CheckNullVar(_p,_n))  {
    eventSink=(wxEvtHandler*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxEvtHandler > eventSink_smtptr;
    if (!get_val_smtptr_param<wxEvtHandler >(eventSink_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
    eventSink = eventSink_smtptr.get();
  }

  bool res =   this->_objectptr->GetObj()->Disconnect(winid, eventType, func, userData, eventSink);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxEvtHandler::Disconnect(wxEventType eventType, wxObjectEventFunction func, wxObject * userData = 0u, wxEvtHandler * eventSink = 0u)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_Disconnect_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'eventType'")
  ADDPARAMCOMMENT_TYPE( wxObjectEventFunction, "parameter named 'func'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxEvtHandler, "parameter named 'eventSink' (def:0u)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_Disconnect_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int eventType;
  if (!get_val_param<int >(eventType,_p,_n,true,true)) ClassReturnEmptyVar;

  wxObjectEventFunction func;
  if (!get_val_param<wxObjectEventFunction >(func,_p,_n,true,true)) ClassReturnEmptyVar;

  wxObject* userData = 0u;
  if (CheckNullVar(_p,_n))  {
    userData=(wxObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObject > userData_smtptr;
    if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
    userData = userData_smtptr.get();
  }

  wxEvtHandler* eventSink = 0u;
  if (CheckNullVar(_p,_n))  {
    eventSink=(wxEvtHandler*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxEvtHandler > eventSink_smtptr;
    if (!get_val_smtptr_param<wxEvtHandler >(eventSink_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
    eventSink = eventSink_smtptr.get();
  }

  bool res =   this->_objectptr->GetObj()->Disconnect(eventType, func, userData, eventSink);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxList * wxEvtHandler::GetDynamicEventTable()
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_GetDynamicEventTable::SetParametersComments()
{
  return_comments="returning a variable of type wxList";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_GetDynamicEventTable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxList * res =   this->_objectptr->GetObj()->GetDynamicEventTable();
  BasicVariable::ptr res_var = AMILabType<wxList >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxEvtHandler::SetClientObject(wxClientData * data)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_SetClientObject::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxClientData, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_SetClientObject::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxClientData* data;
  if (CheckNullVar(_p,_n))  {
    data=(wxClientData*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxClientData > data_smtptr;
    if (!get_val_smtptr_param<wxClientData >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    data = data_smtptr.get();
  }

  this->_objectptr->GetObj()->SetClientObject(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClientData * wxEvtHandler::GetClientObject()
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_GetClientObject::SetParametersComments()
{
  return_comments="returning a variable of type wxClientData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_GetClientObject::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClientData * res =   this->_objectptr->GetObj()->GetClientObject();
  BasicVariable::ptr res_var = AMILabType<wxClientData >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of void wxEvtHandler::SetClientData(void * data)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_SetClientData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_SetClientData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  void* data;
  if (CheckNullVar(_p,_n))  {
    data=(void*)NULL;
    _n++;
  } else {
    boost::shared_ptr<void > data_smtptr;
    if (!get_val_smtptr_param<void >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    data = data_smtptr.get();
  }

  this->_objectptr->GetObj()->SetClientData(data);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void * wxEvtHandler::GetClientData()
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_GetClientData::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_GetClientData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GetClientData();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxEvtHandler::SearchEventTable(wxEventTable & table, wxEvent & event)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_SearchEventTable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEventTable, "parameter named 'table'")
  ADDPARAMCOMMENT_TYPE( wxEvent, "parameter named 'event'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_SearchEventTable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxEventTable > table_smtptr;
  if (!get_val_smtptr_param<wxEventTable >(table_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxEventTable & table = *table_smtptr;

  boost::shared_ptr<wxEvent > event_smtptr;
  if (!get_val_smtptr_param<wxEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxEvent & event = *event_smtptr;

  bool res =   this->_objectptr->GetObj()->SearchEventTable(table, event);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxEvtHandler::SearchDynamicEventTable(wxEvent & event)
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_SearchDynamicEventTable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEvent, "parameter named 'event'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_SearchDynamicEventTable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxEvent > event_smtptr;
  if (!get_val_smtptr_param<wxEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxEvent & event = *event_smtptr;

  bool res =   this->_objectptr->GetObj()->SearchDynamicEventTable(event);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxEvtHandler::ClearEventLocker()
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_ClearEventLocker::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_ClearEventLocker::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ClearEventLocker();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxEvtHandler::ClearEventHashTable()
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_ClearEventHashTable::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_ClearEventHashTable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ClearEventHashTable();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxEvtHandler::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxEvtHandler::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvtHandler::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

