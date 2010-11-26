/**
 * C++ Interface: wrap_wxKeyEvent
 *
 * Description: wrapping wxKeyEvent
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
#include "wrap_wxKeyEvent.h"
#include "stdlib.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxPoint.h"
#include "wrap_wxEvent.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxKeyEvent.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxKeyEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxKeyEvent::wrap_wxKeyEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxKeyEvent);
AMI_DEFINE_VARFROMSMTPTR(wxKeyEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxKeyEvent
//
Variable<AMIObject>::ptr WrapClass_wxKeyEvent::CreateVar( wxKeyEvent* sp)
{
  boost::shared_ptr<wxKeyEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxKeyEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxKeyEvent>::CreateVar(
      new WrapClass_wxKeyEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxKeyEvent::AddMethods(WrapClass<wxKeyEvent>::ptr this_ptr )
{
  
      // Add members from wxEvent
      WrapClass_wxEvent::ptr parent_wxEvent(        boost::dynamic_pointer_cast<WrapClass_wxEvent >(this_ptr));
      parent_wxEvent->AddMethods(parent_wxEvent);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_GetModifiers( this_ptr);
      AddVar_ControlDown( this_ptr);
      AddVar_ShiftDown( this_ptr);
      AddVar_MetaDown( this_ptr);
      AddVar_AltDown( this_ptr);
      AddVar_CmdDown( this_ptr);
      AddVar_HasModifiers( this_ptr);
      AddVar_GetKeyCode( this_ptr);
      AddVar_GetUnicodeKey( this_ptr);
      AddVar_GetRawKeyCode( this_ptr);
      AddVar_GetRawKeyFlags( this_ptr);
      AddVar_GetPosition_1( this_ptr);
      AddVar_GetPosition( this_ptr);
      AddVar_GetPosition_2( this_ptr);
      AddVar_GetPosition_3( this_ptr);
      AddVar_GetX( this_ptr);
      AddVar_GetY( this_ptr);
      AddVar_KeyCode( this_ptr);
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
      
      // Adding public member m_keyCode
      boost::shared_ptr<long int > var_m_keyCode_ptr(&GetObj()->m_keyCode, smartpointer_nodeleter<long int >());
      BasicVariable::ptr var_m_keyCode = AMILabType<long int >::CreateVarFromSmtPtr(var_m_keyCode_ptr);
      if (var_m_keyCode.get()) {
        var_m_keyCode->Rename("m_keyCode");
        context->AddVar(var_m_keyCode,context);
      }
      
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
      
      /* type not available
      // Adding public member m_scanCode
      boost::shared_ptr<bool > var_m_scanCode_ptr(&GetObj()->m_scanCode, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_scanCode = AMILabType<bool >::CreateVarFromSmtPtr(var_m_scanCode_ptr);
      if (var_m_scanCode.get()) {
        var_m_scanCode->Rename("m_scanCode");
        context->AddVar(var_m_scanCode,context);
      }
      */
      
      /* type not available
      // Adding public member m_uniChar
      boost::shared_ptr<wchar_t > var_m_uniChar_ptr(&GetObj()->m_uniChar, smartpointer_nodeleter<wchar_t >());
      BasicVariable::ptr var_m_uniChar = AMILabType<wchar_t >::CreateVarFromSmtPtr(var_m_uniChar_ptr);
      if (var_m_uniChar.get()) {
        var_m_uniChar->Rename("m_uniChar");
        context->AddVar(var_m_uniChar,context);
      }
      */
      
      /* type not available
      // Adding public member m_rawCode
      boost::shared_ptr<unsigned int > var_m_rawCode_ptr(&GetObj()->m_rawCode, smartpointer_nodeleter<unsigned int >());
      BasicVariable::ptr var_m_rawCode = AMILabType<unsigned int >::CreateVarFromSmtPtr(var_m_rawCode_ptr);
      if (var_m_rawCode.get()) {
        var_m_rawCode->Rename("m_rawCode");
        context->AddVar(var_m_rawCode,context);
      }
      */
      
      /* type not available
      // Adding public member m_rawFlags
      boost::shared_ptr<unsigned int > var_m_rawFlags_ptr(&GetObj()->m_rawFlags, smartpointer_nodeleter<unsigned int >());
      BasicVariable::ptr var_m_rawFlags = AMILabType<unsigned int >::CreateVarFromSmtPtr(var_m_rawFlags_ptr);
      if (var_m_rawFlags.get()) {
        var_m_rawFlags->Rename("m_rawFlags");
        context->AddVar(var_m_rawFlags,context);
      }
      */

};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxKeyEvent::wxKeyEvent(wxEventType keyType = wxEVT_NULL)
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_wxKeyEvent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'keyType' (def:wxEVT_NULL)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_wxKeyEvent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int keyType = wxEVT_NULL;
  if (!get_val_param<int >(keyType,_p,_n,false,true)) ClassReturnEmptyVar;

  wxKeyEvent* _newobj = new wxKeyEvent(keyType);
  BasicVariable::ptr res = WrapClass_wxKeyEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxKeyEvent::wxKeyEvent(...)
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_wxKeyEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_wxKeyEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxKeyEvent::wrap_wxKeyEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxKeyEvent::wrap_wxKeyEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxKeyEvent::wxKeyEvent(wxKeyEvent const & evt)
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_wxKeyEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxKeyEvent, "parameter named 'evt'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_wxKeyEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxKeyEvent > evt_smtptr;
  if (!get_val_smtptr_param<wxKeyEvent >(evt_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxKeyEvent const & evt = *evt_smtptr;

  wxKeyEvent* _newobj = new wxKeyEvent(evt);
  BasicVariable::ptr res = WrapClass_wxKeyEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxKeyEvent.
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxKeyEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxKeyEvent >::CreateVar( new wxKeyEvent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of int wxKeyEvent::GetModifiers()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_GetModifiers::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_GetModifiers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetModifiers();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxKeyEvent::ControlDown()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_ControlDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_ControlDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ControlDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxKeyEvent::ShiftDown()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_ShiftDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_ShiftDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ShiftDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxKeyEvent::MetaDown()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_MetaDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_MetaDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->MetaDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxKeyEvent::AltDown()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_AltDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_AltDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->AltDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxKeyEvent::CmdDown()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_CmdDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_CmdDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->CmdDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxKeyEvent::HasModifiers()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_HasModifiers::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_HasModifiers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasModifiers();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of int wxKeyEvent::GetKeyCode()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_GetKeyCode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_GetKeyCode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetKeyCode();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxChar wxKeyEvent::GetUnicodeKey()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_GetUnicodeKey::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_GetUnicodeKey::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxChar res =   this->_objectptr->GetObj()->GetUnicodeKey();
  std::string res_string;
  {
    wchar_t val = res;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res>0) res_string = std::string(1,char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxUint32 wxKeyEvent::GetRawKeyCode()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_GetRawKeyCode::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_GetRawKeyCode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxUint32 res =   this->_objectptr->GetObj()->GetRawKeyCode();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxUint32 wxKeyEvent::GetRawKeyFlags()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_GetRawKeyFlags::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_GetRawKeyFlags::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxUint32 res =   this->_objectptr->GetObj()->GetRawKeyFlags();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxKeyEvent::GetPosition(wxCoord * xpos, wxCoord * ypos)
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_GetPosition_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xpos'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ypos'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_GetPosition_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > xpos_smtptr;
  if (!get_val_smtptr_param<int >(xpos_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* xpos = xpos_smtptr.get();

  boost::shared_ptr<int > ypos_smtptr;
  if (!get_val_smtptr_param<int >(ypos_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* ypos = ypos_smtptr.get();

  this->_objectptr->GetObj()->GetPosition(xpos, ypos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxKeyEvent::GetPosition(...)
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_GetPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_GetPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxKeyEvent::wrap_GetPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxKeyEvent::wrap_GetPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxKeyEvent::wrap_GetPosition_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxKeyEvent::GetPosition(long int * xpos, long int * ypos)
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_GetPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'xpos'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'ypos'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_GetPosition_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<long > xpos_long;
  if (!get_val_smtptr_param<long >(xpos_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long int xpos_val = *xpos_long;
  long int* xpos = &xpos_val;

  boost::shared_ptr<long > ypos_long;
  if (!get_val_smtptr_param<long >(ypos_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long int ypos_val = *ypos_long;
  long int* ypos = &ypos_val;

  this->_objectptr->GetObj()->GetPosition(xpos, ypos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxPoint wxKeyEvent::GetPosition()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_GetPosition_3::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_GetPosition_3::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxPoint res =   this->_objectptr->GetObj()->GetPosition();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxKeyEvent::GetX()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_GetX::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_GetX::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->GetX();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxKeyEvent::GetY()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_GetY::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_GetY::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->GetY();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of long int wxKeyEvent::KeyCode()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_KeyCode::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_KeyCode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   this->_objectptr->GetObj()->KeyCode();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxKeyEvent::Clone()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = WrapClass_wxEvent::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxKeyEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxKeyEvent & wxKeyEvent::operator =(wxKeyEvent const & evt)
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxKeyEvent, "parameter named 'evt'")
  return_comments="returning a variable of type wxKeyEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxKeyEvent > evt_smtptr;
  if (!get_val_smtptr_param<wxKeyEvent >(evt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxKeyEvent const & evt = *evt_smtptr;

  wxKeyEvent & res =   (*this->_objectptr->GetObj()) = (evt);
  return AMILabType<wxKeyEvent >::CreateVar(res);
}

