/**
 * C++ Interface: wrap_wxIntegerHash
 *
 * Description: wrapping wxIntegerHash
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxIntegerHash_h_
#define _wrap_wxIntegerHash_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxIntegerHash_declared
  #define wxIntegerHash_declared
  AMI_DECLARE_TYPE(wxIntegerHash);
#endif

// TODO: check for inheritence ...
class WrapClass_wxIntegerHash : public WrapClass<wxIntegerHash>
    
{
  DEFINE_CLASS(WrapClass_wxIntegerHash);

  protected:
    typedef WrapClass<wxIntegerHash>::ptr _parentclass_ptr;
    typedef wxIntegerHash ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxIntegerHash>& GetObj() const { return WrapClass<wxIntegerHash>::GetObj(); }

    /// Constructor
    WrapClass_wxIntegerHash(boost::shared_ptr<wxIntegerHash > si): 
    WrapClass<wxIntegerHash>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxIntegerHash()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIntegerHash_1,"Constructor wxIntegerHash::wxIntegerHash(wxIntegerHash const & param0) (http://docs.wxwidgets.org/stable/wx_wxintegerhash.html#wxintegerhash).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIntegerHash,"Constructor wxIntegerHash::wxIntegerHash() (http://docs.wxwidgets.org/stable/wx_wxintegerhash.html#wxintegerhash).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIntegerHash_2,"Constructor wxIntegerHash::wxIntegerHash() (http://docs.wxwidgets.org/stable/wx_wxintegerhash.html#wxintegerhash).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxIntegerHash*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    // ADD_CLASS_METHOD(operator not available,"long unsigned int wxIntegerHash::()(long int x) (http://docs.wxwidgets.org/stable/wx_wxintegerhash.html#())")
    // ADD_CLASS_METHOD(operator not available,"wxIntegerHash::()() (http://docs.wxwidgets.org/stable/wx_wxintegerhash.html#())")
    // ADD_CLASS_METHOD(operator not available,"long unsigned int wxIntegerHash::()(long unsigned int x) (http://docs.wxwidgets.org/stable/wx_wxintegerhash.html#())")
    // ADD_CLASS_METHOD(operator not available,"long unsigned int wxIntegerHash::()(int x) (http://docs.wxwidgets.org/stable/wx_wxintegerhash.html#())")
    // ADD_CLASS_METHOD(operator not available,"long unsigned int wxIntegerHash::()(unsigned int x) (http://docs.wxwidgets.org/stable/wx_wxintegerhash.html#())")
/* The following types are missing: short int
    // ADD_CLASS_METHOD(operator not available,"long unsigned int wxIntegerHash::()(short int x) (http://docs.wxwidgets.org/stable/wx_wxintegerhash.html#())")
*/
    // ADD_CLASS_METHOD(operator not available,"long unsigned int wxIntegerHash::()(short unsigned int x) (http://docs.wxwidgets.org/stable/wx_wxintegerhash.html#())")
/* The following types are missing: long long unsigned int
    // ADD_CLASS_METHOD(operator not available,"long long unsigned int wxIntegerHash::()(long long int x) (http://docs.wxwidgets.org/stable/wx_wxintegerhash.html#())")
*/
/* The following types are missing: long long unsigned int, long long unsigned int
    // ADD_CLASS_METHOD(operator not available,"long long unsigned int wxIntegerHash::()(long long unsigned int x) (http://docs.wxwidgets.org/stable/wx_wxintegerhash.html#())")
*/
    ADD_CLASS_METHOD(__assign__,            "wxIntegerHash & wxIntegerHash::operator =(wxIntegerHash const & param0) (http://docs.wxwidgets.org/stable/wx_wxintegerhash.html#__assign__)")




    void AddMethods(WrapClass<wxIntegerHash>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxIntegerHash_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxIntegerHash_h
