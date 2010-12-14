/**
 * C++ Interface: wrap_wxDateTime
 *
 * Description: wrapping wxDateTime
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxDateTime_h_
#define _wrap_wxDateTime_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxDateTime_declared
  #define wxDateTime_declared
  AMI_DECLARE_TYPE(wxDateTime);
#endif

// TODO: check for inheritence ...
class WrapClass_wxDateTime : public WrapClass<wxDateTime>
    
{
  DEFINE_CLASS(WrapClass_wxDateTime);

  protected:
    typedef WrapClass<wxDateTime>::ptr _parentclass_ptr;
    typedef wxDateTime ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxDateTime>& GetObj() const { return WrapClass<wxDateTime>::GetObj(); }

    /// Constructor
    WrapClass_wxDateTime(boost::shared_ptr<wxDateTime > si): 
    WrapClass<wxDateTime>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxDateTime()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDateTime_1,"Constructor wxDateTime::wxDateTime(wxDateTime const & param0) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#wxdatetime).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDateTime,"Constructor wxDateTime::wxDateTime() (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#wxdatetime).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDateTime_2,"Constructor wxDateTime::wxDateTime() (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#wxdatetime).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDateTime_3,"Constructor wxDateTime::wxDateTime(time_t timet) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#wxdatetime).");
    /* The following types are missing: tm
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDateTime_4,"Constructor wxDateTime::wxDateTime(tm const & tm) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#wxdatetime).");
    */
    /* The following types are missing: Tm
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDateTime_5,"Constructor wxDateTime::wxDateTime(Tm const & tm) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#wxdatetime).");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDateTime_6,"Constructor wxDateTime::wxDateTime(double jdn) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#wxdatetime).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDateTime_7,"Constructor wxDateTime::wxDateTime(short unsigned int hour, short unsigned int minute = 0, short unsigned int second = 0, short unsigned int millisec = 0) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#wxdatetime).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDateTime_8,"Constructor wxDateTime::wxDateTime(short unsigned int day, wxDateTime::Month month, int year = wxDateTime::Inv_Year, short unsigned int hour = 0, short unsigned int minute = 0, short unsigned int second = 0, short unsigned int millisec = 0) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#wxdatetime).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDateTime_9,"Constructor wxDateTime::wxDateTime(wxLongLong const & time) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#wxdatetime).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxDateTime*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(SetCountry,"void wxDateTime::SetCountry(wxDateTime::Country country) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#setcountry).");
    ADD_CLASS_STATICMETHOD(GetCountry,"wxDateTime::Country wxDateTime::GetCountry() (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getcountry).");
    ADD_CLASS_STATICMETHOD(IsWestEuropeanCountry,"bool wxDateTime::IsWestEuropeanCountry(wxDateTime::Country country = wxDateTime::Country_Default) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#iswesteuropeancountry).");
    ADD_CLASS_STATICMETHOD(GetCurrentYear,"int wxDateTime::GetCurrentYear(wxDateTime::Calendar cal = wxDateTime::Gregorian) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getcurrentyear).");
    ADD_CLASS_STATICMETHOD(ConvertYearToBC,"int wxDateTime::ConvertYearToBC(int year) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#convertyeartobc).");
    ADD_CLASS_STATICMETHOD(GetCurrentMonth,"wxDateTime::Month wxDateTime::GetCurrentMonth(wxDateTime::Calendar cal = wxDateTime::Gregorian) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getcurrentmonth).");
    ADD_CLASS_STATICMETHOD(IsLeapYear,"bool wxDateTime::IsLeapYear(int year = wxDateTime::Inv_Year, wxDateTime::Calendar cal = wxDateTime::Gregorian) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#isleapyear).");
    ADD_CLASS_STATICMETHOD(GetCentury,"int wxDateTime::GetCentury(int year) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getcentury).");
    ADD_CLASS_STATICMETHOD(GetNumberOfDays_1,"short unsigned int wxDateTime::GetNumberOfDays(int year, wxDateTime::Calendar cal = wxDateTime::Gregorian) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getnumberofdays).");
    ADD_CLASS_STATICMETHOD(GetNumberOfDays,"wxDateTime::GetNumberOfDays() (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getnumberofdays).");
    ADD_CLASS_STATICMETHOD(GetNumberOfDays_2,"short unsigned int wxDateTime::GetNumberOfDays(wxDateTime::Month month, int year = wxDateTime::Inv_Year, wxDateTime::Calendar cal = wxDateTime::Gregorian) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getnumberofdays).");
    ADD_CLASS_STATICMETHOD(GetMonthName,"wxString wxDateTime::GetMonthName(wxDateTime::Month month, wxDateTime::NameFlags flags = wxDateTime::Name_Full) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getmonthname).");
    ADD_CLASS_STATICMETHOD(GetWeekDayName,"wxString wxDateTime::GetWeekDayName(wxDateTime::WeekDay weekday, wxDateTime::NameFlags flags = wxDateTime::Name_Full) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getweekdayname).");
    ADD_CLASS_STATICMETHOD(GetAmPmStrings,"void wxDateTime::GetAmPmStrings(wxString * am, wxString * pm) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getampmstrings).");
    ADD_CLASS_STATICMETHOD(IsDSTApplicable,"bool wxDateTime::IsDSTApplicable(int year = wxDateTime::Inv_Year, wxDateTime::Country country = wxDateTime::Country_Default) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#isdstapplicable).");
    ADD_CLASS_STATICMETHOD(GetBeginDST,"wxDateTime wxDateTime::GetBeginDST(int year = wxDateTime::Inv_Year, wxDateTime::Country country = wxDateTime::Country_Default) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getbegindst).");
    ADD_CLASS_STATICMETHOD(GetEndDST,"wxDateTime wxDateTime::GetEndDST(int year = wxDateTime::Inv_Year, wxDateTime::Country country = wxDateTime::Country_Default) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getenddst).");
    ADD_CLASS_STATICMETHOD(Now,"wxDateTime wxDateTime::Now() (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#now).");
    ADD_CLASS_STATICMETHOD(UNow,"wxDateTime wxDateTime::UNow() (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#unow).");
    ADD_CLASS_STATICMETHOD(Today,"wxDateTime wxDateTime::Today() (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#today).");
    ADD_CLASS_STATICMETHOD(SetToWeekOfYear,"wxDateTime wxDateTime::SetToWeekOfYear(int year, short unsigned int numWeek, wxDateTime::WeekDay weekday = wxDateTime::Mon) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#settoweekofyear).");
    ADD_CLASS_STATICMETHOD(GetTimeNow,"time_t wxDateTime::GetTimeNow() (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#gettimenow).");
    /* The following types are missing: tm
    ADD_CLASS_STATICMETHOD(GetTmNow_1,"tm * wxDateTime::GetTmNow() (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#gettmnow).");
    */
    ADD_CLASS_STATICMETHOD(GetTmNow,"wxDateTime::GetTmNow() (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#gettmnow).");
    /* The following types are missing: tm, tm
    ADD_CLASS_STATICMETHOD(GetTmNow_2,"tm * wxDateTime::GetTmNow(tm * tmstruct) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#gettmnow).");
    */



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(SetToCurrent,"wxDateTime & wxDateTime::SetToCurrent()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#settocurrent)")
    ADD_CLASS_METHOD(Set_1,"wxDateTime & wxDateTime::Set(time_t timet)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#set)")
    ADD_CLASS_METHOD(Set,"wxDateTime::Set()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#set)")
/* The following types are missing: tm
    ADD_CLASS_METHOD(Set_2,"wxDateTime & wxDateTime::Set(tm const & tm)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#set)")
*/
/* The following types are missing: Tm
    ADD_CLASS_METHOD(Set_3,"wxDateTime & wxDateTime::Set(Tm const & tm)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#set)")
*/
    ADD_CLASS_METHOD(Set_4,"wxDateTime & wxDateTime::Set(double jdn)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#set)")
    ADD_CLASS_METHOD(Set_5,"wxDateTime & wxDateTime::Set(short unsigned int hour, short unsigned int minute = 0, short unsigned int second = 0, short unsigned int millisec = 0)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#set)")
    ADD_CLASS_METHOD(Set_6,"wxDateTime & wxDateTime::Set(short unsigned int day, wxDateTime::Month month, int year = wxDateTime::Inv_Year, short unsigned int hour = 0, short unsigned int minute = 0, short unsigned int second = 0, short unsigned int millisec = 0)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#set)")
    ADD_CLASS_METHOD(ResetTime,"wxDateTime & wxDateTime::ResetTime()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#resettime)")
    ADD_CLASS_METHOD(GetDateOnly,"wxDateTime wxDateTime::GetDateOnly()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getdateonly)")
    ADD_CLASS_METHOD(SetYear,"wxDateTime & wxDateTime::SetYear(int year)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#setyear)")
    ADD_CLASS_METHOD(SetMonth,"wxDateTime & wxDateTime::SetMonth(wxDateTime::Month month)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#setmonth)")
    ADD_CLASS_METHOD(SetDay,"wxDateTime & wxDateTime::SetDay(short unsigned int day)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#setday)")
    ADD_CLASS_METHOD(SetHour,"wxDateTime & wxDateTime::SetHour(short unsigned int hour)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#sethour)")
    ADD_CLASS_METHOD(SetMinute,"wxDateTime & wxDateTime::SetMinute(short unsigned int minute)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#setminute)")
    ADD_CLASS_METHOD(SetSecond,"wxDateTime & wxDateTime::SetSecond(short unsigned int second)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#setsecond)")
    ADD_CLASS_METHOD(SetMillisecond,"wxDateTime & wxDateTime::SetMillisecond(short unsigned int millisecond)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#setmillisecond)")
    ADD_CLASS_METHOD(SetToWeekDayInSameWeek,"wxDateTime & wxDateTime::SetToWeekDayInSameWeek(wxDateTime::WeekDay weekday, wxDateTime::WeekFlags flags = wxDateTime::Monday_First)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#settoweekdayinsameweek)")
    ADD_CLASS_METHOD(GetWeekDayInSameWeek,"wxDateTime wxDateTime::GetWeekDayInSameWeek(wxDateTime::WeekDay weekday, wxDateTime::WeekFlags param1 = wxDateTime::Monday_First)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getweekdayinsameweek)")
    ADD_CLASS_METHOD(SetToNextWeekDay,"wxDateTime & wxDateTime::SetToNextWeekDay(wxDateTime::WeekDay weekday)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#settonextweekday)")
    ADD_CLASS_METHOD(GetNextWeekDay,"wxDateTime wxDateTime::GetNextWeekDay(wxDateTime::WeekDay weekday)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getnextweekday)")
    ADD_CLASS_METHOD(SetToPrevWeekDay,"wxDateTime & wxDateTime::SetToPrevWeekDay(wxDateTime::WeekDay weekday)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#settoprevweekday)")
    ADD_CLASS_METHOD(GetPrevWeekDay,"wxDateTime wxDateTime::GetPrevWeekDay(wxDateTime::WeekDay weekday)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getprevweekday)")
    ADD_CLASS_METHOD(SetToWeekDay,"bool wxDateTime::SetToWeekDay(wxDateTime::WeekDay weekday, int n = 1, wxDateTime::Month month = wxDateTime::Inv_Month, int year = wxDateTime::Inv_Year)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#settoweekday)")
    ADD_CLASS_METHOD(GetWeekDay_1,"wxDateTime wxDateTime::GetWeekDay(wxDateTime::WeekDay weekday, int n = 1, wxDateTime::Month month = wxDateTime::Inv_Month, int year = wxDateTime::Inv_Year)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getweekday)")
    ADD_CLASS_METHOD(SetToLastWeekDay,"bool wxDateTime::SetToLastWeekDay(wxDateTime::WeekDay weekday, wxDateTime::Month month = wxDateTime::Inv_Month, int year = wxDateTime::Inv_Year)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#settolastweekday)")
    ADD_CLASS_METHOD(GetLastWeekDay,"wxDateTime wxDateTime::GetLastWeekDay(wxDateTime::WeekDay weekday, wxDateTime::Month month = wxDateTime::Inv_Month, int year = wxDateTime::Inv_Year)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getlastweekday)")
    ADD_CLASS_METHOD(SetToLastMonthDay,"wxDateTime & wxDateTime::SetToLastMonthDay(wxDateTime::Month month = wxDateTime::Inv_Month, int year = wxDateTime::Inv_Year)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#settolastmonthday)")
    ADD_CLASS_METHOD(GetLastMonthDay,"wxDateTime wxDateTime::GetLastMonthDay(wxDateTime::Month month = wxDateTime::Inv_Month, int year = wxDateTime::Inv_Year)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getlastmonthday)")
    ADD_CLASS_METHOD(SetToYearDay,"wxDateTime & wxDateTime::SetToYearDay(short unsigned int yday)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#settoyearday)")
    ADD_CLASS_METHOD(GetYearDay,"wxDateTime wxDateTime::GetYearDay(short unsigned int yday)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getyearday)")
    ADD_CLASS_METHOD(GetJulianDayNumber,"double wxDateTime::GetJulianDayNumber()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getjuliandaynumber)")
    ADD_CLASS_METHOD(GetJDN,"double wxDateTime::GetJDN()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getjdn)")
    ADD_CLASS_METHOD(GetModifiedJulianDayNumber,"double wxDateTime::GetModifiedJulianDayNumber()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getmodifiedjuliandaynumber)")
    ADD_CLASS_METHOD(GetMJD,"double wxDateTime::GetMJD()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getmjd)")
    ADD_CLASS_METHOD(GetRataDie,"double wxDateTime::GetRataDie()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getratadie)")
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(ToTimezone,"wxDateTime wxDateTime::ToTimezone(TimeZone const & tz, bool noDST = false)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#totimezone)")
*/
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(MakeTimezone,"wxDateTime & wxDateTime::MakeTimezone(TimeZone const & tz, bool noDST = false)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#maketimezone)")
*/
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(FromTimezone,"wxDateTime wxDateTime::FromTimezone(TimeZone const & tz, bool noDST = false)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#fromtimezone)")
*/
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(MakeFromTimezone,"wxDateTime & wxDateTime::MakeFromTimezone(TimeZone const & tz, bool noDST = false)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#makefromtimezone)")
*/
    ADD_CLASS_METHOD(ToUTC,"wxDateTime wxDateTime::ToUTC(bool noDST = false)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#toutc)")
    ADD_CLASS_METHOD(MakeUTC,"wxDateTime & wxDateTime::MakeUTC(bool noDST = false)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#makeutc)")
    ADD_CLASS_METHOD(ToGMT,"wxDateTime wxDateTime::ToGMT(bool noDST = false)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#togmt)")
    ADD_CLASS_METHOD(MakeGMT,"wxDateTime & wxDateTime::MakeGMT(bool noDST = false)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#makegmt)")
    ADD_CLASS_METHOD(FromUTC,"wxDateTime wxDateTime::FromUTC(bool noDST = false)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#fromutc)")
    ADD_CLASS_METHOD(MakeFromUTC,"wxDateTime & wxDateTime::MakeFromUTC(bool noDST = false)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#makefromutc)")
    ADD_CLASS_METHOD(IsDST,"int wxDateTime::IsDST(wxDateTime::Country country = wxDateTime::Country_Default)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#isdst)")
    ADD_CLASS_METHOD(IsValid,"bool wxDateTime::IsValid()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#isvalid)")
/* The following types are missing: Tm, TimeZone
    ADD_CLASS_METHOD(GetTm,"Tm wxDateTime::GetTm(TimeZone const & tz = wxDateTime::Local)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#gettm)")
*/
    ADD_CLASS_METHOD(GetTicks,"time_t wxDateTime::GetTicks()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getticks)")
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(GetCentury,"int wxDateTime::GetCentury(TimeZone const & tz = wxDateTime::Local)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getcentury)")
*/
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(GetYear,"int wxDateTime::GetYear(TimeZone const & tz = wxDateTime::Local)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getyear)")
*/
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(GetMonth,"wxDateTime::Month wxDateTime::GetMonth(TimeZone const & tz = wxDateTime::Local)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getmonth)")
*/
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(GetDay,"short unsigned int wxDateTime::GetDay(TimeZone const & tz = wxDateTime::Local)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getday)")
*/
    ADD_CLASS_METHOD(GetWeekDay,"wxDateTime::GetWeekDay()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getweekday)")
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(GetWeekDay_2,"wxDateTime::WeekDay wxDateTime::GetWeekDay(TimeZone const & tz = wxDateTime::Local)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getweekday)")
*/
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(GetHour,"short unsigned int wxDateTime::GetHour(TimeZone const & tz = wxDateTime::Local)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#gethour)")
*/
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(GetMinute,"short unsigned int wxDateTime::GetMinute(TimeZone const & tz = wxDateTime::Local)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getminute)")
*/
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(GetSecond,"short unsigned int wxDateTime::GetSecond(TimeZone const & tz = wxDateTime::Local)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getsecond)")
*/
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(GetMillisecond,"short unsigned int wxDateTime::GetMillisecond(TimeZone const & tz = wxDateTime::Local)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getmillisecond)")
*/
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(GetDayOfYear,"short unsigned int wxDateTime::GetDayOfYear(TimeZone const & tz = wxDateTime::Local)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getdayofyear)")
*/
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(GetWeekOfYear,"short unsigned int wxDateTime::GetWeekOfYear(wxDateTime::WeekFlags flags = wxDateTime::Monday_First, TimeZone const & tz = wxDateTime::Local)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getweekofyear)")
*/
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(GetWeekOfMonth,"short unsigned int wxDateTime::GetWeekOfMonth(wxDateTime::WeekFlags flags = wxDateTime::Monday_First, TimeZone const & tz = wxDateTime::Local)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getweekofmonth)")
*/
    ADD_CLASS_METHOD(IsWorkDay,"bool wxDateTime::IsWorkDay(wxDateTime::Country country = wxDateTime::Country_Default)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#isworkday)")
    ADD_CLASS_METHOD(SetFromDOS,"wxDateTime & wxDateTime::SetFromDOS(long unsigned int ddt)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#setfromdos)")
    ADD_CLASS_METHOD(GetAsDOS,"long unsigned int wxDateTime::GetAsDOS()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getasdos)")
    ADD_CLASS_METHOD(IsEqualTo,"bool wxDateTime::IsEqualTo(wxDateTime const & datetime)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#isequalto)")
    ADD_CLASS_METHOD(IsEarlierThan,"bool wxDateTime::IsEarlierThan(wxDateTime const & datetime)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#isearlierthan)")
    ADD_CLASS_METHOD(IsLaterThan,"bool wxDateTime::IsLaterThan(wxDateTime const & datetime)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#islaterthan)")
    ADD_CLASS_METHOD(IsStrictlyBetween,"bool wxDateTime::IsStrictlyBetween(wxDateTime const & t1, wxDateTime const & t2)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#isstrictlybetween)")
    ADD_CLASS_METHOD(IsBetween,"bool wxDateTime::IsBetween(wxDateTime const & t1, wxDateTime const & t2)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#isbetween)")
    ADD_CLASS_METHOD(IsSameDate,"bool wxDateTime::IsSameDate(wxDateTime const & dt)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#issamedate)")
    ADD_CLASS_METHOD(IsSameTime,"bool wxDateTime::IsSameTime(wxDateTime const & dt)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#issametime)")
    ADD_CLASS_METHOD(IsEqualUpTo,"bool wxDateTime::IsEqualUpTo(wxDateTime const & dt, wxTimeSpan const & ts)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#isequalupto)")
    ADD_CLASS_METHOD(Add_1,"wxDateTime wxDateTime::Add(wxTimeSpan const & diff)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#add)")
    ADD_CLASS_METHOD(Add,"wxDateTime::Add()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#add)")
    ADD_CLASS_METHOD(Add_2,"wxDateTime & wxDateTime::Add(wxTimeSpan const & diff)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#add)")
    ADD_CLASS_METHOD(Subtract_1,"wxDateTime wxDateTime::Subtract(wxTimeSpan const & diff)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#subtract)")
    ADD_CLASS_METHOD(Subtract,"wxDateTime::Subtract()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#subtract)")
    ADD_CLASS_METHOD(Subtract_2,"wxDateTime & wxDateTime::Subtract(wxTimeSpan const & diff)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#subtract)")
    ADD_CLASS_METHOD(Add_3,"wxDateTime wxDateTime::Add(wxDateSpan const & diff)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#add)")
    ADD_CLASS_METHOD(Add_4,"wxDateTime & wxDateTime::Add(wxDateSpan const & diff)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#add)")
    ADD_CLASS_METHOD(Subtract_3,"wxDateTime wxDateTime::Subtract(wxDateSpan const & diff)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#subtract)")
    ADD_CLASS_METHOD(Subtract_4,"wxDateTime & wxDateTime::Subtract(wxDateSpan const & diff)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#subtract)")
    ADD_CLASS_METHOD(Subtract_5,"wxTimeSpan wxDateTime::Subtract(wxDateTime const & datetime)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#subtract)")
    ADD_CLASS_METHOD(ParseRfc822Date,"wxChar const * wxDateTime::ParseRfc822Date(wxChar const * date)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#parserfc822date)")
    ADD_CLASS_METHOD(ParseFormat,"wxChar const * wxDateTime::ParseFormat(wxChar const * date, wxChar const * format = wxDefaultDateTimeFormat, wxDateTime const & dateDef = wxDefaultDateTime)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#parseformat)")
    ADD_CLASS_METHOD(ParseDateTime,"wxChar const * wxDateTime::ParseDateTime(wxChar const * datetime)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#parsedatetime)")
    ADD_CLASS_METHOD(ParseDate,"wxChar const * wxDateTime::ParseDate(wxChar const * date)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#parsedate)")
    ADD_CLASS_METHOD(ParseTime,"wxChar const * wxDateTime::ParseTime(wxChar const * time)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#parsetime)")
/* The following types are missing: TimeZone
    ADD_CLASS_METHOD(Format,"wxString wxDateTime::Format(wxChar const * format = wxDefaultDateTimeFormat, TimeZone const & tz = wxDateTime::Local)  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#format)")
*/
    ADD_CLASS_METHOD(FormatDate,"wxString wxDateTime::FormatDate()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#formatdate)")
    ADD_CLASS_METHOD(FormatTime,"wxString wxDateTime::FormatTime()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#formattime)")
    ADD_CLASS_METHOD(FormatISODate,"wxString wxDateTime::FormatISODate()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#formatisodate)")
    ADD_CLASS_METHOD(FormatISOTime,"wxString wxDateTime::FormatISOTime()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#formatisotime)")
    ADD_CLASS_METHOD(GetValue,"wxLongLong wxDateTime::GetValue()  (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#getvalue)")

    // Operators:
    ADD_CLASS_METHOD(__assign___1,            "wxDateTime & wxDateTime::operator =(wxDateTime const & param0) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__assign__)")
    ADD_CLASS_METHOD(__assign__,            "wxDateTime::operator =() (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__assign__)")
    ADD_CLASS_METHOD(__assign___2,            "wxDateTime & wxDateTime::operator =(time_t timet) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__assign__)")
/* The following types are missing: tm
    ADD_CLASS_METHOD(__assign___3,            "wxDateTime & wxDateTime::operator =(tm const & tm) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__assign__)")
*/
/* The following types are missing: Tm
    ADD_CLASS_METHOD(__assign___4,            "wxDateTime & wxDateTime::operator =(Tm const & tm) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__assign__)")
*/
    // ADD_CLASS_METHOD(operator not available,"bool wxDateTime::<(wxDateTime const & dt) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#<)")
    // ADD_CLASS_METHOD(operator not available,"bool wxDateTime::<=(wxDateTime const & dt) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#<=)")
    // ADD_CLASS_METHOD(operator not available,"bool wxDateTime::>(wxDateTime const & dt) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#>)")
    // ADD_CLASS_METHOD(operator not available,"bool wxDateTime::>=(wxDateTime const & dt) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#>=)")
    ADD_CLASS_METHOD(__equal__,            "bool wxDateTime::operator ==(wxDateTime const & dt) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "bool wxDateTime::operator !=(wxDateTime const & dt) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__not_equal__)")
    ADD_CLASS_METHOD(__add_assign___1,            "wxDateTime & wxDateTime::operator +=(wxTimeSpan const & diff) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__add_assign__)")
    ADD_CLASS_METHOD(__add___1,            "wxDateTime wxDateTime::operator +(wxTimeSpan const & ts) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__add__)")
    ADD_CLASS_METHOD(__sub_assign___1,            "wxDateTime & wxDateTime::operator -=(wxTimeSpan const & diff) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__sub_assign__)")
    ADD_CLASS_METHOD(__substract___1,            "wxDateTime wxDateTime::operator -(wxTimeSpan const & ts) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__substract__)")
    ADD_CLASS_METHOD(__add_assign__,            "wxDateTime::operator +=() (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__add_assign__)")
    ADD_CLASS_METHOD(__add_assign___2,            "wxDateTime & wxDateTime::operator +=(wxDateSpan const & diff) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__add_assign__)")
    ADD_CLASS_METHOD(__add__,            "wxDateTime::operator +() (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__add__)")
    ADD_CLASS_METHOD(__add___2,            "wxDateTime wxDateTime::operator +(wxDateSpan const & ds) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__add__)")
    ADD_CLASS_METHOD(__sub_assign__,            "wxDateTime::operator -=() (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__sub_assign__)")
    ADD_CLASS_METHOD(__sub_assign___2,            "wxDateTime & wxDateTime::operator -=(wxDateSpan const & diff) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__sub_assign__)")
    ADD_CLASS_METHOD(__substract__,            "wxDateTime::operator -() (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__substract__)")
    ADD_CLASS_METHOD(__substract___2,            "wxDateTime wxDateTime::operator -(wxDateSpan const & ds) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__substract__)")
    ADD_CLASS_METHOD(__substract___3,            "wxTimeSpan wxDateTime::operator -(wxDateTime const & dt2) (http://docs.wxwidgets.org/stable/wx_wxdatetime.html#__substract__)")




    void AddMethods(WrapClass<wxDateTime>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxDateTime_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxDateTime_h
