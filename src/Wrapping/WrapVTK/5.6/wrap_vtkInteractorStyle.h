/**
 * C++ Interface: wrap_vtkInteractorStyle
 *
 * Description: wrapping vtkInteractorStyle
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkInteractorStyle_h_
#define _wrap_vtkInteractorStyle_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkInteractorStyle.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkInteractorObserver.h"


#ifndef vtkInteractorStyle_declared
  #define vtkInteractorStyle_declared
  AMI_DECLARE_TYPE(vtkInteractorStyle);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkInteractorStyle : public WrapClass<vtkInteractorStyle>
    , public   WrapClass_vtkInteractorObserver
{
  DEFINE_CLASS(WrapClass_vtkInteractorStyle);

  protected:
    typedef WrapClass<vtkInteractorStyle>::ptr _parentclass_ptr;
    typedef vtkInteractorStyle ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkInteractorStyle>& GetObj() const { return WrapClass<vtkInteractorStyle>::GetObj(); }

    /// Constructor
    WrapClass_vtkInteractorStyle(boost::shared_ptr<vtkInteractorStyle > si): 
    WrapClass<vtkInteractorStyle>(si)
    , WrapClass_vtkInteractorObserver(si)
    {}

    /// Destructor
    ~WrapClass_vtkInteractorStyle()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkInteractorStyle*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkInteractorStyle * vtkInteractorStyle::New() (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkInteractorStyle::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkInteractorStyle * vtkInteractorStyle::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkInteractorStyle::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkInteractorStyle * vtkInteractorStyle::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkInteractorStyle::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#printself)")
*/
    ADD_CLASS_METHOD(SetInteractor,"void vtkInteractorStyle::SetInteractor(vtkRenderWindowInteractor * interactor)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#setinteractor)")
    ADD_CLASS_METHOD(SetEnabled,"void vtkInteractorStyle::SetEnabled(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#setenabled)")
    ADD_CLASS_METHOD(SetAutoAdjustCameraClippingRange,"void vtkInteractorStyle::SetAutoAdjustCameraClippingRange(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#setautoadjustcameraclippingrange)")
    ADD_CLASS_METHOD(GetAutoAdjustCameraClippingRangeMinValue,"int vtkInteractorStyle::GetAutoAdjustCameraClippingRangeMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#getautoadjustcameraclippingrangeminvalue)")
    ADD_CLASS_METHOD(GetAutoAdjustCameraClippingRangeMaxValue,"int vtkInteractorStyle::GetAutoAdjustCameraClippingRangeMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#getautoadjustcameraclippingrangemaxvalue)")
    ADD_CLASS_METHOD(GetAutoAdjustCameraClippingRange,"int vtkInteractorStyle::GetAutoAdjustCameraClippingRange()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#getautoadjustcameraclippingrange)")
    ADD_CLASS_METHOD(AutoAdjustCameraClippingRangeOn,"void vtkInteractorStyle::AutoAdjustCameraClippingRangeOn()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#autoadjustcameraclippingrangeon)")
    ADD_CLASS_METHOD(AutoAdjustCameraClippingRangeOff,"void vtkInteractorStyle::AutoAdjustCameraClippingRangeOff()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#autoadjustcameraclippingrangeoff)")
    ADD_CLASS_METHOD(FindPokedRenderer,"void vtkInteractorStyle::FindPokedRenderer(int param0, int param1)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#findpokedrenderer)")
    ADD_CLASS_METHOD(GetState,"int vtkInteractorStyle::GetState()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#getstate)")
    ADD_CLASS_METHOD(GetUseTimers,"int vtkInteractorStyle::GetUseTimers()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#getusetimers)")
    ADD_CLASS_METHOD(SetUseTimers,"void vtkInteractorStyle::SetUseTimers(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#setusetimers)")
    ADD_CLASS_METHOD(UseTimersOn,"void vtkInteractorStyle::UseTimersOn()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#usetimerson)")
    ADD_CLASS_METHOD(UseTimersOff,"void vtkInteractorStyle::UseTimersOff()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#usetimersoff)")
    ADD_CLASS_METHOD(SetTimerDuration,"void vtkInteractorStyle::SetTimerDuration(long unsigned int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#settimerduration)")
    ADD_CLASS_METHOD(GetTimerDurationMinValue,"long unsigned int vtkInteractorStyle::GetTimerDurationMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#gettimerdurationminvalue)")
    ADD_CLASS_METHOD(GetTimerDurationMaxValue,"long unsigned int vtkInteractorStyle::GetTimerDurationMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#gettimerdurationmaxvalue)")
    ADD_CLASS_METHOD(GetTimerDuration,"long unsigned int vtkInteractorStyle::GetTimerDuration()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#gettimerduration)")
    ADD_CLASS_METHOD(SetHandleObservers,"void vtkInteractorStyle::SetHandleObservers(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#sethandleobservers)")
    ADD_CLASS_METHOD(GetHandleObservers,"int vtkInteractorStyle::GetHandleObservers()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#gethandleobservers)")
    ADD_CLASS_METHOD(HandleObserversOn,"void vtkInteractorStyle::HandleObserversOn()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#handleobserverson)")
    ADD_CLASS_METHOD(HandleObserversOff,"void vtkInteractorStyle::HandleObserversOff()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#handleobserversoff)")
    ADD_CLASS_METHOD(OnMouseMove,"void vtkInteractorStyle::OnMouseMove()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onmousemove)")
    ADD_CLASS_METHOD(OnLeftButtonDown,"void vtkInteractorStyle::OnLeftButtonDown()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onleftbuttondown)")
    ADD_CLASS_METHOD(OnLeftButtonUp,"void vtkInteractorStyle::OnLeftButtonUp()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onleftbuttonup)")
    ADD_CLASS_METHOD(OnMiddleButtonDown,"void vtkInteractorStyle::OnMiddleButtonDown()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onmiddlebuttondown)")
    ADD_CLASS_METHOD(OnMiddleButtonUp,"void vtkInteractorStyle::OnMiddleButtonUp()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onmiddlebuttonup)")
    ADD_CLASS_METHOD(OnRightButtonDown,"void vtkInteractorStyle::OnRightButtonDown()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onrightbuttondown)")
    ADD_CLASS_METHOD(OnRightButtonUp,"void vtkInteractorStyle::OnRightButtonUp()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onrightbuttonup)")
    ADD_CLASS_METHOD(OnMouseWheelForward,"void vtkInteractorStyle::OnMouseWheelForward()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onmousewheelforward)")
    ADD_CLASS_METHOD(OnMouseWheelBackward,"void vtkInteractorStyle::OnMouseWheelBackward()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onmousewheelbackward)")
    ADD_CLASS_METHOD(OnChar,"void vtkInteractorStyle::OnChar()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onchar)")
    ADD_CLASS_METHOD(OnKeyDown,"void vtkInteractorStyle::OnKeyDown()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onkeydown)")
    ADD_CLASS_METHOD(OnKeyUp,"void vtkInteractorStyle::OnKeyUp()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onkeyup)")
    ADD_CLASS_METHOD(OnKeyPress,"void vtkInteractorStyle::OnKeyPress()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onkeypress)")
    ADD_CLASS_METHOD(OnKeyRelease,"void vtkInteractorStyle::OnKeyRelease()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onkeyrelease)")
    ADD_CLASS_METHOD(OnExpose,"void vtkInteractorStyle::OnExpose()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onexpose)")
    ADD_CLASS_METHOD(OnConfigure,"void vtkInteractorStyle::OnConfigure()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onconfigure)")
    ADD_CLASS_METHOD(OnEnter,"void vtkInteractorStyle::OnEnter()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onenter)")
    ADD_CLASS_METHOD(OnLeave,"void vtkInteractorStyle::OnLeave()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#onleave)")
    ADD_CLASS_METHOD(OnTimer,"void vtkInteractorStyle::OnTimer()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#ontimer)")
    ADD_CLASS_METHOD(Rotate,"void vtkInteractorStyle::Rotate()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#rotate)")
    ADD_CLASS_METHOD(Spin,"void vtkInteractorStyle::Spin()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#spin)")
    ADD_CLASS_METHOD(Pan,"void vtkInteractorStyle::Pan()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#pan)")
    ADD_CLASS_METHOD(Dolly,"void vtkInteractorStyle::Dolly()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#dolly)")
    ADD_CLASS_METHOD(Zoom,"void vtkInteractorStyle::Zoom()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#zoom)")
    ADD_CLASS_METHOD(UniformScale,"void vtkInteractorStyle::UniformScale()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#uniformscale)")
    ADD_CLASS_METHOD(StartState,"void vtkInteractorStyle::StartState(int newstate)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#startstate)")
    ADD_CLASS_METHOD(StopState,"void vtkInteractorStyle::StopState()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#stopstate)")
    ADD_CLASS_METHOD(StartAnimate,"void vtkInteractorStyle::StartAnimate()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#startanimate)")
    ADD_CLASS_METHOD(StopAnimate,"void vtkInteractorStyle::StopAnimate()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#stopanimate)")
    ADD_CLASS_METHOD(StartRotate,"void vtkInteractorStyle::StartRotate()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#startrotate)")
    ADD_CLASS_METHOD(EndRotate,"void vtkInteractorStyle::EndRotate()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#endrotate)")
    ADD_CLASS_METHOD(StartZoom,"void vtkInteractorStyle::StartZoom()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#startzoom)")
    ADD_CLASS_METHOD(EndZoom,"void vtkInteractorStyle::EndZoom()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#endzoom)")
    ADD_CLASS_METHOD(StartPan,"void vtkInteractorStyle::StartPan()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#startpan)")
    ADD_CLASS_METHOD(EndPan,"void vtkInteractorStyle::EndPan()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#endpan)")
    ADD_CLASS_METHOD(StartSpin,"void vtkInteractorStyle::StartSpin()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#startspin)")
    ADD_CLASS_METHOD(EndSpin,"void vtkInteractorStyle::EndSpin()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#endspin)")
    ADD_CLASS_METHOD(StartDolly,"void vtkInteractorStyle::StartDolly()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#startdolly)")
    ADD_CLASS_METHOD(EndDolly,"void vtkInteractorStyle::EndDolly()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#enddolly)")
    ADD_CLASS_METHOD(StartUniformScale,"void vtkInteractorStyle::StartUniformScale()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#startuniformscale)")
    ADD_CLASS_METHOD(EndUniformScale,"void vtkInteractorStyle::EndUniformScale()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#enduniformscale)")
    ADD_CLASS_METHOD(StartTimer,"void vtkInteractorStyle::StartTimer()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#starttimer)")
    ADD_CLASS_METHOD(EndTimer,"void vtkInteractorStyle::EndTimer()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#endtimer)")
    ADD_CLASS_METHOD(HighlightProp,"void vtkInteractorStyle::HighlightProp(vtkProp * prop)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#highlightprop)")
/* The following types are missing: vtkActor2D
    ADD_CLASS_METHOD(HighlightActor2D,"void vtkInteractorStyle::HighlightActor2D(vtkActor2D * actor2D)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#highlightactor2d)")
*/
    ADD_CLASS_METHOD(HighlightProp3D,"void vtkInteractorStyle::HighlightProp3D(vtkProp3D * prop3D)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#highlightprop3d)")
    ADD_CLASS_METHOD(SetPickColor_1,"void vtkInteractorStyle::SetPickColor(double _arg1, double _arg2, double _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#setpickcolor)")
    ADD_CLASS_METHOD(SetPickColor,"vtkInteractorStyle::SetPickColor()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#setpickcolor)")
    ADD_CLASS_METHOD(SetPickColor_2,"void vtkInteractorStyle::SetPickColor(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#setpickcolor)")
    ADD_CLASS_METHOD(GetPickColor_1,"double * vtkInteractorStyle::GetPickColor()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#getpickcolor)")
    ADD_CLASS_METHOD(GetPickColor,"vtkInteractorStyle::GetPickColor()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#getpickcolor)")
    ADD_CLASS_METHOD(GetPickColor_2,"void vtkInteractorStyle::GetPickColor(double * data)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#getpickcolor)")
    ADD_CLASS_METHOD(SetMouseWheelMotionFactor,"void vtkInteractorStyle::SetMouseWheelMotionFactor(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#setmousewheelmotionfactor)")
    ADD_CLASS_METHOD(GetMouseWheelMotionFactor,"double vtkInteractorStyle::GetMouseWheelMotionFactor()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#getmousewheelmotionfactor)")
/* The following types are missing: vtkTDxInteractorStyle
    ADD_CLASS_METHOD(GetTDxStyle,"vtkTDxInteractorStyle * vtkInteractorStyle::GetTDxStyle()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#gettdxstyle)")
*/
/* The following types are missing: vtkTDxInteractorStyle
    ADD_CLASS_METHOD(SetTDxStyle,"void vtkInteractorStyle::SetTDxStyle(vtkTDxInteractorStyle * tdxStyle)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#settdxstyle)")
*/
/* The following types are missing: void
    ADD_CLASS_METHOD(DelegateTDxEvent,"void vtkInteractorStyle::DelegateTDxEvent(long unsigned int event, void * calldata)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyle.html#delegatetdxevent)")
*/





    void AddMethods(WrapClass<vtkInteractorStyle>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkInteractorStyle_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkInteractorStyle_h
