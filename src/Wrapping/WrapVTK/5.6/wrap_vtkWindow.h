/**
 * C++ Interface: wrap_vtkWindow
 *
 * Description: wrapping vtkWindow
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkWindow_h_
#define _wrap_vtkWindow_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"



AMI_DECLARE_TYPE(vtkWindow);

// TODO: check for inheritence ...
class WrapClass_vtkWindow : public WrapClass<vtkWindow>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkWindow);

  protected:
    typedef WrapClass<vtkWindow>::ptr _parentclass_ptr;
    typedef vtkWindow ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkWindow>& GetObj() const { return WrapClass<vtkWindow>::GetObj(); }

    /// Constructor
    WrapClass_vtkWindow(boost::shared_ptr<vtkWindow > si): 
    WrapClass<vtkWindow>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkWindow()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkWindow*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkWindow::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkWindow * vtkWindow::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkWindow::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkWindow * vtkWindow::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkWindow::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#printself)")
*/
    ADD_CLASS_METHOD(GetPosition,"int * vtkWindow::GetPosition()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#getposition)")
    ADD_CLASS_METHOD(SetPosition_1,"void vtkWindow::SetPosition(int param0, int param1)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#setposition)")
    ADD_CLASS_METHOD(SetPosition,"vtkWindow::SetPosition()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#setposition)")
    ADD_CLASS_METHOD(SetPosition_2,"void vtkWindow::SetPosition(int * a)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#setposition)")
    ADD_CLASS_METHOD(GetSize,"int * vtkWindow::GetSize()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#getsize)")
    ADD_CLASS_METHOD(SetSize_1,"void vtkWindow::SetSize(int param0, int param1)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#setsize)")
    ADD_CLASS_METHOD(SetSize,"vtkWindow::SetSize()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#setsize)")
    ADD_CLASS_METHOD(SetSize_2,"void vtkWindow::SetSize(int * a)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#setsize)")
    ADD_CLASS_METHOD(GetActualSize,"int * vtkWindow::GetActualSize()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#getactualsize)")
    ADD_CLASS_METHOD(SetMapped,"void vtkWindow::SetMapped(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#setmapped)")
    ADD_CLASS_METHOD(GetMapped,"int vtkWindow::GetMapped()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#getmapped)")
    ADD_CLASS_METHOD(MappedOn,"void vtkWindow::MappedOn()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#mappedon)")
    ADD_CLASS_METHOD(MappedOff,"void vtkWindow::MappedOff()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#mappedoff)")
    ADD_CLASS_METHOD(SetErase,"void vtkWindow::SetErase(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#seterase)")
    ADD_CLASS_METHOD(GetErase,"int vtkWindow::GetErase()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#geterase)")
    ADD_CLASS_METHOD(EraseOn,"void vtkWindow::EraseOn()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#eraseon)")
    ADD_CLASS_METHOD(EraseOff,"void vtkWindow::EraseOff()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#eraseoff)")
    ADD_CLASS_METHOD(SetDoubleBuffer,"void vtkWindow::SetDoubleBuffer(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#setdoublebuffer)")
    ADD_CLASS_METHOD(GetDoubleBuffer,"int vtkWindow::GetDoubleBuffer()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#getdoublebuffer)")
    ADD_CLASS_METHOD(DoubleBufferOn,"void vtkWindow::DoubleBufferOn()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#doublebufferon)")
    ADD_CLASS_METHOD(DoubleBufferOff,"void vtkWindow::DoubleBufferOff()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#doublebufferoff)")
    ADD_CLASS_METHOD(GetWindowName,"char * vtkWindow::GetWindowName()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#getwindowname)")
    ADD_CLASS_METHOD(SetWindowName,"void vtkWindow::SetWindowName(char const * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#setwindowname)")
    ADD_CLASS_METHOD(GetDPI,"int vtkWindow::GetDPI()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#getdpi)")
    ADD_CLASS_METHOD(SetDPI,"void vtkWindow::SetDPI(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#setdpi)")
    ADD_CLASS_METHOD(GetDPIMinValue,"int vtkWindow::GetDPIMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#getdpiminvalue)")
    ADD_CLASS_METHOD(GetDPIMaxValue,"int vtkWindow::GetDPIMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#getdpimaxvalue)")
    ADD_CLASS_METHOD(SetOffScreenRendering,"void vtkWindow::SetOffScreenRendering(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#setoffscreenrendering)")
    ADD_CLASS_METHOD(GetOffScreenRendering,"int vtkWindow::GetOffScreenRendering()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#getoffscreenrendering)")
    ADD_CLASS_METHOD(OffScreenRenderingOn,"void vtkWindow::OffScreenRenderingOn()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#offscreenrenderingon)")
    ADD_CLASS_METHOD(OffScreenRenderingOff,"void vtkWindow::OffScreenRenderingOff()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#offscreenrenderingoff)")
    ADD_CLASS_METHOD(MakeCurrent,"void vtkWindow::MakeCurrent()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#makecurrent)")
    ADD_CLASS_METHOD(SetTileScale_1,"void vtkWindow::SetTileScale(int _arg1, int _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#settilescale)")
    ADD_CLASS_METHOD(SetTileScale,"vtkWindow::SetTileScale()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#settilescale)")
    ADD_CLASS_METHOD(SetTileScale_2,"void vtkWindow::SetTileScale(int * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#settilescale)")
    ADD_CLASS_METHOD(GetTileScale_1,"int * vtkWindow::GetTileScale()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#gettilescale)")
    ADD_CLASS_METHOD(GetTileScale,"vtkWindow::GetTileScale()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#gettilescale)")
    ADD_CLASS_METHOD(GetTileScale_2,"void vtkWindow::GetTileScale(int & _arg1, int & _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#gettilescale)")
    ADD_CLASS_METHOD(GetTileScale_3,"void vtkWindow::GetTileScale(int * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#gettilescale)")
    ADD_CLASS_METHOD(SetTileScale_3,"void vtkWindow::SetTileScale(int s)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#settilescale)")
    ADD_CLASS_METHOD(SetTileViewport_1,"void vtkWindow::SetTileViewport(double _arg1, double _arg2, double _arg3, double _arg4)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#settileviewport)")
    ADD_CLASS_METHOD(SetTileViewport,"vtkWindow::SetTileViewport()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#settileviewport)")
    ADD_CLASS_METHOD(SetTileViewport_2,"void vtkWindow::SetTileViewport(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#settileviewport)")
    ADD_CLASS_METHOD(GetTileViewport_1,"double * vtkWindow::GetTileViewport()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#gettileviewport)")
    ADD_CLASS_METHOD(GetTileViewport,"vtkWindow::GetTileViewport()  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#gettileviewport)")
    ADD_CLASS_METHOD(GetTileViewport_2,"void vtkWindow::GetTileViewport(double & _arg1, double & _arg2, double & _arg3, double & _arg4)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#gettileviewport)")
    ADD_CLASS_METHOD(GetTileViewport_3,"void vtkWindow::GetTileViewport(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkwindow.html#gettileviewport)")





    void AddMethods(WrapClass<vtkWindow>::ptr this_ptr );

};


#endif // _wrap_vtkWindow_h
