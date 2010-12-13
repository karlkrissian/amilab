/**
 * C++ Interface: wrap_wxHtmlRenderingState
 *
 * Description: wrapping wxHtmlRenderingState
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

#include "wrap_wxHtmlRenderingState.h"

// get all the required includes
// #include "..."
#ifndef wxHtmlRenderingState_declared
  #define wxHtmlRenderingState_declared
  AMI_DECLARE_TYPE(wxHtmlRenderingState)
#endif
#ifndef wxColour_declared
  #define wxColour_declared
  AMI_DECLARE_TYPE(wxColour)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHtmlRenderingState>::CreateVar( ParamList* p)
{
  WrapClass_wxHtmlRenderingState::wrap_wxHtmlRenderingState construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxHtmlRenderingState);
AMI_DEFINE_VARFROMSMTPTR(wxHtmlRenderingState);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHtmlRenderingState
//
Variable<AMIObject>::ptr WrapClass_wxHtmlRenderingState::CreateVar( wxHtmlRenderingState* sp)
{
  boost::shared_ptr<wxHtmlRenderingState> di_ptr(
    sp,
    wxwindow_nodeleter<wxHtmlRenderingState>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHtmlRenderingState>::CreateVar(
      new WrapClass_wxHtmlRenderingState(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHtmlRenderingState::AddMethods(WrapClass<wxHtmlRenderingState>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_SetSelectionState( this_ptr);
  AddVar_GetSelectionState( this_ptr);
  AddVar_SetFgColour( this_ptr);
  AddVar_GetFgColour( this_ptr);
  AddVar_SetBgColour( this_ptr);
  AddVar_GetBgColour( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlRenderingState_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxHtmlRenderingState");
    WrapClass_wxHtmlRenderingState::AddVar_wxHtmlRenderingState_1(amiobject->GetContext());
  WrapClass_wxHtmlRenderingState::AddVar_wxHtmlRenderingState(amiobject->GetContext());
  WrapClass_wxHtmlRenderingState::AddVar_wxHtmlRenderingState_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxHtmlRenderingState::wxHtmlRenderingState(wxHtmlRenderingState const & param0)
//---------------------------------------------------
void WrapClass_wxHtmlRenderingState::
    wrap_wxHtmlRenderingState_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlRenderingState, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingState::
    wrap_wxHtmlRenderingState_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxHtmlRenderingState > param0_smtptr;
  if (!get_val_smtptr_param<wxHtmlRenderingState >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxHtmlRenderingState const & param0 = *param0_smtptr;

  wxHtmlRenderingState* _newobj = new wxHtmlRenderingState(param0);
  BasicVariable::ptr res = WrapClass_wxHtmlRenderingState::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxHtmlRenderingState::wxHtmlRenderingState(...)
//---------------------------------------------------
void WrapClass_wxHtmlRenderingState::
    wrap_wxHtmlRenderingState::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingState::
    wrap_wxHtmlRenderingState::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxHtmlRenderingState::wrap_wxHtmlRenderingState_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxHtmlRenderingState::wrap_wxHtmlRenderingState_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxHtmlRenderingState::wxHtmlRenderingState()
//---------------------------------------------------
void WrapClass_wxHtmlRenderingState::
    wrap_wxHtmlRenderingState_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingState::
    wrap_wxHtmlRenderingState_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxHtmlRenderingState* _newobj = new wxHtmlRenderingState();
  BasicVariable::ptr res = WrapClass_wxHtmlRenderingState::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxHtmlRenderingState.
//---------------------------------------------------
void WrapClass_wxHtmlRenderingState::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxHtmlRenderingState object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingState::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxHtmlRenderingState >::CreateVar( new wxHtmlRenderingState(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxHtmlRenderingState::SetSelectionState(wxHtmlSelectionState s)
//---------------------------------------------------
void WrapClass_wxHtmlRenderingState::
    wrap_SetSelectionState::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingState::
    wrap_SetSelectionState::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int s_int;
  if (!get_val_param<int >(s_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxHtmlSelectionState s = (wxHtmlSelectionState) s_int;

  this->_objectptr->GetObj()->SetSelectionState(s);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlSelectionState wxHtmlRenderingState::GetSelectionState()
//---------------------------------------------------
void WrapClass_wxHtmlRenderingState::
    wrap_GetSelectionState::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingState::
    wrap_GetSelectionState::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlSelectionState res =   this->_objectptr->GetObj()->GetSelectionState();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlRenderingState::SetFgColour(wxColour const & c)
//---------------------------------------------------
void WrapClass_wxHtmlRenderingState::
    wrap_SetFgColour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingState::
    wrap_SetFgColour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > c_smtptr;
  if (!get_val_smtptr_param<wxColour >(c_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour const & c = *c_smtptr;

  this->_objectptr->GetObj()->SetFgColour(c);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxColour const & wxHtmlRenderingState::GetFgColour()
//---------------------------------------------------
void WrapClass_wxHtmlRenderingState::
    wrap_GetFgColour::SetParametersComments()
{
  return_comments="returning a variable of type wxColour";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingState::
    wrap_GetFgColour::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxColour const & res =   this->_objectptr->GetObj()->GetFgColour();
  return AMILabType<wxColour >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlRenderingState::SetBgColour(wxColour const & c)
//---------------------------------------------------
void WrapClass_wxHtmlRenderingState::
    wrap_SetBgColour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingState::
    wrap_SetBgColour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > c_smtptr;
  if (!get_val_smtptr_param<wxColour >(c_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour const & c = *c_smtptr;

  this->_objectptr->GetObj()->SetBgColour(c);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxColour const & wxHtmlRenderingState::GetBgColour()
//---------------------------------------------------
void WrapClass_wxHtmlRenderingState::
    wrap_GetBgColour::SetParametersComments()
{
  return_comments="returning a variable of type wxColour";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingState::
    wrap_GetBgColour::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxColour const & res =   this->_objectptr->GetObj()->GetBgColour();
  return AMILabType<wxColour >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxHtmlRenderingState & wxHtmlRenderingState::operator =(wxHtmlRenderingState const & param0)
//---------------------------------------------------
void WrapClass_wxHtmlRenderingState::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlRenderingState, "parameter named 'param0'")
  return_comments="returning a variable of type wxHtmlRenderingState";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingState::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlRenderingState > param0_smtptr;
  if (!get_val_smtptr_param<wxHtmlRenderingState >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlRenderingState const & param0 = *param0_smtptr;

  wxHtmlRenderingState & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxHtmlRenderingState >::CreateVar(res);
}

