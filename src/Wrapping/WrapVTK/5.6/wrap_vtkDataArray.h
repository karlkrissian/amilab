/**
 * C++ Interface: wrap_vtkDataArray
 *
 * Description: wrapping vtkDataArray
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkDataArray_h_
#define _wrap_vtkDataArray_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkDataArray.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkAbstractArray.h"



AMI_DECLARE_TYPE(vtkDataArray);

// TODO: check for inheritence ...
class WrapClass_vtkDataArray : public WrapClass<vtkDataArray>
    , public   WrapClass_vtkAbstractArray
{
  DEFINE_CLASS(WrapClass_vtkDataArray);

  protected:
    typedef WrapClass<vtkDataArray>::ptr _parentclass_ptr;
    typedef vtkDataArray ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkDataArray>& GetObj() const { return WrapClass<vtkDataArray>::GetObj(); }

    /// Constructor
    WrapClass_vtkDataArray(boost::shared_ptr<vtkDataArray > si): 
    WrapClass<vtkDataArray>(si)
    , WrapClass_vtkAbstractArray(si)
    {}

    /// Destructor
    ~WrapClass_vtkDataArray()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkDataArray*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkDataArray::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkDataArray * vtkDataArray::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(GetDataTypeRange,"void vtkDataArray::GetDataTypeRange(int type, double * range) (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getdatatyperange).");
    ADD_CLASS_STATICMETHOD(GetDataTypeMin,"double vtkDataArray::GetDataTypeMin(int type) (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getdatatypemin).");
    ADD_CLASS_STATICMETHOD(GetDataTypeMax,"double vtkDataArray::GetDataTypeMax(int type) (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getdatatypemax).");
    ADD_CLASS_STATICMETHOD(CreateDataArray,"vtkDataArray * vtkDataArray::CreateDataArray(int dataType) (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#createdataarray).");
    /* The following types are missing: vtkInformationInformationVectorKey
    ADD_CLASS_STATICMETHOD(PER_COMPONENT,"vtkInformationInformationVectorKey * vtkDataArray::PER_COMPONENT() (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#per_component).");
    */
    /* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_STATICMETHOD(COMPONENT_RANGE,"vtkInformationDoubleVectorKey * vtkDataArray::COMPONENT_RANGE() (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#component_range).");
    */
    /* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_STATICMETHOD(L2_NORM_RANGE,"vtkInformationDoubleVectorKey * vtkDataArray::L2_NORM_RANGE() (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#l2_norm_range).");
    */



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkDataArray::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkDataArray * vtkDataArray::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkDataArray::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#printself)")
*/
    ADD_CLASS_METHOD(IsNumeric,"int vtkDataArray::IsNumeric()  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#isnumeric)")
    ADD_CLASS_METHOD(GetElementComponentSize,"int vtkDataArray::GetElementComponentSize()  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getelementcomponentsize)")
/* The following types are missing: vtkIdList
    ADD_CLASS_METHOD(GetTuples_1,"void vtkDataArray::GetTuples(vtkIdList * ptIds, vtkAbstractArray * output)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#gettuples)")
*/
    ADD_CLASS_METHOD(GetTuples,"vtkDataArray::GetTuples()  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#gettuples)")
    ADD_CLASS_METHOD(GetTuples_2,"void vtkDataArray::GetTuples(vtkIdType p1, vtkIdType p2, vtkAbstractArray * output)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#gettuples)")
/* The following types are missing: vtkIdList
    ADD_CLASS_METHOD(InterpolateTuple_1,"void vtkDataArray::InterpolateTuple(vtkIdType i, vtkIdList * ptIndices, vtkAbstractArray * source, double * weights)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#interpolatetuple)")
*/
    ADD_CLASS_METHOD(InterpolateTuple,"vtkDataArray::InterpolateTuple()  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#interpolatetuple)")
    ADD_CLASS_METHOD(InterpolateTuple_2,"void vtkDataArray::InterpolateTuple(vtkIdType i, vtkIdType id1, vtkAbstractArray * source1, vtkIdType id2, vtkAbstractArray * source2, double t)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#interpolatetuple)")
    ADD_CLASS_METHOD(GetTuple1,"double vtkDataArray::GetTuple1(vtkIdType i)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#gettuple1)")
    ADD_CLASS_METHOD(GetTuple2,"double * vtkDataArray::GetTuple2(vtkIdType i)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#gettuple2)")
    ADD_CLASS_METHOD(GetTuple3,"double * vtkDataArray::GetTuple3(vtkIdType i)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#gettuple3)")
    ADD_CLASS_METHOD(GetTuple4,"double * vtkDataArray::GetTuple4(vtkIdType i)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#gettuple4)")
    ADD_CLASS_METHOD(GetTuple9,"double * vtkDataArray::GetTuple9(vtkIdType i)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#gettuple9)")
    ADD_CLASS_METHOD(SetTuple1,"void vtkDataArray::SetTuple1(vtkIdType i, double value)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#settuple1)")
    ADD_CLASS_METHOD(SetTuple2,"void vtkDataArray::SetTuple2(vtkIdType i, double val0, double val1)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#settuple2)")
    ADD_CLASS_METHOD(SetTuple3,"void vtkDataArray::SetTuple3(vtkIdType i, double val0, double val1, double val2)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#settuple3)")
    ADD_CLASS_METHOD(SetTuple4,"void vtkDataArray::SetTuple4(vtkIdType i, double val0, double val1, double val2, double val3)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#settuple4)")
    ADD_CLASS_METHOD(SetTuple9,"void vtkDataArray::SetTuple9(vtkIdType i, double val0, double val1, double val2, double val3, double val4, double val5, double val6, double val7, double val8)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#settuple9)")
    ADD_CLASS_METHOD(InsertTuple1,"void vtkDataArray::InsertTuple1(vtkIdType i, double value)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#inserttuple1)")
    ADD_CLASS_METHOD(InsertTuple2,"void vtkDataArray::InsertTuple2(vtkIdType i, double val0, double val1)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#inserttuple2)")
    ADD_CLASS_METHOD(InsertTuple3,"void vtkDataArray::InsertTuple3(vtkIdType i, double val0, double val1, double val2)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#inserttuple3)")
    ADD_CLASS_METHOD(InsertTuple4,"void vtkDataArray::InsertTuple4(vtkIdType i, double val0, double val1, double val2, double val3)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#inserttuple4)")
    ADD_CLASS_METHOD(InsertTuple9,"void vtkDataArray::InsertTuple9(vtkIdType i, double val0, double val1, double val2, double val3, double val4, double val5, double val6, double val7, double val8)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#inserttuple9)")
    ADD_CLASS_METHOD(InsertNextTuple1,"void vtkDataArray::InsertNextTuple1(double value)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#insertnexttuple1)")
    ADD_CLASS_METHOD(InsertNextTuple2,"void vtkDataArray::InsertNextTuple2(double val0, double val1)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#insertnexttuple2)")
    ADD_CLASS_METHOD(InsertNextTuple3,"void vtkDataArray::InsertNextTuple3(double val0, double val1, double val2)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#insertnexttuple3)")
    ADD_CLASS_METHOD(InsertNextTuple4,"void vtkDataArray::InsertNextTuple4(double val0, double val1, double val2, double val3)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#insertnexttuple4)")
    ADD_CLASS_METHOD(InsertNextTuple9,"void vtkDataArray::InsertNextTuple9(double val0, double val1, double val2, double val3, double val4, double val5, double val6, double val7, double val8)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#insertnexttuple9)")
    ADD_CLASS_METHOD(GetComponent,"double vtkDataArray::GetComponent(vtkIdType i, int j)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getcomponent)")
    ADD_CLASS_METHOD(SetComponent,"void vtkDataArray::SetComponent(vtkIdType i, int j, double c)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#setcomponent)")
    ADD_CLASS_METHOD(InsertComponent,"void vtkDataArray::InsertComponent(vtkIdType i, int j, double c)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#insertcomponent)")
/* The following types are missing: vtkDoubleArray
    ADD_CLASS_METHOD(GetData,"void vtkDataArray::GetData(vtkIdType tupleMin, vtkIdType tupleMax, int compMin, int compMax, vtkDoubleArray * data)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getdata)")
*/
    ADD_CLASS_METHOD(DeepCopy_1,"void vtkDataArray::DeepCopy(vtkAbstractArray * aa)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#deepcopy)")
    ADD_CLASS_METHOD(DeepCopy,"vtkDataArray::DeepCopy()  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#deepcopy)")
    ADD_CLASS_METHOD(DeepCopy_2,"void vtkDataArray::DeepCopy(vtkDataArray * da)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#deepcopy)")
    ADD_CLASS_METHOD(FillComponent,"void vtkDataArray::FillComponent(int j, double c)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#fillcomponent)")
    ADD_CLASS_METHOD(CopyComponent,"void vtkDataArray::CopyComponent(int j, vtkDataArray * from, int fromComponent)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#copycomponent)")
    ADD_CLASS_METHOD(GetActualMemorySize,"long unsigned int vtkDataArray::GetActualMemorySize()  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getactualmemorysize)")
    ADD_CLASS_METHOD(CreateDefaultLookupTable,"void vtkDataArray::CreateDefaultLookupTable()  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#createdefaultlookuptable)")
/* The following types are missing: vtkLookupTable
    ADD_CLASS_METHOD(SetLookupTable,"void vtkDataArray::SetLookupTable(vtkLookupTable * lut)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#setlookuptable)")
*/
/* The following types are missing: vtkLookupTable
    ADD_CLASS_METHOD(GetLookupTable,"vtkLookupTable * vtkDataArray::GetLookupTable()  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getlookuptable)")
*/
    ADD_CLASS_METHOD(GetRange_1,"void vtkDataArray::GetRange(double * range, int comp)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getrange)")
    ADD_CLASS_METHOD(GetRange,"vtkDataArray::GetRange()  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getrange)")
    ADD_CLASS_METHOD(GetRange_2,"double * vtkDataArray::GetRange(int comp)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getrange)")
    ADD_CLASS_METHOD(GetRange_3,"double * vtkDataArray::GetRange()  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getrange)")
    ADD_CLASS_METHOD(GetRange_4,"void vtkDataArray::GetRange(double * range)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getrange)")
    ADD_CLASS_METHOD(GetDataTypeRange,"void vtkDataArray::GetDataTypeRange(double * range)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getdatatyperange)")
    ADD_CLASS_METHOD(GetDataTypeMin,"double vtkDataArray::GetDataTypeMin()  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getdatatypemin)")
    ADD_CLASS_METHOD(GetDataTypeMax,"double vtkDataArray::GetDataTypeMax()  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getdatatypemax)")
    ADD_CLASS_METHOD(GetMaxNorm,"double vtkDataArray::GetMaxNorm()  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#getmaxnorm)")
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(CopyInformation,"int vtkDataArray::CopyInformation(vtkInformation * infoFrom, int deep = 1)  (http://docs.wxwidgets.org/stable/wx_vtkdataarray.html#copyinformation)")
*/





    void AddMethods(WrapClass<vtkDataArray>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkDataArray_h
