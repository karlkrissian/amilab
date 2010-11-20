/**
 * C++ Interface: wrap_vtkPiecewiseFunction
 *
 * Description: wrapping vtkPiecewiseFunction
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkPiecewiseFunction_h_
#define _wrap_vtkPiecewiseFunction_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkDataObject.h"


AMI_DECLARE_TYPE(vtkPiecewiseFunction);

// TODO: check for inheritence ...
class WrapClass_vtkPiecewiseFunction : public WrapClass<vtkPiecewiseFunction>
    , public   WrapClass_vtkDataObject
{
  DEFINE_CLASS(WrapClass_vtkPiecewiseFunction);

  protected:
    typedef WrapClass<vtkPiecewiseFunction>::ptr _parentclass_ptr;
    typedef vtkPiecewiseFunction ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkPiecewiseFunction>& GetObj() const { return WrapClass<vtkPiecewiseFunction>::GetObj(); }

    /// Constructor
    WrapClass_vtkPiecewiseFunction(boost::shared_ptr<vtkPiecewiseFunction > si): 
    WrapClass<vtkPiecewiseFunction>(si)
    , WrapClass_vtkDataObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkPiecewiseFunction()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkPiecewiseFunction*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkPiecewiseFunction * vtkPiecewiseFunction::New() (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkPiecewiseFunction::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkPiecewiseFunction * vtkPiecewiseFunction::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#safedowncast).");
    /* The following types are missing: vtkInformation
    ADD_CLASS_STATICMETHOD(GetData_1,"vtkPiecewiseFunction * vtkPiecewiseFunction::GetData(vtkInformation * info) (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#getdata).");
    */
    ADD_CLASS_STATICMETHOD(GetData,"vtkPiecewiseFunction::GetData() (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#getdata).");
    /* The following types are missing: vtkInformationVector
    ADD_CLASS_STATICMETHOD(GetData_2,"vtkPiecewiseFunction * vtkPiecewiseFunction::GetData(vtkInformationVector * v, int i = 0) (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#getdata).");
    */



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkPiecewiseFunction::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkPiecewiseFunction * vtkPiecewiseFunction::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkPiecewiseFunction::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#printself)")
*/
    ADD_CLASS_METHOD(DeepCopy,"void vtkPiecewiseFunction::DeepCopy(vtkDataObject * f)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#deepcopy)")
    ADD_CLASS_METHOD(ShallowCopy,"void vtkPiecewiseFunction::ShallowCopy(vtkDataObject * f)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#shallowcopy)")
    ADD_CLASS_METHOD(GetDataObjectType,"int vtkPiecewiseFunction::GetDataObjectType()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#getdataobjecttype)")
    ADD_CLASS_METHOD(GetSize,"int vtkPiecewiseFunction::GetSize()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#getsize)")
    ADD_CLASS_METHOD(AddPoint_1,"int vtkPiecewiseFunction::AddPoint(double x, double y)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#addpoint)")
    ADD_CLASS_METHOD(AddPoint,"vtkPiecewiseFunction::AddPoint()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#addpoint)")
    ADD_CLASS_METHOD(AddPoint_2,"int vtkPiecewiseFunction::AddPoint(double x, double y, double midpoint, double sharpness)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#addpoint)")
    ADD_CLASS_METHOD(RemovePoint,"int vtkPiecewiseFunction::RemovePoint(double x)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#removepoint)")
    ADD_CLASS_METHOD(RemoveAllPoints,"void vtkPiecewiseFunction::RemoveAllPoints()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#removeallpoints)")
    ADD_CLASS_METHOD(AddSegment,"void vtkPiecewiseFunction::AddSegment(double x1, double y1, double x2, double y2)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#addsegment)")
    ADD_CLASS_METHOD(GetValue,"double vtkPiecewiseFunction::GetValue(double x)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#getvalue)")
    ADD_CLASS_METHOD(GetNodeValue,"int vtkPiecewiseFunction::GetNodeValue(int index, double * val)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#getnodevalue)")
    ADD_CLASS_METHOD(SetNodeValue,"int vtkPiecewiseFunction::SetNodeValue(int index, double * val)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#setnodevalue)")
    ADD_CLASS_METHOD(GetDataPointer,"double * vtkPiecewiseFunction::GetDataPointer()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#getdatapointer)")
    ADD_CLASS_METHOD(FillFromDataPointer,"void vtkPiecewiseFunction::FillFromDataPointer(int param0, double * param1)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#fillfromdatapointer)")
    ADD_CLASS_METHOD(GetRange_1,"double * vtkPiecewiseFunction::GetRange()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#getrange)")
    ADD_CLASS_METHOD(GetRange,"vtkPiecewiseFunction::GetRange()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#getrange)")
    ADD_CLASS_METHOD(GetRange_2,"void vtkPiecewiseFunction::GetRange(double & _arg1, double & _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#getrange)")
    ADD_CLASS_METHOD(GetRange_3,"void vtkPiecewiseFunction::GetRange(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#getrange)")
    ADD_CLASS_METHOD(AdjustRange,"int vtkPiecewiseFunction::AdjustRange(double * range)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#adjustrange)")
    ADD_CLASS_METHOD(GetTable_1,"void vtkPiecewiseFunction::GetTable(double x1, double x2, int size, float * table, int stride = 1)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#gettable)")
    ADD_CLASS_METHOD(GetTable,"vtkPiecewiseFunction::GetTable()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#gettable)")
    ADD_CLASS_METHOD(GetTable_2,"void vtkPiecewiseFunction::GetTable(double x1, double x2, int size, double * table, int stride = 1)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#gettable)")
    ADD_CLASS_METHOD(BuildFunctionFromTable,"void vtkPiecewiseFunction::BuildFunctionFromTable(double x1, double x2, int size, double * table, int stride = 1)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#buildfunctionfromtable)")
    ADD_CLASS_METHOD(SetClamping,"void vtkPiecewiseFunction::SetClamping(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#setclamping)")
    ADD_CLASS_METHOD(GetClamping,"int vtkPiecewiseFunction::GetClamping()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#getclamping)")
    ADD_CLASS_METHOD(ClampingOn,"void vtkPiecewiseFunction::ClampingOn()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#clampingon)")
    ADD_CLASS_METHOD(ClampingOff,"void vtkPiecewiseFunction::ClampingOff()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#clampingoff)")
    ADD_CLASS_METHOD(GetType,"char const * vtkPiecewiseFunction::GetType()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#gettype)")
    ADD_CLASS_METHOD(GetFirstNonZeroValue,"double vtkPiecewiseFunction::GetFirstNonZeroValue()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#getfirstnonzerovalue)")
    ADD_CLASS_METHOD(Initialize,"void vtkPiecewiseFunction::Initialize()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#initialize)")
    ADD_CLASS_METHOD(SetAllowDuplicateScalars,"void vtkPiecewiseFunction::SetAllowDuplicateScalars(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#setallowduplicatescalars)")
    ADD_CLASS_METHOD(GetAllowDuplicateScalars,"int vtkPiecewiseFunction::GetAllowDuplicateScalars()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#getallowduplicatescalars)")
    ADD_CLASS_METHOD(AllowDuplicateScalarsOn,"void vtkPiecewiseFunction::AllowDuplicateScalarsOn()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#allowduplicatescalarson)")
    ADD_CLASS_METHOD(AllowDuplicateScalarsOff,"void vtkPiecewiseFunction::AllowDuplicateScalarsOff()  (http://docs.wxwidgets.org/stable/wx_vtkpiecewisefunction.html#allowduplicatescalarsoff)")





    void AddMethods(WrapClass<vtkPiecewiseFunction>::ptr this_ptr );

};


#endif // _wrap_vtkPiecewiseFunction_h
