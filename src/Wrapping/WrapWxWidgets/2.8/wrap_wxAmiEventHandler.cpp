/**
 * C++ Interface: wrap_wxAmiEventHandler
 *
 * Description: wrapping wxAmiEventHandler
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

#include "wrap_wxAmiEventHandler.h"

// get all the required includes
// #include "..."
#ifndef wxCommandEvent_declared
  #define wxCommandEvent_declared
  AMI_DECLARE_TYPE(wxCommandEvent)
#endif
#ifndef wxObjectEventFunction_declared
  #define wxObjectEventFunction_declared
  AMI_DECLARE_TYPE(wxObjectEventFunction)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAmiEventHandler>::CreateVar( ParamList* p)
{
  WrapClass_wxAmiEventHandler::wrap_wxAmiEventHandler construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxAmiEventHandler);
AMI_DEFINE_VARFROMSMTPTR(wxAmiEventHandler);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxAmiEventHandler>::CreateVar( wxAmiEventHandler* val, bool nodeleter)
{ 
  boost::shared_ptr<wxAmiEventHandler> obj_ptr(val,smartpointer_nodeleter<wxAmiEventHandler>());
  return AMILabType<wxAmiEventHandler>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxAmiEventHandler
//
Variable<AMIObject>::ptr WrapClass_wxAmiEventHandler::CreateVar( wxAmiEventHandler* sp)
{
  boost::shared_ptr<wxAmiEventHandler> di_ptr(
    sp,
    wxwindow_nodeleter<wxAmiEventHandler>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAmiEventHandler>::CreateVar(
      new WrapClass_wxAmiEventHandler(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxAmiEventHandler::AddMethods(WrapClass<wxAmiEventHandler>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_OnTest( this_ptr);
  AddVar_GetEventFunction( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxEvtHandler
  boost::shared_ptr<wxEvtHandler > parent_wxEvtHandler(  boost::dynamic_pointer_cast<wxEvtHandler >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxEvtHandler = AMILabType<wxEvtHandler >::CreateVarFromSmtPtr(parent_wxEvtHandler);
  context->AddVar("wxEvtHandler",var_wxEvtHandler);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxEvtHandler = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxEvtHandler);
  context->AddDefault(obj_wxEvtHandler->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxAmiEventHandler_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxAmiEventHandler");
    WrapClass_wxAmiEventHandler::AddVar_wxAmiEventHandler(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxAmiEventHandler::wxAmiEventHandler(AMIFunction * f = 0l)
//---------------------------------------------------
void WrapClass_wxAmiEventHandler::
    wrap_wxAmiEventHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( AMIFunction, "parameter named 'f' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAmiEventHandler::
    wrap_wxAmiEventHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  AMIFunction* f = 0l;
  if (CheckNullVar(_p,_n))  {
    f=(AMIFunction*)NULL;
    _n++;
  } else {
    boost::shared_ptr<AMIFunction > f_smtptr;
    if (!get_val_smtptr_param<AMIFunction >(f_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    f = f_smtptr.get();
  }

  wxAmiEventHandler* _newobj = new wxAmiEventHandler(f);
  BasicVariable::ptr res = WrapClass_wxAmiEventHandler::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxAmiEventHandler::OnTest(wxCommandEvent & event)
//---------------------------------------------------
void WrapClass_wxAmiEventHandler::
    wrap_OnTest::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCommandEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAmiEventHandler::
    wrap_OnTest::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxCommandEvent > event_smtptr;
  if (!get_val_smtptr_param<wxCommandEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxCommandEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnTest(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxObjectEventFunction * wxAmiEventHandler::GetEventFunction()
//---------------------------------------------------
void WrapClass_wxAmiEventHandler::
    wrap_GetEventFunction::SetParametersComments()
{
  return_comments="returning a variable of type wxObjectEventFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAmiEventHandler::
    wrap_GetEventFunction::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxObjectEventFunction * res =   this->_objectptr->GetObj()->GetEventFunction();
  BasicVariable::ptr res_var = AMILabType<wxObjectEventFunction >::CreateVar(res,true);
  return res_var;
}

