/**
 * C++ Interface: wrap_vtkInteractorStyleTrackballCamera
 *
 * Description: wrapping vtkInteractorStyleTrackballCamera
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkInteractorStyleTrackballCamera_h_
#define _wrap_vtkInteractorStyleTrackballCamera_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkInteractorStyleTrackballCamera.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkInteractorStyle.h"



AMI_DECLARE_TYPE(vtkInteractorStyleTrackballCamera);

// TODO: check for inheritence ...
class WrapClass_vtkInteractorStyleTrackballCamera : public WrapClass<vtkInteractorStyleTrackballCamera>
    , public   WrapClass_vtkInteractorStyle
{
  DEFINE_CLASS(WrapClass_vtkInteractorStyleTrackballCamera);

  protected:
    typedef WrapClass<vtkInteractorStyleTrackballCamera>::ptr _parentclass_ptr;
    typedef vtkInteractorStyleTrackballCamera ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkInteractorStyleTrackballCamera>& GetObj() const { return WrapClass<vtkInteractorStyleTrackballCamera>::GetObj(); }

    /// Constructor
    WrapClass_vtkInteractorStyleTrackballCamera(boost::shared_ptr<vtkInteractorStyleTrackballCamera > si): 
    WrapClass<vtkInteractorStyleTrackballCamera>(si)
    , WrapClass_vtkInteractorStyle(si)
    {}

    /// Destructor
    ~WrapClass_vtkInteractorStyleTrackballCamera()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkInteractorStyleTrackballCamera*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkInteractorStyleTrackballCamera * vtkInteractorStyleTrackballCamera::New() (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkInteractorStyleTrackballCamera::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkInteractorStyleTrackballCamera * vtkInteractorStyleTrackballCamera::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkInteractorStyleTrackballCamera::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkInteractorStyleTrackballCamera * vtkInteractorStyleTrackballCamera::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkInteractorStyleTrackballCamera::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#printself)")
*/
    ADD_CLASS_METHOD(OnMouseMove,"void vtkInteractorStyleTrackballCamera::OnMouseMove()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#onmousemove)")
    ADD_CLASS_METHOD(OnLeftButtonDown,"void vtkInteractorStyleTrackballCamera::OnLeftButtonDown()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#onleftbuttondown)")
    ADD_CLASS_METHOD(OnLeftButtonUp,"void vtkInteractorStyleTrackballCamera::OnLeftButtonUp()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#onleftbuttonup)")
    ADD_CLASS_METHOD(OnMiddleButtonDown,"void vtkInteractorStyleTrackballCamera::OnMiddleButtonDown()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#onmiddlebuttondown)")
    ADD_CLASS_METHOD(OnMiddleButtonUp,"void vtkInteractorStyleTrackballCamera::OnMiddleButtonUp()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#onmiddlebuttonup)")
    ADD_CLASS_METHOD(OnRightButtonDown,"void vtkInteractorStyleTrackballCamera::OnRightButtonDown()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#onrightbuttondown)")
    ADD_CLASS_METHOD(OnRightButtonUp,"void vtkInteractorStyleTrackballCamera::OnRightButtonUp()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#onrightbuttonup)")
    ADD_CLASS_METHOD(OnMouseWheelForward,"void vtkInteractorStyleTrackballCamera::OnMouseWheelForward()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#onmousewheelforward)")
    ADD_CLASS_METHOD(OnMouseWheelBackward,"void vtkInteractorStyleTrackballCamera::OnMouseWheelBackward()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#onmousewheelbackward)")
    ADD_CLASS_METHOD(Rotate,"void vtkInteractorStyleTrackballCamera::Rotate()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#rotate)")
    ADD_CLASS_METHOD(Spin,"void vtkInteractorStyleTrackballCamera::Spin()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#spin)")
    ADD_CLASS_METHOD(Pan,"void vtkInteractorStyleTrackballCamera::Pan()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#pan)")
    ADD_CLASS_METHOD(Dolly,"void vtkInteractorStyleTrackballCamera::Dolly()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#dolly)")
    ADD_CLASS_METHOD(SetMotionFactor,"void vtkInteractorStyleTrackballCamera::SetMotionFactor(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#setmotionfactor)")
    ADD_CLASS_METHOD(GetMotionFactor,"double vtkInteractorStyleTrackballCamera::GetMotionFactor()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackballcamera.html#getmotionfactor)")





    void AddMethods(WrapClass<vtkInteractorStyleTrackballCamera>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkInteractorStyleTrackballCamera_h
