/**
 * C++ Interface: wrap_wxImageHistogramBase
 *
 * Description: wrapping wxImageHistogramBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxImageHistogramBase_h_
#define _wrap_wxImageHistogramBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxImageHistogramBase_wxImplementation_HashTable.h"



AMI_DECLARE_TYPE(wxImageHistogramBase);

// TODO: check for inheritence ...
class WrapClass_wxImageHistogramBase : public WrapClass<wxImageHistogramBase>
    , public   WrapClass_wxImageHistogramBase_wxImplementation_HashTable
{
  DEFINE_CLASS(WrapClass_wxImageHistogramBase);

  protected:
    typedef WrapClass<wxImageHistogramBase>::ptr _parentclass_ptr;
    typedef wxImageHistogramBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxImageHistogramBase>& GetObj() const { return WrapClass<wxImageHistogramBase>::GetObj(); }

    /// Constructor
    WrapClass_wxImageHistogramBase(boost::shared_ptr<wxImageHistogramBase > si): 
    WrapClass<wxImageHistogramBase>(si)
    , WrapClass_wxImageHistogramBase_wxImplementation_HashTable(si)
    {}

    /// Destructor
    ~WrapClass_wxImageHistogramBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogramBase_1,"Constructor wxImageHistogramBase::wxImageHistogramBase(wxImageHistogramBase const & param0) (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase.html#wximagehistogrambase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogramBase,"Constructor wxImageHistogramBase::wxImageHistogramBase() (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase.html#wximagehistogrambase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogramBase_2,"Constructor wxImageHistogramBase::wxImageHistogramBase(size_t hint = 100, wxIntegerHash hf = wxIntegerHash(), wxIntegerEqual eq = wxIntegerEqual()) (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase.html#wximagehistogrambase).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxImageHistogramBase*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(find_1,"const_iterator wxImageHistogramBase::find(long unsigned int const & key)  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase.html#find)")
*/
    ADD_CLASS_METHOD(find,"wxImageHistogramBase::find()  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase.html#find)")
/* The following types are missing: iterator
    ADD_CLASS_METHOD(find_2,"iterator wxImageHistogramBase::find(long unsigned int const & key)  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase.html#find)")
*/
/* The following types are missing: Insert_Result
    ADD_CLASS_METHOD(insert,"Insert_Result wxImageHistogramBase::insert(wxImageHistogramBase_wxImplementation_Pair const & v)  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase.html#insert)")
*/
    ADD_CLASS_METHOD(erase_1,"size_t wxImageHistogramBase::erase(long unsigned int const & k)  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase.html#erase)")
    ADD_CLASS_METHOD(erase,"wxImageHistogramBase::erase()  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase.html#erase)")
/* The following types are missing: iterator
    ADD_CLASS_METHOD(erase_2,"void wxImageHistogramBase::erase(iterator const & it)  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase.html#erase)")
*/
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(erase_3,"void wxImageHistogramBase::erase(const_iterator const & it)  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase.html#erase)")
*/
    ADD_CLASS_METHOD(count,"size_t wxImageHistogramBase::count(long unsigned int const & key)  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase.html#count)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxImageHistogramBase & wxImageHistogramBase::operator =(wxImageHistogramBase const & param0) (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase.html#__assign__)")
    ADD_CLASS_METHOD(__at__,            "wxImageHistogramEntry & wxImageHistogramBase::operator [](long unsigned int const & key) (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase.html#__at__)")




    void AddMethods(WrapClass<wxImageHistogramBase>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxImageHistogramBase_h
