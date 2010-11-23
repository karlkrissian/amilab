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

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_vtkInteractorStyleSwitch.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkRenderWindowInteractor.h"
#include "wrap_vtkInteractorStyle.h"
#include "wrap_vtkRenderer.h"


#include "wrap_vtkInteractorStyleSwitch.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkInteractorStyleSwitch>::CreateVar( ParamList* p)
{
  WrapClass_vtkInteractorStyleSwitch::wrap_New construct;
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
  
      // Add members from vtkInteractorStyle
      WrapClass_vtkInteractorStyle::ptr parent_vtkInteractorStyle(        boost::dynamic_pointer_cast<WrapClass_vtkInteractorStyle >(this_ptr));
      parent_vtkInteractorStyle->AddMethods(parent_vtkInteractorStyle);


  // check that the method name is not a token
  
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



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkInteractorStyleSwitch * vtkInteractorStyleSwitch::New()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkInteractorStyleSwitch";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
    wrap_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInteractorStyleSwitch * res =   vtkInteractorStyleSwitch::New();
  BasicVariable::ptr res_var = WrapClass_vtkInteractorStyleSwitch::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyleSwitch::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
    wrap_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkInteractorStyleSwitch::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkInteractorStyleSwitch * vtkInteractorStyleSwitch::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleSwitch::
    wrap_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkInteractorStyleSwitch";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleSwitch::
    wrap_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkInteractorStyleSwitch * res =   vtkInteractorStyleSwitch::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkInteractorStyleSwitch::CreateVar(res);
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
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n)) ClassHelpAndReturn;
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
  BasicVariable::ptr res_var = WrapClass_vtkInteractorStyleSwitch::CreateVar(res);
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
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!get_val_param<vtkIndent >(indent,_p,_n)) ClassHelpAndReturn;

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

  boost::shared_ptr<vtkRenderWindowInteractor > iren_smtptr;
  if (!get_val_smtptr_param<vtkRenderWindowInteractor >(iren_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkRenderWindowInteractor* iren = iren_smtptr.get();

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
  if (!get_val_param<int >(value,_p,_n)) ClassHelpAndReturn;

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
  BasicVariable::ptr res_var = WrapClass_vtkInteractorStyle::CreateVar(res);
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

  boost::shared_ptr<vtkRenderer > param0_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkRenderer* param0 = param0_smtptr.get();

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

  boost::shared_ptr<vtkRenderer > param0_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkRenderer* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetCurrentRenderer(param0);
  return BasicVariable::ptr();
}

