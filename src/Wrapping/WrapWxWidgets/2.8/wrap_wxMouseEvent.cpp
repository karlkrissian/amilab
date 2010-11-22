/**
 * C++ Interface: wrap_wxMouseEvent
 *
 * Description: wrapping wxMouseEvent
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
#include "wrap_wxMouseEvent.h"
#include "wrap_wxPoint.h"
#include "wrap_wxDC.h"
#include "wrap_wxEvent.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxMouseEvent.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxMouseEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxMouseEvent::wrap_wxMouseEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxMouseEvent);
AMI_DEFINE_VARFROMSMTPTR(wxMouseEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxMouseEvent
//
Variable<AMIObject>::ptr WrapClass_wxMouseEvent::CreateVar( wxMouseEvent* sp)
{
  boost::shared_ptr<wxMouseEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxMouseEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxMouseEvent>::CreateVar(
      new WrapClass_wxMouseEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxMouseEvent::AddMethods(WrapClass<wxMouseEvent>::ptr this_ptr )
{
  
      // Add members from wxEvent
      WrapClass_wxEvent::ptr parent_wxEvent(        boost::dynamic_pointer_cast<WrapClass_wxEvent >(this_ptr));
      parent_wxEvent->AddMethods(parent_wxEvent);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_IsButton( this_ptr);
      AddVar_ButtonDown( this_ptr);
      AddVar_ButtonDClick( this_ptr);
      AddVar_ButtonUp( this_ptr);
      AddVar_Button( this_ptr);
      AddVar_ButtonIsDown( this_ptr);
      AddVar_GetButton( this_ptr);
      AddVar_ControlDown( this_ptr);
      AddVar_MetaDown( this_ptr);
      AddVar_AltDown( this_ptr);
      AddVar_ShiftDown( this_ptr);
      AddVar_CmdDown( this_ptr);
      AddVar_LeftDown( this_ptr);
      AddVar_MiddleDown( this_ptr);
      AddVar_RightDown( this_ptr);
      AddVar_LeftUp( this_ptr);
      AddVar_MiddleUp( this_ptr);
      AddVar_RightUp( this_ptr);
      AddVar_LeftDClick( this_ptr);
      AddVar_MiddleDClick( this_ptr);
      AddVar_RightDClick( this_ptr);
      AddVar_LeftIsDown( this_ptr);
      AddVar_MiddleIsDown( this_ptr);
      AddVar_RightIsDown( this_ptr);
      AddVar_Dragging( this_ptr);
      AddVar_Moving( this_ptr);
      AddVar_Entering( this_ptr);
      AddVar_Leaving( this_ptr);
      AddVar_GetPosition_1( this_ptr);
      AddVar_GetPosition( this_ptr);
      AddVar_GetPosition_2( this_ptr);
      AddVar_GetPosition_3( this_ptr);
      AddVar_GetLogicalPosition( this_ptr);
      AddVar_GetX( this_ptr);
      AddVar_GetY( this_ptr);
      AddVar_GetWheelRotation( this_ptr);
      AddVar_GetWheelDelta( this_ptr);
      AddVar_GetLinesPerAction( this_ptr);
      AddVar_IsPageScroll( this_ptr);
      AddVar_Clone( this_ptr);
      AddVar_GetClassInfo( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      // Adding public member m_x
      boost::shared_ptr<int > var_m_x_ptr(&GetObj()->m_x, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_m_x = AMILabType<int >::CreateVarFromSmtPtr(var_m_x_ptr);
      if (var_m_x.get()) {
        var_m_x->Rename("m_x");
        context->AddVar(var_m_x,context);
      }
      
      // Adding public member m_y
      boost::shared_ptr<int > var_m_y_ptr(&GetObj()->m_y, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_m_y = AMILabType<int >::CreateVarFromSmtPtr(var_m_y_ptr);
      if (var_m_y.get()) {
        var_m_y->Rename("m_y");
        context->AddVar(var_m_y,context);
      }
      
      /* type not available
      // Adding public member m_leftDown
      boost::shared_ptr<bool > var_m_leftDown_ptr(&GetObj()->m_leftDown, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_leftDown = AMILabType<bool >::CreateVarFromSmtPtr(var_m_leftDown_ptr);
      if (var_m_leftDown.get()) {
        var_m_leftDown->Rename("m_leftDown");
        context->AddVar(var_m_leftDown,context);
      }
      */
      
      /* type not available
      // Adding public member m_middleDown
      boost::shared_ptr<bool > var_m_middleDown_ptr(&GetObj()->m_middleDown, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_middleDown = AMILabType<bool >::CreateVarFromSmtPtr(var_m_middleDown_ptr);
      if (var_m_middleDown.get()) {
        var_m_middleDown->Rename("m_middleDown");
        context->AddVar(var_m_middleDown,context);
      }
      */
      
      /* type not available
      // Adding public member m_rightDown
      boost::shared_ptr<bool > var_m_rightDown_ptr(&GetObj()->m_rightDown, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_rightDown = AMILabType<bool >::CreateVarFromSmtPtr(var_m_rightDown_ptr);
      if (var_m_rightDown.get()) {
        var_m_rightDown->Rename("m_rightDown");
        context->AddVar(var_m_rightDown,context);
      }
      */
      
      /* type not available
      // Adding public member m_controlDown
      boost::shared_ptr<bool > var_m_controlDown_ptr(&GetObj()->m_controlDown, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_controlDown = AMILabType<bool >::CreateVarFromSmtPtr(var_m_controlDown_ptr);
      if (var_m_controlDown.get()) {
        var_m_controlDown->Rename("m_controlDown");
        context->AddVar(var_m_controlDown,context);
      }
      */
      
      /* type not available
      // Adding public member m_shiftDown
      boost::shared_ptr<bool > var_m_shiftDown_ptr(&GetObj()->m_shiftDown, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_shiftDown = AMILabType<bool >::CreateVarFromSmtPtr(var_m_shiftDown_ptr);
      if (var_m_shiftDown.get()) {
        var_m_shiftDown->Rename("m_shiftDown");
        context->AddVar(var_m_shiftDown,context);
      }
      */
      
      /* type not available
      // Adding public member m_altDown
      boost::shared_ptr<bool > var_m_altDown_ptr(&GetObj()->m_altDown, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_altDown = AMILabType<bool >::CreateVarFromSmtPtr(var_m_altDown_ptr);
      if (var_m_altDown.get()) {
        var_m_altDown->Rename("m_altDown");
        context->AddVar(var_m_altDown,context);
      }
      */
      
      /* type not available
      // Adding public member m_metaDown
      boost::shared_ptr<bool > var_m_metaDown_ptr(&GetObj()->m_metaDown, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_metaDown = AMILabType<bool >::CreateVarFromSmtPtr(var_m_metaDown_ptr);
      if (var_m_metaDown.get()) {
        var_m_metaDown->Rename("m_metaDown");
        context->AddVar(var_m_metaDown,context);
      }
      */
      
      // Adding public member m_wheelRotation
      boost::shared_ptr<int > var_m_wheelRotation_ptr(&GetObj()->m_wheelRotation, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_m_wheelRotation = AMILabType<int >::CreateVarFromSmtPtr(var_m_wheelRotation_ptr);
      if (var_m_wheelRotation.get()) {
        var_m_wheelRotation->Rename("m_wheelRotation");
        context->AddVar(var_m_wheelRotation,context);
      }
      
      // Adding public member m_wheelDelta
      boost::shared_ptr<int > var_m_wheelDelta_ptr(&GetObj()->m_wheelDelta, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_m_wheelDelta = AMILabType<int >::CreateVarFromSmtPtr(var_m_wheelDelta_ptr);
      if (var_m_wheelDelta.get()) {
        var_m_wheelDelta->Rename("m_wheelDelta");
        context->AddVar(var_m_wheelDelta,context);
      }
      
      // Adding public member m_linesPerAction
      boost::shared_ptr<int > var_m_linesPerAction_ptr(&GetObj()->m_linesPerAction, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_m_linesPerAction = AMILabType<int >::CreateVarFromSmtPtr(var_m_linesPerAction_ptr);
      if (var_m_linesPerAction.get()) {
        var_m_linesPerAction->Rename("m_linesPerAction");
        context->AddVar(var_m_linesPerAction,context);
      }

};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxMouseEvent::wxMouseEvent(wxEventType mouseType = wxEVT_NULL)
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_wxMouseEvent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'mouseType' (def:wxEVT_NULL)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_wxMouseEvent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int mouseType = wxEVT_NULL;
  if (!get_val_param<int >(mouseType,_p,_n)) ClassReturnEmptyVar;

  wxMouseEvent* _newobj = new wxMouseEvent(mouseType);
  BasicVariable::ptr res = WrapClass_wxMouseEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxMouseEvent::wxMouseEvent(...)
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_wxMouseEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_wxMouseEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMouseEvent::wrap_wxMouseEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMouseEvent::wrap_wxMouseEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxMouseEvent::wxMouseEvent(wxMouseEvent const & event)
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_wxMouseEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_wxMouseEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMouseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMouseEvent >(event_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxMouseEvent const & event = *event_smtptr;

  wxMouseEvent* _newobj = new wxMouseEvent(event);
  BasicVariable::ptr res = WrapClass_wxMouseEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxMouseEvent.
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxMouseEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxMouseEvent >::CreateVar( new wxMouseEvent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::IsButton()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_IsButton::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_IsButton::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsButton();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::ButtonDown(int but = wxMOUSE_BTN_ANY)
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_ButtonDown::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'but' (def:wxMOUSE_BTN_ANY)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_ButtonDown::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int but = wxMOUSE_BTN_ANY;
  if (!get_val_param<int >(but,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ButtonDown(but);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::ButtonDClick(int but = wxMOUSE_BTN_ANY)
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_ButtonDClick::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'but' (def:wxMOUSE_BTN_ANY)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_ButtonDClick::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int but = wxMOUSE_BTN_ANY;
  if (!get_val_param<int >(but,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ButtonDClick(but);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::ButtonUp(int but = wxMOUSE_BTN_ANY)
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_ButtonUp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'but' (def:wxMOUSE_BTN_ANY)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_ButtonUp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int but = wxMOUSE_BTN_ANY;
  if (!get_val_param<int >(but,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ButtonUp(but);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::Button(int but)
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_Button::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'but'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_Button::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int but;
  if (!get_val_param<int >(but,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Button(but);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::ButtonIsDown(int but)
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_ButtonIsDown::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'but'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_ButtonIsDown::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int but;
  if (!get_val_param<int >(but,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ButtonIsDown(but);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of int wxMouseEvent::GetButton()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_GetButton::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_GetButton::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetButton();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::ControlDown()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_ControlDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_ControlDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ControlDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::MetaDown()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_MetaDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_MetaDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->MetaDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::AltDown()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_AltDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_AltDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->AltDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::ShiftDown()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_ShiftDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_ShiftDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ShiftDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::CmdDown()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_CmdDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_CmdDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->CmdDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::LeftDown()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_LeftDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_LeftDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->LeftDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::MiddleDown()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_MiddleDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_MiddleDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->MiddleDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::RightDown()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_RightDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_RightDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->RightDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::LeftUp()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_LeftUp::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_LeftUp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->LeftUp();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::MiddleUp()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_MiddleUp::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_MiddleUp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->MiddleUp();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::RightUp()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_RightUp::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_RightUp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->RightUp();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::LeftDClick()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_LeftDClick::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_LeftDClick::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->LeftDClick();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::MiddleDClick()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_MiddleDClick::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_MiddleDClick::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->MiddleDClick();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::RightDClick()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_RightDClick::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_RightDClick::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->RightDClick();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::LeftIsDown()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_LeftIsDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_LeftIsDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->LeftIsDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::MiddleIsDown()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_MiddleIsDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_MiddleIsDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->MiddleIsDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::RightIsDown()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_RightIsDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_RightIsDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->RightIsDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::Dragging()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_Dragging::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_Dragging::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Dragging();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::Moving()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_Moving::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_Moving::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Moving();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::Entering()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_Entering::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_Entering::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Entering();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::Leaving()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_Leaving::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_Leaving::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Leaving();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxMouseEvent::GetPosition(wxCoord * xpos, wxCoord * ypos)
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_GetPosition_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xpos'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ypos'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_GetPosition_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > xpos_smtptr;
  if (!get_val_smtptr_param<int >(xpos_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* xpos = xpos_smtptr.get();

  boost::shared_ptr<int > ypos_smtptr;
  if (!get_val_smtptr_param<int >(ypos_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* ypos = ypos_smtptr.get();

  this->_objectptr->GetObj()->GetPosition(xpos, ypos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMouseEvent::GetPosition(...)
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_GetPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_GetPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMouseEvent::wrap_GetPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMouseEvent::wrap_GetPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxMouseEvent::wrap_GetPosition_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxMouseEvent::GetPosition(long int * xpos, long int * ypos)
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_GetPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'xpos'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'ypos'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_GetPosition_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<long > xpos_long;
  if (!get_val_smtptr_param<long >(xpos_long,_p,_n)) ClassReturnEmptyVar;
  long int xpos_val = *xpos_long;
  long int* xpos = &xpos_val;

  boost::shared_ptr<long > ypos_long;
  if (!get_val_smtptr_param<long >(ypos_long,_p,_n)) ClassReturnEmptyVar;
  long int ypos_val = *ypos_long;
  long int* ypos = &ypos_val;

  this->_objectptr->GetObj()->GetPosition(xpos, ypos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxPoint wxMouseEvent::GetPosition()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_GetPosition_3::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_GetPosition_3::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxPoint res =   this->_objectptr->GetObj()->GetPosition();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxMouseEvent::GetLogicalPosition(wxDC const & dc)
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_GetLogicalPosition::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDC, "parameter named 'dc'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_GetLogicalPosition::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDC > dc_smtptr;
  if (!get_val_smtptr_param<wxDC >(dc_smtptr,_p,_n)) ClassHelpAndReturn;
  wxDC const & dc = *dc_smtptr;

  wxPoint res =   this->_objectptr->GetObj()->GetLogicalPosition(dc);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxMouseEvent::GetX()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_GetX::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_GetX::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->GetX();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxMouseEvent::GetY()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_GetY::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_GetY::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->GetY();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxMouseEvent::GetWheelRotation()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_GetWheelRotation::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_GetWheelRotation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetWheelRotation();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxMouseEvent::GetWheelDelta()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_GetWheelDelta::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_GetWheelDelta::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetWheelDelta();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxMouseEvent::GetLinesPerAction()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_GetLinesPerAction::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_GetLinesPerAction::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetLinesPerAction();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxMouseEvent::IsPageScroll()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_IsPageScroll::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_IsPageScroll::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsPageScroll();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxMouseEvent::Clone()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = WrapClass_wxEvent::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxMouseEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMouseEvent & wxMouseEvent::operator =(wxMouseEvent const & event)
//---------------------------------------------------
void WrapClass_wxMouseEvent::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'event'")
  return_comments="returning a variable of type wxMouseEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMouseEvent::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMouseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMouseEvent >(event_smtptr,_p,_n)) ClassHelpAndReturn;
  wxMouseEvent const & event = *event_smtptr;

  wxMouseEvent & res =   (*this->_objectptr->GetObj()) = (event);
  return AMILabType<wxMouseEvent >::CreateVar(res);
}

