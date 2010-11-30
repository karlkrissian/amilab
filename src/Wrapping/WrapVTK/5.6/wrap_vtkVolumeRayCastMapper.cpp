/**
 * C++ Interface: wrap_vtkVolumeRayCastMapper
 *
 * Description: wrapping vtkVolumeRayCastMapper
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
#include "wrap_vtkVolumeRayCastMapper.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkVolumeRayCastFunction.h"
#include "wrap_vtkRenderer.h"
#include "wrap_vtkVolume.h"
#include "wrap_vtkWindow.h"


#include "wrap_vtkVolumeRayCastMapper.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkVolumeRayCastMapper>::CreateVar( ParamList* p)
{
  WrapClass_vtkVolumeRayCastMapper::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkVolumeRayCastMapper);
AMI_DEFINE_VARFROMSMTPTR(vtkVolumeRayCastMapper);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkVolumeRayCastMapper>::CreateVar( vtkVolumeRayCastMapper* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkVolumeRayCastMapper> obj_ptr(val,smartpointer_nodeleter<vtkVolumeRayCastMapper>());
  return AMILabType<vtkVolumeRayCastMapper>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkVolumeRayCastMapper
//
Variable<AMIObject>::ptr WrapClass_vtkVolumeRayCastMapper::CreateVar( vtkVolumeRayCastMapper* sp)
{
  boost::shared_ptr<vtkVolumeRayCastMapper> di_ptr(
    sp,
    wxwindow_nodeleter<vtkVolumeRayCastMapper>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkVolumeRayCastMapper>::CreateVar(
      new WrapClass_vtkVolumeRayCastMapper(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::AddMethods(WrapClass<vtkVolumeRayCastMapper>::ptr this_ptr )
{
  
      // Add members from vtkVolumeMapper
      WrapClass_vtkVolumeMapper::ptr parent_vtkVolumeMapper(        boost::dynamic_pointer_cast<WrapClass_vtkVolumeMapper >(this_ptr));
      parent_vtkVolumeMapper->AddMethods(parent_vtkVolumeMapper);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_SetSampleDistance( this_ptr);
      AddVar_GetSampleDistance( this_ptr);
      AddVar_SetVolumeRayCastFunction( this_ptr);
      AddVar_GetVolumeRayCastFunction( this_ptr);
/* The following types are missing: vtkEncodedGradientEstimator
      AddVar_SetGradientEstimator( this_ptr);
*/
/* The following types are missing: vtkEncodedGradientEstimator
      AddVar_GetGradientEstimator( this_ptr);
*/
/* The following types are missing: vtkEncodedGradientShader
      AddVar_GetGradientShader( this_ptr);
*/
      AddVar_SetImageSampleDistance( this_ptr);
      AddVar_GetImageSampleDistanceMinValue( this_ptr);
      AddVar_GetImageSampleDistanceMaxValue( this_ptr);
      AddVar_GetImageSampleDistance( this_ptr);
      AddVar_SetMinimumImageSampleDistance( this_ptr);
      AddVar_GetMinimumImageSampleDistanceMinValue( this_ptr);
      AddVar_GetMinimumImageSampleDistanceMaxValue( this_ptr);
      AddVar_GetMinimumImageSampleDistance( this_ptr);
      AddVar_SetMaximumImageSampleDistance( this_ptr);
      AddVar_GetMaximumImageSampleDistanceMinValue( this_ptr);
      AddVar_GetMaximumImageSampleDistanceMaxValue( this_ptr);
      AddVar_GetMaximumImageSampleDistance( this_ptr);
      AddVar_SetAutoAdjustSampleDistances( this_ptr);
      AddVar_GetAutoAdjustSampleDistancesMinValue( this_ptr);
      AddVar_GetAutoAdjustSampleDistancesMaxValue( this_ptr);
      AddVar_GetAutoAdjustSampleDistances( this_ptr);
      AddVar_AutoAdjustSampleDistancesOn( this_ptr);
      AddVar_AutoAdjustSampleDistancesOff( this_ptr);
      AddVar_SetNumberOfThreads( this_ptr);
      AddVar_GetNumberOfThreads( this_ptr);
      AddVar_SetIntermixIntersectingGeometry( this_ptr);
      AddVar_GetIntermixIntersectingGeometryMinValue( this_ptr);
      AddVar_GetIntermixIntersectingGeometryMaxValue( this_ptr);
      AddVar_GetIntermixIntersectingGeometry( this_ptr);
      AddVar_IntermixIntersectingGeometryOn( this_ptr);
      AddVar_IntermixIntersectingGeometryOff( this_ptr);
      AddVar_Render( this_ptr);
      AddVar_ReleaseGraphicsResources( this_ptr);
      AddVar_GetZeroOpacityThreshold( this_ptr);
      AddVar_GetGradientMagnitudeScale_1( this_ptr);
      AddVar_GetGradientMagnitudeBias_1( this_ptr);
      AddVar_GetGradientMagnitudeScale( this_ptr);
      AddVar_GetGradientMagnitudeScale_2( this_ptr);
      AddVar_GetGradientMagnitudeBias( this_ptr);
      AddVar_GetGradientMagnitudeBias_2( this_ptr);



  
};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkVolumeRayCastMapper::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkVolumeRayCastMapper");
  
  // Static methods 
  WrapClass_vtkVolumeRayCastMapper::AddVar_New(amiobject->GetContext());
  WrapClass_vtkVolumeRayCastMapper::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkVolumeRayCastMapper::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkVolumeRayCastMapper * vtkVolumeRayCastMapper::New()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolumeRayCastMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolumeRayCastMapper * res =   vtkVolumeRayCastMapper::New();
  BasicVariable::ptr res_var = WrapClass_vtkVolumeRayCastMapper::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeRayCastMapper::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkVolumeRayCastMapper::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkVolumeRayCastMapper * vtkVolumeRayCastMapper::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkVolumeRayCastMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkVolumeRayCastMapper * res =   vtkVolumeRayCastMapper::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkVolumeRayCastMapper::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeRayCastMapper::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
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
//  Wrapping of vtkVolumeRayCastMapper * vtkVolumeRayCastMapper::NewInstance()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolumeRayCastMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolumeRayCastMapper * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkVolumeRayCastMapper::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastMapper::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
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
//  Wrapping of void vtkVolumeRayCastMapper::SetSampleDistance(double _arg)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_SetSampleDistance::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_SetSampleDistance::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetSampleDistance(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeRayCastMapper::GetSampleDistance()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetSampleDistance::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetSampleDistance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetSampleDistance();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastMapper::SetVolumeRayCastFunction(vtkVolumeRayCastFunction * param0)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_SetVolumeRayCastFunction::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVolumeRayCastFunction, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_SetVolumeRayCastFunction::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVolumeRayCastFunction > param0_smtptr;
  if (!get_val_smtptr_param<vtkVolumeRayCastFunction >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVolumeRayCastFunction* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetVolumeRayCastFunction(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkVolumeRayCastFunction * vtkVolumeRayCastMapper::GetVolumeRayCastFunction()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetVolumeRayCastFunction::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolumeRayCastFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetVolumeRayCastFunction::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolumeRayCastFunction * res =   this->_objectptr->GetObj()->GetVolumeRayCastFunction();
  BasicVariable::ptr res_var = WrapClass_vtkVolumeRayCastFunction::CreateVar(res);
  return res_var;
}
/* The following types are missing: vtkEncodedGradientEstimator

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastMapper::SetGradientEstimator(vtkEncodedGradientEstimator * gradest)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_SetGradientEstimator::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkEncodedGradientEstimator, "parameter named 'gradest'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_SetGradientEstimator::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkEncodedGradientEstimator > gradest_smtptr;
  if (!get_val_smtptr_param<vtkEncodedGradientEstimator >(gradest_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkEncodedGradientEstimator* gradest = gradest_smtptr.get();

  this->_objectptr->GetObj()->SetGradientEstimator(gradest);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkEncodedGradientEstimator

//---------------------------------------------------
//  Wrapping of vtkEncodedGradientEstimator * vtkVolumeRayCastMapper::GetGradientEstimator()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetGradientEstimator::SetParametersComments()
{
  return_comments="returning a variable of type vtkEncodedGradientEstimator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetGradientEstimator::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkEncodedGradientEstimator * res =   this->_objectptr->GetObj()->GetGradientEstimator();
  return AMILabType<vtkEncodedGradientEstimator >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkEncodedGradientShader

//---------------------------------------------------
//  Wrapping of vtkEncodedGradientShader * vtkVolumeRayCastMapper::GetGradientShader()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetGradientShader::SetParametersComments()
{
  return_comments="returning a variable of type vtkEncodedGradientShader";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetGradientShader::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkEncodedGradientShader * res =   this->_objectptr->GetObj()->GetGradientShader();
  return AMILabType<vtkEncodedGradientShader >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastMapper::SetImageSampleDistance(double _arg)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_SetImageSampleDistance::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_SetImageSampleDistance::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetImageSampleDistance(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeRayCastMapper::GetImageSampleDistanceMinValue()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetImageSampleDistanceMinValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetImageSampleDistanceMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetImageSampleDistanceMinValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeRayCastMapper::GetImageSampleDistanceMaxValue()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetImageSampleDistanceMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetImageSampleDistanceMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetImageSampleDistanceMaxValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeRayCastMapper::GetImageSampleDistance()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetImageSampleDistance::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetImageSampleDistance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetImageSampleDistance();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastMapper::SetMinimumImageSampleDistance(double _arg)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_SetMinimumImageSampleDistance::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_SetMinimumImageSampleDistance::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMinimumImageSampleDistance(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeRayCastMapper::GetMinimumImageSampleDistanceMinValue()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistanceMinValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistanceMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetMinimumImageSampleDistanceMinValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeRayCastMapper::GetMinimumImageSampleDistanceMaxValue()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistanceMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistanceMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetMinimumImageSampleDistanceMaxValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeRayCastMapper::GetMinimumImageSampleDistance()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistance::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetMinimumImageSampleDistance();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastMapper::SetMaximumImageSampleDistance(double _arg)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_SetMaximumImageSampleDistance::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_SetMaximumImageSampleDistance::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMaximumImageSampleDistance(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeRayCastMapper::GetMaximumImageSampleDistanceMinValue()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistanceMinValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistanceMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetMaximumImageSampleDistanceMinValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeRayCastMapper::GetMaximumImageSampleDistanceMaxValue()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistanceMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistanceMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetMaximumImageSampleDistanceMaxValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeRayCastMapper::GetMaximumImageSampleDistance()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistance::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetMaximumImageSampleDistance();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastMapper::SetAutoAdjustSampleDistances(int _arg)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_SetAutoAdjustSampleDistances::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_SetAutoAdjustSampleDistances::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAutoAdjustSampleDistances(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeRayCastMapper::GetAutoAdjustSampleDistancesMinValue()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistancesMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistancesMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAutoAdjustSampleDistancesMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeRayCastMapper::GetAutoAdjustSampleDistancesMaxValue()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistancesMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistancesMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAutoAdjustSampleDistancesMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeRayCastMapper::GetAutoAdjustSampleDistances()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistances::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistances::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAutoAdjustSampleDistances();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastMapper::AutoAdjustSampleDistancesOn()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_AutoAdjustSampleDistancesOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_AutoAdjustSampleDistancesOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AutoAdjustSampleDistancesOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastMapper::AutoAdjustSampleDistancesOff()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_AutoAdjustSampleDistancesOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_AutoAdjustSampleDistancesOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AutoAdjustSampleDistancesOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastMapper::SetNumberOfThreads(int num)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_SetNumberOfThreads::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'num'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_SetNumberOfThreads::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int num;
  if (!get_val_param<int >(num,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetNumberOfThreads(num);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeRayCastMapper::GetNumberOfThreads()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetNumberOfThreads::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetNumberOfThreads::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfThreads();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastMapper::SetIntermixIntersectingGeometry(int _arg)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_SetIntermixIntersectingGeometry::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_SetIntermixIntersectingGeometry::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetIntermixIntersectingGeometry(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeRayCastMapper::GetIntermixIntersectingGeometryMinValue()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetIntermixIntersectingGeometryMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetIntermixIntersectingGeometryMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetIntermixIntersectingGeometryMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeRayCastMapper::GetIntermixIntersectingGeometryMaxValue()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetIntermixIntersectingGeometryMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetIntermixIntersectingGeometryMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetIntermixIntersectingGeometryMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeRayCastMapper::GetIntermixIntersectingGeometry()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetIntermixIntersectingGeometry::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetIntermixIntersectingGeometry::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetIntermixIntersectingGeometry();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastMapper::IntermixIntersectingGeometryOn()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_IntermixIntersectingGeometryOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_IntermixIntersectingGeometryOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->IntermixIntersectingGeometryOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastMapper::IntermixIntersectingGeometryOff()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_IntermixIntersectingGeometryOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_IntermixIntersectingGeometryOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->IntermixIntersectingGeometryOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastMapper::Render(vtkRenderer * param0, vtkVolume * param1)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_Render::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( vtkVolume, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_Render::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderer > param0_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkRenderer* param0 = param0_smtptr.get();

  boost::shared_ptr<vtkVolume > param1_smtptr;
  if (!get_val_smtptr_param<vtkVolume >(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVolume* param1 = param1_smtptr.get();

  this->_objectptr->GetObj()->Render(param0, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastMapper::ReleaseGraphicsResources(vtkWindow * param0)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_ReleaseGraphicsResources::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkWindow, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_ReleaseGraphicsResources::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkWindow > param0_smtptr;
  if (!get_val_smtptr_param<vtkWindow >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkWindow* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->ReleaseGraphicsResources(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkVolumeRayCastMapper::GetZeroOpacityThreshold(vtkVolume * vol)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetZeroOpacityThreshold::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVolume, "parameter named 'vol'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetZeroOpacityThreshold::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVolume > vol_smtptr;
  if (!get_val_smtptr_param<vtkVolume >(vol_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVolume* vol = vol_smtptr.get();

  float res =   this->_objectptr->GetObj()->GetZeroOpacityThreshold(vol);
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkVolumeRayCastMapper::GetGradientMagnitudeScale()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetGradientMagnitudeScale_1::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetGradientMagnitudeScale_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  float res =   this->_objectptr->GetObj()->GetGradientMagnitudeScale();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkVolumeRayCastMapper::GetGradientMagnitudeBias()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetGradientMagnitudeBias_1::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetGradientMagnitudeBias_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  float res =   this->_objectptr->GetObj()->GetGradientMagnitudeBias();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeRayCastMapper::GetGradientMagnitudeScale(...)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetGradientMagnitudeScale::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetGradientMagnitudeScale::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeRayCastMapper::wrap_GetGradientMagnitudeScale_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeRayCastMapper::wrap_GetGradientMagnitudeScale_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of float vtkVolumeRayCastMapper::GetGradientMagnitudeScale(int param0)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetGradientMagnitudeScale_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetGradientMagnitudeScale_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  float res =   this->_objectptr->GetObj()->GetGradientMagnitudeScale(param0);
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeRayCastMapper::GetGradientMagnitudeBias(...)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetGradientMagnitudeBias::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetGradientMagnitudeBias::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeRayCastMapper::wrap_GetGradientMagnitudeBias_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeRayCastMapper::wrap_GetGradientMagnitudeBias_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of float vtkVolumeRayCastMapper::GetGradientMagnitudeBias(int param0)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastMapper::
    wrap_GetGradientMagnitudeBias_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastMapper::
    wrap_GetGradientMagnitudeBias_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  float res =   this->_objectptr->GetObj()->GetGradientMagnitudeBias(param0);
  return AMILabType<float >::CreateVar(res);
}

