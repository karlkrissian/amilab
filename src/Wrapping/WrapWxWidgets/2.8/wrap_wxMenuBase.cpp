/**
 * C++ Interface: wrap_wxMenuBase
 *
 * Description: wrapping wxMenuBase
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
#include "wrap_wxMenuItem.h"
#include "wrap_wxMenu.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxWindow.h"
#include "wrap_wxMenuBar.h"
#include "wrap_wxMenuBarBase.h"


#include "wrap_wxMenuBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxMenuBase>::CreateVar( ParamList* p)
{
  WrapClass_wxMenuBase::wrap_wxMenuBase construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxMenuBase);
AMI_DEFINE_VARFROMSMTPTR(wxMenuBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxMenuBase>::CreateVar( wxMenuBase* val, bool nodeleter)
{ 
  boost::shared_ptr<wxMenuBase> obj_ptr(val,smartpointer_nodeleter<wxMenuBase>());
  return AMILabType<wxMenuBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxMenuBase
//
Variable<AMIObject>::ptr WrapClass_wxMenuBase::CreateVar( wxMenuBase* sp)
{
  boost::shared_ptr<wxMenuBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxMenuBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxMenuBase>::CreateVar(
      new WrapClass_wxMenuBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxMenuBase::AddMethods(WrapClass<wxMenuBase>::ptr this_ptr )
{
  /*
      // Add members from wxEvtHandler
      WrapClass_wxEvtHandler::ptr parent_wxEvtHandler(        boost::dynamic_pointer_cast<WrapClass_wxEvtHandler >(this_ptr));
      parent_wxEvtHandler->AddMethods(parent_wxEvtHandler);
      */


  // check that the method name is not a token
  
      // Adding standard methods 
/* The following types are missing: wxItemKind
      AddVar_Append_1( this_ptr);
*/
      AddVar_AppendSeparator( this_ptr);
      AddVar_AppendCheckItem( this_ptr);
      AddVar_AppendRadioItem( this_ptr);
      AddVar_AppendSubMenu( this_ptr);
      AddVar_Append( this_ptr);
      AddVar_Append_2( this_ptr);
      AddVar_Break( this_ptr);
      AddVar_Insert_1( this_ptr);
      AddVar_Insert( this_ptr);
/* The following types are missing: wxItemKind
      AddVar_Insert_2( this_ptr);
*/
      AddVar_InsertSeparator( this_ptr);
      AddVar_InsertCheckItem( this_ptr);
      AddVar_InsertRadioItem( this_ptr);
      AddVar_Insert_3( this_ptr);
      AddVar_Prepend_1( this_ptr);
      AddVar_Prepend( this_ptr);
/* The following types are missing: wxItemKind
      AddVar_Prepend_2( this_ptr);
*/
      AddVar_PrependSeparator( this_ptr);
      AddVar_PrependCheckItem( this_ptr);
      AddVar_PrependRadioItem( this_ptr);
      AddVar_Prepend_3( this_ptr);
      AddVar_Remove_1( this_ptr);
      AddVar_Remove( this_ptr);
      AddVar_Remove_2( this_ptr);
      AddVar_Delete_1( this_ptr);
      AddVar_Delete( this_ptr);
      AddVar_Delete_2( this_ptr);
      AddVar_Destroy_1( this_ptr);
      AddVar_Destroy( this_ptr);
      AddVar_Destroy_2( this_ptr);
      AddVar_GetMenuItemCount( this_ptr);
/* The following types are missing: wxMenuItemList
      AddVar_GetMenuItems_1( this_ptr);
*/
      AddVar_GetMenuItems( this_ptr);
/* The following types are missing: wxMenuItemList
      AddVar_GetMenuItems_2( this_ptr);
*/
      AddVar_FindItem_1( this_ptr);
      AddVar_FindItem( this_ptr);
/* The following types are missing: wxMenu * *
      AddVar_FindItem_2( this_ptr);
*/
      AddVar_FindItemByPosition( this_ptr);
      AddVar_Enable( this_ptr);
      AddVar_IsEnabled( this_ptr);
      AddVar_Check( this_ptr);
      AddVar_IsChecked( this_ptr);
      AddVar_SetLabel( this_ptr);
      AddVar_GetLabel( this_ptr);
      AddVar_SetHelpString( this_ptr);
      AddVar_GetHelpString( this_ptr);
      AddVar_SetTitle( this_ptr);
      AddVar_GetTitle( this_ptr);
/* The following types are missing: wxEvtHandler
      AddVar_SetEventHandler( this_ptr);
*/
/* The following types are missing: wxEvtHandler
      AddVar_GetEventHandler( this_ptr);
*/
      AddVar_SetInvokingWindow( this_ptr);
      AddVar_GetInvokingWindow( this_ptr);
      AddVar_GetStyle( this_ptr);
/* The following types are missing: wxEvtHandler
      AddVar_UpdateUI( this_ptr);
*/
      AddVar_GetMenuBar( this_ptr);
      AddVar_Attach( this_ptr);
      AddVar_Detach( this_ptr);
      AddVar_IsAttached( this_ptr);
      AddVar_SetParent( this_ptr);
      AddVar_GetParent( this_ptr);
      AddVar_FindChildItem( this_ptr);
      AddVar_SendEvent( this_ptr);
      AddVar_Append_3( this_ptr);
      AddVar_Append_4( this_ptr);
      AddVar_Insert_4( this_ptr);
      AddVar_Prepend_4( this_ptr);
      AddVar_GetLabelText( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxMenuBase::wxMenuBase(wxString const & title, long int style = 0)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_wxMenuBase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_wxMenuBase_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & title = *title_smtptr;

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  wxMenuBase* _newobj = new wxMenuBase(title, style);
  BasicVariable::ptr res = WrapClass_wxMenuBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxMenuBase::wxMenuBase(...)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_wxMenuBase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_wxMenuBase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuBase::wrap_wxMenuBase_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuBase::wrap_wxMenuBase_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxMenuBase::wxMenuBase(long int style = 0)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_wxMenuBase_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_wxMenuBase_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  wxMenuBase* _newobj = new wxMenuBase(style);
  BasicVariable::ptr res = WrapClass_wxMenuBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxMenuBase::LockAccels(bool locked)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_static_LockAccels::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'locked'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_static_LockAccels::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int locked_int;
  if (!get_val_param<int >(locked_int,_p,_n,true,false)) ClassHelpAndReturn;
  bool locked = (bool) (locked_int>0.5);

  wxMenuBase::LockAccels(locked);
  return BasicVariable::ptr();
}
/* The following types are missing: wxItemKind

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::Append(int itemid, wxString const & text = wxEmptyString, wxString const & help = wxEmptyString, wxItemKind kind = wxITEM_NORMAL)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Append_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxItemKind, "parameter named 'kind' (def:wxITEM_NORMAL)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Append_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,true)) ClassReturnEmptyVar;

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

  wxMenuItem * res =   this->_objectptr->GetObj()->Append(itemid, text, help, kind);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::AppendSeparator()
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_AppendSeparator::SetParametersComments()
{
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_AppendSeparator::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxMenuItem * res =   this->_objectptr->GetObj()->AppendSeparator();
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::AppendCheckItem(int itemid, wxString const & text, wxString const & help = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_AppendCheckItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help' (def:wxEmptyString)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_AppendCheckItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxString > help_smtptr;
  if (!get_val_smtptr_param<wxString >(help_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & help = ( help_smtptr.get() ? (*help_smtptr) : wxString(wxEmptyString) );

  wxMenuItem * res =   this->_objectptr->GetObj()->AppendCheckItem(itemid, text, help);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::AppendRadioItem(int itemid, wxString const & text, wxString const & help = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_AppendRadioItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help' (def:wxEmptyString)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_AppendRadioItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxString > help_smtptr;
  if (!get_val_smtptr_param<wxString >(help_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & help = ( help_smtptr.get() ? (*help_smtptr) : wxString(wxEmptyString) );

  wxMenuItem * res =   this->_objectptr->GetObj()->AppendRadioItem(itemid, text, help);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::AppendSubMenu(wxMenu * submenu, wxString const & text, wxString const & help = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_AppendSubMenu::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'submenu'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help' (def:wxEmptyString)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_AppendSubMenu::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenu > submenu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(submenu_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenu* submenu = submenu_smtptr.get();

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxString > help_smtptr;
  if (!get_val_smtptr_param<wxString >(help_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & help = ( help_smtptr.get() ? (*help_smtptr) : wxString(wxEmptyString) );

  wxMenuItem * res =   this->_objectptr->GetObj()->AppendSubMenu(submenu, text, help);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuBase::Append(...)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Append::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Append::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuBase::wrap_Append_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxMenuBase::wrap_Append_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxMenuBase::wrap_Append_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::Append(wxMenuItem * item)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Append_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'item'")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Append_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMenuItem > item_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(item_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenuItem* item = item_smtptr.get();

  wxMenuItem * res =   this->_objectptr->GetObj()->Append(item);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxMenuBase::Break()
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Break::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Break::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Break();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::Insert(size_t pos, wxMenuItem * item)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Insert_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'item'")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Insert_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  boost::shared_ptr<wxMenuItem > item_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(item_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenuItem* item = item_smtptr.get();

  wxMenuItem * res =   this->_objectptr->GetObj()->Insert(pos, item);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuBase::Insert(...)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Insert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Insert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuBase::wrap_Insert_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuBase::wrap_Insert_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxMenuBase::wrap_Insert_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxItemKind

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::Insert(size_t pos, int itemid, wxString const & text = wxEmptyString, wxString const & help = wxEmptyString, wxItemKind kind = wxITEM_NORMAL)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Insert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxItemKind, "parameter named 'kind' (def:wxITEM_NORMAL)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Insert_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,true)) ClassReturnEmptyVar;

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

  wxMenuItem * res =   this->_objectptr->GetObj()->Insert(pos, itemid, text, help, kind);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::InsertSeparator(size_t pos)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_InsertSeparator::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_InsertSeparator::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  wxMenuItem * res =   this->_objectptr->GetObj()->InsertSeparator(pos);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::InsertCheckItem(size_t pos, int itemid, wxString const & text, wxString const & help = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_InsertCheckItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help' (def:wxEmptyString)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_InsertCheckItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxString > help_smtptr;
  if (!get_val_smtptr_param<wxString >(help_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & help = ( help_smtptr.get() ? (*help_smtptr) : wxString(wxEmptyString) );

  wxMenuItem * res =   this->_objectptr->GetObj()->InsertCheckItem(pos, itemid, text, help);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::InsertRadioItem(size_t pos, int itemid, wxString const & text, wxString const & help = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_InsertRadioItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help' (def:wxEmptyString)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_InsertRadioItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxString > help_smtptr;
  if (!get_val_smtptr_param<wxString >(help_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & help = ( help_smtptr.get() ? (*help_smtptr) : wxString(wxEmptyString) );

  wxMenuItem * res =   this->_objectptr->GetObj()->InsertRadioItem(pos, itemid, text, help);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::Insert(size_t pos, int itemid, wxString const & text, wxMenu * submenu, wxString const & help = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Insert_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'submenu'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help' (def:wxEmptyString)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Insert_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxMenu > submenu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(submenu_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenu* submenu = submenu_smtptr.get();

  boost::shared_ptr<wxString > help_smtptr;
  if (!get_val_smtptr_param<wxString >(help_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & help = ( help_smtptr.get() ? (*help_smtptr) : wxString(wxEmptyString) );

  wxMenuItem * res =   this->_objectptr->GetObj()->Insert(pos, itemid, text, submenu, help);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::Prepend(wxMenuItem * item)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Prepend_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'item'")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Prepend_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMenuItem > item_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(item_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenuItem* item = item_smtptr.get();

  wxMenuItem * res =   this->_objectptr->GetObj()->Prepend(item);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuBase::Prepend(...)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Prepend::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Prepend::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuBase::wrap_Prepend_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuBase::wrap_Prepend_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxMenuBase::wrap_Prepend_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxItemKind

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::Prepend(int itemid, wxString const & text = wxEmptyString, wxString const & help = wxEmptyString, wxItemKind kind = wxITEM_NORMAL)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Prepend_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxItemKind, "parameter named 'kind' (def:wxITEM_NORMAL)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Prepend_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,true)) ClassReturnEmptyVar;

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

  wxMenuItem * res =   this->_objectptr->GetObj()->Prepend(itemid, text, help, kind);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::PrependSeparator()
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_PrependSeparator::SetParametersComments()
{
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_PrependSeparator::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxMenuItem * res =   this->_objectptr->GetObj()->PrependSeparator();
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::PrependCheckItem(int itemid, wxString const & text, wxString const & help = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_PrependCheckItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help' (def:wxEmptyString)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_PrependCheckItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxString > help_smtptr;
  if (!get_val_smtptr_param<wxString >(help_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & help = ( help_smtptr.get() ? (*help_smtptr) : wxString(wxEmptyString) );

  wxMenuItem * res =   this->_objectptr->GetObj()->PrependCheckItem(itemid, text, help);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::PrependRadioItem(int itemid, wxString const & text, wxString const & help = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_PrependRadioItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help' (def:wxEmptyString)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_PrependRadioItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxString > help_smtptr;
  if (!get_val_smtptr_param<wxString >(help_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & help = ( help_smtptr.get() ? (*help_smtptr) : wxString(wxEmptyString) );

  wxMenuItem * res =   this->_objectptr->GetObj()->PrependRadioItem(itemid, text, help);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::Prepend(int itemid, wxString const & text, wxMenu * submenu, wxString const & help = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Prepend_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'submenu'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help' (def:wxEmptyString)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Prepend_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxMenu > submenu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(submenu_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenu* submenu = submenu_smtptr.get();

  boost::shared_ptr<wxString > help_smtptr;
  if (!get_val_smtptr_param<wxString >(help_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & help = ( help_smtptr.get() ? (*help_smtptr) : wxString(wxEmptyString) );

  wxMenuItem * res =   this->_objectptr->GetObj()->Prepend(itemid, text, submenu, help);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::Remove(int itemid)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Remove_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Remove_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,true)) ClassReturnEmptyVar;

  wxMenuItem * res =   this->_objectptr->GetObj()->Remove(itemid);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuBase::Remove(...)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Remove::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Remove::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuBase::wrap_Remove_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuBase::wrap_Remove_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::Remove(wxMenuItem * item)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Remove_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'item'")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Remove_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMenuItem > item_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(item_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenuItem* item = item_smtptr.get();

  wxMenuItem * res =   this->_objectptr->GetObj()->Remove(item);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBase::Delete(int itemid)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Delete_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Delete_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Delete(itemid);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuBase::Delete(...)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Delete::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Delete::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuBase::wrap_Delete_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuBase::wrap_Delete_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBase::Delete(wxMenuItem * item)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Delete_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'item'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Delete_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMenuItem > item_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(item_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenuItem* item = item_smtptr.get();

  bool res =   this->_objectptr->GetObj()->Delete(item);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBase::Destroy(int itemid)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Destroy_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Destroy_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Destroy(itemid);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuBase::Destroy(...)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Destroy::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Destroy::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuBase::wrap_Destroy_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuBase::wrap_Destroy_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBase::Destroy(wxMenuItem * item)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Destroy_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'item'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Destroy_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMenuItem > item_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(item_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenuItem* item = item_smtptr.get();

  bool res =   this->_objectptr->GetObj()->Destroy(item);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of size_t wxMenuBase::GetMenuItemCount()
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_GetMenuItemCount::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_GetMenuItemCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->GetMenuItemCount();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}
/* The following types are missing: wxMenuItemList

//---------------------------------------------------
//  Wrapping of wxMenuItemList const & wxMenuBase::GetMenuItems()
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_GetMenuItems_1::SetParametersComments()
{
  return_comments="returning a variable of type wxMenuItemList";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_GetMenuItems_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxMenuItemList const & res =   this->_objectptr->GetObj()->GetMenuItems();
  return AMILabType<wxMenuItemList >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuBase::GetMenuItems(...)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_GetMenuItems::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_GetMenuItems::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxMenuItemList

//---------------------------------------------------
//  Wrapping of wxMenuItemList & wxMenuBase::GetMenuItems()
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_GetMenuItems_2::SetParametersComments()
{
  return_comments="returning a variable of type wxMenuItemList";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_GetMenuItems_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxMenuItemList & res =   this->_objectptr->GetObj()->GetMenuItems();
  return AMILabType<wxMenuItemList >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of int wxMenuBase::FindItem(wxString const & item)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_FindItem_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'item'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_FindItem_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > item_smtptr;
  if (!get_val_smtptr_param<wxString >(item_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & item = *item_smtptr;

  int res =   this->_objectptr->GetObj()->FindItem(item);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuBase::FindItem(...)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_FindItem::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_FindItem::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuBase::wrap_FindItem_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxMenu * *

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::FindItem(int itemid, wxMenu * * menu = 0l)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_FindItem_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menu' (def:0l)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_FindItem_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxMenu > menu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(menu_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenu* menu = menu_smtptr.get();

  wxMenuItem * res =   this->_objectptr->GetObj()->FindItem(itemid, menu);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::FindItemByPosition(size_t position)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_FindItemByPosition::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'position'")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_FindItemByPosition::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long position_long;
  if (!get_val_param<long >(position_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int position = boost::numeric_cast<long unsigned int >(position_long);

  wxMenuItem * res =   this->_objectptr->GetObj()->FindItemByPosition(position);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxMenuBase::Enable(int itemid, bool enable)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Enable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'enable'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Enable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  int enable_int;
  if (!get_val_param<int >(enable_int,_p,_n,true,false)) ClassHelpAndReturn;
  bool enable = (bool) (enable_int>0.5);

  this->_objectptr->GetObj()->Enable(itemid, enable);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBase::IsEnabled(int itemid)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_IsEnabled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_IsEnabled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsEnabled(itemid);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxMenuBase::Check(int itemid, bool check)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Check::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'check'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Check::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  int check_int;
  if (!get_val_param<int >(check_int,_p,_n,true,false)) ClassHelpAndReturn;
  bool check = (bool) (check_int>0.5);

  this->_objectptr->GetObj()->Check(itemid, check);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBase::IsChecked(int itemid)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_IsChecked::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_IsChecked::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsChecked(itemid);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxMenuBase::SetLabel(int itemid, wxString const & label)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_SetLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_SetLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & label = *label_smtptr;

  this->_objectptr->GetObj()->SetLabel(itemid, label);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxMenuBase::GetLabel(int itemid)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_GetLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_GetLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetLabel(itemid);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxMenuBase::SetHelpString(int itemid, wxString const & helpString)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_SetHelpString::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'helpString'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
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
//  Wrapping of wxString wxMenuBase::GetHelpString(int itemid)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_GetHelpString::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
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
//  Wrapping of void wxMenuBase::SetTitle(wxString const & title)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_SetTitle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_SetTitle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  this->_objectptr->GetObj()->SetTitle(title);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString const wxMenuBase::GetTitle()
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_GetTitle::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_GetTitle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const res =   this->_objectptr->GetObj()->GetTitle();
  return AMILabType<wxString >::CreateVar(res);
}
/* The following types are missing: wxEvtHandler

//---------------------------------------------------
//  Wrapping of void wxMenuBase::SetEventHandler(wxEvtHandler * handler)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_SetEventHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEvtHandler, "parameter named 'handler'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_SetEventHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxEvtHandler > handler_smtptr;
  if (!get_val_smtptr_param<wxEvtHandler >(handler_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxEvtHandler* handler = handler_smtptr.get();

  this->_objectptr->GetObj()->SetEventHandler(handler);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxEvtHandler

//---------------------------------------------------
//  Wrapping of wxEvtHandler * wxMenuBase::GetEventHandler()
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_GetEventHandler::SetParametersComments()
{
  return_comments="returning a variable of type wxEvtHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_GetEventHandler::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvtHandler * res =   this->_objectptr->GetObj()->GetEventHandler();
  return AMILabType<wxEvtHandler >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void wxMenuBase::SetInvokingWindow(wxWindow * win)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_SetInvokingWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'win'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_SetInvokingWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > win_smtptr;
  if (!get_val_smtptr_param<wxWindow >(win_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* win = win_smtptr.get();

  this->_objectptr->GetObj()->SetInvokingWindow(win);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxMenuBase::GetInvokingWindow()
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_GetInvokingWindow::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_GetInvokingWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetInvokingWindow();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of long int wxMenuBase::GetStyle()
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_GetStyle::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_GetStyle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   this->_objectptr->GetObj()->GetStyle();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}
/* The following types are missing: wxEvtHandler

//---------------------------------------------------
//  Wrapping of void wxMenuBase::UpdateUI(wxEvtHandler * source = 0u)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_UpdateUI::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEvtHandler, "parameter named 'source' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_UpdateUI::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxEvtHandler > source_smtptr;
  if (!get_val_smtptr_param<wxEvtHandler >(source_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxEvtHandler* source = source_smtptr.get();

  this->_objectptr->GetObj()->UpdateUI(source);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of wxMenuBar * wxMenuBase::GetMenuBar()
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_GetMenuBar::SetParametersComments()
{
  return_comments="returning a variable of type wxMenuBar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_GetMenuBar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxMenuBar * res =   this->_objectptr->GetObj()->GetMenuBar();
  BasicVariable::ptr res_var = WrapClass_wxMenuBar::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxMenuBase::Attach(wxMenuBarBase * menubar)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Attach::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuBarBase, "parameter named 'menubar'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Attach::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenuBarBase > menubar_smtptr;
  if (!get_val_smtptr_param<wxMenuBarBase >(menubar_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenuBarBase* menubar = menubar_smtptr.get();

  this->_objectptr->GetObj()->Attach(menubar);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuBase::Detach()
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Detach::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Detach::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Detach();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBase::IsAttached()
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_IsAttached::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_IsAttached::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsAttached();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxMenuBase::SetParent(wxMenu * parent)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_SetParent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'parent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_SetParent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenu > parent_smtptr;
  if (!get_val_smtptr_param<wxMenu >(parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenu* parent = parent_smtptr.get();

  this->_objectptr->GetObj()->SetParent(parent);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxMenu * wxMenuBase::GetParent()
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_GetParent::SetParametersComments()
{
  return_comments="returning a variable of type wxMenu";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_GetParent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxMenu * res =   this->_objectptr->GetObj()->GetParent();
  BasicVariable::ptr res_var = WrapClass_wxMenu::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::FindChildItem(int itemid, size_t * pos = 0l)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_FindChildItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos' (def:0l)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_FindChildItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<long > pos_long;
  if (!get_val_smtptr_param<long >(pos_long,_p,_n,true,false,false)) ClassHelpAndReturn;
  long unsigned int pos_val = boost::numeric_cast<long unsigned int >(*pos_long);
  long unsigned int* pos = &pos_val;

  wxMenuItem * res =   this->_objectptr->GetObj()->FindChildItem(itemid, pos);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBase::SendEvent(int itemid, int checked = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_SendEvent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'checked' (def:-0x00000000000000001)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_SendEvent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  int checked = -0x00000000000000001;
  if (!get_val_param<int >(checked,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->SendEvent(itemid, checked);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxMenuBase::Append(int itemid, wxString const & text, wxString const & help, bool isCheckable)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Append_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'isCheckable'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Append_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

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

  this->_objectptr->GetObj()->Append(itemid, text, help, isCheckable);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBase::Append(int itemid, wxString const & text, wxMenu * submenu, wxString const & help = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Append_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'submenu'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help' (def:wxEmptyString)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Append_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxMenu > submenu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(submenu_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenu* submenu = submenu_smtptr.get();

  boost::shared_ptr<wxString > help_smtptr;
  if (!get_val_smtptr_param<wxString >(help_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & help = ( help_smtptr.get() ? (*help_smtptr) : wxString(wxEmptyString) );

  wxMenuItem * res =   this->_objectptr->GetObj()->Append(itemid, text, submenu, help);
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxMenuBase::Insert(size_t pos, int itemid, wxString const & text, wxString const & help, bool isCheckable)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Insert_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'isCheckable'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Insert_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

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

  this->_objectptr->GetObj()->Insert(pos, itemid, text, help, isCheckable);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuBase::Prepend(int itemid, wxString const & text, wxString const & help, bool isCheckable)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_Prepend_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'isCheckable'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_Prepend_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

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

  this->_objectptr->GetObj()->Prepend(itemid, text, help, isCheckable);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxMenuBase::GetLabelText(int itemid)
//---------------------------------------------------
void WrapClass_wxMenuBase::
    wrap_GetLabelText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'itemid'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBase::
    wrap_GetLabelText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int itemid;
  if (!get_val_param<int >(itemid,_p,_n,true,false)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetLabelText(itemid);
  return AMILabType<wxString >::CreateVar(res);
}

