/**
 * C++ Interface: wrap_vtkObject
 *
 * Description: wrapping vtkObject
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkObject_h_
#define _wrap_vtkObject_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObjectBase.h"



AMI_DECLARE_TYPE(vtkObject);

// TODO: check for inheritence ...
class WrapClass_vtkObject : public WrapClass<vtkObject>
    , public   WrapClass_vtkObjectBase
{
  DEFINE_CLASS(WrapClass_vtkObject);

  protected:
    typedef WrapClass<vtkObject>::ptr _parentclass_ptr;
    typedef vtkObject ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkObject>& GetObj() const { return WrapClass<vtkObject>::GetObj(); }

    /// Constructor
    WrapClass_vtkObject(boost::shared_ptr<vtkObject > si): 
    WrapClass<vtkObject>(si)
    , WrapClass_vtkObjectBase(si)
    {}

    /// Destructor
    ~WrapClass_vtkObject()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkObject*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkObject::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkobject.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkObject * vtkObject::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkobject.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(New,"vtkObject * vtkObject::New() (http://docs.wxwidgets.org/stable/wx_vtkobject.html#new).");
    ADD_CLASS_STATICMETHOD(BreakOnError,"void vtkObject::BreakOnError() (http://docs.wxwidgets.org/stable/wx_vtkobject.html#breakonerror).");
    ADD_CLASS_STATICMETHOD(SetGlobalWarningDisplay,"void vtkObject::SetGlobalWarningDisplay(int val) (http://docs.wxwidgets.org/stable/wx_vtkobject.html#setglobalwarningdisplay).");
    ADD_CLASS_STATICMETHOD(GlobalWarningDisplayOn,"void vtkObject::GlobalWarningDisplayOn() (http://docs.wxwidgets.org/stable/wx_vtkobject.html#globalwarningdisplayon).");
    ADD_CLASS_STATICMETHOD(GlobalWarningDisplayOff,"void vtkObject::GlobalWarningDisplayOff() (http://docs.wxwidgets.org/stable/wx_vtkobject.html#globalwarningdisplayoff).");
    ADD_CLASS_STATICMETHOD(GetGlobalWarningDisplay,"int vtkObject::GetGlobalWarningDisplay() (http://docs.wxwidgets.org/stable/wx_vtkobject.html#getglobalwarningdisplay).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkObject::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkObject * vtkObject::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#newinstance)")
    ADD_CLASS_METHOD(DebugOn,"void vtkObject::DebugOn()  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#debugon)")
    ADD_CLASS_METHOD(DebugOff,"void vtkObject::DebugOff()  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#debugoff)")
    ADD_CLASS_METHOD(GetDebug,"unsigned char vtkObject::GetDebug()  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#getdebug)")
    ADD_CLASS_METHOD(SetDebug,"void vtkObject::SetDebug(unsigned char debugFlag)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#setdebug)")
    ADD_CLASS_METHOD(Modified,"void vtkObject::Modified()  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#modified)")
    ADD_CLASS_METHOD(GetMTime,"long unsigned int vtkObject::GetMTime()  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#getmtime)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkObject::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#printself)")
*/
    ADD_CLASS_METHOD(AddObserver_1,"long unsigned int vtkObject::AddObserver(long unsigned int event, vtkCommand * param1, float priority = 0.0f)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#addobserver)")
    ADD_CLASS_METHOD(AddObserver,"vtkObject::AddObserver()  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#addobserver)")
    ADD_CLASS_METHOD(AddObserver_2,"long unsigned int vtkObject::AddObserver(char const * event, vtkCommand * param1, float priority = 0.0f)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#addobserver)")
    ADD_CLASS_METHOD(GetCommand,"vtkCommand * vtkObject::GetCommand(long unsigned int tag)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#getcommand)")
    ADD_CLASS_METHOD(RemoveObserver_1,"void vtkObject::RemoveObserver(vtkCommand * param0)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#removeobserver)")
    ADD_CLASS_METHOD(RemoveObservers_1,"void vtkObject::RemoveObservers(long unsigned int event, vtkCommand * param1)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#removeobservers)")
    ADD_CLASS_METHOD(RemoveObservers,"vtkObject::RemoveObservers()  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#removeobservers)")
    ADD_CLASS_METHOD(RemoveObservers_2,"void vtkObject::RemoveObservers(char const * event, vtkCommand * param1)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#removeobservers)")
    ADD_CLASS_METHOD(HasObserver_1,"int vtkObject::HasObserver(long unsigned int event, vtkCommand * param1)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#hasobserver)")
    ADD_CLASS_METHOD(HasObserver,"vtkObject::HasObserver()  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#hasobserver)")
    ADD_CLASS_METHOD(HasObserver_2,"int vtkObject::HasObserver(char const * event, vtkCommand * param1)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#hasobserver)")
    ADD_CLASS_METHOD(RemoveObserver,"vtkObject::RemoveObserver()  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#removeobserver)")
    ADD_CLASS_METHOD(RemoveObserver_2,"void vtkObject::RemoveObserver(long unsigned int tag)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#removeobserver)")
    ADD_CLASS_METHOD(RemoveObservers_3,"void vtkObject::RemoveObservers(long unsigned int event)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#removeobservers)")
    ADD_CLASS_METHOD(RemoveObservers_4,"void vtkObject::RemoveObservers(char const * event)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#removeobservers)")
    ADD_CLASS_METHOD(RemoveAllObservers,"void vtkObject::RemoveAllObservers()  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#removeallobservers)")
    ADD_CLASS_METHOD(HasObserver_3,"int vtkObject::HasObserver(long unsigned int event)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#hasobserver)")
    ADD_CLASS_METHOD(HasObserver_4,"int vtkObject::HasObserver(char const * event)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#hasobserver)")
/* The following types are missing: void
    ADD_CLASS_METHOD(InvokeEvent_1,"int vtkObject::InvokeEvent(long unsigned int event, void * callData)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#invokeevent)")
*/
    ADD_CLASS_METHOD(InvokeEvent,"vtkObject::InvokeEvent()  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#invokeevent)")
/* The following types are missing: void
    ADD_CLASS_METHOD(InvokeEvent_2,"int vtkObject::InvokeEvent(char const * event, void * callData)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#invokeevent)")
*/
    ADD_CLASS_METHOD(InvokeEvent_3,"int vtkObject::InvokeEvent(long unsigned int event)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#invokeevent)")
    ADD_CLASS_METHOD(InvokeEvent_4,"int vtkObject::InvokeEvent(char const * event)  (http://docs.wxwidgets.org/stable/wx_vtkobject.html#invokeevent)")





    void AddMethods(WrapClass<vtkObject>::ptr this_ptr );

};


#endif // _wrap_vtkObject_h
