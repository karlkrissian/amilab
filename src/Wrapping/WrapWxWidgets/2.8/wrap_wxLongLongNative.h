/**
 * C++ Interface: wrap_wxLongLongNative
 *
 * Description: wrapping wxLongLongNative
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxLongLongNative_h_
#define _wrap_wxLongLongNative_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxLongLongNative_declared
  #define wxLongLongNative_declared
  AMI_DECLARE_TYPE(wxLongLongNative);
#endif

// TODO: check for inheritence ...
class WrapClass_wxLongLongNative : public WrapClass<wxLongLongNative>
    
{
  DEFINE_CLASS(WrapClass_wxLongLongNative);

  protected:
    typedef WrapClass<wxLongLongNative>::ptr _parentclass_ptr;
    typedef wxLongLongNative ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxLongLongNative>& GetObj() const { return WrapClass<wxLongLongNative>::GetObj(); }

    /// Constructor
    WrapClass_wxLongLongNative(boost::shared_ptr<wxLongLongNative > si): 
    WrapClass<wxLongLongNative>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxLongLongNative()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxLongLongNative_1,"Constructor wxLongLongNative::wxLongLongNative(wxLongLongNative const & param0) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#wxlonglongnative).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxLongLongNative,"Constructor wxLongLongNative::wxLongLongNative() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#wxlonglongnative).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxLongLongNative_2,"Constructor wxLongLongNative::wxLongLongNative() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#wxlonglongnative).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxLongLongNative_3,"Constructor wxLongLongNative::wxLongLongNative(long long int ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#wxlonglongnative).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxLongLongNative_4,"Constructor wxLongLongNative::wxLongLongNative(wxInt32 hi, wxUint32 lo) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#wxlonglongnative).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxLongLongNative*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Assign,"wxLongLongNative & wxLongLongNative::Assign(double d)  (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#assign)")
    ADD_CLASS_METHOD(GetHi,"wxInt32 wxLongLongNative::GetHi()  (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#gethi)")
    ADD_CLASS_METHOD(GetLo,"wxUint32 wxLongLongNative::GetLo()  (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#getlo)")
    ADD_CLASS_METHOD(Abs_1,"wxLongLongNative wxLongLongNative::Abs()  (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#abs)")
    ADD_CLASS_METHOD(Abs,"wxLongLongNative::Abs()  (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#abs)")
    ADD_CLASS_METHOD(Abs_2,"wxLongLongNative & wxLongLongNative::Abs()  (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#abs)")
    ADD_CLASS_METHOD(GetValue,"long long int wxLongLongNative::GetValue()  (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#getvalue)")
    ADD_CLASS_METHOD(ToLong,"long int wxLongLongNative::ToLong()  (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#tolong)")
    ADD_CLASS_METHOD(ToDouble,"double wxLongLongNative::ToDouble()  (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#todouble)")
    ADD_CLASS_METHOD(Negate,"wxLongLongNative & wxLongLongNative::Negate()  (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#negate)")
    ADD_CLASS_METHOD(ToString,"wxString wxLongLongNative::ToString()  (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#tostring)")
    ADD_CLASS_METHOD(asArray,"void * wxLongLongNative::asArray()  (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#asarray)")

    // Operators:
    ADD_CLASS_METHOD(__assign___1,            "wxLongLongNative & wxLongLongNative::operator =(wxLongLongNative const & param0) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__assign__)")
    ADD_CLASS_METHOD(__assign__,            "wxLongLongNative::operator =() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__assign__)")
    ADD_CLASS_METHOD(__assign___2,            "wxLongLongNative & wxLongLongNative::operator =(long long int ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__assign__)")
/* The following types are missing: long long unsigned int
    ADD_CLASS_METHOD(__assign___3,            "wxLongLongNative & wxLongLongNative::operator =(long long unsigned int ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__assign__)")
*/
    ADD_CLASS_METHOD(__assign___4,            "wxLongLongNative & wxLongLongNative::operator =(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__assign__)")
    ADD_CLASS_METHOD(__assign___5,            "wxLongLongNative & wxLongLongNative::operator =(int l) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__assign__)")
    ADD_CLASS_METHOD(__assign___6,            "wxLongLongNative & wxLongLongNative::operator =(long int l) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__assign__)")
    ADD_CLASS_METHOD(__assign___7,            "wxLongLongNative & wxLongLongNative::operator =(unsigned int l) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__assign__)")
    ADD_CLASS_METHOD(__assign___8,            "wxLongLongNative & wxLongLongNative::operator =(long unsigned int l) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__assign__)")
    ADD_CLASS_METHOD(__add___1,            "wxLongLongNative wxLongLongNative::operator +(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__add__)")
    ADD_CLASS_METHOD(__add_assign___1,            "wxLongLongNative & wxLongLongNative::operator +=(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__add_assign__)")
    ADD_CLASS_METHOD(__add__,            "wxLongLongNative::operator +() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__add__)")
    ADD_CLASS_METHOD(__add___2,            "wxLongLongNative wxLongLongNative::operator +(long long int const ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__add__)")
    ADD_CLASS_METHOD(__add_assign__,            "wxLongLongNative::operator +=() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__add_assign__)")
    ADD_CLASS_METHOD(__add_assign___2,            "wxLongLongNative & wxLongLongNative::operator +=(long long int const ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__add_assign__)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative & wxLongLongNative::++() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#++)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative::++() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#++)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative wxLongLongNative::++(int param0) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#++)")
    ADD_CLASS_METHOD(__substract___1,            "wxLongLongNative wxLongLongNative::operator -() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__substract__)")
    ADD_CLASS_METHOD(__substract__,            "wxLongLongNative::operator -() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__substract__)")
    ADD_CLASS_METHOD(__substract___2,            "wxLongLongNative wxLongLongNative::operator -(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__substract__)")
    ADD_CLASS_METHOD(__sub_assign___1,            "wxLongLongNative & wxLongLongNative::operator -=(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__sub_assign__)")
    ADD_CLASS_METHOD(__substract___3,            "wxLongLongNative wxLongLongNative::operator -(long long int const ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__substract__)")
    ADD_CLASS_METHOD(__sub_assign__,            "wxLongLongNative::operator -=() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__sub_assign__)")
    ADD_CLASS_METHOD(__sub_assign___2,            "wxLongLongNative & wxLongLongNative::operator -=(long long int const ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__sub_assign__)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative & wxLongLongNative::--() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#--)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative::--() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#--)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative wxLongLongNative::--(int param0) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#--)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative wxLongLongNative::<<(int shift) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#<<)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative & wxLongLongNative::<<=(int shift) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#<<=)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative wxLongLongNative::>>(int shift) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#>>)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative & wxLongLongNative::>>=(int shift) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#>>=)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative wxLongLongNative::&(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#&)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative & wxLongLongNative::&=(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#&=)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative wxLongLongNative::|(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#|)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative & wxLongLongNative::|=(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#|=)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative wxLongLongNative::^(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#^)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative & wxLongLongNative::^=(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#^=)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative wxLongLongNative::*(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#*)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative::*() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#*)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative wxLongLongNative::*(long int l) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#*)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative & wxLongLongNative::*=(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#*=)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative::*=() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#*=)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative & wxLongLongNative::*=(long int l) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#*=)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative wxLongLongNative::/(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#/)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative::/() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#/)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative wxLongLongNative::/(long int l) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#/)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative & wxLongLongNative::/=(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#/=)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative::/=() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#/=)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative & wxLongLongNative::/=(long int l) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#/=)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative wxLongLongNative::%(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#%)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative::%() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#%)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative wxLongLongNative::%(long int l) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#%)")
    ADD_CLASS_METHOD(__equal___1,            "bool wxLongLongNative::operator ==(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__equal__)")
    ADD_CLASS_METHOD(__equal__,            "wxLongLongNative::operator ==() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__equal__)")
    ADD_CLASS_METHOD(__equal___2,            "bool wxLongLongNative::operator ==(long int l) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal___1,            "bool wxLongLongNative::operator !=(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__not_equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "wxLongLongNative::operator !=() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__not_equal__)")
    ADD_CLASS_METHOD(__not_equal___2,            "bool wxLongLongNative::operator !=(long int l) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#__not_equal__)")
    // ADD_CLASS_METHOD(operator not available,"bool wxLongLongNative::<(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#<)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative::<() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#<)")
    // ADD_CLASS_METHOD(operator not available,"bool wxLongLongNative::<(long int l) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#<)")
    // ADD_CLASS_METHOD(operator not available,"bool wxLongLongNative::>(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#>)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative::>() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#>)")
    // ADD_CLASS_METHOD(operator not available,"bool wxLongLongNative::>(long int l) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#>)")
    // ADD_CLASS_METHOD(operator not available,"bool wxLongLongNative::<=(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#<=)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative::<=() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#<=)")
    // ADD_CLASS_METHOD(operator not available,"bool wxLongLongNative::<=(long int l) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#<=)")
    // ADD_CLASS_METHOD(operator not available,"bool wxLongLongNative::>=(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#>=)")
    // ADD_CLASS_METHOD(operator not available,"wxLongLongNative::>=() (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#>=)")
    // ADD_CLASS_METHOD(operator not available,"bool wxLongLongNative::>=(long int l) (http://docs.wxwidgets.org/stable/wx_wxlonglongnative.html#>=)")




    void AddMethods(WrapClass<wxLongLongNative>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxLongLongNative_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxLongLongNative_h
