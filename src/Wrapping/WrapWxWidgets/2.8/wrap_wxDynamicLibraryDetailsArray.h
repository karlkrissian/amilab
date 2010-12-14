/**
 * C++ Interface: wrap_wxDynamicLibraryDetailsArray
 *
 * Description: wrapping wxDynamicLibraryDetailsArray
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxDynamicLibraryDetailsArray_h_
#define _wrap_wxDynamicLibraryDetailsArray_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxDynamicLibraryDetailsArray_declared
  #define wxDynamicLibraryDetailsArray_declared
  AMI_DECLARE_TYPE(wxDynamicLibraryDetailsArray);
#endif

// TODO: check for inheritence ...
class WrapClass_wxDynamicLibraryDetailsArray : public WrapClass<wxDynamicLibraryDetailsArray>
    
{
  DEFINE_CLASS(WrapClass_wxDynamicLibraryDetailsArray);

  protected:
    typedef WrapClass<wxDynamicLibraryDetailsArray>::ptr _parentclass_ptr;
    typedef wxDynamicLibraryDetailsArray ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxDynamicLibraryDetailsArray>& GetObj() const { return WrapClass<wxDynamicLibraryDetailsArray>::GetObj(); }

    /// Constructor
    WrapClass_wxDynamicLibraryDetailsArray(boost::shared_ptr<wxDynamicLibraryDetailsArray > si): 
    WrapClass<wxDynamicLibraryDetailsArray>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxDynamicLibraryDetailsArray()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDynamicLibraryDetailsArray_1,"Constructor wxDynamicLibraryDetailsArray::wxDynamicLibraryDetailsArray() (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#wxdynamiclibrarydetailsarray).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDynamicLibraryDetailsArray,"Constructor wxDynamicLibraryDetailsArray::wxDynamicLibraryDetailsArray() (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#wxdynamiclibrarydetailsarray).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDynamicLibraryDetailsArray_2,"Constructor wxDynamicLibraryDetailsArray::wxDynamicLibraryDetailsArray(wxDynamicLibraryDetailsArray const & src) (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#wxdynamiclibrarydetailsarray).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxDynamicLibraryDetailsArray*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Alloc,"void wxDynamicLibraryDetailsArray::Alloc(size_t count)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#alloc)")
    ADD_CLASS_METHOD(GetCount,"size_t wxDynamicLibraryDetailsArray::GetCount()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#getcount)")
    ADD_CLASS_METHOD(size,"size_t wxDynamicLibraryDetailsArray::size()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#size)")
    ADD_CLASS_METHOD(IsEmpty,"bool wxDynamicLibraryDetailsArray::IsEmpty()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#isempty)")
    ADD_CLASS_METHOD(empty,"bool wxDynamicLibraryDetailsArray::empty()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#empty)")
    ADD_CLASS_METHOD(Count,"size_t wxDynamicLibraryDetailsArray::Count()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#count)")
    ADD_CLASS_METHOD(Shrink,"void wxDynamicLibraryDetailsArray::Shrink()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#shrink)")
    ADD_CLASS_METHOD(Item,"_wxObjArraywxDynamicLibraryDetailsArray & wxDynamicLibraryDetailsArray::Item(size_t uiIndex)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#item)")
    ADD_CLASS_METHOD(Last,"_wxObjArraywxDynamicLibraryDetailsArray & wxDynamicLibraryDetailsArray::Last()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#last)")
    ADD_CLASS_METHOD(Index,"int wxDynamicLibraryDetailsArray::Index(_wxObjArraywxDynamicLibraryDetailsArray const & lItem, bool bFromEnd = false)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#index)")
    ADD_CLASS_METHOD(Add_1,"void wxDynamicLibraryDetailsArray::Add(_wxObjArraywxDynamicLibraryDetailsArray const & lItem, size_t nInsert = 1)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#add)")
    ADD_CLASS_METHOD(Add,"wxDynamicLibraryDetailsArray::Add()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#add)")
    ADD_CLASS_METHOD(Add_2,"void wxDynamicLibraryDetailsArray::Add(_wxObjArraywxDynamicLibraryDetailsArray const * pItem)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#add)")
    ADD_CLASS_METHOD(push_back_1,"void wxDynamicLibraryDetailsArray::push_back(_wxObjArraywxDynamicLibraryDetailsArray const * pItem)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#push_back)")
    ADD_CLASS_METHOD(push_back,"wxDynamicLibraryDetailsArray::push_back()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#push_back)")
    ADD_CLASS_METHOD(push_back_2,"void wxDynamicLibraryDetailsArray::push_back(_wxObjArraywxDynamicLibraryDetailsArray const & lItem)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#push_back)")
    ADD_CLASS_METHOD(Insert_1,"void wxDynamicLibraryDetailsArray::Insert(_wxObjArraywxDynamicLibraryDetailsArray const & lItem, size_t uiIndex, size_t nInsert = 1)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#insert)")
    ADD_CLASS_METHOD(Insert,"wxDynamicLibraryDetailsArray::Insert()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#insert)")
    ADD_CLASS_METHOD(Insert_2,"void wxDynamicLibraryDetailsArray::Insert(_wxObjArraywxDynamicLibraryDetailsArray const * pItem, size_t uiIndex)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#insert)")
    ADD_CLASS_METHOD(Empty,"void wxDynamicLibraryDetailsArray::Empty()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#empty)")
    ADD_CLASS_METHOD(Clear,"void wxDynamicLibraryDetailsArray::Clear()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#clear)")
    ADD_CLASS_METHOD(Detach,"_wxObjArraywxDynamicLibraryDetailsArray * wxDynamicLibraryDetailsArray::Detach(size_t uiIndex)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#detach)")
    ADD_CLASS_METHOD(RemoveAt,"void wxDynamicLibraryDetailsArray::RemoveAt(size_t uiIndex, size_t nRemove = 1)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#removeat)")
/* The following types are missing: _11355
    ADD_CLASS_METHOD(Sort,"void wxDynamicLibraryDetailsArray::Sort(CMPFUNC_wxObjArraywxDynamicLibraryDetailsArray fCmp)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#sort)")
*/

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxDynamicLibraryDetailsArray & wxDynamicLibraryDetailsArray::operator =(wxDynamicLibraryDetailsArray const & src) (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#__assign__)")
    ADD_CLASS_METHOD(__at__,            "_wxObjArraywxDynamicLibraryDetailsArray & wxDynamicLibraryDetailsArray::operator [](size_t uiIndex) (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetailsarray.html#__at__)")




    void AddMethods(WrapClass<wxDynamicLibraryDetailsArray>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxDynamicLibraryDetailsArray_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxDynamicLibraryDetailsArray_h
