/**
 * C++ Interface: wrap_wxAuiManagerEvent
 *
 * Description: wrapping wxAuiManagerEvent
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
#include "wrap_wxAuiManager.h"
#include "wrap_wxAuiPaneInfo.h"
#include "wrap_wxDC.h"
#include "wrap_wxAuiManagerEvent.h"
#include "wrap_wxEvent.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxAuiManagerEvent.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAuiManagerEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxAuiManagerEvent::wrap_wxAuiManagerEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxAuiManagerEvent);
AMI_DEFINE_VARFROMSMTPTR(wxAuiManagerEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxAuiManagerEvent
//
Variable<AMIObject>::ptr WrapClass_wxAuiManagerEvent::CreateVar( wxAuiManagerEvent* sp)
{
  boost::shared_ptr<wxAuiManagerEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxAuiManagerEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAuiManagerEvent>::CreateVar(
      new WrapClass_wxAuiManagerEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxAuiManagerEvent::AddMethods(WrapClass<wxAuiManagerEvent>::ptr this_ptr )
{
  
      // Add members from wxEvent
      WrapClass_wxEvent::ptr parent_wxEvent(        boost::dynamic_pointer_cast<WrapClass_wxEvent >(this_ptr));
      parent_wxEvent->AddMethods(parent_wxEvent);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Clone( this_ptr);
      AddVar_SetManager( this_ptr);
      AddVar_SetPane( this_ptr);
      AddVar_SetButton( this_ptr);
      AddVar_SetDC( this_ptr);
      AddVar_GetManager( this_ptr);
      AddVar_GetPane( this_ptr);
      AddVar_GetButton( this_ptr);
      AddVar_GetDC( this_ptr);
      AddVar_Veto( this_ptr);
      AddVar_GetVeto( this_ptr);
      AddVar_SetCanVeto( this_ptr);
      AddVar_CanVeto( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      // Adding public member manager
      boost::shared_ptr<wxAuiManager > var_manager_ptr(GetObj()->manager, smartpointer_nodeleter<wxAuiManager >());
      BasicVariable::ptr var_manager = AMILabType<wxAuiManager >::CreateVarFromSmtPtr(var_manager_ptr);
      if (var_manager.get()) {
        var_manager->Rename("manager");
        context->AddVar(var_manager,context);
      }
      
      // Adding public member pane
      boost::shared_ptr<wxAuiPaneInfo > var_pane_ptr(GetObj()->pane, smartpointer_nodeleter<wxAuiPaneInfo >());
      BasicVariable::ptr var_pane = AMILabType<wxAuiPaneInfo >::CreateVarFromSmtPtr(var_pane_ptr);
      if (var_pane.get()) {
        var_pane->Rename("pane");
        context->AddVar(var_pane,context);
      }
      
      // Adding public member button
      boost::shared_ptr<int > var_button_ptr(&GetObj()->button, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_button = AMILabType<int >::CreateVarFromSmtPtr(var_button_ptr);
      if (var_button.get()) {
        var_button->Rename("button");
        context->AddVar(var_button,context);
      }
      
      /* type not available
      // Adding public member veto_flag
      boost::shared_ptr<bool > var_veto_flag_ptr(&GetObj()->veto_flag, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_veto_flag = AMILabType<bool >::CreateVarFromSmtPtr(var_veto_flag_ptr);
      if (var_veto_flag.get()) {
        var_veto_flag->Rename("veto_flag");
        context->AddVar(var_veto_flag,context);
      }
      */
      
      /* type not available
      // Adding public member canveto_flag
      boost::shared_ptr<bool > var_canveto_flag_ptr(&GetObj()->canveto_flag, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_canveto_flag = AMILabType<bool >::CreateVarFromSmtPtr(var_canveto_flag_ptr);
      if (var_canveto_flag.get()) {
        var_canveto_flag->Rename("canveto_flag");
        context->AddVar(var_canveto_flag,context);
      }
      */
      
      // Adding public member dc
      boost::shared_ptr<wxDC > var_dc_ptr(GetObj()->dc, smartpointer_nodeleter<wxDC >());
      BasicVariable::ptr var_dc = AMILabType<wxDC >::CreateVarFromSmtPtr(var_dc_ptr);
      if (var_dc.get()) {
        var_dc->Rename("dc");
        context->AddVar(var_dc,context);
      }

};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxAuiManagerEvent::wxAuiManagerEvent(wxEventType type = wxEVT_NULL)
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_wxAuiManagerEvent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type' (def:wxEVT_NULL)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_wxAuiManagerEvent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int type = wxEVT_NULL;
  if (!get_val_param<int >(type,_p,_n,false,true)) ClassReturnEmptyVar;

  wxAuiManagerEvent* _newobj = new wxAuiManagerEvent(type);
  BasicVariable::ptr res = WrapClass_wxAuiManagerEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxAuiManagerEvent::wxAuiManagerEvent(...)
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_wxAuiManagerEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_wxAuiManagerEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiManagerEvent::wrap_wxAuiManagerEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiManagerEvent::wrap_wxAuiManagerEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxAuiManagerEvent::wxAuiManagerEvent(wxAuiManagerEvent const & c)
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_wxAuiManagerEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiManagerEvent, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_wxAuiManagerEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiManagerEvent > c_smtptr;
  if (!get_val_smtptr_param<wxAuiManagerEvent >(c_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxAuiManagerEvent const & c = *c_smtptr;

  wxAuiManagerEvent* _newobj = new wxAuiManagerEvent(c);
  BasicVariable::ptr res = WrapClass_wxAuiManagerEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxAuiManagerEvent.
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxAuiManagerEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxAuiManagerEvent >::CreateVar( new wxAuiManagerEvent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxAuiManagerEvent::Clone()
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = WrapClass_wxEvent::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxAuiManagerEvent::SetManager(wxAuiManager * mgr)
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_SetManager::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiManager, "parameter named 'mgr'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_SetManager::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiManager > mgr_smtptr;
  if (!get_val_smtptr_param<wxAuiManager >(mgr_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiManager* mgr = mgr_smtptr.get();

  this->_objectptr->GetObj()->SetManager(mgr);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiManagerEvent::SetPane(wxAuiPaneInfo * p)
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_SetPane::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_SetPane::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfo > p_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiPaneInfo* p = p_smtptr.get();

  this->_objectptr->GetObj()->SetPane(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiManagerEvent::SetButton(int b)
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_SetButton::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_SetButton::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int b;
  if (!get_val_param<int >(b,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetButton(b);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiManagerEvent::SetDC(wxDC * pdc)
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_SetDC::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDC, "parameter named 'pdc'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_SetDC::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDC > pdc_smtptr;
  if (!get_val_smtptr_param<wxDC >(pdc_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDC* pdc = pdc_smtptr.get();

  this->_objectptr->GetObj()->SetDC(pdc);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxAuiManager * wxAuiManagerEvent::GetManager()
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_GetManager::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiManager";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_GetManager::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiManager * res =   this->_objectptr->GetObj()->GetManager();
  BasicVariable::ptr res_var = WrapClass_wxAuiManager::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo * wxAuiManagerEvent::GetPane()
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_GetPane::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_GetPane::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo * res =   this->_objectptr->GetObj()->GetPane();
  BasicVariable::ptr res_var = WrapClass_wxAuiPaneInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int wxAuiManagerEvent::GetButton()
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_GetButton::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_GetButton::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetButton();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDC * wxAuiManagerEvent::GetDC()
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_GetDC::SetParametersComments()
{
  return_comments="returning a variable of type wxDC";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_GetDC::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDC * res =   this->_objectptr->GetObj()->GetDC();
  BasicVariable::ptr res_var = WrapClass_wxDC::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxAuiManagerEvent::Veto(bool veto = true)
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_Veto::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'veto' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_Veto::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int veto_int = ((true==true)?1:0);;
  if (!get_val_param<int >(veto_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool veto = (bool) (veto_int>0.5);

  this->_objectptr->GetObj()->Veto(veto);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiManagerEvent::GetVeto()
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_GetVeto::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_GetVeto::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetVeto();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxAuiManagerEvent::SetCanVeto(bool can_veto)
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_SetCanVeto::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'can_veto'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_SetCanVeto::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int can_veto_int;
  if (!get_val_param<int >(can_veto_int,_p,_n,true,false)) ClassHelpAndReturn;
  bool can_veto = (bool) (can_veto_int>0.5);

  this->_objectptr->GetObj()->SetCanVeto(can_veto);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiManagerEvent::CanVeto()
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_CanVeto::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_CanVeto::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->CanVeto();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxAuiManagerEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxAuiManagerEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManagerEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

