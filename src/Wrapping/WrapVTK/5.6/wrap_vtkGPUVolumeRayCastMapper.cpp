/**
 * C++ Interface: wrap_vtkGPUVolumeRayCastMapper
 *
 * Description: wrapping vtkGPUVolumeRayCastMapper
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
#include "wrap_vtkGPUVolumeRayCastMapper.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_vtkRenderWindow.h"
#include "wrap_vtkVolumeProperty.h"
#include "wrap_vtkRenderer.h"
#include "wrap_vtkVolume.h"
#include "wrap_vtkImageData.h"
#include "wrap_vtkWindow.h"


#include "wrap_vtkGPUVolumeRayCastMapper.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkGPUVolumeRayCastMapper>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkGPUVolumeRayCastMapper);
AMI_DEFINE_VARFROMSMTPTR(vtkGPUVolumeRayCastMapper);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkGPUVolumeRayCastMapper>::CreateVar( vtkGPUVolumeRayCastMapper* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkGPUVolumeRayCastMapper> obj_ptr(val,smartpointer_nodeleter<vtkGPUVolumeRayCastMapper>());
  return AMILabType<vtkGPUVolumeRayCastMapper>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkGPUVolumeRayCastMapper
//
Variable<AMIObject>::ptr WrapClass_vtkGPUVolumeRayCastMapper::CreateVar( vtkGPUVolumeRayCastMapper* sp)
{
  boost::shared_ptr<vtkGPUVolumeRayCastMapper> di_ptr(
    sp,
    wxwindow_nodeleter<vtkGPUVolumeRayCastMapper>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkGPUVolumeRayCastMapper>::CreateVar(
      new WrapClass_vtkGPUVolumeRayCastMapper(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::AddMethods(WrapClass<vtkGPUVolumeRayCastMapper>::ptr this_ptr )
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
      AddVar_SetAutoAdjustSampleDistances( this_ptr);
      AddVar_GetAutoAdjustSampleDistancesMinValue( this_ptr);
      AddVar_GetAutoAdjustSampleDistancesMaxValue( this_ptr);
      AddVar_GetAutoAdjustSampleDistances( this_ptr);
      AddVar_AutoAdjustSampleDistancesOn( this_ptr);
      AddVar_AutoAdjustSampleDistancesOff( this_ptr);
      AddVar_SetSampleDistance( this_ptr);
      AddVar_GetSampleDistance( this_ptr);
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
      AddVar_SetFinalColorWindow( this_ptr);
      AddVar_GetFinalColorWindow( this_ptr);
      AddVar_SetFinalColorLevel( this_ptr);
      AddVar_GetFinalColorLevel( this_ptr);
      AddVar_SetMaxMemoryInBytes( this_ptr);
      AddVar_GetMaxMemoryInBytes( this_ptr);
      AddVar_SetMaxMemoryFraction( this_ptr);
      AddVar_GetMaxMemoryFractionMinValue( this_ptr);
      AddVar_GetMaxMemoryFractionMaxValue( this_ptr);
      AddVar_GetMaxMemoryFraction( this_ptr);
      AddVar_SetReportProgress( this_ptr);
      AddVar_GetReportProgress( this_ptr);
      AddVar_IsRenderSupported( this_ptr);
      AddVar_CreateCanonicalView( this_ptr);
      AddVar_SetMaskInput( this_ptr);
      AddVar_GetMaskInput( this_ptr);
      AddVar_SetMaskBlendFactor( this_ptr);
      AddVar_GetMaskBlendFactorMinValue( this_ptr);
      AddVar_GetMaskBlendFactorMaxValue( this_ptr);
      AddVar_GetMaskBlendFactor( this_ptr);
      AddVar_Render( this_ptr);
      AddVar_GPURender( this_ptr);
      AddVar_ReleaseGraphicsResources( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkGPUVolumeRayCastMapper * vtkGPUVolumeRayCastMapper::New()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkGPUVolumeRayCastMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkGPUVolumeRayCastMapper * res =   vtkGPUVolumeRayCastMapper::New();
  BasicVariable::ptr res_var = WrapClass_vtkGPUVolumeRayCastMapper::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkGPUVolumeRayCastMapper::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkGPUVolumeRayCastMapper::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkGPUVolumeRayCastMapper * vtkGPUVolumeRayCastMapper::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkGPUVolumeRayCastMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkGPUVolumeRayCastMapper * res =   vtkGPUVolumeRayCastMapper::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkGPUVolumeRayCastMapper::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkGPUVolumeRayCastMapper::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
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
//  Wrapping of vtkGPUVolumeRayCastMapper * vtkGPUVolumeRayCastMapper::NewInstance()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkGPUVolumeRayCastMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkGPUVolumeRayCastMapper * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkGPUVolumeRayCastMapper::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
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
//  Wrapping of void vtkGPUVolumeRayCastMapper::SetAutoAdjustSampleDistances(int _arg)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetAutoAdjustSampleDistances::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
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
//  Wrapping of int vtkGPUVolumeRayCastMapper::GetAutoAdjustSampleDistancesMinValue()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistancesMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistancesMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAutoAdjustSampleDistancesMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkGPUVolumeRayCastMapper::GetAutoAdjustSampleDistancesMaxValue()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistancesMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistancesMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAutoAdjustSampleDistancesMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkGPUVolumeRayCastMapper::GetAutoAdjustSampleDistances()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistances::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistances::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAutoAdjustSampleDistances();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::AutoAdjustSampleDistancesOn()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_AutoAdjustSampleDistancesOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_AutoAdjustSampleDistancesOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AutoAdjustSampleDistancesOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::AutoAdjustSampleDistancesOff()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_AutoAdjustSampleDistancesOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_AutoAdjustSampleDistancesOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AutoAdjustSampleDistancesOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::SetSampleDistance(float _arg)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetSampleDistance::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetSampleDistance::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!get_val_param<float >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetSampleDistance(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetSampleDistance()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetSampleDistance::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetSampleDistance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetSampleDistance();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::SetImageSampleDistance(float _arg)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetImageSampleDistance::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetImageSampleDistance::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!get_val_param<float >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetImageSampleDistance(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetImageSampleDistanceMinValue()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetImageSampleDistanceMinValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetImageSampleDistanceMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetImageSampleDistanceMinValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetImageSampleDistanceMaxValue()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetImageSampleDistanceMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetImageSampleDistanceMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetImageSampleDistanceMaxValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetImageSampleDistance()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetImageSampleDistance::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetImageSampleDistance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetImageSampleDistance();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::SetMinimumImageSampleDistance(float _arg)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetMinimumImageSampleDistance::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetMinimumImageSampleDistance::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!get_val_param<float >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMinimumImageSampleDistance(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetMinimumImageSampleDistanceMinValue()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistanceMinValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistanceMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetMinimumImageSampleDistanceMinValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetMinimumImageSampleDistanceMaxValue()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistanceMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistanceMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetMinimumImageSampleDistanceMaxValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetMinimumImageSampleDistance()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistance::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetMinimumImageSampleDistance();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::SetMaximumImageSampleDistance(float _arg)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetMaximumImageSampleDistance::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetMaximumImageSampleDistance::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!get_val_param<float >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMaximumImageSampleDistance(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetMaximumImageSampleDistanceMinValue()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistanceMinValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistanceMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetMaximumImageSampleDistanceMinValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetMaximumImageSampleDistanceMaxValue()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistanceMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistanceMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetMaximumImageSampleDistanceMaxValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetMaximumImageSampleDistance()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistance::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetMaximumImageSampleDistance();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::SetFinalColorWindow(float _arg)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetFinalColorWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetFinalColorWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!get_val_param<float >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFinalColorWindow(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetFinalColorWindow()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetFinalColorWindow::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetFinalColorWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetFinalColorWindow();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::SetFinalColorLevel(float _arg)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetFinalColorLevel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetFinalColorLevel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!get_val_param<float >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFinalColorLevel(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetFinalColorLevel()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetFinalColorLevel::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetFinalColorLevel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetFinalColorLevel();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::SetMaxMemoryInBytes(vtkIdType _arg)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetMaxMemoryInBytes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetMaxMemoryInBytes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long _arg_long;
  if (!get_val_param<long >(_arg_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int _arg = boost::numeric_cast<long long int >(_arg_long);

  this->_objectptr->GetObj()->SetMaxMemoryInBytes(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkGPUVolumeRayCastMapper::GetMaxMemoryInBytes()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaxMemoryInBytes::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaxMemoryInBytes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->GetMaxMemoryInBytes();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::SetMaxMemoryFraction(float _arg)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetMaxMemoryFraction::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetMaxMemoryFraction::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!get_val_param<float >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMaxMemoryFraction(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetMaxMemoryFractionMinValue()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaxMemoryFractionMinValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaxMemoryFractionMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetMaxMemoryFractionMinValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetMaxMemoryFractionMaxValue()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaxMemoryFractionMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaxMemoryFractionMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetMaxMemoryFractionMaxValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetMaxMemoryFraction()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaxMemoryFraction::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaxMemoryFraction::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetMaxMemoryFraction();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::SetReportProgress(bool _arg)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetReportProgress::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetReportProgress::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg_int;
  if (!get_val_param<int >(_arg_int,_p,_n,true,false)) ClassHelpAndReturn;
  bool _arg = (bool) (_arg_int>0.5);

  this->_objectptr->GetObj()->SetReportProgress(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool vtkGPUVolumeRayCastMapper::GetReportProgress()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetReportProgress::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetReportProgress::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetReportProgress();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of int vtkGPUVolumeRayCastMapper::IsRenderSupported(vtkRenderWindow * param0, vtkVolumeProperty * param1)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_IsRenderSupported::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderWindow, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( vtkVolumeProperty, "parameter named 'param1'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_IsRenderSupported::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderWindow > param0_smtptr;
  if (!get_val_smtptr_param<vtkRenderWindow >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkRenderWindow* param0 = param0_smtptr.get();

  boost::shared_ptr<vtkVolumeProperty > param1_smtptr;
  if (!get_val_smtptr_param<vtkVolumeProperty >(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVolumeProperty* param1 = param1_smtptr.get();

  int res =   this->_objectptr->GetObj()->IsRenderSupported(param0, param1);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::CreateCanonicalView(vtkRenderer * ren, vtkVolume * volume, vtkImageData * image, int blend_mode, double * viewDirection, double * viewUp)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_CreateCanonicalView::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'ren'")
  ADDPARAMCOMMENT_TYPE( vtkVolume, "parameter named 'volume'")
  ADDPARAMCOMMENT_TYPE( vtkImageData, "parameter named 'image'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'blend_mode'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'viewDirection'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'viewUp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_CreateCanonicalView::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderer > ren_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(ren_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkRenderer* ren = ren_smtptr.get();

  boost::shared_ptr<vtkVolume > volume_smtptr;
  if (!get_val_smtptr_param<vtkVolume >(volume_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVolume* volume = volume_smtptr.get();

  boost::shared_ptr<vtkImageData > image_smtptr;
  if (!get_val_smtptr_param<vtkImageData >(image_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkImageData* image = image_smtptr.get();

  int blend_mode;
  if (!get_val_param<int >(blend_mode,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<double > viewDirection_smtptr;
  if (!get_val_smtptr_param<double >(viewDirection_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* viewDirection = viewDirection_smtptr.get();

  boost::shared_ptr<double > viewUp_smtptr;
  if (!get_val_smtptr_param<double >(viewUp_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* viewUp = viewUp_smtptr.get();

  this->_objectptr->GetObj()->CreateCanonicalView(ren, volume, image, blend_mode, viewDirection, viewUp);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::SetMaskInput(vtkImageData * mask)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetMaskInput::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkImageData, "parameter named 'mask'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetMaskInput::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkImageData > mask_smtptr;
  if (!get_val_smtptr_param<vtkImageData >(mask_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkImageData* mask = mask_smtptr.get();

  this->_objectptr->GetObj()->SetMaskInput(mask);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkImageData * vtkGPUVolumeRayCastMapper::GetMaskInput()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaskInput::SetParametersComments()
{
  return_comments="returning a variable of type vtkImageData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaskInput::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkImageData * res =   this->_objectptr->GetObj()->GetMaskInput();
  BasicVariable::ptr res_var = WrapClass_vtkImageData::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::SetMaskBlendFactor(float _arg)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetMaskBlendFactor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_SetMaskBlendFactor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!get_val_param<float >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMaskBlendFactor(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetMaskBlendFactorMinValue()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaskBlendFactorMinValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaskBlendFactorMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetMaskBlendFactorMinValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetMaskBlendFactorMaxValue()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaskBlendFactorMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaskBlendFactorMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetMaskBlendFactorMaxValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkGPUVolumeRayCastMapper::GetMaskBlendFactor()
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaskBlendFactor::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GetMaskBlendFactor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetMaskBlendFactor();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::Render(vtkRenderer * param0, vtkVolume * param1)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_Render::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( vtkVolume, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
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
//  Wrapping of void vtkGPUVolumeRayCastMapper::GPURender(vtkRenderer * param0, vtkVolume * param1)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GPURender::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( vtkVolume, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_GPURender::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->GPURender(param0, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkGPUVolumeRayCastMapper::ReleaseGraphicsResources(vtkWindow * param0)
//---------------------------------------------------
void WrapClass_vtkGPUVolumeRayCastMapper::
    wrap_ReleaseGraphicsResources::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkWindow, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkGPUVolumeRayCastMapper::
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

