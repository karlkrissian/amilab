/**
 * C++ Interface: wrap_vtkAbstractArray
 *
 * Description: wrapping vtkAbstractArray
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
#include "wrap_vtkAbstractArray.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_vtkVariant.h"


#include "wrap_vtkAbstractArray.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkAbstractArray>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkAbstractArray);
AMI_DEFINE_VARFROMSMTPTR(vtkAbstractArray);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkAbstractArray>::CreateVar( vtkAbstractArray* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkAbstractArray> obj_ptr(val,smartpointer_nodeleter<vtkAbstractArray>());
  return AMILabType<vtkAbstractArray>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkAbstractArray
//
Variable<AMIObject>::ptr WrapClass_vtkAbstractArray::CreateVar( vtkAbstractArray* sp)
{
  boost::shared_ptr<vtkAbstractArray> di_ptr(
    sp,
    wxwindow_nodeleter<vtkAbstractArray>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkAbstractArray>::CreateVar(
      new WrapClass_vtkAbstractArray(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkAbstractArray::AddMethods(WrapClass<vtkAbstractArray>::ptr this_ptr )
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
      AddVar_SetNumberOfComponents( this_ptr);
      AddVar_GetNumberOfComponentsMinValue( this_ptr);
      AddVar_GetNumberOfComponentsMaxValue( this_ptr);
      AddVar_GetNumberOfComponents( this_ptr);
      AddVar_GetNumberOfTuples( this_ptr);
/* The following types are missing: vtkIdList
      AddVar_GetTuples_1( this_ptr);
*/
      AddVar_GetTuples( this_ptr);
      AddVar_GetTuples_2( this_ptr);
      AddVar_DeepCopy( this_ptr);
      AddVar_Reset( this_ptr);
      AddVar_GetSize( this_ptr);
      AddVar_GetMaxId( this_ptr);
/* The following types are missing: void
      AddVar_ExportToVoidPointer( this_ptr);
*/
      AddVar_SetName( this_ptr);
      AddVar_GetName( this_ptr);
      AddVar_GetDataTypeAsString( this_ptr);
      AddVar_GetDataSize( this_ptr);
      AddVar_GetVariantValue( this_ptr);
/* The following types are missing: vtkInformation
      AddVar_GetInformation( this_ptr);
*/
      AddVar_HasInformation( this_ptr);
/* The following types are missing: vtkInformation
      AddVar_CopyInformation( this_ptr);
*/



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkAbstractArray::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkAbstractArray::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkAbstractArray * vtkAbstractArray::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkAbstractArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkAbstractArray * res =   vtkAbstractArray::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkAbstractArray::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkAbstractArray::GetDataTypeSize(int type)
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_static_GetDataTypeSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_static_GetDataTypeSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int type;
  if (!get_val_param<int >(type,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   vtkAbstractArray::GetDataTypeSize(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkAbstractArray * vtkAbstractArray::CreateArray(int dataType)
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_static_CreateArray::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dataType'")
  return_comments="returning a variable of type vtkAbstractArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_static_CreateArray::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int dataType;
  if (!get_val_param<int >(dataType,_p,_n,true,false)) ClassHelpAndReturn;

  vtkAbstractArray * res =   vtkAbstractArray::CreateArray(dataType);
  BasicVariable::ptr res_var = WrapClass_vtkAbstractArray::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkAbstractArray::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
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
//  Wrapping of vtkAbstractArray * vtkAbstractArray::NewInstance()
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkAbstractArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAbstractArray * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkAbstractArray::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkAbstractArray::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
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
//  Wrapping of void vtkAbstractArray::SetNumberOfComponents(int _arg)
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_SetNumberOfComponents::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_SetNumberOfComponents::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetNumberOfComponents(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkAbstractArray::GetNumberOfComponentsMinValue()
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_GetNumberOfComponentsMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_GetNumberOfComponentsMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfComponentsMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkAbstractArray::GetNumberOfComponentsMaxValue()
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_GetNumberOfComponentsMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_GetNumberOfComponentsMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfComponentsMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkAbstractArray::GetNumberOfComponents()
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_GetNumberOfComponents::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_GetNumberOfComponents::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfComponents();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkAbstractArray::GetNumberOfTuples()
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_GetNumberOfTuples::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_GetNumberOfTuples::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->GetNumberOfTuples();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}
/* The following types are missing: vtkIdList

//---------------------------------------------------
//  Wrapping of void vtkAbstractArray::GetTuples(vtkIdList * ptIds, vtkAbstractArray * output)
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_GetTuples_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkIdList, "parameter named 'ptIds'")
  ADDPARAMCOMMENT_TYPE( vtkAbstractArray, "parameter named 'output'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_GetTuples_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkIdList > ptIds_smtptr;
  if (!get_val_smtptr_param<vtkIdList >(ptIds_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkIdList* ptIds = ptIds_smtptr.get();

  boost::shared_ptr<vtkAbstractArray > output_smtptr;
  if (!get_val_smtptr_param<vtkAbstractArray >(output_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkAbstractArray* output = output_smtptr.get();

  this->_objectptr->GetObj()->GetTuples(ptIds, output);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAbstractArray::GetTuples(...)
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_GetTuples::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_GetTuples::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkAbstractArray::wrap_GetTuples_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractArray::GetTuples(vtkIdType p1, vtkIdType p2, vtkAbstractArray * output)
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_GetTuples_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'p1'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'p2'")
  ADDPARAMCOMMENT_TYPE( vtkAbstractArray, "parameter named 'output'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
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

  boost::shared_ptr<vtkAbstractArray > output_smtptr;
  if (!get_val_smtptr_param<vtkAbstractArray >(output_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkAbstractArray* output = output_smtptr.get();

  this->_objectptr->GetObj()->GetTuples(p1, p2, output);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractArray::DeepCopy(vtkAbstractArray * da)
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_DeepCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAbstractArray, "parameter named 'da'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_DeepCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkAbstractArray > da_smtptr;
  if (!get_val_smtptr_param<vtkAbstractArray >(da_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkAbstractArray* da = da_smtptr.get();

  this->_objectptr->GetObj()->DeepCopy(da);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractArray::Reset()
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_Reset::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_Reset::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Reset();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkAbstractArray::GetSize()
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_GetSize::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_GetSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->GetSize();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkAbstractArray::GetMaxId()
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_GetMaxId::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_GetMaxId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->GetMaxId();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of void vtkAbstractArray::ExportToVoidPointer(void * param0)
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_ExportToVoidPointer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_ExportToVoidPointer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<void > param0_smtptr;
  if (!get_val_smtptr_param<void >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  void* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->ExportToVoidPointer(param0);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkAbstractArray::SetName(char const * _arg)
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_SetName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_SetName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > _arg_string;
  if (!get_val_smtptr_param<std::string >(_arg_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * _arg = _arg_string->c_str();

  this->_objectptr->GetObj()->SetName(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char * vtkAbstractArray::GetName()
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_GetName::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_GetName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char * res =   this->_objectptr->GetObj()->GetName();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of char const * vtkAbstractArray::GetDataTypeAsString()
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_GetDataTypeAsString::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_GetDataTypeAsString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   this->_objectptr->GetObj()->GetDataTypeAsString();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkAbstractArray::GetDataSize()
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_GetDataSize::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_GetDataSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->GetDataSize();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of vtkVariant vtkAbstractArray::GetVariantValue(vtkIdType idx)
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_GetVariantValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'idx'")
  return_comments="returning a variable of type vtkVariant";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_GetVariantValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long idx_long;
  if (!get_val_param<long >(idx_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int idx = boost::numeric_cast<long long int >(idx_long);

  vtkVariant res =   this->_objectptr->GetObj()->GetVariantValue(idx);
  return AMILabType<vtkVariant >::CreateVar(res);
}
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of vtkInformation * vtkAbstractArray::GetInformation()
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_GetInformation::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformation";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_GetInformation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformation * res =   this->_objectptr->GetObj()->GetInformation();
  return AMILabType<vtkInformation >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of bool vtkAbstractArray::HasInformation()
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_HasInformation::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_HasInformation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasInformation();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of int vtkAbstractArray::CopyInformation(vtkInformation * infoFrom, int deep = 1)
//---------------------------------------------------
void WrapClass_vtkAbstractArray::
    wrap_CopyInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'infoFrom'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deep' (def:1)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractArray::
    wrap_CopyInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkInformation > infoFrom_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(infoFrom_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkInformation* infoFrom = infoFrom_smtptr.get();

  int deep = 1;
  if (!get_val_param<int >(deep,_p,_n,false,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->CopyInformation(infoFrom, deep);
  return AMILabType<int >::CreateVar(res);
}
*/

