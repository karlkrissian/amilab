/**
 * C++ Interface: wrap_wxObjectList
 *
 * Description: wrapping wxObjectList
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxObjectList_h_
#define _wrap_wxObjectList_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxListBase.h"



AMI_DECLARE_TYPE(wxObjectList);

// TODO: check for inheritence ...
class WrapClass_wxObjectList : public WrapClass<wxObjectList>
    , public   WrapClass_wxListBase
{
  DEFINE_CLASS(WrapClass_wxObjectList);

  protected:
    typedef WrapClass<wxObjectList>::ptr _parentclass_ptr;
    typedef wxObjectList ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxObjectList>& GetObj() const { return WrapClass<wxObjectList>::GetObj(); }

    /// Constructor
    WrapClass_wxObjectList(boost::shared_ptr<wxObjectList > si): 
    WrapClass<wxObjectList>(si)
    , WrapClass_wxListBase(si)
    {}

    /// Destructor
    ~WrapClass_wxObjectList()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxObjectList_1,"Constructor wxObjectList::wxObjectList(wxKeyType keyType = wxKEY_NONE) (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#wxobjectlist).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxObjectList,"Constructor wxObjectList::wxObjectList() (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#wxobjectlist).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxObjectList_2,"Constructor wxObjectList::wxObjectList(wxObjectList const & list) (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#wxobjectlist).");
    /* The following types are missing: wxObject * *
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxObjectList_3,"Constructor wxObjectList::wxObjectList(size_t count, wxObject * * elements) (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#wxobjectlist).");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxObjectList_4,"Constructor wxObjectList::wxObjectList(size_t n, wxObject * const & v = 0u) (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#wxobjectlist).");
    /* The following types are missing: const_iterator, const_iterator
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxObjectList_5,"Constructor wxObjectList::wxObjectList(const_iterator const & first, const_iterator const & last) (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#wxobjectlist).");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxObjectList*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetFirst,"wxObjectListNode * wxObjectList::GetFirst()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#getfirst)")
    ADD_CLASS_METHOD(GetLast,"wxObjectListNode * wxObjectList::GetLast()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#getlast)")
    ADD_CLASS_METHOD(Item,"wxObjectListNode * wxObjectList::Item(size_t index)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#item)")
    ADD_CLASS_METHOD(Append_1,"wxObjectListNode * wxObjectList::Append(wxObject * object)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#append)")
    ADD_CLASS_METHOD(Insert_1,"wxObjectListNode * wxObjectList::Insert(wxObject * object)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#insert)")
    ADD_CLASS_METHOD(Insert,"wxObjectList::Insert()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#insert)")
    ADD_CLASS_METHOD(Insert_2,"wxObjectListNode * wxObjectList::Insert(size_t pos, wxObject * object)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#insert)")
    ADD_CLASS_METHOD(Insert_3,"wxObjectListNode * wxObjectList::Insert(wxObjectListNode * prev, wxObject * object)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#insert)")
    ADD_CLASS_METHOD(Append,"wxObjectList::Append()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#append)")
/* The following types are missing: void
    ADD_CLASS_METHOD(Append_2,"wxObjectListNode * wxObjectList::Append(long int key, void * object)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#append)")
*/
/* The following types are missing: void
    ADD_CLASS_METHOD(Append_3,"wxObjectListNode * wxObjectList::Append(wxChar const * key, void * object)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#append)")
*/
    ADD_CLASS_METHOD(DetachNode,"wxObjectListNode * wxObjectList::DetachNode(wxObjectListNode * node)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#detachnode)")
    ADD_CLASS_METHOD(DeleteNode,"bool wxObjectList::DeleteNode(wxObjectListNode * node)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#deletenode)")
    ADD_CLASS_METHOD(DeleteObject,"bool wxObjectList::DeleteObject(wxObject * object)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#deleteobject)")
    ADD_CLASS_METHOD(Erase,"void wxObjectList::Erase(wxObjectListNode * it)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#erase)")
    ADD_CLASS_METHOD(Find_1,"wxObjectListNode * wxObjectList::Find(wxObject const * object)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#find)")
    ADD_CLASS_METHOD(Find,"wxObjectList::Find()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#find)")
    ADD_CLASS_METHOD(Find_2,"wxObjectListNode * wxObjectList::Find(wxListKey const & key)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#find)")
    ADD_CLASS_METHOD(IndexOf,"int wxObjectList::IndexOf(wxObject * object)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#indexof)")
/* The following types are missing: _9904
    ADD_CLASS_METHOD(Sort_1,"void wxObjectList::Sort(wxSortCompareFunction func)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#sort)")
*/
    ADD_CLASS_METHOD(Sort,"wxObjectList::Sort()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#sort)")
/* The following types are missing: _8750
    ADD_CLASS_METHOD(Sort_2,"void wxObjectList::Sort(wxSortFuncFor_wxObjectList func)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#sort)")
*/
/* The following types are missing: iterator
    ADD_CLASS_METHOD(begin_1,"iterator wxObjectList::begin()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#begin)")
*/
    ADD_CLASS_METHOD(begin,"wxObjectList::begin()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#begin)")
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(begin_2,"const_iterator wxObjectList::begin()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#begin)")
*/
/* The following types are missing: iterator
    ADD_CLASS_METHOD(end_1,"iterator wxObjectList::end()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#end)")
*/
    ADD_CLASS_METHOD(end,"wxObjectList::end()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#end)")
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(end_2,"const_iterator wxObjectList::end()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#end)")
*/
/* The following types are missing: reverse_iterator
    ADD_CLASS_METHOD(rbegin_1,"reverse_iterator wxObjectList::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#rbegin)")
*/
    ADD_CLASS_METHOD(rbegin,"wxObjectList::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#rbegin)")
/* The following types are missing: const_reverse_iterator
    ADD_CLASS_METHOD(rbegin_2,"const_reverse_iterator wxObjectList::rbegin()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#rbegin)")
*/
/* The following types are missing: reverse_iterator
    ADD_CLASS_METHOD(rend_1,"reverse_iterator wxObjectList::rend()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#rend)")
*/
    ADD_CLASS_METHOD(rend,"wxObjectList::rend()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#rend)")
/* The following types are missing: const_reverse_iterator
    ADD_CLASS_METHOD(rend_2,"const_reverse_iterator wxObjectList::rend()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#rend)")
*/
    ADD_CLASS_METHOD(resize,"void wxObjectList::resize(size_t n, wxObject * v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#resize)")
    ADD_CLASS_METHOD(size,"size_t wxObjectList::size()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#size)")
    ADD_CLASS_METHOD(max_size,"size_t wxObjectList::max_size()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#max_size)")
    ADD_CLASS_METHOD(empty,"bool wxObjectList::empty()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#empty)")
    ADD_CLASS_METHOD(front_1,"wxObject * & wxObjectList::front()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#front)")
    ADD_CLASS_METHOD(front,"wxObjectList::front()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#front)")
    ADD_CLASS_METHOD(front_2,"wxObject * const & wxObjectList::front()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#front)")
    ADD_CLASS_METHOD(back_1,"wxObject * & wxObjectList::back()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#back)")
    ADD_CLASS_METHOD(back,"wxObjectList::back()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#back)")
    ADD_CLASS_METHOD(back_2,"wxObject * const & wxObjectList::back()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#back)")
    ADD_CLASS_METHOD(push_front,"void wxObjectList::push_front(wxObject * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#push_front)")
    ADD_CLASS_METHOD(pop_front,"void wxObjectList::pop_front()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#pop_front)")
    ADD_CLASS_METHOD(push_back,"void wxObjectList::push_back(wxObject * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#push_back)")
    ADD_CLASS_METHOD(pop_back,"void wxObjectList::pop_back()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#pop_back)")
/* The following types are missing: const_iterator, const_iterator
    ADD_CLASS_METHOD(assign_1,"void wxObjectList::assign(const_iterator first, const_iterator const & last)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#assign)")
*/
    ADD_CLASS_METHOD(assign,"wxObjectList::assign()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#assign)")
    ADD_CLASS_METHOD(assign_2,"void wxObjectList::assign(size_t n, wxObject * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#assign)")
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(insert_1,"iterator wxObjectList::insert(iterator const & it, wxObject * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#insert)")
*/
    ADD_CLASS_METHOD(insert,"wxObjectList::insert()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#insert)")
/* The following types are missing: iterator
    ADD_CLASS_METHOD(insert_2,"void wxObjectList::insert(iterator const & it, size_t n, wxObject * const & v = 0u)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#insert)")
*/
/* The following types are missing: iterator, const_iterator, const_iterator
    ADD_CLASS_METHOD(insert_3,"void wxObjectList::insert(iterator const & it, const_iterator first, const_iterator const & last)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#insert)")
*/
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(erase_1,"iterator wxObjectList::erase(iterator const & it)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#erase)")
*/
    ADD_CLASS_METHOD(erase,"wxObjectList::erase()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#erase)")
/* The following types are missing: iterator, iterator, iterator
    ADD_CLASS_METHOD(erase_2,"iterator wxObjectList::erase(iterator const & first, iterator const & last)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#erase)")
*/
    ADD_CLASS_METHOD(clear,"void wxObjectList::clear()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#clear)")
/* The following types are missing: iterator, iterator, iterator
    ADD_CLASS_METHOD(splice_1,"void wxObjectList::splice(iterator const & it, wxObjectList & l, iterator const & first, iterator const & last)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#splice)")
*/
    ADD_CLASS_METHOD(splice,"wxObjectList::splice()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#splice)")
/* The following types are missing: iterator
    ADD_CLASS_METHOD(splice_2,"void wxObjectList::splice(iterator const & it, wxObjectList & l)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#splice)")
*/
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(splice_3,"void wxObjectList::splice(iterator const & it, wxObjectList & l, iterator const & first)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#splice)")
*/
    ADD_CLASS_METHOD(remove,"void wxObjectList::remove(wxObject * const & v)  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#remove)")
    ADD_CLASS_METHOD(reverse,"void wxObjectList::reverse()  (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#reverse)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxObjectList & wxObjectList::operator =(wxObjectList const & list) (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#__assign__)")
    ADD_CLASS_METHOD(__at__,            "wxObject * wxObjectList::operator [](size_t index) (http://docs.wxwidgets.org/stable/wx_wxobjectlist.html#__at__)")




    void AddMethods(WrapClass<wxObjectList>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxObjectList_h
