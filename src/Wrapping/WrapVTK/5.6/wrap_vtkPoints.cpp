/**
 * C++ Interface: wrap_vtkPoints
 *
 * Description: wrapping vtkPoints
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
#include "wrap_vtkPoints.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_vtkDataArray.h"


#include "wrap_vtkPoints.h"

// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkPoints>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkPoints);
AMI_DEFINE_VARFROMSMTPTR(vtkPoints);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkPoints>::CreateVar( vtkPoints* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkPoints> obj_ptr(val,smartpointer_nodeleter<vtkPoints>());
  return AMILabType<vtkPoints>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkPoints
//
Variable<AMIObject>::ptr WrapClass_vtkPoints::CreateVar( vtkPoints* sp)
{
  boost::shared_ptr<vtkPoints> di_ptr(
    sp,
    wxwindow_nodeleter<vtkPoints>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkPoints>::CreateVar(
      new WrapClass_vtkPoints(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkPoints::AddMethods(WrapClass<vtkPoints>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_Allocate( this_ptr);
  AddVar_Initialize( this_ptr);
  AddVar_SetData( this_ptr);
  AddVar_GetData( this_ptr);
  AddVar_GetDataType( this_ptr);
  AddVar_SetDataType( this_ptr);
  AddVar_SetDataTypeToBit( this_ptr);
  AddVar_SetDataTypeToChar( this_ptr);
  AddVar_SetDataTypeToUnsignedChar( this_ptr);
  AddVar_SetDataTypeToShort( this_ptr);
  AddVar_SetDataTypeToUnsignedShort( this_ptr);
  AddVar_SetDataTypeToInt( this_ptr);
  AddVar_SetDataTypeToUnsignedInt( this_ptr);
  AddVar_SetDataTypeToLong( this_ptr);
  AddVar_SetDataTypeToUnsignedLong( this_ptr);
  AddVar_SetDataTypeToFloat( this_ptr);
  AddVar_SetDataTypeToDouble( this_ptr);
  AddVar_GetVoidPointer( this_ptr);
  AddVar_Squeeze( this_ptr);
  AddVar_Reset( this_ptr);
  AddVar_DeepCopy( this_ptr);
  AddVar_ShallowCopy( this_ptr);
  AddVar_GetActualMemorySize( this_ptr);
  AddVar_GetNumberOfPoints( this_ptr);
  AddVar_GetPoint_1( this_ptr);
  AddVar_GetPoint( this_ptr);
  AddVar_GetPoint_2( this_ptr);
  AddVar_SetPoint_1( this_ptr);
  AddVar_SetPoint( this_ptr);
  AddVar_SetPoint_2( this_ptr);
  AddVar_SetPoint_3( this_ptr);
  AddVar_InsertPoint_1( this_ptr);
  AddVar_InsertPoint( this_ptr);
  AddVar_InsertPoint_2( this_ptr);
  AddVar_InsertPoint_3( this_ptr);
  AddVar_InsertNextPoint_1( this_ptr);
  AddVar_InsertNextPoint( this_ptr);
  AddVar_InsertNextPoint_2( this_ptr);
  AddVar_InsertNextPoint_3( this_ptr);
  AddVar_SetNumberOfPoints( this_ptr);
/* The following types are missing: vtkIdList
  AddVar_GetPoints( this_ptr);
*/
  AddVar_ComputeBounds( this_ptr);
  AddVar_GetBounds_1( this_ptr);
  AddVar_GetBounds( this_ptr);
  AddVar_GetBounds_2( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

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
void WrapClass_vtkPoints::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkPoints");
  
  // Static methods 
  WrapClass_vtkPoints::AddVar_New_1(amiobject->GetContext());
  WrapClass_vtkPoints::AddVar_New(amiobject->GetContext());
  WrapClass_vtkPoints::AddVar_New_2(amiobject->GetContext());
  WrapClass_vtkPoints::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkPoints::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkPoints * vtkPoints::New(int dataType)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_static_New_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dataType'")
  return_comments="returning a variable of type vtkPoints";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_static_New_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int dataType;
  if (!get_val_param<int >(dataType,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkPoints * res =   vtkPoints::New(dataType);
  BasicVariable::ptr res_var = WrapClass_vtkPoints::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... static vtkPoints::New(...)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_static_New::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_static_New::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPoints::wrap_static_New_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPoints::wrap_static_New_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkPoints * vtkPoints::New()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_static_New_2::SetParametersComments()
{
  return_comments="returning a variable of type vtkPoints";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_static_New_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkPoints * res =   vtkPoints::New();
  BasicVariable::ptr res_var = WrapClass_vtkPoints::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkPoints::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkPoints::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkPoints * vtkPoints::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkPoints";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
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

  vtkPoints * res =   vtkPoints::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkPoints::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkPoints::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
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
//  Wrapping of vtkPoints * vtkPoints::NewInstance()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkPoints";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPoints * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkPoints::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkPoints::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
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
//  Wrapping of int vtkPoints::Allocate(vtkIdType const sz, vtkIdType const ext = 1000)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_Allocate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'ext' (def:1000)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_Allocate::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long sz_long;
  if (!get_val_param<long >(sz_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int sz = boost::numeric_cast<long long int >(sz_long);

  long ext_long = boost::numeric_cast<long >((unsigned int)1000);;
  if (!get_val_param<long >(ext_long,_p,_n,false,false)) ClassHelpAndReturn;
  long long int ext = boost::numeric_cast<long long int >(ext_long);

  int res =   this->_objectptr->GetObj()->Allocate(sz, ext);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::Initialize()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_Initialize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_Initialize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Initialize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetData(vtkDataArray * param0)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkDataArray* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > param0_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->SetData(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkDataArray * vtkPoints::GetData()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_GetData::SetParametersComments()
{
  return_comments="returning a variable of type vtkDataArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_GetData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkDataArray * res =   this->_objectptr->GetObj()->GetData();
  BasicVariable::ptr res_var = WrapClass_vtkDataArray::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkPoints::GetDataType()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_GetDataType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_GetDataType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDataType();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetDataType(int dataType)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetDataType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dataType'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetDataType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int dataType;
  if (!get_val_param<int >(dataType,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDataType(dataType);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetDataTypeToBit()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetDataTypeToBit::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetDataTypeToBit::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDataTypeToBit();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetDataTypeToChar()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetDataTypeToChar::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetDataTypeToChar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDataTypeToChar();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetDataTypeToUnsignedChar()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetDataTypeToUnsignedChar::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetDataTypeToUnsignedChar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDataTypeToUnsignedChar();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetDataTypeToShort()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetDataTypeToShort::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetDataTypeToShort::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDataTypeToShort();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetDataTypeToUnsignedShort()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetDataTypeToUnsignedShort::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetDataTypeToUnsignedShort::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDataTypeToUnsignedShort();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetDataTypeToInt()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetDataTypeToInt::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetDataTypeToInt::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDataTypeToInt();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetDataTypeToUnsignedInt()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetDataTypeToUnsignedInt::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetDataTypeToUnsignedInt::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDataTypeToUnsignedInt();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetDataTypeToLong()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetDataTypeToLong::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetDataTypeToLong::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDataTypeToLong();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetDataTypeToUnsignedLong()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetDataTypeToUnsignedLong::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetDataTypeToUnsignedLong::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDataTypeToUnsignedLong();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetDataTypeToFloat()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetDataTypeToFloat::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetDataTypeToFloat::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDataTypeToFloat();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetDataTypeToDouble()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetDataTypeToDouble::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetDataTypeToDouble::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDataTypeToDouble();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void * vtkPoints::GetVoidPointer(int const id)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_GetVoidPointer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_GetVoidPointer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GetVoidPointer(id);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::Squeeze()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_Squeeze::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_Squeeze::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Squeeze();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::Reset()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_Reset::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_Reset::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Reset();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::DeepCopy(vtkPoints * ad)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_DeepCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPoints, "parameter named 'ad'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_DeepCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkPoints* ad;
  if (CheckNullVar(_p,_n))  {
    ad=(vtkPoints*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPoints > ad_smtptr;
    if (!get_val_smtptr_param<vtkPoints >(ad_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    ad = ad_smtptr.get();
  }

  this->_objectptr->GetObj()->DeepCopy(ad);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::ShallowCopy(vtkPoints * ad)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_ShallowCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPoints, "parameter named 'ad'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_ShallowCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkPoints* ad;
  if (CheckNullVar(_p,_n))  {
    ad=(vtkPoints*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPoints > ad_smtptr;
    if (!get_val_smtptr_param<vtkPoints >(ad_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    ad = ad_smtptr.get();
  }

  this->_objectptr->GetObj()->ShallowCopy(ad);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkPoints::GetActualMemorySize()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_GetActualMemorySize::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_GetActualMemorySize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetActualMemorySize();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkPoints::GetNumberOfPoints()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_GetNumberOfPoints::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_GetNumberOfPoints::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->GetNumberOfPoints();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of double * vtkPoints::GetPoint(vtkIdType id)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_GetPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_GetPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int id = boost::numeric_cast<long long int >(id_long);

  double * res =   this->_objectptr->GetObj()->GetPoint(id);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPoints::GetPoint(...)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_GetPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_GetPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPoints::wrap_GetPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPoints::wrap_GetPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::GetPoint(vtkIdType id, double * x)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_GetPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_GetPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int id = boost::numeric_cast<long long int >(id_long);

  double* x;
  if (CheckNullVar(_p,_n))  {
    x=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > x_smtptr;
    if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    x = x_smtptr.get();
  }

  this->_objectptr->GetObj()->GetPoint(id, x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetPoint(vtkIdType id, float const * x)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int id = boost::numeric_cast<long long int >(id_long);

  float* x;
  if (CheckNullVar(_p,_n))  {
    x=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > x_smtptr;
    if (!get_val_smtptr_param<float >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    x = x_smtptr.get();
  }

  this->_objectptr->GetObj()->SetPoint(id, x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPoints::SetPoint(...)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPoints::wrap_SetPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPoints::wrap_SetPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkPoints::wrap_SetPoint_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetPoint(vtkIdType id, double const * x)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int id = boost::numeric_cast<long long int >(id_long);

  double* x;
  if (CheckNullVar(_p,_n))  {
    x=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > x_smtptr;
    if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    x = x_smtptr.get();
  }

  this->_objectptr->GetObj()->SetPoint(id, x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetPoint(vtkIdType id, double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetPoint_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetPoint_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int id = boost::numeric_cast<long long int >(id_long);

  double x;
  if (!get_val_param<double >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  double y;
  if (!get_val_param<double >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  double z;
  if (!get_val_param<double >(z,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetPoint(id, x, y, z);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::InsertPoint(vtkIdType id, float const * x)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_InsertPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_InsertPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int id = boost::numeric_cast<long long int >(id_long);

  float* x;
  if (CheckNullVar(_p,_n))  {
    x=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > x_smtptr;
    if (!get_val_smtptr_param<float >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    x = x_smtptr.get();
  }

  this->_objectptr->GetObj()->InsertPoint(id, x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPoints::InsertPoint(...)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_InsertPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_InsertPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPoints::wrap_InsertPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPoints::wrap_InsertPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkPoints::wrap_InsertPoint_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::InsertPoint(vtkIdType id, double const * x)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_InsertPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_InsertPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int id = boost::numeric_cast<long long int >(id_long);

  double* x;
  if (CheckNullVar(_p,_n))  {
    x=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > x_smtptr;
    if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    x = x_smtptr.get();
  }

  this->_objectptr->GetObj()->InsertPoint(id, x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::InsertPoint(vtkIdType id, double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_InsertPoint_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_InsertPoint_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int id = boost::numeric_cast<long long int >(id_long);

  double x;
  if (!get_val_param<double >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  double y;
  if (!get_val_param<double >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  double z;
  if (!get_val_param<double >(z,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->InsertPoint(id, x, y, z);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkPoints::InsertNextPoint(float const * x)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_InsertNextPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'x'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_InsertNextPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  float* x;
  if (CheckNullVar(_p,_n))  {
    x=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > x_smtptr;
    if (!get_val_smtptr_param<float >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    x = x_smtptr.get();
  }

  vtkIdType res =   this->_objectptr->GetObj()->InsertNextPoint(x);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPoints::InsertNextPoint(...)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_InsertNextPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_InsertNextPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPoints::wrap_InsertNextPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPoints::wrap_InsertNextPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkPoints::wrap_InsertNextPoint_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkPoints::InsertNextPoint(double const * x)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_InsertNextPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_InsertNextPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* x;
  if (CheckNullVar(_p,_n))  {
    x=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > x_smtptr;
    if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    x = x_smtptr.get();
  }

  vtkIdType res =   this->_objectptr->GetObj()->InsertNextPoint(x);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkPoints::InsertNextPoint(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_InsertNextPoint_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_InsertNextPoint_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  double y;
  if (!get_val_param<double >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  double z;
  if (!get_val_param<double >(z,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkIdType res =   this->_objectptr->GetObj()->InsertNextPoint(x, y, z);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::SetNumberOfPoints(vtkIdType number)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_SetNumberOfPoints::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'number'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_SetNumberOfPoints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long number_long;
  if (!get_val_param<long >(number_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int number = boost::numeric_cast<long long int >(number_long);

  this->_objectptr->GetObj()->SetNumberOfPoints(number);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkIdList

//---------------------------------------------------
//  Wrapping of void vtkPoints::GetPoints(vtkIdList * ptId, vtkPoints * fp)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_GetPoints::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkIdList, "parameter named 'ptId'")
  ADDPARAMCOMMENT_TYPE( vtkPoints, "parameter named 'fp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_GetPoints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkIdList* ptId;
  if (CheckNullVar(_p,_n))  {
    ptId=(vtkIdList*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkIdList > ptId_smtptr;
    if (!get_val_smtptr_param<vtkIdList >(ptId_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    ptId = ptId_smtptr.get();
  }

  vtkPoints* fp;
  if (CheckNullVar(_p,_n))  {
    fp=(vtkPoints*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPoints > fp_smtptr;
    if (!get_val_smtptr_param<vtkPoints >(fp_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    fp = fp_smtptr.get();
  }

  this->_objectptr->GetObj()->GetPoints(ptId, fp);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkPoints::ComputeBounds()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_ComputeBounds::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_ComputeBounds::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ComputeBounds();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkPoints::GetBounds()
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_GetBounds_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_GetBounds_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetBounds();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPoints::GetBounds(...)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_GetBounds::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_GetBounds::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPoints::wrap_GetBounds_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPoints::wrap_GetBounds_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkPoints::GetBounds(double * bounds)
//---------------------------------------------------
void WrapClass_vtkPoints::
    wrap_GetBounds_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPoints::
    wrap_GetBounds_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* bounds;
  if (CheckNullVar(_p,_n))  {
    bounds=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > bounds_smtptr;
    if (!get_val_smtptr_param<double >(bounds_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    bounds = bounds_smtptr.get();
  }

  this->_objectptr->GetObj()->GetBounds(bounds);
  return BasicVariable::ptr();
}

