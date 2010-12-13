/**
 * C++ Interface: wrap_wxDateSpan
 *
 * Description: wrapping wxDateSpan
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxDateSpan_h_
#define _wrap_wxDateSpan_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxDateSpan_declared
  #define wxDateSpan_declared
  AMI_DECLARE_TYPE(wxDateSpan);
#endif

// TODO: check for inheritence ...
class WrapClass_wxDateSpan : public WrapClass<wxDateSpan>
    
{
  DEFINE_CLASS(WrapClass_wxDateSpan);

  protected:
    typedef WrapClass<wxDateSpan>::ptr _parentclass_ptr;
    typedef wxDateSpan ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxDateSpan>& GetObj() const { return WrapClass<wxDateSpan>::GetObj(); }

    /// Constructor
    WrapClass_wxDateSpan(boost::shared_ptr<wxDateSpan > si): 
    WrapClass<wxDateSpan>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxDateSpan()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDateSpan_1,"Constructor wxDateSpan::wxDateSpan(wxDateSpan const & param0) (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#wxdatespan).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDateSpan,"Constructor wxDateSpan::wxDateSpan() (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#wxdatespan).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDateSpan_2,"Constructor wxDateSpan::wxDateSpan(int years = 0, int months = 0, int weeks = 0, int days = 0) (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#wxdatespan).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxDateSpan*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(Days,"wxDateSpan wxDateSpan::Days(int days) (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#days).");
    ADD_CLASS_STATICMETHOD(Day,"wxDateSpan wxDateSpan::Day() (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#day).");
    ADD_CLASS_STATICMETHOD(Weeks,"wxDateSpan wxDateSpan::Weeks(int weeks) (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#weeks).");
    ADD_CLASS_STATICMETHOD(Week,"wxDateSpan wxDateSpan::Week() (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#week).");
    ADD_CLASS_STATICMETHOD(Months,"wxDateSpan wxDateSpan::Months(int mon) (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#months).");
    ADD_CLASS_STATICMETHOD(Month,"wxDateSpan wxDateSpan::Month() (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#month).");
    ADD_CLASS_STATICMETHOD(Years,"wxDateSpan wxDateSpan::Years(int years) (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#years).");
    ADD_CLASS_STATICMETHOD(Year,"wxDateSpan wxDateSpan::Year() (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#year).");



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(SetYears,"wxDateSpan & wxDateSpan::SetYears(int n)  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#setyears)")
    ADD_CLASS_METHOD(SetMonths,"wxDateSpan & wxDateSpan::SetMonths(int n)  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#setmonths)")
    ADD_CLASS_METHOD(SetWeeks,"wxDateSpan & wxDateSpan::SetWeeks(int n)  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#setweeks)")
    ADD_CLASS_METHOD(SetDays,"wxDateSpan & wxDateSpan::SetDays(int n)  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#setdays)")
    ADD_CLASS_METHOD(GetYears,"int wxDateSpan::GetYears()  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#getyears)")
    ADD_CLASS_METHOD(GetMonths,"int wxDateSpan::GetMonths()  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#getmonths)")
    ADD_CLASS_METHOD(GetWeeks,"int wxDateSpan::GetWeeks()  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#getweeks)")
    ADD_CLASS_METHOD(GetDays,"int wxDateSpan::GetDays()  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#getdays)")
    ADD_CLASS_METHOD(GetTotalDays,"int wxDateSpan::GetTotalDays()  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#gettotaldays)")
    ADD_CLASS_METHOD(Add_1,"wxDateSpan wxDateSpan::Add(wxDateSpan const & other)  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#add)")
    ADD_CLASS_METHOD(Add,"wxDateSpan::Add()  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#add)")
    ADD_CLASS_METHOD(Add_2,"wxDateSpan & wxDateSpan::Add(wxDateSpan const & other)  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#add)")
    ADD_CLASS_METHOD(Subtract_1,"wxDateSpan wxDateSpan::Subtract(wxDateSpan const & other)  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#subtract)")
    ADD_CLASS_METHOD(Subtract,"wxDateSpan::Subtract()  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#subtract)")
    ADD_CLASS_METHOD(Subtract_2,"wxDateSpan & wxDateSpan::Subtract(wxDateSpan const & other)  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#subtract)")
    ADD_CLASS_METHOD(Negate,"wxDateSpan wxDateSpan::Negate()  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#negate)")
    ADD_CLASS_METHOD(Neg,"wxDateSpan & wxDateSpan::Neg()  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#neg)")
    ADD_CLASS_METHOD(Multiply_1,"wxDateSpan wxDateSpan::Multiply(int factor)  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#multiply)")
    ADD_CLASS_METHOD(Multiply,"wxDateSpan::Multiply()  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#multiply)")
    ADD_CLASS_METHOD(Multiply_2,"wxDateSpan & wxDateSpan::Multiply(int factor)  (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#multiply)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxDateSpan & wxDateSpan::operator =(wxDateSpan const & param0) (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#__assign__)")
    ADD_CLASS_METHOD(__add_assign__,            "wxDateSpan & wxDateSpan::operator +=(wxDateSpan const & other) (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#__add_assign__)")
    ADD_CLASS_METHOD(__add__,            "wxDateSpan wxDateSpan::operator +(wxDateSpan const & ds) (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#__add__)")
    ADD_CLASS_METHOD(__sub_assign__,            "wxDateSpan & wxDateSpan::operator -=(wxDateSpan const & other) (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#__sub_assign__)")
    ADD_CLASS_METHOD(__substract___1,            "wxDateSpan wxDateSpan::operator -(wxDateSpan const & ds) (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#__substract__)")
    ADD_CLASS_METHOD(__substract__,            "wxDateSpan::operator -() (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#__substract__)")
    ADD_CLASS_METHOD(__substract___2,            "wxDateSpan & wxDateSpan::operator -() (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#__substract__)")
    // ADD_CLASS_METHOD(operator not available,"wxDateSpan & wxDateSpan::*=(int factor) (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#*=)")
    // ADD_CLASS_METHOD(operator not available,"wxDateSpan wxDateSpan::*(int n) (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#*)")
    ADD_CLASS_METHOD(__equal__,            "bool wxDateSpan::operator ==(wxDateSpan const & ds) (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "bool wxDateSpan::operator !=(wxDateSpan const & ds) (http://docs.wxwidgets.org/stable/wx_wxdatespan.html#__not_equal__)")




    void AddMethods(WrapClass<wxDateSpan>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxDateSpan_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxDateSpan_h
