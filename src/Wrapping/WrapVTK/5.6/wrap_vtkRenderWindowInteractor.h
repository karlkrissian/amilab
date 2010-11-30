/**
 * C++ Interface: wrap_vtkRenderWindowInteractor
 *
 * Description: wrapping vtkRenderWindowInteractor
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkRenderWindowInteractor_h_
#define _wrap_vtkRenderWindowInteractor_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"



AMI_DECLARE_TYPE(vtkRenderWindowInteractor);

// TODO: check for inheritence ...
class WrapClass_vtkRenderWindowInteractor : public WrapClass<vtkRenderWindowInteractor>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkRenderWindowInteractor);

  protected:
    typedef WrapClass<vtkRenderWindowInteractor>::ptr _parentclass_ptr;
    typedef vtkRenderWindowInteractor ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkRenderWindowInteractor>& GetObj() const { return WrapClass<vtkRenderWindowInteractor>::GetObj(); }

    /// Constructor
    WrapClass_vtkRenderWindowInteractor(boost::shared_ptr<vtkRenderWindowInteractor > si): 
    WrapClass<vtkRenderWindowInteractor>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkRenderWindowInteractor()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkRenderWindowInteractor*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkRenderWindowInteractor * vtkRenderWindowInteractor::New() (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkRenderWindowInteractor::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkRenderWindowInteractor * vtkRenderWindowInteractor::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkRenderWindowInteractor::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkRenderWindowInteractor * vtkRenderWindowInteractor::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkRenderWindowInteractor::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#printself)")
*/
    ADD_CLASS_METHOD(Initialize,"void vtkRenderWindowInteractor::Initialize()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#initialize)")
    ADD_CLASS_METHOD(ReInitialize,"void vtkRenderWindowInteractor::ReInitialize()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#reinitialize)")
    ADD_CLASS_METHOD(UnRegister,"void vtkRenderWindowInteractor::UnRegister(vtkObjectBase * o)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#unregister)")
    ADD_CLASS_METHOD(Start,"void vtkRenderWindowInteractor::Start()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#start)")
    ADD_CLASS_METHOD(Enable,"void vtkRenderWindowInteractor::Enable()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#enable)")
    ADD_CLASS_METHOD(Disable,"void vtkRenderWindowInteractor::Disable()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#disable)")
    ADD_CLASS_METHOD(GetEnabled,"int vtkRenderWindowInteractor::GetEnabled()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getenabled)")
    ADD_CLASS_METHOD(EnableRenderOn,"void vtkRenderWindowInteractor::EnableRenderOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#enablerenderon)")
    ADD_CLASS_METHOD(EnableRenderOff,"void vtkRenderWindowInteractor::EnableRenderOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#enablerenderoff)")
    ADD_CLASS_METHOD(SetEnableRender,"void vtkRenderWindowInteractor::SetEnableRender(bool _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setenablerender)")
    ADD_CLASS_METHOD(GetEnableRender,"bool vtkRenderWindowInteractor::GetEnableRender()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getenablerender)")
    ADD_CLASS_METHOD(SetRenderWindow,"void vtkRenderWindowInteractor::SetRenderWindow(vtkRenderWindow * aren)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setrenderwindow)")
    ADD_CLASS_METHOD(GetRenderWindow,"vtkRenderWindow * vtkRenderWindowInteractor::GetRenderWindow()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getrenderwindow)")
    ADD_CLASS_METHOD(UpdateSize,"void vtkRenderWindowInteractor::UpdateSize(int x, int y)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#updatesize)")
    ADD_CLASS_METHOD(CreateTimer,"int vtkRenderWindowInteractor::CreateTimer(int timerType)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#createtimer)")
    ADD_CLASS_METHOD(DestroyTimer_1,"int vtkRenderWindowInteractor::DestroyTimer()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#destroytimer)")
    ADD_CLASS_METHOD(CreateRepeatingTimer,"int vtkRenderWindowInteractor::CreateRepeatingTimer(long unsigned int duration)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#createrepeatingtimer)")
    ADD_CLASS_METHOD(CreateOneShotTimer,"int vtkRenderWindowInteractor::CreateOneShotTimer(long unsigned int duration)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#createoneshottimer)")
    ADD_CLASS_METHOD(IsOneShotTimer,"int vtkRenderWindowInteractor::IsOneShotTimer(int timerId)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#isoneshottimer)")
    ADD_CLASS_METHOD(GetTimerDuration_1,"long unsigned int vtkRenderWindowInteractor::GetTimerDuration(int timerId)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#gettimerduration)")
    ADD_CLASS_METHOD(ResetTimer,"int vtkRenderWindowInteractor::ResetTimer(int timerId)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#resettimer)")
    ADD_CLASS_METHOD(DestroyTimer,"vtkRenderWindowInteractor::DestroyTimer()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#destroytimer)")
    ADD_CLASS_METHOD(DestroyTimer_2,"int vtkRenderWindowInteractor::DestroyTimer(int timerId)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#destroytimer)")
    ADD_CLASS_METHOD(GetVTKTimerId,"int vtkRenderWindowInteractor::GetVTKTimerId(int platformTimerId)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getvtktimerid)")
    ADD_CLASS_METHOD(SetTimerDuration,"void vtkRenderWindowInteractor::SetTimerDuration(long unsigned int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#settimerduration)")
    ADD_CLASS_METHOD(GetTimerDurationMinValue,"long unsigned int vtkRenderWindowInteractor::GetTimerDurationMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#gettimerdurationminvalue)")
    ADD_CLASS_METHOD(GetTimerDurationMaxValue,"long unsigned int vtkRenderWindowInteractor::GetTimerDurationMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#gettimerdurationmaxvalue)")
    ADD_CLASS_METHOD(GetTimerDuration,"vtkRenderWindowInteractor::GetTimerDuration()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#gettimerduration)")
    ADD_CLASS_METHOD(GetTimerDuration_2,"long unsigned int vtkRenderWindowInteractor::GetTimerDuration()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#gettimerduration)")
    ADD_CLASS_METHOD(SetTimerEventId,"void vtkRenderWindowInteractor::SetTimerEventId(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#settimereventid)")
    ADD_CLASS_METHOD(GetTimerEventId,"int vtkRenderWindowInteractor::GetTimerEventId()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#gettimereventid)")
    ADD_CLASS_METHOD(SetTimerEventType,"void vtkRenderWindowInteractor::SetTimerEventType(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#settimereventtype)")
    ADD_CLASS_METHOD(GetTimerEventType,"int vtkRenderWindowInteractor::GetTimerEventType()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#gettimereventtype)")
    ADD_CLASS_METHOD(SetTimerEventDuration,"void vtkRenderWindowInteractor::SetTimerEventDuration(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#settimereventduration)")
    ADD_CLASS_METHOD(GetTimerEventDuration,"int vtkRenderWindowInteractor::GetTimerEventDuration()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#gettimereventduration)")
    ADD_CLASS_METHOD(SetTimerEventPlatformId,"void vtkRenderWindowInteractor::SetTimerEventPlatformId(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#settimereventplatformid)")
    ADD_CLASS_METHOD(GetTimerEventPlatformId,"int vtkRenderWindowInteractor::GetTimerEventPlatformId()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#gettimereventplatformid)")
    ADD_CLASS_METHOD(TerminateApp,"void vtkRenderWindowInteractor::TerminateApp()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#terminateapp)")
    ADD_CLASS_METHOD(SetInteractorStyle,"void vtkRenderWindowInteractor::SetInteractorStyle(vtkInteractorObserver * param0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setinteractorstyle)")
    ADD_CLASS_METHOD(GetInteractorStyle,"vtkInteractorObserver * vtkRenderWindowInteractor::GetInteractorStyle()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getinteractorstyle)")
    ADD_CLASS_METHOD(SetLightFollowCamera,"void vtkRenderWindowInteractor::SetLightFollowCamera(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setlightfollowcamera)")
    ADD_CLASS_METHOD(GetLightFollowCamera,"int vtkRenderWindowInteractor::GetLightFollowCamera()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getlightfollowcamera)")
    ADD_CLASS_METHOD(LightFollowCameraOn,"void vtkRenderWindowInteractor::LightFollowCameraOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#lightfollowcameraon)")
    ADD_CLASS_METHOD(LightFollowCameraOff,"void vtkRenderWindowInteractor::LightFollowCameraOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#lightfollowcameraoff)")
    ADD_CLASS_METHOD(SetDesiredUpdateRate,"void vtkRenderWindowInteractor::SetDesiredUpdateRate(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setdesiredupdaterate)")
    ADD_CLASS_METHOD(GetDesiredUpdateRateMinValue,"double vtkRenderWindowInteractor::GetDesiredUpdateRateMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getdesiredupdaterateminvalue)")
    ADD_CLASS_METHOD(GetDesiredUpdateRateMaxValue,"double vtkRenderWindowInteractor::GetDesiredUpdateRateMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getdesiredupdateratemaxvalue)")
    ADD_CLASS_METHOD(GetDesiredUpdateRate,"double vtkRenderWindowInteractor::GetDesiredUpdateRate()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getdesiredupdaterate)")
    ADD_CLASS_METHOD(SetStillUpdateRate,"void vtkRenderWindowInteractor::SetStillUpdateRate(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setstillupdaterate)")
    ADD_CLASS_METHOD(GetStillUpdateRateMinValue,"double vtkRenderWindowInteractor::GetStillUpdateRateMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getstillupdaterateminvalue)")
    ADD_CLASS_METHOD(GetStillUpdateRateMaxValue,"double vtkRenderWindowInteractor::GetStillUpdateRateMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getstillupdateratemaxvalue)")
    ADD_CLASS_METHOD(GetStillUpdateRate,"double vtkRenderWindowInteractor::GetStillUpdateRate()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getstillupdaterate)")
    ADD_CLASS_METHOD(GetInitialized,"int vtkRenderWindowInteractor::GetInitialized()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getinitialized)")
/* The following types are missing: vtkAbstractPicker
    ADD_CLASS_METHOD(SetPicker,"void vtkRenderWindowInteractor::SetPicker(vtkAbstractPicker * param0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setpicker)")
*/
/* The following types are missing: vtkAbstractPicker
    ADD_CLASS_METHOD(GetPicker,"vtkAbstractPicker * vtkRenderWindowInteractor::GetPicker()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getpicker)")
*/
/* The following types are missing: vtkAbstractPropPicker
    ADD_CLASS_METHOD(CreateDefaultPicker,"vtkAbstractPropPicker * vtkRenderWindowInteractor::CreateDefaultPicker()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#createdefaultpicker)")
*/
    ADD_CLASS_METHOD(ExitCallback,"void vtkRenderWindowInteractor::ExitCallback()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#exitcallback)")
    ADD_CLASS_METHOD(UserCallback,"void vtkRenderWindowInteractor::UserCallback()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#usercallback)")
    ADD_CLASS_METHOD(StartPickCallback,"void vtkRenderWindowInteractor::StartPickCallback()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#startpickcallback)")
    ADD_CLASS_METHOD(EndPickCallback,"void vtkRenderWindowInteractor::EndPickCallback()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#endpickcallback)")
    ADD_CLASS_METHOD(GetMousePosition,"void vtkRenderWindowInteractor::GetMousePosition(int * x, int * y)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getmouseposition)")
    ADD_CLASS_METHOD(HideCursor,"void vtkRenderWindowInteractor::HideCursor()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#hidecursor)")
    ADD_CLASS_METHOD(ShowCursor,"void vtkRenderWindowInteractor::ShowCursor()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#showcursor)")
    ADD_CLASS_METHOD(Render,"void vtkRenderWindowInteractor::Render()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#render)")
    ADD_CLASS_METHOD(FlyTo_1,"void vtkRenderWindowInteractor::FlyTo(vtkRenderer * ren, double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#flyto)")
    ADD_CLASS_METHOD(FlyTo,"vtkRenderWindowInteractor::FlyTo()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#flyto)")
    ADD_CLASS_METHOD(FlyTo_2,"void vtkRenderWindowInteractor::FlyTo(vtkRenderer * ren, double * x)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#flyto)")
    ADD_CLASS_METHOD(FlyToImage_1,"void vtkRenderWindowInteractor::FlyToImage(vtkRenderer * ren, double x, double y)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#flytoimage)")
    ADD_CLASS_METHOD(FlyToImage,"vtkRenderWindowInteractor::FlyToImage()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#flytoimage)")
    ADD_CLASS_METHOD(FlyToImage_2,"void vtkRenderWindowInteractor::FlyToImage(vtkRenderer * ren, double * x)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#flytoimage)")
    ADD_CLASS_METHOD(SetNumberOfFlyFrames,"void vtkRenderWindowInteractor::SetNumberOfFlyFrames(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setnumberofflyframes)")
    ADD_CLASS_METHOD(GetNumberOfFlyFramesMinValue,"int vtkRenderWindowInteractor::GetNumberOfFlyFramesMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getnumberofflyframesminvalue)")
    ADD_CLASS_METHOD(GetNumberOfFlyFramesMaxValue,"int vtkRenderWindowInteractor::GetNumberOfFlyFramesMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getnumberofflyframesmaxvalue)")
    ADD_CLASS_METHOD(GetNumberOfFlyFrames,"int vtkRenderWindowInteractor::GetNumberOfFlyFrames()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getnumberofflyframes)")
    ADD_CLASS_METHOD(SetDolly,"void vtkRenderWindowInteractor::SetDolly(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setdolly)")
    ADD_CLASS_METHOD(GetDolly,"double vtkRenderWindowInteractor::GetDolly()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getdolly)")
    ADD_CLASS_METHOD(GetEventPosition_1,"int * vtkRenderWindowInteractor::GetEventPosition()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#geteventposition)")
    ADD_CLASS_METHOD(GetEventPosition,"vtkRenderWindowInteractor::GetEventPosition()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#geteventposition)")
    ADD_CLASS_METHOD(GetEventPosition_2,"void vtkRenderWindowInteractor::GetEventPosition(int & _arg1, int & _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#geteventposition)")
    ADD_CLASS_METHOD(GetEventPosition_3,"void vtkRenderWindowInteractor::GetEventPosition(int * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#geteventposition)")
    ADD_CLASS_METHOD(GetLastEventPosition_1,"int * vtkRenderWindowInteractor::GetLastEventPosition()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getlasteventposition)")
    ADD_CLASS_METHOD(GetLastEventPosition,"vtkRenderWindowInteractor::GetLastEventPosition()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getlasteventposition)")
    ADD_CLASS_METHOD(GetLastEventPosition_2,"void vtkRenderWindowInteractor::GetLastEventPosition(int & _arg1, int & _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getlasteventposition)")
    ADD_CLASS_METHOD(GetLastEventPosition_3,"void vtkRenderWindowInteractor::GetLastEventPosition(int * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getlasteventposition)")
    ADD_CLASS_METHOD(SetLastEventPosition_1,"void vtkRenderWindowInteractor::SetLastEventPosition(int _arg1, int _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setlasteventposition)")
    ADD_CLASS_METHOD(SetLastEventPosition,"vtkRenderWindowInteractor::SetLastEventPosition()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setlasteventposition)")
    ADD_CLASS_METHOD(SetLastEventPosition_2,"void vtkRenderWindowInteractor::SetLastEventPosition(int * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setlasteventposition)")
    ADD_CLASS_METHOD(SetEventPosition_1,"void vtkRenderWindowInteractor::SetEventPosition(int x, int y)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#seteventposition)")
    ADD_CLASS_METHOD(SetEventPosition,"vtkRenderWindowInteractor::SetEventPosition()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#seteventposition)")
    ADD_CLASS_METHOD(SetEventPosition_2,"void vtkRenderWindowInteractor::SetEventPosition(int * pos)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#seteventposition)")
    ADD_CLASS_METHOD(SetEventPositionFlipY_1,"void vtkRenderWindowInteractor::SetEventPositionFlipY(int x, int y)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#seteventpositionflipy)")
    ADD_CLASS_METHOD(SetEventPositionFlipY,"vtkRenderWindowInteractor::SetEventPositionFlipY()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#seteventpositionflipy)")
    ADD_CLASS_METHOD(SetEventPositionFlipY_2,"void vtkRenderWindowInteractor::SetEventPositionFlipY(int * pos)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#seteventpositionflipy)")
    ADD_CLASS_METHOD(SetAltKey,"void vtkRenderWindowInteractor::SetAltKey(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setaltkey)")
    ADD_CLASS_METHOD(GetAltKey,"int vtkRenderWindowInteractor::GetAltKey()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getaltkey)")
    ADD_CLASS_METHOD(SetControlKey,"void vtkRenderWindowInteractor::SetControlKey(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setcontrolkey)")
    ADD_CLASS_METHOD(GetControlKey,"int vtkRenderWindowInteractor::GetControlKey()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getcontrolkey)")
    ADD_CLASS_METHOD(SetShiftKey,"void vtkRenderWindowInteractor::SetShiftKey(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setshiftkey)")
    ADD_CLASS_METHOD(GetShiftKey,"int vtkRenderWindowInteractor::GetShiftKey()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getshiftkey)")
    ADD_CLASS_METHOD(SetKeyCode,"void vtkRenderWindowInteractor::SetKeyCode(char _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setkeycode)")
    ADD_CLASS_METHOD(GetKeyCode,"char vtkRenderWindowInteractor::GetKeyCode()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getkeycode)")
    ADD_CLASS_METHOD(SetRepeatCount,"void vtkRenderWindowInteractor::SetRepeatCount(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setrepeatcount)")
    ADD_CLASS_METHOD(GetRepeatCount,"int vtkRenderWindowInteractor::GetRepeatCount()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getrepeatcount)")
    ADD_CLASS_METHOD(SetKeySym,"void vtkRenderWindowInteractor::SetKeySym(char const * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setkeysym)")
    ADD_CLASS_METHOD(GetKeySym,"char * vtkRenderWindowInteractor::GetKeySym()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getkeysym)")
    ADD_CLASS_METHOD(SetEventInformation,"void vtkRenderWindowInteractor::SetEventInformation(int x, int y, int ctrl = 0, int shift = 0, char keycode = 0, int repeatcount = 0, char const * keysym = 0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#seteventinformation)")
    ADD_CLASS_METHOD(SetEventInformationFlipY,"void vtkRenderWindowInteractor::SetEventInformationFlipY(int x, int y, int ctrl = 0, int shift = 0, char keycode = 0, int repeatcount = 0, char const * keysym = 0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#seteventinformationflipy)")
    ADD_CLASS_METHOD(SetKeyEventInformation,"void vtkRenderWindowInteractor::SetKeyEventInformation(int ctrl = 0, int shift = 0, char keycode = 0, int repeatcount = 0, char const * keysym = 0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setkeyeventinformation)")
    ADD_CLASS_METHOD(SetSize_1,"void vtkRenderWindowInteractor::SetSize(int _arg1, int _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setsize)")
    ADD_CLASS_METHOD(SetSize,"vtkRenderWindowInteractor::SetSize()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setsize)")
    ADD_CLASS_METHOD(SetSize_2,"void vtkRenderWindowInteractor::SetSize(int * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setsize)")
    ADD_CLASS_METHOD(GetSize_1,"int * vtkRenderWindowInteractor::GetSize()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getsize)")
    ADD_CLASS_METHOD(GetSize,"vtkRenderWindowInteractor::GetSize()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getsize)")
    ADD_CLASS_METHOD(GetSize_2,"void vtkRenderWindowInteractor::GetSize(int & _arg1, int & _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getsize)")
    ADD_CLASS_METHOD(GetSize_3,"void vtkRenderWindowInteractor::GetSize(int * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getsize)")
    ADD_CLASS_METHOD(SetEventSize_1,"void vtkRenderWindowInteractor::SetEventSize(int _arg1, int _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#seteventsize)")
    ADD_CLASS_METHOD(SetEventSize,"vtkRenderWindowInteractor::SetEventSize()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#seteventsize)")
    ADD_CLASS_METHOD(SetEventSize_2,"void vtkRenderWindowInteractor::SetEventSize(int * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#seteventsize)")
    ADD_CLASS_METHOD(GetEventSize_1,"int * vtkRenderWindowInteractor::GetEventSize()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#geteventsize)")
    ADD_CLASS_METHOD(GetEventSize,"vtkRenderWindowInteractor::GetEventSize()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#geteventsize)")
    ADD_CLASS_METHOD(GetEventSize_2,"void vtkRenderWindowInteractor::GetEventSize(int & _arg1, int & _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#geteventsize)")
    ADD_CLASS_METHOD(GetEventSize_3,"void vtkRenderWindowInteractor::GetEventSize(int * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#geteventsize)")
    ADD_CLASS_METHOD(FindPokedRenderer,"vtkRenderer * vtkRenderWindowInteractor::FindPokedRenderer(int param0, int param1)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#findpokedrenderer)")
/* The following types are missing: vtkObserverMediator
    ADD_CLASS_METHOD(GetObserverMediator,"vtkObserverMediator * vtkRenderWindowInteractor::GetObserverMediator()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getobservermediator)")
*/
    ADD_CLASS_METHOD(SetUseTDx,"void vtkRenderWindowInteractor::SetUseTDx(bool _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#setusetdx)")
    ADD_CLASS_METHOD(GetUseTDx,"bool vtkRenderWindowInteractor::GetUseTDx()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindowinteractor.html#getusetdx)")





    void AddMethods(WrapClass<vtkRenderWindowInteractor>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkRenderWindowInteractor_h
