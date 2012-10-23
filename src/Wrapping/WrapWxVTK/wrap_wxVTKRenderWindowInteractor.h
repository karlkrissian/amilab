/**
 * C++ Interface: wrap_wxVTKRenderWindowInteractor
 *
 * Description: wrapping wxVTKRenderWindowInteractor
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxVTKRenderWindowInteractor_h_
#define _wrap_wxVTKRenderWindowInteractor_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wxVTKRenderWindowInteractor.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxWindow.h"
#include "wrap_vtkRenderWindowInteractor.h"



AMI_DECLARE_TYPE(wxVTKRenderWindowInteractor);

// TODO: check for inheritence ...
class WrapClass_wxVTKRenderWindowInteractor : public WrapClass<wxVTKRenderWindowInteractor>
    , public   WrapClass_wxWindow, public   WrapClass_vtkRenderWindowInteractor
{
  DEFINE_CLASS(WrapClass_wxVTKRenderWindowInteractor);

  protected:
    typedef WrapClass<wxVTKRenderWindowInteractor>::ptr _parentclass_ptr;
    typedef wxVTKRenderWindowInteractor ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxVTKRenderWindowInteractor>& GetObj() const { return WrapClass<wxVTKRenderWindowInteractor>::GetObj(); }
    std::string ObjPointerAsString() { return "wxVTKRenderWindowInteractor"; }

    /// Constructor
    WrapClass_wxVTKRenderWindowInteractor(boost::shared_ptr<wxVTKRenderWindowInteractor > si): 
    WrapClass<wxVTKRenderWindowInteractor>(si)
    , WrapClass_wxWindow(si), WrapClass_vtkRenderWindowInteractor(si)
    {}

    /// Constructor const
    WrapClass_wxVTKRenderWindowInteractor(boost::shared_ptr<wxVTKRenderWindowInteractor const> si, bool): 
      WrapClass<wxVTKRenderWindowInteractor>(si,true), 
      WrapClass_wxWindow(si, true), 
      WrapClass_vtkRenderWindowInteractor(si, true)
    {}

    /// Destructor
    ~WrapClass_wxVTKRenderWindowInteractor()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxVTKRenderWindowInteractor_1,"Constructor wxVTKRenderWindowInteractor::wxVTKRenderWindowInteractor() (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#wxvtkrenderwindowinteractor).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxVTKRenderWindowInteractor,"Constructor wxVTKRenderWindowInteractor::wxVTKRenderWindowInteractor() (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#wxvtkrenderwindowinteractor).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxVTKRenderWindowInteractor_2,"Constructor wxVTKRenderWindowInteractor::wxVTKRenderWindowInteractor(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 262144, wxString const & name = wxPanelNameStr) (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#wxvtkrenderwindowinteractor).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxVTKRenderWindowInteractor*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int wxVTKRenderWindowInteractor::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"wxVTKRenderWindowInteractor * wxVTKRenderWindowInteractor::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(New,"wxVTKRenderWindowInteractor * wxVTKRenderWindowInteractor::New() (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#new).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxVTKRenderWindowInteractor::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#getclassinfo)")
    ADD_CLASS_METHOD(IsA,"int wxVTKRenderWindowInteractor::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"wxVTKRenderWindowInteractor * wxVTKRenderWindowInteractor::NewInstance()  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void wxVTKRenderWindowInteractor::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#printself)")
*/
    ADD_CLASS_METHOD(Initialize,"void wxVTKRenderWindowInteractor::Initialize()  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#initialize)")
    ADD_CLASS_METHOD(Enable_1,"void wxVTKRenderWindowInteractor::Enable()  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#enable)")
    ADD_CLASS_METHOD(Enable,"wxVTKRenderWindowInteractor::Enable()  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#enable)")
    ADD_CLASS_METHOD(Enable_2,"bool wxVTKRenderWindowInteractor::Enable(bool enable)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#enable)")
    ADD_CLASS_METHOD(Disable,"void wxVTKRenderWindowInteractor::Disable()  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#disable)")
    ADD_CLASS_METHOD(Start,"void wxVTKRenderWindowInteractor::Start()  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#start)")
    ADD_CLASS_METHOD(UpdateSize,"void wxVTKRenderWindowInteractor::UpdateSize(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#updatesize)")
    ADD_CLASS_METHOD(CreateTimer,"int wxVTKRenderWindowInteractor::CreateTimer(int timertype)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#createtimer)")
    ADD_CLASS_METHOD(DestroyTimer,"int wxVTKRenderWindowInteractor::DestroyTimer()  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#destroytimer)")
    ADD_CLASS_METHOD(TerminateApp,"void wxVTKRenderWindowInteractor::TerminateApp()  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#terminateapp)")
    ADD_CLASS_METHOD(OnPaint,"void wxVTKRenderWindowInteractor::OnPaint(wxPaintEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#onpaint)")
/* The following types are missing: wxEraseEvent
    ADD_CLASS_METHOD(OnEraseBackground,"void wxVTKRenderWindowInteractor::OnEraseBackground(wxEraseEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#onerasebackground)")
*/
    ADD_CLASS_METHOD(OnMotion,"void wxVTKRenderWindowInteractor::OnMotion(wxMouseEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#onmotion)")
    ADD_CLASS_METHOD(OnButtonDown,"void wxVTKRenderWindowInteractor::OnButtonDown(wxMouseEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#onbuttondown)")
    ADD_CLASS_METHOD(OnButtonUp,"void wxVTKRenderWindowInteractor::OnButtonUp(wxMouseEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#onbuttonup)")
    ADD_CLASS_METHOD(OnEnter,"void wxVTKRenderWindowInteractor::OnEnter(wxMouseEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#onenter)")
    ADD_CLASS_METHOD(OnLeave,"void wxVTKRenderWindowInteractor::OnLeave(wxMouseEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#onleave)")
    ADD_CLASS_METHOD(OnKeyDown,"void wxVTKRenderWindowInteractor::OnKeyDown(wxKeyEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#onkeydown)")
    ADD_CLASS_METHOD(OnKeyUp,"void wxVTKRenderWindowInteractor::OnKeyUp(wxKeyEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#onkeyup)")
    ADD_CLASS_METHOD(OnChar,"void wxVTKRenderWindowInteractor::OnChar(wxKeyEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#onchar)")
/* The following types are missing: wxTimerEvent
    ADD_CLASS_METHOD(OnTimer,"void wxVTKRenderWindowInteractor::OnTimer(wxTimerEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#ontimer)")
*/
    ADD_CLASS_METHOD(OnSize,"void wxVTKRenderWindowInteractor::OnSize(wxSizeEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#onsize)")
    ADD_CLASS_METHOD(OnMouseWheel,"void wxVTKRenderWindowInteractor::OnMouseWheel(wxMouseEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#onmousewheel)")
    ADD_CLASS_METHOD(Render,"void wxVTKRenderWindowInteractor::Render()  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#render)")
    ADD_CLASS_METHOD(SetRenderWhenDisabled,"void wxVTKRenderWindowInteractor::SetRenderWhenDisabled(int newValue)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#setrenderwhendisabled)")
    ADD_CLASS_METHOD(GetStereo,"int wxVTKRenderWindowInteractor::GetStereo()  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#getstereo)")
    ADD_CLASS_METHOD(StereoOn,"void wxVTKRenderWindowInteractor::StereoOn()  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#stereoon)")
    ADD_CLASS_METHOD(StereoOff,"void wxVTKRenderWindowInteractor::StereoOff()  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#stereooff)")
    ADD_CLASS_METHOD(SetStereo,"void wxVTKRenderWindowInteractor::SetStereo(int capable)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#setstereo)")
    ADD_CLASS_METHOD(SetUseCaptureMouse,"void wxVTKRenderWindowInteractor::SetUseCaptureMouse(int _arg)  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#setusecapturemouse)")
    ADD_CLASS_METHOD(UseCaptureMouseOn,"void wxVTKRenderWindowInteractor::UseCaptureMouseOn()  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#usecapturemouseon)")
    ADD_CLASS_METHOD(UseCaptureMouseOff,"void wxVTKRenderWindowInteractor::UseCaptureMouseOff()  (http://docs.wxwidgets.org/stable/wx_wxvtkrenderwindowinteractor.html#usecapturemouseoff)")





    void AddMethods(WrapClass<wxVTKRenderWindowInteractor>::ptr this_ptr );

};


#endif // _wrap_wxVTKRenderWindowInteractor_h
