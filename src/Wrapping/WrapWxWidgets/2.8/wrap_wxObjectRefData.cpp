/**
 * C++ Interface: wrap_wxObjectRefData
 *
 * Description: wrapping wxObjectRefData
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

#include "wrap_wxObjectRefData.h"

// get all the required includes
// #include "..."
#ifndef wxObjectRefData_declared
  #define wxObjectRefData_declared
  AMI_DECLARE_TYPE(wxObjectRefData)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxObjectRefData>::CreateVar( ParamList* p)
{
  WrapClass_wxObjectRefData::wrap_wxObjectRefData construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxObjectRefData);
AMI_DEFINE_VARFROMSMTPTR(wxObjectRefData);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxObjectRefData
//
Variable<AMIObject>::ptr WrapClass_wxObjectRefData::CreateVar( wxObjectRefData* sp)
{
  boost::shared_ptr<wxObjectRefData> di_ptr(
    sp,
    wxwindow_nodeleter<wxObjectRefData>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxObjectRefData>::CreateVar(
      new WrapClass_wxObjectRefData(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxObjectRefData::AddMethods(WrapClass<wxObjectRefData>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_GetRefCount( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxObjectRefData_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxObjectRefData");
    WrapClass_wxObjectRefData::AddVar_wxObjectRefData_1(amiobject->GetContext());
  WrapClass_wxObjectRefData::AddVar_wxObjectRefData(amiobject->GetContext());
  WrapClass_wxObjectRefData::AddVar_wxObjectRefData_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxObjectRefData::wxObjectRefData(wxObjectRefData const & param0)
//---------------------------------------------------
void WrapClass_wxObjectRefData::
    wrap_wxObjectRefData_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObjectRefData, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectRefData::
    wrap_wxObjectRefData_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxObjectRefData > param0_smtptr;
  if (!get_val_smtptr_param<wxObjectRefData >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxObjectRefData const & param0 = *param0_smtptr;

  wxObjectRefData* _newobj = new wxObjectRefData(param0);
  BasicVariable::ptr res = WrapClass_wxObjectRefData::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxObjectRefData::wxObjectRefData(...)
//---------------------------------------------------
void WrapClass_wxObjectRefData::
    wrap_wxObjectRefData::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectRefData::
    wrap_wxObjectRefData::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxObjectRefData::wrap_wxObjectRefData_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxObjectRefData::wrap_wxObjectRefData_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxObjectRefData::wxObjectRefData()
//---------------------------------------------------
void WrapClass_wxObjectRefData::
    wrap_wxObjectRefData_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectRefData::
    wrap_wxObjectRefData_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxObjectRefData* _newobj = new wxObjectRefData();
  BasicVariable::ptr res = WrapClass_wxObjectRefData::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxObjectRefData.
//---------------------------------------------------
void WrapClass_wxObjectRefData::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxObjectRefData object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectRefData::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxObjectRefData >::CreateVar( new wxObjectRefData(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of int wxObjectRefData::GetRefCount()
//---------------------------------------------------
void WrapClass_wxObjectRefData::
    wrap_GetRefCount::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectRefData::
    wrap_GetRefCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetRefCount();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxObjectRefData & wxObjectRefData::operator =(wxObjectRefData const & param0)
//---------------------------------------------------
void WrapClass_wxObjectRefData::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObjectRefData, "parameter named 'param0'")
  return_comments="returning a variable of type wxObjectRefData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectRefData::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxObjectRefData > param0_smtptr;
  if (!get_val_smtptr_param<wxObjectRefData >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxObjectRefData const & param0 = *param0_smtptr;

  wxObjectRefData & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxObjectRefData >::CreateVar(res);
}

