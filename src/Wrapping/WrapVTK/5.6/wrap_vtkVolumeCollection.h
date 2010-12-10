/**
 * C++ Interface: wrap_vtkVolumeCollection
 *
 * Description: wrapping vtkVolumeCollection
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkVolumeCollection_h_
#define _wrap_vtkVolumeCollection_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkVolumeCollection.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkPropCollection.h"



AMI_DECLARE_TYPE(vtkVolumeCollection);

// TODO: check for inheritence ...
class WrapClass_vtkVolumeCollection : public WrapClass<vtkVolumeCollection>
    , public   WrapClass_vtkPropCollection
{
  DEFINE_CLASS(WrapClass_vtkVolumeCollection);

  protected:
    typedef WrapClass<vtkVolumeCollection>::ptr _parentclass_ptr;
    typedef vtkVolumeCollection ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkVolumeCollection>& GetObj() const { return WrapClass<vtkVolumeCollection>::GetObj(); }

    /// Constructor
    WrapClass_vtkVolumeCollection(boost::shared_ptr<vtkVolumeCollection > si): 
    WrapClass<vtkVolumeCollection>(si)
    , WrapClass_vtkPropCollection(si)
    {}

    /// Destructor
    ~WrapClass_vtkVolumeCollection()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkVolumeCollection*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkVolumeCollection * vtkVolumeCollection::New() (http://docs.wxwidgets.org/stable/wx_vtkvolumecollection.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkVolumeCollection::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkvolumecollection.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkVolumeCollection * vtkVolumeCollection::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkvolumecollection.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkVolumeCollection::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkvolumecollection.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkVolumeCollection * vtkVolumeCollection::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkvolumecollection.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkVolumeCollection::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkvolumecollection.html#printself)")
*/
    ADD_CLASS_METHOD(AddItem,"void vtkVolumeCollection::AddItem(vtkVolume * a)  (http://docs.wxwidgets.org/stable/wx_vtkvolumecollection.html#additem)")
    ADD_CLASS_METHOD(GetNextVolume_1,"vtkVolume * vtkVolumeCollection::GetNextVolume()  (http://docs.wxwidgets.org/stable/wx_vtkvolumecollection.html#getnextvolume)")
    ADD_CLASS_METHOD(GetNextItem,"vtkVolume * vtkVolumeCollection::GetNextItem()  (http://docs.wxwidgets.org/stable/wx_vtkvolumecollection.html#getnextitem)")
    ADD_CLASS_METHOD(GetNextVolume,"vtkVolumeCollection::GetNextVolume()  (http://docs.wxwidgets.org/stable/wx_vtkvolumecollection.html#getnextvolume)")
/* The following types are missing: void
    ADD_CLASS_METHOD(GetNextVolume_2,"vtkVolume * vtkVolumeCollection::GetNextVolume(vtkCollectionSimpleIterator & cookie)  (http://docs.wxwidgets.org/stable/wx_vtkvolumecollection.html#getnextvolume)")
*/





    void AddMethods(WrapClass<vtkVolumeCollection>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkVolumeCollection_h
