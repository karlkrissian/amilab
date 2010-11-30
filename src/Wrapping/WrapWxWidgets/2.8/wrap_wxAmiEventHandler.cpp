/**
 * C++ Interface: wrap_wxAmiEventHandler
 *
 * Description: wrapping wxAmiEventHandler
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
#include "wrap_wxString.h"
#include "wrap_wxCommandEvent.h"
#include "wrap_wxObjectEventFunction.h"


#include "wrap_wxAmiEventHandler.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAmiEventHandler>::CreateVar( ParamList* p)
{
  WrapClass_wxAmiEventHandler::wrap_wxAmiEventHandler construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxAmiEventHandler);
AMI_DEFINE_VARFROMSMTPTR(wxAmiEventHandler);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxAmiEventHandler>::CreateVar( wxAmiEventHandler* val, bool nodeleter)
{ 
  boost::shared_ptr<wxAmiEventHandler> obj_ptr(val,smartpointer_nodeleter<wxAmiEventHandler>());
  return AMILabType<wxAmiEventHandler>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxAmiEventHandler
//
Variable<AMIObject>::ptr WrapClass_wxAmiEventHandler::CreateVar( wxAmiEventHandler* sp)
{
  boost::shared_ptr<wxAmiEventHandler> di_ptr(
    sp,
    wxwindow_nodeleter<wxAmiEventHandler>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAmiEventHandler>::CreateVar(
      new WrapClass_wxAmiEventHandler(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxAmiEventHandler::AddMethods(WrapClass<wxAmiEventHandler>::ptr this_ptr )
{
  
      // Add members from wxEvtHandler
      WrapClass_wxEvtHandler::ptr parent_wxEvtHandler(        boost::dynamic_pointer_cast<WrapClass_wxEvtHandler >(this_ptr));
      parent_wxEvtHandler->AddMethods(parent_wxEvtHandler);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_OnTest( this_ptr);
      AddVar_GetEventFunction( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxAmiEventHandler::wxAmiEventHandler(wxString t)
//---------------------------------------------------
void WrapClass_wxAmiEventHandler::
    wrap_wxAmiEventHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 't'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAmiEventHandler::
    wrap_wxAmiEventHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxString t;
  if (!get_val_param<wxString >(t,_p,_n,true,false)) ClassHelpAndReturn;

  wxAmiEventHandler* _newobj = new wxAmiEventHandler(t);
  BasicVariable::ptr res = WrapClass_wxAmiEventHandler::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxAmiEventHandler::OnTest(wxCommandEvent & event)
//---------------------------------------------------
void WrapClass_wxAmiEventHandler::
    wrap_OnTest::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCommandEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAmiEventHandler::
    wrap_OnTest::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxCommandEvent > event_smtptr;
  if (!get_val_smtptr_param<wxCommandEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxCommandEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnTest(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxObjectEventFunction wxAmiEventHandler::GetEventFunction()
//---------------------------------------------------
void WrapClass_wxAmiEventHandler::
    wrap_GetEventFunction::SetParametersComments()
{
  return_comments="returning a variable of type wxObjectEventFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAmiEventHandler::
    wrap_GetEventFunction::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxObjectEventFunction res =   this->_objectptr->GetObj()->GetEventFunction();
  return AMILabType<wxObjectEventFunction >::CreateVar(res);
}

