/**
 * C++ Interface: wrap_wxBitmapButtonBase
 *
 * Description: wrapping wxBitmapButtonBase
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
#include "wrap_wxWindow.h"
#include "wrap_wxPoint.h"
#include "wrap_wxSize.h"
#include "wrap_wxString.h"


#include "wrap_wxBitmapButtonBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxBitmapButtonBase>::CreateVar( ParamList* p)
{
  WrapClass_wxBitmapButtonBase::wrap_wxBitmapButtonBase construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxBitmapButtonBase);
AMI_DEFINE_VARFROMSMTPTR(wxBitmapButtonBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxBitmapButtonBase>::CreateVar( wxBitmapButtonBase* val)
{ 
  boost::shared_ptr<wxBitmapButtonBase> obj_ptr(val,wxwindow_nodeleter<wxBitmapButtonBase>());
  return AMILabType<wxBitmapButtonBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxBitmapButtonBase
//
Variable<AMIObject>::ptr WrapClass_wxBitmapButtonBase::CreateVar( wxBitmapButtonBase* sp)
{
  boost::shared_ptr<wxBitmapButtonBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxBitmapButtonBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxBitmapButtonBase>::CreateVar(
      new WrapClass_wxBitmapButtonBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxBitmapButtonBase::AddMethods(WrapClass<wxBitmapButtonBase>::ptr this_ptr )
{
  
      // Add members from wxButton
      WrapClass_wxButton::ptr parent_wxButton(        boost::dynamic_pointer_cast<WrapClass_wxButton >(this_ptr));
      parent_wxButton->AddMethods(parent_wxButton);


  // check that the method name is not a token
  
      // Adding standard methods 
/* The following types are missing: wxValidator
      AddVar_Create( this_ptr);
*/
      AddVar_SetMargins( this_ptr);
      AddVar_GetMarginX( this_ptr);
      AddVar_GetMarginY( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxBitmapButtonBase::wxBitmapButtonBase()
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_wxBitmapButtonBase::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_wxBitmapButtonBase::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmapButtonBase* _newobj = new wxBitmapButtonBase();
  BasicVariable::ptr res = WrapClass_wxBitmapButtonBase::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxValidator

//---------------------------------------------------
//  Wrapping of bool wxBitmapButtonBase::Create(wxWindow * parent, wxWindowID winid, wxPoint const & pos, wxSize const & size, long int style, wxValidator const & validator, wxString const & name)
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
  ADDPARAMCOMMENT_TYPE( wxValidator, "parameter named 'validator'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();

  int winid;
  if (!get_val_param<int >(winid,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n)) ClassHelpAndReturn;
  wxPoint const & pos = *pos_smtptr;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize const & size = *size_smtptr;

  long style_long;
  if (!get_val_param<long >(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxValidator > validator_smtptr;
  if (!get_val_smtptr_param<wxValidator >(validator_smtptr,_p,_n)) ClassHelpAndReturn;
  wxValidator const & validator = *validator_smtptr;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  bool res =   this->_objectptr->GetObj()->Create(parent, winid, pos, size, style, validator, name);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of void wxBitmapButtonBase::SetMargins(int x, int y)
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_SetMargins::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_SetMargins::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMargins(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxBitmapButtonBase::GetMarginX()
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetMarginX::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetMarginX::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMarginX();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxBitmapButtonBase::GetMarginY()
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetMarginY::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetMarginY::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMarginY();
  return AMILabType<int >::CreateVar(res);
}

