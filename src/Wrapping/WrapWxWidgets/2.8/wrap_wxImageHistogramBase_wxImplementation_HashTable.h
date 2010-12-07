/**
 * C++ Interface: wrap_wxImageHistogramBase_wxImplementation_HashTable
 *
 * Description: wrapping wxImageHistogramBase_wxImplementation_HashTable
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxImageHistogramBase_wxImplementation_HashTable_h_
#define _wrap_wxImageHistogramBase_wxImplementation_HashTable_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxImageHistogramBase_wxImplementation_HashTable);

// TODO: check for inheritence ...
class WrapClass_wxImageHistogramBase_wxImplementation_HashTable : public WrapClass<wxImageHistogramBase_wxImplementation_HashTable>
    
{
  DEFINE_CLASS(WrapClass_wxImageHistogramBase_wxImplementation_HashTable);

  protected:
    typedef WrapClass<wxImageHistogramBase_wxImplementation_HashTable>::ptr _parentclass_ptr;
    typedef wxImageHistogramBase_wxImplementation_HashTable ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxImageHistogramBase_wxImplementation_HashTable>& GetObj() const { return WrapClass<wxImageHistogramBase_wxImplementation_HashTable>::GetObj(); }

    /// Constructor
    WrapClass_wxImageHistogramBase_wxImplementation_HashTable(boost::shared_ptr<wxImageHistogramBase_wxImplementation_HashTable > si): 
    WrapClass<wxImageHistogramBase_wxImplementation_HashTable>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxImageHistogramBase_wxImplementation_HashTable()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogramBase_wxImplementation_HashTable_1,"Constructor wxImageHistogramBase_wxImplementation_HashTable::wxImageHistogramBase_wxImplementation_HashTable(size_t sz = 10, wxIntegerHash const & hfun = wxIntegerHash(), wxIntegerEqual const & k_eq = wxIntegerEqual(), wxImageHistogramBase_wxImplementation_KeyEx const & k_ex = wxImageHistogramBase_wxImplementation_KeyEx()) (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#wximagehistogrambase_wximplementation_hashtable).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogramBase_wxImplementation_HashTable,"Constructor wxImageHistogramBase_wxImplementation_HashTable::wxImageHistogramBase_wxImplementation_HashTable() (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#wximagehistogrambase_wximplementation_hashtable).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogramBase_wxImplementation_HashTable_2,"Constructor wxImageHistogramBase_wxImplementation_HashTable::wxImageHistogramBase_wxImplementation_HashTable(wxImageHistogramBase_wxImplementation_HashTable const & ht) (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#wximagehistogrambase_wximplementation_hashtable).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxImageHistogramBase_wxImplementation_HashTable*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(hash_funct,"wxIntegerHash wxImageHistogramBase_wxImplementation_HashTable::hash_funct()  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#hash_funct)")
    ADD_CLASS_METHOD(key_eq,"wxIntegerEqual wxImageHistogramBase_wxImplementation_HashTable::key_eq()  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#key_eq)")
    ADD_CLASS_METHOD(clear,"void wxImageHistogramBase_wxImplementation_HashTable::clear()  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#clear)")
    ADD_CLASS_METHOD(size,"size_t wxImageHistogramBase_wxImplementation_HashTable::size()  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#size)")
    ADD_CLASS_METHOD(max_size,"size_t wxImageHistogramBase_wxImplementation_HashTable::max_size()  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#max_size)")
    ADD_CLASS_METHOD(empty,"bool wxImageHistogramBase_wxImplementation_HashTable::empty()  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#empty)")
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(end_1,"const_iterator wxImageHistogramBase_wxImplementation_HashTable::end()  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#end)")
*/
    ADD_CLASS_METHOD(end,"wxImageHistogramBase_wxImplementation_HashTable::end()  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#end)")
/* The following types are missing: iterator
    ADD_CLASS_METHOD(end_2,"iterator wxImageHistogramBase_wxImplementation_HashTable::end()  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#end)")
*/
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(begin_1,"const_iterator wxImageHistogramBase_wxImplementation_HashTable::begin()  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#begin)")
*/
    ADD_CLASS_METHOD(begin,"wxImageHistogramBase_wxImplementation_HashTable::begin()  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#begin)")
/* The following types are missing: iterator
    ADD_CLASS_METHOD(begin_2,"iterator wxImageHistogramBase_wxImplementation_HashTable::begin()  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#begin)")
*/
    ADD_CLASS_METHOD(erase,"size_t wxImageHistogramBase_wxImplementation_HashTable::erase(long unsigned int const & key)  (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#erase)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxImageHistogramBase_wxImplementation_HashTable const & wxImageHistogramBase_wxImplementation_HashTable::operator =(wxImageHistogramBase_wxImplementation_HashTable const & ht) (http://docs.wxwidgets.org/stable/wx_wximagehistogrambase_wximplementation_hashtable.html#__assign__)")




    void AddMethods(WrapClass<wxImageHistogramBase_wxImplementation_HashTable>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxImageHistogramBase_wxImplementation_HashTable_h
