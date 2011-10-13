/**
 * C++ Interface: wrap_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper
 *
 * Description: wrapping vtkAMILabOpenGLGPUMultiVolumeRayCastMapper
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper_h_
#define _wrap_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "/home/karl/projects/Sourceforge/amilab/trunk/Modules/vtkAmiVolRen/src/vtkAMILabOpenGLGPUMultiVolumeRayCastMapper.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkGPUVolumeRayCastMapper.h"


#ifndef vtkAMILabOpenGLGPUMultiVolumeRayCastMapper_declared
  #define vtkAMILabOpenGLGPUMultiVolumeRayCastMapper_declared
  AMI_DECLARE_TYPE(vtkAMILabOpenGLGPUMultiVolumeRayCastMapper);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper : public WrapClass<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper>
    , public   WrapClass_vtkGPUVolumeRayCastMapper
{
  DEFINE_CLASS(WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper);

  protected:
    typedef WrapClass<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper>::ptr _parentclass_ptr;
    typedef vtkAMILabOpenGLGPUMultiVolumeRayCastMapper ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper>& GetObj() const { return WrapClass<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper>::GetObj(); }

    /// Constructor
    WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper(boost::shared_ptr<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper > si): 
    WrapClass<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper>(si)
    , WrapClass_vtkGPUVolumeRayCastMapper(si)
    {}

    /// Destructor
    ~WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkAMILabOpenGLGPUMultiVolumeRayCastMapper*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkAMILabOpenGLGPUMultiVolumeRayCastMapper * vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::New() (http://docs.wxwidgets.org/stable/wx_vtkamilabopenglgpumultivolumeraycastmapper.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkamilabopenglgpumultivolumeraycastmapper.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkAMILabOpenGLGPUMultiVolumeRayCastMapper * vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkamilabopenglgpumultivolumeraycastmapper.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(OpenGLErrorMessage,"char const * vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::OpenGLErrorMessage(unsigned int errorCode) (http://docs.wxwidgets.org/stable/wx_vtkamilabopenglgpumultivolumeraycastmapper.html#openglerrormessage).");
    ADD_CLASS_STATICMETHOD(PrintError,"void vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::PrintError(char const * headerMessage) (http://docs.wxwidgets.org/stable/wx_vtkamilabopenglgpumultivolumeraycastmapper.html#printerror).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkamilabopenglgpumultivolumeraycastmapper.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkAMILabOpenGLGPUMultiVolumeRayCastMapper * vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkamilabopenglgpumultivolumeraycastmapper.html#newinstance)")
/* The following types are missing: std::ostream
    ADD_CLASS_METHOD(PrintSelf,"void vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::PrintSelf(std::ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkamilabopenglgpumultivolumeraycastmapper.html#printself)")
*/
    ADD_CLASS_METHOD(IsRenderSupported,"int vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::IsRenderSupported(vtkRenderWindow * window, vtkVolumeProperty * property)  (http://docs.wxwidgets.org/stable/wx_vtkamilabopenglgpumultivolumeraycastmapper.html#isrendersupported)")
    ADD_CLASS_METHOD(ReleaseGraphicsResources,"void vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::ReleaseGraphicsResources(vtkWindow * window)  (http://docs.wxwidgets.org/stable/wx_vtkamilabopenglgpumultivolumeraycastmapper.html#releasegraphicsresources)")





    void AddMethods(WrapClass<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkAMILabOpenGLGPUMultiVolumeRayCastMapper_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper_h
