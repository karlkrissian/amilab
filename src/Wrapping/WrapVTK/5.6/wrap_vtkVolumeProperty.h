/**
 * C++ Interface: wrap_vtkVolumeProperty
 *
 * Description: wrapping vtkVolumeProperty
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkVolumeProperty_h_
#define _wrap_vtkVolumeProperty_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"


AMI_DECLARE_TYPE(vtkVolumeProperty);

// TODO: check for inheritence ...
class WrapClass_vtkVolumeProperty : public WrapClass<vtkVolumeProperty>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkVolumeProperty);

  protected:
    typedef WrapClass<vtkVolumeProperty>::ptr _parentclass_ptr;
    typedef vtkVolumeProperty ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkVolumeProperty>& GetObj() const { return WrapClass<vtkVolumeProperty>::GetObj(); }

    /// Constructor
    WrapClass_vtkVolumeProperty(boost::shared_ptr<vtkVolumeProperty > si): 
    WrapClass<vtkVolumeProperty>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkVolumeProperty()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkVolumeProperty*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkVolumeProperty * vtkVolumeProperty::New() (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkVolumeProperty::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkVolumeProperty * vtkVolumeProperty::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkVolumeProperty::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkVolumeProperty * vtkVolumeProperty::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkVolumeProperty::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#printself)")
*/
    ADD_CLASS_METHOD(DeepCopy,"void vtkVolumeProperty::DeepCopy(vtkVolumeProperty * p)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#deepcopy)")
    ADD_CLASS_METHOD(GetMTime,"long unsigned int vtkVolumeProperty::GetMTime()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getmtime)")
    ADD_CLASS_METHOD(SetIndependentComponents,"void vtkVolumeProperty::SetIndependentComponents(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setindependentcomponents)")
    ADD_CLASS_METHOD(GetIndependentComponentsMinValue,"int vtkVolumeProperty::GetIndependentComponentsMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getindependentcomponentsminvalue)")
    ADD_CLASS_METHOD(GetIndependentComponentsMaxValue,"int vtkVolumeProperty::GetIndependentComponentsMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getindependentcomponentsmaxvalue)")
    ADD_CLASS_METHOD(GetIndependentComponents,"int vtkVolumeProperty::GetIndependentComponents()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getindependentcomponents)")
    ADD_CLASS_METHOD(IndependentComponentsOn,"void vtkVolumeProperty::IndependentComponentsOn()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#independentcomponentson)")
    ADD_CLASS_METHOD(IndependentComponentsOff,"void vtkVolumeProperty::IndependentComponentsOff()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#independentcomponentsoff)")
    ADD_CLASS_METHOD(SetInterpolationType,"void vtkVolumeProperty::SetInterpolationType(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setinterpolationtype)")
    ADD_CLASS_METHOD(GetInterpolationTypeMinValue,"int vtkVolumeProperty::GetInterpolationTypeMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getinterpolationtypeminvalue)")
    ADD_CLASS_METHOD(GetInterpolationTypeMaxValue,"int vtkVolumeProperty::GetInterpolationTypeMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getinterpolationtypemaxvalue)")
    ADD_CLASS_METHOD(GetInterpolationType,"int vtkVolumeProperty::GetInterpolationType()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getinterpolationtype)")
    ADD_CLASS_METHOD(SetInterpolationTypeToNearest,"void vtkVolumeProperty::SetInterpolationTypeToNearest()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setinterpolationtypetonearest)")
    ADD_CLASS_METHOD(SetInterpolationTypeToLinear,"void vtkVolumeProperty::SetInterpolationTypeToLinear()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setinterpolationtypetolinear)")
    ADD_CLASS_METHOD(GetInterpolationTypeAsString,"char const * vtkVolumeProperty::GetInterpolationTypeAsString()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getinterpolationtypeasstring)")
    ADD_CLASS_METHOD(SetComponentWeight,"void vtkVolumeProperty::SetComponentWeight(int index, double value)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setcomponentweight)")
    ADD_CLASS_METHOD(GetComponentWeight,"double vtkVolumeProperty::GetComponentWeight(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getcomponentweight)")
    ADD_CLASS_METHOD(SetColor_1,"void vtkVolumeProperty::SetColor(int index, vtkPiecewiseFunction * function)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setcolor)")
    ADD_CLASS_METHOD(SetColor,"vtkVolumeProperty::SetColor()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setcolor)")
    ADD_CLASS_METHOD(SetColor_2,"void vtkVolumeProperty::SetColor(vtkPiecewiseFunction * f)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setcolor)")
    ADD_CLASS_METHOD(SetColor_3,"void vtkVolumeProperty::SetColor(int index, vtkColorTransferFunction * function)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setcolor)")
    ADD_CLASS_METHOD(SetColor_4,"void vtkVolumeProperty::SetColor(vtkColorTransferFunction * f)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setcolor)")
    ADD_CLASS_METHOD(GetColorChannels_1,"int vtkVolumeProperty::GetColorChannels(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getcolorchannels)")
    ADD_CLASS_METHOD(GetColorChannels,"vtkVolumeProperty::GetColorChannels()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getcolorchannels)")
    ADD_CLASS_METHOD(GetColorChannels_2,"int vtkVolumeProperty::GetColorChannels()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getcolorchannels)")
    ADD_CLASS_METHOD(GetGrayTransferFunction_1,"vtkPiecewiseFunction * vtkVolumeProperty::GetGrayTransferFunction(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getgraytransferfunction)")
    ADD_CLASS_METHOD(GetGrayTransferFunction,"vtkVolumeProperty::GetGrayTransferFunction()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getgraytransferfunction)")
    ADD_CLASS_METHOD(GetGrayTransferFunction_2,"vtkPiecewiseFunction * vtkVolumeProperty::GetGrayTransferFunction()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getgraytransferfunction)")
    ADD_CLASS_METHOD(GetRGBTransferFunction_1,"vtkColorTransferFunction * vtkVolumeProperty::GetRGBTransferFunction(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getrgbtransferfunction)")
    ADD_CLASS_METHOD(GetRGBTransferFunction,"vtkVolumeProperty::GetRGBTransferFunction()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getrgbtransferfunction)")
    ADD_CLASS_METHOD(GetRGBTransferFunction_2,"vtkColorTransferFunction * vtkVolumeProperty::GetRGBTransferFunction()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getrgbtransferfunction)")
    ADD_CLASS_METHOD(SetScalarOpacity_1,"void vtkVolumeProperty::SetScalarOpacity(int index, vtkPiecewiseFunction * function)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setscalaropacity)")
    ADD_CLASS_METHOD(SetScalarOpacity,"vtkVolumeProperty::SetScalarOpacity()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setscalaropacity)")
    ADD_CLASS_METHOD(SetScalarOpacity_2,"void vtkVolumeProperty::SetScalarOpacity(vtkPiecewiseFunction * f)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setscalaropacity)")
    ADD_CLASS_METHOD(GetScalarOpacity_1,"vtkPiecewiseFunction * vtkVolumeProperty::GetScalarOpacity(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getscalaropacity)")
    ADD_CLASS_METHOD(GetScalarOpacity,"vtkVolumeProperty::GetScalarOpacity()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getscalaropacity)")
    ADD_CLASS_METHOD(GetScalarOpacity_2,"vtkPiecewiseFunction * vtkVolumeProperty::GetScalarOpacity()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getscalaropacity)")
    ADD_CLASS_METHOD(SetScalarOpacityUnitDistance_1,"void vtkVolumeProperty::SetScalarOpacityUnitDistance(int index, double distance)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setscalaropacityunitdistance)")
    ADD_CLASS_METHOD(SetScalarOpacityUnitDistance,"vtkVolumeProperty::SetScalarOpacityUnitDistance()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setscalaropacityunitdistance)")
    ADD_CLASS_METHOD(SetScalarOpacityUnitDistance_2,"void vtkVolumeProperty::SetScalarOpacityUnitDistance(double distance)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setscalaropacityunitdistance)")
    ADD_CLASS_METHOD(GetScalarOpacityUnitDistance_1,"double vtkVolumeProperty::GetScalarOpacityUnitDistance(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getscalaropacityunitdistance)")
    ADD_CLASS_METHOD(GetScalarOpacityUnitDistance,"vtkVolumeProperty::GetScalarOpacityUnitDistance()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getscalaropacityunitdistance)")
    ADD_CLASS_METHOD(GetScalarOpacityUnitDistance_2,"double vtkVolumeProperty::GetScalarOpacityUnitDistance()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getscalaropacityunitdistance)")
    ADD_CLASS_METHOD(SetGradientOpacity_1,"void vtkVolumeProperty::SetGradientOpacity(int index, vtkPiecewiseFunction * function)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setgradientopacity)")
    ADD_CLASS_METHOD(SetGradientOpacity,"vtkVolumeProperty::SetGradientOpacity()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setgradientopacity)")
    ADD_CLASS_METHOD(SetGradientOpacity_2,"void vtkVolumeProperty::SetGradientOpacity(vtkPiecewiseFunction * function)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setgradientopacity)")
    ADD_CLASS_METHOD(GetGradientOpacity_1,"vtkPiecewiseFunction * vtkVolumeProperty::GetGradientOpacity(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getgradientopacity)")
    ADD_CLASS_METHOD(GetGradientOpacity,"vtkVolumeProperty::GetGradientOpacity()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getgradientopacity)")
    ADD_CLASS_METHOD(GetGradientOpacity_2,"vtkPiecewiseFunction * vtkVolumeProperty::GetGradientOpacity()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getgradientopacity)")
    ADD_CLASS_METHOD(SetDisableGradientOpacity_1,"void vtkVolumeProperty::SetDisableGradientOpacity(int index, int value)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setdisablegradientopacity)")
    ADD_CLASS_METHOD(SetDisableGradientOpacity,"vtkVolumeProperty::SetDisableGradientOpacity()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setdisablegradientopacity)")
    ADD_CLASS_METHOD(SetDisableGradientOpacity_2,"void vtkVolumeProperty::SetDisableGradientOpacity(int value)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setdisablegradientopacity)")
    ADD_CLASS_METHOD(DisableGradientOpacityOn_1,"void vtkVolumeProperty::DisableGradientOpacityOn(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#disablegradientopacityon)")
    ADD_CLASS_METHOD(DisableGradientOpacityOn,"vtkVolumeProperty::DisableGradientOpacityOn()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#disablegradientopacityon)")
    ADD_CLASS_METHOD(DisableGradientOpacityOn_2,"void vtkVolumeProperty::DisableGradientOpacityOn()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#disablegradientopacityon)")
    ADD_CLASS_METHOD(DisableGradientOpacityOff_1,"void vtkVolumeProperty::DisableGradientOpacityOff(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#disablegradientopacityoff)")
    ADD_CLASS_METHOD(DisableGradientOpacityOff,"vtkVolumeProperty::DisableGradientOpacityOff()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#disablegradientopacityoff)")
    ADD_CLASS_METHOD(DisableGradientOpacityOff_2,"void vtkVolumeProperty::DisableGradientOpacityOff()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#disablegradientopacityoff)")
    ADD_CLASS_METHOD(GetDisableGradientOpacity_1,"int vtkVolumeProperty::GetDisableGradientOpacity(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getdisablegradientopacity)")
    ADD_CLASS_METHOD(GetDisableGradientOpacity,"vtkVolumeProperty::GetDisableGradientOpacity()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getdisablegradientopacity)")
    ADD_CLASS_METHOD(GetDisableGradientOpacity_2,"int vtkVolumeProperty::GetDisableGradientOpacity()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getdisablegradientopacity)")
    ADD_CLASS_METHOD(GetStoredGradientOpacity_1,"vtkPiecewiseFunction * vtkVolumeProperty::GetStoredGradientOpacity(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getstoredgradientopacity)")
    ADD_CLASS_METHOD(GetStoredGradientOpacity,"vtkVolumeProperty::GetStoredGradientOpacity()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getstoredgradientopacity)")
    ADD_CLASS_METHOD(GetStoredGradientOpacity_2,"vtkPiecewiseFunction * vtkVolumeProperty::GetStoredGradientOpacity()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getstoredgradientopacity)")
    ADD_CLASS_METHOD(SetShade_1,"void vtkVolumeProperty::SetShade(int index, int value)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setshade)")
    ADD_CLASS_METHOD(SetShade,"vtkVolumeProperty::SetShade()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setshade)")
    ADD_CLASS_METHOD(SetShade_2,"void vtkVolumeProperty::SetShade(int value)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setshade)")
    ADD_CLASS_METHOD(GetShade_1,"int vtkVolumeProperty::GetShade(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getshade)")
    ADD_CLASS_METHOD(GetShade,"vtkVolumeProperty::GetShade()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getshade)")
    ADD_CLASS_METHOD(GetShade_2,"int vtkVolumeProperty::GetShade()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getshade)")
    ADD_CLASS_METHOD(ShadeOn_1,"void vtkVolumeProperty::ShadeOn(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#shadeon)")
    ADD_CLASS_METHOD(ShadeOn,"vtkVolumeProperty::ShadeOn()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#shadeon)")
    ADD_CLASS_METHOD(ShadeOn_2,"void vtkVolumeProperty::ShadeOn()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#shadeon)")
    ADD_CLASS_METHOD(ShadeOff_1,"void vtkVolumeProperty::ShadeOff(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#shadeoff)")
    ADD_CLASS_METHOD(ShadeOff,"vtkVolumeProperty::ShadeOff()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#shadeoff)")
    ADD_CLASS_METHOD(ShadeOff_2,"void vtkVolumeProperty::ShadeOff()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#shadeoff)")
    ADD_CLASS_METHOD(SetAmbient_1,"void vtkVolumeProperty::SetAmbient(int index, double value)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setambient)")
    ADD_CLASS_METHOD(SetAmbient,"vtkVolumeProperty::SetAmbient()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setambient)")
    ADD_CLASS_METHOD(SetAmbient_2,"void vtkVolumeProperty::SetAmbient(double value)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setambient)")
    ADD_CLASS_METHOD(GetAmbient_1,"double vtkVolumeProperty::GetAmbient(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getambient)")
    ADD_CLASS_METHOD(GetAmbient,"vtkVolumeProperty::GetAmbient()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getambient)")
    ADD_CLASS_METHOD(GetAmbient_2,"double vtkVolumeProperty::GetAmbient()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getambient)")
    ADD_CLASS_METHOD(SetDiffuse_1,"void vtkVolumeProperty::SetDiffuse(int index, double value)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setdiffuse)")
    ADD_CLASS_METHOD(SetDiffuse,"vtkVolumeProperty::SetDiffuse()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setdiffuse)")
    ADD_CLASS_METHOD(SetDiffuse_2,"void vtkVolumeProperty::SetDiffuse(double value)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setdiffuse)")
    ADD_CLASS_METHOD(GetDiffuse_1,"double vtkVolumeProperty::GetDiffuse(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getdiffuse)")
    ADD_CLASS_METHOD(GetDiffuse,"vtkVolumeProperty::GetDiffuse()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getdiffuse)")
    ADD_CLASS_METHOD(GetDiffuse_2,"double vtkVolumeProperty::GetDiffuse()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getdiffuse)")
    ADD_CLASS_METHOD(SetSpecular_1,"void vtkVolumeProperty::SetSpecular(int index, double value)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setspecular)")
    ADD_CLASS_METHOD(SetSpecular,"vtkVolumeProperty::SetSpecular()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setspecular)")
    ADD_CLASS_METHOD(SetSpecular_2,"void vtkVolumeProperty::SetSpecular(double value)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setspecular)")
    ADD_CLASS_METHOD(GetSpecular_1,"double vtkVolumeProperty::GetSpecular(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getspecular)")
    ADD_CLASS_METHOD(GetSpecular,"vtkVolumeProperty::GetSpecular()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getspecular)")
    ADD_CLASS_METHOD(GetSpecular_2,"double vtkVolumeProperty::GetSpecular()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getspecular)")
    ADD_CLASS_METHOD(SetSpecularPower_1,"void vtkVolumeProperty::SetSpecularPower(int index, double value)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setspecularpower)")
    ADD_CLASS_METHOD(SetSpecularPower,"vtkVolumeProperty::SetSpecularPower()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setspecularpower)")
    ADD_CLASS_METHOD(SetSpecularPower_2,"void vtkVolumeProperty::SetSpecularPower(double value)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#setspecularpower)")
    ADD_CLASS_METHOD(GetSpecularPower_1,"double vtkVolumeProperty::GetSpecularPower(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getspecularpower)")
    ADD_CLASS_METHOD(GetSpecularPower,"vtkVolumeProperty::GetSpecularPower()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getspecularpower)")
    ADD_CLASS_METHOD(GetSpecularPower_2,"double vtkVolumeProperty::GetSpecularPower()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getspecularpower)")
    ADD_CLASS_METHOD(UpdateMTimes,"void vtkVolumeProperty::UpdateMTimes()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#updatemtimes)")
    ADD_CLASS_METHOD(GetGradientOpacityMTime_1,"vtkTimeStamp vtkVolumeProperty::GetGradientOpacityMTime(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getgradientopacitymtime)")
    ADD_CLASS_METHOD(GetGradientOpacityMTime,"vtkVolumeProperty::GetGradientOpacityMTime()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getgradientopacitymtime)")
    ADD_CLASS_METHOD(GetGradientOpacityMTime_2,"vtkTimeStamp vtkVolumeProperty::GetGradientOpacityMTime()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getgradientopacitymtime)")
    ADD_CLASS_METHOD(GetScalarOpacityMTime_1,"vtkTimeStamp vtkVolumeProperty::GetScalarOpacityMTime(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getscalaropacitymtime)")
    ADD_CLASS_METHOD(GetScalarOpacityMTime,"vtkVolumeProperty::GetScalarOpacityMTime()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getscalaropacitymtime)")
    ADD_CLASS_METHOD(GetScalarOpacityMTime_2,"vtkTimeStamp vtkVolumeProperty::GetScalarOpacityMTime()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getscalaropacitymtime)")
    ADD_CLASS_METHOD(GetRGBTransferFunctionMTime_1,"vtkTimeStamp vtkVolumeProperty::GetRGBTransferFunctionMTime(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getrgbtransferfunctionmtime)")
    ADD_CLASS_METHOD(GetRGBTransferFunctionMTime,"vtkVolumeProperty::GetRGBTransferFunctionMTime()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getrgbtransferfunctionmtime)")
    ADD_CLASS_METHOD(GetRGBTransferFunctionMTime_2,"vtkTimeStamp vtkVolumeProperty::GetRGBTransferFunctionMTime()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getrgbtransferfunctionmtime)")
    ADD_CLASS_METHOD(GetGrayTransferFunctionMTime_1,"vtkTimeStamp vtkVolumeProperty::GetGrayTransferFunctionMTime(int index)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getgraytransferfunctionmtime)")
    ADD_CLASS_METHOD(GetGrayTransferFunctionMTime,"vtkVolumeProperty::GetGrayTransferFunctionMTime()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getgraytransferfunctionmtime)")
    ADD_CLASS_METHOD(GetGrayTransferFunctionMTime_2,"vtkTimeStamp vtkVolumeProperty::GetGrayTransferFunctionMTime()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeproperty.html#getgraytransferfunctionmtime)")





    void AddMethods(WrapClass<vtkVolumeProperty>::ptr this_ptr );

};


#endif // _wrap_vtkVolumeProperty_h
