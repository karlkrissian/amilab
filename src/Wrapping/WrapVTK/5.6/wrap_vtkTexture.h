/**
 * C++ Interface: wrap_vtkTexture
 *
 * Description: wrapping vtkTexture
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkTexture_h_
#define _wrap_vtkTexture_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkTexture.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkImageAlgorithm.h"


#ifndef vtkTexture_declared
  #define vtkTexture_declared
  AMI_DECLARE_TYPE(vtkTexture);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkTexture : public WrapClass<vtkTexture>
    , public   WrapClass_vtkImageAlgorithm
{
  DEFINE_CLASS(WrapClass_vtkTexture);

  protected:
    typedef WrapClass<vtkTexture>::ptr _parentclass_ptr;
    typedef vtkTexture ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkTexture>& GetObj() const { return WrapClass<vtkTexture>::GetObj(); }

    /// Constructor
    WrapClass_vtkTexture(boost::shared_ptr<vtkTexture > si): 
    WrapClass<vtkTexture>(si)
    , WrapClass_vtkImageAlgorithm(si)
    {}

    /// Destructor
    ~WrapClass_vtkTexture()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkTexture*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkTexture * vtkTexture::New() (http://docs.wxwidgets.org/stable/wx_vtktexture.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkTexture::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtktexture.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkTexture * vtkTexture::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtktexture.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkTexture::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkTexture * vtkTexture::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkTexture::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#printself)")
*/
    ADD_CLASS_METHOD(Render,"void vtkTexture::Render(vtkRenderer * ren)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#render)")
    ADD_CLASS_METHOD(PostRender,"void vtkTexture::PostRender(vtkRenderer * param0)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#postrender)")
    ADD_CLASS_METHOD(ReleaseGraphicsResources,"void vtkTexture::ReleaseGraphicsResources(vtkWindow * param0)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#releasegraphicsresources)")
    ADD_CLASS_METHOD(Load,"void vtkTexture::Load(vtkRenderer * param0)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#load)")
    ADD_CLASS_METHOD(GetRepeat,"int vtkTexture::GetRepeat()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#getrepeat)")
    ADD_CLASS_METHOD(SetRepeat,"void vtkTexture::SetRepeat(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#setrepeat)")
    ADD_CLASS_METHOD(RepeatOn,"void vtkTexture::RepeatOn()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#repeaton)")
    ADD_CLASS_METHOD(RepeatOff,"void vtkTexture::RepeatOff()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#repeatoff)")
    ADD_CLASS_METHOD(GetEdgeClamp,"int vtkTexture::GetEdgeClamp()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#getedgeclamp)")
    ADD_CLASS_METHOD(SetEdgeClamp,"void vtkTexture::SetEdgeClamp(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#setedgeclamp)")
    ADD_CLASS_METHOD(EdgeClampOn,"void vtkTexture::EdgeClampOn()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#edgeclampon)")
    ADD_CLASS_METHOD(EdgeClampOff,"void vtkTexture::EdgeClampOff()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#edgeclampoff)")
    ADD_CLASS_METHOD(GetInterpolate,"int vtkTexture::GetInterpolate()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#getinterpolate)")
    ADD_CLASS_METHOD(SetInterpolate,"void vtkTexture::SetInterpolate(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#setinterpolate)")
    ADD_CLASS_METHOD(InterpolateOn,"void vtkTexture::InterpolateOn()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#interpolateon)")
    ADD_CLASS_METHOD(InterpolateOff,"void vtkTexture::InterpolateOff()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#interpolateoff)")
    ADD_CLASS_METHOD(SetQuality,"void vtkTexture::SetQuality(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#setquality)")
    ADD_CLASS_METHOD(GetQuality,"int vtkTexture::GetQuality()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#getquality)")
    ADD_CLASS_METHOD(SetQualityToDefault,"void vtkTexture::SetQualityToDefault()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#setqualitytodefault)")
    ADD_CLASS_METHOD(SetQualityTo16Bit,"void vtkTexture::SetQualityTo16Bit()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#setqualityto16bit)")
    ADD_CLASS_METHOD(SetQualityTo32Bit,"void vtkTexture::SetQualityTo32Bit()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#setqualityto32bit)")
    ADD_CLASS_METHOD(GetMapColorScalarsThroughLookupTable,"int vtkTexture::GetMapColorScalarsThroughLookupTable()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#getmapcolorscalarsthroughlookuptable)")
    ADD_CLASS_METHOD(SetMapColorScalarsThroughLookupTable,"void vtkTexture::SetMapColorScalarsThroughLookupTable(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#setmapcolorscalarsthroughlookuptable)")
    ADD_CLASS_METHOD(MapColorScalarsThroughLookupTableOn,"void vtkTexture::MapColorScalarsThroughLookupTableOn()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#mapcolorscalarsthroughlookuptableon)")
    ADD_CLASS_METHOD(MapColorScalarsThroughLookupTableOff,"void vtkTexture::MapColorScalarsThroughLookupTableOff()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#mapcolorscalarsthroughlookuptableoff)")
    ADD_CLASS_METHOD(GetInput,"vtkImageData * vtkTexture::GetInput()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#getinput)")
    ADD_CLASS_METHOD(SetLookupTable,"void vtkTexture::SetLookupTable(vtkScalarsToColors * param0)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#setlookuptable)")
    ADD_CLASS_METHOD(GetLookupTable,"vtkScalarsToColors * vtkTexture::GetLookupTable()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#getlookuptable)")
    ADD_CLASS_METHOD(GetMappedScalars,"vtkUnsignedCharArray * vtkTexture::GetMappedScalars()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#getmappedscalars)")
    ADD_CLASS_METHOD(MapScalarsToColors,"unsigned char * vtkTexture::MapScalarsToColors(vtkDataArray * scalars)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#mapscalarstocolors)")
    ADD_CLASS_METHOD(SetTransform,"void vtkTexture::SetTransform(vtkTransform * transform)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#settransform)")
    ADD_CLASS_METHOD(GetTransform,"vtkTransform * vtkTexture::GetTransform()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#gettransform)")
    ADD_CLASS_METHOD(GetBlendingMode,"int vtkTexture::GetBlendingMode()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#getblendingmode)")
    ADD_CLASS_METHOD(SetBlendingMode,"void vtkTexture::SetBlendingMode(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#setblendingmode)")
    ADD_CLASS_METHOD(GetPremultipliedAlpha,"bool vtkTexture::GetPremultipliedAlpha()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#getpremultipliedalpha)")
    ADD_CLASS_METHOD(SetPremultipliedAlpha,"void vtkTexture::SetPremultipliedAlpha(bool _arg)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#setpremultipliedalpha)")
    ADD_CLASS_METHOD(PremultipliedAlphaOn,"void vtkTexture::PremultipliedAlphaOn()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#premultipliedalphaon)")
    ADD_CLASS_METHOD(PremultipliedAlphaOff,"void vtkTexture::PremultipliedAlphaOff()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#premultipliedalphaoff)")
    ADD_CLASS_METHOD(GetRestrictPowerOf2ImageSmaller,"int vtkTexture::GetRestrictPowerOf2ImageSmaller()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#getrestrictpowerof2imagesmaller)")
    ADD_CLASS_METHOD(SetRestrictPowerOf2ImageSmaller,"void vtkTexture::SetRestrictPowerOf2ImageSmaller(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#setrestrictpowerof2imagesmaller)")
    ADD_CLASS_METHOD(RestrictPowerOf2ImageSmallerOn,"void vtkTexture::RestrictPowerOf2ImageSmallerOn()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#restrictpowerof2imagesmalleron)")
    ADD_CLASS_METHOD(RestrictPowerOf2ImageSmallerOff,"void vtkTexture::RestrictPowerOf2ImageSmallerOff()  (http://docs.wxwidgets.org/stable/wx_vtktexture.html#restrictpowerof2imagesmalleroff)")





    void AddMethods(WrapClass<vtkTexture>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkTexture_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkTexture_h
