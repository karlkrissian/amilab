/**
 * C++ Interface: wrap_vtkIntArray
 *
 * Description: wrapping vtkIntArray
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

#include "wrap_vtkIntArray.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef vtkIntArray_declared
  #define vtkIntArray_declared
  AMI_DECLARE_TYPE(vtkIntArray)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkIntArray>::CreateVar( ParamList* p)
{
  WrapClass_vtkIntArray::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkIntArray);
AMI_DEFINE_VARFROMSMTPTR(vtkIntArray);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkIntArray>::CreateVar( vtkIntArray* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkIntArray> obj_ptr(val,smartpointer_nodeleter<vtkIntArray>());
  return AMILabType<vtkIntArray>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkIntArray
//
Variable<AMIObject>::ptr WrapClass_vtkIntArray::CreateVar( vtkIntArray* sp)
{
  boost::shared_ptr<vtkIntArray> di_ptr(
    sp,
    wxwindow_nodeleter<vtkIntArray>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkIntArray>::CreateVar(
      new WrapClass_vtkIntArray(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkIntArray::AddMethods(WrapClass<vtkIntArray>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_GetDataType( this_ptr);
  AddVar_GetTupleValue( this_ptr);
  AddVar_SetTupleValue( this_ptr);
  AddVar_InsertTupleValue( this_ptr);
  AddVar_InsertNextTupleValue( this_ptr);
  AddVar_GetValue( this_ptr);
  AddVar_SetValue( this_ptr);
  AddVar_SetNumberOfValues( this_ptr);
  AddVar_InsertValue( this_ptr);
  AddVar_InsertNextValue( this_ptr);
  AddVar_WritePointer( this_ptr);
  AddVar_GetPointer( this_ptr);
  AddVar_SetArray_1( this_ptr);
  AddVar_SetArray( this_ptr);
  AddVar_SetArray_2( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases
/*
  // Add base parent vtkDataArrayTemplate<int>
  boost::shared_ptr<vtkDataArrayTemplate<int> > parent_vtkDataArrayTemplate_int_(  boost::dynamic_pointer_cast<vtkDataArrayTemplate<int> >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkDataArrayTemplate_int_ = AMILabType<vtkDataArrayTemplate<int> >::CreateVarFromSmtPtr(parent_vtkDataArrayTemplate_int_);
  context->AddVar("vtkDataArrayTemplate_int_",var_vtkDataArrayTemplate_int_);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkDataArrayTemplate_int_ = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkDataArrayTemplate_int_);
  context->AddDefault(obj_vtkDataArrayTemplate_int_->Pointer()->GetContext());
*/

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkIntArray_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkIntArray");
  
  // Static methods 
  WrapClass_vtkIntArray::AddVar_New(amiobject->GetContext());
  WrapClass_vtkIntArray::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkIntArray::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkIntArray * vtkIntArray::New()
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkIntArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIntArray * res =   vtkIntArray::New();
  BasicVariable::ptr res_var = AMILabType<vtkIntArray >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkIntArray::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkIntArray::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkIntArray * vtkIntArray::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkIntArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
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

  vtkIntArray * res =   vtkIntArray::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkIntArray >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkIntArray::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
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
//  Wrapping of vtkIntArray * vtkIntArray::NewInstance()
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkIntArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIntArray * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkIntArray >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkIntArray::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
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
//  Wrapping of int vtkIntArray::GetDataType()
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_GetDataType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_GetDataType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDataType();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkIntArray::GetTupleValue(vtkIdType i, int * tuple)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_GetTupleValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tuple'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_GetTupleValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  int* tuple;
  if (CheckNullVar(_p,_n))  {
    tuple=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > tuple_smtptr;
    if (!get_val_smtptr_param<int >(tuple_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    tuple = tuple_smtptr.get();
  }

  this->_objectptr->GetObj()->GetTupleValue(i, tuple);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkIntArray::SetTupleValue(vtkIdType i, int const * tuple)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_SetTupleValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tuple'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_SetTupleValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  int* tuple;
  if (CheckNullVar(_p,_n))  {
    tuple=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > tuple_smtptr;
    if (!get_val_smtptr_param<int >(tuple_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    tuple = tuple_smtptr.get();
  }

  this->_objectptr->GetObj()->SetTupleValue(i, tuple);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkIntArray::InsertTupleValue(vtkIdType i, int const * tuple)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_InsertTupleValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tuple'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_InsertTupleValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  int* tuple;
  if (CheckNullVar(_p,_n))  {
    tuple=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > tuple_smtptr;
    if (!get_val_smtptr_param<int >(tuple_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    tuple = tuple_smtptr.get();
  }

  this->_objectptr->GetObj()->InsertTupleValue(i, tuple);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkIntArray::InsertNextTupleValue(int const * tuple)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_InsertNextTupleValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tuple'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_InsertNextTupleValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int* tuple;
  if (CheckNullVar(_p,_n))  {
    tuple=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > tuple_smtptr;
    if (!get_val_smtptr_param<int >(tuple_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    tuple = tuple_smtptr.get();
  }

  vtkIdType res =   this->_objectptr->GetObj()->InsertNextTupleValue(tuple);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of int vtkIntArray::GetValue(vtkIdType id)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_GetValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_GetValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int id = boost::numeric_cast<long long int >(id_long);

  int res =   this->_objectptr->GetObj()->GetValue(id);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkIntArray::SetValue(vtkIdType id, int value)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_SetValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_SetValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int id = boost::numeric_cast<long long int >(id_long);

  int value;
  if (!get_val_param<int >(value,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetValue(id, value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkIntArray::SetNumberOfValues(vtkIdType number)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_SetNumberOfValues::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'number'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_SetNumberOfValues::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long number_long;
  if (!get_val_param<long >(number_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int number = boost::numeric_cast<long long int >(number_long);

  this->_objectptr->GetObj()->SetNumberOfValues(number);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkIntArray::InsertValue(vtkIdType id, int f)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_InsertValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'f'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_InsertValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int id = boost::numeric_cast<long long int >(id_long);

  int f;
  if (!get_val_param<int >(f,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InsertValue(id, f);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkIntArray::InsertNextValue(int f)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_InsertNextValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'f'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_InsertNextValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int f;
  if (!get_val_param<int >(f,_p,_n,true,false)) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->InsertNextValue(f);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of int * vtkIntArray::WritePointer(vtkIdType id, vtkIdType number)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_WritePointer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'number'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_WritePointer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int id = boost::numeric_cast<long long int >(id_long);

  long number_long;
  if (!get_val_param<long >(number_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int number = boost::numeric_cast<long long int >(number_long);

  int * res =   this->_objectptr->GetObj()->WritePointer(id, number);
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of int * vtkIntArray::GetPointer(vtkIdType id)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_GetPointer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_GetPointer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int id = boost::numeric_cast<long long int >(id_long);

  int * res =   this->_objectptr->GetObj()->GetPointer(id);
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkIntArray::SetArray(int * array, vtkIdType size, int save)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_SetArray_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'array'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'save'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_SetArray_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int* array;
  if (CheckNullVar(_p,_n))  {
    array=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > array_smtptr;
    if (!get_val_smtptr_param<int >(array_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    array = array_smtptr.get();
  }

  long size_long;
  if (!get_val_param<long >(size_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int size = boost::numeric_cast<long long int >(size_long);

  int save;
  if (!get_val_param<int >(save,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetArray(array, size, save);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkIntArray::SetArray(...)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_SetArray::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_SetArray::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkIntArray::wrap_SetArray_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkIntArray::wrap_SetArray_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkIntArray::SetArray(int * array, vtkIdType size, int save, int deleteMethod)
//---------------------------------------------------
void WrapClass_vtkIntArray::
    wrap_SetArray_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'array'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'save'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deleteMethod'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIntArray::
    wrap_SetArray_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int* array;
  if (CheckNullVar(_p,_n))  {
    array=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > array_smtptr;
    if (!get_val_smtptr_param<int >(array_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    array = array_smtptr.get();
  }

  long size_long;
  if (!get_val_param<long >(size_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int size = boost::numeric_cast<long long int >(size_long);

  int save;
  if (!get_val_param<int >(save,_p,_n,true,true)) ClassReturnEmptyVar;

  int deleteMethod;
  if (!get_val_param<int >(deleteMethod,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetArray(array, size, save, deleteMethod);
  return BasicVariable::ptr();
}

