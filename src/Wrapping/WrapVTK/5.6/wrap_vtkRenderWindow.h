/**
 * C++ Interface: wrap_vtkRenderWindow
 *
 * Description: wrapping vtkRenderWindow
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkRenderWindow_h_
#define _wrap_vtkRenderWindow_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkRenderWindow.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkWindow.h"



AMI_DECLARE_TYPE(vtkRenderWindow);

// TODO: check for inheritence ...
class WrapClass_vtkRenderWindow : public WrapClass<vtkRenderWindow>
    , public   WrapClass_vtkWindow
{
  DEFINE_CLASS(WrapClass_vtkRenderWindow);

  protected:
    typedef WrapClass<vtkRenderWindow>::ptr _parentclass_ptr;
    typedef vtkRenderWindow ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkRenderWindow>& GetObj() const { return WrapClass<vtkRenderWindow>::GetObj(); }

    /// Constructor
    WrapClass_vtkRenderWindow(boost::shared_ptr<vtkRenderWindow > si): 
    WrapClass<vtkRenderWindow>(si)
    , WrapClass_vtkWindow(si)
    {}

    /// Destructor
    ~WrapClass_vtkRenderWindow()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkRenderWindow*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkRenderWindow::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkRenderWindow * vtkRenderWindow::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(New,"vtkRenderWindow * vtkRenderWindow::New() (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#new).");
    ADD_CLASS_STATICMETHOD(GetRenderLibrary,"char const * vtkRenderWindow::GetRenderLibrary() (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getrenderlibrary).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkRenderWindow::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkRenderWindow * vtkRenderWindow::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkRenderWindow::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#printself)")
*/
    ADD_CLASS_METHOD(AddRenderer,"void vtkRenderWindow::AddRenderer(vtkRenderer * param0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#addrenderer)")
    ADD_CLASS_METHOD(RemoveRenderer,"void vtkRenderWindow::RemoveRenderer(vtkRenderer * param0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#removerenderer)")
    ADD_CLASS_METHOD(HasRenderer,"int vtkRenderWindow::HasRenderer(vtkRenderer * param0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#hasrenderer)")
    ADD_CLASS_METHOD(GetRenderers,"vtkRendererCollection * vtkRenderWindow::GetRenderers()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getrenderers)")
    ADD_CLASS_METHOD(Render,"void vtkRenderWindow::Render()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#render)")
    ADD_CLASS_METHOD(CopyResultFrame,"void vtkRenderWindow::CopyResultFrame()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#copyresultframe)")
    ADD_CLASS_METHOD(MakeRenderWindowInteractor,"vtkRenderWindowInteractor * vtkRenderWindow::MakeRenderWindowInteractor()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#makerenderwindowinteractor)")
    ADD_CLASS_METHOD(SetCursorPosition,"void vtkRenderWindow::SetCursorPosition(int param0, int param1)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setcursorposition)")
    ADD_CLASS_METHOD(SetCurrentCursor,"void vtkRenderWindow::SetCurrentCursor(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setcurrentcursor)")
    ADD_CLASS_METHOD(GetCurrentCursor,"int vtkRenderWindow::GetCurrentCursor()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getcurrentcursor)")
    ADD_CLASS_METHOD(GetFullScreen,"int vtkRenderWindow::GetFullScreen()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getfullscreen)")
    ADD_CLASS_METHOD(FullScreenOn,"void vtkRenderWindow::FullScreenOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#fullscreenon)")
    ADD_CLASS_METHOD(FullScreenOff,"void vtkRenderWindow::FullScreenOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#fullscreenoff)")
    ADD_CLASS_METHOD(SetBorders,"void vtkRenderWindow::SetBorders(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setborders)")
    ADD_CLASS_METHOD(GetBorders,"int vtkRenderWindow::GetBorders()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getborders)")
    ADD_CLASS_METHOD(BordersOn,"void vtkRenderWindow::BordersOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#borderson)")
    ADD_CLASS_METHOD(BordersOff,"void vtkRenderWindow::BordersOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#bordersoff)")
    ADD_CLASS_METHOD(GetStereoCapableWindow,"int vtkRenderWindow::GetStereoCapableWindow()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getstereocapablewindow)")
    ADD_CLASS_METHOD(StereoCapableWindowOn,"void vtkRenderWindow::StereoCapableWindowOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#stereocapablewindowon)")
    ADD_CLASS_METHOD(StereoCapableWindowOff,"void vtkRenderWindow::StereoCapableWindowOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#stereocapablewindowoff)")
    ADD_CLASS_METHOD(SetStereoCapableWindow,"void vtkRenderWindow::SetStereoCapableWindow(int capable)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setstereocapablewindow)")
    ADD_CLASS_METHOD(GetStereoRender,"int vtkRenderWindow::GetStereoRender()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getstereorender)")
    ADD_CLASS_METHOD(SetStereoRender,"void vtkRenderWindow::SetStereoRender(int stereo)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setstereorender)")
    ADD_CLASS_METHOD(StereoRenderOn,"void vtkRenderWindow::StereoRenderOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#stereorenderon)")
    ADD_CLASS_METHOD(StereoRenderOff,"void vtkRenderWindow::StereoRenderOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#stereorenderoff)")
    ADD_CLASS_METHOD(SetAlphaBitPlanes,"void vtkRenderWindow::SetAlphaBitPlanes(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setalphabitplanes)")
    ADD_CLASS_METHOD(GetAlphaBitPlanes,"int vtkRenderWindow::GetAlphaBitPlanes()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getalphabitplanes)")
    ADD_CLASS_METHOD(AlphaBitPlanesOn,"void vtkRenderWindow::AlphaBitPlanesOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#alphabitplaneson)")
    ADD_CLASS_METHOD(AlphaBitPlanesOff,"void vtkRenderWindow::AlphaBitPlanesOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#alphabitplanesoff)")
    ADD_CLASS_METHOD(SetPointSmoothing,"void vtkRenderWindow::SetPointSmoothing(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setpointsmoothing)")
    ADD_CLASS_METHOD(GetPointSmoothing,"int vtkRenderWindow::GetPointSmoothing()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getpointsmoothing)")
    ADD_CLASS_METHOD(PointSmoothingOn,"void vtkRenderWindow::PointSmoothingOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#pointsmoothingon)")
    ADD_CLASS_METHOD(PointSmoothingOff,"void vtkRenderWindow::PointSmoothingOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#pointsmoothingoff)")
    ADD_CLASS_METHOD(SetLineSmoothing,"void vtkRenderWindow::SetLineSmoothing(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setlinesmoothing)")
    ADD_CLASS_METHOD(GetLineSmoothing,"int vtkRenderWindow::GetLineSmoothing()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getlinesmoothing)")
    ADD_CLASS_METHOD(LineSmoothingOn,"void vtkRenderWindow::LineSmoothingOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#linesmoothingon)")
    ADD_CLASS_METHOD(LineSmoothingOff,"void vtkRenderWindow::LineSmoothingOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#linesmoothingoff)")
    ADD_CLASS_METHOD(SetPolygonSmoothing,"void vtkRenderWindow::SetPolygonSmoothing(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setpolygonsmoothing)")
    ADD_CLASS_METHOD(GetPolygonSmoothing,"int vtkRenderWindow::GetPolygonSmoothing()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getpolygonsmoothing)")
    ADD_CLASS_METHOD(PolygonSmoothingOn,"void vtkRenderWindow::PolygonSmoothingOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#polygonsmoothingon)")
    ADD_CLASS_METHOD(PolygonSmoothingOff,"void vtkRenderWindow::PolygonSmoothingOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#polygonsmoothingoff)")
    ADD_CLASS_METHOD(GetStereoType,"int vtkRenderWindow::GetStereoType()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getstereotype)")
    ADD_CLASS_METHOD(SetStereoType,"void vtkRenderWindow::SetStereoType(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setstereotype)")
    ADD_CLASS_METHOD(SetStereoTypeToCrystalEyes,"void vtkRenderWindow::SetStereoTypeToCrystalEyes()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setstereotypetocrystaleyes)")
    ADD_CLASS_METHOD(SetStereoTypeToRedBlue,"void vtkRenderWindow::SetStereoTypeToRedBlue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setstereotypetoredblue)")
    ADD_CLASS_METHOD(SetStereoTypeToInterlaced,"void vtkRenderWindow::SetStereoTypeToInterlaced()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setstereotypetointerlaced)")
    ADD_CLASS_METHOD(SetStereoTypeToLeft,"void vtkRenderWindow::SetStereoTypeToLeft()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setstereotypetoleft)")
    ADD_CLASS_METHOD(SetStereoTypeToRight,"void vtkRenderWindow::SetStereoTypeToRight()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setstereotypetoright)")
    ADD_CLASS_METHOD(SetStereoTypeToDresden,"void vtkRenderWindow::SetStereoTypeToDresden()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setstereotypetodresden)")
    ADD_CLASS_METHOD(SetStereoTypeToAnaglyph,"void vtkRenderWindow::SetStereoTypeToAnaglyph()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setstereotypetoanaglyph)")
    ADD_CLASS_METHOD(SetStereoTypeToCheckerboard,"void vtkRenderWindow::SetStereoTypeToCheckerboard()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setstereotypetocheckerboard)")
    ADD_CLASS_METHOD(GetStereoTypeAsString,"char const * vtkRenderWindow::GetStereoTypeAsString()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getstereotypeasstring)")
    ADD_CLASS_METHOD(StereoUpdate,"void vtkRenderWindow::StereoUpdate()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#stereoupdate)")
    ADD_CLASS_METHOD(StereoMidpoint,"void vtkRenderWindow::StereoMidpoint()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#stereomidpoint)")
    ADD_CLASS_METHOD(StereoRenderComplete,"void vtkRenderWindow::StereoRenderComplete()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#stereorendercomplete)")
    ADD_CLASS_METHOD(SetAnaglyphColorSaturation,"void vtkRenderWindow::SetAnaglyphColorSaturation(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setanaglyphcolorsaturation)")
    ADD_CLASS_METHOD(GetAnaglyphColorSaturationMinValue,"float vtkRenderWindow::GetAnaglyphColorSaturationMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getanaglyphcolorsaturationminvalue)")
    ADD_CLASS_METHOD(GetAnaglyphColorSaturationMaxValue,"float vtkRenderWindow::GetAnaglyphColorSaturationMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getanaglyphcolorsaturationmaxvalue)")
    ADD_CLASS_METHOD(GetAnaglyphColorSaturation,"float vtkRenderWindow::GetAnaglyphColorSaturation()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getanaglyphcolorsaturation)")
    ADD_CLASS_METHOD(SetAnaglyphColorMask_1,"void vtkRenderWindow::SetAnaglyphColorMask(int _arg1, int _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setanaglyphcolormask)")
    ADD_CLASS_METHOD(SetAnaglyphColorMask,"vtkRenderWindow::SetAnaglyphColorMask()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setanaglyphcolormask)")
    ADD_CLASS_METHOD(SetAnaglyphColorMask_2,"void vtkRenderWindow::SetAnaglyphColorMask(int * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setanaglyphcolormask)")
    ADD_CLASS_METHOD(GetAnaglyphColorMask_1,"int * vtkRenderWindow::GetAnaglyphColorMask()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getanaglyphcolormask)")
    ADD_CLASS_METHOD(GetAnaglyphColorMask,"vtkRenderWindow::GetAnaglyphColorMask()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getanaglyphcolormask)")
    ADD_CLASS_METHOD(GetAnaglyphColorMask_2,"void vtkRenderWindow::GetAnaglyphColorMask(int * data)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getanaglyphcolormask)")
    ADD_CLASS_METHOD(SetSwapBuffers,"void vtkRenderWindow::SetSwapBuffers(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setswapbuffers)")
    ADD_CLASS_METHOD(GetSwapBuffers,"int vtkRenderWindow::GetSwapBuffers()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getswapbuffers)")
    ADD_CLASS_METHOD(SwapBuffersOn,"void vtkRenderWindow::SwapBuffersOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#swapbufferson)")
    ADD_CLASS_METHOD(SwapBuffersOff,"void vtkRenderWindow::SwapBuffersOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#swapbuffersoff)")
    ADD_CLASS_METHOD(GetZbufferDataAtPoint,"float vtkRenderWindow::GetZbufferDataAtPoint(int x, int y)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getzbufferdataatpoint)")
    ADD_CLASS_METHOD(GetAAFrames,"int vtkRenderWindow::GetAAFrames()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getaaframes)")
    ADD_CLASS_METHOD(SetAAFrames,"void vtkRenderWindow::SetAAFrames(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setaaframes)")
    ADD_CLASS_METHOD(GetFDFrames,"int vtkRenderWindow::GetFDFrames()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getfdframes)")
    ADD_CLASS_METHOD(SetFDFrames,"void vtkRenderWindow::SetFDFrames(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setfdframes)")
    ADD_CLASS_METHOD(GetSubFrames,"int vtkRenderWindow::GetSubFrames()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getsubframes)")
    ADD_CLASS_METHOD(SetSubFrames,"void vtkRenderWindow::SetSubFrames(int subFrames)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setsubframes)")
    ADD_CLASS_METHOD(GetNeverRendered,"int vtkRenderWindow::GetNeverRendered()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getneverrendered)")
    ADD_CLASS_METHOD(GetAbortRender,"int vtkRenderWindow::GetAbortRender()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getabortrender)")
    ADD_CLASS_METHOD(SetAbortRender,"void vtkRenderWindow::SetAbortRender(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setabortrender)")
    ADD_CLASS_METHOD(GetInAbortCheck,"int vtkRenderWindow::GetInAbortCheck()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getinabortcheck)")
    ADD_CLASS_METHOD(SetInAbortCheck,"void vtkRenderWindow::SetInAbortCheck(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setinabortcheck)")
    ADD_CLASS_METHOD(CheckAbortStatus,"int vtkRenderWindow::CheckAbortStatus()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#checkabortstatus)")
    ADD_CLASS_METHOD(GetIsPicking,"int vtkRenderWindow::GetIsPicking()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getispicking)")
    ADD_CLASS_METHOD(SetIsPicking,"void vtkRenderWindow::SetIsPicking(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setispicking)")
    ADD_CLASS_METHOD(IsPickingOn,"void vtkRenderWindow::IsPickingOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#ispickingon)")
    ADD_CLASS_METHOD(IsPickingOff,"void vtkRenderWindow::IsPickingOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#ispickingoff)")
    ADD_CLASS_METHOD(CheckInRenderStatus,"int vtkRenderWindow::CheckInRenderStatus()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#checkinrenderstatus)")
    ADD_CLASS_METHOD(ClearInRenderStatus,"void vtkRenderWindow::ClearInRenderStatus()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#clearinrenderstatus)")
    ADD_CLASS_METHOD(SetDesiredUpdateRate,"void vtkRenderWindow::SetDesiredUpdateRate(double param0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setdesiredupdaterate)")
    ADD_CLASS_METHOD(GetDesiredUpdateRate,"double vtkRenderWindow::GetDesiredUpdateRate()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getdesiredupdaterate)")
    ADD_CLASS_METHOD(GetNumberOfLayers,"int vtkRenderWindow::GetNumberOfLayers()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getnumberoflayers)")
    ADD_CLASS_METHOD(SetNumberOfLayers,"void vtkRenderWindow::SetNumberOfLayers(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setnumberoflayers)")
    ADD_CLASS_METHOD(GetNumberOfLayersMinValue,"int vtkRenderWindow::GetNumberOfLayersMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getnumberoflayersminvalue)")
    ADD_CLASS_METHOD(GetNumberOfLayersMaxValue,"int vtkRenderWindow::GetNumberOfLayersMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getnumberoflayersmaxvalue)")
    ADD_CLASS_METHOD(GetInteractor,"vtkRenderWindowInteractor * vtkRenderWindow::GetInteractor()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getinteractor)")
    ADD_CLASS_METHOD(SetInteractor,"void vtkRenderWindow::SetInteractor(vtkRenderWindowInteractor * param0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setinteractor)")
    ADD_CLASS_METHOD(UnRegister,"void vtkRenderWindow::UnRegister(vtkObjectBase * o)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#unregister)")
    ADD_CLASS_METHOD(SetForceMakeCurrent,"void vtkRenderWindow::SetForceMakeCurrent()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setforcemakecurrent)")
    ADD_CLASS_METHOD(ReportCapabilities,"char const * vtkRenderWindow::ReportCapabilities()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#reportcapabilities)")
    ADD_CLASS_METHOD(SupportsOpenGL,"int vtkRenderWindow::SupportsOpenGL()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#supportsopengl)")
    ADD_CLASS_METHOD(IsDirect,"int vtkRenderWindow::IsDirect()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#isdirect)")
/* The following types are missing: vtkPainterDeviceAdapter
    ADD_CLASS_METHOD(GetPainterDeviceAdapter,"vtkPainterDeviceAdapter * vtkRenderWindow::GetPainterDeviceAdapter()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getpainterdeviceadapter)")
*/
    ADD_CLASS_METHOD(SetMultiSamples,"void vtkRenderWindow::SetMultiSamples(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setmultisamples)")
    ADD_CLASS_METHOD(GetMultiSamples,"int vtkRenderWindow::GetMultiSamples()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getmultisamples)")
    ADD_CLASS_METHOD(SetStencilCapable,"void vtkRenderWindow::SetStencilCapable(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setstencilcapable)")
    ADD_CLASS_METHOD(GetStencilCapable,"int vtkRenderWindow::GetStencilCapable()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getstencilcapable)")
    ADD_CLASS_METHOD(StencilCapableOn,"void vtkRenderWindow::StencilCapableOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#stencilcapableon)")
    ADD_CLASS_METHOD(StencilCapableOff,"void vtkRenderWindow::StencilCapableOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#stencilcapableoff)")
    ADD_CLASS_METHOD(SetReportGraphicErrors,"void vtkRenderWindow::SetReportGraphicErrors(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#setreportgraphicerrors)")
    ADD_CLASS_METHOD(GetReportGraphicErrors,"int vtkRenderWindow::GetReportGraphicErrors()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#getreportgraphicerrors)")
    ADD_CLASS_METHOD(ReportGraphicErrorsOn,"void vtkRenderWindow::ReportGraphicErrorsOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#reportgraphicerrorson)")
    ADD_CLASS_METHOD(ReportGraphicErrorsOff,"void vtkRenderWindow::ReportGraphicErrorsOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderwindow.html#reportgraphicerrorsoff)")





    void AddMethods(WrapClass<vtkRenderWindow>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkRenderWindow_h
