/**
 * C++ Interface: wrap_vtkVolumeRayCastFunction
 *
 * Description: wrapping vtkVolumeRayCastFunction
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkVolumeRayCastFunction_h_
#define _wrap_vtkVolumeRayCastFunction_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkVolumeRayCastFunction.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"


#ifndef vtkVolumeRayCastFunction_declared
  #define vtkVolumeRayCastFunction_declared
  AMI_DECLARE_TYPE(vtkVolumeRayCastFunction);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkVolumeRayCastFunction : public WrapClass<vtkVolumeRayCastFunction>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkVolumeRayCastFunction);

  protected:
    typedef WrapClass<vtkVolumeRayCastFunction>::ptr _parentclass_ptr;
    typedef vtkVolumeRayCastFunction ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkVolumeRayCastFunction>& GetObj() const { return WrapClass<vtkVolumeRayCastFunction>::GetObj(); }

    /// Constructor
    WrapClass_vtkVolumeRayCastFunction(boost::shared_ptr<vtkVolumeRayCastFunction > si): 
    WrapClass<vtkVolumeRayCastFunction>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkVolumeRayCastFunction()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkVolumeRayCastFunction*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkVolumeRayCastFunction::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastfunction.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkVolumeRayCastFunction * vtkVolumeRayCastFunction::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastfunction.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkVolumeRayCastFunction::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastfunction.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkVolumeRayCastFunction * vtkVolumeRayCastFunction::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastfunction.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkVolumeRayCastFunction::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastfunction.html#printself)")
*/
    ADD_CLASS_METHOD(FunctionInitialize,"void vtkVolumeRayCastFunction::FunctionInitialize(vtkRenderer * ren, vtkVolume * vol, vtkVolumeRayCastStaticInfo * staticInfo)  (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastfunction.html#functioninitialize)")





    void AddMethods(WrapClass<vtkVolumeRayCastFunction>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkVolumeRayCastFunction_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkVolumeRayCastFunction_h
