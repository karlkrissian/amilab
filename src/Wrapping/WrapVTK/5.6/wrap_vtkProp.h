/**
 * C++ Interface: wrap_vtkProp
 *
 * Description: wrapping vtkProp
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkProp_h_
#define _wrap_vtkProp_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"



AMI_DECLARE_TYPE(vtkProp);

// TODO: check for inheritence ...
class WrapClass_vtkProp : public WrapClass<vtkProp>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkProp);

  protected:
    typedef WrapClass<vtkProp>::ptr _parentclass_ptr;
    typedef vtkProp ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkProp>& GetObj() const { return WrapClass<vtkProp>::GetObj(); }

    /// Constructor
    WrapClass_vtkProp(boost::shared_ptr<vtkProp > si): 
    WrapClass<vtkProp>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkProp()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkProp*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkProp::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkprop.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkProp * vtkProp::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkprop.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkProp::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkProp * vtkProp::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkProp::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#printself)")
*/
    ADD_CLASS_METHOD(GetActors,"void vtkProp::GetActors(vtkPropCollection * param0)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getactors)")
    ADD_CLASS_METHOD(GetActors2D,"void vtkProp::GetActors2D(vtkPropCollection * param0)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getactors2d)")
    ADD_CLASS_METHOD(GetVolumes,"void vtkProp::GetVolumes(vtkPropCollection * param0)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getvolumes)")
    ADD_CLASS_METHOD(SetVisibility,"void vtkProp::SetVisibility(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#setvisibility)")
    ADD_CLASS_METHOD(GetVisibility,"int vtkProp::GetVisibility()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getvisibility)")
    ADD_CLASS_METHOD(VisibilityOn,"void vtkProp::VisibilityOn()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#visibilityon)")
    ADD_CLASS_METHOD(VisibilityOff,"void vtkProp::VisibilityOff()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#visibilityoff)")
    ADD_CLASS_METHOD(SetPickable,"void vtkProp::SetPickable(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#setpickable)")
    ADD_CLASS_METHOD(GetPickable,"int vtkProp::GetPickable()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getpickable)")
    ADD_CLASS_METHOD(PickableOn,"void vtkProp::PickableOn()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#pickableon)")
    ADD_CLASS_METHOD(PickableOff,"void vtkProp::PickableOff()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#pickableoff)")
    ADD_CLASS_METHOD(Pick,"void vtkProp::Pick()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#pick)")
    ADD_CLASS_METHOD(SetDragable,"void vtkProp::SetDragable(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#setdragable)")
    ADD_CLASS_METHOD(GetDragable,"int vtkProp::GetDragable()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getdragable)")
    ADD_CLASS_METHOD(DragableOn,"void vtkProp::DragableOn()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#dragableon)")
    ADD_CLASS_METHOD(DragableOff,"void vtkProp::DragableOff()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#dragableoff)")
    ADD_CLASS_METHOD(GetRedrawMTime,"long unsigned int vtkProp::GetRedrawMTime()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getredrawmtime)")
    ADD_CLASS_METHOD(SetUseBounds,"void vtkProp::SetUseBounds(bool _arg)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#setusebounds)")
    ADD_CLASS_METHOD(GetUseBounds,"bool vtkProp::GetUseBounds()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getusebounds)")
    ADD_CLASS_METHOD(UseBoundsOn,"void vtkProp::UseBoundsOn()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#useboundson)")
    ADD_CLASS_METHOD(UseBoundsOff,"void vtkProp::UseBoundsOff()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#useboundsoff)")
    ADD_CLASS_METHOD(GetBounds,"double * vtkProp::GetBounds()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getbounds)")
    ADD_CLASS_METHOD(ShallowCopy,"void vtkProp::ShallowCopy(vtkProp * prop)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#shallowcopy)")
    ADD_CLASS_METHOD(InitPathTraversal,"void vtkProp::InitPathTraversal()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#initpathtraversal)")
/* The following types are missing: vtkAssemblyPath
    ADD_CLASS_METHOD(GetNextPath,"vtkAssemblyPath * vtkProp::GetNextPath()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getnextpath)")
*/
    ADD_CLASS_METHOD(GetNumberOfPaths,"int vtkProp::GetNumberOfPaths()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getnumberofpaths)")
    ADD_CLASS_METHOD(PokeMatrix,"void vtkProp::PokeMatrix(vtkMatrix4x4 * param0)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#pokematrix)")
    ADD_CLASS_METHOD(GetMatrix,"vtkMatrix4x4 * vtkProp::GetMatrix()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getmatrix)")
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(GetPropertyKeys,"vtkInformation * vtkProp::GetPropertyKeys()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getpropertykeys)")
*/
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(SetPropertyKeys,"void vtkProp::SetPropertyKeys(vtkInformation * keys)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#setpropertykeys)")
*/
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(HasKeys,"bool vtkProp::HasKeys(vtkInformation * requiredKeys)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#haskeys)")
*/
    ADD_CLASS_METHOD(RenderOpaqueGeometry,"int vtkProp::RenderOpaqueGeometry(vtkViewport * param0)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#renderopaquegeometry)")
    ADD_CLASS_METHOD(RenderTranslucentPolygonalGeometry,"int vtkProp::RenderTranslucentPolygonalGeometry(vtkViewport * param0)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#rendertranslucentpolygonalgeometry)")
    ADD_CLASS_METHOD(RenderVolumetricGeometry,"int vtkProp::RenderVolumetricGeometry(vtkViewport * param0)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#rendervolumetricgeometry)")
    ADD_CLASS_METHOD(RenderOverlay,"int vtkProp::RenderOverlay(vtkViewport * param0)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#renderoverlay)")
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(RenderFilteredOpaqueGeometry,"bool vtkProp::RenderFilteredOpaqueGeometry(vtkViewport * v, vtkInformation * requiredKeys)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#renderfilteredopaquegeometry)")
*/
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(RenderFilteredTranslucentPolygonalGeometry,"bool vtkProp::RenderFilteredTranslucentPolygonalGeometry(vtkViewport * v, vtkInformation * requiredKeys)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#renderfilteredtranslucentpolygonalgeometry)")
*/
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(RenderFilteredVolumetricGeometry,"bool vtkProp::RenderFilteredVolumetricGeometry(vtkViewport * v, vtkInformation * requiredKeys)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#renderfilteredvolumetricgeometry)")
*/
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(RenderFilteredOverlay,"bool vtkProp::RenderFilteredOverlay(vtkViewport * v, vtkInformation * requiredKeys)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#renderfilteredoverlay)")
*/
    ADD_CLASS_METHOD(HasTranslucentPolygonalGeometry,"int vtkProp::HasTranslucentPolygonalGeometry()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#hastranslucentpolygonalgeometry)")
    ADD_CLASS_METHOD(ReleaseGraphicsResources,"void vtkProp::ReleaseGraphicsResources(vtkWindow * param0)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#releasegraphicsresources)")
    ADD_CLASS_METHOD(GetEstimatedRenderTime_1,"double vtkProp::GetEstimatedRenderTime(vtkViewport * param0)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getestimatedrendertime)")
    ADD_CLASS_METHOD(GetEstimatedRenderTime,"vtkProp::GetEstimatedRenderTime()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getestimatedrendertime)")
    ADD_CLASS_METHOD(GetEstimatedRenderTime_2,"double vtkProp::GetEstimatedRenderTime()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getestimatedrendertime)")
    ADD_CLASS_METHOD(SetEstimatedRenderTime,"void vtkProp::SetEstimatedRenderTime(double t)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#setestimatedrendertime)")
    ADD_CLASS_METHOD(RestoreEstimatedRenderTime,"void vtkProp::RestoreEstimatedRenderTime()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#restoreestimatedrendertime)")
    ADD_CLASS_METHOD(AddEstimatedRenderTime,"void vtkProp::AddEstimatedRenderTime(double t, vtkViewport * param1)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#addestimatedrendertime)")
    ADD_CLASS_METHOD(SetAllocatedRenderTime,"void vtkProp::SetAllocatedRenderTime(double t, vtkViewport * param1)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#setallocatedrendertime)")
    ADD_CLASS_METHOD(GetAllocatedRenderTime,"double vtkProp::GetAllocatedRenderTime()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getallocatedrendertime)")
    ADD_CLASS_METHOD(SetRenderTimeMultiplier,"void vtkProp::SetRenderTimeMultiplier(double t)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#setrendertimemultiplier)")
    ADD_CLASS_METHOD(GetRenderTimeMultiplier,"double vtkProp::GetRenderTimeMultiplier()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getrendertimemultiplier)")
/* The following types are missing: vtkAssemblyPaths, vtkAssemblyPath
    ADD_CLASS_METHOD(BuildPaths,"void vtkProp::BuildPaths(vtkAssemblyPaths * paths, vtkAssemblyPath * path)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#buildpaths)")
*/
    ADD_CLASS_METHOD(GetSupportsSelection,"bool vtkProp::GetSupportsSelection()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getsupportsselection)")
    ADD_CLASS_METHOD(GetNumberOfConsumers,"int vtkProp::GetNumberOfConsumers()  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getnumberofconsumers)")
    ADD_CLASS_METHOD(AddConsumer,"void vtkProp::AddConsumer(vtkObject * c)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#addconsumer)")
    ADD_CLASS_METHOD(RemoveConsumer,"void vtkProp::RemoveConsumer(vtkObject * c)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#removeconsumer)")
    ADD_CLASS_METHOD(GetConsumer,"vtkObject * vtkProp::GetConsumer(int i)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#getconsumer)")
    ADD_CLASS_METHOD(IsConsumer,"int vtkProp::IsConsumer(vtkObject * c)  (http://docs.wxwidgets.org/stable/wx_vtkprop.html#isconsumer)")





    void AddMethods(WrapClass<vtkProp>::ptr this_ptr );

};


#endif // _wrap_vtkProp_h
