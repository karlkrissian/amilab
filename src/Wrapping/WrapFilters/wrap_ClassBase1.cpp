/**
 * C++ Interface: wrap_ClassBase1
 *
 * Description: wrapping ClassBase1
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_ClassBase1.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_ClassBase1.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<ClassBase1>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_ClassBase1::wrap_ClassBase1 construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(ClassBase1);
AMI_DEFINE_VARFROMSMTPTR(ClassBase1);


//
// static member for creating a variable from a pointer to ClassBase1
//
Variable<AMIObject>::ptr WrapClass_ClassBase1::CreateVar( ClassBase1* sp)
{
  boost::shared_ptr<ClassBase1> di_ptr(
    sp,
    wxwindow_nodeleter<ClassBase1>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<ClassBase1>::CreateVar(
      new WrapClass_ClassBase1(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor ClassBase1::ClassBase1(ClassBase1 const & param0)
//---------------------------------------------------
void WrapClass_ClassBase1::
    wrap_ClassBase1_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( ClassBase1, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase1::
    wrap_ClassBase1_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<ClassBase1 > param0_smtptr;
  if (!get_val_smtptr_param<ClassBase1 >(param0_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  ClassBase1 const & param0 = *param0_smtptr;

  ClassBase1* _newobj = new ClassBase1(param0);
  BasicVariable::ptr res = WrapClass_ClassBase1::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor ClassBase1::ClassBase1(...)
//---------------------------------------------------
void WrapClass_ClassBase1::
    wrap_ClassBase1::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase1::
    wrap_ClassBase1::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_ClassBase1::wrap_ClassBase1_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_ClassBase1::wrap_ClassBase1_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor ClassBase1::ClassBase1()
//---------------------------------------------------
void WrapClass_ClassBase1::
    wrap_ClassBase1_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase1::
    wrap_ClassBase1_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  ClassBase1* _newobj = new ClassBase1();
  BasicVariable::ptr res = WrapClass_ClassBase1::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for ClassBase1.
//---------------------------------------------------
void WrapClass_ClassBase1::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the ClassBase1 object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase1::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<ClassBase1 >::CreateVar( new ClassBase1(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void ClassBase1::Method1()
//---------------------------------------------------
void WrapClass_ClassBase1::
    wrap_Method1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase1::
    wrap_Method1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Method1();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of ClassBase1 & ClassBase1::=(ClassBase1 const & param0)
//---------------------------------------------------
void WrapClass_ClassBase1::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( ClassBase1, "parameter named 'param0'")
  return_comments="returning a variable of type ClassBase1";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ClassBase1::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<ClassBase1 > param0_smtptr;
  if (!get_val_smtptr_param<ClassBase1 >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  ClassBase1 const & param0 = *param0_smtptr;

  ClassBase1 & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<ClassBase1 >::CreateVar(res);
}

