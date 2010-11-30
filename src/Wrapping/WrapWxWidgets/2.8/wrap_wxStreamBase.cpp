/**
 * C++ Interface: wrap_wxStreamBase
 *
 * Description: wrapping wxStreamBase
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
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_wxStreamBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxStreamBase>::CreateVar( ParamList* p)
{
  WrapClass_wxStreamBase::wrap_wxStreamBase construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxStreamBase);
AMI_DEFINE_VARFROMSMTPTR(wxStreamBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxStreamBase>::CreateVar( wxStreamBase* val, bool nodeleter)
{ 
  boost::shared_ptr<wxStreamBase> obj_ptr(val,smartpointer_nodeleter<wxStreamBase>());
  return AMILabType<wxStreamBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxStreamBase
//
Variable<AMIObject>::ptr WrapClass_wxStreamBase::CreateVar( wxStreamBase* sp)
{
  boost::shared_ptr<wxStreamBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxStreamBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxStreamBase>::CreateVar(
      new WrapClass_wxStreamBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxStreamBase::AddMethods(WrapClass<wxStreamBase>::ptr this_ptr )
{
  


  // check that the method name is not a token
  
      // Adding standard methods 
/* The following types are missing: wxStreamError
      AddVar_GetLastError( this_ptr);
*/
      AddVar_IsOk( this_ptr);
      AddVar_Reset( this_ptr);
      AddVar_GetSize( this_ptr);
      AddVar_GetLength( this_ptr);
      AddVar_IsSeekable( this_ptr);

      // Adding operators
      // AddVar_operator not available( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxStreamBase::wxStreamBase()
//---------------------------------------------------
void WrapClass_wxStreamBase::
    wrap_wxStreamBase::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStreamBase::
    wrap_wxStreamBase::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxStreamBase* _newobj = new wxStreamBase();
  BasicVariable::ptr res = WrapClass_wxStreamBase::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxStreamError

//---------------------------------------------------
//  Wrapping of wxStreamError wxStreamBase::GetLastError()
//---------------------------------------------------
void WrapClass_wxStreamBase::
    wrap_GetLastError::SetParametersComments()
{
  return_comments="returning a variable of type wxStreamError";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStreamBase::
    wrap_GetLastError::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxStreamError res =   this->_objectptr->GetObj()->GetLastError();
  return AMILabType<wxStreamError >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxStreamBase::IsOk()
//---------------------------------------------------
void WrapClass_wxStreamBase::
    wrap_IsOk::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStreamBase::
    wrap_IsOk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOk();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxStreamBase::Reset()
//---------------------------------------------------
void WrapClass_wxStreamBase::
    wrap_Reset::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStreamBase::
    wrap_Reset::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Reset();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of size_t wxStreamBase::GetSize()
//---------------------------------------------------
void WrapClass_wxStreamBase::
    wrap_GetSize::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStreamBase::
    wrap_GetSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->GetSize();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxFileOffset wxStreamBase::GetLength()
//---------------------------------------------------
void WrapClass_wxStreamBase::
    wrap_GetLength::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStreamBase::
    wrap_GetLength::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxFileOffset res =   this->_objectptr->GetObj()->GetLength();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxStreamBase::IsSeekable()
//---------------------------------------------------
void WrapClass_wxStreamBase::
    wrap_IsSeekable::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStreamBase::
    wrap_IsSeekable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsSeekable();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxStreamBase::!()
//---------------------------------------------------
void WrapClass_wxStreamBase::
    wrap_operator not available::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStreamBase::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->!();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/

