/**
 * C++ Interface: wrap_vtkInformation
 *
 * Description: wrapping vtkInformation
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

/*
//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
*/

#include "wrap_vtkInformation.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef vtkInformation_declared
  #define vtkInformation_declared
  AMI_DECLARE_TYPE(vtkInformation)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkDataObject_declared
  #define vtkDataObject_declared
  AMI_DECLARE_TYPE(vtkDataObject)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkInformation>::CreateVar( ParamList* p)
{
  WrapClass_vtkInformation::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkInformation);
AMI_DEFINE_VARFROMSMTPTR(vtkInformation);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkInformation>::CreateVar( vtkInformation* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkInformation> obj_ptr(val,smartpointer_nodeleter<vtkInformation>());
  return AMILabType<vtkInformation>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkInformation
//
Variable<AMIObject>::ptr WrapClass_vtkInformation::CreateVar( vtkInformation* sp)
{
  boost::shared_ptr<vtkInformation> di_ptr(
    sp,
    wxwindow_nodeleter<vtkInformation>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkInformation>::CreateVar(
      new WrapClass_vtkInformation(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkInformation::AddMethods(WrapClass<vtkInformation>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintKeys( this_ptr);
*/
  AddVar_Modified_1( this_ptr);
  AddVar_Modified( this_ptr);
/* The following types are missing: vtkInformationKey
  AddVar_Modified_2( this_ptr);
*/
  AddVar_Clear( this_ptr);
  AddVar_GetNumberOfKeys( this_ptr);
  AddVar_Copy( this_ptr);
/* The following types are missing: vtkInformationKey
  AddVar_CopyEntry_1( this_ptr);
*/
  AddVar_CopyEntry( this_ptr);
/* The following types are missing: vtkInformationDataObjectKey
  AddVar_CopyEntry_2( this_ptr);
*/
/* The following types are missing: vtkInformationDoubleVectorKey
  AddVar_CopyEntry_3( this_ptr);
*/
/* The following types are missing: vtkInformationInformationKey
  AddVar_CopyEntry_4( this_ptr);
*/
/* The following types are missing: vtkInformationInformationVectorKey
  AddVar_CopyEntry_5( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerKey
  AddVar_CopyEntry_6( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerVectorKey
  AddVar_CopyEntry_7( this_ptr);
*/
/* The following types are missing: vtkInformationRequestKey
  AddVar_CopyEntry_8( this_ptr);
*/
/* The following types are missing: vtkInformationStringKey
  AddVar_CopyEntry_9( this_ptr);
*/
/* The following types are missing: vtkInformationStringVectorKey
  AddVar_CopyEntry_10( this_ptr);
*/
/* The following types are missing: vtkInformationUnsignedLongKey
  AddVar_CopyEntry_11( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey
  AddVar_CopyEntries( this_ptr);
*/
/* The following types are missing: vtkInformationKey
  AddVar_Has_1( this_ptr);
*/
/* The following types are missing: vtkInformationKey
  AddVar_Remove_1( this_ptr);
*/
/* The following types are missing: vtkInformationRequestKey
  AddVar_Set_1( this_ptr);
*/
  AddVar_Remove( this_ptr);
/* The following types are missing: vtkInformationRequestKey
  AddVar_Remove_2( this_ptr);
*/
  AddVar_Has( this_ptr);
/* The following types are missing: vtkInformationRequestKey
  AddVar_Has_2( this_ptr);
*/
  AddVar_Set( this_ptr);
/* The following types are missing: vtkInformationIntegerKey
  AddVar_Set_2( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerKey
  AddVar_Get_1( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerKey
  AddVar_Remove_3( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerKey
  AddVar_Has_3( this_ptr);
*/
/* The following types are missing: vtkInformationIdTypeKey
  AddVar_Set_3( this_ptr);
*/
  AddVar_Get( this_ptr);
/* The following types are missing: vtkInformationIdTypeKey
  AddVar_Get_2( this_ptr);
*/
/* The following types are missing: vtkInformationIdTypeKey
  AddVar_Remove_4( this_ptr);
*/
/* The following types are missing: vtkInformationIdTypeKey
  AddVar_Has_4( this_ptr);
*/
/* The following types are missing: vtkInformationDoubleKey
  AddVar_Set_4( this_ptr);
*/
/* The following types are missing: vtkInformationDoubleKey
  AddVar_Get_3( this_ptr);
*/
/* The following types are missing: vtkInformationDoubleKey
  AddVar_Remove_5( this_ptr);
*/
/* The following types are missing: vtkInformationDoubleKey
  AddVar_Has_5( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerVectorKey
  AddVar_Append_1( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerVectorKey
  AddVar_Set_5( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerVectorKey
  AddVar_Set_6( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerVectorKey
  AddVar_Set_7( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerVectorKey
  AddVar_Get_4( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerVectorKey
  AddVar_Get_5( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerVectorKey
  AddVar_Get_6( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerVectorKey
  AddVar_Length_1( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerVectorKey
  AddVar_Remove_6( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerVectorKey
  AddVar_Has_6( this_ptr);
*/
  AddVar_Append( this_ptr);
/* The following types are missing: vtkInformationStringVectorKey
  AddVar_Append_2( this_ptr);
*/
/* The following types are missing: vtkInformationStringVectorKey
  AddVar_Set_8( this_ptr);
*/
/* The following types are missing: vtkInformationStringVectorKey
  AddVar_Get_7( this_ptr);
*/
  AddVar_Length( this_ptr);
/* The following types are missing: vtkInformationStringVectorKey
  AddVar_Length_2( this_ptr);
*/
/* The following types are missing: vtkInformationStringVectorKey
  AddVar_Remove_7( this_ptr);
*/
/* The following types are missing: vtkInformationStringVectorKey
  AddVar_Has_7( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerPointerKey
  AddVar_Set_9( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerPointerKey
  AddVar_Get_8( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerPointerKey
  AddVar_Get_9( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerPointerKey
  AddVar_Length_3( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerPointerKey
  AddVar_Remove_8( this_ptr);
*/
/* The following types are missing: vtkInformationIntegerPointerKey
  AddVar_Has_8( this_ptr);
*/
/* The following types are missing: vtkInformationUnsignedLongKey
  AddVar_Set_10( this_ptr);
*/
/* The following types are missing: vtkInformationUnsignedLongKey
  AddVar_Get_10( this_ptr);
*/
/* The following types are missing: vtkInformationUnsignedLongKey
  AddVar_Remove_9( this_ptr);
*/
/* The following types are missing: vtkInformationUnsignedLongKey
  AddVar_Has_9( this_ptr);
*/
/* The following types are missing: vtkInformationDoubleVectorKey
  AddVar_Append_3( this_ptr);
*/
/* The following types are missing: vtkInformationDoubleVectorKey
  AddVar_Set_11( this_ptr);
*/
/* The following types are missing: vtkInformationDoubleVectorKey
  AddVar_Set_12( this_ptr);
*/
/* The following types are missing: vtkInformationDoubleVectorKey
  AddVar_Set_13( this_ptr);
*/
/* The following types are missing: vtkInformationDoubleVectorKey
  AddVar_Get_11( this_ptr);
*/
/* The following types are missing: vtkInformationDoubleVectorKey
  AddVar_Get_12( this_ptr);
*/
/* The following types are missing: vtkInformationDoubleVectorKey
  AddVar_Get_13( this_ptr);
*/
/* The following types are missing: vtkInformationDoubleVectorKey
  AddVar_Length_4( this_ptr);
*/
/* The following types are missing: vtkInformationDoubleVectorKey
  AddVar_Remove_10( this_ptr);
*/
/* The following types are missing: vtkInformationDoubleVectorKey
  AddVar_Has_10( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationKey
  AddVar_Append_4( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationKey
  AddVar_AppendUnique_1( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationKey
  AddVar_Set_14( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationKey
  AddVar_Remove_11( this_ptr);
*/
/* The following types are missing: vtkInformationKey, vtkInformationKeyVectorKey
  AddVar_Get_14( this_ptr);
*/
/* The following types are missing: vtkInformationKey, vtkInformationKeyVectorKey
  AddVar_Get_15( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationKey
  AddVar_Get_16( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey
  AddVar_Length_5( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey
  AddVar_Remove_12( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey
  AddVar_Has_11( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDataObjectKey
  AddVar_Append_5( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDoubleKey
  AddVar_Append_6( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDoubleVectorKey
  AddVar_Append_7( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationInformationKey
  AddVar_Append_8( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationInformationVectorKey
  AddVar_Append_9( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationIntegerKey
  AddVar_Append_10( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationIntegerVectorKey
  AddVar_Append_11( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationStringKey
  AddVar_Append_12( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationStringVectorKey
  AddVar_Append_13( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationObjectBaseKey
  AddVar_Append_14( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationUnsignedLongKey
  AddVar_Append_15( this_ptr);
*/
  AddVar_AppendUnique( this_ptr);
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDataObjectKey
  AddVar_AppendUnique_2( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDoubleKey
  AddVar_AppendUnique_3( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDoubleVectorKey
  AddVar_AppendUnique_4( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationInformationKey
  AddVar_AppendUnique_5( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationInformationVectorKey
  AddVar_AppendUnique_6( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationIntegerKey
  AddVar_AppendUnique_7( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationIntegerVectorKey
  AddVar_AppendUnique_8( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationStringKey
  AddVar_AppendUnique_9( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationStringVectorKey
  AddVar_AppendUnique_10( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationObjectBaseKey
  AddVar_AppendUnique_11( this_ptr);
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationUnsignedLongKey
  AddVar_AppendUnique_12( this_ptr);
*/
/* The following types are missing: vtkInformationStringKey
  AddVar_Set_15( this_ptr);
*/
/* The following types are missing: vtkInformationStringKey
  AddVar_Get_17( this_ptr);
*/
/* The following types are missing: vtkInformationStringKey
  AddVar_Remove_13( this_ptr);
*/
/* The following types are missing: vtkInformationStringKey
  AddVar_Has_12( this_ptr);
*/
/* The following types are missing: vtkInformationInformationKey
  AddVar_Set_16( this_ptr);
*/
/* The following types are missing: vtkInformationInformationKey
  AddVar_Get_18( this_ptr);
*/
/* The following types are missing: vtkInformationInformationKey
  AddVar_Remove_14( this_ptr);
*/
/* The following types are missing: vtkInformationInformationKey
  AddVar_Has_13( this_ptr);
*/
/* The following types are missing: vtkInformationInformationVectorKey, vtkInformationVector
  AddVar_Set_17( this_ptr);
*/
/* The following types are missing: vtkInformationVector, vtkInformationInformationVectorKey
  AddVar_Get_19( this_ptr);
*/
/* The following types are missing: vtkInformationInformationVectorKey
  AddVar_Remove_15( this_ptr);
*/
/* The following types are missing: vtkInformationInformationVectorKey
  AddVar_Has_14( this_ptr);
*/
/* The following types are missing: vtkInformationObjectBaseKey
  AddVar_Set_18( this_ptr);
*/
/* The following types are missing: vtkInformationObjectBaseKey
  AddVar_Get_20( this_ptr);
*/
/* The following types are missing: vtkInformationObjectBaseKey
  AddVar_Remove_16( this_ptr);
*/
/* The following types are missing: vtkInformationObjectBaseKey
  AddVar_Has_15( this_ptr);
*/
/* The following types are missing: vtkInformationDataObjectKey
  AddVar_Set_19( this_ptr);
*/
/* The following types are missing: vtkInformationDataObjectKey
  AddVar_Get_21( this_ptr);
*/
/* The following types are missing: vtkInformationDataObjectKey
  AddVar_Remove_17( this_ptr);
*/
/* The following types are missing: vtkInformationDataObjectKey
  AddVar_Has_16( this_ptr);
*/
  AddVar_Register( this_ptr);
  AddVar_UnRegister( this_ptr);
/* The following types are missing: vtkInformationRequestKey
  AddVar_SetRequest( this_ptr);
*/
/* The following types are missing: vtkInformationRequestKey
  AddVar_GetRequest( this_ptr);
*/



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent vtkObject
  boost::shared_ptr<vtkObject > parent_vtkObject(  boost::dynamic_pointer_cast<vtkObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkObject = AMILabType<vtkObject >::CreateVarFromSmtPtr(parent_vtkObject);
  context->AddVar("vtkObject",var_vtkObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkObject);
  context->AddDefault(obj_vtkObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkInformation_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkInformation");
  
  // Static methods 
  WrapClass_vtkInformation::AddVar_New(amiobject->GetContext());
  WrapClass_vtkInformation::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkInformation::AddVar_SafeDownCast(amiobject->GetContext());
  /* Types are missing
  WrapClass_vtkInformation::AddVar_GetKey_1(amiobject->GetContext());
  */
  WrapClass_vtkInformation::AddVar_GetKey(amiobject->GetContext());
  /* Types are missing
  WrapClass_vtkInformation::AddVar_GetKey_2(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkInformation::AddVar_GetKey_3(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkInformation::AddVar_GetKey_4(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkInformation::AddVar_GetKey_5(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkInformation::AddVar_GetKey_6(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkInformation::AddVar_GetKey_7(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkInformation::AddVar_GetKey_8(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkInformation::AddVar_GetKey_9(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkInformation::AddVar_GetKey_10(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkInformation::AddVar_GetKey_11(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkInformation::AddVar_GetKey_12(amiobject->GetContext());
  */

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkInformation * vtkInformation::New()
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformation";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformation * res =   vtkInformation::New();
  BasicVariable::ptr res_var = AMILabType<vtkInformation >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkInformation::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkInformation::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkInformation * vtkInformation::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkInformation";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkObjectBase* o;
  if (CheckNullVar(_p,_n))  {
    o=(vtkObjectBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkObjectBase > o_smtptr;
    if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    o = o_smtptr.get();
  }

  vtkInformation * res =   vtkInformation::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkInformation >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: vtkInformationKey, vtkInformationDataObjectKey

//---------------------------------------------------
//  Wrapping of vtkInformationKey * vtkInformation::GetKey(vtkInformationDataObjectKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_static_GetKey_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDataObjectKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkInformationKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_static_GetKey_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDataObjectKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDataObjectKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDataObjectKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDataObjectKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey * res =   vtkInformation::GetKey(key);
  return AMILabType<vtkInformationKey >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... static vtkInformation::GetKey(...)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_static_GetKey::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_static_GetKey::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformationKey, vtkInformationDoubleKey

//---------------------------------------------------
//  Wrapping of vtkInformationKey * vtkInformation::GetKey(vtkInformationDoubleKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_static_GetKey_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkInformationKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_static_GetKey_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDoubleKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey * res =   vtkInformation::GetKey(key);
  return AMILabType<vtkInformationKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationKey, vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationKey * vtkInformation::GetKey(vtkInformationDoubleVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_static_GetKey_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkInformationKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_static_GetKey_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDoubleVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey * res =   vtkInformation::GetKey(key);
  return AMILabType<vtkInformationKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationKey, vtkInformationInformationKey

//---------------------------------------------------
//  Wrapping of vtkInformationKey * vtkInformation::GetKey(vtkInformationInformationKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_static_GetKey_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationInformationKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkInformationKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_static_GetKey_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationInformationKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationInformationKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationInformationKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationInformationKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey * res =   vtkInformation::GetKey(key);
  return AMILabType<vtkInformationKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationKey, vtkInformationInformationVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationKey * vtkInformation::GetKey(vtkInformationInformationVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_static_GetKey_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationInformationVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkInformationKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_static_GetKey_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationInformationVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationInformationVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationInformationVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationInformationVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey * res =   vtkInformation::GetKey(key);
  return AMILabType<vtkInformationKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationKey, vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationKey * vtkInformation::GetKey(vtkInformationIntegerKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_static_GetKey_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkInformationKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_static_GetKey_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey * res =   vtkInformation::GetKey(key);
  return AMILabType<vtkInformationKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationKey, vtkInformationIntegerVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationKey * vtkInformation::GetKey(vtkInformationIntegerVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_static_GetKey_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkInformationKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_static_GetKey_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey * res =   vtkInformation::GetKey(key);
  return AMILabType<vtkInformationKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationKey, vtkInformationRequestKey

//---------------------------------------------------
//  Wrapping of vtkInformationKey * vtkInformation::GetKey(vtkInformationRequestKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_static_GetKey_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationRequestKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkInformationKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_static_GetKey_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationRequestKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationRequestKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationRequestKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationRequestKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey * res =   vtkInformation::GetKey(key);
  return AMILabType<vtkInformationKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationKey, vtkInformationStringKey

//---------------------------------------------------
//  Wrapping of vtkInformationKey * vtkInformation::GetKey(vtkInformationStringKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_static_GetKey_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationStringKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkInformationKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_static_GetKey_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationStringKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationStringKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey * res =   vtkInformation::GetKey(key);
  return AMILabType<vtkInformationKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationKey, vtkInformationStringVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationKey * vtkInformation::GetKey(vtkInformationStringVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_static_GetKey_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationStringVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkInformationKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_static_GetKey_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationStringVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationStringVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey * res =   vtkInformation::GetKey(key);
  return AMILabType<vtkInformationKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationKey, vtkInformationKey

//---------------------------------------------------
//  Wrapping of vtkInformationKey * vtkInformation::GetKey(vtkInformationKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_static_GetKey_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkInformationKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_static_GetKey_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey * res =   vtkInformation::GetKey(key);
  return AMILabType<vtkInformationKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationKey, vtkInformationUnsignedLongKey

//---------------------------------------------------
//  Wrapping of vtkInformationKey * vtkInformation::GetKey(vtkInformationUnsignedLongKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_static_GetKey_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationUnsignedLongKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkInformationKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_static_GetKey_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationUnsignedLongKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationUnsignedLongKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationUnsignedLongKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationUnsignedLongKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey * res =   vtkInformation::GetKey(key);
  return AMILabType<vtkInformationKey >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of int vtkInformation::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_IsA::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   this->_objectptr->GetObj()->IsA(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkInformation * vtkInformation::NewInstance()
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformation";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformation * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkInformation >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkInformation::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_PrintSelf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<basic_ostream<char,std::char_traits<char> > > os_smtptr;
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!get_val_param<vtkIndent >(indent,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PrintSelf(os, indent);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkInformation::PrintKeys(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_PrintKeys::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_PrintKeys::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<basic_ostream<char,std::char_traits<char> > > os_smtptr;
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!get_val_param<vtkIndent >(indent,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PrintKeys(os, indent);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkInformation::Modified()
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Modified_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Modified_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Modified();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkInformation::Modified(...)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Modified::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Modified::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkInformation::wrap_Modified_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformationKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Modified(vtkInformationKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Modified_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Modified_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Modified(key);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkInformation::Clear()
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkInformation::GetNumberOfKeys()
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_GetNumberOfKeys::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_GetNumberOfKeys::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfKeys();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkInformation::Copy(vtkInformation * from, int deep = 0)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Copy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'from'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deep' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Copy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkInformation* from;
  if (CheckNullVar(_p,_n))  {
    from=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > from_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(from_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    from = from_smtptr.get();
  }

  int deep = 0;
  if (!get_val_param<int >(deep,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Copy(from, deep);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkInformationKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationKey * key, int deep = 0)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_CopyEntry_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'from'")
  ADDPARAMCOMMENT_TYPE( vtkInformationKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deep' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_CopyEntry_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkInformation* from;
  if (CheckNullVar(_p,_n))  {
    from=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > from_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(from_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    from = from_smtptr.get();
  }

  vtkInformationKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int deep = 0;
  if (!get_val_param<int >(deep,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->CopyEntry(from, key, deep);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkInformation::CopyEntry(...)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_CopyEntry::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_CopyEntry::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformationDataObjectKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationDataObjectKey * key, int deep = 0)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_CopyEntry_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'from'")
  ADDPARAMCOMMENT_TYPE( vtkInformationDataObjectKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deep' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_CopyEntry_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkInformation* from;
  if (CheckNullVar(_p,_n))  {
    from=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > from_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(from_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    from = from_smtptr.get();
  }

  vtkInformationDataObjectKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDataObjectKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDataObjectKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDataObjectKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int deep = 0;
  if (!get_val_param<int >(deep,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->CopyEntry(from, key, deep);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationDoubleVectorKey * key, int deep = 0)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_CopyEntry_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'from'")
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deep' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_CopyEntry_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkInformation* from;
  if (CheckNullVar(_p,_n))  {
    from=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > from_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(from_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    from = from_smtptr.get();
  }

  vtkInformationDoubleVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int deep = 0;
  if (!get_val_param<int >(deep,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->CopyEntry(from, key, deep);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationInformationKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationInformationKey * key, int deep = 0)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_CopyEntry_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'from'")
  ADDPARAMCOMMENT_TYPE( vtkInformationInformationKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deep' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_CopyEntry_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkInformation* from;
  if (CheckNullVar(_p,_n))  {
    from=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > from_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(from_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    from = from_smtptr.get();
  }

  vtkInformationInformationKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationInformationKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationInformationKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationInformationKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int deep = 0;
  if (!get_val_param<int >(deep,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->CopyEntry(from, key, deep);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationInformationVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationInformationVectorKey * key, int deep = 0)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_CopyEntry_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'from'")
  ADDPARAMCOMMENT_TYPE( vtkInformationInformationVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deep' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_CopyEntry_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkInformation* from;
  if (CheckNullVar(_p,_n))  {
    from=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > from_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(from_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    from = from_smtptr.get();
  }

  vtkInformationInformationVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationInformationVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationInformationVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationInformationVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int deep = 0;
  if (!get_val_param<int >(deep,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->CopyEntry(from, key, deep);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationIntegerKey * key, int deep = 0)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_CopyEntry_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'from'")
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deep' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_CopyEntry_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkInformation* from;
  if (CheckNullVar(_p,_n))  {
    from=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > from_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(from_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    from = from_smtptr.get();
  }

  vtkInformationIntegerKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int deep = 0;
  if (!get_val_param<int >(deep,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->CopyEntry(from, key, deep);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationIntegerVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationIntegerVectorKey * key, int deep = 0)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_CopyEntry_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'from'")
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deep' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_CopyEntry_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkInformation* from;
  if (CheckNullVar(_p,_n))  {
    from=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > from_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(from_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    from = from_smtptr.get();
  }

  vtkInformationIntegerVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int deep = 0;
  if (!get_val_param<int >(deep,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->CopyEntry(from, key, deep);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationRequestKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationRequestKey * key, int deep = 0)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_CopyEntry_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'from'")
  ADDPARAMCOMMENT_TYPE( vtkInformationRequestKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deep' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_CopyEntry_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkInformation* from;
  if (CheckNullVar(_p,_n))  {
    from=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > from_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(from_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    from = from_smtptr.get();
  }

  vtkInformationRequestKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationRequestKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationRequestKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationRequestKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int deep = 0;
  if (!get_val_param<int >(deep,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->CopyEntry(from, key, deep);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationStringKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationStringKey * key, int deep = 0)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_CopyEntry_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'from'")
  ADDPARAMCOMMENT_TYPE( vtkInformationStringKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deep' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_CopyEntry_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkInformation* from;
  if (CheckNullVar(_p,_n))  {
    from=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > from_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(from_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    from = from_smtptr.get();
  }

  vtkInformationStringKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationStringKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int deep = 0;
  if (!get_val_param<int >(deep,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->CopyEntry(from, key, deep);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationStringVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationStringVectorKey * key, int deep = 0)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_CopyEntry_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'from'")
  ADDPARAMCOMMENT_TYPE( vtkInformationStringVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deep' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_CopyEntry_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkInformation* from;
  if (CheckNullVar(_p,_n))  {
    from=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > from_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(from_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    from = from_smtptr.get();
  }

  vtkInformationStringVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationStringVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int deep = 0;
  if (!get_val_param<int >(deep,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->CopyEntry(from, key, deep);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationUnsignedLongKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::CopyEntry(vtkInformation * from, vtkInformationUnsignedLongKey * key, int deep = 0)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_CopyEntry_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'from'")
  ADDPARAMCOMMENT_TYPE( vtkInformationUnsignedLongKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deep' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_CopyEntry_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkInformation* from;
  if (CheckNullVar(_p,_n))  {
    from=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > from_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(from_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    from = from_smtptr.get();
  }

  vtkInformationUnsignedLongKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationUnsignedLongKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationUnsignedLongKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationUnsignedLongKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int deep = 0;
  if (!get_val_param<int >(deep,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->CopyEntry(from, key, deep);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::CopyEntries(vtkInformation * from, vtkInformationKeyVectorKey * key, int deep = 0)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_CopyEntries::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'from'")
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deep' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_CopyEntries::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  vtkInformation* from;
  if (CheckNullVar(_p,_n))  {
    from=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > from_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(from_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    from = from_smtptr.get();
  }

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    key = key_smtptr.get();
  }

  int deep = 0;
  if (!get_val_param<int >(deep,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->CopyEntries(from, key, deep);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Has(vtkInformationKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Has(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationRequestKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationRequestKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationRequestKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationRequestKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationRequestKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationRequestKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationRequestKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Set(key);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkInformation::Remove(...)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformationRequestKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationRequestKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationRequestKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationRequestKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationRequestKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationRequestKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationRequestKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkInformation::Has(...)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformationRequestKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Has(vtkInformationRequestKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationRequestKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationRequestKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationRequestKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationRequestKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationRequestKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Has(key);
  return AMILabType<int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkInformation::Set(...)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationIntegerKey * key, int value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int value;
  if (!get_val_param<int >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Set(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Get(vtkInformationIntegerKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Get(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationIntegerKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Has(vtkInformationIntegerKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Has(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationIdTypeKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationIdTypeKey * key, vtkIdType value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIdTypeKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIdTypeKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIdTypeKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIdTypeKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIdTypeKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  long value_long;
  if (!get_val_param<long >(value_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int value = boost::numeric_cast<long long int >(value_long);

  this->_objectptr->GetObj()->Set(key, value);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkInformation::Get(...)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformationIdTypeKey

//---------------------------------------------------
//  Wrapping of vtkIdType vtkInformation::Get(vtkInformationIdTypeKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIdTypeKey, "parameter named 'key'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIdTypeKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIdTypeKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIdTypeKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIdTypeKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkIdType res =   this->_objectptr->GetObj()->Get(key);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}
*/
/* The following types are missing: vtkInformationIdTypeKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationIdTypeKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIdTypeKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIdTypeKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIdTypeKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIdTypeKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIdTypeKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationIdTypeKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Has(vtkInformationIdTypeKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIdTypeKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIdTypeKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIdTypeKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIdTypeKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIdTypeKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Has(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationDoubleKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationDoubleKey * key, double value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDoubleKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  double value;
  if (!get_val_param<double >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Set(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationDoubleKey

//---------------------------------------------------
//  Wrapping of double vtkInformation::Get(vtkInformationDoubleKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleKey, "parameter named 'key'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDoubleKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  double res =   this->_objectptr->GetObj()->Get(key);
  return AMILabType<double >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationDoubleKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationDoubleKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDoubleKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationDoubleKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Has(vtkInformationDoubleKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDoubleKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Has(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationIntegerVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Append(vtkInformationIntegerVectorKey * key, int value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Append_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Append_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int value;
  if (!get_val_param<int >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Append(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationIntegerVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationIntegerVectorKey * key, int * value, int length)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'length'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int* value;
  if (CheckNullVar(_p,_n))  {
    value=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > value_smtptr;
    if (!get_val_smtptr_param<int >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  int length;
  if (!get_val_param<int >(length,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Set(key, value, length);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationIntegerVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationIntegerVectorKey * key, int value1, int value2, int value3)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int value1;
  if (!get_val_param<int >(value1,_p,_n,true,true)) ClassReturnEmptyVar;

  int value2;
  if (!get_val_param<int >(value2,_p,_n,true,true)) ClassReturnEmptyVar;

  int value3;
  if (!get_val_param<int >(value3,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Set(key, value1, value2, value3);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationIntegerVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationIntegerVectorKey * key, int value1, int value2, int value3, int value4, int value5, int value6)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value3'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value4'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value5'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value6'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int value1;
  if (!get_val_param<int >(value1,_p,_n,true,true)) ClassReturnEmptyVar;

  int value2;
  if (!get_val_param<int >(value2,_p,_n,true,true)) ClassReturnEmptyVar;

  int value3;
  if (!get_val_param<int >(value3,_p,_n,true,true)) ClassReturnEmptyVar;

  int value4;
  if (!get_val_param<int >(value4,_p,_n,true,true)) ClassReturnEmptyVar;

  int value5;
  if (!get_val_param<int >(value5,_p,_n,true,true)) ClassReturnEmptyVar;

  int value6;
  if (!get_val_param<int >(value6,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Set(key, value1, value2, value3, value4, value5, value6);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationIntegerVectorKey

//---------------------------------------------------
//  Wrapping of int * vtkInformation::Get(vtkInformationIntegerVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int * res =   this->_objectptr->GetObj()->Get(key);
  return AMILabType<int >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerVectorKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Get(vtkInformationIntegerVectorKey * key, int idx)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'idx'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int idx;
  if (!get_val_param<int >(idx,_p,_n,true,true)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->Get(key, idx);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationIntegerVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Get(vtkInformationIntegerVectorKey * key, int * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int* value;
  if (CheckNullVar(_p,_n))  {
    value=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > value_smtptr;
    if (!get_val_smtptr_param<int >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->Get(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationIntegerVectorKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Length(vtkInformationIntegerVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Length_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Length_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Length(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationIntegerVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationIntegerVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerVectorKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationIntegerVectorKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Has(vtkInformationIntegerVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Has(key);
  return AMILabType<int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkInformation::Append(...)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Append::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Append::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformationStringVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Append(vtkInformationStringVectorKey * key, char const * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Append_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationStringVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Append_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationStringVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationStringVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  boost::shared_ptr<std::string > value_string;
  if (!get_val_smtptr_param<std::string >(value_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * value = value_string->c_str();

  this->_objectptr->GetObj()->Append(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationStringVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationStringVectorKey * key, char const * value, int idx = 0)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationStringVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'value'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'idx' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationStringVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationStringVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  boost::shared_ptr<std::string > value_string;
  if (!get_val_smtptr_param<std::string >(value_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * value = value_string->c_str();

  int idx = 0;
  if (!get_val_param<int >(idx,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Set(key, value, idx);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationStringVectorKey

//---------------------------------------------------
//  Wrapping of char const * vtkInformation::Get(vtkInformationStringVectorKey * key, int idx = 0)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationStringVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'idx' (def:0)")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationStringVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationStringVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int idx = 0;
  if (!get_val_param<int >(idx,_p,_n,false,true)) ClassReturnEmptyVar;

  char const * res =   this->_objectptr->GetObj()->Get(key, idx);
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkInformation::Length(...)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Length::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Length::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformationStringVectorKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Length(vtkInformationStringVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Length_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationStringVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Length_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationStringVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationStringVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Length(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationStringVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationStringVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationStringVectorKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationStringVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationStringVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationStringVectorKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Has(vtkInformationStringVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationStringVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationStringVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationStringVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Has(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationIntegerPointerKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationIntegerPointerKey * key, int * value, int length)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerPointerKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'length'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerPointerKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerPointerKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerPointerKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerPointerKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int* value;
  if (CheckNullVar(_p,_n))  {
    value=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > value_smtptr;
    if (!get_val_smtptr_param<int >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  int length;
  if (!get_val_param<int >(length,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Set(key, value, length);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationIntegerPointerKey

//---------------------------------------------------
//  Wrapping of int * vtkInformation::Get(vtkInformationIntegerPointerKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerPointerKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerPointerKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerPointerKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerPointerKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerPointerKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int * res =   this->_objectptr->GetObj()->Get(key);
  return AMILabType<int >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerPointerKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Get(vtkInformationIntegerPointerKey * key, int * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerPointerKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerPointerKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerPointerKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerPointerKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerPointerKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int* value;
  if (CheckNullVar(_p,_n))  {
    value=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > value_smtptr;
    if (!get_val_smtptr_param<int >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->Get(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationIntegerPointerKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Length(vtkInformationIntegerPointerKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Length_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerPointerKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Length_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerPointerKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerPointerKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerPointerKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerPointerKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Length(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationIntegerPointerKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationIntegerPointerKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerPointerKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerPointerKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerPointerKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerPointerKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerPointerKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationIntegerPointerKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Has(vtkInformationIntegerPointerKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerPointerKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationIntegerPointerKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationIntegerPointerKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerPointerKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerPointerKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Has(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationUnsignedLongKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationUnsignedLongKey * key, long unsigned int value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationUnsignedLongKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationUnsignedLongKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationUnsignedLongKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationUnsignedLongKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationUnsignedLongKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  long value_long;
  if (!get_val_param<long >(value_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int value = boost::numeric_cast<long unsigned int >(value_long);

  this->_objectptr->GetObj()->Set(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationUnsignedLongKey

//---------------------------------------------------
//  Wrapping of long unsigned int vtkInformation::Get(vtkInformationUnsignedLongKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationUnsignedLongKey, "parameter named 'key'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationUnsignedLongKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationUnsignedLongKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationUnsignedLongKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationUnsignedLongKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  long unsigned int res =   this->_objectptr->GetObj()->Get(key);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}
*/
/* The following types are missing: vtkInformationUnsignedLongKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationUnsignedLongKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationUnsignedLongKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationUnsignedLongKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationUnsignedLongKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationUnsignedLongKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationUnsignedLongKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationUnsignedLongKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Has(vtkInformationUnsignedLongKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationUnsignedLongKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationUnsignedLongKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationUnsignedLongKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationUnsignedLongKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationUnsignedLongKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Has(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Append(vtkInformationDoubleVectorKey * key, double value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Append_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Append_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDoubleVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  double value;
  if (!get_val_param<double >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Append(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationDoubleVectorKey * key, double * value, int length)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'length'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDoubleVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  double* value;
  if (CheckNullVar(_p,_n))  {
    value=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > value_smtptr;
    if (!get_val_smtptr_param<double >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  int length;
  if (!get_val_param<int >(length,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Set(key, value, length);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationDoubleVectorKey * key, double value1, double value2, double value3)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDoubleVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  double value1;
  if (!get_val_param<double >(value1,_p,_n,true,true)) ClassReturnEmptyVar;

  double value2;
  if (!get_val_param<double >(value2,_p,_n,true,true)) ClassReturnEmptyVar;

  double value3;
  if (!get_val_param<double >(value3,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Set(key, value1, value2, value3);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationDoubleVectorKey * key, double value1, double value2, double value3, double value4, double value5, double value6)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value3'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value4'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value5'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value6'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDoubleVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  double value1;
  if (!get_val_param<double >(value1,_p,_n,true,true)) ClassReturnEmptyVar;

  double value2;
  if (!get_val_param<double >(value2,_p,_n,true,true)) ClassReturnEmptyVar;

  double value3;
  if (!get_val_param<double >(value3,_p,_n,true,true)) ClassReturnEmptyVar;

  double value4;
  if (!get_val_param<double >(value4,_p,_n,true,true)) ClassReturnEmptyVar;

  double value5;
  if (!get_val_param<double >(value5,_p,_n,true,true)) ClassReturnEmptyVar;

  double value6;
  if (!get_val_param<double >(value6,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Set(key, value1, value2, value3, value4, value5, value6);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of double * vtkInformation::Get(vtkInformationDoubleVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDoubleVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  double * res =   this->_objectptr->GetObj()->Get(key);
  return AMILabType<double >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of double vtkInformation::Get(vtkInformationDoubleVectorKey * key, int idx)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'idx'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDoubleVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int idx;
  if (!get_val_param<int >(idx,_p,_n,true,true)) ClassReturnEmptyVar;

  double res =   this->_objectptr->GetObj()->Get(key, idx);
  return AMILabType<double >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Get(vtkInformationDoubleVectorKey * key, double * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDoubleVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  double* value;
  if (CheckNullVar(_p,_n))  {
    value=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > value_smtptr;
    if (!get_val_smtptr_param<double >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->Get(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Length(vtkInformationDoubleVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Length_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Length_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDoubleVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Length(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationDoubleVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleVectorKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDoubleVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Has(vtkInformationDoubleVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDoubleVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDoubleVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Has(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Append_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Append_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->Append(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_AppendUnique_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_AppendUnique_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->AppendUnique(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationKeyVectorKey * key, vtkInformationKey * * value, int length)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_14::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationKey, "parameter named 'value'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'length'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_14::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey* local_value = NULL;
  vtkInformationKey** value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationKey**)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    local_value = value_smtptr.get();
    value = &local_value;
  }

  int length;
  if (!get_val_param<int >(length,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Set(key, value, length);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationKeyVectorKey * key, vtkInformationKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKey, vtkInformationKeyVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationKey * * vtkInformation::Get(vtkInformationKeyVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_14::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkInformationKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_14::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey * * res =   this->_objectptr->GetObj()->Get(key);
  return AMILabType<vtkInformationKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationKey, vtkInformationKeyVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationKey * vtkInformation::Get(vtkInformationKeyVectorKey * key, int idx)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_15::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'idx'")
  return_comments="returning a variable of type vtkInformationKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_15::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int idx;
  if (!get_val_param<int >(idx,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkInformationKey * res =   this->_objectptr->GetObj()->Get(key, idx);
  return AMILabType<vtkInformationKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Get(vtkInformationKeyVectorKey * key, vtkInformationKey * * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_16::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_16::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationKey* local_value = NULL;
  vtkInformationKey** value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationKey**)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    local_value = value_smtptr.get();
    value = &local_value;
  }

  this->_objectptr->GetObj()->Get(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Length(vtkInformationKeyVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Length_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Length_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Length(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationKeyVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationKeyVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Has(vtkInformationKeyVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Has(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDataObjectKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationDataObjectKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Append_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationDataObjectKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Append_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationDataObjectKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationDataObjectKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDataObjectKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationDataObjectKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->Append(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDoubleKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationDoubleKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Append_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Append_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationDoubleKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationDoubleKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->Append(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationDoubleVectorKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Append_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleVectorKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Append_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationDoubleVectorKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationDoubleVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleVectorKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleVectorKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->Append(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationInformationKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationInformationKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Append_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationInformationKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Append_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationInformationKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationInformationKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationInformationKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationInformationKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->Append(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationInformationVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationInformationVectorKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Append_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationInformationVectorKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Append_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationInformationVectorKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationInformationVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationInformationVectorKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationInformationVectorKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->Append(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationIntegerKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Append_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Append_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationIntegerKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationIntegerKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->Append(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationIntegerVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationIntegerVectorKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Append_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerVectorKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Append_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationIntegerVectorKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationIntegerVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerVectorKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerVectorKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->Append(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationStringKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationStringKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Append_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationStringKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Append_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationStringKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationStringKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->Append(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationStringVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationStringVectorKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Append_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationStringVectorKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Append_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationStringVectorKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationStringVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringVectorKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringVectorKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->Append(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationObjectBaseKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationObjectBaseKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Append_14::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationObjectBaseKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Append_14::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationObjectBaseKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationObjectBaseKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationObjectBaseKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationObjectBaseKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->Append(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationUnsignedLongKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Append(vtkInformationKeyVectorKey * key, vtkInformationUnsignedLongKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Append_15::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationUnsignedLongKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Append_15::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationUnsignedLongKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationUnsignedLongKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationUnsignedLongKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationUnsignedLongKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->Append(key, value);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkInformation::AppendUnique(...)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_AppendUnique::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_AppendUnique::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDataObjectKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationDataObjectKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_AppendUnique_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationDataObjectKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_AppendUnique_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationDataObjectKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationDataObjectKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDataObjectKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationDataObjectKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->AppendUnique(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDoubleKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationDoubleKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_AppendUnique_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_AppendUnique_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationDoubleKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationDoubleKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->AppendUnique(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationDoubleVectorKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_AppendUnique_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationDoubleVectorKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_AppendUnique_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationDoubleVectorKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationDoubleVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDoubleVectorKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationDoubleVectorKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->AppendUnique(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationInformationKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationInformationKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_AppendUnique_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationInformationKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_AppendUnique_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationInformationKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationInformationKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationInformationKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationInformationKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->AppendUnique(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationInformationVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationInformationVectorKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_AppendUnique_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationInformationVectorKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_AppendUnique_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationInformationVectorKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationInformationVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationInformationVectorKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationInformationVectorKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->AppendUnique(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationIntegerKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_AppendUnique_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_AppendUnique_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationIntegerKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationIntegerKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->AppendUnique(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationIntegerVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationIntegerVectorKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_AppendUnique_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationIntegerVectorKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_AppendUnique_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationIntegerVectorKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationIntegerVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationIntegerVectorKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationIntegerVectorKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->AppendUnique(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationStringKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationStringKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_AppendUnique_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationStringKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_AppendUnique_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationStringKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationStringKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->AppendUnique(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationStringVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationStringVectorKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_AppendUnique_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationStringVectorKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_AppendUnique_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationStringVectorKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationStringVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringVectorKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringVectorKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->AppendUnique(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationObjectBaseKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationObjectBaseKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_AppendUnique_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationObjectBaseKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_AppendUnique_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationObjectBaseKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationObjectBaseKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationObjectBaseKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationObjectBaseKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->AppendUnique(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationKeyVectorKey, vtkInformationUnsignedLongKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::AppendUnique(vtkInformationKeyVectorKey * key, vtkInformationUnsignedLongKey * value)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_AppendUnique_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationKeyVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationUnsignedLongKey, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_AppendUnique_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationKeyVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationKeyVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationKeyVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationKeyVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationUnsignedLongKey* value;
  if (CheckNullVar(_p,_n))  {
    value=(vtkInformationUnsignedLongKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationUnsignedLongKey > value_smtptr;
    if (!get_val_smtptr_param<vtkInformationUnsignedLongKey >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    value = value_smtptr.get();
  }

  this->_objectptr->GetObj()->AppendUnique(key, value);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationStringKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationStringKey * key, char const * param1)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_15::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationStringKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_15::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationStringKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationStringKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  boost::shared_ptr<std::string > param1_string;
  if (!get_val_smtptr_param<std::string >(param1_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * param1 = param1_string->c_str();

  this->_objectptr->GetObj()->Set(key, param1);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationStringKey

//---------------------------------------------------
//  Wrapping of char const * vtkInformation::Get(vtkInformationStringKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_17::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationStringKey, "parameter named 'key'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_17::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationStringKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationStringKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  char const * res =   this->_objectptr->GetObj()->Get(key);
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}
*/
/* The following types are missing: vtkInformationStringKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationStringKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationStringKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationStringKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationStringKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationStringKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Has(vtkInformationStringKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationStringKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationStringKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationStringKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationStringKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationStringKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Has(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationInformationKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationInformationKey * key, vtkInformation * param1)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_16::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationInformationKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_16::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationInformationKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationInformationKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationInformationKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationInformationKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformation* param1;
  if (CheckNullVar(_p,_n))  {
    param1=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > param1_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(param1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    param1 = param1_smtptr.get();
  }

  this->_objectptr->GetObj()->Set(key, param1);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationInformationKey

//---------------------------------------------------
//  Wrapping of vtkInformation * vtkInformation::Get(vtkInformationInformationKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_18::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationInformationKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkInformation";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_18::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationInformationKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationInformationKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationInformationKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationInformationKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformation * res =   this->_objectptr->GetObj()->Get(key);
  BasicVariable::ptr res_var = AMILabType<vtkInformation >::CreateVar(res,true);
  return res_var;
}
*/
/* The following types are missing: vtkInformationInformationKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationInformationKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_14::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationInformationKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_14::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationInformationKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationInformationKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationInformationKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationInformationKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationInformationKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Has(vtkInformationInformationKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationInformationKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationInformationKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationInformationKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationInformationKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationInformationKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Has(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationInformationVectorKey, vtkInformationVector

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationInformationVectorKey * key, vtkInformationVector * param1)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_17::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationInformationVectorKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkInformationVector, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_17::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationInformationVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationInformationVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationInformationVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationInformationVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationVector* param1;
  if (CheckNullVar(_p,_n))  {
    param1=(vtkInformationVector*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationVector > param1_smtptr;
    if (!get_val_smtptr_param<vtkInformationVector >(param1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    param1 = param1_smtptr.get();
  }

  this->_objectptr->GetObj()->Set(key, param1);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationVector, vtkInformationInformationVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationVector * vtkInformation::Get(vtkInformationInformationVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_19::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationInformationVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkInformationVector";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_19::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationInformationVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationInformationVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationInformationVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationInformationVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkInformationVector * res =   this->_objectptr->GetObj()->Get(key);
  return AMILabType<vtkInformationVector >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationInformationVectorKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationInformationVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_15::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationInformationVectorKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_15::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationInformationVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationInformationVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationInformationVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationInformationVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationInformationVectorKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Has(vtkInformationInformationVectorKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has_14::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationInformationVectorKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has_14::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationInformationVectorKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationInformationVectorKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationInformationVectorKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationInformationVectorKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Has(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationObjectBaseKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationObjectBaseKey * key, vtkObjectBase * param1)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_18::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationObjectBaseKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_18::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationObjectBaseKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationObjectBaseKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationObjectBaseKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationObjectBaseKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkObjectBase* param1;
  if (CheckNullVar(_p,_n))  {
    param1=(vtkObjectBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkObjectBase > param1_smtptr;
    if (!get_val_smtptr_param<vtkObjectBase >(param1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    param1 = param1_smtptr.get();
  }

  this->_objectptr->GetObj()->Set(key, param1);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationObjectBaseKey

//---------------------------------------------------
//  Wrapping of vtkObjectBase * vtkInformation::Get(vtkInformationObjectBaseKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_20::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationObjectBaseKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkObjectBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_20::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationObjectBaseKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationObjectBaseKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationObjectBaseKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationObjectBaseKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkObjectBase * res =   this->_objectptr->GetObj()->Get(key);
  BasicVariable::ptr res_var = AMILabType<vtkObjectBase >::CreateVar(res,true);
  return res_var;
}
*/
/* The following types are missing: vtkInformationObjectBaseKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationObjectBaseKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_16::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationObjectBaseKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_16::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationObjectBaseKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationObjectBaseKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationObjectBaseKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationObjectBaseKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationObjectBaseKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Has(vtkInformationObjectBaseKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has_15::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationObjectBaseKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has_15::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationObjectBaseKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationObjectBaseKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationObjectBaseKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationObjectBaseKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Has(key);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformationDataObjectKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Set(vtkInformationDataObjectKey * key, vtkDataObject * param1)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Set_19::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDataObjectKey, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Set_19::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDataObjectKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDataObjectKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDataObjectKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDataObjectKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkDataObject* param1;
  if (CheckNullVar(_p,_n))  {
    param1=(vtkDataObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataObject > param1_smtptr;
    if (!get_val_smtptr_param<vtkDataObject >(param1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    param1 = param1_smtptr.get();
  }

  this->_objectptr->GetObj()->Set(key, param1);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationDataObjectKey

//---------------------------------------------------
//  Wrapping of vtkDataObject * vtkInformation::Get(vtkInformationDataObjectKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Get_21::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDataObjectKey, "parameter named 'key'")
  return_comments="returning a variable of type vtkDataObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Get_21::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDataObjectKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDataObjectKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDataObjectKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDataObjectKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  vtkDataObject * res =   this->_objectptr->GetObj()->Get(key);
  BasicVariable::ptr res_var = AMILabType<vtkDataObject >::CreateVar(res,true);
  return res_var;
}
*/
/* The following types are missing: vtkInformationDataObjectKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::Remove(vtkInformationDataObjectKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Remove_17::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDataObjectKey, "parameter named 'key'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Remove_17::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDataObjectKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDataObjectKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDataObjectKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDataObjectKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  this->_objectptr->GetObj()->Remove(key);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationDataObjectKey

//---------------------------------------------------
//  Wrapping of int vtkInformation::Has(vtkInformationDataObjectKey * key)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Has_16::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationDataObjectKey, "parameter named 'key'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Has_16::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationDataObjectKey* key;
  if (CheckNullVar(_p,_n))  {
    key=(vtkInformationDataObjectKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationDataObjectKey > key_smtptr;
    if (!get_val_smtptr_param<vtkInformationDataObjectKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    key = key_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->Has(key);
  return AMILabType<int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkInformation::Register(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_Register::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_Register::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkObjectBase* o;
  if (CheckNullVar(_p,_n))  {
    o=(vtkObjectBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkObjectBase > o_smtptr;
    if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    o = o_smtptr.get();
  }

  this->_objectptr->GetObj()->Register(o);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInformation::UnRegister(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_UnRegister::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_UnRegister::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkObjectBase* o;
  if (CheckNullVar(_p,_n))  {
    o=(vtkObjectBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkObjectBase > o_smtptr;
    if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    o = o_smtptr.get();
  }

  this->_objectptr->GetObj()->UnRegister(o);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkInformationRequestKey

//---------------------------------------------------
//  Wrapping of void vtkInformation::SetRequest(vtkInformationRequestKey * request)
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_SetRequest::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationRequestKey, "parameter named 'request'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_SetRequest::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkInformationRequestKey* request;
  if (CheckNullVar(_p,_n))  {
    request=(vtkInformationRequestKey*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationRequestKey > request_smtptr;
    if (!get_val_smtptr_param<vtkInformationRequestKey >(request_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    request = request_smtptr.get();
  }

  this->_objectptr->GetObj()->SetRequest(request);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationRequestKey

//---------------------------------------------------
//  Wrapping of vtkInformationRequestKey * vtkInformation::GetRequest()
//---------------------------------------------------
void WrapClass_vtkInformation::
    wrap_GetRequest::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationRequestKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInformation::
    wrap_GetRequest::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationRequestKey * res =   this->_objectptr->GetObj()->GetRequest();
  return AMILabType<vtkInformationRequestKey >::CreateVar(res,true);
}
*/

