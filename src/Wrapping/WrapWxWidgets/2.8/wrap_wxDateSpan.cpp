/**
 * C++ Interface: wrap_wxDateSpan
 *
 * Description: wrapping wxDateSpan
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

#include "wrap_wxDateSpan.h"

// get all the required includes
// #include "..."
#ifndef wxDateSpan_declared
  #define wxDateSpan_declared
  AMI_DECLARE_TYPE(wxDateSpan)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxDateSpan>::CreateVar( ParamList* p)
{
  WrapClass_wxDateSpan::wrap_wxDateSpan construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxDateSpan);
AMI_DEFINE_VARFROMSMTPTR(wxDateSpan);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxDateSpan
//
Variable<AMIObject>::ptr WrapClass_wxDateSpan::CreateVar( wxDateSpan* sp)
{
  boost::shared_ptr<wxDateSpan> di_ptr(
    sp,
    wxwindow_nodeleter<wxDateSpan>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxDateSpan>::CreateVar(
      new WrapClass_wxDateSpan(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxDateSpan::AddMethods(WrapClass<wxDateSpan>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_SetYears( this_ptr);
  AddVar_SetMonths( this_ptr);
  AddVar_SetWeeks( this_ptr);
  AddVar_SetDays( this_ptr);
  AddVar_GetYears( this_ptr);
  AddVar_GetMonths( this_ptr);
  AddVar_GetWeeks( this_ptr);
  AddVar_GetDays( this_ptr);
  AddVar_GetTotalDays( this_ptr);
  AddVar_Add_1( this_ptr);
  AddVar_Add( this_ptr);
  AddVar_Add_2( this_ptr);
  AddVar_Subtract_1( this_ptr);
  AddVar_Subtract( this_ptr);
  AddVar_Subtract_2( this_ptr);
  AddVar_Negate( this_ptr);
  AddVar_Neg( this_ptr);
  AddVar_Multiply_1( this_ptr);
  AddVar_Multiply( this_ptr);
  AddVar_Multiply_2( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);
  AddVar___add_assign__( this_ptr);
  AddVar___add__( this_ptr);
  AddVar___sub_assign__( this_ptr);
  AddVar___substract___1( this_ptr);
  AddVar___substract__( this_ptr);
  AddVar___substract___2( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  AddVar___equal__( this_ptr);
  AddVar___not_equal__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxDateSpan_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxDateSpan");
    WrapClass_wxDateSpan::AddVar_wxDateSpan_1(amiobject->GetContext());
  WrapClass_wxDateSpan::AddVar_wxDateSpan(amiobject->GetContext());
  WrapClass_wxDateSpan::AddVar_wxDateSpan_2(amiobject->GetContext());


  // Static methods 
  WrapClass_wxDateSpan::AddVar_Days(amiobject->GetContext());
  WrapClass_wxDateSpan::AddVar_Day(amiobject->GetContext());
  WrapClass_wxDateSpan::AddVar_Weeks(amiobject->GetContext());
  WrapClass_wxDateSpan::AddVar_Week(amiobject->GetContext());
  WrapClass_wxDateSpan::AddVar_Months(amiobject->GetContext());
  WrapClass_wxDateSpan::AddVar_Month(amiobject->GetContext());
  WrapClass_wxDateSpan::AddVar_Years(amiobject->GetContext());
  WrapClass_wxDateSpan::AddVar_Year(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxDateSpan::wxDateSpan(wxDateSpan const & param0)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_wxDateSpan_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_wxDateSpan_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateSpan > param0_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxDateSpan const & param0 = *param0_smtptr;

  wxDateSpan* _newobj = new wxDateSpan(param0);
  BasicVariable::ptr res = WrapClass_wxDateSpan::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxDateSpan::wxDateSpan(...)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_wxDateSpan::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_wxDateSpan::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDateSpan::wrap_wxDateSpan_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDateSpan::wrap_wxDateSpan_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxDateSpan::wxDateSpan(int years = 0, int months = 0, int weeks = 0, int days = 0)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_wxDateSpan_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'years' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'months' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weeks' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'days' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_wxDateSpan_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int years = 0;
  if (!get_val_param<int >(years,_p,_n,false,true)) ClassReturnEmptyVar;

  int months = 0;
  if (!get_val_param<int >(months,_p,_n,false,true)) ClassReturnEmptyVar;

  int weeks = 0;
  if (!get_val_param<int >(weeks,_p,_n,false,true)) ClassReturnEmptyVar;

  int days = 0;
  if (!get_val_param<int >(days,_p,_n,false,true)) ClassReturnEmptyVar;

  wxDateSpan* _newobj = new wxDateSpan(years, months, weeks, days);
  BasicVariable::ptr res = WrapClass_wxDateSpan::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxDateSpan wxDateSpan::Days(int days)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_static_Days::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'days'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_static_Days::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int days;
  if (!get_val_param<int >(days,_p,_n,true,false)) ClassHelpAndReturn;

  wxDateSpan res =   wxDateSpan::Days(days);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan wxDateSpan::Day()
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_static_Day::SetParametersComments()
{
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_static_Day::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDateSpan res =   wxDateSpan::Day();
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan wxDateSpan::Weeks(int weeks)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_static_Weeks::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weeks'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_static_Weeks::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int weeks;
  if (!get_val_param<int >(weeks,_p,_n,true,false)) ClassHelpAndReturn;

  wxDateSpan res =   wxDateSpan::Weeks(weeks);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan wxDateSpan::Week()
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_static_Week::SetParametersComments()
{
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_static_Week::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDateSpan res =   wxDateSpan::Week();
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan wxDateSpan::Months(int mon)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_static_Months::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'mon'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_static_Months::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int mon;
  if (!get_val_param<int >(mon,_p,_n,true,false)) ClassHelpAndReturn;

  wxDateSpan res =   wxDateSpan::Months(mon);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan wxDateSpan::Month()
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_static_Month::SetParametersComments()
{
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_static_Month::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDateSpan res =   wxDateSpan::Month();
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan wxDateSpan::Years(int years)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_static_Years::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'years'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_static_Years::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int years;
  if (!get_val_param<int >(years,_p,_n,true,false)) ClassHelpAndReturn;

  wxDateSpan res =   wxDateSpan::Years(years);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan wxDateSpan::Year()
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_static_Year::SetParametersComments()
{
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_static_Year::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDateSpan res =   wxDateSpan::Year();
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxDateSpan.
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxDateSpan object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxDateSpan >::CreateVar( new wxDateSpan(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxDateSpan & wxDateSpan::SetYears(int n)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_SetYears::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_SetYears::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,false)) ClassHelpAndReturn;

  wxDateSpan & res =   this->_objectptr->GetObj()->SetYears(n);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan & wxDateSpan::SetMonths(int n)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_SetMonths::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_SetMonths::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,false)) ClassHelpAndReturn;

  wxDateSpan & res =   this->_objectptr->GetObj()->SetMonths(n);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan & wxDateSpan::SetWeeks(int n)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_SetWeeks::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_SetWeeks::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,false)) ClassHelpAndReturn;

  wxDateSpan & res =   this->_objectptr->GetObj()->SetWeeks(n);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan & wxDateSpan::SetDays(int n)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_SetDays::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_SetDays::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,false)) ClassHelpAndReturn;

  wxDateSpan & res =   this->_objectptr->GetObj()->SetDays(n);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxDateSpan::GetYears()
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_GetYears::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_GetYears::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetYears();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxDateSpan::GetMonths()
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_GetMonths::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_GetMonths::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMonths();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxDateSpan::GetWeeks()
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_GetWeeks::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_GetWeeks::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetWeeks();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxDateSpan::GetDays()
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_GetDays::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_GetDays::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDays();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxDateSpan::GetTotalDays()
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_GetTotalDays::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_GetTotalDays::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetTotalDays();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan wxDateSpan::Add(wxDateSpan const & other)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_Add_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'other'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_Add_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateSpan > other_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(other_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDateSpan const & other = *other_smtptr;

  wxDateSpan res =   this->_objectptr->GetObj()->Add(other);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDateSpan::Add(...)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_Add::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_Add::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDateSpan::wrap_Add_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDateSpan::wrap_Add_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxDateSpan & wxDateSpan::Add(wxDateSpan const & other)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_Add_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'other'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_Add_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateSpan > other_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(other_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDateSpan const & other = *other_smtptr;

  wxDateSpan & res =   this->_objectptr->GetObj()->Add(other);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan wxDateSpan::Subtract(wxDateSpan const & other)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_Subtract_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'other'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_Subtract_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateSpan > other_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(other_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDateSpan const & other = *other_smtptr;

  wxDateSpan res =   this->_objectptr->GetObj()->Subtract(other);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDateSpan::Subtract(...)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_Subtract::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_Subtract::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDateSpan::wrap_Subtract_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDateSpan::wrap_Subtract_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxDateSpan & wxDateSpan::Subtract(wxDateSpan const & other)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_Subtract_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'other'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_Subtract_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateSpan > other_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(other_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDateSpan const & other = *other_smtptr;

  wxDateSpan & res =   this->_objectptr->GetObj()->Subtract(other);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan wxDateSpan::Negate()
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_Negate::SetParametersComments()
{
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_Negate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDateSpan res =   this->_objectptr->GetObj()->Negate();
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan & wxDateSpan::Neg()
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_Neg::SetParametersComments()
{
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_Neg::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDateSpan & res =   this->_objectptr->GetObj()->Neg();
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan wxDateSpan::Multiply(int factor)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_Multiply_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'factor'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_Multiply_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int factor;
  if (!get_val_param<int >(factor,_p,_n,true,true)) ClassReturnEmptyVar;

  wxDateSpan res =   this->_objectptr->GetObj()->Multiply(factor);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDateSpan::Multiply(...)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_Multiply::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_Multiply::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDateSpan::wrap_Multiply_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDateSpan::wrap_Multiply_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxDateSpan & wxDateSpan::Multiply(int factor)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_Multiply_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'factor'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_Multiply_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int factor;
  if (!get_val_param<int >(factor,_p,_n,true,true)) ClassReturnEmptyVar;

  wxDateSpan & res =   this->_objectptr->GetObj()->Multiply(factor);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan & wxDateSpan::operator =(wxDateSpan const & param0)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'param0'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateSpan > param0_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateSpan const & param0 = *param0_smtptr;

  wxDateSpan & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan & wxDateSpan::operator +=(wxDateSpan const & other)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap___add_assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'other'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap___add_assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateSpan > other_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(other_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateSpan const & other = *other_smtptr;

  wxDateSpan & res =   (*this->_objectptr->GetObj()) += (other);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan wxDateSpan::operator +(wxDateSpan const & ds)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap___add__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'ds'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap___add__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateSpan > ds_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(ds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateSpan const & ds = *ds_smtptr;

  wxDateSpan res =   (*this->_objectptr->GetObj()) + (ds);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan & wxDateSpan::operator -=(wxDateSpan const & other)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap___sub_assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'other'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap___sub_assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateSpan > other_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(other_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateSpan const & other = *other_smtptr;

  wxDateSpan & res =   (*this->_objectptr->GetObj()) -= (other);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateSpan wxDateSpan::operator -(wxDateSpan const & ds)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap___substract___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'ds'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap___substract___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateSpan > ds_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(ds_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDateSpan const & ds = *ds_smtptr;

  wxDateSpan res =   (*this->_objectptr->GetObj()) - (ds);
  return AMILabType<wxDateSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDateSpan::-(...)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap___substract__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap___substract__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDateSpan::wrap___substract___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDateSpan::wrap___substract___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxDateSpan & wxDateSpan::operator -()
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap___substract___2::SetParametersComments()
{
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap___substract___2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxDateSpan & res =  - (*this->_objectptr->GetObj());
  return AMILabType<wxDateSpan >::CreateVar(res);
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxDateSpan & wxDateSpan::*=(int factor)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'factor'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int factor;
  if (!get_val_param<int >(factor,_p,_n,true,false)) ClassHelpAndReturn;

  wxDateSpan & res =   this->_objectptr->GetObj()->*=(factor);
  return AMILabType<wxDateSpan >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxDateSpan wxDateSpan::*(int n)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  return_comments="returning a variable of type wxDateSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,false)) ClassHelpAndReturn;

  wxDateSpan res =   this->_objectptr->GetObj()->*(n);
  return AMILabType<wxDateSpan >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxDateSpan::operator ==(wxDateSpan const & ds)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap___equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'ds'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap___equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateSpan > ds_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(ds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateSpan const & ds = *ds_smtptr;

  bool res =   (*this->_objectptr->GetObj()) == (ds);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDateSpan::operator !=(wxDateSpan const & ds)
//---------------------------------------------------
void WrapClass_wxDateSpan::
    wrap___not_equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'ds'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateSpan::
    wrap___not_equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateSpan > ds_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(ds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateSpan const & ds = *ds_smtptr;

  bool res =   (*this->_objectptr->GetObj()) != (ds);
  return AMILabType<bool >::CreateVar(res);
}

