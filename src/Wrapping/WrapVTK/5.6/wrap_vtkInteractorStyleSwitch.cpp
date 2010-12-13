/**
 * C++ Interface: wrap_vtkInteractorStyleSwitch
 *
 * Description: wrapping vtkInteractorStyleSwitch
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

#include "wrap_vtkInteractorStyleSwitch.h"

// get all the required includes
// #include "..."
#ifndef vtkInteractorStyleSwitch_declared
  #define vtkInteractorStyleSwitch_declared
  AMI_DECLARE_TYPE(vtkInteractorStyleSwitch)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkRenderWindowInteractor_declared
  #define vtkRenderWindowInteractor_declared
  AMI_DECLARE_TYPE(vtkRenderWindowInteractor)
#endif
#ifndef vtkInteractorStyle_declared
  #define vtkInteractorStyle_declared
  AMI_DECLARE_TYPE(vtkInteractorStyle)
#endif
#ifndef vtkRenderer_declared
  #define vtkRenderer_declared
  AMI_DECLARE_TYPE(vtkRenderer)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkInteractorStyleSwitch>::CreateVar( ParamList* p)
{
  WrapClass_vtkInteractorStyleSwitch::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkInteractorStyleSwitch);
AMI_DEFINE_VARFROMSMTPTR(vtkInteractorStyleSwitch);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkInteractorStyleSwitch>::CreateVar( vtkInteractorStyleSwitch* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkInteractorStyleSwitch> obj_ptr(val,smartpointer_nodeleter<vtkInteractorStyleSwitch>());
  return AMILabType<vtkInteractorStyleSwitch>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkInteractorStyleSwitch
//
Variable<AMIObject>::ptr WrapClass_vtkInteractorStyleSwitch::CreateVar( vtkInteractorStyleSwitch* sp)
{
  boost::shared_ptr<vtkInteractorStyleSwitch> di_ptr(
    sp,
    wxwindow_nodeleter<vtkInteractorStyleSwitch>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkInteractorStyleSwitch>::CreateVar(
      new WrapClass_vtkInteractorStyleSwitch(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::AddMethods(WrapClass<vtkInteractorStyleSwitch>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_SetInteractor( this_ptr);
  AddVar_SetAutoAdjustCameraClippingRange( this_ptr);
  AddVar_GetCurrentStyle( this_ptr);
  AddVar_SetCurrentStyleToJoystickActor( this_ptr);
  AddVar_SetCurrentStyleToJoystickCamera( this_ptr);
  AddVar_SetCurrentStyleToTrackballActor( this_ptr);
  AddVar_SetCurrentStyleToTrackballCamera( this_ptr);
  AddVar_OnChar( this_ptr);
  AddVar_SetDefaultRenderer( this_ptr);
  AddVar_SetCurrentRenderer( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent vtkInteractorStyle
  boost::shared_ptr<vtkInteractorStyle > parent_vtkInteractorStyle(  boost::dynamic_pointer_cast<vtkInteractorStyle >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkInteractorStyle = AMILabType<vtkInteractorStyle >::CreateVarFromSmtPtr(parent_vtkInteractorStyle);
  context->AddVar("vtkInteractorStyle",var_vtkInteractorStyle);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkInteractorStyle = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkInteractorStyle);
  context->AddDefault(obj_vtkInteractorStyle->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkInteractorStyleSwitch_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkInteractorStyleSwitch");
  
  // Static methods 
  WrapClass_vtkInteractorStyleSwitch::AddVar_New(amiobject->GetContext());
  WrapClass_vtkInteractorStyleSwitch::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkInteractorStyleSwitch::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkInteractorStyleSwitch * vtkInteractorStyleSwitch::New()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkInteractorStyleSwitch";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInteractorStyleSwitch * res =   vtkInteractorStyleSwitch::New();
  BasicVariable::ptr res_var = AMILabType<vtkInteractorStyleSwitch >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyleSwitch::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkInteractorStyleSwitch::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkInteractorStyleSwitch * vtkInteractorStyleSwitch::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkInteractorStyleSwitch";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
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

  vtkInteractorStyleSwitch * res =   vtkInteractorStyleSwitch::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkInteractorStyleSwitch >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyleSwitch::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
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
//  Wrapping of vtkInteractorStyleSwitch * vtkInteractorStyleSwitch::NewInstance()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkInteractorStyleSwitch";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInteractorStyleSwitch * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkInteractorStyleSwitch >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleSwitch::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
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
//  Wrapping of void vtkInteractorStyleSwitch::SetInteractor(vtkRenderWindowInteractor * iren)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_SetInteractor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderWindowInteractor, "parameter named 'iren'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
    wrap_SetInteractor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkRenderWindowInteractor* iren;
  if (CheckNullVar(_p,_n))  {
    iren=(vtkRenderWindowInteractor*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderWindowInteractor > iren_smtptr;
    if (!get_val_smtptr_param<vtkRenderWindowInteractor >(iren_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    iren = iren_smtptr.get();
  }

  this->_objectptr->GetObj()->SetInteractor(iren);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleSwitch::SetAutoAdjustCameraClippingRange(int value)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_SetAutoAdjustCameraClippingRange::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
    wrap_SetAutoAdjustCameraClippingRange::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int value;
  if (!get_val_param<int >(value,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAutoAdjustCameraClippingRange(value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkInteractorStyle * vtkInteractorStyleSwitch::GetCurrentStyle()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_GetCurrentStyle::SetParametersComments()
{
  return_comments="returning a variable of type vtkInteractorStyle";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
    wrap_GetCurrentStyle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInteractorStyle * res =   this->_objectptr->GetObj()->GetCurrentStyle();
  BasicVariable::ptr res_var = AMILabType<vtkInteractorStyle >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleSwitch::SetCurrentStyleToJoystickActor()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_SetCurrentStyleToJoystickActor::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
    wrap_SetCurrentStyleToJoystickActor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCurrentStyleToJoystickActor();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleSwitch::SetCurrentStyleToJoystickCamera()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_SetCurrentStyleToJoystickCamera::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
    wrap_SetCurrentStyleToJoystickCamera::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCurrentStyleToJoystickCamera();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleSwitch::SetCurrentStyleToTrackballActor()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_SetCurrentStyleToTrackballActor::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
    wrap_SetCurrentStyleToTrackballActor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCurrentStyleToTrackballActor();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleSwitch::SetCurrentStyleToTrackballCamera()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_SetCurrentStyleToTrackballCamera::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
    wrap_SetCurrentStyleToTrackballCamera::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCurrentStyleToTrackballCamera();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleSwitch::OnChar()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_OnChar::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
    wrap_OnChar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnChar();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleSwitch::SetDefaultRenderer(vtkRenderer * param0)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_SetDefaultRenderer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
    wrap_SetDefaultRenderer::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetDefaultRenderer(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleSwitch::SetCurrentRenderer(vtkRenderer * param0)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_SetCurrentRenderer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
    wrap_SetCurrentRenderer::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetCurrentRenderer(param0);
  return BasicVariable::ptr();
}

