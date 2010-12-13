/**
 * C++ Interface: wrap_vtkVolumeRayCastMapper
 *
 * Description: wrapping vtkVolumeRayCastMapper
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkVolumeRayCastMapper_h_
#define _wrap_vtkVolumeRayCastMapper_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkVolumeRayCastMapper.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkVolumeMapper.h"


#ifndef vtkVolumeRayCastMapper_declared
  #define vtkVolumeRayCastMapper_declared
  AMI_DECLARE_TYPE(vtkVolumeRayCastMapper);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkVolumeRayCastMapper : public WrapClass<vtkVolumeRayCastMapper>
    , public   WrapClass_vtkVolumeMapper
{
  DEFINE_CLASS(WrapClass_vtkVolumeRayCastMapper);

  protected:
    typedef WrapClass<vtkVolumeRayCastMapper>::ptr _parentclass_ptr;
    typedef vtkVolumeRayCastMapper ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkVolumeRayCastMapper>& GetObj() const { return WrapClass<vtkVolumeRayCastMapper>::GetObj(); }

    /// Constructor
    WrapClass_vtkVolumeRayCastMapper(boost::shared_ptr<vtkVolumeRayCastMapper > si): 
    WrapClass<vtkVolumeRayCastMapper>(si)
    , WrapClass_vtkVolumeMapper(si)
    {}

    /// Destructor
    ~WrapClass_vtkVolumeRayCastMapper()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkVolumeRayCastMapper*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkVolumeRayCastMapper * vtkVolumeRayCastMapper::New() (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkVolumeRayCastMapper::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkVolumeRayCastMapper * vtkVolumeRayCastMapper::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkVolumeRayCastMapper::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkVolumeRayCastMapper * vtkVolumeRayCastMapper::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkVolumeRayCastMapper::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#printself)")
*/
    ADD_CLASS_METHOD(SetSampleDistance,"void vtkVolumeRayCastMapper::SetSampleDistance(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#setsampledistance)")
    ADD_CLASS_METHOD(GetSampleDistance,"double vtkVolumeRayCastMapper::GetSampleDistance()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getsampledistance)")
    ADD_CLASS_METHOD(SetVolumeRayCastFunction,"void vtkVolumeRayCastMapper::SetVolumeRayCastFunction(vtkVolumeRayCastFunction * param0)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#setvolumeraycastfunction)")
    ADD_CLASS_METHOD(GetVolumeRayCastFunction,"vtkVolumeRayCastFunction * vtkVolumeRayCastMapper::GetVolumeRayCastFunction()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getvolumeraycastfunction)")
/* The following types are missing: vtkEncodedGradientEstimator
    ADD_CLASS_METHOD(SetGradientEstimator,"void vtkVolumeRayCastMapper::SetGradientEstimator(vtkEncodedGradientEstimator * gradest)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#setgradientestimator)")
*/
/* The following types are missing: vtkEncodedGradientEstimator
    ADD_CLASS_METHOD(GetGradientEstimator,"vtkEncodedGradientEstimator * vtkVolumeRayCastMapper::GetGradientEstimator()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getgradientestimator)")
*/
/* The following types are missing: vtkEncodedGradientShader
    ADD_CLASS_METHOD(GetGradientShader,"vtkEncodedGradientShader * vtkVolumeRayCastMapper::GetGradientShader()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getgradientshader)")
*/
    ADD_CLASS_METHOD(SetImageSampleDistance,"void vtkVolumeRayCastMapper::SetImageSampleDistance(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#setimagesampledistance)")
    ADD_CLASS_METHOD(GetImageSampleDistanceMinValue,"double vtkVolumeRayCastMapper::GetImageSampleDistanceMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getimagesampledistanceminvalue)")
    ADD_CLASS_METHOD(GetImageSampleDistanceMaxValue,"double vtkVolumeRayCastMapper::GetImageSampleDistanceMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getimagesampledistancemaxvalue)")
    ADD_CLASS_METHOD(GetImageSampleDistance,"double vtkVolumeRayCastMapper::GetImageSampleDistance()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getimagesampledistance)")
    ADD_CLASS_METHOD(SetMinimumImageSampleDistance,"void vtkVolumeRayCastMapper::SetMinimumImageSampleDistance(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#setminimumimagesampledistance)")
    ADD_CLASS_METHOD(GetMinimumImageSampleDistanceMinValue,"double vtkVolumeRayCastMapper::GetMinimumImageSampleDistanceMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getminimumimagesampledistanceminvalue)")
    ADD_CLASS_METHOD(GetMinimumImageSampleDistanceMaxValue,"double vtkVolumeRayCastMapper::GetMinimumImageSampleDistanceMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getminimumimagesampledistancemaxvalue)")
    ADD_CLASS_METHOD(GetMinimumImageSampleDistance,"double vtkVolumeRayCastMapper::GetMinimumImageSampleDistance()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getminimumimagesampledistance)")
    ADD_CLASS_METHOD(SetMaximumImageSampleDistance,"void vtkVolumeRayCastMapper::SetMaximumImageSampleDistance(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#setmaximumimagesampledistance)")
    ADD_CLASS_METHOD(GetMaximumImageSampleDistanceMinValue,"double vtkVolumeRayCastMapper::GetMaximumImageSampleDistanceMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getmaximumimagesampledistanceminvalue)")
    ADD_CLASS_METHOD(GetMaximumImageSampleDistanceMaxValue,"double vtkVolumeRayCastMapper::GetMaximumImageSampleDistanceMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getmaximumimagesampledistancemaxvalue)")
    ADD_CLASS_METHOD(GetMaximumImageSampleDistance,"double vtkVolumeRayCastMapper::GetMaximumImageSampleDistance()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getmaximumimagesampledistance)")
    ADD_CLASS_METHOD(SetAutoAdjustSampleDistances,"void vtkVolumeRayCastMapper::SetAutoAdjustSampleDistances(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#setautoadjustsampledistances)")
    ADD_CLASS_METHOD(GetAutoAdjustSampleDistancesMinValue,"int vtkVolumeRayCastMapper::GetAutoAdjustSampleDistancesMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getautoadjustsampledistancesminvalue)")
    ADD_CLASS_METHOD(GetAutoAdjustSampleDistancesMaxValue,"int vtkVolumeRayCastMapper::GetAutoAdjustSampleDistancesMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getautoadjustsampledistancesmaxvalue)")
    ADD_CLASS_METHOD(GetAutoAdjustSampleDistances,"int vtkVolumeRayCastMapper::GetAutoAdjustSampleDistances()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getautoadjustsampledistances)")
    ADD_CLASS_METHOD(AutoAdjustSampleDistancesOn,"void vtkVolumeRayCastMapper::AutoAdjustSampleDistancesOn()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#autoadjustsampledistanceson)")
    ADD_CLASS_METHOD(AutoAdjustSampleDistancesOff,"void vtkVolumeRayCastMapper::AutoAdjustSampleDistancesOff()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#autoadjustsampledistancesoff)")
    ADD_CLASS_METHOD(SetNumberOfThreads,"void vtkVolumeRayCastMapper::SetNumberOfThreads(int num)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#setnumberofthreads)")
    ADD_CLASS_METHOD(GetNumberOfThreads,"int vtkVolumeRayCastMapper::GetNumberOfThreads()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getnumberofthreads)")
    ADD_CLASS_METHOD(SetIntermixIntersectingGeometry,"void vtkVolumeRayCastMapper::SetIntermixIntersectingGeometry(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#setintermixintersectinggeometry)")
    ADD_CLASS_METHOD(GetIntermixIntersectingGeometryMinValue,"int vtkVolumeRayCastMapper::GetIntermixIntersectingGeometryMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getintermixintersectinggeometryminvalue)")
    ADD_CLASS_METHOD(GetIntermixIntersectingGeometryMaxValue,"int vtkVolumeRayCastMapper::GetIntermixIntersectingGeometryMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getintermixintersectinggeometrymaxvalue)")
    ADD_CLASS_METHOD(GetIntermixIntersectingGeometry,"int vtkVolumeRayCastMapper::GetIntermixIntersectingGeometry()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getintermixintersectinggeometry)")
    ADD_CLASS_METHOD(IntermixIntersectingGeometryOn,"void vtkVolumeRayCastMapper::IntermixIntersectingGeometryOn()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#intermixintersectinggeometryon)")
    ADD_CLASS_METHOD(IntermixIntersectingGeometryOff,"void vtkVolumeRayCastMapper::IntermixIntersectingGeometryOff()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#intermixintersectinggeometryoff)")
    ADD_CLASS_METHOD(Render,"void vtkVolumeRayCastMapper::Render(vtkRenderer * param0, vtkVolume * param1)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#render)")
    ADD_CLASS_METHOD(ReleaseGraphicsResources,"void vtkVolumeRayCastMapper::ReleaseGraphicsResources(vtkWindow * param0)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#releasegraphicsresources)")
    ADD_CLASS_METHOD(GetZeroOpacityThreshold,"float vtkVolumeRayCastMapper::GetZeroOpacityThreshold(vtkVolume * vol)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getzeroopacitythreshold)")
    ADD_CLASS_METHOD(GetGradientMagnitudeScale_1,"float vtkVolumeRayCastMapper::GetGradientMagnitudeScale()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getgradientmagnitudescale)")
    ADD_CLASS_METHOD(GetGradientMagnitudeBias_1,"float vtkVolumeRayCastMapper::GetGradientMagnitudeBias()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getgradientmagnitudebias)")
    ADD_CLASS_METHOD(GetGradientMagnitudeScale,"vtkVolumeRayCastMapper::GetGradientMagnitudeScale()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getgradientmagnitudescale)")
    ADD_CLASS_METHOD(GetGradientMagnitudeScale_2,"float vtkVolumeRayCastMapper::GetGradientMagnitudeScale(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getgradientmagnitudescale)")
    ADD_CLASS_METHOD(GetGradientMagnitudeBias,"vtkVolumeRayCastMapper::GetGradientMagnitudeBias()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getgradientmagnitudebias)")
    ADD_CLASS_METHOD(GetGradientMagnitudeBias_2,"float vtkVolumeRayCastMapper::GetGradientMagnitudeBias(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastmapper.html#getgradientmagnitudebias)")





    void AddMethods(WrapClass<vtkVolumeRayCastMapper>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkVolumeRayCastMapper_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkVolumeRayCastMapper_h
