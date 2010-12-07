/**
 * C++ Interface: wrap_wxScrollHelper
 *
 * Description: wrapping wxScrollHelper
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
#include "wrap_wxPoint.h"
#include "wrap_wxScrollWinEvent.h"
#include "wrap_wxRect.h"
#include "wrap_wxDC.h"
#include "wrap_wxSizeEvent.h"
#include "wrap_wxPaintEvent.h"
#include "wrap_wxKeyEvent.h"
#include "wrap_wxMouseEvent.h"
#include "wrap_wxChildFocusEvent.h"


#include "wrap_wxScrollHelper.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxScrollHelper>::CreateVar( ParamList* p)
{
  WrapClass_wxScrollHelper::wrap_wxScrollHelper construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxScrollHelper);
AMI_DEFINE_VARFROMSMTPTR(wxScrollHelper);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxScrollHelper>::CreateVar( wxScrollHelper* val, bool nodeleter)
{ 
  boost::shared_ptr<wxScrollHelper> obj_ptr(val,smartpointer_nodeleter<wxScrollHelper>());
  return AMILabType<wxScrollHelper>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxScrollHelper
//
Variable<AMIObject>::ptr WrapClass_wxScrollHelper::CreateVar( wxScrollHelper* sp)
{
  boost::shared_ptr<wxScrollHelper> di_ptr(
    sp,
    wxwindow_nodeleter<wxScrollHelper>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxScrollHelper>::CreateVar(
      new WrapClass_wxScrollHelper(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxScrollHelper::AddMethods(WrapClass<wxScrollHelper>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding standard methods 
      AddVar_SetScrollbars( this_ptr);
      AddVar_Scroll( this_ptr);
      AddVar_GetScrollPageSize( this_ptr);
      AddVar_SetScrollPageSize( this_ptr);
      AddVar_GetScrollLines( this_ptr);
      AddVar_SetScrollRate( this_ptr);
      AddVar_GetScrollPixelsPerUnit( this_ptr);
      AddVar_EnableScrolling( this_ptr);
      AddVar_GetViewStart( this_ptr);
      AddVar_SetScale( this_ptr);
      AddVar_GetScaleX( this_ptr);
      AddVar_GetScaleY( this_ptr);
      AddVar_CalcScrolledPosition_1( this_ptr);
      AddVar_CalcScrolledPosition( this_ptr);
      AddVar_CalcScrolledPosition_2( this_ptr);
      AddVar_CalcUnscrolledPosition_1( this_ptr);
      AddVar_CalcUnscrolledPosition( this_ptr);
      AddVar_CalcUnscrolledPosition_2( this_ptr);
      AddVar_DoCalcScrolledPosition( this_ptr);
      AddVar_DoCalcUnscrolledPosition( this_ptr);
      AddVar_AdjustScrollbars( this_ptr);
      AddVar_CalcScrollInc( this_ptr);
      AddVar_SetTargetWindow( this_ptr);
      AddVar_GetTargetWindow( this_ptr);
      AddVar_SetTargetRect( this_ptr);
      AddVar_GetTargetRect( this_ptr);
      AddVar_OnDraw( this_ptr);
      AddVar_DoPrepareDC( this_ptr);
      AddVar_IsAutoScrolling( this_ptr);
      AddVar_StopAutoScrolling( this_ptr);
      AddVar_SendAutoScrollEvents( this_ptr);
      AddVar_HandleOnScroll( this_ptr);
      AddVar_HandleOnSize( this_ptr);
      AddVar_HandleOnPaint( this_ptr);
      AddVar_HandleOnChar( this_ptr);
      AddVar_HandleOnMouseEnter( this_ptr);
      AddVar_HandleOnMouseLeave( this_ptr);
      AddVar_HandleOnMouseWheel( this_ptr);
      AddVar_HandleOnChildFocus( this_ptr);
      AddVar_OnScroll( this_ptr);



  

  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxScrollHelper::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxScrollHelper");
    WrapClass_wxScrollHelper::AddVar_wxScrollHelper(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxScrollHelper::wxScrollHelper(wxWindow * winToScroll)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_wxScrollHelper::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'winToScroll'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_wxScrollHelper::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > winToScroll_smtptr;
  if (!get_val_smtptr_param<wxWindow >(winToScroll_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* winToScroll = winToScroll_smtptr.get();

  wxScrollHelper* _newobj = new wxScrollHelper(winToScroll);
  BasicVariable::ptr res = WrapClass_wxScrollHelper::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::SetScrollbars(int pixelsPerUnitX, int pixelsPerUnitY, int noUnitsX, int noUnitsY, int xPos = 0, int yPos = 0, bool noRefresh = false)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_SetScrollbars::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pixelsPerUnitX'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pixelsPerUnitY'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'noUnitsX'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'noUnitsY'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xPos' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yPos' (def:0)")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'noRefresh' (def:false)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_SetScrollbars::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  int pixelsPerUnitX;
  if (!get_val_param<int >(pixelsPerUnitX,_p,_n,true,false)) ClassHelpAndReturn;

  int pixelsPerUnitY;
  if (!get_val_param<int >(pixelsPerUnitY,_p,_n,true,false)) ClassHelpAndReturn;

  int noUnitsX;
  if (!get_val_param<int >(noUnitsX,_p,_n,true,false)) ClassHelpAndReturn;

  int noUnitsY;
  if (!get_val_param<int >(noUnitsY,_p,_n,true,false)) ClassHelpAndReturn;

  int xPos = 0;
  if (!get_val_param<int >(xPos,_p,_n,false,false)) ClassHelpAndReturn;

  int yPos = 0;
  if (!get_val_param<int >(yPos,_p,_n,false,false)) ClassHelpAndReturn;

  bool noRefresh = false;
  if (!get_val_param<bool >(noRefresh,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScrollbars(pixelsPerUnitX, pixelsPerUnitY, noUnitsX, noUnitsY, xPos, yPos, noRefresh);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::Scroll(int x, int y)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_Scroll::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_Scroll::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Scroll(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxScrollHelper::GetScrollPageSize(int orient)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_GetScrollPageSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orient'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_GetScrollPageSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int orient;
  if (!get_val_param<int >(orient,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetScrollPageSize(orient);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::SetScrollPageSize(int orient, int pageSize)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_SetScrollPageSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orient'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pageSize'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_SetScrollPageSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int orient;
  if (!get_val_param<int >(orient,_p,_n,true,false)) ClassHelpAndReturn;

  int pageSize;
  if (!get_val_param<int >(pageSize,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScrollPageSize(orient, pageSize);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxScrollHelper::GetScrollLines(int orient)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_GetScrollLines::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orient'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_GetScrollLines::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int orient;
  if (!get_val_param<int >(orient,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetScrollLines(orient);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::SetScrollRate(int xstep, int ystep)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_SetScrollRate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xstep'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ystep'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_SetScrollRate::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int xstep;
  if (!get_val_param<int >(xstep,_p,_n,true,false)) ClassHelpAndReturn;

  int ystep;
  if (!get_val_param<int >(ystep,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScrollRate(xstep, ystep);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::GetScrollPixelsPerUnit(int * pixelsPerUnitX, int * pixelsPerUnitY)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_GetScrollPixelsPerUnit::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pixelsPerUnitX'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pixelsPerUnitY'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_GetScrollPixelsPerUnit::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > pixelsPerUnitX_smtptr;
  if (!get_val_smtptr_param<int >(pixelsPerUnitX_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* pixelsPerUnitX = pixelsPerUnitX_smtptr.get();

  boost::shared_ptr<int > pixelsPerUnitY_smtptr;
  if (!get_val_smtptr_param<int >(pixelsPerUnitY_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* pixelsPerUnitY = pixelsPerUnitY_smtptr.get();

  this->_objectptr->GetObj()->GetScrollPixelsPerUnit(pixelsPerUnitX, pixelsPerUnitY);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::EnableScrolling(bool x_scrolling, bool y_scrolling)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_EnableScrolling::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'x_scrolling'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'y_scrolling'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_EnableScrolling::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  bool x_scrolling;
  if (!get_val_param<bool >(x_scrolling,_p,_n,true,false)) ClassHelpAndReturn;

  bool y_scrolling;
  if (!get_val_param<bool >(y_scrolling,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EnableScrolling(x_scrolling, y_scrolling);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::GetViewStart(int * x, int * y)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_GetViewStart::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_GetViewStart::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > x_smtptr;
  if (!get_val_smtptr_param<int >(x_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* x = x_smtptr.get();

  boost::shared_ptr<int > y_smtptr;
  if (!get_val_smtptr_param<int >(y_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* y = y_smtptr.get();

  this->_objectptr->GetObj()->GetViewStart(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::SetScale(double xs, double ys)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_SetScale::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'xs'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'ys'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_SetScale::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  double xs;
  if (!get_val_param<double >(xs,_p,_n,true,false)) ClassHelpAndReturn;

  double ys;
  if (!get_val_param<double >(ys,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScale(xs, ys);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double wxScrollHelper::GetScaleX()
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_GetScaleX::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_GetScaleX::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetScaleX();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double wxScrollHelper::GetScaleY()
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_GetScaleY::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_GetScaleY::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetScaleY();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::CalcScrolledPosition(int x, int y, int * xx, int * yy)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_CalcScrolledPosition_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_CalcScrolledPosition_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<int > xx_smtptr;
  if (!get_val_smtptr_param<int >(xx_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* xx = xx_smtptr.get();

  boost::shared_ptr<int > yy_smtptr;
  if (!get_val_smtptr_param<int >(yy_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* yy = yy_smtptr.get();

  this->_objectptr->GetObj()->CalcScrolledPosition(x, y, xx, yy);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxScrollHelper::CalcScrolledPosition(...)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_CalcScrolledPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_CalcScrolledPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxScrollHelper::wrap_CalcScrolledPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxScrollHelper::wrap_CalcScrolledPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxPoint wxScrollHelper::CalcScrolledPosition(wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_CalcScrolledPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_CalcScrolledPosition_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  wxPoint res =   this->_objectptr->GetObj()->CalcScrolledPosition(pt);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::CalcUnscrolledPosition(int x, int y, int * xx, int * yy)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_CalcUnscrolledPosition_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_CalcUnscrolledPosition_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<int > xx_smtptr;
  if (!get_val_smtptr_param<int >(xx_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* xx = xx_smtptr.get();

  boost::shared_ptr<int > yy_smtptr;
  if (!get_val_smtptr_param<int >(yy_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* yy = yy_smtptr.get();

  this->_objectptr->GetObj()->CalcUnscrolledPosition(x, y, xx, yy);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxScrollHelper::CalcUnscrolledPosition(...)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_CalcUnscrolledPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_CalcUnscrolledPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxScrollHelper::wrap_CalcUnscrolledPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxScrollHelper::wrap_CalcUnscrolledPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxPoint wxScrollHelper::CalcUnscrolledPosition(wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_CalcUnscrolledPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_CalcUnscrolledPosition_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  wxPoint res =   this->_objectptr->GetObj()->CalcUnscrolledPosition(pt);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::DoCalcScrolledPosition(int x, int y, int * xx, int * yy)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_DoCalcScrolledPosition::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_DoCalcScrolledPosition::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<int > xx_smtptr;
  if (!get_val_smtptr_param<int >(xx_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* xx = xx_smtptr.get();

  boost::shared_ptr<int > yy_smtptr;
  if (!get_val_smtptr_param<int >(yy_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* yy = yy_smtptr.get();

  this->_objectptr->GetObj()->DoCalcScrolledPosition(x, y, xx, yy);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::DoCalcUnscrolledPosition(int x, int y, int * xx, int * yy)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_DoCalcUnscrolledPosition::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_DoCalcUnscrolledPosition::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<int > xx_smtptr;
  if (!get_val_smtptr_param<int >(xx_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* xx = xx_smtptr.get();

  boost::shared_ptr<int > yy_smtptr;
  if (!get_val_smtptr_param<int >(yy_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* yy = yy_smtptr.get();

  this->_objectptr->GetObj()->DoCalcUnscrolledPosition(x, y, xx, yy);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::AdjustScrollbars()
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_AdjustScrollbars::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_AdjustScrollbars::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AdjustScrollbars();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxScrollHelper::CalcScrollInc(wxScrollWinEvent & event)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_CalcScrollInc::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScrollWinEvent, "parameter named 'event'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_CalcScrollInc::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxScrollWinEvent > event_smtptr;
  if (!get_val_smtptr_param<wxScrollWinEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxScrollWinEvent & event = *event_smtptr;

  int res =   this->_objectptr->GetObj()->CalcScrollInc(event);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::SetTargetWindow(wxWindow * target)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_SetTargetWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'target'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_SetTargetWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > target_smtptr;
  if (!get_val_smtptr_param<wxWindow >(target_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* target = target_smtptr.get();

  this->_objectptr->GetObj()->SetTargetWindow(target);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxScrollHelper::GetTargetWindow()
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_GetTargetWindow::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_GetTargetWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetTargetWindow();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::SetTargetRect(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_SetTargetRect::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_SetTargetRect::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRect const & rect = *rect_smtptr;

  this->_objectptr->GetObj()->SetTargetRect(rect);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxRect wxScrollHelper::GetTargetRect()
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_GetTargetRect::SetParametersComments()
{
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_GetTargetRect::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxRect res =   this->_objectptr->GetObj()->GetTargetRect();
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::OnDraw(wxDC & param0)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_OnDraw::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDC, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_OnDraw::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDC > param0_smtptr;
  if (!get_val_smtptr_param<wxDC >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDC & param0 = *param0_smtptr;

  this->_objectptr->GetObj()->OnDraw(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::DoPrepareDC(wxDC & dc)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_DoPrepareDC::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDC, "parameter named 'dc'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_DoPrepareDC::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDC > dc_smtptr;
  if (!get_val_smtptr_param<wxDC >(dc_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDC & dc = *dc_smtptr;

  this->_objectptr->GetObj()->DoPrepareDC(dc);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxScrollHelper::IsAutoScrolling()
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_IsAutoScrolling::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_IsAutoScrolling::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsAutoScrolling();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::StopAutoScrolling()
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_StopAutoScrolling::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_StopAutoScrolling::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StopAutoScrolling();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxScrollHelper::SendAutoScrollEvents(wxScrollWinEvent & event)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_SendAutoScrollEvents::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScrollWinEvent, "parameter named 'event'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_SendAutoScrollEvents::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxScrollWinEvent > event_smtptr;
  if (!get_val_smtptr_param<wxScrollWinEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxScrollWinEvent & event = *event_smtptr;

  bool res =   this->_objectptr->GetObj()->SendAutoScrollEvents(event);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::HandleOnScroll(wxScrollWinEvent & event)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_HandleOnScroll::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScrollWinEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_HandleOnScroll::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxScrollWinEvent > event_smtptr;
  if (!get_val_smtptr_param<wxScrollWinEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxScrollWinEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->HandleOnScroll(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::HandleOnSize(wxSizeEvent & event)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_HandleOnSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizeEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_HandleOnSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSizeEvent > event_smtptr;
  if (!get_val_smtptr_param<wxSizeEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSizeEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->HandleOnSize(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::HandleOnPaint(wxPaintEvent & event)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_HandleOnPaint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPaintEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_HandleOnPaint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPaintEvent > event_smtptr;
  if (!get_val_smtptr_param<wxPaintEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPaintEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->HandleOnPaint(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::HandleOnChar(wxKeyEvent & event)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_HandleOnChar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxKeyEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_HandleOnChar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxKeyEvent > event_smtptr;
  if (!get_val_smtptr_param<wxKeyEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxKeyEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->HandleOnChar(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::HandleOnMouseEnter(wxMouseEvent & event)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_HandleOnMouseEnter::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_HandleOnMouseEnter::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMouseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMouseEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMouseEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->HandleOnMouseEnter(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::HandleOnMouseLeave(wxMouseEvent & event)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_HandleOnMouseLeave::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_HandleOnMouseLeave::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMouseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMouseEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMouseEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->HandleOnMouseLeave(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::HandleOnMouseWheel(wxMouseEvent & event)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_HandleOnMouseWheel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_HandleOnMouseWheel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMouseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMouseEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMouseEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->HandleOnMouseWheel(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::HandleOnChildFocus(wxChildFocusEvent & event)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_HandleOnChildFocus::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxChildFocusEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_HandleOnChildFocus::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxChildFocusEvent > event_smtptr;
  if (!get_val_smtptr_param<wxChildFocusEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxChildFocusEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->HandleOnChildFocus(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelper::OnScroll(wxScrollWinEvent & event)
//---------------------------------------------------
void WrapClass_wxScrollHelper::
    wrap_OnScroll::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScrollWinEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelper::
    wrap_OnScroll::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxScrollWinEvent > event_smtptr;
  if (!get_val_smtptr_param<wxScrollWinEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxScrollWinEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnScroll(event);
  return BasicVariable::ptr();
}

