/**
 * C++ Interface: wrap_vtkInteractorStyleSwitch
 *
 * Description: wrapping vtkInteractorStyleSwitch
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkInteractorStyleSwitch_h_
#define _wrap_vtkInteractorStyleSwitch_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkInteractorStyleSwitch.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkInteractorStyle.h"


#ifndef vtkInteractorStyleSwitch_declared
  #define vtkInteractorStyleSwitch_declared
  AMI_DECLARE_TYPE(vtkInteractorStyleSwitch);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkInteractorStyleSwitch : public WrapClass<vtkInteractorStyleSwitch>
    , public   WrapClass_vtkInteractorStyle
{
  DEFINE_CLASS(WrapClass_vtkInteractorStyleSwitch);

  protected:
    typedef WrapClass<vtkInteractorStyleSwitch>::ptr _parentclass_ptr;
    typedef vtkInteractorStyleSwitch ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkInteractorStyleSwitch>& GetObj() const { return WrapClass<vtkInteractorStyleSwitch>::GetObj(); }

    /// Constructor
    WrapClass_vtkInteractorStyleSwitch(boost::shared_ptr<vtkInteractorStyleSwitch > si): 
    WrapClass<vtkInteractorStyleSwitch>(si)
    , WrapClass_vtkInteractorStyle(si)
    {}

    /// Destructor
    ~WrapClass_vtkInteractorStyleSwitch()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkInteractorStyleSwitch*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkInteractorStyleSwitch * vtkInteractorStyleSwitch::New() (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleswitch.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkInteractorStyleSwitch::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleswitch.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkInteractorStyleSwitch * vtkInteractorStyleSwitch::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleswitch.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkInteractorStyleSwitch::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleswitch.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkInteractorStyleSwitch * vtkInteractorStyleSwitch::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleswitch.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkInteractorStyleSwitch::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleswitch.html#printself)")
*/
    ADD_CLASS_METHOD(SetInteractor,"void vtkInteractorStyleSwitch::SetInteractor(vtkRenderWindowInteractor * iren)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleswitch.html#setinteractor)")
    ADD_CLASS_METHOD(SetAutoAdjustCameraClippingRange,"void vtkInteractorStyleSwitch::SetAutoAdjustCameraClippingRange(int value)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleswitch.html#setautoadjustcameraclippingrange)")
    ADD_CLASS_METHOD(GetCurrentStyle,"vtkInteractorStyle * vtkInteractorStyleSwitch::GetCurrentStyle()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleswitch.html#getcurrentstyle)")
    ADD_CLASS_METHOD(SetCurrentStyleToJoystickActor,"void vtkInteractorStyleSwitch::SetCurrentStyleToJoystickActor()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleswitch.html#setcurrentstyletojoystickactor)")
    ADD_CLASS_METHOD(SetCurrentStyleToJoystickCamera,"void vtkInteractorStyleSwitch::SetCurrentStyleToJoystickCamera()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleswitch.html#setcurrentstyletojoystickcamera)")
    ADD_CLASS_METHOD(SetCurrentStyleToTrackballActor,"void vtkInteractorStyleSwitch::SetCurrentStyleToTrackballActor()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleswitch.html#setcurrentstyletotrackballactor)")
    ADD_CLASS_METHOD(SetCurrentStyleToTrackballCamera,"void vtkInteractorStyleSwitch::SetCurrentStyleToTrackballCamera()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleswitch.html#setcurrentstyletotrackballcamera)")
    ADD_CLASS_METHOD(OnChar,"void vtkInteractorStyleSwitch::OnChar()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleswitch.html#onchar)")
    ADD_CLASS_METHOD(SetDefaultRenderer,"void vtkInteractorStyleSwitch::SetDefaultRenderer(vtkRenderer * param0)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleswitch.html#setdefaultrenderer)")
    ADD_CLASS_METHOD(SetCurrentRenderer,"void vtkInteractorStyleSwitch::SetCurrentRenderer(vtkRenderer * param0)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleswitch.html#setcurrentrenderer)")





    void AddMethods(WrapClass<vtkInteractorStyleSwitch>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkInteractorStyleSwitch_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkInteractorStyleSwitch_h
