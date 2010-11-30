/**
 * C++ Interface: wrap_vtkVolumeRayCastCompositeFunction
 *
 * Description: wrapping vtkVolumeRayCastCompositeFunction
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
#include "wrap_vtkVolumeRayCastCompositeFunction.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkVolumeRayCastDynamicInfo.h"
#include "wrap_vtkVolumeRayCastStaticInfo.h"
#include "wrap_vtkVolume.h"


#include "wrap_vtkVolumeRayCastCompositeFunction.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkVolumeRayCastCompositeFunction>::CreateVar( ParamList* p)
{
  WrapClass_vtkVolumeRayCastCompositeFunction::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkVolumeRayCastCompositeFunction);
AMI_DEFINE_VARFROMSMTPTR(vtkVolumeRayCastCompositeFunction);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkVolumeRayCastCompositeFunction>::CreateVar( vtkVolumeRayCastCompositeFunction* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkVolumeRayCastCompositeFunction> obj_ptr(val,smartpointer_nodeleter<vtkVolumeRayCastCompositeFunction>());
  return AMILabType<vtkVolumeRayCastCompositeFunction>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkVolumeRayCastCompositeFunction
//
Variable<AMIObject>::ptr WrapClass_vtkVolumeRayCastCompositeFunction::CreateVar( vtkVolumeRayCastCompositeFunction* sp)
{
  boost::shared_ptr<vtkVolumeRayCastCompositeFunction> di_ptr(
    sp,
    wxwindow_nodeleter<vtkVolumeRayCastCompositeFunction>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkVolumeRayCastCompositeFunction>::CreateVar(
      new WrapClass_vtkVolumeRayCastCompositeFunction(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkVolumeRayCastCompositeFunction::AddMethods(WrapClass<vtkVolumeRayCastCompositeFunction>::ptr this_ptr )
{
  
      // Add members from vtkVolumeRayCastFunction
      WrapClass_vtkVolumeRayCastFunction::ptr parent_vtkVolumeRayCastFunction(        boost::dynamic_pointer_cast<WrapClass_vtkVolumeRayCastFunction >(this_ptr));
      parent_vtkVolumeRayCastFunction->AddMethods(parent_vtkVolumeRayCastFunction);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_SetCompositeMethod( this_ptr);
      AddVar_GetCompositeMethodMinValue( this_ptr);
      AddVar_GetCompositeMethodMaxValue( this_ptr);
      AddVar_GetCompositeMethod( this_ptr);
      AddVar_SetCompositeMethodToInterpolateFirst( this_ptr);
      AddVar_SetCompositeMethodToClassifyFirst( this_ptr);
      AddVar_GetCompositeMethodAsString( this_ptr);
      AddVar_CastRay( this_ptr);
      AddVar_GetZeroOpacityThreshold( this_ptr);



  
};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkVolumeRayCastCompositeFunction::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkVolumeRayCastCompositeFunction");
  
  // Static methods 
  WrapClass_vtkVolumeRayCastCompositeFunction::AddVar_New(amiobject->GetContext());
  WrapClass_vtkVolumeRayCastCompositeFunction::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkVolumeRayCastCompositeFunction::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkVolumeRayCastCompositeFunction * vtkVolumeRayCastCompositeFunction::New()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolumeRayCastCompositeFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolumeRayCastCompositeFunction * res =   vtkVolumeRayCastCompositeFunction::New();
  BasicVariable::ptr res_var = WrapClass_vtkVolumeRayCastCompositeFunction::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeRayCastCompositeFunction::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkVolumeRayCastCompositeFunction::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkVolumeRayCastCompositeFunction * vtkVolumeRayCastCompositeFunction::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkVolumeRayCastCompositeFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkVolumeRayCastCompositeFunction * res =   vtkVolumeRayCastCompositeFunction::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkVolumeRayCastCompositeFunction::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeRayCastCompositeFunction::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastCompositeFunction::
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
//  Wrapping of vtkVolumeRayCastCompositeFunction * vtkVolumeRayCastCompositeFunction::NewInstance()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolumeRayCastCompositeFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolumeRayCastCompositeFunction * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkVolumeRayCastCompositeFunction::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastCompositeFunction::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastCompositeFunction::
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
//  Wrapping of void vtkVolumeRayCastCompositeFunction::SetCompositeMethod(int _arg)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_SetCompositeMethod::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_SetCompositeMethod::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCompositeMethod(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeRayCastCompositeFunction::GetCompositeMethodMinValue()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_GetCompositeMethodMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_GetCompositeMethodMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCompositeMethodMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeRayCastCompositeFunction::GetCompositeMethodMaxValue()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_GetCompositeMethodMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_GetCompositeMethodMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCompositeMethodMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeRayCastCompositeFunction::GetCompositeMethod()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_GetCompositeMethod::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_GetCompositeMethod::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCompositeMethod();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastCompositeFunction::SetCompositeMethodToInterpolateFirst()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_SetCompositeMethodToInterpolateFirst::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_SetCompositeMethodToInterpolateFirst::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCompositeMethodToInterpolateFirst();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastCompositeFunction::SetCompositeMethodToClassifyFirst()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_SetCompositeMethodToClassifyFirst::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_SetCompositeMethodToClassifyFirst::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCompositeMethodToClassifyFirst();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char const * vtkVolumeRayCastCompositeFunction::GetCompositeMethodAsString()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_GetCompositeMethodAsString::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_GetCompositeMethodAsString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   this->_objectptr->GetObj()->GetCompositeMethodAsString();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastCompositeFunction::CastRay(vtkVolumeRayCastDynamicInfo * dynamicInfo, vtkVolumeRayCastStaticInfo * staticInfo)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_CastRay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVolumeRayCastDynamicInfo, "parameter named 'dynamicInfo'")
  ADDPARAMCOMMENT_TYPE( vtkVolumeRayCastStaticInfo, "parameter named 'staticInfo'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_CastRay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVolumeRayCastDynamicInfo > dynamicInfo_smtptr;
  if (!get_val_smtptr_param<vtkVolumeRayCastDynamicInfo >(dynamicInfo_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVolumeRayCastDynamicInfo* dynamicInfo = dynamicInfo_smtptr.get();

  boost::shared_ptr<vtkVolumeRayCastStaticInfo > staticInfo_smtptr;
  if (!get_val_smtptr_param<vtkVolumeRayCastStaticInfo >(staticInfo_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVolumeRayCastStaticInfo* staticInfo = staticInfo_smtptr.get();

  this->_objectptr->GetObj()->CastRay(dynamicInfo, staticInfo);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkVolumeRayCastCompositeFunction::GetZeroOpacityThreshold(vtkVolume * vol)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastCompositeFunction::
    wrap_GetZeroOpacityThreshold::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVolume, "parameter named 'vol'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastCompositeFunction::
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

