/**
 * C++ Interface: wrap_wxMenuItemList
 *
 * Description: wrapping wxMenuItemList
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxMenuItemList_h_
#define _wrap_wxMenuItemList_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxListBase.h"



AMI_DECLARE_TYPE(wxMenuItemList);

// TODO: check for inheritence ...
class WrapClass_wxMenuItemList : public WrapClass<wxMenuItemList>
    , public   WrapClass_wxListBase
{
  DEFINE_CLASS(WrapClass_wxMenuItemList);

  protected:
    typedef WrapClass<wxMenuItemList>::ptr _parentclass_ptr;
    typedef wxMenuItemList ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxMenuItemList>& GetObj() const { return WrapClass<wxMenuItemList>::GetObj(); }

    /// Constructor
    WrapClass_wxMenuItemList(boost::shared_ptr<wxMenuItemList > si): 
    WrapClass<wxMenuItemList>(si)
    , WrapClass_wxListBase(si)
    {}

    /// Destructor
    ~WrapClass_wxMenuItemList()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuItemList_1,"Constructor wxMenuItemList::wxMenuItemList(wxKeyType keyType = wxKEY_NONE) (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#wxmenuitemlist).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuItemList,"Constructor wxMenuItemList::wxMenuItemList() (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#wxmenuitemlist).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuItemList_2,"Constructor wxMenuItemList::wxMenuItemList(wxMenuItemList const & list) (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#wxmenuitemlist).");
    /* The following types are missing: wxMenuItem * *
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuItemList_3,"Constructor wxMenuItemList::wxMenuItemList(size_t count, wxMenuItem * * elements) (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#wxmenuitemlist).");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuItemList_4,"Constructor wxMenuItemList::wxMenuItemList(size_t n, wxMenuItem * const & v = 0u) (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#wxmenuitemlist).");
    /* The following types are missing: const_iterator, const_iterator
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuItemList_5,"Constructor wxMenuItemList::wxMenuItemList(const_iterator const & first, const_iterator const & last) (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#wxmenuitemlist).");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxMenuItemList*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetFirst,"wxwxMenuItemListNode * wxMenuItemList::GetFirst()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#getfirst)")
    ADD_CLASS_METHOD(GetLast,"wxwxMenuItemListNode * wxMenuItemList::GetLast()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#getlast)")
    ADD_CLASS_METHOD(Item,"wxwxMenuItemListNode * wxMenuItemList::Item(size_t index)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#item)")
    ADD_CLASS_METHOD(Append_1,"wxwxMenuItemListNode * wxMenuItemList::Append(wxMenuItem * object)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#append)")
    ADD_CLASS_METHOD(Insert_1,"wxwxMenuItemListNode * wxMenuItemList::Insert(wxMenuItem * object)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#insert)")
    ADD_CLASS_METHOD(Insert,"wxMenuItemList::Insert()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#insert)")
    ADD_CLASS_METHOD(Insert_2,"wxwxMenuItemListNode * wxMenuItemList::Insert(size_t pos, wxMenuItem * object)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#insert)")
    ADD_CLASS_METHOD(Insert_3,"wxwxMenuItemListNode * wxMenuItemList::Insert(wxwxMenuItemListNode * prev, wxMenuItem * object)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#insert)")
    ADD_CLASS_METHOD(Append,"wxMenuItemList::Append()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#append)")
/* The following types are missing: void
    ADD_CLASS_METHOD(Append_2,"wxwxMenuItemListNode * wxMenuItemList::Append(long int key, void * object)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#append)")
*/
/* The following types are missing: void
    ADD_CLASS_METHOD(Append_3,"wxwxMenuItemListNode * wxMenuItemList::Append(wxChar const * key, void * object)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#append)")
*/
    ADD_CLASS_METHOD(DetachNode,"wxwxMenuItemListNode * wxMenuItemList::DetachNode(wxwxMenuItemListNode * node)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#detachnode)")
    ADD_CLASS_METHOD(DeleteNode,"bool wxMenuItemList::DeleteNode(wxwxMenuItemListNode * node)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#deletenode)")
    ADD_CLASS_METHOD(DeleteObject,"bool wxMenuItemList::DeleteObject(wxMenuItem * object)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#deleteobject)")
    ADD_CLASS_METHOD(Erase,"void wxMenuItemList::Erase(wxwxMenuItemListNode * it)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#erase)")
    ADD_CLASS_METHOD(Find_1,"wxwxMenuItemListNode * wxMenuItemList::Find(wxMenuItem const * object)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#find)")
    ADD_CLASS_METHOD(Find,"wxMenuItemList::Find()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#find)")
    ADD_CLASS_METHOD(Find_2,"wxwxMenuItemListNode * wxMenuItemList::Find(wxListKey const & key)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#find)")
    ADD_CLASS_METHOD(IndexOf,"int wxMenuItemList::IndexOf(wxMenuItem * object)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#indexof)")
/* The following types are missing: _9904
    ADD_CLASS_METHOD(Sort_1,"void wxMenuItemList::Sort(wxSortCompareFunction func)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#sort)")
*/
    ADD_CLASS_METHOD(Sort,"wxMenuItemList::Sort()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#sort)")
/* The following types are missing: _8388
    ADD_CLASS_METHOD(Sort_2,"void wxMenuItemList::Sort(wxSortFuncFor_wxMenuItemList func)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#sort)")
*/
/* The following types are missing: iterator
    ADD_CLASS_METHOD(begin_1,"iterator wxMenuItemList::begin()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#begin)")
*/
    ADD_CLASS_METHOD(begin,"wxMenuItemList::begin()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#begin)")
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(begin_2,"const_iterator wxMenuItemList::begin()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#begin)")
*/
/* The following types are missing: iterator
    ADD_CLASS_METHOD(end_1,"iterator wxMenuItemList::end()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#end)")
*/
    ADD_CLASS_METHOD(end,"wxMenuItemList::end()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#end)")
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(end_2,"const_iterator wxMenuItemList::end()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#end)")
*/
/* The following types are missing: reverse_iterator
    ADD_CLASS_METHOD(rbegin_1,"reverse_iterator wxMenuItemList::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#rbegin)")
*/
    ADD_CLASS_METHOD(rbegin,"wxMenuItemList::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#rbegin)")
/* The following types are missing: const_reverse_iterator
    ADD_CLASS_METHOD(rbegin_2,"const_reverse_iterator wxMenuItemList::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#rbegin)")
*/
/* The following types are missing: reverse_iterator
    ADD_CLASS_METHOD(rend_1,"reverse_iterator wxMenuItemList::rend()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#rend)")
*/
    ADD_CLASS_METHOD(rend,"wxMenuItemList::rend()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#rend)")
/* The following types are missing: const_reverse_iterator
    ADD_CLASS_METHOD(rend_2,"const_reverse_iterator wxMenuItemList::rend()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#rend)")
*/
    ADD_CLASS_METHOD(resize,"void wxMenuItemList::resize(size_t n, wxMenuItem * v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#resize)")
    ADD_CLASS_METHOD(size,"size_t wxMenuItemList::size()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#size)")
    ADD_CLASS_METHOD(max_size,"size_t wxMenuItemList::max_size()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#max_size)")
    ADD_CLASS_METHOD(empty,"bool wxMenuItemList::empty()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#empty)")
    ADD_CLASS_METHOD(front_1,"wxMenuItem * & wxMenuItemList::front()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#front)")
    ADD_CLASS_METHOD(front,"wxMenuItemList::front()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#front)")
    ADD_CLASS_METHOD(front_2,"wxMenuItem * const & wxMenuItemList::front()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#front)")
    ADD_CLASS_METHOD(back_1,"wxMenuItem * & wxMenuItemList::back()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#back)")
    ADD_CLASS_METHOD(back,"wxMenuItemList::back()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#back)")
    ADD_CLASS_METHOD(back_2,"wxMenuItem * const & wxMenuItemList::back()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#back)")
    ADD_CLASS_METHOD(push_front,"void wxMenuItemList::push_front(wxMenuItem * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#push_front)")
    ADD_CLASS_METHOD(pop_front,"void wxMenuItemList::pop_front()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#pop_front)")
    ADD_CLASS_METHOD(push_back,"void wxMenuItemList::push_back(wxMenuItem * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#push_back)")
    ADD_CLASS_METHOD(pop_back,"void wxMenuItemList::pop_back()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#pop_back)")
/* The following types are missing: const_iterator, const_iterator
    ADD_CLASS_METHOD(assign_1,"void wxMenuItemList::assign(const_iterator first, const_iterator const & last)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#assign)")
*/
    ADD_CLASS_METHOD(assign,"wxMenuItemList::assign()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#assign)")
    ADD_CLASS_METHOD(assign_2,"void wxMenuItemList::assign(size_t n, wxMenuItem * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#assign)")
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(insert_1,"iterator wxMenuItemList::insert(iterator const & it, wxMenuItem * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#insert)")
*/
    ADD_CLASS_METHOD(insert,"wxMenuItemList::insert()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#insert)")
/* The following types are missing: iterator
    ADD_CLASS_METHOD(insert_2,"void wxMenuItemList::insert(iterator const & it, size_t n, wxMenuItem * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#insert)")
*/
/* The following types are missing: iterator, const_iterator, const_iterator
    ADD_CLASS_METHOD(insert_3,"void wxMenuItemList::insert(iterator const & it, const_iterator first, const_iterator const & last)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#insert)")
*/
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(erase_1,"iterator wxMenuItemList::erase(iterator const & it)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#erase)")
*/
    ADD_CLASS_METHOD(erase,"wxMenuItemList::erase()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#erase)")
/* The following types are missing: iterator, iterator, iterator
    ADD_CLASS_METHOD(erase_2,"iterator wxMenuItemList::erase(iterator const & first, iterator const & last)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#erase)")
*/
    ADD_CLASS_METHOD(clear,"void wxMenuItemList::clear()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#clear)")
/* The following types are missing: iterator, iterator, iterator
    ADD_CLASS_METHOD(splice_1,"void wxMenuItemList::splice(iterator const & it, wxMenuItemList & l, iterator const & first, iterator const & last)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#splice)")
*/
    ADD_CLASS_METHOD(splice,"wxMenuItemList::splice()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#splice)")
/* The following types are missing: iterator
    ADD_CLASS_METHOD(splice_2,"void wxMenuItemList::splice(iterator const & it, wxMenuItemList & l)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#splice)")
*/
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(splice_3,"void wxMenuItemList::splice(iterator const & it, wxMenuItemList & l, iterator const & first)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#splice)")
*/
    ADD_CLASS_METHOD(remove,"void wxMenuItemList::remove(wxMenuItem * const & v)  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#remove)")
    ADD_CLASS_METHOD(reverse,"void wxMenuItemList::reverse()  (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#reverse)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxMenuItemList & wxMenuItemList::operator =(wxMenuItemList const & list) (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#__assign__)")
    ADD_CLASS_METHOD(__at__,            "wxMenuItem * wxMenuItemList::operator [](size_t index) (http://docs.wxwidgets.org/stable/wx_wxmenuitemlist.html#__at__)")




    void AddMethods(WrapClass<wxMenuItemList>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxMenuItemList_h
