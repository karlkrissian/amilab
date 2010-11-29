/**
 * C++ Interface: wrap_wxBitmapHandler
 *
 * Description: wrapping wxBitmapHandler
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
#include "wrap_wxBitmapHandler.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxBitmapHandler.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxBitmapHandler>::CreateVar( ParamList* p)
{
  WrapClass_wxBitmapHandler::wrap_wxBitmapHandler construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxBitmapHandler);
AMI_DEFINE_VARFROMSMTPTR(wxBitmapHandler);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxBitmapHandler
//
Variable<AMIObject>::ptr WrapClass_wxBitmapHandler::CreateVar( wxBitmapHandler* sp)
{
  boost::shared_ptr<wxBitmapHandler> di_ptr(
    sp,
    wxwindow_nodeleter<wxBitmapHandler>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxBitmapHandler>::CreateVar(
      new WrapClass_wxBitmapHandler(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxBitmapHandler::AddMethods(WrapClass<wxBitmapHandler>::ptr this_ptr )
{
  
      // Add members from wxBitmapHandlerBase
      WrapClass_wxBitmapHandlerBase::ptr parent_wxBitmapHandlerBase(        boost::dynamic_pointer_cast<WrapClass_wxBitmapHandlerBase >(this_ptr));
      parent_wxBitmapHandlerBase->AddMethods(parent_wxBitmapHandlerBase);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_GetClassInfo( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxBitmapHandler::wxBitmapHandler(wxBitmapHandler const & param0)
//---------------------------------------------------
void WrapClass_wxBitmapHandler::
    wrap_wxBitmapHandler_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmapHandler, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandler::
    wrap_wxBitmapHandler_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmapHandler > param0_smtptr;
  if (!get_val_smtptr_param<wxBitmapHandler >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxBitmapHandler const & param0 = *param0_smtptr;

  wxBitmapHandler* _newobj = new wxBitmapHandler(param0);
  BasicVariable::ptr res = WrapClass_wxBitmapHandler::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxBitmapHandler::wxBitmapHandler(...)
//---------------------------------------------------
void WrapClass_wxBitmapHandler::
    wrap_wxBitmapHandler::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandler::
    wrap_wxBitmapHandler::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxBitmapHandler::wrap_wxBitmapHandler_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxBitmapHandler::wrap_wxBitmapHandler_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxBitmapHandler::wxBitmapHandler()
//---------------------------------------------------
void WrapClass_wxBitmapHandler::
    wrap_wxBitmapHandler_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandler::
    wrap_wxBitmapHandler_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBitmapHandler* _newobj = new wxBitmapHandler();
  BasicVariable::ptr res = WrapClass_wxBitmapHandler::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxBitmapHandler.
//---------------------------------------------------
void WrapClass_wxBitmapHandler::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxBitmapHandler object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandler::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxBitmapHandler >::CreateVar( new wxBitmapHandler(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxBitmapHandler::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxBitmapHandler::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandler::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxBitmapHandler & wxBitmapHandler::operator =(wxBitmapHandler const & param0)
//---------------------------------------------------
void WrapClass_wxBitmapHandler::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmapHandler, "parameter named 'param0'")
  return_comments="returning a variable of type wxBitmapHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandler::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmapHandler > param0_smtptr;
  if (!get_val_smtptr_param<wxBitmapHandler >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmapHandler const & param0 = *param0_smtptr;

  wxBitmapHandler & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxBitmapHandler >::CreateVar(res);
}

