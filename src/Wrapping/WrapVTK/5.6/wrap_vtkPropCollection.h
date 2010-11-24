/**
 * C++ Interface: wrap_vtkPropCollection
 *
 * Description: wrapping vtkPropCollection
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkPropCollection_h_
#define _wrap_vtkPropCollection_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkCollection.h"



AMI_DECLARE_TYPE(vtkPropCollection);

// TODO: check for inheritence ...
class WrapClass_vtkPropCollection : public WrapClass<vtkPropCollection>
    , public   WrapClass_vtkCollection
{
  DEFINE_CLASS(WrapClass_vtkPropCollection);

  protected:
    typedef WrapClass<vtkPropCollection>::ptr _parentclass_ptr;
    typedef vtkPropCollection ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkPropCollection>& GetObj() const { return WrapClass<vtkPropCollection>::GetObj(); }

    /// Constructor
    WrapClass_vtkPropCollection(boost::shared_ptr<vtkPropCollection > si): 
    WrapClass<vtkPropCollection>(si)
    , WrapClass_vtkCollection(si)
    {}

    /// Destructor
    ~WrapClass_vtkPropCollection()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkPropCollection*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkPropCollection * vtkPropCollection::New() (http://docs.wxwidgets.org/stable/wx_vtkpropcollection.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkPropCollection::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkpropcollection.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkPropCollection * vtkPropCollection::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkpropcollection.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkPropCollection::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkpropcollection.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkPropCollection * vtkPropCollection::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkpropcollection.html#newinstance)")
    ADD_CLASS_METHOD(AddItem,"void vtkPropCollection::AddItem(vtkProp * a)  (http://docs.wxwidgets.org/stable/wx_vtkpropcollection.html#additem)")
    ADD_CLASS_METHOD(GetNextProp_1,"vtkProp * vtkPropCollection::GetNextProp()  (http://docs.wxwidgets.org/stable/wx_vtkpropcollection.html#getnextprop)")
    ADD_CLASS_METHOD(GetLastProp,"vtkProp * vtkPropCollection::GetLastProp()  (http://docs.wxwidgets.org/stable/wx_vtkpropcollection.html#getlastprop)")
    ADD_CLASS_METHOD(GetNumberOfPaths,"int vtkPropCollection::GetNumberOfPaths()  (http://docs.wxwidgets.org/stable/wx_vtkpropcollection.html#getnumberofpaths)")
    ADD_CLASS_METHOD(GetNextProp,"vtkPropCollection::GetNextProp()  (http://docs.wxwidgets.org/stable/wx_vtkpropcollection.html#getnextprop)")
/* The following types are missing: void
    ADD_CLASS_METHOD(GetNextProp_2,"vtkProp * vtkPropCollection::GetNextProp(vtkCollectionSimpleIterator & cookie)  (http://docs.wxwidgets.org/stable/wx_vtkpropcollection.html#getnextprop)")
*/





    void AddMethods(WrapClass<vtkPropCollection>::ptr this_ptr );

};


#endif // _wrap_vtkPropCollection_h
