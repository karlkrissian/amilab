/**
 * C++ Interface: wrap_vtkVolumeProperty
 *
 * Description: wrapping vtkVolumeProperty
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
#include "wrap_vtkVolumeProperty.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_vtkPiecewiseFunction.h"
#include "wrap_vtkColorTransferFunction.h"
#include "wrap_vtkTimeStamp.h"


#include "wrap_vtkVolumeProperty.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkVolumeProperty>::CreateVar( ParamList* p)
{
  WrapClass_vtkVolumeProperty::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkVolumeProperty);
AMI_DEFINE_VARFROMSMTPTR(vtkVolumeProperty);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkVolumeProperty>::CreateVar( vtkVolumeProperty* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkVolumeProperty> obj_ptr(val,smartpointer_nodeleter<vtkVolumeProperty>());
  return AMILabType<vtkVolumeProperty>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkVolumeProperty
//
Variable<AMIObject>::ptr WrapClass_vtkVolumeProperty::CreateVar( vtkVolumeProperty* sp)
{
  boost::shared_ptr<vtkVolumeProperty> di_ptr(
    sp,
    wxwindow_nodeleter<vtkVolumeProperty>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkVolumeProperty>::CreateVar(
      new WrapClass_vtkVolumeProperty(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkVolumeProperty::AddMethods(WrapClass<vtkVolumeProperty>::ptr this_ptr )
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
      AddVar_DeepCopy( this_ptr);
      AddVar_GetMTime( this_ptr);
      AddVar_SetIndependentComponents( this_ptr);
      AddVar_GetIndependentComponentsMinValue( this_ptr);
      AddVar_GetIndependentComponentsMaxValue( this_ptr);
      AddVar_GetIndependentComponents( this_ptr);
      AddVar_IndependentComponentsOn( this_ptr);
      AddVar_IndependentComponentsOff( this_ptr);
      AddVar_SetInterpolationType( this_ptr);
      AddVar_GetInterpolationTypeMinValue( this_ptr);
      AddVar_GetInterpolationTypeMaxValue( this_ptr);
      AddVar_GetInterpolationType( this_ptr);
      AddVar_SetInterpolationTypeToNearest( this_ptr);
      AddVar_SetInterpolationTypeToLinear( this_ptr);
      AddVar_GetInterpolationTypeAsString( this_ptr);
      AddVar_SetComponentWeight( this_ptr);
      AddVar_GetComponentWeight( this_ptr);
      AddVar_SetColor_1( this_ptr);
      AddVar_SetColor( this_ptr);
      AddVar_SetColor_2( this_ptr);
      AddVar_SetColor_3( this_ptr);
      AddVar_SetColor_4( this_ptr);
      AddVar_GetColorChannels_1( this_ptr);
      AddVar_GetColorChannels( this_ptr);
      AddVar_GetColorChannels_2( this_ptr);
      AddVar_GetGrayTransferFunction_1( this_ptr);
      AddVar_GetGrayTransferFunction( this_ptr);
      AddVar_GetGrayTransferFunction_2( this_ptr);
      AddVar_GetRGBTransferFunction_1( this_ptr);
      AddVar_GetRGBTransferFunction( this_ptr);
      AddVar_GetRGBTransferFunction_2( this_ptr);
      AddVar_SetScalarOpacity_1( this_ptr);
      AddVar_SetScalarOpacity( this_ptr);
      AddVar_SetScalarOpacity_2( this_ptr);
      AddVar_GetScalarOpacity_1( this_ptr);
      AddVar_GetScalarOpacity( this_ptr);
      AddVar_GetScalarOpacity_2( this_ptr);
      AddVar_SetScalarOpacityUnitDistance_1( this_ptr);
      AddVar_SetScalarOpacityUnitDistance( this_ptr);
      AddVar_SetScalarOpacityUnitDistance_2( this_ptr);
      AddVar_GetScalarOpacityUnitDistance_1( this_ptr);
      AddVar_GetScalarOpacityUnitDistance( this_ptr);
      AddVar_GetScalarOpacityUnitDistance_2( this_ptr);
      AddVar_SetGradientOpacity_1( this_ptr);
      AddVar_SetGradientOpacity( this_ptr);
      AddVar_SetGradientOpacity_2( this_ptr);
      AddVar_GetGradientOpacity_1( this_ptr);
      AddVar_GetGradientOpacity( this_ptr);
      AddVar_GetGradientOpacity_2( this_ptr);
      AddVar_SetDisableGradientOpacity_1( this_ptr);
      AddVar_SetDisableGradientOpacity( this_ptr);
      AddVar_SetDisableGradientOpacity_2( this_ptr);
      AddVar_DisableGradientOpacityOn_1( this_ptr);
      AddVar_DisableGradientOpacityOn( this_ptr);
      AddVar_DisableGradientOpacityOn_2( this_ptr);
      AddVar_DisableGradientOpacityOff_1( this_ptr);
      AddVar_DisableGradientOpacityOff( this_ptr);
      AddVar_DisableGradientOpacityOff_2( this_ptr);
      AddVar_GetDisableGradientOpacity_1( this_ptr);
      AddVar_GetDisableGradientOpacity( this_ptr);
      AddVar_GetDisableGradientOpacity_2( this_ptr);
      AddVar_GetStoredGradientOpacity_1( this_ptr);
      AddVar_GetStoredGradientOpacity( this_ptr);
      AddVar_GetStoredGradientOpacity_2( this_ptr);
      AddVar_SetShade_1( this_ptr);
      AddVar_SetShade( this_ptr);
      AddVar_SetShade_2( this_ptr);
      AddVar_GetShade_1( this_ptr);
      AddVar_GetShade( this_ptr);
      AddVar_GetShade_2( this_ptr);
      AddVar_ShadeOn_1( this_ptr);
      AddVar_ShadeOn( this_ptr);
      AddVar_ShadeOn_2( this_ptr);
      AddVar_ShadeOff_1( this_ptr);
      AddVar_ShadeOff( this_ptr);
      AddVar_ShadeOff_2( this_ptr);
      AddVar_SetAmbient_1( this_ptr);
      AddVar_SetAmbient( this_ptr);
      AddVar_SetAmbient_2( this_ptr);
      AddVar_GetAmbient_1( this_ptr);
      AddVar_GetAmbient( this_ptr);
      AddVar_GetAmbient_2( this_ptr);
      AddVar_SetDiffuse_1( this_ptr);
      AddVar_SetDiffuse( this_ptr);
      AddVar_SetDiffuse_2( this_ptr);
      AddVar_GetDiffuse_1( this_ptr);
      AddVar_GetDiffuse( this_ptr);
      AddVar_GetDiffuse_2( this_ptr);
      AddVar_SetSpecular_1( this_ptr);
      AddVar_SetSpecular( this_ptr);
      AddVar_SetSpecular_2( this_ptr);
      AddVar_GetSpecular_1( this_ptr);
      AddVar_GetSpecular( this_ptr);
      AddVar_GetSpecular_2( this_ptr);
      AddVar_SetSpecularPower_1( this_ptr);
      AddVar_SetSpecularPower( this_ptr);
      AddVar_SetSpecularPower_2( this_ptr);
      AddVar_GetSpecularPower_1( this_ptr);
      AddVar_GetSpecularPower( this_ptr);
      AddVar_GetSpecularPower_2( this_ptr);
      AddVar_UpdateMTimes( this_ptr);
      AddVar_GetGradientOpacityMTime_1( this_ptr);
      AddVar_GetGradientOpacityMTime( this_ptr);
      AddVar_GetGradientOpacityMTime_2( this_ptr);
      AddVar_GetScalarOpacityMTime_1( this_ptr);
      AddVar_GetScalarOpacityMTime( this_ptr);
      AddVar_GetScalarOpacityMTime_2( this_ptr);
      AddVar_GetRGBTransferFunctionMTime_1( this_ptr);
      AddVar_GetRGBTransferFunctionMTime( this_ptr);
      AddVar_GetRGBTransferFunctionMTime_2( this_ptr);
      AddVar_GetGrayTransferFunctionMTime_1( this_ptr);
      AddVar_GetGrayTransferFunctionMTime( this_ptr);
      AddVar_GetGrayTransferFunctionMTime_2( this_ptr);



  
};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkVolumeProperty::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkVolumeProperty");
  
  // Static methods 
  WrapClass_vtkVolumeProperty::AddVar_New(amiobject->GetContext());
  WrapClass_vtkVolumeProperty::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkVolumeProperty::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkVolumeProperty * vtkVolumeProperty::New()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolumeProperty";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolumeProperty * res =   vtkVolumeProperty::New();
  BasicVariable::ptr res_var = WrapClass_vtkVolumeProperty::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeProperty::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkVolumeProperty::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkVolumeProperty * vtkVolumeProperty::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkVolumeProperty";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkVolumeProperty * res =   vtkVolumeProperty::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkVolumeProperty::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeProperty::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
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
//  Wrapping of vtkVolumeProperty * vtkVolumeProperty::NewInstance()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolumeProperty";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolumeProperty * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkVolumeProperty::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
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
//  Wrapping of void vtkVolumeProperty::DeepCopy(vtkVolumeProperty * p)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_DeepCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVolumeProperty, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_DeepCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVolumeProperty > p_smtptr;
  if (!get_val_smtptr_param<vtkVolumeProperty >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVolumeProperty* p = p_smtptr.get();

  this->_objectptr->GetObj()->DeepCopy(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkVolumeProperty::GetMTime()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetIndependentComponents(int _arg)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetIndependentComponents::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetIndependentComponents::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetIndependentComponents(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeProperty::GetIndependentComponentsMinValue()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetIndependentComponentsMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetIndependentComponentsMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetIndependentComponentsMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeProperty::GetIndependentComponentsMaxValue()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetIndependentComponentsMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetIndependentComponentsMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetIndependentComponentsMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeProperty::GetIndependentComponents()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetIndependentComponents::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetIndependentComponents::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetIndependentComponents();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::IndependentComponentsOn()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_IndependentComponentsOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_IndependentComponentsOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->IndependentComponentsOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::IndependentComponentsOff()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_IndependentComponentsOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_IndependentComponentsOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->IndependentComponentsOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetInterpolationType(int _arg)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetInterpolationType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetInterpolationType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInterpolationType(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeProperty::GetInterpolationTypeMinValue()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetInterpolationTypeMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetInterpolationTypeMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetInterpolationTypeMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeProperty::GetInterpolationTypeMaxValue()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetInterpolationTypeMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetInterpolationTypeMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetInterpolationTypeMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeProperty::GetInterpolationType()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetInterpolationType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetInterpolationType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetInterpolationType();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetInterpolationTypeToNearest()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetInterpolationTypeToNearest::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetInterpolationTypeToNearest::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInterpolationTypeToNearest();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetInterpolationTypeToLinear()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetInterpolationTypeToLinear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetInterpolationTypeToLinear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInterpolationTypeToLinear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char const * vtkVolumeProperty::GetInterpolationTypeAsString()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetInterpolationTypeAsString::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetInterpolationTypeAsString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   this->_objectptr->GetObj()->GetInterpolationTypeAsString();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetComponentWeight(int index, double value)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetComponentWeight::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetComponentWeight::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,false)) ClassHelpAndReturn;

  double value;
  if (!get_val_param<double >(value,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetComponentWeight(index, value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeProperty::GetComponentWeight(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetComponentWeight::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetComponentWeight::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,false)) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetComponentWeight(index);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetColor(int index, vtkPiecewiseFunction * function)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetColor_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( vtkPiecewiseFunction, "parameter named 'function'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetColor_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<vtkPiecewiseFunction > function_smtptr;
  if (!get_val_smtptr_param<vtkPiecewiseFunction >(function_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkPiecewiseFunction* function = function_smtptr.get();

  this->_objectptr->GetObj()->SetColor(index, function);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::SetColor(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetColor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetColor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_SetColor_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_SetColor_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_SetColor_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_SetColor_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetColor(vtkPiecewiseFunction * f)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetColor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPiecewiseFunction, "parameter named 'f'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetColor_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkPiecewiseFunction > f_smtptr;
  if (!get_val_smtptr_param<vtkPiecewiseFunction >(f_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkPiecewiseFunction* f = f_smtptr.get();

  this->_objectptr->GetObj()->SetColor(f);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetColor(int index, vtkColorTransferFunction * function)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetColor_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( vtkColorTransferFunction, "parameter named 'function'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetColor_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<vtkColorTransferFunction > function_smtptr;
  if (!get_val_smtptr_param<vtkColorTransferFunction >(function_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkColorTransferFunction* function = function_smtptr.get();

  this->_objectptr->GetObj()->SetColor(index, function);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetColor(vtkColorTransferFunction * f)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetColor_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkColorTransferFunction, "parameter named 'f'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetColor_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkColorTransferFunction > f_smtptr;
  if (!get_val_smtptr_param<vtkColorTransferFunction >(f_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkColorTransferFunction* f = f_smtptr.get();

  this->_objectptr->GetObj()->SetColor(f);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeProperty::GetColorChannels(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetColorChannels_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetColorChannels_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->GetColorChannels(index);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetColorChannels(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetColorChannels::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetColorChannels::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetColorChannels_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetColorChannels_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeProperty::GetColorChannels()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetColorChannels_2::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetColorChannels_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->GetColorChannels();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkPiecewiseFunction * vtkVolumeProperty::GetGrayTransferFunction(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetGrayTransferFunction_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type vtkPiecewiseFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetGrayTransferFunction_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkPiecewiseFunction * res =   this->_objectptr->GetObj()->GetGrayTransferFunction(index);
  BasicVariable::ptr res_var = WrapClass_vtkPiecewiseFunction::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetGrayTransferFunction(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetGrayTransferFunction::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetGrayTransferFunction::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetGrayTransferFunction_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetGrayTransferFunction_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkPiecewiseFunction * vtkVolumeProperty::GetGrayTransferFunction()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetGrayTransferFunction_2::SetParametersComments()
{
  return_comments="returning a variable of type vtkPiecewiseFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetGrayTransferFunction_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkPiecewiseFunction * res =   this->_objectptr->GetObj()->GetGrayTransferFunction();
  BasicVariable::ptr res_var = WrapClass_vtkPiecewiseFunction::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkColorTransferFunction * vtkVolumeProperty::GetRGBTransferFunction(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetRGBTransferFunction_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type vtkColorTransferFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetRGBTransferFunction_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkColorTransferFunction * res =   this->_objectptr->GetObj()->GetRGBTransferFunction(index);
  BasicVariable::ptr res_var = WrapClass_vtkColorTransferFunction::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetRGBTransferFunction(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetRGBTransferFunction::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetRGBTransferFunction::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetRGBTransferFunction_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetRGBTransferFunction_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkColorTransferFunction * vtkVolumeProperty::GetRGBTransferFunction()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetRGBTransferFunction_2::SetParametersComments()
{
  return_comments="returning a variable of type vtkColorTransferFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetRGBTransferFunction_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkColorTransferFunction * res =   this->_objectptr->GetObj()->GetRGBTransferFunction();
  BasicVariable::ptr res_var = WrapClass_vtkColorTransferFunction::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetScalarOpacity(int index, vtkPiecewiseFunction * function)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetScalarOpacity_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( vtkPiecewiseFunction, "parameter named 'function'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetScalarOpacity_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<vtkPiecewiseFunction > function_smtptr;
  if (!get_val_smtptr_param<vtkPiecewiseFunction >(function_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkPiecewiseFunction* function = function_smtptr.get();

  this->_objectptr->GetObj()->SetScalarOpacity(index, function);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::SetScalarOpacity(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetScalarOpacity::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetScalarOpacity::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_SetScalarOpacity_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_SetScalarOpacity_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetScalarOpacity(vtkPiecewiseFunction * f)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetScalarOpacity_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPiecewiseFunction, "parameter named 'f'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetScalarOpacity_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkPiecewiseFunction > f_smtptr;
  if (!get_val_smtptr_param<vtkPiecewiseFunction >(f_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkPiecewiseFunction* f = f_smtptr.get();

  this->_objectptr->GetObj()->SetScalarOpacity(f);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkPiecewiseFunction * vtkVolumeProperty::GetScalarOpacity(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacity_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type vtkPiecewiseFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacity_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkPiecewiseFunction * res =   this->_objectptr->GetObj()->GetScalarOpacity(index);
  BasicVariable::ptr res_var = WrapClass_vtkPiecewiseFunction::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetScalarOpacity(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacity::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacity::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetScalarOpacity_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetScalarOpacity_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkPiecewiseFunction * vtkVolumeProperty::GetScalarOpacity()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacity_2::SetParametersComments()
{
  return_comments="returning a variable of type vtkPiecewiseFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacity_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkPiecewiseFunction * res =   this->_objectptr->GetObj()->GetScalarOpacity();
  BasicVariable::ptr res_var = WrapClass_vtkPiecewiseFunction::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetScalarOpacityUnitDistance(int index, double distance)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetScalarOpacityUnitDistance_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'distance'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetScalarOpacityUnitDistance_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  double distance;
  if (!get_val_param<double >(distance,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetScalarOpacityUnitDistance(index, distance);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::SetScalarOpacityUnitDistance(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetScalarOpacityUnitDistance::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetScalarOpacityUnitDistance::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_SetScalarOpacityUnitDistance_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_SetScalarOpacityUnitDistance_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetScalarOpacityUnitDistance(double distance)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetScalarOpacityUnitDistance_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'distance'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetScalarOpacityUnitDistance_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double distance;
  if (!get_val_param<double >(distance,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetScalarOpacityUnitDistance(distance);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeProperty::GetScalarOpacityUnitDistance(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacityUnitDistance_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacityUnitDistance_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  double res =   this->_objectptr->GetObj()->GetScalarOpacityUnitDistance(index);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetScalarOpacityUnitDistance(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacityUnitDistance::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacityUnitDistance::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetScalarOpacityUnitDistance_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetScalarOpacityUnitDistance_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeProperty::GetScalarOpacityUnitDistance()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacityUnitDistance_2::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacityUnitDistance_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double res =   this->_objectptr->GetObj()->GetScalarOpacityUnitDistance();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetGradientOpacity(int index, vtkPiecewiseFunction * function)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetGradientOpacity_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( vtkPiecewiseFunction, "parameter named 'function'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetGradientOpacity_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<vtkPiecewiseFunction > function_smtptr;
  if (!get_val_smtptr_param<vtkPiecewiseFunction >(function_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkPiecewiseFunction* function = function_smtptr.get();

  this->_objectptr->GetObj()->SetGradientOpacity(index, function);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::SetGradientOpacity(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetGradientOpacity::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetGradientOpacity::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_SetGradientOpacity_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_SetGradientOpacity_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetGradientOpacity(vtkPiecewiseFunction * function)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetGradientOpacity_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPiecewiseFunction, "parameter named 'function'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetGradientOpacity_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkPiecewiseFunction > function_smtptr;
  if (!get_val_smtptr_param<vtkPiecewiseFunction >(function_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkPiecewiseFunction* function = function_smtptr.get();

  this->_objectptr->GetObj()->SetGradientOpacity(function);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkPiecewiseFunction * vtkVolumeProperty::GetGradientOpacity(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetGradientOpacity_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type vtkPiecewiseFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetGradientOpacity_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkPiecewiseFunction * res =   this->_objectptr->GetObj()->GetGradientOpacity(index);
  BasicVariable::ptr res_var = WrapClass_vtkPiecewiseFunction::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetGradientOpacity(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetGradientOpacity::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetGradientOpacity::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetGradientOpacity_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetGradientOpacity_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkPiecewiseFunction * vtkVolumeProperty::GetGradientOpacity()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetGradientOpacity_2::SetParametersComments()
{
  return_comments="returning a variable of type vtkPiecewiseFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetGradientOpacity_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkPiecewiseFunction * res =   this->_objectptr->GetObj()->GetGradientOpacity();
  BasicVariable::ptr res_var = WrapClass_vtkPiecewiseFunction::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetDisableGradientOpacity(int index, int value)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetDisableGradientOpacity_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetDisableGradientOpacity_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  int value;
  if (!get_val_param<int >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetDisableGradientOpacity(index, value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::SetDisableGradientOpacity(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetDisableGradientOpacity::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetDisableGradientOpacity::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_SetDisableGradientOpacity_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_SetDisableGradientOpacity_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetDisableGradientOpacity(int value)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetDisableGradientOpacity_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetDisableGradientOpacity_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int value;
  if (!get_val_param<int >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetDisableGradientOpacity(value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::DisableGradientOpacityOn(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_DisableGradientOpacityOn_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_DisableGradientOpacityOn_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DisableGradientOpacityOn(index);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::DisableGradientOpacityOn(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_DisableGradientOpacityOn::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_DisableGradientOpacityOn::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_DisableGradientOpacityOn_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_DisableGradientOpacityOn_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::DisableGradientOpacityOn()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_DisableGradientOpacityOn_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_DisableGradientOpacityOn_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DisableGradientOpacityOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::DisableGradientOpacityOff(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_DisableGradientOpacityOff_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_DisableGradientOpacityOff_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DisableGradientOpacityOff(index);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::DisableGradientOpacityOff(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_DisableGradientOpacityOff::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_DisableGradientOpacityOff::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_DisableGradientOpacityOff_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_DisableGradientOpacityOff_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::DisableGradientOpacityOff()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_DisableGradientOpacityOff_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_DisableGradientOpacityOff_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DisableGradientOpacityOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeProperty::GetDisableGradientOpacity(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetDisableGradientOpacity_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetDisableGradientOpacity_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->GetDisableGradientOpacity(index);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetDisableGradientOpacity(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetDisableGradientOpacity::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetDisableGradientOpacity::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetDisableGradientOpacity_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetDisableGradientOpacity_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeProperty::GetDisableGradientOpacity()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetDisableGradientOpacity_2::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetDisableGradientOpacity_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->GetDisableGradientOpacity();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkPiecewiseFunction * vtkVolumeProperty::GetStoredGradientOpacity(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetStoredGradientOpacity_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type vtkPiecewiseFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetStoredGradientOpacity_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkPiecewiseFunction * res =   this->_objectptr->GetObj()->GetStoredGradientOpacity(index);
  BasicVariable::ptr res_var = WrapClass_vtkPiecewiseFunction::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetStoredGradientOpacity(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetStoredGradientOpacity::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetStoredGradientOpacity::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetStoredGradientOpacity_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetStoredGradientOpacity_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkPiecewiseFunction * vtkVolumeProperty::GetStoredGradientOpacity()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetStoredGradientOpacity_2::SetParametersComments()
{
  return_comments="returning a variable of type vtkPiecewiseFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetStoredGradientOpacity_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkPiecewiseFunction * res =   this->_objectptr->GetObj()->GetStoredGradientOpacity();
  BasicVariable::ptr res_var = WrapClass_vtkPiecewiseFunction::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetShade(int index, int value)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetShade_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetShade_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  int value;
  if (!get_val_param<int >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetShade(index, value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::SetShade(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetShade::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetShade::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_SetShade_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_SetShade_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetShade(int value)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetShade_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetShade_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int value;
  if (!get_val_param<int >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetShade(value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeProperty::GetShade(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetShade_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetShade_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->GetShade(index);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetShade(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetShade::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetShade::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetShade_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetShade_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeProperty::GetShade()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetShade_2::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetShade_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->GetShade();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::ShadeOn(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_ShadeOn_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_ShadeOn_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->ShadeOn(index);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::ShadeOn(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_ShadeOn::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_ShadeOn::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_ShadeOn_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_ShadeOn_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::ShadeOn()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_ShadeOn_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_ShadeOn_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->ShadeOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::ShadeOff(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_ShadeOff_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_ShadeOff_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->ShadeOff(index);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::ShadeOff(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_ShadeOff::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_ShadeOff::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_ShadeOff_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_ShadeOff_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::ShadeOff()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_ShadeOff_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_ShadeOff_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->ShadeOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetAmbient(int index, double value)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetAmbient_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetAmbient_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  double value;
  if (!get_val_param<double >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetAmbient(index, value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::SetAmbient(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetAmbient::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetAmbient::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_SetAmbient_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_SetAmbient_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetAmbient(double value)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetAmbient_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetAmbient_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double value;
  if (!get_val_param<double >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetAmbient(value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeProperty::GetAmbient(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetAmbient_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetAmbient_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  double res =   this->_objectptr->GetObj()->GetAmbient(index);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetAmbient(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetAmbient::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetAmbient::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetAmbient_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetAmbient_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeProperty::GetAmbient()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetAmbient_2::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetAmbient_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double res =   this->_objectptr->GetObj()->GetAmbient();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetDiffuse(int index, double value)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetDiffuse_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetDiffuse_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  double value;
  if (!get_val_param<double >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetDiffuse(index, value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::SetDiffuse(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetDiffuse::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetDiffuse::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_SetDiffuse_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_SetDiffuse_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetDiffuse(double value)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetDiffuse_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetDiffuse_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double value;
  if (!get_val_param<double >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetDiffuse(value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeProperty::GetDiffuse(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetDiffuse_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetDiffuse_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  double res =   this->_objectptr->GetObj()->GetDiffuse(index);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetDiffuse(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetDiffuse::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetDiffuse::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetDiffuse_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetDiffuse_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeProperty::GetDiffuse()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetDiffuse_2::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetDiffuse_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double res =   this->_objectptr->GetObj()->GetDiffuse();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetSpecular(int index, double value)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetSpecular_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetSpecular_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  double value;
  if (!get_val_param<double >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetSpecular(index, value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::SetSpecular(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetSpecular::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetSpecular::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_SetSpecular_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_SetSpecular_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetSpecular(double value)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetSpecular_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetSpecular_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double value;
  if (!get_val_param<double >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetSpecular(value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeProperty::GetSpecular(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetSpecular_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetSpecular_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  double res =   this->_objectptr->GetObj()->GetSpecular(index);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetSpecular(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetSpecular::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetSpecular::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetSpecular_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetSpecular_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeProperty::GetSpecular()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetSpecular_2::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetSpecular_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double res =   this->_objectptr->GetObj()->GetSpecular();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetSpecularPower(int index, double value)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetSpecularPower_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetSpecularPower_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  double value;
  if (!get_val_param<double >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetSpecularPower(index, value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::SetSpecularPower(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetSpecularPower::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetSpecularPower::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_SetSpecularPower_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_SetSpecularPower_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::SetSpecularPower(double value)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_SetSpecularPower_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_SetSpecularPower_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double value;
  if (!get_val_param<double >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetSpecularPower(value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeProperty::GetSpecularPower(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetSpecularPower_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetSpecularPower_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  double res =   this->_objectptr->GetObj()->GetSpecularPower(index);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetSpecularPower(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetSpecularPower::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetSpecularPower::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetSpecularPower_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetSpecularPower_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double vtkVolumeProperty::GetSpecularPower()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetSpecularPower_2::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetSpecularPower_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double res =   this->_objectptr->GetObj()->GetSpecularPower();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeProperty::UpdateMTimes()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_UpdateMTimes::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_UpdateMTimes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UpdateMTimes();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkTimeStamp vtkVolumeProperty::GetGradientOpacityMTime(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetGradientOpacityMTime_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type vtkTimeStamp";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetGradientOpacityMTime_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkTimeStamp res =   this->_objectptr->GetObj()->GetGradientOpacityMTime(index);
  return AMILabType<vtkTimeStamp >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetGradientOpacityMTime(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetGradientOpacityMTime::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetGradientOpacityMTime::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetGradientOpacityMTime_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetGradientOpacityMTime_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkTimeStamp vtkVolumeProperty::GetGradientOpacityMTime()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetGradientOpacityMTime_2::SetParametersComments()
{
  return_comments="returning a variable of type vtkTimeStamp";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetGradientOpacityMTime_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkTimeStamp res =   this->_objectptr->GetObj()->GetGradientOpacityMTime();
  return AMILabType<vtkTimeStamp >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkTimeStamp vtkVolumeProperty::GetScalarOpacityMTime(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacityMTime_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type vtkTimeStamp";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacityMTime_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkTimeStamp res =   this->_objectptr->GetObj()->GetScalarOpacityMTime(index);
  return AMILabType<vtkTimeStamp >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetScalarOpacityMTime(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacityMTime::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacityMTime::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetScalarOpacityMTime_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetScalarOpacityMTime_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkTimeStamp vtkVolumeProperty::GetScalarOpacityMTime()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacityMTime_2::SetParametersComments()
{
  return_comments="returning a variable of type vtkTimeStamp";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetScalarOpacityMTime_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkTimeStamp res =   this->_objectptr->GetObj()->GetScalarOpacityMTime();
  return AMILabType<vtkTimeStamp >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkTimeStamp vtkVolumeProperty::GetRGBTransferFunctionMTime(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetRGBTransferFunctionMTime_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type vtkTimeStamp";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetRGBTransferFunctionMTime_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkTimeStamp res =   this->_objectptr->GetObj()->GetRGBTransferFunctionMTime(index);
  return AMILabType<vtkTimeStamp >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetRGBTransferFunctionMTime(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetRGBTransferFunctionMTime::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetRGBTransferFunctionMTime::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetRGBTransferFunctionMTime_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetRGBTransferFunctionMTime_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkTimeStamp vtkVolumeProperty::GetRGBTransferFunctionMTime()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetRGBTransferFunctionMTime_2::SetParametersComments()
{
  return_comments="returning a variable of type vtkTimeStamp";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetRGBTransferFunctionMTime_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkTimeStamp res =   this->_objectptr->GetObj()->GetRGBTransferFunctionMTime();
  return AMILabType<vtkTimeStamp >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkTimeStamp vtkVolumeProperty::GetGrayTransferFunctionMTime(int index)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetGrayTransferFunctionMTime_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type vtkTimeStamp";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetGrayTransferFunctionMTime_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkTimeStamp res =   this->_objectptr->GetObj()->GetGrayTransferFunctionMTime(index);
  return AMILabType<vtkTimeStamp >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeProperty::GetGrayTransferFunctionMTime(...)
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetGrayTransferFunctionMTime::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetGrayTransferFunctionMTime::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeProperty::wrap_GetGrayTransferFunctionMTime_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeProperty::wrap_GetGrayTransferFunctionMTime_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkTimeStamp vtkVolumeProperty::GetGrayTransferFunctionMTime()
//---------------------------------------------------
void WrapClass_vtkVolumeProperty::
    wrap_GetGrayTransferFunctionMTime_2::SetParametersComments()
{
  return_comments="returning a variable of type vtkTimeStamp";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeProperty::
    wrap_GetGrayTransferFunctionMTime_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkTimeStamp res =   this->_objectptr->GetObj()->GetGrayTransferFunctionMTime();
  return AMILabType<vtkTimeStamp >::CreateVar(res);
}

