/**
 * C++ Interface: wrap_TemplateClass<int>
 *
 * Description: wrapping TemplateClass<int>
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_TemplateClass_int_.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_TemplateClass_int_.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<TemplateClass<int> >::CreateVar( ParamList* p)
{
  WrapClass_TemplateClass_int_::wrap_TemplateClass construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(TemplateClass<int>);
AMI_DEFINE_VARFROMSMTPTR_TEMPLATE2(TemplateClass<int>,TemplateClass_int_);


//
// static member for creating a variable from a pointer to TemplateClass<int>
//
Variable<AMIObject>::ptr WrapClass_TemplateClass_int_::CreateVar( TemplateClass<int>* sp)
{
  boost::shared_ptr<TemplateClass<int> > di_ptr(
    sp,
    wxwindow_nodeleter<TemplateClass<int> >()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<TemplateClass<int> >::CreateVar(
      new WrapClass_TemplateClass_int_(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor TemplateClass<int>::TemplateClass(TemplateClass<int> const & param0)
//---------------------------------------------------
void WrapClass_TemplateClass_int_::
    wrap_TemplateClass_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TemplateClass<int>, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_TemplateClass_int_::
    wrap_TemplateClass_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<TemplateClass<int> > param0_smtptr;
  if (!get_val_smtptr_param<TemplateClass<int> >(param0_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  TemplateClass<int> const & param0 = *param0_smtptr;

  TemplateClass<int>* _newobj = new TemplateClass<int>(param0);
  BasicVariable::ptr res = WrapClass_TemplateClass_int_::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor TemplateClass<int>::TemplateClass(...)
//---------------------------------------------------
void WrapClass_TemplateClass_int_::
    wrap_TemplateClass::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_TemplateClass_int_::
    wrap_TemplateClass::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_TemplateClass_int_::wrap_TemplateClass_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_TemplateClass_int_::wrap_TemplateClass_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor TemplateClass<int>::TemplateClass()
//---------------------------------------------------
void WrapClass_TemplateClass_int_::
    wrap_TemplateClass_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_TemplateClass_int_::
    wrap_TemplateClass_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  TemplateClass<int>* _newobj = new TemplateClass<int>();
  BasicVariable::ptr res = WrapClass_TemplateClass_int_::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for TemplateClass<int>.
//---------------------------------------------------
void WrapClass_TemplateClass_int_::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the TemplateClass<int> object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_TemplateClass_int_::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<TemplateClass<int> >::CreateVar( new TemplateClass<int>(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of TemplateClass<int> & TemplateClass<int>::=(TemplateClass<int> const & param0)
//---------------------------------------------------
void WrapClass_TemplateClass_int_::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TemplateClass<int>, "parameter named 'param0'")
  return_comments="returning a variable of type TemplateClass<int>";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_TemplateClass_int_::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TemplateClass<int> > param0_smtptr;
  if (!get_val_smtptr_param<TemplateClass<int> >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  TemplateClass<int> const & param0 = *param0_smtptr;

  TemplateClass<int> & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<TemplateClass<int> >::CreateVar(res);
}

