/**
 * C++ Interface: wrap_vtkRenderWindowInteractor
 *
 * Description: wrapping vtkRenderWindowInteractor
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
#include "wrap_vtkRenderWindowInteractor.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkRenderWindow.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_vtkInteractorObserver.h"
#include "wrap_vtkRenderer.h"


#include "wrap_vtkRenderWindowInteractor.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkRenderWindowInteractor>::CreateVar( ParamList* p)
{
  WrapClass_vtkRenderWindowInteractor::wrap_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkRenderWindowInteractor);
AMI_DEFINE_VARFROMSMTPTR(vtkRenderWindowInteractor);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkRenderWindowInteractor>::CreateVar( vtkRenderWindowInteractor* val)
{ 
  boost::shared_ptr<vtkRenderWindowInteractor> obj_ptr(val,wxwindow_nodeleter<vtkRenderWindowInteractor>());
  return AMILabType<vtkRenderWindowInteractor>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkRenderWindowInteractor
//
Variable<AMIObject>::ptr WrapClass_vtkRenderWindowInteractor::CreateVar( vtkRenderWindowInteractor* sp)
{
  boost::shared_ptr<vtkRenderWindowInteractor> di_ptr(
    sp,
    wxwindow_nodeleter<vtkRenderWindowInteractor>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkRenderWindowInteractor>::CreateVar(
      new WrapClass_vtkRenderWindowInteractor(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::AddMethods(WrapClass<vtkRenderWindowInteractor>::ptr this_ptr )
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
      AddVar_Initialize( this_ptr);
      AddVar_ReInitialize( this_ptr);
      AddVar_UnRegister( this_ptr);
      AddVar_Start( this_ptr);
      AddVar_Enable( this_ptr);
      AddVar_Disable( this_ptr);
      AddVar_GetEnabled( this_ptr);
      AddVar_EnableRenderOn( this_ptr);
      AddVar_EnableRenderOff( this_ptr);
      AddVar_SetEnableRender( this_ptr);
      AddVar_GetEnableRender( this_ptr);
      AddVar_SetRenderWindow( this_ptr);
      AddVar_GetRenderWindow( this_ptr);
      AddVar_UpdateSize( this_ptr);
      AddVar_CreateTimer( this_ptr);
      AddVar_DestroyTimer_1( this_ptr);
      AddVar_CreateRepeatingTimer( this_ptr);
      AddVar_CreateOneShotTimer( this_ptr);
      AddVar_IsOneShotTimer( this_ptr);
      AddVar_GetTimerDuration_1( this_ptr);
      AddVar_ResetTimer( this_ptr);
      AddVar_DestroyTimer( this_ptr);
      AddVar_DestroyTimer_2( this_ptr);
      AddVar_GetVTKTimerId( this_ptr);
      AddVar_SetTimerDuration( this_ptr);
      AddVar_GetTimerDurationMinValue( this_ptr);
      AddVar_GetTimerDurationMaxValue( this_ptr);
      AddVar_GetTimerDuration( this_ptr);
      AddVar_GetTimerDuration_2( this_ptr);
      AddVar_SetTimerEventId( this_ptr);
      AddVar_GetTimerEventId( this_ptr);
      AddVar_SetTimerEventType( this_ptr);
      AddVar_GetTimerEventType( this_ptr);
      AddVar_SetTimerEventDuration( this_ptr);
      AddVar_GetTimerEventDuration( this_ptr);
      AddVar_SetTimerEventPlatformId( this_ptr);
      AddVar_GetTimerEventPlatformId( this_ptr);
      AddVar_TerminateApp( this_ptr);
      AddVar_SetInteractorStyle( this_ptr);
      AddVar_GetInteractorStyle( this_ptr);
      AddVar_SetLightFollowCamera( this_ptr);
      AddVar_GetLightFollowCamera( this_ptr);
      AddVar_LightFollowCameraOn( this_ptr);
      AddVar_LightFollowCameraOff( this_ptr);
      AddVar_SetDesiredUpdateRate( this_ptr);
      AddVar_GetDesiredUpdateRateMinValue( this_ptr);
      AddVar_GetDesiredUpdateRateMaxValue( this_ptr);
      AddVar_GetDesiredUpdateRate( this_ptr);
      AddVar_SetStillUpdateRate( this_ptr);
      AddVar_GetStillUpdateRateMinValue( this_ptr);
      AddVar_GetStillUpdateRateMaxValue( this_ptr);
      AddVar_GetStillUpdateRate( this_ptr);
      AddVar_GetInitialized( this_ptr);
/* The following types are missing: vtkAbstractPicker
      AddVar_SetPicker( this_ptr);
*/
/* The following types are missing: vtkAbstractPicker
      AddVar_GetPicker( this_ptr);
*/
/* The following types are missing: vtkAbstractPropPicker
      AddVar_CreateDefaultPicker( this_ptr);
*/
      AddVar_ExitCallback( this_ptr);
      AddVar_UserCallback( this_ptr);
      AddVar_StartPickCallback( this_ptr);
      AddVar_EndPickCallback( this_ptr);
      AddVar_GetMousePosition( this_ptr);
      AddVar_HideCursor( this_ptr);
      AddVar_ShowCursor( this_ptr);
      AddVar_Render( this_ptr);
      AddVar_FlyTo_1( this_ptr);
      AddVar_FlyTo( this_ptr);
      AddVar_FlyTo_2( this_ptr);
      AddVar_FlyToImage_1( this_ptr);
      AddVar_FlyToImage( this_ptr);
      AddVar_FlyToImage_2( this_ptr);
      AddVar_SetNumberOfFlyFrames( this_ptr);
      AddVar_GetNumberOfFlyFramesMinValue( this_ptr);
      AddVar_GetNumberOfFlyFramesMaxValue( this_ptr);
      AddVar_GetNumberOfFlyFrames( this_ptr);
      AddVar_SetDolly( this_ptr);
      AddVar_GetDolly( this_ptr);
      AddVar_GetEventPosition_1( this_ptr);
      AddVar_GetEventPosition( this_ptr);
      AddVar_GetEventPosition_2( this_ptr);
      AddVar_GetEventPosition_3( this_ptr);
      AddVar_GetLastEventPosition_1( this_ptr);
      AddVar_GetLastEventPosition( this_ptr);
      AddVar_GetLastEventPosition_2( this_ptr);
      AddVar_GetLastEventPosition_3( this_ptr);
      AddVar_SetLastEventPosition_1( this_ptr);
      AddVar_SetLastEventPosition( this_ptr);
      AddVar_SetLastEventPosition_2( this_ptr);
      AddVar_SetEventPosition_1( this_ptr);
      AddVar_SetEventPosition( this_ptr);
      AddVar_SetEventPosition_2( this_ptr);
      AddVar_SetEventPositionFlipY_1( this_ptr);
      AddVar_SetEventPositionFlipY( this_ptr);
      AddVar_SetEventPositionFlipY_2( this_ptr);
      AddVar_SetAltKey( this_ptr);
      AddVar_GetAltKey( this_ptr);
      AddVar_SetControlKey( this_ptr);
      AddVar_GetControlKey( this_ptr);
      AddVar_SetShiftKey( this_ptr);
      AddVar_GetShiftKey( this_ptr);
      AddVar_SetKeyCode( this_ptr);
      AddVar_GetKeyCode( this_ptr);
      AddVar_SetRepeatCount( this_ptr);
      AddVar_GetRepeatCount( this_ptr);
      AddVar_SetKeySym( this_ptr);
      AddVar_GetKeySym( this_ptr);
      AddVar_SetEventInformation( this_ptr);
      AddVar_SetEventInformationFlipY( this_ptr);
      AddVar_SetKeyEventInformation( this_ptr);
      AddVar_SetSize_1( this_ptr);
      AddVar_SetSize( this_ptr);
      AddVar_SetSize_2( this_ptr);
      AddVar_GetSize_1( this_ptr);
      AddVar_GetSize( this_ptr);
      AddVar_GetSize_2( this_ptr);
      AddVar_GetSize_3( this_ptr);
      AddVar_SetEventSize_1( this_ptr);
      AddVar_SetEventSize( this_ptr);
      AddVar_SetEventSize_2( this_ptr);
      AddVar_GetEventSize_1( this_ptr);
      AddVar_GetEventSize( this_ptr);
      AddVar_GetEventSize_2( this_ptr);
      AddVar_GetEventSize_3( this_ptr);
      AddVar_FindPokedRenderer( this_ptr);
/* The following types are missing: vtkObserverMediator
      AddVar_GetObserverMediator( this_ptr);
*/
      AddVar_SetUseTDx( this_ptr);
      AddVar_GetUseTDx( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkRenderWindowInteractor * vtkRenderWindowInteractor::New()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkRenderWindowInteractor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRenderWindowInteractor * res =   vtkRenderWindowInteractor::New();
  BasicVariable::ptr res_var = WrapClass_vtkRenderWindowInteractor::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkRenderWindowInteractor::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkRenderWindowInteractor * vtkRenderWindowInteractor::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkRenderWindowInteractor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkRenderWindowInteractor * res =   vtkRenderWindowInteractor::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkRenderWindowInteractor::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
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
//  Wrapping of vtkRenderWindowInteractor * vtkRenderWindowInteractor::NewInstance()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkRenderWindowInteractor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRenderWindowInteractor * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkRenderWindowInteractor::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
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
//  Wrapping of void vtkRenderWindowInteractor::Initialize()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_Initialize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_Initialize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Initialize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::ReInitialize()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_ReInitialize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_ReInitialize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ReInitialize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::UnRegister(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_UnRegister::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_UnRegister::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  this->_objectptr->GetObj()->UnRegister(o);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::Start()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_Start::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_Start::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Start();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::Enable()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_Enable::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_Enable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Enable();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::Disable()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_Disable::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_Disable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Disable();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::GetEnabled()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetEnabled::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetEnabled::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetEnabled();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::EnableRenderOn()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_EnableRenderOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_EnableRenderOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EnableRenderOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::EnableRenderOff()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_EnableRenderOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_EnableRenderOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EnableRenderOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetEnableRender(bool _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetEnableRender::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetEnableRender::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg_int;
  if (!get_val_param<int >(_arg_int,_p,_n)) ClassHelpAndReturn;
  bool _arg = (bool) (_arg_int>0.5);

  this->_objectptr->GetObj()->SetEnableRender(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool vtkRenderWindowInteractor::GetEnableRender()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetEnableRender::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetEnableRender::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetEnableRender();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetRenderWindow(vtkRenderWindow * aren)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetRenderWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderWindow, "parameter named 'aren'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetRenderWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderWindow > aren_smtptr;
  if (!get_val_smtptr_param<vtkRenderWindow >(aren_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkRenderWindow* aren = aren_smtptr.get();

  this->_objectptr->GetObj()->SetRenderWindow(aren);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkRenderWindow * vtkRenderWindowInteractor::GetRenderWindow()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetRenderWindow::SetParametersComments()
{
  return_comments="returning a variable of type vtkRenderWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetRenderWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRenderWindow * res =   this->_objectptr->GetObj()->GetRenderWindow();
  BasicVariable::ptr res_var = WrapClass_vtkRenderWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::UpdateSize(int x, int y)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_UpdateSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_UpdateSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UpdateSize(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::CreateTimer(int timerType)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_CreateTimer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'timerType'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_CreateTimer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int timerType;
  if (!get_val_param<int >(timerType,_p,_n)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->CreateTimer(timerType);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::DestroyTimer()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_DestroyTimer_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_DestroyTimer_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->DestroyTimer();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::CreateRepeatingTimer(long unsigned int duration)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_CreateRepeatingTimer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'duration'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_CreateRepeatingTimer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long duration_long;
  if (!get_val_param<long >(duration_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int duration = boost::numeric_cast<long unsigned int >(duration_long);

  int res =   this->_objectptr->GetObj()->CreateRepeatingTimer(duration);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::CreateOneShotTimer(long unsigned int duration)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_CreateOneShotTimer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'duration'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_CreateOneShotTimer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long duration_long;
  if (!get_val_param<long >(duration_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int duration = boost::numeric_cast<long unsigned int >(duration_long);

  int res =   this->_objectptr->GetObj()->CreateOneShotTimer(duration);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::IsOneShotTimer(int timerId)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_IsOneShotTimer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'timerId'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_IsOneShotTimer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int timerId;
  if (!get_val_param<int >(timerId,_p,_n)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->IsOneShotTimer(timerId);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkRenderWindowInteractor::GetTimerDuration(int timerId)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerDuration_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'timerId'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerDuration_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int timerId;
  if (!get_val_param<int >(timerId,_p,_n)) ClassReturnEmptyVar;

  long unsigned int res =   this->_objectptr->GetObj()->GetTimerDuration(timerId);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::ResetTimer(int timerId)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_ResetTimer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'timerId'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_ResetTimer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int timerId;
  if (!get_val_param<int >(timerId,_p,_n)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->ResetTimer(timerId);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderWindowInteractor::DestroyTimer(...)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_DestroyTimer::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_DestroyTimer::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderWindowInteractor::wrap_DestroyTimer_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_DestroyTimer_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::DestroyTimer(int timerId)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_DestroyTimer_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'timerId'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_DestroyTimer_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int timerId;
  if (!get_val_param<int >(timerId,_p,_n)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->DestroyTimer(timerId);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::GetVTKTimerId(int platformTimerId)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetVTKTimerId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'platformTimerId'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetVTKTimerId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int platformTimerId;
  if (!get_val_param<int >(platformTimerId,_p,_n)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetVTKTimerId(platformTimerId);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetTimerDuration(long unsigned int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetTimerDuration::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
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
//  Wrapping of long unsigned int vtkRenderWindowInteractor::GetTimerDurationMinValue()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerDurationMinValue::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerDurationMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetTimerDurationMinValue();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkRenderWindowInteractor::GetTimerDurationMaxValue()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerDurationMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerDurationMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetTimerDurationMaxValue();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderWindowInteractor::GetTimerDuration(...)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerDuration::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerDuration::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderWindowInteractor::wrap_GetTimerDuration_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_GetTimerDuration_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkRenderWindowInteractor::GetTimerDuration()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerDuration_2::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerDuration_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  long unsigned int res =   this->_objectptr->GetObj()->GetTimerDuration();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetTimerEventId(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetTimerEventId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetTimerEventId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetTimerEventId(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::GetTimerEventId()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerEventId::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerEventId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetTimerEventId();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetTimerEventType(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetTimerEventType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetTimerEventType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetTimerEventType(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::GetTimerEventType()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerEventType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerEventType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetTimerEventType();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetTimerEventDuration(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetTimerEventDuration::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetTimerEventDuration::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetTimerEventDuration(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::GetTimerEventDuration()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerEventDuration::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerEventDuration::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetTimerEventDuration();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetTimerEventPlatformId(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetTimerEventPlatformId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetTimerEventPlatformId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetTimerEventPlatformId(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::GetTimerEventPlatformId()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerEventPlatformId::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetTimerEventPlatformId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetTimerEventPlatformId();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::TerminateApp()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_TerminateApp::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_TerminateApp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->TerminateApp();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetInteractorStyle(vtkInteractorObserver * param0)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetInteractorStyle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInteractorObserver, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetInteractorStyle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkInteractorObserver > param0_smtptr;
  if (!get_val_smtptr_param<vtkInteractorObserver >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkInteractorObserver* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetInteractorStyle(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkInteractorObserver * vtkRenderWindowInteractor::GetInteractorStyle()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetInteractorStyle::SetParametersComments()
{
  return_comments="returning a variable of type vtkInteractorObserver";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetInteractorStyle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInteractorObserver * res =   this->_objectptr->GetObj()->GetInteractorStyle();
  BasicVariable::ptr res_var = WrapClass_vtkInteractorObserver::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetLightFollowCamera(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetLightFollowCamera::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetLightFollowCamera::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetLightFollowCamera(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::GetLightFollowCamera()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetLightFollowCamera::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetLightFollowCamera::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetLightFollowCamera();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::LightFollowCameraOn()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_LightFollowCameraOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_LightFollowCameraOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->LightFollowCameraOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::LightFollowCameraOff()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_LightFollowCameraOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_LightFollowCameraOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->LightFollowCameraOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetDesiredUpdateRate(double _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetDesiredUpdateRate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetDesiredUpdateRate::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDesiredUpdateRate(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkRenderWindowInteractor::GetDesiredUpdateRateMinValue()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetDesiredUpdateRateMinValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetDesiredUpdateRateMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetDesiredUpdateRateMinValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkRenderWindowInteractor::GetDesiredUpdateRateMaxValue()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetDesiredUpdateRateMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetDesiredUpdateRateMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetDesiredUpdateRateMaxValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkRenderWindowInteractor::GetDesiredUpdateRate()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetDesiredUpdateRate::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetDesiredUpdateRate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetDesiredUpdateRate();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetStillUpdateRate(double _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetStillUpdateRate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetStillUpdateRate::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStillUpdateRate(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkRenderWindowInteractor::GetStillUpdateRateMinValue()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetStillUpdateRateMinValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetStillUpdateRateMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetStillUpdateRateMinValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkRenderWindowInteractor::GetStillUpdateRateMaxValue()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetStillUpdateRateMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetStillUpdateRateMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetStillUpdateRateMaxValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkRenderWindowInteractor::GetStillUpdateRate()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetStillUpdateRate::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetStillUpdateRate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetStillUpdateRate();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::GetInitialized()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetInitialized::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetInitialized::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetInitialized();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: vtkAbstractPicker

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetPicker(vtkAbstractPicker * param0)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetPicker::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAbstractPicker, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetPicker::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkAbstractPicker > param0_smtptr;
  if (!get_val_smtptr_param<vtkAbstractPicker >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkAbstractPicker* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetPicker(param0);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkAbstractPicker

//---------------------------------------------------
//  Wrapping of vtkAbstractPicker * vtkRenderWindowInteractor::GetPicker()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetPicker::SetParametersComments()
{
  return_comments="returning a variable of type vtkAbstractPicker";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetPicker::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAbstractPicker * res =   this->_objectptr->GetObj()->GetPicker();
  return AMILabType<vtkAbstractPicker >::CreateVar(res);
}
*/
/* The following types are missing: vtkAbstractPropPicker

//---------------------------------------------------
//  Wrapping of vtkAbstractPropPicker * vtkRenderWindowInteractor::CreateDefaultPicker()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_CreateDefaultPicker::SetParametersComments()
{
  return_comments="returning a variable of type vtkAbstractPropPicker";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_CreateDefaultPicker::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAbstractPropPicker * res =   this->_objectptr->GetObj()->CreateDefaultPicker();
  return AMILabType<vtkAbstractPropPicker >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::ExitCallback()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_ExitCallback::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_ExitCallback::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ExitCallback();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::UserCallback()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_UserCallback::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_UserCallback::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UserCallback();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::StartPickCallback()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_StartPickCallback::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_StartPickCallback::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StartPickCallback();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::EndPickCallback()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_EndPickCallback::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_EndPickCallback::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EndPickCallback();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::GetMousePosition(int * x, int * y)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetMousePosition::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetMousePosition::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > x_smtptr;
  if (!get_val_smtptr_param<int >(x_smtptr,_p,_n)) ClassHelpAndReturn;
  int* x = x_smtptr.get();

  boost::shared_ptr<int > y_smtptr;
  if (!get_val_smtptr_param<int >(y_smtptr,_p,_n)) ClassHelpAndReturn;
  int* y = y_smtptr.get();

  this->_objectptr->GetObj()->GetMousePosition(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::HideCursor()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_HideCursor::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_HideCursor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->HideCursor();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::ShowCursor()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_ShowCursor::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_ShowCursor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ShowCursor();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::Render()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_Render::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_Render::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Render();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::FlyTo(vtkRenderer * ren, double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_FlyTo_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'ren'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_FlyTo_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkRenderer > ren_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(ren_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkRenderer* ren = ren_smtptr.get();

  double x;
  if (!get_val_param<double >(x,_p,_n)) ClassReturnEmptyVar;

  double y;
  if (!get_val_param<double >(y,_p,_n)) ClassReturnEmptyVar;

  double z;
  if (!get_val_param<double >(z,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->FlyTo(ren, x, y, z);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderWindowInteractor::FlyTo(...)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_FlyTo::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_FlyTo::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderWindowInteractor::wrap_FlyTo_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_FlyTo_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::FlyTo(vtkRenderer * ren, double * x)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_FlyTo_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'ren'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_FlyTo_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkRenderer > ren_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(ren_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkRenderer* ren = ren_smtptr.get();

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* x = x_smtptr.get();

  this->_objectptr->GetObj()->FlyTo(ren, x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::FlyToImage(vtkRenderer * ren, double x, double y)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_FlyToImage_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'ren'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_FlyToImage_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkRenderer > ren_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(ren_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkRenderer* ren = ren_smtptr.get();

  double x;
  if (!get_val_param<double >(x,_p,_n)) ClassReturnEmptyVar;

  double y;
  if (!get_val_param<double >(y,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->FlyToImage(ren, x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderWindowInteractor::FlyToImage(...)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_FlyToImage::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_FlyToImage::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderWindowInteractor::wrap_FlyToImage_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_FlyToImage_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::FlyToImage(vtkRenderer * ren, double * x)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_FlyToImage_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'ren'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_FlyToImage_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkRenderer > ren_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(ren_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkRenderer* ren = ren_smtptr.get();

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* x = x_smtptr.get();

  this->_objectptr->GetObj()->FlyToImage(ren, x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetNumberOfFlyFrames(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetNumberOfFlyFrames::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetNumberOfFlyFrames::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetNumberOfFlyFrames(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::GetNumberOfFlyFramesMinValue()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetNumberOfFlyFramesMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetNumberOfFlyFramesMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfFlyFramesMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::GetNumberOfFlyFramesMaxValue()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetNumberOfFlyFramesMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetNumberOfFlyFramesMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfFlyFramesMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::GetNumberOfFlyFrames()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetNumberOfFlyFrames::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetNumberOfFlyFrames::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfFlyFrames();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetDolly(double _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetDolly::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetDolly::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDolly(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkRenderWindowInteractor::GetDolly()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetDolly::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetDolly::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetDolly();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int * vtkRenderWindowInteractor::GetEventPosition()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetEventPosition_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetEventPosition_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int * res =   this->_objectptr->GetObj()->GetEventPosition();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderWindowInteractor::GetEventPosition(...)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetEventPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetEventPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderWindowInteractor::wrap_GetEventPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_GetEventPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_GetEventPosition_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::GetEventPosition(int & _arg1, int & _arg2)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetEventPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetEventPosition_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg1_smtptr;
  if (!get_val_smtptr_param<int >(_arg1_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<int > _arg2_smtptr;
  if (!get_val_smtptr_param<int >(_arg2_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & _arg2 = *_arg2_smtptr;

  this->_objectptr->GetObj()->GetEventPosition(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::GetEventPosition(int * _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetEventPosition_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetEventPosition_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg_smtptr;
  if (!get_val_smtptr_param<int >(_arg_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetEventPosition(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int * vtkRenderWindowInteractor::GetLastEventPosition()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetLastEventPosition_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetLastEventPosition_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int * res =   this->_objectptr->GetObj()->GetLastEventPosition();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderWindowInteractor::GetLastEventPosition(...)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetLastEventPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetLastEventPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderWindowInteractor::wrap_GetLastEventPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_GetLastEventPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_GetLastEventPosition_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::GetLastEventPosition(int & _arg1, int & _arg2)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetLastEventPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetLastEventPosition_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg1_smtptr;
  if (!get_val_smtptr_param<int >(_arg1_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<int > _arg2_smtptr;
  if (!get_val_smtptr_param<int >(_arg2_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & _arg2 = *_arg2_smtptr;

  this->_objectptr->GetObj()->GetLastEventPosition(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::GetLastEventPosition(int * _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetLastEventPosition_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetLastEventPosition_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg_smtptr;
  if (!get_val_smtptr_param<int >(_arg_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetLastEventPosition(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetLastEventPosition(int _arg1, int _arg2)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetLastEventPosition_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetLastEventPosition_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int _arg1;
  if (!get_val_param<int >(_arg1,_p,_n)) ClassReturnEmptyVar;

  int _arg2;
  if (!get_val_param<int >(_arg2,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetLastEventPosition(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderWindowInteractor::SetLastEventPosition(...)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetLastEventPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetLastEventPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderWindowInteractor::wrap_SetLastEventPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_SetLastEventPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetLastEventPosition(int * _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetLastEventPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetLastEventPosition_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg_smtptr;
  if (!get_val_smtptr_param<int >(_arg_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetLastEventPosition(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetEventPosition(int x, int y)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventPosition_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventPosition_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetEventPosition(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderWindowInteractor::SetEventPosition(...)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderWindowInteractor::wrap_SetEventPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_SetEventPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetEventPosition(int * pos)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pos'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventPosition_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > pos_smtptr;
  if (!get_val_smtptr_param<int >(pos_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* pos = pos_smtptr.get();

  this->_objectptr->GetObj()->SetEventPosition(pos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetEventPositionFlipY(int x, int y)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventPositionFlipY_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventPositionFlipY_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetEventPositionFlipY(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderWindowInteractor::SetEventPositionFlipY(...)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventPositionFlipY::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventPositionFlipY::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderWindowInteractor::wrap_SetEventPositionFlipY_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_SetEventPositionFlipY_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetEventPositionFlipY(int * pos)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventPositionFlipY_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pos'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventPositionFlipY_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > pos_smtptr;
  if (!get_val_smtptr_param<int >(pos_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* pos = pos_smtptr.get();

  this->_objectptr->GetObj()->SetEventPositionFlipY(pos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetAltKey(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetAltKey::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetAltKey::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAltKey(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::GetAltKey()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetAltKey::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetAltKey::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAltKey();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetControlKey(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetControlKey::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetControlKey::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetControlKey(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::GetControlKey()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetControlKey::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetControlKey::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetControlKey();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetShiftKey(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetShiftKey::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetShiftKey::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetShiftKey(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::GetShiftKey()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetShiftKey::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetShiftKey::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetShiftKey();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetKeyCode(char _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetKeyCode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetKeyCode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  std::string _arg_string;
  if (!get_val_param<std::string >(_arg_string,_p,_n)) ClassHelpAndReturn;
  char _arg = ' ';
if (_arg_string.size()>0) _arg = _arg_string[0];

  this->_objectptr->GetObj()->SetKeyCode(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char vtkRenderWindowInteractor::GetKeyCode()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetKeyCode::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetKeyCode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char res =   this->_objectptr->GetObj()->GetKeyCode();
  std::string res_string = std::string(1,res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetRepeatCount(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetRepeatCount::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetRepeatCount::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRepeatCount(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindowInteractor::GetRepeatCount()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetRepeatCount::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetRepeatCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetRepeatCount();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetKeySym(char const * _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetKeySym::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetKeySym::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > _arg_string;
  if (!get_val_smtptr_param<std::string >(_arg_string,_p,_n)) ClassHelpAndReturn;
  char const * _arg = _arg_string->c_str();

  this->_objectptr->GetObj()->SetKeySym(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char * vtkRenderWindowInteractor::GetKeySym()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetKeySym::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetKeySym::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char * res =   this->_objectptr->GetObj()->GetKeySym();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetEventInformation(int x, int y, int ctrl = 0, int shift = 0, char keycode = 0, int repeatcount = 0, char const * keysym = 0)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ctrl' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'shift' (def:0)")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'keycode' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'repeatcount' (def:0)")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'keysym' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassHelpAndReturn;

  int ctrl = 0;
  if (!get_val_param<int >(ctrl,_p,_n)) ClassHelpAndReturn;

  int shift = 0;
  if (!get_val_param<int >(shift,_p,_n)) ClassHelpAndReturn;

  std::string keycode_string = std::string(1,0);;
  if (!get_val_param<std::string >(keycode_string,_p,_n)) ClassHelpAndReturn;
  char keycode = ' ';
if (keycode_string.size()>0) keycode = keycode_string[0];

  int repeatcount = 0;
  if (!get_val_param<int >(repeatcount,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<std::string > keysym_string;
  if (!get_val_smtptr_param<std::string >(keysym_string,_p,_n)) ClassHelpAndReturn;
  char const * keysym = keysym_string->c_str();

  this->_objectptr->GetObj()->SetEventInformation(x, y, ctrl, shift, keycode, repeatcount, keysym);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetEventInformationFlipY(int x, int y, int ctrl = 0, int shift = 0, char keycode = 0, int repeatcount = 0, char const * keysym = 0)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventInformationFlipY::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ctrl' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'shift' (def:0)")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'keycode' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'repeatcount' (def:0)")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'keysym' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventInformationFlipY::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassHelpAndReturn;

  int ctrl = 0;
  if (!get_val_param<int >(ctrl,_p,_n)) ClassHelpAndReturn;

  int shift = 0;
  if (!get_val_param<int >(shift,_p,_n)) ClassHelpAndReturn;

  std::string keycode_string = std::string(1,0);;
  if (!get_val_param<std::string >(keycode_string,_p,_n)) ClassHelpAndReturn;
  char keycode = ' ';
if (keycode_string.size()>0) keycode = keycode_string[0];

  int repeatcount = 0;
  if (!get_val_param<int >(repeatcount,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<std::string > keysym_string;
  if (!get_val_smtptr_param<std::string >(keysym_string,_p,_n)) ClassHelpAndReturn;
  char const * keysym = keysym_string->c_str();

  this->_objectptr->GetObj()->SetEventInformationFlipY(x, y, ctrl, shift, keycode, repeatcount, keysym);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetKeyEventInformation(int ctrl = 0, int shift = 0, char keycode = 0, int repeatcount = 0, char const * keysym = 0)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetKeyEventInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ctrl' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'shift' (def:0)")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'keycode' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'repeatcount' (def:0)")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'keysym' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetKeyEventInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  int ctrl = 0;
  if (!get_val_param<int >(ctrl,_p,_n)) ClassHelpAndReturn;

  int shift = 0;
  if (!get_val_param<int >(shift,_p,_n)) ClassHelpAndReturn;

  std::string keycode_string = std::string(1,0);;
  if (!get_val_param<std::string >(keycode_string,_p,_n)) ClassHelpAndReturn;
  char keycode = ' ';
if (keycode_string.size()>0) keycode = keycode_string[0];

  int repeatcount = 0;
  if (!get_val_param<int >(repeatcount,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<std::string > keysym_string;
  if (!get_val_smtptr_param<std::string >(keysym_string,_p,_n)) ClassHelpAndReturn;
  char const * keysym = keysym_string->c_str();

  this->_objectptr->GetObj()->SetKeyEventInformation(ctrl, shift, keycode, repeatcount, keysym);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetSize(int _arg1, int _arg2)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetSize_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetSize_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int _arg1;
  if (!get_val_param<int >(_arg1,_p,_n)) ClassReturnEmptyVar;

  int _arg2;
  if (!get_val_param<int >(_arg2,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetSize(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderWindowInteractor::SetSize(...)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderWindowInteractor::wrap_SetSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_SetSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetSize(int * _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg_smtptr;
  if (!get_val_smtptr_param<int >(_arg_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetSize(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int * vtkRenderWindowInteractor::GetSize()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetSize_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetSize_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int * res =   this->_objectptr->GetObj()->GetSize();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderWindowInteractor::GetSize(...)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderWindowInteractor::wrap_GetSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_GetSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_GetSize_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::GetSize(int & _arg1, int & _arg2)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg1_smtptr;
  if (!get_val_smtptr_param<int >(_arg1_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<int > _arg2_smtptr;
  if (!get_val_smtptr_param<int >(_arg2_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & _arg2 = *_arg2_smtptr;

  this->_objectptr->GetObj()->GetSize(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::GetSize(int * _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetSize_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetSize_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg_smtptr;
  if (!get_val_smtptr_param<int >(_arg_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetSize(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetEventSize(int _arg1, int _arg2)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventSize_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventSize_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int _arg1;
  if (!get_val_param<int >(_arg1,_p,_n)) ClassReturnEmptyVar;

  int _arg2;
  if (!get_val_param<int >(_arg2,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetEventSize(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderWindowInteractor::SetEventSize(...)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderWindowInteractor::wrap_SetEventSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_SetEventSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetEventSize(int * _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetEventSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg_smtptr;
  if (!get_val_smtptr_param<int >(_arg_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetEventSize(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int * vtkRenderWindowInteractor::GetEventSize()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetEventSize_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetEventSize_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int * res =   this->_objectptr->GetObj()->GetEventSize();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderWindowInteractor::GetEventSize(...)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetEventSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetEventSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderWindowInteractor::wrap_GetEventSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_GetEventSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindowInteractor::wrap_GetEventSize_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::GetEventSize(int & _arg1, int & _arg2)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetEventSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetEventSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg1_smtptr;
  if (!get_val_smtptr_param<int >(_arg1_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<int > _arg2_smtptr;
  if (!get_val_smtptr_param<int >(_arg2_smtptr,_p,_n)) ClassReturnEmptyVar;
  int & _arg2 = *_arg2_smtptr;

  this->_objectptr->GetObj()->GetEventSize(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::GetEventSize(int * _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetEventSize_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetEventSize_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg_smtptr;
  if (!get_val_smtptr_param<int >(_arg_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetEventSize(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkRenderer * vtkRenderWindowInteractor::FindPokedRenderer(int param0, int param1)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_FindPokedRenderer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param1'")
  return_comments="returning a variable of type vtkRenderer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_FindPokedRenderer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n)) ClassHelpAndReturn;

  int param1;
  if (!get_val_param<int >(param1,_p,_n)) ClassHelpAndReturn;

  vtkRenderer * res =   this->_objectptr->GetObj()->FindPokedRenderer(param0, param1);
  BasicVariable::ptr res_var = WrapClass_vtkRenderer::CreateVar(res);
  return res_var;
}
/* The following types are missing: vtkObserverMediator

//---------------------------------------------------
//  Wrapping of vtkObserverMediator * vtkRenderWindowInteractor::GetObserverMediator()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetObserverMediator::SetParametersComments()
{
  return_comments="returning a variable of type vtkObserverMediator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetObserverMediator::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkObserverMediator * res =   this->_objectptr->GetObj()->GetObserverMediator();
  return AMILabType<vtkObserverMediator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkRenderWindowInteractor::SetUseTDx(bool _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_SetUseTDx::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_SetUseTDx::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg_int;
  if (!get_val_param<int >(_arg_int,_p,_n)) ClassHelpAndReturn;
  bool _arg = (bool) (_arg_int>0.5);

  this->_objectptr->GetObj()->SetUseTDx(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool vtkRenderWindowInteractor::GetUseTDx()
//---------------------------------------------------
void WrapClass_vtkRenderWindowInteractor::
    wrap_GetUseTDx::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindowInteractor::
    wrap_GetUseTDx::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetUseTDx();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

