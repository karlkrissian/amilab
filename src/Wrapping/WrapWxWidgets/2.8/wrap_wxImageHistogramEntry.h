/**
 * C++ Interface: wrap_wxImageHistogramEntry
 *
 * Description: wrapping wxImageHistogramEntry
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxImageHistogramEntry_h_
#define _wrap_wxImageHistogramEntry_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxImageHistogramEntry_declared
  #define wxImageHistogramEntry_declared
  AMI_DECLARE_TYPE(wxImageHistogramEntry);
#endif

// TODO: check for inheritence ...
class WrapClass_wxImageHistogramEntry : public WrapClass<wxImageHistogramEntry>
    
{
  DEFINE_CLASS(WrapClass_wxImageHistogramEntry);

  protected:
    typedef WrapClass<wxImageHistogramEntry>::ptr _parentclass_ptr;
    typedef wxImageHistogramEntry ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxImageHistogramEntry>& GetObj() const { return WrapClass<wxImageHistogramEntry>::GetObj(); }

    /// Constructor
    WrapClass_wxImageHistogramEntry(boost::shared_ptr<wxImageHistogramEntry > si): 
    WrapClass<wxImageHistogramEntry>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxImageHistogramEntry()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogramEntry_1,"Constructor wxImageHistogramEntry::wxImageHistogramEntry(wxImageHistogramEntry const & param0) (http://docs.wxwidgets.org/stable/wx_wximagehistogramentry.html#wximagehistogramentry).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogramEntry,"Constructor wxImageHistogramEntry::wxImageHistogramEntry() (http://docs.wxwidgets.org/stable/wx_wximagehistogramentry.html#wximagehistogramentry).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogramEntry_2,"Constructor wxImageHistogramEntry::wxImageHistogramEntry() (http://docs.wxwidgets.org/stable/wx_wximagehistogramentry.html#wximagehistogramentry).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxImageHistogramEntry*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxImageHistogramEntry & wxImageHistogramEntry::operator =(wxImageHistogramEntry const & param0) (http://docs.wxwidgets.org/stable/wx_wximagehistogramentry.html#__assign__)")




    void AddMethods(WrapClass<wxImageHistogramEntry>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxImageHistogramEntry_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxImageHistogramEntry_h
