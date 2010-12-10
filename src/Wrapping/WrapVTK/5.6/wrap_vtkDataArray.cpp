/**
 * C++ Interface: wrap_vtkDataArray
 *
 * Description: wrapping vtkDataArray
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
#include "wrap_vtkDataArray.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkAbstractArray.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_vtkDataArray.h"

// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkDataArray>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkDataArray);
AMI_DEFINE_VARFROMSMTPTR(vtkDataArray);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkDataArray>::CreateVar( vtkDataArray* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkDataArray> obj_ptr(val,smartpointer_nodeleter<vtkDataArray>());
  return AMILabType<vtkDataArray>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkDataArray
//
Variable<AMIObject>::ptr WrapClass_vtkDataArray::CreateVar( vtkDataArray* sp)
{
  boost::shared_ptr<vtkDataArray> di_ptr(
    sp,
    wxwindow_nodeleter<vtkDataArray>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkDataArray>::CreateVar(
      new WrapClass_vtkDataArray(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkDataArray::AddMethods(WrapClass<vtkDataArray>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_IsNumeric( this_ptr);
  AddVar_GetElementComponentSize( this_ptr);
/* The following types are missing: vtkIdList
  AddVar_GetTuples_1( this_ptr);
*/
  AddVar_GetTuples( this_ptr);
  AddVar_GetTuples_2( this_ptr);
/* The following types are missing: vtkIdList
  AddVar_InterpolateTuple_1( this_ptr);
*/
  AddVar_InterpolateTuple( this_ptr);
  AddVar_InterpolateTuple_2( this_ptr);
  AddVar_GetTuple1( this_ptr);
  AddVar_GetTuple2( this_ptr);
  AddVar_GetTuple3( this_ptr);
  AddVar_GetTuple4( this_ptr);
  AddVar_GetTuple9( this_ptr);
  AddVar_SetTuple1( this_ptr);
  AddVar_SetTuple2( this_ptr);
  AddVar_SetTuple3( this_ptr);
  AddVar_SetTuple4( this_ptr);
  AddVar_SetTuple9( this_ptr);
  AddVar_InsertTuple1( this_ptr);
  AddVar_InsertTuple2( this_ptr);
  AddVar_InsertTuple3( this_ptr);
  AddVar_InsertTuple4( this_ptr);
  AddVar_InsertTuple9( this_ptr);
  AddVar_InsertNextTuple1( this_ptr);
  AddVar_InsertNextTuple2( this_ptr);
  AddVar_InsertNextTuple3( this_ptr);
  AddVar_InsertNextTuple4( this_ptr);
  AddVar_InsertNextTuple9( this_ptr);
  AddVar_GetComponent( this_ptr);
  AddVar_SetComponent( this_ptr);
  AddVar_InsertComponent( this_ptr);
/* The following types are missing: vtkDoubleArray
  AddVar_GetData( this_ptr);
*/
  AddVar_DeepCopy_1( this_ptr);
  AddVar_DeepCopy( this_ptr);
  AddVar_DeepCopy_2( this_ptr);
  AddVar_FillComponent( this_ptr);
  AddVar_CopyComponent( this_ptr);
  AddVar_GetActualMemorySize( this_ptr);
  AddVar_CreateDefaultLookupTable( this_ptr);
/* The following types are missing: vtkLookupTable
  AddVar_SetLookupTable( this_ptr);
*/
/* The following types are missing: vtkLookupTable
  AddVar_GetLookupTable( this_ptr);
*/
  AddVar_GetRange_1( this_ptr);
  AddVar_GetRange( this_ptr);
  AddVar_GetRange_2( this_ptr);
  AddVar_GetRange_3( this_ptr);
  AddVar_GetRange_4( this_ptr);
  AddVar_GetDataTypeRange( this_ptr);
  AddVar_GetDataTypeMin( this_ptr);
  AddVar_GetDataTypeMax( this_ptr);
  AddVar_GetMaxNorm( this_ptr);
/* The following types are missing: vtkInformation
  AddVar_CopyInformation( this_ptr);
*/



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent vtkAbstractArray
  boost::shared_ptr<vtkAbstractArray > parent_vtkAbstractArray(  boost::dynamic_pointer_cast<vtkAbstractArray >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkAbstractArray = AMILabType<vtkAbstractArray >::CreateVarFromSmtPtr(parent_vtkAbstractArray);
  context->AddVar("vtkAbstractArray",var_vtkAbstractArray);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkAbstractArray = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkAbstractArray);
  context->AddDefault(obj_vtkAbstractArray->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkDataArray::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkDataArray");
  
  // Static methods 
  WrapClass_vtkDataArray::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkDataArray::AddVar_SafeDownCast(amiobject->GetContext());
  WrapClass_vtkDataArray::AddVar_GetDataTypeRange(amiobject->GetContext());
  WrapClass_vtkDataArray::AddVar_GetDataTypeMin(amiobject->GetContext());
  WrapClass_vtkDataArray::AddVar_GetDataTypeMax(amiobject->GetContext());
  WrapClass_vtkDataArray::AddVar_CreateDataArray(amiobject->GetContext());
  /* Types are missing
  WrapClass_vtkDataArray::AddVar_PER_COMPONENT(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkDataArray::AddVar_COMPONENT_RANGE(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_vtkDataArray::AddVar_L2_NORM_RANGE(amiobject->GetContext());
  */

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkDataArray::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkDataArray::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkDataArray * vtkDataArray::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkDataArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
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

  vtkDataArray * res =   vtkDataArray::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkDataArray::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::GetDataTypeRange(int type, double * range)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_static_GetDataTypeRange::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'range'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_static_GetDataTypeRange::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int type;
  if (!get_val_param<int >(type,_p,_n,true,false)) ClassHelpAndReturn;

  double* range;
  if (CheckNullVar(_p,_n))  {
    range=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > range_smtptr;
    if (!get_val_smtptr_param<double >(range_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    range = range_smtptr.get();
  }

  vtkDataArray::GetDataTypeRange(type, range);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkDataArray::GetDataTypeMin(int type)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_static_GetDataTypeMin::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_static_GetDataTypeMin::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int type;
  if (!get_val_param<int >(type,_p,_n,true,false)) ClassHelpAndReturn;

  double res =   vtkDataArray::GetDataTypeMin(type);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkDataArray::GetDataTypeMax(int type)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_static_GetDataTypeMax::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_static_GetDataTypeMax::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int type;
  if (!get_val_param<int >(type,_p,_n,true,false)) ClassHelpAndReturn;

  double res =   vtkDataArray::GetDataTypeMax(type);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkDataArray * vtkDataArray::CreateDataArray(int dataType)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_static_CreateDataArray::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dataType'")
  return_comments="returning a variable of type vtkDataArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_static_CreateDataArray::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int dataType;
  if (!get_val_param<int >(dataType,_p,_n,true,false)) ClassHelpAndReturn;

  vtkDataArray * res =   vtkDataArray::CreateDataArray(dataType);
  BasicVariable::ptr res_var = WrapClass_vtkDataArray::CreateVar(res);
  return res_var;
}
/* The following types are missing: vtkInformationInformationVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationInformationVectorKey * vtkDataArray::PER_COMPONENT()
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_static_PER_COMPONENT::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationInformationVectorKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_static_PER_COMPONENT::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationInformationVectorKey * res =   vtkDataArray::PER_COMPONENT();
  return AMILabType<vtkInformationInformationVectorKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationDoubleVectorKey * vtkDataArray::COMPONENT_RANGE()
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_static_COMPONENT_RANGE::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationDoubleVectorKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_static_COMPONENT_RANGE::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationDoubleVectorKey * res =   vtkDataArray::COMPONENT_RANGE();
  return AMILabType<vtkInformationDoubleVectorKey >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformationDoubleVectorKey

//---------------------------------------------------
//  Wrapping of vtkInformationDoubleVectorKey * vtkDataArray::L2_NORM_RANGE()
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_static_L2_NORM_RANGE::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformationDoubleVectorKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_static_L2_NORM_RANGE::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformationDoubleVectorKey * res =   vtkDataArray::L2_NORM_RANGE();
  return AMILabType<vtkInformationDoubleVectorKey >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of int vtkDataArray::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
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
//  Wrapping of vtkDataArray * vtkDataArray::NewInstance()
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkDataArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkDataArray * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkDataArray::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkDataArray::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
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
//  Wrapping of int vtkDataArray::IsNumeric()
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_IsNumeric::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_IsNumeric::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->IsNumeric();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkDataArray::GetElementComponentSize()
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetElementComponentSize::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetElementComponentSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetElementComponentSize();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: vtkIdList

//---------------------------------------------------
//  Wrapping of void vtkDataArray::GetTuples(vtkIdList * ptIds, vtkAbstractArray * output)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetTuples_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkIdList, "parameter named 'ptIds'")
  ADDPARAMCOMMENT_TYPE( vtkAbstractArray, "parameter named 'output'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetTuples_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkIdList* ptIds;
  if (CheckNullVar(_p,_n))  {
    ptIds=(vtkIdList*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkIdList > ptIds_smtptr;
    if (!get_val_smtptr_param<vtkIdList >(ptIds_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    ptIds = ptIds_smtptr.get();
  }

  vtkAbstractArray* output;
  if (CheckNullVar(_p,_n))  {
    output=(vtkAbstractArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkAbstractArray > output_smtptr;
    if (!get_val_smtptr_param<vtkAbstractArray >(output_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    output = output_smtptr.get();
  }

  this->_objectptr->GetObj()->GetTuples(ptIds, output);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkDataArray::GetTuples(...)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetTuples::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetTuples::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkDataArray::wrap_GetTuples_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::GetTuples(vtkIdType p1, vtkIdType p2, vtkAbstractArray * output)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetTuples_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'p1'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'p2'")
  ADDPARAMCOMMENT_TYPE( vtkAbstractArray, "parameter named 'output'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetTuples_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  long p1_long;
  if (!get_val_param<long >(p1_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int p1 = boost::numeric_cast<long long int >(p1_long);

  long p2_long;
  if (!get_val_param<long >(p2_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int p2 = boost::numeric_cast<long long int >(p2_long);

  vtkAbstractArray* output;
  if (CheckNullVar(_p,_n))  {
    output=(vtkAbstractArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkAbstractArray > output_smtptr;
    if (!get_val_smtptr_param<vtkAbstractArray >(output_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    output = output_smtptr.get();
  }

  this->_objectptr->GetObj()->GetTuples(p1, p2, output);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkIdList

//---------------------------------------------------
//  Wrapping of void vtkDataArray::InterpolateTuple(vtkIdType i, vtkIdList * ptIndices, vtkAbstractArray * source, double * weights)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_InterpolateTuple_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( vtkIdList, "parameter named 'ptIndices'")
  ADDPARAMCOMMENT_TYPE( vtkAbstractArray, "parameter named 'source'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'weights'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_InterpolateTuple_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int i = boost::numeric_cast<long long int >(i_long);

  vtkIdList* ptIndices;
  if (CheckNullVar(_p,_n))  {
    ptIndices=(vtkIdList*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkIdList > ptIndices_smtptr;
    if (!get_val_smtptr_param<vtkIdList >(ptIndices_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    ptIndices = ptIndices_smtptr.get();
  }

  vtkAbstractArray* source;
  if (CheckNullVar(_p,_n))  {
    source=(vtkAbstractArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkAbstractArray > source_smtptr;
    if (!get_val_smtptr_param<vtkAbstractArray >(source_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    source = source_smtptr.get();
  }

  double* weights;
  if (CheckNullVar(_p,_n))  {
    weights=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > weights_smtptr;
    if (!get_val_smtptr_param<double >(weights_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    weights = weights_smtptr.get();
  }

  this->_objectptr->GetObj()->InterpolateTuple(i, ptIndices, source, weights);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkDataArray::InterpolateTuple(...)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_InterpolateTuple::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_InterpolateTuple::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkDataArray::wrap_InterpolateTuple_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::InterpolateTuple(vtkIdType i, vtkIdType id1, vtkAbstractArray * source1, vtkIdType id2, vtkAbstractArray * source2, double t)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_InterpolateTuple_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id1'")
  ADDPARAMCOMMENT_TYPE( vtkAbstractArray, "parameter named 'source1'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id2'")
  ADDPARAMCOMMENT_TYPE( vtkAbstractArray, "parameter named 'source2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 't'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_InterpolateTuple_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int i = boost::numeric_cast<long long int >(i_long);

  long id1_long;
  if (!get_val_param<long >(id1_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int id1 = boost::numeric_cast<long long int >(id1_long);

  vtkAbstractArray* source1;
  if (CheckNullVar(_p,_n))  {
    source1=(vtkAbstractArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkAbstractArray > source1_smtptr;
    if (!get_val_smtptr_param<vtkAbstractArray >(source1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    source1 = source1_smtptr.get();
  }

  long id2_long;
  if (!get_val_param<long >(id2_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int id2 = boost::numeric_cast<long long int >(id2_long);

  vtkAbstractArray* source2;
  if (CheckNullVar(_p,_n))  {
    source2=(vtkAbstractArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkAbstractArray > source2_smtptr;
    if (!get_val_smtptr_param<vtkAbstractArray >(source2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    source2 = source2_smtptr.get();
  }

  double t;
  if (!get_val_param<double >(t,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->InterpolateTuple(i, id1, source1, id2, source2, t);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkDataArray::GetTuple1(vtkIdType i)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetTuple1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetTuple1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  double res =   this->_objectptr->GetObj()->GetTuple1(i);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double * vtkDataArray::GetTuple2(vtkIdType i)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetTuple2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetTuple2::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  double * res =   this->_objectptr->GetObj()->GetTuple2(i);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkDataArray::GetTuple3(vtkIdType i)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetTuple3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetTuple3::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  double * res =   this->_objectptr->GetObj()->GetTuple3(i);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkDataArray::GetTuple4(vtkIdType i)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetTuple4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetTuple4::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  double * res =   this->_objectptr->GetObj()->GetTuple4(i);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkDataArray::GetTuple9(vtkIdType i)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetTuple9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetTuple9::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  double * res =   this->_objectptr->GetObj()->GetTuple9(i);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::SetTuple1(vtkIdType i, double value)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_SetTuple1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_SetTuple1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  double value;
  if (!get_val_param<double >(value,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetTuple1(i, value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::SetTuple2(vtkIdType i, double val0, double val1)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_SetTuple2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_SetTuple2::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  double val0;
  if (!get_val_param<double >(val0,_p,_n,true,false)) ClassHelpAndReturn;

  double val1;
  if (!get_val_param<double >(val1,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetTuple2(i, val0, val1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::SetTuple3(vtkIdType i, double val0, double val1, double val2)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_SetTuple3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_SetTuple3::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  double val0;
  if (!get_val_param<double >(val0,_p,_n,true,false)) ClassHelpAndReturn;

  double val1;
  if (!get_val_param<double >(val1,_p,_n,true,false)) ClassHelpAndReturn;

  double val2;
  if (!get_val_param<double >(val2,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetTuple3(i, val0, val1, val2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::SetTuple4(vtkIdType i, double val0, double val1, double val2, double val3)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_SetTuple4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_SetTuple4::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  double val0;
  if (!get_val_param<double >(val0,_p,_n,true,false)) ClassHelpAndReturn;

  double val1;
  if (!get_val_param<double >(val1,_p,_n,true,false)) ClassHelpAndReturn;

  double val2;
  if (!get_val_param<double >(val2,_p,_n,true,false)) ClassHelpAndReturn;

  double val3;
  if (!get_val_param<double >(val3,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetTuple4(i, val0, val1, val2, val3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::SetTuple9(vtkIdType i, double val0, double val1, double val2, double val3, double val4, double val5, double val6, double val7, double val8)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_SetTuple9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val3'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val4'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val5'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val6'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val7'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val8'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_SetTuple9::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>10) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  double val0;
  if (!get_val_param<double >(val0,_p,_n,true,false)) ClassHelpAndReturn;

  double val1;
  if (!get_val_param<double >(val1,_p,_n,true,false)) ClassHelpAndReturn;

  double val2;
  if (!get_val_param<double >(val2,_p,_n,true,false)) ClassHelpAndReturn;

  double val3;
  if (!get_val_param<double >(val3,_p,_n,true,false)) ClassHelpAndReturn;

  double val4;
  if (!get_val_param<double >(val4,_p,_n,true,false)) ClassHelpAndReturn;

  double val5;
  if (!get_val_param<double >(val5,_p,_n,true,false)) ClassHelpAndReturn;

  double val6;
  if (!get_val_param<double >(val6,_p,_n,true,false)) ClassHelpAndReturn;

  double val7;
  if (!get_val_param<double >(val7,_p,_n,true,false)) ClassHelpAndReturn;

  double val8;
  if (!get_val_param<double >(val8,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetTuple9(i, val0, val1, val2, val3, val4, val5, val6, val7, val8);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::InsertTuple1(vtkIdType i, double value)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_InsertTuple1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_InsertTuple1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  double value;
  if (!get_val_param<double >(value,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InsertTuple1(i, value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::InsertTuple2(vtkIdType i, double val0, double val1)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_InsertTuple2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_InsertTuple2::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  double val0;
  if (!get_val_param<double >(val0,_p,_n,true,false)) ClassHelpAndReturn;

  double val1;
  if (!get_val_param<double >(val1,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InsertTuple2(i, val0, val1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::InsertTuple3(vtkIdType i, double val0, double val1, double val2)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_InsertTuple3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_InsertTuple3::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  double val0;
  if (!get_val_param<double >(val0,_p,_n,true,false)) ClassHelpAndReturn;

  double val1;
  if (!get_val_param<double >(val1,_p,_n,true,false)) ClassHelpAndReturn;

  double val2;
  if (!get_val_param<double >(val2,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InsertTuple3(i, val0, val1, val2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::InsertTuple4(vtkIdType i, double val0, double val1, double val2, double val3)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_InsertTuple4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_InsertTuple4::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  double val0;
  if (!get_val_param<double >(val0,_p,_n,true,false)) ClassHelpAndReturn;

  double val1;
  if (!get_val_param<double >(val1,_p,_n,true,false)) ClassHelpAndReturn;

  double val2;
  if (!get_val_param<double >(val2,_p,_n,true,false)) ClassHelpAndReturn;

  double val3;
  if (!get_val_param<double >(val3,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InsertTuple4(i, val0, val1, val2, val3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::InsertTuple9(vtkIdType i, double val0, double val1, double val2, double val3, double val4, double val5, double val6, double val7, double val8)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_InsertTuple9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val3'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val4'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val5'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val6'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val7'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val8'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_InsertTuple9::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>10) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  double val0;
  if (!get_val_param<double >(val0,_p,_n,true,false)) ClassHelpAndReturn;

  double val1;
  if (!get_val_param<double >(val1,_p,_n,true,false)) ClassHelpAndReturn;

  double val2;
  if (!get_val_param<double >(val2,_p,_n,true,false)) ClassHelpAndReturn;

  double val3;
  if (!get_val_param<double >(val3,_p,_n,true,false)) ClassHelpAndReturn;

  double val4;
  if (!get_val_param<double >(val4,_p,_n,true,false)) ClassHelpAndReturn;

  double val5;
  if (!get_val_param<double >(val5,_p,_n,true,false)) ClassHelpAndReturn;

  double val6;
  if (!get_val_param<double >(val6,_p,_n,true,false)) ClassHelpAndReturn;

  double val7;
  if (!get_val_param<double >(val7,_p,_n,true,false)) ClassHelpAndReturn;

  double val8;
  if (!get_val_param<double >(val8,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InsertTuple9(i, val0, val1, val2, val3, val4, val5, val6, val7, val8);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::InsertNextTuple1(double value)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_InsertNextTuple1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_InsertNextTuple1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double value;
  if (!get_val_param<double >(value,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InsertNextTuple1(value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::InsertNextTuple2(double val0, double val1)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_InsertNextTuple2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_InsertNextTuple2::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  double val0;
  if (!get_val_param<double >(val0,_p,_n,true,false)) ClassHelpAndReturn;

  double val1;
  if (!get_val_param<double >(val1,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InsertNextTuple2(val0, val1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::InsertNextTuple3(double val0, double val1, double val2)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_InsertNextTuple3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_InsertNextTuple3::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  double val0;
  if (!get_val_param<double >(val0,_p,_n,true,false)) ClassHelpAndReturn;

  double val1;
  if (!get_val_param<double >(val1,_p,_n,true,false)) ClassHelpAndReturn;

  double val2;
  if (!get_val_param<double >(val2,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InsertNextTuple3(val0, val1, val2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::InsertNextTuple4(double val0, double val1, double val2, double val3)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_InsertNextTuple4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_InsertNextTuple4::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  double val0;
  if (!get_val_param<double >(val0,_p,_n,true,false)) ClassHelpAndReturn;

  double val1;
  if (!get_val_param<double >(val1,_p,_n,true,false)) ClassHelpAndReturn;

  double val2;
  if (!get_val_param<double >(val2,_p,_n,true,false)) ClassHelpAndReturn;

  double val3;
  if (!get_val_param<double >(val3,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InsertNextTuple4(val0, val1, val2, val3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::InsertNextTuple9(double val0, double val1, double val2, double val3, double val4, double val5, double val6, double val7, double val8)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_InsertNextTuple9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val3'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val4'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val5'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val6'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val7'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val8'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_InsertNextTuple9::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>9) ClassHelpAndReturn;
  int _n=0;

  double val0;
  if (!get_val_param<double >(val0,_p,_n,true,false)) ClassHelpAndReturn;

  double val1;
  if (!get_val_param<double >(val1,_p,_n,true,false)) ClassHelpAndReturn;

  double val2;
  if (!get_val_param<double >(val2,_p,_n,true,false)) ClassHelpAndReturn;

  double val3;
  if (!get_val_param<double >(val3,_p,_n,true,false)) ClassHelpAndReturn;

  double val4;
  if (!get_val_param<double >(val4,_p,_n,true,false)) ClassHelpAndReturn;

  double val5;
  if (!get_val_param<double >(val5,_p,_n,true,false)) ClassHelpAndReturn;

  double val6;
  if (!get_val_param<double >(val6,_p,_n,true,false)) ClassHelpAndReturn;

  double val7;
  if (!get_val_param<double >(val7,_p,_n,true,false)) ClassHelpAndReturn;

  double val8;
  if (!get_val_param<double >(val8,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InsertNextTuple9(val0, val1, val2, val3, val4, val5, val6, val7, val8);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkDataArray::GetComponent(vtkIdType i, int j)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetComponent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'j'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetComponent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  int j;
  if (!get_val_param<int >(j,_p,_n,true,false)) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetComponent(i, j);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::SetComponent(vtkIdType i, int j, double c)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_SetComponent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'j'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_SetComponent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  int j;
  if (!get_val_param<int >(j,_p,_n,true,false)) ClassHelpAndReturn;

  double c;
  if (!get_val_param<double >(c,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetComponent(i, j, c);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::InsertComponent(vtkIdType i, int j, double c)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_InsertComponent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'j'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_InsertComponent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  int j;
  if (!get_val_param<int >(j,_p,_n,true,false)) ClassHelpAndReturn;

  double c;
  if (!get_val_param<double >(c,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InsertComponent(i, j, c);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkDoubleArray

//---------------------------------------------------
//  Wrapping of void vtkDataArray::GetData(vtkIdType tupleMin, vtkIdType tupleMax, int compMin, int compMax, vtkDoubleArray * data)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'tupleMin'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'tupleMax'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'compMin'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'compMax'")
  ADDPARAMCOMMENT_TYPE( vtkDoubleArray, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  long tupleMin_long;
  if (!get_val_param<long >(tupleMin_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int tupleMin = boost::numeric_cast<long long int >(tupleMin_long);

  long tupleMax_long;
  if (!get_val_param<long >(tupleMax_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int tupleMax = boost::numeric_cast<long long int >(tupleMax_long);

  int compMin;
  if (!get_val_param<int >(compMin,_p,_n,true,false)) ClassHelpAndReturn;

  int compMax;
  if (!get_val_param<int >(compMax,_p,_n,true,false)) ClassHelpAndReturn;

  vtkDoubleArray* data;
  if (CheckNullVar(_p,_n))  {
    data=(vtkDoubleArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDoubleArray > data_smtptr;
    if (!get_val_smtptr_param<vtkDoubleArray >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    data = data_smtptr.get();
  }

  this->_objectptr->GetObj()->GetData(tupleMin, tupleMax, compMin, compMax, data);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkDataArray::DeepCopy(vtkAbstractArray * aa)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_DeepCopy_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAbstractArray, "parameter named 'aa'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_DeepCopy_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkAbstractArray* aa;
  if (CheckNullVar(_p,_n))  {
    aa=(vtkAbstractArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkAbstractArray > aa_smtptr;
    if (!get_val_smtptr_param<vtkAbstractArray >(aa_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    aa = aa_smtptr.get();
  }

  this->_objectptr->GetObj()->DeepCopy(aa);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkDataArray::DeepCopy(...)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_DeepCopy::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_DeepCopy::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkDataArray::wrap_DeepCopy_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkDataArray::wrap_DeepCopy_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::DeepCopy(vtkDataArray * da)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_DeepCopy_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'da'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_DeepCopy_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkDataArray* da;
  if (CheckNullVar(_p,_n))  {
    da=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > da_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(da_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    da = da_smtptr.get();
  }

  this->_objectptr->GetObj()->DeepCopy(da);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::FillComponent(int j, double c)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_FillComponent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'j'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_FillComponent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int j;
  if (!get_val_param<int >(j,_p,_n,true,false)) ClassHelpAndReturn;

  double c;
  if (!get_val_param<double >(c,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->FillComponent(j, c);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::CopyComponent(int j, vtkDataArray * from, int fromComponent)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_CopyComponent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'j'")
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'from'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'fromComponent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_CopyComponent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int j;
  if (!get_val_param<int >(j,_p,_n,true,false)) ClassHelpAndReturn;

  vtkDataArray* from;
  if (CheckNullVar(_p,_n))  {
    from=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > from_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(from_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    from = from_smtptr.get();
  }

  int fromComponent;
  if (!get_val_param<int >(fromComponent,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->CopyComponent(j, from, fromComponent);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkDataArray::GetActualMemorySize()
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetActualMemorySize::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetActualMemorySize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetActualMemorySize();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::CreateDefaultLookupTable()
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_CreateDefaultLookupTable::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_CreateDefaultLookupTable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->CreateDefaultLookupTable();
  return BasicVariable::ptr();
}
/* The following types are missing: vtkLookupTable

//---------------------------------------------------
//  Wrapping of void vtkDataArray::SetLookupTable(vtkLookupTable * lut)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_SetLookupTable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkLookupTable, "parameter named 'lut'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_SetLookupTable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkLookupTable* lut;
  if (CheckNullVar(_p,_n))  {
    lut=(vtkLookupTable*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkLookupTable > lut_smtptr;
    if (!get_val_smtptr_param<vtkLookupTable >(lut_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    lut = lut_smtptr.get();
  }

  this->_objectptr->GetObj()->SetLookupTable(lut);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkLookupTable

//---------------------------------------------------
//  Wrapping of vtkLookupTable * vtkDataArray::GetLookupTable()
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetLookupTable::SetParametersComments()
{
  return_comments="returning a variable of type vtkLookupTable";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetLookupTable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkLookupTable * res =   this->_objectptr->GetObj()->GetLookupTable();
  return AMILabType<vtkLookupTable >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkDataArray::GetRange(double * range, int comp)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetRange_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'range'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'comp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetRange_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double* range;
  if (CheckNullVar(_p,_n))  {
    range=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > range_smtptr;
    if (!get_val_smtptr_param<double >(range_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    range = range_smtptr.get();
  }

  int comp;
  if (!get_val_param<int >(comp,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->GetRange(range, comp);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkDataArray::GetRange(...)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetRange::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetRange::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkDataArray::wrap_GetRange_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkDataArray::wrap_GetRange_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkDataArray::wrap_GetRange_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_vtkDataArray::wrap_GetRange_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double * vtkDataArray::GetRange(int comp)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetRange_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'comp'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetRange_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int comp;
  if (!get_val_param<int >(comp,_p,_n,true,true)) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetRange(comp);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkDataArray::GetRange()
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetRange_3::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetRange_3::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetRange();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::GetRange(double * range)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetRange_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'range'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetRange_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* range;
  if (CheckNullVar(_p,_n))  {
    range=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > range_smtptr;
    if (!get_val_smtptr_param<double >(range_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    range = range_smtptr.get();
  }

  this->_objectptr->GetObj()->GetRange(range);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataArray::GetDataTypeRange(double * range)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetDataTypeRange::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'range'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetDataTypeRange::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double* range;
  if (CheckNullVar(_p,_n))  {
    range=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > range_smtptr;
    if (!get_val_smtptr_param<double >(range_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    range = range_smtptr.get();
  }

  this->_objectptr->GetObj()->GetDataTypeRange(range);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkDataArray::GetDataTypeMin()
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetDataTypeMin::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetDataTypeMin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetDataTypeMin();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkDataArray::GetDataTypeMax()
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetDataTypeMax::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetDataTypeMax::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetDataTypeMax();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkDataArray::GetMaxNorm()
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_GetMaxNorm::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_GetMaxNorm::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetMaxNorm();
  return AMILabType<double >::CreateVar(res);
}
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of int vtkDataArray::CopyInformation(vtkInformation * infoFrom, int deep = 1)
//---------------------------------------------------
void WrapClass_vtkDataArray::
    wrap_CopyInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'infoFrom'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deep' (def:1)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataArray::
    wrap_CopyInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkInformation* infoFrom;
  if (CheckNullVar(_p,_n))  {
    infoFrom=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > infoFrom_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(infoFrom_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    infoFrom = infoFrom_smtptr.get();
  }

  int deep = 1;
  if (!get_val_param<int >(deep,_p,_n,false,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->CopyInformation(infoFrom, deep);
  return AMILabType<int >::CreateVar(res);
}
*/

