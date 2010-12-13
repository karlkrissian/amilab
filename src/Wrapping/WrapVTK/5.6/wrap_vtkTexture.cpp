/**
 * C++ Interface: wrap_vtkTexture
 *
 * Description: wrapping vtkTexture
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

#include "wrap_vtkTexture.h"

// get all the required includes
// #include "..."
#ifndef vtkTexture_declared
  #define vtkTexture_declared
  AMI_DECLARE_TYPE(vtkTexture)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkRenderer_declared
  #define vtkRenderer_declared
  AMI_DECLARE_TYPE(vtkRenderer)
#endif
#ifndef vtkWindow_declared
  #define vtkWindow_declared
  AMI_DECLARE_TYPE(vtkWindow)
#endif
#ifndef vtkImageData_declared
  #define vtkImageData_declared
  AMI_DECLARE_TYPE(vtkImageData)
#endif
#ifndef vtkScalarsToColors_declared
  #define vtkScalarsToColors_declared
  AMI_DECLARE_TYPE(vtkScalarsToColors)
#endif
#ifndef vtkUnsignedCharArray_declared
  #define vtkUnsignedCharArray_declared
  AMI_DECLARE_TYPE(vtkUnsignedCharArray)
#endif
#ifndef vtkDataArray_declared
  #define vtkDataArray_declared
  AMI_DECLARE_TYPE(vtkDataArray)
#endif
#ifndef vtkTransform_declared
  #define vtkTransform_declared
  AMI_DECLARE_TYPE(vtkTransform)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkTexture>::CreateVar( ParamList* p)
{
  WrapClass_vtkTexture::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkTexture);
AMI_DEFINE_VARFROMSMTPTR(vtkTexture);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkTexture>::CreateVar( vtkTexture* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkTexture> obj_ptr(val,smartpointer_nodeleter<vtkTexture>());
  return AMILabType<vtkTexture>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkTexture
//
Variable<AMIObject>::ptr WrapClass_vtkTexture::CreateVar( vtkTexture* sp)
{
  boost::shared_ptr<vtkTexture> di_ptr(
    sp,
    wxwindow_nodeleter<vtkTexture>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkTexture>::CreateVar(
      new WrapClass_vtkTexture(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkTexture::AddMethods(WrapClass<vtkTexture>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_Render( this_ptr);
  AddVar_PostRender( this_ptr);
  AddVar_ReleaseGraphicsResources( this_ptr);
  AddVar_Load( this_ptr);
  AddVar_GetRepeat( this_ptr);
  AddVar_SetRepeat( this_ptr);
  AddVar_RepeatOn( this_ptr);
  AddVar_RepeatOff( this_ptr);
  AddVar_GetEdgeClamp( this_ptr);
  AddVar_SetEdgeClamp( this_ptr);
  AddVar_EdgeClampOn( this_ptr);
  AddVar_EdgeClampOff( this_ptr);
  AddVar_GetInterpolate( this_ptr);
  AddVar_SetInterpolate( this_ptr);
  AddVar_InterpolateOn( this_ptr);
  AddVar_InterpolateOff( this_ptr);
  AddVar_SetQuality( this_ptr);
  AddVar_GetQuality( this_ptr);
  AddVar_SetQualityToDefault( this_ptr);
  AddVar_SetQualityTo16Bit( this_ptr);
  AddVar_SetQualityTo32Bit( this_ptr);
  AddVar_GetMapColorScalarsThroughLookupTable( this_ptr);
  AddVar_SetMapColorScalarsThroughLookupTable( this_ptr);
  AddVar_MapColorScalarsThroughLookupTableOn( this_ptr);
  AddVar_MapColorScalarsThroughLookupTableOff( this_ptr);
  AddVar_GetInput( this_ptr);
  AddVar_SetLookupTable( this_ptr);
  AddVar_GetLookupTable( this_ptr);
  AddVar_GetMappedScalars( this_ptr);
  AddVar_MapScalarsToColors( this_ptr);
  AddVar_SetTransform( this_ptr);
  AddVar_GetTransform( this_ptr);
  AddVar_GetBlendingMode( this_ptr);
  AddVar_SetBlendingMode( this_ptr);
  AddVar_GetPremultipliedAlpha( this_ptr);
  AddVar_SetPremultipliedAlpha( this_ptr);
  AddVar_PremultipliedAlphaOn( this_ptr);
  AddVar_PremultipliedAlphaOff( this_ptr);
  AddVar_GetRestrictPowerOf2ImageSmaller( this_ptr);
  AddVar_SetRestrictPowerOf2ImageSmaller( this_ptr);
  AddVar_RestrictPowerOf2ImageSmallerOn( this_ptr);
  AddVar_RestrictPowerOf2ImageSmallerOff( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  
  AMIObject::ptr obj_VTKTextureBlendingMode(new AMIObject);
  obj_VTKTextureBlendingMode->SetName("VTKTextureBlendingMode");

  BasicVariable::ptr var_VTK_TEXTURE_BLENDING_MODE_NONE = AMILabType<int >::CreateVar(0);
  if (var_VTK_TEXTURE_BLENDING_MODE_NONE.get()) {
    var_VTK_TEXTURE_BLENDING_MODE_NONE->Rename("VTK_TEXTURE_BLENDING_MODE_NONE");
    obj_VTKTextureBlendingMode->GetContext()->AddVar(var_VTK_TEXTURE_BLENDING_MODE_NONE,obj_VTKTextureBlendingMode->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_VTKTextureBlendingMode->GetName().c_str(),obj_VTKTextureBlendingMode,context);


  // Adding Bases

  // Add base parent vtkImageAlgorithm
  boost::shared_ptr<vtkImageAlgorithm > parent_vtkImageAlgorithm(  boost::dynamic_pointer_cast<vtkImageAlgorithm >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkImageAlgorithm = AMILabType<vtkImageAlgorithm >::CreateVarFromSmtPtr(parent_vtkImageAlgorithm);
  context->AddVar("vtkImageAlgorithm",var_vtkImageAlgorithm);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkImageAlgorithm = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkImageAlgorithm);
  context->AddDefault(obj_vtkImageAlgorithm->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkTexture_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkTexture");
  
  // Static methods 
  WrapClass_vtkTexture::AddVar_New(amiobject->GetContext());
  WrapClass_vtkTexture::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkTexture::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkTexture * vtkTexture::New()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkTexture";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkTexture * res =   vtkTexture::New();
  BasicVariable::ptr res_var = AMILabType<vtkTexture >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkTexture::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkTexture::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkTexture * vtkTexture::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkTexture";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
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

  vtkTexture * res =   vtkTexture::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkTexture >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkTexture::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
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
//  Wrapping of vtkTexture * vtkTexture::NewInstance()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkTexture";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkTexture * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkTexture >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkTexture::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
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
//  Wrapping of void vtkTexture::Render(vtkRenderer * ren)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_Render::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'ren'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_Render::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkRenderer* ren;
  if (CheckNullVar(_p,_n))  {
    ren=(vtkRenderer*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderer > ren_smtptr;
    if (!get_val_smtptr_param<vtkRenderer >(ren_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    ren = ren_smtptr.get();
  }

  this->_objectptr->GetObj()->Render(ren);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::PostRender(vtkRenderer * param0)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_PostRender::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_PostRender::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkRenderer* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkRenderer*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderer > param0_smtptr;
    if (!get_val_smtptr_param<vtkRenderer >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->PostRender(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::ReleaseGraphicsResources(vtkWindow * param0)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_ReleaseGraphicsResources::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkWindow, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_ReleaseGraphicsResources::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkWindow* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkWindow > param0_smtptr;
    if (!get_val_smtptr_param<vtkWindow >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->ReleaseGraphicsResources(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::Load(vtkRenderer * param0)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_Load::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_Load::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkRenderer* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkRenderer*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderer > param0_smtptr;
    if (!get_val_smtptr_param<vtkRenderer >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->Load(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkTexture::GetRepeat()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_GetRepeat::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_GetRepeat::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetRepeat();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::SetRepeat(int _arg)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_SetRepeat::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_SetRepeat::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRepeat(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::RepeatOn()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_RepeatOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_RepeatOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RepeatOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::RepeatOff()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_RepeatOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_RepeatOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RepeatOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkTexture::GetEdgeClamp()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_GetEdgeClamp::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_GetEdgeClamp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetEdgeClamp();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::SetEdgeClamp(int _arg)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_SetEdgeClamp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_SetEdgeClamp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetEdgeClamp(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::EdgeClampOn()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_EdgeClampOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_EdgeClampOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EdgeClampOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::EdgeClampOff()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_EdgeClampOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_EdgeClampOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EdgeClampOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkTexture::GetInterpolate()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_GetInterpolate::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_GetInterpolate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetInterpolate();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::SetInterpolate(int _arg)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_SetInterpolate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_SetInterpolate::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInterpolate(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::InterpolateOn()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_InterpolateOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_InterpolateOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InterpolateOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::InterpolateOff()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_InterpolateOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_InterpolateOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InterpolateOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::SetQuality(int _arg)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_SetQuality::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_SetQuality::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetQuality(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkTexture::GetQuality()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_GetQuality::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_GetQuality::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetQuality();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::SetQualityToDefault()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_SetQualityToDefault::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_SetQualityToDefault::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetQualityToDefault();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::SetQualityTo16Bit()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_SetQualityTo16Bit::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_SetQualityTo16Bit::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetQualityTo16Bit();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::SetQualityTo32Bit()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_SetQualityTo32Bit::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_SetQualityTo32Bit::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetQualityTo32Bit();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkTexture::GetMapColorScalarsThroughLookupTable()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_GetMapColorScalarsThroughLookupTable::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_GetMapColorScalarsThroughLookupTable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMapColorScalarsThroughLookupTable();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::SetMapColorScalarsThroughLookupTable(int _arg)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_SetMapColorScalarsThroughLookupTable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_SetMapColorScalarsThroughLookupTable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMapColorScalarsThroughLookupTable(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::MapColorScalarsThroughLookupTableOn()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_MapColorScalarsThroughLookupTableOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_MapColorScalarsThroughLookupTableOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->MapColorScalarsThroughLookupTableOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::MapColorScalarsThroughLookupTableOff()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_MapColorScalarsThroughLookupTableOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_MapColorScalarsThroughLookupTableOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->MapColorScalarsThroughLookupTableOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkImageData * vtkTexture::GetInput()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_GetInput::SetParametersComments()
{
  return_comments="returning a variable of type vtkImageData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_GetInput::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkImageData * res =   this->_objectptr->GetObj()->GetInput();
  BasicVariable::ptr res_var = AMILabType<vtkImageData >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::SetLookupTable(vtkScalarsToColors * param0)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_SetLookupTable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkScalarsToColors, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_SetLookupTable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkScalarsToColors* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkScalarsToColors*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkScalarsToColors > param0_smtptr;
    if (!get_val_smtptr_param<vtkScalarsToColors >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->SetLookupTable(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkScalarsToColors * vtkTexture::GetLookupTable()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_GetLookupTable::SetParametersComments()
{
  return_comments="returning a variable of type vtkScalarsToColors";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_GetLookupTable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkScalarsToColors * res =   this->_objectptr->GetObj()->GetLookupTable();
  BasicVariable::ptr res_var = AMILabType<vtkScalarsToColors >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkUnsignedCharArray * vtkTexture::GetMappedScalars()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_GetMappedScalars::SetParametersComments()
{
  return_comments="returning a variable of type vtkUnsignedCharArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_GetMappedScalars::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkUnsignedCharArray * res =   this->_objectptr->GetObj()->GetMappedScalars();
  BasicVariable::ptr res_var = AMILabType<vtkUnsignedCharArray >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of unsigned char * vtkTexture::MapScalarsToColors(vtkDataArray * scalars)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_MapScalarsToColors::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'scalars'")
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_MapScalarsToColors::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkDataArray* scalars;
  if (CheckNullVar(_p,_n))  {
    scalars=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > scalars_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(scalars_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    scalars = scalars_smtptr.get();
  }

  unsigned char * res =   this->_objectptr->GetObj()->MapScalarsToColors(scalars);
  return AMILabType<unsigned char >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::SetTransform(vtkTransform * transform)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_SetTransform::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkTransform, "parameter named 'transform'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_SetTransform::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkTransform* transform;
  if (CheckNullVar(_p,_n))  {
    transform=(vtkTransform*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkTransform > transform_smtptr;
    if (!get_val_smtptr_param<vtkTransform >(transform_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    transform = transform_smtptr.get();
  }

  this->_objectptr->GetObj()->SetTransform(transform);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkTransform * vtkTexture::GetTransform()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_GetTransform::SetParametersComments()
{
  return_comments="returning a variable of type vtkTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_GetTransform::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkTransform * res =   this->_objectptr->GetObj()->GetTransform();
  BasicVariable::ptr res_var = AMILabType<vtkTransform >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkTexture::GetBlendingMode()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_GetBlendingMode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_GetBlendingMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetBlendingMode();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::SetBlendingMode(int _arg)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_SetBlendingMode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_SetBlendingMode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetBlendingMode(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool vtkTexture::GetPremultipliedAlpha()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_GetPremultipliedAlpha::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_GetPremultipliedAlpha::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetPremultipliedAlpha();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::SetPremultipliedAlpha(bool _arg)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_SetPremultipliedAlpha::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_SetPremultipliedAlpha::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool _arg;
  if (!get_val_param<bool >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetPremultipliedAlpha(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::PremultipliedAlphaOn()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_PremultipliedAlphaOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_PremultipliedAlphaOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PremultipliedAlphaOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::PremultipliedAlphaOff()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_PremultipliedAlphaOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_PremultipliedAlphaOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PremultipliedAlphaOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkTexture::GetRestrictPowerOf2ImageSmaller()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_GetRestrictPowerOf2ImageSmaller::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_GetRestrictPowerOf2ImageSmaller::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetRestrictPowerOf2ImageSmaller();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::SetRestrictPowerOf2ImageSmaller(int _arg)
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_SetRestrictPowerOf2ImageSmaller::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_SetRestrictPowerOf2ImageSmaller::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRestrictPowerOf2ImageSmaller(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::RestrictPowerOf2ImageSmallerOn()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_RestrictPowerOf2ImageSmallerOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_RestrictPowerOf2ImageSmallerOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RestrictPowerOf2ImageSmallerOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTexture::RestrictPowerOf2ImageSmallerOff()
//---------------------------------------------------
void WrapClass_vtkTexture::
    wrap_RestrictPowerOf2ImageSmallerOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTexture::
    wrap_RestrictPowerOf2ImageSmallerOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RestrictPowerOf2ImageSmallerOff();
  return BasicVariable::ptr();
}

