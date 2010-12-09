/**
 * C++ Interface: wrap_wxDateTime
 *
 * Description: wrapping wxDateTime
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxDateTime.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxLongLongNative.h"
#include "wrap_wxString.h"
#include "wrap_wxTimeSpan.h"
#include "wrap_wxDateSpan.h"
#include "stdlib.h"
#include "wchar.h"


#include "wrap_wxDateTime.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxDateTime>::CreateVar( ParamList* p)
{
  WrapClass_wxDateTime::wrap_wxDateTime construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxDateTime);
AMI_DEFINE_VARFROMSMTPTR(wxDateTime);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxDateTime
//
Variable<AMIObject>::ptr WrapClass_wxDateTime::CreateVar( wxDateTime* sp)
{
  boost::shared_ptr<wxDateTime> di_ptr(
    sp,
    wxwindow_nodeleter<wxDateTime>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxDateTime>::CreateVar(
      new WrapClass_wxDateTime(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxDateTime::AddMethods(WrapClass<wxDateTime>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_SetToCurrent( this_ptr);
  AddVar_Set_1( this_ptr);
  AddVar_Set( this_ptr);
/* The following types are missing: tm
  AddVar_Set_2( this_ptr);
*/
/* The following types are missing: Tm
  AddVar_Set_3( this_ptr);
*/
  AddVar_Set_4( this_ptr);
  AddVar_Set_5( this_ptr);
  AddVar_Set_6( this_ptr);
  AddVar_ResetTime( this_ptr);
  AddVar_GetDateOnly( this_ptr);
  AddVar_SetYear( this_ptr);
  AddVar_SetMonth( this_ptr);
  AddVar_SetDay( this_ptr);
  AddVar_SetHour( this_ptr);
  AddVar_SetMinute( this_ptr);
  AddVar_SetSecond( this_ptr);
  AddVar_SetMillisecond( this_ptr);
  AddVar_SetToWeekDayInSameWeek( this_ptr);
  AddVar_GetWeekDayInSameWeek( this_ptr);
  AddVar_SetToNextWeekDay( this_ptr);
  AddVar_GetNextWeekDay( this_ptr);
  AddVar_SetToPrevWeekDay( this_ptr);
  AddVar_GetPrevWeekDay( this_ptr);
  AddVar_SetToWeekDay( this_ptr);
  AddVar_GetWeekDay_1( this_ptr);
  AddVar_SetToLastWeekDay( this_ptr);
  AddVar_GetLastWeekDay( this_ptr);
  AddVar_SetToLastMonthDay( this_ptr);
  AddVar_GetLastMonthDay( this_ptr);
  AddVar_SetToYearDay( this_ptr);
  AddVar_GetYearDay( this_ptr);
  AddVar_GetJulianDayNumber( this_ptr);
  AddVar_GetJDN( this_ptr);
  AddVar_GetModifiedJulianDayNumber( this_ptr);
  AddVar_GetMJD( this_ptr);
  AddVar_GetRataDie( this_ptr);
/* The following types are missing: TimeZone
  AddVar_ToTimezone( this_ptr);
*/
/* The following types are missing: TimeZone
  AddVar_MakeTimezone( this_ptr);
*/
/* The following types are missing: TimeZone
  AddVar_FromTimezone( this_ptr);
*/
/* The following types are missing: TimeZone
  AddVar_MakeFromTimezone( this_ptr);
*/
  AddVar_ToUTC( this_ptr);
  AddVar_MakeUTC( this_ptr);
  AddVar_ToGMT( this_ptr);
  AddVar_MakeGMT( this_ptr);
  AddVar_FromUTC( this_ptr);
  AddVar_MakeFromUTC( this_ptr);
  AddVar_IsDST( this_ptr);
  AddVar_IsValid( this_ptr);
/* The following types are missing: Tm, TimeZone
  AddVar_GetTm( this_ptr);
*/
  AddVar_GetTicks( this_ptr);
/* The following types are missing: TimeZone
  AddVar_GetCentury( this_ptr);
*/
/* The following types are missing: TimeZone
  AddVar_GetYear( this_ptr);
*/
/* The following types are missing: TimeZone
  AddVar_GetMonth( this_ptr);
*/
/* The following types are missing: TimeZone
  AddVar_GetDay( this_ptr);
*/
  AddVar_GetWeekDay( this_ptr);
/* The following types are missing: TimeZone
  AddVar_GetWeekDay_2( this_ptr);
*/
/* The following types are missing: TimeZone
  AddVar_GetHour( this_ptr);
*/
/* The following types are missing: TimeZone
  AddVar_GetMinute( this_ptr);
*/
/* The following types are missing: TimeZone
  AddVar_GetSecond( this_ptr);
*/
/* The following types are missing: TimeZone
  AddVar_GetMillisecond( this_ptr);
*/
/* The following types are missing: TimeZone
  AddVar_GetDayOfYear( this_ptr);
*/
/* The following types are missing: TimeZone
  AddVar_GetWeekOfYear( this_ptr);
*/
/* The following types are missing: TimeZone
  AddVar_GetWeekOfMonth( this_ptr);
*/
  AddVar_IsWorkDay( this_ptr);
  AddVar_SetFromDOS( this_ptr);
  AddVar_GetAsDOS( this_ptr);
  AddVar_IsEqualTo( this_ptr);
  AddVar_IsEarlierThan( this_ptr);
  AddVar_IsLaterThan( this_ptr);
  AddVar_IsStrictlyBetween( this_ptr);
  AddVar_IsBetween( this_ptr);
  AddVar_IsSameDate( this_ptr);
  AddVar_IsSameTime( this_ptr);
  AddVar_IsEqualUpTo( this_ptr);
  AddVar_Add_1( this_ptr);
  AddVar_Add( this_ptr);
  AddVar_Add_2( this_ptr);
  AddVar_Subtract_1( this_ptr);
  AddVar_Subtract( this_ptr);
  AddVar_Subtract_2( this_ptr);
  AddVar_Add_3( this_ptr);
  AddVar_Add_4( this_ptr);
  AddVar_Subtract_3( this_ptr);
  AddVar_Subtract_4( this_ptr);
  AddVar_Subtract_5( this_ptr);
  AddVar_ParseRfc822Date( this_ptr);
  AddVar_ParseFormat( this_ptr);
  AddVar_ParseDateTime( this_ptr);
  AddVar_ParseDate( this_ptr);
  AddVar_ParseTime( this_ptr);
/* The following types are missing: TimeZone
  AddVar_Format( this_ptr);
*/
  AddVar_FormatDate( this_ptr);
  AddVar_FormatTime( this_ptr);
  AddVar_FormatISODate( this_ptr);
  AddVar_FormatISOTime( this_ptr);
  AddVar_GetValue( this_ptr);

  // Adding operators
  AddVar___assign___1( this_ptr);
  AddVar___assign__( this_ptr);
  AddVar___assign___2( this_ptr);
/* The following types are missing: tm
  AddVar___assign___3( this_ptr);
*/
/* The following types are missing: Tm
  AddVar___assign___4( this_ptr);
*/
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  AddVar___equal__( this_ptr);
  AddVar___not_equal__( this_ptr);
  AddVar___add_assign___1( this_ptr);
  AddVar___add___1( this_ptr);
  AddVar___sub_assign___1( this_ptr);
  AddVar___substract___1( this_ptr);
  AddVar___add_assign__( this_ptr);
  AddVar___add_assign___2( this_ptr);
  AddVar___add__( this_ptr);
  AddVar___add___2( this_ptr);
  AddVar___sub_assign__( this_ptr);
  AddVar___sub_assign___2( this_ptr);
  AddVar___substract__( this_ptr);
  AddVar___substract___2( this_ptr);
  AddVar___substract___3( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  
  AMIObject::ptr obj_TZ(new AMIObject);
  obj_TZ->SetName("TZ");

  BasicVariable::ptr var_Local = AMILabType<int >::CreateVar(0);
  if (var_Local.get()) {
    var_Local->Rename("Local");
    obj_TZ->GetContext()->AddVar(var_Local,obj_TZ->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_TZ->GetName().c_str(),obj_TZ,context);
  AMIObject::ptr obj_Calendar(new AMIObject);
  obj_Calendar->SetName("Calendar");

  BasicVariable::ptr var_Gregorian = AMILabType<int >::CreateVar(0);
  if (var_Gregorian.get()) {
    var_Gregorian->Rename("Gregorian");
    obj_Calendar->GetContext()->AddVar(var_Gregorian,obj_Calendar->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_Calendar->GetName().c_str(),obj_Calendar,context);
  AMIObject::ptr obj_GregorianAdoption(new AMIObject);
  obj_GregorianAdoption->SetName("GregorianAdoption");

  BasicVariable::ptr var_Gr_Unknown = AMILabType<int >::CreateVar(0);
  if (var_Gr_Unknown.get()) {
    var_Gr_Unknown->Rename("Gr_Unknown");
    obj_GregorianAdoption->GetContext()->AddVar(var_Gr_Unknown,obj_GregorianAdoption->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_GregorianAdoption->GetName().c_str(),obj_GregorianAdoption,context);
  AMIObject::ptr obj_Country(new AMIObject);
  obj_Country->SetName("Country");

  BasicVariable::ptr var_Country_Unknown = AMILabType<int >::CreateVar(0);
  if (var_Country_Unknown.get()) {
    var_Country_Unknown->Rename("Country_Unknown");
    obj_Country->GetContext()->AddVar(var_Country_Unknown,obj_Country->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_Country->GetName().c_str(),obj_Country,context);
  AMIObject::ptr obj_Month(new AMIObject);
  obj_Month->SetName("Month");

  BasicVariable::ptr var_Jan = AMILabType<int >::CreateVar(0);
  if (var_Jan.get()) {
    var_Jan->Rename("Jan");
    obj_Month->GetContext()->AddVar(var_Jan,obj_Month->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_Month->GetName().c_str(),obj_Month,context);
  AMIObject::ptr obj_WeekDay(new AMIObject);
  obj_WeekDay->SetName("WeekDay");

  BasicVariable::ptr var_Sun = AMILabType<int >::CreateVar(0);
  if (var_Sun.get()) {
    var_Sun->Rename("Sun");
    obj_WeekDay->GetContext()->AddVar(var_Sun,obj_WeekDay->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_WeekDay->GetName().c_str(),obj_WeekDay,context);
  AMIObject::ptr obj_Year(new AMIObject);
  obj_Year->SetName("Year");

  BasicVariable::ptr var_Inv_Year = AMILabType<int >::CreateVar(-32768);
  if (var_Inv_Year.get()) {
    var_Inv_Year->Rename("Inv_Year");
    obj_Year->GetContext()->AddVar(var_Inv_Year,obj_Year->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_Year->GetName().c_str(),obj_Year,context);
  AMIObject::ptr obj_NameFlags(new AMIObject);
  obj_NameFlags->SetName("NameFlags");

  BasicVariable::ptr var_Name_Full = AMILabType<int >::CreateVar(1);
  if (var_Name_Full.get()) {
    var_Name_Full->Rename("Name_Full");
    obj_NameFlags->GetContext()->AddVar(var_Name_Full,obj_NameFlags->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_NameFlags->GetName().c_str(),obj_NameFlags,context);
  AMIObject::ptr obj_WeekFlags(new AMIObject);
  obj_WeekFlags->SetName("WeekFlags");

  BasicVariable::ptr var_Default_First = AMILabType<int >::CreateVar(0);
  if (var_Default_First.get()) {
    var_Default_First->Rename("Default_First");
    obj_WeekFlags->GetContext()->AddVar(var_Default_First,obj_WeekFlags->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_WeekFlags->GetName().c_str(),obj_WeekFlags,context);


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxDateTime::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxDateTime");
    WrapClass_wxDateTime::AddVar_wxDateTime_1(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_wxDateTime(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_wxDateTime_2(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_wxDateTime_3(amiobject->GetContext());
  /* Types are missing
  WrapClass_wxDateTime::AddVar_wxDateTime_4(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_wxDateTime::AddVar_wxDateTime_5(amiobject->GetContext());
  */
  WrapClass_wxDateTime::AddVar_wxDateTime_6(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_wxDateTime_7(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_wxDateTime_8(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_wxDateTime_9(amiobject->GetContext());


  // Static methods 
  WrapClass_wxDateTime::AddVar_SetCountry(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_GetCountry(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_IsWestEuropeanCountry(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_GetCurrentYear(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_ConvertYearToBC(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_GetCurrentMonth(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_IsLeapYear(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_GetCentury(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_GetNumberOfDays_1(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_GetNumberOfDays(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_GetNumberOfDays_2(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_GetMonthName(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_GetWeekDayName(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_GetAmPmStrings(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_IsDSTApplicable(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_GetBeginDST(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_GetEndDST(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_Now(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_UNow(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_Today(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_SetToWeekOfYear(amiobject->GetContext());
  WrapClass_wxDateTime::AddVar_GetTimeNow(amiobject->GetContext());
  /* Types are missing
  WrapClass_wxDateTime::AddVar_GetTmNow_1(amiobject->GetContext());
  */
  WrapClass_wxDateTime::AddVar_GetTmNow(amiobject->GetContext());
  /* Types are missing
  WrapClass_wxDateTime::AddVar_GetTmNow_2(amiobject->GetContext());
  */

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxDateTime::wxDateTime(wxDateTime const & param0)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_wxDateTime_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_wxDateTime_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateTime > param0_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxDateTime const & param0 = *param0_smtptr;

  wxDateTime* _newobj = new wxDateTime(param0);
  BasicVariable::ptr res = WrapClass_wxDateTime::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxDateTime::wxDateTime(...)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_wxDateTime::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_wxDateTime::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDateTime::wrap_wxDateTime_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_wxDateTime_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_wxDateTime_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_wxDateTime_6 m6;
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_wxDateTime_7 m7;
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_wxDateTime_8 m8;
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_wxDateTime_9 m9;
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxDateTime::wxDateTime()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_wxDateTime_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_wxDateTime_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxDateTime* _newobj = new wxDateTime();
  BasicVariable::ptr res = WrapClass_wxDateTime::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxDateTime::wxDateTime(time_t timet)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_wxDateTime_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'timet'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_wxDateTime_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long timet_long;
  if (!get_val_param<long >(timet_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int timet = timet_long;

  wxDateTime* _newobj = new wxDateTime(timet);
  BasicVariable::ptr res = WrapClass_wxDateTime::CreateVar(_newobj);
  return res;
}
/* The following types are missing: tm

//---------------------------------------------------
//  Wrapping of Constructor wxDateTime::wxDateTime(tm const & tm)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_wxDateTime_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( tm, "parameter named 'tm'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_wxDateTime_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<tm > tm_smtptr;
  if (!get_val_smtptr_param<tm >(tm_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  tm const & tm = *tm_smtptr;

  wxDateTime* _newobj = new wxDateTime(tm);
  BasicVariable::ptr res = WrapClass_wxDateTime::CreateVar(_newobj);
  return res;
}
*/
/* The following types are missing: Tm

//---------------------------------------------------
//  Wrapping of Constructor wxDateTime::wxDateTime(Tm const & tm)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_wxDateTime_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( Tm, "parameter named 'tm'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_wxDateTime_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<Tm > tm_smtptr;
  if (!get_val_smtptr_param<Tm >(tm_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  Tm const & tm = *tm_smtptr;

  wxDateTime* _newobj = new wxDateTime(tm);
  BasicVariable::ptr res = WrapClass_wxDateTime::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxDateTime::wxDateTime(double jdn)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_wxDateTime_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'jdn'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_wxDateTime_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double jdn;
  if (!get_val_param<double >(jdn,_p,_n,true,true)) ClassReturnEmptyVar;

  wxDateTime* _newobj = new wxDateTime(jdn);
  BasicVariable::ptr res = WrapClass_wxDateTime::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxDateTime::wxDateTime(short unsigned int hour, short unsigned int minute = 0, short unsigned int second = 0, short unsigned int millisec = 0)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_wxDateTime_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'hour'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'minute' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'second' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'millisec' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_wxDateTime_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int hour_int;
  if (!get_val_param<int >(hour_int,_p,_n,true,true)) ClassReturnEmptyVar;
  short unsigned int hour = boost::numeric_cast<short unsigned int >(hour_int);

  int minute_int = boost::numeric_cast<int >((unsigned int)0);;
  if (!get_val_param<int >(minute_int,_p,_n,false,true)) ClassReturnEmptyVar;
  short unsigned int minute = boost::numeric_cast<short unsigned int >(minute_int);

  int second_int = boost::numeric_cast<int >((unsigned int)0);;
  if (!get_val_param<int >(second_int,_p,_n,false,true)) ClassReturnEmptyVar;
  short unsigned int second = boost::numeric_cast<short unsigned int >(second_int);

  int millisec_int = boost::numeric_cast<int >((unsigned int)0);;
  if (!get_val_param<int >(millisec_int,_p,_n,false,true)) ClassReturnEmptyVar;
  short unsigned int millisec = boost::numeric_cast<short unsigned int >(millisec_int);

  wxDateTime* _newobj = new wxDateTime(hour, minute, second, millisec);
  BasicVariable::ptr res = WrapClass_wxDateTime::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxDateTime::wxDateTime(short unsigned int day, wxDateTime::Month month, int year = wxDateTime::Inv_Year, short unsigned int hour = 0, short unsigned int minute = 0, short unsigned int second = 0, short unsigned int millisec = 0)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_wxDateTime_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'day'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'month'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year' (def:wxDateTime::Inv_Year)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'hour' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'minute' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'second' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'millisec' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_wxDateTime_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  int day_int;
  if (!get_val_param<int >(day_int,_p,_n,true,true)) ClassReturnEmptyVar;
  short unsigned int day = boost::numeric_cast<short unsigned int >(day_int);

  int month_int;
  if (!get_val_param<int >(month_int,_p,_n,true,true)) ClassReturnEmptyVar;
  wxDateTime::Month month = (wxDateTime::Month) month_int;

  int year = wxDateTime::Inv_Year;
  if (!get_val_param<int >(year,_p,_n,false,true)) ClassReturnEmptyVar;

  int hour_int = boost::numeric_cast<int >((unsigned int)0);;
  if (!get_val_param<int >(hour_int,_p,_n,false,true)) ClassReturnEmptyVar;
  short unsigned int hour = boost::numeric_cast<short unsigned int >(hour_int);

  int minute_int = boost::numeric_cast<int >((unsigned int)0);;
  if (!get_val_param<int >(minute_int,_p,_n,false,true)) ClassReturnEmptyVar;
  short unsigned int minute = boost::numeric_cast<short unsigned int >(minute_int);

  int second_int = boost::numeric_cast<int >((unsigned int)0);;
  if (!get_val_param<int >(second_int,_p,_n,false,true)) ClassReturnEmptyVar;
  short unsigned int second = boost::numeric_cast<short unsigned int >(second_int);

  int millisec_int = boost::numeric_cast<int >((unsigned int)0);;
  if (!get_val_param<int >(millisec_int,_p,_n,false,true)) ClassReturnEmptyVar;
  short unsigned int millisec = boost::numeric_cast<short unsigned int >(millisec_int);

  wxDateTime* _newobj = new wxDateTime(day, month, year, hour, minute, second, millisec);
  BasicVariable::ptr res = WrapClass_wxDateTime::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxDateTime::wxDateTime(wxLongLong const & time)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_wxDateTime_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'time'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_wxDateTime_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > time_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(time_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLong const & time = *time_smtptr;

  wxDateTime* _newobj = new wxDateTime(time);
  BasicVariable::ptr res = WrapClass_wxDateTime::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxDateTime::SetCountry(wxDateTime::Country country)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_SetCountry::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'country'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_SetCountry::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int country_int;
  if (!get_val_param<int >(country_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxDateTime::Country country = (wxDateTime::Country) country_int;

  wxDateTime::SetCountry(country);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxDateTime::Country wxDateTime::GetCountry()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_GetCountry::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_GetCountry::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDateTime::Country res =   wxDateTime::GetCountry();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxDateTime::IsWestEuropeanCountry(wxDateTime::Country country = wxDateTime::Country_Default)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_IsWestEuropeanCountry::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'country' (def:wxDateTime::Country_Default)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_IsWestEuropeanCountry::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int country_int = (int) wxDateTime::wxDateTime::Country_Default;;
  if (!get_val_param<int >(country_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::Country country = (wxDateTime::Country) country_int;

  bool res =   wxDateTime::IsWestEuropeanCountry(country);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxDateTime::GetCurrentYear(wxDateTime::Calendar cal = wxDateTime::Gregorian)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_GetCurrentYear::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cal' (def:wxDateTime::Gregorian)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_GetCurrentYear::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int cal_int = (int) wxDateTime::wxDateTime::Gregorian;;
  if (!get_val_param<int >(cal_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::Calendar cal = (wxDateTime::Calendar) cal_int;

  int res =   wxDateTime::GetCurrentYear(cal);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxDateTime::ConvertYearToBC(int year)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_ConvertYearToBC::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_ConvertYearToBC::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int year;
  if (!get_val_param<int >(year,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   wxDateTime::ConvertYearToBC(year);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime::Month wxDateTime::GetCurrentMonth(wxDateTime::Calendar cal = wxDateTime::Gregorian)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_GetCurrentMonth::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cal' (def:wxDateTime::Gregorian)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_GetCurrentMonth::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int cal_int = (int) wxDateTime::wxDateTime::Gregorian;;
  if (!get_val_param<int >(cal_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::Calendar cal = (wxDateTime::Calendar) cal_int;

  wxDateTime::Month res =   wxDateTime::GetCurrentMonth(cal);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxDateTime::IsLeapYear(int year = wxDateTime::Inv_Year, wxDateTime::Calendar cal = wxDateTime::Gregorian)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_IsLeapYear::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year' (def:wxDateTime::Inv_Year)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cal' (def:wxDateTime::Gregorian)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_IsLeapYear::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int year = wxDateTime::Inv_Year;
  if (!get_val_param<int >(year,_p,_n,false,false)) ClassHelpAndReturn;

  int cal_int = (int) wxDateTime::wxDateTime::Gregorian;;
  if (!get_val_param<int >(cal_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::Calendar cal = (wxDateTime::Calendar) cal_int;

  bool res =   wxDateTime::IsLeapYear(year, cal);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxDateTime::GetCentury(int year)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_GetCentury::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_GetCentury::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int year;
  if (!get_val_param<int >(year,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   wxDateTime::GetCentury(year);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of short unsigned int wxDateTime::GetNumberOfDays(int year, wxDateTime::Calendar cal = wxDateTime::Gregorian)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_GetNumberOfDays_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cal' (def:wxDateTime::Gregorian)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_GetNumberOfDays_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int year;
  if (!get_val_param<int >(year,_p,_n,true,true)) ClassReturnEmptyVar;

  int cal_int = (int) wxDateTime::wxDateTime::Gregorian;;
  if (!get_val_param<int >(cal_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxDateTime::Calendar cal = (wxDateTime::Calendar) cal_int;

  short unsigned int res =   wxDateTime::GetNumberOfDays(year, cal);
  int res_int = boost::numeric_cast<int >((unsigned int)res);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... static wxDateTime::GetNumberOfDays(...)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_GetNumberOfDays::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_GetNumberOfDays::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDateTime::wrap_static_GetNumberOfDays_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_static_GetNumberOfDays_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of short unsigned int wxDateTime::GetNumberOfDays(wxDateTime::Month month, int year = wxDateTime::Inv_Year, wxDateTime::Calendar cal = wxDateTime::Gregorian)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_GetNumberOfDays_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'month'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year' (def:wxDateTime::Inv_Year)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cal' (def:wxDateTime::Gregorian)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_GetNumberOfDays_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int month_int;
  if (!get_val_param<int >(month_int,_p,_n,true,true)) ClassReturnEmptyVar;
  wxDateTime::Month month = (wxDateTime::Month) month_int;

  int year = wxDateTime::Inv_Year;
  if (!get_val_param<int >(year,_p,_n,false,true)) ClassReturnEmptyVar;

  int cal_int = (int) wxDateTime::wxDateTime::Gregorian;;
  if (!get_val_param<int >(cal_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxDateTime::Calendar cal = (wxDateTime::Calendar) cal_int;

  short unsigned int res =   wxDateTime::GetNumberOfDays(month, year, cal);
  int res_int = boost::numeric_cast<int >((unsigned int)res);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxString wxDateTime::GetMonthName(wxDateTime::Month month, wxDateTime::NameFlags flags = wxDateTime::Name_Full)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_GetMonthName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'month'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:wxDateTime::Name_Full)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_GetMonthName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int month_int;
  if (!get_val_param<int >(month_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxDateTime::Month month = (wxDateTime::Month) month_int;

  int flags_int = (int) wxDateTime::wxDateTime::Name_Full;;
  if (!get_val_param<int >(flags_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::NameFlags flags = (wxDateTime::NameFlags) flags_int;

  wxString res =   wxDateTime::GetMonthName(month, flags);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxDateTime::GetWeekDayName(wxDateTime::WeekDay weekday, wxDateTime::NameFlags flags = wxDateTime::Name_Full)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_GetWeekDayName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weekday'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:wxDateTime::Name_Full)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_GetWeekDayName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int weekday_int;
  if (!get_val_param<int >(weekday_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxDateTime::WeekDay weekday = (wxDateTime::WeekDay) weekday_int;

  int flags_int = (int) wxDateTime::wxDateTime::Name_Full;;
  if (!get_val_param<int >(flags_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::NameFlags flags = (wxDateTime::NameFlags) flags_int;

  wxString res =   wxDateTime::GetWeekDayName(weekday, flags);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDateTime::GetAmPmStrings(wxString * am, wxString * pm)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_GetAmPmStrings::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'am'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'pm'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_GetAmPmStrings::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > am_smtptr;
  if (!get_val_smtptr_param<wxString >(am_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString* am = am_smtptr.get();

  boost::shared_ptr<wxString > pm_smtptr;
  if (!get_val_smtptr_param<wxString >(pm_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString* pm = pm_smtptr.get();

  wxDateTime::GetAmPmStrings(am, pm);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxDateTime::IsDSTApplicable(int year = wxDateTime::Inv_Year, wxDateTime::Country country = wxDateTime::Country_Default)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_IsDSTApplicable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year' (def:wxDateTime::Inv_Year)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'country' (def:wxDateTime::Country_Default)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_IsDSTApplicable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int year = wxDateTime::Inv_Year;
  if (!get_val_param<int >(year,_p,_n,false,false)) ClassHelpAndReturn;

  int country_int = (int) wxDateTime::wxDateTime::Country_Default;;
  if (!get_val_param<int >(country_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::Country country = (wxDateTime::Country) country_int;

  bool res =   wxDateTime::IsDSTApplicable(year, country);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::GetBeginDST(int year = wxDateTime::Inv_Year, wxDateTime::Country country = wxDateTime::Country_Default)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_GetBeginDST::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year' (def:wxDateTime::Inv_Year)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'country' (def:wxDateTime::Country_Default)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_GetBeginDST::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int year = wxDateTime::Inv_Year;
  if (!get_val_param<int >(year,_p,_n,false,false)) ClassHelpAndReturn;

  int country_int = (int) wxDateTime::wxDateTime::Country_Default;;
  if (!get_val_param<int >(country_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::Country country = (wxDateTime::Country) country_int;

  wxDateTime res =   wxDateTime::GetBeginDST(year, country);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::GetEndDST(int year = wxDateTime::Inv_Year, wxDateTime::Country country = wxDateTime::Country_Default)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_GetEndDST::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year' (def:wxDateTime::Inv_Year)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'country' (def:wxDateTime::Country_Default)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_GetEndDST::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int year = wxDateTime::Inv_Year;
  if (!get_val_param<int >(year,_p,_n,false,false)) ClassHelpAndReturn;

  int country_int = (int) wxDateTime::wxDateTime::Country_Default;;
  if (!get_val_param<int >(country_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::Country country = (wxDateTime::Country) country_int;

  wxDateTime res =   wxDateTime::GetEndDST(year, country);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::Now()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_Now::SetParametersComments()
{
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_Now::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDateTime res =   wxDateTime::Now();
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::UNow()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_UNow::SetParametersComments()
{
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_UNow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDateTime res =   wxDateTime::UNow();
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::Today()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_Today::SetParametersComments()
{
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_Today::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDateTime res =   wxDateTime::Today();
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::SetToWeekOfYear(int year, short unsigned int numWeek, wxDateTime::WeekDay weekday = wxDateTime::Mon)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_SetToWeekOfYear::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'numWeek'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weekday' (def:wxDateTime::Mon)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_SetToWeekOfYear::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int year;
  if (!get_val_param<int >(year,_p,_n,true,false)) ClassHelpAndReturn;

  int numWeek_int;
  if (!get_val_param<int >(numWeek_int,_p,_n,true,false)) ClassHelpAndReturn;
  short unsigned int numWeek = boost::numeric_cast<short unsigned int >(numWeek_int);

  int weekday_int = (int) wxDateTime::wxDateTime::Mon;;
  if (!get_val_param<int >(weekday_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::WeekDay weekday = (wxDateTime::WeekDay) weekday_int;

  wxDateTime res =   wxDateTime::SetToWeekOfYear(year, numWeek, weekday);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of time_t wxDateTime::GetTimeNow()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_GetTimeNow::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_GetTimeNow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  time_t res =   wxDateTime::GetTimeNow();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}
/* The following types are missing: tm

//---------------------------------------------------
//  Wrapping of tm * wxDateTime::GetTmNow()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_GetTmNow_1::SetParametersComments()
{
  return_comments="returning a variable of type tm";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_GetTmNow_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  tm * res =   wxDateTime::GetTmNow();
  return AMILabType<tm >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... static wxDateTime::GetTmNow(...)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_GetTmNow::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_GetTmNow::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: tm, tm

//---------------------------------------------------
//  Wrapping of tm * wxDateTime::GetTmNow(tm * tmstruct)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_static_GetTmNow_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( tm, "parameter named 'tmstruct'")
  return_comments="returning a variable of type tm";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_static_GetTmNow_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<tm > tmstruct_smtptr;
  if (!get_val_smtptr_param<tm >(tmstruct_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  tm* tmstruct = tmstruct_smtptr.get();

  tm * res =   wxDateTime::GetTmNow(tmstruct);
  return AMILabType<tm >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of 'copy' method for wxDateTime.
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxDateTime object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxDateTime >::CreateVar( new wxDateTime(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::SetToCurrent()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_SetToCurrent::SetParametersComments()
{
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_SetToCurrent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDateTime & res =   this->_objectptr->GetObj()->SetToCurrent();
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::Set(time_t timet)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Set_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'timet'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Set_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long timet_long;
  if (!get_val_param<long >(timet_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int timet = timet_long;

  wxDateTime & res =   this->_objectptr->GetObj()->Set(timet);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDateTime::Set(...)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Set::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Set::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDateTime::wrap_Set_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_Set_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_Set_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_Set_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: tm

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::Set(tm const & tm)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Set_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( tm, "parameter named 'tm'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Set_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<tm > tm_smtptr;
  if (!get_val_smtptr_param<tm >(tm_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  tm const & tm = *tm_smtptr;

  wxDateTime & res =   this->_objectptr->GetObj()->Set(tm);
  return AMILabType<wxDateTime >::CreateVar(res);
}
*/
/* The following types are missing: Tm

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::Set(Tm const & tm)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Set_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( Tm, "parameter named 'tm'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Set_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<Tm > tm_smtptr;
  if (!get_val_smtptr_param<Tm >(tm_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  Tm const & tm = *tm_smtptr;

  wxDateTime & res =   this->_objectptr->GetObj()->Set(tm);
  return AMILabType<wxDateTime >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::Set(double jdn)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Set_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'jdn'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Set_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double jdn;
  if (!get_val_param<double >(jdn,_p,_n,true,true)) ClassReturnEmptyVar;

  wxDateTime & res =   this->_objectptr->GetObj()->Set(jdn);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::Set(short unsigned int hour, short unsigned int minute = 0, short unsigned int second = 0, short unsigned int millisec = 0)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Set_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'hour'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'minute' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'second' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'millisec' (def:0)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Set_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int hour_int;
  if (!get_val_param<int >(hour_int,_p,_n,true,true)) ClassReturnEmptyVar;
  short unsigned int hour = boost::numeric_cast<short unsigned int >(hour_int);

  int minute_int = boost::numeric_cast<int >((unsigned int)0);;
  if (!get_val_param<int >(minute_int,_p,_n,false,true)) ClassReturnEmptyVar;
  short unsigned int minute = boost::numeric_cast<short unsigned int >(minute_int);

  int second_int = boost::numeric_cast<int >((unsigned int)0);;
  if (!get_val_param<int >(second_int,_p,_n,false,true)) ClassReturnEmptyVar;
  short unsigned int second = boost::numeric_cast<short unsigned int >(second_int);

  int millisec_int = boost::numeric_cast<int >((unsigned int)0);;
  if (!get_val_param<int >(millisec_int,_p,_n,false,true)) ClassReturnEmptyVar;
  short unsigned int millisec = boost::numeric_cast<short unsigned int >(millisec_int);

  wxDateTime & res =   this->_objectptr->GetObj()->Set(hour, minute, second, millisec);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::Set(short unsigned int day, wxDateTime::Month month, int year = wxDateTime::Inv_Year, short unsigned int hour = 0, short unsigned int minute = 0, short unsigned int second = 0, short unsigned int millisec = 0)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Set_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'day'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'month'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year' (def:wxDateTime::Inv_Year)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'hour' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'minute' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'second' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'millisec' (def:0)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Set_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  int day_int;
  if (!get_val_param<int >(day_int,_p,_n,true,true)) ClassReturnEmptyVar;
  short unsigned int day = boost::numeric_cast<short unsigned int >(day_int);

  int month_int;
  if (!get_val_param<int >(month_int,_p,_n,true,true)) ClassReturnEmptyVar;
  wxDateTime::Month month = (wxDateTime::Month) month_int;

  int year = wxDateTime::Inv_Year;
  if (!get_val_param<int >(year,_p,_n,false,true)) ClassReturnEmptyVar;

  int hour_int = boost::numeric_cast<int >((unsigned int)0);;
  if (!get_val_param<int >(hour_int,_p,_n,false,true)) ClassReturnEmptyVar;
  short unsigned int hour = boost::numeric_cast<short unsigned int >(hour_int);

  int minute_int = boost::numeric_cast<int >((unsigned int)0);;
  if (!get_val_param<int >(minute_int,_p,_n,false,true)) ClassReturnEmptyVar;
  short unsigned int minute = boost::numeric_cast<short unsigned int >(minute_int);

  int second_int = boost::numeric_cast<int >((unsigned int)0);;
  if (!get_val_param<int >(second_int,_p,_n,false,true)) ClassReturnEmptyVar;
  short unsigned int second = boost::numeric_cast<short unsigned int >(second_int);

  int millisec_int = boost::numeric_cast<int >((unsigned int)0);;
  if (!get_val_param<int >(millisec_int,_p,_n,false,true)) ClassReturnEmptyVar;
  short unsigned int millisec = boost::numeric_cast<short unsigned int >(millisec_int);

  wxDateTime & res =   this->_objectptr->GetObj()->Set(day, month, year, hour, minute, second, millisec);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::ResetTime()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_ResetTime::SetParametersComments()
{
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_ResetTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDateTime & res =   this->_objectptr->GetObj()->ResetTime();
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::GetDateOnly()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetDateOnly::SetParametersComments()
{
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetDateOnly::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDateTime res =   this->_objectptr->GetObj()->GetDateOnly();
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::SetYear(int year)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_SetYear::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_SetYear::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int year;
  if (!get_val_param<int >(year,_p,_n,true,false)) ClassHelpAndReturn;

  wxDateTime & res =   this->_objectptr->GetObj()->SetYear(year);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::SetMonth(wxDateTime::Month month)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_SetMonth::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'month'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_SetMonth::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int month_int;
  if (!get_val_param<int >(month_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxDateTime::Month month = (wxDateTime::Month) month_int;

  wxDateTime & res =   this->_objectptr->GetObj()->SetMonth(month);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::SetDay(short unsigned int day)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_SetDay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'day'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_SetDay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int day_int;
  if (!get_val_param<int >(day_int,_p,_n,true,false)) ClassHelpAndReturn;
  short unsigned int day = boost::numeric_cast<short unsigned int >(day_int);

  wxDateTime & res =   this->_objectptr->GetObj()->SetDay(day);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::SetHour(short unsigned int hour)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_SetHour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'hour'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_SetHour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int hour_int;
  if (!get_val_param<int >(hour_int,_p,_n,true,false)) ClassHelpAndReturn;
  short unsigned int hour = boost::numeric_cast<short unsigned int >(hour_int);

  wxDateTime & res =   this->_objectptr->GetObj()->SetHour(hour);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::SetMinute(short unsigned int minute)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_SetMinute::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'minute'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_SetMinute::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int minute_int;
  if (!get_val_param<int >(minute_int,_p,_n,true,false)) ClassHelpAndReturn;
  short unsigned int minute = boost::numeric_cast<short unsigned int >(minute_int);

  wxDateTime & res =   this->_objectptr->GetObj()->SetMinute(minute);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::SetSecond(short unsigned int second)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_SetSecond::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'second'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_SetSecond::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int second_int;
  if (!get_val_param<int >(second_int,_p,_n,true,false)) ClassHelpAndReturn;
  short unsigned int second = boost::numeric_cast<short unsigned int >(second_int);

  wxDateTime & res =   this->_objectptr->GetObj()->SetSecond(second);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::SetMillisecond(short unsigned int millisecond)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_SetMillisecond::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'millisecond'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_SetMillisecond::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int millisecond_int;
  if (!get_val_param<int >(millisecond_int,_p,_n,true,false)) ClassHelpAndReturn;
  short unsigned int millisecond = boost::numeric_cast<short unsigned int >(millisecond_int);

  wxDateTime & res =   this->_objectptr->GetObj()->SetMillisecond(millisecond);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::SetToWeekDayInSameWeek(wxDateTime::WeekDay weekday, wxDateTime::WeekFlags flags = wxDateTime::Monday_First)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_SetToWeekDayInSameWeek::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weekday'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:wxDateTime::Monday_First)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_SetToWeekDayInSameWeek::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int weekday_int;
  if (!get_val_param<int >(weekday_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxDateTime::WeekDay weekday = (wxDateTime::WeekDay) weekday_int;

  int flags_int = (int) wxDateTime::wxDateTime::Monday_First;;
  if (!get_val_param<int >(flags_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::WeekFlags flags = (wxDateTime::WeekFlags) flags_int;

  wxDateTime & res =   this->_objectptr->GetObj()->SetToWeekDayInSameWeek(weekday, flags);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::GetWeekDayInSameWeek(wxDateTime::WeekDay weekday, wxDateTime::WeekFlags param1 = wxDateTime::Monday_First)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetWeekDayInSameWeek::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weekday'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param1' (def:wxDateTime::Monday_First)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetWeekDayInSameWeek::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int weekday_int;
  if (!get_val_param<int >(weekday_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxDateTime::WeekDay weekday = (wxDateTime::WeekDay) weekday_int;

  int param1_int = (int) wxDateTime::wxDateTime::Monday_First;;
  if (!get_val_param<int >(param1_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::WeekFlags param1 = (wxDateTime::WeekFlags) param1_int;

  wxDateTime res =   this->_objectptr->GetObj()->GetWeekDayInSameWeek(weekday, param1);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::SetToNextWeekDay(wxDateTime::WeekDay weekday)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_SetToNextWeekDay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weekday'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_SetToNextWeekDay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int weekday_int;
  if (!get_val_param<int >(weekday_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxDateTime::WeekDay weekday = (wxDateTime::WeekDay) weekday_int;

  wxDateTime & res =   this->_objectptr->GetObj()->SetToNextWeekDay(weekday);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::GetNextWeekDay(wxDateTime::WeekDay weekday)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetNextWeekDay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weekday'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetNextWeekDay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int weekday_int;
  if (!get_val_param<int >(weekday_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxDateTime::WeekDay weekday = (wxDateTime::WeekDay) weekday_int;

  wxDateTime res =   this->_objectptr->GetObj()->GetNextWeekDay(weekday);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::SetToPrevWeekDay(wxDateTime::WeekDay weekday)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_SetToPrevWeekDay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weekday'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_SetToPrevWeekDay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int weekday_int;
  if (!get_val_param<int >(weekday_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxDateTime::WeekDay weekday = (wxDateTime::WeekDay) weekday_int;

  wxDateTime & res =   this->_objectptr->GetObj()->SetToPrevWeekDay(weekday);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::GetPrevWeekDay(wxDateTime::WeekDay weekday)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetPrevWeekDay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weekday'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetPrevWeekDay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int weekday_int;
  if (!get_val_param<int >(weekday_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxDateTime::WeekDay weekday = (wxDateTime::WeekDay) weekday_int;

  wxDateTime res =   this->_objectptr->GetObj()->GetPrevWeekDay(weekday);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDateTime::SetToWeekDay(wxDateTime::WeekDay weekday, int n = 1, wxDateTime::Month month = wxDateTime::Inv_Month, int year = wxDateTime::Inv_Year)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_SetToWeekDay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weekday'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n' (def:1)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'month' (def:wxDateTime::Inv_Month)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year' (def:wxDateTime::Inv_Year)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_SetToWeekDay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  int weekday_int;
  if (!get_val_param<int >(weekday_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxDateTime::WeekDay weekday = (wxDateTime::WeekDay) weekday_int;

  int n = 1;
  if (!get_val_param<int >(n,_p,_n,false,false)) ClassHelpAndReturn;

  int month_int = (int) wxDateTime::wxDateTime::Inv_Month;;
  if (!get_val_param<int >(month_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::Month month = (wxDateTime::Month) month_int;

  int year = wxDateTime::Inv_Year;
  if (!get_val_param<int >(year,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->SetToWeekDay(weekday, n, month, year);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::GetWeekDay(wxDateTime::WeekDay weekday, int n = 1, wxDateTime::Month month = wxDateTime::Inv_Month, int year = wxDateTime::Inv_Year)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetWeekDay_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weekday'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n' (def:1)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'month' (def:wxDateTime::Inv_Month)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year' (def:wxDateTime::Inv_Year)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetWeekDay_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int weekday_int;
  if (!get_val_param<int >(weekday_int,_p,_n,true,true)) ClassReturnEmptyVar;
  wxDateTime::WeekDay weekday = (wxDateTime::WeekDay) weekday_int;

  int n = 1;
  if (!get_val_param<int >(n,_p,_n,false,true)) ClassReturnEmptyVar;

  int month_int = (int) wxDateTime::wxDateTime::Inv_Month;;
  if (!get_val_param<int >(month_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxDateTime::Month month = (wxDateTime::Month) month_int;

  int year = wxDateTime::Inv_Year;
  if (!get_val_param<int >(year,_p,_n,false,true)) ClassReturnEmptyVar;

  wxDateTime res =   this->_objectptr->GetObj()->GetWeekDay(weekday, n, month, year);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDateTime::SetToLastWeekDay(wxDateTime::WeekDay weekday, wxDateTime::Month month = wxDateTime::Inv_Month, int year = wxDateTime::Inv_Year)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_SetToLastWeekDay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weekday'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'month' (def:wxDateTime::Inv_Month)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year' (def:wxDateTime::Inv_Year)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_SetToLastWeekDay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int weekday_int;
  if (!get_val_param<int >(weekday_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxDateTime::WeekDay weekday = (wxDateTime::WeekDay) weekday_int;

  int month_int = (int) wxDateTime::wxDateTime::Inv_Month;;
  if (!get_val_param<int >(month_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::Month month = (wxDateTime::Month) month_int;

  int year = wxDateTime::Inv_Year;
  if (!get_val_param<int >(year,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->SetToLastWeekDay(weekday, month, year);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::GetLastWeekDay(wxDateTime::WeekDay weekday, wxDateTime::Month month = wxDateTime::Inv_Month, int year = wxDateTime::Inv_Year)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetLastWeekDay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weekday'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'month' (def:wxDateTime::Inv_Month)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year' (def:wxDateTime::Inv_Year)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetLastWeekDay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int weekday_int;
  if (!get_val_param<int >(weekday_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxDateTime::WeekDay weekday = (wxDateTime::WeekDay) weekday_int;

  int month_int = (int) wxDateTime::wxDateTime::Inv_Month;;
  if (!get_val_param<int >(month_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::Month month = (wxDateTime::Month) month_int;

  int year = wxDateTime::Inv_Year;
  if (!get_val_param<int >(year,_p,_n,false,false)) ClassHelpAndReturn;

  wxDateTime res =   this->_objectptr->GetObj()->GetLastWeekDay(weekday, month, year);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::SetToLastMonthDay(wxDateTime::Month month = wxDateTime::Inv_Month, int year = wxDateTime::Inv_Year)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_SetToLastMonthDay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'month' (def:wxDateTime::Inv_Month)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year' (def:wxDateTime::Inv_Year)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_SetToLastMonthDay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int month_int = (int) wxDateTime::wxDateTime::Inv_Month;;
  if (!get_val_param<int >(month_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::Month month = (wxDateTime::Month) month_int;

  int year = wxDateTime::Inv_Year;
  if (!get_val_param<int >(year,_p,_n,false,false)) ClassHelpAndReturn;

  wxDateTime & res =   this->_objectptr->GetObj()->SetToLastMonthDay(month, year);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::GetLastMonthDay(wxDateTime::Month month = wxDateTime::Inv_Month, int year = wxDateTime::Inv_Year)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetLastMonthDay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'month' (def:wxDateTime::Inv_Month)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'year' (def:wxDateTime::Inv_Year)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetLastMonthDay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int month_int = (int) wxDateTime::wxDateTime::Inv_Month;;
  if (!get_val_param<int >(month_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::Month month = (wxDateTime::Month) month_int;

  int year = wxDateTime::Inv_Year;
  if (!get_val_param<int >(year,_p,_n,false,false)) ClassHelpAndReturn;

  wxDateTime res =   this->_objectptr->GetObj()->GetLastMonthDay(month, year);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::SetToYearDay(short unsigned int yday)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_SetToYearDay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yday'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_SetToYearDay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int yday_int;
  if (!get_val_param<int >(yday_int,_p,_n,true,false)) ClassHelpAndReturn;
  short unsigned int yday = boost::numeric_cast<short unsigned int >(yday_int);

  wxDateTime & res =   this->_objectptr->GetObj()->SetToYearDay(yday);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::GetYearDay(short unsigned int yday)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetYearDay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yday'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetYearDay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int yday_int;
  if (!get_val_param<int >(yday_int,_p,_n,true,false)) ClassHelpAndReturn;
  short unsigned int yday = boost::numeric_cast<short unsigned int >(yday_int);

  wxDateTime res =   this->_objectptr->GetObj()->GetYearDay(yday);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double wxDateTime::GetJulianDayNumber()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetJulianDayNumber::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetJulianDayNumber::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetJulianDayNumber();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double wxDateTime::GetJDN()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetJDN::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetJDN::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetJDN();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double wxDateTime::GetModifiedJulianDayNumber()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetModifiedJulianDayNumber::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetModifiedJulianDayNumber::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetModifiedJulianDayNumber();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double wxDateTime::GetMJD()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetMJD::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetMJD::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetMJD();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double wxDateTime::GetRataDie()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetRataDie::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetRataDie::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetRataDie();
  return AMILabType<double >::CreateVar(res);
}
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::ToTimezone(TimeZone const & tz, bool noDST = false)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_ToTimezone::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'noDST' (def:false)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_ToTimezone::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  TimeZone const & tz = *tz_smtptr;

  bool noDST = false;
  if (!get_val_param<bool >(noDST,_p,_n,false,false)) ClassHelpAndReturn;

  wxDateTime res =   this->_objectptr->GetObj()->ToTimezone(tz, noDST);
  return AMILabType<wxDateTime >::CreateVar(res);
}
*/
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::MakeTimezone(TimeZone const & tz, bool noDST = false)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_MakeTimezone::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'noDST' (def:false)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_MakeTimezone::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  TimeZone const & tz = *tz_smtptr;

  bool noDST = false;
  if (!get_val_param<bool >(noDST,_p,_n,false,false)) ClassHelpAndReturn;

  wxDateTime & res =   this->_objectptr->GetObj()->MakeTimezone(tz, noDST);
  return AMILabType<wxDateTime >::CreateVar(res);
}
*/
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::FromTimezone(TimeZone const & tz, bool noDST = false)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_FromTimezone::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'noDST' (def:false)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_FromTimezone::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  TimeZone const & tz = *tz_smtptr;

  bool noDST = false;
  if (!get_val_param<bool >(noDST,_p,_n,false,false)) ClassHelpAndReturn;

  wxDateTime res =   this->_objectptr->GetObj()->FromTimezone(tz, noDST);
  return AMILabType<wxDateTime >::CreateVar(res);
}
*/
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::MakeFromTimezone(TimeZone const & tz, bool noDST = false)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_MakeFromTimezone::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'noDST' (def:false)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_MakeFromTimezone::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  TimeZone const & tz = *tz_smtptr;

  bool noDST = false;
  if (!get_val_param<bool >(noDST,_p,_n,false,false)) ClassHelpAndReturn;

  wxDateTime & res =   this->_objectptr->GetObj()->MakeFromTimezone(tz, noDST);
  return AMILabType<wxDateTime >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::ToUTC(bool noDST = false)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_ToUTC::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'noDST' (def:false)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_ToUTC::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool noDST = false;
  if (!get_val_param<bool >(noDST,_p,_n,false,false)) ClassHelpAndReturn;

  wxDateTime res =   this->_objectptr->GetObj()->ToUTC(noDST);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::MakeUTC(bool noDST = false)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_MakeUTC::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'noDST' (def:false)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_MakeUTC::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool noDST = false;
  if (!get_val_param<bool >(noDST,_p,_n,false,false)) ClassHelpAndReturn;

  wxDateTime & res =   this->_objectptr->GetObj()->MakeUTC(noDST);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::ToGMT(bool noDST = false)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_ToGMT::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'noDST' (def:false)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_ToGMT::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool noDST = false;
  if (!get_val_param<bool >(noDST,_p,_n,false,false)) ClassHelpAndReturn;

  wxDateTime res =   this->_objectptr->GetObj()->ToGMT(noDST);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::MakeGMT(bool noDST = false)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_MakeGMT::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'noDST' (def:false)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_MakeGMT::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool noDST = false;
  if (!get_val_param<bool >(noDST,_p,_n,false,false)) ClassHelpAndReturn;

  wxDateTime & res =   this->_objectptr->GetObj()->MakeGMT(noDST);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::FromUTC(bool noDST = false)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_FromUTC::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'noDST' (def:false)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_FromUTC::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool noDST = false;
  if (!get_val_param<bool >(noDST,_p,_n,false,false)) ClassHelpAndReturn;

  wxDateTime res =   this->_objectptr->GetObj()->FromUTC(noDST);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::MakeFromUTC(bool noDST = false)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_MakeFromUTC::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'noDST' (def:false)")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_MakeFromUTC::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool noDST = false;
  if (!get_val_param<bool >(noDST,_p,_n,false,false)) ClassHelpAndReturn;

  wxDateTime & res =   this->_objectptr->GetObj()->MakeFromUTC(noDST);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxDateTime::IsDST(wxDateTime::Country country = wxDateTime::Country_Default)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_IsDST::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'country' (def:wxDateTime::Country_Default)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_IsDST::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int country_int = (int) wxDateTime::wxDateTime::Country_Default;;
  if (!get_val_param<int >(country_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::Country country = (wxDateTime::Country) country_int;

  int res =   this->_objectptr->GetObj()->IsDST(country);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDateTime::IsValid()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_IsValid::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_IsValid::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsValid();
  return AMILabType<bool >::CreateVar(res);
}
/* The following types are missing: Tm, TimeZone

//---------------------------------------------------
//  Wrapping of Tm wxDateTime::GetTm(TimeZone const & tz = wxDateTime::Local)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetTm::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz' (def:wxDateTime::Local)")
  return_comments="returning a variable of type Tm";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetTm::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  TimeZone const & tz = ( tz_smtptr.get() ? (*tz_smtptr) : TimeZone(wxDateTime::Local) );

  Tm res =   this->_objectptr->GetObj()->GetTm(tz);
  return AMILabType<Tm >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of time_t wxDateTime::GetTicks()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetTicks::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetTicks::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  time_t res =   this->_objectptr->GetObj()->GetTicks();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of int wxDateTime::GetCentury(TimeZone const & tz = wxDateTime::Local)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetCentury::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz' (def:wxDateTime::Local)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetCentury::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  TimeZone const & tz = ( tz_smtptr.get() ? (*tz_smtptr) : TimeZone(wxDateTime::Local) );

  int res =   this->_objectptr->GetObj()->GetCentury(tz);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of int wxDateTime::GetYear(TimeZone const & tz = wxDateTime::Local)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetYear::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz' (def:wxDateTime::Local)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetYear::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  TimeZone const & tz = ( tz_smtptr.get() ? (*tz_smtptr) : TimeZone(wxDateTime::Local) );

  int res =   this->_objectptr->GetObj()->GetYear(tz);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of wxDateTime::Month wxDateTime::GetMonth(TimeZone const & tz = wxDateTime::Local)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetMonth::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz' (def:wxDateTime::Local)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetMonth::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  TimeZone const & tz = ( tz_smtptr.get() ? (*tz_smtptr) : TimeZone(wxDateTime::Local) );

  wxDateTime::Month res =   this->_objectptr->GetObj()->GetMonth(tz);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}
*/
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of short unsigned int wxDateTime::GetDay(TimeZone const & tz = wxDateTime::Local)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetDay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz' (def:wxDateTime::Local)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetDay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  TimeZone const & tz = ( tz_smtptr.get() ? (*tz_smtptr) : TimeZone(wxDateTime::Local) );

  short unsigned int res =   this->_objectptr->GetObj()->GetDay(tz);
  int res_int = boost::numeric_cast<int >((unsigned int)res);
  return AMILabType<int >::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDateTime::GetWeekDay(...)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetWeekDay::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetWeekDay::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDateTime::wrap_GetWeekDay_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of wxDateTime::WeekDay wxDateTime::GetWeekDay(TimeZone const & tz = wxDateTime::Local)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetWeekDay_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz' (def:wxDateTime::Local)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetWeekDay_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  TimeZone const & tz = ( tz_smtptr.get() ? (*tz_smtptr) : TimeZone(wxDateTime::Local) );

  wxDateTime::WeekDay res =   this->_objectptr->GetObj()->GetWeekDay(tz);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}
*/
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of short unsigned int wxDateTime::GetHour(TimeZone const & tz = wxDateTime::Local)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetHour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz' (def:wxDateTime::Local)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetHour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  TimeZone const & tz = ( tz_smtptr.get() ? (*tz_smtptr) : TimeZone(wxDateTime::Local) );

  short unsigned int res =   this->_objectptr->GetObj()->GetHour(tz);
  int res_int = boost::numeric_cast<int >((unsigned int)res);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of short unsigned int wxDateTime::GetMinute(TimeZone const & tz = wxDateTime::Local)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetMinute::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz' (def:wxDateTime::Local)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetMinute::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  TimeZone const & tz = ( tz_smtptr.get() ? (*tz_smtptr) : TimeZone(wxDateTime::Local) );

  short unsigned int res =   this->_objectptr->GetObj()->GetMinute(tz);
  int res_int = boost::numeric_cast<int >((unsigned int)res);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of short unsigned int wxDateTime::GetSecond(TimeZone const & tz = wxDateTime::Local)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetSecond::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz' (def:wxDateTime::Local)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetSecond::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  TimeZone const & tz = ( tz_smtptr.get() ? (*tz_smtptr) : TimeZone(wxDateTime::Local) );

  short unsigned int res =   this->_objectptr->GetObj()->GetSecond(tz);
  int res_int = boost::numeric_cast<int >((unsigned int)res);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of short unsigned int wxDateTime::GetMillisecond(TimeZone const & tz = wxDateTime::Local)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetMillisecond::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz' (def:wxDateTime::Local)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetMillisecond::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  TimeZone const & tz = ( tz_smtptr.get() ? (*tz_smtptr) : TimeZone(wxDateTime::Local) );

  short unsigned int res =   this->_objectptr->GetObj()->GetMillisecond(tz);
  int res_int = boost::numeric_cast<int >((unsigned int)res);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of short unsigned int wxDateTime::GetDayOfYear(TimeZone const & tz = wxDateTime::Local)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetDayOfYear::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz' (def:wxDateTime::Local)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetDayOfYear::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  TimeZone const & tz = ( tz_smtptr.get() ? (*tz_smtptr) : TimeZone(wxDateTime::Local) );

  short unsigned int res =   this->_objectptr->GetObj()->GetDayOfYear(tz);
  int res_int = boost::numeric_cast<int >((unsigned int)res);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of short unsigned int wxDateTime::GetWeekOfYear(wxDateTime::WeekFlags flags = wxDateTime::Monday_First, TimeZone const & tz = wxDateTime::Local)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetWeekOfYear::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:wxDateTime::Monday_First)")
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz' (def:wxDateTime::Local)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetWeekOfYear::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int flags_int = (int) wxDateTime::wxDateTime::Monday_First;;
  if (!get_val_param<int >(flags_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::WeekFlags flags = (wxDateTime::WeekFlags) flags_int;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  TimeZone const & tz = ( tz_smtptr.get() ? (*tz_smtptr) : TimeZone(wxDateTime::Local) );

  short unsigned int res =   this->_objectptr->GetObj()->GetWeekOfYear(flags, tz);
  int res_int = boost::numeric_cast<int >((unsigned int)res);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of short unsigned int wxDateTime::GetWeekOfMonth(wxDateTime::WeekFlags flags = wxDateTime::Monday_First, TimeZone const & tz = wxDateTime::Local)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetWeekOfMonth::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:wxDateTime::Monday_First)")
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz' (def:wxDateTime::Local)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetWeekOfMonth::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int flags_int = (int) wxDateTime::wxDateTime::Monday_First;;
  if (!get_val_param<int >(flags_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::WeekFlags flags = (wxDateTime::WeekFlags) flags_int;

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  TimeZone const & tz = ( tz_smtptr.get() ? (*tz_smtptr) : TimeZone(wxDateTime::Local) );

  short unsigned int res =   this->_objectptr->GetObj()->GetWeekOfMonth(flags, tz);
  int res_int = boost::numeric_cast<int >((unsigned int)res);
  return AMILabType<int >::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxDateTime::IsWorkDay(wxDateTime::Country country = wxDateTime::Country_Default)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_IsWorkDay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'country' (def:wxDateTime::Country_Default)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_IsWorkDay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int country_int = (int) wxDateTime::wxDateTime::Country_Default;;
  if (!get_val_param<int >(country_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDateTime::Country country = (wxDateTime::Country) country_int;

  bool res =   this->_objectptr->GetObj()->IsWorkDay(country);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::SetFromDOS(long unsigned int ddt)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_SetFromDOS::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'ddt'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_SetFromDOS::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long ddt_long;
  if (!get_val_param<long >(ddt_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int ddt = boost::numeric_cast<long unsigned int >(ddt_long);

  wxDateTime & res =   this->_objectptr->GetObj()->SetFromDOS(ddt);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of long unsigned int wxDateTime::GetAsDOS()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetAsDOS::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetAsDOS::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetAsDOS();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxDateTime::IsEqualTo(wxDateTime const & datetime)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_IsEqualTo::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'datetime'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_IsEqualTo::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateTime > datetime_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(datetime_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateTime const & datetime = *datetime_smtptr;

  bool res =   this->_objectptr->GetObj()->IsEqualTo(datetime);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDateTime::IsEarlierThan(wxDateTime const & datetime)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_IsEarlierThan::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'datetime'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_IsEarlierThan::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateTime > datetime_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(datetime_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateTime const & datetime = *datetime_smtptr;

  bool res =   this->_objectptr->GetObj()->IsEarlierThan(datetime);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDateTime::IsLaterThan(wxDateTime const & datetime)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_IsLaterThan::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'datetime'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_IsLaterThan::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateTime > datetime_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(datetime_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateTime const & datetime = *datetime_smtptr;

  bool res =   this->_objectptr->GetObj()->IsLaterThan(datetime);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDateTime::IsStrictlyBetween(wxDateTime const & t1, wxDateTime const & t2)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_IsStrictlyBetween::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 't1'")
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 't2'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_IsStrictlyBetween::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateTime > t1_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(t1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateTime const & t1 = *t1_smtptr;

  boost::shared_ptr<wxDateTime > t2_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(t2_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateTime const & t2 = *t2_smtptr;

  bool res =   this->_objectptr->GetObj()->IsStrictlyBetween(t1, t2);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDateTime::IsBetween(wxDateTime const & t1, wxDateTime const & t2)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_IsBetween::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 't1'")
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 't2'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_IsBetween::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateTime > t1_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(t1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateTime const & t1 = *t1_smtptr;

  boost::shared_ptr<wxDateTime > t2_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(t2_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateTime const & t2 = *t2_smtptr;

  bool res =   this->_objectptr->GetObj()->IsBetween(t1, t2);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDateTime::IsSameDate(wxDateTime const & dt)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_IsSameDate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dt'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_IsSameDate::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateTime > dt_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(dt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateTime const & dt = *dt_smtptr;

  bool res =   this->_objectptr->GetObj()->IsSameDate(dt);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDateTime::IsSameTime(wxDateTime const & dt)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_IsSameTime::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dt'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_IsSameTime::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateTime > dt_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(dt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateTime const & dt = *dt_smtptr;

  bool res =   this->_objectptr->GetObj()->IsSameTime(dt);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDateTime::IsEqualUpTo(wxDateTime const & dt, wxTimeSpan const & ts)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_IsEqualUpTo::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dt'")
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'ts'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_IsEqualUpTo::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateTime > dt_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(dt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateTime const & dt = *dt_smtptr;

  boost::shared_ptr<wxTimeSpan > ts_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(ts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxTimeSpan const & ts = *ts_smtptr;

  bool res =   this->_objectptr->GetObj()->IsEqualUpTo(dt, ts);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::Add(wxTimeSpan const & diff)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Add_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Add_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxTimeSpan const & diff = *diff_smtptr;

  wxDateTime res =   this->_objectptr->GetObj()->Add(diff);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDateTime::Add(...)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Add::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Add::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDateTime::wrap_Add_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_Add_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_Add_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_Add_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::Add(wxTimeSpan const & diff)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Add_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Add_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxTimeSpan const & diff = *diff_smtptr;

  wxDateTime & res =   this->_objectptr->GetObj()->Add(diff);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::Subtract(wxTimeSpan const & diff)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Subtract_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Subtract_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxTimeSpan const & diff = *diff_smtptr;

  wxDateTime res =   this->_objectptr->GetObj()->Subtract(diff);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDateTime::Subtract(...)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Subtract::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Subtract::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDateTime::wrap_Subtract_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_Subtract_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_Subtract_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_Subtract_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap_Subtract_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::Subtract(wxTimeSpan const & diff)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Subtract_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Subtract_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxTimeSpan const & diff = *diff_smtptr;

  wxDateTime & res =   this->_objectptr->GetObj()->Subtract(diff);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::Add(wxDateSpan const & diff)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Add_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Add_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDateSpan const & diff = *diff_smtptr;

  wxDateTime res =   this->_objectptr->GetObj()->Add(diff);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::Add(wxDateSpan const & diff)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Add_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Add_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDateSpan const & diff = *diff_smtptr;

  wxDateTime & res =   this->_objectptr->GetObj()->Add(diff);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::Subtract(wxDateSpan const & diff)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Subtract_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Subtract_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDateSpan const & diff = *diff_smtptr;

  wxDateTime res =   this->_objectptr->GetObj()->Subtract(diff);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::Subtract(wxDateSpan const & diff)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Subtract_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Subtract_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDateSpan const & diff = *diff_smtptr;

  wxDateTime & res =   this->_objectptr->GetObj()->Subtract(diff);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxDateTime::Subtract(wxDateTime const & datetime)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Subtract_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'datetime'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Subtract_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateTime > datetime_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(datetime_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDateTime const & datetime = *datetime_smtptr;

  wxTimeSpan res =   this->_objectptr->GetObj()->Subtract(datetime);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxChar const * wxDateTime::ParseRfc822Date(wxChar const * date)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_ParseRfc822Date::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'date'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_ParseRfc822Date::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > date_string;
  if (!get_val_smtptr_param<std::string >(date_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  wchar_t date[date_string->size()+1];
mbstowcs(date,date_string->c_str(),date_string->size()+1);

  wxChar const * res =   this->_objectptr->GetObj()->ParseRfc822Date(date);
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxChar const * wxDateTime::ParseFormat(wxChar const * date, wxChar const * format = wxDefaultDateTimeFormat, wxDateTime const & dateDef = wxDefaultDateTime)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_ParseFormat::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'date'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'format' (def:wxDefaultDateTimeFormat)")
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dateDef' (def:wxDefaultDateTime)")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_ParseFormat::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > date_string;
  if (!get_val_smtptr_param<std::string >(date_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  wchar_t date[date_string->size()+1];
mbstowcs(date,date_string->c_str(),date_string->size()+1);

  boost::shared_ptr<std::string > format_string;
  if (!get_val_smtptr_param<std::string >(format_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  wchar_t format[format_string->size()+1];
mbstowcs(format,format_string->c_str(),format_string->size()+1);

  boost::shared_ptr<wxDateTime > dateDef_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(dateDef_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxDateTime const & dateDef = ( dateDef_smtptr.get() ? (*dateDef_smtptr) : wxDefaultDateTime );

  wxChar const * res =   this->_objectptr->GetObj()->ParseFormat(date, format, dateDef);
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxChar const * wxDateTime::ParseDateTime(wxChar const * datetime)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_ParseDateTime::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'datetime'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_ParseDateTime::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > datetime_string;
  if (!get_val_smtptr_param<std::string >(datetime_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  wchar_t datetime[datetime_string->size()+1];
mbstowcs(datetime,datetime_string->c_str(),datetime_string->size()+1);

  wxChar const * res =   this->_objectptr->GetObj()->ParseDateTime(datetime);
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxChar const * wxDateTime::ParseDate(wxChar const * date)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_ParseDate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'date'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_ParseDate::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > date_string;
  if (!get_val_smtptr_param<std::string >(date_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  wchar_t date[date_string->size()+1];
mbstowcs(date,date_string->c_str(),date_string->size()+1);

  wxChar const * res =   this->_objectptr->GetObj()->ParseDate(date);
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxChar const * wxDateTime::ParseTime(wxChar const * time)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_ParseTime::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'time'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_ParseTime::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > time_string;
  if (!get_val_smtptr_param<std::string >(time_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  wchar_t time[time_string->size()+1];
mbstowcs(time,time_string->c_str(),time_string->size()+1);

  wxChar const * res =   this->_objectptr->GetObj()->ParseTime(time);
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}
/* The following types are missing: TimeZone

//---------------------------------------------------
//  Wrapping of wxString wxDateTime::Format(wxChar const * format = wxDefaultDateTimeFormat, TimeZone const & tz = wxDateTime::Local)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_Format::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'format' (def:wxDefaultDateTimeFormat)")
  ADDPARAMCOMMENT_TYPE( TimeZone, "parameter named 'tz' (def:wxDateTime::Local)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_Format::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > format_string;
  if (!get_val_smtptr_param<std::string >(format_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  wchar_t format[format_string->size()+1];
mbstowcs(format,format_string->c_str(),format_string->size()+1);

  boost::shared_ptr<TimeZone > tz_smtptr;
  if (!get_val_smtptr_param<TimeZone >(tz_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  TimeZone const & tz = ( tz_smtptr.get() ? (*tz_smtptr) : TimeZone(wxDateTime::Local) );

  wxString res =   this->_objectptr->GetObj()->Format(format, tz);
  return AMILabType<wxString >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString wxDateTime::FormatDate()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_FormatDate::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_FormatDate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->FormatDate();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxDateTime::FormatTime()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_FormatTime::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_FormatTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->FormatTime();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxDateTime::FormatISODate()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_FormatISODate::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_FormatISODate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->FormatISODate();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxDateTime::FormatISOTime()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_FormatISOTime::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_FormatISOTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->FormatISOTime();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxLongLong wxDateTime::GetValue()
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_GetValue::SetParametersComments()
{
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_GetValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxLongLong res =   this->_objectptr->GetObj()->GetValue();
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::operator =(wxDateTime const & param0)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'param0'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateTime > param0_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(param0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDateTime const & param0 = *param0_smtptr;

  wxDateTime & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDateTime::=(...)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDateTime::wrap___assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap___assign___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::operator =(time_t timet)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'timet'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long timet_long;
  if (!get_val_param<long >(timet_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int timet = timet_long;

  wxDateTime & res =   (*this->_objectptr->GetObj()) = (timet);
  return AMILabType<wxDateTime >::CreateVar(res);
}
/*
 * The following types are missing: tm

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::operator =(tm const & tm)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___assign___3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( tm, "parameter named 'tm'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___assign___3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<tm > tm_smtptr;
  if (!get_val_smtptr_param<tm >(tm_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  tm const & tm = *tm_smtptr;

  wxDateTime & res =   (*this->_objectptr->GetObj()) = (tm);
  return AMILabType<wxDateTime >::CreateVar(res);
}
*/
/*
 * The following types are missing: Tm

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::operator =(Tm const & tm)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___assign___4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( Tm, "parameter named 'tm'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___assign___4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<Tm > tm_smtptr;
  if (!get_val_smtptr_param<Tm >(tm_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  Tm const & tm = *tm_smtptr;

  wxDateTime & res =   (*this->_objectptr->GetObj()) = (tm);
  return AMILabType<wxDateTime >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxDateTime::<(wxDateTime const & dt)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dt'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateTime > dt_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(dt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateTime const & dt = *dt_smtptr;

  bool res =   this->_objectptr->GetObj()-><(dt);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxDateTime::<=(wxDateTime const & dt)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dt'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateTime > dt_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(dt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateTime const & dt = *dt_smtptr;

  bool res =   this->_objectptr->GetObj()-><=(dt);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxDateTime::>(wxDateTime const & dt)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dt'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateTime > dt_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(dt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateTime const & dt = *dt_smtptr;

  bool res =   this->_objectptr->GetObj()->>(dt);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxDateTime::>=(wxDateTime const & dt)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dt'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateTime > dt_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(dt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateTime const & dt = *dt_smtptr;

  bool res =   this->_objectptr->GetObj()->>=(dt);
  return AMILabType<bool >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxDateTime::operator ==(wxDateTime const & dt)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dt'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateTime > dt_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(dt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateTime const & dt = *dt_smtptr;

  bool res =   (*this->_objectptr->GetObj()) == (dt);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDateTime::operator !=(wxDateTime const & dt)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___not_equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dt'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___not_equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDateTime > dt_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(dt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDateTime const & dt = *dt_smtptr;

  bool res =   (*this->_objectptr->GetObj()) != (dt);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::operator +=(wxTimeSpan const & diff)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___add_assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___add_assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxTimeSpan const & diff = *diff_smtptr;

  wxDateTime & res =   (*this->_objectptr->GetObj()) += (diff);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::operator +(wxTimeSpan const & ts)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___add___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'ts'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___add___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > ts_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(ts_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxTimeSpan const & ts = *ts_smtptr;

  wxDateTime res =   (*this->_objectptr->GetObj()) + (ts);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::operator -=(wxTimeSpan const & diff)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___sub_assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___sub_assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxTimeSpan const & diff = *diff_smtptr;

  wxDateTime & res =   (*this->_objectptr->GetObj()) -= (diff);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::operator -(wxTimeSpan const & ts)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___substract___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimeSpan, "parameter named 'ts'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___substract___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxTimeSpan > ts_smtptr;
  if (!get_val_smtptr_param<wxTimeSpan >(ts_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxTimeSpan const & ts = *ts_smtptr;

  wxDateTime res =   (*this->_objectptr->GetObj()) - (ts);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDateTime::+=(...)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___add_assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___add_assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDateTime::wrap___add_assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap___add_assign___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::operator +=(wxDateSpan const & diff)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___add_assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___add_assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDateSpan const & diff = *diff_smtptr;

  wxDateTime & res =   (*this->_objectptr->GetObj()) += (diff);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDateTime::+(...)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___add__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___add__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDateTime::wrap___add___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap___add___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::operator +(wxDateSpan const & ds)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___add___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'ds'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___add___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateSpan > ds_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(ds_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDateSpan const & ds = *ds_smtptr;

  wxDateTime res =   (*this->_objectptr->GetObj()) + (ds);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDateTime::-=(...)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___sub_assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___sub_assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDateTime::wrap___sub_assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap___sub_assign___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxDateTime & wxDateTime::operator -=(wxDateSpan const & diff)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___sub_assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'diff'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___sub_assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateSpan > diff_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(diff_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDateSpan const & diff = *diff_smtptr;

  wxDateTime & res =   (*this->_objectptr->GetObj()) -= (diff);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDateTime::-(...)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___substract__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___substract__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDateTime::wrap___substract___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap___substract___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxDateTime::wrap___substract___3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxDateTime::operator -(wxDateSpan const & ds)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___substract___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateSpan, "parameter named 'ds'")
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___substract___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateSpan > ds_smtptr;
  if (!get_val_smtptr_param<wxDateSpan >(ds_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDateSpan const & ds = *ds_smtptr;

  wxDateTime res =   (*this->_objectptr->GetObj()) - (ds);
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxTimeSpan wxDateTime::operator -(wxDateTime const & dt2)
//---------------------------------------------------
void WrapClass_wxDateTime::
    wrap___substract___3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dt2'")
  return_comments="returning a variable of type wxTimeSpan";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDateTime::
    wrap___substract___3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDateTime > dt2_smtptr;
  if (!get_val_smtptr_param<wxDateTime >(dt2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDateTime const & dt2 = *dt2_smtptr;

  wxTimeSpan res =   (*this->_objectptr->GetObj()) - (dt2);
  return AMILabType<wxTimeSpan >::CreateVar(res);
}

