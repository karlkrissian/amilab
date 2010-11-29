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
#include "wrap_wxAuiDockArt.h"
#include "wrap_wxAuiPaneInfo.h"
#include "wrap_wxString.h"
#include "wrap_wxAuiPaneInfoArray.h"
#include "wrap_wxPoint.h"
#include "wrap_wxAuiFloatingFrame.h"
#include "wrap_wxRect.h"
#include "wrap_wxAuiManagerEvent.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxAuiManager.h"

//----------------------------------------------------------------------
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
AMI_DEFINE_VARFROMSMTPTR(wxAuiManager);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxAuiManager>::CreateVar( wxAuiManager* val, bool nodeleter)
{ 
  boost::shared_ptr<wxAuiManager> obj_ptr(val,smartpointer_nodeleter<wxAuiManager>());
  return AMILabType<wxAuiManager>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
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

//----------------------------------------------------------------------
void WrapClass_wxAuiManager::AddMethods(WrapClass<wxAuiManager>::ptr this_ptr )
{
  
      // Add members from wxEvtHandler
      WrapClass_wxEvtHandler::ptr parent_wxEvtHandler(        boost::dynamic_pointer_cast<WrapClass_wxEvtHandler >(this_ptr));
      parent_wxEvtHandler->AddMethods(parent_wxEvtHandler);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_UnInit( this_ptr);
      AddVar_SetFlags( this_ptr);
      AddVar_GetFlags( this_ptr);
      AddVar_SetManagedWindow( this_ptr);
      AddVar_GetManagedWindow( this_ptr);
      AddVar_SetArtProvider( this_ptr);
      AddVar_GetArtProvider( this_ptr);
      AddVar_GetPane_1( this_ptr);
      AddVar_GetPane( this_ptr);
      AddVar_GetPane_2( this_ptr);
      AddVar_GetAllPanes( this_ptr);
      AddVar_AddPane_1( this_ptr);
      AddVar_AddPane( this_ptr);
      AddVar_AddPane_2( this_ptr);
      AddVar_AddPane_3( this_ptr);
      AddVar_InsertPane( this_ptr);
      AddVar_DetachPane( this_ptr);
      AddVar_Update( this_ptr);
      AddVar_SavePaneInfo( this_ptr);
      AddVar_LoadPaneInfo( this_ptr);
      AddVar_SavePerspective( this_ptr);
      AddVar_LoadPerspective( this_ptr);
      AddVar_SetDockSizeConstraint( this_ptr);
      AddVar_GetDockSizeConstraint( this_ptr);
      AddVar_ClosePane( this_ptr);
      AddVar_MaximizePane( this_ptr);
      AddVar_RestorePane( this_ptr);
      AddVar_RestoreMaximizedPane( this_ptr);
      AddVar_CreateFloatingFrame( this_ptr);
      AddVar_StartPaneDrag( this_ptr);
      AddVar_CalculateHintRect( this_ptr);
      AddVar_DrawHintRect( this_ptr);
      AddVar_ShowHint( this_ptr);
      AddVar_HideHint( this_ptr);
      AddVar_OnRender( this_ptr);
      AddVar_OnPaneButton( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxAuiManager::wxAuiManager(wxWindow * managed_wnd = 0l, unsigned int flags = wxAUI_MGR_DEFAULT)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_wxAuiManager::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'managed_wnd' (def:0l)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flags' (def:wxAUI_MGR_DEFAULT)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_wxAuiManager::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > managed_wnd_smtptr;
  if (!get_val_smtptr_param<wxWindow >(managed_wnd_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* managed_wnd = managed_wnd_smtptr.get();

  long flags_long = boost::numeric_cast<long >((unsigned int)wxAUI_MGR_DEFAULT);;
  if (!get_val_param<long >(flags_long,_p,_n,false,false)) ClassHelpAndReturn;
  unsigned int flags = boost::numeric_cast<unsigned int >(flags_long);

  wxAuiManager* _newobj = new wxAuiManager(managed_wnd, flags);
  BasicVariable::ptr res = WrapClass_wxAuiManager::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxAuiManager * wxAuiManager::GetManager(wxWindow * window)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_static_GetManager::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  return_comments="returning a variable of type wxAuiManager";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_static_GetManager::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* window = window_smtptr.get();

  wxAuiManager * res =   wxAuiManager::GetManager(window);
  BasicVariable::ptr res_var = WrapClass_wxAuiManager::CreateVar(res);
  return res_var;
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
    wrap_UnInit::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

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
    wrap_SetFlags::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long flags_long;
  if (!get_val_param<long >(flags_long,_p,_n,true,false)) ClassHelpAndReturn;
  unsigned int flags = boost::numeric_cast<unsigned int >(flags_long);

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
    wrap_GetFlags::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  unsigned int res =   this->_objectptr->GetObj()->GetFlags();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
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
    wrap_SetManagedWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > managed_wnd_smtptr;
  if (!get_val_smtptr_param<wxWindow >(managed_wnd_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* managed_wnd = managed_wnd_smtptr.get();

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
    wrap_GetManagedWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetManagedWindow();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

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
    wrap_SetArtProvider::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiDockArt > art_provider_smtptr;
  if (!get_val_smtptr_param<wxAuiDockArt >(art_provider_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiDockArt* art_provider = art_provider_smtptr.get();

  this->_objectptr->GetObj()->SetArtProvider(art_provider);
  return BasicVariable::ptr();
}

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
    wrap_GetArtProvider::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiDockArt * res =   this->_objectptr->GetObj()->GetArtProvider();
  BasicVariable::ptr res_var = WrapClass_wxAuiDockArt::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiManager::GetPane(wxWindow * window)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_GetPane_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_GetPane_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->GetPane(window);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxAuiManager::GetPane(...)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_GetPane::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_GetPane::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiManager::wrap_GetPane_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiManager::wrap_GetPane_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiManager::GetPane(wxString const & name)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_GetPane_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_GetPane_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->GetPane(name);
  return AMILabType<wxAuiPaneInfo >::CreateVar(&res);
}

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
    wrap_GetAllPanes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfoArray & res =   this->_objectptr->GetObj()->GetAllPanes();
  return AMILabType<wxAuiPaneInfoArray >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiManager::AddPane(wxWindow * window, wxAuiPaneInfo const & pane_info)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_AddPane_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'pane_info'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_AddPane_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  boost::shared_ptr<wxAuiPaneInfo > pane_info_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(pane_info_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxAuiPaneInfo const & pane_info = *pane_info_smtptr;

  bool res =   this->_objectptr->GetObj()->AddPane(window, pane_info);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxAuiManager::AddPane(...)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_AddPane::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_AddPane::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiManager::wrap_AddPane_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiManager::wrap_AddPane_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxAuiManager::wrap_AddPane_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxAuiManager::AddPane(wxWindow * window, wxAuiPaneInfo const & pane_info, wxPoint const & drop_pos)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_AddPane_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'pane_info'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'drop_pos'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_AddPane_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  boost::shared_ptr<wxAuiPaneInfo > pane_info_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(pane_info_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxAuiPaneInfo const & pane_info = *pane_info_smtptr;

  boost::shared_ptr<wxPoint > drop_pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(drop_pos_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & drop_pos = *drop_pos_smtptr;

  bool res =   this->_objectptr->GetObj()->AddPane(window, pane_info, drop_pos);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiManager::AddPane(wxWindow * window, int direction = wxLEFT, wxString const & caption = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_AddPane_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'direction' (def:wxLEFT)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'caption' (def:wxEmptyString)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_AddPane_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  int direction = wxLEFT;
  if (!get_val_param<int >(direction,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > caption_smtptr;
  if (!get_val_smtptr_param<wxString >(caption_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & caption = ( caption_smtptr.get() ? (*caption_smtptr) : wxString(wxEmptyString) );

  bool res =   this->_objectptr->GetObj()->AddPane(window, direction, caption);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiManager::InsertPane(wxWindow * window, wxAuiPaneInfo const & insert_location, int insert_level = wxAUI_INSERT_PANE)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_InsertPane::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'insert_location'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'insert_level' (def:wxAUI_INSERT_PANE)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_InsertPane::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* window = window_smtptr.get();

  boost::shared_ptr<wxAuiPaneInfo > insert_location_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(insert_location_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiPaneInfo const & insert_location = *insert_location_smtptr;

  int insert_level = wxAUI_INSERT_PANE;
  if (!get_val_param<int >(insert_level,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->InsertPane(window, insert_location, insert_level);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

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
    wrap_DetachPane::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* window = window_smtptr.get();

  bool res =   this->_objectptr->GetObj()->DetachPane(window);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
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
    wrap_Update::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Update();
  return BasicVariable::ptr();
}

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
    wrap_SavePaneInfo::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfo > pane_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(pane_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiPaneInfo & pane = *pane_smtptr;

  wxString res =   this->_objectptr->GetObj()->SavePaneInfo(pane);
  return AMILabType<wxString >::CreateVar(res);
}

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
    wrap_LoadPaneInfo::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  wxString pane_part;
  if (!get_val_param<wxString >(pane_part,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxAuiPaneInfo > pane_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(pane_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiPaneInfo & pane = *pane_smtptr;

  this->_objectptr->GetObj()->LoadPaneInfo(pane_part, pane);
  return BasicVariable::ptr();
}

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
    wrap_SavePerspective::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->SavePerspective();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiManager::LoadPerspective(wxString const & perspective, bool update = true)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_LoadPerspective::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'perspective'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'update' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_LoadPerspective::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > perspective_smtptr;
  if (!get_val_smtptr_param<wxString >(perspective_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & perspective = *perspective_smtptr;

  int update_int = ((true==true)?1:0);;
  if (!get_val_param<int >(update_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool update = (bool) (update_int>0.5);

  bool res =   this->_objectptr->GetObj()->LoadPerspective(perspective, update);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
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
    wrap_SetDockSizeConstraint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  double width_pct;
  if (!get_val_param<double >(width_pct,_p,_n,true,false)) ClassHelpAndReturn;

  double height_pct;
  if (!get_val_param<double >(height_pct,_p,_n,true,false)) ClassHelpAndReturn;

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
    wrap_GetDockSizeConstraint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > width_pct_smtptr;
  if (!get_val_smtptr_param<double >(width_pct_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* width_pct = width_pct_smtptr.get();

  boost::shared_ptr<double > height_pct_smtptr;
  if (!get_val_smtptr_param<double >(height_pct_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* height_pct = height_pct_smtptr.get();

  this->_objectptr->GetObj()->GetDockSizeConstraint(width_pct, height_pct);
  return BasicVariable::ptr();
}

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
    wrap_ClosePane::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfo > pane_info_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(pane_info_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiPaneInfo & pane_info = *pane_info_smtptr;

  this->_objectptr->GetObj()->ClosePane(pane_info);
  return BasicVariable::ptr();
}

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
    wrap_MaximizePane::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfo > pane_info_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(pane_info_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiPaneInfo & pane_info = *pane_info_smtptr;

  this->_objectptr->GetObj()->MaximizePane(pane_info);
  return BasicVariable::ptr();
}

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
    wrap_RestorePane::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfo > pane_info_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(pane_info_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiPaneInfo & pane_info = *pane_info_smtptr;

  this->_objectptr->GetObj()->RestorePane(pane_info);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiManager::RestoreMaximizedPane()
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_RestoreMaximizedPane::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_RestoreMaximizedPane::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RestoreMaximizedPane();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxAuiFloatingFrame * wxAuiManager::CreateFloatingFrame(wxWindow * parent, wxAuiPaneInfo const & p)
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
    wrap_CreateFloatingFrame::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();

  boost::shared_ptr<wxAuiPaneInfo > p_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiPaneInfo const & p = *p_smtptr;

  wxAuiFloatingFrame * res =   this->_objectptr->GetObj()->CreateFloatingFrame(parent, p);
  BasicVariable::ptr res_var = WrapClass_wxAuiFloatingFrame::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxAuiManager::StartPaneDrag(wxWindow * pane_window, wxPoint const & offset)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_StartPaneDrag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'pane_window'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'offset'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_StartPaneDrag::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > pane_window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(pane_window_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* pane_window = pane_window_smtptr.get();

  boost::shared_ptr<wxPoint > offset_smtptr;
  if (!get_val_smtptr_param<wxPoint >(offset_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & offset = *offset_smtptr;

  this->_objectptr->GetObj()->StartPaneDrag(pane_window, offset);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxRect wxAuiManager::CalculateHintRect(wxWindow * pane_window, wxPoint const & pt, wxPoint const & offset)
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
    wrap_CalculateHintRect::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > pane_window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(pane_window_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* pane_window = pane_window_smtptr.get();

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & pt = *pt_smtptr;

  boost::shared_ptr<wxPoint > offset_smtptr;
  if (!get_val_smtptr_param<wxPoint >(offset_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & offset = *offset_smtptr;

  wxRect res =   this->_objectptr->GetObj()->CalculateHintRect(pane_window, pt, offset);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiManager::DrawHintRect(wxWindow * pane_window, wxPoint const & pt, wxPoint const & offset)
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
    wrap_DrawHintRect::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > pane_window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(pane_window_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* pane_window = pane_window_smtptr.get();

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & pt = *pt_smtptr;

  boost::shared_ptr<wxPoint > offset_smtptr;
  if (!get_val_smtptr_param<wxPoint >(offset_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & offset = *offset_smtptr;

  this->_objectptr->GetObj()->DrawHintRect(pane_window, pt, offset);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiManager::ShowHint(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_ShowHint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_ShowHint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRect const & rect = *rect_smtptr;

  this->_objectptr->GetObj()->ShowHint(rect);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiManager::HideHint()
//---------------------------------------------------
void WrapClass_wxAuiManager::
    wrap_HideHint::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiManager::
    wrap_HideHint::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->HideHint();
  return BasicVariable::ptr();
}

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
    wrap_OnRender::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiManagerEvent > evt_smtptr;
  if (!get_val_smtptr_param<wxAuiManagerEvent >(evt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiManagerEvent & evt = *evt_smtptr;

  this->_objectptr->GetObj()->OnRender(evt);
  return BasicVariable::ptr();
}

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
    wrap_OnPaneButton::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiManagerEvent > evt_smtptr;
  if (!get_val_smtptr_param<wxAuiManagerEvent >(evt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiManagerEvent & evt = *evt_smtptr;

  this->_objectptr->GetObj()->OnPaneButton(evt);
  return BasicVariable::ptr();
}

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
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

