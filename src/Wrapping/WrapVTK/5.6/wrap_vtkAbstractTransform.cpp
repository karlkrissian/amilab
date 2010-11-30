/**
 * C++ Interface: wrap_vtkAbstractTransform
 *
 * Description: wrapping vtkAbstractTransform
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
#include "wrap_vtkAbstractTransform.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkPoints.h"
#include "wrap_vtkDataArray.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_vtkAbstractTransform.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkAbstractTransform>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkAbstractTransform);
AMI_DEFINE_VARFROMSMTPTR(vtkAbstractTransform);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkAbstractTransform>::CreateVar( vtkAbstractTransform* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkAbstractTransform> obj_ptr(val,smartpointer_nodeleter<vtkAbstractTransform>());
  return AMILabType<vtkAbstractTransform>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkAbstractTransform
//
Variable<AMIObject>::ptr WrapClass_vtkAbstractTransform::CreateVar( vtkAbstractTransform* sp)
{
  boost::shared_ptr<vtkAbstractTransform> di_ptr(
    sp,
    wxwindow_nodeleter<vtkAbstractTransform>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkAbstractTransform>::CreateVar(
      new WrapClass_vtkAbstractTransform(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkAbstractTransform::AddMethods(WrapClass<vtkAbstractTransform>::ptr this_ptr )
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
      AddVar_TransformPoint_1( this_ptr);
      AddVar_TransformPoint( this_ptr);
      AddVar_TransformPoint_2( this_ptr);
      AddVar_TransformPoint_3( this_ptr);
      AddVar_TransformPoint_4( this_ptr);
      AddVar_TransformFloatPoint_1( this_ptr);
      AddVar_TransformFloatPoint( this_ptr);
      AddVar_TransformFloatPoint_2( this_ptr);
      AddVar_TransformDoublePoint_1( this_ptr);
      AddVar_TransformDoublePoint( this_ptr);
      AddVar_TransformDoublePoint_2( this_ptr);
      AddVar_TransformNormalAtPoint_1( this_ptr);
      AddVar_TransformNormalAtPoint( this_ptr);
      AddVar_TransformNormalAtPoint_2( this_ptr);
      AddVar_TransformNormalAtPoint_3( this_ptr);
      AddVar_TransformDoubleNormalAtPoint( this_ptr);
      AddVar_TransformFloatNormalAtPoint( this_ptr);
      AddVar_TransformVectorAtPoint_1( this_ptr);
      AddVar_TransformVectorAtPoint( this_ptr);
      AddVar_TransformVectorAtPoint_2( this_ptr);
      AddVar_TransformVectorAtPoint_3( this_ptr);
      AddVar_TransformDoubleVectorAtPoint( this_ptr);
      AddVar_TransformFloatVectorAtPoint( this_ptr);
      AddVar_TransformPoints( this_ptr);
      AddVar_TransformPointsNormalsVectors( this_ptr);
      AddVar_GetInverse( this_ptr);
      AddVar_SetInverse( this_ptr);
      AddVar_DeepCopy( this_ptr);
      AddVar_Update( this_ptr);
      AddVar_CircuitCheck( this_ptr);
      AddVar_GetMTime( this_ptr);
      AddVar_UnRegister( this_ptr);
      AddVar_Identity( this_ptr);



  
};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkAbstractTransform::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkAbstractTransform");
  
  // Static methods 
  WrapClass_vtkAbstractTransform::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkAbstractTransform::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkAbstractTransform::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkAbstractTransform::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkAbstractTransform * vtkAbstractTransform::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkAbstractTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkAbstractTransform * res =   vtkAbstractTransform::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkAbstractTransform::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkAbstractTransform::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
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
//  Wrapping of vtkAbstractTransform * vtkAbstractTransform::NewInstance()
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkAbstractTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAbstractTransform * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkAbstractTransform::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkAbstractTransform::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
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
//  Wrapping of void vtkAbstractTransform::TransformPoint(float const * in, float * out)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<float > in_smtptr;
  if (!get_val_smtptr_param<float >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* in = in_smtptr.get();

  boost::shared_ptr<float > out_smtptr;
  if (!get_val_smtptr_param<float >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* out = out_smtptr.get();

  this->_objectptr->GetObj()->TransformPoint(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAbstractTransform::TransformPoint(...)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkAbstractTransform::wrap_TransformPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkAbstractTransform::wrap_TransformPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkAbstractTransform::wrap_TransformPoint_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_vtkAbstractTransform::wrap_TransformPoint_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractTransform::TransformPoint(double const * in, double * out)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > in_smtptr;
  if (!get_val_smtptr_param<double >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* in = in_smtptr.get();

  boost::shared_ptr<double > out_smtptr;
  if (!get_val_smtptr_param<double >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* out = out_smtptr.get();

  this->_objectptr->GetObj()->TransformPoint(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkAbstractTransform::TransformPoint(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformPoint_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformPoint_3::CallMember( ParamList* _p)
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

  double * res =   this->_objectptr->GetObj()->TransformPoint(x, y, z);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkAbstractTransform::TransformPoint(double const * point)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformPoint_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'point'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformPoint_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > point_smtptr;
  if (!get_val_smtptr_param<double >(point_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* point = point_smtptr.get();

  double * res =   this->_objectptr->GetObj()->TransformPoint(point);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of float * vtkAbstractTransform::TransformFloatPoint(float x, float y, float z)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformFloatPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'z'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformFloatPoint_1::CallMember( ParamList* _p)
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

  float * res =   this->_objectptr->GetObj()->TransformFloatPoint(x, y, z);
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAbstractTransform::TransformFloatPoint(...)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformFloatPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformFloatPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkAbstractTransform::wrap_TransformFloatPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkAbstractTransform::wrap_TransformFloatPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of float * vtkAbstractTransform::TransformFloatPoint(float const * point)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformFloatPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'point'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformFloatPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<float > point_smtptr;
  if (!get_val_smtptr_param<float >(point_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* point = point_smtptr.get();

  float * res =   this->_objectptr->GetObj()->TransformFloatPoint(point);
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkAbstractTransform::TransformDoublePoint(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformDoublePoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformDoublePoint_1::CallMember( ParamList* _p)
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

  double * res =   this->_objectptr->GetObj()->TransformDoublePoint(x, y, z);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAbstractTransform::TransformDoublePoint(...)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformDoublePoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformDoublePoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkAbstractTransform::wrap_TransformDoublePoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkAbstractTransform::wrap_TransformDoublePoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double * vtkAbstractTransform::TransformDoublePoint(double const * point)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformDoublePoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'point'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformDoublePoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > point_smtptr;
  if (!get_val_smtptr_param<double >(point_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* point = point_smtptr.get();

  double * res =   this->_objectptr->GetObj()->TransformDoublePoint(point);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractTransform::TransformNormalAtPoint(float const * point, float const * in, float * out)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformNormalAtPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'point'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformNormalAtPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<float > point_smtptr;
  if (!get_val_smtptr_param<float >(point_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* point = point_smtptr.get();

  boost::shared_ptr<float > in_smtptr;
  if (!get_val_smtptr_param<float >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* in = in_smtptr.get();

  boost::shared_ptr<float > out_smtptr;
  if (!get_val_smtptr_param<float >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* out = out_smtptr.get();

  this->_objectptr->GetObj()->TransformNormalAtPoint(point, in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAbstractTransform::TransformNormalAtPoint(...)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformNormalAtPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformNormalAtPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkAbstractTransform::wrap_TransformNormalAtPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkAbstractTransform::wrap_TransformNormalAtPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkAbstractTransform::wrap_TransformNormalAtPoint_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractTransform::TransformNormalAtPoint(double const * point, double const * in, double * out)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformNormalAtPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'point'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformNormalAtPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > point_smtptr;
  if (!get_val_smtptr_param<double >(point_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* point = point_smtptr.get();

  boost::shared_ptr<double > in_smtptr;
  if (!get_val_smtptr_param<double >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* in = in_smtptr.get();

  boost::shared_ptr<double > out_smtptr;
  if (!get_val_smtptr_param<double >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* out = out_smtptr.get();

  this->_objectptr->GetObj()->TransformNormalAtPoint(point, in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkAbstractTransform::TransformNormalAtPoint(double const * point, double const * normal)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformNormalAtPoint_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'point'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'normal'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformNormalAtPoint_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > point_smtptr;
  if (!get_val_smtptr_param<double >(point_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* point = point_smtptr.get();

  boost::shared_ptr<double > normal_smtptr;
  if (!get_val_smtptr_param<double >(normal_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* normal = normal_smtptr.get();

  double * res =   this->_objectptr->GetObj()->TransformNormalAtPoint(point, normal);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkAbstractTransform::TransformDoubleNormalAtPoint(double const * point, double const * normal)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformDoubleNormalAtPoint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'point'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'normal'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformDoubleNormalAtPoint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > point_smtptr;
  if (!get_val_smtptr_param<double >(point_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* point = point_smtptr.get();

  boost::shared_ptr<double > normal_smtptr;
  if (!get_val_smtptr_param<double >(normal_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* normal = normal_smtptr.get();

  double * res =   this->_objectptr->GetObj()->TransformDoubleNormalAtPoint(point, normal);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of float * vtkAbstractTransform::TransformFloatNormalAtPoint(float const * point, float const * normal)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformFloatNormalAtPoint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'point'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'normal'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformFloatNormalAtPoint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<float > point_smtptr;
  if (!get_val_smtptr_param<float >(point_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  float* point = point_smtptr.get();

  boost::shared_ptr<float > normal_smtptr;
  if (!get_val_smtptr_param<float >(normal_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  float* normal = normal_smtptr.get();

  float * res =   this->_objectptr->GetObj()->TransformFloatNormalAtPoint(point, normal);
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractTransform::TransformVectorAtPoint(float const * point, float const * in, float * out)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformVectorAtPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'point'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformVectorAtPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<float > point_smtptr;
  if (!get_val_smtptr_param<float >(point_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* point = point_smtptr.get();

  boost::shared_ptr<float > in_smtptr;
  if (!get_val_smtptr_param<float >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* in = in_smtptr.get();

  boost::shared_ptr<float > out_smtptr;
  if (!get_val_smtptr_param<float >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* out = out_smtptr.get();

  this->_objectptr->GetObj()->TransformVectorAtPoint(point, in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAbstractTransform::TransformVectorAtPoint(...)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformVectorAtPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformVectorAtPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkAbstractTransform::wrap_TransformVectorAtPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkAbstractTransform::wrap_TransformVectorAtPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkAbstractTransform::wrap_TransformVectorAtPoint_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractTransform::TransformVectorAtPoint(double const * point, double const * in, double * out)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformVectorAtPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'point'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformVectorAtPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > point_smtptr;
  if (!get_val_smtptr_param<double >(point_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* point = point_smtptr.get();

  boost::shared_ptr<double > in_smtptr;
  if (!get_val_smtptr_param<double >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* in = in_smtptr.get();

  boost::shared_ptr<double > out_smtptr;
  if (!get_val_smtptr_param<double >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* out = out_smtptr.get();

  this->_objectptr->GetObj()->TransformVectorAtPoint(point, in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkAbstractTransform::TransformVectorAtPoint(double const * point, double const * vector)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformVectorAtPoint_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'point'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'vector'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformVectorAtPoint_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > point_smtptr;
  if (!get_val_smtptr_param<double >(point_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* point = point_smtptr.get();

  boost::shared_ptr<double > vector_smtptr;
  if (!get_val_smtptr_param<double >(vector_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* vector = vector_smtptr.get();

  double * res =   this->_objectptr->GetObj()->TransformVectorAtPoint(point, vector);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkAbstractTransform::TransformDoubleVectorAtPoint(double const * point, double const * vector)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformDoubleVectorAtPoint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'point'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'vector'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformDoubleVectorAtPoint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > point_smtptr;
  if (!get_val_smtptr_param<double >(point_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* point = point_smtptr.get();

  boost::shared_ptr<double > vector_smtptr;
  if (!get_val_smtptr_param<double >(vector_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* vector = vector_smtptr.get();

  double * res =   this->_objectptr->GetObj()->TransformDoubleVectorAtPoint(point, vector);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of float * vtkAbstractTransform::TransformFloatVectorAtPoint(float const * point, float const * vector)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformFloatVectorAtPoint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'point'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'vector'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformFloatVectorAtPoint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<float > point_smtptr;
  if (!get_val_smtptr_param<float >(point_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  float* point = point_smtptr.get();

  boost::shared_ptr<float > vector_smtptr;
  if (!get_val_smtptr_param<float >(vector_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  float* vector = vector_smtptr.get();

  float * res =   this->_objectptr->GetObj()->TransformFloatVectorAtPoint(point, vector);
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractTransform::TransformPoints(vtkPoints * inPts, vtkPoints * outPts)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_TransformPoints::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPoints, "parameter named 'inPts'")
  ADDPARAMCOMMENT_TYPE( vtkPoints, "parameter named 'outPts'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformPoints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkPoints > inPts_smtptr;
  if (!get_val_smtptr_param<vtkPoints >(inPts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkPoints* inPts = inPts_smtptr.get();

  boost::shared_ptr<vtkPoints > outPts_smtptr;
  if (!get_val_smtptr_param<vtkPoints >(outPts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkPoints* outPts = outPts_smtptr.get();

  this->_objectptr->GetObj()->TransformPoints(inPts, outPts);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractTransform::TransformPointsNormalsVectors(vtkPoints * inPts, vtkPoints * outPts, vtkDataArray * inNms, vtkDataArray * outNms, vtkDataArray * inVrs, vtkDataArray * outVrs)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
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
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_TransformPointsNormalsVectors::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkPoints > inPts_smtptr;
  if (!get_val_smtptr_param<vtkPoints >(inPts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkPoints* inPts = inPts_smtptr.get();

  boost::shared_ptr<vtkPoints > outPts_smtptr;
  if (!get_val_smtptr_param<vtkPoints >(outPts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkPoints* outPts = outPts_smtptr.get();

  boost::shared_ptr<vtkDataArray > inNms_smtptr;
  if (!get_val_smtptr_param<vtkDataArray >(inNms_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataArray* inNms = inNms_smtptr.get();

  boost::shared_ptr<vtkDataArray > outNms_smtptr;
  if (!get_val_smtptr_param<vtkDataArray >(outNms_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataArray* outNms = outNms_smtptr.get();

  boost::shared_ptr<vtkDataArray > inVrs_smtptr;
  if (!get_val_smtptr_param<vtkDataArray >(inVrs_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataArray* inVrs = inVrs_smtptr.get();

  boost::shared_ptr<vtkDataArray > outVrs_smtptr;
  if (!get_val_smtptr_param<vtkDataArray >(outVrs_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataArray* outVrs = outVrs_smtptr.get();

  this->_objectptr->GetObj()->TransformPointsNormalsVectors(inPts, outPts, inNms, outNms, inVrs, outVrs);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkAbstractTransform * vtkAbstractTransform::GetInverse()
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_GetInverse::SetParametersComments()
{
  return_comments="returning a variable of type vtkAbstractTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_GetInverse::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAbstractTransform * res =   this->_objectptr->GetObj()->GetInverse();
  BasicVariable::ptr res_var = WrapClass_vtkAbstractTransform::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractTransform::SetInverse(vtkAbstractTransform * transform)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_SetInverse::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAbstractTransform, "parameter named 'transform'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_SetInverse::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkAbstractTransform > transform_smtptr;
  if (!get_val_smtptr_param<vtkAbstractTransform >(transform_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkAbstractTransform* transform = transform_smtptr.get();

  this->_objectptr->GetObj()->SetInverse(transform);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractTransform::DeepCopy(vtkAbstractTransform * param0)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_DeepCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAbstractTransform, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_DeepCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkAbstractTransform > param0_smtptr;
  if (!get_val_smtptr_param<vtkAbstractTransform >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkAbstractTransform* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->DeepCopy(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractTransform::Update()
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_Update::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_Update::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Update();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkAbstractTransform::CircuitCheck(vtkAbstractTransform * transform)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_CircuitCheck::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAbstractTransform, "parameter named 'transform'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_CircuitCheck::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkAbstractTransform > transform_smtptr;
  if (!get_val_smtptr_param<vtkAbstractTransform >(transform_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkAbstractTransform* transform = transform_smtptr.get();

  int res =   this->_objectptr->GetObj()->CircuitCheck(transform);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkAbstractTransform::GetMTime()
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_GetMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_GetMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractTransform::UnRegister(vtkObjectBase * O)
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_UnRegister::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'O'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_UnRegister::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > O_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(O_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* O = O_smtptr.get();

  this->_objectptr->GetObj()->UnRegister(O);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractTransform::Identity()
//---------------------------------------------------
void WrapClass_vtkAbstractTransform::
    wrap_Identity::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractTransform::
    wrap_Identity::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Identity();
  return BasicVariable::ptr();
}

