/**
 * C++ Interface: wrap_vtkActor
 *
 * Description: wrapping vtkActor
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkActor_h_
#define _wrap_vtkActor_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkActor.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkProp3D.h"


#ifndef vtkActor_declared
  #define vtkActor_declared
  AMI_DECLARE_TYPE(vtkActor);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkActor : public WrapClass<vtkActor>
    , public   WrapClass_vtkProp3D
{
  DEFINE_CLASS(WrapClass_vtkActor);

  protected:
    typedef WrapClass<vtkActor>::ptr _parentclass_ptr;
    typedef vtkActor ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkActor>& GetObj() const { return WrapClass<vtkActor>::GetObj(); }

    /// Constructor
    WrapClass_vtkActor(boost::shared_ptr<vtkActor > si): 
    WrapClass<vtkActor>(si)
    , WrapClass_vtkProp3D(si)
    {}

    /// Destructor
    ~WrapClass_vtkActor()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkActor*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkActor::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkactor.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkActor * vtkActor::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkactor.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(New,"vtkActor * vtkActor::New() (http://docs.wxwidgets.org/stable/wx_vtkactor.html#new).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkActor::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkActor * vtkActor::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkActor::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#printself)")
*/
    ADD_CLASS_METHOD(GetActors,"void vtkActor::GetActors(vtkPropCollection * param0)  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#getactors)")
    ADD_CLASS_METHOD(RenderOpaqueGeometry,"int vtkActor::RenderOpaqueGeometry(vtkViewport * viewport)  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#renderopaquegeometry)")
    ADD_CLASS_METHOD(RenderTranslucentPolygonalGeometry,"int vtkActor::RenderTranslucentPolygonalGeometry(vtkViewport * viewport)  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#rendertranslucentpolygonalgeometry)")
    ADD_CLASS_METHOD(HasTranslucentPolygonalGeometry,"int vtkActor::HasTranslucentPolygonalGeometry()  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#hastranslucentpolygonalgeometry)")
/* The following types are missing: vtkMapper
    ADD_CLASS_METHOD(Render,"void vtkActor::Render(vtkRenderer * param0, vtkMapper * param1)  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#render)")
*/
    ADD_CLASS_METHOD(ShallowCopy,"void vtkActor::ShallowCopy(vtkProp * prop)  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#shallowcopy)")
    ADD_CLASS_METHOD(ReleaseGraphicsResources,"void vtkActor::ReleaseGraphicsResources(vtkWindow * param0)  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#releasegraphicsresources)")
    ADD_CLASS_METHOD(SetProperty,"void vtkActor::SetProperty(vtkProperty * lut)  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#setproperty)")
    ADD_CLASS_METHOD(GetProperty,"vtkProperty * vtkActor::GetProperty()  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#getproperty)")
    ADD_CLASS_METHOD(MakeProperty,"vtkProperty * vtkActor::MakeProperty()  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#makeproperty)")
    ADD_CLASS_METHOD(SetBackfaceProperty,"void vtkActor::SetBackfaceProperty(vtkProperty * lut)  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#setbackfaceproperty)")
    ADD_CLASS_METHOD(GetBackfaceProperty,"vtkProperty * vtkActor::GetBackfaceProperty()  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#getbackfaceproperty)")
/* The following types are missing: vtkTexture
    ADD_CLASS_METHOD(SetTexture,"void vtkActor::SetTexture(vtkTexture * param0)  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#settexture)")
*/
/* The following types are missing: vtkTexture
    ADD_CLASS_METHOD(GetTexture,"vtkTexture * vtkActor::GetTexture()  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#gettexture)")
*/
/* The following types are missing: vtkMapper
    ADD_CLASS_METHOD(SetMapper,"void vtkActor::SetMapper(vtkMapper * param0)  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#setmapper)")
*/
/* The following types are missing: vtkMapper
    ADD_CLASS_METHOD(GetMapper,"vtkMapper * vtkActor::GetMapper()  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#getmapper)")
*/
    ADD_CLASS_METHOD(GetBounds_1,"void vtkActor::GetBounds(double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#getbounds)")
    ADD_CLASS_METHOD(GetBounds,"vtkActor::GetBounds()  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#getbounds)")
    ADD_CLASS_METHOD(GetBounds_2,"double * vtkActor::GetBounds()  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#getbounds)")
    ADD_CLASS_METHOD(ApplyProperties,"void vtkActor::ApplyProperties()  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#applyproperties)")
    ADD_CLASS_METHOD(GetMTime,"long unsigned int vtkActor::GetMTime()  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#getmtime)")
    ADD_CLASS_METHOD(GetRedrawMTime,"long unsigned int vtkActor::GetRedrawMTime()  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#getredrawmtime)")
    ADD_CLASS_METHOD(GetSupportsSelection,"bool vtkActor::GetSupportsSelection()  (http://docs.wxwidgets.org/stable/wx_vtkactor.html#getsupportsselection)")





    void AddMethods(WrapClass<vtkActor>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkActor_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkActor_h
