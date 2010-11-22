/**
 * C++ Interface: wrap_wxEvent
 *
 * Description: wrapping wxEvent
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
#include "wrap_wxClassInfo.h"


#include "wrap_wxEvent.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxEvent>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxEvent);
AMI_DEFINE_VARFROMSMTPTR(wxEvent);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxEvent>::CreateVar( wxEvent* val, bool nodeleter)
{ 
  boost::shared_ptr<wxEvent> obj_ptr(val,smartpointer_nodeleter<wxEvent>());
  return AMILabType<wxEvent>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxEvent
//
Variable<AMIObject>::ptr WrapClass_wxEvent::CreateVar( wxEvent* sp)
{
  boost::shared_ptr<wxEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxEvent>::CreateVar(
      new WrapClass_wxEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxEvent::AddMethods(WrapClass<wxEvent>::ptr this_ptr )
{
  
      // Add members from wxObject
      WrapClass_wxObject::ptr parent_wxObject(        boost::dynamic_pointer_cast<WrapClass_wxObject >(this_ptr));
      parent_wxObject->AddMethods(parent_wxObject);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_SetEventType( this_ptr);
      AddVar_GetEventType( this_ptr);
      AddVar_GetEventObject( this_ptr);
      AddVar_SetEventObject( this_ptr);
      AddVar_GetTimestamp( this_ptr);
      AddVar_SetTimestamp( this_ptr);
      AddVar_GetId( this_ptr);
      AddVar_SetId( this_ptr);
      AddVar_Skip( this_ptr);
      AddVar_GetSkipped( this_ptr);
      AddVar_IsCommandEvent( this_ptr);
      AddVar_ShouldPropagate( this_ptr);
      AddVar_StopPropagation( this_ptr);
      AddVar_ResumePropagation( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      // Adding public member m_eventObject
      boost::shared_ptr<wxObject > var_m_eventObject_ptr(GetObj()->m_eventObject, smartpointer_nodeleter<wxObject >());
      BasicVariable::ptr var_m_eventObject = AMILabType<wxObject >::CreateVarFromSmtPtr(var_m_eventObject_ptr);
      if (var_m_eventObject.get()) {
        var_m_eventObject->Rename("m_eventObject");
        context->AddVar(var_m_eventObject,context);
      }
      
      // Adding public member m_eventType
      boost::shared_ptr<int > var_m_eventType_ptr(&GetObj()->m_eventType, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_m_eventType = AMILabType<int >::CreateVarFromSmtPtr(var_m_eventType_ptr);
      if (var_m_eventType.get()) {
        var_m_eventType->Rename("m_eventType");
        context->AddVar(var_m_eventType,context);
      }
      
      // Adding public member m_timeStamp
      boost::shared_ptr<long int > var_m_timeStamp_ptr(&GetObj()->m_timeStamp, smartpointer_nodeleter<long int >());
      BasicVariable::ptr var_m_timeStamp = AMILabType<long int >::CreateVarFromSmtPtr(var_m_timeStamp_ptr);
      if (var_m_timeStamp.get()) {
        var_m_timeStamp->Rename("m_timeStamp");
        context->AddVar(var_m_timeStamp,context);
      }
      
      // Adding public member m_id
      boost::shared_ptr<int > var_m_id_ptr(&GetObj()->m_id, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_m_id = AMILabType<int >::CreateVarFromSmtPtr(var_m_id_ptr);
      if (var_m_id.get()) {
        var_m_id->Rename("m_id");
        context->AddVar(var_m_id,context);
      }
      
      // Adding public member m_callbackUserData
      boost::shared_ptr<wxObject > var_m_callbackUserData_ptr(GetObj()->m_callbackUserData, smartpointer_nodeleter<wxObject >());
      BasicVariable::ptr var_m_callbackUserData = AMILabType<wxObject >::CreateVarFromSmtPtr(var_m_callbackUserData_ptr);
      if (var_m_callbackUserData.get()) {
        var_m_callbackUserData->Rename("m_callbackUserData");
        context->AddVar(var_m_callbackUserData,context);
      }
      
      /* type not available
      // Adding public member m_skipped
      boost::shared_ptr<bool > var_m_skipped_ptr(&GetObj()->m_skipped, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_skipped = AMILabType<bool >::CreateVarFromSmtPtr(var_m_skipped_ptr);
      if (var_m_skipped.get()) {
        var_m_skipped->Rename("m_skipped");
        context->AddVar(var_m_skipped,context);
      }
      */
      
      /* type not available
      // Adding public member m_isCommandEvent
      boost::shared_ptr<bool > var_m_isCommandEvent_ptr(&GetObj()->m_isCommandEvent, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_isCommandEvent = AMILabType<bool >::CreateVarFromSmtPtr(var_m_isCommandEvent_ptr);
      if (var_m_isCommandEvent.get()) {
        var_m_isCommandEvent->Rename("m_isCommandEvent");
        context->AddVar(var_m_isCommandEvent,context);
      }
      */

};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of void wxEvent::SetEventType(wxEventType typ)
//---------------------------------------------------
void WrapClass_wxEvent::
    wrap_SetEventType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'typ'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvent::
    wrap_SetEventType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int typ;
  if (!get_val_param<int >(typ,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetEventType(typ);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxEventType wxEvent::GetEventType()
//---------------------------------------------------
void WrapClass_wxEvent::
    wrap_GetEventType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvent::
    wrap_GetEventType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEventType res =   this->_objectptr->GetObj()->GetEventType();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxObject * wxEvent::GetEventObject()
//---------------------------------------------------
void WrapClass_wxEvent::
    wrap_GetEventObject::SetParametersComments()
{
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvent::
    wrap_GetEventObject::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxObject * res =   this->_objectptr->GetObj()->GetEventObject();
  BasicVariable::ptr res_var = WrapClass_wxObject::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxEvent::SetEventObject(wxObject * obj)
//---------------------------------------------------
void WrapClass_wxEvent::
    wrap_SetEventObject::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'obj'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvent::
    wrap_SetEventObject::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxObject > obj_smtptr;
  if (!get_val_smtptr_param<wxObject >(obj_smtptr,_p,_n)) ClassHelpAndReturn;
  wxObject* obj = obj_smtptr.get();

  this->_objectptr->GetObj()->SetEventObject(obj);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long int wxEvent::GetTimestamp()
//---------------------------------------------------
void WrapClass_wxEvent::
    wrap_GetTimestamp::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvent::
    wrap_GetTimestamp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   this->_objectptr->GetObj()->GetTimestamp();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxEvent::SetTimestamp(long int ts = 0)
//---------------------------------------------------
void WrapClass_wxEvent::
    wrap_SetTimestamp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'ts' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvent::
    wrap_SetTimestamp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long ts_long = 0;;
  if (!get_val_param<long >(ts_long,_p,_n)) ClassHelpAndReturn;
  long int ts = ts_long;

  this->_objectptr->GetObj()->SetTimestamp(ts);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxEvent::GetId()
//---------------------------------------------------
void WrapClass_wxEvent::
    wrap_GetId::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvent::
    wrap_GetId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetId();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxEvent::SetId(int Id)
//---------------------------------------------------
void WrapClass_wxEvent::
    wrap_SetId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'Id'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvent::
    wrap_SetId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int Id;
  if (!get_val_param<int >(Id,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetId(Id);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxEvent::Skip(bool skip = true)
//---------------------------------------------------
void WrapClass_wxEvent::
    wrap_Skip::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'skip' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvent::
    wrap_Skip::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int skip_int = ((true==true)?1:0);;
  if (!get_val_param<int >(skip_int,_p,_n)) ClassHelpAndReturn;
  bool skip = (bool) (skip_int>0.5);

  this->_objectptr->GetObj()->Skip(skip);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxEvent::GetSkipped()
//---------------------------------------------------
void WrapClass_wxEvent::
    wrap_GetSkipped::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvent::
    wrap_GetSkipped::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetSkipped();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxEvent::IsCommandEvent()
//---------------------------------------------------
void WrapClass_wxEvent::
    wrap_IsCommandEvent::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvent::
    wrap_IsCommandEvent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsCommandEvent();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxEvent::ShouldPropagate()
//---------------------------------------------------
void WrapClass_wxEvent::
    wrap_ShouldPropagate::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvent::
    wrap_ShouldPropagate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ShouldPropagate();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of int wxEvent::StopPropagation()
//---------------------------------------------------
void WrapClass_wxEvent::
    wrap_StopPropagation::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvent::
    wrap_StopPropagation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->StopPropagation();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxEvent::ResumePropagation(int propagationLevel)
//---------------------------------------------------
void WrapClass_wxEvent::
    wrap_ResumePropagation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'propagationLevel'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvent::
    wrap_ResumePropagation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int propagationLevel;
  if (!get_val_param<int >(propagationLevel,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ResumePropagation(propagationLevel);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

