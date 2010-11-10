/**
 * C++ Interface: wrap_wxAuiToolBar
 *
 * Description: wrapping wxAuiToolBar
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_wxAuiToolBar.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxWindow.h"
#include "wrap_wxPoint.h"
#include "wrap_wxSize.h"
#include "wrap_wxAuiToolBarArt.h"
#include "wrap_wxFont.h"
#include "wrap_wxString.h"
#include "wrap_wxBitmap.h"
#include "wrap_wxObject.h"
#include "wrap_wxControl.h"
#include "wrap_wxAuiToolBarItem.h"
#include "wrap_wxRect.h"
#include "wrap_wxAuiToolBarItemArray.h"
#include "wrap_wxClassInfo.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAuiToolBar>::CreateVar( ParamList* p)
{
  WrapClass_wxAuiToolBar::wrap_wxAuiToolBar construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxAuiToolBar);

//
// static member for creating a variable from a pointer to wxAuiToolBar
//
Variable<AMIObject>::ptr WrapClass_wxAuiToolBar::CreateVar( wxAuiToolBar* sp)
{
  boost::shared_ptr<wxAuiToolBar> di_ptr(
    sp,
    wxwindow_nodeleter<wxAuiToolBar>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAuiToolBar>::CreateVar(
      new WrapClass_wxAuiToolBar(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor wxAuiToolBar::wxAuiToolBar(wxWindow * parent, wxWindowID id, wxPoint & position, wxSize & size, long int style)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_wxAuiToolBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'position'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_wxAuiToolBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxWindow* parent;
  if (!get_val_ptr_param<wxWindow>(parent,_p,_n)) ClassHelpAndReturn;
  int id;
  if (!get_val_param<int>(id,_p,_n)) ClassHelpAndReturn;
  wxPoint* position_ptr;
  if (!get_val_ptr_param<wxPoint>(position_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& position = *position_ptr;
  wxSize* size_ptr;
  if (!get_val_ptr_param<wxSize>(size_ptr,_p,_n)) ClassHelpAndReturn;
  wxSize& size = *size_ptr;
  long style_long;
  if (!get_val_param<long>(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;
  wxAuiToolBar* _newobj = new wxAuiToolBar(parent, id, position, size, style);
  BasicVariable::ptr res = WrapClass_wxAuiToolBar::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetWindowStyleFlag(long int style)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetWindowStyleFlag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetWindowStyleFlag::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  long style_long;
  if (!get_val_param<long>(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;
  this->_objectptr->GetObj()->SetWindowStyleFlag(style);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long int wxAuiToolBar::GetWindowStyleFlag()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetWindowStyleFlag::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetWindowStyleFlag::CallMember( ParamList* _p)
{
  long int res =   this->_objectptr->GetObj()->GetWindowStyleFlag();
  long  res_long = res;
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetArtProvider(wxAuiToolBarArt * art)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetArtProvider::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarArt, "parameter named 'art'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetArtProvider::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxAuiToolBarArt* art;
  if (!get_val_ptr_param<wxAuiToolBarArt>(art,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetArtProvider(art);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxAuiToolBarArt * wxAuiToolBar::GetArtProvider()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetArtProvider::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiToolBarArt";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetArtProvider::CallMember( ParamList* _p)
{
  wxAuiToolBarArt * res =   this->_objectptr->GetObj()->GetArtProvider();
  BasicVariable::ptr res_var = WrapClass_wxAuiToolBarArt::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::SetFont(wxFont & font)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetFont::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'font'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetFont::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxFont* font_ptr;
  if (!get_val_ptr_param<wxFont>(font_ptr,_p,_n)) ClassHelpAndReturn;
  wxFont& font = *font_ptr;
  bool res =   this->_objectptr->GetObj()->SetFont(font);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
/* The following types are missing: wxItemKind

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::AddTool(int tool_id, wxString & label, wxBitmap & bitmap, wxString & short_help_string, wxItemKind kind)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddTool::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'short_help_string'")
  ADDPARAMCOMMENT_TYPE( wxItemKind, "parameter named 'kind'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddTool::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  wxString* label_ptr;
  if (!get_val_ptr_param<wxString>(label_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& label = *label_ptr;
  wxBitmap* bitmap_ptr;
  if (!get_val_ptr_param<wxBitmap>(bitmap_ptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap& bitmap = *bitmap_ptr;
  wxString* short_help_string_ptr;
  if (!get_val_ptr_param<wxString>(short_help_string_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& short_help_string = *short_help_string_ptr;
  wxItemKind kind;
  if (!get_val_param<wxItemKind>(kind,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->AddTool(tool_id, label, bitmap, short_help_string, kind);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxItemKind

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::AddTool(int tool_id, wxString & label, wxBitmap & bitmap, wxBitmap & disabled_bitmap, wxItemKind kind, wxString & short_help_string, wxString & long_help_string, wxObject * client_data)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddTool1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'disabled_bitmap'")
  ADDPARAMCOMMENT_TYPE( wxItemKind, "parameter named 'kind'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'short_help_string'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'long_help_string'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'client_data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddTool1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  wxString* label_ptr;
  if (!get_val_ptr_param<wxString>(label_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& label = *label_ptr;
  wxBitmap* bitmap_ptr;
  if (!get_val_ptr_param<wxBitmap>(bitmap_ptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap& bitmap = *bitmap_ptr;
  wxBitmap* disabled_bitmap_ptr;
  if (!get_val_ptr_param<wxBitmap>(disabled_bitmap_ptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap& disabled_bitmap = *disabled_bitmap_ptr;
  wxItemKind kind;
  if (!get_val_param<wxItemKind>(kind,_p,_n)) ClassHelpAndReturn;
  wxString* short_help_string_ptr;
  if (!get_val_ptr_param<wxString>(short_help_string_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& short_help_string = *short_help_string_ptr;
  wxString* long_help_string_ptr;
  if (!get_val_ptr_param<wxString>(long_help_string_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& long_help_string = *long_help_string_ptr;
  wxObject* client_data;
  if (!get_val_ptr_param<wxObject>(client_data,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->AddTool(tool_id, label, bitmap, disabled_bitmap, kind, short_help_string, long_help_string, client_data);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::AddTool(int tool_id, wxBitmap & bitmap, wxBitmap & disabled_bitmap, bool toggle, wxObject * client_data, wxString & short_help_string, wxString & long_help_string)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddTool2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'disabled_bitmap'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toggle'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'client_data'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'short_help_string'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'long_help_string'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddTool2::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  wxBitmap* bitmap_ptr;
  if (!get_val_ptr_param<wxBitmap>(bitmap_ptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap& bitmap = *bitmap_ptr;
  wxBitmap* disabled_bitmap_ptr;
  if (!get_val_ptr_param<wxBitmap>(disabled_bitmap_ptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap& disabled_bitmap = *disabled_bitmap_ptr;
  int toggle_int;
  if (!get_val_param<int>(toggle_int,_p,_n)) ClassHelpAndReturn;
  bool toggle = (bool) (toggle_int>0.5);
  wxObject* client_data;
  if (!get_val_ptr_param<wxObject>(client_data,_p,_n)) ClassHelpAndReturn;
  wxString* short_help_string_ptr;
  if (!get_val_ptr_param<wxString>(short_help_string_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& short_help_string = *short_help_string_ptr;
  wxString* long_help_string_ptr;
  if (!get_val_ptr_param<wxString>(long_help_string_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& long_help_string = *long_help_string_ptr;
  this->_objectptr->GetObj()->AddTool(tool_id, bitmap, disabled_bitmap, toggle, client_data, short_help_string, long_help_string);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::AddLabel(int tool_id, wxString & label, int const width)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  wxString* label_ptr;
  if (!get_val_ptr_param<wxString>(label_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& label = *label_ptr;
  int width;
  if (!get_val_param<int>(width,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->AddLabel(tool_id, label, width);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::AddControl(wxControl * control, wxString & label)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddControl::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxControl, "parameter named 'control'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddControl::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxControl* control;
  if (!get_val_ptr_param<wxControl>(control,_p,_n)) ClassHelpAndReturn;
  wxString* label_ptr;
  if (!get_val_ptr_param<wxString>(label_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& label = *label_ptr;
  this->_objectptr->GetObj()->AddControl(control, label);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::AddSeparator()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddSeparator::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddSeparator::CallMember( ParamList* _p)
{
  this->_objectptr->GetObj()->AddSeparator();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::AddSpacer(int pixels)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddSpacer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pixels'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddSpacer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int pixels;
  if (!get_val_param<int>(pixels,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->AddSpacer(pixels);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::AddStretchSpacer(int proportion)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddStretchSpacer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddStretchSpacer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int proportion;
  if (!get_val_param<int>(proportion,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->AddStretchSpacer(proportion);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::Realize()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_Realize::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_Realize::CallMember( ParamList* _p)
{
  bool res =   this->_objectptr->GetObj()->Realize();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxControl * wxAuiToolBar::FindControl(int window_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_FindControl::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'window_id'")
  return_comments="returning a variable of type wxControl";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_FindControl::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int window_id;
  if (!get_val_param<int>(window_id,_p,_n)) ClassHelpAndReturn;
  wxControl * res =   this->_objectptr->GetObj()->FindControl(window_id);
  BasicVariable::ptr res_var = WrapClass_wxControl::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxAuiToolBarItem * wxAuiToolBar::FindToolByPosition(wxCoord x, wxCoord y)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_FindToolByPosition::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type wxAuiToolBarItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_FindToolByPosition::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int x;
  if (!get_val_param<int>(x,_p,_n)) ClassHelpAndReturn;
  int y;
  if (!get_val_param<int>(y,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItem * res =   this->_objectptr->GetObj()->FindToolByPosition(x, y);
  BasicVariable::ptr res_var = WrapClass_wxAuiToolBarItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxAuiToolBarItem * wxAuiToolBar::FindToolByIndex(int idx)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_FindToolByIndex::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'idx'")
  return_comments="returning a variable of type wxAuiToolBarItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_FindToolByIndex::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int idx;
  if (!get_val_param<int>(idx,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItem * res =   this->_objectptr->GetObj()->FindToolByIndex(idx);
  BasicVariable::ptr res_var = WrapClass_wxAuiToolBarItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxAuiToolBarItem * wxAuiToolBar::FindTool(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_FindTool::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type wxAuiToolBarItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_FindTool::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItem * res =   this->_objectptr->GetObj()->FindTool(tool_id);
  BasicVariable::ptr res_var = WrapClass_wxAuiToolBarItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::ClearTools()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_ClearTools::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_ClearTools::CallMember( ParamList* _p)
{
  this->_objectptr->GetObj()->ClearTools();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::Clear()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_Clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_Clear::CallMember( ParamList* _p)
{
  this->_objectptr->GetObj()->Clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::DeleteTool(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_DeleteTool::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_DeleteTool::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  bool res =   this->_objectptr->GetObj()->DeleteTool(tool_id);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::DeleteByIndex(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_DeleteByIndex::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_DeleteByIndex::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  bool res =   this->_objectptr->GetObj()->DeleteByIndex(tool_id);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
/* The following types are missing: long unsigned int

//---------------------------------------------------
//  Wrapping of size_t wxAuiToolBar::GetToolCount()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolCount::SetParametersComments()
{
  return_comments="returning a variable of type long unsigned int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolCount::CallMember( ParamList* _p)
{
  size_t res =   this->_objectptr->GetObj()->GetToolCount();
  return AMILabType<long unsigned int>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of int wxAuiToolBar::GetToolPos(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolPos::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolPos::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  int res =   this->_objectptr->GetObj()->GetToolPos(tool_id);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBar::GetToolIndex(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolIndex::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolIndex::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  int res =   this->_objectptr->GetObj()->GetToolIndex(tool_id);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetToolFits(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolFits::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolFits::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  bool res =   this->_objectptr->GetObj()->GetToolFits(tool_id);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxRect wxAuiToolBar::GetToolRect(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolRect::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolRect::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  wxRect res =   this->_objectptr->GetObj()->GetToolRect(tool_id);
  return AMILabType<wxRect>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetToolFitsByIndex(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolFitsByIndex::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolFitsByIndex::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  bool res =   this->_objectptr->GetObj()->GetToolFitsByIndex(tool_id);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetToolBarFits()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolBarFits::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolBarFits::CallMember( ParamList* _p)
{
  bool res =   this->_objectptr->GetObj()->GetToolBarFits();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetMargins(wxSize & size)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetMargins::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetMargins::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxSize* size_ptr;
  if (!get_val_ptr_param<wxSize>(size_ptr,_p,_n)) ClassHelpAndReturn;
  wxSize& size = *size_ptr;
  this->_objectptr->GetObj()->SetMargins(size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetMargins(int x, int y)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetMargins1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetMargins1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int x;
  if (!get_val_param<int>(x,_p,_n)) ClassHelpAndReturn;
  int y;
  if (!get_val_param<int>(y,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetMargins(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetMargins(int left, int right, int top, int bottom)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetMargins2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'left'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'right'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'top'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bottom'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetMargins2::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int left;
  if (!get_val_param<int>(left,_p,_n)) ClassHelpAndReturn;
  int right;
  if (!get_val_param<int>(right,_p,_n)) ClassHelpAndReturn;
  int top;
  if (!get_val_param<int>(top,_p,_n)) ClassHelpAndReturn;
  int bottom;
  if (!get_val_param<int>(bottom,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetMargins(left, right, top, bottom);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolBitmapSize(wxSize & size)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolBitmapSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolBitmapSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxSize* size_ptr;
  if (!get_val_ptr_param<wxSize>(size_ptr,_p,_n)) ClassHelpAndReturn;
  wxSize& size = *size_ptr;
  this->_objectptr->GetObj()->SetToolBitmapSize(size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxAuiToolBar::GetToolBitmapSize()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolBitmapSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolBitmapSize::CallMember( ParamList* _p)
{
  wxSize res =   this->_objectptr->GetObj()->GetToolBitmapSize();
  return AMILabType<wxSize>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetOverflowVisible()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetOverflowVisible::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetOverflowVisible::CallMember( ParamList* _p)
{
  bool res =   this->_objectptr->GetObj()->GetOverflowVisible();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetOverflowVisible(bool visible)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetOverflowVisible::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'visible'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetOverflowVisible::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int visible_int;
  if (!get_val_param<int>(visible_int,_p,_n)) ClassHelpAndReturn;
  bool visible = (bool) (visible_int>0.5);
  this->_objectptr->GetObj()->SetOverflowVisible(visible);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetGripperVisible()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetGripperVisible::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetGripperVisible::CallMember( ParamList* _p)
{
  bool res =   this->_objectptr->GetObj()->GetGripperVisible();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetGripperVisible(bool visible)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetGripperVisible::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'visible'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetGripperVisible::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int visible_int;
  if (!get_val_param<int>(visible_int,_p,_n)) ClassHelpAndReturn;
  bool visible = (bool) (visible_int>0.5);
  this->_objectptr->GetObj()->SetGripperVisible(visible);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::ToggleTool(int tool_id, bool state)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_ToggleTool::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'state'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_ToggleTool::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  int state_int;
  if (!get_val_param<int>(state_int,_p,_n)) ClassHelpAndReturn;
  bool state = (bool) (state_int>0.5);
  this->_objectptr->GetObj()->ToggleTool(tool_id, state);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetToolToggled(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolToggled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolToggled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  bool res =   this->_objectptr->GetObj()->GetToolToggled(tool_id);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::EnableTool(int tool_id, bool state)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_EnableTool::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'state'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_EnableTool::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  int state_int;
  if (!get_val_param<int>(state_int,_p,_n)) ClassHelpAndReturn;
  bool state = (bool) (state_int>0.5);
  this->_objectptr->GetObj()->EnableTool(tool_id, state);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetToolEnabled(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolEnabled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolEnabled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  bool res =   this->_objectptr->GetObj()->GetToolEnabled(tool_id);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolDropDown(int tool_id, bool dropdown)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolDropDown::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dropdown'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolDropDown::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  int dropdown_int;
  if (!get_val_param<int>(dropdown_int,_p,_n)) ClassHelpAndReturn;
  bool dropdown = (bool) (dropdown_int>0.5);
  this->_objectptr->GetObj()->SetToolDropDown(tool_id, dropdown);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetToolDropDown(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolDropDown::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolDropDown::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  bool res =   this->_objectptr->GetObj()->GetToolDropDown(tool_id);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolBorderPadding(int padding)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolBorderPadding::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'padding'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolBorderPadding::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int padding;
  if (!get_val_param<int>(padding,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetToolBorderPadding(padding);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBar::GetToolBorderPadding()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolBorderPadding::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolBorderPadding::CallMember( ParamList* _p)
{
  int res =   this->_objectptr->GetObj()->GetToolBorderPadding();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolTextOrientation(int orientation)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolTextOrientation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orientation'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolTextOrientation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int orientation;
  if (!get_val_param<int>(orientation,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetToolTextOrientation(orientation);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBar::GetToolTextOrientation()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolTextOrientation::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolTextOrientation::CallMember( ParamList* _p)
{
  int res =   this->_objectptr->GetObj()->GetToolTextOrientation();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolPacking(int packing)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolPacking::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'packing'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolPacking::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int packing;
  if (!get_val_param<int>(packing,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetToolPacking(packing);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBar::GetToolPacking()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolPacking::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolPacking::CallMember( ParamList* _p)
{
  int res =   this->_objectptr->GetObj()->GetToolPacking();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolProportion(int tool_id, int proportion)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolProportion::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolProportion::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  int proportion;
  if (!get_val_param<int>(proportion,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetToolProportion(tool_id, proportion);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBar::GetToolProportion(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolProportion::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolProportion::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  int res =   this->_objectptr->GetObj()->GetToolProportion(tool_id);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolSeparation(int separation)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolSeparation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'separation'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolSeparation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int separation;
  if (!get_val_param<int>(separation,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetToolSeparation(separation);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBar::GetToolSeparation()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolSeparation::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolSeparation::CallMember( ParamList* _p)
{
  int res =   this->_objectptr->GetObj()->GetToolSeparation();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolSticky(int tool_id, bool sticky)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolSticky::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'sticky'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolSticky::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  int sticky_int;
  if (!get_val_param<int>(sticky_int,_p,_n)) ClassHelpAndReturn;
  bool sticky = (bool) (sticky_int>0.5);
  this->_objectptr->GetObj()->SetToolSticky(tool_id, sticky);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetToolSticky(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolSticky::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolSticky::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  bool res =   this->_objectptr->GetObj()->GetToolSticky(tool_id);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxString wxAuiToolBar::GetToolLabel(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  wxString res =   this->_objectptr->GetObj()->GetToolLabel(tool_id);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolLabel(int tool_id, wxString & label)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  wxString* label_ptr;
  if (!get_val_ptr_param<wxString>(label_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& label = *label_ptr;
  this->_objectptr->GetObj()->SetToolLabel(tool_id, label);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxBitmap wxAuiToolBar::GetToolBitmap(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  wxBitmap res =   this->_objectptr->GetObj()->GetToolBitmap(tool_id);
  return AMILabType<wxBitmap>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolBitmap(int tool_id, wxBitmap & bitmap)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  wxBitmap* bitmap_ptr;
  if (!get_val_ptr_param<wxBitmap>(bitmap_ptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap& bitmap = *bitmap_ptr;
  this->_objectptr->GetObj()->SetToolBitmap(tool_id, bitmap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxAuiToolBar::GetToolShortHelp(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolShortHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolShortHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  wxString res =   this->_objectptr->GetObj()->GetToolShortHelp(tool_id);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolShortHelp(int tool_id, wxString & help_string)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolShortHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help_string'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolShortHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  wxString* help_string_ptr;
  if (!get_val_ptr_param<wxString>(help_string_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& help_string = *help_string_ptr;
  this->_objectptr->GetObj()->SetToolShortHelp(tool_id, help_string);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxAuiToolBar::GetToolLongHelp(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolLongHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolLongHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  wxString res =   this->_objectptr->GetObj()->GetToolLongHelp(tool_id);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolLongHelp(int tool_id, wxString & help_string)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolLongHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help_string'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolLongHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int tool_id;
  if (!get_val_param<int>(tool_id,_p,_n)) ClassHelpAndReturn;
  wxString* help_string_ptr;
  if (!get_val_ptr_param<wxString>(help_string_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& help_string = *help_string_ptr;
  this->_objectptr->GetObj()->SetToolLongHelp(tool_id, help_string);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetCustomOverflowItems(wxAuiToolBarItemArray & prepend, wxAuiToolBarItemArray & append)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetCustomOverflowItems::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItemArray, "parameter named 'prepend'")
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItemArray, "parameter named 'append'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetCustomOverflowItems::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxAuiToolBarItemArray* prepend_ptr;
  if (!get_val_ptr_param<wxAuiToolBarItemArray>(prepend_ptr,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItemArray& prepend = *prepend_ptr;
  wxAuiToolBarItemArray* append_ptr;
  if (!get_val_ptr_param<wxAuiToolBarItemArray>(append_ptr,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItemArray& append = *append_ptr;
  this->_objectptr->GetObj()->SetCustomOverflowItems(prepend, append);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxAuiToolBar::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxObject * wxAuiToolBar::wxCreateObject()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_wxCreateObject::SetParametersComments()
{
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_wxCreateObject::CallMember( ParamList* _p)
{
  wxObject * res =   this->_objectptr->GetObj()->wxCreateObject();
  BasicVariable::ptr res_var = WrapClass_wxObject::CreateVar(res);
  return res_var;
}

