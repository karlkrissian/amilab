/**
 * C++ Interface: wrap_wxTimeSpan
 *
 * Description: wrapping wxTimeSpan
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

#include "wrap_wxTimeSpan.h"

// get all the required includes
// #include "..."
#include "stdlib.h"
#ifndef wxTimeSpan_declared
  #define wxTimeSpan_declared
  AMI_DECLARE_TYPE(wxTimeSpan)
#endif
#ifndef wxLongLongNative_declared
  #define wxLongLongNative_declared
  AMI_DECLARE_TYPE(wxLongLongNative)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxTimeSpan>::CreateVar( ParamList* p)
{
  WrapClass_wxTimeSpan::wrap_wxTimeSpan construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxTimeSpan);
AMI_DEFINE_VARFROMSMTPTR(wxTimeSpan);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxTimeSpan
//
Variable<AMIObject>::ptr WrapClass_wxTimeSpan::CreateVar( wxTimeSpan* sp)
{
  boost::shared_ptr<wxTimeSpan> di_ptr(
    sp,
    wxwindow_nodeleter<wxTimeSpan>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxTimeSpan>::CreateVar(
      new WrapClass_wxTimeSpan(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxTimeSpan::AddMethods(WrapClass<wxTimeSpan>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_Add_1( this_ptr);
  AddVar_Add( this_ptr);
  AddVar_Add_2( this_ptr);
  AddVar_Subtract_1( this_ptr);
  AddVar_Subtract( this_ptr);
  AddVar_Subtract_2( this_ptr);
  AddVar_Multiply_1( this_ptr);
  AddVar_Multiply( this_ptr);
  AddVar_Multiply_2( this_ptr);
  AddVar_Negate( this_ptr);
  AddVar_Neg( this_ptr);
  AddVar_Abs( this_ptr);
  AddVar_IsNull( this_ptr);
  AddVar_IsPositive( this_ptr);
  AddVar_IsNegative( this_ptr);
  AddVar_IsEqualTo( this_ptr);
  AddVar_IsLongerThan( this_ptr);
  AddVar_IsShorterThan( this_ptr);
  AddVar_GetWeeks( this_ptr);
  AddVar_GetDays( this_ptr);
  AddVar_GetHours( this_ptr);
  AddVar_GetMinutes( this_ptr);
  AddVar_GetSeconds( this_ptr);
  AddVar_GetMilliseconds( this_ptr);
  AddVar_Format( this_ptr);
  AddVar_GetValue( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);
  AddVar___add_assign__( this_ptr);
  AddVar___add__( this_ptr);
  AddVar___sub_assign__( this_ptr);
  AddVar___substract___1( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  AddVar___substract__( this_ptr);
  AddVar___substract___2( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  AddVar___equal__( this_ptr);
  AddVar___not_equal__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxTimeSpan_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxTimeSpan");
    WrapClass_wxTimeSpan::AddVar_wxTimeSpan_1(amiobject->GetContext());
  WrapClass_wxTimeSpan::AddVar_wxTimeSpan(amiobject->GetContext());
  WrapClass_wxTimeSpan::AddVar_wxTimeSpan_2(amiobject->GetContext());
  WrapClass_wxTimeSpan::AddVar_wxTimeSpan_3(amiobject->GetContext());
  WrapClass_wxTimeSpan::AddVar_wxTimeSpan_4(amiobject->GetContext());


  // Static methods 
  WrapClass_wxTimeSpan::AddVar_Milliseconds(amiobject->GetContext());
  WrapClass_wxTimeSpan::AddVar_Millisecond(amiobject->GetContext());
  WrapClass_wxTimeSpan::AddVar_Seconds(amiobject->GetContext());
  WrapClass_wxTimeSpan::AddVar_Second(amiobject->GetContext());
  WrapClass_wxTimeSpan::AddVar_Minutes(amiobject->GetContext());
  WrapClass_wxTimeSpan::AddVar_Minute(amiobject->GetContext());
  WrapClass_wxTimeSpan::AddVar_Hours(amiobject->GetContext());
  WrapClass_wxTimeSpan::AddVar_Hour(amiobject->GetContext());
  WrapClass_wxTimeSpan::AddVar_Days(amiobject->GetContext());
  WrapClass_wxTimeSpan::AddVar_Day(amiobject->GetContext());
  WrapClass_wxTimeSpan::AddVar_Weeks(amiobject->GetContext());
  WrapClass_wxTimeSpan::AddVar_Week(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxTimeSpan::wxTimeSpan(wxTimeSpan const & param0)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_wxTimeSpan_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_wxTimeSpan_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > param0_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxTimeSpan const & param0 = *param0_smtptr;

  wxTimeSpan* _newobj = new wxTimeSpan(param0);
  BasicVariable::ptr res = WrapClass_wxTimeSpan::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxTimeSpan::wxTimeSpan(...)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_wxTimeSpan::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_wxTimeSpan::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxTimeSpan::wrap_wxTimeSpan_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxTimeSpan::wrap_wxTimeSpan_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxTimeSpan::wrap_wxTimeSpan_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxTimeSpan::wrap_wxTimeSpan_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxTimeSpan::wxTimeSpan()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_wxTimeSpan_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_wxTimeSpan_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxTimeSpan* _newobj = new wxTimeSpan();
  BasicVariable::ptr res = WrapClass_wxTimeSpan::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxTimeSpan::wxTimeSpan(long int hours, long int minutes = 0, wxLongLong seconds = 0, wxLongLong milliseconds = 0)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_wxTimeSpan_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'hours'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'minutes' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'seconds' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'milliseconds' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_wxTimeSpan_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  long hours_long;
  if (!get_val_param<long >(hours_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int hours = hours_long;

  long minutes_long = 0;;
  if (!get_val_param<long >(minutes_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int minutes = minutes_long;

  wxLongLongNative seconds = 0;
  if (!get_val_param<wxLongLongNative >(seconds,_p,_n,false,true)) ClassReturnEmptyVar;

  wxLongLongNative milliseconds = 0;
  if (!get_val_param<wxLongLongNative >(milliseconds,_p,_n,false,true)) ClassReturnEmptyVar;

  wxTimeSpan* _newobj = new wxTimeSpan(hours, minutes, seconds, milliseconds);
  BasicVariable::ptr res = WrapClass_wxTimeSpan::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxTimeSpan::wxTimeSpan(wxLongLong const & diff)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_wxTimeSpan_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'diff'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_wxTimeSpan_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > diff_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLong const & diff = *diff_smtptr;

  wxTimeSpan* _newobj = new wxTimeSpan(diff);
  BasicVariable::ptr res = WrapClass_wxTimeSpan::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Milliseconds(wxLongLong ms)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_static_Milliseconds::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'ms'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_static_Milliseconds::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxLongLongNative ms;
  if (!get_val_param<wxLongLongNative >(ms,_p,_n,true,false)) ClassHelpAndReturn;

  wxTimeSpan res =   wxTimeSpan::Milliseconds(ms);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Millisecond()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_static_Millisecond::SetParametersComments()
{
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_static_Millisecond::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxTimeSpan res =   wxTimeSpan::Millisecond();
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Seconds(wxLongLong sec)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_static_Seconds::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'sec'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_static_Seconds::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxLongLongNative sec;
  if (!get_val_param<wxLongLongNative >(sec,_p,_n,true,false)) ClassHelpAndReturn;

  wxTimeSpan res =   wxTimeSpan::Seconds(sec);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Second()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_static_Second::SetParametersComments()
{
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_static_Second::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxTimeSpan res =   wxTimeSpan::Second();
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Minutes(long int min)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_static_Minutes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'min'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_static_Minutes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long min_long;
  if (!get_val_param<long >(min_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int min = min_long;

  wxTimeSpan res =   wxTimeSpan::Minutes(min);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Minute()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_static_Minute::SetParametersComments()
{
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_static_Minute::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxTimeSpan res =   wxTimeSpan::Minute();
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Hours(long int hours)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_static_Hours::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'hours'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_static_Hours::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long hours_long;
  if (!get_val_param<long >(hours_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int hours = hours_long;

  wxTimeSpan res =   wxTimeSpan::Hours(hours);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Hour()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_static_Hour::SetParametersComments()
{
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_static_Hour::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxTimeSpan res =   wxTimeSpan::Hour();
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Days(long int days)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_static_Days::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'days'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_static_Days::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long days_long;
  if (!get_val_param<long >(days_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int days = days_long;

  wxTimeSpan res =   wxTimeSpan::Days(days);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Day()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_static_Day::SetParametersComments()
{
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_static_Day::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxTimeSpan res =   wxTimeSpan::Day();
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Weeks(long int days)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_static_Weeks::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'days'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_static_Weeks::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long days_long;
  if (!get_val_param<long >(days_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int days = days_long;

  wxTimeSpan res =   wxTimeSpan::Weeks(days);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Week()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_static_Week::SetParametersComments()
{
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_static_Week::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxTimeSpan res =   wxTimeSpan::Week();
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxTimeSpan.
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxTimeSpan object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxTimeSpan >::CreateVar( new wxTimeSpan(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Add(wxTimeSpan const & diff)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_Add_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_Add_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxTimeSpan const & diff = *diff_smtptr;

  wxTimeSpan res =   this->_objectptr->GetObj()->Add(diff);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxTimeSpan::Add(...)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_Add::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_Add::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxTimeSpan::wrap_Add_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxTimeSpan::wrap_Add_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan & wxTimeSpan::Add(wxTimeSpan const & diff)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_Add_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_Add_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxTimeSpan const & diff = *diff_smtptr;

  wxTimeSpan & res =   this->_objectptr->GetObj()->Add(diff);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Subtract(wxTimeSpan const & diff)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_Subtract_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_Subtract_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxTimeSpan const & diff = *diff_smtptr;

  wxTimeSpan res =   this->_objectptr->GetObj()->Subtract(diff);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxTimeSpan::Subtract(...)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_Subtract::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_Subtract::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxTimeSpan::wrap_Subtract_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxTimeSpan::wrap_Subtract_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan & wxTimeSpan::Subtract(wxTimeSpan const & diff)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_Subtract_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_Subtract_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxTimeSpan const & diff = *diff_smtptr;

  wxTimeSpan & res =   this->_objectptr->GetObj()->Subtract(diff);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Multiply(int n)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_Multiply_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_Multiply_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,true)) ClassReturnEmptyVar;

  wxTimeSpan res =   this->_objectptr->GetObj()->Multiply(n);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxTimeSpan::Multiply(...)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_Multiply::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_Multiply::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxTimeSpan::wrap_Multiply_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxTimeSpan::wrap_Multiply_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan & wxTimeSpan::Multiply(int n)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_Multiply_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_Multiply_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,true)) ClassReturnEmptyVar;

  wxTimeSpan & res =   this->_objectptr->GetObj()->Multiply(n);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Negate()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_Negate::SetParametersComments()
{
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_Negate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxTimeSpan res =   this->_objectptr->GetObj()->Negate();
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan & wxTimeSpan::Neg()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_Neg::SetParametersComments()
{
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_Neg::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxTimeSpan & res =   this->_objectptr->GetObj()->Neg();
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::Abs()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_Abs::SetParametersComments()
{
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_Abs::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxTimeSpan res =   this->_objectptr->GetObj()->Abs();
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxTimeSpan::IsNull()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_IsNull::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_IsNull::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsNull();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxTimeSpan::IsPositive()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_IsPositive::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_IsPositive::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsPositive();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxTimeSpan::IsNegative()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_IsNegative::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_IsNegative::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsNegative();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxTimeSpan::IsEqualTo(wxTimeSpan const & ts)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_IsEqualTo::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'ts'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_IsEqualTo::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > ts_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(ts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxTimeSpan const & ts = *ts_smtptr;

  bool res =   this->_objectptr->GetObj()->IsEqualTo(ts);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxTimeSpan::IsLongerThan(wxTimeSpan const & ts)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_IsLongerThan::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'ts'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_IsLongerThan::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > ts_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(ts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxTimeSpan const & ts = *ts_smtptr;

  bool res =   this->_objectptr->GetObj()->IsLongerThan(ts);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxTimeSpan::IsShorterThan(wxTimeSpan const & t)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_IsShorterThan::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 't'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_IsShorterThan::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > t_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(t_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxTimeSpan const & t = *t_smtptr;

  bool res =   this->_objectptr->GetObj()->IsShorterThan(t);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxTimeSpan::GetWeeks()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_GetWeeks::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_GetWeeks::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetWeeks();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxTimeSpan::GetDays()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_GetDays::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_GetDays::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDays();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxTimeSpan::GetHours()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_GetHours::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_GetHours::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetHours();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxTimeSpan::GetMinutes()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_GetMinutes::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_GetMinutes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMinutes();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxLongLong wxTimeSpan::GetSeconds()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_GetSeconds::SetParametersComments()
{
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_GetSeconds::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxLongLong res =   this->_objectptr->GetObj()->GetSeconds();
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxLongLong wxTimeSpan::GetMilliseconds()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_GetMilliseconds::SetParametersComments()
{
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_GetMilliseconds::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxLongLong res =   this->_objectptr->GetObj()->GetMilliseconds();
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxTimeSpan::Format(wxChar const * format = wxDefaultTimeSpanFormat)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_Format::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'format' (def:wxDefaultTimeSpanFormat)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_Format::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > format_string;
  if (!get_val_smtptr_param<std::string >(format_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  wchar_t format[format_string->size()+1];
mbstowcs(format,format_string->c_str(),format_string->size()+1);

  wxString res =   this->_objectptr->GetObj()->Format(format);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxLongLong wxTimeSpan::GetValue()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_GetValue::SetParametersComments()
{
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_GetValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxLongLong res =   this->_objectptr->GetObj()->GetValue();
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan & wxTimeSpan::operator =(wxTimeSpan const & param0)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'param0'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > param0_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxTimeSpan const & param0 = *param0_smtptr;

  wxTimeSpan & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan & wxTimeSpan::operator +=(wxTimeSpan const & diff)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap___add_assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap___add_assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(diff_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxTimeSpan const & diff = *diff_smtptr;

  wxTimeSpan & res =   (*this->_objectptr->GetObj()) += (diff);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::operator +(wxTimeSpan const & ts)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap___add__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'ts'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap___add__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > ts_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(ts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxTimeSpan const & ts = *ts_smtptr;

  wxTimeSpan res =   (*this->_objectptr->GetObj()) + (ts);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan & wxTimeSpan::operator -=(wxTimeSpan const & diff)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap___sub_assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap___sub_assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(diff_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxTimeSpan const & diff = *diff_smtptr;

  wxTimeSpan & res =   (*this->_objectptr->GetObj()) -= (diff);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::operator -(wxTimeSpan const & ts)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap___substract___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'ts'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap___substract___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > ts_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(ts_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxTimeSpan const & ts = *ts_smtptr;

  wxTimeSpan res =   (*this->_objectptr->GetObj()) - (ts);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxTimeSpan & wxTimeSpan::*=(int n)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,false)) ClassHelpAndReturn;

  wxTimeSpan & res =   this->_objectptr->GetObj()->*=(n);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxTimeSpan::*(int n)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,false)) ClassHelpAndReturn;

  wxTimeSpan res =   this->_objectptr->GetObj()->*(n);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxTimeSpan::-(...)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap___substract__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap___substract__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxTimeSpan::wrap___substract___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxTimeSpan::wrap___substract___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan & wxTimeSpan::operator -()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap___substract___2::SetParametersComments()
{
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap___substract___2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxTimeSpan & res =  - (*this->_objectptr->GetObj());
  return AMILabType<wxTimeSpan >::CreateVar(res);
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxTimeSpan::!()
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_operator not available::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->!();
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxTimeSpan::<(wxTimeSpan const & ts)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'ts'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > ts_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(ts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxTimeSpan const & ts = *ts_smtptr;

  bool res =   this->_objectptr->GetObj()-><(ts);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxTimeSpan::<=(wxTimeSpan const & ts)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'ts'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > ts_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(ts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxTimeSpan const & ts = *ts_smtptr;

  bool res =   this->_objectptr->GetObj()-><=(ts);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxTimeSpan::>(wxTimeSpan const & ts)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'ts'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > ts_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(ts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxTimeSpan const & ts = *ts_smtptr;

  bool res =   this->_objectptr->GetObj()->>(ts);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxTimeSpan::>=(wxTimeSpan const & ts)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'ts'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > ts_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(ts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxTimeSpan const & ts = *ts_smtptr;

  bool res =   this->_objectptr->GetObj()->>=(ts);
  return AMILabType<bool >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxTimeSpan::operator ==(wxTimeSpan const & ts)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap___equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'ts'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap___equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > ts_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(ts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxTimeSpan const & ts = *ts_smtptr;

  bool res =   (*this->_objectptr->GetObj()) == (ts);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxTimeSpan::operator !=(wxTimeSpan const & ts)
//---------------------------------------------------
void WrapClass_wxTimeSpan::
    wrap___not_equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'ts'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTimeSpan::
    wrap___not_equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > ts_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(ts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxTimeSpan const & ts = *ts_smtptr;

  bool res =   (*this->_objectptr->GetObj()) != (ts);
  return AMILabType<bool >::CreateVar(res);
}

