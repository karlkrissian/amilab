/**
 * C++ Interface: wrap_vtkTransform
 *
 * Description: wrapping vtkTransform
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
#include "wrap_vtkTransform.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_vtkTransform.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkTransform>::CreateVar( ParamList* p)
{
  WrapClass_vtkTransform::wrap_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkTransform);
AMI_DEFINE_VARFROMSMTPTR(vtkTransform);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkTransform>::CreateVar( vtkTransform* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkTransform> obj_ptr(val,smartpointer_nodeleter<vtkTransform>());
  return AMILabType<vtkTransform>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkTransform
//
Variable<AMIObject>::ptr WrapClass_vtkTransform::CreateVar( vtkTransform* sp)
{
  boost::shared_ptr<vtkTransform> di_ptr(
    sp,
    wxwindow_nodeleter<vtkTransform>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkTransform>::CreateVar(
      new WrapClass_vtkTransform(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkTransform::AddMethods(WrapClass<vtkTransform>::ptr this_ptr )
{
  /*
      // Add members from vtkLinearTransform
      WrapClass_vtkLinearTransform::ptr parent_vtkLinearTransform(        boost::dynamic_pointer_cast<WrapClass_vtkLinearTransform >(this_ptr));
      parent_vtkLinearTransform->AddMethods(parent_vtkLinearTransform);
      */


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_Identity( this_ptr);
      AddVar_Inverse( this_ptr);
      AddVar_Translate_1( this_ptr);
      AddVar_Translate( this_ptr);
      AddVar_Translate_2( this_ptr);
      AddVar_Translate_3( this_ptr);
      AddVar_RotateWXYZ_1( this_ptr);
      AddVar_RotateWXYZ( this_ptr);
      AddVar_RotateWXYZ_2( this_ptr);
      AddVar_RotateWXYZ_3( this_ptr);
      AddVar_RotateX( this_ptr);
      AddVar_RotateY( this_ptr);
      AddVar_RotateZ( this_ptr);
      AddVar_Scale_1( this_ptr);
      AddVar_Scale( this_ptr);
      AddVar_Scale_2( this_ptr);
      AddVar_Scale_3( this_ptr);
/* The following types are missing: vtkMatrix4x4
      AddVar_SetMatrix_1( this_ptr);
*/
      AddVar_SetMatrix( this_ptr);
      AddVar_SetMatrix_2( this_ptr);
/* The following types are missing: vtkMatrix4x4
      AddVar_Concatenate_1( this_ptr);
*/
      AddVar_Concatenate( this_ptr);
      AddVar_Concatenate_2( this_ptr);
/* The following types are missing: vtkLinearTransform
      AddVar_Concatenate_3( this_ptr);
*/
      AddVar_PreMultiply( this_ptr);
      AddVar_PostMultiply( this_ptr);
      AddVar_GetNumberOfConcatenatedTransforms( this_ptr);
/* The following types are missing: vtkLinearTransform
      AddVar_GetConcatenatedTransform( this_ptr);
*/
      AddVar_GetOrientation_1( this_ptr);
      AddVar_GetOrientation( this_ptr);
      AddVar_GetOrientation_2( this_ptr);
      AddVar_GetOrientation_3( this_ptr);
      AddVar_GetOrientationWXYZ_1( this_ptr);
      AddVar_GetOrientationWXYZ( this_ptr);
      AddVar_GetOrientationWXYZ_2( this_ptr);
      AddVar_GetOrientationWXYZ_3( this_ptr);
      AddVar_GetPosition_1( this_ptr);
      AddVar_GetPosition( this_ptr);
      AddVar_GetPosition_2( this_ptr);
      AddVar_GetPosition_3( this_ptr);
      AddVar_GetScale_1( this_ptr);
      AddVar_GetScale( this_ptr);
      AddVar_GetScale_2( this_ptr);
      AddVar_GetScale_3( this_ptr);
/* The following types are missing: vtkMatrix4x4
      AddVar_GetInverse_1( this_ptr);
*/
/* The following types are missing: vtkMatrix4x4
      AddVar_GetTranspose( this_ptr);
*/
/* The following types are missing: vtkLinearTransform
      AddVar_SetInput( this_ptr);
*/
/* The following types are missing: vtkLinearTransform
      AddVar_GetInput( this_ptr);
*/
      AddVar_GetInverseFlag( this_ptr);
      AddVar_Push( this_ptr);
      AddVar_Pop( this_ptr);
/* The following types are missing: vtkAbstractTransform
      AddVar_CircuitCheck( this_ptr);
*/
      AddVar_GetInverse( this_ptr);
/* The following types are missing: vtkAbstractTransform
      AddVar_GetInverse_2( this_ptr);
*/
/* The following types are missing: vtkAbstractTransform
      AddVar_MakeTransform( this_ptr);
*/
      AddVar_GetMTime( this_ptr);
      AddVar_MultiplyPoint_1( this_ptr);
      AddVar_MultiplyPoint( this_ptr);
      AddVar_MultiplyPoint_2( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkTransform * vtkTransform::New()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkTransform * res =   vtkTransform::New();
  BasicVariable::ptr res_var = WrapClass_vtkTransform::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkTransform::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkTransform::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkTransform * vtkTransform::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkTransform * res =   vtkTransform::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkTransform::CreateVar(res);
  return res_var;
}
/* The following types are missing: vtkMatrix4x4

//---------------------------------------------------
//  Wrapping of void vtkTransform::GetOrientation(double * orient, vtkMatrix4x4 * matrix)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetOrientation_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'orient'")
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'matrix'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetOrientation_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > orient_smtptr;
  if (!get_val_smtptr_param<double >(orient_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* orient = orient_smtptr.get();

  boost::shared_ptr<vtkMatrix4x4 > matrix_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(matrix_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4* matrix = matrix_smtptr.get();

  vtkTransform::GetOrientation(orient, matrix);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of int vtkTransform::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
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
//  Wrapping of vtkTransform * vtkTransform::NewInstance()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkTransform * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkTransform::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkTransform::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
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
//  Wrapping of void vtkTransform::Identity()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_Identity::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_Identity::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Identity();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::Inverse()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_Inverse::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_Inverse::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Inverse();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::Translate(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_Translate_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_Translate_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->Translate(x, y, z);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkTransform::Translate(...)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_Translate::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_Translate::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkTransform::wrap_Translate_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkTransform::wrap_Translate_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkTransform::wrap_Translate_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::Translate(double const * x)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_Translate_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_Translate_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* x = x_smtptr.get();

  this->_objectptr->GetObj()->Translate(x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::Translate(float const * x)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_Translate_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_Translate_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<float > x_smtptr;
  if (!get_val_smtptr_param<float >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* x = x_smtptr.get();

  this->_objectptr->GetObj()->Translate(x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::RotateWXYZ(double angle, double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_RotateWXYZ_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_RotateWXYZ_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  double angle;
  if (!get_val_param<double >(angle,_p,_n,true,true)) ClassReturnEmptyVar;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  double y;
  if (!get_val_param<double >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  double z;
  if (!get_val_param<double >(z,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->RotateWXYZ(angle, x, y, z);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkTransform::RotateWXYZ(...)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_RotateWXYZ::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_RotateWXYZ::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkTransform::wrap_RotateWXYZ_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkTransform::wrap_RotateWXYZ_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkTransform::wrap_RotateWXYZ_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::RotateWXYZ(double angle, double const * axis)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_RotateWXYZ_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'axis'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_RotateWXYZ_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double angle;
  if (!get_val_param<double >(angle,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<double > axis_smtptr;
  if (!get_val_smtptr_param<double >(axis_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* axis = axis_smtptr.get();

  this->_objectptr->GetObj()->RotateWXYZ(angle, axis);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::RotateWXYZ(double angle, float const * axis)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_RotateWXYZ_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'axis'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_RotateWXYZ_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double angle;
  if (!get_val_param<double >(angle,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<float > axis_smtptr;
  if (!get_val_smtptr_param<float >(axis_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* axis = axis_smtptr.get();

  this->_objectptr->GetObj()->RotateWXYZ(angle, axis);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::RotateX(double angle)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_RotateX::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_RotateX::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double angle;
  if (!get_val_param<double >(angle,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RotateX(angle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::RotateY(double angle)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_RotateY::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_RotateY::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double angle;
  if (!get_val_param<double >(angle,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RotateY(angle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::RotateZ(double angle)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_RotateZ::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_RotateZ::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double angle;
  if (!get_val_param<double >(angle,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RotateZ(angle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::Scale(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_Scale_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_Scale_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->Scale(x, y, z);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkTransform::Scale(...)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_Scale::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_Scale::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkTransform::wrap_Scale_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkTransform::wrap_Scale_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkTransform::wrap_Scale_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::Scale(double const * s)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_Scale_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_Scale_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > s_smtptr;
  if (!get_val_smtptr_param<double >(s_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* s = s_smtptr.get();

  this->_objectptr->GetObj()->Scale(s);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::Scale(float const * s)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_Scale_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_Scale_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<float > s_smtptr;
  if (!get_val_smtptr_param<float >(s_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* s = s_smtptr.get();

  this->_objectptr->GetObj()->Scale(s);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkMatrix4x4

//---------------------------------------------------
//  Wrapping of void vtkTransform::SetMatrix(vtkMatrix4x4 * matrix)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_SetMatrix_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'matrix'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_SetMatrix_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkMatrix4x4 > matrix_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(matrix_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4* matrix = matrix_smtptr.get();

  this->_objectptr->GetObj()->SetMatrix(matrix);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkTransform::SetMatrix(...)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_SetMatrix::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_SetMatrix::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkTransform::wrap_SetMatrix_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::SetMatrix(double const * elements)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_SetMatrix_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'elements'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_SetMatrix_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > elements_smtptr;
  if (!get_val_smtptr_param<double >(elements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* elements = elements_smtptr.get();

  this->_objectptr->GetObj()->SetMatrix(elements);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkMatrix4x4

//---------------------------------------------------
//  Wrapping of void vtkTransform::Concatenate(vtkMatrix4x4 * matrix)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_Concatenate_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'matrix'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_Concatenate_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkMatrix4x4 > matrix_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(matrix_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4* matrix = matrix_smtptr.get();

  this->_objectptr->GetObj()->Concatenate(matrix);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkTransform::Concatenate(...)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_Concatenate::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_Concatenate::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkTransform::wrap_Concatenate_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::Concatenate(double const * elements)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_Concatenate_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'elements'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_Concatenate_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > elements_smtptr;
  if (!get_val_smtptr_param<double >(elements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* elements = elements_smtptr.get();

  this->_objectptr->GetObj()->Concatenate(elements);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkLinearTransform

//---------------------------------------------------
//  Wrapping of void vtkTransform::Concatenate(vtkLinearTransform * transform)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_Concatenate_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkLinearTransform, "parameter named 'transform'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_Concatenate_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkLinearTransform > transform_smtptr;
  if (!get_val_smtptr_param<vtkLinearTransform >(transform_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkLinearTransform* transform = transform_smtptr.get();

  this->_objectptr->GetObj()->Concatenate(transform);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkTransform::PreMultiply()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_PreMultiply::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_PreMultiply::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PreMultiply();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::PostMultiply()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_PostMultiply::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_PostMultiply::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PostMultiply();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkTransform::GetNumberOfConcatenatedTransforms()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetNumberOfConcatenatedTransforms::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetNumberOfConcatenatedTransforms::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfConcatenatedTransforms();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: vtkLinearTransform

//---------------------------------------------------
//  Wrapping of vtkLinearTransform * vtkTransform::GetConcatenatedTransform(int i)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetConcatenatedTransform::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  return_comments="returning a variable of type vtkLinearTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetConcatenatedTransform::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,false)) ClassHelpAndReturn;

  vtkLinearTransform * res =   this->_objectptr->GetObj()->GetConcatenatedTransform(i);
  return AMILabType<vtkLinearTransform >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkTransform::GetOrientation(double * orient)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetOrientation_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'orient'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetOrientation_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > orient_smtptr;
  if (!get_val_smtptr_param<double >(orient_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* orient = orient_smtptr.get();

  this->_objectptr->GetObj()->GetOrientation(orient);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkTransform::GetOrientation(...)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetOrientation::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetOrientation::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkTransform::wrap_GetOrientation_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkTransform::wrap_GetOrientation_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkTransform::wrap_GetOrientation_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::GetOrientation(float * orient)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetOrientation_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'orient'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetOrientation_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<float > orient_smtptr;
  if (!get_val_smtptr_param<float >(orient_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* orient = orient_smtptr.get();

  this->_objectptr->GetObj()->GetOrientation(orient);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkTransform::GetOrientation()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetOrientation_3::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetOrientation_3::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetOrientation();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::GetOrientationWXYZ(double * wxyz)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetOrientationWXYZ_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'wxyz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetOrientationWXYZ_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > wxyz_smtptr;
  if (!get_val_smtptr_param<double >(wxyz_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* wxyz = wxyz_smtptr.get();

  this->_objectptr->GetObj()->GetOrientationWXYZ(wxyz);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkTransform::GetOrientationWXYZ(...)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetOrientationWXYZ::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetOrientationWXYZ::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkTransform::wrap_GetOrientationWXYZ_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkTransform::wrap_GetOrientationWXYZ_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkTransform::wrap_GetOrientationWXYZ_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::GetOrientationWXYZ(float * wxyz)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetOrientationWXYZ_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'wxyz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetOrientationWXYZ_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<float > wxyz_smtptr;
  if (!get_val_smtptr_param<float >(wxyz_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* wxyz = wxyz_smtptr.get();

  this->_objectptr->GetObj()->GetOrientationWXYZ(wxyz);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkTransform::GetOrientationWXYZ()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetOrientationWXYZ_3::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetOrientationWXYZ_3::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetOrientationWXYZ();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::GetPosition(double * pos)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetPosition_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'pos'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetPosition_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > pos_smtptr;
  if (!get_val_smtptr_param<double >(pos_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* pos = pos_smtptr.get();

  this->_objectptr->GetObj()->GetPosition(pos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkTransform::GetPosition(...)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkTransform::wrap_GetPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkTransform::wrap_GetPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkTransform::wrap_GetPosition_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::GetPosition(float * pos)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'pos'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetPosition_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<float > pos_smtptr;
  if (!get_val_smtptr_param<float >(pos_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* pos = pos_smtptr.get();

  this->_objectptr->GetObj()->GetPosition(pos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkTransform::GetPosition()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetPosition_3::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetPosition_3::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetPosition();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::GetScale(double * scale)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetScale_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'scale'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetScale_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > scale_smtptr;
  if (!get_val_smtptr_param<double >(scale_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* scale = scale_smtptr.get();

  this->_objectptr->GetObj()->GetScale(scale);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkTransform::GetScale(...)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetScale::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetScale::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkTransform::wrap_GetScale_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkTransform::wrap_GetScale_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkTransform::wrap_GetScale_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::GetScale(float * scale)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetScale_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'scale'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetScale_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<float > scale_smtptr;
  if (!get_val_smtptr_param<float >(scale_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* scale = scale_smtptr.get();

  this->_objectptr->GetObj()->GetScale(scale);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkTransform::GetScale()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetScale_3::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetScale_3::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetScale();
  return AMILabType<double >::CreateVar(res,true);
}
/* The following types are missing: vtkMatrix4x4

//---------------------------------------------------
//  Wrapping of void vtkTransform::GetInverse(vtkMatrix4x4 * inverse)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetInverse_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'inverse'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetInverse_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkMatrix4x4 > inverse_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(inverse_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4* inverse = inverse_smtptr.get();

  this->_objectptr->GetObj()->GetInverse(inverse);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkMatrix4x4

//---------------------------------------------------
//  Wrapping of void vtkTransform::GetTranspose(vtkMatrix4x4 * transpose)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetTranspose::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'transpose'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetTranspose::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkMatrix4x4 > transpose_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(transpose_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkMatrix4x4* transpose = transpose_smtptr.get();

  this->_objectptr->GetObj()->GetTranspose(transpose);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkLinearTransform

//---------------------------------------------------
//  Wrapping of void vtkTransform::SetInput(vtkLinearTransform * input)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_SetInput::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkLinearTransform, "parameter named 'input'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_SetInput::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkLinearTransform > input_smtptr;
  if (!get_val_smtptr_param<vtkLinearTransform >(input_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkLinearTransform* input = input_smtptr.get();

  this->_objectptr->GetObj()->SetInput(input);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkLinearTransform

//---------------------------------------------------
//  Wrapping of vtkLinearTransform * vtkTransform::GetInput()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetInput::SetParametersComments()
{
  return_comments="returning a variable of type vtkLinearTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetInput::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkLinearTransform * res =   this->_objectptr->GetObj()->GetInput();
  return AMILabType<vtkLinearTransform >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of int vtkTransform::GetInverseFlag()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetInverseFlag::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetInverseFlag::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetInverseFlag();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::Push()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_Push::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_Push::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Push();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::Pop()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_Pop::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_Pop::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Pop();
  return BasicVariable::ptr();
}
/* The following types are missing: vtkAbstractTransform

//---------------------------------------------------
//  Wrapping of int vtkTransform::CircuitCheck(vtkAbstractTransform * transform)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_CircuitCheck::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAbstractTransform, "parameter named 'transform'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
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
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkTransform::GetInverse(...)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetInverse::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetInverse::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkAbstractTransform

//---------------------------------------------------
//  Wrapping of vtkAbstractTransform * vtkTransform::GetInverse()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetInverse_2::SetParametersComments()
{
  return_comments="returning a variable of type vtkAbstractTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetInverse_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkAbstractTransform * res =   this->_objectptr->GetObj()->GetInverse();
  return AMILabType<vtkAbstractTransform >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkAbstractTransform

//---------------------------------------------------
//  Wrapping of vtkAbstractTransform * vtkTransform::MakeTransform()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_MakeTransform::SetParametersComments()
{
  return_comments="returning a variable of type vtkAbstractTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_MakeTransform::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAbstractTransform * res =   this->_objectptr->GetObj()->MakeTransform();
  return AMILabType<vtkAbstractTransform >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of long unsigned int vtkTransform::GetMTime()
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_GetMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_GetMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::MultiplyPoint(float const * in, float * out)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_MultiplyPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_MultiplyPoint_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->MultiplyPoint(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkTransform::MultiplyPoint(...)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_MultiplyPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_MultiplyPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkTransform::wrap_MultiplyPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkTransform::wrap_MultiplyPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkTransform::MultiplyPoint(double const * in, double * out)
//---------------------------------------------------
void WrapClass_vtkTransform::
    wrap_MultiplyPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTransform::
    wrap_MultiplyPoint_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->MultiplyPoint(in, out);
  return BasicVariable::ptr();
}

