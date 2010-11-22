/**
 * C++ Interface: wrap_wxCommandEvent
 *
 * Description: wrapping wxCommandEvent
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
#include "wrap_wxCommandEvent.h"
#include "wrap_wxClientData.h"
#include "wrap_wxString.h"
#include "wrap_wxEvent.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxCommandEvent.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxCommandEvent>::CreateVar( ParamList* p)
{
  WrapClass_wxCommandEvent::wrap_wxCommandEvent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxCommandEvent);
AMI_DEFINE_VARFROMSMTPTR(wxCommandEvent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxCommandEvent
//
Variable<AMIObject>::ptr WrapClass_wxCommandEvent::CreateVar( wxCommandEvent* sp)
{
  boost::shared_ptr<wxCommandEvent> di_ptr(
    sp,
    wxwindow_nodeleter<wxCommandEvent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxCommandEvent>::CreateVar(
      new WrapClass_wxCommandEvent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxCommandEvent::AddMethods(WrapClass<wxCommandEvent>::ptr this_ptr )
{
  
      // Add members from wxEvent
      WrapClass_wxEvent::ptr parent_wxEvent(        boost::dynamic_pointer_cast<WrapClass_wxEvent >(this_ptr));
      parent_wxEvent->AddMethods(parent_wxEvent);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
/* The following types are missing: void
      AddVar_SetClientData( this_ptr);
*/
      AddVar_GetClientData( this_ptr);
      AddVar_SetClientObject( this_ptr);
      AddVar_GetClientObject( this_ptr);
      AddVar_GetSelection( this_ptr);
      AddVar_SetString( this_ptr);
      AddVar_GetString( this_ptr);
      AddVar_IsChecked( this_ptr);
      AddVar_IsSelection( this_ptr);
      AddVar_SetExtraLong( this_ptr);
      AddVar_GetExtraLong( this_ptr);
      AddVar_SetInt( this_ptr);
      AddVar_GetInt( this_ptr);
      AddVar_Clone( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      /* type not available
      // Adding public member m_commandString
      boost::shared_ptr<wxCommandEventStringHelper > var_m_commandString_ptr(&GetObj()->m_commandString, smartpointer_nodeleter<wxCommandEventStringHelper >());
      BasicVariable::ptr var_m_commandString = AMILabType<wxCommandEventStringHelper >::CreateVarFromSmtPtr(var_m_commandString_ptr);
      if (var_m_commandString.get()) {
        var_m_commandString->Rename("m_commandString");
        context->AddVar(var_m_commandString,context);
      }
      */
      
      // Adding public member m_cmdString
      boost::shared_ptr<wxString > var_m_cmdString_ptr(&GetObj()->m_cmdString, smartpointer_nodeleter<wxString >());
      BasicVariable::ptr var_m_cmdString = AMILabType<wxString >::CreateVarFromSmtPtr(var_m_cmdString_ptr);
      if (var_m_cmdString.get()) {
        var_m_cmdString->Rename("m_cmdString");
        context->AddVar(var_m_cmdString,context);
      }
      
      // Adding public member m_commandInt
      boost::shared_ptr<int > var_m_commandInt_ptr(&GetObj()->m_commandInt, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_m_commandInt = AMILabType<int >::CreateVarFromSmtPtr(var_m_commandInt_ptr);
      if (var_m_commandInt.get()) {
        var_m_commandInt->Rename("m_commandInt");
        context->AddVar(var_m_commandInt,context);
      }
      
      // Adding public member m_extraLong
      boost::shared_ptr<long int > var_m_extraLong_ptr(&GetObj()->m_extraLong, smartpointer_nodeleter<long int >());
      BasicVariable::ptr var_m_extraLong = AMILabType<long int >::CreateVarFromSmtPtr(var_m_extraLong_ptr);
      if (var_m_extraLong.get()) {
        var_m_extraLong->Rename("m_extraLong");
        context->AddVar(var_m_extraLong,context);
      }
      
      /* Cannot wrap void* 
      // Adding public member m_clientData
      boost::shared_ptr<void > var_m_clientData_ptr(GetObj()->m_clientData, smartpointer_nodeleter<void >());
      BasicVariable::ptr var_m_clientData = AMILabType<void >::CreateVarFromSmtPtr(var_m_clientData_ptr);
      if (var_m_clientData.get()) {
        var_m_clientData->Rename("m_clientData");
        context->AddVar(var_m_clientData,context);
      }
      */
      
      // Adding public member m_clientObject
      boost::shared_ptr<wxClientData > var_m_clientObject_ptr(GetObj()->m_clientObject, smartpointer_nodeleter<wxClientData >());
      BasicVariable::ptr var_m_clientObject = AMILabType<wxClientData >::CreateVarFromSmtPtr(var_m_clientObject_ptr);
      if (var_m_clientObject.get()) {
        var_m_clientObject->Rename("m_clientObject");
        context->AddVar(var_m_clientObject,context);
      }

};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxCommandEvent::wxCommandEvent(wxEventType commandType = wxEVT_NULL, int winid = 0)
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_wxCommandEvent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'commandType' (def:wxEVT_NULL)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_wxCommandEvent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int commandType = wxEVT_NULL;
  if (!get_val_param<int >(commandType,_p,_n)) ClassReturnEmptyVar;

  int winid = 0;
  if (!get_val_param<int >(winid,_p,_n)) ClassReturnEmptyVar;

  wxCommandEvent* _newobj = new wxCommandEvent(commandType, winid);
  BasicVariable::ptr res = WrapClass_wxCommandEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxCommandEvent::wxCommandEvent(...)
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_wxCommandEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_wxCommandEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxCommandEvent::wrap_wxCommandEvent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxCommandEvent::wrap_wxCommandEvent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxCommandEvent::wxCommandEvent(wxCommandEvent const & event)
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_wxCommandEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCommandEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_wxCommandEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCommandEvent > event_smtptr;
  if (!get_val_smtptr_param<wxCommandEvent >(event_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxCommandEvent const & event = *event_smtptr;

  wxCommandEvent* _newobj = new wxCommandEvent(event);
  BasicVariable::ptr res = WrapClass_wxCommandEvent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxCommandEvent.
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxCommandEvent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxCommandEvent >::CreateVar( new wxCommandEvent(*(this->_objectptr->GetObj())));
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of void wxCommandEvent::SetClientData(void * clientData)
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_SetClientData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'clientData'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_SetClientData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<void > clientData_smtptr;
  if (!get_val_smtptr_param<void >(clientData_smtptr,_p,_n)) ClassHelpAndReturn;
  void* clientData = clientData_smtptr.get();

  this->_objectptr->GetObj()->SetClientData(clientData);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void * wxCommandEvent::GetClientData()
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_GetClientData::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_GetClientData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GetClientData();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxCommandEvent::SetClientObject(wxClientData * clientObject)
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_SetClientObject::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxClientData, "parameter named 'clientObject'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_SetClientObject::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxClientData > clientObject_smtptr;
  if (!get_val_smtptr_param<wxClientData >(clientObject_smtptr,_p,_n)) ClassHelpAndReturn;
  wxClientData* clientObject = clientObject_smtptr.get();

  this->_objectptr->GetObj()->SetClientObject(clientObject);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClientData * wxCommandEvent::GetClientObject()
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_GetClientObject::SetParametersComments()
{
  return_comments="returning a variable of type wxClientData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_GetClientObject::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClientData * res =   this->_objectptr->GetObj()->GetClientObject();
  BasicVariable::ptr res_var = WrapClass_wxClientData::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int wxCommandEvent::GetSelection()
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_GetSelection::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_GetSelection::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetSelection();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxCommandEvent::SetString(wxString const & s)
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_SetString::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_SetString::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > s_smtptr;
  if (!get_val_smtptr_param<wxString >(s_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & s = *s_smtptr;

  this->_objectptr->GetObj()->SetString(s);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxCommandEvent::GetString()
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_GetString::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_GetString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetString();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxCommandEvent::IsChecked()
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_IsChecked::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_IsChecked::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsChecked();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxCommandEvent::IsSelection()
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_IsSelection::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_IsSelection::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsSelection();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxCommandEvent::SetExtraLong(long int extraLong)
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_SetExtraLong::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'extraLong'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_SetExtraLong::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long extraLong_long;
  if (!get_val_param<long >(extraLong_long,_p,_n)) ClassHelpAndReturn;
  long int extraLong = extraLong_long;

  this->_objectptr->GetObj()->SetExtraLong(extraLong);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long int wxCommandEvent::GetExtraLong()
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_GetExtraLong::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_GetExtraLong::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   this->_objectptr->GetObj()->GetExtraLong();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxCommandEvent::SetInt(int i)
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_SetInt::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_SetInt::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int i;
  if (!get_val_param<int >(i,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInt(i);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxCommandEvent::GetInt()
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_GetInt::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_GetInt::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetInt();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxEvent * wxCommandEvent::Clone()
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvent * res =   this->_objectptr->GetObj()->Clone();
  BasicVariable::ptr res_var = WrapClass_wxEvent::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxCommandEvent::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxCommandEvent::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCommandEvent::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

