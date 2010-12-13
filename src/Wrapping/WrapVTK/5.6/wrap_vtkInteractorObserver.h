/**
 * C++ Interface: wrap_vtkInteractorObserver
 *
 * Description: wrapping vtkInteractorObserver
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkInteractorObserver_h_
#define _wrap_vtkInteractorObserver_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkInteractorObserver.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"


#ifndef vtkInteractorObserver_declared
  #define vtkInteractorObserver_declared
  AMI_DECLARE_TYPE(vtkInteractorObserver);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkInteractorObserver : public WrapClass<vtkInteractorObserver>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkInteractorObserver);

  protected:
    typedef WrapClass<vtkInteractorObserver>::ptr _parentclass_ptr;
    typedef vtkInteractorObserver ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkInteractorObserver>& GetObj() const { return WrapClass<vtkInteractorObserver>::GetObj(); }

    /// Constructor
    WrapClass_vtkInteractorObserver(boost::shared_ptr<vtkInteractorObserver > si): 
    WrapClass<vtkInteractorObserver>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkInteractorObserver()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkInteractorObserver*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkInteractorObserver::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkInteractorObserver * vtkInteractorObserver::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(ComputeDisplayToWorld,"void vtkInteractorObserver::ComputeDisplayToWorld(vtkRenderer * ren, double x, double y, double z, double * worldPt) (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#computedisplaytoworld).");
    ADD_CLASS_STATICMETHOD(ComputeWorldToDisplay,"void vtkInteractorObserver::ComputeWorldToDisplay(vtkRenderer * ren, double x, double y, double z, double * displayPt) (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#computeworldtodisplay).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkInteractorObserver::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkInteractorObserver * vtkInteractorObserver::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkInteractorObserver::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#printself)")
*/
    ADD_CLASS_METHOD(SetEnabled,"void vtkInteractorObserver::SetEnabled(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#setenabled)")
    ADD_CLASS_METHOD(GetEnabled,"int vtkInteractorObserver::GetEnabled()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#getenabled)")
    ADD_CLASS_METHOD(EnabledOn,"void vtkInteractorObserver::EnabledOn()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#enabledon)")
    ADD_CLASS_METHOD(EnabledOff,"void vtkInteractorObserver::EnabledOff()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#enabledoff)")
    ADD_CLASS_METHOD(On,"void vtkInteractorObserver::On()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#on)")
    ADD_CLASS_METHOD(Off,"void vtkInteractorObserver::Off()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#off)")
    ADD_CLASS_METHOD(SetInteractor,"void vtkInteractorObserver::SetInteractor(vtkRenderWindowInteractor * iren)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#setinteractor)")
    ADD_CLASS_METHOD(GetInteractor,"vtkRenderWindowInteractor * vtkInteractorObserver::GetInteractor()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#getinteractor)")
    ADD_CLASS_METHOD(SetPriority,"void vtkInteractorObserver::SetPriority(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#setpriority)")
    ADD_CLASS_METHOD(GetPriorityMinValue,"float vtkInteractorObserver::GetPriorityMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#getpriorityminvalue)")
    ADD_CLASS_METHOD(GetPriorityMaxValue,"float vtkInteractorObserver::GetPriorityMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#getprioritymaxvalue)")
    ADD_CLASS_METHOD(GetPriority,"float vtkInteractorObserver::GetPriority()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#getpriority)")
    ADD_CLASS_METHOD(SetKeyPressActivation,"void vtkInteractorObserver::SetKeyPressActivation(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#setkeypressactivation)")
    ADD_CLASS_METHOD(GetKeyPressActivation,"int vtkInteractorObserver::GetKeyPressActivation()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#getkeypressactivation)")
    ADD_CLASS_METHOD(KeyPressActivationOn,"void vtkInteractorObserver::KeyPressActivationOn()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#keypressactivationon)")
    ADD_CLASS_METHOD(KeyPressActivationOff,"void vtkInteractorObserver::KeyPressActivationOff()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#keypressactivationoff)")
    ADD_CLASS_METHOD(SetKeyPressActivationValue,"void vtkInteractorObserver::SetKeyPressActivationValue(char _arg)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#setkeypressactivationvalue)")
    ADD_CLASS_METHOD(GetKeyPressActivationValue,"char vtkInteractorObserver::GetKeyPressActivationValue()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#getkeypressactivationvalue)")
    ADD_CLASS_METHOD(GetDefaultRenderer,"vtkRenderer * vtkInteractorObserver::GetDefaultRenderer()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#getdefaultrenderer)")
    ADD_CLASS_METHOD(SetDefaultRenderer,"void vtkInteractorObserver::SetDefaultRenderer(vtkRenderer * param0)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#setdefaultrenderer)")
    ADD_CLASS_METHOD(GetCurrentRenderer,"vtkRenderer * vtkInteractorObserver::GetCurrentRenderer()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#getcurrentrenderer)")
    ADD_CLASS_METHOD(SetCurrentRenderer,"void vtkInteractorObserver::SetCurrentRenderer(vtkRenderer * param0)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#setcurrentrenderer)")
    ADD_CLASS_METHOD(OnChar,"void vtkInteractorObserver::OnChar()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#onchar)")
    ADD_CLASS_METHOD(GrabFocus,"void vtkInteractorObserver::GrabFocus(vtkCommand * mouseEvents, vtkCommand * keypressEvents = 0l)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#grabfocus)")
    ADD_CLASS_METHOD(ReleaseFocus,"void vtkInteractorObserver::ReleaseFocus()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorobserver.html#releasefocus)")





    void AddMethods(WrapClass<vtkInteractorObserver>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkInteractorObserver_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkInteractorObserver_h
