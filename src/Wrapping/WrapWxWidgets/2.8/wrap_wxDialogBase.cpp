/**
 * C++ Interface: wrap_wxDialogBase
 *
 * Description: wrapping wxDialogBase
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

#include "wrap_wxDialogBase.h"

// get all the required includes
// #include "..."
#ifndef wxSizer_declared
  #define wxSizer_declared
  AMI_DECLARE_TYPE(wxSizer)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxStdDialogButtonSizer_declared
  #define wxStdDialogButtonSizer_declared
  AMI_DECLARE_TYPE(wxStdDialogButtonSizer)
#endif
#ifndef wxNavigationKeyEvent_declared
  #define wxNavigationKeyEvent_declared
  AMI_DECLARE_TYPE(wxNavigationKeyEvent)
#endif
#ifndef wxFocusEvent_declared
  #define wxFocusEvent_declared
  AMI_DECLARE_TYPE(wxFocusEvent)
#endif
#ifndef wxChildFocusEvent_declared
  #define wxChildFocusEvent_declared
  AMI_DECLARE_TYPE(wxChildFocusEvent)
#endif
#ifndef wxWindowBase_declared
  #define wxWindowBase_declared
  AMI_DECLARE_TYPE(wxWindowBase)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxDialogBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxDialogBase);
AMI_DEFINE_VARFROMSMTPTR(wxDialogBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxDialogBase>::CreateVar( wxDialogBase* val, bool nodeleter)
{ 
  boost::shared_ptr<wxDialogBase> obj_ptr(val,smartpointer_nodeleter<wxDialogBase>());
  return AMILabType<wxDialogBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxDialogBase
//
Variable<AMIObject>::ptr WrapClass_wxDialogBase::CreateVar( wxDialogBase* sp)
{
  boost::shared_ptr<wxDialogBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxDialogBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxDialogBase>::CreateVar(
      new WrapClass_wxDialogBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxDialogBase::AddMethods(WrapClass<wxDialogBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_SetReturnCode( this_ptr);
  AddVar_GetReturnCode( this_ptr);
  AddVar_SetAffirmativeId( this_ptr);
  AddVar_GetAffirmativeId( this_ptr);
  AddVar_SetEscapeId( this_ptr);
  AddVar_GetEscapeId( this_ptr);
  AddVar_CreateTextSizer( this_ptr);
  AddVar_CreateButtonSizer( this_ptr);
  AddVar_CreateSeparatedButtonSizer( this_ptr);
  AddVar_CreateStdDialogButtonSizer( this_ptr);
  AddVar_OnNavigationKey( this_ptr);
  AddVar_OnFocus( this_ptr);
  AddVar_OnChildFocus( this_ptr);
  AddVar_SetFocus( this_ptr);
  AddVar_SetFocusIgnoringChildren( this_ptr);
  AddVar_RemoveChild( this_ptr);
  AddVar_AcceptsFocus( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  
  AMIObject::ptr obj_enum_157(new AMIObject);
  obj_enum_157->SetName("enum_157");

  BasicVariable::ptr var_ButtonSizerFlags = AMILabType<int >::CreateVar(32926);
  if (var_ButtonSizerFlags.get()) {
    var_ButtonSizerFlags->Rename("ButtonSizerFlags");
    obj_enum_157->GetContext()->AddVar(var_ButtonSizerFlags,obj_enum_157->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_enum_157->GetName().c_str(),obj_enum_157,context);


  // Adding Bases

  // Add base parent wxTopLevelWindow
  boost::shared_ptr<wxTopLevelWindow > parent_wxTopLevelWindow(  boost::dynamic_pointer_cast<wxTopLevelWindow >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxTopLevelWindow = AMILabType<wxTopLevelWindow >::CreateVarFromSmtPtr(parent_wxTopLevelWindow);
  context->AddVar("wxTopLevelWindow",var_wxTopLevelWindow);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxTopLevelWindow = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxTopLevelWindow);
  context->AddDefault(obj_wxTopLevelWindow->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxDialogBase_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxDialogBase");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of void wxDialogBase::SetReturnCode(int returnCode)
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_SetReturnCode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'returnCode'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_SetReturnCode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int returnCode;
  if (!get_val_param<int >(returnCode,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetReturnCode(returnCode);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxDialogBase::GetReturnCode()
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_GetReturnCode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_GetReturnCode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetReturnCode();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDialogBase::SetAffirmativeId(int affirmativeId)
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_SetAffirmativeId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'affirmativeId'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_SetAffirmativeId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int affirmativeId;
  if (!get_val_param<int >(affirmativeId,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAffirmativeId(affirmativeId);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxDialogBase::GetAffirmativeId()
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_GetAffirmativeId::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_GetAffirmativeId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAffirmativeId();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDialogBase::SetEscapeId(int escapeId)
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_SetEscapeId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'escapeId'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_SetEscapeId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int escapeId;
  if (!get_val_param<int >(escapeId,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetEscapeId(escapeId);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxDialogBase::GetEscapeId()
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_GetEscapeId::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_GetEscapeId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetEscapeId();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizer * wxDialogBase::CreateTextSizer(wxString const & message)
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_CreateTextSizer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'message'")
  return_comments="returning a variable of type wxSizer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_CreateTextSizer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > message_smtptr;
  if (!get_val_smtptr_param<wxString >(message_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & message = *message_smtptr;

  wxSizer * res =   this->_objectptr->GetObj()->CreateTextSizer(message);
  BasicVariable::ptr res_var = AMILabType<wxSizer >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizer * wxDialogBase::CreateButtonSizer(long int flags)
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_CreateButtonSizer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flags'")
  return_comments="returning a variable of type wxSizer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_CreateButtonSizer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long flags_long;
  if (!get_val_param<long >(flags_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int flags = flags_long;

  wxSizer * res =   this->_objectptr->GetObj()->CreateButtonSizer(flags);
  BasicVariable::ptr res_var = AMILabType<wxSizer >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizer * wxDialogBase::CreateSeparatedButtonSizer(long int flags)
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_CreateSeparatedButtonSizer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flags'")
  return_comments="returning a variable of type wxSizer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_CreateSeparatedButtonSizer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long flags_long;
  if (!get_val_param<long >(flags_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int flags = flags_long;

  wxSizer * res =   this->_objectptr->GetObj()->CreateSeparatedButtonSizer(flags);
  BasicVariable::ptr res_var = AMILabType<wxSizer >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxStdDialogButtonSizer * wxDialogBase::CreateStdDialogButtonSizer(long int flags)
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_CreateStdDialogButtonSizer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flags'")
  return_comments="returning a variable of type wxStdDialogButtonSizer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_CreateStdDialogButtonSizer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long flags_long;
  if (!get_val_param<long >(flags_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int flags = flags_long;

  wxStdDialogButtonSizer * res =   this->_objectptr->GetObj()->CreateStdDialogButtonSizer(flags);
  BasicVariable::ptr res_var = AMILabType<wxStdDialogButtonSizer >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxDialogBase::OnNavigationKey(wxNavigationKeyEvent & event)
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_OnNavigationKey::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxNavigationKeyEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_OnNavigationKey::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxNavigationKeyEvent > event_smtptr;
  if (!get_val_smtptr_param<wxNavigationKeyEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxNavigationKeyEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnNavigationKey(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDialogBase::OnFocus(wxFocusEvent & event)
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_OnFocus::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFocusEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_OnFocus::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFocusEvent > event_smtptr;
  if (!get_val_smtptr_param<wxFocusEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFocusEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnFocus(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDialogBase::OnChildFocus(wxChildFocusEvent & event)
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_OnChildFocus::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxChildFocusEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_OnChildFocus::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxChildFocusEvent > event_smtptr;
  if (!get_val_smtptr_param<wxChildFocusEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxChildFocusEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnChildFocus(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDialogBase::SetFocus()
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_SetFocus::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_SetFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFocus();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDialogBase::SetFocusIgnoringChildren()
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_SetFocusIgnoringChildren::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_SetFocusIgnoringChildren::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFocusIgnoringChildren();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDialogBase::RemoveChild(wxWindowBase * child)
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_RemoveChild::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'child'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_RemoveChild::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxWindowBase* child;
  if (CheckNullVar(_p,_n))  {
    child=(wxWindowBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindowBase > child_smtptr;
    if (!get_val_smtptr_param<wxWindowBase >(child_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    child = child_smtptr.get();
  }

  this->_objectptr->GetObj()->RemoveChild(child);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxDialogBase::AcceptsFocus()
//---------------------------------------------------
void WrapClass_wxDialogBase::
    wrap_AcceptsFocus::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialogBase::
    wrap_AcceptsFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->AcceptsFocus();
  return AMILabType<bool >::CreateVar(res);
}

