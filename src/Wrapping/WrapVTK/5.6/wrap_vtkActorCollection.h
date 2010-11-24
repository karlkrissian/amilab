/**
 * C++ Interface: wrap_vtkActorCollection
 *
 * Description: wrapping vtkActorCollection
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkActorCollection_h_
#define _wrap_vtkActorCollection_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkPropCollection.h"



AMI_DECLARE_TYPE(vtkActorCollection);

// TODO: check for inheritence ...
class WrapClass_vtkActorCollection : public WrapClass<vtkActorCollection>
    , public   WrapClass_vtkPropCollection
{
  DEFINE_CLASS(WrapClass_vtkActorCollection);

  protected:
    typedef WrapClass<vtkActorCollection>::ptr _parentclass_ptr;
    typedef vtkActorCollection ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkActorCollection>& GetObj() const { return WrapClass<vtkActorCollection>::GetObj(); }

    /// Constructor
    WrapClass_vtkActorCollection(boost::shared_ptr<vtkActorCollection > si): 
    WrapClass<vtkActorCollection>(si)
    , WrapClass_vtkPropCollection(si)
    {}

    /// Destructor
    ~WrapClass_vtkActorCollection()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkActorCollection*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkActorCollection * vtkActorCollection::New() (http://docs.wxwidgets.org/stable/wx_vtkactorcollection.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkActorCollection::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkactorcollection.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkActorCollection * vtkActorCollection::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkactorcollection.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkActorCollection::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkactorcollection.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkActorCollection * vtkActorCollection::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkactorcollection.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkActorCollection::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkactorcollection.html#printself)")
*/
    ADD_CLASS_METHOD(AddItem,"void vtkActorCollection::AddItem(vtkActor * a)  (http://docs.wxwidgets.org/stable/wx_vtkactorcollection.html#additem)")
    ADD_CLASS_METHOD(GetNextActor_1,"vtkActor * vtkActorCollection::GetNextActor()  (http://docs.wxwidgets.org/stable/wx_vtkactorcollection.html#getnextactor)")
    ADD_CLASS_METHOD(GetLastActor,"vtkActor * vtkActorCollection::GetLastActor()  (http://docs.wxwidgets.org/stable/wx_vtkactorcollection.html#getlastactor)")
    ADD_CLASS_METHOD(GetNextItem,"vtkActor * vtkActorCollection::GetNextItem()  (http://docs.wxwidgets.org/stable/wx_vtkactorcollection.html#getnextitem)")
    ADD_CLASS_METHOD(GetLastItem,"vtkActor * vtkActorCollection::GetLastItem()  (http://docs.wxwidgets.org/stable/wx_vtkactorcollection.html#getlastitem)")
/* The following types are missing: vtkProperty
    ADD_CLASS_METHOD(ApplyProperties,"void vtkActorCollection::ApplyProperties(vtkProperty * p)  (http://docs.wxwidgets.org/stable/wx_vtkactorcollection.html#applyproperties)")
*/
    ADD_CLASS_METHOD(GetNextActor,"vtkActorCollection::GetNextActor()  (http://docs.wxwidgets.org/stable/wx_vtkactorcollection.html#getnextactor)")
/* The following types are missing: void
    ADD_CLASS_METHOD(GetNextActor_2,"vtkActor * vtkActorCollection::GetNextActor(vtkCollectionSimpleIterator & cookie)  (http://docs.wxwidgets.org/stable/wx_vtkactorcollection.html#getnextactor)")
*/





    void AddMethods(WrapClass<vtkActorCollection>::ptr this_ptr );

};


#endif // _wrap_vtkActorCollection_h
