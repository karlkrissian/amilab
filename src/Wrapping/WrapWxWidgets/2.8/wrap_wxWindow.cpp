/**
 * C++ Interface: wrap_wxWindow
 *
 * Description: wrapping wxWindow
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

#include "wrap_wxWindow.h"

// get all the required includes
// #include "..."
#include "stdlib.h"
#ifndef wxRegion_declared
  #define wxRegion_declared
  AMI_DECLARE_TYPE(wxRegion)
#endif
#ifndef wxWindow_declared
  #define wxWindow_declared
  AMI_DECLARE_TYPE(wxWindow)
#endif
#ifndef wxPoint_declared
  #define wxPoint_declared
  AMI_DECLARE_TYPE(wxPoint)
#endif
#ifndef wxSize_declared
  #define wxSize_declared
  AMI_DECLARE_TYPE(wxSize)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxWindowBase_declared
  #define wxWindowBase_declared
  AMI_DECLARE_TYPE(wxWindowBase)
#endif
#ifndef wxRect_declared
  #define wxRect_declared
  AMI_DECLARE_TYPE(wxRect)
#endif
#ifndef wxColour_declared
  #define wxColour_declared
  AMI_DECLARE_TYPE(wxColour)
#endif
#ifndef wxCursor_declared
  #define wxCursor_declared
  AMI_DECLARE_TYPE(wxCursor)
#endif
#ifndef wxFont_declared
  #define wxFont_declared
  AMI_DECLARE_TYPE(wxFont)
#endif
#ifndef wxIdleEvent_declared
  #define wxIdleEvent_declared
  AMI_DECLARE_TYPE(wxIdleEvent)
#endif
#ifndef wxEvent_declared
  #define wxEvent_declared
  AMI_DECLARE_TYPE(wxEvent)
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
BasicVariable::ptr WrapClass<wxWindow>::CreateVar( ParamList* p)
{
  WrapClass_wxWindow::wrap_wxWindow construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxWindow);
AMI_DEFINE_VARFROMSMTPTR(wxWindow);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxWindow>::CreateVar( wxWindow* val, bool nodeleter)
{ 
  boost::shared_ptr<wxWindow> obj_ptr(val,smartpointer_nodeleter<wxWindow>());
  return AMILabType<wxWindow>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxWindow
//
Variable<AMIObject>::ptr WrapClass_wxWindow::CreateVar( wxWindow* sp)
{
  boost::shared_ptr<wxWindow> di_ptr(
    sp,
    wxwindow_nodeleter<wxWindow>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxWindow>::CreateVar(
      new WrapClass_wxWindow(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxWindow::AddMethods(WrapClass<wxWindow>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Create( this_ptr);
  AddVar_SetLabel( this_ptr);
  AddVar_GetLabel( this_ptr);
  AddVar_Destroy( this_ptr);
  AddVar_Raise( this_ptr);
  AddVar_Lower( this_ptr);
  AddVar_Show( this_ptr);
  AddVar_Enable( this_ptr);
  AddVar_SetWindowStyleFlag( this_ptr);
  AddVar_IsRetained( this_ptr);
  AddVar_SetFocus( this_ptr);
  AddVar_AcceptsFocus( this_ptr);
  AddVar_Reparent( this_ptr);
  AddVar_WarpPointer( this_ptr);
  AddVar_Refresh( this_ptr);
  AddVar_Update( this_ptr);
  AddVar_ClearBackground( this_ptr);
  AddVar_SetBackgroundColour( this_ptr);
  AddVar_SetForegroundColour( this_ptr);
  AddVar_SetCursor( this_ptr);
  AddVar_SetFont( this_ptr);
  AddVar_SetBackgroundStyle( this_ptr);
  AddVar_GetCharHeight( this_ptr);
  AddVar_GetCharWidth( this_ptr);
  AddVar_GetTextExtent( this_ptr);
  AddVar_SetScrollbar( this_ptr);
  AddVar_SetScrollPos( this_ptr);
  AddVar_GetScrollPos( this_ptr);
  AddVar_GetScrollThumb( this_ptr);
  AddVar_GetScrollRange( this_ptr);
  AddVar_ScrollWindow( this_ptr);
  AddVar_ScrollLines( this_ptr);
  AddVar_ScrollPages( this_ptr);
/* The following types are missing: wxDropTarget
  AddVar_SetDropTarget( this_ptr);
*/
  AddVar_AddChild( this_ptr);
  AddVar_RemoveChild( this_ptr);
  AddVar_SetLayoutDirection( this_ptr);
  AddVar_GetLayoutDirection( this_ptr);
  AddVar_AdjustForLayoutDirection( this_ptr);
  AddVar_DoIsExposed_1( this_ptr);
  AddVar_DoIsExposed( this_ptr);
  AddVar_DoIsExposed_2( this_ptr);
  AddVar_SetDoubleBuffered( this_ptr);
  AddVar_IsDoubleBuffered( this_ptr);
/* The following types are missing: _GtkWidget
  AddVar_GetHandle( this_ptr);
*/
  AddVar_OnInternalIdle( this_ptr);
  AddVar_GtkUpdate( this_ptr);
  AddVar_OnIdle( this_ptr);
  AddVar_OnParentEnable( this_ptr);
  AddVar_PreCreation( this_ptr);
  AddVar_PostCreation( this_ptr);
  AddVar_DoAddChild( this_ptr);
  AddVar_GtkSendPaintEvents( this_ptr);
/* The following types are missing: _GtkWidget
  AddVar_GetConnectWidget( this_ptr);
*/
/* The following types are missing: _GtkWidget
  AddVar_ConnectWidget( this_ptr);
*/
/* The following types are missing: _GdkEventAny
  AddVar_GTKCallbackCommonPrologue( this_ptr);
*/
  AddVar_GTKProcessEvent( this_ptr);
/* The following types are missing: _PangoContext
  AddVar_GtkGetPangoDefaultContext( this_ptr);
*/
/* The following types are missing: _GtkTooltips
  AddVar_ApplyToolTip( this_ptr);
*/
  AddVar_GtkUpdateSize( this_ptr);
  AddVar_GtkShowOnIdle( this_ptr);
  AddVar_GtkShowFromOnIdle( this_ptr);
/* The following types are missing: _GtkWidget
  AddVar_FixUpMouseEvent( this_ptr);
*/
  AddVar_IsTransparentForMouse( this_ptr);
  AddVar_IsRadioButton( this_ptr);
/* The following types are missing: _GtkRange
  AddVar_GetScrollEventType( this_ptr);
*/
  AddVar_BlockScrollEvent( this_ptr);
  AddVar_UnblockScrollEvent( this_ptr);
/* The following types are missing: _GtkRange
  AddVar_ScrollDirFromRange( this_ptr);
*/
  AddVar_GetClassInfo( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());
  
  // Adding public member m_x
  boost::shared_ptr<int > var_m_x_ptr(&GetObj()->m_x, smartpointer_nodeleter<int >());
  if (var_m_x_ptr.get()) {
    BasicVariable::ptr var_m_x = AMILabType<int >::CreateVarFromSmtPtr(var_m_x_ptr);
    if (var_m_x.get()) {
      var_m_x->Rename("m_x");
      context->AddVar(var_m_x,context);
    }
  }
  
  // Adding public member m_y
  boost::shared_ptr<int > var_m_y_ptr(&GetObj()->m_y, smartpointer_nodeleter<int >());
  if (var_m_y_ptr.get()) {
    BasicVariable::ptr var_m_y = AMILabType<int >::CreateVarFromSmtPtr(var_m_y_ptr);
    if (var_m_y.get()) {
      var_m_y->Rename("m_y");
      context->AddVar(var_m_y,context);
    }
  }
  
  // Adding public member m_width
  boost::shared_ptr<int > var_m_width_ptr(&GetObj()->m_width, smartpointer_nodeleter<int >());
  if (var_m_width_ptr.get()) {
    BasicVariable::ptr var_m_width = AMILabType<int >::CreateVarFromSmtPtr(var_m_width_ptr);
    if (var_m_width.get()) {
      var_m_width->Rename("m_width");
      context->AddVar(var_m_width,context);
    }
  }
  
  // Adding public member m_height
  boost::shared_ptr<int > var_m_height_ptr(&GetObj()->m_height, smartpointer_nodeleter<int >());
  if (var_m_height_ptr.get()) {
    BasicVariable::ptr var_m_height = AMILabType<int >::CreateVarFromSmtPtr(var_m_height_ptr);
    if (var_m_height.get()) {
      var_m_height->Rename("m_height");
      context->AddVar(var_m_height,context);
    }
  }
  
  // Adding public member m_oldClientWidth
  boost::shared_ptr<int > var_m_oldClientWidth_ptr(&GetObj()->m_oldClientWidth, smartpointer_nodeleter<int >());
  if (var_m_oldClientWidth_ptr.get()) {
    BasicVariable::ptr var_m_oldClientWidth = AMILabType<int >::CreateVarFromSmtPtr(var_m_oldClientWidth_ptr);
    if (var_m_oldClientWidth.get()) {
      var_m_oldClientWidth->Rename("m_oldClientWidth");
      context->AddVar(var_m_oldClientWidth,context);
    }
  }
  
  // Adding public member m_oldClientHeight
  boost::shared_ptr<int > var_m_oldClientHeight_ptr(&GetObj()->m_oldClientHeight, smartpointer_nodeleter<int >());
  if (var_m_oldClientHeight_ptr.get()) {
    BasicVariable::ptr var_m_oldClientHeight = AMILabType<int >::CreateVarFromSmtPtr(var_m_oldClientHeight_ptr);
    if (var_m_oldClientHeight.get()) {
      var_m_oldClientHeight->Rename("m_oldClientHeight");
      context->AddVar(var_m_oldClientHeight,context);
    }
  }
  
  /* Type not available
  // Adding public member m_widget
  boost::shared_ptr<_GtkWidget > var_m_widget_ptr(GetObj()->m_widget, smartpointer_nodeleter<_GtkWidget >());
  if (var_m_widget_ptr.get()) {
    BasicVariable::ptr var_m_widget = AMILabType<_GtkWidget >::CreateVarFromSmtPtr(var_m_widget_ptr);
    if (var_m_widget.get()) {
      var_m_widget->Rename("m_widget");
      context->AddVar(var_m_widget,context);
    }
  }
  */
  
  /* Type not available
  // Adding public member m_wxwindow
  boost::shared_ptr<_GtkWidget > var_m_wxwindow_ptr(GetObj()->m_wxwindow, smartpointer_nodeleter<_GtkWidget >());
  if (var_m_wxwindow_ptr.get()) {
    BasicVariable::ptr var_m_wxwindow = AMILabType<_GtkWidget >::CreateVarFromSmtPtr(var_m_wxwindow_ptr);
    if (var_m_wxwindow.get()) {
      var_m_wxwindow->Rename("m_wxwindow");
      context->AddVar(var_m_wxwindow,context);
    }
  }
  */
  
  /* Type not available
  // Adding public member m_focusWidget
  boost::shared_ptr<_GtkWidget > var_m_focusWidget_ptr(GetObj()->m_focusWidget, smartpointer_nodeleter<_GtkWidget >());
  if (var_m_focusWidget_ptr.get()) {
    BasicVariable::ptr var_m_focusWidget = AMILabType<_GtkWidget >::CreateVarFromSmtPtr(var_m_focusWidget_ptr);
    if (var_m_focusWidget.get()) {
      var_m_focusWidget->Rename("m_focusWidget");
      context->AddVar(var_m_focusWidget,context);
    }
  }
  */
  
  /* Type not available
  // Adding public member m_imData
  boost::shared_ptr<wxGtkIMData > var_m_imData_ptr(GetObj()->m_imData, smartpointer_nodeleter<wxGtkIMData >());
  if (var_m_imData_ptr.get()) {
    BasicVariable::ptr var_m_imData = AMILabType<wxGtkIMData >::CreateVarFromSmtPtr(var_m_imData_ptr);
    if (var_m_imData.get()) {
      var_m_imData->Rename("m_imData");
      context->AddVar(var_m_imData,context);
    }
  }
  */
  
  /* Type not available
  // Adding public member m_scrollBar
  boost::shared_ptr<_GtkRange > var_m_scrollBar_ptr(&GetObj()->m_scrollBar, smartpointer_nodeleter<_GtkRange >());
  if (var_m_scrollBar_ptr.get()) {
    BasicVariable::ptr var_m_scrollBar = AMILabType<_GtkRange >::CreateVarFromSmtPtr(var_m_scrollBar_ptr);
    if (var_m_scrollBar.get()) {
      var_m_scrollBar->Rename("m_scrollBar");
      context->AddVar(var_m_scrollBar,context);
    }
  }
  */
  
  /* ArrayType not implemented
  // Adding public member m_scrollPos
  boost::shared_ptr<double > var_m_scrollPos_ptr(&GetObj()->m_scrollPos, smartpointer_nodeleter<double >());
  if (var_m_scrollPos_ptr.get()) {
    BasicVariable::ptr var_m_scrollPos = AMILabType<double >::CreateVarFromSmtPtr(var_m_scrollPos_ptr);
    if (var_m_scrollPos.get()) {
      var_m_scrollPos->Rename("m_scrollPos");
      context->AddVar(var_m_scrollPos,context);
    }
  }
  */
  
  /* ArrayType not implemented
  // Adding public member m_blockValueChanged
  boost::shared_ptr<bool > var_m_blockValueChanged_ptr(&GetObj()->m_blockValueChanged, smartpointer_nodeleter<bool >());
  if (var_m_blockValueChanged_ptr.get()) {
    BasicVariable::ptr var_m_blockValueChanged = AMILabType<bool >::CreateVarFromSmtPtr(var_m_blockValueChanged_ptr);
    if (var_m_blockValueChanged.get()) {
      var_m_blockValueChanged->Rename("m_blockValueChanged");
      context->AddVar(var_m_blockValueChanged,context);
    }
  }
  */
  
  /* Can't get address of a bit field
  // Adding public member m_needParent
  boost::shared_ptr<bool > var_m_needParent_ptr(&GetObj()->m_needParent, smartpointer_nodeleter<bool >());
  if (var_m_needParent_ptr.get()) {
    BasicVariable::ptr var_m_needParent = AMILabType<bool >::CreateVarFromSmtPtr(var_m_needParent_ptr);
    if (var_m_needParent.get()) {
      var_m_needParent->Rename("m_needParent");
      context->AddVar(var_m_needParent,context);
    }
  }
  */
  
  /* Can't get address of a bit field
  // Adding public member m_noExpose
  boost::shared_ptr<bool > var_m_noExpose_ptr(&GetObj()->m_noExpose, smartpointer_nodeleter<bool >());
  if (var_m_noExpose_ptr.get()) {
    BasicVariable::ptr var_m_noExpose = AMILabType<bool >::CreateVarFromSmtPtr(var_m_noExpose_ptr);
    if (var_m_noExpose.get()) {
      var_m_noExpose->Rename("m_noExpose");
      context->AddVar(var_m_noExpose,context);
    }
  }
  */
  
  /* Can't get address of a bit field
  // Adding public member m_nativeSizeEvent
  boost::shared_ptr<bool > var_m_nativeSizeEvent_ptr(&GetObj()->m_nativeSizeEvent, smartpointer_nodeleter<bool >());
  if (var_m_nativeSizeEvent_ptr.get()) {
    BasicVariable::ptr var_m_nativeSizeEvent = AMILabType<bool >::CreateVarFromSmtPtr(var_m_nativeSizeEvent_ptr);
    if (var_m_nativeSizeEvent.get()) {
      var_m_nativeSizeEvent->Rename("m_nativeSizeEvent");
      context->AddVar(var_m_nativeSizeEvent,context);
    }
  }
  */
  
  /* Can't get address of a bit field
  // Adding public member m_hasScrolling
  boost::shared_ptr<bool > var_m_hasScrolling_ptr(&GetObj()->m_hasScrolling, smartpointer_nodeleter<bool >());
  if (var_m_hasScrolling_ptr.get()) {
    BasicVariable::ptr var_m_hasScrolling = AMILabType<bool >::CreateVarFromSmtPtr(var_m_hasScrolling_ptr);
    if (var_m_hasScrolling.get()) {
      var_m_hasScrolling->Rename("m_hasScrolling");
      context->AddVar(var_m_hasScrolling,context);
    }
  }
  */
  
  /* Can't get address of a bit field
  // Adding public member m_hasVMT
  boost::shared_ptr<bool > var_m_hasVMT_ptr(&GetObj()->m_hasVMT, smartpointer_nodeleter<bool >());
  if (var_m_hasVMT_ptr.get()) {
    BasicVariable::ptr var_m_hasVMT = AMILabType<bool >::CreateVarFromSmtPtr(var_m_hasVMT_ptr);
    if (var_m_hasVMT.get()) {
      var_m_hasVMT->Rename("m_hasVMT");
      context->AddVar(var_m_hasVMT,context);
    }
  }
  */
  
  /* Can't get address of a bit field
  // Adding public member m_sizeSet
  boost::shared_ptr<bool > var_m_sizeSet_ptr(&GetObj()->m_sizeSet, smartpointer_nodeleter<bool >());
  if (var_m_sizeSet_ptr.get()) {
    BasicVariable::ptr var_m_sizeSet = AMILabType<bool >::CreateVarFromSmtPtr(var_m_sizeSet_ptr);
    if (var_m_sizeSet.get()) {
      var_m_sizeSet->Rename("m_sizeSet");
      context->AddVar(var_m_sizeSet,context);
    }
  }
  */
  
  /* Can't get address of a bit field
  // Adding public member m_resizing
  boost::shared_ptr<bool > var_m_resizing_ptr(&GetObj()->m_resizing, smartpointer_nodeleter<bool >());
  if (var_m_resizing_ptr.get()) {
    BasicVariable::ptr var_m_resizing = AMILabType<bool >::CreateVarFromSmtPtr(var_m_resizing_ptr);
    if (var_m_resizing.get()) {
      var_m_resizing->Rename("m_resizing");
      context->AddVar(var_m_resizing,context);
    }
  }
  */
  
  /* Can't get address of a bit field
  // Adding public member m_acceptsFocus
  boost::shared_ptr<bool > var_m_acceptsFocus_ptr(&GetObj()->m_acceptsFocus, smartpointer_nodeleter<bool >());
  if (var_m_acceptsFocus_ptr.get()) {
    BasicVariable::ptr var_m_acceptsFocus = AMILabType<bool >::CreateVarFromSmtPtr(var_m_acceptsFocus_ptr);
    if (var_m_acceptsFocus.get()) {
      var_m_acceptsFocus->Rename("m_acceptsFocus");
      context->AddVar(var_m_acceptsFocus,context);
    }
  }
  */
  
  /* Can't get address of a bit field
  // Adding public member m_hasFocus
  boost::shared_ptr<bool > var_m_hasFocus_ptr(&GetObj()->m_hasFocus, smartpointer_nodeleter<bool >());
  if (var_m_hasFocus_ptr.get()) {
    BasicVariable::ptr var_m_hasFocus = AMILabType<bool >::CreateVarFromSmtPtr(var_m_hasFocus_ptr);
    if (var_m_hasFocus.get()) {
      var_m_hasFocus->Rename("m_hasFocus");
      context->AddVar(var_m_hasFocus,context);
    }
  }
  */
  
  /* Can't get address of a bit field
  // Adding public member m_isScrolling
  boost::shared_ptr<bool > var_m_isScrolling_ptr(&GetObj()->m_isScrolling, smartpointer_nodeleter<bool >());
  if (var_m_isScrolling_ptr.get()) {
    BasicVariable::ptr var_m_isScrolling = AMILabType<bool >::CreateVarFromSmtPtr(var_m_isScrolling_ptr);
    if (var_m_isScrolling.get()) {
      var_m_isScrolling->Rename("m_isScrolling");
      context->AddVar(var_m_isScrolling,context);
    }
  }
  */
  
  /* Can't get address of a bit field
  // Adding public member m_clipPaintRegion
  boost::shared_ptr<bool > var_m_clipPaintRegion_ptr(&GetObj()->m_clipPaintRegion, smartpointer_nodeleter<bool >());
  if (var_m_clipPaintRegion_ptr.get()) {
    BasicVariable::ptr var_m_clipPaintRegion = AMILabType<bool >::CreateVarFromSmtPtr(var_m_clipPaintRegion_ptr);
    if (var_m_clipPaintRegion.get()) {
      var_m_clipPaintRegion->Rename("m_clipPaintRegion");
      context->AddVar(var_m_clipPaintRegion,context);
    }
  }
  */
  
  // Adding public member m_nativeUpdateRegion
  boost::shared_ptr<wxRegion > var_m_nativeUpdateRegion_ptr(&GetObj()->m_nativeUpdateRegion, smartpointer_nodeleter<wxRegion >());
  if (var_m_nativeUpdateRegion_ptr.get()) {
    BasicVariable::ptr var_m_nativeUpdateRegion = AMILabType<wxRegion >::CreateVarFromSmtPtr(var_m_nativeUpdateRegion_ptr);
    if (var_m_nativeUpdateRegion.get()) {
      var_m_nativeUpdateRegion->Rename("m_nativeUpdateRegion");
      context->AddVar(var_m_nativeUpdateRegion,context);
    }
  }
  
  /* Can't get address of a bit field
  // Adding public member m_dirtyTabOrder
  boost::shared_ptr<bool > var_m_dirtyTabOrder_ptr(&GetObj()->m_dirtyTabOrder, smartpointer_nodeleter<bool >());
  if (var_m_dirtyTabOrder_ptr.get()) {
    BasicVariable::ptr var_m_dirtyTabOrder = AMILabType<bool >::CreateVarFromSmtPtr(var_m_dirtyTabOrder_ptr);
    if (var_m_dirtyTabOrder.get()) {
      var_m_dirtyTabOrder->Rename("m_dirtyTabOrder");
      context->AddVar(var_m_dirtyTabOrder,context);
    }
  }
  */
  
  /* Can't get address of a bit field
  // Adding public member m_needsStyleChange
  boost::shared_ptr<bool > var_m_needsStyleChange_ptr(&GetObj()->m_needsStyleChange, smartpointer_nodeleter<bool >());
  if (var_m_needsStyleChange_ptr.get()) {
    BasicVariable::ptr var_m_needsStyleChange = AMILabType<bool >::CreateVarFromSmtPtr(var_m_needsStyleChange_ptr);
    if (var_m_needsStyleChange.get()) {
      var_m_needsStyleChange->Rename("m_needsStyleChange");
      context->AddVar(var_m_needsStyleChange,context);
    }
  }
  */
  
  /* Can't get address of a bit field
  // Adding public member m_mouseButtonDown
  boost::shared_ptr<bool > var_m_mouseButtonDown_ptr(&GetObj()->m_mouseButtonDown, smartpointer_nodeleter<bool >());
  if (var_m_mouseButtonDown_ptr.get()) {
    BasicVariable::ptr var_m_mouseButtonDown = AMILabType<bool >::CreateVarFromSmtPtr(var_m_mouseButtonDown_ptr);
    if (var_m_mouseButtonDown.get()) {
      var_m_mouseButtonDown->Rename("m_mouseButtonDown");
      context->AddVar(var_m_mouseButtonDown,context);
    }
  }
  */
  
  /* Can't get address of a bit field
  // Adding public member m_blockScrollEvent
  boost::shared_ptr<bool > var_m_blockScrollEvent_ptr(&GetObj()->m_blockScrollEvent, smartpointer_nodeleter<bool >());
  if (var_m_blockScrollEvent_ptr.get()) {
    BasicVariable::ptr var_m_blockScrollEvent = AMILabType<bool >::CreateVarFromSmtPtr(var_m_blockScrollEvent_ptr);
    if (var_m_blockScrollEvent.get()) {
      var_m_blockScrollEvent->Rename("m_blockScrollEvent");
      context->AddVar(var_m_blockScrollEvent,context);
    }
  }
  */
  
  /* Can't get address of a bit field
  // Adding public member m_showOnIdle
  boost::shared_ptr<bool > var_m_showOnIdle_ptr(&GetObj()->m_showOnIdle, smartpointer_nodeleter<bool >());
  if (var_m_showOnIdle_ptr.get()) {
    BasicVariable::ptr var_m_showOnIdle = AMILabType<bool >::CreateVarFromSmtPtr(var_m_showOnIdle_ptr);
    if (var_m_showOnIdle.get()) {
      var_m_showOnIdle->Rename("m_showOnIdle");
      context->AddVar(var_m_showOnIdle,context);
    }
  }
  */
  
  /* Type not available
  // Adding public member m_insertCallback
  boost::shared_ptr<_7173 > var_m_insertCallback_ptr(&GetObj()->m_insertCallback, smartpointer_nodeleter<_7173 >());
  if (var_m_insertCallback_ptr.get()) {
    BasicVariable::ptr var_m_insertCallback = AMILabType<_7173 >::CreateVarFromSmtPtr(var_m_insertCallback_ptr);
    if (var_m_insertCallback.get()) {
      var_m_insertCallback->Rename("m_insertCallback");
      context->AddVar(var_m_insertCallback,context);
    }
  }
  */


  
  AMIObject::ptr obj_ScrollDir(new AMIObject);
  obj_ScrollDir->SetName("ScrollDir");

  BasicVariable::ptr var_ScrollDir_Horz = AMILabType<int >::CreateVar(0);
  if (var_ScrollDir_Horz.get()) {
    var_ScrollDir_Horz->Rename("ScrollDir_Horz");
    obj_ScrollDir->GetContext()->AddVar(var_ScrollDir_Horz,obj_ScrollDir->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_ScrollDir->GetName().c_str(),obj_ScrollDir,context);


  // Adding Bases

  // Add base parent wxWindowBase
  boost::shared_ptr<wxWindowBase > parent_wxWindowBase(  boost::dynamic_pointer_cast<wxWindowBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxWindowBase = AMILabType<wxWindowBase >::CreateVarFromSmtPtr(parent_wxWindowBase);
  context->AddVar("wxWindowBase",var_wxWindowBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxWindowBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxWindowBase);
  context->AddDefault(obj_wxWindowBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxWindow_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxWindow");
    WrapClass_wxWindow::AddVar_wxWindow_1(amiobject->GetContext());
  WrapClass_wxWindow::AddVar_wxWindow(amiobject->GetContext());
  WrapClass_wxWindow::AddVar_wxWindow_2(amiobject->GetContext());


  // Static methods 
  /* Types are missing
  WrapClass_wxWindow::AddVar_GTKGetLayout(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_wxWindow::AddVar_GTKSetLayout(amiobject->GetContext());
  */

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxWindow::wxWindow()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_wxWindow_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_wxWindow_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxWindow* _newobj = new wxWindow();
  BasicVariable::ptr res = WrapClass_wxWindow::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxWindow::wxWindow(...)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_wxWindow::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_wxWindow::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindow::wrap_wxWindow_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindow::wrap_wxWindow_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxWindow::wxWindow(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxString const & name = wxPanelNameStr)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_wxWindow_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxPanelNameStr)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_wxWindow_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  wxWindow* parent;
  if (CheckNullVar(_p,_n))  {
    parent=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > parent_smtptr;
    if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
    parent = parent_smtptr.get();
  }

  int id;
  if (!get_val_param<int >(id,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxPanelNameStr) );

  wxWindow* _newobj = new wxWindow(parent, id, pos, size, style, name);
  BasicVariable::ptr res = WrapClass_wxWindow::CreateVar(_newobj);
  return res;
}
/* The following types are missing: _GtkWidget

//---------------------------------------------------
//  Wrapping of wxLayoutDirection wxWindow::GTKGetLayout(GtkWidget * widget)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_static_GTKGetLayout::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GtkWidget, "parameter named 'widget'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_static_GTKGetLayout::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  _GtkWidget* widget;
  if (CheckNullVar(_p,_n))  {
    widget=(_GtkWidget*)NULL;
    _n++;
  } else {
    boost::shared_ptr<_GtkWidget > widget_smtptr;
    if (!get_val_smtptr_param<_GtkWidget >(widget_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    widget = widget_smtptr.get();
  }

  wxLayoutDirection res =   wxWindow::GTKGetLayout(widget);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}
*/
/* The following types are missing: _GtkWidget

//---------------------------------------------------
//  Wrapping of void wxWindow::GTKSetLayout(GtkWidget * widget, wxLayoutDirection dir)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_static_GTKSetLayout::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GtkWidget, "parameter named 'widget'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dir'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_static_GTKSetLayout::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  _GtkWidget* widget;
  if (CheckNullVar(_p,_n))  {
    widget=(_GtkWidget*)NULL;
    _n++;
  } else {
    boost::shared_ptr<_GtkWidget > widget_smtptr;
    if (!get_val_smtptr_param<_GtkWidget >(widget_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    widget = widget_smtptr.get();
  }

  int dir_int;
  if (!get_val_param<int >(dir_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxLayoutDirection dir = (wxLayoutDirection) dir_int;

  wxWindow::GTKSetLayout(widget, dir);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of bool wxWindow::Create(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxString const & name = wxPanelNameStr)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxPanelNameStr)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  wxWindow* parent;
  if (CheckNullVar(_p,_n))  {
    parent=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > parent_smtptr;
    if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    parent = parent_smtptr.get();
  }

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxPanelNameStr) );

  bool res =   this->_objectptr->GetObj()->Create(parent, id, pos, size, style, name);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindow::SetLabel(wxString const & param0)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_SetLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_SetLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > param0_smtptr;
  if (!get_val_smtptr_param<wxString >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & param0 = *param0_smtptr;

  this->_objectptr->GetObj()->SetLabel(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxWindow::GetLabel()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GetLabel::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GetLabel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetLabel();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::Destroy()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_Destroy::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_Destroy::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Destroy();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindow::Raise()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_Raise::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_Raise::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Raise();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindow::Lower()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_Lower::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_Lower::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Lower();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::Show(bool show = true)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_Show::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'show' (def:true)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_Show::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool show = true;
  if (!get_val_param<bool >(show,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Show(show);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::Enable(bool enable = true)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_Enable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'enable' (def:true)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_Enable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool enable = true;
  if (!get_val_param<bool >(enable,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Enable(enable);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindow::SetWindowStyleFlag(long int style)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_SetWindowStyleFlag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_SetWindowStyleFlag::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long style_long;
  if (!get_val_param<long >(style_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int style = style_long;

  this->_objectptr->GetObj()->SetWindowStyleFlag(style);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::IsRetained()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_IsRetained::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_IsRetained::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsRetained();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindow::SetFocus()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_SetFocus::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_SetFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFocus();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::AcceptsFocus()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_AcceptsFocus::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_AcceptsFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->AcceptsFocus();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::Reparent(wxWindowBase * newParent)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_Reparent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'newParent'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_Reparent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxWindowBase* newParent;
  if (CheckNullVar(_p,_n))  {
    newParent=(wxWindowBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindowBase > newParent_smtptr;
    if (!get_val_smtptr_param<wxWindowBase >(newParent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    newParent = newParent_smtptr.get();
  }

  bool res =   this->_objectptr->GetObj()->Reparent(newParent);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindow::WarpPointer(int x, int y)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_WarpPointer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_WarpPointer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->WarpPointer(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindow::Refresh(bool eraseBackground = true, wxRect const * rect = 0u)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_Refresh::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'eraseBackground' (def:true)")
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_Refresh::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  bool eraseBackground = true;
  if (!get_val_param<bool >(eraseBackground,_p,_n,false,false)) ClassHelpAndReturn;

  wxRect* rect = 0u;
  if (CheckNullVar(_p,_n))  {
    rect=(wxRect*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxRect > rect_smtptr;
    if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    rect = rect_smtptr.get();
  }

  this->_objectptr->GetObj()->Refresh(eraseBackground, rect);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindow::Update()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_Update::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_Update::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Update();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindow::ClearBackground()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_ClearBackground::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_ClearBackground::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ClearBackground();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::SetBackgroundColour(wxColour const & colour)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_SetBackgroundColour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'colour'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_SetBackgroundColour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > colour_smtptr;
  if (!get_val_smtptr_param<wxColour >(colour_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour const & colour = *colour_smtptr;

  bool res =   this->_objectptr->GetObj()->SetBackgroundColour(colour);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::SetForegroundColour(wxColour const & colour)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_SetForegroundColour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'colour'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_SetForegroundColour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > colour_smtptr;
  if (!get_val_smtptr_param<wxColour >(colour_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour const & colour = *colour_smtptr;

  bool res =   this->_objectptr->GetObj()->SetForegroundColour(colour);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::SetCursor(wxCursor const & cursor)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_SetCursor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCursor, "parameter named 'cursor'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_SetCursor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxCursor > cursor_smtptr;
  if (!get_val_smtptr_param<wxCursor >(cursor_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxCursor const & cursor = *cursor_smtptr;

  bool res =   this->_objectptr->GetObj()->SetCursor(cursor);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::SetFont(wxFont const & font)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_SetFont::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'font'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_SetFont::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFont > font_smtptr;
  if (!get_val_smtptr_param<wxFont >(font_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFont const & font = *font_smtptr;

  bool res =   this->_objectptr->GetObj()->SetFont(font);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::SetBackgroundStyle(wxBackgroundStyle style)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_SetBackgroundStyle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'style'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_SetBackgroundStyle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int style_int;
  if (!get_val_param<int >(style_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxBackgroundStyle style = (wxBackgroundStyle) style_int;

  bool res =   this->_objectptr->GetObj()->SetBackgroundStyle(style);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxWindow::GetCharHeight()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GetCharHeight::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GetCharHeight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCharHeight();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxWindow::GetCharWidth()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GetCharWidth::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GetCharWidth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCharWidth();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindow::GetTextExtent(wxString const & string, int * x, int * y, int * descent = 0u, int * externalLeading = 0u, wxFont const * theFont = 0u)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GetTextExtent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'string'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'descent' (def:0u)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'externalLeading' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'theFont' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GetTextExtent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > string_smtptr;
  if (!get_val_smtptr_param<wxString >(string_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & string = *string_smtptr;

  int* x;
  if (CheckNullVar(_p,_n))  {
    x=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > x_smtptr;
    if (!get_val_smtptr_param<int >(x_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    x = x_smtptr.get();
  }

  int* y;
  if (CheckNullVar(_p,_n))  {
    y=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > y_smtptr;
    if (!get_val_smtptr_param<int >(y_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    y = y_smtptr.get();
  }

  int* descent = 0u;
  if (CheckNullVar(_p,_n))  {
    descent=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > descent_smtptr;
    if (!get_val_smtptr_param<int >(descent_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    descent = descent_smtptr.get();
  }

  int* externalLeading = 0u;
  if (CheckNullVar(_p,_n))  {
    externalLeading=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > externalLeading_smtptr;
    if (!get_val_smtptr_param<int >(externalLeading_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    externalLeading = externalLeading_smtptr.get();
  }

  wxFont* theFont = 0u;
  if (CheckNullVar(_p,_n))  {
    theFont=(wxFont*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxFont > theFont_smtptr;
    if (!get_val_smtptr_param<wxFont >(theFont_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    theFont = theFont_smtptr.get();
  }

  this->_objectptr->GetObj()->GetTextExtent(string, x, y, descent, externalLeading, theFont);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindow::SetScrollbar(int orient, int pos, int thumbVisible, int range, bool refresh = true)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_SetScrollbar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orient'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'thumbVisible'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'range'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'refresh' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_SetScrollbar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  int orient;
  if (!get_val_param<int >(orient,_p,_n,true,false)) ClassHelpAndReturn;

  int pos;
  if (!get_val_param<int >(pos,_p,_n,true,false)) ClassHelpAndReturn;

  int thumbVisible;
  if (!get_val_param<int >(thumbVisible,_p,_n,true,false)) ClassHelpAndReturn;

  int range;
  if (!get_val_param<int >(range,_p,_n,true,false)) ClassHelpAndReturn;

  bool refresh = true;
  if (!get_val_param<bool >(refresh,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScrollbar(orient, pos, thumbVisible, range, refresh);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindow::SetScrollPos(int orient, int pos, bool refresh = true)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_SetScrollPos::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orient'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'refresh' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_SetScrollPos::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int orient;
  if (!get_val_param<int >(orient,_p,_n,true,false)) ClassHelpAndReturn;

  int pos;
  if (!get_val_param<int >(pos,_p,_n,true,false)) ClassHelpAndReturn;

  bool refresh = true;
  if (!get_val_param<bool >(refresh,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScrollPos(orient, pos, refresh);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxWindow::GetScrollPos(int orient)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GetScrollPos::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orient'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GetScrollPos::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int orient;
  if (!get_val_param<int >(orient,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetScrollPos(orient);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxWindow::GetScrollThumb(int orient)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GetScrollThumb::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orient'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GetScrollThumb::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int orient;
  if (!get_val_param<int >(orient,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetScrollThumb(orient);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxWindow::GetScrollRange(int orient)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GetScrollRange::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orient'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GetScrollRange::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int orient;
  if (!get_val_param<int >(orient,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetScrollRange(orient);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindow::ScrollWindow(int dx, int dy, wxRect const * rect = 0u)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_ScrollWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dy'")
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_ScrollWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int dx;
  if (!get_val_param<int >(dx,_p,_n,true,false)) ClassHelpAndReturn;

  int dy;
  if (!get_val_param<int >(dy,_p,_n,true,false)) ClassHelpAndReturn;

  wxRect* rect = 0u;
  if (CheckNullVar(_p,_n))  {
    rect=(wxRect*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxRect > rect_smtptr;
    if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    rect = rect_smtptr.get();
  }

  this->_objectptr->GetObj()->ScrollWindow(dx, dy, rect);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::ScrollLines(int lines)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_ScrollLines::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'lines'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_ScrollLines::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int lines;
  if (!get_val_param<int >(lines,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ScrollLines(lines);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::ScrollPages(int pages)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_ScrollPages::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pages'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_ScrollPages::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int pages;
  if (!get_val_param<int >(pages,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ScrollPages(pages);
  return AMILabType<bool >::CreateVar(res);
}
/* The following types are missing: wxDropTarget

//---------------------------------------------------
//  Wrapping of void wxWindow::SetDropTarget(wxDropTarget * dropTarget)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_SetDropTarget::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDropTarget, "parameter named 'dropTarget'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_SetDropTarget::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxDropTarget* dropTarget;
  if (CheckNullVar(_p,_n))  {
    dropTarget=(wxDropTarget*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxDropTarget > dropTarget_smtptr;
    if (!get_val_smtptr_param<wxDropTarget >(dropTarget_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    dropTarget = dropTarget_smtptr.get();
  }

  this->_objectptr->GetObj()->SetDropTarget(dropTarget);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxWindow::AddChild(wxWindowBase * child)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_AddChild::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'child'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_AddChild::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxWindowBase* child;
  if (CheckNullVar(_p,_n))  {
    child=(wxWindowBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindowBase > child_smtptr;
    if (!get_val_smtptr_param<wxWindowBase >(child_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    child = child_smtptr.get();
  }

  this->_objectptr->GetObj()->AddChild(child);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindow::RemoveChild(wxWindowBase * child)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_RemoveChild::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'child'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_RemoveChild::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxWindowBase* child;
  if (CheckNullVar(_p,_n))  {
    child=(wxWindowBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindowBase > child_smtptr;
    if (!get_val_smtptr_param<wxWindowBase >(child_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    child = child_smtptr.get();
  }

  this->_objectptr->GetObj()->RemoveChild(child);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindow::SetLayoutDirection(wxLayoutDirection dir)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_SetLayoutDirection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dir'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
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
//  Wrapping of wxLayoutDirection wxWindow::GetLayoutDirection()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GetLayoutDirection::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GetLayoutDirection::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxLayoutDirection res =   this->_objectptr->GetObj()->GetLayoutDirection();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxWindow::AdjustForLayoutDirection(wxCoord x, wxCoord width, wxCoord widthTotal)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_AdjustForLayoutDirection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'widthTotal'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_AdjustForLayoutDirection::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,false)) ClassHelpAndReturn;

  int widthTotal;
  if (!get_val_param<int >(widthTotal,_p,_n,true,false)) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->AdjustForLayoutDirection(x, width, widthTotal);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::DoIsExposed(int x, int y)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_DoIsExposed_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_DoIsExposed_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->DoIsExposed(x, y);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindow::DoIsExposed(...)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_DoIsExposed::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_DoIsExposed::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindow::wrap_DoIsExposed_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindow::wrap_DoIsExposed_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::DoIsExposed(int x, int y, int w, int h)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_DoIsExposed_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_DoIsExposed_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  int w;
  if (!get_val_param<int >(w,_p,_n,true,true)) ClassReturnEmptyVar;

  int h;
  if (!get_val_param<int >(h,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->DoIsExposed(x, y, w, h);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindow::SetDoubleBuffered(bool on)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_SetDoubleBuffered::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'on'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_SetDoubleBuffered::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool on;
  if (!get_val_param<bool >(on,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDoubleBuffered(on);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::IsDoubleBuffered()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_IsDoubleBuffered::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_IsDoubleBuffered::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsDoubleBuffered();
  return AMILabType<bool >::CreateVar(res);
}
/* The following types are missing: _GtkWidget

//---------------------------------------------------
//  Wrapping of WXWidget wxWindow::GetHandle()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GetHandle::SetParametersComments()
{
  return_comments="returning a variable of type _GtkWidget";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GetHandle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  WXWidget res =   this->_objectptr->GetObj()->GetHandle();
  return AMILabType<_GtkWidget >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxWindow::OnInternalIdle()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_OnInternalIdle::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_OnInternalIdle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnInternalIdle();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindow::GtkUpdate()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GtkUpdate::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GtkUpdate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GtkUpdate();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindow::OnIdle(wxIdleEvent & param0)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_OnIdle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIdleEvent, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_OnIdle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxIdleEvent > param0_smtptr;
  if (!get_val_smtptr_param<wxIdleEvent >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxIdleEvent & param0 = *param0_smtptr;

  this->_objectptr->GetObj()->OnIdle(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindow::OnParentEnable(bool param0)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_OnParentEnable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_OnParentEnable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool param0;
  if (!get_val_param<bool >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnParentEnable(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::PreCreation(wxWindow * parent, wxPoint const & pos, wxSize const & size)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_PreCreation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_PreCreation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  wxWindow* parent;
  if (CheckNullVar(_p,_n))  {
    parent=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > parent_smtptr;
    if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    parent = parent_smtptr.get();
  }

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & pos = *pos_smtptr;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSize const & size = *size_smtptr;

  bool res =   this->_objectptr->GetObj()->PreCreation(parent, pos, size);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindow::PostCreation()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_PostCreation::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_PostCreation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PostCreation();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindow::DoAddChild(wxWindow * child)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_DoAddChild::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'child'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_DoAddChild::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxWindow* child;
  if (CheckNullVar(_p,_n))  {
    child=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > child_smtptr;
    if (!get_val_smtptr_param<wxWindow >(child_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    child = child_smtptr.get();
  }

  this->_objectptr->GetObj()->DoAddChild(child);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindow::GtkSendPaintEvents()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GtkSendPaintEvents::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GtkSendPaintEvents::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GtkSendPaintEvents();
  return BasicVariable::ptr();
}
/* The following types are missing: _GtkWidget

//---------------------------------------------------
//  Wrapping of GtkWidget * wxWindow::GetConnectWidget()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GetConnectWidget::SetParametersComments()
{
  return_comments="returning a variable of type _GtkWidget";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GetConnectWidget::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  GtkWidget * res =   this->_objectptr->GetObj()->GetConnectWidget();
  return AMILabType<_GtkWidget >::CreateVar(res,true);
}
*/
/* The following types are missing: _GtkWidget

//---------------------------------------------------
//  Wrapping of void wxWindow::ConnectWidget(GtkWidget * widget)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_ConnectWidget::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GtkWidget, "parameter named 'widget'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_ConnectWidget::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  _GtkWidget* widget;
  if (CheckNullVar(_p,_n))  {
    widget=(_GtkWidget*)NULL;
    _n++;
  } else {
    boost::shared_ptr<_GtkWidget > widget_smtptr;
    if (!get_val_smtptr_param<_GtkWidget >(widget_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    widget = widget_smtptr.get();
  }

  this->_objectptr->GetObj()->ConnectWidget(widget);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: _GdkEventAny

//---------------------------------------------------
//  Wrapping of int wxWindow::GTKCallbackCommonPrologue(_GdkEventAny * event)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GTKCallbackCommonPrologue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GdkEventAny, "parameter named 'event'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GTKCallbackCommonPrologue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  _GdkEventAny* event;
  if (CheckNullVar(_p,_n))  {
    event=(_GdkEventAny*)NULL;
    _n++;
  } else {
    boost::shared_ptr<_GdkEventAny > event_smtptr;
    if (!get_val_smtptr_param<_GdkEventAny >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    event = event_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->GTKCallbackCommonPrologue(event);
  return AMILabType<int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxWindow::GTKProcessEvent(wxEvent & event)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GTKProcessEvent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEvent, "parameter named 'event'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GTKProcessEvent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxEvent > event_smtptr;
  if (!get_val_smtptr_param<wxEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxEvent & event = *event_smtptr;

  bool res =   this->_objectptr->GetObj()->GTKProcessEvent(event);
  return AMILabType<bool >::CreateVar(res);
}
/* The following types are missing: _PangoContext

//---------------------------------------------------
//  Wrapping of PangoContext * wxWindow::GtkGetPangoDefaultContext()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GtkGetPangoDefaultContext::SetParametersComments()
{
  return_comments="returning a variable of type _PangoContext";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GtkGetPangoDefaultContext::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  PangoContext * res =   this->_objectptr->GetObj()->GtkGetPangoDefaultContext();
  return AMILabType<_PangoContext >::CreateVar(res,true);
}
*/
/* The following types are missing: _GtkTooltips

//---------------------------------------------------
//  Wrapping of void wxWindow::ApplyToolTip(GtkTooltips * tips, wxChar const * tip)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_ApplyToolTip::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GtkTooltips, "parameter named 'tips'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'tip'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_ApplyToolTip::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  _GtkTooltips* tips;
  if (CheckNullVar(_p,_n))  {
    tips=(_GtkTooltips*)NULL;
    _n++;
  } else {
    boost::shared_ptr<_GtkTooltips > tips_smtptr;
    if (!get_val_smtptr_param<_GtkTooltips >(tips_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    tips = tips_smtptr.get();
  }

  boost::shared_ptr<std::string > tip_string;
  if (!get_val_smtptr_param<std::string >(tip_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  wchar_t tip[tip_string->size()+1];
mbstowcs(tip,tip_string->c_str(),tip_string->size()+1);

  this->_objectptr->GetObj()->ApplyToolTip(tips, tip);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxWindow::GtkUpdateSize()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GtkUpdateSize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GtkUpdateSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GtkUpdateSize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindow::GtkShowOnIdle()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GtkShowOnIdle::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GtkShowOnIdle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GtkShowOnIdle();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::GtkShowFromOnIdle()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GtkShowFromOnIdle::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GtkShowFromOnIdle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GtkShowFromOnIdle();
  return AMILabType<bool >::CreateVar(res);
}
/* The following types are missing: _GtkWidget

//---------------------------------------------------
//  Wrapping of void wxWindow::FixUpMouseEvent(GtkWidget * param0, wxCoord & param1, wxCoord & param2)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_FixUpMouseEvent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GtkWidget, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_FixUpMouseEvent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  _GtkWidget* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(_GtkWidget*)NULL;
    _n++;
  } else {
    boost::shared_ptr<_GtkWidget > param0_smtptr;
    if (!get_val_smtptr_param<_GtkWidget >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  boost::shared_ptr<int > param1_smtptr;
  if (!get_val_smtptr_param<int >(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxCoord & param1 = *param1_smtptr;

  boost::shared_ptr<int > param2_smtptr;
  if (!get_val_smtptr_param<int >(param2_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxCoord & param2 = *param2_smtptr;

  this->_objectptr->GetObj()->FixUpMouseEvent(param0, param1, param2);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of bool wxWindow::IsTransparentForMouse()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_IsTransparentForMouse::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_IsTransparentForMouse::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsTransparentForMouse();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxWindow::IsRadioButton()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_IsRadioButton::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_IsRadioButton::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsRadioButton();
  return AMILabType<bool >::CreateVar(res);
}
/* The following types are missing: _GtkRange

//---------------------------------------------------
//  Wrapping of wxEventType wxWindow::GetScrollEventType(GtkRange * range)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GetScrollEventType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GtkRange, "parameter named 'range'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GetScrollEventType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  _GtkRange* range;
  if (CheckNullVar(_p,_n))  {
    range=(_GtkRange*)NULL;
    _n++;
  } else {
    boost::shared_ptr<_GtkRange > range_smtptr;
    if (!get_val_smtptr_param<_GtkRange >(range_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    range = range_smtptr.get();
  }

  wxEventType res =   this->_objectptr->GetObj()->GetScrollEventType(range);
  return AMILabType<int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxWindow::BlockScrollEvent()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_BlockScrollEvent::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_BlockScrollEvent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->BlockScrollEvent();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindow::UnblockScrollEvent()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_UnblockScrollEvent::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_UnblockScrollEvent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UnblockScrollEvent();
  return BasicVariable::ptr();
}
/* The following types are missing: _GtkRange

//---------------------------------------------------
//  Wrapping of wxWindow::ScrollDir wxWindow::ScrollDirFromRange(GtkRange * range)
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_ScrollDirFromRange::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GtkRange, "parameter named 'range'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_ScrollDirFromRange::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  _GtkRange* range;
  if (CheckNullVar(_p,_n))  {
    range=(_GtkRange*)NULL;
    _n++;
  } else {
    boost::shared_ptr<_GtkRange > range_smtptr;
    if (!get_val_smtptr_param<_GtkRange >(range_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    range = range_smtptr.get();
  }

  wxWindow::ScrollDir res =   this->_objectptr->GetObj()->ScrollDirFromRange(range);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxWindow::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxWindow::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindow::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

