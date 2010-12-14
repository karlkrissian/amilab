/**
 * C++ Interface: wrap_wxIntegerEqual
 *
 * Description: wrapping wxIntegerEqual
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxIntegerEqual_h_
#define _wrap_wxIntegerEqual_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxIntegerEqual_declared
  #define wxIntegerEqual_declared
  AMI_DECLARE_TYPE(wxIntegerEqual);
#endif

// TODO: check for inheritence ...
class WrapClass_wxIntegerEqual : public WrapClass<wxIntegerEqual>
    
{
  DEFINE_CLASS(WrapClass_wxIntegerEqual);

  protected:
    typedef WrapClass<wxIntegerEqual>::ptr _parentclass_ptr;
    typedef wxIntegerEqual ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxIntegerEqual>& GetObj() const { return WrapClass<wxIntegerEqual>::GetObj(); }

    /// Constructor
    WrapClass_wxIntegerEqual(boost::shared_ptr<wxIntegerEqual > si): 
    WrapClass<wxIntegerEqual>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxIntegerEqual()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIntegerEqual_1,"Constructor wxIntegerEqual::wxIntegerEqual(wxIntegerEqual const & param0) (http://docs.wxwidgets.org/stable/wx_wxintegerequal.html#wxintegerequal).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIntegerEqual,"Constructor wxIntegerEqual::wxIntegerEqual() (http://docs.wxwidgets.org/stable/wx_wxintegerequal.html#wxintegerequal).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIntegerEqual_2,"Constructor wxIntegerEqual::wxIntegerEqual() (http://docs.wxwidgets.org/stable/wx_wxintegerequal.html#wxintegerequal).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxIntegerEqual*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    // ADD_CLASS_METHOD(operator not available,"bool wxIntegerEqual::()(long int a, long int b) (http://docs.wxwidgets.org/stable/wx_wxintegerequal.html#())")
    // ADD_CLASS_METHOD(operator not available,"wxIntegerEqual::()() (http://docs.wxwidgets.org/stable/wx_wxintegerequal.html#())")
    // ADD_CLASS_METHOD(operator not available,"bool wxIntegerEqual::()(long unsigned int a, long unsigned int b) (http://docs.wxwidgets.org/stable/wx_wxintegerequal.html#())")
    // ADD_CLASS_METHOD(operator not available,"bool wxIntegerEqual::()(int a, int b) (http://docs.wxwidgets.org/stable/wx_wxintegerequal.html#())")
    // ADD_CLASS_METHOD(operator not available,"bool wxIntegerEqual::()(unsigned int a, unsigned int b) (http://docs.wxwidgets.org/stable/wx_wxintegerequal.html#())")
/* The following types are missing: short int, short int
    // ADD_CLASS_METHOD(operator not available,"bool wxIntegerEqual::()(short int a, short int b) (http://docs.wxwidgets.org/stable/wx_wxintegerequal.html#())")
*/
    // ADD_CLASS_METHOD(operator not available,"bool wxIntegerEqual::()(short unsigned int a, short unsigned int b) (http://docs.wxwidgets.org/stable/wx_wxintegerequal.html#())")
    // ADD_CLASS_METHOD(operator not available,"bool wxIntegerEqual::()(long long int a, long long int b) (http://docs.wxwidgets.org/stable/wx_wxintegerequal.html#())")
/* The following types are missing: long long unsigned int, long long unsigned int
    // ADD_CLASS_METHOD(operator not available,"bool wxIntegerEqual::()(long long unsigned int a, long long unsigned int b) (http://docs.wxwidgets.org/stable/wx_wxintegerequal.html#())")
*/
    ADD_CLASS_METHOD(__assign__,            "wxIntegerEqual & wxIntegerEqual::operator =(wxIntegerEqual const & param0) (http://docs.wxwidgets.org/stable/wx_wxintegerequal.html#__assign__)")




    void AddMethods(WrapClass<wxIntegerEqual>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxIntegerEqual_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxIntegerEqual_h
