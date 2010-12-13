/**
 * C++ Interface: wrap_wxPaintEvent
 *
 * Description: wrapping wxPaintEvent
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

#include "wrap_wxPaintEvent.h"

// get all the required includes
// #include "..."
#ifndef wxPaintEvent_declared
  #define wxPaintEvent_declared
  AMI_DECLARE_TYPE(wxPaintEvent)
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
BasicVariable::ptr WrapClass<wxPaintEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxPaintEvent::wrap_wxPaintEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxPaintEvent);
AMI_DEFINE_VARFROMSMTPTR(wxPaintEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxPaintEvent
//
Variable<AMIObject>::ptr WrapClass_wxPaintEvent::CreateVar( wxPaintEvent* sp)
{
  boost::shared_ptr<wxPaintEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxPaintEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxPaintEvent>::CreateVar(
      new WrapClass_wxPaintEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxPaintEvent::AddMethods(WrapClass<wxPaintEvent>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
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
void WrapClasswxPaintEvent_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxPaintEvent");
    WrapClass_wxPaintEvent::AddVar_wxPaintEvent_1(amiobject->GetContext());
  WrapClass_wxPaintEvent::AddVar_wxPaintEvent(amiobject->GetContext());
  WrapClass_wxPaintEvent::AddVar_wxPaintEvent_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxPaintEvent::wxPaintEvent(wxPaintEvent const & param0)
//---------------------------------------------------
void WrapClass_wxPaintEvent::
    wrap_wxPaintEvent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPaintEvent, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPaintEvent::
    wrap_wxPaintEvent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPaintEvent > param0_smtptr;
  if (!get_val_smtptr_param<wxPaintEvent >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxPaintEvent const & param0 = *param0_smtptr;

  wxPaintEvent* _newobj = new wxPaintEvent(param0);
  BasicVariable::ptr res = WrapClass_wxPaintEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxPaintEvent::wxPaintEvent(...)
//---------------------------------------------------
void WrapClass_wxPaintEvent::
    wrap_wxPaintEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPaintEvent::
    wrap_wxPaintEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxPaintEvent::wrap_wxPaintEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxPaintEvent::wrap_wxPaintEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxPaintEvent::wxPaintEvent(int Id = 0)
//---------------------------------------------------
void WrapClass_wxPaintEvent::
    wrap_wxPaintEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'Id' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPaintEvent::
    wrap_wxPaintEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int Id = 0;
  if (!get_val_param<int >(Id,_p,_n,false,true)) ClassReturnEmptyVar;

  wxPaintEvent* _newobj = new wxPaintEvent(Id);
  BasicVariable::ptr res = WrapClass_wxPaintEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxPaintEvent.
//---------------------------------------------------
void WrapClass_wxPaintEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxPaintEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPaintEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxPaintEvent >::CreateVar( new wxPaintEvent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxPaintEvent::Clone()
//---------------------------------------------------
void WrapClass_wxPaintEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPaintEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = AMILabType<wxEvent >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxPaintEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxPaintEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPaintEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

