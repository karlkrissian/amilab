/**
 * C++ Interface: wrap_wxScrollWinEvent
 *
 * Description: wrapping wxScrollWinEvent
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

#include "wrap_wxScrollWinEvent.h"

// get all the required includes
// #include "..."
#ifndef wxScrollWinEvent_declared
  #define wxScrollWinEvent_declared
  AMI_DECLARE_TYPE(wxScrollWinEvent)
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
BasicVariable::ptr WrapClass<wxScrollWinEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxScrollWinEvent::wrap_wxScrollWinEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxScrollWinEvent);
AMI_DEFINE_VARFROMSMTPTR(wxScrollWinEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxScrollWinEvent
//
Variable<AMIObject>::ptr WrapClass_wxScrollWinEvent::CreateVar( wxScrollWinEvent* sp)
{
  boost::shared_ptr<wxScrollWinEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxScrollWinEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxScrollWinEvent>::CreateVar(
      new WrapClass_wxScrollWinEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxScrollWinEvent::AddMethods(WrapClass<wxScrollWinEvent>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_GetOrientation( this_ptr);
  AddVar_GetPosition( this_ptr);
  AddVar_SetOrientation( this_ptr);
  AddVar_SetPosition( this_ptr);
  AddVar_Clone( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

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
void WrapClasswxScrollWinEvent_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxScrollWinEvent");
    WrapClass_wxScrollWinEvent::AddVar_wxScrollWinEvent_1(amiobject->GetContext());
  WrapClass_wxScrollWinEvent::AddVar_wxScrollWinEvent(amiobject->GetContext());
  WrapClass_wxScrollWinEvent::AddVar_wxScrollWinEvent_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxScrollWinEvent::wxScrollWinEvent(wxEventType commandType = wxEVT_NULL, int pos = 0, int orient = 0)
//---------------------------------------------------
void WrapClass_wxScrollWinEvent::
    wrap_wxScrollWinEvent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'commandType' (def:wxEVT_NULL)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pos' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orient' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollWinEvent::
    wrap_wxScrollWinEvent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int commandType = wxEVT_NULL;
  if (!get_val_param<int >(commandType,_p,_n,false,true)) ClassReturnEmptyVar;

  int pos = 0;
  if (!get_val_param<int >(pos,_p,_n,false,true)) ClassReturnEmptyVar;

  int orient = 0;
  if (!get_val_param<int >(orient,_p,_n,false,true)) ClassReturnEmptyVar;

  wxScrollWinEvent* _newobj = new wxScrollWinEvent(commandType, pos, orient);
  BasicVariable::ptr res = WrapClass_wxScrollWinEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxScrollWinEvent::wxScrollWinEvent(...)
//---------------------------------------------------
void WrapClass_wxScrollWinEvent::
    wrap_wxScrollWinEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollWinEvent::
    wrap_wxScrollWinEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxScrollWinEvent::wrap_wxScrollWinEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxScrollWinEvent::wrap_wxScrollWinEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxScrollWinEvent::wxScrollWinEvent(wxScrollWinEvent const & event)
//---------------------------------------------------
void WrapClass_wxScrollWinEvent::
    wrap_wxScrollWinEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScrollWinEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollWinEvent::
    wrap_wxScrollWinEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScrollWinEvent > event_smtptr;
  if (!get_val_smtptr_param<wxScrollWinEvent >(event_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxScrollWinEvent const & event = *event_smtptr;

  wxScrollWinEvent* _newobj = new wxScrollWinEvent(event);
  BasicVariable::ptr res = WrapClass_wxScrollWinEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxScrollWinEvent.
//---------------------------------------------------
void WrapClass_wxScrollWinEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxScrollWinEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollWinEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxScrollWinEvent >::CreateVar( new wxScrollWinEvent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of int wxScrollWinEvent::GetOrientation()
//---------------------------------------------------
void WrapClass_wxScrollWinEvent::
    wrap_GetOrientation::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollWinEvent::
    wrap_GetOrientation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetOrientation();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxScrollWinEvent::GetPosition()
//---------------------------------------------------
void WrapClass_wxScrollWinEvent::
    wrap_GetPosition::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollWinEvent::
    wrap_GetPosition::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetPosition();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxScrollWinEvent::SetOrientation(int orient)
//---------------------------------------------------
void WrapClass_wxScrollWinEvent::
    wrap_SetOrientation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orient'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollWinEvent::
    wrap_SetOrientation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int orient;
  if (!get_val_param<int >(orient,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetOrientation(orient);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollWinEvent::SetPosition(int pos)
//---------------------------------------------------
void WrapClass_wxScrollWinEvent::
    wrap_SetPosition::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pos'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollWinEvent::
    wrap_SetPosition::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int pos;
  if (!get_val_param<int >(pos,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetPosition(pos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxScrollWinEvent::Clone()
//---------------------------------------------------
void WrapClass_wxScrollWinEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollWinEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = AMILabType<wxEvent >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxScrollWinEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxScrollWinEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollWinEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

