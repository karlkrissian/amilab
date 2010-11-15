/**
 * C++ Interface: wrap_wxWindowBase
 *
 * Description: wrapping wxWindowBase
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
#include "wrap_wxWindowBase.h"
#include "wrap_wxPoint.h"
#include "wrap_wxSize.h"
#include "wrap_wxString.h"
#include "wrap_wxRect.h"
#include "wrap_wxWindow.h"
#include "wrap_wxVisualAttributes.h"
#include "wrap_wxFont.h"
#include "wrap_wxSizer.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxWindowBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxWindowBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxWindowBase);
AMI_DEFINE_VARFROMSMTPTR(wxWindowBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxWindowBase>::CreateVar( wxWindowBase* val)
{ 
  boost::shared_ptr<wxWindowBase> obj_ptr(val,wxwindow_nodeleter<wxWindowBase>());
  return AMILabType<wxWindowBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxWindowBase
//
Variable<AMIObject>::ptr WrapClass_wxWindowBase::CreateVar( wxWindowBase* sp)
{
  boost::shared_ptr<wxWindowBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxWindowBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxWindowBase>::CreateVar(
      new WrapClass_wxWindowBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxWindowBase::AddMethods(WrapClass<wxWindowBase>::ptr this_ptr )
{
  /*
      // Add members from wxEvtHandler
      WrapClass_wxEvtHandler::ptr parent_wxEvtHandler(        boost::dynamic_pointer_cast<WrapClass_wxEvtHandler >(this_ptr));
      parent_wxEvtHandler->AddMethods(parent_wxEvtHandler);
      */


  // check that the method name is not a token
  
      // Adding standard methods 
/* The following types are missing: wxValidator
      AddVar_CreateBase( this_ptr);
*/
      AddVar_Close( this_ptr);
      AddVar_Destroy( this_ptr);
      AddVar_DestroyChildren( this_ptr);
      AddVar_IsBeingDeleted( this_ptr);
      AddVar_SetName( this_ptr);
      AddVar_GetName( this_ptr);
      AddVar_SetWindowVariant( this_ptr);
      AddVar_GetWindowVariant( this_ptr);
      AddVar_SetId( this_ptr);
      AddVar_GetId( this_ptr);
      AddVar_GetLayoutDirection( this_ptr);
      AddVar_SetLayoutDirection( this_ptr);
      AddVar_AdjustForLayoutDirection( this_ptr);
      AddVar_NewControlId( this_ptr);
      AddVar_NextControlId( this_ptr);
      AddVar_PrevControlId( this_ptr);
      AddVar_SetSize_1( this_ptr);
      AddVar_SetSize( this_ptr);
      AddVar_SetSize_2( this_ptr);
      AddVar_SetSize_3( this_ptr);
      AddVar_SetSize_4( this_ptr);
      AddVar_Move_1( this_ptr);
      AddVar_Move( this_ptr);
      AddVar_Move_2( this_ptr);
      AddVar_SetPosition( this_ptr);
      AddVar_SetClientSize_1( this_ptr);
      AddVar_SetClientSize( this_ptr);
      AddVar_SetClientSize_2( this_ptr);
      AddVar_SetClientSize_3( this_ptr);
      AddVar_GetPosition_1( this_ptr);
      AddVar_GetPosition( this_ptr);
      AddVar_GetPosition_2( this_ptr);
      AddVar_GetScreenPosition_1( this_ptr);
      AddVar_GetScreenPosition( this_ptr);
      AddVar_GetScreenPosition_2( this_ptr);
      AddVar_GetSize_1( this_ptr);
      AddVar_GetSize( this_ptr);
      AddVar_GetSize_2( this_ptr);
      AddVar_GetClientSize_1( this_ptr);
      AddVar_GetClientSize( this_ptr);
      AddVar_GetClientSize_2( this_ptr);
      AddVar_GetRect( this_ptr);
      AddVar_GetScreenRect( this_ptr);
      AddVar_GetClientAreaOrigin( this_ptr);
      AddVar_GetClientRect( this_ptr);
      AddVar_ClientToWindowSize( this_ptr);
      AddVar_WindowToClientSize( this_ptr);
      AddVar_GetBestSize_1( this_ptr);
      AddVar_GetBestSize( this_ptr);
      AddVar_GetBestSize_2( this_ptr);
/* The following types are missing: wxScrollHelper
      AddVar_SetScrollHelper( this_ptr);
*/
/* The following types are missing: wxScrollHelper
      AddVar_GetScrollHelper( this_ptr);
*/
      AddVar_InvalidateBestSize( this_ptr);
      AddVar_CacheBestSize( this_ptr);
      AddVar_GetEffectiveMinSize( this_ptr);
      AddVar_SetInitialSize( this_ptr);
      AddVar_Centre( this_ptr);
      AddVar_Center( this_ptr);
      AddVar_CentreOnParent( this_ptr);
      AddVar_CenterOnParent( this_ptr);
      AddVar_Fit( this_ptr);
      AddVar_FitInside( this_ptr);
      AddVar_SetSizeHints_1( this_ptr);
      AddVar_SetSizeHints( this_ptr);
      AddVar_SetSizeHints_2( this_ptr);
      AddVar_DoSetSizeHints( this_ptr);
      AddVar_SetVirtualSizeHints_1( this_ptr);
      AddVar_SetVirtualSizeHints( this_ptr);
      AddVar_SetVirtualSizeHints_2( this_ptr);
      AddVar_SetMinSize( this_ptr);
      AddVar_SetMaxSize( this_ptr);
      AddVar_GetMinSize( this_ptr);
      AddVar_GetMaxSize( this_ptr);
      AddVar_GetMinWidth( this_ptr);
      AddVar_GetMinHeight( this_ptr);
      AddVar_GetMaxWidth( this_ptr);
      AddVar_GetMaxHeight( this_ptr);
      AddVar_SetVirtualSize_1( this_ptr);
      AddVar_SetVirtualSize( this_ptr);
      AddVar_SetVirtualSize_2( this_ptr);
      AddVar_GetVirtualSize_1( this_ptr);
      AddVar_GetVirtualSize( this_ptr);
      AddVar_GetVirtualSize_2( this_ptr);
      AddVar_DoSetVirtualSize( this_ptr);
      AddVar_DoGetVirtualSize( this_ptr);
      AddVar_GetBestVirtualSize( this_ptr);
      AddVar_GetWindowBorderSize( this_ptr);
      AddVar_Show( this_ptr);
      AddVar_Hide( this_ptr);
      AddVar_Enable( this_ptr);
      AddVar_Disable( this_ptr);
      AddVar_IsShown( this_ptr);
      AddVar_IsEnabled( this_ptr);
      AddVar_IsShownOnScreen( this_ptr);
      AddVar_SetWindowStyleFlag( this_ptr);
      AddVar_GetWindowStyleFlag( this_ptr);
      AddVar_SetWindowStyle( this_ptr);
      AddVar_GetWindowStyle( this_ptr);
      AddVar_HasFlag( this_ptr);
      AddVar_IsRetained( this_ptr);
      AddVar_ToggleWindowStyle( this_ptr);
      AddVar_SetExtraStyle( this_ptr);
      AddVar_GetExtraStyle( this_ptr);
      AddVar_MakeModal( this_ptr);
      AddVar_SetThemeEnabled( this_ptr);
      AddVar_GetThemeEnabled( this_ptr);
      AddVar_SetFocusFromKbd( this_ptr);
      AddVar_FindFocus( this_ptr);
      AddVar_DoFindFocus( this_ptr);
      AddVar_AcceptsFocus( this_ptr);
      AddVar_AcceptsFocusFromKeyboard( this_ptr);
      AddVar_MoveBeforeInTabOrder( this_ptr);
      AddVar_MoveAfterInTabOrder( this_ptr);
/* The following types are missing: wxWindowList
      AddVar_GetChildren_1( this_ptr);
*/
      AddVar_GetChildren( this_ptr);
/* The following types are missing: wxWindowList
      AddVar_GetChildren_2( this_ptr);
*/
/* The following types are missing: wxWindowList
      AddVar_GetWindowChildren( this_ptr);
*/
      AddVar_GetPrevSibling( this_ptr);
      AddVar_GetNextSibling( this_ptr);
      AddVar_GetParent( this_ptr);
      AddVar_GetGrandParent( this_ptr);
      AddVar_IsTopLevel( this_ptr);
      AddVar_SetParent( this_ptr);
      AddVar_Reparent( this_ptr);
      AddVar_AddChild( this_ptr);
      AddVar_RemoveChild( this_ptr);
      AddVar_FindWindow_1( this_ptr);
      AddVar_FindWindow( this_ptr);
      AddVar_FindWindow_2( this_ptr);
      AddVar_FindWindowById( this_ptr);
      AddVar_FindWindowByName( this_ptr);
      AddVar_FindWindowByLabel( this_ptr);
/* The following types are missing: wxEvtHandler
      AddVar_GetEventHandler( this_ptr);
*/
/* The following types are missing: wxEvtHandler
      AddVar_SetEventHandler( this_ptr);
*/
/* The following types are missing: wxEvtHandler
      AddVar_PushEventHandler( this_ptr);
*/
/* The following types are missing: wxEvtHandler
      AddVar_PopEventHandler( this_ptr);
*/
/* The following types are missing: wxEvtHandler
      AddVar_RemoveEventHandler( this_ptr);
*/
/* The following types are missing: wxValidator
      AddVar_SetValidator( this_ptr);
*/
/* The following types are missing: wxValidator
      AddVar_GetValidator( this_ptr);
*/
      AddVar_Validate( this_ptr);
      AddVar_TransferDataToWindow( this_ptr);
      AddVar_TransferDataFromWindow( this_ptr);
      AddVar_InitDialog( this_ptr);
/* The following types are missing: wxAcceleratorTable
      AddVar_SetAcceleratorTable( this_ptr);
*/
/* The following types are missing: wxAcceleratorTable
      AddVar_GetAcceleratorTable( this_ptr);
*/
      AddVar_ConvertPixelsToDialog_1( this_ptr);
      AddVar_ConvertDialogToPixels_1( this_ptr);
      AddVar_ConvertPixelsToDialog( this_ptr);
      AddVar_ConvertPixelsToDialog_2( this_ptr);
      AddVar_ConvertDialogToPixels( this_ptr);
      AddVar_ConvertDialogToPixels_2( this_ptr);
      AddVar_CaptureMouse( this_ptr);
      AddVar_ReleaseMouse( this_ptr);
      AddVar_GetCapture( this_ptr);
      AddVar_HasCapture( this_ptr);
      AddVar_RefreshRect( this_ptr);
      AddVar_Update( this_ptr);
      AddVar_ClearBackground( this_ptr);
      AddVar_Freeze( this_ptr);
      AddVar_Thaw( this_ptr);
      AddVar_IsFrozen( this_ptr);
/* The following types are missing: wxDC
      AddVar_PrepareDC( this_ptr);
*/
      AddVar_IsDoubleBuffered( this_ptr);
/* The following types are missing: wxRegion
      AddVar_GetUpdateRegion_1( this_ptr);
*/
      AddVar_GetUpdateRegion( this_ptr);
/* The following types are missing: wxRegion
      AddVar_GetUpdateRegion_2( this_ptr);
*/
      AddVar_GetUpdateClientRect( this_ptr);
      AddVar_DoIsExposed_1( this_ptr);
      AddVar_DoIsExposed( this_ptr);
      AddVar_DoIsExposed_2( this_ptr);
      AddVar_IsExposed_1( this_ptr);
      AddVar_IsExposed( this_ptr);
      AddVar_IsExposed_2( this_ptr);
      AddVar_IsExposed_3( this_ptr);
      AddVar_IsExposed_4( this_ptr);
      AddVar_GetDefaultAttributes( this_ptr);
      AddVar_GetClassDefaultAttributes( this_ptr);
/* The following types are missing: wxColour
      AddVar_SetBackgroundColour( this_ptr);
*/
/* The following types are missing: wxColour
      AddVar_SetOwnBackgroundColour( this_ptr);
*/
/* The following types are missing: wxColour
      AddVar_GetBackgroundColour( this_ptr);
*/
      AddVar_InheritsBackgroundColour( this_ptr);
      AddVar_UseBgCol( this_ptr);
/* The following types are missing: wxColour
      AddVar_SetForegroundColour( this_ptr);
*/
/* The following types are missing: wxColour
      AddVar_SetOwnForegroundColour( this_ptr);
*/
/* The following types are missing: wxColour
      AddVar_GetForegroundColour( this_ptr);
*/
      AddVar_SetBackgroundStyle( this_ptr);
      AddVar_GetBackgroundStyle( this_ptr);
      AddVar_HasTransparentBackground( this_ptr);
      AddVar_SetOwnFont( this_ptr);
      AddVar_GetFont( this_ptr);
/* The following types are missing: wxCursor
      AddVar_SetCursor( this_ptr);
*/
/* The following types are missing: wxCursor
      AddVar_GetCursor( this_ptr);
*/
/* The following types are missing: wxCaret
      AddVar_SetCaret( this_ptr);
*/
/* The following types are missing: wxCaret
      AddVar_GetCaret( this_ptr);
*/
      AddVar_ClientToScreen_1( this_ptr);
      AddVar_ScreenToClient_1( this_ptr);
      AddVar_ClientToScreen( this_ptr);
      AddVar_ClientToScreen_2( this_ptr);
      AddVar_ScreenToClient( this_ptr);
      AddVar_ScreenToClient_2( this_ptr);
      AddVar_HitTest_1( this_ptr);
      AddVar_HitTest( this_ptr);
      AddVar_HitTest_2( this_ptr);
      AddVar_GetBorder_1( this_ptr);
      AddVar_GetBorder( this_ptr);
      AddVar_GetBorder_2( this_ptr);
      AddVar_UpdateWindowUI( this_ptr);
/* The following types are missing: wxUpdateUIEvent
      AddVar_DoUpdateWindowUI( this_ptr);
*/
/* The following types are missing: wxMenu
      AddVar_PopupMenu_1( this_ptr);
*/
      AddVar_PopupMenu( this_ptr);
/* The following types are missing: wxMenu
      AddVar_PopupMenu_2( this_ptr);
*/
      AddVar_HasMultiplePages( this_ptr);
      AddVar_HasScrollbar( this_ptr);
      AddVar_ScrollLines( this_ptr);
      AddVar_ScrollPages( this_ptr);
      AddVar_LineUp( this_ptr);
      AddVar_LineDown( this_ptr);
      AddVar_PageUp( this_ptr);
      AddVar_PageDown( this_ptr);
      AddVar_SetHelpText( this_ptr);
      AddVar_SetHelpTextForId( this_ptr);
      AddVar_GetHelpText( this_ptr);
      AddVar_SetToolTip_1( this_ptr);
      AddVar_SetToolTip( this_ptr);
/* The following types are missing: wxToolTip
      AddVar_SetToolTip_2( this_ptr);
*/
      AddVar_UnsetToolTip( this_ptr);
/* The following types are missing: wxToolTip
      AddVar_GetToolTip( this_ptr);
*/
/* The following types are missing: wxDropTarget
      AddVar_GetDropTarget( this_ptr);
*/
      AddVar_DragAcceptFiles( this_ptr);
/* The following types are missing: wxLayoutConstraints
      AddVar_SetConstraints( this_ptr);
*/
/* The following types are missing: wxLayoutConstraints
      AddVar_GetConstraints( this_ptr);
*/
/* The following types are missing: wxLayoutConstraints
      AddVar_UnsetConstraints( this_ptr);
*/
/* The following types are missing: wxWindowList
      AddVar_GetConstraintsInvolvedIn( this_ptr);
*/
      AddVar_AddConstraintReference( this_ptr);
      AddVar_RemoveConstraintReference( this_ptr);
      AddVar_DeleteRelatedConstraints( this_ptr);
      AddVar_ResetConstraints( this_ptr);
      AddVar_SetConstraintSizes( this_ptr);
      AddVar_LayoutPhase1( this_ptr);
      AddVar_LayoutPhase2( this_ptr);
      AddVar_DoPhase( this_ptr);
      AddVar_SetSizeConstraint( this_ptr);
      AddVar_MoveConstraint( this_ptr);
      AddVar_GetSizeConstraint( this_ptr);
      AddVar_GetClientSizeConstraint( this_ptr);
      AddVar_GetPositionConstraint( this_ptr);
      AddVar_SetAutoLayout( this_ptr);
      AddVar_GetAutoLayout( this_ptr);
      AddVar_Layout( this_ptr);
      AddVar_SetSizer( this_ptr);
      AddVar_SetSizerAndFit( this_ptr);
      AddVar_GetSizer( this_ptr);
      AddVar_SetContainingSizer( this_ptr);
      AddVar_GetContainingSizer( this_ptr);
      AddVar_SetTransparent( this_ptr);
      AddVar_CanSetTransparent( this_ptr);
/* The following types are missing: wxSysColourChangedEvent
      AddVar_OnSysColourChanged( this_ptr);
*/
/* The following types are missing: wxInitDialogEvent
      AddVar_OnInitDialog( this_ptr);
*/
/* The following types are missing: wxMouseEvent
      AddVar_OnMiddleClick( this_ptr);
*/
/* The following types are missing: wxHelpEvent
      AddVar_OnHelp( this_ptr);
*/
      AddVar_OnInternalIdle( this_ptr);
/* The following types are missing: _GtkWidget
      AddVar_AssociateHandle( this_ptr);
*/
      AddVar_DissociateHandle( this_ptr);
/* The following types are missing: wxPalette
      AddVar_GetPalette( this_ptr);
*/
/* The following types are missing: wxPalette
      AddVar_SetPalette( this_ptr);
*/
      AddVar_HasCustomPalette( this_ptr);
      AddVar_GetAncestorWithCustomPalette( this_ptr);
      AddVar_InheritAttributes( this_ptr);
      AddVar_ShouldInheritColours( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------

/* The following types are missing: wxValidator

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::CreateBase(wxWindowBase * parent, wxWindowID winid, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxPanelNameStr)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_CreateBase::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxValidator, "parameter named 'validator' (def:wxDefaultValidator)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxPanelNameStr)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_CreateBase::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowBase > parent_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(parent_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindowBase* parent = parent_smtptr.get();

  int winid;
  if (!get_val_param<int >(winid,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = (pos_smtptr.get()?
    (wxPoint const &) (*pos_smtptr):
    (wxPoint const &) wxDefaultPosition);

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = (size_smtptr.get()?
    (wxSize const &) (*size_smtptr):
    (wxSize const &) wxDefaultSize);

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxValidator > validator_smtptr;
  if (!get_val_smtptr_param<wxValidator >(validator_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxValidator const & validator = (validator_smtptr.get()?
    (wxValidator const &) (*validator_smtptr):
    (wxValidator const &) wxDefaultValidator);

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = (name_smtptr.get()?
    (wxString const &) (*name_smtptr):
    (wxString const &) wxPanelNameStr);

  bool res =   this->_objectptr->GetObj()->CreateBase(parent, winid, pos, size, style, validator, name);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::Close(bool force = false)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Close::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'force' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Close::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int force_int = ((false==true)?1:0);;
  if (!get_val_param<int >(force_int,_p,_n)) ClassHelpAndReturn;
  bool force = (bool) (force_int>0.5);

  bool res =   this->_objectptr->GetObj()->Close(force);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::Destroy()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Destroy::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Destroy::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Destroy();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::DestroyChildren()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_DestroyChildren::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_DestroyChildren::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->DestroyChildren();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::IsBeingDeleted()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_IsBeingDeleted::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_IsBeingDeleted::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsBeingDeleted();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetName(wxString const & name)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  this->_objectptr->GetObj()->SetName(name);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxWindowBase::GetName()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetName::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetName();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetWindowVariant(wxWindowVariant variant)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetWindowVariant::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'variant'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetWindowVariant::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int variant_int;
  if (!get_val_param<int >(variant_int,_p,_n)) ClassHelpAndReturn;
  wxWindowVariant variant = (wxWindowVariant) variant_int;

  this->_objectptr->GetObj()->SetWindowVariant(variant);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxWindowVariant wxWindowBase::GetWindowVariant()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetWindowVariant::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetWindowVariant::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindowVariant res =   this->_objectptr->GetObj()->GetWindowVariant();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetId(wxWindowID winid)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int winid;
  if (!get_val_param<int >(winid,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetId(winid);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxWindowID wxWindowBase::GetId()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetId::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindowID res =   this->_objectptr->GetObj()->GetId();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxLayoutDirection wxWindowBase::GetLayoutDirection()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetLayoutDirection::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetLayoutDirection::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxLayoutDirection res =   this->_objectptr->GetObj()->GetLayoutDirection();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetLayoutDirection(wxLayoutDirection param0)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetLayoutDirection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetLayoutDirection::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int param0_int;
  if (!get_val_param<int >(param0_int,_p,_n)) ClassHelpAndReturn;
  wxLayoutDirection param0 = (wxLayoutDirection) param0_int;

  this->_objectptr->GetObj()->SetLayoutDirection(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxCoord wxWindowBase::AdjustForLayoutDirection(wxCoord x, wxCoord width, wxCoord widthTotal)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_AdjustForLayoutDirection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'widthTotal'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_AdjustForLayoutDirection::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassHelpAndReturn;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassHelpAndReturn;

  int widthTotal;
  if (!get_val_param<int >(widthTotal,_p,_n)) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->AdjustForLayoutDirection(x, width, widthTotal);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxWindowBase::NewControlId()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_NewControlId::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_NewControlId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->NewControlId();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxWindowBase::NextControlId(int winid)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_NextControlId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_NextControlId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int winid;
  if (!get_val_param<int >(winid,_p,_n)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->NextControlId(winid);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxWindowBase::PrevControlId(int winid)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_PrevControlId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_PrevControlId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int winid;
  if (!get_val_param<int >(winid,_p,_n)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->PrevControlId(winid);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetSize(int x, int y, int width, int height, int sizeFlags = 3)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetSize_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'sizeFlags' (def:3)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetSize_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassReturnEmptyVar;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  int sizeFlags = 3;
  if (!get_val_param<int >(sizeFlags,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetSize(x, y, width, height, sizeFlags);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::SetSize(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_SetSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_SetSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_SetSize_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_SetSize_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetSize(int width, int height)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetSize(width, height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetSize(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetSize_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetSize_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  this->_objectptr->GetObj()->SetSize(size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetSize(wxRect const & rect, int sizeFlags = 3)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetSize_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'sizeFlags' (def:3)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetSize_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  int sizeFlags = 3;
  if (!get_val_param<int >(sizeFlags,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetSize(rect, sizeFlags);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::Move(int x, int y, int flags = 0)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Move_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Move_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassReturnEmptyVar;

  int flags = 0;
  if (!get_val_param<int >(flags,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Move(x, y, flags);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::Move(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Move::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Move::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_Move_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_Move_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::Move(wxPoint const & pt, int flags = 0)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Move_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Move_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  int flags = 0;
  if (!get_val_param<int >(flags,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Move(pt, flags);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetPosition(wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetPosition::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetPosition::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n)) ClassHelpAndReturn;
  wxPoint const & pt = *pt_smtptr;

  this->_objectptr->GetObj()->SetPosition(pt);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetClientSize(int width, int height)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetClientSize_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetClientSize_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetClientSize(width, height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::SetClientSize(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetClientSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetClientSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_SetClientSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_SetClientSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_SetClientSize_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetClientSize(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetClientSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetClientSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  this->_objectptr->GetObj()->SetClientSize(size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetClientSize(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetClientSize_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetClientSize_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  this->_objectptr->GetObj()->SetClientSize(rect);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::GetPosition(int * x, int * y)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetPosition_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetPosition_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > x_smtptr;
  if (!get_val_smtptr_param<int >(x_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* x = x_smtptr.get();

  boost::shared_ptr<int > y_smtptr;
  if (!get_val_smtptr_param<int >(y_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* y = y_smtptr.get();

  this->_objectptr->GetObj()->GetPosition(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::GetPosition(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_GetPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_GetPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxPoint wxWindowBase::GetPosition()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetPosition_2::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetPosition_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxPoint res =   this->_objectptr->GetObj()->GetPosition();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::GetScreenPosition(int * x, int * y)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetScreenPosition_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetScreenPosition_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > x_smtptr;
  if (!get_val_smtptr_param<int >(x_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* x = x_smtptr.get();

  boost::shared_ptr<int > y_smtptr;
  if (!get_val_smtptr_param<int >(y_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* y = y_smtptr.get();

  this->_objectptr->GetObj()->GetScreenPosition(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::GetScreenPosition(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetScreenPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetScreenPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_GetScreenPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_GetScreenPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxPoint wxWindowBase::GetScreenPosition()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetScreenPosition_2::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetScreenPosition_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxPoint res =   this->_objectptr->GetObj()->GetScreenPosition();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::GetSize(int * w, int * h)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetSize_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetSize_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > w_smtptr;
  if (!get_val_smtptr_param<int >(w_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* w = w_smtptr.get();

  boost::shared_ptr<int > h_smtptr;
  if (!get_val_smtptr_param<int >(h_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* h = h_smtptr.get();

  this->_objectptr->GetObj()->GetSize(w, h);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::GetSize(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_GetSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_GetSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxSize wxWindowBase::GetSize()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetSize_2::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetSize_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxSize res =   this->_objectptr->GetObj()->GetSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::GetClientSize(int * w, int * h)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetClientSize_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetClientSize_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > w_smtptr;
  if (!get_val_smtptr_param<int >(w_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* w = w_smtptr.get();

  boost::shared_ptr<int > h_smtptr;
  if (!get_val_smtptr_param<int >(h_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* h = h_smtptr.get();

  this->_objectptr->GetObj()->GetClientSize(w, h);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::GetClientSize(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetClientSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetClientSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_GetClientSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_GetClientSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxSize wxWindowBase::GetClientSize()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetClientSize_2::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetClientSize_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxSize res =   this->_objectptr->GetObj()->GetClientSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRect wxWindowBase::GetRect()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetRect::SetParametersComments()
{
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetRect::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxRect res =   this->_objectptr->GetObj()->GetRect();
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRect wxWindowBase::GetScreenRect()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetScreenRect::SetParametersComments()
{
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetScreenRect::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxRect res =   this->_objectptr->GetObj()->GetScreenRect();
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxWindowBase::GetClientAreaOrigin()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetClientAreaOrigin::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetClientAreaOrigin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint res =   this->_objectptr->GetObj()->GetClientAreaOrigin();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRect wxWindowBase::GetClientRect()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetClientRect::SetParametersComments()
{
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetClientRect::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxRect res =   this->_objectptr->GetObj()->GetClientRect();
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSize wxWindowBase::ClientToWindowSize(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ClientToWindowSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ClientToWindowSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize const & size = *size_smtptr;

  wxSize res =   this->_objectptr->GetObj()->ClientToWindowSize(size);
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSize wxWindowBase::WindowToClientSize(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_WindowToClientSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_WindowToClientSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize const & size = *size_smtptr;

  wxSize res =   this->_objectptr->GetObj()->WindowToClientSize(size);
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSize wxWindowBase::GetBestSize()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetBestSize_1::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetBestSize_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxSize res =   this->_objectptr->GetObj()->GetBestSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::GetBestSize(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetBestSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetBestSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_GetBestSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_GetBestSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::GetBestSize(int * w, int * h)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetBestSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetBestSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > w_smtptr;
  if (!get_val_smtptr_param<int >(w_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* w = w_smtptr.get();

  boost::shared_ptr<int > h_smtptr;
  if (!get_val_smtptr_param<int >(h_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* h = h_smtptr.get();

  this->_objectptr->GetObj()->GetBestSize(w, h);
  return BasicVariable::ptr();
}
/* The following types are missing: wxScrollHelper

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetScrollHelper(wxScrollHelper * sh)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetScrollHelper::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScrollHelper, "parameter named 'sh'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetScrollHelper::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxScrollHelper > sh_smtptr;
  if (!get_val_smtptr_param<wxScrollHelper >(sh_smtptr,_p,_n)) ClassHelpAndReturn;
  wxScrollHelper* sh = sh_smtptr.get();

  this->_objectptr->GetObj()->SetScrollHelper(sh);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxScrollHelper

//---------------------------------------------------
//  Wrapping of wxScrollHelper * wxWindowBase::GetScrollHelper()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetScrollHelper::SetParametersComments()
{
  return_comments="returning a variable of type wxScrollHelper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetScrollHelper::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxScrollHelper * res =   this->_objectptr->GetObj()->GetScrollHelper();
  return AMILabType<wxScrollHelper >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxWindowBase::InvalidateBestSize()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_InvalidateBestSize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_InvalidateBestSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InvalidateBestSize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::CacheBestSize(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_CacheBestSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_CacheBestSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize const & size = *size_smtptr;

  this->_objectptr->GetObj()->CacheBestSize(size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxWindowBase::GetEffectiveMinSize()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetEffectiveMinSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetEffectiveMinSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetEffectiveMinSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetInitialSize(wxSize const & size = wxDefaultSize)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetInitialSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetInitialSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = (size_smtptr.get()?
    (wxSize const &) (*size_smtptr):
    (wxSize const &) wxDefaultSize);

  this->_objectptr->GetObj()->SetInitialSize(size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::Centre(int dir = wxBOTH)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Centre::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dir' (def:wxBOTH)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Centre::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int dir = wxBOTH;
  if (!get_val_param<int >(dir,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Centre(dir);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::Center(int dir = wxBOTH)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Center::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dir' (def:wxBOTH)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Center::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int dir = wxBOTH;
  if (!get_val_param<int >(dir,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Center(dir);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::CentreOnParent(int dir = wxBOTH)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_CentreOnParent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dir' (def:wxBOTH)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_CentreOnParent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int dir = wxBOTH;
  if (!get_val_param<int >(dir,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->CentreOnParent(dir);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::CenterOnParent(int dir = wxBOTH)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_CenterOnParent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dir' (def:wxBOTH)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_CenterOnParent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int dir = wxBOTH;
  if (!get_val_param<int >(dir,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->CenterOnParent(dir);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::Fit()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Fit::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Fit::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Fit();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::FitInside()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_FitInside::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_FitInside::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->FitInside();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetSizeHints(int minW, int minH, int maxW = wxDefaultCoord, int maxH = wxDefaultCoord, int incW = wxDefaultCoord, int incH = wxDefaultCoord)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetSizeHints_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'minW'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'minH'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'maxW' (def:wxDefaultCoord)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'maxH' (def:wxDefaultCoord)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'incW' (def:wxDefaultCoord)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'incH' (def:wxDefaultCoord)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetSizeHints_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  int minW;
  if (!get_val_param<int >(minW,_p,_n)) ClassReturnEmptyVar;

  int minH;
  if (!get_val_param<int >(minH,_p,_n)) ClassReturnEmptyVar;

  int maxW = wxDefaultCoord;
  if (!get_val_param<int >(maxW,_p,_n)) ClassReturnEmptyVar;

  int maxH = wxDefaultCoord;
  if (!get_val_param<int >(maxH,_p,_n)) ClassReturnEmptyVar;

  int incW = wxDefaultCoord;
  if (!get_val_param<int >(incW,_p,_n)) ClassReturnEmptyVar;

  int incH = wxDefaultCoord;
  if (!get_val_param<int >(incH,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetSizeHints(minW, minH, maxW, maxH, incW, incH);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::SetSizeHints(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetSizeHints::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetSizeHints::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_SetSizeHints_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_SetSizeHints_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetSizeHints(wxSize const & minSize, wxSize const & maxSize = wxDefaultSize, wxSize const & incSize = wxDefaultSize)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetSizeHints_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'minSize'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'maxSize' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'incSize' (def:wxDefaultSize)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetSizeHints_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > minSize_smtptr;
  if (!get_val_smtptr_param<wxSize >(minSize_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSize const & minSize = *minSize_smtptr;

  boost::shared_ptr<wxSize > maxSize_smtptr;
  if (!get_val_smtptr_param<wxSize >(maxSize_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & maxSize = (maxSize_smtptr.get()?
    (wxSize const &) (*maxSize_smtptr):
    (wxSize const &) wxDefaultSize);

  boost::shared_ptr<wxSize > incSize_smtptr;
  if (!get_val_smtptr_param<wxSize >(incSize_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & incSize = (incSize_smtptr.get()?
    (wxSize const &) (*incSize_smtptr):
    (wxSize const &) wxDefaultSize);

  this->_objectptr->GetObj()->SetSizeHints(minSize, maxSize, incSize);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::DoSetSizeHints(int minW, int minH, int maxW, int maxH, int incW, int incH)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_DoSetSizeHints::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'minW'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'minH'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'maxW'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'maxH'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'incW'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'incH'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_DoSetSizeHints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  int minW;
  if (!get_val_param<int >(minW,_p,_n)) ClassHelpAndReturn;

  int minH;
  if (!get_val_param<int >(minH,_p,_n)) ClassHelpAndReturn;

  int maxW;
  if (!get_val_param<int >(maxW,_p,_n)) ClassHelpAndReturn;

  int maxH;
  if (!get_val_param<int >(maxH,_p,_n)) ClassHelpAndReturn;

  int incW;
  if (!get_val_param<int >(incW,_p,_n)) ClassHelpAndReturn;

  int incH;
  if (!get_val_param<int >(incH,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DoSetSizeHints(minW, minH, maxW, maxH, incW, incH);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetVirtualSizeHints(int minW, int minH, int maxW = wxDefaultCoord, int maxH = wxDefaultCoord)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetVirtualSizeHints_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'minW'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'minH'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'maxW' (def:wxDefaultCoord)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'maxH' (def:wxDefaultCoord)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetVirtualSizeHints_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int minW;
  if (!get_val_param<int >(minW,_p,_n)) ClassReturnEmptyVar;

  int minH;
  if (!get_val_param<int >(minH,_p,_n)) ClassReturnEmptyVar;

  int maxW = wxDefaultCoord;
  if (!get_val_param<int >(maxW,_p,_n)) ClassReturnEmptyVar;

  int maxH = wxDefaultCoord;
  if (!get_val_param<int >(maxH,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetVirtualSizeHints(minW, minH, maxW, maxH);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::SetVirtualSizeHints(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetVirtualSizeHints::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetVirtualSizeHints::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_SetVirtualSizeHints_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_SetVirtualSizeHints_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetVirtualSizeHints(wxSize const & minSize, wxSize const & maxSize = wxDefaultSize)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetVirtualSizeHints_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'minSize'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'maxSize' (def:wxDefaultSize)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetVirtualSizeHints_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > minSize_smtptr;
  if (!get_val_smtptr_param<wxSize >(minSize_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSize const & minSize = *minSize_smtptr;

  boost::shared_ptr<wxSize > maxSize_smtptr;
  if (!get_val_smtptr_param<wxSize >(maxSize_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & maxSize = (maxSize_smtptr.get()?
    (wxSize const &) (*maxSize_smtptr):
    (wxSize const &) wxDefaultSize);

  this->_objectptr->GetObj()->SetVirtualSizeHints(minSize, maxSize);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetMinSize(wxSize const & minSize)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetMinSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'minSize'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetMinSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSize > minSize_smtptr;
  if (!get_val_smtptr_param<wxSize >(minSize_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize const & minSize = *minSize_smtptr;

  this->_objectptr->GetObj()->SetMinSize(minSize);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetMaxSize(wxSize const & maxSize)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetMaxSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'maxSize'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetMaxSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSize > maxSize_smtptr;
  if (!get_val_smtptr_param<wxSize >(maxSize_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize const & maxSize = *maxSize_smtptr;

  this->_objectptr->GetObj()->SetMaxSize(maxSize);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxWindowBase::GetMinSize()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetMinSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetMinSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetMinSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSize wxWindowBase::GetMaxSize()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetMaxSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetMaxSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetMaxSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxWindowBase::GetMinWidth()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetMinWidth::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetMinWidth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMinWidth();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxWindowBase::GetMinHeight()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetMinHeight::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetMinHeight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMinHeight();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxWindowBase::GetMaxWidth()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetMaxWidth::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetMaxWidth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMaxWidth();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxWindowBase::GetMaxHeight()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetMaxHeight::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetMaxHeight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMaxHeight();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetVirtualSize(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetVirtualSize_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetVirtualSize_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  this->_objectptr->GetObj()->SetVirtualSize(size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::SetVirtualSize(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetVirtualSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetVirtualSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_SetVirtualSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_SetVirtualSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetVirtualSize(int x, int y)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetVirtualSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetVirtualSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetVirtualSize(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxWindowBase::GetVirtualSize()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetVirtualSize_1::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetVirtualSize_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxSize res =   this->_objectptr->GetObj()->GetVirtualSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::GetVirtualSize(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetVirtualSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetVirtualSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_GetVirtualSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_GetVirtualSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::GetVirtualSize(int * x, int * y)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetVirtualSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetVirtualSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > x_smtptr;
  if (!get_val_smtptr_param<int >(x_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* x = x_smtptr.get();

  boost::shared_ptr<int > y_smtptr;
  if (!get_val_smtptr_param<int >(y_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* y = y_smtptr.get();

  this->_objectptr->GetObj()->GetVirtualSize(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::DoSetVirtualSize(int x, int y)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_DoSetVirtualSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_DoSetVirtualSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DoSetVirtualSize(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxWindowBase::DoGetVirtualSize()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_DoGetVirtualSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_DoGetVirtualSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->DoGetVirtualSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSize wxWindowBase::GetBestVirtualSize()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetBestVirtualSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetBestVirtualSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetBestVirtualSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSize wxWindowBase::GetWindowBorderSize()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetWindowBorderSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetWindowBorderSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetWindowBorderSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::Show(bool show = true)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Show::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'show' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Show::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int show_int = ((true==true)?1:0);;
  if (!get_val_param<int >(show_int,_p,_n)) ClassHelpAndReturn;
  bool show = (bool) (show_int>0.5);

  bool res =   this->_objectptr->GetObj()->Show(show);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::Hide()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Hide::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Hide::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Hide();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::Enable(bool enable = true)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Enable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'enable' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Enable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int enable_int = ((true==true)?1:0);;
  if (!get_val_param<int >(enable_int,_p,_n)) ClassHelpAndReturn;
  bool enable = (bool) (enable_int>0.5);

  bool res =   this->_objectptr->GetObj()->Enable(enable);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::Disable()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Disable::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Disable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Disable();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::IsShown()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_IsShown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_IsShown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsShown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::IsEnabled()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_IsEnabled::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_IsEnabled::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsEnabled();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::IsShownOnScreen()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_IsShownOnScreen::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_IsShownOnScreen::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsShownOnScreen();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetWindowStyleFlag(long int style)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetWindowStyleFlag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetWindowStyleFlag::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long style_long;
  if (!get_val_param<long >(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;

  this->_objectptr->GetObj()->SetWindowStyleFlag(style);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long int wxWindowBase::GetWindowStyleFlag()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetWindowStyleFlag::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetWindowStyleFlag::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   this->_objectptr->GetObj()->GetWindowStyleFlag();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetWindowStyle(long int style)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetWindowStyle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetWindowStyle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long style_long;
  if (!get_val_param<long >(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;

  this->_objectptr->GetObj()->SetWindowStyle(style);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long int wxWindowBase::GetWindowStyle()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetWindowStyle::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetWindowStyle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   this->_objectptr->GetObj()->GetWindowStyle();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::HasFlag(int flag)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_HasFlag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_HasFlag::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int flag;
  if (!get_val_param<int >(flag,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasFlag(flag);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::IsRetained()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_IsRetained::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_IsRetained::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsRetained();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::ToggleWindowStyle(int flag)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ToggleWindowStyle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ToggleWindowStyle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int flag;
  if (!get_val_param<int >(flag,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ToggleWindowStyle(flag);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetExtraStyle(long int exStyle)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetExtraStyle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'exStyle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetExtraStyle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long exStyle_long;
  if (!get_val_param<long >(exStyle_long,_p,_n)) ClassHelpAndReturn;
  long int exStyle = exStyle_long;

  this->_objectptr->GetObj()->SetExtraStyle(exStyle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long int wxWindowBase::GetExtraStyle()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetExtraStyle::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetExtraStyle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   this->_objectptr->GetObj()->GetExtraStyle();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::MakeModal(bool modal = true)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_MakeModal::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'modal' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_MakeModal::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int modal_int = ((true==true)?1:0);;
  if (!get_val_param<int >(modal_int,_p,_n)) ClassHelpAndReturn;
  bool modal = (bool) (modal_int>0.5);

  this->_objectptr->GetObj()->MakeModal(modal);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetThemeEnabled(bool enableTheme)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetThemeEnabled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'enableTheme'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetThemeEnabled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int enableTheme_int;
  if (!get_val_param<int >(enableTheme_int,_p,_n)) ClassHelpAndReturn;
  bool enableTheme = (bool) (enableTheme_int>0.5);

  this->_objectptr->GetObj()->SetThemeEnabled(enableTheme);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::GetThemeEnabled()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetThemeEnabled::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetThemeEnabled::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetThemeEnabled();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetFocusFromKbd()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetFocusFromKbd::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetFocusFromKbd::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFocusFromKbd();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxWindowBase::FindFocus()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_FindFocus::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_FindFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->FindFocus();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxWindowBase::DoFindFocus()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_DoFindFocus::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_DoFindFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->DoFindFocus();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::AcceptsFocus()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_AcceptsFocus::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_AcceptsFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->AcceptsFocus();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::AcceptsFocusFromKeyboard()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_AcceptsFocusFromKeyboard::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_AcceptsFocusFromKeyboard::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->AcceptsFocusFromKeyboard();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::MoveBeforeInTabOrder(wxWindow * win)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_MoveBeforeInTabOrder::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'win'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_MoveBeforeInTabOrder::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > win_smtptr;
  if (!get_val_smtptr_param<wxWindow >(win_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* win = win_smtptr.get();

  this->_objectptr->GetObj()->MoveBeforeInTabOrder(win);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::MoveAfterInTabOrder(wxWindow * win)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_MoveAfterInTabOrder::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'win'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_MoveAfterInTabOrder::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > win_smtptr;
  if (!get_val_smtptr_param<wxWindow >(win_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* win = win_smtptr.get();

  this->_objectptr->GetObj()->MoveAfterInTabOrder(win);
  return BasicVariable::ptr();
}
/* The following types are missing: wxWindowList

//---------------------------------------------------
//  Wrapping of wxWindowList const & wxWindowBase::GetChildren()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetChildren_1::SetParametersComments()
{
  return_comments="returning a variable of type wxWindowList";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetChildren_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxWindowList const & res =   this->_objectptr->GetObj()->GetChildren();
  return AMILabType<wxWindowList >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::GetChildren(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetChildren::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetChildren::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxWindowList

//---------------------------------------------------
//  Wrapping of wxWindowList & wxWindowBase::GetChildren()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetChildren_2::SetParametersComments()
{
  return_comments="returning a variable of type wxWindowList";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetChildren_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxWindowList & res =   this->_objectptr->GetObj()->GetChildren();
  return AMILabType<wxWindowList >::CreateVar(res);
}
*/
/* The following types are missing: wxWindowList

//---------------------------------------------------
//  Wrapping of wxWindowList const & wxWindowBase::GetWindowChildren()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetWindowChildren::SetParametersComments()
{
  return_comments="returning a variable of type wxWindowList";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetWindowChildren::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindowList const & res =   this->_objectptr->GetObj()->GetWindowChildren();
  return AMILabType<wxWindowList >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxWindow * wxWindowBase::GetPrevSibling()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetPrevSibling::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetPrevSibling::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetPrevSibling();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxWindowBase::GetNextSibling()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetNextSibling::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetNextSibling::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetNextSibling();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxWindowBase::GetParent()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetParent::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetParent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetParent();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxWindowBase::GetGrandParent()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetGrandParent::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetGrandParent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetGrandParent();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::IsTopLevel()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_IsTopLevel::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_IsTopLevel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsTopLevel();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetParent(wxWindowBase * parent)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetParent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'parent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetParent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowBase > parent_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(parent_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindowBase* parent = parent_smtptr.get();

  this->_objectptr->GetObj()->SetParent(parent);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::Reparent(wxWindowBase * newParent)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Reparent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'newParent'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Reparent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowBase > newParent_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(newParent_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindowBase* newParent = newParent_smtptr.get();

  bool res =   this->_objectptr->GetObj()->Reparent(newParent);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::AddChild(wxWindowBase * child)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_AddChild::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'child'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_AddChild::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowBase > child_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(child_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindowBase* child = child_smtptr.get();

  this->_objectptr->GetObj()->AddChild(child);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::RemoveChild(wxWindowBase * child)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_RemoveChild::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'child'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_RemoveChild::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowBase > child_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(child_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindowBase* child = child_smtptr.get();

  this->_objectptr->GetObj()->RemoveChild(child);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxWindowBase::FindWindow(long int winid)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_FindWindow_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'winid'")
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_FindWindow_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long winid_long;
  if (!get_val_param<long >(winid_long,_p,_n)) ClassReturnEmptyVar;
  long int winid = winid_long;

  wxWindow * res =   this->_objectptr->GetObj()->FindWindow(winid);
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::FindWindow(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_FindWindow::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_FindWindow::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_FindWindow_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_FindWindow_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxWindowBase::FindWindow(wxString const & name)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_FindWindow_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_FindWindow_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  wxWindow * res =   this->_objectptr->GetObj()->FindWindow(name);
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxWindowBase::FindWindowById(long int winid, wxWindow const * parent = 0l)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_FindWindowById::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'winid'")
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent' (def:0l)")
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_FindWindowById::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long winid_long;
  if (!get_val_param<long >(winid_long,_p,_n)) ClassHelpAndReturn;
  long int winid = winid_long;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();

  wxWindow * res =   this->_objectptr->GetObj()->FindWindowById(winid, parent);
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxWindowBase::FindWindowByName(wxString const & name, wxWindow const * parent = 0l)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_FindWindowByName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent' (def:0l)")
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_FindWindowByName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();

  wxWindow * res =   this->_objectptr->GetObj()->FindWindowByName(name, parent);
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxWindowBase::FindWindowByLabel(wxString const & label, wxWindow const * parent = 0l)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_FindWindowByLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent' (def:0l)")
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_FindWindowByLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & label = *label_smtptr;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();

  wxWindow * res =   this->_objectptr->GetObj()->FindWindowByLabel(label, parent);
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}
/* The following types are missing: wxEvtHandler

//---------------------------------------------------
//  Wrapping of wxEvtHandler * wxWindowBase::GetEventHandler()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetEventHandler::SetParametersComments()
{
  return_comments="returning a variable of type wxEvtHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetEventHandler::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxEvtHandler * res =   this->_objectptr->GetObj()->GetEventHandler();
  return AMILabType<wxEvtHandler >::CreateVar(res);
}
*/
/* The following types are missing: wxEvtHandler

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetEventHandler(wxEvtHandler * handler)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetEventHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEvtHandler, "parameter named 'handler'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetEventHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxEvtHandler > handler_smtptr;
  if (!get_val_smtptr_param<wxEvtHandler >(handler_smtptr,_p,_n)) ClassHelpAndReturn;
  wxEvtHandler* handler = handler_smtptr.get();

  this->_objectptr->GetObj()->SetEventHandler(handler);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxEvtHandler

//---------------------------------------------------
//  Wrapping of void wxWindowBase::PushEventHandler(wxEvtHandler * handler)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_PushEventHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEvtHandler, "parameter named 'handler'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_PushEventHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxEvtHandler > handler_smtptr;
  if (!get_val_smtptr_param<wxEvtHandler >(handler_smtptr,_p,_n)) ClassHelpAndReturn;
  wxEvtHandler* handler = handler_smtptr.get();

  this->_objectptr->GetObj()->PushEventHandler(handler);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxEvtHandler

//---------------------------------------------------
//  Wrapping of wxEvtHandler * wxWindowBase::PopEventHandler(bool deleteHandler = false)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_PopEventHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deleteHandler' (def:false)")
  return_comments="returning a variable of type wxEvtHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_PopEventHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int deleteHandler_int = ((false==true)?1:0);;
  if (!get_val_param<int >(deleteHandler_int,_p,_n)) ClassHelpAndReturn;
  bool deleteHandler = (bool) (deleteHandler_int>0.5);

  wxEvtHandler * res =   this->_objectptr->GetObj()->PopEventHandler(deleteHandler);
  return AMILabType<wxEvtHandler >::CreateVar(res);
}
*/
/* The following types are missing: wxEvtHandler

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::RemoveEventHandler(wxEvtHandler * handler)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_RemoveEventHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEvtHandler, "parameter named 'handler'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_RemoveEventHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxEvtHandler > handler_smtptr;
  if (!get_val_smtptr_param<wxEvtHandler >(handler_smtptr,_p,_n)) ClassHelpAndReturn;
  wxEvtHandler* handler = handler_smtptr.get();

  bool res =   this->_objectptr->GetObj()->RemoveEventHandler(handler);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/* The following types are missing: wxValidator

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetValidator(wxValidator const & validator)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetValidator::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxValidator, "parameter named 'validator'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetValidator::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxValidator > validator_smtptr;
  if (!get_val_smtptr_param<wxValidator >(validator_smtptr,_p,_n)) ClassHelpAndReturn;
  wxValidator const & validator = *validator_smtptr;

  this->_objectptr->GetObj()->SetValidator(validator);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxValidator

//---------------------------------------------------
//  Wrapping of wxValidator * wxWindowBase::GetValidator()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetValidator::SetParametersComments()
{
  return_comments="returning a variable of type wxValidator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetValidator::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxValidator * res =   this->_objectptr->GetObj()->GetValidator();
  return AMILabType<wxValidator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::Validate()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Validate::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Validate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Validate();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::TransferDataToWindow()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_TransferDataToWindow::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_TransferDataToWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->TransferDataToWindow();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::TransferDataFromWindow()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_TransferDataFromWindow::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_TransferDataFromWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->TransferDataFromWindow();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::InitDialog()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_InitDialog::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_InitDialog::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InitDialog();
  return BasicVariable::ptr();
}
/* The following types are missing: wxAcceleratorTable

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetAcceleratorTable(wxAcceleratorTable const & accel)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetAcceleratorTable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAcceleratorTable, "parameter named 'accel'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetAcceleratorTable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAcceleratorTable > accel_smtptr;
  if (!get_val_smtptr_param<wxAcceleratorTable >(accel_smtptr,_p,_n)) ClassHelpAndReturn;
  wxAcceleratorTable const & accel = *accel_smtptr;

  this->_objectptr->GetObj()->SetAcceleratorTable(accel);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxAcceleratorTable

//---------------------------------------------------
//  Wrapping of wxAcceleratorTable * wxWindowBase::GetAcceleratorTable()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetAcceleratorTable::SetParametersComments()
{
  return_comments="returning a variable of type wxAcceleratorTable";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetAcceleratorTable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAcceleratorTable * res =   this->_objectptr->GetObj()->GetAcceleratorTable();
  return AMILabType<wxAcceleratorTable >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxPoint wxWindowBase::ConvertPixelsToDialog(wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ConvertPixelsToDialog_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ConvertPixelsToDialog_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  wxPoint res =   this->_objectptr->GetObj()->ConvertPixelsToDialog(pt);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxWindowBase::ConvertDialogToPixels(wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ConvertDialogToPixels_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ConvertDialogToPixels_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  wxPoint res =   this->_objectptr->GetObj()->ConvertDialogToPixels(pt);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::ConvertPixelsToDialog(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ConvertPixelsToDialog::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ConvertPixelsToDialog::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_ConvertPixelsToDialog_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_ConvertPixelsToDialog_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxSize wxWindowBase::ConvertPixelsToDialog(wxSize const & sz)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ConvertPixelsToDialog_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ConvertPixelsToDialog_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > sz_smtptr;
  if (!get_val_smtptr_param<wxSize >(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSize const & sz = *sz_smtptr;

  wxSize res =   this->_objectptr->GetObj()->ConvertPixelsToDialog(sz);
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::ConvertDialogToPixels(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ConvertDialogToPixels::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ConvertDialogToPixels::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_ConvertDialogToPixels_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_ConvertDialogToPixels_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxSize wxWindowBase::ConvertDialogToPixels(wxSize const & sz)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ConvertDialogToPixels_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ConvertDialogToPixels_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > sz_smtptr;
  if (!get_val_smtptr_param<wxSize >(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSize const & sz = *sz_smtptr;

  wxSize res =   this->_objectptr->GetObj()->ConvertDialogToPixels(sz);
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::CaptureMouse()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_CaptureMouse::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_CaptureMouse::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->CaptureMouse();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::ReleaseMouse()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ReleaseMouse::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ReleaseMouse::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ReleaseMouse();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxWindowBase::GetCapture()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetCapture::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetCapture::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetCapture();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::HasCapture()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_HasCapture::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_HasCapture::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasCapture();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::RefreshRect(wxRect const & rect, bool eraseBackground = true)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_RefreshRect::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'eraseBackground' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_RefreshRect::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n)) ClassHelpAndReturn;
  wxRect const & rect = *rect_smtptr;

  int eraseBackground_int = ((true==true)?1:0);;
  if (!get_val_param<int >(eraseBackground_int,_p,_n)) ClassHelpAndReturn;
  bool eraseBackground = (bool) (eraseBackground_int>0.5);

  this->_objectptr->GetObj()->RefreshRect(rect, eraseBackground);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::Update()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Update::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Update::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Update();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::ClearBackground()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ClearBackground::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ClearBackground::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ClearBackground();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::Freeze()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Freeze::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Freeze::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Freeze();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::Thaw()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Thaw::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Thaw::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Thaw();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::IsFrozen()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_IsFrozen::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_IsFrozen::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsFrozen();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
/* The following types are missing: wxDC

//---------------------------------------------------
//  Wrapping of void wxWindowBase::PrepareDC(wxDC & param0)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_PrepareDC::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDC, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_PrepareDC::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDC > param0_smtptr;
  if (!get_val_smtptr_param<wxDC >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  wxDC & param0 = *param0_smtptr;

  this->_objectptr->GetObj()->PrepareDC(param0);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::IsDoubleBuffered()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_IsDoubleBuffered::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_IsDoubleBuffered::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsDoubleBuffered();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
/* The following types are missing: wxRegion

//---------------------------------------------------
//  Wrapping of wxRegion const & wxWindowBase::GetUpdateRegion()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetUpdateRegion_1::SetParametersComments()
{
  return_comments="returning a variable of type wxRegion";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetUpdateRegion_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxRegion const & res =   this->_objectptr->GetObj()->GetUpdateRegion();
  return AMILabType<wxRegion >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::GetUpdateRegion(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetUpdateRegion::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetUpdateRegion::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxRegion

//---------------------------------------------------
//  Wrapping of wxRegion & wxWindowBase::GetUpdateRegion()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetUpdateRegion_2::SetParametersComments()
{
  return_comments="returning a variable of type wxRegion";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetUpdateRegion_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxRegion & res =   this->_objectptr->GetObj()->GetUpdateRegion();
  return AMILabType<wxRegion >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxRect wxWindowBase::GetUpdateClientRect()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetUpdateClientRect::SetParametersComments()
{
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetUpdateClientRect::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxRect res =   this->_objectptr->GetObj()->GetUpdateClientRect();
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::DoIsExposed(int x, int y)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_DoIsExposed_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_DoIsExposed_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->DoIsExposed(x, y);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::DoIsExposed(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_DoIsExposed::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_DoIsExposed::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_DoIsExposed_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_DoIsExposed_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::DoIsExposed(int x, int y, int w, int h)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_DoIsExposed_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_DoIsExposed_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassReturnEmptyVar;

  int w;
  if (!get_val_param<int >(w,_p,_n)) ClassReturnEmptyVar;

  int h;
  if (!get_val_param<int >(h,_p,_n)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->DoIsExposed(x, y, w, h);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::IsExposed(int x, int y)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_IsExposed_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_IsExposed_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->IsExposed(x, y);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::IsExposed(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_IsExposed::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_IsExposed::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_IsExposed_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_IsExposed_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_IsExposed_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_IsExposed_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::IsExposed(int x, int y, int w, int h)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_IsExposed_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_IsExposed_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassReturnEmptyVar;

  int w;
  if (!get_val_param<int >(w,_p,_n)) ClassReturnEmptyVar;

  int h;
  if (!get_val_param<int >(h,_p,_n)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->IsExposed(x, y, w, h);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::IsExposed(wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_IsExposed_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_IsExposed_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  bool res =   this->_objectptr->GetObj()->IsExposed(pt);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::IsExposed(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_IsExposed_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_IsExposed_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  bool res =   this->_objectptr->GetObj()->IsExposed(rect);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxVisualAttributes wxWindowBase::GetDefaultAttributes()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetDefaultAttributes::SetParametersComments()
{
  return_comments="returning a variable of type wxVisualAttributes";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetDefaultAttributes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxVisualAttributes res =   this->_objectptr->GetObj()->GetDefaultAttributes();
  return AMILabType<wxVisualAttributes >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxVisualAttributes wxWindowBase::GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetClassDefaultAttributes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'variant' (def:wxWINDOW_VARIANT_NORMAL)")
  return_comments="returning a variable of type wxVisualAttributes";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetClassDefaultAttributes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int variant_int = (int) wxWINDOW_VARIANT_NORMAL;;
  if (!get_val_param<int >(variant_int,_p,_n)) ClassHelpAndReturn;
  wxWindowVariant variant = (wxWindowVariant) variant_int;

  wxVisualAttributes res =   this->_objectptr->GetObj()->GetClassDefaultAttributes(variant);
  return AMILabType<wxVisualAttributes >::CreateVar(res);
}
/* The following types are missing: wxColour

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::SetBackgroundColour(wxColour const & colour)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetBackgroundColour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'colour'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetBackgroundColour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > colour_smtptr;
  if (!get_val_smtptr_param<wxColour >(colour_smtptr,_p,_n)) ClassHelpAndReturn;
  wxColour const & colour = *colour_smtptr;

  bool res =   this->_objectptr->GetObj()->SetBackgroundColour(colour);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/* The following types are missing: wxColour

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetOwnBackgroundColour(wxColour const & colour)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetOwnBackgroundColour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'colour'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetOwnBackgroundColour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > colour_smtptr;
  if (!get_val_smtptr_param<wxColour >(colour_smtptr,_p,_n)) ClassHelpAndReturn;
  wxColour const & colour = *colour_smtptr;

  this->_objectptr->GetObj()->SetOwnBackgroundColour(colour);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxColour

//---------------------------------------------------
//  Wrapping of wxColour wxWindowBase::GetBackgroundColour()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetBackgroundColour::SetParametersComments()
{
  return_comments="returning a variable of type wxColour";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetBackgroundColour::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxColour res =   this->_objectptr->GetObj()->GetBackgroundColour();
  return AMILabType<wxColour >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::InheritsBackgroundColour()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_InheritsBackgroundColour::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_InheritsBackgroundColour::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->InheritsBackgroundColour();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::UseBgCol()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_UseBgCol::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_UseBgCol::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->UseBgCol();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
/* The following types are missing: wxColour

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::SetForegroundColour(wxColour const & colour)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetForegroundColour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'colour'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetForegroundColour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > colour_smtptr;
  if (!get_val_smtptr_param<wxColour >(colour_smtptr,_p,_n)) ClassHelpAndReturn;
  wxColour const & colour = *colour_smtptr;

  bool res =   this->_objectptr->GetObj()->SetForegroundColour(colour);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/* The following types are missing: wxColour

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetOwnForegroundColour(wxColour const & colour)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetOwnForegroundColour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'colour'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetOwnForegroundColour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > colour_smtptr;
  if (!get_val_smtptr_param<wxColour >(colour_smtptr,_p,_n)) ClassHelpAndReturn;
  wxColour const & colour = *colour_smtptr;

  this->_objectptr->GetObj()->SetOwnForegroundColour(colour);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxColour

//---------------------------------------------------
//  Wrapping of wxColour wxWindowBase::GetForegroundColour()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetForegroundColour::SetParametersComments()
{
  return_comments="returning a variable of type wxColour";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetForegroundColour::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxColour res =   this->_objectptr->GetObj()->GetForegroundColour();
  return AMILabType<wxColour >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::SetBackgroundStyle(wxBackgroundStyle style)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetBackgroundStyle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'style'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetBackgroundStyle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int style_int;
  if (!get_val_param<int >(style_int,_p,_n)) ClassHelpAndReturn;
  wxBackgroundStyle style = (wxBackgroundStyle) style_int;

  bool res =   this->_objectptr->GetObj()->SetBackgroundStyle(style);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxBackgroundStyle wxWindowBase::GetBackgroundStyle()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetBackgroundStyle::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetBackgroundStyle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBackgroundStyle res =   this->_objectptr->GetObj()->GetBackgroundStyle();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::HasTransparentBackground()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_HasTransparentBackground::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_HasTransparentBackground::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasTransparentBackground();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetOwnFont(wxFont const & font)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetOwnFont::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'font'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetOwnFont::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFont > font_smtptr;
  if (!get_val_smtptr_param<wxFont >(font_smtptr,_p,_n)) ClassHelpAndReturn;
  wxFont const & font = *font_smtptr;

  this->_objectptr->GetObj()->SetOwnFont(font);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxFont wxWindowBase::GetFont()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetFont::SetParametersComments()
{
  return_comments="returning a variable of type wxFont";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetFont::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxFont res =   this->_objectptr->GetObj()->GetFont();
  return AMILabType<wxFont >::CreateVar(res);
}
/* The following types are missing: wxCursor

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::SetCursor(wxCursor const & cursor)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetCursor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCursor, "parameter named 'cursor'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetCursor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxCursor > cursor_smtptr;
  if (!get_val_smtptr_param<wxCursor >(cursor_smtptr,_p,_n)) ClassHelpAndReturn;
  wxCursor const & cursor = *cursor_smtptr;

  bool res =   this->_objectptr->GetObj()->SetCursor(cursor);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/* The following types are missing: wxCursor

//---------------------------------------------------
//  Wrapping of wxCursor const & wxWindowBase::GetCursor()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetCursor::SetParametersComments()
{
  return_comments="returning a variable of type wxCursor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetCursor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCursor const & res =   this->_objectptr->GetObj()->GetCursor();
  return AMILabType<wxCursor >::CreateVar(res);
}
*/
/* The following types are missing: wxCaret

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetCaret(wxCaret * caret)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetCaret::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCaret, "parameter named 'caret'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetCaret::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxCaret > caret_smtptr;
  if (!get_val_smtptr_param<wxCaret >(caret_smtptr,_p,_n)) ClassHelpAndReturn;
  wxCaret* caret = caret_smtptr.get();

  this->_objectptr->GetObj()->SetCaret(caret);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxCaret

//---------------------------------------------------
//  Wrapping of wxCaret * wxWindowBase::GetCaret()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetCaret::SetParametersComments()
{
  return_comments="returning a variable of type wxCaret";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetCaret::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCaret * res =   this->_objectptr->GetObj()->GetCaret();
  return AMILabType<wxCaret >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxWindowBase::ClientToScreen(int * x, int * y)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ClientToScreen_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ClientToScreen_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > x_smtptr;
  if (!get_val_smtptr_param<int >(x_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* x = x_smtptr.get();

  boost::shared_ptr<int > y_smtptr;
  if (!get_val_smtptr_param<int >(y_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* y = y_smtptr.get();

  this->_objectptr->GetObj()->ClientToScreen(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::ScreenToClient(int * x, int * y)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ScreenToClient_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ScreenToClient_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > x_smtptr;
  if (!get_val_smtptr_param<int >(x_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* x = x_smtptr.get();

  boost::shared_ptr<int > y_smtptr;
  if (!get_val_smtptr_param<int >(y_smtptr,_p,_n)) ClassReturnEmptyVar;
  int* y = y_smtptr.get();

  this->_objectptr->GetObj()->ScreenToClient(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::ClientToScreen(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ClientToScreen::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ClientToScreen::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_ClientToScreen_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_ClientToScreen_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxPoint wxWindowBase::ClientToScreen(wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ClientToScreen_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ClientToScreen_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  wxPoint res =   this->_objectptr->GetObj()->ClientToScreen(pt);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::ScreenToClient(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ScreenToClient::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ScreenToClient::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_ScreenToClient_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_ScreenToClient_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxPoint wxWindowBase::ScreenToClient(wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ScreenToClient_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ScreenToClient_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  wxPoint res =   this->_objectptr->GetObj()->ScreenToClient(pt);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxHitTest wxWindowBase::HitTest(wxCoord x, wxCoord y)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_HitTest_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_HitTest_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassReturnEmptyVar;

  wxHitTest res =   this->_objectptr->GetObj()->HitTest(x, y);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::HitTest(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_HitTest::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_HitTest::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_HitTest_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_HitTest_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxHitTest wxWindowBase::HitTest(wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_HitTest_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_HitTest_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  wxHitTest res =   this->_objectptr->GetObj()->HitTest(pt);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxBorder wxWindowBase::GetBorder(long int flags)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetBorder_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flags'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetBorder_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long flags_long;
  if (!get_val_param<long >(flags_long,_p,_n)) ClassReturnEmptyVar;
  long int flags = flags_long;

  wxBorder res =   this->_objectptr->GetObj()->GetBorder(flags);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::GetBorder(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetBorder::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetBorder::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_GetBorder_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowBase::wrap_GetBorder_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxBorder wxWindowBase::GetBorder()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetBorder_2::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetBorder_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBorder res =   this->_objectptr->GetObj()->GetBorder();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::UpdateWindowUI(long int flags = wxUPDATE_UI_NONE)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_UpdateWindowUI::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flags' (def:wxUPDATE_UI_NONE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_UpdateWindowUI::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long flags_long = wxUPDATE_UI_NONE;;
  if (!get_val_param<long >(flags_long,_p,_n)) ClassHelpAndReturn;
  long int flags = flags_long;

  this->_objectptr->GetObj()->UpdateWindowUI(flags);
  return BasicVariable::ptr();
}
/* The following types are missing: wxUpdateUIEvent

//---------------------------------------------------
//  Wrapping of void wxWindowBase::DoUpdateWindowUI(wxUpdateUIEvent & event)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_DoUpdateWindowUI::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUpdateUIEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_DoUpdateWindowUI::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxUpdateUIEvent > event_smtptr;
  if (!get_val_smtptr_param<wxUpdateUIEvent >(event_smtptr,_p,_n)) ClassHelpAndReturn;
  wxUpdateUIEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->DoUpdateWindowUI(event);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxMenu

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::PopupMenu(wxMenu * menu, wxPoint const & pos = wxDefaultPosition)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_PopupMenu_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menu'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_PopupMenu_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMenu > menu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(menu_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMenu* menu = menu_smtptr.get();

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pos = (pos_smtptr.get()?
    (wxPoint const &) (*pos_smtptr):
    (wxPoint const &) wxDefaultPosition);

  bool res =   this->_objectptr->GetObj()->PopupMenu(menu, pos);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::PopupMenu(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_PopupMenu::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_PopupMenu::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxMenu

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::PopupMenu(wxMenu * menu, int x, int y)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_PopupMenu_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menu'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_PopupMenu_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMenu > menu_smtptr;
  if (!get_val_smtptr_param<wxMenu >(menu_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMenu* menu = menu_smtptr.get();

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->PopupMenu(menu, x, y);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::HasMultiplePages()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_HasMultiplePages::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_HasMultiplePages::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasMultiplePages();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::HasScrollbar(int orient)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_HasScrollbar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orient'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_HasScrollbar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int orient;
  if (!get_val_param<int >(orient,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasScrollbar(orient);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::ScrollLines(int param0)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ScrollLines::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ScrollLines::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ScrollLines(param0);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::ScrollPages(int param0)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ScrollPages::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ScrollPages::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ScrollPages(param0);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::LineUp()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_LineUp::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_LineUp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->LineUp();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::LineDown()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_LineDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_LineDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->LineDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::PageUp()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_PageUp::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_PageUp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->PageUp();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::PageDown()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_PageDown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_PageDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->PageDown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetHelpText(wxString const & text)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetHelpText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetHelpText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  this->_objectptr->GetObj()->SetHelpText(text);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetHelpTextForId(wxString const & text)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetHelpTextForId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetHelpTextForId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  this->_objectptr->GetObj()->SetHelpTextForId(text);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxWindowBase::GetHelpText()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetHelpText::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetHelpText::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetHelpText();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetToolTip(wxString const & tip)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetToolTip_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'tip'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetToolTip_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > tip_smtptr;
  if (!get_val_smtptr_param<wxString >(tip_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & tip = *tip_smtptr;

  this->_objectptr->GetObj()->SetToolTip(tip);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowBase::SetToolTip(...)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetToolTip::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetToolTip::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowBase::wrap_SetToolTip_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxToolTip

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetToolTip(wxToolTip * tip)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetToolTip_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxToolTip, "parameter named 'tip'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetToolTip_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxToolTip > tip_smtptr;
  if (!get_val_smtptr_param<wxToolTip >(tip_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxToolTip* tip = tip_smtptr.get();

  this->_objectptr->GetObj()->SetToolTip(tip);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxWindowBase::UnsetToolTip()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_UnsetToolTip::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_UnsetToolTip::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UnsetToolTip();
  return BasicVariable::ptr();
}
/* The following types are missing: wxToolTip

//---------------------------------------------------
//  Wrapping of wxToolTip * wxWindowBase::GetToolTip()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetToolTip::SetParametersComments()
{
  return_comments="returning a variable of type wxToolTip";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetToolTip::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxToolTip * res =   this->_objectptr->GetObj()->GetToolTip();
  return AMILabType<wxToolTip >::CreateVar(res);
}
*/
/* The following types are missing: wxDropTarget

//---------------------------------------------------
//  Wrapping of wxDropTarget * wxWindowBase::GetDropTarget()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetDropTarget::SetParametersComments()
{
  return_comments="returning a variable of type wxDropTarget";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetDropTarget::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDropTarget * res =   this->_objectptr->GetObj()->GetDropTarget();
  return AMILabType<wxDropTarget >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxWindowBase::DragAcceptFiles(bool accept)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_DragAcceptFiles::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'accept'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_DragAcceptFiles::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int accept_int;
  if (!get_val_param<int >(accept_int,_p,_n)) ClassHelpAndReturn;
  bool accept = (bool) (accept_int>0.5);

  this->_objectptr->GetObj()->DragAcceptFiles(accept);
  return BasicVariable::ptr();
}
/* The following types are missing: wxLayoutConstraints

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetConstraints(wxLayoutConstraints * constraints)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetConstraints::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLayoutConstraints, "parameter named 'constraints'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetConstraints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxLayoutConstraints > constraints_smtptr;
  if (!get_val_smtptr_param<wxLayoutConstraints >(constraints_smtptr,_p,_n)) ClassHelpAndReturn;
  wxLayoutConstraints* constraints = constraints_smtptr.get();

  this->_objectptr->GetObj()->SetConstraints(constraints);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxLayoutConstraints

//---------------------------------------------------
//  Wrapping of wxLayoutConstraints * wxWindowBase::GetConstraints()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetConstraints::SetParametersComments()
{
  return_comments="returning a variable of type wxLayoutConstraints";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetConstraints::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxLayoutConstraints * res =   this->_objectptr->GetObj()->GetConstraints();
  return AMILabType<wxLayoutConstraints >::CreateVar(res);
}
*/
/* The following types are missing: wxLayoutConstraints

//---------------------------------------------------
//  Wrapping of void wxWindowBase::UnsetConstraints(wxLayoutConstraints * c)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_UnsetConstraints::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLayoutConstraints, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_UnsetConstraints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxLayoutConstraints > c_smtptr;
  if (!get_val_smtptr_param<wxLayoutConstraints >(c_smtptr,_p,_n)) ClassHelpAndReturn;
  wxLayoutConstraints* c = c_smtptr.get();

  this->_objectptr->GetObj()->UnsetConstraints(c);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxWindowList

//---------------------------------------------------
//  Wrapping of wxWindowList * wxWindowBase::GetConstraintsInvolvedIn()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetConstraintsInvolvedIn::SetParametersComments()
{
  return_comments="returning a variable of type wxWindowList";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetConstraintsInvolvedIn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindowList * res =   this->_objectptr->GetObj()->GetConstraintsInvolvedIn();
  return AMILabType<wxWindowList >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxWindowBase::AddConstraintReference(wxWindowBase * otherWin)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_AddConstraintReference::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'otherWin'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_AddConstraintReference::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowBase > otherWin_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(otherWin_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindowBase* otherWin = otherWin_smtptr.get();

  this->_objectptr->GetObj()->AddConstraintReference(otherWin);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::RemoveConstraintReference(wxWindowBase * otherWin)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_RemoveConstraintReference::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'otherWin'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_RemoveConstraintReference::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowBase > otherWin_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(otherWin_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindowBase* otherWin = otherWin_smtptr.get();

  this->_objectptr->GetObj()->RemoveConstraintReference(otherWin);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::DeleteRelatedConstraints()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_DeleteRelatedConstraints::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_DeleteRelatedConstraints::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DeleteRelatedConstraints();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::ResetConstraints()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ResetConstraints::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ResetConstraints::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ResetConstraints();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetConstraintSizes(bool recurse = true)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetConstraintSizes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'recurse' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetConstraintSizes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int recurse_int = ((true==true)?1:0);;
  if (!get_val_param<int >(recurse_int,_p,_n)) ClassHelpAndReturn;
  bool recurse = (bool) (recurse_int>0.5);

  this->_objectptr->GetObj()->SetConstraintSizes(recurse);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::LayoutPhase1(int * noChanges)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_LayoutPhase1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'noChanges'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_LayoutPhase1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > noChanges_smtptr;
  if (!get_val_smtptr_param<int >(noChanges_smtptr,_p,_n)) ClassHelpAndReturn;
  int* noChanges = noChanges_smtptr.get();

  bool res =   this->_objectptr->GetObj()->LayoutPhase1(noChanges);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::LayoutPhase2(int * noChanges)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_LayoutPhase2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'noChanges'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_LayoutPhase2::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > noChanges_smtptr;
  if (!get_val_smtptr_param<int >(noChanges_smtptr,_p,_n)) ClassHelpAndReturn;
  int* noChanges = noChanges_smtptr.get();

  bool res =   this->_objectptr->GetObj()->LayoutPhase2(noChanges);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::DoPhase(int phase)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_DoPhase::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'phase'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_DoPhase::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int phase;
  if (!get_val_param<int >(phase,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->DoPhase(phase);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetSizeConstraint(int x, int y, int w, int h)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetSizeConstraint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetSizeConstraint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassHelpAndReturn;

  int w;
  if (!get_val_param<int >(w,_p,_n)) ClassHelpAndReturn;

  int h;
  if (!get_val_param<int >(h,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetSizeConstraint(x, y, w, h);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::MoveConstraint(int x, int y)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_MoveConstraint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_MoveConstraint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->MoveConstraint(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::GetSizeConstraint(int * w, int * h)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetSizeConstraint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetSizeConstraint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > w_smtptr;
  if (!get_val_smtptr_param<int >(w_smtptr,_p,_n)) ClassHelpAndReturn;
  int* w = w_smtptr.get();

  boost::shared_ptr<int > h_smtptr;
  if (!get_val_smtptr_param<int >(h_smtptr,_p,_n)) ClassHelpAndReturn;
  int* h = h_smtptr.get();

  this->_objectptr->GetObj()->GetSizeConstraint(w, h);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::GetClientSizeConstraint(int * w, int * h)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetClientSizeConstraint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetClientSizeConstraint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > w_smtptr;
  if (!get_val_smtptr_param<int >(w_smtptr,_p,_n)) ClassHelpAndReturn;
  int* w = w_smtptr.get();

  boost::shared_ptr<int > h_smtptr;
  if (!get_val_smtptr_param<int >(h_smtptr,_p,_n)) ClassHelpAndReturn;
  int* h = h_smtptr.get();

  this->_objectptr->GetObj()->GetClientSizeConstraint(w, h);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::GetPositionConstraint(int * x, int * y)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetPositionConstraint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetPositionConstraint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > x_smtptr;
  if (!get_val_smtptr_param<int >(x_smtptr,_p,_n)) ClassHelpAndReturn;
  int* x = x_smtptr.get();

  boost::shared_ptr<int > y_smtptr;
  if (!get_val_smtptr_param<int >(y_smtptr,_p,_n)) ClassHelpAndReturn;
  int* y = y_smtptr.get();

  this->_objectptr->GetObj()->GetPositionConstraint(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetAutoLayout(bool autoLayout)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetAutoLayout::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'autoLayout'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetAutoLayout::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int autoLayout_int;
  if (!get_val_param<int >(autoLayout_int,_p,_n)) ClassHelpAndReturn;
  bool autoLayout = (bool) (autoLayout_int>0.5);

  this->_objectptr->GetObj()->SetAutoLayout(autoLayout);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::GetAutoLayout()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetAutoLayout::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetAutoLayout::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetAutoLayout();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::Layout()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_Layout::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_Layout::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Layout();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetSizer(wxSizer * sizer, bool deleteOld = true)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetSizer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deleteOld' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetSizer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSizer* sizer = sizer_smtptr.get();

  int deleteOld_int = ((true==true)?1:0);;
  if (!get_val_param<int >(deleteOld_int,_p,_n)) ClassHelpAndReturn;
  bool deleteOld = (bool) (deleteOld_int>0.5);

  this->_objectptr->GetObj()->SetSizer(sizer, deleteOld);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetSizerAndFit(wxSizer * sizer, bool deleteOld = true)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetSizerAndFit::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'deleteOld' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetSizerAndFit::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSizer* sizer = sizer_smtptr.get();

  int deleteOld_int = ((true==true)?1:0);;
  if (!get_val_param<int >(deleteOld_int,_p,_n)) ClassHelpAndReturn;
  bool deleteOld = (bool) (deleteOld_int>0.5);

  this->_objectptr->GetObj()->SetSizerAndFit(sizer, deleteOld);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSizer * wxWindowBase::GetSizer()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetSizer::SetParametersComments()
{
  return_comments="returning a variable of type wxSizer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetSizer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizer * res =   this->_objectptr->GetObj()->GetSizer();
  BasicVariable::ptr res_var = WrapClass_wxSizer::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetContainingSizer(wxSizer * sizer)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetContainingSizer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetContainingSizer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSizer* sizer = sizer_smtptr.get();

  this->_objectptr->GetObj()->SetContainingSizer(sizer);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSizer * wxWindowBase::GetContainingSizer()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetContainingSizer::SetParametersComments()
{
  return_comments="returning a variable of type wxSizer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetContainingSizer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizer * res =   this->_objectptr->GetObj()->GetContainingSizer();
  BasicVariable::ptr res_var = WrapClass_wxSizer::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::SetTransparent(wxByte param0)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetTransparent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'param0'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetTransparent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  unsigned char param0;
  if (!get_val_param<unsigned char >(param0,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->SetTransparent(param0);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::CanSetTransparent()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_CanSetTransparent::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_CanSetTransparent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->CanSetTransparent();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
/* The following types are missing: wxSysColourChangedEvent

//---------------------------------------------------
//  Wrapping of void wxWindowBase::OnSysColourChanged(wxSysColourChangedEvent & event)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_OnSysColourChanged::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSysColourChangedEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_OnSysColourChanged::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSysColourChangedEvent > event_smtptr;
  if (!get_val_smtptr_param<wxSysColourChangedEvent >(event_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSysColourChangedEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnSysColourChanged(event);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxInitDialogEvent

//---------------------------------------------------
//  Wrapping of void wxWindowBase::OnInitDialog(wxInitDialogEvent & event)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_OnInitDialog::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxInitDialogEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_OnInitDialog::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxInitDialogEvent > event_smtptr;
  if (!get_val_smtptr_param<wxInitDialogEvent >(event_smtptr,_p,_n)) ClassHelpAndReturn;
  wxInitDialogEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnInitDialog(event);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxMouseEvent

//---------------------------------------------------
//  Wrapping of void wxWindowBase::OnMiddleClick(wxMouseEvent & event)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_OnMiddleClick::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_OnMiddleClick::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMouseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMouseEvent >(event_smtptr,_p,_n)) ClassHelpAndReturn;
  wxMouseEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnMiddleClick(event);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxHelpEvent

//---------------------------------------------------
//  Wrapping of void wxWindowBase::OnHelp(wxHelpEvent & event)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_OnHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHelpEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_OnHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHelpEvent > event_smtptr;
  if (!get_val_smtptr_param<wxHelpEvent >(event_smtptr,_p,_n)) ClassHelpAndReturn;
  wxHelpEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnHelp(event);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxWindowBase::OnInternalIdle()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_OnInternalIdle::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_OnInternalIdle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnInternalIdle();
  return BasicVariable::ptr();
}
/* The following types are missing: _GtkWidget

//---------------------------------------------------
//  Wrapping of void wxWindowBase::AssociateHandle(WXWidget param0)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_AssociateHandle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GtkWidget, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_AssociateHandle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  _GtkWidget param0;
  if (!get_val_param<_GtkWidget >(param0,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AssociateHandle(param0);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxWindowBase::DissociateHandle()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_DissociateHandle::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_DissociateHandle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DissociateHandle();
  return BasicVariable::ptr();
}
/* The following types are missing: wxPalette

//---------------------------------------------------
//  Wrapping of wxPalette wxWindowBase::GetPalette()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetPalette::SetParametersComments()
{
  return_comments="returning a variable of type wxPalette";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetPalette::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPalette res =   this->_objectptr->GetObj()->GetPalette();
  return AMILabType<wxPalette >::CreateVar(res);
}
*/
/* The following types are missing: wxPalette

//---------------------------------------------------
//  Wrapping of void wxWindowBase::SetPalette(wxPalette const & pal)
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_SetPalette::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPalette, "parameter named 'pal'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_SetPalette::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPalette > pal_smtptr;
  if (!get_val_smtptr_param<wxPalette >(pal_smtptr,_p,_n)) ClassHelpAndReturn;
  wxPalette const & pal = *pal_smtptr;

  this->_objectptr->GetObj()->SetPalette(pal);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::HasCustomPalette()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_HasCustomPalette::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_HasCustomPalette::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasCustomPalette();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxWindowBase::GetAncestorWithCustomPalette()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetAncestorWithCustomPalette::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetAncestorWithCustomPalette::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetAncestorWithCustomPalette();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxWindowBase::InheritAttributes()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_InheritAttributes::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_InheritAttributes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InheritAttributes();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxWindowBase::ShouldInheritColours()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_ShouldInheritColours::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_ShouldInheritColours::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ShouldInheritColours();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxWindowBase::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxWindowBase::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowBase::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

