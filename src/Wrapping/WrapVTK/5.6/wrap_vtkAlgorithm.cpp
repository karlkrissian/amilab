/**
 * C++ Interface: wrap_vtkAlgorithm
 *
 * Description: wrapping vtkAlgorithm
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

#include "wrap_vtkAlgorithm.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef vtkAlgorithm_declared
  #define vtkAlgorithm_declared
  AMI_DECLARE_TYPE(vtkAlgorithm)
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
BasicVariable::ptr WrapClass<vtkAlgorithm>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkAlgorithm);
AMI_DEFINE_VARFROMSMTPTR(vtkAlgorithm);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkAlgorithm>::CreateVar( vtkAlgorithm* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkAlgorithm> obj_ptr(val,smartpointer_nodeleter<vtkAlgorithm>());
  return AMILabType<vtkAlgorithm>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkAlgorithm
//
Variable<AMIObject>::ptr WrapClass_vtkAlgorithm::CreateVar( vtkAlgorithm* sp)
{
  boost::shared_ptr<vtkAlgorithm> di_ptr(
    sp,
    wxwindow_nodeleter<vtkAlgorithm>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkAlgorithm>::CreateVar(
      new WrapClass_vtkAlgorithm(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkAlgorithm::AddMethods(WrapClass<vtkAlgorithm>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_HasExecutive( this_ptr);
/* The following types are missing: vtkExecutive
  AddVar_GetExecutive( this_ptr);
*/
/* The following types are missing: vtkExecutive
  AddVar_SetExecutive( this_ptr);
*/
/* The following types are missing: vtkInformation, vtkInformationVector, vtkInformationVector
  AddVar_ProcessRequest( this_ptr);
*/
/* The following types are missing: vtkInformation, vtkInformationVector, vtkInformationVector
  AddVar_ComputePipelineMTime( this_ptr);
*/
/* The following types are missing: vtkInformation
  AddVar_ModifyRequest( this_ptr);
*/
/* The following types are missing: vtkInformation
  AddVar_GetInputPortInformation( this_ptr);
*/
/* The following types are missing: vtkInformation
  AddVar_GetOutputPortInformation( this_ptr);
*/
/* The following types are missing: vtkInformation
  AddVar_GetInformation( this_ptr);
*/
/* The following types are missing: vtkInformation
  AddVar_SetInformation( this_ptr);
*/
  AddVar_GetNumberOfInputPorts( this_ptr);
  AddVar_GetNumberOfOutputPorts( this_ptr);
  AddVar_Register( this_ptr);
  AddVar_UnRegister( this_ptr);
  AddVar_SetAbortExecute( this_ptr);
  AddVar_GetAbortExecute( this_ptr);
  AddVar_AbortExecuteOn( this_ptr);
  AddVar_AbortExecuteOff( this_ptr);
  AddVar_SetProgress( this_ptr);
  AddVar_GetProgressMinValue( this_ptr);
  AddVar_GetProgressMaxValue( this_ptr);
  AddVar_GetProgress( this_ptr);
  AddVar_UpdateProgress( this_ptr);
  AddVar_SetProgressText( this_ptr);
  AddVar_GetProgressText( this_ptr);
  AddVar_GetErrorCode( this_ptr);
  AddVar_SetInputArrayToProcess_1( this_ptr);
  AddVar_SetInputArrayToProcess( this_ptr);
  AddVar_SetInputArrayToProcess_2( this_ptr);
/* The following types are missing: vtkInformation
  AddVar_SetInputArrayToProcess_3( this_ptr);
*/
  AddVar_SetInputArrayToProcess_4( this_ptr);
/* The following types are missing: vtkInformation
  AddVar_GetInputArrayInformation( this_ptr);
*/
  AddVar_RemoveAllInputs( this_ptr);
  AddVar_GetOutputDataObject( this_ptr);
  AddVar_GetInputDataObject( this_ptr);
/* The following types are missing: vtkAlgorithmOutput
  AddVar_SetInputConnection_1( this_ptr);
*/
  AddVar_SetInputConnection( this_ptr);
/* The following types are missing: vtkAlgorithmOutput
  AddVar_SetInputConnection_2( this_ptr);
*/
/* The following types are missing: vtkAlgorithmOutput
  AddVar_AddInputConnection_1( this_ptr);
*/
  AddVar_AddInputConnection( this_ptr);
/* The following types are missing: vtkAlgorithmOutput
  AddVar_AddInputConnection_2( this_ptr);
*/
/* The following types are missing: vtkAlgorithmOutput
  AddVar_RemoveInputConnection( this_ptr);
*/
/* The following types are missing: vtkAlgorithmOutput
  AddVar_GetOutputPort_1( this_ptr);
*/
  AddVar_GetOutputPort( this_ptr);
/* The following types are missing: vtkAlgorithmOutput
  AddVar_GetOutputPort_2( this_ptr);
*/
  AddVar_GetNumberOfInputConnections( this_ptr);
  AddVar_GetTotalNumberOfInputConnections( this_ptr);
/* The following types are missing: vtkAlgorithmOutput
  AddVar_GetInputConnection( this_ptr);
*/
  AddVar_Update( this_ptr);
  AddVar_UpdateInformation( this_ptr);
  AddVar_UpdateWholeExtent( this_ptr);
  AddVar_ConvertTotalInputToPortConnection( this_ptr);
  AddVar_SetReleaseDataFlag( this_ptr);
  AddVar_GetReleaseDataFlag( this_ptr);
  AddVar_ReleaseDataFlagOn( this_ptr);
  AddVar_ReleaseDataFlagOff( this_ptr);
  AddVar_UpdateExtentIsEmpty_1( this_ptr);
  AddVar_UpdateExtentIsEmpty( this_ptr);
/* The following types are missing: vtkInformation
  AddVar_UpdateExtentIsEmpty_2( this_ptr);
*/
  AddVar_ComputePriority( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());
  
  // Adding public member AbortExecute
  boost::shared_ptr<int > var_AbortExecute_ptr(&GetObj()->AbortExecute, smartpointer_nodeleter<int >());
  if (var_AbortExecute_ptr.get()) {
    BasicVariable::ptr var_AbortExecute = AMILabType<int >::CreateVarFromSmtPtr(var_AbortExecute_ptr);
    if (var_AbortExecute.get()) {
      var_AbortExecute->Rename("AbortExecute");
      context->AddVar(var_AbortExecute,context);
    }
  }


  


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
void WrapClassvtkAlgorithm_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkAlgorithm");
  
  // Static methods 
  WrapClass_vtkAlgorithm::AddVar_New(amiobject->GetContext());
  WrapClass_vtkAlgorithm::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkAlgorithm::AddVar_SafeDownCast(amiobject->GetContext());
  /* Types are missing
  WrapClass_vtkAlgorithm::AddVar_INPUT_IS_OPTIONAL(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkAlgorithm::AddVar_INPUT_IS_REPEATABLE(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkAlgorithm::AddVar_INPUT_REQUIRED_FIELDS(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkAlgorithm::AddVar_INPUT_REQUIRED_DATA_TYPE(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkAlgorithm::AddVar_INPUT_ARRAYS_TO_PROCESS(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkAlgorithm::AddVar_INPUT_PORT(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkAlgorithm::AddVar_INPUT_CONNECTION(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkAlgorithm::AddVar_SetDefaultExecutivePrototype(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkAlgorithm::AddVar_PRESERVES_DATASET(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkAlgorithm::AddVar_PRESERVES_GEOMETRY(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkAlgorithm::AddVar_PRESERVES_BOUNDS(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkAlgorithm::AddVar_PRESERVES_TOPOLOGY(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkAlgorithm::AddVar_PRESERVES_ATTRIBUTES(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkAlgorithm::AddVar_PRESERVES_RANGES(amiobject->GetContext());
  */

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkAlgorithm * vtkAlgorithm::New()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkAlgorithm";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAlgorithm * res =   vtkAlgorithm::New();
  BasicVariable::ptr res_var = AMILabType<vtkAlgorithm >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkAlgorithm::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkAlgorithm::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkAlgorithm * vtkAlgorithm::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkAlgorithm";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
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

  vtkAlgorithm * res =   vtkAlgorithm::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkAlgorithm >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkAlgorithm::INPUT_IS_OPTIONAL()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_INPUT_IS_OPTIONAL::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_static_INPUT_IS_OPTIONAL::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkAlgorithm::INPUT_IS_OPTIONAL();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkAlgorithm::INPUT_IS_REPEATABLE()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_INPUT_IS_REPEATABLE::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_static_INPUT_IS_REPEATABLE::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkAlgorithm::INPUT_IS_REPEATABLE();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationInformationVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationInformationVectorKey * vtkAlgorithm::INPUT_REQUIRED_FIELDS()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_INPUT_REQUIRED_FIELDS::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationInformationVectorKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_static_INPUT_REQUIRED_FIELDS::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationInformationVectorKey * res =   vtkAlgorithm::INPUT_REQUIRED_FIELDS();
  return AMILabType<vtkInformationInformationVectorKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationStringVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationStringVectorKey * vtkAlgorithm::INPUT_REQUIRED_DATA_TYPE()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_INPUT_REQUIRED_DATA_TYPE::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationStringVectorKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_static_INPUT_REQUIRED_DATA_TYPE::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationStringVectorKey * res =   vtkAlgorithm::INPUT_REQUIRED_DATA_TYPE();
  return AMILabType<vtkInformationStringVectorKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationInformationVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationInformationVectorKey * vtkAlgorithm::INPUT_ARRAYS_TO_PROCESS()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_INPUT_ARRAYS_TO_PROCESS::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationInformationVectorKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_static_INPUT_ARRAYS_TO_PROCESS::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationInformationVectorKey * res =   vtkAlgorithm::INPUT_ARRAYS_TO_PROCESS();
  return AMILabType<vtkInformationInformationVectorKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkAlgorithm::INPUT_PORT()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_INPUT_PORT::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_static_INPUT_PORT::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkAlgorithm::INPUT_PORT();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkAlgorithm::INPUT_CONNECTION()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_INPUT_CONNECTION::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_static_INPUT_CONNECTION::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkAlgorithm::INPUT_CONNECTION();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkExecutive

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::SetDefaultExecutivePrototype(vtkExecutive * proto)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_SetDefaultExecutivePrototype::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkExecutive, "parameter named 'proto'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_static_SetDefaultExecutivePrototype::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkExecutive* proto;
  if (CheckNullVar(_p,_n))  {
    proto=(vtkExecutive*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkExecutive > proto_smtptr;
    if (!get_val_smtptr_param<vtkExecutive >(proto_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    proto = proto_smtptr.get();
  }

  vtkAlgorithm::SetDefaultExecutivePrototype(proto);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkAlgorithm::PRESERVES_DATASET()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_PRESERVES_DATASET::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_static_PRESERVES_DATASET::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkAlgorithm::PRESERVES_DATASET();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkAlgorithm::PRESERVES_GEOMETRY()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_PRESERVES_GEOMETRY::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_static_PRESERVES_GEOMETRY::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkAlgorithm::PRESERVES_GEOMETRY();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkAlgorithm::PRESERVES_BOUNDS()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_PRESERVES_BOUNDS::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_static_PRESERVES_BOUNDS::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkAlgorithm::PRESERVES_BOUNDS();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkAlgorithm::PRESERVES_TOPOLOGY()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_PRESERVES_TOPOLOGY::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_static_PRESERVES_TOPOLOGY::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkAlgorithm::PRESERVES_TOPOLOGY();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkAlgorithm::PRESERVES_ATTRIBUTES()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_PRESERVES_ATTRIBUTES::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_static_PRESERVES_ATTRIBUTES::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkAlgorithm::PRESERVES_ATTRIBUTES();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationIntegerKey

//---------------------------------------------------
//  Wrapping of vtkInformationIntegerKey * vtkAlgorithm::PRESERVES_RANGES()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_static_PRESERVES_RANGES::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationIntegerKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_static_PRESERVES_RANGES::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationIntegerKey * res =   vtkAlgorithm::PRESERVES_RANGES();
  return AMILabType<vtkInformationIntegerKey >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of int vtkAlgorithm::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
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
//  Wrapping of vtkAlgorithm * vtkAlgorithm::NewInstance()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkAlgorithm";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAlgorithm * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkAlgorithm >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
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

//---------------------------------------------------
//  Wrapping of int vtkAlgorithm::HasExecutive()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_HasExecutive::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_HasExecutive::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->HasExecutive();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: vtkExecutive

//---------------------------------------------------
//  Wrapping of vtkExecutive * vtkAlgorithm::GetExecutive()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetExecutive::SetParametersComments()
{
  return_comments="returning a variable of type vtkExecutive";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetExecutive::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkExecutive * res =   this->_objectptr->GetObj()->GetExecutive();
  return AMILabType<vtkExecutive >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkExecutive

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::SetExecutive(vtkExecutive * executive)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_SetExecutive::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkExecutive, "parameter named 'executive'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_SetExecutive::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkExecutive* executive;
  if (CheckNullVar(_p,_n))  {
    executive=(vtkExecutive*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkExecutive > executive_smtptr;
    if (!get_val_smtptr_param<vtkExecutive >(executive_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    executive = executive_smtptr.get();
  }

  this->_objectptr->GetObj()->SetExecutive(executive);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformation, vtkInformationVector, vtkInformationVector

//---------------------------------------------------
//  Wrapping of int vtkAlgorithm::ProcessRequest(vtkInformation * request, vtkInformationVector * * inInfo, vtkInformationVector * outInfo)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_ProcessRequest::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'request'")
  ADDPARAMCOMMENT_TYPE( vtkInformationVector, "parameter named 'inInfo'")
  ADDPARAMCOMMENT_TYPE( vtkInformationVector, "parameter named 'outInfo'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_ProcessRequest::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  vtkInformation* request;
  if (CheckNullVar(_p,_n))  {
    request=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > request_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(request_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    request = request_smtptr.get();
  }

  vtkInformationVector* local_inInfo = NULL;
  vtkInformationVector** inInfo;
  if (CheckNullVar(_p,_n))  {
    inInfo=(vtkInformationVector**)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationVector > inInfo_smtptr;
    if (!get_val_smtptr_param<vtkInformationVector >(inInfo_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    local_inInfo = inInfo_smtptr.get();
    inInfo = &local_inInfo;
  }

  vtkInformationVector* outInfo;
  if (CheckNullVar(_p,_n))  {
    outInfo=(vtkInformationVector*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationVector > outInfo_smtptr;
    if (!get_val_smtptr_param<vtkInformationVector >(outInfo_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    outInfo = outInfo_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->ProcessRequest(request, inInfo, outInfo);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformation, vtkInformationVector, vtkInformationVector

//---------------------------------------------------
//  Wrapping of int vtkAlgorithm::ComputePipelineMTime(vtkInformation * request, vtkInformationVector * * inInfoVec, vtkInformationVector * outInfoVec, int requestFromOutputPort, long unsigned int * mtime)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_ComputePipelineMTime::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'request'")
  ADDPARAMCOMMENT_TYPE( vtkInformationVector, "parameter named 'inInfoVec'")
  ADDPARAMCOMMENT_TYPE( vtkInformationVector, "parameter named 'outInfoVec'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'requestFromOutputPort'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'mtime'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_ComputePipelineMTime::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  vtkInformation* request;
  if (CheckNullVar(_p,_n))  {
    request=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > request_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(request_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    request = request_smtptr.get();
  }

  vtkInformationVector* local_inInfoVec = NULL;
  vtkInformationVector** inInfoVec;
  if (CheckNullVar(_p,_n))  {
    inInfoVec=(vtkInformationVector**)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationVector > inInfoVec_smtptr;
    if (!get_val_smtptr_param<vtkInformationVector >(inInfoVec_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    local_inInfoVec = inInfoVec_smtptr.get();
    inInfoVec = &local_inInfoVec;
  }

  vtkInformationVector* outInfoVec;
  if (CheckNullVar(_p,_n))  {
    outInfoVec=(vtkInformationVector*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationVector > outInfoVec_smtptr;
    if (!get_val_smtptr_param<vtkInformationVector >(outInfoVec_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    outInfoVec = outInfoVec_smtptr.get();
  }

  int requestFromOutputPort;
  if (!get_val_param<int >(requestFromOutputPort,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<long > mtime_long;
  if (!get_val_smtptr_param<long >(mtime_long,_p,_n,true,false,false)) ClassHelpAndReturn;
  long unsigned int mtime_val = boost::numeric_cast<long unsigned int >(*mtime_long);
  long unsigned int* mtime = &mtime_val;

  int res =   this->_objectptr->GetObj()->ComputePipelineMTime(request, inInfoVec, outInfoVec, requestFromOutputPort, mtime);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of int vtkAlgorithm::ModifyRequest(vtkInformation * request, int when)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_ModifyRequest::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'request'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'when'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_ModifyRequest::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkInformation* request;
  if (CheckNullVar(_p,_n))  {
    request=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > request_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(request_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    request = request_smtptr.get();
  }

  int when;
  if (!get_val_param<int >(when,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->ModifyRequest(request, when);
  return AMILabType<int >::CreateVar(res);
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of vtkInformation * vtkAlgorithm::GetInputPortInformation(int port)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetInputPortInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'port'")
  return_comments="returning a variable of type vtkInformation";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetInputPortInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int port;
  if (!get_val_param<int >(port,_p,_n,true,false)) ClassHelpAndReturn;

  vtkInformation * res =   this->_objectptr->GetObj()->GetInputPortInformation(port);
  return AMILabType<vtkInformation >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of vtkInformation * vtkAlgorithm::GetOutputPortInformation(int port)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetOutputPortInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'port'")
  return_comments="returning a variable of type vtkInformation";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetOutputPortInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int port;
  if (!get_val_param<int >(port,_p,_n,true,false)) ClassHelpAndReturn;

  vtkInformation * res =   this->_objectptr->GetObj()->GetOutputPortInformation(port);
  return AMILabType<vtkInformation >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of vtkInformation * vtkAlgorithm::GetInformation()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetInformation::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformation";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetInformation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformation * res =   this->_objectptr->GetObj()->GetInformation();
  return AMILabType<vtkInformation >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::SetInformation(vtkInformation * param0)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_SetInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_SetInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkInformation* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > param0_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->SetInformation(param0);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of int vtkAlgorithm::GetNumberOfInputPorts()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetNumberOfInputPorts::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetNumberOfInputPorts::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfInputPorts();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkAlgorithm::GetNumberOfOutputPorts()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetNumberOfOutputPorts::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetNumberOfOutputPorts::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfOutputPorts();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::Register(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_Register::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
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
//  Wrapping of void vtkAlgorithm::UnRegister(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_UnRegister::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
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

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::SetAbortExecute(int _arg)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_SetAbortExecute::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_SetAbortExecute::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAbortExecute(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkAlgorithm::GetAbortExecute()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetAbortExecute::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetAbortExecute::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAbortExecute();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::AbortExecuteOn()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_AbortExecuteOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_AbortExecuteOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AbortExecuteOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::AbortExecuteOff()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_AbortExecuteOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_AbortExecuteOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AbortExecuteOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::SetProgress(double _arg)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_SetProgress::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_SetProgress::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetProgress(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkAlgorithm::GetProgressMinValue()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetProgressMinValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetProgressMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetProgressMinValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkAlgorithm::GetProgressMaxValue()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetProgressMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetProgressMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetProgressMaxValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkAlgorithm::GetProgress()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetProgress::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetProgress::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetProgress();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::UpdateProgress(double amount)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_UpdateProgress::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'amount'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_UpdateProgress::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double amount;
  if (!get_val_param<double >(amount,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UpdateProgress(amount);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::SetProgressText(char const * ptext)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_SetProgressText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ptext'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_SetProgressText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > ptext_string;
  if (!get_val_smtptr_param<std::string >(ptext_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * ptext = ptext_string->c_str();

  this->_objectptr->GetObj()->SetProgressText(ptext);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char * vtkAlgorithm::GetProgressText()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetProgressText::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetProgressText::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char * res =   this->_objectptr->GetObj()->GetProgressText();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkAlgorithm::GetErrorCode()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetErrorCode::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetErrorCode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetErrorCode();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::SetInputArrayToProcess(int idx, int port, int connection, int fieldAssociation, char const * name)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_SetInputArrayToProcess_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'idx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'port'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'connection'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'fieldAssociation'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_SetInputArrayToProcess_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  int idx;
  if (!get_val_param<int >(idx,_p,_n,true,true)) ClassReturnEmptyVar;

  int port;
  if (!get_val_param<int >(port,_p,_n,true,true)) ClassReturnEmptyVar;

  int connection;
  if (!get_val_param<int >(connection,_p,_n,true,true)) ClassReturnEmptyVar;

  int fieldAssociation;
  if (!get_val_param<int >(fieldAssociation,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  this->_objectptr->GetObj()->SetInputArrayToProcess(idx, port, connection, fieldAssociation, name);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAlgorithm::SetInputArrayToProcess(...)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_SetInputArrayToProcess::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_SetInputArrayToProcess::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkAlgorithm::wrap_SetInputArrayToProcess_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkAlgorithm::wrap_SetInputArrayToProcess_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkAlgorithm::wrap_SetInputArrayToProcess_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::SetInputArrayToProcess(int idx, int port, int connection, int fieldAssociation, int fieldAttributeType)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_SetInputArrayToProcess_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'idx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'port'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'connection'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'fieldAssociation'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'fieldAttributeType'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_SetInputArrayToProcess_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  int idx;
  if (!get_val_param<int >(idx,_p,_n,true,true)) ClassReturnEmptyVar;

  int port;
  if (!get_val_param<int >(port,_p,_n,true,true)) ClassReturnEmptyVar;

  int connection;
  if (!get_val_param<int >(connection,_p,_n,true,true)) ClassReturnEmptyVar;

  int fieldAssociation;
  if (!get_val_param<int >(fieldAssociation,_p,_n,true,true)) ClassReturnEmptyVar;

  int fieldAttributeType;
  if (!get_val_param<int >(fieldAttributeType,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetInputArrayToProcess(idx, port, connection, fieldAssociation, fieldAttributeType);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::SetInputArrayToProcess(int idx, vtkInformation * info)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_SetInputArrayToProcess_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'idx'")
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'info'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_SetInputArrayToProcess_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int idx;
  if (!get_val_param<int >(idx,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkInformation* info;
  if (CheckNullVar(_p,_n))  {
    info=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > info_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(info_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    info = info_smtptr.get();
  }

  this->_objectptr->GetObj()->SetInputArrayToProcess(idx, info);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::SetInputArrayToProcess(int idx, int port, int connection, char const * fieldAssociation, char const * attributeTypeorName)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_SetInputArrayToProcess_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'idx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'port'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'connection'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'fieldAssociation'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'attributeTypeorName'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_SetInputArrayToProcess_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  int idx;
  if (!get_val_param<int >(idx,_p,_n,true,true)) ClassReturnEmptyVar;

  int port;
  if (!get_val_param<int >(port,_p,_n,true,true)) ClassReturnEmptyVar;

  int connection;
  if (!get_val_param<int >(connection,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<std::string > fieldAssociation_string;
  if (!get_val_smtptr_param<std::string >(fieldAssociation_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * fieldAssociation = fieldAssociation_string->c_str();

  boost::shared_ptr<std::string > attributeTypeorName_string;
  if (!get_val_smtptr_param<std::string >(attributeTypeorName_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * attributeTypeorName = attributeTypeorName_string->c_str();

  this->_objectptr->GetObj()->SetInputArrayToProcess(idx, port, connection, fieldAssociation, attributeTypeorName);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of vtkInformation * vtkAlgorithm::GetInputArrayInformation(int idx)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetInputArrayInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'idx'")
  return_comments="returning a variable of type vtkInformation";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetInputArrayInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int idx;
  if (!get_val_param<int >(idx,_p,_n,true,false)) ClassHelpAndReturn;

  vtkInformation * res =   this->_objectptr->GetObj()->GetInputArrayInformation(idx);
  return AMILabType<vtkInformation >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::RemoveAllInputs()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_RemoveAllInputs::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_RemoveAllInputs::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RemoveAllInputs();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkDataObject * vtkAlgorithm::GetOutputDataObject(int port)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetOutputDataObject::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'port'")
  return_comments="returning a variable of type vtkDataObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetOutputDataObject::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int port;
  if (!get_val_param<int >(port,_p,_n,true,false)) ClassHelpAndReturn;

  vtkDataObject * res =   this->_objectptr->GetObj()->GetOutputDataObject(port);
  BasicVariable::ptr res_var = AMILabType<vtkDataObject >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkDataObject * vtkAlgorithm::GetInputDataObject(int port, int connection)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetInputDataObject::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'port'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'connection'")
  return_comments="returning a variable of type vtkDataObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetInputDataObject::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int port;
  if (!get_val_param<int >(port,_p,_n,true,false)) ClassHelpAndReturn;

  int connection;
  if (!get_val_param<int >(connection,_p,_n,true,false)) ClassHelpAndReturn;

  vtkDataObject * res =   this->_objectptr->GetObj()->GetInputDataObject(port, connection);
  BasicVariable::ptr res_var = AMILabType<vtkDataObject >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: vtkAlgorithmOutput

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::SetInputConnection(int port, vtkAlgorithmOutput * input)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_SetInputConnection_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'port'")
  ADDPARAMCOMMENT_TYPE( vtkAlgorithmOutput, "parameter named 'input'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_SetInputConnection_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int port;
  if (!get_val_param<int >(port,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkAlgorithmOutput* input;
  if (CheckNullVar(_p,_n))  {
    input=(vtkAlgorithmOutput*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkAlgorithmOutput > input_smtptr;
    if (!get_val_smtptr_param<vtkAlgorithmOutput >(input_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    input = input_smtptr.get();
  }

  this->_objectptr->GetObj()->SetInputConnection(port, input);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAlgorithm::SetInputConnection(...)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_SetInputConnection::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_SetInputConnection::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkAlgorithmOutput

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::SetInputConnection(vtkAlgorithmOutput * input)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_SetInputConnection_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAlgorithmOutput, "parameter named 'input'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_SetInputConnection_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkAlgorithmOutput* input;
  if (CheckNullVar(_p,_n))  {
    input=(vtkAlgorithmOutput*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkAlgorithmOutput > input_smtptr;
    if (!get_val_smtptr_param<vtkAlgorithmOutput >(input_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    input = input_smtptr.get();
  }

  this->_objectptr->GetObj()->SetInputConnection(input);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkAlgorithmOutput

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::AddInputConnection(int port, vtkAlgorithmOutput * input)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_AddInputConnection_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'port'")
  ADDPARAMCOMMENT_TYPE( vtkAlgorithmOutput, "parameter named 'input'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_AddInputConnection_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int port;
  if (!get_val_param<int >(port,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkAlgorithmOutput* input;
  if (CheckNullVar(_p,_n))  {
    input=(vtkAlgorithmOutput*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkAlgorithmOutput > input_smtptr;
    if (!get_val_smtptr_param<vtkAlgorithmOutput >(input_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    input = input_smtptr.get();
  }

  this->_objectptr->GetObj()->AddInputConnection(port, input);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAlgorithm::AddInputConnection(...)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_AddInputConnection::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_AddInputConnection::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkAlgorithmOutput

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::AddInputConnection(vtkAlgorithmOutput * input)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_AddInputConnection_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAlgorithmOutput, "parameter named 'input'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_AddInputConnection_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkAlgorithmOutput* input;
  if (CheckNullVar(_p,_n))  {
    input=(vtkAlgorithmOutput*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkAlgorithmOutput > input_smtptr;
    if (!get_val_smtptr_param<vtkAlgorithmOutput >(input_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    input = input_smtptr.get();
  }

  this->_objectptr->GetObj()->AddInputConnection(input);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkAlgorithmOutput

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::RemoveInputConnection(int port, vtkAlgorithmOutput * input)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_RemoveInputConnection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'port'")
  ADDPARAMCOMMENT_TYPE( vtkAlgorithmOutput, "parameter named 'input'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_RemoveInputConnection::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int port;
  if (!get_val_param<int >(port,_p,_n,true,false)) ClassHelpAndReturn;

  vtkAlgorithmOutput* input;
  if (CheckNullVar(_p,_n))  {
    input=(vtkAlgorithmOutput*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkAlgorithmOutput > input_smtptr;
    if (!get_val_smtptr_param<vtkAlgorithmOutput >(input_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    input = input_smtptr.get();
  }

  this->_objectptr->GetObj()->RemoveInputConnection(port, input);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkAlgorithmOutput

//---------------------------------------------------
//  Wrapping of vtkAlgorithmOutput * vtkAlgorithm::GetOutputPort(int index)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetOutputPort_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type vtkAlgorithmOutput";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetOutputPort_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkAlgorithmOutput * res =   this->_objectptr->GetObj()->GetOutputPort(index);
  return AMILabType<vtkAlgorithmOutput >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAlgorithm::GetOutputPort(...)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetOutputPort::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetOutputPort::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkAlgorithmOutput

//---------------------------------------------------
//  Wrapping of vtkAlgorithmOutput * vtkAlgorithm::GetOutputPort()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetOutputPort_2::SetParametersComments()
{
  return_comments="returning a variable of type vtkAlgorithmOutput";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetOutputPort_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkAlgorithmOutput * res =   this->_objectptr->GetObj()->GetOutputPort();
  return AMILabType<vtkAlgorithmOutput >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of int vtkAlgorithm::GetNumberOfInputConnections(int port)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetNumberOfInputConnections::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'port'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetNumberOfInputConnections::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int port;
  if (!get_val_param<int >(port,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfInputConnections(port);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkAlgorithm::GetTotalNumberOfInputConnections()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetTotalNumberOfInputConnections::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetTotalNumberOfInputConnections::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetTotalNumberOfInputConnections();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: vtkAlgorithmOutput

//---------------------------------------------------
//  Wrapping of vtkAlgorithmOutput * vtkAlgorithm::GetInputConnection(int port, int index)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetInputConnection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'port'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type vtkAlgorithmOutput";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetInputConnection::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int port;
  if (!get_val_param<int >(port,_p,_n,true,false)) ClassHelpAndReturn;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,false)) ClassHelpAndReturn;

  vtkAlgorithmOutput * res =   this->_objectptr->GetObj()->GetInputConnection(port, index);
  return AMILabType<vtkAlgorithmOutput >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::Update()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_Update::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_Update::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Update();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::UpdateInformation()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_UpdateInformation::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_UpdateInformation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UpdateInformation();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::UpdateWholeExtent()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_UpdateWholeExtent::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_UpdateWholeExtent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UpdateWholeExtent();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::ConvertTotalInputToPortConnection(int ind, int & port, int & conn)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_ConvertTotalInputToPortConnection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ind'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'port'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'conn'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_ConvertTotalInputToPortConnection::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int ind;
  if (!get_val_param<int >(ind,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<int > port_smtptr;
  if (!get_val_smtptr_param<int >(port_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int & port = *port_smtptr;

  boost::shared_ptr<int > conn_smtptr;
  if (!get_val_smtptr_param<int >(conn_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int & conn = *conn_smtptr;

  this->_objectptr->GetObj()->ConvertTotalInputToPortConnection(ind, port, conn);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::SetReleaseDataFlag(int param0)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_SetReleaseDataFlag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_SetReleaseDataFlag::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetReleaseDataFlag(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkAlgorithm::GetReleaseDataFlag()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_GetReleaseDataFlag::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_GetReleaseDataFlag::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetReleaseDataFlag();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::ReleaseDataFlagOn()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_ReleaseDataFlagOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_ReleaseDataFlagOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ReleaseDataFlagOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAlgorithm::ReleaseDataFlagOff()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_ReleaseDataFlagOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_ReleaseDataFlagOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ReleaseDataFlagOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkAlgorithm::UpdateExtentIsEmpty(vtkDataObject * output)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_UpdateExtentIsEmpty_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'output'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_UpdateExtentIsEmpty_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkDataObject* output;
  if (CheckNullVar(_p,_n))  {
    output=(vtkDataObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataObject > output_smtptr;
    if (!get_val_smtptr_param<vtkDataObject >(output_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    output = output_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->UpdateExtentIsEmpty(output);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAlgorithm::UpdateExtentIsEmpty(...)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_UpdateExtentIsEmpty::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_UpdateExtentIsEmpty::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkAlgorithm::wrap_UpdateExtentIsEmpty_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of int vtkAlgorithm::UpdateExtentIsEmpty(vtkInformation * pinfo, int extentType)
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_UpdateExtentIsEmpty_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'pinfo'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'extentType'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_UpdateExtentIsEmpty_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformation* pinfo;
  if (CheckNullVar(_p,_n))  {
    pinfo=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > pinfo_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(pinfo_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    pinfo = pinfo_smtptr.get();
  }

  int extentType;
  if (!get_val_param<int >(extentType,_p,_n,true,true)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->UpdateExtentIsEmpty(pinfo, extentType);
  return AMILabType<int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of double vtkAlgorithm::ComputePriority()
//---------------------------------------------------
void WrapClass_vtkAlgorithm::
    wrap_ComputePriority::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithm::
    wrap_ComputePriority::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->ComputePriority();
  return AMILabType<double >::CreateVar(res);
}

