/**
 * C++ Interface: wrap_wxMenuBar
 *
 * Description: wrapping wxMenuBar
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

#include "wrap_wxMenuBar.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxWindow_declared
  #define wxWindow_declared
  AMI_DECLARE_TYPE(wxWindow)
#endif
#ifndef wxMenu_declared
  #define wxMenu_declared
  AMI_DECLARE_TYPE(wxMenu)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxMenuItem_declared
  #define wxMenuItem_declared
  AMI_DECLARE_TYPE(wxMenuItem)
#endif
#ifndef wxFrame_declared
  #define wxFrame_declared
  AMI_DECLARE_TYPE(wxFrame)
#endif
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxMenuBar>::CreateVar( ParamList* p)
{
  WrapClass_wxMenuBar::wrap_wxMenuBar construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxMenuBar);
AMI_DEFINE_VARFROMSMTPTR(wxMenuBar);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxMenuBar>::CreateVar( wxMenuBar* val, bool nodeleter)
{ 
  boost::shared_ptr<wxMenuBar> obj_ptr(val,smartpointer_nodeleter<wxMenuBar>());
  return AMILabType<wxMenuBar>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxMenuBar
//
Variable<AMIObject>::ptr WrapClass_wxMenuBar::CreateVar( wxMenuBar* sp)
{
  boost::shared_ptr<wxMenuBar> di_ptr(
    sp,
    wxwindow_nodeleter<wxMenuBar>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxMenuBar>::CreateVar(
      new WrapClass_wxMenuBar(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxMenuBar::AddMethods(WrapClass<wxMenuBar>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Append( this_ptr);
  AddVar_Insert( this_ptr);
  AddVar_Replace( this_ptr);
  AddVar_Remove( this_ptr);
  AddVar_FindMenuItem( this_ptr);
  AddVar_FindItem( this_ptr);
  AddVar_EnableTop( this_ptr);
  AddVar_SetLabelTop( this_ptr);
  AddVar_GetLabelTop( this_ptr);
  AddVar_SetLayoutDirection( this_ptr);
  AddVar_GetLayoutDirection( this_ptr);
  AddVar_Attach( this_ptr);
  AddVar_SetInvokingWindow( this_ptr);
  AddVar_UnsetInvokingWindow( this_ptr);
  AddVar_GtkAppend( this_ptr);
  AddVar_GetClassInfo( this_ptr);
  AddVar_GetMenuLabel( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());
  
  /* Type not available
  // Adding public member m_menubar
  boost::shared_ptr<_GtkWidget > var_m_menubar_ptr(GetObj()->m_menubar, smartpointer_nodeleter<_GtkWidget >());
  if (var_m_menubar_ptr.get()) {
    BasicVariable::ptr var_m_menubar = AMILabType<_GtkWidget >::CreateVarFromSmtPtr(var_m_menubar_ptr);
    if (var_m_menubar.get()) {
      var_m_menubar->Rename("m_menubar");
      context->AddVar(var_m_menubar,context);
    }
  }
  */
  
  // Adding public member m_style
  boost::shared_ptr<long int > var_m_style_ptr(&GetObj()->m_style, smartpointer_nodeleter<long int >());
  if (var_m_style_ptr.get()) {
    BasicVariable::ptr var_m_style = AMILabType<long int >::CreateVarFromSmtPtr(var_m_style_ptr);
    if (var_m_style.get()) {
      var_m_style->Rename("m_style");
      context->AddVar(var_m_style,context);
    }
  }
  
  // Adding public member m_invokingWindow
  boost::shared_ptr<wxWindow > var_m_invokingWindow_ptr(GetObj()->m_invokingWindow, smartpointer_nodeleter<wxWindow >());
  if (var_m_invokingWindow_ptr.get()) {
    BasicVariable::ptr var_m_invokingWindow = AMILabType<wxWindow >::CreateVarFromSmtPtr(var_m_invokingWindow_ptr);
    if (var_m_invokingWindow.get()) {
      var_m_invokingWindow->Rename("m_invokingWindow");
      context->AddVar(var_m_invokingWindow,context);
    }
  }


  


  // Adding Bases

  // Add base parent wxMenuBarBase
  boost::shared_ptr<wxMenuBarBase > parent_wxMenuBarBase(  boost::dynamic_pointer_cast<wxMenuBarBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxMenuBarBase = AMILabType<wxMenuBarBase >::CreateVarFromSmtPtr(parent_wxMenuBarBase);
  context->AddVar("wxMenuBarBase",var_wxMenuBarBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxMenuBarBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxMenuBarBase);
  context->AddDefault(obj_wxMenuBarBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxMenuBar_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxMenuBar");
    WrapClass_wxMenuBar::AddVar_wxMenuBar_1(amiobject->GetContext());
  WrapClass_wxMenuBar::AddVar_wxMenuBar(amiobject->GetContext());
  WrapClass_wxMenuBar::AddVar_wxMenuBar_2(amiobject->GetContext());
  WrapClass_wxMenuBar::AddVar_wxMenuBar_3(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxMenuBar::wxMenuBar()
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_wxMenuBar_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_wxMenuBar_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxMenuBar* _newobj = new wxMenuBar();
  BasicVariable::ptr res = WrapClass_wxMenuBar::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxMenuBar::wxMenuBar(...)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_wxMenuBar::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_wxMenuBar::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuBar::wrap_wxMenuBar_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuBar::wrap_wxMenuBar_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxMenuBar::wrap_wxMenuBar_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxMenuBar::wxMenuBar(long int style)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_wxMenuBar_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_wxMenuBar_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long style_long;
  if (!get_val_param<long >(style_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int style = style_long;

  wxMenuBar* _newobj = new wxMenuBar(style);
  BasicVariable::ptr res = WrapClass_wxMenuBar::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxMenuBar::wxMenuBar(size_t n, wxMenu * * menus, wxString const * titles, long int style = 0)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_wxMenuBar_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menus'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'titles'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_wxMenuBar_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  wxMenu* local_menus = NULL;
  wxMenu** menus;
  if (CheckNullVar(_p,_n))  {
    menus=(wxMenu**)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxMenu > menus_smtptr;
    if (!get_val_smtptr_param<wxMenu >(menus_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    local_menus = menus_smtptr.get();
    menus = &local_menus;
  }

  wxString* titles;
  if (CheckNullVar(_p,_n))  {
    titles=(wxString*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxString > titles_smtptr;
    if (!get_val_smtptr_param<wxString >(titles_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    titles = titles_smtptr.get();
  }

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  wxMenuBar* _newobj = new wxMenuBar(n, menus, titles, style);
  BasicVariable::ptr res = WrapClass_wxMenuBar::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBar::Append(wxMenu * menu, wxString const & title)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_Append::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menu'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_Append::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  wxMenu* menu;
  if (CheckNullVar(_p,_n))  {
    menu=(wxMenu*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxMenu > menu_smtptr;
    if (!get_val_smtptr_param<wxMenu >(menu_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    menu = menu_smtptr.get();
  }

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  bool res =   this->_objectptr->GetObj()->Append(menu, title);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBar::Insert(size_t pos, wxMenu * menu, wxString const & title)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_Insert::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menu'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_Insert::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  wxMenu* menu;
  if (CheckNullVar(_p,_n))  {
    menu=(wxMenu*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxMenu > menu_smtptr;
    if (!get_val_smtptr_param<wxMenu >(menu_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    menu = menu_smtptr.get();
  }

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  bool res =   this->_objectptr->GetObj()->Insert(pos, menu, title);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxMenu * wxMenuBar::Replace(size_t pos, wxMenu * menu, wxString const & title)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_Replace::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menu'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  return_comments="returning a variable of type wxMenu";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_Replace::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  wxMenu* menu;
  if (CheckNullVar(_p,_n))  {
    menu=(wxMenu*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxMenu > menu_smtptr;
    if (!get_val_smtptr_param<wxMenu >(menu_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    menu = menu_smtptr.get();
  }

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  wxMenu * res =   this->_objectptr->GetObj()->Replace(pos, menu, title);
  BasicVariable::ptr res_var = AMILabType<wxMenu >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMenu * wxMenuBar::Remove(size_t pos)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_Remove::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  return_comments="returning a variable of type wxMenu";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_Remove::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  wxMenu * res =   this->_objectptr->GetObj()->Remove(pos);
  BasicVariable::ptr res_var = AMILabType<wxMenu >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int wxMenuBar::FindMenuItem(wxString const & menuString, wxString const & itemString)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_FindMenuItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'menuString'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'itemString'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_FindMenuItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > menuString_smtptr;
  if (!get_val_smtptr_param<wxString >(menuString_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & menuString = *menuString_smtptr;

  boost::shared_ptr<wxString > itemString_smtptr;
  if (!get_val_smtptr_param<wxString >(itemString_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & itemString = *itemString_smtptr;

  int res =   this->_objectptr->GetObj()->FindMenuItem(menuString, itemString);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuBar::FindItem(int id, wxMenu * * menu = 0l)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_FindItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menu' (def:0l)")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_FindItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  wxMenu* local_menu = NULL;
  wxMenu** menu = 0l;
  if (CheckNullVar(_p,_n))  {
    menu=(wxMenu**)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxMenu > menu_smtptr;
    if (!get_val_smtptr_param<wxMenu >(menu_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    local_menu = menu_smtptr.get();
    menu = &local_menu;
  }

  wxMenuItem * res =   this->_objectptr->GetObj()->FindItem(id, menu);
  BasicVariable::ptr res_var = AMILabType<wxMenuItem >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxMenuBar::EnableTop(size_t pos, bool flag)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_EnableTop::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'flag'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_EnableTop::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  bool flag;
  if (!get_val_param<bool >(flag,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EnableTop(pos, flag);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuBar::SetLabelTop(size_t pos, wxString const & label)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_SetLabelTop::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_SetLabelTop::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetLabelTop(pos, label);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxMenuBar::GetLabelTop(size_t pos)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_GetLabelTop::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_GetLabelTop::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  wxString res =   this->_objectptr->GetObj()->GetLabelTop(pos);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxMenuBar::SetLayoutDirection(wxLayoutDirection dir)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_SetLayoutDirection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dir'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_SetLayoutDirection::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int dir_int;
  if (!get_val_param<int >(dir_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxLayoutDirection dir = (wxLayoutDirection) dir_int;

  this->_objectptr->GetObj()->SetLayoutDirection(dir);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxLayoutDirection wxMenuBar::GetLayoutDirection()
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_GetLayoutDirection::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_GetLayoutDirection::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxLayoutDirection res =   this->_objectptr->GetObj()->GetLayoutDirection();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxMenuBar::Attach(wxFrame * frame)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_Attach::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFrame, "parameter named 'frame'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_Attach::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxFrame* frame;
  if (CheckNullVar(_p,_n))  {
    frame=(wxFrame*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxFrame > frame_smtptr;
    if (!get_val_smtptr_param<wxFrame >(frame_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    frame = frame_smtptr.get();
  }

  this->_objectptr->GetObj()->Attach(frame);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuBar::SetInvokingWindow(wxWindow * win)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_SetInvokingWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'win'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_SetInvokingWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxWindow* win;
  if (CheckNullVar(_p,_n))  {
    win=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > win_smtptr;
    if (!get_val_smtptr_param<wxWindow >(win_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    win = win_smtptr.get();
  }

  this->_objectptr->GetObj()->SetInvokingWindow(win);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuBar::UnsetInvokingWindow(wxWindow * win)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_UnsetInvokingWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'win'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_UnsetInvokingWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxWindow* win;
  if (CheckNullVar(_p,_n))  {
    win=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > win_smtptr;
    if (!get_val_smtptr_param<wxWindow >(win_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    win = win_smtptr.get();
  }

  this->_objectptr->GetObj()->UnsetInvokingWindow(win);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxMenuBar::GtkAppend(wxMenu * menu, wxString const & title, int pos = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_GtkAppend::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menu'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pos' (def:-0x00000000000000001)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_GtkAppend::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  wxMenu* menu;
  if (CheckNullVar(_p,_n))  {
    menu=(wxMenu*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxMenu > menu_smtptr;
    if (!get_val_smtptr_param<wxMenu >(menu_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    menu = menu_smtptr.get();
  }

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  int pos = -0x00000000000000001;
  if (!get_val_param<int >(pos,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GtkAppend(menu, title, pos);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxMenuBar::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxString wxMenuBar::GetMenuLabel(size_t pos)
//---------------------------------------------------
void WrapClass_wxMenuBar::
    wrap_GetMenuLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuBar::
    wrap_GetMenuLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  wxString res =   this->_objectptr->GetObj()->GetMenuLabel(pos);
  return AMILabType<wxString >::CreateVar(res);
}

