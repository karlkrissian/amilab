/**
 * C++ Interface: wrap_wxSizerItemList
 *
 * Description: wrapping wxSizerItemList
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxSizerItemList_h_
#define _wrap_wxSizerItemList_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxListBase.h"


#ifndef wxSizerItemList_declared
  #define wxSizerItemList_declared
  AMI_DECLARE_TYPE(wxSizerItemList);
#endif

// TODO: check for inheritence ...
class WrapClass_wxSizerItemList : public WrapClass<wxSizerItemList>
    , public   WrapClass_wxListBase
{
  DEFINE_CLASS(WrapClass_wxSizerItemList);

  protected:
    typedef WrapClass<wxSizerItemList>::ptr _parentclass_ptr;
    typedef wxSizerItemList ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxSizerItemList>& GetObj() const { return WrapClass<wxSizerItemList>::GetObj(); }

    /// Constructor
    WrapClass_wxSizerItemList(boost::shared_ptr<wxSizerItemList > si): 
    WrapClass<wxSizerItemList>(si)
    , WrapClass_wxListBase(si)
    {}

    /// Destructor
    ~WrapClass_wxSizerItemList()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerItemList_1,"Constructor wxSizerItemList::wxSizerItemList(wxKeyType keyType = wxKEY_NONE) (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#wxsizeritemlist).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerItemList,"Constructor wxSizerItemList::wxSizerItemList() (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#wxsizeritemlist).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerItemList_2,"Constructor wxSizerItemList::wxSizerItemList(wxSizerItemList const & list) (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#wxsizeritemlist).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerItemList_3,"Constructor wxSizerItemList::wxSizerItemList(size_t count, wxSizerItem * * elements) (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#wxsizeritemlist).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerItemList_4,"Constructor wxSizerItemList::wxSizerItemList(size_t n, wxSizerItem * const & v = 0u) (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#wxsizeritemlist).");
    /* The following types are missing: const_iterator, const_iterator
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerItemList_5,"Constructor wxSizerItemList::wxSizerItemList(const_iterator const & first, const_iterator const & last) (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#wxsizeritemlist).");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxSizerItemList*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetFirst,"wxwxSizerItemListNode * wxSizerItemList::GetFirst()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#getfirst)")
    ADD_CLASS_METHOD(GetLast,"wxwxSizerItemListNode * wxSizerItemList::GetLast()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#getlast)")
    ADD_CLASS_METHOD(Item,"wxwxSizerItemListNode * wxSizerItemList::Item(size_t index)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#item)")
    ADD_CLASS_METHOD(Append_1,"wxwxSizerItemListNode * wxSizerItemList::Append(wxSizerItem * object)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#append)")
    ADD_CLASS_METHOD(Insert_1,"wxwxSizerItemListNode * wxSizerItemList::Insert(wxSizerItem * object)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#insert)")
    ADD_CLASS_METHOD(Insert,"wxSizerItemList::Insert()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#insert)")
    ADD_CLASS_METHOD(Insert_2,"wxwxSizerItemListNode * wxSizerItemList::Insert(size_t pos, wxSizerItem * object)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#insert)")
    ADD_CLASS_METHOD(Insert_3,"wxwxSizerItemListNode * wxSizerItemList::Insert(wxwxSizerItemListNode * prev, wxSizerItem * object)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#insert)")
    ADD_CLASS_METHOD(Append,"wxSizerItemList::Append()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#append)")
/* The following types are missing: void
    ADD_CLASS_METHOD(Append_2,"wxwxSizerItemListNode * wxSizerItemList::Append(long int key, void * object)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#append)")
*/
/* The following types are missing: void
    ADD_CLASS_METHOD(Append_3,"wxwxSizerItemListNode * wxSizerItemList::Append(wxChar const * key, void * object)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#append)")
*/
    ADD_CLASS_METHOD(DetachNode,"wxwxSizerItemListNode * wxSizerItemList::DetachNode(wxwxSizerItemListNode * node)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#detachnode)")
    ADD_CLASS_METHOD(DeleteNode,"bool wxSizerItemList::DeleteNode(wxwxSizerItemListNode * node)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#deletenode)")
    ADD_CLASS_METHOD(DeleteObject,"bool wxSizerItemList::DeleteObject(wxSizerItem * object)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#deleteobject)")
    ADD_CLASS_METHOD(Erase,"void wxSizerItemList::Erase(wxwxSizerItemListNode * it)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#erase)")
    ADD_CLASS_METHOD(Find_1,"wxwxSizerItemListNode * wxSizerItemList::Find(wxSizerItem const * object)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#find)")
    ADD_CLASS_METHOD(Find,"wxSizerItemList::Find()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#find)")
    ADD_CLASS_METHOD(Find_2,"wxwxSizerItemListNode * wxSizerItemList::Find(wxListKey const & key)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#find)")
    ADD_CLASS_METHOD(IndexOf,"int wxSizerItemList::IndexOf(wxSizerItem * object)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#indexof)")
/* The following types are missing: _17586
    ADD_CLASS_METHOD(Sort_1,"void wxSizerItemList::Sort(wxSortCompareFunction func)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#sort)")
*/
    ADD_CLASS_METHOD(Sort,"wxSizerItemList::Sort()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#sort)")
/* The following types are missing: _8653
    ADD_CLASS_METHOD(Sort_2,"void wxSizerItemList::Sort(wxSortFuncFor_wxSizerItemList func)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#sort)")
*/
/* The following types are missing: iterator
    ADD_CLASS_METHOD(begin_1,"iterator wxSizerItemList::begin()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#begin)")
*/
    ADD_CLASS_METHOD(begin,"wxSizerItemList::begin()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#begin)")
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(begin_2,"const_iterator wxSizerItemList::begin()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#begin)")
*/
/* The following types are missing: iterator
    ADD_CLASS_METHOD(end_1,"iterator wxSizerItemList::end()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#end)")
*/
    ADD_CLASS_METHOD(end,"wxSizerItemList::end()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#end)")
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(end_2,"const_iterator wxSizerItemList::end()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#end)")
*/
/* The following types are missing: reverse_iterator
    ADD_CLASS_METHOD(rbegin_1,"reverse_iterator wxSizerItemList::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#rbegin)")
*/
    ADD_CLASS_METHOD(rbegin,"wxSizerItemList::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#rbegin)")
/* The following types are missing: const_reverse_iterator
    ADD_CLASS_METHOD(rbegin_2,"const_reverse_iterator wxSizerItemList::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#rbegin)")
*/
/* The following types are missing: reverse_iterator
    ADD_CLASS_METHOD(rend_1,"reverse_iterator wxSizerItemList::rend()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#rend)")
*/
    ADD_CLASS_METHOD(rend,"wxSizerItemList::rend()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#rend)")
/* The following types are missing: const_reverse_iterator
    ADD_CLASS_METHOD(rend_2,"const_reverse_iterator wxSizerItemList::rend()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#rend)")
*/
    ADD_CLASS_METHOD(resize,"void wxSizerItemList::resize(size_t n, wxSizerItem * v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#resize)")
    ADD_CLASS_METHOD(size,"size_t wxSizerItemList::size()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#size)")
    ADD_CLASS_METHOD(max_size,"size_t wxSizerItemList::max_size()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#max_size)")
    ADD_CLASS_METHOD(empty,"bool wxSizerItemList::empty()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#empty)")
    ADD_CLASS_METHOD(front_1,"wxSizerItem * & wxSizerItemList::front()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#front)")
    ADD_CLASS_METHOD(front,"wxSizerItemList::front()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#front)")
    ADD_CLASS_METHOD(front_2,"wxSizerItem * const & wxSizerItemList::front()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#front)")
    ADD_CLASS_METHOD(back_1,"wxSizerItem * & wxSizerItemList::back()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#back)")
    ADD_CLASS_METHOD(back,"wxSizerItemList::back()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#back)")
    ADD_CLASS_METHOD(back_2,"wxSizerItem * const & wxSizerItemList::back()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#back)")
    ADD_CLASS_METHOD(push_front,"void wxSizerItemList::push_front(wxSizerItem * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#push_front)")
    ADD_CLASS_METHOD(pop_front,"void wxSizerItemList::pop_front()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#pop_front)")
    ADD_CLASS_METHOD(push_back,"void wxSizerItemList::push_back(wxSizerItem * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#push_back)")
    ADD_CLASS_METHOD(pop_back,"void wxSizerItemList::pop_back()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#pop_back)")
/* The following types are missing: const_iterator, const_iterator
    ADD_CLASS_METHOD(assign_1,"void wxSizerItemList::assign(const_iterator first, const_iterator const & last)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#assign)")
*/
    ADD_CLASS_METHOD(assign,"wxSizerItemList::assign()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#assign)")
    ADD_CLASS_METHOD(assign_2,"void wxSizerItemList::assign(size_t n, wxSizerItem * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#assign)")
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(insert_1,"iterator wxSizerItemList::insert(iterator const & it, wxSizerItem * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#insert)")
*/
    ADD_CLASS_METHOD(insert,"wxSizerItemList::insert()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#insert)")
/* The following types are missing: iterator
    ADD_CLASS_METHOD(insert_2,"void wxSizerItemList::insert(iterator const & it, size_t n, wxSizerItem * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#insert)")
*/
/* The following types are missing: iterator, const_iterator, const_iterator
    ADD_CLASS_METHOD(insert_3,"void wxSizerItemList::insert(iterator const & it, const_iterator first, const_iterator const & last)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#insert)")
*/
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(erase_1,"iterator wxSizerItemList::erase(iterator const & it)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#erase)")
*/
    ADD_CLASS_METHOD(erase,"wxSizerItemList::erase()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#erase)")
/* The following types are missing: iterator, iterator, iterator
    ADD_CLASS_METHOD(erase_2,"iterator wxSizerItemList::erase(iterator const & first, iterator const & last)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#erase)")
*/
    ADD_CLASS_METHOD(clear,"void wxSizerItemList::clear()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#clear)")
/* The following types are missing: iterator, iterator, iterator
    ADD_CLASS_METHOD(splice_1,"void wxSizerItemList::splice(iterator const & it, wxSizerItemList & l, iterator const & first, iterator const & last)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#splice)")
*/
    ADD_CLASS_METHOD(splice,"wxSizerItemList::splice()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#splice)")
/* The following types are missing: iterator
    ADD_CLASS_METHOD(splice_2,"void wxSizerItemList::splice(iterator const & it, wxSizerItemList & l)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#splice)")
*/
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(splice_3,"void wxSizerItemList::splice(iterator const & it, wxSizerItemList & l, iterator const & first)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#splice)")
*/
    ADD_CLASS_METHOD(remove,"void wxSizerItemList::remove(wxSizerItem * const & v)  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#remove)")
    ADD_CLASS_METHOD(reverse,"void wxSizerItemList::reverse()  (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#reverse)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxSizerItemList & wxSizerItemList::operator =(wxSizerItemList const & list) (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#__assign__)")
    ADD_CLASS_METHOD(__at__,            "wxSizerItem * wxSizerItemList::operator [](size_t index) (http://docs.wxwidgets.org/stable/wx_wxsizeritemlist.html#__at__)")




    void AddMethods(WrapClass<wxSizerItemList>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxSizerItemList_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxSizerItemList_h
