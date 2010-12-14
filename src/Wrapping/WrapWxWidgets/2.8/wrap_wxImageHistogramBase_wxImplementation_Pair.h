/**
 * C++ Interface: wrap_wxImageHistogramBase_wxImplementation_Pair
 *
 * Description: wrapping wxImageHistogramBase_wxImplementation_Pair
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxImageHistogramBase_wxImplementation_Pair_h_
#define _wrap_wxImageHistogramBase_wxImplementation_Pair_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxImageHistogramBase_wxImplementation_Pair_declared
  #define wxImageHistogramBase_wxImplementation_Pair_declared
  AMI_DECLARE_TYPE(wxImageHistogramBase_wxImplementation_Pair);
#endif

// TODO: check for inheritence ...
class WrapClass_wxImageHistogramBase_wxImplementation_Pair : public WrapClass<wxImageHistogramBase_wxImplementation_Pair>
    
{
  DEFINE_CLASS(WrapClass_wxImageHistogramBase_wxImplementation_Pair);

  protected:
    typedef WrapClass<wxImageHistogramBase_wxImplementation_Pair>::ptr _parentclass_ptr;
    typedef wxImageHistogramBase_wxImplementation_Pair ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxImageHistogramBase_wxImplementation_Pair>& GetObj() const { return WrapClass<wxImageHistogramBase_wxImplementation_Pair>::GetObj(); }

    /// Constructor
    WrapClass_wxImageHistogramBase_wxImplementation_Pair(boost::shared_ptr<wxImageHistogramBase_wxImplementation_Pair > si): 
    WrapClass<wxImageHistogramBase_wxImplementation_Pair>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxImageHistogramBase_wxImplementation_Pair()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogramBase_wxImplementation_Pair_1,"Constructor wxImageHistogramBase_wxImplementation_Pair::wxImageHistogramBase_wxImplementation_Pair(wxImageHistogramBase_wxImplementation_Pair const & param0) (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_pair.html#wximagehistogrambase_wximplementation_pair).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogramBase_wxImplementation_Pair,"Constructor wxImageHistogramBase_wxImplementation_Pair::wxImageHistogramBase_wxImplementation_Pair() (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_pair.html#wximagehistogrambase_wximplementation_pair).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogramBase_wxImplementation_Pair_2,"Constructor wxImageHistogramBase_wxImplementation_Pair::wxImageHistogramBase_wxImplementation_Pair(long unsigned int const & f, wxImageHistogramEntry const & s) (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_pair.html#wximagehistogrambase_wximplementation_pair).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxImageHistogramBase_wxImplementation_Pair*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxImageHistogramBase_wxImplementation_Pair & wxImageHistogramBase_wxImplementation_Pair::operator =(wxImageHistogramBase_wxImplementation_Pair const & param0) (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_pair.html#__assign__)")




    void AddMethods(WrapClass<wxImageHistogramBase_wxImplementation_Pair>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxImageHistogramBase_wxImplementation_Pair_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxImageHistogramBase_wxImplementation_Pair_h
