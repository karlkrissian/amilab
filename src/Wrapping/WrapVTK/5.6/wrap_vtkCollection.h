/**
 * C++ Interface: wrap_vtkCollection
 *
 * Description: wrapping vtkCollection
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkCollection_h_
#define _wrap_vtkCollection_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkCollection.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"


#ifndef vtkCollection_declared
  #define vtkCollection_declared
  AMI_DECLARE_TYPE(vtkCollection);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkCollection : public WrapClass<vtkCollection>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkCollection);

  protected:
    typedef WrapClass<vtkCollection>::ptr _parentclass_ptr;
    typedef vtkCollection ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkCollection>& GetObj() const { return WrapClass<vtkCollection>::GetObj(); }

    /// Constructor
    WrapClass_vtkCollection(boost::shared_ptr<vtkCollection > si): 
    WrapClass<vtkCollection>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkCollection()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkCollection*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkCollection::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkCollection * vtkCollection::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(New,"vtkCollection * vtkCollection::New() (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#new).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkCollection::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkCollection * vtkCollection::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkCollection::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#printself)")
*/
    ADD_CLASS_METHOD(AddItem,"void vtkCollection::AddItem(vtkObject * param0)  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#additem)")
    ADD_CLASS_METHOD(InsertItem,"void vtkCollection::InsertItem(int i, vtkObject * param1)  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#insertitem)")
    ADD_CLASS_METHOD(ReplaceItem,"void vtkCollection::ReplaceItem(int i, vtkObject * param1)  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#replaceitem)")
    ADD_CLASS_METHOD(RemoveItem_1,"void vtkCollection::RemoveItem(int i)  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#removeitem)")
    ADD_CLASS_METHOD(RemoveItem,"vtkCollection::RemoveItem()  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#removeitem)")
    ADD_CLASS_METHOD(RemoveItem_2,"void vtkCollection::RemoveItem(vtkObject * param0)  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#removeitem)")
    ADD_CLASS_METHOD(RemoveAllItems,"void vtkCollection::RemoveAllItems()  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#removeallitems)")
    ADD_CLASS_METHOD(IsItemPresent,"int vtkCollection::IsItemPresent(vtkObject * a)  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#isitempresent)")
    ADD_CLASS_METHOD(GetNumberOfItems,"int vtkCollection::GetNumberOfItems()  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#getnumberofitems)")
    ADD_CLASS_METHOD(InitTraversal_1,"void vtkCollection::InitTraversal()  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#inittraversal)")
    ADD_CLASS_METHOD(InitTraversal,"vtkCollection::InitTraversal()  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#inittraversal)")
/* The following types are missing: void
    ADD_CLASS_METHOD(InitTraversal_2,"void vtkCollection::InitTraversal(vtkCollectionSimpleIterator & cookie)  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#inittraversal)")
*/
    ADD_CLASS_METHOD(GetNextItemAsObject_1,"vtkObject * vtkCollection::GetNextItemAsObject()  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#getnextitemasobject)")
    ADD_CLASS_METHOD(GetItemAsObject,"vtkObject * vtkCollection::GetItemAsObject(int i)  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#getitemasobject)")
    ADD_CLASS_METHOD(GetNextItemAsObject,"vtkCollection::GetNextItemAsObject()  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#getnextitemasobject)")
/* The following types are missing: void
    ADD_CLASS_METHOD(GetNextItemAsObject_2,"vtkObject * vtkCollection::GetNextItemAsObject(void * & cookie)  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#getnextitemasobject)")
*/
/* The following types are missing: vtkCollectionIterator
    ADD_CLASS_METHOD(NewIterator,"vtkCollectionIterator * vtkCollection::NewIterator()  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#newiterator)")
*/
    ADD_CLASS_METHOD(Register,"void vtkCollection::Register(vtkObjectBase * o)  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#register)")
    ADD_CLASS_METHOD(UnRegister,"void vtkCollection::UnRegister(vtkObjectBase * o)  (http://docs.wxwidgets.org/stable/wx_vtkcollection.html#unregister)")





    void AddMethods(WrapClass<vtkCollection>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkCollection_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkCollection_h
