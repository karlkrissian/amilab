/**
 * C++ Interface: wrap_wxMenuItem
 *
 * Description: wrapping wxMenuItem
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
#include "wrap_wxBitmap.h"
#include "wrap_wxAcceleratorEntry.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxMenuItem.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxMenuItem>::CreateVar( ParamList* p)
{
  WrapClass_wxMenuItem::wrap_wxMenuItem construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxMenuItem);
AMI_DEFINE_VARFROMSMTPTR(wxMenuItem);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxMenuItem>::CreateVar( wxMenuItem* val, bool nodeleter)
{ 
  boost::shared_ptr<wxMenuItem> obj_ptr(val,smartpointer_nodeleter<wxMenuItem>());
  return AMILabType<wxMenuItem>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxMenuItem
//
Variable<AMIObject>::ptr WrapClass_wxMenuItem::CreateVar( wxMenuItem* sp)
{
  boost::shared_ptr<wxMenuItem> di_ptr(
    sp,
    wxwindow_nodeleter<wxMenuItem>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxMenuItem>::CreateVar(
      new WrapClass_wxMenuItem(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxMenuItem::AddMethods(WrapClass<wxMenuItem>::ptr this_ptr )
{
  
      // Add members from wxMenuItemBase
      WrapClass_wxMenuItemBase::ptr parent_wxMenuItemBase(        boost::dynamic_pointer_cast<WrapClass_wxMenuItemBase >(this_ptr));
      parent_wxMenuItemBase->AddMethods(parent_wxMenuItemBase);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_SetText( this_ptr);
      AddVar_Enable( this_ptr);
      AddVar_Check( this_ptr);
      AddVar_IsChecked( this_ptr);
      AddVar_SetBitmap( this_ptr);
      AddVar_GetBitmap( this_ptr);
      AddVar_GetAccel( this_ptr);
/* The following types are missing: _GtkWidget
      AddVar_SetMenuItem( this_ptr);
*/
/* The following types are missing: _GtkWidget
      AddVar_GetMenuItem( this_ptr);
*/
/* The following types are missing: _GtkWidget
      AddVar_GetLabelWidget( this_ptr);
*/
/* The following types are missing: _GtkWidget
      AddVar_SetLabelWidget( this_ptr);
*/
      AddVar_GetHotKey( this_ptr);
      AddVar_GetClassInfo( this_ptr);
      AddVar_GetItemLabel( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------

/* The following types are missing: wxItemKind

//---------------------------------------------------
//  Wrapping of Constructor wxMenuItem::wxMenuItem(wxMenu * parentMenu = 0u, int id = wxID_SEPARATOR, wxString const & text = wxEmptyString, wxString const & help = wxEmptyString, wxItemKind kind = wxITEM_NORMAL, wxMenu * subMenu = 0u)
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_wxMenuItem_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'parentMenu' (def:0u)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id' (def:wxID_SEPARATOR)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxItemKind, "parameter named 'kind' (def:wxITEM_NORMAL)")
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'subMenu' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_wxMenuItem_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMenu > parentMenu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(parentMenu_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMenu* parentMenu = parentMenu_smtptr.get();

  int id = wxID_SEPARATOR;
  if (!get_val_param<int >(id,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & text = ( text_smtptr.get() ? (*text_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxString > help_smtptr;
  if (!get_val_smtptr_param<wxString >(help_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & help = ( help_smtptr.get() ? (*help_smtptr) : wxString(wxEmptyString) );

  wxItemKind kind = wxITEM_NORMAL;
  if (!get_val_param<wxItemKind >(kind,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxMenu > subMenu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(subMenu_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMenu* subMenu = subMenu_smtptr.get();

  wxMenuItem* _newobj = new wxMenuItem(parentMenu, id, text, help, kind, subMenu);
  BasicVariable::ptr res = WrapClass_wxMenuItem::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxMenuItem::wxMenuItem(...)
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_wxMenuItem::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_wxMenuItem::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuItem::wrap_wxMenuItem_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxMenuItem::wxMenuItem(wxMenu * parentMenu, int id, wxString const & text, wxString const & help, bool isCheckable, wxMenu * subMenu = 0u)
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_wxMenuItem_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'parentMenu'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'isCheckable'")
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'subMenu' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_wxMenuItem_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMenu > parentMenu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(parentMenu_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMenu* parentMenu = parentMenu_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxString > help_smtptr;
  if (!get_val_smtptr_param<wxString >(help_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & help = *help_smtptr;

  int isCheckable_int;
  if (!get_val_param<int >(isCheckable_int,_p,_n)) ClassReturnEmptyVar;
  bool isCheckable = (bool) (isCheckable_int>0.5);

  boost::shared_ptr<wxMenu > subMenu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(subMenu_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMenu* subMenu = subMenu_smtptr.get();

  wxMenuItem* _newobj = new wxMenuItem(parentMenu, id, text, help, isCheckable, subMenu);
  BasicVariable::ptr res = WrapClass_wxMenuItem::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxString wxMenuItem::GTKProcessMenuItemLabel(wxString const & str, wxString * hotKey)
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_GTKProcessMenuItemLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'hotKey'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_GTKProcessMenuItemLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & str = *str_smtptr;

  boost::shared_ptr<wxString > hotKey_smtptr;
  if (!get_val_smtptr_param<wxString >(hotKey_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString* hotKey = hotKey_smtptr.get();

  wxString res =   wxMenuItem::GTKProcessMenuItemLabel(str, hotKey);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxMenuItem::SetText(wxString const & str)
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_SetText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_SetText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & str = *str_smtptr;

  this->_objectptr->GetObj()->SetText(str);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuItem::Enable(bool enable = 1)
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_Enable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'enable' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_Enable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int enable_int = ((1==true)?1:0);;
  if (!get_val_param<int >(enable_int,_p,_n)) ClassHelpAndReturn;
  bool enable = (bool) (enable_int>0.5);

  this->_objectptr->GetObj()->Enable(enable);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuItem::Check(bool check = 1)
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_Check::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'check' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_Check::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int check_int = ((1==true)?1:0);;
  if (!get_val_param<int >(check_int,_p,_n)) ClassHelpAndReturn;
  bool check = (bool) (check_int>0.5);

  this->_objectptr->GetObj()->Check(check);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxMenuItem::IsChecked()
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_IsChecked::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_IsChecked::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsChecked();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxMenuItem::SetBitmap(wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_SetBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_SetBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  this->_objectptr->GetObj()->SetBitmap(bitmap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxBitmap const & wxMenuItem::GetBitmap()
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_GetBitmap::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_GetBitmap::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap const & res =   this->_objectptr->GetObj()->GetBitmap();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAcceleratorEntry * wxMenuItem::GetAccel()
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_GetAccel::SetParametersComments()
{
  return_comments="returning a variable of type wxAcceleratorEntry";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_GetAccel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAcceleratorEntry * res =   this->_objectptr->GetObj()->GetAccel();
  BasicVariable::ptr res_var = WrapClass_wxAcceleratorEntry::CreateVar(res);
  return res_var;
}
/* The following types are missing: _GtkWidget

//---------------------------------------------------
//  Wrapping of void wxMenuItem::SetMenuItem(GtkWidget * menuItem)
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_SetMenuItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GtkWidget, "parameter named 'menuItem'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_SetMenuItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<_GtkWidget > menuItem_smtptr;
  if (!get_val_smtptr_param<_GtkWidget >(menuItem_smtptr,_p,_n)) ClassHelpAndReturn;
  _GtkWidget* menuItem = menuItem_smtptr.get();

  this->_objectptr->GetObj()->SetMenuItem(menuItem);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: _GtkWidget

//---------------------------------------------------
//  Wrapping of GtkWidget * wxMenuItem::GetMenuItem()
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_GetMenuItem::SetParametersComments()
{
  return_comments="returning a variable of type _GtkWidget";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_GetMenuItem::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  GtkWidget * res =   this->_objectptr->GetObj()->GetMenuItem();
  return AMILabType<_GtkWidget >::CreateVar(res,true);
}
*/
/* The following types are missing: _GtkWidget

//---------------------------------------------------
//  Wrapping of GtkWidget * wxMenuItem::GetLabelWidget()
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_GetLabelWidget::SetParametersComments()
{
  return_comments="returning a variable of type _GtkWidget";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_GetLabelWidget::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  GtkWidget * res =   this->_objectptr->GetObj()->GetLabelWidget();
  return AMILabType<_GtkWidget >::CreateVar(res,true);
}
*/
/* The following types are missing: _GtkWidget

//---------------------------------------------------
//  Wrapping of void wxMenuItem::SetLabelWidget(GtkWidget * labelWidget)
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_SetLabelWidget::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GtkWidget, "parameter named 'labelWidget'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_SetLabelWidget::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<_GtkWidget > labelWidget_smtptr;
  if (!get_val_smtptr_param<_GtkWidget >(labelWidget_smtptr,_p,_n)) ClassHelpAndReturn;
  _GtkWidget* labelWidget = labelWidget_smtptr.get();

  this->_objectptr->GetObj()->SetLabelWidget(labelWidget);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of wxString wxMenuItem::GetHotKey()
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_GetHotKey::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_GetHotKey::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetHotKey();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxMenuItem::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxString wxMenuItem::GetItemLabel()
//---------------------------------------------------
void WrapClass_wxMenuItem::
    wrap_GetItemLabel::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItem::
    wrap_GetItemLabel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetItemLabel();
  return AMILabType<wxString >::CreateVar(res);
}

