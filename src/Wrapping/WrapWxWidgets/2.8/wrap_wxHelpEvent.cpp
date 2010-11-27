/**
 * C++ Interface: wrap_wxHelpEvent
 *
 * Description: wrapping wxHelpEvent
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
#include "wrap_wxPoint.h"
#include "wrap_wxHelpEvent.h"
#include "wrap_wxString.h"
#include "wrap_wxEvent.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxHelpEvent.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHelpEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxHelpEvent::wrap_wxHelpEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxHelpEvent);
AMI_DEFINE_VARFROMSMTPTR(wxHelpEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHelpEvent
//
Variable<AMIObject>::ptr WrapClass_wxHelpEvent::CreateVar( wxHelpEvent* sp)
{
  boost::shared_ptr<wxHelpEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxHelpEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHelpEvent>::CreateVar(
      new WrapClass_wxHelpEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHelpEvent::AddMethods(WrapClass<wxHelpEvent>::ptr this_ptr )
{
  
      // Add members from wxCommandEvent
      WrapClass_wxCommandEvent::ptr parent_wxCommandEvent(        boost::dynamic_pointer_cast<WrapClass_wxCommandEvent >(this_ptr));
      parent_wxCommandEvent->AddMethods(parent_wxCommandEvent);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_GetPosition( this_ptr);
      AddVar_SetPosition( this_ptr);
      AddVar_GetLink( this_ptr);
      AddVar_SetLink( this_ptr);
      AddVar_GetTarget( this_ptr);
      AddVar_SetTarget( this_ptr);
      AddVar_Clone( this_ptr);
      AddVar_GetOrigin( this_ptr);
      AddVar_SetOrigin( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxHelpEvent::wxHelpEvent(wxEventType type = wxEVT_NULL, wxWindowID winid = 0, wxPoint const & pt = wxDefaultPosition, wxHelpEvent::Origin origin = Origin_Unknown)
//---------------------------------------------------
void WrapClass_wxHelpEvent::
    wrap_wxHelpEvent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type' (def:wxEVT_NULL)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'origin' (def:Origin_Unknown)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHelpEvent::
    wrap_wxHelpEvent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int type = wxEVT_NULL;
  if (!get_val_param<int >(type,_p,_n,false,true)) ClassReturnEmptyVar;

  int winid = 0;
  if (!get_val_param<int >(winid,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pt = ( pt_smtptr.get() ? (*pt_smtptr) : wxPoint(wxDefaultPosition) );

  int origin_int = (int) wxHelpEvent::Origin_Unknown;;
  if (!get_val_param<int >(origin_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxHelpEvent::Origin origin = (wxHelpEvent::Origin) origin_int;

  wxHelpEvent* _newobj = new wxHelpEvent(type, winid, pt, origin);
  BasicVariable::ptr res = WrapClass_wxHelpEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxHelpEvent::wxHelpEvent(...)
//---------------------------------------------------
void WrapClass_wxHelpEvent::
    wrap_wxHelpEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHelpEvent::
    wrap_wxHelpEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxHelpEvent::wrap_wxHelpEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxHelpEvent::wrap_wxHelpEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxHelpEvent::wxHelpEvent(wxHelpEvent const & event)
//---------------------------------------------------
void WrapClass_wxHelpEvent::
    wrap_wxHelpEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHelpEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHelpEvent::
    wrap_wxHelpEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxHelpEvent > event_smtptr;
  if (!get_val_smtptr_param<wxHelpEvent >(event_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxHelpEvent const & event = *event_smtptr;

  wxHelpEvent* _newobj = new wxHelpEvent(event);
  BasicVariable::ptr res = WrapClass_wxHelpEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxHelpEvent.
//---------------------------------------------------
void WrapClass_wxHelpEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxHelpEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHelpEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxHelpEvent >::CreateVar( new wxHelpEvent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxPoint const & wxHelpEvent::GetPosition()
//---------------------------------------------------
void WrapClass_wxHelpEvent::
    wrap_GetPosition::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHelpEvent::
    wrap_GetPosition::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint const & res =   this->_objectptr->GetObj()->GetPosition();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHelpEvent::SetPosition(wxPoint const & pos)
//---------------------------------------------------
void WrapClass_wxHelpEvent::
    wrap_SetPosition::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHelpEvent::
    wrap_SetPosition::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & pos = *pos_smtptr;

  this->_objectptr->GetObj()->SetPosition(pos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString const & wxHelpEvent::GetLink()
//---------------------------------------------------
void WrapClass_wxHelpEvent::
    wrap_GetLink::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHelpEvent::
    wrap_GetLink::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetLink();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHelpEvent::SetLink(wxString const & link)
//---------------------------------------------------
void WrapClass_wxHelpEvent::
    wrap_SetLink::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'link'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHelpEvent::
    wrap_SetLink::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > link_smtptr;
  if (!get_val_smtptr_param<wxString >(link_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & link = *link_smtptr;

  this->_objectptr->GetObj()->SetLink(link);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString const & wxHelpEvent::GetTarget()
//---------------------------------------------------
void WrapClass_wxHelpEvent::
    wrap_GetTarget::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHelpEvent::
    wrap_GetTarget::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetTarget();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHelpEvent::SetTarget(wxString const & target)
//---------------------------------------------------
void WrapClass_wxHelpEvent::
    wrap_SetTarget::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'target'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHelpEvent::
    wrap_SetTarget::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > target_smtptr;
  if (!get_val_smtptr_param<wxString >(target_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & target = *target_smtptr;

  this->_objectptr->GetObj()->SetTarget(target);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxHelpEvent::Clone()
//---------------------------------------------------
void WrapClass_wxHelpEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHelpEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = WrapClass_wxEvent::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHelpEvent::Origin wxHelpEvent::GetOrigin()
//---------------------------------------------------
void WrapClass_wxHelpEvent::
    wrap_GetOrigin::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHelpEvent::
    wrap_GetOrigin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHelpEvent::Origin res =   this->_objectptr->GetObj()->GetOrigin();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxHelpEvent::SetOrigin(wxHelpEvent::Origin origin)
//---------------------------------------------------
void WrapClass_wxHelpEvent::
    wrap_SetOrigin::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'origin'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHelpEvent::
    wrap_SetOrigin::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int origin_int;
  if (!get_val_param<int >(origin_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxHelpEvent::Origin origin = (wxHelpEvent::Origin) origin_int;

  this->_objectptr->GetObj()->SetOrigin(origin);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxHelpEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxHelpEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHelpEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

