/**
 * C++ Interface: wrap_wxFrame
 *
 * Description: wrapping wxFrame
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_wxFrame.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxWindow.h"
#include "wrap_wxString.h"
#include "wrap_wxPoint.h"
#include "wrap_wxSize.h"
#include "wrap_wxClassInfo.h"
#include "wrap_wxObject.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxFrame>::CreateVar( ParamList* p)
{
  WrapClass_wxFrame::wrap_wxFrame construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxFrame);

//
// static member for creating a variable from a pointer to wxFrame
//
Variable<AMIObject>::ptr WrapClass_wxFrame::CreateVar( wxFrame* sp)
{
  boost::shared_ptr<wxFrame> di_ptr(
    sp,
    wxwindow_nodeleter<wxFrame>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxFrame>::CreateVar(
      new WrapClass_wxFrame(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor wxFrame::wxFrame()
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_wxFrame1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_wxFrame1::CallMember( ParamList* _p)
{
  wxFrame* _newobj = new wxFrame();
  BasicVariable::ptr res = WrapClass_wxFrame::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxFrame::wxFrame(...)
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_wxFrame::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_wxFrame::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFrame::wrap_wxFrame1 m1;
  res = m1.CallMember(_p);
  if (res.get()) return res;
  WrapClass_wxFrame::wrap_wxFrame2 m2;
  res = m2.CallMember(_p);
  if (res.get()) return res;
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of Constructor wxFrame::wxFrame(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos, wxSize const & size, long int style, wxString const & name)
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_wxFrame2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_wxFrame2::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxWindow* parent;
  if (!get_val_ptr_param<wxWindow>(parent,_p,_n)) ClassHelpAndReturn;
  int id;
  if (!get_val_param<int>(id,_p,_n)) ClassHelpAndReturn;
  wxString* title_ptr;
  if (!get_val_ptr_param<wxString>(title_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& title = *title_ptr;
  wxPoint* pos_ptr;
  if (!get_val_ptr_param<wxPoint>(pos_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& pos = *pos_ptr;
  wxSize* size_ptr;
  if (!get_val_ptr_param<wxSize>(size_ptr,_p,_n)) ClassHelpAndReturn;
  wxSize& size = *size_ptr;
  long style_long;
  if (!get_val_param<long>(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;
  wxString* name_ptr;
  if (!get_val_ptr_param<wxString>(name_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& name = *name_ptr;
  wxFrame* _newobj = new wxFrame(parent, id, title, pos, size, style, name);
  BasicVariable::ptr res = WrapClass_wxFrame::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of bool wxFrame::Create(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos, wxSize const & size, long int style, wxString const & name)
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxWindow* parent;
  if (!get_val_ptr_param<wxWindow>(parent,_p,_n)) ClassHelpAndReturn;
  int id;
  if (!get_val_param<int>(id,_p,_n)) ClassHelpAndReturn;
  wxString* title_ptr;
  if (!get_val_ptr_param<wxString>(title_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& title = *title_ptr;
  wxPoint* pos_ptr;
  if (!get_val_ptr_param<wxPoint>(pos_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& pos = *pos_ptr;
  wxSize* size_ptr;
  if (!get_val_ptr_param<wxSize>(size_ptr,_p,_n)) ClassHelpAndReturn;
  wxSize& size = *size_ptr;
  long style_long;
  if (!get_val_param<long>(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;
  wxString* name_ptr;
  if (!get_val_ptr_param<wxString>(name_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& name = *name_ptr;
  bool res =   this->_objectptr->GetObj()->Create(parent, id, title, pos, size, style, name);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
/* The following types are missing: wxStatusBar

//---------------------------------------------------
//  Wrapping of wxStatusBar * wxFrame::CreateStatusBar(int number, long int style, wxWindowID id, wxString const & name)
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_CreateStatusBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'number'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type wxStatusBar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_CreateStatusBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int number;
  if (!get_val_param<int>(number,_p,_n)) ClassHelpAndReturn;
  long style_long;
  if (!get_val_param<long>(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;
  int id;
  if (!get_val_param<int>(id,_p,_n)) ClassHelpAndReturn;
  wxString* name_ptr;
  if (!get_val_ptr_param<wxString>(name_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& name = *name_ptr;
  wxStatusBar * res =   this->_objectptr->GetObj()->CreateStatusBar(number, style, id, name);
  return AMILabType<wxStatusBar>::CreateVar(res);
}
*/
/* The following types are missing: wxStatusBar

//---------------------------------------------------
//  Wrapping of void wxFrame::SetStatusBar(wxStatusBar * statbar)
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_SetStatusBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStatusBar, "parameter named 'statbar'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_SetStatusBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxStatusBar* statbar;
  if (!get_val_ptr_param<wxStatusBar>(statbar,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetStatusBar(statbar);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxToolBar

//---------------------------------------------------
//  Wrapping of wxToolBar * wxFrame::CreateToolBar(long int style, wxWindowID id, wxString const & name)
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_CreateToolBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type wxToolBar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_CreateToolBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  long style_long;
  if (!get_val_param<long>(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;
  int id;
  if (!get_val_param<int>(id,_p,_n)) ClassHelpAndReturn;
  wxString* name_ptr;
  if (!get_val_ptr_param<wxString>(name_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& name = *name_ptr;
  wxToolBar * res =   this->_objectptr->GetObj()->CreateToolBar(style, id, name);
  return AMILabType<wxToolBar>::CreateVar(res);
}
*/
/* The following types are missing: wxToolBar

//---------------------------------------------------
//  Wrapping of void wxFrame::SetToolBar(wxToolBar * toolbar)
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_SetToolBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxToolBar, "parameter named 'toolbar'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_SetToolBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxToolBar* toolbar;
  if (!get_val_ptr_param<wxToolBar>(toolbar,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetToolBar(toolbar);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of wxPoint wxFrame::GetClientAreaOrigin()
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_GetClientAreaOrigin::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_GetClientAreaOrigin::CallMember( ParamList* _p)
{
  wxPoint res =   this->_objectptr->GetObj()->GetClientAreaOrigin();
  return AMILabType<wxPoint>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxFrame::GtkOnSize()
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_GtkOnSize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_GtkOnSize::CallMember( ParamList* _p)
{
//  this->_objectptr->GetObj()->GtkOnSize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrame::OnInternalIdle()
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_OnInternalIdle::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_OnInternalIdle::CallMember( ParamList* _p)
{
  this->_objectptr->GetObj()->OnInternalIdle();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrame::UpdateMenuBarSize()
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_UpdateMenuBarSize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_UpdateMenuBarSize::CallMember( ParamList* _p)
{
//  this->_objectptr->GetObj()->UpdateMenuBarSize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxFrame::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxObject * wxFrame::wxCreateObject()
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_wxCreateObject::SetParametersComments()
{
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_wxCreateObject::CallMember( ParamList* _p)
{
  wxObject * res =   this->_objectptr->GetObj()->wxCreateObject();
  BasicVariable::ptr res_var = WrapClass_wxObject::CreateVar(res);
  return res_var;
}

