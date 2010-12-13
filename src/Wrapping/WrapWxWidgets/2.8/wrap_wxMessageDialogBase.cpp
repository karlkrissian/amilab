/**
 * C++ Interface: wrap_wxMessageDialogBase
 *
 * Description: wrapping wxMessageDialogBase
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

#include "wrap_wxMessageDialogBase.h"

// get all the required includes
// #include "..."
#ifndef wxMessageDialogBase_declared
  #define wxMessageDialogBase_declared
  AMI_DECLARE_TYPE(wxMessageDialogBase)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxMessageDialogBase>::CreateVar( ParamList* p)
{
  WrapClass_wxMessageDialogBase::wrap_wxMessageDialogBase construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxMessageDialogBase);
AMI_DEFINE_VARFROMSMTPTR(wxMessageDialogBase);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxMessageDialogBase
//
Variable<AMIObject>::ptr WrapClass_wxMessageDialogBase::CreateVar( wxMessageDialogBase* sp)
{
  boost::shared_ptr<wxMessageDialogBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxMessageDialogBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxMessageDialogBase>::CreateVar(
      new WrapClass_wxMessageDialogBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxMessageDialogBase::AddMethods(WrapClass<wxMessageDialogBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxMessageDialogBase_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxMessageDialogBase");
    WrapClass_wxMessageDialogBase::AddVar_wxMessageDialogBase_1(amiobject->GetContext());
  WrapClass_wxMessageDialogBase::AddVar_wxMessageDialogBase(amiobject->GetContext());
  WrapClass_wxMessageDialogBase::AddVar_wxMessageDialogBase_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxMessageDialogBase::wxMessageDialogBase(wxMessageDialogBase const & param0)
//---------------------------------------------------
void WrapClass_wxMessageDialogBase::
    wrap_wxMessageDialogBase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMessageDialogBase, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMessageDialogBase::
    wrap_wxMessageDialogBase_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMessageDialogBase > param0_smtptr;
  if (!get_val_smtptr_param<wxMessageDialogBase >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxMessageDialogBase const & param0 = *param0_smtptr;

  wxMessageDialogBase* _newobj = new wxMessageDialogBase(param0);
  BasicVariable::ptr res = WrapClass_wxMessageDialogBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxMessageDialogBase::wxMessageDialogBase(...)
//---------------------------------------------------
void WrapClass_wxMessageDialogBase::
    wrap_wxMessageDialogBase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMessageDialogBase::
    wrap_wxMessageDialogBase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMessageDialogBase::wrap_wxMessageDialogBase_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMessageDialogBase::wrap_wxMessageDialogBase_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxMessageDialogBase::wxMessageDialogBase()
//---------------------------------------------------
void WrapClass_wxMessageDialogBase::
    wrap_wxMessageDialogBase_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMessageDialogBase::
    wrap_wxMessageDialogBase_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxMessageDialogBase* _newobj = new wxMessageDialogBase();
  BasicVariable::ptr res = WrapClass_wxMessageDialogBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxMessageDialogBase.
//---------------------------------------------------
void WrapClass_wxMessageDialogBase::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxMessageDialogBase object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMessageDialogBase::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxMessageDialogBase >::CreateVar( new wxMessageDialogBase(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxMessageDialogBase & wxMessageDialogBase::operator =(wxMessageDialogBase const & param0)
//---------------------------------------------------
void WrapClass_wxMessageDialogBase::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMessageDialogBase, "parameter named 'param0'")
  return_comments="returning a variable of type wxMessageDialogBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMessageDialogBase::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMessageDialogBase > param0_smtptr;
  if (!get_val_smtptr_param<wxMessageDialogBase >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMessageDialogBase const & param0 = *param0_smtptr;

  wxMessageDialogBase & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxMessageDialogBase >::CreateVar(res);
}

