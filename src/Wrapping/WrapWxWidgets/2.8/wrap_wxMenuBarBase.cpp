/**
 * C++ Interface: wrap_wxMenuBarBase
 *
 * Description: wrapping wxMenuBarBase
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
#include "wrap_wxMenu.h"
#include "wrap_wxString.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxMenuItem.h"
#include "wrap_wxFrame.h"


#include "wrap_wxMenuBarBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxMenuBarBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxMenuBarBase);
AMI_DEFINE_VARFROMSMTPTR(wxMenuBarBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxMenuBarBase>::CreateVar( wxMenuBarBase* val, bool nodeleter)
{ 
  boost::shared_ptr<wxMenuBarBase> obj_ptr(val,smartpointer_nodeleter<wxMenuBarBase>());
  return AMILabType<wxMenuBarBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxMenuBarBase
//
Variable<AMIObject>::ptr WrapClass_wxMenuBarBase::CreateVar( wxMenuBarBase* sp)
{
  boost::shared_ptr<wxMenuBarBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxMenuBarBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxMenuBarBase>::CreateVar(
      new WrapClass_wxMenuBarBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxMenuBarBase::AddMethods(WrapClass<wxMenuBarBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding standard methods 
      AddVar_Append( this_ptr);
      AddVar_Insert( this_ptr);
      AddVar_GetMenuCount( this_ptr);
      AddVar_GetMenu( this_ptr);
      AddVar_Replace( this_ptr);
      AddVar_Remove( this_ptr);
      AddVar_IsEnabledTop( this_ptr);
      AddVar_FindMenuItem( this_ptr);
/* The following types are missing: wxMenu * *
      AddVar_FindItem( this_ptr);
*/
      AddVar_FindMenu( this_ptr);
      AddVar_Enable_1( this_ptr);
      AddVar_Check( this_ptr);
      AddVar_IsChecked( this_ptr);
      AddVar_IsEnabled_1( this_ptr);
      AddVar_IsEnabled( this_ptr);
      AddVar_IsEnabled_2( this_ptr);
      AddVar_SetLabel_1( this_ptr);
      AddVar_GetLabel_1( this_ptr);
      AddVar_SetHelpString( this_ptr);
      AddVar_GetHelpString( this_ptr);
      AddVar_GetFrame( this_ptr);
      AddVar_IsAttached( this_ptr);
      AddVar_Attach( this_ptr);
      AddVar_Detach( this_ptr);
      AddVar_Enable( this_ptr);
      AddVar_Enable_2( this_ptr);
      AddVar_SetLabel( this_ptr);
      AddVar_SetLabel_2( this_ptr);
      AddVar_GetLabel( this_ptr);
      AddVar_GetLabel_2( this_ptr);
      AddVar_AcceptsFocusFromKeyboard( this_ptr);
      AddVar_UpdateMenus( this_ptr);
      AddVar_SetMenuLabel( this_ptr);
      AddVar_GetMenuLabelText( this_ptr);



  

  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxWindow
  boost::shared_ptr<wxWindow > parent_wxWindow(  boost::dynamic_pointer_cast<wxWindow >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxWindow = AMILabType<wxWindow >::CreateVarFromSmtPtr(parent_wxWindow);
  context->AddVar("wxWindow",var_wxWindow);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxWindow = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxWindow);
  context->AddDefault(obj_wxWindow->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxMenuBarBase::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxMenuBarBase");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of bool wxMenuBarBase::Append(wxMenu * menu, wxString const & title)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_Append::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menu'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_Append::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenu > menu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(menu_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenu* menu = menu_smtptr.get();

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  bool res =   this->_objectptr->GetObj()->Append(menu, title);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBarBase::Insert(size_t pos, wxMenu * menu, wxString const & title)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_Insert::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menu'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_Insert::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  boost::shared_ptr<wxMenu > menu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(menu_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenu* menu = menu_smtptr.get();

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  bool res =   this->_objectptr->GetObj()->Insert(pos, menu, title);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of size_t wxMenuBarBase::GetMenuCount()
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_GetMenuCount::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_GetMenuCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->GetMenuCount();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxMenu * wxMenuBarBase::GetMenu(size_t pos)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_GetMenu::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  return_comments="returning a variable of type wxMenu";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_GetMenu::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  wxMenu * res =   this->_objectptr->GetObj()->GetMenu(pos);
  BasicVariable::ptr res_var = WrapClass_wxMenu::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMenu * wxMenuBarBase::Replace(size_t pos, wxMenu * menu, wxString const & title)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_Replace::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menu'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  return_comments="returning a variable of type wxMenu";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_Replace::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  boost::shared_ptr<wxMenu > menu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(menu_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenu* menu = menu_smtptr.get();

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  wxMenu * res =   this->_objectptr->GetObj()->Replace(pos, menu, title);
  BasicVariable::ptr res_var = WrapClass_wxMenu::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMenu * wxMenuBarBase::Remove(size_t pos)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_Remove::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  return_comments="returning a variable of type wxMenu";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_Remove::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  wxMenu * res =   this->_objectptr->GetObj()->Remove(pos);
  BasicVariable::ptr res_var = WrapClass_wxMenu::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBarBase::IsEnabledTop(size_t param0)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_IsEnabledTop::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'param0'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_IsEnabledTop::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long param0_long;
  if (!get_val_param<long >(param0_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int param0 = boost::numeric_cast<long unsigned int >(param0_long);

  bool res =   this->_objectptr->GetObj()->IsEnabledTop(param0);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxMenuBarBase::FindMenuItem(wxString const & menu, wxString const & item)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_FindMenuItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'menu'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'item'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_FindMenuItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > menu_smtptr;
  if (!get_val_smtptr_param<wxString >(menu_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & menu = *menu_smtptr;

  boost::shared_ptr<wxString > item_smtptr;
  if (!get_val_smtptr_param<wxString >(item_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & item = *item_smtptr;

  int res =   this->_objectptr->GetObj()->FindMenuItem(menu, item);
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: wxMenu * *

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBarBase::FindItem(int itemid, wxMenu * * menu = 0l)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_FindItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menu' (def:0l)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_FindItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxMenu > menu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(menu_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenu* menu = menu_smtptr.get();

  wxMenuItem * res =   this->_objectptr->GetObj()->FindItem(itemid, menu);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of int wxMenuBarBase::FindMenu(wxString const & title)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_FindMenu::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_FindMenu::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  int res =   this->_objectptr->GetObj()->FindMenu(title);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxMenuBarBase::Enable(int itemid, bool enable)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_Enable_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'enable'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_Enable_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,true)) ClassReturnEmptyVar;

  bool enable;
  if (!get_val_param<bool >(enable,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Enable(itemid, enable);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuBarBase::Check(int itemid, bool check)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_Check::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'check'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_Check::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  bool check;
  if (!get_val_param<bool >(check,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Check(itemid, check);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBarBase::IsChecked(int itemid)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_IsChecked::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_IsChecked::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsChecked(itemid);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBarBase::IsEnabled(int itemid)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_IsEnabled_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_IsEnabled_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->IsEnabled(itemid);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuBarBase::IsEnabled(...)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_IsEnabled::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_IsEnabled::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuBarBase::wrap_IsEnabled_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuBarBase::wrap_IsEnabled_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBarBase::IsEnabled()
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_IsEnabled_2::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_IsEnabled_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->IsEnabled();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxMenuBarBase::SetLabel(int itemid, wxString const & label)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_SetLabel_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_SetLabel_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & label = *label_smtptr;

  this->_objectptr->GetObj()->SetLabel(itemid, label);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxMenuBarBase::GetLabel(int itemid)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_GetLabel_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_GetLabel_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,true)) ClassReturnEmptyVar;

  wxString res =   this->_objectptr->GetObj()->GetLabel(itemid);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxMenuBarBase::SetHelpString(int itemid, wxString const & helpString)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_SetHelpString::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'helpString'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_SetHelpString::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > helpString_smtptr;
  if (!get_val_smtptr_param<wxString >(helpString_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & helpString = *helpString_smtptr;

  this->_objectptr->GetObj()->SetHelpString(itemid, helpString);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxMenuBarBase::GetHelpString(int itemid)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_GetHelpString::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_GetHelpString::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetHelpString(itemid);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxFrame * wxMenuBarBase::GetFrame()
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_GetFrame::SetParametersComments()
{
  return_comments="returning a variable of type wxFrame";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_GetFrame::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxFrame * res =   this->_objectptr->GetObj()->GetFrame();
  BasicVariable::ptr res_var = WrapClass_wxFrame::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBarBase::IsAttached()
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_IsAttached::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_IsAttached::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsAttached();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxMenuBarBase::Attach(wxFrame * frame)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_Attach::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFrame, "parameter named 'frame'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_Attach::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFrame > frame_smtptr;
  if (!get_val_smtptr_param<wxFrame >(frame_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFrame* frame = frame_smtptr.get();

  this->_objectptr->GetObj()->Attach(frame);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuBarBase::Detach()
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_Detach::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_Detach::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Detach();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuBarBase::Enable(...)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_Enable::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_Enable::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuBarBase::wrap_Enable_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuBarBase::wrap_Enable_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBarBase::Enable(bool enable = true)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_Enable_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'enable' (def:true)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_Enable_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  bool enable = true;
  if (!get_val_param<bool >(enable,_p,_n,false,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Enable(enable);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuBarBase::SetLabel(...)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_SetLabel::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_SetLabel::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuBarBase::wrap_SetLabel_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuBarBase::wrap_SetLabel_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxMenuBarBase::SetLabel(wxString const & s)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_SetLabel_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_SetLabel_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > s_smtptr;
  if (!get_val_smtptr_param<wxString >(s_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & s = *s_smtptr;

  this->_objectptr->GetObj()->SetLabel(s);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuBarBase::GetLabel(...)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_GetLabel::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_GetLabel::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuBarBase::wrap_GetLabel_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuBarBase::wrap_GetLabel_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString wxMenuBarBase::GetLabel()
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_GetLabel_2::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_GetLabel_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxString res =   this->_objectptr->GetObj()->GetLabel();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBarBase::AcceptsFocusFromKeyboard()
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_AcceptsFocusFromKeyboard::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_AcceptsFocusFromKeyboard::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->AcceptsFocusFromKeyboard();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxMenuBarBase::UpdateMenus()
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_UpdateMenus::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_UpdateMenus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UpdateMenus();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuBarBase::SetMenuLabel(size_t pos, wxString const & label)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_SetMenuLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_SetMenuLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & label = *label_smtptr;

  this->_objectptr->GetObj()->SetMenuLabel(pos, label);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxMenuBarBase::GetMenuLabelText(size_t pos)
//---------------------------------------------------
void WrapClass_wxMenuBarBase::
    wrap_GetMenuLabelText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBarBase::
    wrap_GetMenuLabelText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  wxString res =   this->_objectptr->GetObj()->GetMenuLabelText(pos);
  return AMILabType<wxString >::CreateVar(res);
}

