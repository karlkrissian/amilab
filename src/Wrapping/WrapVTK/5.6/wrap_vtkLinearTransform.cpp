/**
 * C++ Interface: wrap_vtkLinearTransform
 *
 * Description: wrapping vtkLinearTransform
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

#include "wrap_vtkLinearTransform.h"

// get all the required includes
// #include "..."
#ifndef vtkLinearTransform_declared
  #define vtkLinearTransform_declared
  AMI_DECLARE_TYPE(vtkLinearTransform)
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
BasicVariable::ptr WrapClass<vtkLinearTransform>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkLinearTransform);
AMI_DEFINE_VARFROMSMTPTR(vtkLinearTransform);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkLinearTransform>::CreateVar( vtkLinearTransform* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkLinearTransform> obj_ptr(val,smartpointer_nodeleter<vtkLinearTransform>());
  return AMILabType<vtkLinearTransform>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkLinearTransform
//
Variable<AMIObject>::ptr WrapClass_vtkLinearTransform::CreateVar( vtkLinearTransform* sp)
{
  boost::shared_ptr<vtkLinearTransform> di_ptr(
    sp,
    wxwindow_nodeleter<vtkLinearTransform>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkLinearTransform>::CreateVar(
      new WrapClass_vtkLinearTransform(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkLinearTransform::AddMethods(WrapClass<vtkLinearTransform>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_TransformNormal_1( this_ptr);
  AddVar_TransformNormal( this_ptr);
  AddVar_TransformNormal_2( this_ptr);
  AddVar_TransformNormal_3( this_ptr);
  AddVar_TransformNormal_4( this_ptr);
  AddVar_TransformFloatNormal_1( this_ptr);
  AddVar_TransformFloatNormal( this_ptr);
  AddVar_TransformFloatNormal_2( this_ptr);
  AddVar_TransformDoubleNormal_1( this_ptr);
  AddVar_TransformDoubleNormal( this_ptr);
  AddVar_TransformDoubleNormal_2( this_ptr);
  AddVar_TransformVector_1( this_ptr);
  AddVar_TransformVector( this_ptr);
  AddVar_TransformVector_2( this_ptr);
  AddVar_TransformVector_3( this_ptr);
  AddVar_TransformVector_4( this_ptr);
  AddVar_TransformFloatVector_1( this_ptr);
  AddVar_TransformFloatVector( this_ptr);
  AddVar_TransformFloatVector_2( this_ptr);
  AddVar_TransformDoubleVector_1( this_ptr);
  AddVar_TransformDoubleVector( this_ptr);
  AddVar_TransformDoubleVector_2( this_ptr);
  AddVar_TransformPoints( this_ptr);
  AddVar_TransformNormals( this_ptr);
  AddVar_TransformVectors( this_ptr);
  AddVar_TransformPointsNormalsVectors( this_ptr);
  AddVar_GetLinearInverse( this_ptr);
  AddVar_InternalTransformPoint_1( this_ptr);
  AddVar_InternalTransformPoint( this_ptr);
  AddVar_InternalTransformPoint_2( this_ptr);
  AddVar_InternalTransformNormal_1( this_ptr);
  AddVar_InternalTransformNormal( this_ptr);
  AddVar_InternalTransformNormal_2( this_ptr);
  AddVar_InternalTransformVector_1( this_ptr);
  AddVar_InternalTransformVector( this_ptr);
  AddVar_InternalTransformVector_2( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent vtkHomogeneousTransform
  boost::shared_ptr<vtkHomogeneousTransform > parent_vtkHomogeneousTransform(  boost::dynamic_pointer_cast<vtkHomogeneousTransform >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkHomogeneousTransform = AMILabType<vtkHomogeneousTransform >::CreateVarFromSmtPtr(parent_vtkHomogeneousTransform);
  context->AddVar("vtkHomogeneousTransform",var_vtkHomogeneousTransform);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkHomogeneousTransform = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkHomogeneousTransform);
  context->AddDefault(obj_vtkHomogeneousTransform->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkLinearTransform_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkLinearTransform");
  
  // Static methods 
  WrapClass_vtkLinearTransform::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkLinearTransform::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkLinearTransform::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkLinearTransform::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkLinearTransform * vtkLinearTransform::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkLinearTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
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

  vtkLinearTransform * res =   vtkLinearTransform::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkLinearTransform >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkLinearTransform::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
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
//  Wrapping of vtkLinearTransform * vtkLinearTransform::NewInstance()
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkLinearTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkLinearTransform * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkLinearTransform >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkLinearTransform::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
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
//  Wrapping of void vtkLinearTransform::TransformNormal(float const * in, float * out)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformNormal_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformNormal_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  float* in;
  if (CheckNullVar(_p,_n))  {
    in=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > in_smtptr;
    if (!get_val_smtptr_param<float >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    in = in_smtptr.get();
  }

  float* out;
  if (CheckNullVar(_p,_n))  {
    out=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > out_smtptr;
    if (!get_val_smtptr_param<float >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    out = out_smtptr.get();
  }

  this->_objectptr->GetObj()->TransformNormal(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkLinearTransform::TransformNormal(...)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformNormal::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformNormal::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkLinearTransform::wrap_TransformNormal_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkLinearTransform::wrap_TransformNormal_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkLinearTransform::wrap_TransformNormal_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_vtkLinearTransform::wrap_TransformNormal_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkLinearTransform::TransformNormal(double const * in, double * out)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformNormal_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformNormal_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double* in;
  if (CheckNullVar(_p,_n))  {
    in=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > in_smtptr;
    if (!get_val_smtptr_param<double >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    in = in_smtptr.get();
  }

  double* out;
  if (CheckNullVar(_p,_n))  {
    out=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > out_smtptr;
    if (!get_val_smtptr_param<double >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    out = out_smtptr.get();
  }

  this->_objectptr->GetObj()->TransformNormal(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkLinearTransform::TransformNormal(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformNormal_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformNormal_3::CallMember( ParamList* _p)
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

  double * res =   this->_objectptr->GetObj()->TransformNormal(x, y, z);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkLinearTransform::TransformNormal(double const * normal)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformNormal_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'normal'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformNormal_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* normal;
  if (CheckNullVar(_p,_n))  {
    normal=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > normal_smtptr;
    if (!get_val_smtptr_param<double >(normal_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    normal = normal_smtptr.get();
  }

  double * res =   this->_objectptr->GetObj()->TransformNormal(normal);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of float * vtkLinearTransform::TransformFloatNormal(float x, float y, float z)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformFloatNormal_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'z'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformFloatNormal_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  float x;
  if (!get_val_param<float >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  float y;
  if (!get_val_param<float >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  float z;
  if (!get_val_param<float >(z,_p,_n,true,true)) ClassReturnEmptyVar;

  float * res =   this->_objectptr->GetObj()->TransformFloatNormal(x, y, z);
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkLinearTransform::TransformFloatNormal(...)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformFloatNormal::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformFloatNormal::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkLinearTransform::wrap_TransformFloatNormal_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkLinearTransform::wrap_TransformFloatNormal_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of float * vtkLinearTransform::TransformFloatNormal(float const * normal)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformFloatNormal_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'normal'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformFloatNormal_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  float* normal;
  if (CheckNullVar(_p,_n))  {
    normal=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > normal_smtptr;
    if (!get_val_smtptr_param<float >(normal_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    normal = normal_smtptr.get();
  }

  float * res =   this->_objectptr->GetObj()->TransformFloatNormal(normal);
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkLinearTransform::TransformDoubleNormal(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformDoubleNormal_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformDoubleNormal_1::CallMember( ParamList* _p)
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

  double * res =   this->_objectptr->GetObj()->TransformDoubleNormal(x, y, z);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkLinearTransform::TransformDoubleNormal(...)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformDoubleNormal::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformDoubleNormal::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkLinearTransform::wrap_TransformDoubleNormal_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkLinearTransform::wrap_TransformDoubleNormal_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double * vtkLinearTransform::TransformDoubleNormal(double const * normal)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformDoubleNormal_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'normal'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformDoubleNormal_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* normal;
  if (CheckNullVar(_p,_n))  {
    normal=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > normal_smtptr;
    if (!get_val_smtptr_param<double >(normal_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    normal = normal_smtptr.get();
  }

  double * res =   this->_objectptr->GetObj()->TransformDoubleNormal(normal);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkLinearTransform::TransformVector(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformVector_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformVector_1::CallMember( ParamList* _p)
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

  double * res =   this->_objectptr->GetObj()->TransformVector(x, y, z);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkLinearTransform::TransformVector(...)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformVector::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformVector::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkLinearTransform::wrap_TransformVector_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkLinearTransform::wrap_TransformVector_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkLinearTransform::wrap_TransformVector_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_vtkLinearTransform::wrap_TransformVector_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double * vtkLinearTransform::TransformVector(double const * normal)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformVector_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'normal'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformVector_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* normal;
  if (CheckNullVar(_p,_n))  {
    normal=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > normal_smtptr;
    if (!get_val_smtptr_param<double >(normal_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    normal = normal_smtptr.get();
  }

  double * res =   this->_objectptr->GetObj()->TransformVector(normal);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkLinearTransform::TransformVector(float const * in, float * out)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformVector_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformVector_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  float* in;
  if (CheckNullVar(_p,_n))  {
    in=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > in_smtptr;
    if (!get_val_smtptr_param<float >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    in = in_smtptr.get();
  }

  float* out;
  if (CheckNullVar(_p,_n))  {
    out=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > out_smtptr;
    if (!get_val_smtptr_param<float >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    out = out_smtptr.get();
  }

  this->_objectptr->GetObj()->TransformVector(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkLinearTransform::TransformVector(double const * in, double * out)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformVector_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformVector_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double* in;
  if (CheckNullVar(_p,_n))  {
    in=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > in_smtptr;
    if (!get_val_smtptr_param<double >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    in = in_smtptr.get();
  }

  double* out;
  if (CheckNullVar(_p,_n))  {
    out=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > out_smtptr;
    if (!get_val_smtptr_param<double >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    out = out_smtptr.get();
  }

  this->_objectptr->GetObj()->TransformVector(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float * vtkLinearTransform::TransformFloatVector(float x, float y, float z)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformFloatVector_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'z'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformFloatVector_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  float x;
  if (!get_val_param<float >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  float y;
  if (!get_val_param<float >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  float z;
  if (!get_val_param<float >(z,_p,_n,true,true)) ClassReturnEmptyVar;

  float * res =   this->_objectptr->GetObj()->TransformFloatVector(x, y, z);
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkLinearTransform::TransformFloatVector(...)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformFloatVector::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformFloatVector::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkLinearTransform::wrap_TransformFloatVector_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkLinearTransform::wrap_TransformFloatVector_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of float * vtkLinearTransform::TransformFloatVector(float const * vec)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformFloatVector_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'vec'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformFloatVector_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  float* vec;
  if (CheckNullVar(_p,_n))  {
    vec=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > vec_smtptr;
    if (!get_val_smtptr_param<float >(vec_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    vec = vec_smtptr.get();
  }

  float * res =   this->_objectptr->GetObj()->TransformFloatVector(vec);
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkLinearTransform::TransformDoubleVector(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformDoubleVector_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformDoubleVector_1::CallMember( ParamList* _p)
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

  double * res =   this->_objectptr->GetObj()->TransformDoubleVector(x, y, z);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkLinearTransform::TransformDoubleVector(...)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformDoubleVector::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformDoubleVector::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkLinearTransform::wrap_TransformDoubleVector_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkLinearTransform::wrap_TransformDoubleVector_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double * vtkLinearTransform::TransformDoubleVector(double const * vec)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformDoubleVector_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'vec'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformDoubleVector_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* vec;
  if (CheckNullVar(_p,_n))  {
    vec=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > vec_smtptr;
    if (!get_val_smtptr_param<double >(vec_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    vec = vec_smtptr.get();
  }

  double * res =   this->_objectptr->GetObj()->TransformDoubleVector(vec);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkLinearTransform::TransformPoints(vtkPoints * inPts, vtkPoints * outPts)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformPoints::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPoints, "parameter named 'inPts'")
  ADDPARAMCOMMENT_TYPE( vtkPoints, "parameter named 'outPts'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformPoints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkPoints* inPts;
  if (CheckNullVar(_p,_n))  {
    inPts=(vtkPoints*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPoints > inPts_smtptr;
    if (!get_val_smtptr_param<vtkPoints >(inPts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    inPts = inPts_smtptr.get();
  }

  vtkPoints* outPts;
  if (CheckNullVar(_p,_n))  {
    outPts=(vtkPoints*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPoints > outPts_smtptr;
    if (!get_val_smtptr_param<vtkPoints >(outPts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    outPts = outPts_smtptr.get();
  }

  this->_objectptr->GetObj()->TransformPoints(inPts, outPts);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkLinearTransform::TransformNormals(vtkDataArray * inNms, vtkDataArray * outNms)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformNormals::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'inNms'")
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'outNms'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformNormals::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkDataArray* inNms;
  if (CheckNullVar(_p,_n))  {
    inNms=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > inNms_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(inNms_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    inNms = inNms_smtptr.get();
  }

  vtkDataArray* outNms;
  if (CheckNullVar(_p,_n))  {
    outNms=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > outNms_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(outNms_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    outNms = outNms_smtptr.get();
  }

  this->_objectptr->GetObj()->TransformNormals(inNms, outNms);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkLinearTransform::TransformVectors(vtkDataArray * inVrs, vtkDataArray * outVrs)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformVectors::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'inVrs'")
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'outVrs'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformVectors::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkDataArray* inVrs;
  if (CheckNullVar(_p,_n))  {
    inVrs=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > inVrs_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(inVrs_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    inVrs = inVrs_smtptr.get();
  }

  vtkDataArray* outVrs;
  if (CheckNullVar(_p,_n))  {
    outVrs=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > outVrs_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(outVrs_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    outVrs = outVrs_smtptr.get();
  }

  this->_objectptr->GetObj()->TransformVectors(inVrs, outVrs);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkLinearTransform::TransformPointsNormalsVectors(vtkPoints * inPts, vtkPoints * outPts, vtkDataArray * inNms, vtkDataArray * outNms, vtkDataArray * inVrs, vtkDataArray * outVrs)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_TransformPointsNormalsVectors::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPoints, "parameter named 'inPts'")
  ADDPARAMCOMMENT_TYPE( vtkPoints, "parameter named 'outPts'")
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'inNms'")
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'outNms'")
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'inVrs'")
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'outVrs'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_TransformPointsNormalsVectors::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  vtkPoints* inPts;
  if (CheckNullVar(_p,_n))  {
    inPts=(vtkPoints*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPoints > inPts_smtptr;
    if (!get_val_smtptr_param<vtkPoints >(inPts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    inPts = inPts_smtptr.get();
  }

  vtkPoints* outPts;
  if (CheckNullVar(_p,_n))  {
    outPts=(vtkPoints*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPoints > outPts_smtptr;
    if (!get_val_smtptr_param<vtkPoints >(outPts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    outPts = outPts_smtptr.get();
  }

  vtkDataArray* inNms;
  if (CheckNullVar(_p,_n))  {
    inNms=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > inNms_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(inNms_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    inNms = inNms_smtptr.get();
  }

  vtkDataArray* outNms;
  if (CheckNullVar(_p,_n))  {
    outNms=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > outNms_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(outNms_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    outNms = outNms_smtptr.get();
  }

  vtkDataArray* inVrs;
  if (CheckNullVar(_p,_n))  {
    inVrs=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > inVrs_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(inVrs_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    inVrs = inVrs_smtptr.get();
  }

  vtkDataArray* outVrs;
  if (CheckNullVar(_p,_n))  {
    outVrs=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > outVrs_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(outVrs_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    outVrs = outVrs_smtptr.get();
  }

  this->_objectptr->GetObj()->TransformPointsNormalsVectors(inPts, outPts, inNms, outNms, inVrs, outVrs);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkLinearTransform * vtkLinearTransform::GetLinearInverse()
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_GetLinearInverse::SetParametersComments()
{
  return_comments="returning a variable of type vtkLinearTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_GetLinearInverse::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkLinearTransform * res =   this->_objectptr->GetObj()->GetLinearInverse();
  BasicVariable::ptr res_var = AMILabType<vtkLinearTransform >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkLinearTransform::InternalTransformPoint(float const * in, float * out)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_InternalTransformPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_InternalTransformPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  float* in;
  if (CheckNullVar(_p,_n))  {
    in=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > in_smtptr;
    if (!get_val_smtptr_param<float >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    in = in_smtptr.get();
  }

  float* out;
  if (CheckNullVar(_p,_n))  {
    out=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > out_smtptr;
    if (!get_val_smtptr_param<float >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    out = out_smtptr.get();
  }

  this->_objectptr->GetObj()->InternalTransformPoint(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkLinearTransform::InternalTransformPoint(...)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_InternalTransformPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_InternalTransformPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkLinearTransform::wrap_InternalTransformPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkLinearTransform::wrap_InternalTransformPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkLinearTransform::InternalTransformPoint(double const * in, double * out)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_InternalTransformPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_InternalTransformPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double* in;
  if (CheckNullVar(_p,_n))  {
    in=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > in_smtptr;
    if (!get_val_smtptr_param<double >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    in = in_smtptr.get();
  }

  double* out;
  if (CheckNullVar(_p,_n))  {
    out=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > out_smtptr;
    if (!get_val_smtptr_param<double >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    out = out_smtptr.get();
  }

  this->_objectptr->GetObj()->InternalTransformPoint(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkLinearTransform::InternalTransformNormal(float const * in, float * out)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_InternalTransformNormal_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_InternalTransformNormal_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  float* in;
  if (CheckNullVar(_p,_n))  {
    in=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > in_smtptr;
    if (!get_val_smtptr_param<float >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    in = in_smtptr.get();
  }

  float* out;
  if (CheckNullVar(_p,_n))  {
    out=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > out_smtptr;
    if (!get_val_smtptr_param<float >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    out = out_smtptr.get();
  }

  this->_objectptr->GetObj()->InternalTransformNormal(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkLinearTransform::InternalTransformNormal(...)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_InternalTransformNormal::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_InternalTransformNormal::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkLinearTransform::wrap_InternalTransformNormal_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkLinearTransform::wrap_InternalTransformNormal_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkLinearTransform::InternalTransformNormal(double const * in, double * out)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_InternalTransformNormal_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_InternalTransformNormal_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double* in;
  if (CheckNullVar(_p,_n))  {
    in=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > in_smtptr;
    if (!get_val_smtptr_param<double >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    in = in_smtptr.get();
  }

  double* out;
  if (CheckNullVar(_p,_n))  {
    out=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > out_smtptr;
    if (!get_val_smtptr_param<double >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    out = out_smtptr.get();
  }

  this->_objectptr->GetObj()->InternalTransformNormal(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkLinearTransform::InternalTransformVector(float const * in, float * out)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_InternalTransformVector_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_InternalTransformVector_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  float* in;
  if (CheckNullVar(_p,_n))  {
    in=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > in_smtptr;
    if (!get_val_smtptr_param<float >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    in = in_smtptr.get();
  }

  float* out;
  if (CheckNullVar(_p,_n))  {
    out=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > out_smtptr;
    if (!get_val_smtptr_param<float >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    out = out_smtptr.get();
  }

  this->_objectptr->GetObj()->InternalTransformVector(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkLinearTransform::InternalTransformVector(...)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_InternalTransformVector::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_InternalTransformVector::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkLinearTransform::wrap_InternalTransformVector_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkLinearTransform::wrap_InternalTransformVector_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkLinearTransform::InternalTransformVector(double const * in, double * out)
//---------------------------------------------------
void WrapClass_vtkLinearTransform::
    wrap_InternalTransformVector_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLinearTransform::
    wrap_InternalTransformVector_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double* in;
  if (CheckNullVar(_p,_n))  {
    in=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > in_smtptr;
    if (!get_val_smtptr_param<double >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    in = in_smtptr.get();
  }

  double* out;
  if (CheckNullVar(_p,_n))  {
    out=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > out_smtptr;
    if (!get_val_smtptr_param<double >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    out = out_smtptr.get();
  }

  this->_objectptr->GetObj()->InternalTransformVector(in, out);
  return BasicVariable::ptr();
}

