/**
 * C++ Interface: wrap_wxWindowList
 *
 * Description: wrapping wxWindowList
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxWindowList_h_
#define _wrap_wxWindowList_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxListBase.h"



AMI_DECLARE_TYPE(wxWindowList);

// TODO: check for inheritence ...
class WrapClass_wxWindowList : public WrapClass<wxWindowList>
    , public   WrapClass_wxListBase
{
  DEFINE_CLASS(WrapClass_wxWindowList);

  protected:
    typedef WrapClass<wxWindowList>::ptr _parentclass_ptr;
    typedef wxWindowList ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxWindowList>& GetObj() const { return WrapClass<wxWindowList>::GetObj(); }

    /// Constructor
    WrapClass_wxWindowList(boost::shared_ptr<wxWindowList > si): 
    WrapClass<wxWindowList>(si)
    , WrapClass_wxListBase(si)
    {}

    /// Destructor
    ~WrapClass_wxWindowList()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWindowList_1,"Constructor wxWindowList::wxWindowList(wxKeyType keyType = wxKEY_NONE) (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#wxwindowlist).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWindowList,"Constructor wxWindowList::wxWindowList() (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#wxwindowlist).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWindowList_2,"Constructor wxWindowList::wxWindowList(wxWindowList const & list) (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#wxwindowlist).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWindowList_3,"Constructor wxWindowList::wxWindowList(size_t count, wxWindow * * elements) (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#wxwindowlist).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWindowList_4,"Constructor wxWindowList::wxWindowList(size_t n, wxWindow * const & v = 0u) (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#wxwindowlist).");
    /* The following types are missing: const_iterator, const_iterator
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWindowList_5,"Constructor wxWindowList::wxWindowList(const_iterator const & first, const_iterator const & last) (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#wxwindowlist).");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxWindowList*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetFirst,"wxWindowListNode * wxWindowList::GetFirst()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#getfirst)")
    ADD_CLASS_METHOD(GetLast,"wxWindowListNode * wxWindowList::GetLast()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#getlast)")
    ADD_CLASS_METHOD(Item,"wxWindowListNode * wxWindowList::Item(size_t index)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#item)")
    ADD_CLASS_METHOD(Append_1,"wxWindowListNode * wxWindowList::Append(wxWindowBase * object)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#append)")
    ADD_CLASS_METHOD(Insert_1,"wxWindowListNode * wxWindowList::Insert(wxWindowBase * object)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#insert)")
    ADD_CLASS_METHOD(Insert,"wxWindowList::Insert()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#insert)")
    ADD_CLASS_METHOD(Insert_2,"wxWindowListNode * wxWindowList::Insert(size_t pos, wxWindowBase * object)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#insert)")
    ADD_CLASS_METHOD(Insert_3,"wxWindowListNode * wxWindowList::Insert(wxWindowListNode * prev, wxWindowBase * object)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#insert)")
    ADD_CLASS_METHOD(Append,"wxWindowList::Append()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#append)")
/* The following types are missing: void
    ADD_CLASS_METHOD(Append_2,"wxWindowListNode * wxWindowList::Append(long int key, void * object)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#append)")
*/
/* The following types are missing: void
    ADD_CLASS_METHOD(Append_3,"wxWindowListNode * wxWindowList::Append(wxChar const * key, void * object)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#append)")
*/
    ADD_CLASS_METHOD(DetachNode,"wxWindowListNode * wxWindowList::DetachNode(wxWindowListNode * node)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#detachnode)")
    ADD_CLASS_METHOD(DeleteNode,"bool wxWindowList::DeleteNode(wxWindowListNode * node)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#deletenode)")
    ADD_CLASS_METHOD(DeleteObject,"bool wxWindowList::DeleteObject(wxWindowBase * object)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#deleteobject)")
    ADD_CLASS_METHOD(Erase,"void wxWindowList::Erase(wxWindowListNode * it)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#erase)")
    ADD_CLASS_METHOD(Find_1,"wxWindowListNode * wxWindowList::Find(wxWindowBase const * object)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#find)")
    ADD_CLASS_METHOD(Find,"wxWindowList::Find()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#find)")
    ADD_CLASS_METHOD(Find_2,"wxWindowListNode * wxWindowList::Find(wxListKey const & key)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#find)")
    ADD_CLASS_METHOD(IndexOf,"int wxWindowList::IndexOf(wxWindowBase * object)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#indexof)")
/* The following types are missing: _9505
    ADD_CLASS_METHOD(Sort_1,"void wxWindowList::Sort(wxSortCompareFunction func)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#sort)")
*/
    ADD_CLASS_METHOD(Sort,"wxWindowList::Sort()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#sort)")
/* The following types are missing: _10213
    ADD_CLASS_METHOD(Sort_2,"void wxWindowList::Sort(wxSortFuncFor_wxWindowList func)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#sort)")
*/
/* The following types are missing: iterator
    ADD_CLASS_METHOD(begin_1,"iterator wxWindowList::begin()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#begin)")
*/
    ADD_CLASS_METHOD(begin,"wxWindowList::begin()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#begin)")
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(begin_2,"const_iterator wxWindowList::begin()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#begin)")
*/
/* The following types are missing: iterator
    ADD_CLASS_METHOD(end_1,"iterator wxWindowList::end()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#end)")
*/
    ADD_CLASS_METHOD(end,"wxWindowList::end()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#end)")
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(end_2,"const_iterator wxWindowList::end()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#end)")
*/
/* The following types are missing: reverse_iterator
    ADD_CLASS_METHOD(rbegin_1,"reverse_iterator wxWindowList::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#rbegin)")
*/
    ADD_CLASS_METHOD(rbegin,"wxWindowList::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#rbegin)")
/* The following types are missing: const_reverse_iterator
    ADD_CLASS_METHOD(rbegin_2,"const_reverse_iterator wxWindowList::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#rbegin)")
*/
/* The following types are missing: reverse_iterator
    ADD_CLASS_METHOD(rend_1,"reverse_iterator wxWindowList::rend()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#rend)")
*/
    ADD_CLASS_METHOD(rend,"wxWindowList::rend()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#rend)")
/* The following types are missing: const_reverse_iterator
    ADD_CLASS_METHOD(rend_2,"const_reverse_iterator wxWindowList::rend()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#rend)")
*/
    ADD_CLASS_METHOD(resize,"void wxWindowList::resize(size_t n, wxWindow * v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#resize)")
    ADD_CLASS_METHOD(size,"size_t wxWindowList::size()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#size)")
    ADD_CLASS_METHOD(max_size,"size_t wxWindowList::max_size()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#max_size)")
    ADD_CLASS_METHOD(empty,"bool wxWindowList::empty()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#empty)")
    ADD_CLASS_METHOD(front_1,"wxWindow * & wxWindowList::front()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#front)")
    ADD_CLASS_METHOD(front,"wxWindowList::front()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#front)")
    ADD_CLASS_METHOD(front_2,"wxWindow * const & wxWindowList::front()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#front)")
    ADD_CLASS_METHOD(back_1,"wxWindow * & wxWindowList::back()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#back)")
    ADD_CLASS_METHOD(back,"wxWindowList::back()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#back)")
    ADD_CLASS_METHOD(back_2,"wxWindow * const & wxWindowList::back()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#back)")
    ADD_CLASS_METHOD(push_front,"void wxWindowList::push_front(wxWindow * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#push_front)")
    ADD_CLASS_METHOD(pop_front,"void wxWindowList::pop_front()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#pop_front)")
    ADD_CLASS_METHOD(push_back,"void wxWindowList::push_back(wxWindow * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#push_back)")
    ADD_CLASS_METHOD(pop_back,"void wxWindowList::pop_back()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#pop_back)")
/* The following types are missing: const_iterator, const_iterator
    ADD_CLASS_METHOD(assign_1,"void wxWindowList::assign(const_iterator first, const_iterator const & last)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#assign)")
*/
    ADD_CLASS_METHOD(assign,"wxWindowList::assign()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#assign)")
    ADD_CLASS_METHOD(assign_2,"void wxWindowList::assign(size_t n, wxWindow * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#assign)")
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(insert_1,"iterator wxWindowList::insert(iterator const & it, wxWindow * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#insert)")
*/
    ADD_CLASS_METHOD(insert,"wxWindowList::insert()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#insert)")
/* The following types are missing: iterator
    ADD_CLASS_METHOD(insert_2,"void wxWindowList::insert(iterator const & it, size_t n, wxWindow * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#insert)")
*/
/* The following types are missing: iterator, const_iterator, const_iterator
    ADD_CLASS_METHOD(insert_3,"void wxWindowList::insert(iterator const & it, const_iterator first, const_iterator const & last)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#insert)")
*/
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(erase_1,"iterator wxWindowList::erase(iterator const & it)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#erase)")
*/
    ADD_CLASS_METHOD(erase,"wxWindowList::erase()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#erase)")
/* The following types are missing: iterator, iterator, iterator
    ADD_CLASS_METHOD(erase_2,"iterator wxWindowList::erase(iterator const & first, iterator const & last)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#erase)")
*/
    ADD_CLASS_METHOD(clear,"void wxWindowList::clear()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#clear)")
/* The following types are missing: iterator, iterator, iterator
    ADD_CLASS_METHOD(splice_1,"void wxWindowList::splice(iterator const & it, wxWindowList & l, iterator const & first, iterator const & last)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#splice)")
*/
    ADD_CLASS_METHOD(splice,"wxWindowList::splice()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#splice)")
/* The following types are missing: iterator
    ADD_CLASS_METHOD(splice_2,"void wxWindowList::splice(iterator const & it, wxWindowList & l)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#splice)")
*/
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(splice_3,"void wxWindowList::splice(iterator const & it, wxWindowList & l, iterator const & first)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#splice)")
*/
    ADD_CLASS_METHOD(remove,"void wxWindowList::remove(wxWindow * const & v)  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#remove)")
    ADD_CLASS_METHOD(reverse,"void wxWindowList::reverse()  (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#reverse)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxWindowList & wxWindowList::operator =(wxWindowList const & list) (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#__assign__)")
    ADD_CLASS_METHOD(__at__,            "wxWindow * wxWindowList::operator [](size_t index) (http://docs.wxwidgets.org/stable/wx_wxwindowlist.html#__at__)")




    void AddMethods(WrapClass<wxWindowList>::ptr this_ptr );

};


#endif // _wrap_wxWindowList_h
