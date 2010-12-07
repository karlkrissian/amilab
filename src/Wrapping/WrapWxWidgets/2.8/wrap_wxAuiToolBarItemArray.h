/**
 * C++ Interface: wrap_wxAuiToolBarItemArray
 *
 * Description: wrapping wxAuiToolBarItemArray
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAuiToolBarItemArray_h_
#define _wrap_wxAuiToolBarItemArray_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxAuiToolBarItemArray);

// TODO: check for inheritence ...
class WrapClass_wxAuiToolBarItemArray : public WrapClass<wxAuiToolBarItemArray>
    
{
  DEFINE_CLASS(WrapClass_wxAuiToolBarItemArray);

  protected:
    typedef WrapClass<wxAuiToolBarItemArray>::ptr _parentclass_ptr;
    typedef wxAuiToolBarItemArray ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAuiToolBarItemArray>& GetObj() const { return WrapClass<wxAuiToolBarItemArray>::GetObj(); }

    /// Constructor
    WrapClass_wxAuiToolBarItemArray(boost::shared_ptr<wxAuiToolBarItemArray > si): 
    WrapClass<wxAuiToolBarItemArray>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxAuiToolBarItemArray()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiToolBarItemArray_1,"Constructor wxAuiToolBarItemArray::wxAuiToolBarItemArray() (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#wxauitoolbaritemarray).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiToolBarItemArray,"Constructor wxAuiToolBarItemArray::wxAuiToolBarItemArray() (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#wxauitoolbaritemarray).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiToolBarItemArray_2,"Constructor wxAuiToolBarItemArray::wxAuiToolBarItemArray(wxAuiToolBarItemArray const & src) (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#wxauitoolbaritemarray).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiToolBarItemArray*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Alloc,"void wxAuiToolBarItemArray::Alloc(size_t count)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#alloc)")
    ADD_CLASS_METHOD(GetCount,"size_t wxAuiToolBarItemArray::GetCount()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#getcount)")
    ADD_CLASS_METHOD(size,"size_t wxAuiToolBarItemArray::size()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#size)")
    ADD_CLASS_METHOD(IsEmpty,"bool wxAuiToolBarItemArray::IsEmpty()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#isempty)")
    ADD_CLASS_METHOD(empty,"bool wxAuiToolBarItemArray::empty()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#empty)")
    ADD_CLASS_METHOD(Count,"size_t wxAuiToolBarItemArray::Count()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#count)")
    ADD_CLASS_METHOD(Shrink,"void wxAuiToolBarItemArray::Shrink()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#shrink)")
    ADD_CLASS_METHOD(Item,"_wxObjArraywxAuiToolBarItemArray & wxAuiToolBarItemArray::Item(size_t uiIndex)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#item)")
    ADD_CLASS_METHOD(Last,"_wxObjArraywxAuiToolBarItemArray & wxAuiToolBarItemArray::Last()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#last)")
    ADD_CLASS_METHOD(Index,"int wxAuiToolBarItemArray::Index(_wxObjArraywxAuiToolBarItemArray const & lItem, bool bFromEnd = false)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#index)")
    ADD_CLASS_METHOD(Add_1,"void wxAuiToolBarItemArray::Add(_wxObjArraywxAuiToolBarItemArray const & lItem, size_t nInsert = 1)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#add)")
    ADD_CLASS_METHOD(Add,"wxAuiToolBarItemArray::Add()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#add)")
    ADD_CLASS_METHOD(Add_2,"void wxAuiToolBarItemArray::Add(_wxObjArraywxAuiToolBarItemArray const * pItem)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#add)")
    ADD_CLASS_METHOD(push_back_1,"void wxAuiToolBarItemArray::push_back(_wxObjArraywxAuiToolBarItemArray const * pItem)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#push_back)")
    ADD_CLASS_METHOD(push_back,"wxAuiToolBarItemArray::push_back()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#push_back)")
    ADD_CLASS_METHOD(push_back_2,"void wxAuiToolBarItemArray::push_back(_wxObjArraywxAuiToolBarItemArray const & lItem)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#push_back)")
    ADD_CLASS_METHOD(Insert_1,"void wxAuiToolBarItemArray::Insert(_wxObjArraywxAuiToolBarItemArray const & lItem, size_t uiIndex, size_t nInsert = 1)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#insert)")
    ADD_CLASS_METHOD(Insert,"wxAuiToolBarItemArray::Insert()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#insert)")
    ADD_CLASS_METHOD(Insert_2,"void wxAuiToolBarItemArray::Insert(_wxObjArraywxAuiToolBarItemArray const * pItem, size_t uiIndex)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#insert)")
    ADD_CLASS_METHOD(Empty,"void wxAuiToolBarItemArray::Empty()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#empty)")
    ADD_CLASS_METHOD(Clear,"void wxAuiToolBarItemArray::Clear()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#clear)")
    ADD_CLASS_METHOD(Detach,"_wxObjArraywxAuiToolBarItemArray * wxAuiToolBarItemArray::Detach(size_t uiIndex)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#detach)")
    ADD_CLASS_METHOD(RemoveAt,"void wxAuiToolBarItemArray::RemoveAt(size_t uiIndex, size_t nRemove = 1)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#removeat)")
/* The following types are missing: _13436
    ADD_CLASS_METHOD(Sort,"void wxAuiToolBarItemArray::Sort(CMPFUNC_wxObjArraywxAuiToolBarItemArray fCmp)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#sort)")
*/

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxAuiToolBarItemArray & wxAuiToolBarItemArray::operator =(wxAuiToolBarItemArray const & src) (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#__assign__)")
    ADD_CLASS_METHOD(__at__,            "_wxObjArraywxAuiToolBarItemArray & wxAuiToolBarItemArray::operator [](size_t uiIndex) (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritemarray.html#__at__)")




    void AddMethods(WrapClass<wxAuiToolBarItemArray>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxAuiToolBarItemArray_h
