/**
 * C++ Interface: wrap_vtkVolumeRayCastCompositeFunction
 *
 * Description: wrapping vtkVolumeRayCastCompositeFunction
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkVolumeRayCastCompositeFunction_h_
#define _wrap_vtkVolumeRayCastCompositeFunction_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkVolumeRayCastCompositeFunction.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkVolumeRayCastFunction.h"


#ifndef vtkVolumeRayCastCompositeFunction_declared
  #define vtkVolumeRayCastCompositeFunction_declared
  AMI_DECLARE_TYPE(vtkVolumeRayCastCompositeFunction);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkVolumeRayCastCompositeFunction : public WrapClass<vtkVolumeRayCastCompositeFunction>
    , public   WrapClass_vtkVolumeRayCastFunction
{
  DEFINE_CLASS(WrapClass_vtkVolumeRayCastCompositeFunction);

  protected:
    typedef WrapClass<vtkVolumeRayCastCompositeFunction>::ptr _parentclass_ptr;
    typedef vtkVolumeRayCastCompositeFunction ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkVolumeRayCastCompositeFunction>& GetObj() const { return WrapClass<vtkVolumeRayCastCompositeFunction>::GetObj(); }

    /// Constructor
    WrapClass_vtkVolumeRayCastCompositeFunction(boost::shared_ptr<vtkVolumeRayCastCompositeFunction > si): 
    WrapClass<vtkVolumeRayCastCompositeFunction>(si)
    , WrapClass_vtkVolumeRayCastFunction(si)
    {}

    /// Destructor
    ~WrapClass_vtkVolumeRayCastCompositeFunction()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkVolumeRayCastCompositeFunction*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkVolumeRayCastCompositeFunction * vtkVolumeRayCastCompositeFunction::New() (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastcompositefunction.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkVolumeRayCastCompositeFunction::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastcompositefunction.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkVolumeRayCastCompositeFunction * vtkVolumeRayCastCompositeFunction::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastcompositefunction.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkVolumeRayCastCompositeFunction::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastcompositefunction.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkVolumeRayCastCompositeFunction * vtkVolumeRayCastCompositeFunction::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastcompositefunction.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkVolumeRayCastCompositeFunction::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastcompositefunction.html#printself)")
*/
    ADD_CLASS_METHOD(SetCompositeMethod,"void vtkVolumeRayCastCompositeFunction::SetCompositeMethod(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastcompositefunction.html#setcompositemethod)")
    ADD_CLASS_METHOD(GetCompositeMethodMinValue,"int vtkVolumeRayCastCompositeFunction::GetCompositeMethodMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastcompositefunction.html#getcompositemethodminvalue)")
    ADD_CLASS_METHOD(GetCompositeMethodMaxValue,"int vtkVolumeRayCastCompositeFunction::GetCompositeMethodMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastcompositefunction.html#getcompositemethodmaxvalue)")
    ADD_CLASS_METHOD(GetCompositeMethod,"int vtkVolumeRayCastCompositeFunction::GetCompositeMethod()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastcompositefunction.html#getcompositemethod)")
    ADD_CLASS_METHOD(SetCompositeMethodToInterpolateFirst,"void vtkVolumeRayCastCompositeFunction::SetCompositeMethodToInterpolateFirst()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastcompositefunction.html#setcompositemethodtointerpolatefirst)")
    ADD_CLASS_METHOD(SetCompositeMethodToClassifyFirst,"void vtkVolumeRayCastCompositeFunction::SetCompositeMethodToClassifyFirst()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastcompositefunction.html#setcompositemethodtoclassifyfirst)")
    ADD_CLASS_METHOD(GetCompositeMethodAsString,"char const * vtkVolumeRayCastCompositeFunction::GetCompositeMethodAsString()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastcompositefunction.html#getcompositemethodasstring)")
    ADD_CLASS_METHOD(CastRay,"void vtkVolumeRayCastCompositeFunction::CastRay(vtkVolumeRayCastDynamicInfo * dynamicInfo, vtkVolumeRayCastStaticInfo * staticInfo)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastcompositefunction.html#castray)")
    ADD_CLASS_METHOD(GetZeroOpacityThreshold,"float vtkVolumeRayCastCompositeFunction::GetZeroOpacityThreshold(vtkVolume * vol)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastcompositefunction.html#getzeroopacitythreshold)")





    void AddMethods(WrapClass<vtkVolumeRayCastCompositeFunction>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkVolumeRayCastCompositeFunction_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkVolumeRayCastCompositeFunction_h
