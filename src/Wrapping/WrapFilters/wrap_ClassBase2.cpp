/**
 * C++ Interface: wrap_ClassBase2
 *
 * Description: wrapping ClassBase2
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_ClassBase2.h"

#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_ClassBase2.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<ClassBase2>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_ClassBase2::wrap_ClassBase2 construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(ClassBase2);
AMI_DEFINE_VARFROMSMTPTR(ClassBase2);


//
// static member for creating a variable from a pointer to ClassBase2
//
Variable<AMIObject>::ptr WrapClass_ClassBase2::CreateVar( ClassBase2* sp)
{
  boost::shared_ptr<ClassBase2> di_ptr(
    sp,
    wxwindow_nodeleter<ClassBase2>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<ClassBase2>::CreateVar(
      new WrapClass_ClassBase2(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor ClassBase2::ClassBase2(ClassBase2 const & param0)
//---------------------------------------------------
void WrapClass_ClassBase2::
    wrap_ClassBase2_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( ClassBase2, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase2::
    wrap_ClassBase2_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<ClassBase2 > param0_smtptr;
  if (!get_val_smtptr_param<ClassBase2 >(param0_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  ClassBase2 const & param0 = *param0_smtptr;

  ClassBase2* _newobj = new ClassBase2(param0);
  BasicVariable::ptr res = WrapClass_ClassBase2::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor ClassBase2::ClassBase2(...)
//---------------------------------------------------
void WrapClass_ClassBase2::
    wrap_ClassBase2::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase2::
    wrap_ClassBase2::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_ClassBase2::wrap_ClassBase2_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_ClassBase2::wrap_ClassBase2_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor ClassBase2::ClassBase2()
//---------------------------------------------------
void WrapClass_ClassBase2::
    wrap_ClassBase2_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase2::
    wrap_ClassBase2_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  ClassBase2* _newobj = new ClassBase2();
  BasicVariable::ptr res = WrapClass_ClassBase2::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for ClassBase2.
//---------------------------------------------------
void WrapClass_ClassBase2::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the ClassBase2 object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase2::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<ClassBase2 >::CreateVar( new ClassBase2(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void ClassBase2::Method2()
//---------------------------------------------------
void WrapClass_ClassBase2::
    wrap_Method2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase2::
    wrap_Method2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Method2();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of ClassBase2 & ClassBase2::=(ClassBase2 const & param0)
//---------------------------------------------------
void WrapClass_ClassBase2::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( ClassBase2, "parameter named 'param0'")
  return_comments="returning a variable of type ClassBase2";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase2::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<ClassBase2 > param0_smtptr;
  if (!get_val_smtptr_param<ClassBase2 >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  ClassBase2 const & param0 = *param0_smtptr;

  ClassBase2 & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<ClassBase2 >::CreateVar(res);
}

