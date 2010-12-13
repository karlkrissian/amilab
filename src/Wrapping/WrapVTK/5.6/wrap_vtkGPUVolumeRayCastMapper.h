/**
 * C++ Interface: wrap_vtkGPUVolumeRayCastMapper
 *
 * Description: wrapping vtkGPUVolumeRayCastMapper
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkGPUVolumeRayCastMapper_h_
#define _wrap_vtkGPUVolumeRayCastMapper_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkGPUVolumeRayCastMapper.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkVolumeMapper.h"


#ifndef vtkGPUVolumeRayCastMapper_declared
  #define vtkGPUVolumeRayCastMapper_declared
  AMI_DECLARE_TYPE(vtkGPUVolumeRayCastMapper);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkGPUVolumeRayCastMapper : public WrapClass<vtkGPUVolumeRayCastMapper>
    , public   WrapClass_vtkVolumeMapper
{
  DEFINE_CLASS(WrapClass_vtkGPUVolumeRayCastMapper);

  protected:
    typedef WrapClass<vtkGPUVolumeRayCastMapper>::ptr _parentclass_ptr;
    typedef vtkGPUVolumeRayCastMapper ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkGPUVolumeRayCastMapper>& GetObj() const { return WrapClass<vtkGPUVolumeRayCastMapper>::GetObj(); }

    /// Constructor
    WrapClass_vtkGPUVolumeRayCastMapper(boost::shared_ptr<vtkGPUVolumeRayCastMapper > si): 
    WrapClass<vtkGPUVolumeRayCastMapper>(si)
    , WrapClass_vtkVolumeMapper(si)
    {}

    /// Destructor
    ~WrapClass_vtkGPUVolumeRayCastMapper()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkGPUVolumeRayCastMapper*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkGPUVolumeRayCastMapper * vtkGPUVolumeRayCastMapper::New() (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkGPUVolumeRayCastMapper::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkGPUVolumeRayCastMapper * vtkGPUVolumeRayCastMapper::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkGPUVolumeRayCastMapper::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkGPUVolumeRayCastMapper * vtkGPUVolumeRayCastMapper::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkGPUVolumeRayCastMapper::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#printself)")
*/
    ADD_CLASS_METHOD(SetAutoAdjustSampleDistances,"void vtkGPUVolumeRayCastMapper::SetAutoAdjustSampleDistances(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#setautoadjustsampledistances)")
    ADD_CLASS_METHOD(GetAutoAdjustSampleDistancesMinValue,"int vtkGPUVolumeRayCastMapper::GetAutoAdjustSampleDistancesMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getautoadjustsampledistancesminvalue)")
    ADD_CLASS_METHOD(GetAutoAdjustSampleDistancesMaxValue,"int vtkGPUVolumeRayCastMapper::GetAutoAdjustSampleDistancesMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getautoadjustsampledistancesmaxvalue)")
    ADD_CLASS_METHOD(GetAutoAdjustSampleDistances,"int vtkGPUVolumeRayCastMapper::GetAutoAdjustSampleDistances()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getautoadjustsampledistances)")
    ADD_CLASS_METHOD(AutoAdjustSampleDistancesOn,"void vtkGPUVolumeRayCastMapper::AutoAdjustSampleDistancesOn()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#autoadjustsampledistanceson)")
    ADD_CLASS_METHOD(AutoAdjustSampleDistancesOff,"void vtkGPUVolumeRayCastMapper::AutoAdjustSampleDistancesOff()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#autoadjustsampledistancesoff)")
    ADD_CLASS_METHOD(SetSampleDistance,"void vtkGPUVolumeRayCastMapper::SetSampleDistance(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#setsampledistance)")
    ADD_CLASS_METHOD(GetSampleDistance,"float vtkGPUVolumeRayCastMapper::GetSampleDistance()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getsampledistance)")
    ADD_CLASS_METHOD(SetImageSampleDistance,"void vtkGPUVolumeRayCastMapper::SetImageSampleDistance(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#setimagesampledistance)")
    ADD_CLASS_METHOD(GetImageSampleDistanceMinValue,"float vtkGPUVolumeRayCastMapper::GetImageSampleDistanceMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getimagesampledistanceminvalue)")
    ADD_CLASS_METHOD(GetImageSampleDistanceMaxValue,"float vtkGPUVolumeRayCastMapper::GetImageSampleDistanceMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getimagesampledistancemaxvalue)")
    ADD_CLASS_METHOD(GetImageSampleDistance,"float vtkGPUVolumeRayCastMapper::GetImageSampleDistance()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getimagesampledistance)")
    ADD_CLASS_METHOD(SetMinimumImageSampleDistance,"void vtkGPUVolumeRayCastMapper::SetMinimumImageSampleDistance(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#setminimumimagesampledistance)")
    ADD_CLASS_METHOD(GetMinimumImageSampleDistanceMinValue,"float vtkGPUVolumeRayCastMapper::GetMinimumImageSampleDistanceMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getminimumimagesampledistanceminvalue)")
    ADD_CLASS_METHOD(GetMinimumImageSampleDistanceMaxValue,"float vtkGPUVolumeRayCastMapper::GetMinimumImageSampleDistanceMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getminimumimagesampledistancemaxvalue)")
    ADD_CLASS_METHOD(GetMinimumImageSampleDistance,"float vtkGPUVolumeRayCastMapper::GetMinimumImageSampleDistance()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getminimumimagesampledistance)")
    ADD_CLASS_METHOD(SetMaximumImageSampleDistance,"void vtkGPUVolumeRayCastMapper::SetMaximumImageSampleDistance(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#setmaximumimagesampledistance)")
    ADD_CLASS_METHOD(GetMaximumImageSampleDistanceMinValue,"float vtkGPUVolumeRayCastMapper::GetMaximumImageSampleDistanceMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getmaximumimagesampledistanceminvalue)")
    ADD_CLASS_METHOD(GetMaximumImageSampleDistanceMaxValue,"float vtkGPUVolumeRayCastMapper::GetMaximumImageSampleDistanceMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getmaximumimagesampledistancemaxvalue)")
    ADD_CLASS_METHOD(GetMaximumImageSampleDistance,"float vtkGPUVolumeRayCastMapper::GetMaximumImageSampleDistance()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getmaximumimagesampledistance)")
    ADD_CLASS_METHOD(SetFinalColorWindow,"void vtkGPUVolumeRayCastMapper::SetFinalColorWindow(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#setfinalcolorwindow)")
    ADD_CLASS_METHOD(GetFinalColorWindow,"float vtkGPUVolumeRayCastMapper::GetFinalColorWindow()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getfinalcolorwindow)")
    ADD_CLASS_METHOD(SetFinalColorLevel,"void vtkGPUVolumeRayCastMapper::SetFinalColorLevel(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#setfinalcolorlevel)")
    ADD_CLASS_METHOD(GetFinalColorLevel,"float vtkGPUVolumeRayCastMapper::GetFinalColorLevel()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getfinalcolorlevel)")
    ADD_CLASS_METHOD(SetMaxMemoryInBytes,"void vtkGPUVolumeRayCastMapper::SetMaxMemoryInBytes(vtkIdType _arg)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#setmaxmemoryinbytes)")
    ADD_CLASS_METHOD(GetMaxMemoryInBytes,"vtkIdType vtkGPUVolumeRayCastMapper::GetMaxMemoryInBytes()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getmaxmemoryinbytes)")
    ADD_CLASS_METHOD(SetMaxMemoryFraction,"void vtkGPUVolumeRayCastMapper::SetMaxMemoryFraction(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#setmaxmemoryfraction)")
    ADD_CLASS_METHOD(GetMaxMemoryFractionMinValue,"float vtkGPUVolumeRayCastMapper::GetMaxMemoryFractionMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getmaxmemoryfractionminvalue)")
    ADD_CLASS_METHOD(GetMaxMemoryFractionMaxValue,"float vtkGPUVolumeRayCastMapper::GetMaxMemoryFractionMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getmaxmemoryfractionmaxvalue)")
    ADD_CLASS_METHOD(GetMaxMemoryFraction,"float vtkGPUVolumeRayCastMapper::GetMaxMemoryFraction()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getmaxmemoryfraction)")
    ADD_CLASS_METHOD(SetReportProgress,"void vtkGPUVolumeRayCastMapper::SetReportProgress(bool _arg)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#setreportprogress)")
    ADD_CLASS_METHOD(GetReportProgress,"bool vtkGPUVolumeRayCastMapper::GetReportProgress()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getreportprogress)")
    ADD_CLASS_METHOD(IsRenderSupported,"int vtkGPUVolumeRayCastMapper::IsRenderSupported(vtkRenderWindow * param0, vtkVolumeProperty * param1)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#isrendersupported)")
    ADD_CLASS_METHOD(CreateCanonicalView,"void vtkGPUVolumeRayCastMapper::CreateCanonicalView(vtkRenderer * ren, vtkVolume * volume, vtkImageData * image, int blend_mode, double * viewDirection, double * viewUp)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#createcanonicalview)")
    ADD_CLASS_METHOD(SetMaskInput,"void vtkGPUVolumeRayCastMapper::SetMaskInput(vtkImageData * mask)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#setmaskinput)")
    ADD_CLASS_METHOD(GetMaskInput,"vtkImageData * vtkGPUVolumeRayCastMapper::GetMaskInput()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getmaskinput)")
    ADD_CLASS_METHOD(SetMaskBlendFactor,"void vtkGPUVolumeRayCastMapper::SetMaskBlendFactor(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#setmaskblendfactor)")
    ADD_CLASS_METHOD(GetMaskBlendFactorMinValue,"float vtkGPUVolumeRayCastMapper::GetMaskBlendFactorMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getmaskblendfactorminvalue)")
    ADD_CLASS_METHOD(GetMaskBlendFactorMaxValue,"float vtkGPUVolumeRayCastMapper::GetMaskBlendFactorMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getmaskblendfactormaxvalue)")
    ADD_CLASS_METHOD(GetMaskBlendFactor,"float vtkGPUVolumeRayCastMapper::GetMaskBlendFactor()  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#getmaskblendfactor)")
    ADD_CLASS_METHOD(Render,"void vtkGPUVolumeRayCastMapper::Render(vtkRenderer * param0, vtkVolume * param1)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#render)")
    ADD_CLASS_METHOD(GPURender,"void vtkGPUVolumeRayCastMapper::GPURender(vtkRenderer * param0, vtkVolume * param1)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#gpurender)")
    ADD_CLASS_METHOD(ReleaseGraphicsResources,"void vtkGPUVolumeRayCastMapper::ReleaseGraphicsResources(vtkWindow * param0)  (http://docs.wxwidgets.org/stable/wx_vtkgpuvolumeraycastmapper.html#releasegraphicsresources)")





    void AddMethods(WrapClass<vtkGPUVolumeRayCastMapper>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkGPUVolumeRayCastMapper_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkGPUVolumeRayCastMapper_h
