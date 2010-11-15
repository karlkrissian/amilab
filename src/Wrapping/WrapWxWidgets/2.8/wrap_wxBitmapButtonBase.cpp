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
#include "wrap_wxBitmap.h"
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
      AddVar_SetBitmapLabel( this_ptr);
      AddVar_SetBitmapSelected( this_ptr);
      AddVar_SetBitmapFocus( this_ptr);
      AddVar_SetBitmapDisabled( this_ptr);
      AddVar_SetBitmapHover( this_ptr);
      AddVar_GetBitmapLabel_1( this_ptr);
      AddVar_GetBitmapSelected_1( this_ptr);
      AddVar_GetBitmapFocus_1( this_ptr);
      AddVar_GetBitmapDisabled_1( this_ptr);
      AddVar_GetBitmapHover_1( this_ptr);
      AddVar_GetBitmapLabel( this_ptr);
      AddVar_GetBitmapLabel_2( this_ptr);
      AddVar_GetBitmapSelected( this_ptr);
      AddVar_GetBitmapSelected_2( this_ptr);
      AddVar_GetBitmapFocus( this_ptr);
      AddVar_GetBitmapFocus_2( this_ptr);
      AddVar_GetBitmapDisabled( this_ptr);
      AddVar_GetBitmapDisabled_2( this_ptr);
      AddVar_GetBitmapHover( this_ptr);
      AddVar_GetBitmapHover_2( this_ptr);
      AddVar_SetMargins( this_ptr);
      AddVar_GetMarginX( this_ptr);
      AddVar_GetMarginY( this_ptr);
      AddVar_SetLabel_1( this_ptr);
      AddVar_SetLabel( this_ptr);
      AddVar_SetLabel_2( this_ptr);



  
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

//---------------------------------------------------
//  Wrapping of void wxBitmapButtonBase::SetBitmapLabel(wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_SetBitmapLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_SetBitmapLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  this->_objectptr->GetObj()->SetBitmapLabel(bitmap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBitmapButtonBase::SetBitmapSelected(wxBitmap const & sel)
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_SetBitmapSelected::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'sel'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_SetBitmapSelected::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > sel_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(sel_smtptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap const & sel = *sel_smtptr;

  this->_objectptr->GetObj()->SetBitmapSelected(sel);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBitmapButtonBase::SetBitmapFocus(wxBitmap const & focus)
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_SetBitmapFocus::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'focus'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_SetBitmapFocus::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > focus_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(focus_smtptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap const & focus = *focus_smtptr;

  this->_objectptr->GetObj()->SetBitmapFocus(focus);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBitmapButtonBase::SetBitmapDisabled(wxBitmap const & disabled)
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_SetBitmapDisabled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'disabled'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_SetBitmapDisabled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > disabled_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(disabled_smtptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap const & disabled = *disabled_smtptr;

  this->_objectptr->GetObj()->SetBitmapDisabled(disabled);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBitmapButtonBase::SetBitmapHover(wxBitmap const & hover)
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_SetBitmapHover::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'hover'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_SetBitmapHover::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > hover_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(hover_smtptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap const & hover = *hover_smtptr;

  this->_objectptr->GetObj()->SetBitmapHover(hover);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxBitmap const & wxBitmapButtonBase::GetBitmapLabel()
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapLabel_1::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapLabel_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBitmap const & res =   this->_objectptr->GetObj()->GetBitmapLabel();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap const & wxBitmapButtonBase::GetBitmapSelected()
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapSelected_1::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapSelected_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBitmap const & res =   this->_objectptr->GetObj()->GetBitmapSelected();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap const & wxBitmapButtonBase::GetBitmapFocus()
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapFocus_1::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapFocus_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBitmap const & res =   this->_objectptr->GetObj()->GetBitmapFocus();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap const & wxBitmapButtonBase::GetBitmapDisabled()
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapDisabled_1::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapDisabled_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBitmap const & res =   this->_objectptr->GetObj()->GetBitmapDisabled();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap const & wxBitmapButtonBase::GetBitmapHover()
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapHover_1::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapHover_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBitmap const & res =   this->_objectptr->GetObj()->GetBitmapHover();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxBitmapButtonBase::GetBitmapLabel(...)
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapLabel::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapLabel::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxBitmapButtonBase::wrap_GetBitmapLabel_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxBitmapButtonBase::wrap_GetBitmapLabel_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxBitmap & wxBitmapButtonBase::GetBitmapLabel()
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapLabel_2::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapLabel_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBitmap & res =   this->_objectptr->GetObj()->GetBitmapLabel();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxBitmapButtonBase::GetBitmapSelected(...)
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapSelected::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapSelected::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxBitmapButtonBase::wrap_GetBitmapSelected_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxBitmapButtonBase::wrap_GetBitmapSelected_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxBitmap & wxBitmapButtonBase::GetBitmapSelected()
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapSelected_2::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapSelected_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBitmap & res =   this->_objectptr->GetObj()->GetBitmapSelected();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxBitmapButtonBase::GetBitmapFocus(...)
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapFocus::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapFocus::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxBitmapButtonBase::wrap_GetBitmapFocus_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxBitmapButtonBase::wrap_GetBitmapFocus_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxBitmap & wxBitmapButtonBase::GetBitmapFocus()
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapFocus_2::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapFocus_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBitmap & res =   this->_objectptr->GetObj()->GetBitmapFocus();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxBitmapButtonBase::GetBitmapDisabled(...)
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapDisabled::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapDisabled::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxBitmapButtonBase::wrap_GetBitmapDisabled_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxBitmapButtonBase::wrap_GetBitmapDisabled_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxBitmap & wxBitmapButtonBase::GetBitmapDisabled()
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapDisabled_2::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapDisabled_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBitmap & res =   this->_objectptr->GetObj()->GetBitmapDisabled();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxBitmapButtonBase::GetBitmapHover(...)
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapHover::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapHover::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxBitmapButtonBase::wrap_GetBitmapHover_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxBitmapButtonBase::wrap_GetBitmapHover_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxBitmap & wxBitmapButtonBase::GetBitmapHover()
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapHover_2::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_GetBitmapHover_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBitmap & res =   this->_objectptr->GetObj()->GetBitmapHover();
  return AMILabType<wxBitmap >::CreateVar(res);
}

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

//---------------------------------------------------
//  Wrapping of void wxBitmapButtonBase::SetLabel(wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_SetLabel_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_SetLabel_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  this->_objectptr->GetObj()->SetLabel(bitmap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxBitmapButtonBase::SetLabel(...)
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_SetLabel::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_SetLabel::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxBitmapButtonBase::wrap_SetLabel_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxBitmapButtonBase::wrap_SetLabel_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxBitmapButtonBase::SetLabel(wxString const & label)
//---------------------------------------------------
void WrapClass_wxBitmapButtonBase::
    wrap_SetLabel_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButtonBase::
    wrap_SetLabel_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & label = *label_smtptr;

  this->_objectptr->GetObj()->SetLabel(label);
  return BasicVariable::ptr();
}

