/**
 * C++ Interface: wrap_TestClass
 *
 * Description: wrapping TestClass
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_TestClass.h"

#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_TestClass.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<TestClass>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_TestClass::wrap_TestClass construct;
  return construct.CallMember(p);
}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(TestClass);
AMI_DEFINE_VARFROMSMTPTR(TestClass);


//
// static member for creating a variable from a pointer to TestClass
//
Variable<AMIObject>::ptr WrapClass_TestClass::CreateVar( TestClass* sp)
{
  boost::shared_ptr<TestClass> di_ptr(
    sp,
    wxwindow_nodeleter<TestClass>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<TestClass>::CreateVar(
      new WrapClass_TestClass(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor TestClass::TestClass(TestClass const & param0)
//---------------------------------------------------
void WrapClass_TestClass::
    wrap_TestClass1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TestClass, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_TestClass::
    wrap_TestClass1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<TestClass> param0_smtptr;
  if (!get_val_smtptr_param<TestClass>(param0_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  TestClass const & param0 = *param0_smtptr;

  TestClass* _newobj = new TestClass(param0);
  BasicVariable::ptr res = WrapClass_TestClass::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor TestClass::TestClass(...)
//---------------------------------------------------
void WrapClass_TestClass::
    wrap_TestClass::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_TestClass::
    wrap_TestClass::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_TestClass::wrap_TestClass1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_TestClass::wrap_TestClass2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor TestClass::TestClass(int a)
//---------------------------------------------------
void WrapClass_TestClass::
    wrap_TestClass2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'a'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_TestClass::
    wrap_TestClass2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int a;
  if (!get_val_param<int>(a,_p,_n)) ClassReturnEmptyVar;

  TestClass* _newobj = new TestClass(a);
  BasicVariable::ptr res = WrapClass_TestClass::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for TestClass.
//---------------------------------------------------
void WrapClass_TestClass::
    wrap_copy::SetParametersComments()
{
  return_comments="A copy of the TestClass object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_TestClass::
    wrap_copy::CallMember( ParamList* _p)
{
    return AMILabType<TestClass>::CreateVar( new TestClass(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of int TestClass::GetVal()
//---------------------------------------------------
void WrapClass_TestClass::
    wrap_GetVal::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_TestClass::
    wrap_GetVal::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetVal();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void TestClass::SetVal(int const & v)
//---------------------------------------------------
void WrapClass_TestClass::
    wrap_SetVal::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_TestClass::
    wrap_SetVal::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int> v_smtptr;
  if (!get_val_smtptr_param<int>(v_smtptr,_p,_n)) ClassHelpAndReturn;
  int const & v = *v_smtptr;

  this->_objectptr->GetObj()->SetVal(v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void TestClass::SetComment(char const * c)
//---------------------------------------------------
void WrapClass_TestClass::
    wrap_SetComment::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_TestClass::
    wrap_SetComment::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string> c_string;
  if (!get_val_smtptr_param<std::string>(c_string,_p,_n)) ClassHelpAndReturn;
  char const * c = c_string->c_str();

  this->_objectptr->GetObj()->SetComment(c);
  return BasicVariable::ptr();
}
/* The following types are missing: basic_string<char,std::char_traits<char>,std::allocator<char> >

//---------------------------------------------------
//  Wrapping of string TestClass::GetComment()
//---------------------------------------------------
void WrapClass_TestClass::
    wrap_GetComment::SetParametersComments()
{
  return_comments="returning a variable of type basic_string<char,std::char_traits<char>,std::allocator<char> >";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_TestClass::
    wrap_GetComment::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  string res =   this->_objectptr->GetObj()->GetComment();
  return AMILabType<basic_string<char,std::char_traits<char>,std::allocator<char> >>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void TestClass::PrintComment()
//---------------------------------------------------
void WrapClass_TestClass::
    wrap_PrintComment::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_TestClass::
    wrap_PrintComment::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PrintComment();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of TestClass & TestClass::=(TestClass const & param0)
//---------------------------------------------------
void WrapClass_TestClass::
    wrap_assign::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TestClass, "parameter named 'param0'")
  return_comments="returning a variable of type TestClass";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_TestClass::
    wrap_assign::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TestClass> param0_smtptr;
  if (!get_val_smtptr_param<TestClass>(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  TestClass const & param0 = *param0_smtptr;

  TestClass & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<TestClass>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of TestClass TestClass::+(TestClass const & t2)
//---------------------------------------------------
void WrapClass_TestClass::
    wrap_add::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TestClass, "parameter named 't2'")
  return_comments="returning a variable of type TestClass";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_TestClass::
    wrap_add::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TestClass> t2_smtptr;
  if (!get_val_smtptr_param<TestClass>(t2_smtptr,_p,_n)) ClassHelpAndReturn;
  TestClass const & t2 = *t2_smtptr;

  TestClass res =   (*this->_objectptr->GetObj()) + (t2);
  return AMILabType<TestClass>::CreateVar(res);
}

