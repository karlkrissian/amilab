/**
 * C++ Interface: wrap_vtkInformation
 *
 * Description: wrapping vtkInformation
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkInformation_h_
#define _wrap_vtkInformation_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkInformation.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"


#ifndef vtkInformation_declared
  #define vtkInformation_declared
  AMI_DECLARE_TYPE(vtkInformation);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkInformation : public WrapClass<vtkInformation>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkInformation);

  protected:
    typedef WrapClass<vtkInformation>::ptr _parentclass_ptr;
    typedef vtkInformation ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkInformation>& GetObj() const { return WrapClass<vtkInformation>::GetObj(); }

    /// Constructor
    WrapClass_vtkInformation(boost::shared_ptr<vtkInformation > si): 
    WrapClass<vtkInformation>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkInformation()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkInformation*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkInformation * vtkInformation::New() (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkInformation::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkInformation * vtkInformation::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#safedowncast).");
    /* The following types are missing: vtkInformationKey, vtkInformationDataObjectKey
    ADD_CLASS_STATICMETHOD(GetKey_1,"vtkInformationKey * vtkInformation::GetKey(vtkInformationDataObjectKey * key) (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#getkey).");
    */
    ADD_CLASS_STATICMETHOD(GetKey,"vtkInformation::GetKey() (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#getkey).");
    /* The following types are missing: vtkInformationKey, vtkInformationDoubleKey
    ADD_CLASS_STATICMETHOD(GetKey_2,"vtkInformationKey * vtkInformation::GetKey(vtkInformationDoubleKey * key) (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#getkey).");
    */
    /* The following types are missing: vtkInformationKey, vtkInformationDoubleVectorKey
    ADD_CLASS_STATICMETHOD(GetKey_3,"vtkInformationKey * vtkInformation::GetKey(vtkInformationDoubleVectorKey * key) (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#getkey).");
    */
    /* The following types are missing: vtkInformationKey, vtkInformationInformationKey
    ADD_CLASS_STATICMETHOD(GetKey_4,"vtkInformationKey * vtkInformation::GetKey(vtkInformationInformationKey * key) (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#getkey).");
    */
    /* The following types are missing: vtkInformationKey, vtkInformationInformationVectorKey
    ADD_CLASS_STATICMETHOD(GetKey_5,"vtkInformationKey * vtkInformation::GetKey(vtkInformationInformationVectorKey * key) (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#getkey).");
    */
    /* The following types are missing: vtkInformationKey, vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(GetKey_6,"vtkInformationKey * vtkInformation::GetKey(vtkInformationIntegerKey * key) (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#getkey).");
    */
    /* The following types are missing: vtkInformationKey, vtkInformationIntegerVectorKey
    ADD_CLASS_STATICMETHOD(GetKey_7,"vtkInformationKey * vtkInformation::GetKey(vtkInformationIntegerVectorKey * key) (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#getkey).");
    */
    /* The following types are missing: vtkInformationKey, vtkInformationRequestKey
    ADD_CLASS_STATICMETHOD(GetKey_8,"vtkInformationKey * vtkInformation::GetKey(vtkInformationRequestKey * key) (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#getkey).");
    */
    /* The following types are missing: vtkInformationKey, vtkInformationStringKey
    ADD_CLASS_STATICMETHOD(GetKey_9,"vtkInformationKey * vtkInformation::GetKey(vtkInformationStringKey * key) (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#getkey).");
    */
    /* The following types are missing: vtkInformationKey, vtkInformationStringVectorKey
    ADD_CLASS_STATICMETHOD(GetKey_10,"vtkInformationKey * vtkInformation::GetKey(vtkInformationStringVectorKey * key) (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#getkey).");
    */
    /* The following types are missing: vtkInformationKey, vtkInformationKey
    ADD_CLASS_STATICMETHOD(GetKey_11,"vtkInformationKey * vtkInformation::GetKey(vtkInformationKey * key) (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#getkey).");
    */
    /* The following types are missing: vtkInformationKey, vtkInformationUnsignedLongKey
    ADD_CLASS_STATICMETHOD(GetKey_12,"vtkInformationKey * vtkInformation::GetKey(vtkInformationUnsignedLongKey * key) (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#getkey).");
    */



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkInformation::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkInformation * vtkInformation::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkInformation::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#printself)")
*/
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintKeys,"void vtkInformation::PrintKeys(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#printkeys)")
*/
    ADD_CLASS_METHOD(Modified_1,"void vtkInformation::Modified()  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#modified)")
    ADD_CLASS_METHOD(Modified,"vtkInformation::Modified()  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#modified)")
/* The following types are missing: vtkInformationKey
    ADD_CLASS_METHOD(Modified_2,"void vtkInformation::Modified(vtkInformationKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#modified)")
*/
    ADD_CLASS_METHOD(Clear,"void vtkInformation::Clear()  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#clear)")
    ADD_CLASS_METHOD(GetNumberOfKeys,"int vtkInformation::GetNumberOfKeys()  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#getnumberofkeys)")
    ADD_CLASS_METHOD(Copy,"void vtkInformation::Copy(vtkInformation * from, int deep = 0)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#copy)")
/* The following types are missing: vtkInformationKey
    ADD_CLASS_METHOD(CopyEntry_1,"void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationKey * key, int deep = 0)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#copyentry)")
*/
    ADD_CLASS_METHOD(CopyEntry,"vtkInformation::CopyEntry()  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#copyentry)")
/* The following types are missing: vtkInformationDataObjectKey
    ADD_CLASS_METHOD(CopyEntry_2,"void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationDataObjectKey * key, int deep = 0)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#copyentry)")
*/
/* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_METHOD(CopyEntry_3,"void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationDoubleVectorKey * key, int deep = 0)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#copyentry)")
*/
/* The following types are missing: vtkInformationInformationKey
    ADD_CLASS_METHOD(CopyEntry_4,"void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationInformationKey * key, int deep = 0)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#copyentry)")
*/
/* The following types are missing: vtkInformationInformationVectorKey
    ADD_CLASS_METHOD(CopyEntry_5,"void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationInformationVectorKey * key, int deep = 0)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#copyentry)")
*/
/* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_METHOD(CopyEntry_6,"void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationIntegerKey * key, int deep = 0)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#copyentry)")
*/
/* The following types are missing: vtkInformationIntegerVectorKey
    ADD_CLASS_METHOD(CopyEntry_7,"void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationIntegerVectorKey * key, int deep = 0)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#copyentry)")
*/
/* The following types are missing: vtkInformationRequestKey
    ADD_CLASS_METHOD(CopyEntry_8,"void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationRequestKey * key, int deep = 0)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#copyentry)")
*/
/* The following types are missing: vtkInformationStringKey
    ADD_CLASS_METHOD(CopyEntry_9,"void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationStringKey * key, int deep = 0)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#copyentry)")
*/
/* The following types are missing: vtkInformationStringVectorKey
    ADD_CLASS_METHOD(CopyEntry_10,"void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationStringVectorKey * key, int deep = 0)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#copyentry)")
*/
/* The following types are missing: vtkInformationUnsignedLongKey
    ADD_CLASS_METHOD(CopyEntry_11,"void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationUnsignedLongKey * key, int deep = 0)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#copyentry)")
*/
/* The following types are missing: vtkInformationKeyVectorKey
    ADD_CLASS_METHOD(CopyEntries,"void vtkInformation::CopyEntries(vtkInformation * from, vtkInformationKeyVectorKey * key, int deep = 0)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#copyentries)")
*/
/* The following types are missing: vtkInformationKey
    ADD_CLASS_METHOD(Has_1,"int vtkInformation::Has(vtkInformationKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
*/
/* The following types are missing: vtkInformationKey
    ADD_CLASS_METHOD(Remove_1,"void vtkInformation::Remove(vtkInformationKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
/* The following types are missing: vtkInformationRequestKey
    ADD_CLASS_METHOD(Set_1,"void vtkInformation::Set(vtkInformationRequestKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
    ADD_CLASS_METHOD(Remove,"vtkInformation::Remove()  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
/* The following types are missing: vtkInformationRequestKey
    ADD_CLASS_METHOD(Remove_2,"void vtkInformation::Remove(vtkInformationRequestKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
    ADD_CLASS_METHOD(Has,"vtkInformation::Has()  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
/* The following types are missing: vtkInformationRequestKey
    ADD_CLASS_METHOD(Has_2,"int vtkInformation::Has(vtkInformationRequestKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
*/
    ADD_CLASS_METHOD(Set,"vtkInformation::Set()  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
/* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_METHOD(Set_2,"void vtkInformation::Set(vtkInformationIntegerKey * key, int value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_METHOD(Get_1,"int vtkInformation::Get(vtkInformationIntegerKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_METHOD(Remove_3,"void vtkInformation::Remove(vtkInformationIntegerKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
/* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_METHOD(Has_3,"int vtkInformation::Has(vtkInformationIntegerKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
*/
/* The following types are missing: vtkInformationIdTypeKey
    ADD_CLASS_METHOD(Set_3,"void vtkInformation::Set(vtkInformationIdTypeKey * key, vtkIdType value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
    ADD_CLASS_METHOD(Get,"vtkInformation::Get()  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
/* The following types are missing: vtkInformationIdTypeKey
    ADD_CLASS_METHOD(Get_2,"vtkIdType vtkInformation::Get(vtkInformationIdTypeKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationIdTypeKey
    ADD_CLASS_METHOD(Remove_4,"void vtkInformation::Remove(vtkInformationIdTypeKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
/* The following types are missing: vtkInformationIdTypeKey
    ADD_CLASS_METHOD(Has_4,"int vtkInformation::Has(vtkInformationIdTypeKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
*/
/* The following types are missing: vtkInformationDoubleKey
    ADD_CLASS_METHOD(Set_4,"void vtkInformation::Set(vtkInformationDoubleKey * key, double value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationDoubleKey
    ADD_CLASS_METHOD(Get_3,"double vtkInformation::Get(vtkInformationDoubleKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationDoubleKey
    ADD_CLASS_METHOD(Remove_5,"void vtkInformation::Remove(vtkInformationDoubleKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
/* The following types are missing: vtkInformationDoubleKey
    ADD_CLASS_METHOD(Has_5,"int vtkInformation::Has(vtkInformationDoubleKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
*/
/* The following types are missing: vtkInformationIntegerVectorKey
    ADD_CLASS_METHOD(Append_1,"void vtkInformation::Append(vtkInformationIntegerVectorKey * key, int value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#append)")
*/
/* The following types are missing: vtkInformationIntegerVectorKey
    ADD_CLASS_METHOD(Set_5,"void vtkInformation::Set(vtkInformationIntegerVectorKey * key, int * value, int length)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationIntegerVectorKey
    ADD_CLASS_METHOD(Set_6,"void vtkInformation::Set(vtkInformationIntegerVectorKey * key, int value1, int value2, int value3)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationIntegerVectorKey
    ADD_CLASS_METHOD(Set_7,"void vtkInformation::Set(vtkInformationIntegerVectorKey * key, int value1, int value2, int value3, int value4, int value5, int value6)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationIntegerVectorKey
    ADD_CLASS_METHOD(Get_4,"int * vtkInformation::Get(vtkInformationIntegerVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationIntegerVectorKey
    ADD_CLASS_METHOD(Get_5,"int vtkInformation::Get(vtkInformationIntegerVectorKey * key, int idx)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationIntegerVectorKey
    ADD_CLASS_METHOD(Get_6,"void vtkInformation::Get(vtkInformationIntegerVectorKey * key, int * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationIntegerVectorKey
    ADD_CLASS_METHOD(Length_1,"int vtkInformation::Length(vtkInformationIntegerVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#length)")
*/
/* The following types are missing: vtkInformationIntegerVectorKey
    ADD_CLASS_METHOD(Remove_6,"void vtkInformation::Remove(vtkInformationIntegerVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
/* The following types are missing: vtkInformationIntegerVectorKey
    ADD_CLASS_METHOD(Has_6,"int vtkInformation::Has(vtkInformationIntegerVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
*/
    ADD_CLASS_METHOD(Append,"vtkInformation::Append()  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#append)")
/* The following types are missing: vtkInformationStringVectorKey
    ADD_CLASS_METHOD(Append_2,"void vtkInformation::Append(vtkInformationStringVectorKey * key, char const * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#append)")
*/
/* The following types are missing: vtkInformationStringVectorKey
    ADD_CLASS_METHOD(Set_8,"void vtkInformation::Set(vtkInformationStringVectorKey * key, char const * value, int idx = 0)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationStringVectorKey
    ADD_CLASS_METHOD(Get_7,"char const * vtkInformation::Get(vtkInformationStringVectorKey * key, int idx = 0)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
    ADD_CLASS_METHOD(Length,"vtkInformation::Length()  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#length)")
/* The following types are missing: vtkInformationStringVectorKey
    ADD_CLASS_METHOD(Length_2,"int vtkInformation::Length(vtkInformationStringVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#length)")
*/
/* The following types are missing: vtkInformationStringVectorKey
    ADD_CLASS_METHOD(Remove_7,"void vtkInformation::Remove(vtkInformationStringVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
/* The following types are missing: vtkInformationStringVectorKey
    ADD_CLASS_METHOD(Has_7,"int vtkInformation::Has(vtkInformationStringVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
*/
/* The following types are missing: vtkInformationIntegerPointerKey
    ADD_CLASS_METHOD(Set_9,"void vtkInformation::Set(vtkInformationIntegerPointerKey * key, int * value, int length)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationIntegerPointerKey
    ADD_CLASS_METHOD(Get_8,"int * vtkInformation::Get(vtkInformationIntegerPointerKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationIntegerPointerKey
    ADD_CLASS_METHOD(Get_9,"void vtkInformation::Get(vtkInformationIntegerPointerKey * key, int * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationIntegerPointerKey
    ADD_CLASS_METHOD(Length_3,"int vtkInformation::Length(vtkInformationIntegerPointerKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#length)")
*/
/* The following types are missing: vtkInformationIntegerPointerKey
    ADD_CLASS_METHOD(Remove_8,"void vtkInformation::Remove(vtkInformationIntegerPointerKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
/* The following types are missing: vtkInformationIntegerPointerKey
    ADD_CLASS_METHOD(Has_8,"int vtkInformation::Has(vtkInformationIntegerPointerKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
*/
/* The following types are missing: vtkInformationUnsignedLongKey
    ADD_CLASS_METHOD(Set_10,"void vtkInformation::Set(vtkInformationUnsignedLongKey * key, long unsigned int value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationUnsignedLongKey
    ADD_CLASS_METHOD(Get_10,"long unsigned int vtkInformation::Get(vtkInformationUnsignedLongKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationUnsignedLongKey
    ADD_CLASS_METHOD(Remove_9,"void vtkInformation::Remove(vtkInformationUnsignedLongKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
/* The following types are missing: vtkInformationUnsignedLongKey
    ADD_CLASS_METHOD(Has_9,"int vtkInformation::Has(vtkInformationUnsignedLongKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
*/
/* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_METHOD(Append_3,"void vtkInformation::Append(vtkInformationDoubleVectorKey * key, double value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#append)")
*/
/* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_METHOD(Set_11,"void vtkInformation::Set(vtkInformationDoubleVectorKey * key, double * value, int length)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_METHOD(Set_12,"void vtkInformation::Set(vtkInformationDoubleVectorKey * key, double value1, double value2, double value3)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_METHOD(Set_13,"void vtkInformation::Set(vtkInformationDoubleVectorKey * key, double value1, double value2, double value3, double value4, double value5, double value6)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_METHOD(Get_11,"double * vtkInformation::Get(vtkInformationDoubleVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_METHOD(Get_12,"double vtkInformation::Get(vtkInformationDoubleVectorKey * key, int idx)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_METHOD(Get_13,"void vtkInformation::Get(vtkInformationDoubleVectorKey * key, double * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_METHOD(Length_4,"int vtkInformation::Length(vtkInformationDoubleVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#length)")
*/
/* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_METHOD(Remove_10,"void vtkInformation::Remove(vtkInformationDoubleVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
/* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_METHOD(Has_10,"int vtkInformation::Has(vtkInformationDoubleVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationKey
    ADD_CLASS_METHOD(Append_4,"void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#append)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationKey
    ADD_CLASS_METHOD(AppendUnique_1,"void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#appendunique)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationKey
    ADD_CLASS_METHOD(Set_14,"void vtkInformation::Set(vtkInformationKeyVectorKey * key, vtkInformationKey * * value, int length)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationKey
    ADD_CLASS_METHOD(Remove_11,"void vtkInformation::Remove(vtkInformationKeyVectorKey * key, vtkInformationKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
/* The following types are missing: vtkInformationKey, vtkInformationKeyVectorKey
    ADD_CLASS_METHOD(Get_14,"vtkInformationKey * * vtkInformation::Get(vtkInformationKeyVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationKey, vtkInformationKeyVectorKey
    ADD_CLASS_METHOD(Get_15,"vtkInformationKey * vtkInformation::Get(vtkInformationKeyVectorKey * key, int idx)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationKey
    ADD_CLASS_METHOD(Get_16,"void vtkInformation::Get(vtkInformationKeyVectorKey * key, vtkInformationKey * * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationKeyVectorKey
    ADD_CLASS_METHOD(Length_5,"int vtkInformation::Length(vtkInformationKeyVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#length)")
*/
/* The following types are missing: vtkInformationKeyVectorKey
    ADD_CLASS_METHOD(Remove_12,"void vtkInformation::Remove(vtkInformationKeyVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
/* The following types are missing: vtkInformationKeyVectorKey
    ADD_CLASS_METHOD(Has_11,"int vtkInformation::Has(vtkInformationKeyVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDataObjectKey
    ADD_CLASS_METHOD(Append_5,"void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationDataObjectKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#append)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDoubleKey
    ADD_CLASS_METHOD(Append_6,"void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationDoubleKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#append)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDoubleVectorKey
    ADD_CLASS_METHOD(Append_7,"void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationDoubleVectorKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#append)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationInformationKey
    ADD_CLASS_METHOD(Append_8,"void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationInformationKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#append)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationInformationVectorKey
    ADD_CLASS_METHOD(Append_9,"void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationInformationVectorKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#append)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationIntegerKey
    ADD_CLASS_METHOD(Append_10,"void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationIntegerKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#append)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationIntegerVectorKey
    ADD_CLASS_METHOD(Append_11,"void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationIntegerVectorKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#append)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationStringKey
    ADD_CLASS_METHOD(Append_12,"void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationStringKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#append)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationStringVectorKey
    ADD_CLASS_METHOD(Append_13,"void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationStringVectorKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#append)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationObjectBaseKey
    ADD_CLASS_METHOD(Append_14,"void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationObjectBaseKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#append)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationUnsignedLongKey
    ADD_CLASS_METHOD(Append_15,"void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationUnsignedLongKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#append)")
*/
    ADD_CLASS_METHOD(AppendUnique,"vtkInformation::AppendUnique()  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#appendunique)")
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDataObjectKey
    ADD_CLASS_METHOD(AppendUnique_2,"void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationDataObjectKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#appendunique)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDoubleKey
    ADD_CLASS_METHOD(AppendUnique_3,"void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationDoubleKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#appendunique)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDoubleVectorKey
    ADD_CLASS_METHOD(AppendUnique_4,"void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationDoubleVectorKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#appendunique)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationInformationKey
    ADD_CLASS_METHOD(AppendUnique_5,"void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationInformationKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#appendunique)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationInformationVectorKey
    ADD_CLASS_METHOD(AppendUnique_6,"void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationInformationVectorKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#appendunique)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationIntegerKey
    ADD_CLASS_METHOD(AppendUnique_7,"void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationIntegerKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#appendunique)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationIntegerVectorKey
    ADD_CLASS_METHOD(AppendUnique_8,"void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationIntegerVectorKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#appendunique)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationStringKey
    ADD_CLASS_METHOD(AppendUnique_9,"void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationStringKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#appendunique)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationStringVectorKey
    ADD_CLASS_METHOD(AppendUnique_10,"void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationStringVectorKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#appendunique)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationObjectBaseKey
    ADD_CLASS_METHOD(AppendUnique_11,"void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationObjectBaseKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#appendunique)")
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationUnsignedLongKey
    ADD_CLASS_METHOD(AppendUnique_12,"void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationUnsignedLongKey * value)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#appendunique)")
*/
/* The following types are missing: vtkInformationStringKey
    ADD_CLASS_METHOD(Set_15,"void vtkInformation::Set(vtkInformationStringKey * key, char const * param1)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationStringKey
    ADD_CLASS_METHOD(Get_17,"char const * vtkInformation::Get(vtkInformationStringKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationStringKey
    ADD_CLASS_METHOD(Remove_13,"void vtkInformation::Remove(vtkInformationStringKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
/* The following types are missing: vtkInformationStringKey
    ADD_CLASS_METHOD(Has_12,"int vtkInformation::Has(vtkInformationStringKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
*/
/* The following types are missing: vtkInformationInformationKey
    ADD_CLASS_METHOD(Set_16,"void vtkInformation::Set(vtkInformationInformationKey * key, vtkInformation * param1)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationInformationKey
    ADD_CLASS_METHOD(Get_18,"vtkInformation * vtkInformation::Get(vtkInformationInformationKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationInformationKey
    ADD_CLASS_METHOD(Remove_14,"void vtkInformation::Remove(vtkInformationInformationKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
/* The following types are missing: vtkInformationInformationKey
    ADD_CLASS_METHOD(Has_13,"int vtkInformation::Has(vtkInformationInformationKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
*/
/* The following types are missing: vtkInformationInformationVectorKey, vtkInformationVector
    ADD_CLASS_METHOD(Set_17,"void vtkInformation::Set(vtkInformationInformationVectorKey * key, vtkInformationVector * param1)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationVector, vtkInformationInformationVectorKey
    ADD_CLASS_METHOD(Get_19,"vtkInformationVector * vtkInformation::Get(vtkInformationInformationVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationInformationVectorKey
    ADD_CLASS_METHOD(Remove_15,"void vtkInformation::Remove(vtkInformationInformationVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
/* The following types are missing: vtkInformationInformationVectorKey
    ADD_CLASS_METHOD(Has_14,"int vtkInformation::Has(vtkInformationInformationVectorKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
*/
/* The following types are missing: vtkInformationObjectBaseKey
    ADD_CLASS_METHOD(Set_18,"void vtkInformation::Set(vtkInformationObjectBaseKey * key, vtkObjectBase * param1)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationObjectBaseKey
    ADD_CLASS_METHOD(Get_20,"vtkObjectBase * vtkInformation::Get(vtkInformationObjectBaseKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationObjectBaseKey
    ADD_CLASS_METHOD(Remove_16,"void vtkInformation::Remove(vtkInformationObjectBaseKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
/* The following types are missing: vtkInformationObjectBaseKey
    ADD_CLASS_METHOD(Has_15,"int vtkInformation::Has(vtkInformationObjectBaseKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
*/
/* The following types are missing: vtkInformationDataObjectKey
    ADD_CLASS_METHOD(Set_19,"void vtkInformation::Set(vtkInformationDataObjectKey * key, vtkDataObject * param1)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#set)")
*/
/* The following types are missing: vtkInformationDataObjectKey
    ADD_CLASS_METHOD(Get_21,"vtkDataObject * vtkInformation::Get(vtkInformationDataObjectKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#get)")
*/
/* The following types are missing: vtkInformationDataObjectKey
    ADD_CLASS_METHOD(Remove_17,"void vtkInformation::Remove(vtkInformationDataObjectKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#remove)")
*/
/* The following types are missing: vtkInformationDataObjectKey
    ADD_CLASS_METHOD(Has_16,"int vtkInformation::Has(vtkInformationDataObjectKey * key)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#has)")
*/
    ADD_CLASS_METHOD(Register,"void vtkInformation::Register(vtkObjectBase * o)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#register)")
    ADD_CLASS_METHOD(UnRegister,"void vtkInformation::UnRegister(vtkObjectBase * o)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#unregister)")
/* The following types are missing: vtkInformationRequestKey
    ADD_CLASS_METHOD(SetRequest,"void vtkInformation::SetRequest(vtkInformationRequestKey * request)  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#setrequest)")
*/
/* The following types are missing: vtkInformationRequestKey
    ADD_CLASS_METHOD(GetRequest,"vtkInformationRequestKey * vtkInformation::GetRequest()  (http://docs.wxwidgets.org/stable/wx_vtkinformation.html#getrequest)")
*/





    void AddMethods(WrapClass<vtkInformation>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkInformation_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkInformation_h
