/**
 * C++ Interface: wrap_vtkColorTransferFunction
 *
 * Description: wrapping vtkColorTransferFunction
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkColorTransferFunction_h_
#define _wrap_vtkColorTransferFunction_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkScalarsToColors.h"



AMI_DECLARE_TYPE(vtkColorTransferFunction);

// TODO: check for inheritence ...
class WrapClass_vtkColorTransferFunction : public WrapClass<vtkColorTransferFunction>
    , public   WrapClass_vtkScalarsToColors
{
  DEFINE_CLASS(WrapClass_vtkColorTransferFunction);

  protected:
    typedef WrapClass<vtkColorTransferFunction>::ptr _parentclass_ptr;
    typedef vtkColorTransferFunction ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkColorTransferFunction>& GetObj() const { return WrapClass<vtkColorTransferFunction>::GetObj(); }

    /// Constructor
    WrapClass_vtkColorTransferFunction(boost::shared_ptr<vtkColorTransferFunction > si): 
    WrapClass<vtkColorTransferFunction>(si)
    , WrapClass_vtkScalarsToColors(si)
    {}

    /// Destructor
    ~WrapClass_vtkColorTransferFunction()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkColorTransferFunction*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkColorTransferFunction * vtkColorTransferFunction::New() (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkColorTransferFunction::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkColorTransferFunction * vtkColorTransferFunction::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkColorTransferFunction::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkColorTransferFunction * vtkColorTransferFunction::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#newinstance)")
    ADD_CLASS_METHOD(DeepCopy,"void vtkColorTransferFunction::DeepCopy(vtkColorTransferFunction * f)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#deepcopy)")
    ADD_CLASS_METHOD(ShallowCopy,"void vtkColorTransferFunction::ShallowCopy(vtkColorTransferFunction * f)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#shallowcopy)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkColorTransferFunction::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#printself)")
*/
    ADD_CLASS_METHOD(GetSize,"int vtkColorTransferFunction::GetSize()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getsize)")
    ADD_CLASS_METHOD(AddRGBPoint_1,"int vtkColorTransferFunction::AddRGBPoint(double x, double r, double g, double b)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#addrgbpoint)")
    ADD_CLASS_METHOD(AddRGBPoint,"vtkColorTransferFunction::AddRGBPoint()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#addrgbpoint)")
    ADD_CLASS_METHOD(AddRGBPoint_2,"int vtkColorTransferFunction::AddRGBPoint(double x, double r, double g, double b, double midpoint, double sharpness)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#addrgbpoint)")
    ADD_CLASS_METHOD(AddHSVPoint_1,"int vtkColorTransferFunction::AddHSVPoint(double x, double h, double s, double v)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#addhsvpoint)")
    ADD_CLASS_METHOD(AddHSVPoint,"vtkColorTransferFunction::AddHSVPoint()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#addhsvpoint)")
    ADD_CLASS_METHOD(AddHSVPoint_2,"int vtkColorTransferFunction::AddHSVPoint(double x, double h, double s, double v, double midpoint, double sharpness)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#addhsvpoint)")
    ADD_CLASS_METHOD(RemovePoint,"int vtkColorTransferFunction::RemovePoint(double x)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#removepoint)")
    ADD_CLASS_METHOD(AddRGBSegment,"void vtkColorTransferFunction::AddRGBSegment(double x1, double r1, double g1, double b1, double x2, double r2, double g2, double b2)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#addrgbsegment)")
    ADD_CLASS_METHOD(AddHSVSegment,"void vtkColorTransferFunction::AddHSVSegment(double x1, double h1, double s1, double v1, double x2, double h2, double s2, double v2)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#addhsvsegment)")
    ADD_CLASS_METHOD(RemoveAllPoints,"void vtkColorTransferFunction::RemoveAllPoints()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#removeallpoints)")
    ADD_CLASS_METHOD(GetColor_1,"double * vtkColorTransferFunction::GetColor(double x)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getcolor)")
    ADD_CLASS_METHOD(GetColor,"vtkColorTransferFunction::GetColor()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getcolor)")
    ADD_CLASS_METHOD(GetColor_2,"void vtkColorTransferFunction::GetColor(double x, double * rgb)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getcolor)")
    ADD_CLASS_METHOD(GetRedValue,"double vtkColorTransferFunction::GetRedValue(double x)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getredvalue)")
    ADD_CLASS_METHOD(GetGreenValue,"double vtkColorTransferFunction::GetGreenValue(double x)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getgreenvalue)")
    ADD_CLASS_METHOD(GetBlueValue,"double vtkColorTransferFunction::GetBlueValue(double x)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getbluevalue)")
    ADD_CLASS_METHOD(GetNodeValue,"int vtkColorTransferFunction::GetNodeValue(int index, double * val)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getnodevalue)")
    ADD_CLASS_METHOD(SetNodeValue,"int vtkColorTransferFunction::SetNodeValue(int index, double * val)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#setnodevalue)")
    ADD_CLASS_METHOD(MapValue,"unsigned char * vtkColorTransferFunction::MapValue(double v)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#mapvalue)")
    ADD_CLASS_METHOD(GetRange_1,"double * vtkColorTransferFunction::GetRange()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getrange)")
    ADD_CLASS_METHOD(GetRange,"vtkColorTransferFunction::GetRange()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getrange)")
    ADD_CLASS_METHOD(GetRange_2,"void vtkColorTransferFunction::GetRange(double & _arg1, double & _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getrange)")
    ADD_CLASS_METHOD(GetRange_3,"void vtkColorTransferFunction::GetRange(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getrange)")
    ADD_CLASS_METHOD(AdjustRange,"int vtkColorTransferFunction::AdjustRange(double * range)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#adjustrange)")
    ADD_CLASS_METHOD(GetTable_1,"void vtkColorTransferFunction::GetTable(double x1, double x2, int n, double * table)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#gettable)")
    ADD_CLASS_METHOD(GetTable,"vtkColorTransferFunction::GetTable()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#gettable)")
    ADD_CLASS_METHOD(GetTable_2,"void vtkColorTransferFunction::GetTable(double x1, double x2, int n, float * table)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#gettable)")
    ADD_CLASS_METHOD(GetTable_3,"unsigned char const * vtkColorTransferFunction::GetTable(double x1, double x2, int n)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#gettable)")
    ADD_CLASS_METHOD(BuildFunctionFromTable,"void vtkColorTransferFunction::BuildFunctionFromTable(double x1, double x2, int size, double * table)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#buildfunctionfromtable)")
    ADD_CLASS_METHOD(SetClamping,"void vtkColorTransferFunction::SetClamping(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#setclamping)")
    ADD_CLASS_METHOD(GetClampingMinValue,"int vtkColorTransferFunction::GetClampingMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getclampingminvalue)")
    ADD_CLASS_METHOD(GetClampingMaxValue,"int vtkColorTransferFunction::GetClampingMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getclampingmaxvalue)")
    ADD_CLASS_METHOD(GetClamping,"int vtkColorTransferFunction::GetClamping()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getclamping)")
    ADD_CLASS_METHOD(ClampingOn,"void vtkColorTransferFunction::ClampingOn()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#clampingon)")
    ADD_CLASS_METHOD(ClampingOff,"void vtkColorTransferFunction::ClampingOff()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#clampingoff)")
    ADD_CLASS_METHOD(SetColorSpace,"void vtkColorTransferFunction::SetColorSpace(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#setcolorspace)")
    ADD_CLASS_METHOD(GetColorSpaceMinValue,"int vtkColorTransferFunction::GetColorSpaceMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getcolorspaceminvalue)")
    ADD_CLASS_METHOD(GetColorSpaceMaxValue,"int vtkColorTransferFunction::GetColorSpaceMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getcolorspacemaxvalue)")
    ADD_CLASS_METHOD(SetColorSpaceToRGB,"void vtkColorTransferFunction::SetColorSpaceToRGB()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#setcolorspacetorgb)")
    ADD_CLASS_METHOD(SetColorSpaceToHSV,"void vtkColorTransferFunction::SetColorSpaceToHSV()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#setcolorspacetohsv)")
    ADD_CLASS_METHOD(SetColorSpaceToLab,"void vtkColorTransferFunction::SetColorSpaceToLab()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#setcolorspacetolab)")
    ADD_CLASS_METHOD(SetColorSpaceToDiverging,"void vtkColorTransferFunction::SetColorSpaceToDiverging()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#setcolorspacetodiverging)")
    ADD_CLASS_METHOD(GetColorSpace,"int vtkColorTransferFunction::GetColorSpace()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getcolorspace)")
    ADD_CLASS_METHOD(SetHSVWrap,"void vtkColorTransferFunction::SetHSVWrap(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#sethsvwrap)")
    ADD_CLASS_METHOD(GetHSVWrap,"int vtkColorTransferFunction::GetHSVWrap()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#gethsvwrap)")
    ADD_CLASS_METHOD(HSVWrapOn,"void vtkColorTransferFunction::HSVWrapOn()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#hsvwrapon)")
    ADD_CLASS_METHOD(HSVWrapOff,"void vtkColorTransferFunction::HSVWrapOff()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#hsvwrapoff)")
    ADD_CLASS_METHOD(SetScale,"void vtkColorTransferFunction::SetScale(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#setscale)")
    ADD_CLASS_METHOD(SetScaleToLinear,"void vtkColorTransferFunction::SetScaleToLinear()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#setscaletolinear)")
    ADD_CLASS_METHOD(SetScaleToLog10,"void vtkColorTransferFunction::SetScaleToLog10()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#setscaletolog10)")
    ADD_CLASS_METHOD(GetScale,"int vtkColorTransferFunction::GetScale()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getscale)")
    ADD_CLASS_METHOD(GetDataPointer,"double * vtkColorTransferFunction::GetDataPointer()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getdatapointer)")
    ADD_CLASS_METHOD(FillFromDataPointer,"void vtkColorTransferFunction::FillFromDataPointer(int param0, double * param1)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#fillfromdatapointer)")
/* The following types are missing: void
    ADD_CLASS_METHOD(MapScalarsThroughTable2,"void vtkColorTransferFunction::MapScalarsThroughTable2(void * input, unsigned char * output, int inputDataType, int numberOfValues, int inputIncrement, int outputIncrement)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#mapscalarsthroughtable2)")
*/
    ADD_CLASS_METHOD(SetAllowDuplicateScalars,"void vtkColorTransferFunction::SetAllowDuplicateScalars(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#setallowduplicatescalars)")
    ADD_CLASS_METHOD(GetAllowDuplicateScalars,"int vtkColorTransferFunction::GetAllowDuplicateScalars()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#getallowduplicatescalars)")
    ADD_CLASS_METHOD(AllowDuplicateScalarsOn,"void vtkColorTransferFunction::AllowDuplicateScalarsOn()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#allowduplicatescalarson)")
    ADD_CLASS_METHOD(AllowDuplicateScalarsOff,"void vtkColorTransferFunction::AllowDuplicateScalarsOff()  (http://docs.wxwidgets.org/stable/wx_vtkcolortransferfunction.html#allowduplicatescalarsoff)")





    void AddMethods(WrapClass<vtkColorTransferFunction>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkColorTransferFunction_h
