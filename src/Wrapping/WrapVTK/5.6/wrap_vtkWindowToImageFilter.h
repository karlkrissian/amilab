/**
 * C++ Interface: wrap_vtkWindowToImageFilter
 *
 * Description: wrapping vtkWindowToImageFilter
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkWindowToImageFilter_h_
#define _wrap_vtkWindowToImageFilter_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkWindowToImageFilter.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkAlgorithm.h"


#ifndef vtkWindowToImageFilter_declared
  #define vtkWindowToImageFilter_declared
  AMI_DECLARE_TYPE(vtkWindowToImageFilter);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkWindowToImageFilter : public WrapClass<vtkWindowToImageFilter>
    , public   WrapClass_vtkAlgorithm
{
  DEFINE_CLASS(WrapClass_vtkWindowToImageFilter);

  protected:
    typedef WrapClass<vtkWindowToImageFilter>::ptr _parentclass_ptr;
    typedef vtkWindowToImageFilter ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkWindowToImageFilter>& GetObj() const { return WrapClass<vtkWindowToImageFilter>::GetObj(); }

    /// Constructor
    WrapClass_vtkWindowToImageFilter(boost::shared_ptr<vtkWindowToImageFilter > si): 
    WrapClass<vtkWindowToImageFilter>(si)
    , WrapClass_vtkAlgorithm(si)
    {}

    /// Destructor
    ~WrapClass_vtkWindowToImageFilter()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkWindowToImageFilter*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkWindowToImageFilter * vtkWindowToImageFilter::New() (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkWindowToImageFilter::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkWindowToImageFilter * vtkWindowToImageFilter::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkWindowToImageFilter::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkWindowToImageFilter * vtkWindowToImageFilter::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkWindowToImageFilter::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#printself)")
*/
    ADD_CLASS_METHOD(SetInput,"void vtkWindowToImageFilter::SetInput(vtkWindow * input)  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#setinput)")
    ADD_CLASS_METHOD(GetInput,"vtkWindow * vtkWindowToImageFilter::GetInput()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#getinput)")
    ADD_CLASS_METHOD(SetMagnification,"void vtkWindowToImageFilter::SetMagnification(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#setmagnification)")
    ADD_CLASS_METHOD(GetMagnificationMinValue,"int vtkWindowToImageFilter::GetMagnificationMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#getmagnificationminvalue)")
    ADD_CLASS_METHOD(GetMagnificationMaxValue,"int vtkWindowToImageFilter::GetMagnificationMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#getmagnificationmaxvalue)")
    ADD_CLASS_METHOD(GetMagnification,"int vtkWindowToImageFilter::GetMagnification()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#getmagnification)")
    ADD_CLASS_METHOD(ReadFrontBufferOn,"void vtkWindowToImageFilter::ReadFrontBufferOn()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#readfrontbufferon)")
    ADD_CLASS_METHOD(ReadFrontBufferOff,"void vtkWindowToImageFilter::ReadFrontBufferOff()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#readfrontbufferoff)")
    ADD_CLASS_METHOD(GetReadFrontBuffer,"int vtkWindowToImageFilter::GetReadFrontBuffer()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#getreadfrontbuffer)")
    ADD_CLASS_METHOD(SetReadFrontBuffer,"void vtkWindowToImageFilter::SetReadFrontBuffer(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#setreadfrontbuffer)")
    ADD_CLASS_METHOD(ShouldRerenderOn,"void vtkWindowToImageFilter::ShouldRerenderOn()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#shouldrerenderon)")
    ADD_CLASS_METHOD(ShouldRerenderOff,"void vtkWindowToImageFilter::ShouldRerenderOff()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#shouldrerenderoff)")
    ADD_CLASS_METHOD(SetShouldRerender,"void vtkWindowToImageFilter::SetShouldRerender(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#setshouldrerender)")
    ADD_CLASS_METHOD(GetShouldRerender,"int vtkWindowToImageFilter::GetShouldRerender()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#getshouldrerender)")
    ADD_CLASS_METHOD(SetViewport_1,"void vtkWindowToImageFilter::SetViewport(double _arg1, double _arg2, double _arg3, double _arg4)  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#setviewport)")
    ADD_CLASS_METHOD(SetViewport,"vtkWindowToImageFilter::SetViewport()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#setviewport)")
    ADD_CLASS_METHOD(SetViewport_2,"void vtkWindowToImageFilter::SetViewport(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#setviewport)")
    ADD_CLASS_METHOD(GetViewport_1,"double * vtkWindowToImageFilter::GetViewport()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#getviewport)")
    ADD_CLASS_METHOD(GetViewport,"vtkWindowToImageFilter::GetViewport()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#getviewport)")
    ADD_CLASS_METHOD(GetViewport_2,"void vtkWindowToImageFilter::GetViewport(double * data)  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#getviewport)")
    ADD_CLASS_METHOD(SetInputBufferType,"void vtkWindowToImageFilter::SetInputBufferType(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#setinputbuffertype)")
    ADD_CLASS_METHOD(GetInputBufferType,"int vtkWindowToImageFilter::GetInputBufferType()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#getinputbuffertype)")
    ADD_CLASS_METHOD(SetInputBufferTypeToRGB,"void vtkWindowToImageFilter::SetInputBufferTypeToRGB()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#setinputbuffertypetorgb)")
    ADD_CLASS_METHOD(SetInputBufferTypeToRGBA,"void vtkWindowToImageFilter::SetInputBufferTypeToRGBA()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#setinputbuffertypetorgba)")
    ADD_CLASS_METHOD(SetInputBufferTypeToZBuffer,"void vtkWindowToImageFilter::SetInputBufferTypeToZBuffer()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#setinputbuffertypetozbuffer)")
    ADD_CLASS_METHOD(GetOutput,"vtkImageData * vtkWindowToImageFilter::GetOutput()  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#getoutput)")
/* The following types are missing: vtkInformation, vtkInformationVector, vtkInformationVector
    ADD_CLASS_METHOD(ProcessRequest,"int vtkWindowToImageFilter::ProcessRequest(vtkInformation * param0, vtkInformationVector * * param1, vtkInformationVector * param2)  (http://docs.wxwidgets.org/stable/wx_vtkwindowtoimagefilter.html#processrequest)")
*/





    void AddMethods(WrapClass<vtkWindowToImageFilter>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkWindowToImageFilter_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkWindowToImageFilter_h
