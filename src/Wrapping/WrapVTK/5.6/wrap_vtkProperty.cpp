/**
 * C++ Interface: wrap_vtkProperty
 *
 * Description: wrapping vtkProperty
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
#include "wrap_vtkProperty.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkActor.h"
#include "wrap_vtkRenderer.h"
#include "wrap_vtkWindow.h"


#include "wrap_vtkProperty.h"

// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkProperty>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkProperty);
AMI_DEFINE_VARFROMSMTPTR(vtkProperty);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkProperty>::CreateVar( vtkProperty* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkProperty> obj_ptr(val,smartpointer_nodeleter<vtkProperty>());
  return AMILabType<vtkProperty>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkProperty
//
Variable<AMIObject>::ptr WrapClass_vtkProperty::CreateVar( vtkProperty* sp)
{
  boost::shared_ptr<vtkProperty> di_ptr(
    sp,
    wxwindow_nodeleter<vtkProperty>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkProperty>::CreateVar(
      new WrapClass_vtkProperty(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkProperty::AddMethods(WrapClass<vtkProperty>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_DeepCopy( this_ptr);
  AddVar_Render( this_ptr);
  AddVar_BackfaceRender( this_ptr);
  AddVar_PostRender( this_ptr);
  AddVar_GetLighting( this_ptr);
  AddVar_SetLighting( this_ptr);
  AddVar_LightingOn( this_ptr);
  AddVar_LightingOff( this_ptr);
  AddVar_SetInterpolation( this_ptr);
  AddVar_GetInterpolationMinValue( this_ptr);
  AddVar_GetInterpolationMaxValue( this_ptr);
  AddVar_GetInterpolation( this_ptr);
  AddVar_SetInterpolationToFlat( this_ptr);
  AddVar_SetInterpolationToGouraud( this_ptr);
  AddVar_SetInterpolationToPhong( this_ptr);
  AddVar_GetInterpolationAsString( this_ptr);
  AddVar_SetRepresentation( this_ptr);
  AddVar_GetRepresentationMinValue( this_ptr);
  AddVar_GetRepresentationMaxValue( this_ptr);
  AddVar_GetRepresentation( this_ptr);
  AddVar_SetRepresentationToPoints( this_ptr);
  AddVar_SetRepresentationToWireframe( this_ptr);
  AddVar_SetRepresentationToSurface( this_ptr);
  AddVar_GetRepresentationAsString( this_ptr);
  AddVar_SetColor_1( this_ptr);
  AddVar_SetColor( this_ptr);
  AddVar_SetColor_2( this_ptr);
  AddVar_GetColor_1( this_ptr);
  AddVar_GetColor( this_ptr);
  AddVar_GetColor_2( this_ptr);
  AddVar_GetColor_3( this_ptr);
  AddVar_SetAmbient( this_ptr);
  AddVar_GetAmbientMinValue( this_ptr);
  AddVar_GetAmbientMaxValue( this_ptr);
  AddVar_GetAmbient( this_ptr);
  AddVar_SetDiffuse( this_ptr);
  AddVar_GetDiffuseMinValue( this_ptr);
  AddVar_GetDiffuseMaxValue( this_ptr);
  AddVar_GetDiffuse( this_ptr);
  AddVar_SetSpecular( this_ptr);
  AddVar_GetSpecularMinValue( this_ptr);
  AddVar_GetSpecularMaxValue( this_ptr);
  AddVar_GetSpecular( this_ptr);
  AddVar_SetSpecularPower( this_ptr);
  AddVar_GetSpecularPowerMinValue( this_ptr);
  AddVar_GetSpecularPowerMaxValue( this_ptr);
  AddVar_GetSpecularPower( this_ptr);
  AddVar_SetOpacity( this_ptr);
  AddVar_GetOpacityMinValue( this_ptr);
  AddVar_GetOpacityMaxValue( this_ptr);
  AddVar_GetOpacity( this_ptr);
  AddVar_SetAmbientColor_1( this_ptr);
  AddVar_SetAmbientColor( this_ptr);
  AddVar_SetAmbientColor_2( this_ptr);
  AddVar_GetAmbientColor_1( this_ptr);
  AddVar_GetAmbientColor( this_ptr);
  AddVar_GetAmbientColor_2( this_ptr);
  AddVar_GetAmbientColor_3( this_ptr);
  AddVar_SetDiffuseColor_1( this_ptr);
  AddVar_SetDiffuseColor( this_ptr);
  AddVar_SetDiffuseColor_2( this_ptr);
  AddVar_GetDiffuseColor_1( this_ptr);
  AddVar_GetDiffuseColor( this_ptr);
  AddVar_GetDiffuseColor_2( this_ptr);
  AddVar_GetDiffuseColor_3( this_ptr);
  AddVar_SetSpecularColor_1( this_ptr);
  AddVar_SetSpecularColor( this_ptr);
  AddVar_SetSpecularColor_2( this_ptr);
  AddVar_GetSpecularColor_1( this_ptr);
  AddVar_GetSpecularColor( this_ptr);
  AddVar_GetSpecularColor_2( this_ptr);
  AddVar_GetSpecularColor_3( this_ptr);
  AddVar_GetEdgeVisibility( this_ptr);
  AddVar_SetEdgeVisibility( this_ptr);
  AddVar_EdgeVisibilityOn( this_ptr);
  AddVar_EdgeVisibilityOff( this_ptr);
  AddVar_SetEdgeColor_1( this_ptr);
  AddVar_SetEdgeColor( this_ptr);
  AddVar_SetEdgeColor_2( this_ptr);
  AddVar_GetEdgeColor_1( this_ptr);
  AddVar_GetEdgeColor( this_ptr);
  AddVar_GetEdgeColor_2( this_ptr);
  AddVar_GetEdgeColor_3( this_ptr);
  AddVar_SetLineWidth( this_ptr);
  AddVar_GetLineWidthMinValue( this_ptr);
  AddVar_GetLineWidthMaxValue( this_ptr);
  AddVar_GetLineWidth( this_ptr);
  AddVar_SetLineStipplePattern( this_ptr);
  AddVar_GetLineStipplePattern( this_ptr);
  AddVar_SetLineStippleRepeatFactor( this_ptr);
  AddVar_GetLineStippleRepeatFactorMinValue( this_ptr);
  AddVar_GetLineStippleRepeatFactorMaxValue( this_ptr);
  AddVar_GetLineStippleRepeatFactor( this_ptr);
  AddVar_SetPointSize( this_ptr);
  AddVar_GetPointSizeMinValue( this_ptr);
  AddVar_GetPointSizeMaxValue( this_ptr);
  AddVar_GetPointSize( this_ptr);
  AddVar_GetBackfaceCulling( this_ptr);
  AddVar_SetBackfaceCulling( this_ptr);
  AddVar_BackfaceCullingOn( this_ptr);
  AddVar_BackfaceCullingOff( this_ptr);
  AddVar_GetFrontfaceCulling( this_ptr);
  AddVar_SetFrontfaceCulling( this_ptr);
  AddVar_FrontfaceCullingOn( this_ptr);
  AddVar_FrontfaceCullingOff( this_ptr);
/* The following types are missing: vtkXMLMaterial
  AddVar_GetMaterial( this_ptr);
*/
  AddVar_GetMaterialName( this_ptr);
  AddVar_LoadMaterial_1( this_ptr);
  AddVar_LoadMaterialFromString( this_ptr);
  AddVar_LoadMaterial( this_ptr);
/* The following types are missing: vtkXMLMaterial
  AddVar_LoadMaterial_2( this_ptr);
*/
  AddVar_SetShading( this_ptr);
  AddVar_GetShading( this_ptr);
  AddVar_ShadingOn( this_ptr);
  AddVar_ShadingOff( this_ptr);
/* The following types are missing: vtkShaderProgram
  AddVar_GetShaderProgram( this_ptr);
*/
  AddVar_AddShaderVariable_1( this_ptr);
  AddVar_AddShaderVariable( this_ptr);
  AddVar_AddShaderVariable_2( this_ptr);
  AddVar_AddShaderVariable_3( this_ptr);
  AddVar_AddShaderVariable_4( this_ptr);
  AddVar_AddShaderVariable_5( this_ptr);
  AddVar_AddShaderVariable_6( this_ptr);
  AddVar_AddShaderVariable_7( this_ptr);
  AddVar_AddShaderVariable_8( this_ptr);
  AddVar_AddShaderVariable_9( this_ptr);
  AddVar_AddShaderVariable_10( this_ptr);
  AddVar_AddShaderVariable_11( this_ptr);
  AddVar_AddShaderVariable_12( this_ptr);
/* The following types are missing: vtkTexture
  AddVar_SetTexture_1( this_ptr);
*/
/* The following types are missing: vtkTexture
  AddVar_GetTexture_1( this_ptr);
*/
  AddVar_SetTexture( this_ptr);
/* The following types are missing: vtkTexture
  AddVar_SetTexture_2( this_ptr);
*/
  AddVar_GetTexture( this_ptr);
/* The following types are missing: vtkTexture
  AddVar_GetTexture_2( this_ptr);
*/
  AddVar_RemoveTexture_1( this_ptr);
  AddVar_RemoveTexture( this_ptr);
  AddVar_RemoveTexture_2( this_ptr);
  AddVar_RemoveAllTextures( this_ptr);
  AddVar_GetNumberOfTextures( this_ptr);
  AddVar_ReleaseGraphicsResources( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  
  AMIObject::ptr obj_VTKTextureUnit(new AMIObject);
  obj_VTKTextureUnit->SetName("VTKTextureUnit");

  BasicVariable::ptr var_VTK_TEXTURE_UNIT_0 = AMILabType<int >::CreateVar(0);
  if (var_VTK_TEXTURE_UNIT_0.get()) {
    var_VTK_TEXTURE_UNIT_0->Rename("VTK_TEXTURE_UNIT_0");
    obj_VTKTextureUnit->GetContext()->AddVar(var_VTK_TEXTURE_UNIT_0,obj_VTKTextureUnit->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_VTKTextureUnit->GetName().c_str(),obj_VTKTextureUnit,context);


  // Adding Bases

  // Add base parent vtkObject
  boost::shared_ptr<vtkObject > parent_vtkObject(  boost::dynamic_pointer_cast<vtkObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkObject = AMILabType<vtkObject >::CreateVarFromSmtPtr(parent_vtkObject);
  context->AddVar("vtkObject",var_vtkObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkObject);
  context->AddDefault(obj_vtkObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkProperty::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkProperty");
  
  // Static methods 
  WrapClass_vtkProperty::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkProperty::AddVar_SafeDownCast(amiobject->GetContext());
  WrapClass_vtkProperty::AddVar_New(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkProperty::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkProperty::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkProperty * vtkProperty::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkProperty";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
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

  vtkProperty * res =   vtkProperty::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkProperty::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkProperty * vtkProperty::New()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkProperty";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkProperty * res =   vtkProperty::New();
  BasicVariable::ptr res_var = WrapClass_vtkProperty::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkProperty::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
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
//  Wrapping of vtkProperty * vtkProperty::NewInstance()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkProperty";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkProperty * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkProperty::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkProperty::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
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
//  Wrapping of void vtkProperty::DeepCopy(vtkProperty * p)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_DeepCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProperty, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_DeepCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkProperty* p;
  if (CheckNullVar(_p,_n))  {
    p=(vtkProperty*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkProperty > p_smtptr;
    if (!get_val_smtptr_param<vtkProperty >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    p = p_smtptr.get();
  }

  this->_objectptr->GetObj()->DeepCopy(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::Render(vtkActor * param0, vtkRenderer * param1)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_Render::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkActor, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_Render::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkActor* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkActor*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkActor > param0_smtptr;
    if (!get_val_smtptr_param<vtkActor >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  vtkRenderer* param1;
  if (CheckNullVar(_p,_n))  {
    param1=(vtkRenderer*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderer > param1_smtptr;
    if (!get_val_smtptr_param<vtkRenderer >(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param1 = param1_smtptr.get();
  }

  this->_objectptr->GetObj()->Render(param0, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::BackfaceRender(vtkActor * param0, vtkRenderer * param1)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_BackfaceRender::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkActor, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_BackfaceRender::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkActor* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkActor*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkActor > param0_smtptr;
    if (!get_val_smtptr_param<vtkActor >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  vtkRenderer* param1;
  if (CheckNullVar(_p,_n))  {
    param1=(vtkRenderer*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderer > param1_smtptr;
    if (!get_val_smtptr_param<vtkRenderer >(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param1 = param1_smtptr.get();
  }

  this->_objectptr->GetObj()->BackfaceRender(param0, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::PostRender(vtkActor * param0, vtkRenderer * param1)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_PostRender::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkActor, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_PostRender::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkActor* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkActor*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkActor > param0_smtptr;
    if (!get_val_smtptr_param<vtkActor >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  vtkRenderer* param1;
  if (CheckNullVar(_p,_n))  {
    param1=(vtkRenderer*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderer > param1_smtptr;
    if (!get_val_smtptr_param<vtkRenderer >(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param1 = param1_smtptr.get();
  }

  this->_objectptr->GetObj()->PostRender(param0, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool vtkProperty::GetLighting()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetLighting::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetLighting::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetLighting();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetLighting(bool _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetLighting::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetLighting::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool _arg;
  if (!get_val_param<bool >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetLighting(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::LightingOn()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_LightingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_LightingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->LightingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::LightingOff()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_LightingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_LightingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->LightingOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetInterpolation(int _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetInterpolation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetInterpolation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInterpolation(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkProperty::GetInterpolationMinValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetInterpolationMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetInterpolationMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetInterpolationMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkProperty::GetInterpolationMaxValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetInterpolationMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetInterpolationMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetInterpolationMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkProperty::GetInterpolation()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetInterpolation::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetInterpolation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetInterpolation();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetInterpolationToFlat()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetInterpolationToFlat::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetInterpolationToFlat::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInterpolationToFlat();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetInterpolationToGouraud()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetInterpolationToGouraud::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetInterpolationToGouraud::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInterpolationToGouraud();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetInterpolationToPhong()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetInterpolationToPhong::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetInterpolationToPhong::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInterpolationToPhong();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char const * vtkProperty::GetInterpolationAsString()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetInterpolationAsString::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetInterpolationAsString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   this->_objectptr->GetObj()->GetInterpolationAsString();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetRepresentation(int _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetRepresentation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetRepresentation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRepresentation(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkProperty::GetRepresentationMinValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetRepresentationMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetRepresentationMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetRepresentationMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkProperty::GetRepresentationMaxValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetRepresentationMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetRepresentationMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetRepresentationMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkProperty::GetRepresentation()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetRepresentation::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetRepresentation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetRepresentation();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetRepresentationToPoints()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetRepresentationToPoints::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetRepresentationToPoints::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRepresentationToPoints();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetRepresentationToWireframe()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetRepresentationToWireframe::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetRepresentationToWireframe::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRepresentationToWireframe();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetRepresentationToSurface()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetRepresentationToSurface::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetRepresentationToSurface::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRepresentationToSurface();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char const * vtkProperty::GetRepresentationAsString()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetRepresentationAsString::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetRepresentationAsString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   this->_objectptr->GetObj()->GetRepresentationAsString();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetColor(double r, double g, double b)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetColor_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'g'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'b'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetColor_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  double r;
  if (!get_val_param<double >(r,_p,_n,true,true)) ClassReturnEmptyVar;

  double g;
  if (!get_val_param<double >(g,_p,_n,true,true)) ClassReturnEmptyVar;

  double b;
  if (!get_val_param<double >(b,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetColor(r, g, b);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProperty::SetColor(...)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetColor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetColor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProperty::wrap_SetColor_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_SetColor_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetColor(double * a)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetColor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'a'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetColor_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* a;
  if (CheckNullVar(_p,_n))  {
    a=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > a_smtptr;
    if (!get_val_smtptr_param<double >(a_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    a = a_smtptr.get();
  }

  this->_objectptr->GetObj()->SetColor(a);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkProperty::GetColor()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetColor_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetColor_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetColor();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProperty::GetColor(...)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetColor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetColor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProperty::wrap_GetColor_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_GetColor_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_GetColor_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::GetColor(double * rgb)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetColor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'rgb'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetColor_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* rgb;
  if (CheckNullVar(_p,_n))  {
    rgb=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > rgb_smtptr;
    if (!get_val_smtptr_param<double >(rgb_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    rgb = rgb_smtptr.get();
  }

  this->_objectptr->GetObj()->GetColor(rgb);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::GetColor(double & r, double & g, double & b)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetColor_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'g'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'b'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetColor_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > r_smtptr;
  if (!get_val_smtptr_param<double >(r_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & r = *r_smtptr;

  boost::shared_ptr<double > g_smtptr;
  if (!get_val_smtptr_param<double >(g_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & g = *g_smtptr;

  boost::shared_ptr<double > b_smtptr;
  if (!get_val_smtptr_param<double >(b_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & b = *b_smtptr;

  this->_objectptr->GetObj()->GetColor(r, g, b);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetAmbient(double _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetAmbient::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetAmbient::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAmbient(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkProperty::GetAmbientMinValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetAmbientMinValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetAmbientMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetAmbientMinValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkProperty::GetAmbientMaxValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetAmbientMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetAmbientMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetAmbientMaxValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkProperty::GetAmbient()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetAmbient::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetAmbient::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetAmbient();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetDiffuse(double _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetDiffuse::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetDiffuse::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDiffuse(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkProperty::GetDiffuseMinValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetDiffuseMinValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetDiffuseMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetDiffuseMinValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkProperty::GetDiffuseMaxValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetDiffuseMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetDiffuseMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetDiffuseMaxValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkProperty::GetDiffuse()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetDiffuse::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetDiffuse::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetDiffuse();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetSpecular(double _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetSpecular::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetSpecular::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetSpecular(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkProperty::GetSpecularMinValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetSpecularMinValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetSpecularMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetSpecularMinValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkProperty::GetSpecularMaxValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetSpecularMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetSpecularMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetSpecularMaxValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkProperty::GetSpecular()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetSpecular::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetSpecular::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetSpecular();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetSpecularPower(double _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetSpecularPower::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetSpecularPower::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetSpecularPower(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkProperty::GetSpecularPowerMinValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetSpecularPowerMinValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetSpecularPowerMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetSpecularPowerMinValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkProperty::GetSpecularPowerMaxValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetSpecularPowerMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetSpecularPowerMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetSpecularPowerMaxValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkProperty::GetSpecularPower()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetSpecularPower::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetSpecularPower::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetSpecularPower();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetOpacity(double _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetOpacity::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetOpacity::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetOpacity(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkProperty::GetOpacityMinValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetOpacityMinValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetOpacityMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetOpacityMinValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkProperty::GetOpacityMaxValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetOpacityMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetOpacityMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetOpacityMaxValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkProperty::GetOpacity()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetOpacity::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetOpacity::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetOpacity();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetAmbientColor(double _arg1, double _arg2, double _arg3)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetAmbientColor_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetAmbientColor_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetAmbientColor(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProperty::SetAmbientColor(...)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetAmbientColor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetAmbientColor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProperty::wrap_SetAmbientColor_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_SetAmbientColor_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetAmbientColor(double * _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetAmbientColor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetAmbientColor_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetAmbientColor(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkProperty::GetAmbientColor()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetAmbientColor_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetAmbientColor_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetAmbientColor();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProperty::GetAmbientColor(...)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetAmbientColor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetAmbientColor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProperty::wrap_GetAmbientColor_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_GetAmbientColor_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_GetAmbientColor_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::GetAmbientColor(double & _arg1, double & _arg2, double & _arg3)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetAmbientColor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetAmbientColor_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  boost::shared_ptr<double > _arg3_smtptr;
  if (!get_val_smtptr_param<double >(_arg3_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg3 = *_arg3_smtptr;

  this->_objectptr->GetObj()->GetAmbientColor(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::GetAmbientColor(double * _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetAmbientColor_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetAmbientColor_3::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->GetAmbientColor(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetDiffuseColor(double _arg1, double _arg2, double _arg3)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetDiffuseColor_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetDiffuseColor_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetDiffuseColor(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProperty::SetDiffuseColor(...)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetDiffuseColor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetDiffuseColor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProperty::wrap_SetDiffuseColor_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_SetDiffuseColor_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetDiffuseColor(double * _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetDiffuseColor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetDiffuseColor_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetDiffuseColor(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkProperty::GetDiffuseColor()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetDiffuseColor_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetDiffuseColor_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetDiffuseColor();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProperty::GetDiffuseColor(...)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetDiffuseColor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetDiffuseColor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProperty::wrap_GetDiffuseColor_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_GetDiffuseColor_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_GetDiffuseColor_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::GetDiffuseColor(double & _arg1, double & _arg2, double & _arg3)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetDiffuseColor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetDiffuseColor_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  boost::shared_ptr<double > _arg3_smtptr;
  if (!get_val_smtptr_param<double >(_arg3_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg3 = *_arg3_smtptr;

  this->_objectptr->GetObj()->GetDiffuseColor(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::GetDiffuseColor(double * _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetDiffuseColor_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetDiffuseColor_3::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->GetDiffuseColor(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetSpecularColor(double _arg1, double _arg2, double _arg3)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetSpecularColor_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetSpecularColor_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetSpecularColor(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProperty::SetSpecularColor(...)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetSpecularColor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetSpecularColor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProperty::wrap_SetSpecularColor_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_SetSpecularColor_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetSpecularColor(double * _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetSpecularColor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetSpecularColor_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetSpecularColor(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkProperty::GetSpecularColor()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetSpecularColor_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetSpecularColor_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetSpecularColor();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProperty::GetSpecularColor(...)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetSpecularColor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetSpecularColor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProperty::wrap_GetSpecularColor_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_GetSpecularColor_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_GetSpecularColor_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::GetSpecularColor(double & _arg1, double & _arg2, double & _arg3)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetSpecularColor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetSpecularColor_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  boost::shared_ptr<double > _arg3_smtptr;
  if (!get_val_smtptr_param<double >(_arg3_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg3 = *_arg3_smtptr;

  this->_objectptr->GetObj()->GetSpecularColor(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::GetSpecularColor(double * _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetSpecularColor_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetSpecularColor_3::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->GetSpecularColor(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkProperty::GetEdgeVisibility()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetEdgeVisibility::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetEdgeVisibility::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetEdgeVisibility();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetEdgeVisibility(int _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetEdgeVisibility::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetEdgeVisibility::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetEdgeVisibility(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::EdgeVisibilityOn()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_EdgeVisibilityOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_EdgeVisibilityOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EdgeVisibilityOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::EdgeVisibilityOff()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_EdgeVisibilityOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_EdgeVisibilityOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EdgeVisibilityOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetEdgeColor(double _arg1, double _arg2, double _arg3)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetEdgeColor_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetEdgeColor_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetEdgeColor(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProperty::SetEdgeColor(...)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetEdgeColor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetEdgeColor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProperty::wrap_SetEdgeColor_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_SetEdgeColor_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetEdgeColor(double * _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetEdgeColor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetEdgeColor_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetEdgeColor(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkProperty::GetEdgeColor()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetEdgeColor_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetEdgeColor_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetEdgeColor();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProperty::GetEdgeColor(...)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetEdgeColor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetEdgeColor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProperty::wrap_GetEdgeColor_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_GetEdgeColor_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_GetEdgeColor_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::GetEdgeColor(double & _arg1, double & _arg2, double & _arg3)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetEdgeColor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetEdgeColor_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  boost::shared_ptr<double > _arg3_smtptr;
  if (!get_val_smtptr_param<double >(_arg3_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg3 = *_arg3_smtptr;

  this->_objectptr->GetObj()->GetEdgeColor(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::GetEdgeColor(double * _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetEdgeColor_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetEdgeColor_3::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->GetEdgeColor(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetLineWidth(float _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetLineWidth::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetLineWidth::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!get_val_param<float >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetLineWidth(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkProperty::GetLineWidthMinValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetLineWidthMinValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetLineWidthMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetLineWidthMinValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkProperty::GetLineWidthMaxValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetLineWidthMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetLineWidthMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetLineWidthMaxValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkProperty::GetLineWidth()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetLineWidth::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetLineWidth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetLineWidth();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetLineStipplePattern(int _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetLineStipplePattern::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetLineStipplePattern::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetLineStipplePattern(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkProperty::GetLineStipplePattern()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetLineStipplePattern::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetLineStipplePattern::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetLineStipplePattern();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetLineStippleRepeatFactor(int _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetLineStippleRepeatFactor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetLineStippleRepeatFactor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetLineStippleRepeatFactor(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkProperty::GetLineStippleRepeatFactorMinValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetLineStippleRepeatFactorMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetLineStippleRepeatFactorMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetLineStippleRepeatFactorMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkProperty::GetLineStippleRepeatFactorMaxValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetLineStippleRepeatFactorMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetLineStippleRepeatFactorMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetLineStippleRepeatFactorMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkProperty::GetLineStippleRepeatFactor()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetLineStippleRepeatFactor::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetLineStippleRepeatFactor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetLineStippleRepeatFactor();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetPointSize(float _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetPointSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetPointSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!get_val_param<float >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetPointSize(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkProperty::GetPointSizeMinValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetPointSizeMinValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetPointSizeMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetPointSizeMinValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkProperty::GetPointSizeMaxValue()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetPointSizeMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetPointSizeMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetPointSizeMaxValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkProperty::GetPointSize()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetPointSize::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetPointSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetPointSize();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkProperty::GetBackfaceCulling()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetBackfaceCulling::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetBackfaceCulling::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetBackfaceCulling();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetBackfaceCulling(int _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetBackfaceCulling::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetBackfaceCulling::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetBackfaceCulling(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::BackfaceCullingOn()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_BackfaceCullingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_BackfaceCullingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->BackfaceCullingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::BackfaceCullingOff()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_BackfaceCullingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_BackfaceCullingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->BackfaceCullingOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkProperty::GetFrontfaceCulling()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetFrontfaceCulling::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetFrontfaceCulling::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetFrontfaceCulling();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetFrontfaceCulling(int _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetFrontfaceCulling::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetFrontfaceCulling::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFrontfaceCulling(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::FrontfaceCullingOn()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_FrontfaceCullingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_FrontfaceCullingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->FrontfaceCullingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::FrontfaceCullingOff()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_FrontfaceCullingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_FrontfaceCullingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->FrontfaceCullingOff();
  return BasicVariable::ptr();
}
/* The following types are missing: vtkXMLMaterial

//---------------------------------------------------
//  Wrapping of vtkXMLMaterial * vtkProperty::GetMaterial()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetMaterial::SetParametersComments()
{
  return_comments="returning a variable of type vtkXMLMaterial";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetMaterial::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkXMLMaterial * res =   this->_objectptr->GetObj()->GetMaterial();
  return AMILabType<vtkXMLMaterial >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of char * vtkProperty::GetMaterialName()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetMaterialName::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetMaterialName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char * res =   this->_objectptr->GetObj()->GetMaterialName();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::LoadMaterial(char const * name)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_LoadMaterial_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_LoadMaterial_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  this->_objectptr->GetObj()->LoadMaterial(name);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::LoadMaterialFromString(char const * materialxml)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_LoadMaterialFromString::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'materialxml'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_LoadMaterialFromString::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > materialxml_string;
  if (!get_val_smtptr_param<std::string >(materialxml_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * materialxml = materialxml_string->c_str();

  this->_objectptr->GetObj()->LoadMaterialFromString(materialxml);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProperty::LoadMaterial(...)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_LoadMaterial::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_LoadMaterial::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProperty::wrap_LoadMaterial_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkXMLMaterial

//---------------------------------------------------
//  Wrapping of void vtkProperty::LoadMaterial(vtkXMLMaterial * param0)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_LoadMaterial_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkXMLMaterial, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_LoadMaterial_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkXMLMaterial* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkXMLMaterial*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkXMLMaterial > param0_smtptr;
    if (!get_val_smtptr_param<vtkXMLMaterial >(param0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->LoadMaterial(param0);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetShading(int _arg)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetShading::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetShading::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetShading(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkProperty::GetShading()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetShading::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetShading::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetShading();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::ShadingOn()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_ShadingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_ShadingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ShadingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::ShadingOff()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_ShadingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_ShadingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ShadingOff();
  return BasicVariable::ptr();
}
/* The following types are missing: vtkShaderProgram

//---------------------------------------------------
//  Wrapping of vtkShaderProgram * vtkProperty::GetShaderProgram()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetShaderProgram::SetParametersComments()
{
  return_comments="returning a variable of type vtkShaderProgram";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetShaderProgram::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkShaderProgram * res =   this->_objectptr->GetObj()->GetShaderProgram();
  return AMILabType<vtkShaderProgram >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkProperty::AddShaderVariable(char const * name, int numVars, int * x)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_AddShaderVariable_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'numVars'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_AddShaderVariable_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  int numVars;
  if (!get_val_param<int >(numVars,_p,_n,true,true)) ClassReturnEmptyVar;

  int* x;
  if (CheckNullVar(_p,_n))  {
    x=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > x_smtptr;
    if (!get_val_smtptr_param<int >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    x = x_smtptr.get();
  }

  this->_objectptr->GetObj()->AddShaderVariable(name, numVars, x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProperty::AddShaderVariable(...)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_AddShaderVariable::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_AddShaderVariable::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProperty::wrap_AddShaderVariable_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_AddShaderVariable_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_AddShaderVariable_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_AddShaderVariable_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_AddShaderVariable_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_AddShaderVariable_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_AddShaderVariable_7 m7(this->_objectptr);
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_AddShaderVariable_8 m8(this->_objectptr);
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_AddShaderVariable_9 m9(this->_objectptr);
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_AddShaderVariable_10 m10(this->_objectptr);
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_AddShaderVariable_11 m11(this->_objectptr);
  res = m11.CallMember(_p);
  if (!m11.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_AddShaderVariable_12 m12(this->_objectptr);
  res = m12.CallMember(_p);
  if (!m12.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::AddShaderVariable(char const * name, int numVars, float * x)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_AddShaderVariable_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'numVars'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_AddShaderVariable_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  int numVars;
  if (!get_val_param<int >(numVars,_p,_n,true,true)) ClassReturnEmptyVar;

  float* x;
  if (CheckNullVar(_p,_n))  {
    x=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > x_smtptr;
    if (!get_val_smtptr_param<float >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    x = x_smtptr.get();
  }

  this->_objectptr->GetObj()->AddShaderVariable(name, numVars, x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::AddShaderVariable(char const * name, int numVars, double * x)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_AddShaderVariable_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'numVars'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_AddShaderVariable_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  int numVars;
  if (!get_val_param<int >(numVars,_p,_n,true,true)) ClassReturnEmptyVar;

  double* x;
  if (CheckNullVar(_p,_n))  {
    x=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > x_smtptr;
    if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    x = x_smtptr.get();
  }

  this->_objectptr->GetObj()->AddShaderVariable(name, numVars, x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::AddShaderVariable(char const * name, int v)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_AddShaderVariable_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_AddShaderVariable_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  int v;
  if (!get_val_param<int >(v,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->AddShaderVariable(name, v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::AddShaderVariable(char const * name, float v)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_AddShaderVariable_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_AddShaderVariable_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  float v;
  if (!get_val_param<float >(v,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->AddShaderVariable(name, v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::AddShaderVariable(char const * name, double v)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_AddShaderVariable_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_AddShaderVariable_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  double v;
  if (!get_val_param<double >(v,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->AddShaderVariable(name, v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::AddShaderVariable(char const * name, int v1, int v2)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_AddShaderVariable_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'v1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'v2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_AddShaderVariable_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  int v1;
  if (!get_val_param<int >(v1,_p,_n,true,true)) ClassReturnEmptyVar;

  int v2;
  if (!get_val_param<int >(v2,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->AddShaderVariable(name, v1, v2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::AddShaderVariable(char const * name, float v1, float v2)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_AddShaderVariable_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'v1'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'v2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_AddShaderVariable_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  float v1;
  if (!get_val_param<float >(v1,_p,_n,true,true)) ClassReturnEmptyVar;

  float v2;
  if (!get_val_param<float >(v2,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->AddShaderVariable(name, v1, v2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::AddShaderVariable(char const * name, double v1, double v2)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_AddShaderVariable_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_AddShaderVariable_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  double v1;
  if (!get_val_param<double >(v1,_p,_n,true,true)) ClassReturnEmptyVar;

  double v2;
  if (!get_val_param<double >(v2,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->AddShaderVariable(name, v1, v2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::AddShaderVariable(char const * name, int v1, int v2, int v3)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_AddShaderVariable_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'v1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'v2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'v3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_AddShaderVariable_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  int v1;
  if (!get_val_param<int >(v1,_p,_n,true,true)) ClassReturnEmptyVar;

  int v2;
  if (!get_val_param<int >(v2,_p,_n,true,true)) ClassReturnEmptyVar;

  int v3;
  if (!get_val_param<int >(v3,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->AddShaderVariable(name, v1, v2, v3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::AddShaderVariable(char const * name, float v1, float v2, float v3)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_AddShaderVariable_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'v1'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'v2'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'v3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_AddShaderVariable_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  float v1;
  if (!get_val_param<float >(v1,_p,_n,true,true)) ClassReturnEmptyVar;

  float v2;
  if (!get_val_param<float >(v2,_p,_n,true,true)) ClassReturnEmptyVar;

  float v3;
  if (!get_val_param<float >(v3,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->AddShaderVariable(name, v1, v2, v3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::AddShaderVariable(char const * name, double v1, double v2, double v3)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_AddShaderVariable_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_AddShaderVariable_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  double v1;
  if (!get_val_param<double >(v1,_p,_n,true,true)) ClassReturnEmptyVar;

  double v2;
  if (!get_val_param<double >(v2,_p,_n,true,true)) ClassReturnEmptyVar;

  double v3;
  if (!get_val_param<double >(v3,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->AddShaderVariable(name, v1, v2, v3);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkTexture

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetTexture(char const * name, vtkTexture * texture)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetTexture_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( vtkTexture, "parameter named 'texture'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetTexture_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  vtkTexture* texture;
  if (CheckNullVar(_p,_n))  {
    texture=(vtkTexture*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkTexture > texture_smtptr;
    if (!get_val_smtptr_param<vtkTexture >(texture_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    texture = texture_smtptr.get();
  }

  this->_objectptr->GetObj()->SetTexture(name, texture);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkTexture

//---------------------------------------------------
//  Wrapping of vtkTexture * vtkProperty::GetTexture(char const * name)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetTexture_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  return_comments="returning a variable of type vtkTexture";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetTexture_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  vtkTexture * res =   this->_objectptr->GetObj()->GetTexture(name);
  return AMILabType<vtkTexture >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProperty::SetTexture(...)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetTexture::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetTexture::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkTexture

//---------------------------------------------------
//  Wrapping of void vtkProperty::SetTexture(int unit, vtkTexture * texture)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_SetTexture_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'unit'")
  ADDPARAMCOMMENT_TYPE( vtkTexture, "parameter named 'texture'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_SetTexture_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int unit;
  if (!get_val_param<int >(unit,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkTexture* texture;
  if (CheckNullVar(_p,_n))  {
    texture=(vtkTexture*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkTexture > texture_smtptr;
    if (!get_val_smtptr_param<vtkTexture >(texture_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    texture = texture_smtptr.get();
  }

  this->_objectptr->GetObj()->SetTexture(unit, texture);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProperty::GetTexture(...)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetTexture::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetTexture::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkTexture

//---------------------------------------------------
//  Wrapping of vtkTexture * vtkProperty::GetTexture(int unit)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetTexture_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'unit'")
  return_comments="returning a variable of type vtkTexture";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetTexture_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int unit;
  if (!get_val_param<int >(unit,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkTexture * res =   this->_objectptr->GetObj()->GetTexture(unit);
  return AMILabType<vtkTexture >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkProperty::RemoveTexture(int unit)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_RemoveTexture_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'unit'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_RemoveTexture_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int unit;
  if (!get_val_param<int >(unit,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->RemoveTexture(unit);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProperty::RemoveTexture(...)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_RemoveTexture::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_RemoveTexture::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProperty::wrap_RemoveTexture_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProperty::wrap_RemoveTexture_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::RemoveTexture(char const * name)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_RemoveTexture_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_RemoveTexture_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * name = name_string->c_str();

  this->_objectptr->GetObj()->RemoveTexture(name);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::RemoveAllTextures()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_RemoveAllTextures::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_RemoveAllTextures::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RemoveAllTextures();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkProperty::GetNumberOfTextures()
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_GetNumberOfTextures::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_GetNumberOfTextures::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfTextures();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProperty::ReleaseGraphicsResources(vtkWindow * win)
//---------------------------------------------------
void WrapClass_vtkProperty::
    wrap_ReleaseGraphicsResources::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkWindow, "parameter named 'win'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProperty::
    wrap_ReleaseGraphicsResources::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkWindow* win;
  if (CheckNullVar(_p,_n))  {
    win=(vtkWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkWindow > win_smtptr;
    if (!get_val_smtptr_param<vtkWindow >(win_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    win = win_smtptr.get();
  }

  this->_objectptr->GetObj()->ReleaseGraphicsResources(win);
  return BasicVariable::ptr();
}

