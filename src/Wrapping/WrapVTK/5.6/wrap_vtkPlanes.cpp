/**
 * C++ Interface: wrap_vtkPlanes
 *
 * Description: wrapping vtkPlanes
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

#include "wrap_vtkPlanes.h"

// get all the required includes
// #include "..."
#ifndef vtkPlanes_declared
  #define vtkPlanes_declared
  AMI_DECLARE_TYPE(vtkPlanes)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkPoints_declared
  #define vtkPoints_declared
  AMI_DECLARE_TYPE(vtkPoints)
#endif
#ifndef vtkDataArray_declared
  #define vtkDataArray_declared
  AMI_DECLARE_TYPE(vtkDataArray)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkPlanes>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkPlanes);
AMI_DEFINE_VARFROMSMTPTR(vtkPlanes);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkPlanes>::CreateVar( vtkPlanes* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkPlanes> obj_ptr(val,smartpointer_nodeleter<vtkPlanes>());
  return AMILabType<vtkPlanes>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkPlanes
//
Variable<AMIObject>::ptr WrapClass_vtkPlanes::CreateVar( vtkPlanes* sp)
{
  boost::shared_ptr<vtkPlanes> di_ptr(
    sp,
    wxwindow_nodeleter<vtkPlanes>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkPlanes>::CreateVar(
      new WrapClass_vtkPlanes(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkPlanes::AddMethods(WrapClass<vtkPlanes>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_EvaluateFunction_1( this_ptr);
  AddVar_EvaluateFunction( this_ptr);
  AddVar_EvaluateFunction_2( this_ptr);
  AddVar_EvaluateGradient( this_ptr);
  AddVar_SetPoints( this_ptr);
  AddVar_GetPoints( this_ptr);
  AddVar_SetNormals( this_ptr);
  AddVar_GetNormals( this_ptr);
  AddVar_SetFrustumPlanes( this_ptr);
  AddVar_SetBounds_1( this_ptr);
  AddVar_SetBounds( this_ptr);
  AddVar_SetBounds_2( this_ptr);
  AddVar_GetNumberOfPlanes( this_ptr);
/* The following types are missing: vtkPlane
  AddVar_GetPlane_1( this_ptr);
*/
  AddVar_GetPlane( this_ptr);
/* The following types are missing: vtkPlane
  AddVar_GetPlane_2( this_ptr);
*/



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent vtkImplicitFunction
  boost::shared_ptr<vtkImplicitFunction > parent_vtkImplicitFunction(  boost::dynamic_pointer_cast<vtkImplicitFunction >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkImplicitFunction = AMILabType<vtkImplicitFunction >::CreateVarFromSmtPtr(parent_vtkImplicitFunction);
  context->AddVar("vtkImplicitFunction",var_vtkImplicitFunction);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkImplicitFunction = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkImplicitFunction);
  context->AddDefault(obj_vtkImplicitFunction->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkPlanes_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkPlanes");
  
  // Static methods 
  WrapClass_vtkPlanes::AddVar_New(amiobject->GetContext());
  WrapClass_vtkPlanes::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkPlanes::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkPlanes * vtkPlanes::New()
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkPlanes";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPlanes * res =   vtkPlanes::New();
  BasicVariable::ptr res_var = AMILabType<vtkPlanes >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkPlanes::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkPlanes::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkPlanes * vtkPlanes::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkPlanes";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
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

  vtkPlanes * res =   vtkPlanes::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkPlanes >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkPlanes::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
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
//  Wrapping of vtkPlanes * vtkPlanes::NewInstance()
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkPlanes";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPlanes * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkPlanes >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkPlanes::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
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
//  Wrapping of double vtkPlanes::EvaluateFunction(double * x)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_EvaluateFunction_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_EvaluateFunction_1::CallMember( ParamList* _p)
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

  double res =   this->_objectptr->GetObj()->EvaluateFunction(x);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPlanes::EvaluateFunction(...)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_EvaluateFunction::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_EvaluateFunction::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPlanes::wrap_EvaluateFunction_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPlanes::wrap_EvaluateFunction_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double vtkPlanes::EvaluateFunction(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_EvaluateFunction_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_EvaluateFunction_2::CallMember( ParamList* _p)
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

  double res =   this->_objectptr->GetObj()->EvaluateFunction(x, y, z);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPlanes::EvaluateGradient(double * x, double * n)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_EvaluateGradient::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'n'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_EvaluateGradient::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  double* x;
  if (CheckNullVar(_p,_n))  {
    x=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > x_smtptr;
    if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    x = x_smtptr.get();
  }

  double* n;
  if (CheckNullVar(_p,_n))  {
    n=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > n_smtptr;
    if (!get_val_smtptr_param<double >(n_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    n = n_smtptr.get();
  }

  this->_objectptr->GetObj()->EvaluateGradient(x, n);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPlanes::SetPoints(vtkPoints * param0)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_SetPoints::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPoints, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_SetPoints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkPoints* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkPoints*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPoints > param0_smtptr;
    if (!get_val_smtptr_param<vtkPoints >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->SetPoints(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkPoints * vtkPlanes::GetPoints()
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_GetPoints::SetParametersComments()
{
  return_comments="returning a variable of type vtkPoints";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_GetPoints::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPoints * res =   this->_objectptr->GetObj()->GetPoints();
  BasicVariable::ptr res_var = AMILabType<vtkPoints >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkPlanes::SetNormals(vtkDataArray * normals)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_SetNormals::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'normals'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_SetNormals::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkDataArray* normals;
  if (CheckNullVar(_p,_n))  {
    normals=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > normals_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(normals_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    normals = normals_smtptr.get();
  }

  this->_objectptr->GetObj()->SetNormals(normals);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkDataArray * vtkPlanes::GetNormals()
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_GetNormals::SetParametersComments()
{
  return_comments="returning a variable of type vtkDataArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_GetNormals::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkDataArray * res =   this->_objectptr->GetObj()->GetNormals();
  BasicVariable::ptr res_var = AMILabType<vtkDataArray >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkPlanes::SetFrustumPlanes(double * planes)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_SetFrustumPlanes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'planes'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_SetFrustumPlanes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double* planes;
  if (CheckNullVar(_p,_n))  {
    planes=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > planes_smtptr;
    if (!get_val_smtptr_param<double >(planes_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    planes = planes_smtptr.get();
  }

  this->_objectptr->GetObj()->SetFrustumPlanes(planes);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPlanes::SetBounds(double * bounds)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_SetBounds_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_SetBounds_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetBounds(bounds);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPlanes::SetBounds(...)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_SetBounds::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_SetBounds::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPlanes::wrap_SetBounds_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPlanes::wrap_SetBounds_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkPlanes::SetBounds(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_SetBounds_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'xmin'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'xmax'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'ymin'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'ymax'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'zmin'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'zmax'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_SetBounds_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  double xmin;
  if (!get_val_param<double >(xmin,_p,_n,true,true)) ClassReturnEmptyVar;

  double xmax;
  if (!get_val_param<double >(xmax,_p,_n,true,true)) ClassReturnEmptyVar;

  double ymin;
  if (!get_val_param<double >(ymin,_p,_n,true,true)) ClassReturnEmptyVar;

  double ymax;
  if (!get_val_param<double >(ymax,_p,_n,true,true)) ClassReturnEmptyVar;

  double zmin;
  if (!get_val_param<double >(zmin,_p,_n,true,true)) ClassReturnEmptyVar;

  double zmax;
  if (!get_val_param<double >(zmax,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetBounds(xmin, xmax, ymin, ymax, zmin, zmax);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPlanes::GetNumberOfPlanes()
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_GetNumberOfPlanes::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_GetNumberOfPlanes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfPlanes();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: vtkPlane

//---------------------------------------------------
//  Wrapping of vtkPlane * vtkPlanes::GetPlane(int i)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_GetPlane_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  return_comments="returning a variable of type vtkPlane";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_GetPlane_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkPlane * res =   this->_objectptr->GetObj()->GetPlane(i);
  return AMILabType<vtkPlane >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPlanes::GetPlane(...)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_GetPlane::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_GetPlane::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkPlane

//---------------------------------------------------
//  Wrapping of void vtkPlanes::GetPlane(int i, vtkPlane * plane)
//---------------------------------------------------
void WrapClass_vtkPlanes::
    wrap_GetPlane_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( vtkPlane, "parameter named 'plane'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPlanes::
    wrap_GetPlane_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkPlane* plane;
  if (CheckNullVar(_p,_n))  {
    plane=(vtkPlane*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPlane > plane_smtptr;
    if (!get_val_smtptr_param<vtkPlane >(plane_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    plane = plane_smtptr.get();
  }

  this->_objectptr->GetObj()->GetPlane(i, plane);
  return BasicVariable::ptr();
}
*/

