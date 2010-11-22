/**
 * C++ Interface: wrap_vtkCamera
 *
 * Description: wrapping vtkCamera
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
#include "wrap_vtkCamera.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkRenderer.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_vtkCamera.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkCamera>::CreateVar( ParamList* p)
{
  WrapClass_vtkCamera::wrap_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkCamera);
AMI_DEFINE_VARFROMSMTPTR(vtkCamera);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkCamera>::CreateVar( vtkCamera* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkCamera> obj_ptr(val,smartpointer_nodeleter<vtkCamera>());
  return AMILabType<vtkCamera>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkCamera
//
Variable<AMIObject>::ptr WrapClass_vtkCamera::CreateVar( vtkCamera* sp)
{
  boost::shared_ptr<vtkCamera> di_ptr(
    sp,
    wxwindow_nodeleter<vtkCamera>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkCamera>::CreateVar(
      new WrapClass_vtkCamera(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkCamera::AddMethods(WrapClass<vtkCamera>::ptr this_ptr )
{
  
      // Add members from vtkObject
      WrapClass_vtkObject::ptr parent_vtkObject(        boost::dynamic_pointer_cast<WrapClass_vtkObject >(this_ptr));
      parent_vtkObject->AddMethods(parent_vtkObject);


  // check that the method name is not a token
  
      // Adding standard methods 
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
      AddVar_SetPosition_1( this_ptr);
      AddVar_SetPosition( this_ptr);
      AddVar_SetPosition_2( this_ptr);
      AddVar_GetPosition_1( this_ptr);
      AddVar_GetPosition( this_ptr);
      AddVar_GetPosition_2( this_ptr);
      AddVar_GetPosition_3( this_ptr);
      AddVar_SetFocalPoint_1( this_ptr);
      AddVar_SetFocalPoint( this_ptr);
      AddVar_SetFocalPoint_2( this_ptr);
      AddVar_GetFocalPoint_1( this_ptr);
      AddVar_GetFocalPoint( this_ptr);
      AddVar_GetFocalPoint_2( this_ptr);
      AddVar_GetFocalPoint_3( this_ptr);
      AddVar_SetViewUp_1( this_ptr);
      AddVar_SetViewUp( this_ptr);
      AddVar_SetViewUp_2( this_ptr);
      AddVar_GetViewUp_1( this_ptr);
      AddVar_GetViewUp( this_ptr);
      AddVar_GetViewUp_2( this_ptr);
      AddVar_GetViewUp_3( this_ptr);
      AddVar_OrthogonalizeViewUp( this_ptr);
      AddVar_SetDistance( this_ptr);
      AddVar_GetDistance( this_ptr);
      AddVar_GetDirectionOfProjection_1( this_ptr);
      AddVar_GetDirectionOfProjection( this_ptr);
      AddVar_GetDirectionOfProjection_2( this_ptr);
      AddVar_GetDirectionOfProjection_3( this_ptr);
      AddVar_Dolly( this_ptr);
      AddVar_SetRoll( this_ptr);
      AddVar_GetRoll( this_ptr);
      AddVar_Roll( this_ptr);
      AddVar_Azimuth( this_ptr);
      AddVar_Yaw( this_ptr);
      AddVar_Elevation( this_ptr);
      AddVar_Pitch( this_ptr);
      AddVar_SetParallelProjection( this_ptr);
      AddVar_GetParallelProjection( this_ptr);
      AddVar_ParallelProjectionOn( this_ptr);
      AddVar_ParallelProjectionOff( this_ptr);
      AddVar_SetUseHorizontalViewAngle( this_ptr);
      AddVar_GetUseHorizontalViewAngle( this_ptr);
      AddVar_UseHorizontalViewAngleOn( this_ptr);
      AddVar_UseHorizontalViewAngleOff( this_ptr);
      AddVar_SetViewAngle( this_ptr);
      AddVar_GetViewAngle( this_ptr);
      AddVar_SetParallelScale( this_ptr);
      AddVar_GetParallelScale( this_ptr);
      AddVar_Zoom( this_ptr);
      AddVar_SetClippingRange_1( this_ptr);
      AddVar_SetClippingRange( this_ptr);
      AddVar_SetClippingRange_2( this_ptr);
      AddVar_GetClippingRange_1( this_ptr);
      AddVar_GetClippingRange( this_ptr);
      AddVar_GetClippingRange_2( this_ptr);
      AddVar_GetClippingRange_3( this_ptr);
      AddVar_SetThickness( this_ptr);
      AddVar_GetThickness( this_ptr);
      AddVar_SetWindowCenter( this_ptr);
      AddVar_GetWindowCenter_1( this_ptr);
      AddVar_GetWindowCenter( this_ptr);
      AddVar_GetWindowCenter_2( this_ptr);
      AddVar_GetWindowCenter_3( this_ptr);
      AddVar_SetObliqueAngles( this_ptr);
/* The following types are missing: vtkTransform
      AddVar_ApplyTransform( this_ptr);
*/
      AddVar_GetViewPlaneNormal_1( this_ptr);
      AddVar_GetViewPlaneNormal( this_ptr);
      AddVar_GetViewPlaneNormal_2( this_ptr);
      AddVar_GetViewPlaneNormal_3( this_ptr);
      AddVar_SetViewShear_1( this_ptr);
      AddVar_SetViewShear( this_ptr);
      AddVar_SetViewShear_2( this_ptr);
      AddVar_GetViewShear_1( this_ptr);
      AddVar_GetViewShear( this_ptr);
      AddVar_GetViewShear_2( this_ptr);
      AddVar_GetViewShear_3( this_ptr);
      AddVar_SetEyeAngle( this_ptr);
      AddVar_GetEyeAngle( this_ptr);
      AddVar_SetFocalDisk( this_ptr);
      AddVar_GetFocalDisk( this_ptr);
/* The following types are missing: vtkMatrix4x4
      AddVar_GetViewTransformMatrix( this_ptr);
*/
/* The following types are missing: vtkTransform
      AddVar_GetViewTransformObject( this_ptr);
*/
/* The following types are missing: vtkMatrix4x4
      AddVar_GetPerspectiveTransformMatrix( this_ptr);
*/
/* The following types are missing: vtkMatrix4x4
      AddVar_GetProjectionTransformMatrix( this_ptr);
*/
/* The following types are missing: vtkPerspectiveTransform
      AddVar_GetProjectionTransformObject( this_ptr);
*/
/* The following types are missing: vtkMatrix4x4
      AddVar_GetCompositePerspectiveTransformMatrix( this_ptr);
*/
/* The following types are missing: vtkMatrix4x4
      AddVar_GetCompositeProjectionTransformMatrix( this_ptr);
*/
/* The following types are missing: vtkHomogeneousTransform
      AddVar_SetUserViewTransform( this_ptr);
*/
/* The following types are missing: vtkHomogeneousTransform
      AddVar_GetUserViewTransform( this_ptr);
*/
/* The following types are missing: vtkHomogeneousTransform
      AddVar_SetUserTransform( this_ptr);
*/
/* The following types are missing: vtkHomogeneousTransform
      AddVar_GetUserTransform( this_ptr);
*/
      AddVar_Render( this_ptr);
      AddVar_GetViewingRaysMTime( this_ptr);
      AddVar_ViewingRaysModified( this_ptr);
      AddVar_GetFrustumPlanes( this_ptr);
      AddVar_GetOrientation( this_ptr);
      AddVar_GetOrientationWXYZ( this_ptr);
      AddVar_SetViewPlaneNormal_1( this_ptr);
      AddVar_SetViewPlaneNormal( this_ptr);
      AddVar_SetViewPlaneNormal_2( this_ptr);
      AddVar_ComputeViewPlaneNormal( this_ptr);
/* The following types are missing: vtkMatrix4x4
      AddVar_GetCameraLightTransformMatrix( this_ptr);
*/
      AddVar_UpdateViewport( this_ptr);
      AddVar_SetLeftEye( this_ptr);
      AddVar_GetLeftEye( this_ptr);
      AddVar_ShallowCopy( this_ptr);
      AddVar_DeepCopy( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkCamera::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkCamera::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkCamera * vtkCamera::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkCamera";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkCamera * res =   vtkCamera::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkCamera::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkCamera * vtkCamera::New()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkCamera";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkCamera * res =   vtkCamera::New();
  BasicVariable::ptr res_var = WrapClass_vtkCamera::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkCamera::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
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
//  Wrapping of int vtkCamera::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
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
//  Wrapping of vtkCamera * vtkCamera::NewInstance()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkCamera";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkCamera * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkCamera::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetPosition(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetPosition_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetPosition_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetPosition(x, y, z);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCamera::SetPosition(...)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCamera::wrap_SetPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_SetPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetPosition(double const * a)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'a'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetPosition_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > a_smtptr;
  if (!get_val_smtptr_param<double >(a_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* a = a_smtptr.get();

  this->_objectptr->GetObj()->SetPosition(a);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkCamera::GetPosition()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetPosition_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetPosition_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetPosition();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCamera::GetPosition(...)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCamera::wrap_GetPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_GetPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_GetPosition_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetPosition(double & _arg1, double & _arg2, double & _arg3)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetPosition_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  boost::shared_ptr<double > _arg3_smtptr;
  if (!get_val_smtptr_param<double >(_arg3_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg3 = *_arg3_smtptr;

  this->_objectptr->GetObj()->GetPosition(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetPosition(double * _arg)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetPosition_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetPosition_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetPosition(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetFocalPoint(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetFocalPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetFocalPoint_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetFocalPoint(x, y, z);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCamera::SetFocalPoint(...)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetFocalPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetFocalPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCamera::wrap_SetFocalPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_SetFocalPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetFocalPoint(double const * a)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetFocalPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'a'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetFocalPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > a_smtptr;
  if (!get_val_smtptr_param<double >(a_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* a = a_smtptr.get();

  this->_objectptr->GetObj()->SetFocalPoint(a);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkCamera::GetFocalPoint()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetFocalPoint_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetFocalPoint_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetFocalPoint();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCamera::GetFocalPoint(...)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetFocalPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetFocalPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCamera::wrap_GetFocalPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_GetFocalPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_GetFocalPoint_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetFocalPoint(double & _arg1, double & _arg2, double & _arg3)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetFocalPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetFocalPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  boost::shared_ptr<double > _arg3_smtptr;
  if (!get_val_smtptr_param<double >(_arg3_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg3 = *_arg3_smtptr;

  this->_objectptr->GetObj()->GetFocalPoint(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetFocalPoint(double * _arg)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetFocalPoint_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetFocalPoint_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetFocalPoint(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetViewUp(double vx, double vy, double vz)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetViewUp_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'vx'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'vy'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'vz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetViewUp_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  double vx;
  if (!get_val_param<double >(vx,_p,_n)) ClassReturnEmptyVar;

  double vy;
  if (!get_val_param<double >(vy,_p,_n)) ClassReturnEmptyVar;

  double vz;
  if (!get_val_param<double >(vz,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetViewUp(vx, vy, vz);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCamera::SetViewUp(...)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetViewUp::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetViewUp::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCamera::wrap_SetViewUp_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_SetViewUp_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetViewUp(double const * a)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetViewUp_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'a'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetViewUp_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > a_smtptr;
  if (!get_val_smtptr_param<double >(a_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* a = a_smtptr.get();

  this->_objectptr->GetObj()->SetViewUp(a);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkCamera::GetViewUp()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetViewUp_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetViewUp_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetViewUp();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCamera::GetViewUp(...)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetViewUp::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetViewUp::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCamera::wrap_GetViewUp_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_GetViewUp_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_GetViewUp_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetViewUp(double & _arg1, double & _arg2, double & _arg3)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetViewUp_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetViewUp_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  boost::shared_ptr<double > _arg3_smtptr;
  if (!get_val_smtptr_param<double >(_arg3_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg3 = *_arg3_smtptr;

  this->_objectptr->GetObj()->GetViewUp(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetViewUp(double * _arg)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetViewUp_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetViewUp_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetViewUp(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::OrthogonalizeViewUp()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_OrthogonalizeViewUp::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_OrthogonalizeViewUp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OrthogonalizeViewUp();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetDistance(double param0)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetDistance::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetDistance::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double param0;
  if (!get_val_param<double >(param0,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDistance(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkCamera::GetDistance()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetDistance::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetDistance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetDistance();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double * vtkCamera::GetDirectionOfProjection()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetDirectionOfProjection_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetDirectionOfProjection_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetDirectionOfProjection();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCamera::GetDirectionOfProjection(...)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetDirectionOfProjection::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetDirectionOfProjection::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCamera::wrap_GetDirectionOfProjection_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_GetDirectionOfProjection_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_GetDirectionOfProjection_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetDirectionOfProjection(double & _arg1, double & _arg2, double & _arg3)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetDirectionOfProjection_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetDirectionOfProjection_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  boost::shared_ptr<double > _arg3_smtptr;
  if (!get_val_smtptr_param<double >(_arg3_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg3 = *_arg3_smtptr;

  this->_objectptr->GetObj()->GetDirectionOfProjection(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetDirectionOfProjection(double * _arg)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetDirectionOfProjection_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetDirectionOfProjection_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetDirectionOfProjection(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::Dolly(double value)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_Dolly::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_Dolly::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double value;
  if (!get_val_param<double >(value,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Dolly(value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetRoll(double angle)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetRoll::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetRoll::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double angle;
  if (!get_val_param<double >(angle,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRoll(angle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkCamera::GetRoll()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetRoll::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetRoll::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetRoll();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::Roll(double angle)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_Roll::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_Roll::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double angle;
  if (!get_val_param<double >(angle,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Roll(angle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::Azimuth(double angle)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_Azimuth::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_Azimuth::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double angle;
  if (!get_val_param<double >(angle,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Azimuth(angle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::Yaw(double angle)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_Yaw::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_Yaw::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double angle;
  if (!get_val_param<double >(angle,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Yaw(angle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::Elevation(double angle)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_Elevation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_Elevation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double angle;
  if (!get_val_param<double >(angle,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Elevation(angle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::Pitch(double angle)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_Pitch::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_Pitch::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double angle;
  if (!get_val_param<double >(angle,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Pitch(angle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetParallelProjection(int flag)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetParallelProjection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetParallelProjection::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int flag;
  if (!get_val_param<int >(flag,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetParallelProjection(flag);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkCamera::GetParallelProjection()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetParallelProjection::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetParallelProjection::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetParallelProjection();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::ParallelProjectionOn()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_ParallelProjectionOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_ParallelProjectionOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ParallelProjectionOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::ParallelProjectionOff()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_ParallelProjectionOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_ParallelProjectionOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ParallelProjectionOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetUseHorizontalViewAngle(int flag)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetUseHorizontalViewAngle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetUseHorizontalViewAngle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int flag;
  if (!get_val_param<int >(flag,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetUseHorizontalViewAngle(flag);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkCamera::GetUseHorizontalViewAngle()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetUseHorizontalViewAngle::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetUseHorizontalViewAngle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetUseHorizontalViewAngle();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::UseHorizontalViewAngleOn()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_UseHorizontalViewAngleOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_UseHorizontalViewAngleOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UseHorizontalViewAngleOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::UseHorizontalViewAngleOff()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_UseHorizontalViewAngleOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_UseHorizontalViewAngleOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UseHorizontalViewAngleOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetViewAngle(double angle)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetViewAngle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetViewAngle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double angle;
  if (!get_val_param<double >(angle,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetViewAngle(angle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkCamera::GetViewAngle()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetViewAngle::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetViewAngle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetViewAngle();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetParallelScale(double scale)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetParallelScale::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'scale'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetParallelScale::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double scale;
  if (!get_val_param<double >(scale,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetParallelScale(scale);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkCamera::GetParallelScale()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetParallelScale::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetParallelScale::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetParallelScale();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::Zoom(double factor)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_Zoom::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'factor'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_Zoom::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double factor;
  if (!get_val_param<double >(factor,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Zoom(factor);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetClippingRange(double dNear, double dFar)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetClippingRange_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'dNear'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'dFar'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetClippingRange_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double dNear;
  if (!get_val_param<double >(dNear,_p,_n)) ClassReturnEmptyVar;

  double dFar;
  if (!get_val_param<double >(dFar,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetClippingRange(dNear, dFar);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCamera::SetClippingRange(...)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetClippingRange::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetClippingRange::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCamera::wrap_SetClippingRange_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_SetClippingRange_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetClippingRange(double const * a)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetClippingRange_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'a'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetClippingRange_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > a_smtptr;
  if (!get_val_smtptr_param<double >(a_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* a = a_smtptr.get();

  this->_objectptr->GetObj()->SetClippingRange(a);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkCamera::GetClippingRange()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetClippingRange_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetClippingRange_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetClippingRange();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCamera::GetClippingRange(...)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetClippingRange::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetClippingRange::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCamera::wrap_GetClippingRange_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_GetClippingRange_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_GetClippingRange_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetClippingRange(double & _arg1, double & _arg2)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetClippingRange_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetClippingRange_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  this->_objectptr->GetObj()->GetClippingRange(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetClippingRange(double * _arg)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetClippingRange_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetClippingRange_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetClippingRange(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetThickness(double param0)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetThickness::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetThickness::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double param0;
  if (!get_val_param<double >(param0,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetThickness(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkCamera::GetThickness()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetThickness::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetThickness::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetThickness();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetWindowCenter(double x, double y)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetWindowCenter::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetWindowCenter::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n)) ClassHelpAndReturn;

  double y;
  if (!get_val_param<double >(y,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetWindowCenter(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkCamera::GetWindowCenter()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetWindowCenter_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetWindowCenter_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetWindowCenter();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCamera::GetWindowCenter(...)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetWindowCenter::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetWindowCenter::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCamera::wrap_GetWindowCenter_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_GetWindowCenter_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_GetWindowCenter_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetWindowCenter(double & _arg1, double & _arg2)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetWindowCenter_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetWindowCenter_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  this->_objectptr->GetObj()->GetWindowCenter(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetWindowCenter(double * _arg)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetWindowCenter_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetWindowCenter_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetWindowCenter(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetObliqueAngles(double alpha, double beta)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetObliqueAngles::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'alpha'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'beta'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetObliqueAngles::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  double alpha;
  if (!get_val_param<double >(alpha,_p,_n)) ClassHelpAndReturn;

  double beta;
  if (!get_val_param<double >(beta,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetObliqueAngles(alpha, beta);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkTransform

//---------------------------------------------------
//  Wrapping of void vtkCamera::ApplyTransform(vtkTransform * t)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_ApplyTransform::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkTransform, "parameter named 't'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_ApplyTransform::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkTransform > t_smtptr;
  if (!get_val_smtptr_param<vtkTransform >(t_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkTransform* t = t_smtptr.get();

  this->_objectptr->GetObj()->ApplyTransform(t);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of double * vtkCamera::GetViewPlaneNormal()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetViewPlaneNormal_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetViewPlaneNormal_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetViewPlaneNormal();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCamera::GetViewPlaneNormal(...)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetViewPlaneNormal::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetViewPlaneNormal::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCamera::wrap_GetViewPlaneNormal_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_GetViewPlaneNormal_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_GetViewPlaneNormal_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetViewPlaneNormal(double & _arg1, double & _arg2, double & _arg3)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetViewPlaneNormal_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetViewPlaneNormal_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  boost::shared_ptr<double > _arg3_smtptr;
  if (!get_val_smtptr_param<double >(_arg3_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg3 = *_arg3_smtptr;

  this->_objectptr->GetObj()->GetViewPlaneNormal(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetViewPlaneNormal(double * _arg)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetViewPlaneNormal_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetViewPlaneNormal_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetViewPlaneNormal(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetViewShear(double dxdz, double dydz, double center)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetViewShear_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'dxdz'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'dydz'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'center'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetViewShear_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  double dxdz;
  if (!get_val_param<double >(dxdz,_p,_n)) ClassReturnEmptyVar;

  double dydz;
  if (!get_val_param<double >(dydz,_p,_n)) ClassReturnEmptyVar;

  double center;
  if (!get_val_param<double >(center,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetViewShear(dxdz, dydz, center);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCamera::SetViewShear(...)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetViewShear::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetViewShear::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCamera::wrap_SetViewShear_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_SetViewShear_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetViewShear(double * d)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetViewShear_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'd'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetViewShear_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > d_smtptr;
  if (!get_val_smtptr_param<double >(d_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* d = d_smtptr.get();

  this->_objectptr->GetObj()->SetViewShear(d);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkCamera::GetViewShear()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetViewShear_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetViewShear_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetViewShear();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCamera::GetViewShear(...)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetViewShear::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetViewShear::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCamera::wrap_GetViewShear_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_GetViewShear_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_GetViewShear_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetViewShear(double & _arg1, double & _arg2, double & _arg3)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetViewShear_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetViewShear_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  boost::shared_ptr<double > _arg3_smtptr;
  if (!get_val_smtptr_param<double >(_arg3_smtptr,_p,_n)) ClassReturnEmptyVar;
  double & _arg3 = *_arg3_smtptr;

  this->_objectptr->GetObj()->GetViewShear(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetViewShear(double * _arg)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetViewShear_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetViewShear_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetViewShear(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetEyeAngle(double _arg)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetEyeAngle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetEyeAngle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetEyeAngle(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkCamera::GetEyeAngle()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetEyeAngle::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetEyeAngle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetEyeAngle();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetFocalDisk(double _arg)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetFocalDisk::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetFocalDisk::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFocalDisk(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkCamera::GetFocalDisk()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetFocalDisk::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetFocalDisk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetFocalDisk();
  return AMILabType<double >::CreateVar(res);
}
/* The following types are missing: vtkMatrix4x4

//---------------------------------------------------
//  Wrapping of vtkMatrix4x4 * vtkCamera::GetViewTransformMatrix()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetViewTransformMatrix::SetParametersComments()
{
  return_comments="returning a variable of type vtkMatrix4x4";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetViewTransformMatrix::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkMatrix4x4 * res =   this->_objectptr->GetObj()->GetViewTransformMatrix();
  return AMILabType<vtkMatrix4x4 >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkTransform

//---------------------------------------------------
//  Wrapping of vtkTransform * vtkCamera::GetViewTransformObject()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetViewTransformObject::SetParametersComments()
{
  return_comments="returning a variable of type vtkTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetViewTransformObject::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkTransform * res =   this->_objectptr->GetObj()->GetViewTransformObject();
  return AMILabType<vtkTransform >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkMatrix4x4

//---------------------------------------------------
//  Wrapping of vtkMatrix4x4 * vtkCamera::GetPerspectiveTransformMatrix(double aspect, double nearz, double farz)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetPerspectiveTransformMatrix::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'aspect'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'nearz'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'farz'")
  return_comments="returning a variable of type vtkMatrix4x4";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetPerspectiveTransformMatrix::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  double aspect;
  if (!get_val_param<double >(aspect,_p,_n)) ClassHelpAndReturn;

  double nearz;
  if (!get_val_param<double >(nearz,_p,_n)) ClassHelpAndReturn;

  double farz;
  if (!get_val_param<double >(farz,_p,_n)) ClassHelpAndReturn;

  vtkMatrix4x4 * res =   this->_objectptr->GetObj()->GetPerspectiveTransformMatrix(aspect, nearz, farz);
  return AMILabType<vtkMatrix4x4 >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkMatrix4x4

//---------------------------------------------------
//  Wrapping of vtkMatrix4x4 * vtkCamera::GetProjectionTransformMatrix(double aspect, double nearz, double farz)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetProjectionTransformMatrix::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'aspect'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'nearz'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'farz'")
  return_comments="returning a variable of type vtkMatrix4x4";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetProjectionTransformMatrix::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  double aspect;
  if (!get_val_param<double >(aspect,_p,_n)) ClassHelpAndReturn;

  double nearz;
  if (!get_val_param<double >(nearz,_p,_n)) ClassHelpAndReturn;

  double farz;
  if (!get_val_param<double >(farz,_p,_n)) ClassHelpAndReturn;

  vtkMatrix4x4 * res =   this->_objectptr->GetObj()->GetProjectionTransformMatrix(aspect, nearz, farz);
  return AMILabType<vtkMatrix4x4 >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkPerspectiveTransform

//---------------------------------------------------
//  Wrapping of vtkPerspectiveTransform * vtkCamera::GetProjectionTransformObject(double aspect, double nearz, double farz)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetProjectionTransformObject::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'aspect'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'nearz'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'farz'")
  return_comments="returning a variable of type vtkPerspectiveTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetProjectionTransformObject::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  double aspect;
  if (!get_val_param<double >(aspect,_p,_n)) ClassHelpAndReturn;

  double nearz;
  if (!get_val_param<double >(nearz,_p,_n)) ClassHelpAndReturn;

  double farz;
  if (!get_val_param<double >(farz,_p,_n)) ClassHelpAndReturn;

  vtkPerspectiveTransform * res =   this->_objectptr->GetObj()->GetProjectionTransformObject(aspect, nearz, farz);
  return AMILabType<vtkPerspectiveTransform >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkMatrix4x4

//---------------------------------------------------
//  Wrapping of vtkMatrix4x4 * vtkCamera::GetCompositePerspectiveTransformMatrix(double aspect, double nearz, double farz)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetCompositePerspectiveTransformMatrix::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'aspect'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'nearz'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'farz'")
  return_comments="returning a variable of type vtkMatrix4x4";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetCompositePerspectiveTransformMatrix::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  double aspect;
  if (!get_val_param<double >(aspect,_p,_n)) ClassHelpAndReturn;

  double nearz;
  if (!get_val_param<double >(nearz,_p,_n)) ClassHelpAndReturn;

  double farz;
  if (!get_val_param<double >(farz,_p,_n)) ClassHelpAndReturn;

  vtkMatrix4x4 * res =   this->_objectptr->GetObj()->GetCompositePerspectiveTransformMatrix(aspect, nearz, farz);
  return AMILabType<vtkMatrix4x4 >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkMatrix4x4

//---------------------------------------------------
//  Wrapping of vtkMatrix4x4 * vtkCamera::GetCompositeProjectionTransformMatrix(double aspect, double nearz, double farz)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetCompositeProjectionTransformMatrix::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'aspect'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'nearz'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'farz'")
  return_comments="returning a variable of type vtkMatrix4x4";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetCompositeProjectionTransformMatrix::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  double aspect;
  if (!get_val_param<double >(aspect,_p,_n)) ClassHelpAndReturn;

  double nearz;
  if (!get_val_param<double >(nearz,_p,_n)) ClassHelpAndReturn;

  double farz;
  if (!get_val_param<double >(farz,_p,_n)) ClassHelpAndReturn;

  vtkMatrix4x4 * res =   this->_objectptr->GetObj()->GetCompositeProjectionTransformMatrix(aspect, nearz, farz);
  return AMILabType<vtkMatrix4x4 >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkHomogeneousTransform

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetUserViewTransform(vtkHomogeneousTransform * transform)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetUserViewTransform::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkHomogeneousTransform, "parameter named 'transform'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetUserViewTransform::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkHomogeneousTransform > transform_smtptr;
  if (!get_val_smtptr_param<vtkHomogeneousTransform >(transform_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkHomogeneousTransform* transform = transform_smtptr.get();

  this->_objectptr->GetObj()->SetUserViewTransform(transform);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkHomogeneousTransform

//---------------------------------------------------
//  Wrapping of vtkHomogeneousTransform * vtkCamera::GetUserViewTransform()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetUserViewTransform::SetParametersComments()
{
  return_comments="returning a variable of type vtkHomogeneousTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetUserViewTransform::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkHomogeneousTransform * res =   this->_objectptr->GetObj()->GetUserViewTransform();
  return AMILabType<vtkHomogeneousTransform >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkHomogeneousTransform

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetUserTransform(vtkHomogeneousTransform * transform)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetUserTransform::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkHomogeneousTransform, "parameter named 'transform'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetUserTransform::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkHomogeneousTransform > transform_smtptr;
  if (!get_val_smtptr_param<vtkHomogeneousTransform >(transform_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkHomogeneousTransform* transform = transform_smtptr.get();

  this->_objectptr->GetObj()->SetUserTransform(transform);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkHomogeneousTransform

//---------------------------------------------------
//  Wrapping of vtkHomogeneousTransform * vtkCamera::GetUserTransform()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetUserTransform::SetParametersComments()
{
  return_comments="returning a variable of type vtkHomogeneousTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetUserTransform::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkHomogeneousTransform * res =   this->_objectptr->GetObj()->GetUserTransform();
  return AMILabType<vtkHomogeneousTransform >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkCamera::Render(vtkRenderer * param0)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_Render::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_Render::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderer > param0_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkRenderer* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->Render(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkCamera::GetViewingRaysMTime()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetViewingRaysMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetViewingRaysMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetViewingRaysMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::ViewingRaysModified()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_ViewingRaysModified::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_ViewingRaysModified::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ViewingRaysModified();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::GetFrustumPlanes(double aspect, double * planes)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetFrustumPlanes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'aspect'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'planes'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetFrustumPlanes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  double aspect;
  if (!get_val_param<double >(aspect,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<double > planes_smtptr;
  if (!get_val_smtptr_param<double >(planes_smtptr,_p,_n)) ClassHelpAndReturn;
  double* planes = planes_smtptr.get();

  this->_objectptr->GetObj()->GetFrustumPlanes(aspect, planes);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkCamera::GetOrientation()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetOrientation::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetOrientation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double * res =   this->_objectptr->GetObj()->GetOrientation();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkCamera::GetOrientationWXYZ()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetOrientationWXYZ::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetOrientationWXYZ::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double * res =   this->_objectptr->GetObj()->GetOrientationWXYZ();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetViewPlaneNormal(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetViewPlaneNormal_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetViewPlaneNormal_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetViewPlaneNormal(x, y, z);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCamera::SetViewPlaneNormal(...)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetViewPlaneNormal::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetViewPlaneNormal::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCamera::wrap_SetViewPlaneNormal_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkCamera::wrap_SetViewPlaneNormal_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetViewPlaneNormal(double const * a)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetViewPlaneNormal_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'a'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetViewPlaneNormal_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > a_smtptr;
  if (!get_val_smtptr_param<double >(a_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* a = a_smtptr.get();

  this->_objectptr->GetObj()->SetViewPlaneNormal(a);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::ComputeViewPlaneNormal()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_ComputeViewPlaneNormal::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_ComputeViewPlaneNormal::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ComputeViewPlaneNormal();
  return BasicVariable::ptr();
}
/* The following types are missing: vtkMatrix4x4

//---------------------------------------------------
//  Wrapping of vtkMatrix4x4 * vtkCamera::GetCameraLightTransformMatrix()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetCameraLightTransformMatrix::SetParametersComments()
{
  return_comments="returning a variable of type vtkMatrix4x4";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetCameraLightTransformMatrix::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkMatrix4x4 * res =   this->_objectptr->GetObj()->GetCameraLightTransformMatrix();
  return AMILabType<vtkMatrix4x4 >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkCamera::UpdateViewport(vtkRenderer * param0)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_UpdateViewport::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_UpdateViewport::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderer > param0_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkRenderer* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->UpdateViewport(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::SetLeftEye(int _arg)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_SetLeftEye::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_SetLeftEye::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetLeftEye(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkCamera::GetLeftEye()
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_GetLeftEye::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_GetLeftEye::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetLeftEye();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::ShallowCopy(vtkCamera * source)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_ShallowCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkCamera, "parameter named 'source'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_ShallowCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkCamera > source_smtptr;
  if (!get_val_smtptr_param<vtkCamera >(source_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkCamera* source = source_smtptr.get();

  this->_objectptr->GetObj()->ShallowCopy(source);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCamera::DeepCopy(vtkCamera * source)
//---------------------------------------------------
void WrapClass_vtkCamera::
    wrap_DeepCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkCamera, "parameter named 'source'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCamera::
    wrap_DeepCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkCamera > source_smtptr;
  if (!get_val_smtptr_param<vtkCamera >(source_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkCamera* source = source_smtptr.get();

  this->_objectptr->GetObj()->DeepCopy(source);
  return BasicVariable::ptr();
}

