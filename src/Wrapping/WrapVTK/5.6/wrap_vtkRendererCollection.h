/**
 * C++ Interface: wrap_vtkRendererCollection
 *
 * Description: wrapping vtkRendererCollection
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkRendererCollection_h_
#define _wrap_vtkRendererCollection_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkCollection.h"



AMI_DECLARE_TYPE(vtkRendererCollection);

// TODO: check for inheritence ...
class WrapClass_vtkRendererCollection : public WrapClass<vtkRendererCollection>
    , public   WrapClass_vtkCollection
{
  DEFINE_CLASS(WrapClass_vtkRendererCollection);

  protected:
    typedef WrapClass<vtkRendererCollection>::ptr _parentclass_ptr;
    typedef vtkRendererCollection ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkRendererCollection>& GetObj() const { return WrapClass<vtkRendererCollection>::GetObj(); }

    /// Constructor
    WrapClass_vtkRendererCollection(boost::shared_ptr<vtkRendererCollection > si): 
    WrapClass<vtkRendererCollection>(si)
    , WrapClass_vtkCollection(si)
    {}

    /// Destructor
    ~WrapClass_vtkRendererCollection()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkRendererCollection*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkRendererCollection * vtkRendererCollection::New() (http://docs.wxwidgets.org/stable/wx_vtkrenderercollection.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkRendererCollection::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkrenderercollection.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkRendererCollection * vtkRendererCollection::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkrenderercollection.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkRendererCollection::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkrenderercollection.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkRendererCollection * vtkRendererCollection::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkrenderercollection.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkRendererCollection::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkrenderercollection.html#printself)")
*/
    ADD_CLASS_METHOD(AddItem,"void vtkRendererCollection::AddItem(vtkRenderer * a)  (http://docs.wxwidgets.org/stable/wx_vtkrenderercollection.html#additem)")
    ADD_CLASS_METHOD(GetNextItem,"vtkRenderer * vtkRendererCollection::GetNextItem()  (http://docs.wxwidgets.org/stable/wx_vtkrenderercollection.html#getnextitem)")
    ADD_CLASS_METHOD(Render,"void vtkRendererCollection::Render()  (http://docs.wxwidgets.org/stable/wx_vtkrenderercollection.html#render)")
    ADD_CLASS_METHOD(GetFirstRenderer,"vtkRenderer * vtkRendererCollection::GetFirstRenderer()  (http://docs.wxwidgets.org/stable/wx_vtkrenderercollection.html#getfirstrenderer)")
/* The following types are missing: void
    ADD_CLASS_METHOD(GetNextRenderer,"vtkRenderer * vtkRendererCollection::GetNextRenderer(vtkCollectionSimpleIterator & cookie)  (http://docs.wxwidgets.org/stable/wx_vtkrenderercollection.html#getnextrenderer)")
*/





    void AddMethods(WrapClass<vtkRendererCollection>::ptr this_ptr );

};


#endif // _wrap_vtkRendererCollection_h
