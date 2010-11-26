/**
 * C++ Interface: wrap_wxMenu
 *
 * Description: wrapping wxMenu
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
#include "wrap_wxString.h"
#include "wrap_wxMenuBarBase.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxMenu.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxMenu>::CreateVar( ParamList* p)
{
  WrapClass_wxMenu::wrap_wxMenu construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxMenu);
AMI_DEFINE_VARFROMSMTPTR(wxMenu);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxMenu>::CreateVar( wxMenu* val, bool nodeleter)
{ 
  boost::shared_ptr<wxMenu> obj_ptr(val,smartpointer_nodeleter<wxMenu>());
  return AMILabType<wxMenu>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxMenu
//
Variable<AMIObject>::ptr WrapClass_wxMenu::CreateVar( wxMenu* sp)
{
  boost::shared_ptr<wxMenu> di_ptr(
    sp,
    wxwindow_nodeleter<wxMenu>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxMenu>::CreateVar(
      new WrapClass_wxMenu(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxMenu::AddMethods(WrapClass<wxMenu>::ptr this_ptr )
{
  
      // Add members from wxMenuBase
      WrapClass_wxMenuBase::ptr parent_wxMenuBase(        boost::dynamic_pointer_cast<WrapClass_wxMenuBase >(this_ptr));
      parent_wxMenuBase->AddMethods(parent_wxMenuBase);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_Attach( this_ptr);
      AddVar_SetLayoutDirection( this_ptr);
      AddVar_GetLayoutDirection( this_ptr);
/* The following types are missing: _GtkWidget
      AddVar_FindMenuIdByMenuItem( this_ptr);
*/
      AddVar_GetClassInfo( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      /* type not available
      // Adding public member m_menu
      boost::shared_ptr<_GtkWidget > var_m_menu_ptr(&GetObj()->m_menu, smartpointer_nodeleter<_GtkWidget >());
      BasicVariable::ptr var_m_menu = AMILabType<_GtkWidget >::CreateVarFromSmtPtr(var_m_menu_ptr);
      if (var_m_menu.get()) {
        var_m_menu->Rename("m_menu");
        context->AddVar(var_m_menu,context);
      }
      */
      
      /* type not available
      // Adding public member m_owner
      boost::shared_ptr<_GtkWidget > var_m_owner_ptr(&GetObj()->m_owner, smartpointer_nodeleter<_GtkWidget >());
      BasicVariable::ptr var_m_owner = AMILabType<_GtkWidget >::CreateVarFromSmtPtr(var_m_owner_ptr);
      if (var_m_owner.get()) {
        var_m_owner->Rename("m_owner");
        context->AddVar(var_m_owner,context);
      }
      */
      
      /* type not available
      // Adding public member m_accel
      boost::shared_ptr<_GtkAccelGroup > var_m_accel_ptr(&GetObj()->m_accel, smartpointer_nodeleter<_GtkAccelGroup >());
      BasicVariable::ptr var_m_accel = AMILabType<_GtkAccelGroup >::CreateVarFromSmtPtr(var_m_accel_ptr);
      if (var_m_accel.get()) {
        var_m_accel->Rename("m_accel");
        context->AddVar(var_m_accel,context);
      }
      */

};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxMenu::wxMenu(wxString const & title, long int style = 0)
//---------------------------------------------------
void WrapClass_wxMenu::
    wrap_wxMenu_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenu::
    wrap_wxMenu_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & title = *title_smtptr;

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n)) ClassReturnEmptyVar;
  long int style = style_long;

  wxMenu* _newobj = new wxMenu(title, style);
  BasicVariable::ptr res = WrapClass_wxMenu::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxMenu::wxMenu(...)
//---------------------------------------------------
void WrapClass_wxMenu::
    wrap_wxMenu::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenu::
    wrap_wxMenu::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenu::wrap_wxMenu_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenu::wrap_wxMenu_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxMenu::wxMenu(long int style = 0)
//---------------------------------------------------
void WrapClass_wxMenu::
    wrap_wxMenu_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenu::
    wrap_wxMenu_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n)) ClassReturnEmptyVar;
  long int style = style_long;

  wxMenu* _newobj = new wxMenu(style);
  BasicVariable::ptr res = WrapClass_wxMenu::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxMenu::Attach(wxMenuBarBase * menubar)
//---------------------------------------------------
void WrapClass_wxMenu::
    wrap_Attach::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuBarBase, "parameter named 'menubar'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenu::
    wrap_Attach::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenuBarBase > menubar_smtptr;
  if (!get_val_smtptr_param<wxMenuBarBase >(menubar_smtptr,_p,_n)) ClassHelpAndReturn;
  wxMenuBarBase* menubar = menubar_smtptr.get();

  this->_objectptr->GetObj()->Attach(menubar);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenu::SetLayoutDirection(wxLayoutDirection const dir)
//---------------------------------------------------
void WrapClass_wxMenu::
    wrap_SetLayoutDirection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dir'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenu::
    wrap_SetLayoutDirection::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int dir_int;
  if (!get_val_param<int >(dir_int,_p,_n)) ClassHelpAndReturn;
  wxLayoutDirection dir = (wxLayoutDirection) dir_int;

  this->_objectptr->GetObj()->SetLayoutDirection(dir);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxLayoutDirection wxMenu::GetLayoutDirection()
//---------------------------------------------------
void WrapClass_wxMenu::
    wrap_GetLayoutDirection::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenu::
    wrap_GetLayoutDirection::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxLayoutDirection res =   this->_objectptr->GetObj()->GetLayoutDirection();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}
/* The following types are missing: _GtkWidget

//---------------------------------------------------
//  Wrapping of int wxMenu::FindMenuIdByMenuItem(GtkWidget * menuItem)
//---------------------------------------------------
void WrapClass_wxMenu::
    wrap_FindMenuIdByMenuItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GtkWidget, "parameter named 'menuItem'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenu::
    wrap_FindMenuIdByMenuItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<_GtkWidget > menuItem_smtptr;
  if (!get_val_smtptr_param<_GtkWidget >(menuItem_smtptr,_p,_n)) ClassHelpAndReturn;
  _GtkWidget* menuItem = menuItem_smtptr.get();

  int res =   this->_objectptr->GetObj()->FindMenuIdByMenuItem(menuItem);
  return AMILabType<int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxMenu::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxMenu::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenu::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

