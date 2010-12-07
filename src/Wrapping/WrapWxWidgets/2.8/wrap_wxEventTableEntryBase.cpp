/**
 * C++ Interface: wrap_wxEventTableEntryBase
 *
 * Description: wrapping wxEventTableEntryBase
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
#include "wrap_wxObjectEventFunction.h"
#include "wrap_wxObject.h"
#include "wrap_wxEventTableEntryBase.h"


#include "wrap_wxEventTableEntryBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxEventTableEntryBase>::CreateVar( ParamList* p)
{
  WrapClass_wxEventTableEntryBase::wrap_wxEventTableEntryBase construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxEventTableEntryBase);
AMI_DEFINE_VARFROMSMTPTR(wxEventTableEntryBase);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxEventTableEntryBase
//
Variable<AMIObject>::ptr WrapClass_wxEventTableEntryBase::CreateVar( wxEventTableEntryBase* sp)
{
  boost::shared_ptr<wxEventTableEntryBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxEventTableEntryBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxEventTableEntryBase>::CreateVar(
      new WrapClass_wxEventTableEntryBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxEventTableEntryBase::AddMethods(WrapClass<wxEventTableEntryBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      // Adding public member m_id
      boost::shared_ptr<int > var_m_id_ptr(&GetObj()->m_id, smartpointer_nodeleter<int >());
      if (var_m_id_ptr.get()) {
        BasicVariable::ptr var_m_id = AMILabType<int >::CreateVarFromSmtPtr(var_m_id_ptr);
        if (var_m_id.get()) {
          var_m_id->Rename("m_id");
          context->AddVar(var_m_id,context);
        }
      }
      
      // Adding public member m_lastId
      boost::shared_ptr<int > var_m_lastId_ptr(&GetObj()->m_lastId, smartpointer_nodeleter<int >());
      if (var_m_lastId_ptr.get()) {
        BasicVariable::ptr var_m_lastId = AMILabType<int >::CreateVarFromSmtPtr(var_m_lastId_ptr);
        if (var_m_lastId.get()) {
          var_m_lastId->Rename("m_lastId");
          context->AddVar(var_m_lastId,context);
        }
      }
      
      // Adding public member m_fn
      boost::shared_ptr<wxObjectEventFunction > var_m_fn_ptr(&GetObj()->m_fn, smartpointer_nodeleter<wxObjectEventFunction >());
      if (var_m_fn_ptr.get()) {
        BasicVariable::ptr var_m_fn = AMILabType<wxObjectEventFunction >::CreateVarFromSmtPtr(var_m_fn_ptr);
        if (var_m_fn.get()) {
          var_m_fn->Rename("m_fn");
          context->AddVar(var_m_fn,context);
        }
      }
      
      // Adding public member m_callbackUserData
      boost::shared_ptr<wxObject > var_m_callbackUserData_ptr(GetObj()->m_callbackUserData, smartpointer_nodeleter<wxObject >());
      if (var_m_callbackUserData_ptr.get()) {
        BasicVariable::ptr var_m_callbackUserData = AMILabType<wxObject >::CreateVarFromSmtPtr(var_m_callbackUserData_ptr);
        if (var_m_callbackUserData.get()) {
          var_m_callbackUserData->Rename("m_callbackUserData");
          context->AddVar(var_m_callbackUserData,context);
        }
      }


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxEventTableEntryBase::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxEventTableEntryBase");
    WrapClass_wxEventTableEntryBase::AddVar_wxEventTableEntryBase_1(amiobject->GetContext());
  WrapClass_wxEventTableEntryBase::AddVar_wxEventTableEntryBase(amiobject->GetContext());
  WrapClass_wxEventTableEntryBase::AddVar_wxEventTableEntryBase_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxEventTableEntryBase::wxEventTableEntryBase(int winid, int idLast, wxObjectEventFunction fn, wxObject * data)
//---------------------------------------------------
void WrapClass_wxEventTableEntryBase::
    wrap_wxEventTableEntryBase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'idLast'")
  ADDPARAMCOMMENT_TYPE( wxObjectEventFunction, "parameter named 'fn'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEventTableEntryBase::
    wrap_wxEventTableEntryBase_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int winid;
  if (!get_val_param<int >(winid,_p,_n,true,true)) ClassReturnEmptyVar;

  int idLast;
  if (!get_val_param<int >(idLast,_p,_n,true,true)) ClassReturnEmptyVar;

  wxObjectEventFunction fn;
  if (!get_val_param<wxObjectEventFunction >(fn,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxObject > data_smtptr;
  if (!get_val_smtptr_param<wxObject >(data_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxObject* data = data_smtptr.get();

  wxEventTableEntryBase* _newobj = new wxEventTableEntryBase(winid, idLast, fn, data);
  BasicVariable::ptr res = WrapClass_wxEventTableEntryBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxEventTableEntryBase::wxEventTableEntryBase(...)
//---------------------------------------------------
void WrapClass_wxEventTableEntryBase::
    wrap_wxEventTableEntryBase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEventTableEntryBase::
    wrap_wxEventTableEntryBase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxEventTableEntryBase::wrap_wxEventTableEntryBase_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxEventTableEntryBase::wrap_wxEventTableEntryBase_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxEventTableEntryBase::wxEventTableEntryBase(wxEventTableEntryBase const & event)
//---------------------------------------------------
void WrapClass_wxEventTableEntryBase::
    wrap_wxEventTableEntryBase_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEventTableEntryBase, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEventTableEntryBase::
    wrap_wxEventTableEntryBase_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxEventTableEntryBase > event_smtptr;
  if (!get_val_smtptr_param<wxEventTableEntryBase >(event_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxEventTableEntryBase const & event = *event_smtptr;

  wxEventTableEntryBase* _newobj = new wxEventTableEntryBase(event);
  BasicVariable::ptr res = WrapClass_wxEventTableEntryBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxEventTableEntryBase.
//---------------------------------------------------
void WrapClass_wxEventTableEntryBase::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxEventTableEntryBase object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEventTableEntryBase::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxEventTableEntryBase >::CreateVar( new wxEventTableEntryBase(*(this->_objectptr->GetObj())));
}

