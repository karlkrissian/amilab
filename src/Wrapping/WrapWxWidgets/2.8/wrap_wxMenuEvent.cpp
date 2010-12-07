/**
 * C++ Interface: wrap_wxMenuEvent
 *
 * Description: wrapping wxMenuEvent
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
#include "wrap_wxMenu.h"
#include "wrap_wxMenuEvent.h"
#include "wrap_wxEvent.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxMenuEvent.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxMenuEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxMenuEvent::wrap_wxMenuEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxMenuEvent);
AMI_DEFINE_VARFROMSMTPTR(wxMenuEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxMenuEvent
//
Variable<AMIObject>::ptr WrapClass_wxMenuEvent::CreateVar( wxMenuEvent* sp)
{
  boost::shared_ptr<wxMenuEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxMenuEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxMenuEvent>::CreateVar(
      new WrapClass_wxMenuEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxMenuEvent::AddMethods(WrapClass<wxMenuEvent>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_GetMenuId( this_ptr);
      AddVar_IsPopup( this_ptr);
      AddVar_GetMenu( this_ptr);
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
void WrapClass_wxMenuEvent::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxMenuEvent");
    WrapClass_wxMenuEvent::AddVar_wxMenuEvent_1(amiobject->GetContext());
  WrapClass_wxMenuEvent::AddVar_wxMenuEvent(amiobject->GetContext());
  WrapClass_wxMenuEvent::AddVar_wxMenuEvent_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxMenuEvent::wxMenuEvent(wxEventType type = wxEVT_NULL, int winid = 0, wxMenu * menu = 0l)
//---------------------------------------------------
void WrapClass_wxMenuEvent::
    wrap_wxMenuEvent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type' (def:wxEVT_NULL)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menu' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuEvent::
    wrap_wxMenuEvent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int type = wxEVT_NULL;
  if (!get_val_param<int >(type,_p,_n,false,true)) ClassReturnEmptyVar;

  int winid = 0;
  if (!get_val_param<int >(winid,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxMenu > menu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(menu_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenu* menu = menu_smtptr.get();

  wxMenuEvent* _newobj = new wxMenuEvent(type, winid, menu);
  BasicVariable::ptr res = WrapClass_wxMenuEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxMenuEvent::wxMenuEvent(...)
//---------------------------------------------------
void WrapClass_wxMenuEvent::
    wrap_wxMenuEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuEvent::
    wrap_wxMenuEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuEvent::wrap_wxMenuEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuEvent::wrap_wxMenuEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxMenuEvent::wxMenuEvent(wxMenuEvent const & event)
//---------------------------------------------------
void WrapClass_wxMenuEvent::
    wrap_wxMenuEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuEvent::
    wrap_wxMenuEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMenuEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMenuEvent >(event_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxMenuEvent const & event = *event_smtptr;

  wxMenuEvent* _newobj = new wxMenuEvent(event);
  BasicVariable::ptr res = WrapClass_wxMenuEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxMenuEvent.
//---------------------------------------------------
void WrapClass_wxMenuEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxMenuEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxMenuEvent >::CreateVar( new wxMenuEvent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of int wxMenuEvent::GetMenuId()
//---------------------------------------------------
void WrapClass_wxMenuEvent::
    wrap_GetMenuId::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuEvent::
    wrap_GetMenuId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMenuId();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxMenuEvent::IsPopup()
//---------------------------------------------------
void WrapClass_wxMenuEvent::
    wrap_IsPopup::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuEvent::
    wrap_IsPopup::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsPopup();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxMenu * wxMenuEvent::GetMenu()
//---------------------------------------------------
void WrapClass_wxMenuEvent::
    wrap_GetMenu::SetParametersComments()
{
  return_comments="returning a variable of type wxMenu";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuEvent::
    wrap_GetMenu::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxMenu * res =   this->_objectptr->GetObj()->GetMenu();
  BasicVariable::ptr res_var = WrapClass_wxMenu::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxMenuEvent::Clone()
//---------------------------------------------------
void WrapClass_wxMenuEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = WrapClass_wxEvent::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxMenuEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxMenuEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

