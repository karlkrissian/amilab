/**
 * C++ Interface: wrap_wxSizeEvent
 *
 * Description: wrapping wxSizeEvent
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

#include "wrap_wxSizeEvent.h"

// get all the required includes
// #include "..."
#ifndef wxSize_declared
  #define wxSize_declared
  AMI_DECLARE_TYPE(wxSize)
#endif
#ifndef wxSizeEvent_declared
  #define wxSizeEvent_declared
  AMI_DECLARE_TYPE(wxSizeEvent)
#endif
#ifndef wxRect_declared
  #define wxRect_declared
  AMI_DECLARE_TYPE(wxRect)
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
BasicVariable::ptr WrapClass<wxSizeEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxSizeEvent::wrap_wxSizeEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxSizeEvent);
AMI_DEFINE_VARFROMSMTPTR(wxSizeEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxSizeEvent
//
Variable<AMIObject>::ptr WrapClass_wxSizeEvent::CreateVar( wxSizeEvent* sp)
{
  boost::shared_ptr<wxSizeEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxSizeEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxSizeEvent>::CreateVar(
      new WrapClass_wxSizeEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxSizeEvent::AddMethods(WrapClass<wxSizeEvent>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_GetSize( this_ptr);
  AddVar_GetRect( this_ptr);
  AddVar_SetRect( this_ptr);
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
void WrapClasswxSizeEvent_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxSizeEvent");
    WrapClass_wxSizeEvent::AddVar_wxSizeEvent_1(amiobject->GetContext());
  WrapClass_wxSizeEvent::AddVar_wxSizeEvent(amiobject->GetContext());
  WrapClass_wxSizeEvent::AddVar_wxSizeEvent_2(amiobject->GetContext());
  WrapClass_wxSizeEvent::AddVar_wxSizeEvent_3(amiobject->GetContext());
  WrapClass_wxSizeEvent::AddVar_wxSizeEvent_4(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxSizeEvent::wxSizeEvent()
//---------------------------------------------------
void WrapClass_wxSizeEvent::
    wrap_wxSizeEvent_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizeEvent::
    wrap_wxSizeEvent_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxSizeEvent* _newobj = new wxSizeEvent();
  BasicVariable::ptr res = WrapClass_wxSizeEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxSizeEvent::wxSizeEvent(...)
//---------------------------------------------------
void WrapClass_wxSizeEvent::
    wrap_wxSizeEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizeEvent::
    wrap_wxSizeEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizeEvent::wrap_wxSizeEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizeEvent::wrap_wxSizeEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxSizeEvent::wrap_wxSizeEvent_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxSizeEvent::wrap_wxSizeEvent_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxSizeEvent::wxSizeEvent(wxSize const & sz, int winid = 0)
//---------------------------------------------------
void WrapClass_wxSizeEvent::
    wrap_wxSizeEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizeEvent::
    wrap_wxSizeEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > sz_smtptr;
  if (!get_val_smtptr_param<wxSize >(sz_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & sz = *sz_smtptr;

  int winid = 0;
  if (!get_val_param<int >(winid,_p,_n,false,true)) ClassReturnEmptyVar;

  wxSizeEvent* _newobj = new wxSizeEvent(sz, winid);
  BasicVariable::ptr res = WrapClass_wxSizeEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxSizeEvent::wxSizeEvent(wxSizeEvent const & event)
//---------------------------------------------------
void WrapClass_wxSizeEvent::
    wrap_wxSizeEvent_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizeEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizeEvent::
    wrap_wxSizeEvent_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizeEvent > event_smtptr;
  if (!get_val_smtptr_param<wxSizeEvent >(event_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxSizeEvent const & event = *event_smtptr;

  wxSizeEvent* _newobj = new wxSizeEvent(event);
  BasicVariable::ptr res = WrapClass_wxSizeEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxSizeEvent::wxSizeEvent(wxRect const & rect, int id = 0)
//---------------------------------------------------
void WrapClass_wxSizeEvent::
    wrap_wxSizeEvent_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizeEvent::
    wrap_wxSizeEvent_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  int id = 0;
  if (!get_val_param<int >(id,_p,_n,false,true)) ClassReturnEmptyVar;

  wxSizeEvent* _newobj = new wxSizeEvent(rect, id);
  BasicVariable::ptr res = WrapClass_wxSizeEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxSizeEvent.
//---------------------------------------------------
void WrapClass_wxSizeEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxSizeEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizeEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxSizeEvent >::CreateVar( new wxSizeEvent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxSize wxSizeEvent::GetSize()
//---------------------------------------------------
void WrapClass_wxSizeEvent::
    wrap_GetSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizeEvent::
    wrap_GetSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRect wxSizeEvent::GetRect()
//---------------------------------------------------
void WrapClass_wxSizeEvent::
    wrap_GetRect::SetParametersComments()
{
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizeEvent::
    wrap_GetRect::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxRect res =   this->_objectptr->GetObj()->GetRect();
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxSizeEvent::SetRect(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxSizeEvent::
    wrap_SetRect::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizeEvent::
    wrap_SetRect::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRect const & rect = *rect_smtptr;

  this->_objectptr->GetObj()->SetRect(rect);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxSizeEvent::Clone()
//---------------------------------------------------
void WrapClass_wxSizeEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizeEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = AMILabType<wxEvent >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxSizeEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxSizeEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizeEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

