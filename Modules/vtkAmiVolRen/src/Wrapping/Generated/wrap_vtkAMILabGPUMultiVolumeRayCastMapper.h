/**
 * C++ Interface: wrap_vtkAMILabGPUMultiVolumeRayCastMapper
 *
 * Description: wrapping vtkAMILabGPUMultiVolumeRayCastMapper
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkAMILabGPUMultiVolumeRayCastMapper_h_
#define _wrap_vtkAMILabGPUMultiVolumeRayCastMapper_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "/home/karl/projects/Sourceforge/amilab/trunk/Modules/vtkAmiVolRen/src/vtkAMILabGPUMultiVolumeRayCastMapper.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkVolumeMapper.h"


#ifndef vtkAMILabGPUMultiVolumeRayCastMapper_declared
  #define vtkAMILabGPUMultiVolumeRayCastMapper_declared
  AMI_DECLARE_TYPE(vtkAMILabGPUMultiVolumeRayCastMapper);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper : public WrapClass<vtkAMILabGPUMultiVolumeRayCastMapper>
    , public   WrapClass_vtkVolumeMapper
{
  DEFINE_CLASS(WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper);

  protected:
    typedef WrapClass<vtkAMILabGPUMultiVolumeRayCastMapper>::ptr _parentclass_ptr;
    typedef vtkAMILabGPUMultiVolumeRayCastMapper ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkAMILabGPUMultiVolumeRayCastMapper>& GetObj() const { return WrapClass<vtkAMILabGPUMultiVolumeRayCastMapper>::GetObj(); }

    /// Constructor
    WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper(boost::shared_ptr<vtkAMILabGPUMultiVolumeRayCastMapper > si): 
    WrapClass<vtkAMILabGPUMultiVolumeRayCastMapper>(si)
    , WrapClass_vtkVolumeMapper(si)
    {}

    /// Destructor
    ~WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkAMILabGPUMultiVolumeRayCastMapper*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkAMILabGPUMultiVolumeRayCastMapper * vtkAMILabGPUMultiVolumeRayCastMapper::New() (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkAMILabGPUMultiVolumeRayCastMapper::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkAMILabGPUMultiVolumeRayCastMapper * vtkAMILabGPUMultiVolumeRayCastMapper::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkAMILabGPUMultiVolumeRayCastMapper::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkAMILabGPUMultiVolumeRayCastMapper * vtkAMILabGPUMultiVolumeRayCastMapper::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#newinstance)")
/* The following types are missing: std::ostream
    ADD_CLASS_METHOD(PrintSelf,"void vtkAMILabGPUMultiVolumeRayCastMapper::PrintSelf(std::ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#printself)")
*/
    ADD_CLASS_METHOD(SetAutoAdjustSampleDistances,"void vtkAMILabGPUMultiVolumeRayCastMapper::SetAutoAdjustSampleDistances(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#setautoadjustsampledistances)")
    ADD_CLASS_METHOD(GetAutoAdjustSampleDistancesMinValue,"int vtkAMILabGPUMultiVolumeRayCastMapper::GetAutoAdjustSampleDistancesMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getautoadjustsampledistancesminvalue)")
    ADD_CLASS_METHOD(GetAutoAdjustSampleDistancesMaxValue,"int vtkAMILabGPUMultiVolumeRayCastMapper::GetAutoAdjustSampleDistancesMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getautoadjustsampledistancesmaxvalue)")
    ADD_CLASS_METHOD(GetAutoAdjustSampleDistances,"int vtkAMILabGPUMultiVolumeRayCastMapper::GetAutoAdjustSampleDistances()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getautoadjustsampledistances)")
    ADD_CLASS_METHOD(AutoAdjustSampleDistancesOn,"void vtkAMILabGPUMultiVolumeRayCastMapper::AutoAdjustSampleDistancesOn()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#autoadjustsampledistanceson)")
    ADD_CLASS_METHOD(AutoAdjustSampleDistancesOff,"void vtkAMILabGPUMultiVolumeRayCastMapper::AutoAdjustSampleDistancesOff()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#autoadjustsampledistancesoff)")
    ADD_CLASS_METHOD(SetSampleDistance,"void vtkAMILabGPUMultiVolumeRayCastMapper::SetSampleDistance(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#setsampledistance)")
    ADD_CLASS_METHOD(GetSampleDistance,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetSampleDistance()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getsampledistance)")
    ADD_CLASS_METHOD(SetImageSampleDistance,"void vtkAMILabGPUMultiVolumeRayCastMapper::SetImageSampleDistance(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#setimagesampledistance)")
    ADD_CLASS_METHOD(GetImageSampleDistanceMinValue,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetImageSampleDistanceMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getimagesampledistanceminvalue)")
    ADD_CLASS_METHOD(GetImageSampleDistanceMaxValue,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetImageSampleDistanceMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getimagesampledistancemaxvalue)")
    ADD_CLASS_METHOD(GetImageSampleDistance,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetImageSampleDistance()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getimagesampledistance)")
    ADD_CLASS_METHOD(SetMinimumImageSampleDistance,"void vtkAMILabGPUMultiVolumeRayCastMapper::SetMinimumImageSampleDistance(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#setminimumimagesampledistance)")
    ADD_CLASS_METHOD(GetMinimumImageSampleDistanceMinValue,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetMinimumImageSampleDistanceMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getminimumimagesampledistanceminvalue)")
    ADD_CLASS_METHOD(GetMinimumImageSampleDistanceMaxValue,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetMinimumImageSampleDistanceMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getminimumimagesampledistancemaxvalue)")
    ADD_CLASS_METHOD(GetMinimumImageSampleDistance,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetMinimumImageSampleDistance()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getminimumimagesampledistance)")
    ADD_CLASS_METHOD(SetMaximumImageSampleDistance,"void vtkAMILabGPUMultiVolumeRayCastMapper::SetMaximumImageSampleDistance(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#setmaximumimagesampledistance)")
    ADD_CLASS_METHOD(GetMaximumImageSampleDistanceMinValue,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaximumImageSampleDistanceMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getmaximumimagesampledistanceminvalue)")
    ADD_CLASS_METHOD(GetMaximumImageSampleDistanceMaxValue,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaximumImageSampleDistanceMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getmaximumimagesampledistancemaxvalue)")
    ADD_CLASS_METHOD(GetMaximumImageSampleDistance,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaximumImageSampleDistance()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getmaximumimagesampledistance)")
    ADD_CLASS_METHOD(SetFinalColorWindow,"void vtkAMILabGPUMultiVolumeRayCastMapper::SetFinalColorWindow(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#setfinalcolorwindow)")
    ADD_CLASS_METHOD(GetFinalColorWindow,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetFinalColorWindow()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getfinalcolorwindow)")
    ADD_CLASS_METHOD(SetFinalColorLevel,"void vtkAMILabGPUMultiVolumeRayCastMapper::SetFinalColorLevel(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#setfinalcolorlevel)")
    ADD_CLASS_METHOD(GetFinalColorLevel,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetFinalColorLevel()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getfinalcolorlevel)")
    ADD_CLASS_METHOD(SetMaxMemoryInBytes,"void vtkAMILabGPUMultiVolumeRayCastMapper::SetMaxMemoryInBytes(long long int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#setmaxmemoryinbytes)")
    ADD_CLASS_METHOD(GetMaxMemoryInBytes,"long long int vtkAMILabGPUMultiVolumeRayCastMapper::GetMaxMemoryInBytes()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getmaxmemoryinbytes)")
    ADD_CLASS_METHOD(SetMaxMemoryFraction,"void vtkAMILabGPUMultiVolumeRayCastMapper::SetMaxMemoryFraction(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#setmaxmemoryfraction)")
    ADD_CLASS_METHOD(GetMaxMemoryFractionMinValue,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaxMemoryFractionMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getmaxmemoryfractionminvalue)")
    ADD_CLASS_METHOD(GetMaxMemoryFractionMaxValue,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaxMemoryFractionMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getmaxmemoryfractionmaxvalue)")
    ADD_CLASS_METHOD(GetMaxMemoryFraction,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaxMemoryFraction()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getmaxmemoryfraction)")
    ADD_CLASS_METHOD(SetReportProgress,"void vtkAMILabGPUMultiVolumeRayCastMapper::SetReportProgress(bool _arg)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#setreportprogress)")
    ADD_CLASS_METHOD(GetReportProgress,"bool vtkAMILabGPUMultiVolumeRayCastMapper::GetReportProgress()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getreportprogress)")
    ADD_CLASS_METHOD(IsRenderSupported,"int vtkAMILabGPUMultiVolumeRayCastMapper::IsRenderSupported(vtkRenderWindow * param0, vtkVolumeProperty * param1)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#isrendersupported)")
    ADD_CLASS_METHOD(CreateCanonicalView,"void vtkAMILabGPUMultiVolumeRayCastMapper::CreateCanonicalView(vtkRenderer * ren, vtkVolume * volume, vtkImageData * image, int blend_mode, double * viewDirection, double * viewUp)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#createcanonicalview)")
    ADD_CLASS_METHOD(SetMaskInput,"void vtkAMILabGPUMultiVolumeRayCastMapper::SetMaskInput(vtkImageData * mask)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#setmaskinput)")
    ADD_CLASS_METHOD(GetMaskInput,"vtkImageData * vtkAMILabGPUMultiVolumeRayCastMapper::GetMaskInput()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getmaskinput)")
    ADD_CLASS_METHOD(SetMaskType,"void vtkAMILabGPUMultiVolumeRayCastMapper::SetMaskType(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#setmasktype)")
    ADD_CLASS_METHOD(GetMaskType,"int vtkAMILabGPUMultiVolumeRayCastMapper::GetMaskType()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getmasktype)")
    ADD_CLASS_METHOD(SetMaskTypeToBinary,"void vtkAMILabGPUMultiVolumeRayCastMapper::SetMaskTypeToBinary()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#setmasktypetobinary)")
    ADD_CLASS_METHOD(SetMaskTypeToLabelMap,"void vtkAMILabGPUMultiVolumeRayCastMapper::SetMaskTypeToLabelMap()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#setmasktypetolabelmap)")
    ADD_CLASS_METHOD(SetMaskBlendFactor,"void vtkAMILabGPUMultiVolumeRayCastMapper::SetMaskBlendFactor(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#setmaskblendfactor)")
    ADD_CLASS_METHOD(GetMaskBlendFactorMinValue,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaskBlendFactorMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getmaskblendfactorminvalue)")
    ADD_CLASS_METHOD(GetMaskBlendFactorMaxValue,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaskBlendFactorMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getmaskblendfactormaxvalue)")
    ADD_CLASS_METHOD(GetMaskBlendFactor,"float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaskBlendFactor()  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getmaskblendfactor)")
    ADD_CLASS_METHOD(Render,"void vtkAMILabGPUMultiVolumeRayCastMapper::Render(vtkRenderer * param0, vtkVolume * param1)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#render)")
    ADD_CLASS_METHOD(GPURender,"void vtkAMILabGPUMultiVolumeRayCastMapper::GPURender(vtkRenderer * param0, vtkVolume * param1)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#gpurender)")
    ADD_CLASS_METHOD(ReleaseGraphicsResources,"void vtkAMILabGPUMultiVolumeRayCastMapper::ReleaseGraphicsResources(vtkWindow * param0)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#releasegraphicsresources)")
    ADD_CLASS_METHOD(GetReductionRatio,"void vtkAMILabGPUMultiVolumeRayCastMapper::GetReductionRatio(double * ratio)  (http://docs.wxwidgets.org/stable/wx_vtkamilabgpumultivolumeraycastmapper.html#getreductionratio)")





    void AddMethods(WrapClass<vtkAMILabGPUMultiVolumeRayCastMapper>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkAMILabGPUMultiVolumeRayCastMapper_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkAMILabGPUMultiVolumeRayCastMapper_h
