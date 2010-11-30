/**
 * C++ Interface: wrap_vtkVolume
 *
 * Description: wrapping vtkVolume
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkVolume_h_
#define _wrap_vtkVolume_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkProp3D.h"



AMI_DECLARE_TYPE(vtkVolume);

// TODO: check for inheritence ...
class WrapClass_vtkVolume : public WrapClass<vtkVolume>
    , public   WrapClass_vtkProp3D
{
  DEFINE_CLASS(WrapClass_vtkVolume);

  protected:
    typedef WrapClass<vtkVolume>::ptr _parentclass_ptr;
    typedef vtkVolume ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkVolume>& GetObj() const { return WrapClass<vtkVolume>::GetObj(); }

    /// Constructor
    WrapClass_vtkVolume(boost::shared_ptr<vtkVolume > si): 
    WrapClass<vtkVolume>(si)
    , WrapClass_vtkProp3D(si)
    {}

    /// Destructor
    ~WrapClass_vtkVolume()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkVolume*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkVolume::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkVolume * vtkVolume::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(New,"vtkVolume * vtkVolume::New() (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#new).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkVolume::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkVolume * vtkVolume::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkVolume::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#printself)")
*/
    ADD_CLASS_METHOD(SetMapper,"void vtkVolume::SetMapper(vtkAbstractVolumeMapper * mapper)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#setmapper)")
    ADD_CLASS_METHOD(GetMapper,"vtkAbstractVolumeMapper * vtkVolume::GetMapper()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getmapper)")
    ADD_CLASS_METHOD(SetProperty,"void vtkVolume::SetProperty(vtkVolumeProperty * property)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#setproperty)")
    ADD_CLASS_METHOD(GetProperty,"vtkVolumeProperty * vtkVolume::GetProperty()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getproperty)")
    ADD_CLASS_METHOD(GetVolumes,"void vtkVolume::GetVolumes(vtkPropCollection * vc)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getvolumes)")
    ADD_CLASS_METHOD(Update,"void vtkVolume::Update()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#update)")
    ADD_CLASS_METHOD(GetBounds_1,"double * vtkVolume::GetBounds()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getbounds)")
    ADD_CLASS_METHOD(GetBounds,"vtkVolume::GetBounds()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getbounds)")
    ADD_CLASS_METHOD(GetBounds_2,"void vtkVolume::GetBounds(double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getbounds)")
    ADD_CLASS_METHOD(GetMinXBound,"double vtkVolume::GetMinXBound()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getminxbound)")
    ADD_CLASS_METHOD(GetMaxXBound,"double vtkVolume::GetMaxXBound()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getmaxxbound)")
    ADD_CLASS_METHOD(GetMinYBound,"double vtkVolume::GetMinYBound()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getminybound)")
    ADD_CLASS_METHOD(GetMaxYBound,"double vtkVolume::GetMaxYBound()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getmaxybound)")
    ADD_CLASS_METHOD(GetMinZBound,"double vtkVolume::GetMinZBound()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getminzbound)")
    ADD_CLASS_METHOD(GetMaxZBound,"double vtkVolume::GetMaxZBound()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getmaxzbound)")
    ADD_CLASS_METHOD(GetMTime,"long unsigned int vtkVolume::GetMTime()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getmtime)")
    ADD_CLASS_METHOD(GetRedrawMTime,"long unsigned int vtkVolume::GetRedrawMTime()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getredrawmtime)")
    ADD_CLASS_METHOD(ShallowCopy,"void vtkVolume::ShallowCopy(vtkProp * prop)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#shallowcopy)")
    ADD_CLASS_METHOD(RenderVolumetricGeometry,"int vtkVolume::RenderVolumetricGeometry(vtkViewport * viewport)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#rendervolumetricgeometry)")
    ADD_CLASS_METHOD(ReleaseGraphicsResources,"void vtkVolume::ReleaseGraphicsResources(vtkWindow * param0)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#releasegraphicsresources)")
    ADD_CLASS_METHOD(GetCorrectedScalarOpacityArray_1,"float * vtkVolume::GetCorrectedScalarOpacityArray(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getcorrectedscalaropacityarray)")
    ADD_CLASS_METHOD(GetCorrectedScalarOpacityArray,"vtkVolume::GetCorrectedScalarOpacityArray()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getcorrectedscalaropacityarray)")
    ADD_CLASS_METHOD(GetCorrectedScalarOpacityArray_2,"float * vtkVolume::GetCorrectedScalarOpacityArray()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getcorrectedscalaropacityarray)")
    ADD_CLASS_METHOD(GetScalarOpacityArray_1,"float * vtkVolume::GetScalarOpacityArray(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getscalaropacityarray)")
    ADD_CLASS_METHOD(GetScalarOpacityArray,"vtkVolume::GetScalarOpacityArray()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getscalaropacityarray)")
    ADD_CLASS_METHOD(GetScalarOpacityArray_2,"float * vtkVolume::GetScalarOpacityArray()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getscalaropacityarray)")
    ADD_CLASS_METHOD(GetGradientOpacityArray_1,"float * vtkVolume::GetGradientOpacityArray(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getgradientopacityarray)")
    ADD_CLASS_METHOD(GetGradientOpacityArray,"vtkVolume::GetGradientOpacityArray()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getgradientopacityarray)")
    ADD_CLASS_METHOD(GetGradientOpacityArray_2,"float * vtkVolume::GetGradientOpacityArray()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getgradientopacityarray)")
    ADD_CLASS_METHOD(GetGrayArray_1,"float * vtkVolume::GetGrayArray(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getgrayarray)")
    ADD_CLASS_METHOD(GetGrayArray,"vtkVolume::GetGrayArray()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getgrayarray)")
    ADD_CLASS_METHOD(GetGrayArray_2,"float * vtkVolume::GetGrayArray()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getgrayarray)")
    ADD_CLASS_METHOD(GetRGBArray_1,"float * vtkVolume::GetRGBArray(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getrgbarray)")
    ADD_CLASS_METHOD(GetRGBArray,"vtkVolume::GetRGBArray()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getrgbarray)")
    ADD_CLASS_METHOD(GetRGBArray_2,"float * vtkVolume::GetRGBArray()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getrgbarray)")
    ADD_CLASS_METHOD(GetGradientOpacityConstant_1,"float vtkVolume::GetGradientOpacityConstant(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getgradientopacityconstant)")
    ADD_CLASS_METHOD(GetGradientOpacityConstant,"vtkVolume::GetGradientOpacityConstant()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getgradientopacityconstant)")
    ADD_CLASS_METHOD(GetGradientOpacityConstant_2,"float vtkVolume::GetGradientOpacityConstant()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getgradientopacityconstant)")
    ADD_CLASS_METHOD(GetArraySize,"float vtkVolume::GetArraySize()  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#getarraysize)")
    ADD_CLASS_METHOD(UpdateTransferFunctions,"void vtkVolume::UpdateTransferFunctions(vtkRenderer * ren)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#updatetransferfunctions)")
    ADD_CLASS_METHOD(UpdateScalarOpacityforSampleSize,"void vtkVolume::UpdateScalarOpacityforSampleSize(vtkRenderer * ren, float sample_distance)  (http://docs.wxwidgets.org/stable/wx_vtkvolume.html#updatescalaropacityforsamplesize)")





    void AddMethods(WrapClass<vtkVolume>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkVolume_h
