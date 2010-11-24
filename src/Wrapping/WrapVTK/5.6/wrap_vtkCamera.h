/**
 * C++ Interface: wrap_vtkCamera
 *
 * Description: wrapping vtkCamera
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkCamera_h_
#define _wrap_vtkCamera_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"



AMI_DECLARE_TYPE(vtkCamera);

// TODO: check for inheritence ...
class WrapClass_vtkCamera : public WrapClass<vtkCamera>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkCamera);

  protected:
    typedef WrapClass<vtkCamera>::ptr _parentclass_ptr;
    typedef vtkCamera ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkCamera>& GetObj() const { return WrapClass<vtkCamera>::GetObj(); }

    /// Constructor
    WrapClass_vtkCamera(boost::shared_ptr<vtkCamera > si): 
    WrapClass<vtkCamera>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkCamera()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkCamera*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkCamera::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkCamera * vtkCamera::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(New,"vtkCamera * vtkCamera::New() (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#new).");



    // Standard methods
    
    // Adding standard methods
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkCamera::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#printself)")
*/
    ADD_CLASS_METHOD(IsA,"int vtkCamera::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkCamera * vtkCamera::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#newinstance)")
    ADD_CLASS_METHOD(SetPosition_1,"void vtkCamera::SetPosition(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setposition)")
    ADD_CLASS_METHOD(SetPosition,"vtkCamera::SetPosition()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setposition)")
    ADD_CLASS_METHOD(SetPosition_2,"void vtkCamera::SetPosition(double const * a)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setposition)")
    ADD_CLASS_METHOD(GetPosition_1,"double * vtkCamera::GetPosition()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getposition)")
    ADD_CLASS_METHOD(GetPosition,"vtkCamera::GetPosition()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getposition)")
    ADD_CLASS_METHOD(GetPosition_2,"void vtkCamera::GetPosition(double & _arg1, double & _arg2, double & _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getposition)")
    ADD_CLASS_METHOD(GetPosition_3,"void vtkCamera::GetPosition(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getposition)")
    ADD_CLASS_METHOD(SetFocalPoint_1,"void vtkCamera::SetFocalPoint(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setfocalpoint)")
    ADD_CLASS_METHOD(SetFocalPoint,"vtkCamera::SetFocalPoint()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setfocalpoint)")
    ADD_CLASS_METHOD(SetFocalPoint_2,"void vtkCamera::SetFocalPoint(double const * a)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setfocalpoint)")
    ADD_CLASS_METHOD(GetFocalPoint_1,"double * vtkCamera::GetFocalPoint()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getfocalpoint)")
    ADD_CLASS_METHOD(GetFocalPoint,"vtkCamera::GetFocalPoint()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getfocalpoint)")
    ADD_CLASS_METHOD(GetFocalPoint_2,"void vtkCamera::GetFocalPoint(double & _arg1, double & _arg2, double & _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getfocalpoint)")
    ADD_CLASS_METHOD(GetFocalPoint_3,"void vtkCamera::GetFocalPoint(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getfocalpoint)")
    ADD_CLASS_METHOD(SetViewUp_1,"void vtkCamera::SetViewUp(double vx, double vy, double vz)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setviewup)")
    ADD_CLASS_METHOD(SetViewUp,"vtkCamera::SetViewUp()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setviewup)")
    ADD_CLASS_METHOD(SetViewUp_2,"void vtkCamera::SetViewUp(double const * a)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setviewup)")
    ADD_CLASS_METHOD(GetViewUp_1,"double * vtkCamera::GetViewUp()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getviewup)")
    ADD_CLASS_METHOD(GetViewUp,"vtkCamera::GetViewUp()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getviewup)")
    ADD_CLASS_METHOD(GetViewUp_2,"void vtkCamera::GetViewUp(double & _arg1, double & _arg2, double & _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getviewup)")
    ADD_CLASS_METHOD(GetViewUp_3,"void vtkCamera::GetViewUp(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getviewup)")
    ADD_CLASS_METHOD(OrthogonalizeViewUp,"void vtkCamera::OrthogonalizeViewUp()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#orthogonalizeviewup)")
    ADD_CLASS_METHOD(SetDistance,"void vtkCamera::SetDistance(double param0)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setdistance)")
    ADD_CLASS_METHOD(GetDistance,"double vtkCamera::GetDistance()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getdistance)")
    ADD_CLASS_METHOD(GetDirectionOfProjection_1,"double * vtkCamera::GetDirectionOfProjection()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getdirectionofprojection)")
    ADD_CLASS_METHOD(GetDirectionOfProjection,"vtkCamera::GetDirectionOfProjection()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getdirectionofprojection)")
    ADD_CLASS_METHOD(GetDirectionOfProjection_2,"void vtkCamera::GetDirectionOfProjection(double & _arg1, double & _arg2, double & _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getdirectionofprojection)")
    ADD_CLASS_METHOD(GetDirectionOfProjection_3,"void vtkCamera::GetDirectionOfProjection(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getdirectionofprojection)")
    ADD_CLASS_METHOD(Dolly,"void vtkCamera::Dolly(double value)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#dolly)")
    ADD_CLASS_METHOD(SetRoll,"void vtkCamera::SetRoll(double angle)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setroll)")
    ADD_CLASS_METHOD(GetRoll,"double vtkCamera::GetRoll()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getroll)")
    ADD_CLASS_METHOD(Roll,"void vtkCamera::Roll(double angle)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#roll)")
    ADD_CLASS_METHOD(Azimuth,"void vtkCamera::Azimuth(double angle)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#azimuth)")
    ADD_CLASS_METHOD(Yaw,"void vtkCamera::Yaw(double angle)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#yaw)")
    ADD_CLASS_METHOD(Elevation,"void vtkCamera::Elevation(double angle)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#elevation)")
    ADD_CLASS_METHOD(Pitch,"void vtkCamera::Pitch(double angle)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#pitch)")
    ADD_CLASS_METHOD(SetParallelProjection,"void vtkCamera::SetParallelProjection(int flag)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setparallelprojection)")
    ADD_CLASS_METHOD(GetParallelProjection,"int vtkCamera::GetParallelProjection()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getparallelprojection)")
    ADD_CLASS_METHOD(ParallelProjectionOn,"void vtkCamera::ParallelProjectionOn()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#parallelprojectionon)")
    ADD_CLASS_METHOD(ParallelProjectionOff,"void vtkCamera::ParallelProjectionOff()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#parallelprojectionoff)")
    ADD_CLASS_METHOD(SetUseHorizontalViewAngle,"void vtkCamera::SetUseHorizontalViewAngle(int flag)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setusehorizontalviewangle)")
    ADD_CLASS_METHOD(GetUseHorizontalViewAngle,"int vtkCamera::GetUseHorizontalViewAngle()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getusehorizontalviewangle)")
    ADD_CLASS_METHOD(UseHorizontalViewAngleOn,"void vtkCamera::UseHorizontalViewAngleOn()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#usehorizontalviewangleon)")
    ADD_CLASS_METHOD(UseHorizontalViewAngleOff,"void vtkCamera::UseHorizontalViewAngleOff()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#usehorizontalviewangleoff)")
    ADD_CLASS_METHOD(SetViewAngle,"void vtkCamera::SetViewAngle(double angle)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setviewangle)")
    ADD_CLASS_METHOD(GetViewAngle,"double vtkCamera::GetViewAngle()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getviewangle)")
    ADD_CLASS_METHOD(SetParallelScale,"void vtkCamera::SetParallelScale(double scale)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setparallelscale)")
    ADD_CLASS_METHOD(GetParallelScale,"double vtkCamera::GetParallelScale()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getparallelscale)")
    ADD_CLASS_METHOD(Zoom,"void vtkCamera::Zoom(double factor)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#zoom)")
    ADD_CLASS_METHOD(SetClippingRange_1,"void vtkCamera::SetClippingRange(double dNear, double dFar)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setclippingrange)")
    ADD_CLASS_METHOD(SetClippingRange,"vtkCamera::SetClippingRange()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setclippingrange)")
    ADD_CLASS_METHOD(SetClippingRange_2,"void vtkCamera::SetClippingRange(double const * a)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setclippingrange)")
    ADD_CLASS_METHOD(GetClippingRange_1,"double * vtkCamera::GetClippingRange()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getclippingrange)")
    ADD_CLASS_METHOD(GetClippingRange,"vtkCamera::GetClippingRange()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getclippingrange)")
    ADD_CLASS_METHOD(GetClippingRange_2,"void vtkCamera::GetClippingRange(double & _arg1, double & _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getclippingrange)")
    ADD_CLASS_METHOD(GetClippingRange_3,"void vtkCamera::GetClippingRange(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getclippingrange)")
    ADD_CLASS_METHOD(SetThickness,"void vtkCamera::SetThickness(double param0)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setthickness)")
    ADD_CLASS_METHOD(GetThickness,"double vtkCamera::GetThickness()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getthickness)")
    ADD_CLASS_METHOD(SetWindowCenter,"void vtkCamera::SetWindowCenter(double x, double y)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setwindowcenter)")
    ADD_CLASS_METHOD(GetWindowCenter_1,"double * vtkCamera::GetWindowCenter()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getwindowcenter)")
    ADD_CLASS_METHOD(GetWindowCenter,"vtkCamera::GetWindowCenter()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getwindowcenter)")
    ADD_CLASS_METHOD(GetWindowCenter_2,"void vtkCamera::GetWindowCenter(double & _arg1, double & _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getwindowcenter)")
    ADD_CLASS_METHOD(GetWindowCenter_3,"void vtkCamera::GetWindowCenter(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getwindowcenter)")
    ADD_CLASS_METHOD(SetObliqueAngles,"void vtkCamera::SetObliqueAngles(double alpha, double beta)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setobliqueangles)")
/* The following types are missing: vtkTransform
    ADD_CLASS_METHOD(ApplyTransform,"void vtkCamera::ApplyTransform(vtkTransform * t)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#applytransform)")
*/
    ADD_CLASS_METHOD(GetViewPlaneNormal_1,"double * vtkCamera::GetViewPlaneNormal()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getviewplanenormal)")
    ADD_CLASS_METHOD(GetViewPlaneNormal,"vtkCamera::GetViewPlaneNormal()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getviewplanenormal)")
    ADD_CLASS_METHOD(GetViewPlaneNormal_2,"void vtkCamera::GetViewPlaneNormal(double & _arg1, double & _arg2, double & _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getviewplanenormal)")
    ADD_CLASS_METHOD(GetViewPlaneNormal_3,"void vtkCamera::GetViewPlaneNormal(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getviewplanenormal)")
    ADD_CLASS_METHOD(SetViewShear_1,"void vtkCamera::SetViewShear(double dxdz, double dydz, double center)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setviewshear)")
    ADD_CLASS_METHOD(SetViewShear,"vtkCamera::SetViewShear()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setviewshear)")
    ADD_CLASS_METHOD(SetViewShear_2,"void vtkCamera::SetViewShear(double * d)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setviewshear)")
    ADD_CLASS_METHOD(GetViewShear_1,"double * vtkCamera::GetViewShear()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getviewshear)")
    ADD_CLASS_METHOD(GetViewShear,"vtkCamera::GetViewShear()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getviewshear)")
    ADD_CLASS_METHOD(GetViewShear_2,"void vtkCamera::GetViewShear(double & _arg1, double & _arg2, double & _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getviewshear)")
    ADD_CLASS_METHOD(GetViewShear_3,"void vtkCamera::GetViewShear(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getviewshear)")
    ADD_CLASS_METHOD(SetEyeAngle,"void vtkCamera::SetEyeAngle(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#seteyeangle)")
    ADD_CLASS_METHOD(GetEyeAngle,"double vtkCamera::GetEyeAngle()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#geteyeangle)")
    ADD_CLASS_METHOD(SetFocalDisk,"void vtkCamera::SetFocalDisk(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setfocaldisk)")
    ADD_CLASS_METHOD(GetFocalDisk,"double vtkCamera::GetFocalDisk()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getfocaldisk)")
/* The following types are missing: vtkMatrix4x4
    ADD_CLASS_METHOD(GetViewTransformMatrix,"vtkMatrix4x4 * vtkCamera::GetViewTransformMatrix()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getviewtransformmatrix)")
*/
/* The following types are missing: vtkTransform
    ADD_CLASS_METHOD(GetViewTransformObject,"vtkTransform * vtkCamera::GetViewTransformObject()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getviewtransformobject)")
*/
/* The following types are missing: vtkMatrix4x4
    ADD_CLASS_METHOD(GetPerspectiveTransformMatrix,"vtkMatrix4x4 * vtkCamera::GetPerspectiveTransformMatrix(double aspect, double nearz, double farz)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getperspectivetransformmatrix)")
*/
/* The following types are missing: vtkMatrix4x4
    ADD_CLASS_METHOD(GetProjectionTransformMatrix,"vtkMatrix4x4 * vtkCamera::GetProjectionTransformMatrix(double aspect, double nearz, double farz)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getprojectiontransformmatrix)")
*/
/* The following types are missing: vtkPerspectiveTransform
    ADD_CLASS_METHOD(GetProjectionTransformObject,"vtkPerspectiveTransform * vtkCamera::GetProjectionTransformObject(double aspect, double nearz, double farz)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getprojectiontransformobject)")
*/
/* The following types are missing: vtkMatrix4x4
    ADD_CLASS_METHOD(GetCompositePerspectiveTransformMatrix,"vtkMatrix4x4 * vtkCamera::GetCompositePerspectiveTransformMatrix(double aspect, double nearz, double farz)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getcompositeperspectivetransformmatrix)")
*/
/* The following types are missing: vtkMatrix4x4
    ADD_CLASS_METHOD(GetCompositeProjectionTransformMatrix,"vtkMatrix4x4 * vtkCamera::GetCompositeProjectionTransformMatrix(double aspect, double nearz, double farz)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getcompositeprojectiontransformmatrix)")
*/
/* The following types are missing: vtkHomogeneousTransform
    ADD_CLASS_METHOD(SetUserViewTransform,"void vtkCamera::SetUserViewTransform(vtkHomogeneousTransform * transform)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setuserviewtransform)")
*/
/* The following types are missing: vtkHomogeneousTransform
    ADD_CLASS_METHOD(GetUserViewTransform,"vtkHomogeneousTransform * vtkCamera::GetUserViewTransform()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getuserviewtransform)")
*/
/* The following types are missing: vtkHomogeneousTransform
    ADD_CLASS_METHOD(SetUserTransform,"void vtkCamera::SetUserTransform(vtkHomogeneousTransform * transform)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setusertransform)")
*/
/* The following types are missing: vtkHomogeneousTransform
    ADD_CLASS_METHOD(GetUserTransform,"vtkHomogeneousTransform * vtkCamera::GetUserTransform()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getusertransform)")
*/
    ADD_CLASS_METHOD(Render,"void vtkCamera::Render(vtkRenderer * param0)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#render)")
    ADD_CLASS_METHOD(GetViewingRaysMTime,"long unsigned int vtkCamera::GetViewingRaysMTime()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getviewingraysmtime)")
    ADD_CLASS_METHOD(ViewingRaysModified,"void vtkCamera::ViewingRaysModified()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#viewingraysmodified)")
    ADD_CLASS_METHOD(GetFrustumPlanes,"void vtkCamera::GetFrustumPlanes(double aspect, double * planes)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getfrustumplanes)")
    ADD_CLASS_METHOD(GetOrientation,"double * vtkCamera::GetOrientation()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getorientation)")
    ADD_CLASS_METHOD(GetOrientationWXYZ,"double * vtkCamera::GetOrientationWXYZ()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getorientationwxyz)")
    ADD_CLASS_METHOD(SetViewPlaneNormal_1,"void vtkCamera::SetViewPlaneNormal(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setviewplanenormal)")
    ADD_CLASS_METHOD(SetViewPlaneNormal,"vtkCamera::SetViewPlaneNormal()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setviewplanenormal)")
    ADD_CLASS_METHOD(SetViewPlaneNormal_2,"void vtkCamera::SetViewPlaneNormal(double const * a)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setviewplanenormal)")
    ADD_CLASS_METHOD(ComputeViewPlaneNormal,"void vtkCamera::ComputeViewPlaneNormal()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#computeviewplanenormal)")
/* The following types are missing: vtkMatrix4x4
    ADD_CLASS_METHOD(GetCameraLightTransformMatrix,"vtkMatrix4x4 * vtkCamera::GetCameraLightTransformMatrix()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getcameralighttransformmatrix)")
*/
    ADD_CLASS_METHOD(UpdateViewport,"void vtkCamera::UpdateViewport(vtkRenderer * param0)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#updateviewport)")
    ADD_CLASS_METHOD(SetLeftEye,"void vtkCamera::SetLeftEye(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#setlefteye)")
    ADD_CLASS_METHOD(GetLeftEye,"int vtkCamera::GetLeftEye()  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#getlefteye)")
    ADD_CLASS_METHOD(ShallowCopy,"void vtkCamera::ShallowCopy(vtkCamera * source)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#shallowcopy)")
    ADD_CLASS_METHOD(DeepCopy,"void vtkCamera::DeepCopy(vtkCamera * source)  (http://docs.wxwidgets.org/stable/wx_vtkcamera.html#deepcopy)")





    void AddMethods(WrapClass<vtkCamera>::ptr this_ptr );

};


#endif // _wrap_vtkCamera_h
