/**
 * C++ Interface: wrap_wxTimeSpan
 *
 * Description: wrapping wxTimeSpan
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxTimeSpan_h_
#define _wrap_wxTimeSpan_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxTimeSpan_declared
  #define wxTimeSpan_declared
  AMI_DECLARE_TYPE(wxTimeSpan);
#endif

// TODO: check for inheritence ...
class WrapClass_wxTimeSpan : public WrapClass<wxTimeSpan>
    
{
  DEFINE_CLASS(WrapClass_wxTimeSpan);

  protected:
    typedef WrapClass<wxTimeSpan>::ptr _parentclass_ptr;
    typedef wxTimeSpan ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxTimeSpan>& GetObj() const { return WrapClass<wxTimeSpan>::GetObj(); }

    /// Constructor
    WrapClass_wxTimeSpan(boost::shared_ptr<wxTimeSpan > si): 
    WrapClass<wxTimeSpan>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxTimeSpan()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTimeSpan_1,"Constructor wxTimeSpan::wxTimeSpan(wxTimeSpan const & param0) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#wxtimespan).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTimeSpan,"Constructor wxTimeSpan::wxTimeSpan() (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#wxtimespan).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTimeSpan_2,"Constructor wxTimeSpan::wxTimeSpan() (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#wxtimespan).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTimeSpan_3,"Constructor wxTimeSpan::wxTimeSpan(long int hours, long int minutes = 0, wxLongLong seconds = 0, wxLongLong milliseconds = 0) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#wxtimespan).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTimeSpan_4,"Constructor wxTimeSpan::wxTimeSpan(wxLongLong const & diff) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#wxtimespan).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxTimeSpan*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(Milliseconds,"wxTimeSpan wxTimeSpan::Milliseconds(wxLongLong ms) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#milliseconds).");
    ADD_CLASS_STATICMETHOD(Millisecond,"wxTimeSpan wxTimeSpan::Millisecond() (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#millisecond).");
    ADD_CLASS_STATICMETHOD(Seconds,"wxTimeSpan wxTimeSpan::Seconds(wxLongLong sec) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#seconds).");
    ADD_CLASS_STATICMETHOD(Second,"wxTimeSpan wxTimeSpan::Second() (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#second).");
    ADD_CLASS_STATICMETHOD(Minutes,"wxTimeSpan wxTimeSpan::Minutes(long int min) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#minutes).");
    ADD_CLASS_STATICMETHOD(Minute,"wxTimeSpan wxTimeSpan::Minute() (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#minute).");
    ADD_CLASS_STATICMETHOD(Hours,"wxTimeSpan wxTimeSpan::Hours(long int hours) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#hours).");
    ADD_CLASS_STATICMETHOD(Hour,"wxTimeSpan wxTimeSpan::Hour() (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#hour).");
    ADD_CLASS_STATICMETHOD(Days,"wxTimeSpan wxTimeSpan::Days(long int days) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#days).");
    ADD_CLASS_STATICMETHOD(Day,"wxTimeSpan wxTimeSpan::Day() (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#day).");
    ADD_CLASS_STATICMETHOD(Weeks,"wxTimeSpan wxTimeSpan::Weeks(long int days) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#weeks).");
    ADD_CLASS_STATICMETHOD(Week,"wxTimeSpan wxTimeSpan::Week() (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#week).");



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Add_1,"wxTimeSpan wxTimeSpan::Add(wxTimeSpan const & diff)  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#add)")
    ADD_CLASS_METHOD(Add,"wxTimeSpan::Add()  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#add)")
    ADD_CLASS_METHOD(Add_2,"wxTimeSpan & wxTimeSpan::Add(wxTimeSpan const & diff)  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#add)")
    ADD_CLASS_METHOD(Subtract_1,"wxTimeSpan wxTimeSpan::Subtract(wxTimeSpan const & diff)  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#subtract)")
    ADD_CLASS_METHOD(Subtract,"wxTimeSpan::Subtract()  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#subtract)")
    ADD_CLASS_METHOD(Subtract_2,"wxTimeSpan & wxTimeSpan::Subtract(wxTimeSpan const & diff)  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#subtract)")
    ADD_CLASS_METHOD(Multiply_1,"wxTimeSpan wxTimeSpan::Multiply(int n)  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#multiply)")
    ADD_CLASS_METHOD(Multiply,"wxTimeSpan::Multiply()  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#multiply)")
    ADD_CLASS_METHOD(Multiply_2,"wxTimeSpan & wxTimeSpan::Multiply(int n)  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#multiply)")
    ADD_CLASS_METHOD(Negate,"wxTimeSpan wxTimeSpan::Negate()  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#negate)")
    ADD_CLASS_METHOD(Neg,"wxTimeSpan & wxTimeSpan::Neg()  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#neg)")
    ADD_CLASS_METHOD(Abs,"wxTimeSpan wxTimeSpan::Abs()  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#abs)")
    ADD_CLASS_METHOD(IsNull,"bool wxTimeSpan::IsNull()  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#isnull)")
    ADD_CLASS_METHOD(IsPositive,"bool wxTimeSpan::IsPositive()  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#ispositive)")
    ADD_CLASS_METHOD(IsNegative,"bool wxTimeSpan::IsNegative()  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#isnegative)")
    ADD_CLASS_METHOD(IsEqualTo,"bool wxTimeSpan::IsEqualTo(wxTimeSpan const & ts)  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#isequalto)")
    ADD_CLASS_METHOD(IsLongerThan,"bool wxTimeSpan::IsLongerThan(wxTimeSpan const & ts)  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#islongerthan)")
    ADD_CLASS_METHOD(IsShorterThan,"bool wxTimeSpan::IsShorterThan(wxTimeSpan const & t)  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#isshorterthan)")
    ADD_CLASS_METHOD(GetWeeks,"int wxTimeSpan::GetWeeks()  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#getweeks)")
    ADD_CLASS_METHOD(GetDays,"int wxTimeSpan::GetDays()  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#getdays)")
    ADD_CLASS_METHOD(GetHours,"int wxTimeSpan::GetHours()  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#gethours)")
    ADD_CLASS_METHOD(GetMinutes,"int wxTimeSpan::GetMinutes()  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#getminutes)")
    ADD_CLASS_METHOD(GetSeconds,"wxLongLong wxTimeSpan::GetSeconds()  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#getseconds)")
    ADD_CLASS_METHOD(GetMilliseconds,"wxLongLong wxTimeSpan::GetMilliseconds()  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#getmilliseconds)")
    ADD_CLASS_METHOD(Format,"wxString wxTimeSpan::Format(wxChar const * format = wxDefaultTimeSpanFormat)  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#format)")
    ADD_CLASS_METHOD(GetValue,"wxLongLong wxTimeSpan::GetValue()  (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#getvalue)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxTimeSpan & wxTimeSpan::operator =(wxTimeSpan const & param0) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#__assign__)")
    ADD_CLASS_METHOD(__add_assign__,            "wxTimeSpan & wxTimeSpan::operator +=(wxTimeSpan const & diff) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#__add_assign__)")
    ADD_CLASS_METHOD(__add__,            "wxTimeSpan wxTimeSpan::operator +(wxTimeSpan const & ts) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#__add__)")
    ADD_CLASS_METHOD(__sub_assign__,            "wxTimeSpan & wxTimeSpan::operator -=(wxTimeSpan const & diff) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#__sub_assign__)")
    ADD_CLASS_METHOD(__substract___1,            "wxTimeSpan wxTimeSpan::operator -(wxTimeSpan const & ts) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#__substract__)")
    // ADD_CLASS_METHOD(operator not available,"wxTimeSpan & wxTimeSpan::*=(int n) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#*=)")
    // ADD_CLASS_METHOD(operator not available,"wxTimeSpan wxTimeSpan::*(int n) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#*)")
    ADD_CLASS_METHOD(__substract__,            "wxTimeSpan::operator -() (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#__substract__)")
    ADD_CLASS_METHOD(__substract___2,            "wxTimeSpan & wxTimeSpan::operator -() (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#__substract__)")
    // ADD_CLASS_METHOD(operator not available,"bool wxTimeSpan::!() (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#!)")
    // ADD_CLASS_METHOD(operator not available,"bool wxTimeSpan::<(wxTimeSpan const & ts) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#<)")
    // ADD_CLASS_METHOD(operator not available,"bool wxTimeSpan::<=(wxTimeSpan const & ts) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#<=)")
    // ADD_CLASS_METHOD(operator not available,"bool wxTimeSpan::>(wxTimeSpan const & ts) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#>)")
    // ADD_CLASS_METHOD(operator not available,"bool wxTimeSpan::>=(wxTimeSpan const & ts) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#>=)")
    ADD_CLASS_METHOD(__equal__,            "bool wxTimeSpan::operator ==(wxTimeSpan const & ts) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "bool wxTimeSpan::operator !=(wxTimeSpan const & ts) (http://docs.wxwidgets.org/stable/wx_wxtimespan.html#__not_equal__)")




    void AddMethods(WrapClass<wxTimeSpan>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxTimeSpan_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxTimeSpan_h
