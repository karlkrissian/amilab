/**
 * C++ Interface: wrap_vtkMapper
 *
 * Description: wrapping vtkMapper
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkMapper_h_
#define _wrap_vtkMapper_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkMapper.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkAbstractMapper3D.h"


#ifndef vtkMapper_declared
  #define vtkMapper_declared
  AMI_DECLARE_TYPE(vtkMapper);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkMapper : public WrapClass<vtkMapper>
    , public   WrapClass_vtkAbstractMapper3D
{
  DEFINE_CLASS(WrapClass_vtkMapper);

  protected:
    typedef WrapClass<vtkMapper>::ptr _parentclass_ptr;
    typedef vtkMapper ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkMapper>& GetObj() const { return WrapClass<vtkMapper>::GetObj(); }

    /// Constructor
    WrapClass_vtkMapper(boost::shared_ptr<vtkMapper > si): 
    WrapClass<vtkMapper>(si)
    , WrapClass_vtkAbstractMapper3D(si)
    {}

    /// Destructor
    ~WrapClass_vtkMapper()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkMapper*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkMapper::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkMapper * vtkMapper::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(SetGlobalImmediateModeRendering,"void vtkMapper::SetGlobalImmediateModeRendering(int val) (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setglobalimmediatemoderendering).");
    ADD_CLASS_STATICMETHOD(GlobalImmediateModeRenderingOn,"void vtkMapper::GlobalImmediateModeRenderingOn() (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#globalimmediatemoderenderingon).");
    ADD_CLASS_STATICMETHOD(GlobalImmediateModeRenderingOff,"void vtkMapper::GlobalImmediateModeRenderingOff() (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#globalimmediatemoderenderingoff).");
    ADD_CLASS_STATICMETHOD(GetGlobalImmediateModeRendering,"int vtkMapper::GetGlobalImmediateModeRendering() (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getglobalimmediatemoderendering).");
    ADD_CLASS_STATICMETHOD(SetResolveCoincidentTopology,"void vtkMapper::SetResolveCoincidentTopology(int val) (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setresolvecoincidenttopology).");
    ADD_CLASS_STATICMETHOD(GetResolveCoincidentTopology,"int vtkMapper::GetResolveCoincidentTopology() (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getresolvecoincidenttopology).");
    ADD_CLASS_STATICMETHOD(SetResolveCoincidentTopologyToDefault,"void vtkMapper::SetResolveCoincidentTopologyToDefault() (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setresolvecoincidenttopologytodefault).");
    ADD_CLASS_STATICMETHOD(SetResolveCoincidentTopologyToOff,"void vtkMapper::SetResolveCoincidentTopologyToOff() (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setresolvecoincidenttopologytooff).");
    ADD_CLASS_STATICMETHOD(SetResolveCoincidentTopologyToPolygonOffset,"void vtkMapper::SetResolveCoincidentTopologyToPolygonOffset() (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setresolvecoincidenttopologytopolygonoffset).");
    ADD_CLASS_STATICMETHOD(SetResolveCoincidentTopologyToShiftZBuffer,"void vtkMapper::SetResolveCoincidentTopologyToShiftZBuffer() (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setresolvecoincidenttopologytoshiftzbuffer).");
    ADD_CLASS_STATICMETHOD(SetResolveCoincidentTopologyPolygonOffsetParameters,"void vtkMapper::SetResolveCoincidentTopologyPolygonOffsetParameters(double factor, double units) (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setresolvecoincidenttopologypolygonoffsetparameters).");
    ADD_CLASS_STATICMETHOD(GetResolveCoincidentTopologyPolygonOffsetParameters,"void vtkMapper::GetResolveCoincidentTopologyPolygonOffsetParameters(double & factor, double & units) (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getresolvecoincidenttopologypolygonoffsetparameters).");
    ADD_CLASS_STATICMETHOD(SetResolveCoincidentTopologyPolygonOffsetFaces,"void vtkMapper::SetResolveCoincidentTopologyPolygonOffsetFaces(int faces) (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setresolvecoincidenttopologypolygonoffsetfaces).");
    ADD_CLASS_STATICMETHOD(GetResolveCoincidentTopologyPolygonOffsetFaces,"int vtkMapper::GetResolveCoincidentTopologyPolygonOffsetFaces() (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getresolvecoincidenttopologypolygonoffsetfaces).");
    ADD_CLASS_STATICMETHOD(SetResolveCoincidentTopologyZShift,"void vtkMapper::SetResolveCoincidentTopologyZShift(double val) (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setresolvecoincidenttopologyzshift).");
    ADD_CLASS_STATICMETHOD(GetResolveCoincidentTopologyZShift,"double vtkMapper::GetResolveCoincidentTopologyZShift() (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getresolvecoincidenttopologyzshift).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkMapper::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkMapper * vtkMapper::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkMapper::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#printself)")
*/
    ADD_CLASS_METHOD(ShallowCopy,"void vtkMapper::ShallowCopy(vtkAbstractMapper * m)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#shallowcopy)")
    ADD_CLASS_METHOD(GetMTime,"long unsigned int vtkMapper::GetMTime()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getmtime)")
    ADD_CLASS_METHOD(ReleaseGraphicsResources,"void vtkMapper::ReleaseGraphicsResources(vtkWindow * param0)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#releasegraphicsresources)")
    ADD_CLASS_METHOD(SetLookupTable,"void vtkMapper::SetLookupTable(vtkScalarsToColors * lut)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setlookuptable)")
    ADD_CLASS_METHOD(GetLookupTable,"vtkScalarsToColors * vtkMapper::GetLookupTable()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getlookuptable)")
    ADD_CLASS_METHOD(CreateDefaultLookupTable,"void vtkMapper::CreateDefaultLookupTable()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#createdefaultlookuptable)")
    ADD_CLASS_METHOD(SetScalarVisibility,"void vtkMapper::SetScalarVisibility(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setscalarvisibility)")
    ADD_CLASS_METHOD(GetScalarVisibility,"int vtkMapper::GetScalarVisibility()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getscalarvisibility)")
    ADD_CLASS_METHOD(ScalarVisibilityOn,"void vtkMapper::ScalarVisibilityOn()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#scalarvisibilityon)")
    ADD_CLASS_METHOD(ScalarVisibilityOff,"void vtkMapper::ScalarVisibilityOff()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#scalarvisibilityoff)")
    ADD_CLASS_METHOD(SetStatic,"void vtkMapper::SetStatic(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setstatic)")
    ADD_CLASS_METHOD(GetStatic,"int vtkMapper::GetStatic()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getstatic)")
    ADD_CLASS_METHOD(StaticOn,"void vtkMapper::StaticOn()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#staticon)")
    ADD_CLASS_METHOD(StaticOff,"void vtkMapper::StaticOff()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#staticoff)")
    ADD_CLASS_METHOD(SetColorMode,"void vtkMapper::SetColorMode(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setcolormode)")
    ADD_CLASS_METHOD(GetColorMode,"int vtkMapper::GetColorMode()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getcolormode)")
    ADD_CLASS_METHOD(SetColorModeToDefault,"void vtkMapper::SetColorModeToDefault()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setcolormodetodefault)")
    ADD_CLASS_METHOD(SetColorModeToMapScalars,"void vtkMapper::SetColorModeToMapScalars()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setcolormodetomapscalars)")
    ADD_CLASS_METHOD(GetColorModeAsString,"char const * vtkMapper::GetColorModeAsString()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getcolormodeasstring)")
    ADD_CLASS_METHOD(SetInterpolateScalarsBeforeMapping,"void vtkMapper::SetInterpolateScalarsBeforeMapping(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setinterpolatescalarsbeforemapping)")
    ADD_CLASS_METHOD(GetInterpolateScalarsBeforeMapping,"int vtkMapper::GetInterpolateScalarsBeforeMapping()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getinterpolatescalarsbeforemapping)")
    ADD_CLASS_METHOD(InterpolateScalarsBeforeMappingOn,"void vtkMapper::InterpolateScalarsBeforeMappingOn()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#interpolatescalarsbeforemappingon)")
    ADD_CLASS_METHOD(InterpolateScalarsBeforeMappingOff,"void vtkMapper::InterpolateScalarsBeforeMappingOff()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#interpolatescalarsbeforemappingoff)")
    ADD_CLASS_METHOD(SetUseLookupTableScalarRange,"void vtkMapper::SetUseLookupTableScalarRange(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setuselookuptablescalarrange)")
    ADD_CLASS_METHOD(GetUseLookupTableScalarRange,"int vtkMapper::GetUseLookupTableScalarRange()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getuselookuptablescalarrange)")
    ADD_CLASS_METHOD(UseLookupTableScalarRangeOn,"void vtkMapper::UseLookupTableScalarRangeOn()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#uselookuptablescalarrangeon)")
    ADD_CLASS_METHOD(UseLookupTableScalarRangeOff,"void vtkMapper::UseLookupTableScalarRangeOff()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#uselookuptablescalarrangeoff)")
    ADD_CLASS_METHOD(SetScalarRange_1,"void vtkMapper::SetScalarRange(double _arg1, double _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setscalarrange)")
    ADD_CLASS_METHOD(SetScalarRange,"vtkMapper::SetScalarRange()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setscalarrange)")
    ADD_CLASS_METHOD(SetScalarRange_2,"void vtkMapper::SetScalarRange(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setscalarrange)")
    ADD_CLASS_METHOD(GetScalarRange_1,"double * vtkMapper::GetScalarRange()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getscalarrange)")
    ADD_CLASS_METHOD(GetScalarRange,"vtkMapper::GetScalarRange()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getscalarrange)")
    ADD_CLASS_METHOD(GetScalarRange_2,"void vtkMapper::GetScalarRange(double * data)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getscalarrange)")
    ADD_CLASS_METHOD(SetImmediateModeRendering,"void vtkMapper::SetImmediateModeRendering(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setimmediatemoderendering)")
    ADD_CLASS_METHOD(GetImmediateModeRendering,"int vtkMapper::GetImmediateModeRendering()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getimmediatemoderendering)")
    ADD_CLASS_METHOD(ImmediateModeRenderingOn,"void vtkMapper::ImmediateModeRenderingOn()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#immediatemoderenderingon)")
    ADD_CLASS_METHOD(ImmediateModeRenderingOff,"void vtkMapper::ImmediateModeRenderingOff()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#immediatemoderenderingoff)")
    ADD_CLASS_METHOD(GetForceCompileOnly,"int vtkMapper::GetForceCompileOnly()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getforcecompileonly)")
    ADD_CLASS_METHOD(SetForceCompileOnly,"void vtkMapper::SetForceCompileOnly(int value)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setforcecompileonly)")
    ADD_CLASS_METHOD(SetScalarMode,"void vtkMapper::SetScalarMode(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setscalarmode)")
    ADD_CLASS_METHOD(GetScalarMode,"int vtkMapper::GetScalarMode()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getscalarmode)")
    ADD_CLASS_METHOD(SetScalarModeToDefault,"void vtkMapper::SetScalarModeToDefault()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setscalarmodetodefault)")
    ADD_CLASS_METHOD(SetScalarModeToUsePointData,"void vtkMapper::SetScalarModeToUsePointData()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setscalarmodetousepointdata)")
    ADD_CLASS_METHOD(SetScalarModeToUseCellData,"void vtkMapper::SetScalarModeToUseCellData()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setscalarmodetousecelldata)")
    ADD_CLASS_METHOD(SetScalarModeToUsePointFieldData,"void vtkMapper::SetScalarModeToUsePointFieldData()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setscalarmodetousepointfielddata)")
    ADD_CLASS_METHOD(SetScalarModeToUseCellFieldData,"void vtkMapper::SetScalarModeToUseCellFieldData()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setscalarmodetousecellfielddata)")
    ADD_CLASS_METHOD(SetScalarModeToUseFieldData,"void vtkMapper::SetScalarModeToUseFieldData()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setscalarmodetousefielddata)")
    ADD_CLASS_METHOD(SelectColorArray_1,"void vtkMapper::SelectColorArray(int arrayNum)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#selectcolorarray)")
    ADD_CLASS_METHOD(SelectColorArray,"vtkMapper::SelectColorArray()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#selectcolorarray)")
    ADD_CLASS_METHOD(SelectColorArray_2,"void vtkMapper::SelectColorArray(char const * arrayName)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#selectcolorarray)")
    ADD_CLASS_METHOD(ColorByArrayComponent_1,"void vtkMapper::ColorByArrayComponent(int arrayNum, int component)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#colorbyarraycomponent)")
    ADD_CLASS_METHOD(ColorByArrayComponent,"vtkMapper::ColorByArrayComponent()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#colorbyarraycomponent)")
    ADD_CLASS_METHOD(ColorByArrayComponent_2,"void vtkMapper::ColorByArrayComponent(char const * arrayName, int component)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#colorbyarraycomponent)")
    ADD_CLASS_METHOD(GetArrayName,"char * vtkMapper::GetArrayName()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getarrayname)")
    ADD_CLASS_METHOD(GetArrayId,"int vtkMapper::GetArrayId()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getarrayid)")
    ADD_CLASS_METHOD(GetArrayAccessMode,"int vtkMapper::GetArrayAccessMode()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getarrayaccessmode)")
    ADD_CLASS_METHOD(GetArrayComponent,"int vtkMapper::GetArrayComponent()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getarraycomponent)")
    ADD_CLASS_METHOD(GetScalarModeAsString,"char const * vtkMapper::GetScalarModeAsString()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getscalarmodeasstring)")
    ADD_CLASS_METHOD(GetBounds_1,"double * vtkMapper::GetBounds()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getbounds)")
    ADD_CLASS_METHOD(GetBounds,"vtkMapper::GetBounds()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getbounds)")
    ADD_CLASS_METHOD(GetBounds_2,"void vtkMapper::GetBounds(double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getbounds)")
    ADD_CLASS_METHOD(SetRenderTime,"void vtkMapper::SetRenderTime(double time)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setrendertime)")
    ADD_CLASS_METHOD(GetRenderTime,"double vtkMapper::GetRenderTime()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getrendertime)")
    ADD_CLASS_METHOD(GetInput,"vtkDataSet * vtkMapper::GetInput()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getinput)")
    ADD_CLASS_METHOD(GetInputAsDataSet,"vtkDataSet * vtkMapper::GetInputAsDataSet()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getinputasdataset)")
    ADD_CLASS_METHOD(MapScalars,"vtkUnsignedCharArray * vtkMapper::MapScalars(double alpha)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#mapscalars)")
    ADD_CLASS_METHOD(SetScalarMaterialMode,"void vtkMapper::SetScalarMaterialMode(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setscalarmaterialmode)")
    ADD_CLASS_METHOD(GetScalarMaterialMode,"int vtkMapper::GetScalarMaterialMode()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getscalarmaterialmode)")
    ADD_CLASS_METHOD(SetScalarMaterialModeToDefault,"void vtkMapper::SetScalarMaterialModeToDefault()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setscalarmaterialmodetodefault)")
    ADD_CLASS_METHOD(SetScalarMaterialModeToAmbient,"void vtkMapper::SetScalarMaterialModeToAmbient()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setscalarmaterialmodetoambient)")
    ADD_CLASS_METHOD(SetScalarMaterialModeToDiffuse,"void vtkMapper::SetScalarMaterialModeToDiffuse()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setscalarmaterialmodetodiffuse)")
    ADD_CLASS_METHOD(SetScalarMaterialModeToAmbientAndDiffuse,"void vtkMapper::SetScalarMaterialModeToAmbientAndDiffuse()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#setscalarmaterialmodetoambientanddiffuse)")
    ADD_CLASS_METHOD(GetScalarMaterialModeAsString,"char const * vtkMapper::GetScalarMaterialModeAsString()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getscalarmaterialmodeasstring)")
    ADD_CLASS_METHOD(GetSupportsSelection,"bool vtkMapper::GetSupportsSelection()  (http://docs.wxwidgets.org/stable/wx_vtkmapper.html#getsupportsselection)")





    void AddMethods(WrapClass<vtkMapper>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkMapper_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkMapper_h
