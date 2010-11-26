/**
 * C++ Interface: wrap_vtkInteractorObserver
 *
 * Description: wrapping vtkInteractorObserver
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
#include "wrap_vtkInteractorObserver.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkRenderer.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkRenderWindowInteractor.h"
#include "wrap_vtkCommand.h"


#include "wrap_vtkInteractorObserver.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkInteractorObserver>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkInteractorObserver);
AMI_DEFINE_VARFROMSMTPTR(vtkInteractorObserver);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkInteractorObserver>::CreateVar( vtkInteractorObserver* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkInteractorObserver> obj_ptr(val,smartpointer_nodeleter<vtkInteractorObserver>());
  return AMILabType<vtkInteractorObserver>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkInteractorObserver
//
Variable<AMIObject>::ptr WrapClass_vtkInteractorObserver::CreateVar( vtkInteractorObserver* sp)
{
  boost::shared_ptr<vtkInteractorObserver> di_ptr(
    sp,
    wxwindow_nodeleter<vtkInteractorObserver>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkInteractorObserver>::CreateVar(
      new WrapClass_vtkInteractorObserver(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkInteractorObserver::AddMethods(WrapClass<vtkInteractorObserver>::ptr this_ptr )
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
      AddVar_SetEnabled( this_ptr);
      AddVar_GetEnabled( this_ptr);
      AddVar_EnabledOn( this_ptr);
      AddVar_EnabledOff( this_ptr);
      AddVar_On( this_ptr);
      AddVar_Off( this_ptr);
      AddVar_SetInteractor( this_ptr);
      AddVar_GetInteractor( this_ptr);
      AddVar_SetPriority( this_ptr);
      AddVar_GetPriorityMinValue( this_ptr);
      AddVar_GetPriorityMaxValue( this_ptr);
      AddVar_GetPriority( this_ptr);
      AddVar_SetKeyPressActivation( this_ptr);
      AddVar_GetKeyPressActivation( this_ptr);
      AddVar_KeyPressActivationOn( this_ptr);
      AddVar_KeyPressActivationOff( this_ptr);
      AddVar_SetKeyPressActivationValue( this_ptr);
      AddVar_GetKeyPressActivationValue( this_ptr);
      AddVar_GetDefaultRenderer( this_ptr);
      AddVar_SetDefaultRenderer( this_ptr);
      AddVar_GetCurrentRenderer( this_ptr);
      AddVar_SetCurrentRenderer( this_ptr);
      AddVar_OnChar( this_ptr);
      AddVar_GrabFocus( this_ptr);
      AddVar_ReleaseFocus( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkInteractorObserver::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkInteractorObserver::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkInteractorObserver * vtkInteractorObserver::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkInteractorObserver";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkInteractorObserver * res =   vtkInteractorObserver::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkInteractorObserver::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::ComputeDisplayToWorld(vtkRenderer * ren, double x, double y, double z, double * worldPt)
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_ComputeDisplayToWorld::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'ren'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'worldPt'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_ComputeDisplayToWorld::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderer > ren_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(ren_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkRenderer* ren = ren_smtptr.get();

  double x;
  if (!get_val_param<double >(x,_p,_n,true,false)) ClassHelpAndReturn;

  double y;
  if (!get_val_param<double >(y,_p,_n,true,false)) ClassHelpAndReturn;

  double z;
  if (!get_val_param<double >(z,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<double > worldPt_smtptr;
  if (!get_val_smtptr_param<double >(worldPt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* worldPt = worldPt_smtptr.get();

  vtkInteractorObserver::ComputeDisplayToWorld(ren, x, y, z, worldPt);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::ComputeWorldToDisplay(vtkRenderer * ren, double x, double y, double z, double * displayPt)
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_ComputeWorldToDisplay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'ren'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'displayPt'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_ComputeWorldToDisplay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderer > ren_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(ren_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkRenderer* ren = ren_smtptr.get();

  double x;
  if (!get_val_param<double >(x,_p,_n,true,false)) ClassHelpAndReturn;

  double y;
  if (!get_val_param<double >(y,_p,_n,true,false)) ClassHelpAndReturn;

  double z;
  if (!get_val_param<double >(z,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<double > displayPt_smtptr;
  if (!get_val_smtptr_param<double >(displayPt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* displayPt = displayPt_smtptr.get();

  vtkInteractorObserver::ComputeWorldToDisplay(ren, x, y, z, displayPt);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorObserver::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
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
//  Wrapping of vtkInteractorObserver * vtkInteractorObserver::NewInstance()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkInteractorObserver";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInteractorObserver * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkInteractorObserver::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
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
//  Wrapping of void vtkInteractorObserver::SetEnabled(int param0)
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_SetEnabled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_SetEnabled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetEnabled(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorObserver::GetEnabled()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_GetEnabled::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_GetEnabled::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetEnabled();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::EnabledOn()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_EnabledOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_EnabledOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EnabledOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::EnabledOff()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_EnabledOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_EnabledOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EnabledOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::On()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_On::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_On::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->On();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::Off()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_Off::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_Off::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Off();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::SetInteractor(vtkRenderWindowInteractor * iren)
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_SetInteractor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderWindowInteractor, "parameter named 'iren'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_SetInteractor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderWindowInteractor > iren_smtptr;
  if (!get_val_smtptr_param<vtkRenderWindowInteractor >(iren_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkRenderWindowInteractor* iren = iren_smtptr.get();

  this->_objectptr->GetObj()->SetInteractor(iren);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkRenderWindowInteractor * vtkInteractorObserver::GetInteractor()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_GetInteractor::SetParametersComments()
{
  return_comments="returning a variable of type vtkRenderWindowInteractor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_GetInteractor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRenderWindowInteractor * res =   this->_objectptr->GetObj()->GetInteractor();
  BasicVariable::ptr res_var = WrapClass_vtkRenderWindowInteractor::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::SetPriority(float _arg)
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_SetPriority::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_SetPriority::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!get_val_param<float >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetPriority(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkInteractorObserver::GetPriorityMinValue()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_GetPriorityMinValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_GetPriorityMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetPriorityMinValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkInteractorObserver::GetPriorityMaxValue()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_GetPriorityMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_GetPriorityMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetPriorityMaxValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkInteractorObserver::GetPriority()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_GetPriority::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_GetPriority::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetPriority();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::SetKeyPressActivation(int _arg)
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_SetKeyPressActivation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_SetKeyPressActivation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetKeyPressActivation(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorObserver::GetKeyPressActivation()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_GetKeyPressActivation::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_GetKeyPressActivation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetKeyPressActivation();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::KeyPressActivationOn()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_KeyPressActivationOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_KeyPressActivationOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->KeyPressActivationOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::KeyPressActivationOff()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_KeyPressActivationOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_KeyPressActivationOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->KeyPressActivationOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::SetKeyPressActivationValue(char _arg)
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_SetKeyPressActivationValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_SetKeyPressActivationValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  std::string _arg_string;
  if (!get_val_param<std::string >(_arg_string,_p,_n,true,false)) ClassHelpAndReturn;
  char _arg = ' ';
if (_arg_string.size()>0) _arg = _arg_string[0];

  this->_objectptr->GetObj()->SetKeyPressActivationValue(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char vtkInteractorObserver::GetKeyPressActivationValue()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_GetKeyPressActivationValue::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_GetKeyPressActivationValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char res =   this->_objectptr->GetObj()->GetKeyPressActivationValue();
  std::string res_string = std::string(1,res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of vtkRenderer * vtkInteractorObserver::GetDefaultRenderer()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_GetDefaultRenderer::SetParametersComments()
{
  return_comments="returning a variable of type vtkRenderer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_GetDefaultRenderer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRenderer * res =   this->_objectptr->GetObj()->GetDefaultRenderer();
  BasicVariable::ptr res_var = WrapClass_vtkRenderer::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::SetDefaultRenderer(vtkRenderer * param0)
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_SetDefaultRenderer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_SetDefaultRenderer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderer > param0_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkRenderer* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetDefaultRenderer(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkRenderer * vtkInteractorObserver::GetCurrentRenderer()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_GetCurrentRenderer::SetParametersComments()
{
  return_comments="returning a variable of type vtkRenderer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_GetCurrentRenderer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRenderer * res =   this->_objectptr->GetObj()->GetCurrentRenderer();
  BasicVariable::ptr res_var = WrapClass_vtkRenderer::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::SetCurrentRenderer(vtkRenderer * param0)
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_SetCurrentRenderer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_SetCurrentRenderer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderer > param0_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkRenderer* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetCurrentRenderer(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::OnChar()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_OnChar::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_OnChar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnChar();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::GrabFocus(vtkCommand * mouseEvents, vtkCommand * keypressEvents = 0l)
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_GrabFocus::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkCommand, "parameter named 'mouseEvents'")
  ADDPARAMCOMMENT_TYPE( vtkCommand, "parameter named 'keypressEvents' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_GrabFocus::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkCommand > mouseEvents_smtptr;
  if (!get_val_smtptr_param<vtkCommand >(mouseEvents_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkCommand* mouseEvents = mouseEvents_smtptr.get();

  boost::shared_ptr<vtkCommand > keypressEvents_smtptr;
  if (!get_val_smtptr_param<vtkCommand >(keypressEvents_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkCommand* keypressEvents = keypressEvents_smtptr.get();

  this->_objectptr->GetObj()->GrabFocus(mouseEvents, keypressEvents);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorObserver::ReleaseFocus()
//---------------------------------------------------
void WrapClass_vtkInteractorObserver::
    wrap_ReleaseFocus::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorObserver::
    wrap_ReleaseFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ReleaseFocus();
  return BasicVariable::ptr();
}

