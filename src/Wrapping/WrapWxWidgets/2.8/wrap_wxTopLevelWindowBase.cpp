/**
 * C++ Interface: wrap_wxTopLevelWindowBase
 *
 * Description: wrapping wxTopLevelWindowBase
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
#include "wrap_wxIcon.h"
#include "wrap_wxIconBundle.h"
#include "wrap_wxRegion.h"
#include "wrap_wxWindowBase.h"
#include "wrap_wxWindow.h"
#include "wrap_wxCloseEvent.h"
#include "wrap_wxSizeEvent.h"
#include "wrap_wxActivateEvent.h"
#include "wrap_wxUpdateUIEvent.h"
#include "wrap_wxSize.h"


#include "wrap_wxTopLevelWindowBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxTopLevelWindowBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxTopLevelWindowBase);
AMI_DEFINE_VARFROMSMTPTR(wxTopLevelWindowBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxTopLevelWindowBase>::CreateVar( wxTopLevelWindowBase* val, bool nodeleter)
{ 
  boost::shared_ptr<wxTopLevelWindowBase> obj_ptr(val,smartpointer_nodeleter<wxTopLevelWindowBase>());
  return AMILabType<wxTopLevelWindowBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxTopLevelWindowBase
//
Variable<AMIObject>::ptr WrapClass_wxTopLevelWindowBase::CreateVar( wxTopLevelWindowBase* sp)
{
  boost::shared_ptr<wxTopLevelWindowBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxTopLevelWindowBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxTopLevelWindowBase>::CreateVar(
      new WrapClass_wxTopLevelWindowBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxTopLevelWindowBase::AddMethods(WrapClass<wxTopLevelWindowBase>::ptr this_ptr )
{
  
      // Add members from wxWindow
      WrapClass_wxWindow::ptr parent_wxWindow(        boost::dynamic_pointer_cast<WrapClass_wxWindow >(this_ptr));
      parent_wxWindow->AddMethods(parent_wxWindow);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsAlwaysMaximized( this_ptr);
      AddVar_GetIcon( this_ptr);
      AddVar_GetIcons( this_ptr);
      AddVar_SetIcon( this_ptr);
      AddVar_SetIcons( this_ptr);
      AddVar_EnableCloseButton( this_ptr);
      AddVar_SetShape( this_ptr);
      AddVar_RequestUserAttention( this_ptr);
      AddVar_IsActive( this_ptr);
      AddVar_ShouldPreventAppExit( this_ptr);
      AddVar_CentreOnScreen( this_ptr);
      AddVar_CenterOnScreen( this_ptr);
      AddVar_RemoveChild( this_ptr);
      AddVar_GetDefaultItem( this_ptr);
      AddVar_SetDefaultItem( this_ptr);
      AddVar_GetTmpDefaultItem( this_ptr);
      AddVar_SetTmpDefaultItem( this_ptr);
      AddVar_Destroy( this_ptr);
      AddVar_IsTopLevel( this_ptr);
      AddVar_IsVisible( this_ptr);
      AddVar_OnCloseWindow( this_ptr);
      AddVar_OnSize( this_ptr);
      AddVar_GetRectForTopLevelChildren( this_ptr);
      AddVar_OnActivate( this_ptr);
      AddVar_DoUpdateWindowUI( this_ptr);
      AddVar_SetMinSize( this_ptr);
      AddVar_SetMaxSize( this_ptr);
      AddVar_DoSetSizeHints( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowBase::IsAlwaysMaximized()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_IsAlwaysMaximized::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_IsAlwaysMaximized::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsAlwaysMaximized();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxIcon const & wxTopLevelWindowBase::GetIcon()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_GetIcon::SetParametersComments()
{
  return_comments="returning a variable of type wxIcon";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_GetIcon::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxIcon const & res =   this->_objectptr->GetObj()->GetIcon();
  return AMILabType<wxIcon >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxIconBundle const & wxTopLevelWindowBase::GetIcons()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_GetIcons::SetParametersComments()
{
  return_comments="returning a variable of type wxIconBundle";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_GetIcons::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxIconBundle const & res =   this->_objectptr->GetObj()->GetIcons();
  return AMILabType<wxIconBundle >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowBase::SetIcon(wxIcon const & icon)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_SetIcon::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIcon, "parameter named 'icon'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_SetIcon::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxIcon > icon_smtptr;
  if (!get_val_smtptr_param<wxIcon >(icon_smtptr,_p,_n)) ClassHelpAndReturn;
  wxIcon const & icon = *icon_smtptr;

  this->_objectptr->GetObj()->SetIcon(icon);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowBase::SetIcons(wxIconBundle const & icons)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_SetIcons::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIconBundle, "parameter named 'icons'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_SetIcons::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxIconBundle > icons_smtptr;
  if (!get_val_smtptr_param<wxIconBundle >(icons_smtptr,_p,_n)) ClassHelpAndReturn;
  wxIconBundle const & icons = *icons_smtptr;

  this->_objectptr->GetObj()->SetIcons(icons);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowBase::EnableCloseButton(bool param0)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_EnableCloseButton::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_EnableCloseButton::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int param0_int;
  if (!get_val_param<int >(param0_int,_p,_n)) ClassHelpAndReturn;
  bool param0 = (bool) (param0_int>0.5);

  bool res =   this->_objectptr->GetObj()->EnableCloseButton(param0);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowBase::SetShape(wxRegion const & param0)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_SetShape::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRegion, "parameter named 'param0'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_SetShape::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRegion > param0_smtptr;
  if (!get_val_smtptr_param<wxRegion >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  wxRegion const & param0 = *param0_smtptr;

  bool res =   this->_objectptr->GetObj()->SetShape(param0);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowBase::RequestUserAttention(int flags = wxUSER_ATTENTION_INFO)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_RequestUserAttention::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:wxUSER_ATTENTION_INFO)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_RequestUserAttention::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int flags = wxUSER_ATTENTION_INFO;
  if (!get_val_param<int >(flags,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RequestUserAttention(flags);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowBase::IsActive()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_IsActive::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_IsActive::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsActive();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowBase::ShouldPreventAppExit()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_ShouldPreventAppExit::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_ShouldPreventAppExit::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ShouldPreventAppExit();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowBase::CentreOnScreen(int dir = wxBOTH)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_CentreOnScreen::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dir' (def:wxBOTH)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_CentreOnScreen::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int dir = wxBOTH;
  if (!get_val_param<int >(dir,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->CentreOnScreen(dir);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowBase::CenterOnScreen(int dir = wxBOTH)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_CenterOnScreen::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dir' (def:wxBOTH)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_CenterOnScreen::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int dir = wxBOTH;
  if (!get_val_param<int >(dir,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->CenterOnScreen(dir);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowBase::RemoveChild(wxWindowBase * child)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_RemoveChild::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'child'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_RemoveChild::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowBase > child_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(child_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindowBase* child = child_smtptr.get();

  this->_objectptr->GetObj()->RemoveChild(child);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxTopLevelWindowBase::GetDefaultItem()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_GetDefaultItem::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_GetDefaultItem::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetDefaultItem();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxTopLevelWindowBase::SetDefaultItem(wxWindow * win)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_SetDefaultItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'win'")
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_SetDefaultItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > win_smtptr;
  if (!get_val_smtptr_param<wxWindow >(win_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* win = win_smtptr.get();

  wxWindow * res =   this->_objectptr->GetObj()->SetDefaultItem(win);
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxTopLevelWindowBase::GetTmpDefaultItem()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_GetTmpDefaultItem::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_GetTmpDefaultItem::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetTmpDefaultItem();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxTopLevelWindowBase::SetTmpDefaultItem(wxWindow * win)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_SetTmpDefaultItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'win'")
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_SetTmpDefaultItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > win_smtptr;
  if (!get_val_smtptr_param<wxWindow >(win_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* win = win_smtptr.get();

  wxWindow * res =   this->_objectptr->GetObj()->SetTmpDefaultItem(win);
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowBase::Destroy()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_Destroy::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_Destroy::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Destroy();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowBase::IsTopLevel()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_IsTopLevel::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_IsTopLevel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsTopLevel();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowBase::IsVisible()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_IsVisible::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_IsVisible::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsVisible();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowBase::OnCloseWindow(wxCloseEvent & event)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_OnCloseWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCloseEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_OnCloseWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxCloseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxCloseEvent >(event_smtptr,_p,_n)) ClassHelpAndReturn;
  wxCloseEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnCloseWindow(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowBase::OnSize(wxSizeEvent & param0)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_OnSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizeEvent, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_OnSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSizeEvent > param0_smtptr;
  if (!get_val_smtptr_param<wxSizeEvent >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSizeEvent & param0 = *param0_smtptr;

  this->_objectptr->GetObj()->OnSize(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowBase::GetRectForTopLevelChildren(int * x, int * y, int * w, int * h)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_GetRectForTopLevelChildren::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_GetRectForTopLevelChildren::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > x_smtptr;
  if (!get_val_smtptr_param<int >(x_smtptr,_p,_n)) ClassHelpAndReturn;
  int* x = x_smtptr.get();

  boost::shared_ptr<int > y_smtptr;
  if (!get_val_smtptr_param<int >(y_smtptr,_p,_n)) ClassHelpAndReturn;
  int* y = y_smtptr.get();

  boost::shared_ptr<int > w_smtptr;
  if (!get_val_smtptr_param<int >(w_smtptr,_p,_n)) ClassHelpAndReturn;
  int* w = w_smtptr.get();

  boost::shared_ptr<int > h_smtptr;
  if (!get_val_smtptr_param<int >(h_smtptr,_p,_n)) ClassHelpAndReturn;
  int* h = h_smtptr.get();

  this->_objectptr->GetObj()->GetRectForTopLevelChildren(x, y, w, h);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowBase::OnActivate(wxActivateEvent & param0)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_OnActivate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxActivateEvent, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_OnActivate::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxActivateEvent > param0_smtptr;
  if (!get_val_smtptr_param<wxActivateEvent >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  wxActivateEvent & param0 = *param0_smtptr;

  this->_objectptr->GetObj()->OnActivate(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowBase::DoUpdateWindowUI(wxUpdateUIEvent & event)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_DoUpdateWindowUI::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUpdateUIEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_DoUpdateWindowUI::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxUpdateUIEvent > event_smtptr;
  if (!get_val_smtptr_param<wxUpdateUIEvent >(event_smtptr,_p,_n)) ClassHelpAndReturn;
  wxUpdateUIEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->DoUpdateWindowUI(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowBase::SetMinSize(wxSize const & minSize)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_SetMinSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'minSize'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_SetMinSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSize > minSize_smtptr;
  if (!get_val_smtptr_param<wxSize >(minSize_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize const & minSize = *minSize_smtptr;

  this->_objectptr->GetObj()->SetMinSize(minSize);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowBase::SetMaxSize(wxSize const & maxSize)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_SetMaxSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'maxSize'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_SetMaxSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSize > maxSize_smtptr;
  if (!get_val_smtptr_param<wxSize >(maxSize_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize const & maxSize = *maxSize_smtptr;

  this->_objectptr->GetObj()->SetMaxSize(maxSize);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowBase::DoSetSizeHints(int minW, int minH, int maxW = wxDefaultCoord, int maxH = wxDefaultCoord, int incW = wxDefaultCoord, int incH = wxDefaultCoord)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowBase::
    wrap_DoSetSizeHints::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'minW'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'minH'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'maxW' (def:wxDefaultCoord)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'maxH' (def:wxDefaultCoord)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'incW' (def:wxDefaultCoord)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'incH' (def:wxDefaultCoord)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowBase::
    wrap_DoSetSizeHints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  int minW;
  if (!get_val_param<int >(minW,_p,_n)) ClassHelpAndReturn;

  int minH;
  if (!get_val_param<int >(minH,_p,_n)) ClassHelpAndReturn;

  int maxW = wxDefaultCoord;
  if (!get_val_param<int >(maxW,_p,_n)) ClassHelpAndReturn;

  int maxH = wxDefaultCoord;
  if (!get_val_param<int >(maxH,_p,_n)) ClassHelpAndReturn;

  int incW = wxDefaultCoord;
  if (!get_val_param<int >(incW,_p,_n)) ClassHelpAndReturn;

  int incH = wxDefaultCoord;
  if (!get_val_param<int >(incH,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DoSetSizeHints(minW, minH, maxW, maxH, incW, incH);
  return BasicVariable::ptr();
}

