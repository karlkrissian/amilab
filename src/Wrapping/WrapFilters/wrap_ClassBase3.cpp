/**
 * C++ Interface: wrap_ClassBase3
 *
 * Description: wrapping ClassBase3
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_ClassBase3.h"

#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_ClassBase3.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<ClassBase3>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_ClassBase3::wrap_ClassBase3 construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(ClassBase3);
AMI_DEFINE_VARFROMSMTPTR(ClassBase3);


//
// static member for creating a variable from a pointer to ClassBase3
//
Variable<AMIObject>::ptr WrapClass_ClassBase3::CreateVar( ClassBase3* sp)
{
  boost::shared_ptr<ClassBase3> di_ptr(
    sp,
    wxwindow_nodeleter<ClassBase3>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<ClassBase3>::CreateVar(
      new WrapClass_ClassBase3(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor ClassBase3::ClassBase3(ClassBase3 const & param0)
//---------------------------------------------------
void WrapClass_ClassBase3::
    wrap_ClassBase3_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( ClassBase3, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase3::
    wrap_ClassBase3_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<ClassBase3 > param0_smtptr;
  if (!get_val_smtptr_param<ClassBase3 >(param0_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  ClassBase3 const & param0 = *param0_smtptr;

  ClassBase3* _newobj = new ClassBase3(param0);
  BasicVariable::ptr res = WrapClass_ClassBase3::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor ClassBase3::ClassBase3(...)
//---------------------------------------------------
void WrapClass_ClassBase3::
    wrap_ClassBase3::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase3::
    wrap_ClassBase3::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_ClassBase3::wrap_ClassBase3_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_ClassBase3::wrap_ClassBase3_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor ClassBase3::ClassBase3()
//---------------------------------------------------
void WrapClass_ClassBase3::
    wrap_ClassBase3_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase3::
    wrap_ClassBase3_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  ClassBase3* _newobj = new ClassBase3();
  BasicVariable::ptr res = WrapClass_ClassBase3::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for ClassBase3.
//---------------------------------------------------
void WrapClass_ClassBase3::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the ClassBase3 object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase3::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<ClassBase3 >::CreateVar( new ClassBase3(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void ClassBase3::Method3()
//---------------------------------------------------
void WrapClass_ClassBase3::
    wrap_Method3::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase3::
    wrap_Method3::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Method3();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of ClassBase3 & ClassBase3::=(ClassBase3 const & param0)
//---------------------------------------------------
void WrapClass_ClassBase3::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( ClassBase3, "parameter named 'param0'")
  return_comments="returning a variable of type ClassBase3";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase3::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<ClassBase3 > param0_smtptr;
  if (!get_val_smtptr_param<ClassBase3 >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  ClassBase3 const & param0 = *param0_smtptr;

  ClassBase3 & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<ClassBase3 >::CreateVar(res);
}

