/**
 * C++ Interface: wrap_wxStringBase
 *
 * Description: wrapping wxStringBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxStringBase_h_
#define _wrap_wxStringBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxStringBase);

// TODO: check for inheritence ...
class WrapClass_wxStringBase : public WrapClass<wxStringBase>
    
{
  DEFINE_CLASS(WrapClass_wxStringBase);

  protected:
    typedef WrapClass<wxStringBase>::ptr _parentclass_ptr;
    typedef wxStringBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxStringBase>& GetObj() const { return WrapClass<wxStringBase>::GetObj(); }

    /// Constructor
    WrapClass_wxStringBase(boost::shared_ptr<wxStringBase > si): 
    WrapClass<wxStringBase>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxStringBase()
    {
      std::cout << "~WrapClass_wxStringBase()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase1,"Wrapping of wxStringBase, http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase,"Wrapping of wxStringBase, http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase2,"Wrapping of wxStringBase, http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase3,"Wrapping of wxStringBase, http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase4,"Wrapping of wxStringBase, http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase5,"Wrapping of wxStringBase, http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase6,"Wrapping of wxStringBase, http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase7,"Wrapping of wxStringBase, http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase.");
    /* The following types are missing: void, void
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase8,"Wrapping of wxStringBase, http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase.");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxStringBase*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(copy,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(length,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#length")
    ADD_CLASS_METHOD(size,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#size")
    ADD_CLASS_METHOD(max_size,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#max_size")
    ADD_CLASS_METHOD(resize,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#resize")
    ADD_CLASS_METHOD(clear,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#clear")
    ADD_CLASS_METHOD(empty,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#empty")
    ADD_CLASS_METHOD(reserve,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#reserve")
    ADD_CLASS_METHOD(capacity,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#capacity")
    ADD_CLASS_METHOD(at1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#at")
    ADD_CLASS_METHOD(at,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#at")
    ADD_CLASS_METHOD(at2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#at")
    ADD_CLASS_METHOD(append1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#append")
    ADD_CLASS_METHOD(append,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#append")
    ADD_CLASS_METHOD(append2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#append")
    ADD_CLASS_METHOD(append3,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#append")
    ADD_CLASS_METHOD(append4,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#append")
    ADD_CLASS_METHOD(append5,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#append")
    ADD_CLASS_METHOD(append6,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#append")
    ADD_CLASS_METHOD(begin1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#begin")
    ADD_CLASS_METHOD(begin,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#begin")
    ADD_CLASS_METHOD(begin2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#begin")
    ADD_CLASS_METHOD(end1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#end")
    ADD_CLASS_METHOD(end,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#end")
    ADD_CLASS_METHOD(end2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#end")
/* The following types are missing: const_reverse_iterator
    ADD_CLASS_METHOD(rbegin1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rbegin")
*/
    ADD_CLASS_METHOD(rbegin,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rbegin")
/* The following types are missing: reverse_iterator
    ADD_CLASS_METHOD(rbegin2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rbegin")
*/
/* The following types are missing: const_reverse_iterator
    ADD_CLASS_METHOD(rend1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rend")
*/
    ADD_CLASS_METHOD(rend,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rend")
/* The following types are missing: reverse_iterator
    ADD_CLASS_METHOD(rend2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rend")
*/
    ADD_CLASS_METHOD(insert1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#insert")
    ADD_CLASS_METHOD(insert,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#insert")
    ADD_CLASS_METHOD(insert2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#insert")
    ADD_CLASS_METHOD(insert3,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#insert")
    ADD_CLASS_METHOD(insert4,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#insert")
    ADD_CLASS_METHOD(insert5,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#insert")
    ADD_CLASS_METHOD(insert6,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#insert")
    ADD_CLASS_METHOD(insert7,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#insert")
    ADD_CLASS_METHOD(erase1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#erase")
    ADD_CLASS_METHOD(erase,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#erase")
    ADD_CLASS_METHOD(erase2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#erase")
    ADD_CLASS_METHOD(erase3,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#erase")
    ADD_CLASS_METHOD(c_str,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#c_str")
    ADD_CLASS_METHOD(data,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#data")
    ADD_CLASS_METHOD(replace1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace")
    ADD_CLASS_METHOD(replace,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace")
    ADD_CLASS_METHOD(replace2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace")
    ADD_CLASS_METHOD(replace3,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace")
    ADD_CLASS_METHOD(replace4,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace")
    ADD_CLASS_METHOD(replace5,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace")
    ADD_CLASS_METHOD(replace6,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace")
    ADD_CLASS_METHOD(replace7,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace")
    ADD_CLASS_METHOD(replace8,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace")
    ADD_CLASS_METHOD(replace9,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace")
    ADD_CLASS_METHOD(replace10,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace")
    ADD_CLASS_METHOD(swap,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#swap")
    ADD_CLASS_METHOD(find1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find")
    ADD_CLASS_METHOD(find,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find")
    ADD_CLASS_METHOD(find2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find")
    ADD_CLASS_METHOD(find3,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find")
    ADD_CLASS_METHOD(rfind1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rfind")
    ADD_CLASS_METHOD(rfind,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rfind")
    ADD_CLASS_METHOD(rfind2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rfind")
    ADD_CLASS_METHOD(rfind3,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rfind")
    ADD_CLASS_METHOD(find_first_of1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_of")
    ADD_CLASS_METHOD(find_first_of,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_of")
    ADD_CLASS_METHOD(find_first_of2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_of")
    ADD_CLASS_METHOD(find_first_of3,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_of")
    ADD_CLASS_METHOD(find_first_of4,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_of")
    ADD_CLASS_METHOD(find_last_of1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_of")
    ADD_CLASS_METHOD(find_last_of,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_of")
    ADD_CLASS_METHOD(find_last_of2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_of")
    ADD_CLASS_METHOD(find_last_of3,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_of")
    ADD_CLASS_METHOD(find_last_of4,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_of")
    ADD_CLASS_METHOD(find_first_not_of1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_not_of")
    ADD_CLASS_METHOD(find_first_not_of,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_not_of")
    ADD_CLASS_METHOD(find_first_not_of2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_not_of")
    ADD_CLASS_METHOD(find_first_not_of3,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_not_of")
    ADD_CLASS_METHOD(find_first_not_of4,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_not_of")
    ADD_CLASS_METHOD(find_last_not_of1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_not_of")
    ADD_CLASS_METHOD(find_last_not_of,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_not_of")
    ADD_CLASS_METHOD(find_last_not_of2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_not_of")
    ADD_CLASS_METHOD(find_last_not_of3,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_not_of")
    ADD_CLASS_METHOD(find_last_not_of4,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_not_of")
    ADD_CLASS_METHOD(compare1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#compare")
    ADD_CLASS_METHOD(compare,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#compare")
    ADD_CLASS_METHOD(compare2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#compare")
    ADD_CLASS_METHOD(compare3,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#compare")
    ADD_CLASS_METHOD(compare4,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#compare")
    ADD_CLASS_METHOD(compare5,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#compare")
    ADD_CLASS_METHOD(substr,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#substr")

    // Operators:
    ADD_CLASS_METHOD(assign1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#assign")
    ADD_CLASS_METHOD(assign,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#assign")
    ADD_CLASS_METHOD(assign2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#assign")
    ADD_CLASS_METHOD(assign3,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#assign")
    ADD_CLASS_METHOD(add_assign1,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#add_assign")
    ADD_CLASS_METHOD(add_assign,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#add_assign")
    ADD_CLASS_METHOD(add_assign2,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#add_assign")
    ADD_CLASS_METHOD(add_assign3,"http://docs.wxwidgets.org/stable/wx_wxstringbase.html#add_assign")




    void AddMethods(WrapClass<wxStringBase>::ptr this_ptr )
    {
      


      // check that the method name is not a token
      
      // Adding copy method 
      AddVar_copy( this_ptr);
      // Adding standard methods 
      AddVar_length( this_ptr);
      AddVar_size( this_ptr);
      AddVar_max_size( this_ptr);
      AddVar_resize( this_ptr);
      AddVar_clear( this_ptr);
      AddVar_empty( this_ptr);
      AddVar_reserve( this_ptr);
      AddVar_capacity( this_ptr);
      AddVar_at1( this_ptr);
      AddVar_at( this_ptr);
      AddVar_at2( this_ptr);
      AddVar_append1( this_ptr);
      AddVar_append( this_ptr);
      AddVar_append2( this_ptr);
      AddVar_append3( this_ptr);
      AddVar_append4( this_ptr);
      AddVar_append5( this_ptr);
      AddVar_append6( this_ptr);
      AddVar_begin1( this_ptr);
      AddVar_begin( this_ptr);
      AddVar_begin2( this_ptr);
      AddVar_end1( this_ptr);
      AddVar_end( this_ptr);
      AddVar_end2( this_ptr);
/* The following types are missing: const_reverse_iterator
      AddVar_rbegin1( this_ptr);
*/
      AddVar_rbegin( this_ptr);
/* The following types are missing: reverse_iterator
      AddVar_rbegin2( this_ptr);
*/
/* The following types are missing: const_reverse_iterator
      AddVar_rend1( this_ptr);
*/
      AddVar_rend( this_ptr);
/* The following types are missing: reverse_iterator
      AddVar_rend2( this_ptr);
*/
      AddVar_insert1( this_ptr);
      AddVar_insert( this_ptr);
      AddVar_insert2( this_ptr);
      AddVar_insert3( this_ptr);
      AddVar_insert4( this_ptr);
      AddVar_insert5( this_ptr);
      AddVar_insert6( this_ptr);
      AddVar_insert7( this_ptr);
      AddVar_erase1( this_ptr);
      AddVar_erase( this_ptr);
      AddVar_erase2( this_ptr);
      AddVar_erase3( this_ptr);
      AddVar_c_str( this_ptr);
      AddVar_data( this_ptr);
      AddVar_replace1( this_ptr);
      AddVar_replace( this_ptr);
      AddVar_replace2( this_ptr);
      AddVar_replace3( this_ptr);
      AddVar_replace4( this_ptr);
      AddVar_replace5( this_ptr);
      AddVar_replace6( this_ptr);
      AddVar_replace7( this_ptr);
      AddVar_replace8( this_ptr);
      AddVar_replace9( this_ptr);
      AddVar_replace10( this_ptr);
      AddVar_swap( this_ptr);
      AddVar_find1( this_ptr);
      AddVar_find( this_ptr);
      AddVar_find2( this_ptr);
      AddVar_find3( this_ptr);
      AddVar_rfind1( this_ptr);
      AddVar_rfind( this_ptr);
      AddVar_rfind2( this_ptr);
      AddVar_rfind3( this_ptr);
      AddVar_find_first_of1( this_ptr);
      AddVar_find_first_of( this_ptr);
      AddVar_find_first_of2( this_ptr);
      AddVar_find_first_of3( this_ptr);
      AddVar_find_first_of4( this_ptr);
      AddVar_find_last_of1( this_ptr);
      AddVar_find_last_of( this_ptr);
      AddVar_find_last_of2( this_ptr);
      AddVar_find_last_of3( this_ptr);
      AddVar_find_last_of4( this_ptr);
      AddVar_find_first_not_of1( this_ptr);
      AddVar_find_first_not_of( this_ptr);
      AddVar_find_first_not_of2( this_ptr);
      AddVar_find_first_not_of3( this_ptr);
      AddVar_find_first_not_of4( this_ptr);
      AddVar_find_last_not_of1( this_ptr);
      AddVar_find_last_not_of( this_ptr);
      AddVar_find_last_not_of2( this_ptr);
      AddVar_find_last_not_of3( this_ptr);
      AddVar_find_last_not_of4( this_ptr);
      AddVar_compare1( this_ptr);
      AddVar_compare( this_ptr);
      AddVar_compare2( this_ptr);
      AddVar_compare3( this_ptr);
      AddVar_compare4( this_ptr);
      AddVar_compare5( this_ptr);
      AddVar_substr( this_ptr);

      // Adding operators
      AddVar_assign1( this_ptr);
      AddVar_assign( this_ptr);
      AddVar_assign2( this_ptr);
      AddVar_assign3( this_ptr);
      AddVar_add_assign1( this_ptr);
      AddVar_add_assign( this_ptr);
      AddVar_add_assign2( this_ptr);
      AddVar_add_assign3( this_ptr);



      
    };
};


#endif // _wrap_wxStringBase_h
