/**
 * C++ Interface: wrap_wxFocusEvent
 *
 * Description: wrapping wxFocusEvent
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

#include "wrap_wxFocusEvent.h"

// get all the required includes
// #include "..."
#ifndef wxFocusEvent_declared
  #define wxFocusEvent_declared
  AMI_DECLARE_TYPE(wxFocusEvent)
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
BasicVariable::ptr WrapClass<wxFocusEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxFocusEvent::wrap_wxFocusEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxFocusEvent);
AMI_DEFINE_VARFROMSMTPTR(wxFocusEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxFocusEvent
//
Variable<AMIObject>::ptr WrapClass_wxFocusEvent::CreateVar( wxFocusEvent* sp)
{
  boost::shared_ptr<wxFocusEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxFocusEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxFocusEvent>::CreateVar(
      new WrapClass_wxFocusEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxFocusEvent::AddMethods(WrapClass<wxFocusEvent>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_GetWindow( this_ptr);
  AddVar_SetWindow( this_ptr);
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
void WrapClasswxFocusEvent_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxFocusEvent");
    WrapClass_wxFocusEvent::AddVar_wxFocusEvent_1(amiobject->GetContext());
  WrapClass_wxFocusEvent::AddVar_wxFocusEvent(amiobject->GetContext());
  WrapClass_wxFocusEvent::AddVar_wxFocusEvent_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxFocusEvent::wxFocusEvent(wxEventType type = wxEVT_NULL, int winid = 0)
//---------------------------------------------------
void WrapClass_wxFocusEvent::
    wrap_wxFocusEvent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type' (def:wxEVT_NULL)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFocusEvent::
    wrap_wxFocusEvent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int type = wxEVT_NULL;
  if (!get_val_param<int >(type,_p,_n,false,true)) ClassReturnEmptyVar;

  int winid = 0;
  if (!get_val_param<int >(winid,_p,_n,false,true)) ClassReturnEmptyVar;

  wxFocusEvent* _newobj = new wxFocusEvent(type, winid);
  BasicVariable::ptr res = WrapClass_wxFocusEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxFocusEvent::wxFocusEvent(...)
//---------------------------------------------------
void WrapClass_wxFocusEvent::
    wrap_wxFocusEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFocusEvent::
    wrap_wxFocusEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFocusEvent::wrap_wxFocusEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxFocusEvent::wrap_wxFocusEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxFocusEvent::wxFocusEvent(wxFocusEvent const & event)
//---------------------------------------------------
void WrapClass_wxFocusEvent::
    wrap_wxFocusEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFocusEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFocusEvent::
    wrap_wxFocusEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxFocusEvent > event_smtptr;
  if (!get_val_smtptr_param<wxFocusEvent >(event_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxFocusEvent const & event = *event_smtptr;

  wxFocusEvent* _newobj = new wxFocusEvent(event);
  BasicVariable::ptr res = WrapClass_wxFocusEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxFocusEvent.
//---------------------------------------------------
void WrapClass_wxFocusEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxFocusEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFocusEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxFocusEvent >::CreateVar( new wxFocusEvent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxFocusEvent::GetWindow()
//---------------------------------------------------
void WrapClass_wxFocusEvent::
    wrap_GetWindow::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFocusEvent::
    wrap_GetWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetWindow();
  BasicVariable::ptr res_var = AMILabType<wxWindow >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxFocusEvent::SetWindow(wxWindow * win)
//---------------------------------------------------
void WrapClass_wxFocusEvent::
    wrap_SetWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'win'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFocusEvent::
    wrap_SetWindow::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetWindow(win);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxFocusEvent::Clone()
//---------------------------------------------------
void WrapClass_wxFocusEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFocusEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = AMILabType<wxEvent >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxFocusEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxFocusEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFocusEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

