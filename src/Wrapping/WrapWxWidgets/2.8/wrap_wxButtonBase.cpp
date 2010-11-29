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

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxSize.h"
#include "wrap_wxBitmap.h"


#include "wrap_wxButtonBase.h"

//----------------------------------------------------------------------
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
AMI_DEFINE_VARFROMSMTPTR(wxButtonBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxButtonBase>::CreateVar( wxButtonBase* val, bool nodeleter)
{ 
  boost::shared_ptr<wxButtonBase> obj_ptr(val,smartpointer_nodeleter<wxButtonBase>());
  return AMILabType<wxButtonBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
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

//----------------------------------------------------------------------
void WrapClass_wxButtonBase::AddMethods(WrapClass<wxButtonBase>::ptr this_ptr )
{
  
      // Add members from wxControl
      WrapClass_wxControl::ptr parent_wxControl(        boost::dynamic_pointer_cast<WrapClass_wxControl >(this_ptr));
      parent_wxControl->AddMethods(parent_wxControl);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_SetImageLabel( this_ptr);
      AddVar_SetImageMargins( this_ptr);
      AddVar_SetDefault( this_ptr);
      AddVar_ShouldInheritColours( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


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
//  Wrapping of wxSize wxButtonBase::GetDefaultSize()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_static_GetDefaultSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_static_GetDefaultSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   wxButtonBase::GetDefaultSize();
  return AMILabType<wxSize >::CreateVar(res);
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
  if (!get_val_smtptr_param<wxBitmap >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
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
  if (!get_val_param<int >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  int param1;
  if (!get_val_param<int >(param1,_p,_n,true,false)) ClassHelpAndReturn;

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

