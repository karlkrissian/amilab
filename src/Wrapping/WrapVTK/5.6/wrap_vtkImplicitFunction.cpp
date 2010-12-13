/**
 * C++ Interface: wrap_vtkImplicitFunction
 *
 * Description: wrapping vtkImplicitFunction
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

#include "wrap_vtkImplicitFunction.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef vtkImplicitFunction_declared
  #define vtkImplicitFunction_declared
  AMI_DECLARE_TYPE(vtkImplicitFunction)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkAbstractTransform_declared
  #define vtkAbstractTransform_declared
  AMI_DECLARE_TYPE(vtkAbstractTransform)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkImplicitFunction>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkImplicitFunction);
AMI_DEFINE_VARFROMSMTPTR(vtkImplicitFunction);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkImplicitFunction>::CreateVar( vtkImplicitFunction* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkImplicitFunction> obj_ptr(val,smartpointer_nodeleter<vtkImplicitFunction>());
  return AMILabType<vtkImplicitFunction>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkImplicitFunction
//
Variable<AMIObject>::ptr WrapClass_vtkImplicitFunction::CreateVar( vtkImplicitFunction* sp)
{
  boost::shared_ptr<vtkImplicitFunction> di_ptr(
    sp,
    wxwindow_nodeleter<vtkImplicitFunction>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkImplicitFunction>::CreateVar(
      new WrapClass_vtkImplicitFunction(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkImplicitFunction::AddMethods(WrapClass<vtkImplicitFunction>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_GetMTime( this_ptr);
  AddVar_FunctionValue_1( this_ptr);
  AddVar_FunctionValue( this_ptr);
  AddVar_FunctionValue_2( this_ptr);
  AddVar_FunctionGradient_1( this_ptr);
  AddVar_FunctionGradient( this_ptr);
  AddVar_FunctionGradient_2( this_ptr);
  AddVar_FunctionGradient_3( this_ptr);
  AddVar_SetTransform_1( this_ptr);
  AddVar_SetTransform( this_ptr);
  AddVar_SetTransform_2( this_ptr);
  AddVar_GetTransform( this_ptr);
  AddVar_EvaluateFunction( this_ptr);



  

  


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
void WrapClassvtkImplicitFunction_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkImplicitFunction");
  
  // Static methods 
  WrapClass_vtkImplicitFunction::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkImplicitFunction::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkImplicitFunction::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkImplicitFunction::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkImplicitFunction * vtkImplicitFunction::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkImplicitFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
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

  vtkImplicitFunction * res =   vtkImplicitFunction::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkImplicitFunction >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkImplicitFunction::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
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
//  Wrapping of vtkImplicitFunction * vtkImplicitFunction::NewInstance()
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkImplicitFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkImplicitFunction * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkImplicitFunction >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkImplicitFunction::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
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
//  Wrapping of long unsigned int vtkImplicitFunction::GetMTime()
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_GetMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_GetMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of double vtkImplicitFunction::FunctionValue(double const * x)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_FunctionValue_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_FunctionValue_1::CallMember( ParamList* _p)
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

  double res =   this->_objectptr->GetObj()->FunctionValue(x);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImplicitFunction::FunctionValue(...)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_FunctionValue::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_FunctionValue::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImplicitFunction::wrap_FunctionValue_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImplicitFunction::wrap_FunctionValue_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double vtkImplicitFunction::FunctionValue(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_FunctionValue_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_FunctionValue_2::CallMember( ParamList* _p)
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

  double res =   this->_objectptr->GetObj()->FunctionValue(x, y, z);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkImplicitFunction::FunctionGradient(double const * x, double * g)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_FunctionGradient_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'g'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_FunctionGradient_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
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

  double* g;
  if (CheckNullVar(_p,_n))  {
    g=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > g_smtptr;
    if (!get_val_smtptr_param<double >(g_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    g = g_smtptr.get();
  }

  this->_objectptr->GetObj()->FunctionGradient(x, g);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImplicitFunction::FunctionGradient(...)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_FunctionGradient::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_FunctionGradient::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImplicitFunction::wrap_FunctionGradient_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImplicitFunction::wrap_FunctionGradient_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkImplicitFunction::wrap_FunctionGradient_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double * vtkImplicitFunction::FunctionGradient(double const * x)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_FunctionGradient_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_FunctionGradient_2::CallMember( ParamList* _p)
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

  double * res =   this->_objectptr->GetObj()->FunctionGradient(x);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkImplicitFunction::FunctionGradient(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_FunctionGradient_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_FunctionGradient_3::CallMember( ParamList* _p)
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

  double * res =   this->_objectptr->GetObj()->FunctionGradient(x, y, z);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkImplicitFunction::SetTransform(vtkAbstractTransform * param0)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_SetTransform_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAbstractTransform, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_SetTransform_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkAbstractTransform* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkAbstractTransform*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkAbstractTransform > param0_smtptr;
    if (!get_val_smtptr_param<vtkAbstractTransform >(param0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->SetTransform(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImplicitFunction::SetTransform(...)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_SetTransform::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_SetTransform::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImplicitFunction::wrap_SetTransform_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImplicitFunction::wrap_SetTransform_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkImplicitFunction::SetTransform(double * elements)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_SetTransform_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'elements'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_SetTransform_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* elements;
  if (CheckNullVar(_p,_n))  {
    elements=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > elements_smtptr;
    if (!get_val_smtptr_param<double >(elements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    elements = elements_smtptr.get();
  }

  this->_objectptr->GetObj()->SetTransform(elements);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkAbstractTransform * vtkImplicitFunction::GetTransform()
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_GetTransform::SetParametersComments()
{
  return_comments="returning a variable of type vtkAbstractTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_GetTransform::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAbstractTransform * res =   this->_objectptr->GetObj()->GetTransform();
  BasicVariable::ptr res_var = AMILabType<vtkAbstractTransform >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of double vtkImplicitFunction::EvaluateFunction(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_EvaluateFunction::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_EvaluateFunction::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,false)) ClassHelpAndReturn;

  double y;
  if (!get_val_param<double >(y,_p,_n,true,false)) ClassHelpAndReturn;

  double z;
  if (!get_val_param<double >(z,_p,_n,true,false)) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->EvaluateFunction(x, y, z);
  return AMILabType<double >::CreateVar(res);
}

