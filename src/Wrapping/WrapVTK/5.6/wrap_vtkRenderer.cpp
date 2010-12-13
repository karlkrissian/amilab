/**
 * C++ Interface: wrap_vtkRenderer
 *
 * Description: wrapping vtkRenderer
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

#include "wrap_vtkRenderer.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef vtkRenderer_declared
  #define vtkRenderer_declared
  AMI_DECLARE_TYPE(vtkRenderer)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkProp_declared
  #define vtkProp_declared
  AMI_DECLARE_TYPE(vtkProp)
#endif
#ifndef vtkVolumeCollection_declared
  #define vtkVolumeCollection_declared
  AMI_DECLARE_TYPE(vtkVolumeCollection)
#endif
#ifndef vtkActorCollection_declared
  #define vtkActorCollection_declared
  AMI_DECLARE_TYPE(vtkActorCollection)
#endif
#ifndef vtkCamera_declared
  #define vtkCamera_declared
  AMI_DECLARE_TYPE(vtkCamera)
#endif
#ifndef vtkRenderWindow_declared
  #define vtkRenderWindow_declared
  AMI_DECLARE_TYPE(vtkRenderWindow)
#endif
#ifndef vtkWindow_declared
  #define vtkWindow_declared
  AMI_DECLARE_TYPE(vtkWindow)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkRenderer>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkRenderer);
AMI_DEFINE_VARFROMSMTPTR(vtkRenderer);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkRenderer>::CreateVar( vtkRenderer* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkRenderer> obj_ptr(val,smartpointer_nodeleter<vtkRenderer>());
  return AMILabType<vtkRenderer>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkRenderer
//
Variable<AMIObject>::ptr WrapClass_vtkRenderer::CreateVar( vtkRenderer* sp)
{
  boost::shared_ptr<vtkRenderer> di_ptr(
    sp,
    wxwindow_nodeleter<vtkRenderer>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkRenderer>::CreateVar(
      new WrapClass_vtkRenderer(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkRenderer::AddMethods(WrapClass<vtkRenderer>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_AddActor( this_ptr);
  AddVar_AddVolume( this_ptr);
  AddVar_RemoveActor( this_ptr);
  AddVar_RemoveVolume( this_ptr);
/* The following types are missing: vtkLight
  AddVar_AddLight( this_ptr);
*/
/* The following types are missing: vtkLight
  AddVar_RemoveLight( this_ptr);
*/
  AddVar_RemoveAllLights( this_ptr);
/* The following types are missing: vtkLightCollection
  AddVar_GetLights( this_ptr);
*/
/* The following types are missing: vtkLightCollection
  AddVar_SetLightCollection( this_ptr);
*/
  AddVar_CreateLight( this_ptr);
/* The following types are missing: vtkLight
  AddVar_MakeLight( this_ptr);
*/
  AddVar_GetTwoSidedLighting( this_ptr);
  AddVar_SetTwoSidedLighting( this_ptr);
  AddVar_TwoSidedLightingOn( this_ptr);
  AddVar_TwoSidedLightingOff( this_ptr);
  AddVar_SetLightFollowCamera( this_ptr);
  AddVar_GetLightFollowCamera( this_ptr);
  AddVar_LightFollowCameraOn( this_ptr);
  AddVar_LightFollowCameraOff( this_ptr);
  AddVar_GetAutomaticLightCreation( this_ptr);
  AddVar_SetAutomaticLightCreation( this_ptr);
  AddVar_AutomaticLightCreationOn( this_ptr);
  AddVar_AutomaticLightCreationOff( this_ptr);
  AddVar_UpdateLightsGeometryToFollowCamera( this_ptr);
  AddVar_GetVolumes( this_ptr);
  AddVar_GetActors( this_ptr);
  AddVar_SetActiveCamera( this_ptr);
  AddVar_GetActiveCamera( this_ptr);
  AddVar_MakeCamera( this_ptr);
  AddVar_SetErase( this_ptr);
  AddVar_GetErase( this_ptr);
  AddVar_EraseOn( this_ptr);
  AddVar_EraseOff( this_ptr);
  AddVar_SetDraw( this_ptr);
  AddVar_GetDraw( this_ptr);
  AddVar_DrawOn( this_ptr);
  AddVar_DrawOff( this_ptr);
/* The following types are missing: vtkCuller
  AddVar_AddCuller( this_ptr);
*/
/* The following types are missing: vtkCuller
  AddVar_RemoveCuller( this_ptr);
*/
/* The following types are missing: vtkCullerCollection
  AddVar_GetCullers( this_ptr);
*/
  AddVar_SetAmbient_1( this_ptr);
  AddVar_SetAmbient( this_ptr);
  AddVar_SetAmbient_2( this_ptr);
  AddVar_GetAmbient_1( this_ptr);
  AddVar_GetAmbient( this_ptr);
  AddVar_GetAmbient_2( this_ptr);
  AddVar_SetAllocatedRenderTime( this_ptr);
  AddVar_GetAllocatedRenderTime( this_ptr);
  AddVar_GetTimeFactor( this_ptr);
  AddVar_Render( this_ptr);
  AddVar_DeviceRenderTranslucentPolygonalGeometry( this_ptr);
  AddVar_Clear( this_ptr);
  AddVar_VisibleActorCount( this_ptr);
  AddVar_VisibleVolumeCount( this_ptr);
  AddVar_ComputeVisiblePropBounds_1( this_ptr);
  AddVar_ComputeVisiblePropBounds( this_ptr);
  AddVar_ComputeVisiblePropBounds_2( this_ptr);
  AddVar_ResetCameraClippingRange_1( this_ptr);
  AddVar_ResetCameraClippingRange( this_ptr);
  AddVar_ResetCameraClippingRange_2( this_ptr);
  AddVar_ResetCameraClippingRange_3( this_ptr);
  AddVar_SetNearClippingPlaneTolerance( this_ptr);
  AddVar_GetNearClippingPlaneToleranceMinValue( this_ptr);
  AddVar_GetNearClippingPlaneToleranceMaxValue( this_ptr);
  AddVar_GetNearClippingPlaneTolerance( this_ptr);
  AddVar_ResetCamera_1( this_ptr);
  AddVar_ResetCamera( this_ptr);
  AddVar_ResetCamera_2( this_ptr);
  AddVar_ResetCamera_3( this_ptr);
  AddVar_SetRenderWindow( this_ptr);
  AddVar_GetRenderWindow( this_ptr);
  AddVar_GetVTKWindow( this_ptr);
  AddVar_SetBackingStore( this_ptr);
  AddVar_GetBackingStore( this_ptr);
  AddVar_BackingStoreOn( this_ptr);
  AddVar_BackingStoreOff( this_ptr);
  AddVar_SetInteractive( this_ptr);
  AddVar_GetInteractive( this_ptr);
  AddVar_InteractiveOn( this_ptr);
  AddVar_InteractiveOff( this_ptr);
  AddVar_SetLayer( this_ptr);
  AddVar_GetLayer( this_ptr);
  AddVar_SetPreserveDepthBuffer( this_ptr);
  AddVar_GetPreserveDepthBuffer( this_ptr);
  AddVar_PreserveDepthBufferOn( this_ptr);
  AddVar_PreserveDepthBufferOff( this_ptr);
  AddVar_Transparent( this_ptr);
  AddVar_WorldToView_1( this_ptr);
  AddVar_ViewToWorld_1( this_ptr);
  AddVar_ViewToWorld( this_ptr);
  AddVar_ViewToWorld_2( this_ptr);
  AddVar_WorldToView( this_ptr);
  AddVar_WorldToView_2( this_ptr);
  AddVar_GetZ( this_ptr);
  AddVar_GetMTime( this_ptr);
  AddVar_GetLastRenderTimeInSeconds( this_ptr);
  AddVar_GetNumberOfPropsRendered( this_ptr);
/* The following types are missing: vtkAssemblyPath
  AddVar_PickProp_1( this_ptr);
*/
  AddVar_PickProp( this_ptr);
/* The following types are missing: vtkAssemblyPath
  AddVar_PickProp_2( this_ptr);
*/
  AddVar_StereoMidpoint( this_ptr);
  AddVar_GetTiledAspectRatio( this_ptr);
  AddVar_IsActiveCameraCreated( this_ptr);
  AddVar_SetUseDepthPeeling( this_ptr);
  AddVar_GetUseDepthPeeling( this_ptr);
  AddVar_UseDepthPeelingOn( this_ptr);
  AddVar_UseDepthPeelingOff( this_ptr);
  AddVar_SetOcclusionRatio( this_ptr);
  AddVar_GetOcclusionRatioMinValue( this_ptr);
  AddVar_GetOcclusionRatioMaxValue( this_ptr);
  AddVar_GetOcclusionRatio( this_ptr);
  AddVar_SetMaximumNumberOfPeels( this_ptr);
  AddVar_GetMaximumNumberOfPeels( this_ptr);
  AddVar_GetLastRenderingUsedDepthPeeling( this_ptr);
/* The following types are missing: vtkRendererDelegate
  AddVar_SetDelegate( this_ptr);
*/
/* The following types are missing: vtkRendererDelegate
  AddVar_GetDelegate( this_ptr);
*/
/* The following types are missing: vtkRenderPass
  AddVar_SetPass( this_ptr);
*/
/* The following types are missing: vtkRenderPass
  AddVar_GetPass( this_ptr);
*/
/* The following types are missing: vtkHardwareSelector
  AddVar_GetSelector( this_ptr);
*/
/* The following types are missing: vtkTexture
  AddVar_SetBackgroundTexture( this_ptr);
*/
/* The following types are missing: vtkTexture
  AddVar_GetBackgroundTexture( this_ptr);
*/
  AddVar_SetTexturedBackground( this_ptr);
  AddVar_GetTexturedBackground( this_ptr);
  AddVar_TexturedBackgroundOn( this_ptr);
  AddVar_TexturedBackgroundOff( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent vtkViewport
  boost::shared_ptr<vtkViewport > parent_vtkViewport(  boost::dynamic_pointer_cast<vtkViewport >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkViewport = AMILabType<vtkViewport >::CreateVarFromSmtPtr(parent_vtkViewport);
  context->AddVar("vtkViewport",var_vtkViewport);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkViewport = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkViewport);
  context->AddDefault(obj_vtkViewport->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkRenderer_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkRenderer");
  
  // Static methods 
  WrapClass_vtkRenderer::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkRenderer::AddVar_SafeDownCast(amiobject->GetContext());
  WrapClass_vtkRenderer::AddVar_New(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkRenderer::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkRenderer::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkRenderer * vtkRenderer::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkRenderer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
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

  vtkRenderer * res =   vtkRenderer::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkRenderer >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkRenderer * vtkRenderer::New()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkRenderer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRenderer * res =   vtkRenderer::New();
  BasicVariable::ptr res_var = AMILabType<vtkRenderer >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
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
//  Wrapping of vtkRenderer * vtkRenderer::NewInstance()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkRenderer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRenderer * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkRenderer >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkRenderer::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
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
//  Wrapping of void vtkRenderer::AddActor(vtkProp * p)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_AddActor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_AddActor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkProp* p;
  if (CheckNullVar(_p,_n))  {
    p=(vtkProp*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkProp > p_smtptr;
    if (!get_val_smtptr_param<vtkProp >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    p = p_smtptr.get();
  }

  this->_objectptr->GetObj()->AddActor(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::AddVolume(vtkProp * p)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_AddVolume::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_AddVolume::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkProp* p;
  if (CheckNullVar(_p,_n))  {
    p=(vtkProp*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkProp > p_smtptr;
    if (!get_val_smtptr_param<vtkProp >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    p = p_smtptr.get();
  }

  this->_objectptr->GetObj()->AddVolume(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::RemoveActor(vtkProp * p)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_RemoveActor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_RemoveActor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkProp* p;
  if (CheckNullVar(_p,_n))  {
    p=(vtkProp*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkProp > p_smtptr;
    if (!get_val_smtptr_param<vtkProp >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    p = p_smtptr.get();
  }

  this->_objectptr->GetObj()->RemoveActor(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::RemoveVolume(vtkProp * p)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_RemoveVolume::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_RemoveVolume::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkProp* p;
  if (CheckNullVar(_p,_n))  {
    p=(vtkProp*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkProp > p_smtptr;
    if (!get_val_smtptr_param<vtkProp >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    p = p_smtptr.get();
  }

  this->_objectptr->GetObj()->RemoveVolume(p);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkLight

//---------------------------------------------------
//  Wrapping of void vtkRenderer::AddLight(vtkLight * param0)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_AddLight::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkLight, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_AddLight::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkLight* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkLight*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkLight > param0_smtptr;
    if (!get_val_smtptr_param<vtkLight >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->AddLight(param0);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkLight

//---------------------------------------------------
//  Wrapping of void vtkRenderer::RemoveLight(vtkLight * param0)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_RemoveLight::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkLight, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_RemoveLight::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkLight* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkLight*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkLight > param0_smtptr;
    if (!get_val_smtptr_param<vtkLight >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->RemoveLight(param0);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkRenderer::RemoveAllLights()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_RemoveAllLights::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_RemoveAllLights::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RemoveAllLights();
  return BasicVariable::ptr();
}
/* The following types are missing: vtkLightCollection

//---------------------------------------------------
//  Wrapping of vtkLightCollection * vtkRenderer::GetLights()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetLights::SetParametersComments()
{
  return_comments="returning a variable of type vtkLightCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetLights::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkLightCollection * res =   this->_objectptr->GetObj()->GetLights();
  return AMILabType<vtkLightCollection >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkLightCollection

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetLightCollection(vtkLightCollection * lights)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetLightCollection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkLightCollection, "parameter named 'lights'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetLightCollection::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkLightCollection* lights;
  if (CheckNullVar(_p,_n))  {
    lights=(vtkLightCollection*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkLightCollection > lights_smtptr;
    if (!get_val_smtptr_param<vtkLightCollection >(lights_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    lights = lights_smtptr.get();
  }

  this->_objectptr->GetObj()->SetLightCollection(lights);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkRenderer::CreateLight()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_CreateLight::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_CreateLight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->CreateLight();
  return BasicVariable::ptr();
}
/* The following types are missing: vtkLight

//---------------------------------------------------
//  Wrapping of vtkLight * vtkRenderer::MakeLight()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_MakeLight::SetParametersComments()
{
  return_comments="returning a variable of type vtkLight";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_MakeLight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkLight * res =   this->_objectptr->GetObj()->MakeLight();
  return AMILabType<vtkLight >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of int vtkRenderer::GetTwoSidedLighting()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetTwoSidedLighting::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetTwoSidedLighting::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetTwoSidedLighting();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetTwoSidedLighting(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetTwoSidedLighting::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetTwoSidedLighting::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetTwoSidedLighting(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::TwoSidedLightingOn()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_TwoSidedLightingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_TwoSidedLightingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->TwoSidedLightingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::TwoSidedLightingOff()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_TwoSidedLightingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_TwoSidedLightingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->TwoSidedLightingOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetLightFollowCamera(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetLightFollowCamera::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetLightFollowCamera::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetLightFollowCamera(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::GetLightFollowCamera()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetLightFollowCamera::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetLightFollowCamera::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetLightFollowCamera();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::LightFollowCameraOn()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_LightFollowCameraOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_LightFollowCameraOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->LightFollowCameraOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::LightFollowCameraOff()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_LightFollowCameraOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_LightFollowCameraOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->LightFollowCameraOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::GetAutomaticLightCreation()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetAutomaticLightCreation::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetAutomaticLightCreation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAutomaticLightCreation();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetAutomaticLightCreation(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetAutomaticLightCreation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetAutomaticLightCreation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAutomaticLightCreation(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::AutomaticLightCreationOn()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_AutomaticLightCreationOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_AutomaticLightCreationOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AutomaticLightCreationOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::AutomaticLightCreationOff()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_AutomaticLightCreationOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_AutomaticLightCreationOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AutomaticLightCreationOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::UpdateLightsGeometryToFollowCamera()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_UpdateLightsGeometryToFollowCamera::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_UpdateLightsGeometryToFollowCamera::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->UpdateLightsGeometryToFollowCamera();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkVolumeCollection * vtkRenderer::GetVolumes()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetVolumes::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolumeCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetVolumes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolumeCollection * res =   this->_objectptr->GetObj()->GetVolumes();
  BasicVariable::ptr res_var = AMILabType<vtkVolumeCollection >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkActorCollection * vtkRenderer::GetActors()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetActors::SetParametersComments()
{
  return_comments="returning a variable of type vtkActorCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetActors::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkActorCollection * res =   this->_objectptr->GetObj()->GetActors();
  BasicVariable::ptr res_var = AMILabType<vtkActorCollection >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetActiveCamera(vtkCamera * param0)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetActiveCamera::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkCamera, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetActiveCamera::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkCamera* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkCamera*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkCamera > param0_smtptr;
    if (!get_val_smtptr_param<vtkCamera >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->SetActiveCamera(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkCamera * vtkRenderer::GetActiveCamera()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetActiveCamera::SetParametersComments()
{
  return_comments="returning a variable of type vtkCamera";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetActiveCamera::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkCamera * res =   this->_objectptr->GetObj()->GetActiveCamera();
  BasicVariable::ptr res_var = AMILabType<vtkCamera >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkCamera * vtkRenderer::MakeCamera()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_MakeCamera::SetParametersComments()
{
  return_comments="returning a variable of type vtkCamera";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_MakeCamera::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkCamera * res =   this->_objectptr->GetObj()->MakeCamera();
  BasicVariable::ptr res_var = AMILabType<vtkCamera >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetErase(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetErase::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetErase::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetErase(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::GetErase()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetErase::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetErase::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetErase();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::EraseOn()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_EraseOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_EraseOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EraseOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::EraseOff()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_EraseOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_EraseOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EraseOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetDraw(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetDraw::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetDraw::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDraw(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::GetDraw()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetDraw::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetDraw::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDraw();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::DrawOn()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_DrawOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_DrawOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DrawOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::DrawOff()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_DrawOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_DrawOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DrawOff();
  return BasicVariable::ptr();
}
/* The following types are missing: vtkCuller

//---------------------------------------------------
//  Wrapping of void vtkRenderer::AddCuller(vtkCuller * param0)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_AddCuller::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkCuller, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_AddCuller::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkCuller* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkCuller*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkCuller > param0_smtptr;
    if (!get_val_smtptr_param<vtkCuller >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->AddCuller(param0);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkCuller

//---------------------------------------------------
//  Wrapping of void vtkRenderer::RemoveCuller(vtkCuller * param0)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_RemoveCuller::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkCuller, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_RemoveCuller::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkCuller* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkCuller*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkCuller > param0_smtptr;
    if (!get_val_smtptr_param<vtkCuller >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->RemoveCuller(param0);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkCullerCollection

//---------------------------------------------------
//  Wrapping of vtkCullerCollection * vtkRenderer::GetCullers()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetCullers::SetParametersComments()
{
  return_comments="returning a variable of type vtkCullerCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetCullers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkCullerCollection * res =   this->_objectptr->GetObj()->GetCullers();
  return AMILabType<vtkCullerCollection >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetAmbient(double _arg1, double _arg2, double _arg3)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetAmbient_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetAmbient_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  double _arg1;
  if (!get_val_param<double >(_arg1,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg2;
  if (!get_val_param<double >(_arg2,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg3;
  if (!get_val_param<double >(_arg3,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetAmbient(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderer::SetAmbient(...)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetAmbient::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetAmbient::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderer::wrap_SetAmbient_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderer::wrap_SetAmbient_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetAmbient(double * _arg)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetAmbient_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetAmbient_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* _arg;
  if (CheckNullVar(_p,_n))  {
    _arg=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > _arg_smtptr;
    if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    _arg = _arg_smtptr.get();
  }

  this->_objectptr->GetObj()->SetAmbient(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkRenderer::GetAmbient()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetAmbient_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetAmbient_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetAmbient();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderer::GetAmbient(...)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetAmbient::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetAmbient::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderer::wrap_GetAmbient_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderer::wrap_GetAmbient_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::GetAmbient(double * data)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetAmbient_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetAmbient_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* data;
  if (CheckNullVar(_p,_n))  {
    data=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > data_smtptr;
    if (!get_val_smtptr_param<double >(data_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    data = data_smtptr.get();
  }

  this->_objectptr->GetObj()->GetAmbient(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetAllocatedRenderTime(double _arg)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetAllocatedRenderTime::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetAllocatedRenderTime::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAllocatedRenderTime(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkRenderer::GetAllocatedRenderTime()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetAllocatedRenderTime::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetAllocatedRenderTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetAllocatedRenderTime();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkRenderer::GetTimeFactor()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetTimeFactor::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetTimeFactor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetTimeFactor();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::Render()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_Render::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_Render::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Render();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::DeviceRenderTranslucentPolygonalGeometry()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_DeviceRenderTranslucentPolygonalGeometry::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_DeviceRenderTranslucentPolygonalGeometry::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DeviceRenderTranslucentPolygonalGeometry();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::Clear()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_Clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_Clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::VisibleActorCount()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_VisibleActorCount::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_VisibleActorCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->VisibleActorCount();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::VisibleVolumeCount()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_VisibleVolumeCount::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_VisibleVolumeCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->VisibleVolumeCount();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::ComputeVisiblePropBounds(double * bounds)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_ComputeVisiblePropBounds_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_ComputeVisiblePropBounds_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->ComputeVisiblePropBounds(bounds);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderer::ComputeVisiblePropBounds(...)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_ComputeVisiblePropBounds::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_ComputeVisiblePropBounds::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderer::wrap_ComputeVisiblePropBounds_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderer::wrap_ComputeVisiblePropBounds_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double * vtkRenderer::ComputeVisiblePropBounds()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_ComputeVisiblePropBounds_2::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_ComputeVisiblePropBounds_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->ComputeVisiblePropBounds();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::ResetCameraClippingRange()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_ResetCameraClippingRange_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_ResetCameraClippingRange_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->ResetCameraClippingRange();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderer::ResetCameraClippingRange(...)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_ResetCameraClippingRange::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_ResetCameraClippingRange::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderer::wrap_ResetCameraClippingRange_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderer::wrap_ResetCameraClippingRange_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkRenderer::wrap_ResetCameraClippingRange_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::ResetCameraClippingRange(double * bounds)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_ResetCameraClippingRange_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_ResetCameraClippingRange_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->ResetCameraClippingRange(bounds);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::ResetCameraClippingRange(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_ResetCameraClippingRange_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'xmin'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'xmax'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'ymin'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'ymax'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'zmin'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'zmax'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_ResetCameraClippingRange_3::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->ResetCameraClippingRange(xmin, xmax, ymin, ymax, zmin, zmax);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetNearClippingPlaneTolerance(double _arg)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetNearClippingPlaneTolerance::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetNearClippingPlaneTolerance::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetNearClippingPlaneTolerance(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkRenderer::GetNearClippingPlaneToleranceMinValue()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetNearClippingPlaneToleranceMinValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetNearClippingPlaneToleranceMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetNearClippingPlaneToleranceMinValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkRenderer::GetNearClippingPlaneToleranceMaxValue()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetNearClippingPlaneToleranceMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetNearClippingPlaneToleranceMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetNearClippingPlaneToleranceMaxValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkRenderer::GetNearClippingPlaneTolerance()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetNearClippingPlaneTolerance::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetNearClippingPlaneTolerance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetNearClippingPlaneTolerance();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::ResetCamera()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_ResetCamera_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_ResetCamera_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->ResetCamera();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderer::ResetCamera(...)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_ResetCamera::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_ResetCamera::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderer::wrap_ResetCamera_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderer::wrap_ResetCamera_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkRenderer::wrap_ResetCamera_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::ResetCamera(double * bounds)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_ResetCamera_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_ResetCamera_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->ResetCamera(bounds);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::ResetCamera(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_ResetCamera_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'xmin'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'xmax'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'ymin'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'ymax'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'zmin'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'zmax'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_ResetCamera_3::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->ResetCamera(xmin, xmax, ymin, ymax, zmin, zmax);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetRenderWindow(vtkRenderWindow * param0)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetRenderWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderWindow, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetRenderWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkRenderWindow* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkRenderWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderWindow > param0_smtptr;
    if (!get_val_smtptr_param<vtkRenderWindow >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->SetRenderWindow(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkRenderWindow * vtkRenderer::GetRenderWindow()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetRenderWindow::SetParametersComments()
{
  return_comments="returning a variable of type vtkRenderWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetRenderWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRenderWindow * res =   this->_objectptr->GetObj()->GetRenderWindow();
  BasicVariable::ptr res_var = AMILabType<vtkRenderWindow >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkWindow * vtkRenderer::GetVTKWindow()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetVTKWindow::SetParametersComments()
{
  return_comments="returning a variable of type vtkWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetVTKWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkWindow * res =   this->_objectptr->GetObj()->GetVTKWindow();
  BasicVariable::ptr res_var = AMILabType<vtkWindow >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetBackingStore(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetBackingStore::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetBackingStore::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetBackingStore(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::GetBackingStore()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetBackingStore::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetBackingStore::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetBackingStore();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::BackingStoreOn()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_BackingStoreOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_BackingStoreOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->BackingStoreOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::BackingStoreOff()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_BackingStoreOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_BackingStoreOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->BackingStoreOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetInteractive(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetInteractive::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetInteractive::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInteractive(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::GetInteractive()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetInteractive::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetInteractive::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetInteractive();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::InteractiveOn()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_InteractiveOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_InteractiveOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InteractiveOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::InteractiveOff()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_InteractiveOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_InteractiveOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InteractiveOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetLayer(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetLayer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetLayer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetLayer(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::GetLayer()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetLayer::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetLayer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetLayer();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetPreserveDepthBuffer(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetPreserveDepthBuffer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetPreserveDepthBuffer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetPreserveDepthBuffer(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::GetPreserveDepthBuffer()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetPreserveDepthBuffer::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetPreserveDepthBuffer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetPreserveDepthBuffer();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::PreserveDepthBufferOn()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_PreserveDepthBufferOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_PreserveDepthBufferOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PreserveDepthBufferOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::PreserveDepthBufferOff()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_PreserveDepthBufferOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_PreserveDepthBufferOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PreserveDepthBufferOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::Transparent()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_Transparent::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_Transparent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->Transparent();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::WorldToView()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_WorldToView_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_WorldToView_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->WorldToView();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::ViewToWorld()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_ViewToWorld_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_ViewToWorld_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->ViewToWorld();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderer::ViewToWorld(...)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_ViewToWorld::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_ViewToWorld::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderer::wrap_ViewToWorld_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderer::wrap_ViewToWorld_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::ViewToWorld(double & wx, double & wy, double & wz)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_ViewToWorld_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'wx'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'wy'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'wz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_ViewToWorld_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > wx_smtptr;
  if (!get_val_smtptr_param<double >(wx_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & wx = *wx_smtptr;

  boost::shared_ptr<double > wy_smtptr;
  if (!get_val_smtptr_param<double >(wy_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & wy = *wy_smtptr;

  boost::shared_ptr<double > wz_smtptr;
  if (!get_val_smtptr_param<double >(wz_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & wz = *wz_smtptr;

  this->_objectptr->GetObj()->ViewToWorld(wx, wy, wz);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderer::WorldToView(...)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_WorldToView::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_WorldToView::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderer::wrap_WorldToView_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderer::wrap_WorldToView_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::WorldToView(double & wx, double & wy, double & wz)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_WorldToView_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'wx'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'wy'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'wz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_WorldToView_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > wx_smtptr;
  if (!get_val_smtptr_param<double >(wx_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & wx = *wx_smtptr;

  boost::shared_ptr<double > wy_smtptr;
  if (!get_val_smtptr_param<double >(wy_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & wy = *wy_smtptr;

  boost::shared_ptr<double > wz_smtptr;
  if (!get_val_smtptr_param<double >(wz_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & wz = *wz_smtptr;

  this->_objectptr->GetObj()->WorldToView(wx, wy, wz);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkRenderer::GetZ(int x, int y)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetZ::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetZ::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetZ(x, y);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkRenderer::GetMTime()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of double vtkRenderer::GetLastRenderTimeInSeconds()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetLastRenderTimeInSeconds::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetLastRenderTimeInSeconds::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetLastRenderTimeInSeconds();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::GetNumberOfPropsRendered()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetNumberOfPropsRendered::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetNumberOfPropsRendered::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfPropsRendered();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: vtkAssemblyPath

//---------------------------------------------------
//  Wrapping of vtkAssemblyPath * vtkRenderer::PickProp(double selectionX, double selectionY)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_PickProp_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'selectionX'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'selectionY'")
  return_comments="returning a variable of type vtkAssemblyPath";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_PickProp_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double selectionX;
  if (!get_val_param<double >(selectionX,_p,_n,true,true)) ClassReturnEmptyVar;

  double selectionY;
  if (!get_val_param<double >(selectionY,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkAssemblyPath * res =   this->_objectptr->GetObj()->PickProp(selectionX, selectionY);
  return AMILabType<vtkAssemblyPath >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderer::PickProp(...)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_PickProp::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_PickProp::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkAssemblyPath

//---------------------------------------------------
//  Wrapping of vtkAssemblyPath * vtkRenderer::PickProp(double selectionX1, double selectionY1, double selectionX2, double selectionY2)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_PickProp_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'selectionX1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'selectionY1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'selectionX2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'selectionY2'")
  return_comments="returning a variable of type vtkAssemblyPath";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_PickProp_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  double selectionX1;
  if (!get_val_param<double >(selectionX1,_p,_n,true,true)) ClassReturnEmptyVar;

  double selectionY1;
  if (!get_val_param<double >(selectionY1,_p,_n,true,true)) ClassReturnEmptyVar;

  double selectionX2;
  if (!get_val_param<double >(selectionX2,_p,_n,true,true)) ClassReturnEmptyVar;

  double selectionY2;
  if (!get_val_param<double >(selectionY2,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkAssemblyPath * res =   this->_objectptr->GetObj()->PickProp(selectionX1, selectionY1, selectionX2, selectionY2);
  return AMILabType<vtkAssemblyPath >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkRenderer::StereoMidpoint()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_StereoMidpoint::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_StereoMidpoint::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StereoMidpoint();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkRenderer::GetTiledAspectRatio()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetTiledAspectRatio::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetTiledAspectRatio::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetTiledAspectRatio();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::IsActiveCameraCreated()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_IsActiveCameraCreated::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_IsActiveCameraCreated::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->IsActiveCameraCreated();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetUseDepthPeeling(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetUseDepthPeeling::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetUseDepthPeeling::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetUseDepthPeeling(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::GetUseDepthPeeling()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetUseDepthPeeling::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetUseDepthPeeling::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetUseDepthPeeling();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::UseDepthPeelingOn()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_UseDepthPeelingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_UseDepthPeelingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UseDepthPeelingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::UseDepthPeelingOff()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_UseDepthPeelingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_UseDepthPeelingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UseDepthPeelingOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetOcclusionRatio(double _arg)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetOcclusionRatio::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetOcclusionRatio::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetOcclusionRatio(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkRenderer::GetOcclusionRatioMinValue()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetOcclusionRatioMinValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetOcclusionRatioMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetOcclusionRatioMinValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkRenderer::GetOcclusionRatioMaxValue()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetOcclusionRatioMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetOcclusionRatioMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetOcclusionRatioMaxValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkRenderer::GetOcclusionRatio()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetOcclusionRatio::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetOcclusionRatio::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetOcclusionRatio();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetMaximumNumberOfPeels(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetMaximumNumberOfPeels::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetMaximumNumberOfPeels::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMaximumNumberOfPeels(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::GetMaximumNumberOfPeels()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetMaximumNumberOfPeels::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetMaximumNumberOfPeels::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMaximumNumberOfPeels();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderer::GetLastRenderingUsedDepthPeeling()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetLastRenderingUsedDepthPeeling::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetLastRenderingUsedDepthPeeling::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetLastRenderingUsedDepthPeeling();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: vtkRendererDelegate

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetDelegate(vtkRendererDelegate * d)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetDelegate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRendererDelegate, "parameter named 'd'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetDelegate::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkRendererDelegate* d;
  if (CheckNullVar(_p,_n))  {
    d=(vtkRendererDelegate*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRendererDelegate > d_smtptr;
    if (!get_val_smtptr_param<vtkRendererDelegate >(d_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    d = d_smtptr.get();
  }

  this->_objectptr->GetObj()->SetDelegate(d);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkRendererDelegate

//---------------------------------------------------
//  Wrapping of vtkRendererDelegate * vtkRenderer::GetDelegate()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetDelegate::SetParametersComments()
{
  return_comments="returning a variable of type vtkRendererDelegate";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetDelegate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRendererDelegate * res =   this->_objectptr->GetObj()->GetDelegate();
  return AMILabType<vtkRendererDelegate >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkRenderPass

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetPass(vtkRenderPass * p)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetPass::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderPass, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetPass::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkRenderPass* p;
  if (CheckNullVar(_p,_n))  {
    p=(vtkRenderPass*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderPass > p_smtptr;
    if (!get_val_smtptr_param<vtkRenderPass >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    p = p_smtptr.get();
  }

  this->_objectptr->GetObj()->SetPass(p);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkRenderPass

//---------------------------------------------------
//  Wrapping of vtkRenderPass * vtkRenderer::GetPass()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetPass::SetParametersComments()
{
  return_comments="returning a variable of type vtkRenderPass";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetPass::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRenderPass * res =   this->_objectptr->GetObj()->GetPass();
  return AMILabType<vtkRenderPass >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkHardwareSelector

//---------------------------------------------------
//  Wrapping of vtkHardwareSelector * vtkRenderer::GetSelector()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetSelector::SetParametersComments()
{
  return_comments="returning a variable of type vtkHardwareSelector";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetSelector::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkHardwareSelector * res =   this->_objectptr->GetObj()->GetSelector();
  return AMILabType<vtkHardwareSelector >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkTexture

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetBackgroundTexture(vtkTexture * param0)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetBackgroundTexture::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkTexture, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetBackgroundTexture::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkTexture* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkTexture*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkTexture > param0_smtptr;
    if (!get_val_smtptr_param<vtkTexture >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->SetBackgroundTexture(param0);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkTexture

//---------------------------------------------------
//  Wrapping of vtkTexture * vtkRenderer::GetBackgroundTexture()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetBackgroundTexture::SetParametersComments()
{
  return_comments="returning a variable of type vtkTexture";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetBackgroundTexture::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkTexture * res =   this->_objectptr->GetObj()->GetBackgroundTexture();
  return AMILabType<vtkTexture >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkRenderer::SetTexturedBackground(bool _arg)
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_SetTexturedBackground::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_SetTexturedBackground::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool _arg;
  if (!get_val_param<bool >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetTexturedBackground(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool vtkRenderer::GetTexturedBackground()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_GetTexturedBackground::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_GetTexturedBackground::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetTexturedBackground();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::TexturedBackgroundOn()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_TexturedBackgroundOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_TexturedBackgroundOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->TexturedBackgroundOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderer::TexturedBackgroundOff()
//---------------------------------------------------
void WrapClass_vtkRenderer::
    wrap_TexturedBackgroundOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderer::
    wrap_TexturedBackgroundOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->TexturedBackgroundOff();
  return BasicVariable::ptr();
}

