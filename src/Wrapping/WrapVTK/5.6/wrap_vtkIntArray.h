/**
 * C++ Interface: wrap_vtkIntArray
 *
 * Description: wrapping vtkIntArray
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkIntArray_h_
#define _wrap_vtkIntArray_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkIntArray.h"

// include what is needed for inheritence and for types ...

//#include "wrap_vtkDataArrayTemplate_int_.h"



AMI_DECLARE_TYPE(vtkIntArray);

// TODO: check for inheritence ...
class WrapClass_vtkIntArray : public WrapClass<vtkIntArray>
    //, public  WrapClass_vtkDataArrayTemplate_int_
{
  DEFINE_CLASS(WrapClass_vtkIntArray);

  protected:
    typedef WrapClass<vtkIntArray>::ptr _parentclass_ptr;
    typedef vtkIntArray ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkIntArray>& GetObj() const { return WrapClass<vtkIntArray>::GetObj(); }

    /// Constructor
    WrapClass_vtkIntArray(boost::shared_ptr<vtkIntArray > si): 
    WrapClass<vtkIntArray>(si)
    //, WrapClass_vtkDataArrayTemplate_int_(si)
    {}

    /// Destructor
    ~WrapClass_vtkIntArray()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkIntArray*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkIntArray * vtkIntArray::New() (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkIntArray::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkIntArray * vtkIntArray::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkIntArray::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkIntArray * vtkIntArray::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkIntArray::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#printself)")
*/
    ADD_CLASS_METHOD(GetDataType,"int vtkIntArray::GetDataType()  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#getdatatype)")
    ADD_CLASS_METHOD(GetTupleValue,"void vtkIntArray::GetTupleValue(vtkIdType i, int * tuple)  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#gettuplevalue)")
    ADD_CLASS_METHOD(SetTupleValue,"void vtkIntArray::SetTupleValue(vtkIdType i, int const * tuple)  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#settuplevalue)")
    ADD_CLASS_METHOD(InsertTupleValue,"void vtkIntArray::InsertTupleValue(vtkIdType i, int const * tuple)  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#inserttuplevalue)")
    ADD_CLASS_METHOD(InsertNextTupleValue,"vtkIdType vtkIntArray::InsertNextTupleValue(int const * tuple)  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#insertnexttuplevalue)")
    ADD_CLASS_METHOD(GetValue,"int vtkIntArray::GetValue(vtkIdType id)  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#getvalue)")
    ADD_CLASS_METHOD(SetValue,"void vtkIntArray::SetValue(vtkIdType id, int value)  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#setvalue)")
    ADD_CLASS_METHOD(SetNumberOfValues,"void vtkIntArray::SetNumberOfValues(vtkIdType number)  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#setnumberofvalues)")
    ADD_CLASS_METHOD(InsertValue,"void vtkIntArray::InsertValue(vtkIdType id, int f)  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#insertvalue)")
    ADD_CLASS_METHOD(InsertNextValue,"vtkIdType vtkIntArray::InsertNextValue(int f)  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#insertnextvalue)")
    ADD_CLASS_METHOD(WritePointer,"int * vtkIntArray::WritePointer(vtkIdType id, vtkIdType number)  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#writepointer)")
    ADD_CLASS_METHOD(GetPointer,"int * vtkIntArray::GetPointer(vtkIdType id)  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#getpointer)")
    ADD_CLASS_METHOD(SetArray_1,"void vtkIntArray::SetArray(int * array, vtkIdType size, int save)  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#setarray)")
    ADD_CLASS_METHOD(SetArray,"vtkIntArray::SetArray()  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#setarray)")
    ADD_CLASS_METHOD(SetArray_2,"void vtkIntArray::SetArray(int * array, vtkIdType size, int save, int deleteMethod)  (http://docs.wxwidgets.org/stable/wx_vtkintarray.html#setarray)")





    void AddMethods(WrapClass<vtkIntArray>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkIntArray_h
