/**
 * C++ Interface: wrap_wxULongLongNative
 *
 * Description: wrapping wxULongLongNative
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxULongLongNative_h_
#define _wrap_wxULongLongNative_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxULongLongNative_declared
  #define wxULongLongNative_declared
  AMI_DECLARE_TYPE(wxULongLongNative);
#endif

// TODO: check for inheritence ...
class WrapClass_wxULongLongNative : public WrapClass<wxULongLongNative>
    
{
  DEFINE_CLASS(WrapClass_wxULongLongNative);

  protected:
    typedef WrapClass<wxULongLongNative>::ptr _parentclass_ptr;
    typedef wxULongLongNative ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxULongLongNative>& GetObj() const { return WrapClass<wxULongLongNative>::GetObj(); }

    /// Constructor
    WrapClass_wxULongLongNative(boost::shared_ptr<wxULongLongNative > si): 
    WrapClass<wxULongLongNative>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxULongLongNative()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxULongLongNative_1,"Constructor wxULongLongNative::wxULongLongNative(wxULongLongNative const & param0) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#wxulonglongnative).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxULongLongNative,"Constructor wxULongLongNative::wxULongLongNative() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#wxulonglongnative).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxULongLongNative_2,"Constructor wxULongLongNative::wxULongLongNative() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#wxulonglongnative).");
    /* The following types are missing: long long unsigned int
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxULongLongNative_3,"Constructor wxULongLongNative::wxULongLongNative(long long unsigned int ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#wxulonglongnative).");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxULongLongNative_4,"Constructor wxULongLongNative::wxULongLongNative(wxUint32 hi, wxUint32 lo) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#wxulonglongnative).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxULongLongNative*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetHi,"wxUint32 wxULongLongNative::GetHi()  (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#gethi)")
    ADD_CLASS_METHOD(GetLo,"wxUint32 wxULongLongNative::GetLo()  (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#getlo)")
/* The following types are missing: long long unsigned int
    ADD_CLASS_METHOD(GetValue,"long long unsigned int wxULongLongNative::GetValue()  (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#getvalue)")
*/
    ADD_CLASS_METHOD(ToULong,"long unsigned int wxULongLongNative::ToULong()  (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#toulong)")
    ADD_CLASS_METHOD(ToDouble,"double wxULongLongNative::ToDouble()  (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#todouble)")
    ADD_CLASS_METHOD(ToString,"wxString wxULongLongNative::ToString()  (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#tostring)")
    ADD_CLASS_METHOD(asArray,"void * wxULongLongNative::asArray()  (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#asarray)")

    // Operators:
    ADD_CLASS_METHOD(__assign___1,            "wxULongLongNative & wxULongLongNative::operator =(wxULongLongNative const & param0) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__assign__)")
    ADD_CLASS_METHOD(__assign__,            "wxULongLongNative::operator =() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__assign__)")
/* The following types are missing: long long unsigned int
    ADD_CLASS_METHOD(__assign___2,            "wxULongLongNative & wxULongLongNative::operator =(long long unsigned int ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__assign__)")
*/
    ADD_CLASS_METHOD(__assign___3,            "wxULongLongNative & wxULongLongNative::operator =(long long int ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__assign__)")
    ADD_CLASS_METHOD(__assign___4,            "wxULongLongNative & wxULongLongNative::operator =(int l) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__assign__)")
    ADD_CLASS_METHOD(__assign___5,            "wxULongLongNative & wxULongLongNative::operator =(long int l) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__assign__)")
    ADD_CLASS_METHOD(__assign___6,            "wxULongLongNative & wxULongLongNative::operator =(unsigned int l) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__assign__)")
    ADD_CLASS_METHOD(__assign___7,            "wxULongLongNative & wxULongLongNative::operator =(long unsigned int l) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__assign__)")
    ADD_CLASS_METHOD(__assign___8,            "wxULongLongNative & wxULongLongNative::operator =(wxLongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__assign__)")
    ADD_CLASS_METHOD(__add___1,            "wxULongLongNative wxULongLongNative::operator +(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__add__)")
    ADD_CLASS_METHOD(__add_assign___1,            "wxULongLongNative & wxULongLongNative::operator +=(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__add_assign__)")
    ADD_CLASS_METHOD(__add__,            "wxULongLongNative::operator +() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__add__)")
/* The following types are missing: long long unsigned int
    ADD_CLASS_METHOD(__add___2,            "wxULongLongNative wxULongLongNative::operator +(long long unsigned int const ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__add__)")
*/
    ADD_CLASS_METHOD(__add_assign__,            "wxULongLongNative::operator +=() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__add_assign__)")
/* The following types are missing: long long unsigned int
    ADD_CLASS_METHOD(__add_assign___2,            "wxULongLongNative & wxULongLongNative::operator +=(long long unsigned int const ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__add_assign__)")
*/
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative & wxULongLongNative::++() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#++)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative::++() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#++)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative wxULongLongNative::++(int param0) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#++)")
    ADD_CLASS_METHOD(__substract___1,            "wxULongLongNative wxULongLongNative::operator -(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__substract__)")
    ADD_CLASS_METHOD(__sub_assign___1,            "wxULongLongNative & wxULongLongNative::operator -=(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__sub_assign__)")
    ADD_CLASS_METHOD(__substract__,            "wxULongLongNative::operator -() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__substract__)")
/* The following types are missing: long long unsigned int
    ADD_CLASS_METHOD(__substract___2,            "wxULongLongNative wxULongLongNative::operator -(long long unsigned int const ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__substract__)")
*/
    ADD_CLASS_METHOD(__sub_assign__,            "wxULongLongNative::operator -=() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__sub_assign__)")
/* The following types are missing: long long unsigned int
    ADD_CLASS_METHOD(__sub_assign___2,            "wxULongLongNative & wxULongLongNative::operator -=(long long unsigned int const ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__sub_assign__)")
*/
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative & wxULongLongNative::--() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#--)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative::--() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#--)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative wxULongLongNative::--(int param0) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#--)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative wxULongLongNative::<<(int shift) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#<<)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative & wxULongLongNative::<<=(int shift) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#<<=)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative wxULongLongNative::>>(int shift) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#>>)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative & wxULongLongNative::>>=(int shift) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#>>=)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative wxULongLongNative::&(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#&)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative & wxULongLongNative::&=(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#&=)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative wxULongLongNative::|(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#|)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative & wxULongLongNative::|=(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#|=)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative wxULongLongNative::^(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#^)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative & wxULongLongNative::^=(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#^=)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative wxULongLongNative::*(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#*)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative::*() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#*)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative wxULongLongNative::*(long unsigned int l) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#*)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative & wxULongLongNative::*=(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#*=)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative::*=() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#*=)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative & wxULongLongNative::*=(long unsigned int l) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#*=)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative wxULongLongNative::/(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#/)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative::/() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#/)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative wxULongLongNative::/(long unsigned int l) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#/)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative & wxULongLongNative::/=(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#/=)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative::/=() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#/=)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative & wxULongLongNative::/=(long unsigned int l) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#/=)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative wxULongLongNative::%(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#%)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative::%() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#%)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative wxULongLongNative::%(long unsigned int l) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#%)")
    ADD_CLASS_METHOD(__equal___1,            "bool wxULongLongNative::operator ==(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__equal__)")
    ADD_CLASS_METHOD(__equal__,            "wxULongLongNative::operator ==() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__equal__)")
    ADD_CLASS_METHOD(__equal___2,            "bool wxULongLongNative::operator ==(long unsigned int l) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal___1,            "bool wxULongLongNative::operator !=(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__not_equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "wxULongLongNative::operator !=() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__not_equal__)")
    ADD_CLASS_METHOD(__not_equal___2,            "bool wxULongLongNative::operator !=(long unsigned int l) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#__not_equal__)")
    // ADD_CLASS_METHOD(operator not available,"bool wxULongLongNative::<(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#<)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative::<() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#<)")
    // ADD_CLASS_METHOD(operator not available,"bool wxULongLongNative::<(long unsigned int l) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#<)")
    // ADD_CLASS_METHOD(operator not available,"bool wxULongLongNative::>(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#>)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative::>() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#>)")
    // ADD_CLASS_METHOD(operator not available,"bool wxULongLongNative::>(long unsigned int l) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#>)")
    // ADD_CLASS_METHOD(operator not available,"bool wxULongLongNative::<=(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#<=)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative::<=() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#<=)")
    // ADD_CLASS_METHOD(operator not available,"bool wxULongLongNative::<=(long unsigned int l) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#<=)")
    // ADD_CLASS_METHOD(operator not available,"bool wxULongLongNative::>=(wxULongLongNative const & ll) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#>=)")
    // ADD_CLASS_METHOD(operator not available,"wxULongLongNative::>=() (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#>=)")
    // ADD_CLASS_METHOD(operator not available,"bool wxULongLongNative::>=(long unsigned int l) (http://docs.wxwidgets.org/stable/wx_wxulonglongnative.html#>=)")




    void AddMethods(WrapClass<wxULongLongNative>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxULongLongNative_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxULongLongNative_h
