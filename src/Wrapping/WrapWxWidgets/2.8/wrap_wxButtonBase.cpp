/**
 * C++ Interface: wrap_wxButtonBase
 *
 * Description: wrapping wxButtonBase
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_wxButtonBase.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxBitmap.h"
#include "wrap_wxSize.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxButtonBase>::CreateVar( ParamList* p)
{
  WrapClass_wxButtonBase::wrap_wxButtonBase construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxButtonBase);


//
// static member for creating a variable from a pointer to wxButtonBase
//
Variable<AMIObject>::ptr WrapClass_wxButtonBase::CreateVar( wxButtonBase* sp)
{
  boost::shared_ptr<wxButtonBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxButtonBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxButtonBase>::CreateVar(
      new WrapClass_wxButtonBase(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor wxButtonBase::wxButtonBase()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_wxButtonBase::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_wxButtonBase::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxButtonBase* _newobj = new wxButtonBase();
  BasicVariable::ptr res = WrapClass_wxButtonBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxButtonBase::SetImageLabel(wxBitmap const & param0)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetImageLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetImageLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > param0_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap const & param0 = *param0_smtptr;

  this->_objectptr->GetObj()->SetImageLabel(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxButtonBase::SetImageMargins(wxCoord param0, wxCoord param1)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetImageMargins::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetImageMargins::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n)) ClassHelpAndReturn;

  int param1;
  if (!get_val_param<int >(param1,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetImageMargins(param0, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxButtonBase::SetDefault()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetDefault::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetDefault::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDefault();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxButtonBase::ShouldInheritColours()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_ShouldInheritColours::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_ShouldInheritColours::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ShouldInheritColours();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxSize wxButtonBase::GetDefaultSize()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_GetDefaultSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_GetDefaultSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetDefaultSize();
  return AMILabType<wxSize >::CreateVar(res);
}

