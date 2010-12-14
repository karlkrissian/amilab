/**
 * C++ Interface: wrap_wxArrayInt
 *
 * Description: wrapping wxArrayInt
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxArrayInt_h_
#define _wrap_wxArrayInt_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxBaseArrayInt.h"


#ifndef wxArrayInt_declared
  #define wxArrayInt_declared
  AMI_DECLARE_TYPE(wxArrayInt);
#endif

// TODO: check for inheritence ...
class WrapClass_wxArrayInt : public WrapClass<wxArrayInt>
    , public   WrapClass_wxBaseArrayInt
{
  DEFINE_CLASS(WrapClass_wxArrayInt);

  protected:
    typedef WrapClass<wxArrayInt>::ptr _parentclass_ptr;
    typedef wxArrayInt ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxArrayInt>& GetObj() const { return WrapClass<wxArrayInt>::GetObj(); }

    /// Constructor
    WrapClass_wxArrayInt(boost::shared_ptr<wxArrayInt > si): 
    WrapClass<wxArrayInt>(si)
    , WrapClass_wxBaseArrayInt(si)
    {}

    /// Destructor
    ~WrapClass_wxArrayInt()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxArrayInt_1,"Constructor wxArrayInt::wxArrayInt(wxArrayInt const & param0) (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#wxarrayint).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxArrayInt,"Constructor wxArrayInt::wxArrayInt() (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#wxarrayint).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxArrayInt_2,"Constructor wxArrayInt::wxArrayInt() (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#wxarrayint).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxArrayInt_3,"Constructor wxArrayInt::wxArrayInt(size_t n, _wxArraywxArrayInt const & v) (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#wxarrayint).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxArrayInt_4,"Constructor wxArrayInt::wxArrayInt(_wxArraywxArrayInt const * first, _wxArraywxArrayInt const * last) (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#wxarrayint).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxArrayInt*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Item,"_wxArraywxArrayInt & wxArrayInt::Item(size_t uiIndex)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#item)")
    ADD_CLASS_METHOD(Last,"_wxArraywxArrayInt & wxArrayInt::Last()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#last)")
    ADD_CLASS_METHOD(Index,"int wxArrayInt::Index(_wxArraywxArrayInt lItem, bool bFromEnd = false)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#index)")
    ADD_CLASS_METHOD(Add,"void wxArrayInt::Add(_wxArraywxArrayInt lItem, size_t nInsert = 1)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#add)")
    ADD_CLASS_METHOD(Insert,"void wxArrayInt::Insert(_wxArraywxArrayInt lItem, size_t uiIndex, size_t nInsert = 1)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#insert)")
    ADD_CLASS_METHOD(RemoveAt,"void wxArrayInt::RemoveAt(size_t uiIndex, size_t nRemove = 1)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#removeat)")
    ADD_CLASS_METHOD(Remove,"void wxArrayInt::Remove(_wxArraywxArrayInt lItem)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#remove)")
/* The following types are missing: _18243
    ADD_CLASS_METHOD(Sort,"void wxArrayInt::Sort(CMPFUNC_wxArraywxArrayInt fCmp)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#sort)")
*/
    ADD_CLASS_METHOD(assign_1,"void wxArrayInt::assign(_wxArraywxArrayInt const * first, _wxArraywxArrayInt const * last)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#assign)")
    ADD_CLASS_METHOD(assign,"wxArrayInt::assign()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#assign)")
    ADD_CLASS_METHOD(assign_2,"void wxArrayInt::assign(size_t n, _wxArraywxArrayInt const & v)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#assign)")
    ADD_CLASS_METHOD(back_1,"_wxArraywxArrayInt & wxArrayInt::back()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#back)")
    ADD_CLASS_METHOD(back,"wxArrayInt::back()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#back)")
    ADD_CLASS_METHOD(back_2,"_wxArraywxArrayInt const & wxArrayInt::back()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#back)")
    ADD_CLASS_METHOD(begin_1,"_wxArraywxArrayInt * wxArrayInt::begin()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#begin)")
    ADD_CLASS_METHOD(begin,"wxArrayInt::begin()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#begin)")
    ADD_CLASS_METHOD(begin_2,"_wxArraywxArrayInt const * wxArrayInt::begin()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#begin)")
    ADD_CLASS_METHOD(capacity,"size_t wxArrayInt::capacity()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#capacity)")
    ADD_CLASS_METHOD(end_1,"_wxArraywxArrayInt * wxArrayInt::end()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#end)")
    ADD_CLASS_METHOD(end,"wxArrayInt::end()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#end)")
    ADD_CLASS_METHOD(end_2,"_wxArraywxArrayInt const * wxArrayInt::end()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#end)")
    ADD_CLASS_METHOD(erase_1,"_wxArraywxArrayInt * wxArrayInt::erase(_wxArraywxArrayInt * first, _wxArraywxArrayInt * last)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#erase)")
    ADD_CLASS_METHOD(erase,"wxArrayInt::erase()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#erase)")
    ADD_CLASS_METHOD(erase_2,"_wxArraywxArrayInt * wxArrayInt::erase(_wxArraywxArrayInt * it)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#erase)")
    ADD_CLASS_METHOD(front_1,"_wxArraywxArrayInt & wxArrayInt::front()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#front)")
    ADD_CLASS_METHOD(front,"wxArrayInt::front()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#front)")
    ADD_CLASS_METHOD(front_2,"_wxArraywxArrayInt const & wxArrayInt::front()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#front)")
    ADD_CLASS_METHOD(insert_1,"void wxArrayInt::insert(_wxArraywxArrayInt * it, size_t n, _wxArraywxArrayInt const & v)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#insert)")
    ADD_CLASS_METHOD(insert,"wxArrayInt::insert()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#insert)")
    ADD_CLASS_METHOD(insert_2,"_wxArraywxArrayInt * wxArrayInt::insert(_wxArraywxArrayInt * it, _wxArraywxArrayInt const & v = 0)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#insert)")
    ADD_CLASS_METHOD(insert_3,"void wxArrayInt::insert(_wxArraywxArrayInt * it, _wxArraywxArrayInt const * first, _wxArraywxArrayInt const * last)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#insert)")
    ADD_CLASS_METHOD(pop_back,"void wxArrayInt::pop_back()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#pop_back)")
    ADD_CLASS_METHOD(push_back,"void wxArrayInt::push_back(_wxArraywxArrayInt const & v)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#push_back)")
/* The following types are missing: reverse_iterator
    ADD_CLASS_METHOD(rbegin_1,"reverse_iterator wxArrayInt::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#rbegin)")
*/
    ADD_CLASS_METHOD(rbegin,"wxArrayInt::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#rbegin)")
/* The following types are missing: const_reverse_iterator
    ADD_CLASS_METHOD(rbegin_2,"const_reverse_iterator wxArrayInt::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#rbegin)")
*/
/* The following types are missing: reverse_iterator
    ADD_CLASS_METHOD(rend_1,"reverse_iterator wxArrayInt::rend()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#rend)")
*/
    ADD_CLASS_METHOD(rend,"wxArrayInt::rend()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#rend)")
/* The following types are missing: const_reverse_iterator
    ADD_CLASS_METHOD(rend_2,"const_reverse_iterator wxArrayInt::rend()  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#rend)")
*/
    ADD_CLASS_METHOD(reserve,"void wxArrayInt::reserve(size_t n)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#reserve)")
    ADD_CLASS_METHOD(resize,"void wxArrayInt::resize(size_t n, _wxArraywxArrayInt v = 0)  (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#resize)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxArrayInt & wxArrayInt::operator =(wxArrayInt const & src) (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#__assign__)")
    ADD_CLASS_METHOD(__at__,            "_wxArraywxArrayInt & wxArrayInt::operator [](size_t uiIndex) (http://docs.wxwidgets.org/stable/wx_wxarrayint.html#__at__)")




    void AddMethods(WrapClass<wxArrayInt>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxArrayInt_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxArrayInt_h
