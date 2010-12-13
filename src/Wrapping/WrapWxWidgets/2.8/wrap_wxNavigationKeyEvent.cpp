/**
 * C++ Interface: wrap_wxNavigationKeyEvent
 *
 * Description: wrapping wxNavigationKeyEvent
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

#include "wrap_wxNavigationKeyEvent.h"

// get all the required includes
// #include "..."
#ifndef wxWindow_declared
  #define wxWindow_declared
  AMI_DECLARE_TYPE(wxWindow)
#endif
#ifndef wxNavigationKeyEvent_declared
  #define wxNavigationKeyEvent_declared
  AMI_DECLARE_TYPE(wxNavigationKeyEvent)
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
BasicVariable::ptr WrapClass<wxNavigationKeyEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxNavigationKeyEvent::wrap_wxNavigationKeyEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxNavigationKeyEvent);
AMI_DEFINE_VARFROMSMTPTR(wxNavigationKeyEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxNavigationKeyEvent
//
Variable<AMIObject>::ptr WrapClass_wxNavigationKeyEvent::CreateVar( wxNavigationKeyEvent* sp)
{
  boost::shared_ptr<wxNavigationKeyEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxNavigationKeyEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxNavigationKeyEvent>::CreateVar(
      new WrapClass_wxNavigationKeyEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxNavigationKeyEvent::AddMethods(WrapClass<wxNavigationKeyEvent>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_GetDirection( this_ptr);
  AddVar_SetDirection( this_ptr);
  AddVar_IsWindowChange( this_ptr);
  AddVar_SetWindowChange( this_ptr);
  AddVar_IsFromTab( this_ptr);
  AddVar_SetFromTab( this_ptr);
  AddVar_GetCurrentFocus( this_ptr);
  AddVar_SetCurrentFocus( this_ptr);
  AddVar_SetFlags( this_ptr);
  AddVar_Clone( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());
  
  // Adding public member m_flags
  boost::shared_ptr<long int > var_m_flags_ptr(&GetObj()->m_flags, smartpointer_nodeleter<long int >());
  if (var_m_flags_ptr.get()) {
    BasicVariable::ptr var_m_flags = AMILabType<long int >::CreateVarFromSmtPtr(var_m_flags_ptr);
    if (var_m_flags.get()) {
      var_m_flags->Rename("m_flags");
      context->AddVar(var_m_flags,context);
    }
  }
  
  // Adding public member m_focus
  boost::shared_ptr<wxWindow > var_m_focus_ptr(GetObj()->m_focus, smartpointer_nodeleter<wxWindow >());
  if (var_m_focus_ptr.get()) {
    BasicVariable::ptr var_m_focus = AMILabType<wxWindow >::CreateVarFromSmtPtr(var_m_focus_ptr);
    if (var_m_focus.get()) {
      var_m_focus->Rename("m_focus");
      context->AddVar(var_m_focus,context);
    }
  }


  
  AMIObject::ptr obj_enum_104(new AMIObject);
  obj_enum_104->SetName("enum_104");

  BasicVariable::ptr var_IsBackward = AMILabType<int >::CreateVar(0);
  if (var_IsBackward.get()) {
    var_IsBackward->Rename("IsBackward");
    obj_enum_104->GetContext()->AddVar(var_IsBackward,obj_enum_104->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_enum_104->GetName().c_str(),obj_enum_104,context);


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
void WrapClasswxNavigationKeyEvent_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxNavigationKeyEvent");
    WrapClass_wxNavigationKeyEvent::AddVar_wxNavigationKeyEvent_1(amiobject->GetContext());
  WrapClass_wxNavigationKeyEvent::AddVar_wxNavigationKeyEvent(amiobject->GetContext());
  WrapClass_wxNavigationKeyEvent::AddVar_wxNavigationKeyEvent_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxNavigationKeyEvent::wxNavigationKeyEvent()
//---------------------------------------------------
void WrapClass_wxNavigationKeyEvent::
    wrap_wxNavigationKeyEvent_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNavigationKeyEvent::
    wrap_wxNavigationKeyEvent_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxNavigationKeyEvent* _newobj = new wxNavigationKeyEvent();
  BasicVariable::ptr res = WrapClass_wxNavigationKeyEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxNavigationKeyEvent::wxNavigationKeyEvent(...)
//---------------------------------------------------
void WrapClass_wxNavigationKeyEvent::
    wrap_wxNavigationKeyEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNavigationKeyEvent::
    wrap_wxNavigationKeyEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxNavigationKeyEvent::wrap_wxNavigationKeyEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxNavigationKeyEvent::wrap_wxNavigationKeyEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxNavigationKeyEvent::wxNavigationKeyEvent(wxNavigationKeyEvent const & event)
//---------------------------------------------------
void WrapClass_wxNavigationKeyEvent::
    wrap_wxNavigationKeyEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxNavigationKeyEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNavigationKeyEvent::
    wrap_wxNavigationKeyEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxNavigationKeyEvent > event_smtptr;
  if (!get_val_smtptr_param<wxNavigationKeyEvent >(event_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxNavigationKeyEvent const & event = *event_smtptr;

  wxNavigationKeyEvent* _newobj = new wxNavigationKeyEvent(event);
  BasicVariable::ptr res = WrapClass_wxNavigationKeyEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxNavigationKeyEvent.
//---------------------------------------------------
void WrapClass_wxNavigationKeyEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxNavigationKeyEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNavigationKeyEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxNavigationKeyEvent >::CreateVar( new wxNavigationKeyEvent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxNavigationKeyEvent::GetDirection()
//---------------------------------------------------
void WrapClass_wxNavigationKeyEvent::
    wrap_GetDirection::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNavigationKeyEvent::
    wrap_GetDirection::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetDirection();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxNavigationKeyEvent::SetDirection(bool bForward)
//---------------------------------------------------
void WrapClass_wxNavigationKeyEvent::
    wrap_SetDirection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'bForward'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNavigationKeyEvent::
    wrap_SetDirection::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool bForward;
  if (!get_val_param<bool >(bForward,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDirection(bForward);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxNavigationKeyEvent::IsWindowChange()
//---------------------------------------------------
void WrapClass_wxNavigationKeyEvent::
    wrap_IsWindowChange::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNavigationKeyEvent::
    wrap_IsWindowChange::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsWindowChange();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxNavigationKeyEvent::SetWindowChange(bool bIs)
//---------------------------------------------------
void WrapClass_wxNavigationKeyEvent::
    wrap_SetWindowChange::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'bIs'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNavigationKeyEvent::
    wrap_SetWindowChange::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool bIs;
  if (!get_val_param<bool >(bIs,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetWindowChange(bIs);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxNavigationKeyEvent::IsFromTab()
//---------------------------------------------------
void WrapClass_wxNavigationKeyEvent::
    wrap_IsFromTab::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNavigationKeyEvent::
    wrap_IsFromTab::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsFromTab();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxNavigationKeyEvent::SetFromTab(bool bIs)
//---------------------------------------------------
void WrapClass_wxNavigationKeyEvent::
    wrap_SetFromTab::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'bIs'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNavigationKeyEvent::
    wrap_SetFromTab::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool bIs;
  if (!get_val_param<bool >(bIs,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFromTab(bIs);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxNavigationKeyEvent::GetCurrentFocus()
//---------------------------------------------------
void WrapClass_wxNavigationKeyEvent::
    wrap_GetCurrentFocus::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNavigationKeyEvent::
    wrap_GetCurrentFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetCurrentFocus();
  BasicVariable::ptr res_var = AMILabType<wxWindow >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxNavigationKeyEvent::SetCurrentFocus(wxWindow * win)
//---------------------------------------------------
void WrapClass_wxNavigationKeyEvent::
    wrap_SetCurrentFocus::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'win'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNavigationKeyEvent::
    wrap_SetCurrentFocus::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetCurrentFocus(win);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxNavigationKeyEvent::SetFlags(long int flags)
//---------------------------------------------------
void WrapClass_wxNavigationKeyEvent::
    wrap_SetFlags::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flags'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNavigationKeyEvent::
    wrap_SetFlags::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long flags_long;
  if (!get_val_param<long >(flags_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int flags = flags_long;

  this->_objectptr->GetObj()->SetFlags(flags);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxNavigationKeyEvent::Clone()
//---------------------------------------------------
void WrapClass_wxNavigationKeyEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNavigationKeyEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = AMILabType<wxEvent >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxNavigationKeyEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxNavigationKeyEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNavigationKeyEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

