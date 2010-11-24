/**
 * C++ Interface: wrap_vtkRenderer
 *
 * Description: wrapping vtkRenderer
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkRenderer_h_
#define _wrap_vtkRenderer_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkViewport.h"



AMI_DECLARE_TYPE(vtkRenderer);

// TODO: check for inheritence ...
class WrapClass_vtkRenderer : public WrapClass<vtkRenderer>
    , public   WrapClass_vtkViewport
{
  DEFINE_CLASS(WrapClass_vtkRenderer);

  protected:
    typedef WrapClass<vtkRenderer>::ptr _parentclass_ptr;
    typedef vtkRenderer ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkRenderer>& GetObj() const { return WrapClass<vtkRenderer>::GetObj(); }

    /// Constructor
    WrapClass_vtkRenderer(boost::shared_ptr<vtkRenderer > si): 
    WrapClass<vtkRenderer>(si)
    , WrapClass_vtkViewport(si)
    {}

    /// Destructor
    ~WrapClass_vtkRenderer()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkRenderer*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkRenderer::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkRenderer * vtkRenderer::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(New,"vtkRenderer * vtkRenderer::New() (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#new).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkRenderer::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkRenderer * vtkRenderer::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkRenderer::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#printself)")
*/
    ADD_CLASS_METHOD(AddActor,"void vtkRenderer::AddActor(vtkProp * p)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#addactor)")
    ADD_CLASS_METHOD(AddVolume,"void vtkRenderer::AddVolume(vtkProp * p)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#addvolume)")
    ADD_CLASS_METHOD(RemoveActor,"void vtkRenderer::RemoveActor(vtkProp * p)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#removeactor)")
    ADD_CLASS_METHOD(RemoveVolume,"void vtkRenderer::RemoveVolume(vtkProp * p)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#removevolume)")
/* The following types are missing: vtkLight
    ADD_CLASS_METHOD(AddLight,"void vtkRenderer::AddLight(vtkLight * param0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#addlight)")
*/
/* The following types are missing: vtkLight
    ADD_CLASS_METHOD(RemoveLight,"void vtkRenderer::RemoveLight(vtkLight * param0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#removelight)")
*/
    ADD_CLASS_METHOD(RemoveAllLights,"void vtkRenderer::RemoveAllLights()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#removealllights)")
/* The following types are missing: vtkLightCollection
    ADD_CLASS_METHOD(GetLights,"vtkLightCollection * vtkRenderer::GetLights()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getlights)")
*/
/* The following types are missing: vtkLightCollection
    ADD_CLASS_METHOD(SetLightCollection,"void vtkRenderer::SetLightCollection(vtkLightCollection * lights)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setlightcollection)")
*/
    ADD_CLASS_METHOD(CreateLight,"void vtkRenderer::CreateLight()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#createlight)")
/* The following types are missing: vtkLight
    ADD_CLASS_METHOD(MakeLight,"vtkLight * vtkRenderer::MakeLight()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#makelight)")
*/
    ADD_CLASS_METHOD(GetTwoSidedLighting,"int vtkRenderer::GetTwoSidedLighting()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#gettwosidedlighting)")
    ADD_CLASS_METHOD(SetTwoSidedLighting,"void vtkRenderer::SetTwoSidedLighting(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#settwosidedlighting)")
    ADD_CLASS_METHOD(TwoSidedLightingOn,"void vtkRenderer::TwoSidedLightingOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#twosidedlightingon)")
    ADD_CLASS_METHOD(TwoSidedLightingOff,"void vtkRenderer::TwoSidedLightingOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#twosidedlightingoff)")
    ADD_CLASS_METHOD(SetLightFollowCamera,"void vtkRenderer::SetLightFollowCamera(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setlightfollowcamera)")
    ADD_CLASS_METHOD(GetLightFollowCamera,"int vtkRenderer::GetLightFollowCamera()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getlightfollowcamera)")
    ADD_CLASS_METHOD(LightFollowCameraOn,"void vtkRenderer::LightFollowCameraOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#lightfollowcameraon)")
    ADD_CLASS_METHOD(LightFollowCameraOff,"void vtkRenderer::LightFollowCameraOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#lightfollowcameraoff)")
    ADD_CLASS_METHOD(GetAutomaticLightCreation,"int vtkRenderer::GetAutomaticLightCreation()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getautomaticlightcreation)")
    ADD_CLASS_METHOD(SetAutomaticLightCreation,"void vtkRenderer::SetAutomaticLightCreation(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setautomaticlightcreation)")
    ADD_CLASS_METHOD(AutomaticLightCreationOn,"void vtkRenderer::AutomaticLightCreationOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#automaticlightcreationon)")
    ADD_CLASS_METHOD(AutomaticLightCreationOff,"void vtkRenderer::AutomaticLightCreationOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#automaticlightcreationoff)")
    ADD_CLASS_METHOD(UpdateLightsGeometryToFollowCamera,"int vtkRenderer::UpdateLightsGeometryToFollowCamera()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#updatelightsgeometrytofollowcamera)")
    ADD_CLASS_METHOD(GetVolumes,"vtkVolumeCollection * vtkRenderer::GetVolumes()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getvolumes)")
    ADD_CLASS_METHOD(GetActors,"vtkActorCollection * vtkRenderer::GetActors()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getactors)")
    ADD_CLASS_METHOD(SetActiveCamera,"void vtkRenderer::SetActiveCamera(vtkCamera * param0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setactivecamera)")
    ADD_CLASS_METHOD(GetActiveCamera,"vtkCamera * vtkRenderer::GetActiveCamera()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getactivecamera)")
    ADD_CLASS_METHOD(MakeCamera,"vtkCamera * vtkRenderer::MakeCamera()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#makecamera)")
    ADD_CLASS_METHOD(SetErase,"void vtkRenderer::SetErase(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#seterase)")
    ADD_CLASS_METHOD(GetErase,"int vtkRenderer::GetErase()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#geterase)")
    ADD_CLASS_METHOD(EraseOn,"void vtkRenderer::EraseOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#eraseon)")
    ADD_CLASS_METHOD(EraseOff,"void vtkRenderer::EraseOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#eraseoff)")
    ADD_CLASS_METHOD(SetDraw,"void vtkRenderer::SetDraw(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setdraw)")
    ADD_CLASS_METHOD(GetDraw,"int vtkRenderer::GetDraw()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getdraw)")
    ADD_CLASS_METHOD(DrawOn,"void vtkRenderer::DrawOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#drawon)")
    ADD_CLASS_METHOD(DrawOff,"void vtkRenderer::DrawOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#drawoff)")
/* The following types are missing: vtkCuller
    ADD_CLASS_METHOD(AddCuller,"void vtkRenderer::AddCuller(vtkCuller * param0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#addculler)")
*/
/* The following types are missing: vtkCuller
    ADD_CLASS_METHOD(RemoveCuller,"void vtkRenderer::RemoveCuller(vtkCuller * param0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#removeculler)")
*/
/* The following types are missing: vtkCullerCollection
    ADD_CLASS_METHOD(GetCullers,"vtkCullerCollection * vtkRenderer::GetCullers()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getcullers)")
*/
    ADD_CLASS_METHOD(SetAmbient_1,"void vtkRenderer::SetAmbient(double _arg1, double _arg2, double _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setambient)")
    ADD_CLASS_METHOD(SetAmbient,"vtkRenderer::SetAmbient()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setambient)")
    ADD_CLASS_METHOD(SetAmbient_2,"void vtkRenderer::SetAmbient(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setambient)")
    ADD_CLASS_METHOD(GetAmbient_1,"double * vtkRenderer::GetAmbient()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getambient)")
    ADD_CLASS_METHOD(GetAmbient,"vtkRenderer::GetAmbient()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getambient)")
    ADD_CLASS_METHOD(GetAmbient_2,"void vtkRenderer::GetAmbient(double * data)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getambient)")
    ADD_CLASS_METHOD(SetAllocatedRenderTime,"void vtkRenderer::SetAllocatedRenderTime(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setallocatedrendertime)")
    ADD_CLASS_METHOD(GetAllocatedRenderTime,"double vtkRenderer::GetAllocatedRenderTime()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getallocatedrendertime)")
    ADD_CLASS_METHOD(GetTimeFactor,"double vtkRenderer::GetTimeFactor()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#gettimefactor)")
    ADD_CLASS_METHOD(Render,"void vtkRenderer::Render()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#render)")
    ADD_CLASS_METHOD(DeviceRenderTranslucentPolygonalGeometry,"void vtkRenderer::DeviceRenderTranslucentPolygonalGeometry()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#devicerendertranslucentpolygonalgeometry)")
    ADD_CLASS_METHOD(Clear,"void vtkRenderer::Clear()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#clear)")
    ADD_CLASS_METHOD(VisibleActorCount,"int vtkRenderer::VisibleActorCount()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#visibleactorcount)")
    ADD_CLASS_METHOD(VisibleVolumeCount,"int vtkRenderer::VisibleVolumeCount()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#visiblevolumecount)")
    ADD_CLASS_METHOD(ComputeVisiblePropBounds_1,"void vtkRenderer::ComputeVisiblePropBounds(double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#computevisiblepropbounds)")
    ADD_CLASS_METHOD(ComputeVisiblePropBounds,"vtkRenderer::ComputeVisiblePropBounds()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#computevisiblepropbounds)")
    ADD_CLASS_METHOD(ComputeVisiblePropBounds_2,"double * vtkRenderer::ComputeVisiblePropBounds()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#computevisiblepropbounds)")
    ADD_CLASS_METHOD(ResetCameraClippingRange_1,"void vtkRenderer::ResetCameraClippingRange()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#resetcameraclippingrange)")
    ADD_CLASS_METHOD(ResetCameraClippingRange,"vtkRenderer::ResetCameraClippingRange()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#resetcameraclippingrange)")
    ADD_CLASS_METHOD(ResetCameraClippingRange_2,"void vtkRenderer::ResetCameraClippingRange(double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#resetcameraclippingrange)")
    ADD_CLASS_METHOD(ResetCameraClippingRange_3,"void vtkRenderer::ResetCameraClippingRange(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#resetcameraclippingrange)")
    ADD_CLASS_METHOD(SetNearClippingPlaneTolerance,"void vtkRenderer::SetNearClippingPlaneTolerance(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setnearclippingplanetolerance)")
    ADD_CLASS_METHOD(GetNearClippingPlaneToleranceMinValue,"double vtkRenderer::GetNearClippingPlaneToleranceMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getnearclippingplanetoleranceminvalue)")
    ADD_CLASS_METHOD(GetNearClippingPlaneToleranceMaxValue,"double vtkRenderer::GetNearClippingPlaneToleranceMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getnearclippingplanetolerancemaxvalue)")
    ADD_CLASS_METHOD(GetNearClippingPlaneTolerance,"double vtkRenderer::GetNearClippingPlaneTolerance()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getnearclippingplanetolerance)")
    ADD_CLASS_METHOD(ResetCamera_1,"void vtkRenderer::ResetCamera()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#resetcamera)")
    ADD_CLASS_METHOD(ResetCamera,"vtkRenderer::ResetCamera()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#resetcamera)")
    ADD_CLASS_METHOD(ResetCamera_2,"void vtkRenderer::ResetCamera(double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#resetcamera)")
    ADD_CLASS_METHOD(ResetCamera_3,"void vtkRenderer::ResetCamera(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#resetcamera)")
    ADD_CLASS_METHOD(SetRenderWindow,"void vtkRenderer::SetRenderWindow(vtkRenderWindow * param0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setrenderwindow)")
    ADD_CLASS_METHOD(GetRenderWindow,"vtkRenderWindow * vtkRenderer::GetRenderWindow()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getrenderwindow)")
    ADD_CLASS_METHOD(GetVTKWindow,"vtkWindow * vtkRenderer::GetVTKWindow()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getvtkwindow)")
    ADD_CLASS_METHOD(SetBackingStore,"void vtkRenderer::SetBackingStore(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setbackingstore)")
    ADD_CLASS_METHOD(GetBackingStore,"int vtkRenderer::GetBackingStore()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getbackingstore)")
    ADD_CLASS_METHOD(BackingStoreOn,"void vtkRenderer::BackingStoreOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#backingstoreon)")
    ADD_CLASS_METHOD(BackingStoreOff,"void vtkRenderer::BackingStoreOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#backingstoreoff)")
    ADD_CLASS_METHOD(SetInteractive,"void vtkRenderer::SetInteractive(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setinteractive)")
    ADD_CLASS_METHOD(GetInteractive,"int vtkRenderer::GetInteractive()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getinteractive)")
    ADD_CLASS_METHOD(InteractiveOn,"void vtkRenderer::InteractiveOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#interactiveon)")
    ADD_CLASS_METHOD(InteractiveOff,"void vtkRenderer::InteractiveOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#interactiveoff)")
    ADD_CLASS_METHOD(SetLayer,"void vtkRenderer::SetLayer(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setlayer)")
    ADD_CLASS_METHOD(GetLayer,"int vtkRenderer::GetLayer()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getlayer)")
    ADD_CLASS_METHOD(SetPreserveDepthBuffer,"void vtkRenderer::SetPreserveDepthBuffer(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setpreservedepthbuffer)")
    ADD_CLASS_METHOD(GetPreserveDepthBuffer,"int vtkRenderer::GetPreserveDepthBuffer()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getpreservedepthbuffer)")
    ADD_CLASS_METHOD(PreserveDepthBufferOn,"void vtkRenderer::PreserveDepthBufferOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#preservedepthbufferon)")
    ADD_CLASS_METHOD(PreserveDepthBufferOff,"void vtkRenderer::PreserveDepthBufferOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#preservedepthbufferoff)")
    ADD_CLASS_METHOD(Transparent,"int vtkRenderer::Transparent()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#transparent)")
    ADD_CLASS_METHOD(WorldToView_1,"void vtkRenderer::WorldToView()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#worldtoview)")
    ADD_CLASS_METHOD(ViewToWorld_1,"void vtkRenderer::ViewToWorld()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#viewtoworld)")
    ADD_CLASS_METHOD(ViewToWorld,"vtkRenderer::ViewToWorld()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#viewtoworld)")
    ADD_CLASS_METHOD(ViewToWorld_2,"void vtkRenderer::ViewToWorld(double & wx, double & wy, double & wz)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#viewtoworld)")
    ADD_CLASS_METHOD(WorldToView,"vtkRenderer::WorldToView()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#worldtoview)")
    ADD_CLASS_METHOD(WorldToView_2,"void vtkRenderer::WorldToView(double & wx, double & wy, double & wz)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#worldtoview)")
    ADD_CLASS_METHOD(GetZ,"double vtkRenderer::GetZ(int x, int y)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getz)")
    ADD_CLASS_METHOD(GetMTime,"long unsigned int vtkRenderer::GetMTime()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getmtime)")
    ADD_CLASS_METHOD(GetLastRenderTimeInSeconds,"double vtkRenderer::GetLastRenderTimeInSeconds()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getlastrendertimeinseconds)")
    ADD_CLASS_METHOD(GetNumberOfPropsRendered,"int vtkRenderer::GetNumberOfPropsRendered()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getnumberofpropsrendered)")
/* The following types are missing: vtkAssemblyPath
    ADD_CLASS_METHOD(PickProp_1,"vtkAssemblyPath * vtkRenderer::PickProp(double selectionX, double selectionY)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#pickprop)")
*/
    ADD_CLASS_METHOD(PickProp,"vtkRenderer::PickProp()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#pickprop)")
/* The following types are missing: vtkAssemblyPath
    ADD_CLASS_METHOD(PickProp_2,"vtkAssemblyPath * vtkRenderer::PickProp(double selectionX1, double selectionY1, double selectionX2, double selectionY2)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#pickprop)")
*/
    ADD_CLASS_METHOD(StereoMidpoint,"void vtkRenderer::StereoMidpoint()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#stereomidpoint)")
    ADD_CLASS_METHOD(GetTiledAspectRatio,"double vtkRenderer::GetTiledAspectRatio()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#gettiledaspectratio)")
    ADD_CLASS_METHOD(IsActiveCameraCreated,"int vtkRenderer::IsActiveCameraCreated()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#isactivecameracreated)")
    ADD_CLASS_METHOD(SetUseDepthPeeling,"void vtkRenderer::SetUseDepthPeeling(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setusedepthpeeling)")
    ADD_CLASS_METHOD(GetUseDepthPeeling,"int vtkRenderer::GetUseDepthPeeling()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getusedepthpeeling)")
    ADD_CLASS_METHOD(UseDepthPeelingOn,"void vtkRenderer::UseDepthPeelingOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#usedepthpeelingon)")
    ADD_CLASS_METHOD(UseDepthPeelingOff,"void vtkRenderer::UseDepthPeelingOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#usedepthpeelingoff)")
    ADD_CLASS_METHOD(SetOcclusionRatio,"void vtkRenderer::SetOcclusionRatio(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setocclusionratio)")
    ADD_CLASS_METHOD(GetOcclusionRatioMinValue,"double vtkRenderer::GetOcclusionRatioMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getocclusionratiominvalue)")
    ADD_CLASS_METHOD(GetOcclusionRatioMaxValue,"double vtkRenderer::GetOcclusionRatioMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getocclusionratiomaxvalue)")
    ADD_CLASS_METHOD(GetOcclusionRatio,"double vtkRenderer::GetOcclusionRatio()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getocclusionratio)")
    ADD_CLASS_METHOD(SetMaximumNumberOfPeels,"void vtkRenderer::SetMaximumNumberOfPeels(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setmaximumnumberofpeels)")
    ADD_CLASS_METHOD(GetMaximumNumberOfPeels,"int vtkRenderer::GetMaximumNumberOfPeels()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getmaximumnumberofpeels)")
    ADD_CLASS_METHOD(GetLastRenderingUsedDepthPeeling,"int vtkRenderer::GetLastRenderingUsedDepthPeeling()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getlastrenderinguseddepthpeeling)")
/* The following types are missing: vtkRendererDelegate
    ADD_CLASS_METHOD(SetDelegate,"void vtkRenderer::SetDelegate(vtkRendererDelegate * d)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setdelegate)")
*/
/* The following types are missing: vtkRendererDelegate
    ADD_CLASS_METHOD(GetDelegate,"vtkRendererDelegate * vtkRenderer::GetDelegate()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getdelegate)")
*/
/* The following types are missing: vtkRenderPass
    ADD_CLASS_METHOD(SetPass,"void vtkRenderer::SetPass(vtkRenderPass * p)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setpass)")
*/
/* The following types are missing: vtkRenderPass
    ADD_CLASS_METHOD(GetPass,"vtkRenderPass * vtkRenderer::GetPass()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getpass)")
*/
/* The following types are missing: vtkHardwareSelector
    ADD_CLASS_METHOD(GetSelector,"vtkHardwareSelector * vtkRenderer::GetSelector()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getselector)")
*/
/* The following types are missing: vtkTexture
    ADD_CLASS_METHOD(SetBackgroundTexture,"void vtkRenderer::SetBackgroundTexture(vtkTexture * param0)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#setbackgroundtexture)")
*/
/* The following types are missing: vtkTexture
    ADD_CLASS_METHOD(GetBackgroundTexture,"vtkTexture * vtkRenderer::GetBackgroundTexture()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#getbackgroundtexture)")
*/
    ADD_CLASS_METHOD(SetTexturedBackground,"void vtkRenderer::SetTexturedBackground(bool _arg)  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#settexturedbackground)")
    ADD_CLASS_METHOD(GetTexturedBackground,"bool vtkRenderer::GetTexturedBackground()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#gettexturedbackground)")
    ADD_CLASS_METHOD(TexturedBackgroundOn,"void vtkRenderer::TexturedBackgroundOn()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#texturedbackgroundon)")
    ADD_CLASS_METHOD(TexturedBackgroundOff,"void vtkRenderer::TexturedBackgroundOff()  (http://docs.wxwidgets.org/stable/wx_vtkrenderer.html#texturedbackgroundoff)")





    void AddMethods(WrapClass<vtkRenderer>::ptr this_ptr );

};


#endif // _wrap_vtkRenderer_h
