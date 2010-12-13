/**
 * C++ Interface: wrap_wxChildFocusEvent
 *
 * Description: wrapping wxChildFocusEvent
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

#include "wrap_wxChildFocusEvent.h"

// get all the required includes
// #include "..."
#ifndef wxChildFocusEvent_declared
  #define wxChildFocusEvent_declared
  AMI_DECLARE_TYPE(wxChildFocusEvent)
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
BasicVariable::ptr WrapClass<wxChildFocusEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxChildFocusEvent::wrap_wxChildFocusEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxChildFocusEvent);
AMI_DEFINE_VARFROMSMTPTR(wxChildFocusEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxChildFocusEvent
//
Variable<AMIObject>::ptr WrapClass_wxChildFocusEvent::CreateVar( wxChildFocusEvent* sp)
{
  boost::shared_ptr<wxChildFocusEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxChildFocusEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxChildFocusEvent>::CreateVar(
      new WrapClass_wxChildFocusEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxChildFocusEvent::AddMethods(WrapClass<wxChildFocusEvent>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_GetWindow( this_ptr);
  AddVar_Clone( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxCommandEvent
  boost::shared_ptr<wxCommandEvent > parent_wxCommandEvent(  boost::dynamic_pointer_cast<wxCommandEvent >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxCommandEvent = AMILabType<wxCommandEvent >::CreateVarFromSmtPtr(parent_wxCommandEvent);
  context->AddVar("wxCommandEvent",var_wxCommandEvent);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxCommandEvent = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxCommandEvent);
  context->AddDefault(obj_wxCommandEvent->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxChildFocusEvent_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxChildFocusEvent");
    WrapClass_wxChildFocusEvent::AddVar_wxChildFocusEvent_1(amiobject->GetContext());
  WrapClass_wxChildFocusEvent::AddVar_wxChildFocusEvent(amiobject->GetContext());
  WrapClass_wxChildFocusEvent::AddVar_wxChildFocusEvent_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxChildFocusEvent::wxChildFocusEvent(wxChildFocusEvent const & param0)
//---------------------------------------------------
void WrapClass_wxChildFocusEvent::
    wrap_wxChildFocusEvent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxChildFocusEvent, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxChildFocusEvent::
    wrap_wxChildFocusEvent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxChildFocusEvent > param0_smtptr;
  if (!get_val_smtptr_param<wxChildFocusEvent >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxChildFocusEvent const & param0 = *param0_smtptr;

  wxChildFocusEvent* _newobj = new wxChildFocusEvent(param0);
  BasicVariable::ptr res = WrapClass_wxChildFocusEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxChildFocusEvent::wxChildFocusEvent(...)
//---------------------------------------------------
void WrapClass_wxChildFocusEvent::
    wrap_wxChildFocusEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxChildFocusEvent::
    wrap_wxChildFocusEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxChildFocusEvent::wrap_wxChildFocusEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxChildFocusEvent::wrap_wxChildFocusEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxChildFocusEvent::wxChildFocusEvent(wxWindow * win = 0l)
//---------------------------------------------------
void WrapClass_wxChildFocusEvent::
    wrap_wxChildFocusEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'win' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxChildFocusEvent::
    wrap_wxChildFocusEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  wxWindow* win = 0l;
  if (CheckNullVar(_p,_n))  {
    win=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > win_smtptr;
    if (!get_val_smtptr_param<wxWindow >(win_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
    win = win_smtptr.get();
  }

  wxChildFocusEvent* _newobj = new wxChildFocusEvent(win);
  BasicVariable::ptr res = WrapClass_wxChildFocusEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxChildFocusEvent.
//---------------------------------------------------
void WrapClass_wxChildFocusEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxChildFocusEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxChildFocusEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxChildFocusEvent >::CreateVar( new wxChildFocusEvent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxChildFocusEvent::GetWindow()
//---------------------------------------------------
void WrapClass_wxChildFocusEvent::
    wrap_GetWindow::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxChildFocusEvent::
    wrap_GetWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetWindow();
  BasicVariable::ptr res_var = AMILabType<wxWindow >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxChildFocusEvent::Clone()
//---------------------------------------------------
void WrapClass_wxChildFocusEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxChildFocusEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = AMILabType<wxEvent >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxChildFocusEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxChildFocusEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxChildFocusEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

