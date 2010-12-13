/**
 * C++ Interface: wrap_vtkScalarsToColors
 *
 * Description: wrapping vtkScalarsToColors
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkScalarsToColors_h_
#define _wrap_vtkScalarsToColors_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkScalarsToColors.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"


#ifndef vtkScalarsToColors_declared
  #define vtkScalarsToColors_declared
  AMI_DECLARE_TYPE(vtkScalarsToColors);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkScalarsToColors : public WrapClass<vtkScalarsToColors>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkScalarsToColors);

  protected:
    typedef WrapClass<vtkScalarsToColors>::ptr _parentclass_ptr;
    typedef vtkScalarsToColors ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkScalarsToColors>& GetObj() const { return WrapClass<vtkScalarsToColors>::GetObj(); }

    /// Constructor
    WrapClass_vtkScalarsToColors(boost::shared_ptr<vtkScalarsToColors > si): 
    WrapClass<vtkScalarsToColors>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkScalarsToColors()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkScalarsToColors*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkScalarsToColors::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkScalarsToColors * vtkScalarsToColors::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkScalarsToColors::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkScalarsToColors * vtkScalarsToColors::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkScalarsToColors::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#printself)")
*/
    ADD_CLASS_METHOD(IsOpaque,"int vtkScalarsToColors::IsOpaque()  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#isopaque)")
    ADD_CLASS_METHOD(Build,"void vtkScalarsToColors::Build()  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#build)")
    ADD_CLASS_METHOD(SetRange,"void vtkScalarsToColors::SetRange(double * rng)  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#setrange)")
    ADD_CLASS_METHOD(GetColor,"double * vtkScalarsToColors::GetColor(double v)  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#getcolor)")
    ADD_CLASS_METHOD(GetOpacity,"double vtkScalarsToColors::GetOpacity(double param0)  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#getopacity)")
    ADD_CLASS_METHOD(GetLuminance,"double vtkScalarsToColors::GetLuminance(double x)  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#getluminance)")
    ADD_CLASS_METHOD(SetAlpha,"void vtkScalarsToColors::SetAlpha(double alpha)  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#setalpha)")
    ADD_CLASS_METHOD(GetAlpha,"double vtkScalarsToColors::GetAlpha()  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#getalpha)")
    ADD_CLASS_METHOD(MapScalars,"vtkUnsignedCharArray * vtkScalarsToColors::MapScalars(vtkDataArray * scalars, int colorMode, int component)  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#mapscalars)")
    ADD_CLASS_METHOD(SetVectorMode,"void vtkScalarsToColors::SetVectorMode(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#setvectormode)")
    ADD_CLASS_METHOD(GetVectorMode,"int vtkScalarsToColors::GetVectorMode()  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#getvectormode)")
    ADD_CLASS_METHOD(SetVectorModeToMagnitude,"void vtkScalarsToColors::SetVectorModeToMagnitude()  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#setvectormodetomagnitude)")
    ADD_CLASS_METHOD(SetVectorModeToComponent,"void vtkScalarsToColors::SetVectorModeToComponent()  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#setvectormodetocomponent)")
    ADD_CLASS_METHOD(SetVectorComponent,"void vtkScalarsToColors::SetVectorComponent(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#setvectorcomponent)")
    ADD_CLASS_METHOD(GetVectorComponent,"int vtkScalarsToColors::GetVectorComponent()  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#getvectorcomponent)")
    ADD_CLASS_METHOD(MapScalarsThroughTable_1,"void vtkScalarsToColors::MapScalarsThroughTable(vtkDataArray * scalars, unsigned char * output, int outputFormat)  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#mapscalarsthroughtable)")
    ADD_CLASS_METHOD(MapScalarsThroughTable,"vtkScalarsToColors::MapScalarsThroughTable()  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#mapscalarsthroughtable)")
    ADD_CLASS_METHOD(MapScalarsThroughTable_2,"void vtkScalarsToColors::MapScalarsThroughTable(vtkDataArray * scalars, unsigned char * output)  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#mapscalarsthroughtable)")
    ADD_CLASS_METHOD(ConvertUnsignedCharToRGBA,"vtkUnsignedCharArray * vtkScalarsToColors::ConvertUnsignedCharToRGBA(vtkUnsignedCharArray * colors, int numComp, int numTuples)  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#convertunsignedchartorgba)")
    ADD_CLASS_METHOD(UsingLogScale,"int vtkScalarsToColors::UsingLogScale()  (http://docs.wxwidgets.org/stable/wx_vtkscalarstocolors.html#usinglogscale)")





    void AddMethods(WrapClass<vtkScalarsToColors>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkScalarsToColors_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkScalarsToColors_h
