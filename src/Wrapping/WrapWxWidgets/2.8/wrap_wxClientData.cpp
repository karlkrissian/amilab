/**
 * C++ Interface: wrap_wxClientData
 *
 * Description: wrapping wxClientData
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

#include "wrap_wxClientData.h"

// get all the required includes
// #include "..."
#ifndef wxClientData_declared
  #define wxClientData_declared
  AMI_DECLARE_TYPE(wxClientData)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxClientData>::CreateVar( ParamList* p)
{
  WrapClass_wxClientData::wrap_wxClientData construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxClientData);
AMI_DEFINE_VARFROMSMTPTR(wxClientData);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxClientData
//
Variable<AMIObject>::ptr WrapClass_wxClientData::CreateVar( wxClientData* sp)
{
  boost::shared_ptr<wxClientData> di_ptr(
    sp,
    wxwindow_nodeleter<wxClientData>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxClientData>::CreateVar(
      new WrapClass_wxClientData(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxClientData::AddMethods(WrapClass<wxClientData>::ptr this_ptr )
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
void WrapClasswxClientData_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxClientData");
    WrapClass_wxClientData::AddVar_wxClientData_1(amiobject->GetContext());
  WrapClass_wxClientData::AddVar_wxClientData(amiobject->GetContext());
  WrapClass_wxClientData::AddVar_wxClientData_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxClientData::wxClientData(wxClientData const & param0)
//---------------------------------------------------
void WrapClass_wxClientData::
    wrap_wxClientData_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxClientData, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClientData::
    wrap_wxClientData_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxClientData > param0_smtptr;
  if (!get_val_smtptr_param<wxClientData >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxClientData const & param0 = *param0_smtptr;

  wxClientData* _newobj = new wxClientData(param0);
  BasicVariable::ptr res = WrapClass_wxClientData::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxClientData::wxClientData(...)
//---------------------------------------------------
void WrapClass_wxClientData::
    wrap_wxClientData::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClientData::
    wrap_wxClientData::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxClientData::wrap_wxClientData_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxClientData::wrap_wxClientData_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxClientData::wxClientData()
//---------------------------------------------------
void WrapClass_wxClientData::
    wrap_wxClientData_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClientData::
    wrap_wxClientData_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxClientData* _newobj = new wxClientData();
  BasicVariable::ptr res = WrapClass_wxClientData::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxClientData.
//---------------------------------------------------
void WrapClass_wxClientData::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxClientData object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClientData::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxClientData >::CreateVar( new wxClientData(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxClientData & wxClientData::operator =(wxClientData const & param0)
//---------------------------------------------------
void WrapClass_wxClientData::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxClientData, "parameter named 'param0'")
  return_comments="returning a variable of type wxClientData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClientData::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxClientData > param0_smtptr;
  if (!get_val_smtptr_param<wxClientData >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxClientData const & param0 = *param0_smtptr;

  wxClientData & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxClientData >::CreateVar(res);
}

