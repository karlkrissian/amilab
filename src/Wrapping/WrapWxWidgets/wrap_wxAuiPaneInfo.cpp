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

#include "wrap_wxAuiPaneInfo.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxAuiPaneInfo.h"
#include "wrap_wxWindow.h"
#include "wrap_wxString.h"
#include "wrap_wxSize.h"
#include "wrap_wxPoint.h"
#include "boost/numeric/conversion/cast.hpp"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAuiPaneInfo>::CreateVar( ParamList* p)
{
  WrapClass_wxAuiPaneInfo::wrap_wxAuiPaneInfo construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxAuiPaneInfo);

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

/*
//---------------------------------------------------
// Method that adds wrapping of wxAuiPaneInfo
//---------------------------------------------------

void WrapClass_wxAuiPaneInfo::
      wrap_wxAuiPaneInfo::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(..,"...");
  return_comments = "A wrapped wxAuiPaneInfo object.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
      wrap_wxAuiPaneInfo::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  // get parameters...
  wxAuiPaneInfo* owxAuiPaneInfo = new wxAuiPaneInfo(...); // constructor parameters ...
  BasicVariable::ptr res = WrapClass_wxAuiPaneInfo::CreateVar(owxAuiPaneInfo);
  return res;
}
*/


//---------------------------------------------------
//  Wrapping of Constructor wxAuiPaneInfo::wxAuiPaneInfo()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_wxAuiPaneInfo::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_wxAuiPaneInfo::CallMember( ParamList* _p)
{
  wxAuiPaneInfo* _newobj = new wxAuiPaneInfo();
  BasicVariable::ptr res = WrapClass_wxAuiPaneInfo::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxAuiPaneInfo::wxAuiPaneInfo(wxAuiPaneInfo & c)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_wxAuiPaneInfo1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_wxAuiPaneInfo1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxAuiPaneInfo* c_ptr;
  if (!get_val_ptr_param<wxAuiPaneInfo>(c_ptr,_p,_n)) ClassHelpAndReturn;
  wxAuiPaneInfo& c = *c_ptr;
  wxAuiPaneInfo* _newobj = new wxAuiPaneInfo(c);
  BasicVariable::ptr res = WrapClass_wxAuiPaneInfo::CreateVar(_newobj);
  return res;
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
  int _n=0;
  wxAuiPaneInfo source;
  if (!get_val_param<wxAuiPaneInfo>(source,_p,_n)) ClassHelpAndReturn;
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
  bool res =   this->_objectptr->GetObj()->IsOk();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->IsFixed();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->IsResizable();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->IsShown();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->IsFloating();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->IsDocked();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->IsToolbar();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->IsTopDockable();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->IsBottomDockable();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->IsLeftDockable();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->IsRightDockable();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->IsFloatable();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->IsMovable();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->IsDestroyOnClose();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->IsMaximized();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->HasCaption();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->HasGripper();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->HasBorder();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->HasCloseButton();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->HasMaximizeButton();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->HasMinimizeButton();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->HasPinButton();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  bool res =   this->_objectptr->GetObj()->HasGripperTop();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
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
  int _n=0;
  wxWindow* w;
  if (!get_val_ptr_param<wxWindow>(w,_p,_n)) ClassHelpAndReturn;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Window(w);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Name(wxString & n)
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
  int _n=0;
  wxString* n_ptr;
  if (!get_val_ptr_param<wxString>(n_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& n = *n_ptr;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Name(n);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Caption(wxString & c)
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
  int _n=0;
  wxString* c_ptr;
  if (!get_val_ptr_param<wxString>(c_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& c = *c_ptr;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Caption(c);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Left();
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Right();
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Top();
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Bottom();
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Center();
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Centre();
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  int _n=0;
  int direction;
  if (!get_val_param<int>(direction,_p,_n)) ClassHelpAndReturn;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Direction(direction);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  int _n=0;
  int layer;
  if (!get_val_param<int>(layer,_p,_n)) ClassHelpAndReturn;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Layer(layer);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  int _n=0;
  int row;
  if (!get_val_param<int>(row,_p,_n)) ClassHelpAndReturn;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Row(row);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  int _n=0;
  int pos;
  if (!get_val_param<int>(pos,_p,_n)) ClassHelpAndReturn;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Position(pos);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::BestSize(wxSize & size)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_BestSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_BestSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxSize* size_ptr;
  if (!get_val_ptr_param<wxSize>(size_ptr,_p,_n)) ClassHelpAndReturn;
  wxSize& size = *size_ptr;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->BestSize(size);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::MinSize(wxSize & size)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_MinSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_MinSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxSize* size_ptr;
  if (!get_val_ptr_param<wxSize>(size_ptr,_p,_n)) ClassHelpAndReturn;
  wxSize& size = *size_ptr;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->MinSize(size);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::MaxSize(wxSize & size)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_MaxSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_MaxSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxSize* size_ptr;
  if (!get_val_ptr_param<wxSize>(size_ptr,_p,_n)) ClassHelpAndReturn;
  wxSize& size = *size_ptr;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->MaxSize(size);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::BestSize(int x, int y)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_BestSize1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_BestSize1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int x;
  if (!get_val_param<int>(x,_p,_n)) ClassHelpAndReturn;
  int y;
  if (!get_val_param<int>(y,_p,_n)) ClassHelpAndReturn;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->BestSize(x, y);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::MinSize(int x, int y)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_MinSize1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_MinSize1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int x;
  if (!get_val_param<int>(x,_p,_n)) ClassHelpAndReturn;
  int y;
  if (!get_val_param<int>(y,_p,_n)) ClassHelpAndReturn;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->MinSize(x, y);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::MaxSize(int x, int y)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_MaxSize1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_MaxSize1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int x;
  if (!get_val_param<int>(x,_p,_n)) ClassHelpAndReturn;
  int y;
  if (!get_val_param<int>(y,_p,_n)) ClassHelpAndReturn;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->MaxSize(x, y);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::FloatingPosition(wxPoint & pos)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_FloatingPosition::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_FloatingPosition::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxPoint* pos_ptr;
  if (!get_val_ptr_param<wxPoint>(pos_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& pos = *pos_ptr;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->FloatingPosition(pos);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::FloatingPosition(int x, int y)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_FloatingPosition1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_FloatingPosition1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int x;
  if (!get_val_param<int>(x,_p,_n)) ClassHelpAndReturn;
  int y;
  if (!get_val_param<int>(y,_p,_n)) ClassHelpAndReturn;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->FloatingPosition(x, y);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::FloatingSize(wxSize & size)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_FloatingSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_FloatingSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxSize* size_ptr;
  if (!get_val_ptr_param<wxSize>(size_ptr,_p,_n)) ClassHelpAndReturn;
  wxSize& size = *size_ptr;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->FloatingSize(size);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::FloatingSize(int x, int y)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_FloatingSize1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_FloatingSize1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int x;
  if (!get_val_param<int>(x,_p,_n)) ClassHelpAndReturn;
  int y;
  if (!get_val_param<int>(y,_p,_n)) ClassHelpAndReturn;
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->FloatingSize(x, y);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Fixed();
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Resizable(bool resizable)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Resizable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'resizable'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Resizable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int resizable_int;
  if (!get_val_param<int>(resizable_int,_p,_n)) ClassHelpAndReturn;
  bool resizable = (bool) (resizable_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Resizable(resizable);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Dock();
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Float();
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Hide();
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Show(bool show)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Show::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'show'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Show::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int show_int;
  if (!get_val_param<int>(show_int,_p,_n)) ClassHelpAndReturn;
  bool show = (bool) (show_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Show(show);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::CaptionVisible(bool visible)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_CaptionVisible::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'visible'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_CaptionVisible::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int visible_int;
  if (!get_val_param<int>(visible_int,_p,_n)) ClassHelpAndReturn;
  bool visible = (bool) (visible_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->CaptionVisible(visible);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Maximize();
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Restore();
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::PaneBorder(bool visible)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_PaneBorder::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'visible'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_PaneBorder::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int visible_int;
  if (!get_val_param<int>(visible_int,_p,_n)) ClassHelpAndReturn;
  bool visible = (bool) (visible_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->PaneBorder(visible);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Gripper(bool visible)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Gripper::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'visible'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Gripper::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int visible_int;
  if (!get_val_param<int>(visible_int,_p,_n)) ClassHelpAndReturn;
  bool visible = (bool) (visible_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Gripper(visible);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::GripperTop(bool attop)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_GripperTop::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'attop'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_GripperTop::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int attop_int;
  if (!get_val_param<int>(attop_int,_p,_n)) ClassHelpAndReturn;
  bool attop = (bool) (attop_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->GripperTop(attop);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::CloseButton(bool visible)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_CloseButton::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'visible'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_CloseButton::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int visible_int;
  if (!get_val_param<int>(visible_int,_p,_n)) ClassHelpAndReturn;
  bool visible = (bool) (visible_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->CloseButton(visible);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::MaximizeButton(bool visible)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_MaximizeButton::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'visible'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_MaximizeButton::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int visible_int;
  if (!get_val_param<int>(visible_int,_p,_n)) ClassHelpAndReturn;
  bool visible = (bool) (visible_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->MaximizeButton(visible);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::MinimizeButton(bool visible)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_MinimizeButton::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'visible'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_MinimizeButton::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int visible_int;
  if (!get_val_param<int>(visible_int,_p,_n)) ClassHelpAndReturn;
  bool visible = (bool) (visible_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->MinimizeButton(visible);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::PinButton(bool visible)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_PinButton::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'visible'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_PinButton::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int visible_int;
  if (!get_val_param<int>(visible_int,_p,_n)) ClassHelpAndReturn;
  bool visible = (bool) (visible_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->PinButton(visible);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::DestroyOnClose(bool b)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_DestroyOnClose::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_DestroyOnClose::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int b_int;
  if (!get_val_param<int>(b_int,_p,_n)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->DestroyOnClose(b);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::TopDockable(bool b)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_TopDockable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_TopDockable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int b_int;
  if (!get_val_param<int>(b_int,_p,_n)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->TopDockable(b);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::BottomDockable(bool b)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_BottomDockable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_BottomDockable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int b_int;
  if (!get_val_param<int>(b_int,_p,_n)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->BottomDockable(b);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::LeftDockable(bool b)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_LeftDockable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_LeftDockable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int b_int;
  if (!get_val_param<int>(b_int,_p,_n)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->LeftDockable(b);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::RightDockable(bool b)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_RightDockable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_RightDockable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int b_int;
  if (!get_val_param<int>(b_int,_p,_n)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->RightDockable(b);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Floatable(bool b)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Floatable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Floatable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int b_int;
  if (!get_val_param<int>(b_int,_p,_n)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Floatable(b);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Movable(bool b)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Movable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Movable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int b_int;
  if (!get_val_param<int>(b_int,_p,_n)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Movable(b);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::DockFixed(bool b)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_DockFixed::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_DockFixed::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int b_int;
  if (!get_val_param<int>(b_int,_p,_n)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->DockFixed(b);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfo & wxAuiPaneInfo::Dockable(bool b)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfo::
    wrap_Dockable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfo::
    wrap_Dockable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int b_int;
  if (!get_val_param<int>(b_int,_p,_n)) ClassHelpAndReturn;
  bool b = (bool) (b_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->Dockable(b);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->DefaultPane();
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->CentrePane();
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->CenterPane();
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->ToolbarPane();
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  int _n=0;
  long flag_long;
  if (!get_val_param<long>(flag_long,_p,_n)) ClassHelpAndReturn;
  unsigned int flag = boost::numeric_cast<unsigned int>(flag_long);
  int option_state_int;
  if (!get_val_param<int>(option_state_int,_p,_n)) ClassHelpAndReturn;
  bool option_state = (bool) (option_state_int>0.5);
  wxAuiPaneInfo & res =   this->_objectptr->GetObj()->SetFlag(flag, option_state);
  return AMILabType<wxAuiPaneInfo>::CreateVar(res);
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
  int _n=0;
  long flag_long;
  if (!get_val_param<long>(flag_long,_p,_n)) ClassHelpAndReturn;
  unsigned int flag = boost::numeric_cast<unsigned int>(flag_long);
  bool res =   this->_objectptr->GetObj()->HasFlag(flag);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

