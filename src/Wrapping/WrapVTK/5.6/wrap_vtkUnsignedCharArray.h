/**
 * C++ Interface: wrap_vtkUnsignedCharArray
 *
 * Description: wrapping vtkUnsignedCharArray
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkUnsignedCharArray_h_
#define _wrap_vtkUnsignedCharArray_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

//#include "wrap_vtkDataArrayTemplate_unsigned char_.h"



AMI_DECLARE_TYPE(vtkUnsignedCharArray);

// TODO: check for inheritence ...
class WrapClass_vtkUnsignedCharArray : public WrapClass<vtkUnsignedCharArray>
    //, public  WrapClass_vtkDataArrayTemplate_unsigned char_
{
  DEFINE_CLASS(WrapClass_vtkUnsignedCharArray);

  protected:
    typedef WrapClass<vtkUnsignedCharArray>::ptr _parentclass_ptr;
    typedef vtkUnsignedCharArray ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkUnsignedCharArray>& GetObj() const { return WrapClass<vtkUnsignedCharArray>::GetObj(); }

    /// Constructor
    WrapClass_vtkUnsignedCharArray(boost::shared_ptr<vtkUnsignedCharArray > si): 
    WrapClass<vtkUnsignedCharArray>(si)
    //, WrapClass_vtkDataArrayTemplate_unsigned char_(si)
    {}

    /// Destructor
    ~WrapClass_vtkUnsignedCharArray()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkUnsignedCharArray*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkUnsignedCharArray * vtkUnsignedCharArray::New() (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkUnsignedCharArray::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkUnsignedCharArray * vtkUnsignedCharArray::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkUnsignedCharArray::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkUnsignedCharArray * vtkUnsignedCharArray::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkUnsignedCharArray::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#printself)")
*/
    ADD_CLASS_METHOD(GetDataType,"int vtkUnsignedCharArray::GetDataType()  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#getdatatype)")
    ADD_CLASS_METHOD(GetTupleValue,"void vtkUnsignedCharArray::GetTupleValue(vtkIdType i, unsigned char * tuple)  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#gettuplevalue)")
    ADD_CLASS_METHOD(SetTupleValue,"void vtkUnsignedCharArray::SetTupleValue(vtkIdType i, unsigned char const * tuple)  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#settuplevalue)")
    ADD_CLASS_METHOD(InsertTupleValue,"void vtkUnsignedCharArray::InsertTupleValue(vtkIdType i, unsigned char const * tuple)  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#inserttuplevalue)")
    ADD_CLASS_METHOD(InsertNextTupleValue,"vtkIdType vtkUnsignedCharArray::InsertNextTupleValue(unsigned char const * tuple)  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#insertnexttuplevalue)")
    ADD_CLASS_METHOD(GetValue,"unsigned char vtkUnsignedCharArray::GetValue(vtkIdType id)  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#getvalue)")
    ADD_CLASS_METHOD(SetValue,"void vtkUnsignedCharArray::SetValue(vtkIdType id, unsigned char value)  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#setvalue)")
    ADD_CLASS_METHOD(SetNumberOfValues,"void vtkUnsignedCharArray::SetNumberOfValues(vtkIdType number)  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#setnumberofvalues)")
    ADD_CLASS_METHOD(InsertValue,"void vtkUnsignedCharArray::InsertValue(vtkIdType id, unsigned char f)  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#insertvalue)")
    ADD_CLASS_METHOD(InsertNextValue,"vtkIdType vtkUnsignedCharArray::InsertNextValue(unsigned char f)  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#insertnextvalue)")
    ADD_CLASS_METHOD(WritePointer,"unsigned char * vtkUnsignedCharArray::WritePointer(vtkIdType id, vtkIdType number)  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#writepointer)")
    ADD_CLASS_METHOD(GetPointer,"unsigned char * vtkUnsignedCharArray::GetPointer(vtkIdType id)  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#getpointer)")
    ADD_CLASS_METHOD(SetArray_1,"void vtkUnsignedCharArray::SetArray(unsigned char * array, vtkIdType size, int save)  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#setarray)")
    ADD_CLASS_METHOD(SetArray,"vtkUnsignedCharArray::SetArray()  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#setarray)")
    ADD_CLASS_METHOD(SetArray_2,"void vtkUnsignedCharArray::SetArray(unsigned char * array, vtkIdType size, int save, int deleteMethod)  (http://docs.wxwidgets.org/stable/wx_vtkunsignedchararray.html#setarray)")





    void AddMethods(WrapClass<vtkUnsignedCharArray>::ptr this_ptr );

};


#endif // _wrap_vtkUnsignedCharArray_h
