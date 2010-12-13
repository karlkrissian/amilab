/**
 * C++ Interface: wrap_wxImageHistogramBase_wxImplementation_KeyEx
 *
 * Description: wrapping wxImageHistogramBase_wxImplementation_KeyEx
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxImageHistogramBase_wxImplementation_KeyEx_h_
#define _wrap_wxImageHistogramBase_wxImplementation_KeyEx_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxImageHistogramBase_wxImplementation_KeyEx_declared
  #define wxImageHistogramBase_wxImplementation_KeyEx_declared
  AMI_DECLARE_TYPE(wxImageHistogramBase_wxImplementation_KeyEx);
#endif

// TODO: check for inheritence ...
class WrapClass_wxImageHistogramBase_wxImplementation_KeyEx : public WrapClass<wxImageHistogramBase_wxImplementation_KeyEx>
    
{
  DEFINE_CLASS(WrapClass_wxImageHistogramBase_wxImplementation_KeyEx);

  protected:
    typedef WrapClass<wxImageHistogramBase_wxImplementation_KeyEx>::ptr _parentclass_ptr;
    typedef wxImageHistogramBase_wxImplementation_KeyEx ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxImageHistogramBase_wxImplementation_KeyEx>& GetObj() const { return WrapClass<wxImageHistogramBase_wxImplementation_KeyEx>::GetObj(); }

    /// Constructor
    WrapClass_wxImageHistogramBase_wxImplementation_KeyEx(boost::shared_ptr<wxImageHistogramBase_wxImplementation_KeyEx > si): 
    WrapClass<wxImageHistogramBase_wxImplementation_KeyEx>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxImageHistogramBase_wxImplementation_KeyEx()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogramBase_wxImplementation_KeyEx_1,"Constructor wxImageHistogramBase_wxImplementation_KeyEx::wxImageHistogramBase_wxImplementation_KeyEx(wxImageHistogramBase_wxImplementation_KeyEx const & param0) (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_keyex.html#wximagehistogrambase_wximplementation_keyex).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogramBase_wxImplementation_KeyEx,"Constructor wxImageHistogramBase_wxImplementation_KeyEx::wxImageHistogramBase_wxImplementation_KeyEx() (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_keyex.html#wximagehistogrambase_wximplementation_keyex).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogramBase_wxImplementation_KeyEx_2,"Constructor wxImageHistogramBase_wxImplementation_KeyEx::wxImageHistogramBase_wxImplementation_KeyEx() (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_keyex.html#wximagehistogrambase_wximplementation_keyex).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxImageHistogramBase_wxImplementation_KeyEx*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    // ADD_CLASS_METHOD(operator not available,"long unsigned int const & wxImageHistogramBase_wxImplementation_KeyEx::()(wxImageHistogramBase_wxImplementation_Pair const & pair) (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_keyex.html#())")
    ADD_CLASS_METHOD(__assign__,            "wxImageHistogramBase_wxImplementation_KeyEx & wxImageHistogramBase_wxImplementation_KeyEx::operator =(wxImageHistogramBase_wxImplementation_KeyEx const & param0) (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_keyex.html#__assign__)")




    void AddMethods(WrapClass<wxImageHistogramBase_wxImplementation_KeyEx>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxImageHistogramBase_wxImplementation_KeyEx_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxImageHistogramBase_wxImplementation_KeyEx_h
