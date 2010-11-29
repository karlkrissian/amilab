/**
 * C++ Interface: wrap_wxMenuItemBase
 *
 * Description: wrapping wxMenuItemBase
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
#include "wrap_wxMenuItem.h"
#include "wrap_wxMenu.h"
#include "wrap_wxString.h"
#include "wrap_wxAcceleratorEntry.h"


#include "wrap_wxMenuItemBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxMenuItemBase>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxMenuItemBase);
AMI_DEFINE_VARFROMSMTPTR(wxMenuItemBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxMenuItemBase>::CreateVar( wxMenuItemBase* val, bool nodeleter)
{ 
  boost::shared_ptr<wxMenuItemBase> obj_ptr(val,smartpointer_nodeleter<wxMenuItemBase>());
  return AMILabType<wxMenuItemBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxMenuItemBase
//
Variable<AMIObject>::ptr WrapClass_wxMenuItemBase::CreateVar( wxMenuItemBase* sp)
{
  boost::shared_ptr<wxMenuItemBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxMenuItemBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxMenuItemBase>::CreateVar(
      new WrapClass_wxMenuItemBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxMenuItemBase::AddMethods(WrapClass<wxMenuItemBase>::ptr this_ptr )
{
  
      // Add members from wxObject
      WrapClass_wxObject::ptr parent_wxObject(        boost::dynamic_pointer_cast<WrapClass_wxObject >(this_ptr));
      parent_wxObject->AddMethods(parent_wxObject);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_GetMenu( this_ptr);
      AddVar_SetMenu( this_ptr);
      AddVar_SetId( this_ptr);
      AddVar_GetId( this_ptr);
      AddVar_IsSeparator( this_ptr);
      AddVar_SetText( this_ptr);
      AddVar_GetLabel( this_ptr);
      AddVar_GetText( this_ptr);
/* The following types are missing: wxItemKind
      AddVar_GetKind( this_ptr);
*/
/* The following types are missing: wxItemKind
      AddVar_SetKind( this_ptr);
*/
      AddVar_SetCheckable( this_ptr);
      AddVar_IsCheckable( this_ptr);
      AddVar_IsSubMenu( this_ptr);
      AddVar_SetSubMenu( this_ptr);
      AddVar_GetSubMenu( this_ptr);
      AddVar_Enable( this_ptr);
      AddVar_IsEnabled( this_ptr);
      AddVar_Check( this_ptr);
      AddVar_IsChecked( this_ptr);
      AddVar_Toggle( this_ptr);
      AddVar_SetHelp( this_ptr);
      AddVar_GetHelp( this_ptr);
      AddVar_GetAccel( this_ptr);
      AddVar_SetAccel( this_ptr);
      AddVar_SetName( this_ptr);
      AddVar_GetName( this_ptr);
      AddVar_SetItemLabel( this_ptr);
      AddVar_GetItemLabelText( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------

/* The following types are missing: wxItemKind

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuItemBase::New(wxMenu * parentMenu = 0u, int itemid = wxID_SEPARATOR, wxString const & text = wxEmptyString, wxString const & help = wxEmptyString, wxItemKind kind = wxITEM_NORMAL, wxMenu * subMenu = 0u)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_static_New_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'parentMenu' (def:0u)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid' (def:wxID_SEPARATOR)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxItemKind, "parameter named 'kind' (def:wxITEM_NORMAL)")
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'subMenu' (def:0u)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_static_New_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMenu > parentMenu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(parentMenu_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenu* parentMenu = parentMenu_smtptr.get();

  int itemid = wxID_SEPARATOR;
  if (!get_val_param<int >(itemid,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & text = ( text_smtptr.get() ? (*text_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxString > help_smtptr;
  if (!get_val_smtptr_param<wxString >(help_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & help = ( help_smtptr.get() ? (*help_smtptr) : wxString(wxEmptyString) );

  wxItemKind kind = wxITEM_NORMAL;
  if (!get_val_param<wxItemKind >(kind,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxMenu > subMenu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(subMenu_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenu* subMenu = subMenu_smtptr.get();

  wxMenuItem * res =   wxMenuItemBase::New(parentMenu, itemid, text, help, kind, subMenu);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of wxString wxMenuItemBase::GetLabelFromText(wxString const & text)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_static_GetLabelFromText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_static_GetLabelFromText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  wxString res =   wxMenuItemBase::GetLabelFromText(text);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... static wxMenuItemBase::New(...)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_static_New::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_static_New::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuItemBase::wrap_static_New_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuItemBase::New(wxMenu * parentMenu, int itemid, wxString const & text, wxString const & help, bool isCheckable, wxMenu * subMenu = 0u)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_static_New_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'parentMenu'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'isCheckable'")
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'subMenu' (def:0u)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_static_New_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMenu > parentMenu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(parentMenu_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenu* parentMenu = parentMenu_smtptr.get();

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxString > help_smtptr;
  if (!get_val_smtptr_param<wxString >(help_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & help = *help_smtptr;

  int isCheckable_int;
  if (!get_val_param<int >(isCheckable_int,_p,_n,true,true)) ClassReturnEmptyVar;
  bool isCheckable = (bool) (isCheckable_int>0.5);

  boost::shared_ptr<wxMenu > subMenu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(subMenu_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenu* subMenu = subMenu_smtptr.get();

  wxMenuItem * res =   wxMenuItemBase::New(parentMenu, itemid, text, help, isCheckable, subMenu);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxString wxMenuItemBase::GetLabelText(wxString const & label)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_static_GetLabelText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_static_GetLabelText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & label = *label_smtptr;

  wxString res =   wxMenuItemBase::GetLabelText(label);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxMenu * wxMenuItemBase::GetMenu()
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_GetMenu::SetParametersComments()
{
  return_comments="returning a variable of type wxMenu";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_GetMenu::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxMenu * res =   this->_objectptr->GetObj()->GetMenu();
  BasicVariable::ptr res_var = WrapClass_wxMenu::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemBase::SetMenu(wxMenu * menu)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_SetMenu::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menu'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_SetMenu::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenu > menu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(menu_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenu* menu = menu_smtptr.get();

  this->_objectptr->GetObj()->SetMenu(menu);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemBase::SetId(int itemid)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_SetId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_SetId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetId(itemid);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxMenuItemBase::GetId()
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_GetId::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_GetId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetId();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxMenuItemBase::IsSeparator()
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_IsSeparator::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_IsSeparator::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsSeparator();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemBase::SetText(wxString const & str)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_SetText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_SetText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & str = *str_smtptr;

  this->_objectptr->GetObj()->SetText(str);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxMenuItemBase::GetLabel()
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_GetLabel::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_GetLabel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetLabel();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString const & wxMenuItemBase::GetText()
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_GetText::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_GetText::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetText();
  return AMILabType<wxString >::CreateVar(res);
}
/* The following types are missing: wxItemKind

//---------------------------------------------------
//  Wrapping of wxItemKind wxMenuItemBase::GetKind()
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_GetKind::SetParametersComments()
{
  return_comments="returning a variable of type wxItemKind";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_GetKind::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxItemKind res =   this->_objectptr->GetObj()->GetKind();
  return AMILabType<wxItemKind >::CreateVar(res);
}
*/
/* The following types are missing: wxItemKind

//---------------------------------------------------
//  Wrapping of void wxMenuItemBase::SetKind(wxItemKind kind)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_SetKind::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxItemKind, "parameter named 'kind'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_SetKind::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxItemKind kind;
  if (!get_val_param<wxItemKind >(kind,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetKind(kind);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxMenuItemBase::SetCheckable(bool checkable)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_SetCheckable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'checkable'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_SetCheckable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int checkable_int;
  if (!get_val_param<int >(checkable_int,_p,_n,true,false)) ClassHelpAndReturn;
  bool checkable = (bool) (checkable_int>0.5);

  this->_objectptr->GetObj()->SetCheckable(checkable);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxMenuItemBase::IsCheckable()
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_IsCheckable::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_IsCheckable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsCheckable();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMenuItemBase::IsSubMenu()
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_IsSubMenu::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_IsSubMenu::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsSubMenu();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemBase::SetSubMenu(wxMenu * menu)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_SetSubMenu::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menu'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_SetSubMenu::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenu > menu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(menu_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenu* menu = menu_smtptr.get();

  this->_objectptr->GetObj()->SetSubMenu(menu);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxMenu * wxMenuItemBase::GetSubMenu()
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_GetSubMenu::SetParametersComments()
{
  return_comments="returning a variable of type wxMenu";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_GetSubMenu::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxMenu * res =   this->_objectptr->GetObj()->GetSubMenu();
  BasicVariable::ptr res_var = WrapClass_wxMenu::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemBase::Enable(bool enable = true)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_Enable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'enable' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_Enable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int enable_int = ((true==true)?1:0);;
  if (!get_val_param<int >(enable_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool enable = (bool) (enable_int>0.5);

  this->_objectptr->GetObj()->Enable(enable);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxMenuItemBase::IsEnabled()
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_IsEnabled::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_IsEnabled::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsEnabled();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemBase::Check(bool check = true)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_Check::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'check' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_Check::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int check_int = ((true==true)?1:0);;
  if (!get_val_param<int >(check_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool check = (bool) (check_int>0.5);

  this->_objectptr->GetObj()->Check(check);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxMenuItemBase::IsChecked()
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_IsChecked::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_IsChecked::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsChecked();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemBase::Toggle()
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_Toggle::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_Toggle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Toggle();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemBase::SetHelp(wxString const & str)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_SetHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_SetHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & str = *str_smtptr;

  this->_objectptr->GetObj()->SetHelp(str);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString const & wxMenuItemBase::GetHelp()
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_GetHelp::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_GetHelp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetHelp();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAcceleratorEntry * wxMenuItemBase::GetAccel()
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_GetAccel::SetParametersComments()
{
  return_comments="returning a variable of type wxAcceleratorEntry";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_GetAccel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAcceleratorEntry * res =   this->_objectptr->GetObj()->GetAccel();
  BasicVariable::ptr res_var = WrapClass_wxAcceleratorEntry::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemBase::SetAccel(wxAcceleratorEntry * accel)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_SetAccel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAcceleratorEntry, "parameter named 'accel'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_SetAccel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAcceleratorEntry > accel_smtptr;
  if (!get_val_smtptr_param<wxAcceleratorEntry >(accel_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAcceleratorEntry* accel = accel_smtptr.get();

  this->_objectptr->GetObj()->SetAccel(accel);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemBase::SetName(wxString const & str)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_SetName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_SetName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & str = *str_smtptr;

  this->_objectptr->GetObj()->SetName(str);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString const & wxMenuItemBase::GetName()
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_GetName::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_GetName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetName();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemBase::SetItemLabel(wxString const & str)
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_SetItemLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_SetItemLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & str = *str_smtptr;

  this->_objectptr->GetObj()->SetItemLabel(str);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxMenuItemBase::GetItemLabelText()
//---------------------------------------------------
void WrapClass_wxMenuItemBase::
    wrap_GetItemLabelText::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemBase::
    wrap_GetItemLabelText::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetItemLabelText();
  return AMILabType<wxString >::CreateVar(res);
}

