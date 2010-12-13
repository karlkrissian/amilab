/**
 * C++ Interface: wrap_vtkPoints
 *
 * Description: wrapping vtkPoints
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkPoints_h_
#define _wrap_vtkPoints_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkPoints.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"


#ifndef vtkPoints_declared
  #define vtkPoints_declared
  AMI_DECLARE_TYPE(vtkPoints);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkPoints : public WrapClass<vtkPoints>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkPoints);

  protected:
    typedef WrapClass<vtkPoints>::ptr _parentclass_ptr;
    typedef vtkPoints ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkPoints>& GetObj() const { return WrapClass<vtkPoints>::GetObj(); }

    /// Constructor
    WrapClass_vtkPoints(boost::shared_ptr<vtkPoints > si): 
    WrapClass<vtkPoints>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkPoints()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkPoints*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New_1,"vtkPoints * vtkPoints::New(int dataType) (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#new).");
    ADD_CLASS_STATICMETHOD(New,"vtkPoints::New() (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#new).");
    ADD_CLASS_STATICMETHOD(New_2,"vtkPoints * vtkPoints::New() (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkPoints::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkPoints * vtkPoints::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkPoints::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkPoints * vtkPoints::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkPoints::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#printself)")
*/
    ADD_CLASS_METHOD(Allocate,"int vtkPoints::Allocate(vtkIdType const sz, vtkIdType const ext = 1000)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#allocate)")
    ADD_CLASS_METHOD(Initialize,"void vtkPoints::Initialize()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#initialize)")
    ADD_CLASS_METHOD(SetData,"void vtkPoints::SetData(vtkDataArray * param0)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setdata)")
    ADD_CLASS_METHOD(GetData,"vtkDataArray * vtkPoints::GetData()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#getdata)")
    ADD_CLASS_METHOD(GetDataType,"int vtkPoints::GetDataType()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#getdatatype)")
    ADD_CLASS_METHOD(SetDataType,"void vtkPoints::SetDataType(int dataType)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setdatatype)")
    ADD_CLASS_METHOD(SetDataTypeToBit,"void vtkPoints::SetDataTypeToBit()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setdatatypetobit)")
    ADD_CLASS_METHOD(SetDataTypeToChar,"void vtkPoints::SetDataTypeToChar()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setdatatypetochar)")
    ADD_CLASS_METHOD(SetDataTypeToUnsignedChar,"void vtkPoints::SetDataTypeToUnsignedChar()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setdatatypetounsignedchar)")
    ADD_CLASS_METHOD(SetDataTypeToShort,"void vtkPoints::SetDataTypeToShort()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setdatatypetoshort)")
    ADD_CLASS_METHOD(SetDataTypeToUnsignedShort,"void vtkPoints::SetDataTypeToUnsignedShort()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setdatatypetounsignedshort)")
    ADD_CLASS_METHOD(SetDataTypeToInt,"void vtkPoints::SetDataTypeToInt()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setdatatypetoint)")
    ADD_CLASS_METHOD(SetDataTypeToUnsignedInt,"void vtkPoints::SetDataTypeToUnsignedInt()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setdatatypetounsignedint)")
    ADD_CLASS_METHOD(SetDataTypeToLong,"void vtkPoints::SetDataTypeToLong()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setdatatypetolong)")
    ADD_CLASS_METHOD(SetDataTypeToUnsignedLong,"void vtkPoints::SetDataTypeToUnsignedLong()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setdatatypetounsignedlong)")
    ADD_CLASS_METHOD(SetDataTypeToFloat,"void vtkPoints::SetDataTypeToFloat()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setdatatypetofloat)")
    ADD_CLASS_METHOD(SetDataTypeToDouble,"void vtkPoints::SetDataTypeToDouble()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setdatatypetodouble)")
    ADD_CLASS_METHOD(GetVoidPointer,"void * vtkPoints::GetVoidPointer(int const id)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#getvoidpointer)")
    ADD_CLASS_METHOD(Squeeze,"void vtkPoints::Squeeze()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#squeeze)")
    ADD_CLASS_METHOD(Reset,"void vtkPoints::Reset()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#reset)")
    ADD_CLASS_METHOD(DeepCopy,"void vtkPoints::DeepCopy(vtkPoints * ad)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#deepcopy)")
    ADD_CLASS_METHOD(ShallowCopy,"void vtkPoints::ShallowCopy(vtkPoints * ad)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#shallowcopy)")
    ADD_CLASS_METHOD(GetActualMemorySize,"long unsigned int vtkPoints::GetActualMemorySize()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#getactualmemorysize)")
    ADD_CLASS_METHOD(GetNumberOfPoints,"vtkIdType vtkPoints::GetNumberOfPoints()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#getnumberofpoints)")
    ADD_CLASS_METHOD(GetPoint_1,"double * vtkPoints::GetPoint(vtkIdType id)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#getpoint)")
    ADD_CLASS_METHOD(GetPoint,"vtkPoints::GetPoint()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#getpoint)")
    ADD_CLASS_METHOD(GetPoint_2,"void vtkPoints::GetPoint(vtkIdType id, double * x)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#getpoint)")
    ADD_CLASS_METHOD(SetPoint_1,"void vtkPoints::SetPoint(vtkIdType id, float const * x)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setpoint)")
    ADD_CLASS_METHOD(SetPoint,"vtkPoints::SetPoint()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setpoint)")
    ADD_CLASS_METHOD(SetPoint_2,"void vtkPoints::SetPoint(vtkIdType id, double const * x)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setpoint)")
    ADD_CLASS_METHOD(SetPoint_3,"void vtkPoints::SetPoint(vtkIdType id, double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setpoint)")
    ADD_CLASS_METHOD(InsertPoint_1,"void vtkPoints::InsertPoint(vtkIdType id, float const * x)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#insertpoint)")
    ADD_CLASS_METHOD(InsertPoint,"vtkPoints::InsertPoint()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#insertpoint)")
    ADD_CLASS_METHOD(InsertPoint_2,"void vtkPoints::InsertPoint(vtkIdType id, double const * x)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#insertpoint)")
    ADD_CLASS_METHOD(InsertPoint_3,"void vtkPoints::InsertPoint(vtkIdType id, double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#insertpoint)")
    ADD_CLASS_METHOD(InsertNextPoint_1,"vtkIdType vtkPoints::InsertNextPoint(float const * x)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#insertnextpoint)")
    ADD_CLASS_METHOD(InsertNextPoint,"vtkPoints::InsertNextPoint()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#insertnextpoint)")
    ADD_CLASS_METHOD(InsertNextPoint_2,"vtkIdType vtkPoints::InsertNextPoint(double const * x)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#insertnextpoint)")
    ADD_CLASS_METHOD(InsertNextPoint_3,"vtkIdType vtkPoints::InsertNextPoint(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#insertnextpoint)")
    ADD_CLASS_METHOD(SetNumberOfPoints,"void vtkPoints::SetNumberOfPoints(vtkIdType number)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#setnumberofpoints)")
/* The following types are missing: vtkIdList
    ADD_CLASS_METHOD(GetPoints,"void vtkPoints::GetPoints(vtkIdList * ptId, vtkPoints * fp)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#getpoints)")
*/
    ADD_CLASS_METHOD(ComputeBounds,"void vtkPoints::ComputeBounds()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#computebounds)")
    ADD_CLASS_METHOD(GetBounds_1,"double * vtkPoints::GetBounds()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#getbounds)")
    ADD_CLASS_METHOD(GetBounds,"vtkPoints::GetBounds()  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#getbounds)")
    ADD_CLASS_METHOD(GetBounds_2,"void vtkPoints::GetBounds(double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkpoints.html#getbounds)")





    void AddMethods(WrapClass<vtkPoints>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkPoints_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkPoints_h
