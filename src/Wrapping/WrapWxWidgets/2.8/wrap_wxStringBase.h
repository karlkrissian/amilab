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

#include "wx_includes.h"

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
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase_1,"Constructor wxStringBase::wxStringBase() (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase,"Constructor wxStringBase::wxStringBase() (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase_2,"Constructor wxStringBase::wxStringBase(wxStringBase const & stringSrc) (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase_3,"Constructor wxStringBase::wxStringBase(size_t nRepeat, wxChar ch) (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase_4,"Constructor wxStringBase::wxStringBase(wxChar const * psz) (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase_5,"Constructor wxStringBase::wxStringBase(wxChar const * psz, size_t nLength) (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase_6,"Constructor wxStringBase::wxStringBase(wxChar const * psz, wxMBConv const & param1, size_t nLength = wxStringBase::npos) (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase_7,"Constructor wxStringBase::wxStringBase(wxStringBase const & str, size_t nPos, size_t nLen) (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase).");
    /* The following types are missing: void, void
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStringBase_8,"Constructor wxStringBase::wxStringBase(void const * pStart, void const * pEnd) (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#wxstringbase).");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxStringBase*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(length,"size_t wxStringBase::length()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#length)")
    ADD_CLASS_METHOD(size,"size_t wxStringBase::size()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#size)")
    ADD_CLASS_METHOD(max_size,"size_t wxStringBase::max_size()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#max_size)")
    ADD_CLASS_METHOD(resize,"void wxStringBase::resize(size_t nSize, wxChar ch = 0)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#resize)")
    ADD_CLASS_METHOD(clear,"void wxStringBase::clear()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#clear)")
    ADD_CLASS_METHOD(empty,"bool wxStringBase::empty()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#empty)")
    ADD_CLASS_METHOD(reserve,"void wxStringBase::reserve(size_t sz)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#reserve)")
    ADD_CLASS_METHOD(capacity,"size_t wxStringBase::capacity()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#capacity)")
    ADD_CLASS_METHOD(at_1,"wxChar wxStringBase::at(size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#at)")
    ADD_CLASS_METHOD(at,"wxStringBase::at()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#at)")
    ADD_CLASS_METHOD(at_2,"wxChar & wxStringBase::at(size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#at)")
    ADD_CLASS_METHOD(append_1,"wxStringBase & wxStringBase::append(wxStringBase const & str, size_t pos, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#append)")
    ADD_CLASS_METHOD(append,"wxStringBase::append()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#append)")
    ADD_CLASS_METHOD(append_2,"wxStringBase & wxStringBase::append(wxStringBase const & str)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#append)")
    ADD_CLASS_METHOD(append_3,"wxStringBase & wxStringBase::append(wxChar const * sz)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#append)")
    ADD_CLASS_METHOD(append_4,"wxStringBase & wxStringBase::append(wxChar const * sz, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#append)")
    ADD_CLASS_METHOD(append_5,"wxStringBase & wxStringBase::append(size_t n, wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#append)")
    ADD_CLASS_METHOD(append_6,"wxStringBase & wxStringBase::append(wxChar const * first, wxChar const * last)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#append)")
    ADD_CLASS_METHOD(assign_1,"wxStringBase & wxStringBase::assign(wxStringBase const & str)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#assign)")
    ADD_CLASS_METHOD(assign,"wxStringBase::assign()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#assign)")
    ADD_CLASS_METHOD(assign_2,"wxStringBase & wxStringBase::assign(wxStringBase const & str, size_t pos, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#assign)")
    ADD_CLASS_METHOD(assign_3,"wxStringBase & wxStringBase::assign(wxChar const * sz)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#assign)")
    ADD_CLASS_METHOD(assign_4,"wxStringBase & wxStringBase::assign(wxChar const * sz, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#assign)")
    ADD_CLASS_METHOD(assign_5,"wxStringBase & wxStringBase::assign(size_t n, wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#assign)")
    ADD_CLASS_METHOD(assign_6,"wxStringBase & wxStringBase::assign(wxChar const * first, wxChar const * last)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#assign)")
    ADD_CLASS_METHOD(begin_1,"wxChar const * wxStringBase::begin()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#begin)")
    ADD_CLASS_METHOD(begin,"wxStringBase::begin()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#begin)")
    ADD_CLASS_METHOD(begin_2,"wxChar * wxStringBase::begin()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#begin)")
    ADD_CLASS_METHOD(end_1,"wxChar const * wxStringBase::end()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#end)")
    ADD_CLASS_METHOD(end,"wxStringBase::end()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#end)")
    ADD_CLASS_METHOD(end_2,"wxChar * wxStringBase::end()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#end)")
/* The following types are missing: const_reverse_iterator
    ADD_CLASS_METHOD(rbegin_1,"const_reverse_iterator wxStringBase::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rbegin)")
*/
    ADD_CLASS_METHOD(rbegin,"wxStringBase::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rbegin)")
/* The following types are missing: reverse_iterator
    ADD_CLASS_METHOD(rbegin_2,"reverse_iterator wxStringBase::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rbegin)")
*/
/* The following types are missing: const_reverse_iterator
    ADD_CLASS_METHOD(rend_1,"const_reverse_iterator wxStringBase::rend()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rend)")
*/
    ADD_CLASS_METHOD(rend,"wxStringBase::rend()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rend)")
/* The following types are missing: reverse_iterator
    ADD_CLASS_METHOD(rend_2,"reverse_iterator wxStringBase::rend()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rend)")
*/
    ADD_CLASS_METHOD(insert_1,"wxStringBase & wxStringBase::insert(size_t nPos, wxStringBase const & str)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#insert)")
    ADD_CLASS_METHOD(insert,"wxStringBase::insert()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#insert)")
    ADD_CLASS_METHOD(insert_2,"wxStringBase & wxStringBase::insert(size_t nPos, wxStringBase const & str, size_t nStart, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#insert)")
    ADD_CLASS_METHOD(insert_3,"wxStringBase & wxStringBase::insert(size_t nPos, wxChar const * sz, size_t n = wxStringBase::npos)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#insert)")
    ADD_CLASS_METHOD(insert_4,"wxStringBase & wxStringBase::insert(size_t nPos, size_t n, wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#insert)")
    ADD_CLASS_METHOD(insert_5,"wxChar * wxStringBase::insert(wxChar * it, wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#insert)")
    ADD_CLASS_METHOD(insert_6,"void wxStringBase::insert(wxChar * it, wxChar const * first, wxChar const * last)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#insert)")
    ADD_CLASS_METHOD(insert_7,"void wxStringBase::insert(wxChar * it, size_t n, wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#insert)")
    ADD_CLASS_METHOD(erase_1,"wxStringBase & wxStringBase::erase(size_t pos = 0, size_t n = wxStringBase::npos)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#erase)")
    ADD_CLASS_METHOD(erase,"wxStringBase::erase()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#erase)")
    ADD_CLASS_METHOD(erase_2,"wxChar * wxStringBase::erase(wxChar * first, wxChar * last)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#erase)")
    ADD_CLASS_METHOD(erase_3,"wxChar * wxStringBase::erase(wxChar * first)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#erase)")
    ADD_CLASS_METHOD(c_str,"wxChar const * wxStringBase::c_str()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#c_str)")
    ADD_CLASS_METHOD(data,"wxChar const * wxStringBase::data()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#data)")
    ADD_CLASS_METHOD(replace_1,"wxStringBase & wxStringBase::replace(size_t nStart, size_t nLen, wxChar const * sz)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace)")
    ADD_CLASS_METHOD(replace,"wxStringBase::replace()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace)")
    ADD_CLASS_METHOD(replace_2,"wxStringBase & wxStringBase::replace(size_t nStart, size_t nLen, wxStringBase const & str)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace)")
    ADD_CLASS_METHOD(replace_3,"wxStringBase & wxStringBase::replace(size_t nStart, size_t nLen, size_t nCount, wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace)")
    ADD_CLASS_METHOD(replace_4,"wxStringBase & wxStringBase::replace(size_t nStart, size_t nLen, wxStringBase const & str, size_t nStart2, size_t nLen2)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace)")
    ADD_CLASS_METHOD(replace_5,"wxStringBase & wxStringBase::replace(size_t nStart, size_t nLen, wxChar const * sz, size_t nCount)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace)")
    ADD_CLASS_METHOD(replace_6,"wxStringBase & wxStringBase::replace(wxChar * first, wxChar * last, wxChar const * s)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace)")
    ADD_CLASS_METHOD(replace_7,"wxStringBase & wxStringBase::replace(wxChar * first, wxChar * last, wxChar const * s, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace)")
    ADD_CLASS_METHOD(replace_8,"wxStringBase & wxStringBase::replace(wxChar * first, wxChar * last, wxStringBase const & s)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace)")
    ADD_CLASS_METHOD(replace_9,"wxStringBase & wxStringBase::replace(wxChar * first, wxChar * last, size_t n, wxChar c)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace)")
    ADD_CLASS_METHOD(replace_10,"wxStringBase & wxStringBase::replace(wxChar * first, wxChar * last, wxChar const * first1, wxChar const * last1)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#replace)")
    ADD_CLASS_METHOD(swap,"void wxStringBase::swap(wxStringBase & str)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#swap)")
    ADD_CLASS_METHOD(find_1,"size_t wxStringBase::find(wxStringBase const & str, size_t nStart = 0)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find)")
    ADD_CLASS_METHOD(find,"wxStringBase::find()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find)")
    ADD_CLASS_METHOD(find_2,"size_t wxStringBase::find(wxChar const * sz, size_t nStart = 0, size_t n = wxStringBase::npos)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find)")
    ADD_CLASS_METHOD(find_3,"size_t wxStringBase::find(wxChar ch, size_t nStart = 0)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find)")
    ADD_CLASS_METHOD(rfind_1,"size_t wxStringBase::rfind(wxStringBase const & str, size_t nStart = wxStringBase::npos)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rfind)")
    ADD_CLASS_METHOD(rfind,"wxStringBase::rfind()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rfind)")
    ADD_CLASS_METHOD(rfind_2,"size_t wxStringBase::rfind(wxChar const * sz, size_t nStart = wxStringBase::npos, size_t n = wxStringBase::npos)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rfind)")
    ADD_CLASS_METHOD(rfind_3,"size_t wxStringBase::rfind(wxChar ch, size_t nStart = wxStringBase::npos)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#rfind)")
    ADD_CLASS_METHOD(find_first_of_1,"size_t wxStringBase::find_first_of(wxStringBase const & str, size_t nStart = 0)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_of)")
    ADD_CLASS_METHOD(find_first_of,"wxStringBase::find_first_of()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_of)")
    ADD_CLASS_METHOD(find_first_of_2,"size_t wxStringBase::find_first_of(wxChar const * sz, size_t nStart = 0)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_of)")
    ADD_CLASS_METHOD(find_first_of_3,"size_t wxStringBase::find_first_of(wxChar const * sz, size_t nStart, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_of)")
    ADD_CLASS_METHOD(find_first_of_4,"size_t wxStringBase::find_first_of(wxChar c, size_t nStart = 0)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_of)")
    ADD_CLASS_METHOD(find_last_of_1,"size_t wxStringBase::find_last_of(wxStringBase const & str, size_t nStart = wxStringBase::npos)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_of)")
    ADD_CLASS_METHOD(find_last_of,"wxStringBase::find_last_of()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_of)")
    ADD_CLASS_METHOD(find_last_of_2,"size_t wxStringBase::find_last_of(wxChar const * sz, size_t nStart = wxStringBase::npos)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_of)")
    ADD_CLASS_METHOD(find_last_of_3,"size_t wxStringBase::find_last_of(wxChar const * sz, size_t nStart, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_of)")
    ADD_CLASS_METHOD(find_last_of_4,"size_t wxStringBase::find_last_of(wxChar c, size_t nStart = wxStringBase::npos)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_of)")
    ADD_CLASS_METHOD(find_first_not_of_1,"size_t wxStringBase::find_first_not_of(wxStringBase const & str, size_t nStart = 0)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_not_of)")
    ADD_CLASS_METHOD(find_first_not_of,"wxStringBase::find_first_not_of()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_not_of)")
    ADD_CLASS_METHOD(find_first_not_of_2,"size_t wxStringBase::find_first_not_of(wxChar const * sz, size_t nStart = 0)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_not_of)")
    ADD_CLASS_METHOD(find_first_not_of_3,"size_t wxStringBase::find_first_not_of(wxChar const * sz, size_t nStart, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_not_of)")
    ADD_CLASS_METHOD(find_first_not_of_4,"size_t wxStringBase::find_first_not_of(wxChar ch, size_t nStart = 0)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_first_not_of)")
    ADD_CLASS_METHOD(find_last_not_of_1,"size_t wxStringBase::find_last_not_of(wxStringBase const & str, size_t nStart = wxStringBase::npos)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_not_of)")
    ADD_CLASS_METHOD(find_last_not_of,"wxStringBase::find_last_not_of()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_not_of)")
    ADD_CLASS_METHOD(find_last_not_of_2,"size_t wxStringBase::find_last_not_of(wxChar const * sz, size_t nStart = wxStringBase::npos)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_not_of)")
    ADD_CLASS_METHOD(find_last_not_of_3,"size_t wxStringBase::find_last_not_of(wxChar const * sz, size_t nStart, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_not_of)")
    ADD_CLASS_METHOD(find_last_not_of_4,"size_t wxStringBase::find_last_not_of(wxChar ch, size_t nStart = wxStringBase::npos)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#find_last_not_of)")
    ADD_CLASS_METHOD(compare_1,"int wxStringBase::compare(wxStringBase const & str)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#compare)")
    ADD_CLASS_METHOD(compare,"wxStringBase::compare()  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#compare)")
    ADD_CLASS_METHOD(compare_2,"int wxStringBase::compare(size_t nStart, size_t nLen, wxStringBase const & str)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#compare)")
    ADD_CLASS_METHOD(compare_3,"int wxStringBase::compare(size_t nStart, size_t nLen, wxStringBase const & str, size_t nStart2, size_t nLen2)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#compare)")
    ADD_CLASS_METHOD(compare_4,"int wxStringBase::compare(wxChar const * sz)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#compare)")
    ADD_CLASS_METHOD(compare_5,"int wxStringBase::compare(size_t nStart, size_t nLen, wxChar const * sz, size_t nCount = wxStringBase::npos)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#compare)")
    ADD_CLASS_METHOD(substr,"wxStringBase wxStringBase::substr(size_t nStart = 0, size_t nLen = wxStringBase::npos)  (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#substr)")

    // Operators:
    ADD_CLASS_METHOD(__assign___1,            "wxStringBase & wxStringBase::operator =(wxStringBase const & stringSrc) (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#__assign__)")
    ADD_CLASS_METHOD(__assign__,            "wxStringBase::operator =() (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#__assign__)")
    ADD_CLASS_METHOD(__assign___2,            "wxStringBase & wxStringBase::operator =(wxChar ch) (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#__assign__)")
    ADD_CLASS_METHOD(__assign___3,            "wxStringBase & wxStringBase::operator =(wxChar const * psz) (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#__assign__)")
    ADD_CLASS_METHOD(__add_assign___1,            "wxStringBase & wxStringBase::operator +=(wxStringBase const & s) (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#__add_assign__)")
    ADD_CLASS_METHOD(__add_assign__,            "wxStringBase::operator +=() (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#__add_assign__)")
    ADD_CLASS_METHOD(__add_assign___2,            "wxStringBase & wxStringBase::operator +=(wxChar const * psz) (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#__add_assign__)")
    ADD_CLASS_METHOD(__add_assign___3,            "wxStringBase & wxStringBase::operator +=(wxChar ch) (http://docs.wxwidgets.org/stable/wx_wxstringbase.html#__add_assign__)")




    void AddMethods(WrapClass<wxStringBase>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxStringBase_h
