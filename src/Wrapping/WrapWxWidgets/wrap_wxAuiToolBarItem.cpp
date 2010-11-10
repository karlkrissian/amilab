/**
 * C++ Interface: wrap_wxAuiToolBarItem
 *
 * Description: wrapping wxAuiToolBarItem
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_wxAuiToolBarItem.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxAuiToolBarItem.h"
#include "wrap_wxWindow.h"
#include "wrap_wxString.h"
#include "wrap_wxBitmap.h"
#include "wrap_wxSize.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAuiToolBarItem>::CreateVar( ParamList* p)
{
  WrapClass_wxAuiToolBarItem::wrap_wxAuiToolBarItem construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxAuiToolBarItem);

//
// static member for creating a variable from a pointer to wxAuiToolBarItem
//
Variable<AMIObject>::ptr WrapClass_wxAuiToolBarItem::CreateVar( wxAuiToolBarItem* sp)
{
  boost::shared_ptr<wxAuiToolBarItem> di_ptr(
    sp,
    wxwindow_nodeleter<wxAuiToolBarItem>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAuiToolBarItem>::CreateVar(
      new WrapClass_wxAuiToolBarItem(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor wxAuiToolBarItem::wxAuiToolBarItem()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_wxAuiToolBarItem::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_wxAuiToolBarItem::CallMember( ParamList* _p)
{
  wxAuiToolBarItem* _newobj = new wxAuiToolBarItem();
  BasicVariable::ptr res = WrapClass_wxAuiToolBarItem::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxAuiToolBarItem::wxAuiToolBarItem(wxAuiToolBarItem const & c)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_wxAuiToolBarItem1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_wxAuiToolBarItem1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxAuiToolBarItem* c_ptr;
  if (!get_val_ptr_param<wxAuiToolBarItem>(c_ptr,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItem& c = *c_ptr;
  wxAuiToolBarItem* _newobj = new wxAuiToolBarItem(c);
  BasicVariable::ptr res = WrapClass_wxAuiToolBarItem::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::Assign(wxAuiToolBarItem const & c)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_Assign::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_Assign::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxAuiToolBarItem* c_ptr;
  if (!get_val_ptr_param<wxAuiToolBarItem>(c_ptr,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItem& c = *c_ptr;
  this->_objectptr->GetObj()->Assign(c);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetWindow(wxWindow * w)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'w'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxWindow* w;
  if (!get_val_ptr_param<wxWindow>(w,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetWindow(w);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxAuiToolBarItem::GetWindow()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_GetWindow::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_GetWindow::CallMember( ParamList* _p)
{
  wxWindow * res =   this->_objectptr->GetObj()->GetWindow();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetId(int new_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'new_id'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int new_id;
  if (!get_val_param<int>(new_id,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetId(new_id);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBarItem::GetId()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_GetId::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_GetId::CallMember( ParamList* _p)
{
  int res =   this->_objectptr->GetObj()->GetId();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetKind(int new_kind)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetKind::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'new_kind'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetKind::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int new_kind;
  if (!get_val_param<int>(new_kind,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetKind(new_kind);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBarItem::GetKind()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_GetKind::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_GetKind::CallMember( ParamList* _p)
{
  int res =   this->_objectptr->GetObj()->GetKind();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetState(int new_state)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetState::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'new_state'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetState::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int new_state;
  if (!get_val_param<int>(new_state,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetState(new_state);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBarItem::GetState()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_GetState::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_GetState::CallMember( ParamList* _p)
{
  int res =   this->_objectptr->GetObj()->GetState();
  return AMILabType<int>::CreateVar(res);
}
/* The following types are missing: wxSizerItem

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetSizerItem(wxSizerItem * s)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetSizerItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetSizerItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxSizerItem* s;
  if (!get_val_ptr_param<wxSizerItem>(s,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetSizerItem(s);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxSizerItem

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxAuiToolBarItem::GetSizerItem()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_GetSizerItem::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_GetSizerItem::CallMember( ParamList* _p)
{
  wxSizerItem * res =   this->_objectptr->GetObj()->GetSizerItem();
  return AMILabType<wxSizerItem>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetLabel(wxString const & s)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxString* s_ptr;
  if (!get_val_ptr_param<wxString>(s_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& s = *s_ptr;
  this->_objectptr->GetObj()->SetLabel(s);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString const & wxAuiToolBarItem::GetLabel()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_GetLabel::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_GetLabel::CallMember( ParamList* _p)
{
  wxString const & res =   this->_objectptr->GetObj()->GetLabel();
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetBitmap(wxBitmap const & bmp)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxBitmap* bmp_ptr;
  if (!get_val_ptr_param<wxBitmap>(bmp_ptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap& bmp = *bmp_ptr;
  this->_objectptr->GetObj()->SetBitmap(bmp);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxBitmap const & wxAuiToolBarItem::GetBitmap()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_GetBitmap::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_GetBitmap::CallMember( ParamList* _p)
{
  wxBitmap const & res =   this->_objectptr->GetObj()->GetBitmap();
  return AMILabType<wxBitmap>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetDisabledBitmap(wxBitmap const & bmp)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetDisabledBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetDisabledBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxBitmap* bmp_ptr;
  if (!get_val_ptr_param<wxBitmap>(bmp_ptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap& bmp = *bmp_ptr;
  this->_objectptr->GetObj()->SetDisabledBitmap(bmp);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxBitmap const & wxAuiToolBarItem::GetDisabledBitmap()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_GetDisabledBitmap::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_GetDisabledBitmap::CallMember( ParamList* _p)
{
  wxBitmap const & res =   this->_objectptr->GetObj()->GetDisabledBitmap();
  return AMILabType<wxBitmap>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetHoverBitmap(wxBitmap const & bmp)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetHoverBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetHoverBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxBitmap* bmp_ptr;
  if (!get_val_ptr_param<wxBitmap>(bmp_ptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap& bmp = *bmp_ptr;
  this->_objectptr->GetObj()->SetHoverBitmap(bmp);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxBitmap const & wxAuiToolBarItem::GetHoverBitmap()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_GetHoverBitmap::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_GetHoverBitmap::CallMember( ParamList* _p)
{
  wxBitmap const & res =   this->_objectptr->GetObj()->GetHoverBitmap();
  return AMILabType<wxBitmap>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetShortHelp(wxString const & s)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetShortHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetShortHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxString* s_ptr;
  if (!get_val_ptr_param<wxString>(s_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& s = *s_ptr;
  this->_objectptr->GetObj()->SetShortHelp(s);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString const & wxAuiToolBarItem::GetShortHelp()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_GetShortHelp::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_GetShortHelp::CallMember( ParamList* _p)
{
  wxString const & res =   this->_objectptr->GetObj()->GetShortHelp();
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetLongHelp(wxString const & s)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetLongHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetLongHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxString* s_ptr;
  if (!get_val_ptr_param<wxString>(s_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& s = *s_ptr;
  this->_objectptr->GetObj()->SetLongHelp(s);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString const & wxAuiToolBarItem::GetLongHelp()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_GetLongHelp::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_GetLongHelp::CallMember( ParamList* _p)
{
  wxString const & res =   this->_objectptr->GetObj()->GetLongHelp();
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetMinSize(wxSize const & s)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetMinSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetMinSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxSize* s_ptr;
  if (!get_val_ptr_param<wxSize>(s_ptr,_p,_n)) ClassHelpAndReturn;
  wxSize& s = *s_ptr;
  this->_objectptr->GetObj()->SetMinSize(s);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize const & wxAuiToolBarItem::GetMinSize()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_GetMinSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_GetMinSize::CallMember( ParamList* _p)
{
  wxSize const & res =   this->_objectptr->GetObj()->GetMinSize();
  return AMILabType<wxSize>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetSpacerPixels(int s)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetSpacerPixels::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetSpacerPixels::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int s;
  if (!get_val_param<int>(s,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetSpacerPixels(s);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBarItem::GetSpacerPixels()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_GetSpacerPixels::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_GetSpacerPixels::CallMember( ParamList* _p)
{
  int res =   this->_objectptr->GetObj()->GetSpacerPixels();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetProportion(int p)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetProportion::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetProportion::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int p;
  if (!get_val_param<int>(p,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetProportion(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBarItem::GetProportion()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_GetProportion::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_GetProportion::CallMember( ParamList* _p)
{
  int res =   this->_objectptr->GetObj()->GetProportion();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetActive(bool b)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetActive::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetActive::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int b_int;
  if (!get_val_param<int>(b_int,_p,_n)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);
  this->_objectptr->GetObj()->SetActive(b);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBarItem::IsActive()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_IsActive::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_IsActive::CallMember( ParamList* _p)
{
  bool res =   this->_objectptr->GetObj()->IsActive();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetHasDropDown(bool b)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetHasDropDown::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetHasDropDown::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int b_int;
  if (!get_val_param<int>(b_int,_p,_n)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);
  this->_objectptr->GetObj()->SetHasDropDown(b);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBarItem::HasDropDown()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_HasDropDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_HasDropDown::CallMember( ParamList* _p)
{
  bool res =   this->_objectptr->GetObj()->HasDropDown();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetSticky(bool b)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetSticky::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetSticky::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int b_int;
  if (!get_val_param<int>(b_int,_p,_n)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);
  this->_objectptr->GetObj()->SetSticky(b);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBarItem::IsSticky()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_IsSticky::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_IsSticky::CallMember( ParamList* _p)
{
  bool res =   this->_objectptr->GetObj()->IsSticky();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetUserData(long int l)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetUserData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetUserData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  long l_long;
  if (!get_val_param<long>(l_long,_p,_n)) ClassHelpAndReturn;
  long int l = l_long;
  this->_objectptr->GetObj()->SetUserData(l);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long int wxAuiToolBarItem::GetUserData()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_GetUserData::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_GetUserData::CallMember( ParamList* _p)
{
  long int res =   this->_objectptr->GetObj()->GetUserData();
  long  res_long = res;
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxAuiToolBarItem & wxAuiToolBarItem::=(wxAuiToolBarItem const & c)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_assign::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'c'")
  return_comments="returning a variable of type wxAuiToolBarItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_assign::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxAuiToolBarItem* c_ptr;
  if (!get_val_ptr_param<wxAuiToolBarItem>(c_ptr,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItem& c = *c_ptr;
  wxAuiToolBarItem & res =   (*this->_objectptr->GetObj()) = (c);
  return AMILabType<wxAuiToolBarItem>::CreateVar(res);
}

