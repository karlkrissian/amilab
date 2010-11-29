/**
 * C++ Interface: wrap_vtkUnsignedCharArray
 *
 * Description: wrapping vtkUnsignedCharArray
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
#include "wrap_vtkUnsignedCharArray.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_vtkUnsignedCharArray.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkUnsignedCharArray>::CreateVar( ParamList* p)
{
  WrapClass_vtkUnsignedCharArray::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkUnsignedCharArray);
AMI_DEFINE_VARFROMSMTPTR(vtkUnsignedCharArray);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkUnsignedCharArray>::CreateVar( vtkUnsignedCharArray* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkUnsignedCharArray> obj_ptr(val,smartpointer_nodeleter<vtkUnsignedCharArray>());
  return AMILabType<vtkUnsignedCharArray>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkUnsignedCharArray
//
Variable<AMIObject>::ptr WrapClass_vtkUnsignedCharArray::CreateVar( vtkUnsignedCharArray* sp)
{
  boost::shared_ptr<vtkUnsignedCharArray> di_ptr(
    sp,
    wxwindow_nodeleter<vtkUnsignedCharArray>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkUnsignedCharArray>::CreateVar(
      new WrapClass_vtkUnsignedCharArray(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkUnsignedCharArray::AddMethods(WrapClass<vtkUnsignedCharArray>::ptr this_ptr )
{
  /*
      // Add members from vtkDataArrayTemplate<unsigned char>
      WrapClass_vtkDataArrayTemplate_unsigned char_::ptr parent_vtkDataArrayTemplate_unsigned char_(        boost::dynamic_pointer_cast<WrapClass_vtkDataArrayTemplate_unsigned char_ >(this_ptr));
      parent_vtkDataArrayTemplate_unsigned char_->AddMethods(parent_vtkDataArrayTemplate_unsigned char_);
      */


  // check that the method name is not a token
  
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



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkUnsignedCharArray * vtkUnsignedCharArray::New()
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkUnsignedCharArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkUnsignedCharArray * res =   vtkUnsignedCharArray::New();
  BasicVariable::ptr res_var = WrapClass_vtkUnsignedCharArray::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkUnsignedCharArray::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkUnsignedCharArray::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkUnsignedCharArray * vtkUnsignedCharArray::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkUnsignedCharArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkUnsignedCharArray * res =   vtkUnsignedCharArray::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkUnsignedCharArray::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkUnsignedCharArray::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
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
//  Wrapping of vtkUnsignedCharArray * vtkUnsignedCharArray::NewInstance()
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkUnsignedCharArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkUnsignedCharArray * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkUnsignedCharArray::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkUnsignedCharArray::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
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
//  Wrapping of int vtkUnsignedCharArray::GetDataType()
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_GetDataType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_GetDataType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDataType();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkUnsignedCharArray::GetTupleValue(vtkIdType i, unsigned char * tuple)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_GetTupleValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'tuple'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_GetTupleValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  boost::shared_ptr<unsigned char > tuple_smtptr;
  if (!get_val_smtptr_param<unsigned char >(tuple_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  unsigned char* tuple = tuple_smtptr.get();

  this->_objectptr->GetObj()->GetTupleValue(i, tuple);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkUnsignedCharArray::SetTupleValue(vtkIdType i, unsigned char const * tuple)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_SetTupleValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'tuple'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_SetTupleValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  boost::shared_ptr<unsigned char > tuple_smtptr;
  if (!get_val_smtptr_param<unsigned char >(tuple_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  unsigned char* tuple = tuple_smtptr.get();

  this->_objectptr->GetObj()->SetTupleValue(i, tuple);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkUnsignedCharArray::InsertTupleValue(vtkIdType i, unsigned char const * tuple)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_InsertTupleValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'tuple'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_InsertTupleValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int i = boost::numeric_cast<long long int >(i_long);

  boost::shared_ptr<unsigned char > tuple_smtptr;
  if (!get_val_smtptr_param<unsigned char >(tuple_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  unsigned char* tuple = tuple_smtptr.get();

  this->_objectptr->GetObj()->InsertTupleValue(i, tuple);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkUnsignedCharArray::InsertNextTupleValue(unsigned char const * tuple)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_InsertNextTupleValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'tuple'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_InsertNextTupleValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<unsigned char > tuple_smtptr;
  if (!get_val_smtptr_param<unsigned char >(tuple_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  unsigned char* tuple = tuple_smtptr.get();

  vtkIdType res =   this->_objectptr->GetObj()->InsertNextTupleValue(tuple);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of unsigned char vtkUnsignedCharArray::GetValue(vtkIdType id)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_GetValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_GetValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int id = boost::numeric_cast<long long int >(id_long);

  unsigned char res =   this->_objectptr->GetObj()->GetValue(id);
  return AMILabType<unsigned char >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkUnsignedCharArray::SetValue(vtkIdType id, unsigned char value)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_SetValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_SetValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int id = boost::numeric_cast<long long int >(id_long);

  unsigned char value;
  if (!get_val_param<unsigned char >(value,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetValue(id, value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkUnsignedCharArray::SetNumberOfValues(vtkIdType number)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_SetNumberOfValues::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'number'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
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
//  Wrapping of void vtkUnsignedCharArray::InsertValue(vtkIdType id, unsigned char f)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_InsertValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'f'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_InsertValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int id = boost::numeric_cast<long long int >(id_long);

  unsigned char f;
  if (!get_val_param<unsigned char >(f,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InsertValue(id, f);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkUnsignedCharArray::InsertNextValue(unsigned char f)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_InsertNextValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'f'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_InsertNextValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  unsigned char f;
  if (!get_val_param<unsigned char >(f,_p,_n,true,false)) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->InsertNextValue(f);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of unsigned char * vtkUnsignedCharArray::WritePointer(vtkIdType id, vtkIdType number)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_WritePointer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'number'")
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
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

  unsigned char * res =   this->_objectptr->GetObj()->WritePointer(id, number);
  return AMILabType<unsigned char >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of unsigned char * vtkUnsignedCharArray::GetPointer(vtkIdType id)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_GetPointer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_GetPointer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int id = boost::numeric_cast<long long int >(id_long);

  unsigned char * res =   this->_objectptr->GetObj()->GetPointer(id);
  return AMILabType<unsigned char >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkUnsignedCharArray::SetArray(unsigned char * array, vtkIdType size, int save)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_SetArray_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'array'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'save'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_SetArray_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<unsigned char > array_smtptr;
  if (!get_val_smtptr_param<unsigned char >(array_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  unsigned char* array = array_smtptr.get();

  long size_long;
  if (!get_val_param<long >(size_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int size = boost::numeric_cast<long long int >(size_long);

  int save;
  if (!get_val_param<int >(save,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetArray(array, size, save);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkUnsignedCharArray::SetArray(...)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_SetArray::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_SetArray::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkUnsignedCharArray::wrap_SetArray_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkUnsignedCharArray::wrap_SetArray_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkUnsignedCharArray::SetArray(unsigned char * array, vtkIdType size, int save, int deleteMethod)
//---------------------------------------------------
void WrapClass_vtkUnsignedCharArray::
    wrap_SetArray_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'array'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'save'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deleteMethod'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnsignedCharArray::
    wrap_SetArray_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<unsigned char > array_smtptr;
  if (!get_val_smtptr_param<unsigned char >(array_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  unsigned char* array = array_smtptr.get();

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

