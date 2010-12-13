/**
 * C++ Interface: wrap_vtkPiecewiseFunction
 *
 * Description: wrapping vtkPiecewiseFunction
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

#include "wrap_vtkPiecewiseFunction.h"

// get all the required includes
// #include "..."
#ifndef vtkPiecewiseFunction_declared
  #define vtkPiecewiseFunction_declared
  AMI_DECLARE_TYPE(vtkPiecewiseFunction)
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
BasicVariable::ptr WrapClass<vtkPiecewiseFunction>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkPiecewiseFunction);
AMI_DEFINE_VARFROMSMTPTR(vtkPiecewiseFunction);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkPiecewiseFunction>::CreateVar( vtkPiecewiseFunction* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkPiecewiseFunction> obj_ptr(val,smartpointer_nodeleter<vtkPiecewiseFunction>());
  return AMILabType<vtkPiecewiseFunction>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkPiecewiseFunction
//
Variable<AMIObject>::ptr WrapClass_vtkPiecewiseFunction::CreateVar( vtkPiecewiseFunction* sp)
{
  boost::shared_ptr<vtkPiecewiseFunction> di_ptr(
    sp,
    wxwindow_nodeleter<vtkPiecewiseFunction>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkPiecewiseFunction>::CreateVar(
      new WrapClass_vtkPiecewiseFunction(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkPiecewiseFunction::AddMethods(WrapClass<vtkPiecewiseFunction>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_DeepCopy( this_ptr);
  AddVar_ShallowCopy( this_ptr);
  AddVar_GetDataObjectType( this_ptr);
  AddVar_GetSize( this_ptr);
  AddVar_AddPoint_1( this_ptr);
  AddVar_AddPoint( this_ptr);
  AddVar_AddPoint_2( this_ptr);
  AddVar_RemovePoint( this_ptr);
  AddVar_RemoveAllPoints( this_ptr);
  AddVar_AddSegment( this_ptr);
  AddVar_GetValue( this_ptr);
  AddVar_GetNodeValue( this_ptr);
  AddVar_SetNodeValue( this_ptr);
  AddVar_GetDataPointer( this_ptr);
  AddVar_FillFromDataPointer( this_ptr);
  AddVar_GetRange_1( this_ptr);
  AddVar_GetRange( this_ptr);
  AddVar_GetRange_2( this_ptr);
  AddVar_GetRange_3( this_ptr);
  AddVar_AdjustRange( this_ptr);
  AddVar_GetTable_1( this_ptr);
  AddVar_GetTable( this_ptr);
  AddVar_GetTable_2( this_ptr);
  AddVar_BuildFunctionFromTable( this_ptr);
  AddVar_SetClamping( this_ptr);
  AddVar_GetClamping( this_ptr);
  AddVar_ClampingOn( this_ptr);
  AddVar_ClampingOff( this_ptr);
  AddVar_GetType( this_ptr);
  AddVar_GetFirstNonZeroValue( this_ptr);
  AddVar_Initialize( this_ptr);
  AddVar_SetAllowDuplicateScalars( this_ptr);
  AddVar_GetAllowDuplicateScalars( this_ptr);
  AddVar_AllowDuplicateScalarsOn( this_ptr);
  AddVar_AllowDuplicateScalarsOff( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent vtkDataObject
  boost::shared_ptr<vtkDataObject > parent_vtkDataObject(  boost::dynamic_pointer_cast<vtkDataObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkDataObject = AMILabType<vtkDataObject >::CreateVarFromSmtPtr(parent_vtkDataObject);
  context->AddVar("vtkDataObject",var_vtkDataObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkDataObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkDataObject);
  context->AddDefault(obj_vtkDataObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkPiecewiseFunction_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkPiecewiseFunction");
  
  // Static methods 
  WrapClass_vtkPiecewiseFunction::AddVar_New(amiobject->GetContext());
  WrapClass_vtkPiecewiseFunction::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkPiecewiseFunction::AddVar_SafeDownCast(amiobject->GetContext());
  /* Types are missing
  WrapClass_vtkPiecewiseFunction::AddVar_GetData_1(amiobject->GetContext());
  */
  WrapClass_vtkPiecewiseFunction::AddVar_GetData(amiobject->GetContext());
  /* Types are missing
  WrapClass_vtkPiecewiseFunction::AddVar_GetData_2(amiobject->GetContext());
  */

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkPiecewiseFunction * vtkPiecewiseFunction::New()
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkPiecewiseFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPiecewiseFunction * res =   vtkPiecewiseFunction::New();
  BasicVariable::ptr res_var = AMILabType<vtkPiecewiseFunction >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkPiecewiseFunction::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkPiecewiseFunction::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkPiecewiseFunction * vtkPiecewiseFunction::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkPiecewiseFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
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

  vtkPiecewiseFunction * res =   vtkPiecewiseFunction::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkPiecewiseFunction >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of vtkPiecewiseFunction * vtkPiecewiseFunction::GetData(vtkInformation * info)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_static_GetData_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'info'")
  return_comments="returning a variable of type vtkPiecewiseFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_static_GetData_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformation* info;
  if (CheckNullVar(_p,_n))  {
    info=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > info_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(info_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    info = info_smtptr.get();
  }

  vtkPiecewiseFunction * res =   vtkPiecewiseFunction::GetData(info);
  BasicVariable::ptr res_var = AMILabType<vtkPiecewiseFunction >::CreateVar(res,true);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... static vtkPiecewiseFunction::GetData(...)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_static_GetData::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_static_GetData::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformationVector

//---------------------------------------------------
//  Wrapping of vtkPiecewiseFunction * vtkPiecewiseFunction::GetData(vtkInformationVector * v, int i = 0)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_static_GetData_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationVector, "parameter named 'v'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i' (def:0)")
  return_comments="returning a variable of type vtkPiecewiseFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_static_GetData_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationVector* v;
  if (CheckNullVar(_p,_n))  {
    v=(vtkInformationVector*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationVector > v_smtptr;
    if (!get_val_smtptr_param<vtkInformationVector >(v_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    v = v_smtptr.get();
  }

  int i = 0;
  if (!get_val_param<int >(i,_p,_n,false,true)) ClassReturnEmptyVar;

  vtkPiecewiseFunction * res =   vtkPiecewiseFunction::GetData(v, i);
  BasicVariable::ptr res_var = AMILabType<vtkPiecewiseFunction >::CreateVar(res,true);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of int vtkPiecewiseFunction::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
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
//  Wrapping of vtkPiecewiseFunction * vtkPiecewiseFunction::NewInstance()
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkPiecewiseFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPiecewiseFunction * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkPiecewiseFunction >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
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
//  Wrapping of void vtkPiecewiseFunction::DeepCopy(vtkDataObject * f)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_DeepCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'f'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_DeepCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkDataObject* f;
  if (CheckNullVar(_p,_n))  {
    f=(vtkDataObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataObject > f_smtptr;
    if (!get_val_smtptr_param<vtkDataObject >(f_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    f = f_smtptr.get();
  }

  this->_objectptr->GetObj()->DeepCopy(f);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::ShallowCopy(vtkDataObject * f)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_ShallowCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'f'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_ShallowCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkDataObject* f;
  if (CheckNullVar(_p,_n))  {
    f=(vtkDataObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataObject > f_smtptr;
    if (!get_val_smtptr_param<vtkDataObject >(f_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    f = f_smtptr.get();
  }

  this->_objectptr->GetObj()->ShallowCopy(f);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPiecewiseFunction::GetDataObjectType()
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_GetDataObjectType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_GetDataObjectType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDataObjectType();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkPiecewiseFunction::GetSize()
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_GetSize::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_GetSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetSize();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkPiecewiseFunction::AddPoint(double x, double y)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_AddPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_AddPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  double y;
  if (!get_val_param<double >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->AddPoint(x, y);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPiecewiseFunction::AddPoint(...)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_AddPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_AddPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPiecewiseFunction::wrap_AddPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPiecewiseFunction::wrap_AddPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int vtkPiecewiseFunction::AddPoint(double x, double y, double midpoint, double sharpness)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_AddPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'midpoint'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'sharpness'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_AddPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  double y;
  if (!get_val_param<double >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  double midpoint;
  if (!get_val_param<double >(midpoint,_p,_n,true,true)) ClassReturnEmptyVar;

  double sharpness;
  if (!get_val_param<double >(sharpness,_p,_n,true,true)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->AddPoint(x, y, midpoint, sharpness);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkPiecewiseFunction::RemovePoint(double x)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_RemovePoint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_RemovePoint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->RemovePoint(x);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::RemoveAllPoints()
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_RemoveAllPoints::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_RemoveAllPoints::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RemoveAllPoints();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::AddSegment(double x1, double y1, double x2, double y2)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_AddSegment::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_AddSegment::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  double x1;
  if (!get_val_param<double >(x1,_p,_n,true,false)) ClassHelpAndReturn;

  double y1;
  if (!get_val_param<double >(y1,_p,_n,true,false)) ClassHelpAndReturn;

  double x2;
  if (!get_val_param<double >(x2,_p,_n,true,false)) ClassHelpAndReturn;

  double y2;
  if (!get_val_param<double >(y2,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AddSegment(x1, y1, x2, y2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkPiecewiseFunction::GetValue(double x)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_GetValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_GetValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,false)) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetValue(x);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkPiecewiseFunction::GetNodeValue(int index, double * val)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_GetNodeValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_GetNodeValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,false)) ClassHelpAndReturn;

  double* val;
  if (CheckNullVar(_p,_n))  {
    val=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > val_smtptr;
    if (!get_val_smtptr_param<double >(val_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    val = val_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->GetNodeValue(index, val);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkPiecewiseFunction::SetNodeValue(int index, double * val)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_SetNodeValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_SetNodeValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,false)) ClassHelpAndReturn;

  double* val;
  if (CheckNullVar(_p,_n))  {
    val=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > val_smtptr;
    if (!get_val_smtptr_param<double >(val_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    val = val_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->SetNodeValue(index, val);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double * vtkPiecewiseFunction::GetDataPointer()
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_GetDataPointer::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_GetDataPointer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double * res =   this->_objectptr->GetObj()->GetDataPointer();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::FillFromDataPointer(int param0, double * param1)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_FillFromDataPointer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_FillFromDataPointer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  double* param1;
  if (CheckNullVar(_p,_n))  {
    param1=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > param1_smtptr;
    if (!get_val_smtptr_param<double >(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param1 = param1_smtptr.get();
  }

  this->_objectptr->GetObj()->FillFromDataPointer(param0, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkPiecewiseFunction::GetRange()
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_GetRange_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_GetRange_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetRange();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPiecewiseFunction::GetRange(...)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_GetRange::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_GetRange::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPiecewiseFunction::wrap_GetRange_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPiecewiseFunction::wrap_GetRange_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkPiecewiseFunction::wrap_GetRange_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::GetRange(double & _arg1, double & _arg2)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_GetRange_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_GetRange_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  this->_objectptr->GetObj()->GetRange(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::GetRange(double * _arg)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_GetRange_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_GetRange_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* _arg;
  if (CheckNullVar(_p,_n))  {
    _arg=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > _arg_smtptr;
    if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    _arg = _arg_smtptr.get();
  }

  this->_objectptr->GetObj()->GetRange(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPiecewiseFunction::AdjustRange(double * range)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_AdjustRange::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'range'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_AdjustRange::CallMember( ParamList* _p)
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

  int res =   this->_objectptr->GetObj()->AdjustRange(range);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::GetTable(double x1, double x2, int size, float * table, int stride = 1)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_GetTable_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'table'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'stride' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_GetTable_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  double x1;
  if (!get_val_param<double >(x1,_p,_n,true,true)) ClassReturnEmptyVar;

  double x2;
  if (!get_val_param<double >(x2,_p,_n,true,true)) ClassReturnEmptyVar;

  int size;
  if (!get_val_param<int >(size,_p,_n,true,true)) ClassReturnEmptyVar;

  float* table;
  if (CheckNullVar(_p,_n))  {
    table=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > table_smtptr;
    if (!get_val_smtptr_param<float >(table_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    table = table_smtptr.get();
  }

  int stride = 1;
  if (!get_val_param<int >(stride,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->GetTable(x1, x2, size, table, stride);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPiecewiseFunction::GetTable(...)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_GetTable::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_GetTable::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPiecewiseFunction::wrap_GetTable_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPiecewiseFunction::wrap_GetTable_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::GetTable(double x1, double x2, int size, double * table, int stride = 1)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_GetTable_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'table'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'stride' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_GetTable_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  double x1;
  if (!get_val_param<double >(x1,_p,_n,true,true)) ClassReturnEmptyVar;

  double x2;
  if (!get_val_param<double >(x2,_p,_n,true,true)) ClassReturnEmptyVar;

  int size;
  if (!get_val_param<int >(size,_p,_n,true,true)) ClassReturnEmptyVar;

  double* table;
  if (CheckNullVar(_p,_n))  {
    table=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > table_smtptr;
    if (!get_val_smtptr_param<double >(table_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    table = table_smtptr.get();
  }

  int stride = 1;
  if (!get_val_param<int >(stride,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->GetTable(x1, x2, size, table, stride);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::BuildFunctionFromTable(double x1, double x2, int size, double * table, int stride = 1)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_BuildFunctionFromTable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'table'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'stride' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_BuildFunctionFromTable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  double x1;
  if (!get_val_param<double >(x1,_p,_n,true,false)) ClassHelpAndReturn;

  double x2;
  if (!get_val_param<double >(x2,_p,_n,true,false)) ClassHelpAndReturn;

  int size;
  if (!get_val_param<int >(size,_p,_n,true,false)) ClassHelpAndReturn;

  double* table;
  if (CheckNullVar(_p,_n))  {
    table=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > table_smtptr;
    if (!get_val_smtptr_param<double >(table_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    table = table_smtptr.get();
  }

  int stride = 1;
  if (!get_val_param<int >(stride,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->BuildFunctionFromTable(x1, x2, size, table, stride);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::SetClamping(int _arg)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_SetClamping::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_SetClamping::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetClamping(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPiecewiseFunction::GetClamping()
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_GetClamping::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_GetClamping::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetClamping();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::ClampingOn()
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_ClampingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_ClampingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ClampingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::ClampingOff()
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_ClampingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_ClampingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ClampingOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char const * vtkPiecewiseFunction::GetType()
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_GetType::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_GetType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   this->_objectptr->GetObj()->GetType();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of double vtkPiecewiseFunction::GetFirstNonZeroValue()
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_GetFirstNonZeroValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_GetFirstNonZeroValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetFirstNonZeroValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::Initialize()
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_Initialize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_Initialize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Initialize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::SetAllowDuplicateScalars(int _arg)
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_SetAllowDuplicateScalars::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_SetAllowDuplicateScalars::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAllowDuplicateScalars(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPiecewiseFunction::GetAllowDuplicateScalars()
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_GetAllowDuplicateScalars::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_GetAllowDuplicateScalars::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAllowDuplicateScalars();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::AllowDuplicateScalarsOn()
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_AllowDuplicateScalarsOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_AllowDuplicateScalarsOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AllowDuplicateScalarsOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPiecewiseFunction::AllowDuplicateScalarsOff()
//---------------------------------------------------
void WrapClass_vtkPiecewiseFunction::
    wrap_AllowDuplicateScalarsOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPiecewiseFunction::
    wrap_AllowDuplicateScalarsOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AllowDuplicateScalarsOff();
  return BasicVariable::ptr();
}

