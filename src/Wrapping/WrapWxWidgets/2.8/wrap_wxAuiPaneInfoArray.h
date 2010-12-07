/**
 * C++ Interface: wrap_wxAuiPaneInfoArray
 *
 * Description: wrapping wxAuiPaneInfoArray
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAuiPaneInfoArray_h_
#define _wrap_wxAuiPaneInfoArray_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxAuiPaneInfoArray);

// TODO: check for inheritence ...
class WrapClass_wxAuiPaneInfoArray : public WrapClass<wxAuiPaneInfoArray>
    
{
  DEFINE_CLASS(WrapClass_wxAuiPaneInfoArray);

  protected:
    typedef WrapClass<wxAuiPaneInfoArray>::ptr _parentclass_ptr;
    typedef wxAuiPaneInfoArray ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAuiPaneInfoArray>& GetObj() const { return WrapClass<wxAuiPaneInfoArray>::GetObj(); }

    /// Constructor
    WrapClass_wxAuiPaneInfoArray(boost::shared_ptr<wxAuiPaneInfoArray > si): 
    WrapClass<wxAuiPaneInfoArray>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxAuiPaneInfoArray()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiPaneInfoArray_1,"Constructor wxAuiPaneInfoArray::wxAuiPaneInfoArray() (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#wxauipaneinfoarray).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiPaneInfoArray,"Constructor wxAuiPaneInfoArray::wxAuiPaneInfoArray() (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#wxauipaneinfoarray).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiPaneInfoArray_2,"Constructor wxAuiPaneInfoArray::wxAuiPaneInfoArray(wxAuiPaneInfoArray const & src) (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#wxauipaneinfoarray).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiPaneInfoArray*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Alloc,"void wxAuiPaneInfoArray::Alloc(size_t count)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#alloc)")
    ADD_CLASS_METHOD(GetCount,"size_t wxAuiPaneInfoArray::GetCount()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#getcount)")
    ADD_CLASS_METHOD(size,"size_t wxAuiPaneInfoArray::size()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#size)")
    ADD_CLASS_METHOD(IsEmpty,"bool wxAuiPaneInfoArray::IsEmpty()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#isempty)")
    ADD_CLASS_METHOD(empty,"bool wxAuiPaneInfoArray::empty()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#empty)")
    ADD_CLASS_METHOD(Count,"size_t wxAuiPaneInfoArray::Count()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#count)")
    ADD_CLASS_METHOD(Shrink,"void wxAuiPaneInfoArray::Shrink()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#shrink)")
    ADD_CLASS_METHOD(Item,"_wxObjArraywxAuiPaneInfoArray & wxAuiPaneInfoArray::Item(size_t uiIndex)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#item)")
    ADD_CLASS_METHOD(Last,"_wxObjArraywxAuiPaneInfoArray & wxAuiPaneInfoArray::Last()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#last)")
    ADD_CLASS_METHOD(Index,"int wxAuiPaneInfoArray::Index(_wxObjArraywxAuiPaneInfoArray const & lItem, bool bFromEnd = false)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#index)")
    ADD_CLASS_METHOD(Add_1,"void wxAuiPaneInfoArray::Add(_wxObjArraywxAuiPaneInfoArray const & lItem, size_t nInsert = 1)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#add)")
    ADD_CLASS_METHOD(Add,"wxAuiPaneInfoArray::Add()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#add)")
    ADD_CLASS_METHOD(Add_2,"void wxAuiPaneInfoArray::Add(_wxObjArraywxAuiPaneInfoArray const * pItem)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#add)")
    ADD_CLASS_METHOD(push_back_1,"void wxAuiPaneInfoArray::push_back(_wxObjArraywxAuiPaneInfoArray const * pItem)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#push_back)")
    ADD_CLASS_METHOD(push_back,"wxAuiPaneInfoArray::push_back()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#push_back)")
    ADD_CLASS_METHOD(push_back_2,"void wxAuiPaneInfoArray::push_back(_wxObjArraywxAuiPaneInfoArray const & lItem)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#push_back)")
    ADD_CLASS_METHOD(Insert_1,"void wxAuiPaneInfoArray::Insert(_wxObjArraywxAuiPaneInfoArray const & lItem, size_t uiIndex, size_t nInsert = 1)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#insert)")
    ADD_CLASS_METHOD(Insert,"wxAuiPaneInfoArray::Insert()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#insert)")
    ADD_CLASS_METHOD(Insert_2,"void wxAuiPaneInfoArray::Insert(_wxObjArraywxAuiPaneInfoArray const * pItem, size_t uiIndex)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#insert)")
    ADD_CLASS_METHOD(Empty,"void wxAuiPaneInfoArray::Empty()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#empty)")
    ADD_CLASS_METHOD(Clear,"void wxAuiPaneInfoArray::Clear()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#clear)")
    ADD_CLASS_METHOD(Detach,"_wxObjArraywxAuiPaneInfoArray * wxAuiPaneInfoArray::Detach(size_t uiIndex)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#detach)")
    ADD_CLASS_METHOD(RemoveAt,"void wxAuiPaneInfoArray::RemoveAt(size_t uiIndex, size_t nRemove = 1)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#removeat)")
/* The following types are missing: _15468
    ADD_CLASS_METHOD(Sort,"void wxAuiPaneInfoArray::Sort(CMPFUNC_wxObjArraywxAuiPaneInfoArray fCmp)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#sort)")
*/

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxAuiPaneInfoArray & wxAuiPaneInfoArray::operator =(wxAuiPaneInfoArray const & src) (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#__assign__)")
    ADD_CLASS_METHOD(__at__,            "_wxObjArraywxAuiPaneInfoArray & wxAuiPaneInfoArray::operator [](size_t uiIndex) (http://docs.wxwidgets.org/stable/wx_wxauipaneinfoarray.html#__at__)")




    void AddMethods(WrapClass<wxAuiPaneInfoArray>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxAuiPaneInfoArray_h
