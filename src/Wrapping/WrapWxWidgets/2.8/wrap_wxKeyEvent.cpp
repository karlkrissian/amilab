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

/*
//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
*/

#include "wrap_wxKeyEvent.h"

// get all the required includes
// #include "..."
#include "stdlib.h"
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxKeyEvent_declared
  #define wxKeyEvent_declared
  AMI_DECLARE_TYPE(wxKeyEvent)
#endif
#ifndef wxPoint_declared
  #define wxPoint_declared
  AMI_DECLARE_TYPE(wxPoint)
#endif
#ifndef wxEvent_declared
  #define wxEvent_declared
  AMI_DECLARE_TYPE(wxEvent)
#endif
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

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
  // todo: check that the method name is not a token ?
  
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
  AddVar_Clone( this_ptr);
  AddVar_GetClassInfo( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxEvent
  boost::shared_ptr<wxEvent > parent_wxEvent(  boost::dynamic_pointer_cast<wxEvent >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxEvent = AMILabType<wxEvent >::CreateVarFromSmtPtr(parent_wxEvent);
  context->AddVar("wxEvent",var_wxEvent);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxEvent = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxEvent);
  context->AddDefault(obj_wxEvent->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxKeyEvent_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxKeyEvent");
    WrapClass_wxKeyEvent::AddVar_wxKeyEvent_1(amiobject->GetContext());
  WrapClass_wxKeyEvent::AddVar_wxKeyEvent(amiobject->GetContext());
  WrapClass_wxKeyEvent::AddVar_wxKeyEvent_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

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
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_ControlDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ControlDown();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxKeyEvent::ShiftDown()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_ShiftDown::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_ShiftDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ShiftDown();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxKeyEvent::MetaDown()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_MetaDown::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_MetaDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->MetaDown();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxKeyEvent::AltDown()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_AltDown::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_AltDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->AltDown();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxKeyEvent::CmdDown()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_CmdDown::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_CmdDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->CmdDown();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxKeyEvent::HasModifiers()
//---------------------------------------------------
void WrapClass_wxKeyEvent::
    wrap_HasModifiers::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxKeyEvent::
    wrap_HasModifiers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasModifiers();
  return AMILabType<bool >::CreateVar(res);
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

  int* xpos;
  if (CheckNullVar(_p,_n))  {
    xpos=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > xpos_smtptr;
    if (!get_val_smtptr_param<int >(xpos_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    xpos = xpos_smtptr.get();
  }

  int* ypos;
  if (CheckNullVar(_p,_n))  {
    ypos=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > ypos_smtptr;
    if (!get_val_smtptr_param<int >(ypos_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    ypos = ypos_smtptr.get();
  }

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
  BasicVariable::ptr res_var = AMILabType<wxEvent >::CreateVar(res,true);
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
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
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

