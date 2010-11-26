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
#include "wrap_wxBitmap.h"
#include "wrap_wxSize.h"
#include "wrap_wxWindow.h"


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
BasicVariable::ptr AMILabType<wxButtonBase>::CreateVar( wxButtonBase* val)
{ 
  boost::shared_ptr<wxButtonBase> obj_ptr(val,wxwindow_nodeleter<wxButtonBase>());
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
      AddVar_SetAuthNeeded( this_ptr);
      AddVar_GetAuthNeeded( this_ptr);
      AddVar_SetBitmap( this_ptr);
      AddVar_GetBitmap( this_ptr);
      AddVar_SetBitmapLabel( this_ptr);
      AddVar_SetBitmapPressed( this_ptr);
      AddVar_SetBitmapDisabled( this_ptr);
      AddVar_SetBitmapCurrent( this_ptr);
      AddVar_SetBitmapFocus( this_ptr);
      AddVar_GetBitmapLabel( this_ptr);
      AddVar_GetBitmapPressed( this_ptr);
      AddVar_GetBitmapDisabled( this_ptr);
      AddVar_GetBitmapCurrent( this_ptr);
      AddVar_GetBitmapFocus( this_ptr);
      AddVar_SetBitmapMargins_1( this_ptr);
      AddVar_SetBitmapMargins( this_ptr);
      AddVar_SetBitmapMargins_2( this_ptr);
      AddVar_GetBitmapMargins( this_ptr);
      AddVar_SetBitmapPosition( this_ptr);
      AddVar_SetDefault( this_ptr);
      AddVar_ShouldInheritColours( this_ptr);
      AddVar_GetDefaultSize( this_ptr);
      AddVar_SetImageLabel( this_ptr);
      AddVar_SetImageMargins( this_ptr);
      AddVar_GetBitmapSelected( this_ptr);
      AddVar_GetBitmapHover( this_ptr);
      AddVar_SetBitmapSelected( this_ptr);
      AddVar_SetBitmapHover( this_ptr);
      AddVar_DontShowLabel( this_ptr);
      AddVar_ShowsLabel( this_ptr);



  
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
//  Wrapping of void wxButtonBase::SetAuthNeeded(bool show = true)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetAuthNeeded::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'show' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetAuthNeeded::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int show_int = ((true==true)?1:0);;
  if (!get_val_param<int >(show_int,_p,_n)) ClassHelpAndReturn;
  bool show = (bool) (show_int>0.5);

  this->_objectptr->GetObj()->SetAuthNeeded(show);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxButtonBase::GetAuthNeeded()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_GetAuthNeeded::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_GetAuthNeeded::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetAuthNeeded();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxButtonBase::SetBitmap(wxBitmap const & bitmap, wxDirection dir = wxLEFT)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dir' (def:wxLEFT)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  int dir_int = (int) wxLEFT;;
  if (!get_val_param<int >(dir_int,_p,_n)) ClassHelpAndReturn;
  wxDirection dir = (wxDirection) dir_int;

  this->_objectptr->GetObj()->SetBitmap(bitmap, dir);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxBitmap wxButtonBase::GetBitmap()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_GetBitmap::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_GetBitmap::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap res =   this->_objectptr->GetObj()->GetBitmap();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxButtonBase::SetBitmapLabel(wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetBitmapLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
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
//  Wrapping of void wxButtonBase::SetBitmapPressed(wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetBitmapPressed::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetBitmapPressed::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  this->_objectptr->GetObj()->SetBitmapPressed(bitmap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxButtonBase::SetBitmapDisabled(wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetBitmapDisabled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetBitmapDisabled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  this->_objectptr->GetObj()->SetBitmapDisabled(bitmap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxButtonBase::SetBitmapCurrent(wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetBitmapCurrent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetBitmapCurrent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  this->_objectptr->GetObj()->SetBitmapCurrent(bitmap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxButtonBase::SetBitmapFocus(wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetBitmapFocus::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetBitmapFocus::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  this->_objectptr->GetObj()->SetBitmapFocus(bitmap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxBitmap wxButtonBase::GetBitmapLabel()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_GetBitmapLabel::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_GetBitmapLabel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap res =   this->_objectptr->GetObj()->GetBitmapLabel();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap wxButtonBase::GetBitmapPressed()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_GetBitmapPressed::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_GetBitmapPressed::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap res =   this->_objectptr->GetObj()->GetBitmapPressed();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap wxButtonBase::GetBitmapDisabled()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_GetBitmapDisabled::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_GetBitmapDisabled::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap res =   this->_objectptr->GetObj()->GetBitmapDisabled();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap wxButtonBase::GetBitmapCurrent()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_GetBitmapCurrent::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_GetBitmapCurrent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap res =   this->_objectptr->GetObj()->GetBitmapCurrent();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap wxButtonBase::GetBitmapFocus()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_GetBitmapFocus::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_GetBitmapFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap res =   this->_objectptr->GetObj()->GetBitmapFocus();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxButtonBase::SetBitmapMargins(wxCoord x, wxCoord y)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetBitmapMargins_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetBitmapMargins_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetBitmapMargins(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxButtonBase::SetBitmapMargins(...)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetBitmapMargins::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetBitmapMargins::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxButtonBase::wrap_SetBitmapMargins_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxButtonBase::wrap_SetBitmapMargins_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxButtonBase::SetBitmapMargins(wxSize const & sz)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetBitmapMargins_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetBitmapMargins_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > sz_smtptr;
  if (!get_val_smtptr_param<wxSize >(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSize const & sz = *sz_smtptr;

  this->_objectptr->GetObj()->SetBitmapMargins(sz);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxButtonBase::GetBitmapMargins()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_GetBitmapMargins::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_GetBitmapMargins::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetBitmapMargins();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxButtonBase::SetBitmapPosition(wxDirection dir)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetBitmapPosition::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dir'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetBitmapPosition::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int dir_int;
  if (!get_val_param<int >(dir_int,_p,_n)) ClassHelpAndReturn;
  wxDirection dir = (wxDirection) dir_int;

  this->_objectptr->GetObj()->SetBitmapPosition(dir);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxButtonBase::SetDefault()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetDefault::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetDefault::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->SetDefault();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
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

//---------------------------------------------------
//  Wrapping of void wxButtonBase::SetImageLabel(wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetImageLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetImageLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  this->_objectptr->GetObj()->SetImageLabel(bitmap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxButtonBase::SetImageMargins(wxCoord x, wxCoord y)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetImageMargins::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetImageMargins::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetImageMargins(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxBitmap wxButtonBase::GetBitmapSelected()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_GetBitmapSelected::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_GetBitmapSelected::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap res =   this->_objectptr->GetObj()->GetBitmapSelected();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap wxButtonBase::GetBitmapHover()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_GetBitmapHover::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_GetBitmapHover::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap res =   this->_objectptr->GetObj()->GetBitmapHover();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxButtonBase::SetBitmapSelected(wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetBitmapSelected::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetBitmapSelected::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  this->_objectptr->GetObj()->SetBitmapSelected(bitmap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxButtonBase::SetBitmapHover(wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_SetBitmapHover::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_SetBitmapHover::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  this->_objectptr->GetObj()->SetBitmapHover(bitmap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxButtonBase::DontShowLabel()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_DontShowLabel::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_DontShowLabel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->DontShowLabel();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxButtonBase::ShowsLabel()
//---------------------------------------------------
void WrapClass_wxButtonBase::
    wrap_ShowsLabel::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButtonBase::
    wrap_ShowsLabel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ShowsLabel();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

