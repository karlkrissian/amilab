/**
 * C++ Interface: wrap_vtkOpenGLGPUVolumeRayCastMapper
 *
 * Description: wrapping vtkOpenGLGPUVolumeRayCastMapper
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkOpenGLGPUVolumeRayCastMapper_h_
#define _wrap_vtkOpenGLGPUVolumeRayCastMapper_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkOpenGLGPUVolumeRayCastMapper.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkGPUVolumeRayCastMapper.h"


#ifndef vtkOpenGLGPUVolumeRayCastMapper_declared
  #define vtkOpenGLGPUVolumeRayCastMapper_declared
  AMI_DECLARE_TYPE(vtkOpenGLGPUVolumeRayCastMapper);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkOpenGLGPUVolumeRayCastMapper : public WrapClass<vtkOpenGLGPUVolumeRayCastMapper>
    , public   WrapClass_vtkGPUVolumeRayCastMapper
{
  DEFINE_CLASS(WrapClass_vtkOpenGLGPUVolumeRayCastMapper);

  protected:
    typedef WrapClass<vtkOpenGLGPUVolumeRayCastMapper>::ptr _parentclass_ptr;
    typedef vtkOpenGLGPUVolumeRayCastMapper ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkOpenGLGPUVolumeRayCastMapper>& GetObj() const { return WrapClass<vtkOpenGLGPUVolumeRayCastMapper>::GetObj(); }

    /// Constructor
    WrapClass_vtkOpenGLGPUVolumeRayCastMapper(boost::shared_ptr<vtkOpenGLGPUVolumeRayCastMapper > si): 
    WrapClass<vtkOpenGLGPUVolumeRayCastMapper>(si)
    , WrapClass_vtkGPUVolumeRayCastMapper(si)
    {}

    /// Destructor
    ~WrapClass_vtkOpenGLGPUVolumeRayCastMapper()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkOpenGLGPUVolumeRayCastMapper*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkOpenGLGPUVolumeRayCastMapper * vtkOpenGLGPUVolumeRayCastMapper::New() (http://docs.wxwidgets.org/stable/wx_vtkopenglgpuvolumeraycastmapper.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkOpenGLGPUVolumeRayCastMapper::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkopenglgpuvolumeraycastmapper.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkOpenGLGPUVolumeRayCastMapper * vtkOpenGLGPUVolumeRayCastMapper::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkopenglgpuvolumeraycastmapper.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(OpenGLErrorMessage,"char const * vtkOpenGLGPUVolumeRayCastMapper::OpenGLErrorMessage(unsigned int errorCode) (http://docs.wxwidgets.org/stable/wx_vtkopenglgpuvolumeraycastmapper.html#openglerrormessage).");
    ADD_CLASS_STATICMETHOD(PrintError,"void vtkOpenGLGPUVolumeRayCastMapper::PrintError(char const * headerMessage) (http://docs.wxwidgets.org/stable/wx_vtkopenglgpuvolumeraycastmapper.html#printerror).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkOpenGLGPUVolumeRayCastMapper::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkopenglgpuvolumeraycastmapper.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkOpenGLGPUVolumeRayCastMapper * vtkOpenGLGPUVolumeRayCastMapper::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkopenglgpuvolumeraycastmapper.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkOpenGLGPUVolumeRayCastMapper::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkopenglgpuvolumeraycastmapper.html#printself)")
*/
    ADD_CLASS_METHOD(IsRenderSupported,"int vtkOpenGLGPUVolumeRayCastMapper::IsRenderSupported(vtkRenderWindow * window, vtkVolumeProperty * property)  (http://docs.wxwidgets.org/stable/wx_vtkopenglgpuvolumeraycastmapper.html#isrendersupported)")





    void AddMethods(WrapClass<vtkOpenGLGPUVolumeRayCastMapper>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkOpenGLGPUVolumeRayCastMapper_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkOpenGLGPUVolumeRayCastMapper_h
