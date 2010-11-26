/**
 * C++ Interface: wrap_wxUpdateUIEvent
 *
 * Description: wrapping wxUpdateUIEvent
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
#include "wrap_wxUpdateUIEvent.h"
#include "wrap_wxWindowBase.h"
#include "wrap_wxString.h"
#include "wrap_wxEvent.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxUpdateUIEvent.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxUpdateUIEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxUpdateUIEvent::wrap_wxUpdateUIEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxUpdateUIEvent);
AMI_DEFINE_VARFROMSMTPTR(wxUpdateUIEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxUpdateUIEvent
//
Variable<AMIObject>::ptr WrapClass_wxUpdateUIEvent::CreateVar( wxUpdateUIEvent* sp)
{
  boost::shared_ptr<wxUpdateUIEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxUpdateUIEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxUpdateUIEvent>::CreateVar(
      new WrapClass_wxUpdateUIEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxUpdateUIEvent::AddMethods(WrapClass<wxUpdateUIEvent>::ptr this_ptr )
{
  
      // Add members from wxCommandEvent
      WrapClass_wxCommandEvent::ptr parent_wxCommandEvent(        boost::dynamic_pointer_cast<WrapClass_wxCommandEvent >(this_ptr));
      parent_wxCommandEvent->AddMethods(parent_wxCommandEvent);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_GetChecked( this_ptr);
      AddVar_GetEnabled( this_ptr);
      AddVar_GetShown( this_ptr);
      AddVar_GetText( this_ptr);
      AddVar_GetSetText( this_ptr);
      AddVar_GetSetChecked( this_ptr);
      AddVar_GetSetEnabled( this_ptr);
      AddVar_GetSetShown( this_ptr);
      AddVar_Check( this_ptr);
      AddVar_Enable( this_ptr);
      AddVar_Show( this_ptr);
      AddVar_SetText( this_ptr);
      AddVar_Clone( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxUpdateUIEvent::wxUpdateUIEvent(wxWindowID commandId = 0)
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_wxUpdateUIEvent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'commandId' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_wxUpdateUIEvent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int commandId = 0;
  if (!get_val_param<int >(commandId,_p,_n,false,true)) ClassReturnEmptyVar;

  wxUpdateUIEvent* _newobj = new wxUpdateUIEvent(commandId);
  BasicVariable::ptr res = WrapClass_wxUpdateUIEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxUpdateUIEvent::wxUpdateUIEvent(...)
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_wxUpdateUIEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_wxUpdateUIEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxUpdateUIEvent::wrap_wxUpdateUIEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxUpdateUIEvent::wrap_wxUpdateUIEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxUpdateUIEvent::wxUpdateUIEvent(wxUpdateUIEvent const & event)
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_wxUpdateUIEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUpdateUIEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_wxUpdateUIEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxUpdateUIEvent > event_smtptr;
  if (!get_val_smtptr_param<wxUpdateUIEvent >(event_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxUpdateUIEvent const & event = *event_smtptr;

  wxUpdateUIEvent* _newobj = new wxUpdateUIEvent(event);
  BasicVariable::ptr res = WrapClass_wxUpdateUIEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxUpdateUIEvent::SetUpdateInterval(long int updateInterval)
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_SetUpdateInterval::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'updateInterval'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_SetUpdateInterval::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long updateInterval_long;
  if (!get_val_param<long >(updateInterval_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int updateInterval = updateInterval_long;

  wxUpdateUIEvent::SetUpdateInterval(updateInterval);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long int wxUpdateUIEvent::GetUpdateInterval()
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_GetUpdateInterval::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_GetUpdateInterval::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   wxUpdateUIEvent::GetUpdateInterval();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxUpdateUIEvent::CanUpdate(wxWindowBase * win)
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_CanUpdate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'win'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_CanUpdate::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowBase > win_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(win_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindowBase* win = win_smtptr.get();

  bool res =   wxUpdateUIEvent::CanUpdate(win);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxUpdateUIEvent::ResetUpdateTime()
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_ResetUpdateTime::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_ResetUpdateTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxUpdateUIEvent::ResetUpdateTime();
  return BasicVariable::ptr();
}
/* The following types are missing: wxUpdateUIMode

//---------------------------------------------------
//  Wrapping of void wxUpdateUIEvent::SetMode(wxUpdateUIMode mode)
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_SetMode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUpdateUIMode, "parameter named 'mode'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_SetMode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxUpdateUIMode mode;
  if (!get_val_param<wxUpdateUIMode >(mode,_p,_n,true,false)) ClassHelpAndReturn;

  wxUpdateUIEvent::SetMode(mode);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxUpdateUIMode

//---------------------------------------------------
//  Wrapping of wxUpdateUIMode wxUpdateUIEvent::GetMode()
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_GetMode::SetParametersComments()
{
  return_comments="returning a variable of type wxUpdateUIMode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_GetMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxUpdateUIMode res =   wxUpdateUIEvent::GetMode();
  return AMILabType<wxUpdateUIMode >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of 'copy' method for wxUpdateUIEvent.
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxUpdateUIEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxUpdateUIEvent >::CreateVar( new wxUpdateUIEvent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxUpdateUIEvent::GetChecked()
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_GetChecked::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_GetChecked::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetChecked();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxUpdateUIEvent::GetEnabled()
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_GetEnabled::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_GetEnabled::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetEnabled();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxUpdateUIEvent::GetShown()
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_GetShown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_GetShown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetShown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxString wxUpdateUIEvent::GetText()
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_GetText::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_GetText::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetText();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxUpdateUIEvent::GetSetText()
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_GetSetText::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_GetSetText::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetSetText();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxUpdateUIEvent::GetSetChecked()
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_GetSetChecked::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_GetSetChecked::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetSetChecked();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxUpdateUIEvent::GetSetEnabled()
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_GetSetEnabled::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_GetSetEnabled::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetSetEnabled();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxUpdateUIEvent::GetSetShown()
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_GetSetShown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_GetSetShown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetSetShown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxUpdateUIEvent::Check(bool check)
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_Check::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'check'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_Check::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int check_int;
  if (!get_val_param<int >(check_int,_p,_n,true,false)) ClassHelpAndReturn;
  bool check = (bool) (check_int>0.5);

  this->_objectptr->GetObj()->Check(check);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxUpdateUIEvent::Enable(bool enable)
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_Enable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'enable'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_Enable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int enable_int;
  if (!get_val_param<int >(enable_int,_p,_n,true,false)) ClassHelpAndReturn;
  bool enable = (bool) (enable_int>0.5);

  this->_objectptr->GetObj()->Enable(enable);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxUpdateUIEvent::Show(bool show)
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_Show::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'show'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_Show::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int show_int;
  if (!get_val_param<int >(show_int,_p,_n,true,false)) ClassHelpAndReturn;
  bool show = (bool) (show_int>0.5);

  this->_objectptr->GetObj()->Show(show);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxUpdateUIEvent::SetText(wxString const & text)
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_SetText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_SetText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  this->_objectptr->GetObj()->SetText(text);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxUpdateUIEvent::Clone()
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = WrapClass_wxEvent::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxUpdateUIEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxUpdateUIEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxUpdateUIEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

