/**
 * C++ Interface: wrap_vtkInteractorStyle
 *
 * Description: wrapping vtkInteractorStyle
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
#include "wrap_vtkInteractorStyle.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkRenderWindowInteractor.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_vtkProp.h"
#include "wrap_vtkProp3D.h"


#include "wrap_vtkInteractorStyle.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkInteractorStyle>::CreateVar( ParamList* p)
{
  WrapClass_vtkInteractorStyle::wrap_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkInteractorStyle);
AMI_DEFINE_VARFROMSMTPTR(vtkInteractorStyle);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkInteractorStyle>::CreateVar( vtkInteractorStyle* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkInteractorStyle> obj_ptr(val,smartpointer_nodeleter<vtkInteractorStyle>());
  return AMILabType<vtkInteractorStyle>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkInteractorStyle
//
Variable<AMIObject>::ptr WrapClass_vtkInteractorStyle::CreateVar( vtkInteractorStyle* sp)
{
  boost::shared_ptr<vtkInteractorStyle> di_ptr(
    sp,
    wxwindow_nodeleter<vtkInteractorStyle>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkInteractorStyle>::CreateVar(
      new WrapClass_vtkInteractorStyle(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkInteractorStyle::AddMethods(WrapClass<vtkInteractorStyle>::ptr this_ptr )
{
  
      // Add members from vtkInteractorObserver
      WrapClass_vtkInteractorObserver::ptr parent_vtkInteractorObserver(        boost::dynamic_pointer_cast<WrapClass_vtkInteractorObserver >(this_ptr));
      parent_vtkInteractorObserver->AddMethods(parent_vtkInteractorObserver);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_SetInteractor( this_ptr);
      AddVar_SetEnabled( this_ptr);
      AddVar_SetAutoAdjustCameraClippingRange( this_ptr);
      AddVar_GetAutoAdjustCameraClippingRangeMinValue( this_ptr);
      AddVar_GetAutoAdjustCameraClippingRangeMaxValue( this_ptr);
      AddVar_GetAutoAdjustCameraClippingRange( this_ptr);
      AddVar_AutoAdjustCameraClippingRangeOn( this_ptr);
      AddVar_AutoAdjustCameraClippingRangeOff( this_ptr);
      AddVar_FindPokedRenderer( this_ptr);
      AddVar_GetState( this_ptr);
      AddVar_GetUseTimers( this_ptr);
      AddVar_SetUseTimers( this_ptr);
      AddVar_UseTimersOn( this_ptr);
      AddVar_UseTimersOff( this_ptr);
      AddVar_SetTimerDuration( this_ptr);
      AddVar_GetTimerDurationMinValue( this_ptr);
      AddVar_GetTimerDurationMaxValue( this_ptr);
      AddVar_GetTimerDuration( this_ptr);
      AddVar_SetHandleObservers( this_ptr);
      AddVar_GetHandleObservers( this_ptr);
      AddVar_HandleObserversOn( this_ptr);
      AddVar_HandleObserversOff( this_ptr);
      AddVar_OnMouseMove( this_ptr);
      AddVar_OnLeftButtonDown( this_ptr);
      AddVar_OnLeftButtonUp( this_ptr);
      AddVar_OnMiddleButtonDown( this_ptr);
      AddVar_OnMiddleButtonUp( this_ptr);
      AddVar_OnRightButtonDown( this_ptr);
      AddVar_OnRightButtonUp( this_ptr);
      AddVar_OnMouseWheelForward( this_ptr);
      AddVar_OnMouseWheelBackward( this_ptr);
      AddVar_OnChar( this_ptr);
      AddVar_OnKeyDown( this_ptr);
      AddVar_OnKeyUp( this_ptr);
      AddVar_OnKeyPress( this_ptr);
      AddVar_OnKeyRelease( this_ptr);
      AddVar_OnExpose( this_ptr);
      AddVar_OnConfigure( this_ptr);
      AddVar_OnEnter( this_ptr);
      AddVar_OnLeave( this_ptr);
      AddVar_OnTimer( this_ptr);
      AddVar_Rotate( this_ptr);
      AddVar_Spin( this_ptr);
      AddVar_Pan( this_ptr);
      AddVar_Dolly( this_ptr);
      AddVar_Zoom( this_ptr);
      AddVar_UniformScale( this_ptr);
      AddVar_StartState( this_ptr);
      AddVar_StopState( this_ptr);
      AddVar_StartAnimate( this_ptr);
      AddVar_StopAnimate( this_ptr);
      AddVar_StartRotate( this_ptr);
      AddVar_EndRotate( this_ptr);
      AddVar_StartZoom( this_ptr);
      AddVar_EndZoom( this_ptr);
      AddVar_StartPan( this_ptr);
      AddVar_EndPan( this_ptr);
      AddVar_StartSpin( this_ptr);
      AddVar_EndSpin( this_ptr);
      AddVar_StartDolly( this_ptr);
      AddVar_EndDolly( this_ptr);
      AddVar_StartUniformScale( this_ptr);
      AddVar_EndUniformScale( this_ptr);
      AddVar_StartTimer( this_ptr);
      AddVar_EndTimer( this_ptr);
      AddVar_HighlightProp( this_ptr);
/* The following types are missing: vtkActor2D
      AddVar_HighlightActor2D( this_ptr);
*/
      AddVar_HighlightProp3D( this_ptr);
      AddVar_SetPickColor_1( this_ptr);
      AddVar_SetPickColor( this_ptr);
      AddVar_SetPickColor_2( this_ptr);
      AddVar_GetPickColor_1( this_ptr);
      AddVar_GetPickColor( this_ptr);
      AddVar_GetPickColor_2( this_ptr);
      AddVar_SetMouseWheelMotionFactor( this_ptr);
      AddVar_GetMouseWheelMotionFactor( this_ptr);
/* The following types are missing: vtkTDxInteractorStyle
      AddVar_GetTDxStyle( this_ptr);
*/
/* The following types are missing: vtkTDxInteractorStyle
      AddVar_SetTDxStyle( this_ptr);
*/
/* The following types are missing: void
      AddVar_DelegateTDxEvent( this_ptr);
*/



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkInteractorStyle * vtkInteractorStyle::New()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkInteractorStyle";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInteractorStyle * res =   vtkInteractorStyle::New();
  BasicVariable::ptr res_var = WrapClass_vtkInteractorStyle::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyle::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkInteractorStyle::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkInteractorStyle * vtkInteractorStyle::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkInteractorStyle";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkInteractorStyle * res =   vtkInteractorStyle::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkInteractorStyle::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyle::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
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
//  Wrapping of vtkInteractorStyle * vtkInteractorStyle::NewInstance()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkInteractorStyle";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInteractorStyle * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkInteractorStyle::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
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
//  Wrapping of void vtkInteractorStyle::SetInteractor(vtkRenderWindowInteractor * interactor)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_SetInteractor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderWindowInteractor, "parameter named 'interactor'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_SetInteractor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderWindowInteractor > interactor_smtptr;
  if (!get_val_smtptr_param<vtkRenderWindowInteractor >(interactor_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkRenderWindowInteractor* interactor = interactor_smtptr.get();

  this->_objectptr->GetObj()->SetInteractor(interactor);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::SetEnabled(int param0)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_SetEnabled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_SetEnabled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetEnabled(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::SetAutoAdjustCameraClippingRange(int _arg)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_SetAutoAdjustCameraClippingRange::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_SetAutoAdjustCameraClippingRange::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAutoAdjustCameraClippingRange(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyle::GetAutoAdjustCameraClippingRangeMinValue()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_GetAutoAdjustCameraClippingRangeMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_GetAutoAdjustCameraClippingRangeMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAutoAdjustCameraClippingRangeMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyle::GetAutoAdjustCameraClippingRangeMaxValue()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_GetAutoAdjustCameraClippingRangeMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_GetAutoAdjustCameraClippingRangeMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAutoAdjustCameraClippingRangeMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyle::GetAutoAdjustCameraClippingRange()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_GetAutoAdjustCameraClippingRange::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_GetAutoAdjustCameraClippingRange::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAutoAdjustCameraClippingRange();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::AutoAdjustCameraClippingRangeOn()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_AutoAdjustCameraClippingRangeOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_AutoAdjustCameraClippingRangeOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AutoAdjustCameraClippingRangeOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::AutoAdjustCameraClippingRangeOff()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_AutoAdjustCameraClippingRangeOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_AutoAdjustCameraClippingRangeOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AutoAdjustCameraClippingRangeOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::FindPokedRenderer(int param0, int param1)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_FindPokedRenderer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_FindPokedRenderer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n)) ClassHelpAndReturn;

  int param1;
  if (!get_val_param<int >(param1,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->FindPokedRenderer(param0, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyle::GetState()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_GetState::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_GetState::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetState();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyle::GetUseTimers()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_GetUseTimers::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_GetUseTimers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetUseTimers();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::SetUseTimers(int _arg)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_SetUseTimers::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_SetUseTimers::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetUseTimers(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::UseTimersOn()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_UseTimersOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_UseTimersOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UseTimersOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::UseTimersOff()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_UseTimersOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_UseTimersOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UseTimersOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::SetTimerDuration(long unsigned int _arg)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_SetTimerDuration::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_SetTimerDuration::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long _arg_long;
  if (!get_val_param<long >(_arg_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int _arg = boost::numeric_cast<long unsigned int >(_arg_long);

  this->_objectptr->GetObj()->SetTimerDuration(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkInteractorStyle::GetTimerDurationMinValue()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_GetTimerDurationMinValue::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_GetTimerDurationMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetTimerDurationMinValue();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkInteractorStyle::GetTimerDurationMaxValue()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_GetTimerDurationMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_GetTimerDurationMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetTimerDurationMaxValue();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkInteractorStyle::GetTimerDuration()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_GetTimerDuration::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_GetTimerDuration::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetTimerDuration();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::SetHandleObservers(int _arg)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_SetHandleObservers::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_SetHandleObservers::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetHandleObservers(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyle::GetHandleObservers()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_GetHandleObservers::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_GetHandleObservers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetHandleObservers();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::HandleObserversOn()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_HandleObserversOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_HandleObserversOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->HandleObserversOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::HandleObserversOff()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_HandleObserversOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_HandleObserversOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->HandleObserversOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnMouseMove()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnMouseMove::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnMouseMove::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnMouseMove();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnLeftButtonDown()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnLeftButtonDown::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnLeftButtonDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnLeftButtonDown();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnLeftButtonUp()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnLeftButtonUp::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnLeftButtonUp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnLeftButtonUp();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnMiddleButtonDown()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnMiddleButtonDown::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnMiddleButtonDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnMiddleButtonDown();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnMiddleButtonUp()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnMiddleButtonUp::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnMiddleButtonUp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnMiddleButtonUp();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnRightButtonDown()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnRightButtonDown::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnRightButtonDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnRightButtonDown();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnRightButtonUp()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnRightButtonUp::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnRightButtonUp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnRightButtonUp();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnMouseWheelForward()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnMouseWheelForward::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnMouseWheelForward::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnMouseWheelForward();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnMouseWheelBackward()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnMouseWheelBackward::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnMouseWheelBackward::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnMouseWheelBackward();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnChar()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnChar::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnChar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnChar();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnKeyDown()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnKeyDown::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnKeyDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnKeyDown();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnKeyUp()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnKeyUp::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnKeyUp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnKeyUp();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnKeyPress()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnKeyPress::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnKeyPress::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnKeyPress();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnKeyRelease()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnKeyRelease::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnKeyRelease::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnKeyRelease();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnExpose()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnExpose::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnExpose::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnExpose();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnConfigure()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnConfigure::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnConfigure::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnConfigure();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnEnter()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnEnter::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnEnter::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnEnter();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnLeave()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnLeave::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnLeave::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnLeave();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::OnTimer()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_OnTimer::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_OnTimer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnTimer();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::Rotate()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_Rotate::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_Rotate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Rotate();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::Spin()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_Spin::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_Spin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Spin();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::Pan()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_Pan::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_Pan::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Pan();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::Dolly()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_Dolly::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_Dolly::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Dolly();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::Zoom()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_Zoom::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_Zoom::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Zoom();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::UniformScale()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_UniformScale::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_UniformScale::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UniformScale();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::StartState(int newstate)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_StartState::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'newstate'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_StartState::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int newstate;
  if (!get_val_param<int >(newstate,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StartState(newstate);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::StopState()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_StopState::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_StopState::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StopState();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::StartAnimate()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_StartAnimate::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_StartAnimate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StartAnimate();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::StopAnimate()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_StopAnimate::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_StopAnimate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StopAnimate();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::StartRotate()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_StartRotate::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_StartRotate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StartRotate();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::EndRotate()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_EndRotate::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_EndRotate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EndRotate();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::StartZoom()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_StartZoom::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_StartZoom::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StartZoom();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::EndZoom()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_EndZoom::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_EndZoom::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EndZoom();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::StartPan()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_StartPan::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_StartPan::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StartPan();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::EndPan()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_EndPan::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_EndPan::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EndPan();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::StartSpin()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_StartSpin::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_StartSpin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StartSpin();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::EndSpin()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_EndSpin::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_EndSpin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EndSpin();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::StartDolly()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_StartDolly::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_StartDolly::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StartDolly();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::EndDolly()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_EndDolly::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_EndDolly::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EndDolly();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::StartUniformScale()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_StartUniformScale::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_StartUniformScale::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StartUniformScale();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::EndUniformScale()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_EndUniformScale::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_EndUniformScale::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EndUniformScale();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::StartTimer()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_StartTimer::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_StartTimer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StartTimer();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::EndTimer()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_EndTimer::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_EndTimer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EndTimer();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::HighlightProp(vtkProp * prop)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_HighlightProp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'prop'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_HighlightProp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkProp > prop_smtptr;
  if (!get_val_smtptr_param<vtkProp >(prop_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkProp* prop = prop_smtptr.get();

  this->_objectptr->GetObj()->HighlightProp(prop);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkActor2D

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::HighlightActor2D(vtkActor2D * actor2D)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_HighlightActor2D::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkActor2D, "parameter named 'actor2D'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_HighlightActor2D::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkActor2D > actor2D_smtptr;
  if (!get_val_smtptr_param<vtkActor2D >(actor2D_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkActor2D* actor2D = actor2D_smtptr.get();

  this->_objectptr->GetObj()->HighlightActor2D(actor2D);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::HighlightProp3D(vtkProp3D * prop3D)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_HighlightProp3D::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp3D, "parameter named 'prop3D'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_HighlightProp3D::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkProp3D > prop3D_smtptr;
  if (!get_val_smtptr_param<vtkProp3D >(prop3D_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkProp3D* prop3D = prop3D_smtptr.get();

  this->_objectptr->GetObj()->HighlightProp3D(prop3D);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::SetPickColor(double _arg1, double _arg2, double _arg3)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_SetPickColor_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_SetPickColor_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  double _arg1;
  if (!get_val_param<double >(_arg1,_p,_n)) ClassReturnEmptyVar;

  double _arg2;
  if (!get_val_param<double >(_arg2,_p,_n)) ClassReturnEmptyVar;

  double _arg3;
  if (!get_val_param<double >(_arg3,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetPickColor(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkInteractorStyle::SetPickColor(...)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_SetPickColor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_SetPickColor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkInteractorStyle::wrap_SetPickColor_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkInteractorStyle::wrap_SetPickColor_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::SetPickColor(double * _arg)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_SetPickColor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_SetPickColor_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetPickColor(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkInteractorStyle::GetPickColor()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_GetPickColor_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_GetPickColor_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetPickColor();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkInteractorStyle::GetPickColor(...)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_GetPickColor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_GetPickColor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkInteractorStyle::wrap_GetPickColor_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkInteractorStyle::wrap_GetPickColor_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::GetPickColor(double * data)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_GetPickColor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_GetPickColor_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > data_smtptr;
  if (!get_val_smtptr_param<double >(data_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* data = data_smtptr.get();

  this->_objectptr->GetObj()->GetPickColor(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::SetMouseWheelMotionFactor(double _arg)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_SetMouseWheelMotionFactor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_SetMouseWheelMotionFactor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMouseWheelMotionFactor(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkInteractorStyle::GetMouseWheelMotionFactor()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_GetMouseWheelMotionFactor::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_GetMouseWheelMotionFactor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetMouseWheelMotionFactor();
  return AMILabType<double >::CreateVar(res);
}
/* The following types are missing: vtkTDxInteractorStyle

//---------------------------------------------------
//  Wrapping of vtkTDxInteractorStyle * vtkInteractorStyle::GetTDxStyle()
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_GetTDxStyle::SetParametersComments()
{
  return_comments="returning a variable of type vtkTDxInteractorStyle";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_GetTDxStyle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkTDxInteractorStyle * res =   this->_objectptr->GetObj()->GetTDxStyle();
  return AMILabType<vtkTDxInteractorStyle >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkTDxInteractorStyle

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::SetTDxStyle(vtkTDxInteractorStyle * tdxStyle)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_SetTDxStyle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkTDxInteractorStyle, "parameter named 'tdxStyle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_SetTDxStyle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkTDxInteractorStyle > tdxStyle_smtptr;
  if (!get_val_smtptr_param<vtkTDxInteractorStyle >(tdxStyle_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkTDxInteractorStyle* tdxStyle = tdxStyle_smtptr.get();

  this->_objectptr->GetObj()->SetTDxStyle(tdxStyle);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyle::DelegateTDxEvent(long unsigned int event, void * calldata)
//---------------------------------------------------
void WrapClass_vtkInteractorStyle::
    wrap_DelegateTDxEvent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'event'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'calldata'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyle::
    wrap_DelegateTDxEvent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long event_long;
  if (!get_val_param<long >(event_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int event = boost::numeric_cast<long unsigned int >(event_long);

  boost::shared_ptr<void > calldata_smtptr;
  if (!get_val_smtptr_param<void >(calldata_smtptr,_p,_n)) ClassHelpAndReturn;
  void* calldata = calldata_smtptr.get();

  this->_objectptr->GetObj()->DelegateTDxEvent(event, calldata);
  return BasicVariable::ptr();
}
*/

