/**
 * C++ Interface: wrap_vtkAbstractArray
 *
 * Description: wrapping vtkAbstractArray
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkAbstractArray_h_
#define _wrap_vtkAbstractArray_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"



AMI_DECLARE_TYPE(vtkAbstractArray);

// TODO: check for inheritence ...
class WrapClass_vtkAbstractArray : public WrapClass<vtkAbstractArray>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkAbstractArray);

  protected:
    typedef WrapClass<vtkAbstractArray>::ptr _parentclass_ptr;
    typedef vtkAbstractArray ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkAbstractArray>& GetObj() const { return WrapClass<vtkAbstractArray>::GetObj(); }

    /// Constructor
    WrapClass_vtkAbstractArray(boost::shared_ptr<vtkAbstractArray > si): 
    WrapClass<vtkAbstractArray>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkAbstractArray()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkAbstractArray*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkAbstractArray::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkAbstractArray * vtkAbstractArray::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(GetDataTypeSize,"int vtkAbstractArray::GetDataTypeSize(int type) (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#getdatatypesize).");
    ADD_CLASS_STATICMETHOD(CreateArray,"vtkAbstractArray * vtkAbstractArray::CreateArray(int dataType) (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#createarray).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkAbstractArray::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkAbstractArray * vtkAbstractArray::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkAbstractArray::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#printself)")
*/
    ADD_CLASS_METHOD(SetNumberOfComponents,"void vtkAbstractArray::SetNumberOfComponents(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#setnumberofcomponents)")
    ADD_CLASS_METHOD(GetNumberOfComponentsMinValue,"int vtkAbstractArray::GetNumberOfComponentsMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#getnumberofcomponentsminvalue)")
    ADD_CLASS_METHOD(GetNumberOfComponentsMaxValue,"int vtkAbstractArray::GetNumberOfComponentsMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#getnumberofcomponentsmaxvalue)")
    ADD_CLASS_METHOD(GetNumberOfComponents,"int vtkAbstractArray::GetNumberOfComponents()  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#getnumberofcomponents)")
    ADD_CLASS_METHOD(GetNumberOfTuples,"vtkIdType vtkAbstractArray::GetNumberOfTuples()  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#getnumberoftuples)")
/* The following types are missing: vtkIdList
    ADD_CLASS_METHOD(GetTuples_1,"void vtkAbstractArray::GetTuples(vtkIdList * ptIds, vtkAbstractArray * output)  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#gettuples)")
*/
    ADD_CLASS_METHOD(GetTuples,"vtkAbstractArray::GetTuples()  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#gettuples)")
    ADD_CLASS_METHOD(GetTuples_2,"void vtkAbstractArray::GetTuples(vtkIdType p1, vtkIdType p2, vtkAbstractArray * output)  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#gettuples)")
    ADD_CLASS_METHOD(DeepCopy,"void vtkAbstractArray::DeepCopy(vtkAbstractArray * da)  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#deepcopy)")
    ADD_CLASS_METHOD(Reset,"void vtkAbstractArray::Reset()  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#reset)")
    ADD_CLASS_METHOD(GetSize,"vtkIdType vtkAbstractArray::GetSize()  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#getsize)")
    ADD_CLASS_METHOD(GetMaxId,"vtkIdType vtkAbstractArray::GetMaxId()  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#getmaxid)")
/* The following types are missing: void
    ADD_CLASS_METHOD(ExportToVoidPointer,"void vtkAbstractArray::ExportToVoidPointer(void * param0)  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#exporttovoidpointer)")
*/
    ADD_CLASS_METHOD(SetName,"void vtkAbstractArray::SetName(char const * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#setname)")
    ADD_CLASS_METHOD(GetName,"char * vtkAbstractArray::GetName()  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#getname)")
    ADD_CLASS_METHOD(GetDataTypeAsString,"char const * vtkAbstractArray::GetDataTypeAsString()  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#getdatatypeasstring)")
    ADD_CLASS_METHOD(GetDataSize,"vtkIdType vtkAbstractArray::GetDataSize()  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#getdatasize)")
    ADD_CLASS_METHOD(GetVariantValue,"vtkVariant vtkAbstractArray::GetVariantValue(vtkIdType idx)  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#getvariantvalue)")
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(GetInformation,"vtkInformation * vtkAbstractArray::GetInformation()  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#getinformation)")
*/
    ADD_CLASS_METHOD(HasInformation,"bool vtkAbstractArray::HasInformation()  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#hasinformation)")
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(CopyInformation,"int vtkAbstractArray::CopyInformation(vtkInformation * infoFrom, int deep = 1)  (http://docs.wxwidgets.org/stable/wx_vtkabstractarray.html#copyinformation)")
*/





    void AddMethods(WrapClass<vtkAbstractArray>::ptr this_ptr );

};


#endif // _wrap_vtkAbstractArray_h
