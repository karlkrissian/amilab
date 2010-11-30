/**
 * C++ Interface: wrap_wxAuiPaneInfo
 *
 * Description: wrapping wxAuiPaneInfo
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
#include "wrap_wxWindow.h"
#include "wrap_wxFrame.h"
#include "wrap_wxSize.h"
#include "wrap_wxPoint.h"
#include "wrap_wxRect.h"
#include "wrap_wxAuiPaneInfo.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_wxAuiPaneInfo.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAuiPaneInfo>::CreateVar( ParamList* p)
{
  WrapClass_wxAuiPaneInfo::wrap_wxAuiPaneInfo construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxAuiPaneInfo);
AMI_DEFINE_VARFROMSMTPTR(wxAuiPaneInfo);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxAuiPaneInfo
//
Variable<AMIObject>::ptr WrapClass_wxAuiPaneInfo::CreateVar( wxAuiPaneInfo* sp)
{
  boost::shared_ptr<wxAuiPaneInfo> di_ptr(
    sp,
    wxwindow_nodeleter<wxAuiPaneInfo>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAuiPaneInfo>::CreateVar(
      new WrapClass_wxAuiPaneInfo(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxAuiPaneInfo::AddMethods(WrapClass<wxAuiPaneInfo>::ptr this_ptr )
{
  


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_SafeSet( this_ptr);
      AddVar_IsOk( this_ptr);
      AddVar_IsFixed( this_ptr);
      AddVar_IsResizable( this_ptr);
      AddVar_IsShown( this_ptr);
      AddVar_IsFloating( this_ptr);
      AddVar_IsDocked( this_ptr);
      AddVar_IsToolbar( this_ptr);
      AddVar_IsTopDockable( this_ptr);
      AddVar_IsBottomDockable( this_ptr);
      AddVar_IsLeftDockable( this_ptr);
      AddVar_IsRightDockable( this_ptr);
      AddVar_IsFloatable( this_ptr);
      AddVar_IsMovable( this_ptr);
      AddVar_IsDestroyOnClose( this_ptr);
      AddVar_IsMaximized( this_ptr);
      AddVar_HasCaption( this_ptr);
      AddVar_HasGripper( this_ptr);
      AddVar_HasBorder( this_ptr);
      AddVar_HasCloseButton( this_ptr);
      AddVar_HasMaximizeButton( this_ptr);
      AddVar_HasMinimizeButton( this_ptr);
      AddVar_HasPinButton( this_ptr);
      AddVar_HasGripperTop( this_ptr);
      AddVar_Window( this_ptr);
      AddVar_Name( this_ptr);
      AddVar_Caption( this_ptr);
      AddVar_Left( this_ptr);
      AddVar_Right( this_ptr);
      AddVar_Top( this_ptr);
      AddVar_Bottom( this_ptr);
      AddVar_Center( this_ptr);
      AddVar_Centre( this_ptr);
      AddVar_Direction( this_ptr);
      AddVar_Layer( this_ptr);
      AddVar_Row( this_ptr);
      AddVar_Position( this_ptr);
      AddVar_BestSize_1( this_ptr);
      AddVar_MinSize_1( this_ptr);
      AddVar_MaxSize_1( this_ptr);
      AddVar_BestSize( this_ptr);
      AddVar_BestSize_2( this_ptr);
      AddVar_MinSize( this_ptr);
      AddVar_MinSize_2( this_ptr);
      AddVar_MaxSize( this_ptr);
      AddVar_MaxSize_2( this_ptr);
      AddVar_FloatingPosition_1( this_ptr);
      AddVar_FloatingPosition( this_ptr);
      AddVar_FloatingPosition_2( this_ptr);
      AddVar_FloatingSize_1( this_ptr);
      AddVar_FloatingSize( this_ptr);
      AddVar_FloatingSize_2( this_ptr);
      AddVar_Fixed( this_ptr);
      AddVar_Resizable( this_ptr);
      AddVar_Dock( this_ptr);
      AddVar_Float( this_ptr);
      AddVar_Hide( this_ptr);
      AddVar_Show( this_ptr);
      AddVar_CaptionVisible( this_ptr);
      AddVar_Maximize( this_ptr);
      AddVar_Restore( this_ptr);
      AddVar_PaneBorder( this_ptr);
      AddVar_Gripper( this_ptr);
      AddVar_GripperTop( this_ptr);
      AddVar_CloseButton( this_ptr);
      AddVar_MaximizeButton( this_ptr);
      AddVar_MinimizeButton( this_ptr);
      AddVar_PinButton( this_ptr);
      AddVar_DestroyOnClose( this_ptr);
      AddVar_TopDockable( this_ptr);
      AddVar_BottomDockable( this_ptr);
      AddVar_LeftDockable( this_ptr);
      AddVar_RightDockable( this_ptr);
      AddVar_Floatable( this_ptr);
      AddVar_Movable( this_ptr);
      AddVar_DockFixed( this_ptr);
      AddVar_Dockable( this_ptr);
      AddVar_DefaultPane( this_ptr);
      AddVar_CentrePane( this_ptr);
      AddVar_CenterPane( this_ptr);
      AddVar_ToolbarPane( this_ptr);
      AddVar_SetFlag( this_ptr);
      AddVar_HasFlag( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      // Adding public member name
      boost::shared_ptr<wxString > var_name_ptr(&GetObj()->name, smartpointer_nodeleter<wxString >());
      if (var_name_ptr.get()) {
        BasicVariable::ptr var_name = AMILabType<wxString >::CreateVarFromSmtPtr(var_name_ptr);
        if (var_name.get()) {
          var_name->Rename("name");
          context->AddVar(var_name,context);
        }
      }
      
      // Adding public member caption
      boost::shared_ptr<wxString > var_caption_ptr(&GetObj()->caption, smartpointer_nodeleter<wxString >());
      if (var_caption_ptr.get()) {
        BasicVariable::ptr var_caption = AMILabType<wxString >::CreateVarFromSmtPtr(var_caption_ptr);
        if (var_caption.get()) {
          var_caption->Rename("caption");
          context->AddVar(var_caption,context);
        }
      }
      
      // Adding public member window
      boost::shared_ptr<wxWindow > var_window_ptr(GetObj()->window, smartpointer_nodeleter<wxWindow >());
      if (var_window_ptr.get()) {
        BasicVariable::ptr var_window = AMILabType<wxWindow >::CreateVarFromSmtPtr(var_window_ptr);
        if (var_window.get()) {
          var_window->Rename("window");
          context->AddVar(var_window,context);
        }
      }
      
      // Adding public member frame
      boost::shared_ptr<wxFrame > var_frame_ptr(GetObj()->frame, smartpointer_nodeleter<wxFrame >());
      if (var_frame_ptr.get()) {
        BasicVariable::ptr var_frame = AMILabType<wxFrame >::CreateVarFromSmtPtr(var_frame_ptr);
        if (var_frame.get()) {
          var_frame->Rename("frame");
          context->AddVar(var_frame,context);
        }
      }
      
      /* type not available
      // Adding public member state
      boost::shared_ptr<unsigned int > var_state_ptr(&GetObj()->state, smartpointer_nodeleter<unsigned int >());
      if (var_state_ptr.get()) {
        BasicVariable::ptr var_state = AMILabType<unsigned int >::CreateVarFromSmtPtr(var_state_ptr);
        if (var_state.get()) {
          var_state->Rename("state");
          context->AddVar(var_state,context);
        }
      }
      */
      
      // Adding public member dock_direction
      boost::shared_ptr<int > var_dock_direction_ptr(&GetObj()->dock_direction, smartpointer_nodeleter<int >());
      if (var_dock_direction_ptr.get()) {
        BasicVariable::ptr var_dock_direction = AMILabType<int >::CreateVarFromSmtPtr(var_dock_direction_ptr);
        if (var_dock_direction.get()) {
          var_dock_direction->Rename("dock_direction");
          context->AddVar(var_dock_direction,context);
        }
      }
      
      // Adding public member dock_layer
      boost::shared_ptr<int > var_dock_layer_ptr(&GetObj()->dock_layer, smartpointer_nodeleter<int >());
      if (var_dock_layer_ptr.get()) {
        BasicVariable::ptr var_dock_layer = AMILabType<int >::CreateVarFromSmtPtr(var_dock_layer_ptr);
        if (var_dock_layer.get()) {
          var_dock_layer->Rename("dock_layer");
          context->AddVar(var_dock_layer,context);
        }
      }
      
      // Adding public member dock_row
      boost::shared_ptr<int > var_dock_row_ptr(&GetObj()->dock_row, smartpointer_nodeleter<int >());
      if (var_dock_row_ptr.get()) {
        BasicVariable::ptr var_dock_row = AMILabType<int >::CreateVarFromSmtPtr(var_dock_row_ptr);
        if (var_dock_row.get()) {
          var_dock_row->Rename("dock_row");
          context->AddVar(var_dock_row,context);
        }
      }
      
      // Adding public member dock_pos
      boost::shared_ptr<int > var_dock_pos_ptr(&GetObj()->dock_pos, smartpointer_nodeleter<int >());
      if (var_dock_pos_ptr.get()) {
        BasicVariable::ptr var_dock_pos = AMILabType<int >::CreateVarFromSmtPtr(var_dock_pos_ptr);
        if (var_dock_pos.get()) {
          var_dock_pos->Rename("dock_pos");
          context->AddVar(var_dock_pos,context);
        }
      }
      
      // Adding public member best_size
      boost::shared_ptr<wxSize > var_best_size_ptr(&GetObj()->best_size, smartpointer_nodeleter<wxSize >());
      if (var_best_size_ptr.get()) {
        BasicVariable::ptr var_best_size = AMILabType<wxSize >::CreateVarFromSmtPtr(var_best_size_ptr);
        if (var_best_size.get()) {
          var_best_size->Rename("best_size");
          context->AddVar(var_best_size,context);
        }
      }
      
      // Adding public member min_size
      boost::shared_ptr<wxSize > var_min_size_ptr(&GetObj()->min_size, smartpointer_nodeleter<wxSize >());
      if (var_min_size_ptr.get()) {
        BasicVariable::ptr var_min_size = AMILabType<wxSize >::CreateVarFromSmtPtr(var_min_size_ptr);
        if (var_min_size.get()) {
          var_min_size->Rename("min_size");
          context->AddVar(var_min_size,context);
        }
      }
      
      // Adding public member max_size
      boost::shared_ptr<wxSize > var_max_size_ptr(&GetObj()->max_size, smartpointer_nodeleter<wxSize >());
      if (var_max_size_ptr.get()) {
        BasicVariable::ptr var_max_size = AMILabType<wxSize >::CreateVarFromSmtPtr(var_max_size_ptr);
        if (var_max_size.get()) {
          var_max_size->Rename("max_size");
          context->AddVar(var_max_size,context);
        }
      }
      
      // Adding public member floating_pos
      boost::shared_ptr<wxPoint > var_floating_pos_ptr(&GetObj()->floating_pos, smartpointer_nodeleter<wxPoint >());
      if (var_floating_pos_ptr.get()) {
        BasicVariable::ptr var_floating_pos = AMILabType<wxPoint >::CreateVarFromSmtPtr(var_floating_pos_ptr);
        if (var_floating_pos.get()) {
          var_floating_pos->Rename("floating_pos");
          context->AddVar(var_floating_pos,context);
        }
      }
      
      // Adding public member floating_size
      boost::shared_ptr<wxSize > var_floating_size_ptr(&GetObj()->floating_size, smartpointer_nodeleter<wxSize >());
      if (var_floating_size_ptr.get()) {
        BasicVariable::ptr var_floating_size = AMILabType<wxSize >::CreateVarFromSmtPtr(var_floating_size_ptr);
        if (var_floating_size.get()) {
          var_floating_size->Rename("floating_size");
          context->AddVar(var_floating_size,context);
        }
      }
      
      // Adding public member dock_proportion
      boost::shared_ptr<int > var_dock_proportion_ptr(&GetObj()->dock_proportion, smartpointer_nodeleter<int >());
      if (var_dock_proportion_ptr.get()) {
        BasicVariable::ptr var_dock_proportion = AMILabType<int >::CreateVarFromSmtPtr(var_dock_proportion_ptr);
        if (var_dock_proportion.get()) {
          var_dock_proportion->Rename("dock_proportion");
          context->AddVar(var_dock_proportion,context);
        }
      }
      
      /* type not available
      // Adding public member buttons
      boost::shared_ptr<wxAuiPaneButtonArray > var_buttons_ptr(&GetObj()->buttons, smartpointer_nodeleter<wxAuiPaneButtonArray >());
      if (var_buttons_ptr.get()) {
        BasicVariable::ptr var_buttons = AMILabType<wxAuiPaneButtonArray >::CreateVarFromSmtPtr(var_buttons_ptr);
        if (var_buttons.get()) {
          var_buttons->Rename("buttons");
          context->AddVar(var_buttons,context);
        }
      }
      */
      
      // Adding public member rect
      boost::shared_ptr<wxRect > var_rect_ptr(&GetObj()->rect, smartpointer_nodeleter<wxRect >());
      if (var_rect_ptr.get()) {
        BasicVariable::ptr var_rect = AMILabType<wxRect >::CreateVarFromSmtPtr(var_rect_ptr);
        if (var_rect.get()) {
          var_rect->Rename("rect");
          context->AddVar(var_rect,context);
        }
      }

};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxAuiPaneInfo::wxAuiPaneInfo()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_wxAuiPaneInfo_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_wxAuiPaneInfo_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxAuiPaneInfo* _newobj = new wxAuiPaneInfo();
  BasicVariable::ptr res = WrapClass_wxAuiPaneInfo::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxAuiPaneInfo::wxAuiPaneInfo(...)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_wxAuiPaneInfo::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_wxAuiPaneInfo::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiPaneInfo::wrap_wxAuiPaneInfo_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiPaneInfo::wrap_wxAuiPaneInfo_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxAuiPaneInfo::wxAuiPaneInfo(wxAuiPaneInfo const & c)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_wxAuiPaneInfo_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_wxAuiPaneInfo_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfo > c_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(c_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxAuiPaneInfo const & c = *c_smtptr;

  wxAuiPaneInfo* _newobj = new wxAuiPaneInfo(c);
  BasicVariable::ptr res = WrapClass_wxAuiPaneInfo::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxAuiPaneInfo.
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxAuiPaneInfo object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxAuiPaneInfo >::CreateVar( new wxAuiPaneInfo(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxAuiPaneInfo::SafeSet(wxAuiPaneInfo source)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_SafeSet::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'source'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_SafeSet::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxAuiPaneInfo source;
  if (!get_val_param<wxAuiPaneInfo >(source,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SafeSet(source);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::IsOk()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_IsOk::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_IsOk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOk();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::IsFixed()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_IsFixed::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_IsFixed::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsFixed();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::IsResizable()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_IsResizable::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_IsResizable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsResizable();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::IsShown()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_IsShown::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_IsShown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsShown();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::IsFloating()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_IsFloating::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_IsFloating::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsFloating();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::IsDocked()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_IsDocked::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_IsDocked::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsDocked();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::IsToolbar()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_IsToolbar::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_IsToolbar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsToolbar();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::IsTopDockable()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_IsTopDockable::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_IsTopDockable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsTopDockable();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::IsBottomDockable()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_IsBottomDockable::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_IsBottomDockable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsBottomDockable();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::IsLeftDockable()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_IsLeftDockable::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_IsLeftDockable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsLeftDockable();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::IsRightDockable()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_IsRightDockable::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_IsRightDockable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsRightDockable();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::IsFloatable()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_IsFloatable::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_IsFloatable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsFloatable();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::IsMovable()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_IsMovable::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_IsMovable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsMovable();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::IsDestroyOnClose()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_IsDestroyOnClose::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_IsDestroyOnClose::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsDestroyOnClose();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::IsMaximized()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_IsMaximized::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_IsMaximized::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsMaximized();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::HasCaption()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_HasCaption::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_HasCaption::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasCaption();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::HasGripper()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_HasGripper::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_HasGripper::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasGripper();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::HasBorder()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_HasBorder::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_HasBorder::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasBorder();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::HasCloseButton()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_HasCloseButton::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_HasCloseButton::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasCloseButton();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::HasMaximizeButton()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_HasMaximizeButton::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_HasMaximizeButton::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasMaximizeButton();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::HasMinimizeButton()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_HasMinimizeButton::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_HasMinimizeButton::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasMinimizeButton();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::HasPinButton()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_HasPinButton::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_HasPinButton::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasPinButton();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::HasGripperTop()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_HasGripperTop::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_HasGripperTop::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasGripperTop();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Window(wxWindow * w)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Window::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'w'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Window::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > w_smtptr;
  if (!get_val_smtptr_param<wxWindow >(w_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* w = w_smtptr.get();

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Window(w);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Name(wxString const & n)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Name::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'n'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Name::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > n_smtptr;
  if (!get_val_smtptr_param<wxString >(n_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & n = *n_smtptr;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Name(n);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Caption(wxString const & c)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Caption::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'c'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Caption::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > c_smtptr;
  if (!get_val_smtptr_param<wxString >(c_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & c = *c_smtptr;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Caption(c);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Left()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Left::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Left::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Left();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Right()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Right::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Right::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Right();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Top()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Top::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Top::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Top();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Bottom()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Bottom::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Bottom::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Bottom();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Center()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Center::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Center::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Center();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Centre()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Centre::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Centre::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Centre();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Direction(int direction)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Direction::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'direction'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Direction::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int direction;
  if (!get_val_param<int >(direction,_p,_n,true,false)) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Direction(direction);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Layer(int layer)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Layer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'layer'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Layer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int layer;
  if (!get_val_param<int >(layer,_p,_n,true,false)) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Layer(layer);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Row(int row)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Row::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'row'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Row::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int row;
  if (!get_val_param<int >(row,_p,_n,true,false)) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Row(row);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Position(int pos)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Position::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pos'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Position::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int pos;
  if (!get_val_param<int >(pos,_p,_n,true,false)) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Position(pos);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::BestSize(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_BestSize_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_BestSize_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->BestSize(size);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::MinSize(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_MinSize_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_MinSize_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->MinSize(size);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::MaxSize(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_MaxSize_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_MaxSize_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->MaxSize(size);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxAuiPaneInfo::BestSize(...)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_BestSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_BestSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiPaneInfo::wrap_BestSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiPaneInfo::wrap_BestSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::BestSize(int x, int y)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_BestSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_BestSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->BestSize(x, y);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxAuiPaneInfo::MinSize(...)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_MinSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_MinSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiPaneInfo::wrap_MinSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiPaneInfo::wrap_MinSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::MinSize(int x, int y)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_MinSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_MinSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->MinSize(x, y);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxAuiPaneInfo::MaxSize(...)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_MaxSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_MaxSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiPaneInfo::wrap_MaxSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiPaneInfo::wrap_MaxSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::MaxSize(int x, int y)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_MaxSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_MaxSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->MaxSize(x, y);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::FloatingPosition(wxPoint const & pos)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_FloatingPosition_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_FloatingPosition_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pos = *pos_smtptr;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->FloatingPosition(pos);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxAuiPaneInfo::FloatingPosition(...)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_FloatingPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_FloatingPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiPaneInfo::wrap_FloatingPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiPaneInfo::wrap_FloatingPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::FloatingPosition(int x, int y)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_FloatingPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_FloatingPosition_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->FloatingPosition(x, y);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::FloatingSize(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_FloatingSize_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_FloatingSize_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->FloatingSize(size);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxAuiPaneInfo::FloatingSize(...)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_FloatingSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_FloatingSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiPaneInfo::wrap_FloatingSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiPaneInfo::wrap_FloatingSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::FloatingSize(int x, int y)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_FloatingSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_FloatingSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->FloatingSize(x, y);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Fixed()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Fixed::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Fixed::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Fixed();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Resizable(bool resizable = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Resizable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'resizable' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Resizable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int resizable_int = ((true==true)?1:0);;
  if (!get_val_param<int >(resizable_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool resizable = (bool) (resizable_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Resizable(resizable);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Dock()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Dock::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Dock::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Dock();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Float()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Float::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Float::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Float();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Hide()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Hide::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Hide::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Hide();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Show(bool show = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Show::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'show' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Show::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int show_int = ((true==true)?1:0);;
  if (!get_val_param<int >(show_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool show = (bool) (show_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Show(show);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::CaptionVisible(bool visible = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_CaptionVisible::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'visible' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_CaptionVisible::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int visible_int = ((true==true)?1:0);;
  if (!get_val_param<int >(visible_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool visible = (bool) (visible_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->CaptionVisible(visible);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Maximize()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Maximize::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Maximize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Maximize();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Restore()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Restore::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Restore::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Restore();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::PaneBorder(bool visible = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_PaneBorder::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'visible' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_PaneBorder::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int visible_int = ((true==true)?1:0);;
  if (!get_val_param<int >(visible_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool visible = (bool) (visible_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->PaneBorder(visible);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Gripper(bool visible = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Gripper::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'visible' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Gripper::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int visible_int = ((true==true)?1:0);;
  if (!get_val_param<int >(visible_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool visible = (bool) (visible_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Gripper(visible);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::GripperTop(bool attop = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_GripperTop::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'attop' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_GripperTop::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int attop_int = ((true==true)?1:0);;
  if (!get_val_param<int >(attop_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool attop = (bool) (attop_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->GripperTop(attop);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::CloseButton(bool visible = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_CloseButton::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'visible' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_CloseButton::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int visible_int = ((true==true)?1:0);;
  if (!get_val_param<int >(visible_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool visible = (bool) (visible_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->CloseButton(visible);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::MaximizeButton(bool visible = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_MaximizeButton::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'visible' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_MaximizeButton::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int visible_int = ((true==true)?1:0);;
  if (!get_val_param<int >(visible_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool visible = (bool) (visible_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->MaximizeButton(visible);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::MinimizeButton(bool visible = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_MinimizeButton::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'visible' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_MinimizeButton::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int visible_int = ((true==true)?1:0);;
  if (!get_val_param<int >(visible_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool visible = (bool) (visible_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->MinimizeButton(visible);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::PinButton(bool visible = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_PinButton::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'visible' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_PinButton::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int visible_int = ((true==true)?1:0);;
  if (!get_val_param<int >(visible_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool visible = (bool) (visible_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->PinButton(visible);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::DestroyOnClose(bool b = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_DestroyOnClose::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_DestroyOnClose::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int b_int = ((true==true)?1:0);;
  if (!get_val_param<int >(b_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->DestroyOnClose(b);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::TopDockable(bool b = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_TopDockable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_TopDockable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int b_int = ((true==true)?1:0);;
  if (!get_val_param<int >(b_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->TopDockable(b);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::BottomDockable(bool b = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_BottomDockable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_BottomDockable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int b_int = ((true==true)?1:0);;
  if (!get_val_param<int >(b_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->BottomDockable(b);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::LeftDockable(bool b = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_LeftDockable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_LeftDockable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int b_int = ((true==true)?1:0);;
  if (!get_val_param<int >(b_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->LeftDockable(b);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::RightDockable(bool b = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_RightDockable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_RightDockable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int b_int = ((true==true)?1:0);;
  if (!get_val_param<int >(b_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->RightDockable(b);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Floatable(bool b = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Floatable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Floatable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int b_int = ((true==true)?1:0);;
  if (!get_val_param<int >(b_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Floatable(b);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Movable(bool b = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Movable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Movable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int b_int = ((true==true)?1:0);;
  if (!get_val_param<int >(b_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Movable(b);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::DockFixed(bool b = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_DockFixed::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_DockFixed::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int b_int = ((true==true)?1:0);;
  if (!get_val_param<int >(b_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->DockFixed(b);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Dockable(bool b = true)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Dockable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b' (def:true)")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Dockable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int b_int = ((true==true)?1:0);;
  if (!get_val_param<int >(b_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Dockable(b);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::DefaultPane()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_DefaultPane::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_DefaultPane::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->DefaultPane();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::CentrePane()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_CentrePane::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_CentrePane::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->CentrePane();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::CenterPane()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_CenterPane::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_CenterPane::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->CenterPane();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::ToolbarPane()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_ToolbarPane::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_ToolbarPane::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->ToolbarPane();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::SetFlag(unsigned int flag, bool option_state)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_SetFlag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flag'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'option_state'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_SetFlag::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long flag_long;
  if (!get_val_param<long >(flag_long,_p,_n,true,false)) ClassHelpAndReturn;
  unsigned int flag = boost::numeric_cast<unsigned int >(flag_long);

  int option_state_int;
  if (!get_val_param<int >(option_state_int,_p,_n,true,false)) ClassHelpAndReturn;
  bool option_state = (bool) (option_state_int>0.5);

  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->SetFlag(flag, option_state);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfo::HasFlag(unsigned int flag)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_HasFlag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flag'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_HasFlag::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long flag_long;
  if (!get_val_param<long >(flag_long,_p,_n,true,false)) ClassHelpAndReturn;
  unsigned int flag = boost::numeric_cast<unsigned int >(flag_long);

  bool res =   this->_objectptr->GetObj()->HasFlag(flag);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::operator =(wxAuiPaneInfo const & c)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'c'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfo > c_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(c_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiPaneInfo const & c = *c_smtptr;

  wxAuiPaneInfo & res =   (*this->_objectptr->GetObj()) = (c);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

