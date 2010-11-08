/**
 * C++ Interface: wrap_wxAuiManager
 *
 * Description: wrapping wxAuiManager
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_wxAuiManager.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxWindow.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxAuiManager.h"
#include "wrap_wxString.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAuiManager>::CreateVar( ParamList* p)
{
  WrapClass_wxAuiManager::wrap_wxAuiManager construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxAuiManager);
//AMI_DEFINE_WRAPPEDTYPE_NOCOPY_CREATEFROMPTR(wxAuiManager);

//
// static member for creating a variable from a pointer to wxAuiManager
//
Variable<AMIObject>::ptr WrapClass_wxAuiManager::CreateVar( wxAuiManager* sp)
{
  boost::shared_ptr<wxAuiManager> di_ptr(
    sp,
    wxwindow_nodeleter<wxAuiManager>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAuiManager>::CreateVar(
      new WrapClass_wxAuiManager(di_ptr)
    );
  return res;
}

/*
//---------------------------------------------------
// Method that adds wrapping of wxAuiManager
//---------------------------------------------------

void WrapClass_wxAuiManager::
      wrap_wxAuiManager::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(..,"...");
  return_comments = "A wrapped wxAuiManager object.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
      wrap_wxAuiManager::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  // get parameters...
  wxAuiManager* owxAuiManager = new wxAuiManager(...); // constructor parameters ...
  BasicVariable::ptr res = WrapClass_wxAuiManager::CreateVar(owxAuiManager);
  return res;
}
*/


//---------------------------------------------------
//  Wrapping of Constructor wxAuiManager::wxAuiManager(wxWindow * managed_wnd, unsigned int flags)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_wxAuiManager::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'managed_wnd'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flags'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_wxAuiManager::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxWindow* managed_wnd;
  if (!get_val_ptr_param<wxWindow>(managed_wnd,p,n)) ClassHelpAndReturn;
  long flags_long;
  if (!get_val_param<long>(flags_long,p,n)) ClassHelpAndReturn;
  unsigned int flags = boost::numeric_cast<unsigned int>(flags_long);
  wxAuiManager* _newobj = new wxAuiManager(managed_wnd, flags);
  BasicVariable::ptr res = WrapClass_wxAuiManager::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxAuiManager::UnInit()
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_UnInit::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_UnInit::CallMember( ParamList* p)
{
  this->_objectptr->GetObj()->UnInit();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiManager::SetFlags(unsigned int flags)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_SetFlags::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flags'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_SetFlags::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  long flags_long;
  if (!get_val_param<long>(flags_long,p,n)) ClassHelpAndReturn;
  unsigned int flags = boost::numeric_cast<unsigned int>(flags_long);
  this->_objectptr->GetObj()->SetFlags(flags);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of unsigned int wxAuiManager::GetFlags()
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_GetFlags::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_GetFlags::CallMember( ParamList* p)
{
  unsigned int res =   this->_objectptr->GetObj()->GetFlags();
  long  res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxAuiManager::SetManagedWindow(wxWindow * managed_wnd)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_SetManagedWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'managed_wnd'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_SetManagedWindow::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxWindow* managed_wnd;
  if (!get_val_ptr_param<wxWindow>(managed_wnd,p,n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetManagedWindow(managed_wnd);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxAuiManager::GetManagedWindow()
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_GetManagedWindow::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_GetManagedWindow::CallMember( ParamList* p)
{
  wxWindow * res =   this->_objectptr->GetObj()->GetManagedWindow();
  //return AMILabType<wxWindow>::CreateVar(res);
  return WrapClass_wxWindow::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiManager * wxAuiManager::GetManager(wxWindow * window)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_GetManager::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  return_comments="returning a variable of type wxAuiManager";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_GetManager::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxWindow* window;
  if (!get_val_ptr_param<wxWindow>(window,p,n)) ClassHelpAndReturn;
  wxAuiManager * res =   this->_objectptr->GetObj()->GetManager(window);
  //return AMILabType<wxAuiManager>::CreateVar(res);
  return WrapClass_wxAuiManager::CreateVar(res);
}
/* The following types are missing: wxAuiDockArt

//---------------------------------------------------
//  Wrapping of void wxAuiManager::SetArtProvider(wxAuiDockArt * art_provider)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_SetArtProvider::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiDockArt, "parameter named 'art_provider'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_SetArtProvider::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxAuiDockArt* art_provider;
  if (!get_val_ptr_param<wxAuiDockArt>(art_provider,p,n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetArtProvider(art_provider);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxAuiDockArt

//---------------------------------------------------
//  Wrapping of wxAuiDockArt * wxAuiManager::GetArtProvider()
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_GetArtProvider::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiDockArt";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_GetArtProvider::CallMember( ParamList* p)
{
  wxAuiDockArt * res =   this->_objectptr->GetObj()->GetArtProvider();
  return AMILabType<wxAuiDockArt>::CreateVar(res);
}
*/
/* The following types are missing: wxAuiPaneInfo

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiManager::GetPane(wxWindow * window)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_GetPane::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_GetPane::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxWindow* window;
  if (!get_val_ptr_param<wxWindow>(window,p,n)) ClassHelpAndReturn;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->GetPane(window);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}
*/
/* The following types are missing: wxAuiPaneInfo

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiManager::GetPane(wxString & name)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_GetPane1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_GetPane1::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxString* name_ptr;
  if (!get_val_ptr_param<wxString>(name_ptr,p,n)) ClassHelpAndReturn;
  wxString& name = *name_ptr;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->GetPane(name);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}
*/
/* The following types are missing: wxAuiPaneInfoArray

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfoArray & wxAuiManager::GetAllPanes()
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_GetAllPanes::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfoArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_GetAllPanes::CallMember( ParamList* p)
{
  wxAuiPaneInfoArray & res =   this->_objectptr->GetObj()->GetAllPanes();
  return AMILabType<wxAuiPaneInfoArray>::CreateVar(res);
}
*/
/* The following types are missing: wxAuiPaneInfo

//---------------------------------------------------
//  Wrapping of bool wxAuiManager::AddPane(wxWindow * window, wxAuiPaneInfo & pane_info)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_AddPane::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'pane_info'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_AddPane::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxWindow* window;
  if (!get_val_ptr_param<wxWindow>(window,p,n)) ClassHelpAndReturn;
  wxAuiPaneInfo* pane_info_ptr;
  if (!get_val_ptr_param<wxAuiPaneInfo>(pane_info_ptr,p,n)) ClassHelpAndReturn;
  wxAuiPaneInfo& pane_info = *pane_info_ptr;
  bool res =   this->_objectptr->GetObj()->AddPane(window, pane_info);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
*/
/* The following types are missing: wxAuiPaneInfo, wxPoint

//---------------------------------------------------
//  Wrapping of bool wxAuiManager::AddPane(wxWindow * window, wxAuiPaneInfo & pane_info, wxPoint & drop_pos)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_AddPane1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'pane_info'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'drop_pos'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_AddPane1::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxWindow* window;
  if (!get_val_ptr_param<wxWindow>(window,p,n)) ClassHelpAndReturn;
  wxAuiPaneInfo* pane_info_ptr;
  if (!get_val_ptr_param<wxAuiPaneInfo>(pane_info_ptr,p,n)) ClassHelpAndReturn;
  wxAuiPaneInfo& pane_info = *pane_info_ptr;
  wxPoint* drop_pos_ptr;
  if (!get_val_ptr_param<wxPoint>(drop_pos_ptr,p,n)) ClassHelpAndReturn;
  wxPoint& drop_pos = *drop_pos_ptr;
  bool res =   this->_objectptr->GetObj()->AddPane(window, pane_info, drop_pos);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxAuiManager::AddPane(wxWindow * window, int direction, wxString & caption)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_AddPane2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'direction'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'caption'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_AddPane2::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxWindow* window;
  if (!get_val_ptr_param<wxWindow>(window,p,n)) ClassHelpAndReturn;
  int direction;
  if (!get_val_param<int>(direction,p,n)) ClassHelpAndReturn;
  wxString* caption_ptr;
  if (!get_val_ptr_param<wxString>(caption_ptr,p,n)) ClassHelpAndReturn;
  wxString& caption = *caption_ptr;
  bool res =   this->_objectptr->GetObj()->AddPane(window, direction, caption);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
/* The following types are missing: wxAuiPaneInfo

//---------------------------------------------------
//  Wrapping of bool wxAuiManager::InsertPane(wxWindow * window, wxAuiPaneInfo & insert_location, int insert_level)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_InsertPane::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'insert_location'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'insert_level'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_InsertPane::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxWindow* window;
  if (!get_val_ptr_param<wxWindow>(window,p,n)) ClassHelpAndReturn;
  wxAuiPaneInfo* insert_location_ptr;
  if (!get_val_ptr_param<wxAuiPaneInfo>(insert_location_ptr,p,n)) ClassHelpAndReturn;
  wxAuiPaneInfo& insert_location = *insert_location_ptr;
  int insert_level;
  if (!get_val_param<int>(insert_level,p,n)) ClassHelpAndReturn;
  bool res =   this->_objectptr->GetObj()->InsertPane(window, insert_location, insert_level);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxAuiManager::DetachPane(wxWindow * window)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_DetachPane::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_DetachPane::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxWindow* window;
  if (!get_val_ptr_param<wxWindow>(window,p,n)) ClassHelpAndReturn;
  bool res =   this->_objectptr->GetObj()->DetachPane(window);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxAuiManager::Update()
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_Update::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_Update::CallMember( ParamList* p)
{
  this->_objectptr->GetObj()->Update();
  return BasicVariable::ptr();
}
/* The following types are missing: wxAuiPaneInfo

//---------------------------------------------------
//  Wrapping of wxString wxAuiManager::SavePaneInfo(wxAuiPaneInfo & pane)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_SavePaneInfo::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'pane'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_SavePaneInfo::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxAuiPaneInfo* pane_ptr;
  if (!get_val_ptr_param<wxAuiPaneInfo>(pane_ptr,p,n)) ClassHelpAndReturn;
  wxAuiPaneInfo& pane = *pane_ptr;
  wxString res =   this->_objectptr->GetObj()->SavePaneInfo(pane);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxAuiPaneInfo

//---------------------------------------------------
//  Wrapping of void wxAuiManager::LoadPaneInfo(wxString pane_part, wxAuiPaneInfo & pane)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_LoadPaneInfo::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'pane_part'")
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'pane'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_LoadPaneInfo::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxString pane_part;
  if (!get_val_param<wxString>(pane_part,p,n)) ClassHelpAndReturn;
  wxAuiPaneInfo* pane_ptr;
  if (!get_val_ptr_param<wxAuiPaneInfo>(pane_ptr,p,n)) ClassHelpAndReturn;
  wxAuiPaneInfo& pane = *pane_ptr;
  this->_objectptr->GetObj()->LoadPaneInfo(pane_part, pane);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of wxString wxAuiManager::SavePerspective()
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_SavePerspective::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_SavePerspective::CallMember( ParamList* p)
{
  wxString res =   this->_objectptr->GetObj()->SavePerspective();
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiManager::LoadPerspective(wxString & perspective, bool update)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_LoadPerspective::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'perspective'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'update'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_LoadPerspective::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxString* perspective_ptr;
  if (!get_val_ptr_param<wxString>(perspective_ptr,p,n)) ClassHelpAndReturn;
  wxString& perspective = *perspective_ptr;
  int update_int;
  if (!get_val_param<int>(update_int,p,n)) ClassHelpAndReturn;
  bool update = (bool) (update_int>0.5);
  bool res =   this->_objectptr->GetObj()->LoadPerspective(perspective, update);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxAuiManager::SetDockSizeConstraint(double width_pct, double height_pct)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_SetDockSizeConstraint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'width_pct'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'height_pct'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_SetDockSizeConstraint::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  double width_pct;
  if (!get_val_param<double>(width_pct,p,n)) ClassHelpAndReturn;
  double height_pct;
  if (!get_val_param<double>(height_pct,p,n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetDockSizeConstraint(width_pct, height_pct);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiManager::GetDockSizeConstraint(double * width_pct, double * height_pct)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_GetDockSizeConstraint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'width_pct'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'height_pct'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_GetDockSizeConstraint::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  double* width_pct;
  if (!get_val_ptr_param<double>(width_pct,p,n)) ClassHelpAndReturn;
  double* height_pct;
  if (!get_val_ptr_param<double>(height_pct,p,n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->GetDockSizeConstraint(width_pct, height_pct);
  return BasicVariable::ptr();
}
/* The following types are missing: wxAuiPaneInfo

//---------------------------------------------------
//  Wrapping of void wxAuiManager::ClosePane(wxAuiPaneInfo & pane_info)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_ClosePane::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'pane_info'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_ClosePane::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxAuiPaneInfo* pane_info_ptr;
  if (!get_val_ptr_param<wxAuiPaneInfo>(pane_info_ptr,p,n)) ClassHelpAndReturn;
  wxAuiPaneInfo& pane_info = *pane_info_ptr;
  this->_objectptr->GetObj()->ClosePane(pane_info);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxAuiPaneInfo

//---------------------------------------------------
//  Wrapping of void wxAuiManager::MaximizePane(wxAuiPaneInfo & pane_info)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_MaximizePane::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'pane_info'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_MaximizePane::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxAuiPaneInfo* pane_info_ptr;
  if (!get_val_ptr_param<wxAuiPaneInfo>(pane_info_ptr,p,n)) ClassHelpAndReturn;
  wxAuiPaneInfo& pane_info = *pane_info_ptr;
  this->_objectptr->GetObj()->MaximizePane(pane_info);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxAuiPaneInfo

//---------------------------------------------------
//  Wrapping of void wxAuiManager::RestorePane(wxAuiPaneInfo & pane_info)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_RestorePane::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'pane_info'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_RestorePane::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxAuiPaneInfo* pane_info_ptr;
  if (!get_val_ptr_param<wxAuiPaneInfo>(pane_info_ptr,p,n)) ClassHelpAndReturn;
  wxAuiPaneInfo& pane_info = *pane_info_ptr;
  this->_objectptr->GetObj()->RestorePane(pane_info);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxAuiManager::RestoreMaximizedPane()
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_RestoreMaximizedPane::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_RestoreMaximizedPane::CallMember( ParamList* p)
{
  this->_objectptr->GetObj()->RestoreMaximizedPane();
  return BasicVariable::ptr();
}
/* The following types are missing: wxAuiFloatingFrame, wxAuiPaneInfo

//---------------------------------------------------
//  Wrapping of wxAuiFloatingFrame * wxAuiManager::CreateFloatingFrame(wxWindow * parent, wxAuiPaneInfo & p)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_CreateFloatingFrame::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'p'")
  return_comments="returning a variable of type wxAuiFloatingFrame";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_CreateFloatingFrame::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxWindow* parent;
  if (!get_val_ptr_param<wxWindow>(parent,p,n)) ClassHelpAndReturn;
  wxAuiPaneInfo* p_ptr;
  if (!get_val_ptr_param<wxAuiPaneInfo>(p_ptr,p,n)) ClassHelpAndReturn;
  wxAuiPaneInfo& p = *p_ptr;
  wxAuiFloatingFrame * res =   this->_objectptr->GetObj()->CreateFloatingFrame(parent, p);
  return AMILabType<wxAuiFloatingFrame>::CreateVar(res);
}
*/
/* The following types are missing: wxPoint

//---------------------------------------------------
//  Wrapping of void wxAuiManager::StartPaneDrag(wxWindow * pane_window, wxPoint & offset)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_StartPaneDrag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'pane_window'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'offset'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_StartPaneDrag::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxWindow* pane_window;
  if (!get_val_ptr_param<wxWindow>(pane_window,p,n)) ClassHelpAndReturn;
  wxPoint* offset_ptr;
  if (!get_val_ptr_param<wxPoint>(offset_ptr,p,n)) ClassHelpAndReturn;
  wxPoint& offset = *offset_ptr;
  this->_objectptr->GetObj()->StartPaneDrag(pane_window, offset);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxRect, wxPoint, wxPoint

//---------------------------------------------------
//  Wrapping of wxRect wxAuiManager::CalculateHintRect(wxWindow * pane_window, wxPoint & pt, wxPoint & offset)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_CalculateHintRect::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'pane_window'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'offset'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_CalculateHintRect::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxWindow* pane_window;
  if (!get_val_ptr_param<wxWindow>(pane_window,p,n)) ClassHelpAndReturn;
  wxPoint* pt_ptr;
  if (!get_val_ptr_param<wxPoint>(pt_ptr,p,n)) ClassHelpAndReturn;
  wxPoint& pt = *pt_ptr;
  wxPoint* offset_ptr;
  if (!get_val_ptr_param<wxPoint>(offset_ptr,p,n)) ClassHelpAndReturn;
  wxPoint& offset = *offset_ptr;
  wxRect res =   this->_objectptr->GetObj()->CalculateHintRect(pane_window, pt, offset);
  return AMILabType<wxRect>::CreateVar(res);
}
*/
/* The following types are missing: wxPoint, wxPoint

//---------------------------------------------------
//  Wrapping of void wxAuiManager::DrawHintRect(wxWindow * pane_window, wxPoint & pt, wxPoint & offset)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_DrawHintRect::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'pane_window'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'offset'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_DrawHintRect::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxWindow* pane_window;
  if (!get_val_ptr_param<wxWindow>(pane_window,p,n)) ClassHelpAndReturn;
  wxPoint* pt_ptr;
  if (!get_val_ptr_param<wxPoint>(pt_ptr,p,n)) ClassHelpAndReturn;
  wxPoint& pt = *pt_ptr;
  wxPoint* offset_ptr;
  if (!get_val_ptr_param<wxPoint>(offset_ptr,p,n)) ClassHelpAndReturn;
  wxPoint& offset = *offset_ptr;
  this->_objectptr->GetObj()->DrawHintRect(pane_window, pt, offset);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxRect

//---------------------------------------------------
//  Wrapping of void wxAuiManager::ShowHint(wxRect & rect)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_ShowHint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_ShowHint::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxRect* rect_ptr;
  if (!get_val_ptr_param<wxRect>(rect_ptr,p,n)) ClassHelpAndReturn;
  wxRect& rect = *rect_ptr;
  this->_objectptr->GetObj()->ShowHint(rect);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxAuiManager::HideHint()
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_HideHint::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_HideHint::CallMember( ParamList* p)
{
  this->_objectptr->GetObj()->HideHint();
  return BasicVariable::ptr();
}
/* The following types are missing: wxFrame

//---------------------------------------------------
//  Wrapping of void wxAuiManager::SetFrame(wxFrame * frame)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_SetFrame::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFrame, "parameter named 'frame'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_SetFrame::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxFrame* frame;
  if (!get_val_ptr_param<wxFrame>(frame,p,n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetFrame(frame);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxFrame

//---------------------------------------------------
//  Wrapping of wxFrame * wxAuiManager::GetFrame()
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_GetFrame::SetParametersComments()
{
  return_comments="returning a variable of type wxFrame";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_GetFrame::CallMember( ParamList* p)
{
  wxFrame * res =   this->_objectptr->GetObj()->GetFrame();
  return AMILabType<wxFrame>::CreateVar(res);
}
*/
/* The following types are missing: wxAuiManagerEvent

//---------------------------------------------------
//  Wrapping of void wxAuiManager::OnRender(wxAuiManagerEvent & evt)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_OnRender::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiManagerEvent, "parameter named 'evt'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_OnRender::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxAuiManagerEvent* evt_ptr;
  if (!get_val_ptr_param<wxAuiManagerEvent>(evt_ptr,p,n)) ClassHelpAndReturn;
  wxAuiManagerEvent& evt = *evt_ptr;
  this->_objectptr->GetObj()->OnRender(evt);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxAuiManagerEvent

//---------------------------------------------------
//  Wrapping of void wxAuiManager::OnPaneButton(wxAuiManagerEvent & evt)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_OnPaneButton::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiManagerEvent, "parameter named 'evt'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_OnPaneButton::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxAuiManagerEvent* evt_ptr;
  if (!get_val_ptr_param<wxAuiManagerEvent>(evt_ptr,p,n)) ClassHelpAndReturn;
  wxAuiManagerEvent& evt = *evt_ptr;
  this->_objectptr->GetObj()->OnPaneButton(evt);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxClassInfo

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxAuiManager::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_GetClassInfo::CallMember( ParamList* p)
{
  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  return AMILabType<wxClassInfo>::CreateVar(res);
}
*/
/* The following types are missing: wxObject

//---------------------------------------------------
//  Wrapping of wxObject * wxAuiManager::wxCreateObject()
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_wxCreateObject::SetParametersComments()
{
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_wxCreateObject::CallMember( ParamList* p)
{
  wxObject * res =   this->_objectptr->GetObj()->wxCreateObject();
  return AMILabType<wxObject>::CreateVar(res);
}
*/

