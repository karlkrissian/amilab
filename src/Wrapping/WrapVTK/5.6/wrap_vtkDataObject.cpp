/**
 * C++ Interface: wrap_vtkDataObject
 *
 * Description: wrapping vtkDataObject
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_vtkDataObject.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_vtkDataObject.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkDataObject>::CreateVar( ParamList* p)
{
  WrapClass_vtkDataObject::wrap_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkDataObject);
AMI_DEFINE_VARFROMSMTPTR(vtkDataObject);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkDataObject>::CreateVar( vtkDataObject* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkDataObject> obj_ptr(val,smartpointer_nodeleter<vtkDataObject>());
  return AMILabType<vtkDataObject>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkDataObject
//
Variable<AMIObject>::ptr WrapClass_vtkDataObject::CreateVar( vtkDataObject* sp)
{
  boost::shared_ptr<vtkDataObject> di_ptr(
    sp,
    wxwindow_nodeleter<vtkDataObject>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkDataObject>::CreateVar(
      new WrapClass_vtkDataObject(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkDataObject::AddMethods(WrapClass<vtkDataObject>::ptr this_ptr )
{
  
      // Add members from vtkObject
      WrapClass_vtkObject::ptr parent_vtkObject(        boost::dynamic_pointer_cast<WrapClass_vtkObject >(this_ptr));
      parent_vtkObject->AddMethods(parent_vtkObject);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
/* The following types are missing: vtkSource
      AddVar_GetSource( this_ptr);
*/
/* The following types are missing: vtkSource
      AddVar_SetSource( this_ptr);
*/
/* The following types are missing: vtkInformation
      AddVar_GetInformation( this_ptr);
*/
/* The following types are missing: vtkInformation
      AddVar_SetInformation( this_ptr);
*/
/* The following types are missing: vtkInformation
      AddVar_GetPipelineInformation( this_ptr);
*/
/* The following types are missing: vtkInformation
      AddVar_SetPipelineInformation( this_ptr);
*/
/* The following types are missing: vtkAlgorithmOutput
      AddVar_GetProducerPort( this_ptr);
*/
      AddVar_GetMTime( this_ptr);
      AddVar_Initialize( this_ptr);
      AddVar_ReleaseData( this_ptr);
      AddVar_ShouldIReleaseData( this_ptr);
      AddVar_GetDataReleased( this_ptr);
      AddVar_SetReleaseDataFlag( this_ptr);
      AddVar_GetReleaseDataFlag( this_ptr);
      AddVar_ReleaseDataFlagOn( this_ptr);
      AddVar_ReleaseDataFlagOff( this_ptr);
      AddVar_GlobalReleaseDataFlagOn( this_ptr);
      AddVar_GlobalReleaseDataFlagOff( this_ptr);
/* The following types are missing: vtkFieldData
      AddVar_SetFieldData( this_ptr);
*/
/* The following types are missing: vtkFieldData
      AddVar_GetFieldData( this_ptr);
*/
      AddVar_Register( this_ptr);
      AddVar_UnRegister( this_ptr);
      AddVar_Update( this_ptr);
      AddVar_UpdateInformation( this_ptr);
      AddVar_PropagateUpdateExtent( this_ptr);
      AddVar_TriggerAsynchronousUpdate( this_ptr);
      AddVar_UpdateData( this_ptr);
      AddVar_GetEstimatedMemorySize( this_ptr);
      AddVar_SetUpdateExtent_1( this_ptr);
      AddVar_SetUpdateExtent( this_ptr);
      AddVar_SetUpdateExtent_2( this_ptr);
      AddVar_SetUpdateExtent_3( this_ptr);
      AddVar_SetUpdateExtent_4( this_ptr);
      AddVar_GetUpdateExtent_1( this_ptr);
      AddVar_GetUpdateExtent( this_ptr);
      AddVar_GetUpdateExtent_2( this_ptr);
      AddVar_GetUpdateExtent_3( this_ptr);
      AddVar_GetDataObjectType( this_ptr);
      AddVar_GetUpdateTime( this_ptr);
      AddVar_SetUpdateExtentToWholeExtent( this_ptr);
      AddVar_GetPipelineMTime( this_ptr);
      AddVar_GetActualMemorySize( this_ptr);
      AddVar_CopyInformation( this_ptr);
      AddVar_CopyTypeSpecificInformation( this_ptr);
      AddVar_SetUpdatePiece( this_ptr);
      AddVar_SetUpdateNumberOfPieces( this_ptr);
      AddVar_GetUpdatePiece( this_ptr);
      AddVar_GetUpdateNumberOfPieces( this_ptr);
      AddVar_SetUpdateGhostLevel( this_ptr);
      AddVar_GetUpdateGhostLevel( this_ptr);
      AddVar_SetRequestExactExtent( this_ptr);
      AddVar_GetRequestExactExtent( this_ptr);
      AddVar_RequestExactExtentOn( this_ptr);
      AddVar_RequestExactExtentOff( this_ptr);
      AddVar_SetWholeExtent_1( this_ptr);
      AddVar_SetWholeExtent( this_ptr);
      AddVar_SetWholeExtent_2( this_ptr);
      AddVar_GetWholeExtent_1( this_ptr);
      AddVar_GetWholeExtent( this_ptr);
      AddVar_GetWholeExtent_2( this_ptr);
      AddVar_GetWholeExtent_3( this_ptr);
      AddVar_SetWholeBoundingBox_1( this_ptr);
      AddVar_SetWholeBoundingBox( this_ptr);
      AddVar_SetWholeBoundingBox_2( this_ptr);
      AddVar_GetWholeBoundingBox_1( this_ptr);
      AddVar_GetWholeBoundingBox( this_ptr);
      AddVar_GetWholeBoundingBox_2( this_ptr);
      AddVar_GetWholeBoundingBox_3( this_ptr);
      AddVar_SetMaximumNumberOfPieces( this_ptr);
      AddVar_GetMaximumNumberOfPieces( this_ptr);
/* The following types are missing: vtkInformation, vtkInformation, vtkInformation
      AddVar_CopyInformationToPipeline_1( this_ptr);
*/
      AddVar_CopyInformationToPipeline( this_ptr);
/* The following types are missing: vtkInformation, vtkInformation
      AddVar_CopyInformationToPipeline_2( this_ptr);
*/
/* The following types are missing: vtkInformation
      AddVar_CopyInformationFromPipeline( this_ptr);
*/
      AddVar_DataHasBeenGenerated( this_ptr);
      AddVar_PrepareForNewData( this_ptr);
      AddVar_ShallowCopy( this_ptr);
      AddVar_DeepCopy( this_ptr);
/* The following types are missing: vtkExtentTranslator
      AddVar_SetExtentTranslator( this_ptr);
*/
/* The following types are missing: vtkExtentTranslator
      AddVar_GetExtentTranslator( this_ptr);
*/
      AddVar_GetExtentType( this_ptr);
      AddVar_Crop( this_ptr);
/* The following types are missing: vtkDataSetAttributes
      AddVar_GetAttributes( this_ptr);
*/
/* The following types are missing: vtkFieldData
      AddVar_GetAttributesAsFieldData( this_ptr);
*/
/* The following types are missing: vtkAbstractArray
      AddVar_GetAttributeTypeForArray( this_ptr);
*/
/* The following types are missing: long long int
      AddVar_GetNumberOfElements( this_ptr);
*/



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkDataObject * vtkDataObject::New()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkDataObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkDataObject * res =   vtkDataObject::New();
  BasicVariable::ptr res_var = WrapClass_vtkDataObject::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkDataObject::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkDataObject::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkDataObject * vtkDataObject::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkDataObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkDataObject * res =   vtkDataObject::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkDataObject::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetGlobalReleaseDataFlag(int val)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetGlobalReleaseDataFlag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'val'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetGlobalReleaseDataFlag::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int val;
  if (!get_val_param<int >(val,_p,_n)) ClassHelpAndReturn;

  vtkDataObject::SetGlobalReleaseDataFlag(val);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkDataObject::GetGlobalReleaseDataFlag()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetGlobalReleaseDataFlag::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetGlobalReleaseDataFlag::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   vtkDataObject::GetGlobalReleaseDataFlag();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: vtkInformation, vtkInformation

//---------------------------------------------------
//  Wrapping of vtkInformation * vtkDataObject::GetActiveFieldInformation(vtkInformation * info, int fieldAssociation, int attributeType)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetActiveFieldInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'info'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'fieldAssociation'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'attributeType'")
  return_comments="returning a variable of type vtkInformation";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetActiveFieldInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkInformation > info_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(info_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkInformation* info = info_smtptr.get();

  int fieldAssociation;
  if (!get_val_param<int >(fieldAssociation,_p,_n)) ClassHelpAndReturn;

  int attributeType;
  if (!get_val_param<int >(attributeType,_p,_n)) ClassHelpAndReturn;

  vtkInformation * res =   vtkDataObject::GetActiveFieldInformation(info, fieldAssociation, attributeType);
  return AMILabType<vtkInformation >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformation, vtkInformation

//---------------------------------------------------
//  Wrapping of vtkInformation * vtkDataObject::GetNamedFieldInformation(vtkInformation * info, int fieldAssociation, char const * name)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetNamedFieldInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'info'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'fieldAssociation'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  return_comments="returning a variable of type vtkInformation";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetNamedFieldInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkInformation > info_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(info_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkInformation* info = info_smtptr.get();

  int fieldAssociation;
  if (!get_val_param<int >(fieldAssociation,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n)) ClassHelpAndReturn;
  char const * name = name_string->c_str();

  vtkInformation * res =   vtkDataObject::GetNamedFieldInformation(info, fieldAssociation, name);
  return AMILabType<vtkInformation >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of void vtkDataObject::RemoveNamedFieldInformation(vtkInformation * info, int fieldAssociation, char const * name)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_RemoveNamedFieldInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'info'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'fieldAssociation'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_RemoveNamedFieldInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkInformation > info_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(info_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkInformation* info = info_smtptr.get();

  int fieldAssociation;
  if (!get_val_param<int >(fieldAssociation,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n)) ClassHelpAndReturn;
  char const * name = name_string->c_str();

  vtkDataObject::RemoveNamedFieldInformation(info, fieldAssociation, name);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformation, vtkInformation

//---------------------------------------------------
//  Wrapping of vtkInformation * vtkDataObject::SetActiveAttribute(vtkInformation * info, int fieldAssociation, char const * attributeName, int attributeType)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetActiveAttribute::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'info'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'fieldAssociation'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'attributeName'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'attributeType'")
  return_comments="returning a variable of type vtkInformation";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetActiveAttribute::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkInformation > info_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(info_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkInformation* info = info_smtptr.get();

  int fieldAssociation;
  if (!get_val_param<int >(fieldAssociation,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<std::string > attributeName_string;
  if (!get_val_smtptr_param<std::string >(attributeName_string,_p,_n)) ClassHelpAndReturn;
  char const * attributeName = attributeName_string->c_str();

  int attributeType;
  if (!get_val_param<int >(attributeType,_p,_n)) ClassHelpAndReturn;

  vtkInformation * res =   vtkDataObject::SetActiveAttribute(info, fieldAssociation, attributeName, attributeType);
  return AMILabType<vtkInformation >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetActiveAttributeInfo(vtkInformation * info, int fieldAssociation, int attributeType, char const * name, int arrayType, int numComponents, int numTuples)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetActiveAttributeInfo::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'info'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'fieldAssociation'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'attributeType'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'arrayType'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'numComponents'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'numTuples'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetActiveAttributeInfo::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkInformation > info_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(info_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkInformation* info = info_smtptr.get();

  int fieldAssociation;
  if (!get_val_param<int >(fieldAssociation,_p,_n)) ClassHelpAndReturn;

  int attributeType;
  if (!get_val_param<int >(attributeType,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n)) ClassHelpAndReturn;
  char const * name = name_string->c_str();

  int arrayType;
  if (!get_val_param<int >(arrayType,_p,_n)) ClassHelpAndReturn;

  int numComponents;
  if (!get_val_param<int >(numComponents,_p,_n)) ClassHelpAndReturn;

  int numTuples;
  if (!get_val_param<int >(numTuples,_p,_n)) ClassHelpAndReturn;

  vtkDataObject::SetActiveAttributeInfo(info, fieldAssociation, attributeType, name, arrayType, numComponents, numTuples);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetPointDataActiveScalarInfo(vtkInformation * info, int arrayType, int numComponents)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetPointDataActiveScalarInfo::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'info'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'arrayType'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'numComponents'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetPointDataActiveScalarInfo::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkInformation > info_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(info_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkInformation* info = info_smtptr.get();

  int arrayType;
  if (!get_val_param<int >(arrayType,_p,_n)) ClassHelpAndReturn;

  int numComponents;
  if (!get_val_param<int >(numComponents,_p,_n)) ClassHelpAndReturn;

  vtkDataObject::SetPointDataActiveScalarInfo(info, arrayType, numComponents);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of char const * vtkDataObject::GetAssociationTypeAsString(int associationType)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetAssociationTypeAsString::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'associationType'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetAssociationTypeAsString::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int associationType;
  if (!get_val_param<int >(associationType,_p,_n)) ClassHelpAndReturn;

  char const * res =   vtkDataObject::GetAssociationTypeAsString(associationType);
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}
/* The following types are missing: vtkInformationStringKey

//---------------------------------------------------
//  Wrapping of vtkInformationStringKey * vtkDataObject::DATA_TYPE_NAME()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_DATA_TYPE_NAME::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationStringKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_DATA_TYPE_NAME::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationStringKey * res =   vtkDataObject::DATA_TYPE_NAME();
  return AMILabType<vtkInformationStringKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationDataObjectKey

//---------------------------------------------------
//  Wrapping of vtkInformationDataObjectKey * vtkDataObject::DATA_OBJECT()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_DATA_OBJECT::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationDataObjectKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_DATA_OBJECT::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationDataObjectKey * res =   vtkDataObject::DATA_OBJECT();
  return AMILabType<vtkInformationDataObjectKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkDataObject::DATA_EXTENT_TYPE()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_DATA_EXTENT_TYPE::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_DATA_EXTENT_TYPE::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkDataObject::DATA_EXTENT_TYPE();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerPointerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerPointerKey * vtkDataObject::DATA_EXTENT()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_DATA_EXTENT::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerPointerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_DATA_EXTENT::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerPointerKey * res =   vtkDataObject::DATA_EXTENT();
  return AMILabType<vtkInformationIntegerPointerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkDataObject::DATA_PIECE_NUMBER()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_DATA_PIECE_NUMBER::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_DATA_PIECE_NUMBER::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkDataObject::DATA_PIECE_NUMBER();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkDataObject::DATA_NUMBER_OF_PIECES()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_DATA_NUMBER_OF_PIECES::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_DATA_NUMBER_OF_PIECES::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkDataObject::DATA_NUMBER_OF_PIECES();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkDataObject::DATA_NUMBER_OF_GHOST_LEVELS()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_DATA_NUMBER_OF_GHOST_LEVELS::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_DATA_NUMBER_OF_GHOST_LEVELS::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkDataObject::DATA_NUMBER_OF_GHOST_LEVELS();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationDoubleKey

//---------------------------------------------------
//  Wrapping of vtkInformationDoubleKey * vtkDataObject::DATA_RESOLUTION()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_DATA_RESOLUTION::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationDoubleKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_DATA_RESOLUTION::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationDoubleKey * res =   vtkDataObject::DATA_RESOLUTION();
  return AMILabType<vtkInformationDoubleKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationDoubleVectorKey * vtkDataObject::DATA_TIME_STEPS()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_DATA_TIME_STEPS::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationDoubleVectorKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_DATA_TIME_STEPS::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationDoubleVectorKey * res =   vtkDataObject::DATA_TIME_STEPS();
  return AMILabType<vtkInformationDoubleVectorKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationInformationVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationInformationVectorKey * vtkDataObject::POINT_DATA_VECTOR()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_POINT_DATA_VECTOR::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationInformationVectorKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_POINT_DATA_VECTOR::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationInformationVectorKey * res =   vtkDataObject::POINT_DATA_VECTOR();
  return AMILabType<vtkInformationInformationVectorKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationInformationVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationInformationVectorKey * vtkDataObject::CELL_DATA_VECTOR()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_CELL_DATA_VECTOR::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationInformationVectorKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_CELL_DATA_VECTOR::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationInformationVectorKey * res =   vtkDataObject::CELL_DATA_VECTOR();
  return AMILabType<vtkInformationInformationVectorKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationInformationVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationInformationVectorKey * vtkDataObject::VERTEX_DATA_VECTOR()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_VERTEX_DATA_VECTOR::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationInformationVectorKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_VERTEX_DATA_VECTOR::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationInformationVectorKey * res =   vtkDataObject::VERTEX_DATA_VECTOR();
  return AMILabType<vtkInformationInformationVectorKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationInformationVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationInformationVectorKey * vtkDataObject::EDGE_DATA_VECTOR()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_EDGE_DATA_VECTOR::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationInformationVectorKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_EDGE_DATA_VECTOR::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationInformationVectorKey * res =   vtkDataObject::EDGE_DATA_VECTOR();
  return AMILabType<vtkInformationInformationVectorKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkDataObject::FIELD_ARRAY_TYPE()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_FIELD_ARRAY_TYPE::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_FIELD_ARRAY_TYPE::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkDataObject::FIELD_ARRAY_TYPE();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkDataObject::FIELD_ASSOCIATION()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_FIELD_ASSOCIATION::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_FIELD_ASSOCIATION::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkDataObject::FIELD_ASSOCIATION();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkDataObject::FIELD_ATTRIBUTE_TYPE()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_FIELD_ATTRIBUTE_TYPE::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_FIELD_ATTRIBUTE_TYPE::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkDataObject::FIELD_ATTRIBUTE_TYPE();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkDataObject::FIELD_ACTIVE_ATTRIBUTE()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_FIELD_ACTIVE_ATTRIBUTE::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_FIELD_ACTIVE_ATTRIBUTE::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkDataObject::FIELD_ACTIVE_ATTRIBUTE();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkDataObject::FIELD_NUMBER_OF_COMPONENTS()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_FIELD_NUMBER_OF_COMPONENTS::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_FIELD_NUMBER_OF_COMPONENTS::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkDataObject::FIELD_NUMBER_OF_COMPONENTS();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkDataObject::FIELD_NUMBER_OF_TUPLES()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_FIELD_NUMBER_OF_TUPLES::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_FIELD_NUMBER_OF_TUPLES::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkDataObject::FIELD_NUMBER_OF_TUPLES();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkDataObject::FIELD_OPERATION()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_FIELD_OPERATION::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_FIELD_OPERATION::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkDataObject::FIELD_OPERATION();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationDoubleVectorKey * vtkDataObject::FIELD_RANGE()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_FIELD_RANGE::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationDoubleVectorKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_FIELD_RANGE::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationDoubleVectorKey * res =   vtkDataObject::FIELD_RANGE();
  return AMILabType<vtkInformationDoubleVectorKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationDoubleVectorKey * vtkDataObject::PIECE_FIELD_RANGE()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_PIECE_FIELD_RANGE::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationDoubleVectorKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_PIECE_FIELD_RANGE::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationDoubleVectorKey * res =   vtkDataObject::PIECE_FIELD_RANGE();
  return AMILabType<vtkInformationDoubleVectorKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerVectorKey * vtkDataObject::PIECE_EXTENT()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_PIECE_EXTENT::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerVectorKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_PIECE_EXTENT::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerVectorKey * res =   vtkDataObject::PIECE_EXTENT();
  return AMILabType<vtkInformationIntegerVectorKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationStringKey

//---------------------------------------------------
//  Wrapping of vtkInformationStringKey * vtkDataObject::FIELD_NAME()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_FIELD_NAME::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationStringKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_FIELD_NAME::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationStringKey * res =   vtkDataObject::FIELD_NAME();
  return AMILabType<vtkInformationStringKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationDoubleVectorKey * vtkDataObject::ORIGIN()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_ORIGIN::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationDoubleVectorKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_ORIGIN::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationDoubleVectorKey * res =   vtkDataObject::ORIGIN();
  return AMILabType<vtkInformationDoubleVectorKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationDoubleVectorKey * vtkDataObject::SPACING()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SPACING::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationDoubleVectorKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SPACING::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationDoubleVectorKey * res =   vtkDataObject::SPACING();
  return AMILabType<vtkInformationDoubleVectorKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkDataObject::DATA_GEOMETRY_UNMODIFIED()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_DATA_GEOMETRY_UNMODIFIED::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_DATA_GEOMETRY_UNMODIFIED::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkDataObject::DATA_GEOMETRY_UNMODIFIED();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationDataObjectKey

//---------------------------------------------------
//  Wrapping of vtkInformationDataObjectKey * vtkDataObject::SIL()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SIL::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationDataObjectKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SIL::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationDataObjectKey * res =   vtkDataObject::SIL();
  return AMILabType<vtkInformationDataObjectKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of vtkDataObject * vtkDataObject::GetData(vtkInformation * info)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetData_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'info'")
  return_comments="returning a variable of type vtkDataObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetData_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkInformation > info_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(info_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkInformation* info = info_smtptr.get();

  vtkDataObject * res =   vtkDataObject::GetData(info);
  BasicVariable::ptr res_var = WrapClass_vtkDataObject::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkDataObject::GetData(...)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetData::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetData::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformationVector

//---------------------------------------------------
//  Wrapping of vtkDataObject * vtkDataObject::GetData(vtkInformationVector * v, int i = 0)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetData_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationVector, "parameter named 'v'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i' (def:0)")
  return_comments="returning a variable of type vtkDataObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetData_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkInformationVector > v_smtptr;
  if (!get_val_smtptr_param<vtkInformationVector >(v_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkInformationVector* v = v_smtptr.get();

  int i = 0;
  if (!get_val_param<int >(i,_p,_n)) ClassReturnEmptyVar;

  vtkDataObject * res =   vtkDataObject::GetData(v, i);
  BasicVariable::ptr res_var = WrapClass_vtkDataObject::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of int vtkDataObject::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_IsA::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   this->_objectptr->GetObj()->IsA(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkDataObject * vtkDataObject::NewInstance()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkDataObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkDataObject * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkDataObject::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkDataObject::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_PrintSelf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<basic_ostream<char,std::char_traits<char> > > os_smtptr;
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!get_val_param<vtkIndent >(indent,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PrintSelf(os, indent);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkSource

//---------------------------------------------------
//  Wrapping of vtkSource * vtkDataObject::GetSource()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetSource::SetParametersComments()
{
  return_comments="returning a variable of type vtkSource";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetSource::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkSource * res =   this->_objectptr->GetObj()->GetSource();
  return AMILabType<vtkSource >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkSource

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetSource(vtkSource * s)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetSource::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkSource, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetSource::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkSource > s_smtptr;
  if (!get_val_smtptr_param<vtkSource >(s_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkSource* s = s_smtptr.get();

  this->_objectptr->GetObj()->SetSource(s);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of vtkInformation * vtkDataObject::GetInformation()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetInformation::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformation";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetInformation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformation * res =   this->_objectptr->GetObj()->GetInformation();
  return AMILabType<vtkInformation >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetInformation(vtkInformation * param0)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkInformation > param0_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkInformation* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetInformation(param0);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of vtkInformation * vtkDataObject::GetPipelineInformation()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetPipelineInformation::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformation";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetPipelineInformation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformation * res =   this->_objectptr->GetObj()->GetPipelineInformation();
  return AMILabType<vtkInformation >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetPipelineInformation(vtkInformation * param0)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetPipelineInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetPipelineInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkInformation > param0_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkInformation* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetPipelineInformation(param0);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkAlgorithmOutput

//---------------------------------------------------
//  Wrapping of vtkAlgorithmOutput * vtkDataObject::GetProducerPort()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetProducerPort::SetParametersComments()
{
  return_comments="returning a variable of type vtkAlgorithmOutput";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetProducerPort::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAlgorithmOutput * res =   this->_objectptr->GetObj()->GetProducerPort();
  return AMILabType<vtkAlgorithmOutput >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of long unsigned int vtkDataObject::GetMTime()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::Initialize()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_Initialize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_Initialize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Initialize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::ReleaseData()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_ReleaseData::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_ReleaseData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ReleaseData();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkDataObject::ShouldIReleaseData()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_ShouldIReleaseData::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_ShouldIReleaseData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->ShouldIReleaseData();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkDataObject::GetDataReleased()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetDataReleased::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetDataReleased::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDataReleased();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetReleaseDataFlag(int param0)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetReleaseDataFlag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetReleaseDataFlag::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetReleaseDataFlag(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkDataObject::GetReleaseDataFlag()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetReleaseDataFlag::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetReleaseDataFlag::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetReleaseDataFlag();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::ReleaseDataFlagOn()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_ReleaseDataFlagOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_ReleaseDataFlagOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ReleaseDataFlagOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::ReleaseDataFlagOff()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_ReleaseDataFlagOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_ReleaseDataFlagOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ReleaseDataFlagOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::GlobalReleaseDataFlagOn()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GlobalReleaseDataFlagOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GlobalReleaseDataFlagOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GlobalReleaseDataFlagOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::GlobalReleaseDataFlagOff()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GlobalReleaseDataFlagOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GlobalReleaseDataFlagOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GlobalReleaseDataFlagOff();
  return BasicVariable::ptr();
}
/* The following types are missing: vtkFieldData

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetFieldData(vtkFieldData * param0)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetFieldData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkFieldData, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetFieldData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkFieldData > param0_smtptr;
  if (!get_val_smtptr_param<vtkFieldData >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkFieldData* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetFieldData(param0);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkFieldData

//---------------------------------------------------
//  Wrapping of vtkFieldData * vtkDataObject::GetFieldData()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetFieldData::SetParametersComments()
{
  return_comments="returning a variable of type vtkFieldData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetFieldData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkFieldData * res =   this->_objectptr->GetObj()->GetFieldData();
  return AMILabType<vtkFieldData >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkDataObject::Register(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_Register::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_Register::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  this->_objectptr->GetObj()->Register(o);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::UnRegister(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_UnRegister::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_UnRegister::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  this->_objectptr->GetObj()->UnRegister(o);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::Update()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_Update::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_Update::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Update();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::UpdateInformation()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_UpdateInformation::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_UpdateInformation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UpdateInformation();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::PropagateUpdateExtent()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_PropagateUpdateExtent::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_PropagateUpdateExtent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PropagateUpdateExtent();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::TriggerAsynchronousUpdate()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_TriggerAsynchronousUpdate::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_TriggerAsynchronousUpdate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->TriggerAsynchronousUpdate();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::UpdateData()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_UpdateData::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_UpdateData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UpdateData();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkDataObject::GetEstimatedMemorySize()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetEstimatedMemorySize::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetEstimatedMemorySize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetEstimatedMemorySize();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetUpdateExtent(int piece, int numPieces, int ghostLevel)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetUpdateExtent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'piece'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'numPieces'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ghostLevel'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetUpdateExtent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int piece;
  if (!get_val_param<int >(piece,_p,_n)) ClassReturnEmptyVar;

  int numPieces;
  if (!get_val_param<int >(numPieces,_p,_n)) ClassReturnEmptyVar;

  int ghostLevel;
  if (!get_val_param<int >(ghostLevel,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetUpdateExtent(piece, numPieces, ghostLevel);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkDataObject::SetUpdateExtent(...)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetUpdateExtent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetUpdateExtent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkDataObject::wrap_SetUpdateExtent_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkDataObject::wrap_SetUpdateExtent_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkDataObject::wrap_SetUpdateExtent_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_vtkDataObject::wrap_SetUpdateExtent_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetUpdateExtent(int piece, int numPieces)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetUpdateExtent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'piece'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'numPieces'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetUpdateExtent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int piece;
  if (!get_val_param<int >(piece,_p,_n)) ClassReturnEmptyVar;

  int numPieces;
  if (!get_val_param<int >(numPieces,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetUpdateExtent(piece, numPieces);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetUpdateExtent(int x0, int x1, int y0, int y1, int z0, int z1)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetUpdateExtent_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetUpdateExtent_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  int x0;
  if (!get_val_param<int >(x0,_p,_n)) ClassReturnEmptyVar;

  int x1;
  if (!get_val_param<int >(x1,_p,_n)) ClassReturnEmptyVar;

  int y0;
  if (!get_val_param<int >(y0,_p,_n)) ClassReturnEmptyVar;

  int y1;
  if (!get_val_param<int >(y1,_p,_n)) ClassReturnEmptyVar;

  int z0;
  if (!get_val_param<int >(z0,_p,_n)) ClassReturnEmptyVar;

  int z1;
  if (!get_val_param<int >(z1,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetUpdateExtent(x0, x1, y0, y1, z0, z1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetUpdateExtent(int * extent)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetUpdateExtent_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'extent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetUpdateExtent_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > extent_smtptr;
  if (!get_val_smtptr_param<int >(extent_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* extent = extent_smtptr.get();

  this->_objectptr->GetObj()->SetUpdateExtent(extent);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int * vtkDataObject::GetUpdateExtent()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetUpdateExtent_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetUpdateExtent_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int * res =   this->_objectptr->GetObj()->GetUpdateExtent();
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkDataObject::GetUpdateExtent(...)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetUpdateExtent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetUpdateExtent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkDataObject::wrap_GetUpdateExtent_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkDataObject::wrap_GetUpdateExtent_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkDataObject::wrap_GetUpdateExtent_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::GetUpdateExtent(int & x0, int & x1, int & y0, int & y1, int & z0, int & z1)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetUpdateExtent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetUpdateExtent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > x0_smtptr;
  if (!get_val_smtptr_param<int >(x0_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & x0 = *x0_smtptr;

  boost::shared_ptr<int > x1_smtptr;
  if (!get_val_smtptr_param<int >(x1_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & x1 = *x1_smtptr;

  boost::shared_ptr<int > y0_smtptr;
  if (!get_val_smtptr_param<int >(y0_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & y0 = *y0_smtptr;

  boost::shared_ptr<int > y1_smtptr;
  if (!get_val_smtptr_param<int >(y1_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & y1 = *y1_smtptr;

  boost::shared_ptr<int > z0_smtptr;
  if (!get_val_smtptr_param<int >(z0_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & z0 = *z0_smtptr;

  boost::shared_ptr<int > z1_smtptr;
  if (!get_val_smtptr_param<int >(z1_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & z1 = *z1_smtptr;

  this->_objectptr->GetObj()->GetUpdateExtent(x0, x1, y0, y1, z0, z1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::GetUpdateExtent(int * extent)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetUpdateExtent_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'extent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetUpdateExtent_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > extent_smtptr;
  if (!get_val_smtptr_param<int >(extent_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* extent = extent_smtptr.get();

  this->_objectptr->GetObj()->GetUpdateExtent(extent);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkDataObject::GetDataObjectType()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetDataObjectType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetDataObjectType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDataObjectType();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkDataObject::GetUpdateTime()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetUpdateTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetUpdateTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetUpdateTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetUpdateExtentToWholeExtent()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetUpdateExtentToWholeExtent::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetUpdateExtentToWholeExtent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetUpdateExtentToWholeExtent();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkDataObject::GetPipelineMTime()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetPipelineMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetPipelineMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetPipelineMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkDataObject::GetActualMemorySize()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetActualMemorySize::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetActualMemorySize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetActualMemorySize();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::CopyInformation(vtkDataObject * data)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_CopyInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_CopyInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkDataObject > data_smtptr;
  if (!get_val_smtptr_param<vtkDataObject >(data_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkDataObject* data = data_smtptr.get();

  this->_objectptr->GetObj()->CopyInformation(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::CopyTypeSpecificInformation(vtkDataObject * data)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_CopyTypeSpecificInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_CopyTypeSpecificInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkDataObject > data_smtptr;
  if (!get_val_smtptr_param<vtkDataObject >(data_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkDataObject* data = data_smtptr.get();

  this->_objectptr->GetObj()->CopyTypeSpecificInformation(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetUpdatePiece(int piece)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetUpdatePiece::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'piece'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetUpdatePiece::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int piece;
  if (!get_val_param<int >(piece,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetUpdatePiece(piece);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetUpdateNumberOfPieces(int num)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetUpdateNumberOfPieces::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'num'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetUpdateNumberOfPieces::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int num;
  if (!get_val_param<int >(num,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetUpdateNumberOfPieces(num);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkDataObject::GetUpdatePiece()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetUpdatePiece::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetUpdatePiece::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetUpdatePiece();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkDataObject::GetUpdateNumberOfPieces()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetUpdateNumberOfPieces::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetUpdateNumberOfPieces::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetUpdateNumberOfPieces();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetUpdateGhostLevel(int level)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetUpdateGhostLevel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'level'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetUpdateGhostLevel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int level;
  if (!get_val_param<int >(level,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetUpdateGhostLevel(level);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkDataObject::GetUpdateGhostLevel()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetUpdateGhostLevel::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetUpdateGhostLevel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetUpdateGhostLevel();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetRequestExactExtent(int flag)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetRequestExactExtent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetRequestExactExtent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int flag;
  if (!get_val_param<int >(flag,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRequestExactExtent(flag);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkDataObject::GetRequestExactExtent()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetRequestExactExtent::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetRequestExactExtent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetRequestExactExtent();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::RequestExactExtentOn()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_RequestExactExtentOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_RequestExactExtentOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RequestExactExtentOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::RequestExactExtentOff()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_RequestExactExtentOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_RequestExactExtentOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RequestExactExtentOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetWholeExtent(int x0, int x1, int y0, int y1, int z0, int z1)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetWholeExtent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetWholeExtent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  int x0;
  if (!get_val_param<int >(x0,_p,_n)) ClassReturnEmptyVar;

  int x1;
  if (!get_val_param<int >(x1,_p,_n)) ClassReturnEmptyVar;

  int y0;
  if (!get_val_param<int >(y0,_p,_n)) ClassReturnEmptyVar;

  int y1;
  if (!get_val_param<int >(y1,_p,_n)) ClassReturnEmptyVar;

  int z0;
  if (!get_val_param<int >(z0,_p,_n)) ClassReturnEmptyVar;

  int z1;
  if (!get_val_param<int >(z1,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetWholeExtent(x0, x1, y0, y1, z0, z1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkDataObject::SetWholeExtent(...)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetWholeExtent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetWholeExtent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkDataObject::wrap_SetWholeExtent_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkDataObject::wrap_SetWholeExtent_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetWholeExtent(int * extent)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetWholeExtent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'extent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetWholeExtent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > extent_smtptr;
  if (!get_val_smtptr_param<int >(extent_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* extent = extent_smtptr.get();

  this->_objectptr->GetObj()->SetWholeExtent(extent);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int * vtkDataObject::GetWholeExtent()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetWholeExtent_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetWholeExtent_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int * res =   this->_objectptr->GetObj()->GetWholeExtent();
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkDataObject::GetWholeExtent(...)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetWholeExtent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetWholeExtent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkDataObject::wrap_GetWholeExtent_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkDataObject::wrap_GetWholeExtent_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkDataObject::wrap_GetWholeExtent_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::GetWholeExtent(int & x0, int & x1, int & y0, int & y1, int & z0, int & z1)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetWholeExtent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetWholeExtent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > x0_smtptr;
  if (!get_val_smtptr_param<int >(x0_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & x0 = *x0_smtptr;

  boost::shared_ptr<int > x1_smtptr;
  if (!get_val_smtptr_param<int >(x1_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & x1 = *x1_smtptr;

  boost::shared_ptr<int > y0_smtptr;
  if (!get_val_smtptr_param<int >(y0_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & y0 = *y0_smtptr;

  boost::shared_ptr<int > y1_smtptr;
  if (!get_val_smtptr_param<int >(y1_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & y1 = *y1_smtptr;

  boost::shared_ptr<int > z0_smtptr;
  if (!get_val_smtptr_param<int >(z0_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & z0 = *z0_smtptr;

  boost::shared_ptr<int > z1_smtptr;
  if (!get_val_smtptr_param<int >(z1_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & z1 = *z1_smtptr;

  this->_objectptr->GetObj()->GetWholeExtent(x0, x1, y0, y1, z0, z1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::GetWholeExtent(int * extent)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetWholeExtent_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'extent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetWholeExtent_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > extent_smtptr;
  if (!get_val_smtptr_param<int >(extent_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* extent = extent_smtptr.get();

  this->_objectptr->GetObj()->GetWholeExtent(extent);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetWholeBoundingBox(double x0, double x1, double y0, double y1, double z0, double z1)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetWholeBoundingBox_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetWholeBoundingBox_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  double x0;
  if (!get_val_param<double >(x0,_p,_n)) ClassReturnEmptyVar;

  double x1;
  if (!get_val_param<double >(x1,_p,_n)) ClassReturnEmptyVar;

  double y0;
  if (!get_val_param<double >(y0,_p,_n)) ClassReturnEmptyVar;

  double y1;
  if (!get_val_param<double >(y1,_p,_n)) ClassReturnEmptyVar;

  double z0;
  if (!get_val_param<double >(z0,_p,_n)) ClassReturnEmptyVar;

  double z1;
  if (!get_val_param<double >(z1,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetWholeBoundingBox(x0, x1, y0, y1, z0, z1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkDataObject::SetWholeBoundingBox(...)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetWholeBoundingBox::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetWholeBoundingBox::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkDataObject::wrap_SetWholeBoundingBox_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkDataObject::wrap_SetWholeBoundingBox_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetWholeBoundingBox(double * bb)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetWholeBoundingBox_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bb'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetWholeBoundingBox_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > bb_smtptr;
  if (!get_val_smtptr_param<double >(bb_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* bb = bb_smtptr.get();

  this->_objectptr->GetObj()->SetWholeBoundingBox(bb);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkDataObject::GetWholeBoundingBox()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetWholeBoundingBox_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetWholeBoundingBox_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetWholeBoundingBox();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkDataObject::GetWholeBoundingBox(...)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetWholeBoundingBox::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetWholeBoundingBox::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkDataObject::wrap_GetWholeBoundingBox_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkDataObject::wrap_GetWholeBoundingBox_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkDataObject::wrap_GetWholeBoundingBox_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::GetWholeBoundingBox(double & x0, double & x1, double & y0, double & y1, double & z0, double & z1)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetWholeBoundingBox_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetWholeBoundingBox_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > x0_smtptr;
  if (!get_val_smtptr_param<double >(x0_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & x0 = *x0_smtptr;

  boost::shared_ptr<double > x1_smtptr;
  if (!get_val_smtptr_param<double >(x1_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & x1 = *x1_smtptr;

  boost::shared_ptr<double > y0_smtptr;
  if (!get_val_smtptr_param<double >(y0_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & y0 = *y0_smtptr;

  boost::shared_ptr<double > y1_smtptr;
  if (!get_val_smtptr_param<double >(y1_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & y1 = *y1_smtptr;

  boost::shared_ptr<double > z0_smtptr;
  if (!get_val_smtptr_param<double >(z0_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & z0 = *z0_smtptr;

  boost::shared_ptr<double > z1_smtptr;
  if (!get_val_smtptr_param<double >(z1_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & z1 = *z1_smtptr;

  this->_objectptr->GetObj()->GetWholeBoundingBox(x0, x1, y0, y1, z0, z1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::GetWholeBoundingBox(double * extent)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetWholeBoundingBox_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'extent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetWholeBoundingBox_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > extent_smtptr;
  if (!get_val_smtptr_param<double >(extent_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* extent = extent_smtptr.get();

  this->_objectptr->GetObj()->GetWholeBoundingBox(extent);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetMaximumNumberOfPieces(int param0)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetMaximumNumberOfPieces::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetMaximumNumberOfPieces::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMaximumNumberOfPieces(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkDataObject::GetMaximumNumberOfPieces()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetMaximumNumberOfPieces::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetMaximumNumberOfPieces::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMaximumNumberOfPieces();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: vtkInformation, vtkInformation, vtkInformation

//---------------------------------------------------
//  Wrapping of void vtkDataObject::CopyInformationToPipeline(vtkInformation * request, vtkInformation * input, vtkInformation * output, int forceCopy)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_CopyInformationToPipeline_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'request'")
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'input'")
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'output'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'forceCopy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_CopyInformationToPipeline_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkInformation > request_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(request_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkInformation* request = request_smtptr.get();

  boost::shared_ptr<vtkInformation > input_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(input_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkInformation* input = input_smtptr.get();

  boost::shared_ptr<vtkInformation > output_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(output_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkInformation* output = output_smtptr.get();

  int forceCopy;
  if (!get_val_param<int >(forceCopy,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->CopyInformationToPipeline(request, input, output, forceCopy);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkDataObject::CopyInformationToPipeline(...)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_CopyInformationToPipeline::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_CopyInformationToPipeline::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformation, vtkInformation

//---------------------------------------------------
//  Wrapping of void vtkDataObject::CopyInformationToPipeline(vtkInformation * request, vtkInformation * input)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_CopyInformationToPipeline_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'request'")
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'input'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_CopyInformationToPipeline_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkInformation > request_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(request_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkInformation* request = request_smtptr.get();

  boost::shared_ptr<vtkInformation > input_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(input_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkInformation* input = input_smtptr.get();

  this->_objectptr->GetObj()->CopyInformationToPipeline(request, input);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of void vtkDataObject::CopyInformationFromPipeline(vtkInformation * request)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_CopyInformationFromPipeline::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'request'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_CopyInformationFromPipeline::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkInformation > request_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(request_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkInformation* request = request_smtptr.get();

  this->_objectptr->GetObj()->CopyInformationFromPipeline(request);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkDataObject::DataHasBeenGenerated()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_DataHasBeenGenerated::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_DataHasBeenGenerated::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DataHasBeenGenerated();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::PrepareForNewData()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_PrepareForNewData::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_PrepareForNewData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PrepareForNewData();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::ShallowCopy(vtkDataObject * src)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_ShallowCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_ShallowCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkDataObject > src_smtptr;
  if (!get_val_smtptr_param<vtkDataObject >(src_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkDataObject* src = src_smtptr.get();

  this->_objectptr->GetObj()->ShallowCopy(src);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::DeepCopy(vtkDataObject * src)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_DeepCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_DeepCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkDataObject > src_smtptr;
  if (!get_val_smtptr_param<vtkDataObject >(src_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkDataObject* src = src_smtptr.get();

  this->_objectptr->GetObj()->DeepCopy(src);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkExtentTranslator

//---------------------------------------------------
//  Wrapping of void vtkDataObject::SetExtentTranslator(vtkExtentTranslator * translator)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_SetExtentTranslator::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkExtentTranslator, "parameter named 'translator'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_SetExtentTranslator::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkExtentTranslator > translator_smtptr;
  if (!get_val_smtptr_param<vtkExtentTranslator >(translator_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkExtentTranslator* translator = translator_smtptr.get();

  this->_objectptr->GetObj()->SetExtentTranslator(translator);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkExtentTranslator

//---------------------------------------------------
//  Wrapping of vtkExtentTranslator * vtkDataObject::GetExtentTranslator()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetExtentTranslator::SetParametersComments()
{
  return_comments="returning a variable of type vtkExtentTranslator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetExtentTranslator::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkExtentTranslator * res =   this->_objectptr->GetObj()->GetExtentTranslator();
  return AMILabType<vtkExtentTranslator >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of int vtkDataObject::GetExtentType()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetExtentType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetExtentType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetExtentType();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkDataObject::Crop()
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_Crop::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_Crop::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Crop();
  return BasicVariable::ptr();
}
/* The following types are missing: vtkDataSetAttributes

//---------------------------------------------------
//  Wrapping of vtkDataSetAttributes * vtkDataObject::GetAttributes(int type)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetAttributes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  return_comments="returning a variable of type vtkDataSetAttributes";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetAttributes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int type;
  if (!get_val_param<int >(type,_p,_n)) ClassHelpAndReturn;

  vtkDataSetAttributes * res =   this->_objectptr->GetObj()->GetAttributes(type);
  return AMILabType<vtkDataSetAttributes >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkFieldData

//---------------------------------------------------
//  Wrapping of vtkFieldData * vtkDataObject::GetAttributesAsFieldData(int type)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetAttributesAsFieldData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  return_comments="returning a variable of type vtkFieldData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetAttributesAsFieldData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int type;
  if (!get_val_param<int >(type,_p,_n)) ClassHelpAndReturn;

  vtkFieldData * res =   this->_objectptr->GetObj()->GetAttributesAsFieldData(type);
  return AMILabType<vtkFieldData >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkAbstractArray

//---------------------------------------------------
//  Wrapping of int vtkDataObject::GetAttributeTypeForArray(vtkAbstractArray * arr)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetAttributeTypeForArray::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAbstractArray, "parameter named 'arr'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetAttributeTypeForArray::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkAbstractArray > arr_smtptr;
  if (!get_val_smtptr_param<vtkAbstractArray >(arr_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkAbstractArray* arr = arr_smtptr.get();

  int res =   this->_objectptr->GetObj()->GetAttributeTypeForArray(arr);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: long long int

//---------------------------------------------------
//  Wrapping of vtkIdType vtkDataObject::GetNumberOfElements(int type)
//---------------------------------------------------
void WrapClass_vtkDataObject::
    wrap_GetNumberOfElements::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  return_comments="returning a variable of type long long int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataObject::
    wrap_GetNumberOfElements::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int type;
  if (!get_val_param<int >(type,_p,_n)) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->GetNumberOfElements(type);
  return AMILabType<long long int >::CreateVar(res);
}
*/

