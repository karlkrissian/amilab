/**
 * C++ Interface: wrap_vtkCellTypes
 *
 * Description: wrapping vtkCellTypes
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

#include "wrap_vtkCellTypes.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef vtkCellTypes_declared
  #define vtkCellTypes_declared
  AMI_DECLARE_TYPE(vtkCellTypes)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkUnsignedCharArray_declared
  #define vtkUnsignedCharArray_declared
  AMI_DECLARE_TYPE(vtkUnsignedCharArray)
#endif
#ifndef vtkIntArray_declared
  #define vtkIntArray_declared
  AMI_DECLARE_TYPE(vtkIntArray)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkCellTypes>::CreateVar( ParamList* p)
{
  WrapClass_vtkCellTypes::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkCellTypes);
AMI_DEFINE_VARFROMSMTPTR(vtkCellTypes);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkCellTypes>::CreateVar( vtkCellTypes* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkCellTypes> obj_ptr(val,smartpointer_nodeleter<vtkCellTypes>());
  return AMILabType<vtkCellTypes>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkCellTypes
//
Variable<AMIObject>::ptr WrapClass_vtkCellTypes::CreateVar( vtkCellTypes* sp)
{
  boost::shared_ptr<vtkCellTypes> di_ptr(
    sp,
    wxwindow_nodeleter<vtkCellTypes>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkCellTypes>::CreateVar(
      new WrapClass_vtkCellTypes(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkCellTypes::AddMethods(WrapClass<vtkCellTypes>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_Allocate( this_ptr);
  AddVar_InsertCell( this_ptr);
  AddVar_InsertNextCell( this_ptr);
  AddVar_SetCellTypes( this_ptr);
  AddVar_GetCellLocation( this_ptr);
  AddVar_DeleteCell( this_ptr);
  AddVar_GetNumberOfTypes( this_ptr);
  AddVar_IsType( this_ptr);
  AddVar_InsertNextType( this_ptr);
  AddVar_GetCellType( this_ptr);
  AddVar_Squeeze( this_ptr);
  AddVar_Reset( this_ptr);
  AddVar_GetActualMemorySize( this_ptr);
  AddVar_DeepCopy( this_ptr);



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
void WrapClassvtkCellTypes_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkCellTypes");
  
  // Static methods 
  WrapClass_vtkCellTypes::AddVar_New(amiobject->GetContext());
  WrapClass_vtkCellTypes::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkCellTypes::AddVar_SafeDownCast(amiobject->GetContext());
  WrapClass_vtkCellTypes::AddVar_GetClassNameFromTypeId(amiobject->GetContext());
  WrapClass_vtkCellTypes::AddVar_GetTypeIdFromClassName(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkCellTypes * vtkCellTypes::New()
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkCellTypes";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkCellTypes * res =   vtkCellTypes::New();
  BasicVariable::ptr res_var = AMILabType<vtkCellTypes >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkCellTypes::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkCellTypes::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkCellTypes * vtkCellTypes::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkCellTypes";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
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

  vtkCellTypes * res =   vtkCellTypes::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkCellTypes >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of char const * vtkCellTypes::GetClassNameFromTypeId(int typeId)
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_static_GetClassNameFromTypeId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'typeId'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_static_GetClassNameFromTypeId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int typeId;
  if (!get_val_param<int >(typeId,_p,_n,true,false)) ClassHelpAndReturn;

  char const * res =   vtkCellTypes::GetClassNameFromTypeId(typeId);
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of int vtkCellTypes::GetTypeIdFromClassName(char const * classname)
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_static_GetTypeIdFromClassName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'classname'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_static_GetTypeIdFromClassName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > classname_string;
  if (!get_val_smtptr_param<std::string >(classname_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * classname = classname_string->c_str();

  int res =   vtkCellTypes::GetTypeIdFromClassName(classname);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkCellTypes::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
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
//  Wrapping of vtkCellTypes * vtkCellTypes::NewInstance()
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkCellTypes";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkCellTypes * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkCellTypes >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkCellTypes::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
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
//  Wrapping of int vtkCellTypes::Allocate(int sz = 512, int ext = 1000)
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_Allocate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'sz' (def:512)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ext' (def:1000)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_Allocate::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int sz = 512;
  if (!get_val_param<int >(sz,_p,_n,false,false)) ClassHelpAndReturn;

  int ext = 1000;
  if (!get_val_param<int >(ext,_p,_n,false,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->Allocate(sz, ext);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkCellTypes::InsertCell(int id, unsigned char type, int loc)
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_InsertCell::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'type'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'loc'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_InsertCell::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  unsigned char type;
  if (!get_val_param<unsigned char >(type,_p,_n,true,false)) ClassHelpAndReturn;

  int loc;
  if (!get_val_param<int >(loc,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InsertCell(id, type, loc);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkCellTypes::InsertNextCell(unsigned char type, int loc)
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_InsertNextCell::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'type'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'loc'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_InsertNextCell::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  unsigned char type;
  if (!get_val_param<unsigned char >(type,_p,_n,true,false)) ClassHelpAndReturn;

  int loc;
  if (!get_val_param<int >(loc,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->InsertNextCell(type, loc);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkCellTypes::SetCellTypes(int ncells, vtkUnsignedCharArray * cellTypes, vtkIntArray * cellLocations)
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_SetCellTypes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ncells'")
  ADDPARAMCOMMENT_TYPE( vtkUnsignedCharArray, "parameter named 'cellTypes'")
  ADDPARAMCOMMENT_TYPE( vtkIntArray, "parameter named 'cellLocations'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_SetCellTypes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int ncells;
  if (!get_val_param<int >(ncells,_p,_n,true,false)) ClassHelpAndReturn;

  vtkUnsignedCharArray* cellTypes;
  if (CheckNullVar(_p,_n))  {
    cellTypes=(vtkUnsignedCharArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkUnsignedCharArray > cellTypes_smtptr;
    if (!get_val_smtptr_param<vtkUnsignedCharArray >(cellTypes_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    cellTypes = cellTypes_smtptr.get();
  }

  vtkIntArray* cellLocations;
  if (CheckNullVar(_p,_n))  {
    cellLocations=(vtkIntArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkIntArray > cellLocations_smtptr;
    if (!get_val_smtptr_param<vtkIntArray >(cellLocations_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    cellLocations = cellLocations_smtptr.get();
  }

  this->_objectptr->GetObj()->SetCellTypes(ncells, cellTypes, cellLocations);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkCellTypes::GetCellLocation(int cellId)
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_GetCellLocation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cellId'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_GetCellLocation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int cellId;
  if (!get_val_param<int >(cellId,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCellLocation(cellId);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkCellTypes::DeleteCell(vtkIdType cellId)
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_DeleteCell::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_DeleteCell::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  this->_objectptr->GetObj()->DeleteCell(cellId);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkCellTypes::GetNumberOfTypes()
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_GetNumberOfTypes::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_GetNumberOfTypes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfTypes();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkCellTypes::IsType(unsigned char type)
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_IsType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_IsType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  unsigned char type;
  if (!get_val_param<unsigned char >(type,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->IsType(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkCellTypes::InsertNextType(unsigned char type)
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_InsertNextType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_InsertNextType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  unsigned char type;
  if (!get_val_param<unsigned char >(type,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->InsertNextType(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of unsigned char vtkCellTypes::GetCellType(int cellId)
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_GetCellType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cellId'")
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_GetCellType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int cellId;
  if (!get_val_param<int >(cellId,_p,_n,true,false)) ClassHelpAndReturn;

  unsigned char res =   this->_objectptr->GetObj()->GetCellType(cellId);
  return AMILabType<unsigned char >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkCellTypes::Squeeze()
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_Squeeze::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_Squeeze::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Squeeze();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCellTypes::Reset()
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_Reset::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_Reset::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Reset();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkCellTypes::GetActualMemorySize()
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_GetActualMemorySize::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_GetActualMemorySize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetActualMemorySize();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkCellTypes::DeepCopy(vtkCellTypes * src)
//---------------------------------------------------
void WrapClass_vtkCellTypes::
    wrap_DeepCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkCellTypes, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCellTypes::
    wrap_DeepCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkCellTypes* src;
  if (CheckNullVar(_p,_n))  {
    src=(vtkCellTypes*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkCellTypes > src_smtptr;
    if (!get_val_smtptr_param<vtkCellTypes >(src_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    src = src_smtptr.get();
  }

  this->_objectptr->GetObj()->DeepCopy(src);
  return BasicVariable::ptr();
}

