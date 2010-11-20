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

// get all the required includes
// #include "..."
#include "wrap_vtkImplicitFunction.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_vtkImplicitFunction.h"

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
BasicVariable::ptr AMILabType<vtkImplicitFunction>::CreateVar( vtkImplicitFunction* val)
{ 
  boost::shared_ptr<vtkImplicitFunction> obj_ptr(val,wxwindow_nodeleter<vtkImplicitFunction>());
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
      AddVar_GetMTime( this_ptr);
      AddVar_FunctionValue_1( this_ptr);
      AddVar_FunctionValue( this_ptr);
      AddVar_FunctionValue_2( this_ptr);
      AddVar_FunctionGradient_1( this_ptr);
      AddVar_FunctionGradient( this_ptr);
      AddVar_FunctionGradient_2( this_ptr);
      AddVar_FunctionGradient_3( this_ptr);
/* The following types are missing: vtkAbstractTransform
      AddVar_SetTransform_1( this_ptr);
*/
      AddVar_SetTransform( this_ptr);
      AddVar_SetTransform_2( this_ptr);
/* The following types are missing: vtkAbstractTransform
      AddVar_GetTransform( this_ptr);
*/
      AddVar_EvaluateFunction( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkImplicitFunction::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkImplicitFunction::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkImplicitFunction * vtkImplicitFunction::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkImplicitFunction::
    wrap_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkImplicitFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImplicitFunction::
    wrap_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkImplicitFunction * res =   vtkImplicitFunction::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkImplicitFunction::CreateVar(res);
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
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n)) ClassHelpAndReturn;
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
  BasicVariable::ptr res_var = WrapClass_vtkImplicitFunction::CreateVar(res);
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
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!get_val_param<vtkIndent >(indent,_p,_n)) ClassHelpAndReturn;

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

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* x = x_smtptr.get();

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
  if (!get_val_param<double >(x,_p,_n)) ClassReturnEmptyVar;

  double y;
  if (!get_val_param<double >(y,_p,_n)) ClassReturnEmptyVar;

  double z;
  if (!get_val_param<double >(z,_p,_n)) ClassReturnEmptyVar;

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

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* x = x_smtptr.get();

  boost::shared_ptr<double > g_smtptr;
  if (!get_val_smtptr_param<double >(g_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* g = g_smtptr.get();

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

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* x = x_smtptr.get();

  double * res =   this->_objectptr->GetObj()->FunctionGradient(x);
  return AMILabType<double >::CreateVar(res);
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
  if (!get_val_param<double >(x,_p,_n)) ClassReturnEmptyVar;

  double y;
  if (!get_val_param<double >(y,_p,_n)) ClassReturnEmptyVar;

  double z;
  if (!get_val_param<double >(z,_p,_n)) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->FunctionGradient(x, y, z);
  return AMILabType<double >::CreateVar(res);
}
/* The following types are missing: vtkAbstractTransform

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

  boost::shared_ptr<vtkAbstractTransform > param0_smtptr;
  if (!get_val_smtptr_param<vtkAbstractTransform >(param0_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkAbstractTransform* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetTransform(param0);
  return BasicVariable::ptr();
}
*/

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

  boost::shared_ptr<double > elements_smtptr;
  if (!get_val_smtptr_param<double >(elements_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* elements = elements_smtptr.get();

  this->_objectptr->GetObj()->SetTransform(elements);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkAbstractTransform

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
  return AMILabType<vtkAbstractTransform >::CreateVar(res);
}
*/

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
  if (!get_val_param<double >(x,_p,_n)) ClassHelpAndReturn;

  double y;
  if (!get_val_param<double >(y,_p,_n)) ClassHelpAndReturn;

  double z;
  if (!get_val_param<double >(z,_p,_n)) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->EvaluateFunction(x, y, z);
  return AMILabType<double >::CreateVar(res);
}

