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

/*
//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
*/

#include "wrap_wxAuiToolBarItem.h"

// get all the required includes
// #include "..."
#ifndef wxAuiToolBarItem_declared
  #define wxAuiToolBarItem_declared
  AMI_DECLARE_TYPE(wxAuiToolBarItem)
#endif
#ifndef wxWindow_declared
  #define wxWindow_declared
  AMI_DECLARE_TYPE(wxWindow)
#endif
#ifndef wxSizerItem_declared
  #define wxSizerItem_declared
  AMI_DECLARE_TYPE(wxSizerItem)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxBitmap_declared
  #define wxBitmap_declared
  AMI_DECLARE_TYPE(wxBitmap)
#endif
#ifndef wxSize_declared
  #define wxSize_declared
  AMI_DECLARE_TYPE(wxSize)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAuiToolBarItem>::CreateVar( ParamList* p)
{
  WrapClass_wxAuiToolBarItem::wrap_wxAuiToolBarItem construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxAuiToolBarItem);
AMI_DEFINE_VARFROMSMTPTR(wxAuiToolBarItem);


//----------------------------------------------------------------------
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

//----------------------------------------------------------------------
void WrapClass_wxAuiToolBarItem::AddMethods(WrapClass<wxAuiToolBarItem>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_Assign( this_ptr);
  AddVar_SetWindow( this_ptr);
  AddVar_GetWindow( this_ptr);
  AddVar_SetId( this_ptr);
  AddVar_GetId( this_ptr);
  AddVar_SetKind( this_ptr);
  AddVar_GetKind( this_ptr);
  AddVar_SetState( this_ptr);
  AddVar_GetState( this_ptr);
  AddVar_SetSizerItem( this_ptr);
  AddVar_GetSizerItem( this_ptr);
  AddVar_SetLabel( this_ptr);
  AddVar_GetLabel( this_ptr);
  AddVar_SetBitmap( this_ptr);
  AddVar_GetBitmap( this_ptr);
  AddVar_SetDisabledBitmap( this_ptr);
  AddVar_GetDisabledBitmap( this_ptr);
  AddVar_SetHoverBitmap( this_ptr);
  AddVar_GetHoverBitmap( this_ptr);
  AddVar_SetShortHelp( this_ptr);
  AddVar_GetShortHelp( this_ptr);
  AddVar_SetLongHelp( this_ptr);
  AddVar_GetLongHelp( this_ptr);
  AddVar_SetMinSize( this_ptr);
  AddVar_GetMinSize( this_ptr);
  AddVar_SetSpacerPixels( this_ptr);
  AddVar_GetSpacerPixels( this_ptr);
  AddVar_SetProportion( this_ptr);
  AddVar_GetProportion( this_ptr);
  AddVar_SetActive( this_ptr);
  AddVar_IsActive( this_ptr);
  AddVar_SetHasDropDown( this_ptr);
  AddVar_HasDropDown( this_ptr);
  AddVar_SetSticky( this_ptr);
  AddVar_IsSticky( this_ptr);
  AddVar_SetUserData( this_ptr);
  AddVar_GetUserData( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxAuiToolBarItem_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxAuiToolBarItem");
    WrapClass_wxAuiToolBarItem::AddVar_wxAuiToolBarItem_1(amiobject->GetContext());
  WrapClass_wxAuiToolBarItem::AddVar_wxAuiToolBarItem(amiobject->GetContext());
  WrapClass_wxAuiToolBarItem::AddVar_wxAuiToolBarItem_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxAuiToolBarItem::wxAuiToolBarItem()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_wxAuiToolBarItem_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_wxAuiToolBarItem_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxAuiToolBarItem* _newobj = new wxAuiToolBarItem();
  BasicVariable::ptr res = WrapClass_wxAuiToolBarItem::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxAuiToolBarItem::wxAuiToolBarItem(...)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_wxAuiToolBarItem::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_wxAuiToolBarItem::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiToolBarItem::wrap_wxAuiToolBarItem_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiToolBarItem::wrap_wxAuiToolBarItem_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxAuiToolBarItem::wxAuiToolBarItem(wxAuiToolBarItem const & c)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_wxAuiToolBarItem_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_wxAuiToolBarItem_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiToolBarItem > c_smtptr;
  if (!get_val_smtptr_param<wxAuiToolBarItem >(c_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxAuiToolBarItem const & c = *c_smtptr;

  wxAuiToolBarItem* _newobj = new wxAuiToolBarItem(c);
  BasicVariable::ptr res = WrapClass_wxAuiToolBarItem::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxAuiToolBarItem.
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxAuiToolBarItem object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxAuiToolBarItem >::CreateVar( new wxAuiToolBarItem(*(this->_objectptr->GetObj())));
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiToolBarItem > c_smtptr;
  if (!get_val_smtptr_param<wxAuiToolBarItem >(c_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiToolBarItem const & c = *c_smtptr;

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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxWindow* w;
  if (CheckNullVar(_p,_n))  {
    w=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > w_smtptr;
    if (!get_val_smtptr_param<wxWindow >(w_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    w = w_smtptr.get();
  }

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetWindow();
  BasicVariable::ptr res_var = AMILabType<wxWindow >::CreateVar(res,true);
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int new_id;
  if (!get_val_param<int >(new_id,_p,_n,true,false)) ClassHelpAndReturn;

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetId();
  return AMILabType<int >::CreateVar(res);
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int new_kind;
  if (!get_val_param<int >(new_kind,_p,_n,true,false)) ClassHelpAndReturn;

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetKind();
  return AMILabType<int >::CreateVar(res);
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int new_state;
  if (!get_val_param<int >(new_state,_p,_n,true,false)) ClassHelpAndReturn;

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetState();
  return AMILabType<int >::CreateVar(res);
}

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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxSizerItem* s;
  if (CheckNullVar(_p,_n))  {
    s=(wxSizerItem*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxSizerItem > s_smtptr;
    if (!get_val_smtptr_param<wxSizerItem >(s_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    s = s_smtptr.get();
  }

  this->_objectptr->GetObj()->SetSizerItem(s);
  return BasicVariable::ptr();
}

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizerItem * res =   this->_objectptr->GetObj()->GetSizerItem();
  BasicVariable::ptr res_var = AMILabType<wxSizerItem >::CreateVar(res,true);
  return res_var;
}

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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > s_smtptr;
  if (!get_val_smtptr_param<wxString >(s_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & s = *s_smtptr;

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetLabel();
  return AMILabType<wxString >::CreateVar(res);
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bmp_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmp_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & bmp = *bmp_smtptr;

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap const & res =   this->_objectptr->GetObj()->GetBitmap();
  return AMILabType<wxBitmap >::CreateVar(res);
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bmp_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmp_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & bmp = *bmp_smtptr;

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap const & res =   this->_objectptr->GetObj()->GetDisabledBitmap();
  return AMILabType<wxBitmap >::CreateVar(res);
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bmp_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmp_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & bmp = *bmp_smtptr;

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap const & res =   this->_objectptr->GetObj()->GetHoverBitmap();
  return AMILabType<wxBitmap >::CreateVar(res);
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > s_smtptr;
  if (!get_val_smtptr_param<wxString >(s_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & s = *s_smtptr;

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetShortHelp();
  return AMILabType<wxString >::CreateVar(res);
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > s_smtptr;
  if (!get_val_smtptr_param<wxString >(s_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & s = *s_smtptr;

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetLongHelp();
  return AMILabType<wxString >::CreateVar(res);
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSize > s_smtptr;
  if (!get_val_smtptr_param<wxSize >(s_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSize const & s = *s_smtptr;

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize const & res =   this->_objectptr->GetObj()->GetMinSize();
  return AMILabType<wxSize >::CreateVar(res);
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int s;
  if (!get_val_param<int >(s,_p,_n,true,false)) ClassHelpAndReturn;

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetSpacerPixels();
  return AMILabType<int >::CreateVar(res);
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int p;
  if (!get_val_param<int >(p,_p,_n,true,false)) ClassHelpAndReturn;

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetProportion();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetActive(bool b)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetActive::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'b'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetActive::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool b;
  if (!get_val_param<bool >(b,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetActive(b);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBarItem::IsActive()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_IsActive::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_IsActive::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsActive();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetHasDropDown(bool b)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetHasDropDown::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'b'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetHasDropDown::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool b;
  if (!get_val_param<bool >(b,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetHasDropDown(b);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBarItem::HasDropDown()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_HasDropDown::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_HasDropDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasDropDown();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItem::SetSticky(bool b)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_SetSticky::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'b'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_SetSticky::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool b;
  if (!get_val_param<bool >(b,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetSticky(b);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBarItem::IsSticky()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap_IsSticky::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap_IsSticky::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsSticky();
  return AMILabType<bool >::CreateVar(res);
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,false)) ClassHelpAndReturn;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   this->_objectptr->GetObj()->GetUserData();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxAuiToolBarItem & wxAuiToolBarItem::operator =(wxAuiToolBarItem const & c)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItem::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'c'")
  return_comments="returning a variable of type wxAuiToolBarItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItem::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiToolBarItem > c_smtptr;
  if (!get_val_smtptr_param<wxAuiToolBarItem >(c_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiToolBarItem const & c = *c_smtptr;

  wxAuiToolBarItem & res =   (*this->_objectptr->GetObj()) = (c);
  return AMILabType<wxAuiToolBarItem >::CreateVar(res);
}

