/**
 * C++ Interface: wrap_wxDCBase
 *
 * Description: wrapping wxDCBase
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
#include "wrap_wxDrawObject.h"
#include "wrap_wxColour.h"
#include "wrap_wxPoint.h"
#include "wrap_wxRect.h"
#include "wrap_wxSize.h"
#include "wrap_wxList.h"
#include "wrap_wxIcon.h"
#include "wrap_wxBitmap.h"
#include "wrap_wxString.h"
#include "wrap_wxDC.h"
#include "wrap_wxRegion.h"
#include "wrap_wxFont.h"
#include "wrap_wxArrayInt.h"
#include "wrap_wxBrush.h"
#include "wrap_wxPen.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxDCBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxDCBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxDCBase);
AMI_DEFINE_VARFROMSMTPTR(wxDCBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxDCBase>::CreateVar( wxDCBase* val, bool nodeleter)
{ 
  boost::shared_ptr<wxDCBase> obj_ptr(val,smartpointer_nodeleter<wxDCBase>());
  return AMILabType<wxDCBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxDCBase
//
Variable<AMIObject>::ptr WrapClass_wxDCBase::CreateVar( wxDCBase* sp)
{
  boost::shared_ptr<wxDCBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxDCBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxDCBase>::CreateVar(
      new WrapClass_wxDCBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxDCBase::AddMethods(WrapClass<wxDCBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding standard methods 
      AddVar_DrawObject( this_ptr);
      AddVar_FloodFill_1( this_ptr);
      AddVar_FloodFill( this_ptr);
      AddVar_FloodFill_2( this_ptr);
      AddVar_GradientFillConcentric_1( this_ptr);
      AddVar_GradientFillConcentric( this_ptr);
      AddVar_GradientFillConcentric_2( this_ptr);
      AddVar_GradientFillLinear( this_ptr);
      AddVar_GetPixel_1( this_ptr);
      AddVar_GetPixel( this_ptr);
      AddVar_GetPixel_2( this_ptr);
      AddVar_DrawLine_1( this_ptr);
      AddVar_DrawLine( this_ptr);
      AddVar_DrawLine_2( this_ptr);
      AddVar_CrossHair_1( this_ptr);
      AddVar_CrossHair( this_ptr);
      AddVar_CrossHair_2( this_ptr);
      AddVar_DrawArc_1( this_ptr);
      AddVar_DrawArc( this_ptr);
      AddVar_DrawArc_2( this_ptr);
      AddVar_DrawCheckMark_1( this_ptr);
      AddVar_DrawCheckMark( this_ptr);
      AddVar_DrawCheckMark_2( this_ptr);
      AddVar_DrawEllipticArc_1( this_ptr);
      AddVar_DrawEllipticArc( this_ptr);
      AddVar_DrawEllipticArc_2( this_ptr);
      AddVar_DrawPoint_1( this_ptr);
      AddVar_DrawPoint( this_ptr);
      AddVar_DrawPoint_2( this_ptr);
      AddVar_DrawLines_1( this_ptr);
      AddVar_DrawLines( this_ptr);
      AddVar_DrawLines_2( this_ptr);
      AddVar_DrawPolygon_1( this_ptr);
      AddVar_DrawPolygon( this_ptr);
      AddVar_DrawPolygon_2( this_ptr);
      AddVar_DrawPolyPolygon( this_ptr);
      AddVar_DrawRectangle_1( this_ptr);
      AddVar_DrawRectangle( this_ptr);
      AddVar_DrawRectangle_2( this_ptr);
      AddVar_DrawRectangle_3( this_ptr);
      AddVar_DrawRoundedRectangle_1( this_ptr);
      AddVar_DrawRoundedRectangle( this_ptr);
      AddVar_DrawRoundedRectangle_2( this_ptr);
      AddVar_DrawRoundedRectangle_3( this_ptr);
      AddVar_DrawCircle_1( this_ptr);
      AddVar_DrawCircle( this_ptr);
      AddVar_DrawCircle_2( this_ptr);
      AddVar_DrawEllipse_1( this_ptr);
      AddVar_DrawEllipse( this_ptr);
      AddVar_DrawEllipse_2( this_ptr);
      AddVar_DrawEllipse_3( this_ptr);
      AddVar_DrawIcon_1( this_ptr);
      AddVar_DrawIcon( this_ptr);
      AddVar_DrawIcon_2( this_ptr);
      AddVar_DrawBitmap_1( this_ptr);
      AddVar_DrawBitmap( this_ptr);
      AddVar_DrawBitmap_2( this_ptr);
      AddVar_DrawText_1( this_ptr);
      AddVar_DrawText( this_ptr);
      AddVar_DrawText_2( this_ptr);
      AddVar_DrawRotatedText_1( this_ptr);
      AddVar_DrawRotatedText( this_ptr);
      AddVar_DrawRotatedText_2( this_ptr);
      AddVar_DrawLabel_1( this_ptr);
      AddVar_DrawLabel( this_ptr);
      AddVar_DrawLabel_2( this_ptr);
      AddVar_Blit_1( this_ptr);
      AddVar_Blit( this_ptr);
      AddVar_Blit_2( this_ptr);
      AddVar_GetAsBitmap( this_ptr);
      AddVar_DrawSpline_1( this_ptr);
      AddVar_DrawSpline( this_ptr);
      AddVar_DrawSpline_2( this_ptr);
      AddVar_DrawSpline_3( this_ptr);
      AddVar_StartDoc( this_ptr);
      AddVar_EndDoc( this_ptr);
      AddVar_StartPage( this_ptr);
      AddVar_EndPage( this_ptr);
      AddVar_SetClippingRegion_1( this_ptr);
      AddVar_SetClippingRegion( this_ptr);
      AddVar_SetClippingRegion_2( this_ptr);
      AddVar_SetClippingRegion_3( this_ptr);
      AddVar_SetClippingRegion_4( this_ptr);
      AddVar_SetDeviceClippingRegion( this_ptr);
      AddVar_DestroyClippingRegion( this_ptr);
      AddVar_GetClippingBox_1( this_ptr);
      AddVar_GetClippingBox( this_ptr);
      AddVar_GetClippingBox_2( this_ptr);
      AddVar_GetTextExtent_1( this_ptr);
      AddVar_GetTextExtent( this_ptr);
      AddVar_GetTextExtent_2( this_ptr);
      AddVar_GetMultiLineTextExtent_1( this_ptr);
      AddVar_GetMultiLineTextExtent( this_ptr);
      AddVar_GetMultiLineTextExtent_2( this_ptr);
      AddVar_GetPartialTextExtents( this_ptr);
      AddVar_GetSize_1( this_ptr);
      AddVar_GetSize( this_ptr);
      AddVar_GetSize_2( this_ptr);
      AddVar_GetSizeMM_1( this_ptr);
      AddVar_GetSizeMM( this_ptr);
      AddVar_GetSizeMM_2( this_ptr);
      AddVar_DeviceToLogicalX( this_ptr);
      AddVar_DeviceToLogicalY( this_ptr);
      AddVar_DeviceToLogicalXRel( this_ptr);
      AddVar_DeviceToLogicalYRel( this_ptr);
      AddVar_LogicalToDeviceX( this_ptr);
      AddVar_LogicalToDeviceY( this_ptr);
      AddVar_LogicalToDeviceXRel( this_ptr);
      AddVar_LogicalToDeviceYRel( this_ptr);
      AddVar_Ok( this_ptr);
      AddVar_IsOk( this_ptr);
      AddVar_GetBackgroundMode( this_ptr);
      AddVar_GetBackground( this_ptr);
      AddVar_GetBrush( this_ptr);
      AddVar_GetFont( this_ptr);
      AddVar_GetPen( this_ptr);
      AddVar_GetTextForeground( this_ptr);
      AddVar_GetTextBackground( this_ptr);
      AddVar_SetTextForeground( this_ptr);
      AddVar_SetTextBackground( this_ptr);
      AddVar_GetMapMode( this_ptr);
      AddVar_GetUserScale( this_ptr);
      AddVar_GetLogicalScale( this_ptr);
      AddVar_SetLogicalScale( this_ptr);
      AddVar_GetLogicalOrigin_1( this_ptr);
      AddVar_GetLogicalOrigin( this_ptr);
      AddVar_GetLogicalOrigin_2( this_ptr);
      AddVar_GetDeviceOrigin_1( this_ptr);
      AddVar_GetDeviceOrigin( this_ptr);
      AddVar_GetDeviceOrigin_2( this_ptr);
      AddVar_ComputeScaleAndOrigin( this_ptr);
      AddVar_GetLogicalFunction( this_ptr);
      AddVar_CalcBoundingBox( this_ptr);
      AddVar_ResetBoundingBox( this_ptr);
      AddVar_MinX( this_ptr);
      AddVar_MaxX( this_ptr);
      AddVar_MinY( this_ptr);
      AddVar_MaxY( this_ptr);
      AddVar_GetTextExtent_3( this_ptr);
      AddVar_GetLogicalOrigin_3( this_ptr);
      AddVar_GetDeviceOrigin_3( this_ptr);
      AddVar_GetClippingBox_3( this_ptr);
      AddVar_GetLayoutDirection( this_ptr);
      AddVar_SetLayoutDirection( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  

  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxObject
  boost::shared_ptr<wxObject > parent_wxObject(  boost::dynamic_pointer_cast<wxObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxObject = AMILabType<wxObject >::CreateVarFromSmtPtr(parent_wxObject);
  context->AddVar("wxObject",var_wxObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxObject);
  context->AddDefault(obj_wxObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxDCBase::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxDCBase");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawObject(wxDrawObject * drawobject)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawObject::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDrawObject, "parameter named 'drawobject'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawObject::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDrawObject > drawobject_smtptr;
  if (!get_val_smtptr_param<wxDrawObject >(drawobject_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDrawObject* drawobject = drawobject_smtptr.get();

  this->_objectptr->GetObj()->DrawObject(drawobject);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxDCBase::FloodFill(wxCoord x, wxCoord y, wxColour const & col, int style = wxFLOOD_SURFACE)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_FloodFill_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'col'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'style' (def:wxFLOOD_SURFACE)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_FloodFill_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxColour > col_smtptr;
  if (!get_val_smtptr_param<wxColour >(col_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxColour const & col = *col_smtptr;

  int style = wxFLOOD_SURFACE;
  if (!get_val_param<int >(style,_p,_n,false,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->FloodFill(x, y, col, style);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::FloodFill(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_FloodFill::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_FloodFill::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_FloodFill_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_FloodFill_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxDCBase::FloodFill(wxPoint const & pt, wxColour const & col, int style = wxFLOOD_SURFACE)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_FloodFill_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'col'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'style' (def:wxFLOOD_SURFACE)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_FloodFill_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  boost::shared_ptr<wxColour > col_smtptr;
  if (!get_val_smtptr_param<wxColour >(col_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxColour const & col = *col_smtptr;

  int style = wxFLOOD_SURFACE;
  if (!get_val_param<int >(style,_p,_n,false,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->FloodFill(pt, col, style);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GradientFillConcentric(wxRect const & rect, wxColour const & initialColour, wxColour const & destColour)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GradientFillConcentric_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'initialColour'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'destColour'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GradientFillConcentric_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  boost::shared_ptr<wxColour > initialColour_smtptr;
  if (!get_val_smtptr_param<wxColour >(initialColour_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxColour const & initialColour = *initialColour_smtptr;

  boost::shared_ptr<wxColour > destColour_smtptr;
  if (!get_val_smtptr_param<wxColour >(destColour_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxColour const & destColour = *destColour_smtptr;

  this->_objectptr->GetObj()->GradientFillConcentric(rect, initialColour, destColour);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::GradientFillConcentric(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GradientFillConcentric::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GradientFillConcentric::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_GradientFillConcentric_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_GradientFillConcentric_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GradientFillConcentric(wxRect const & rect, wxColour const & initialColour, wxColour const & destColour, wxPoint const & circleCenter)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GradientFillConcentric_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'initialColour'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'destColour'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'circleCenter'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GradientFillConcentric_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  boost::shared_ptr<wxColour > initialColour_smtptr;
  if (!get_val_smtptr_param<wxColour >(initialColour_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxColour const & initialColour = *initialColour_smtptr;

  boost::shared_ptr<wxColour > destColour_smtptr;
  if (!get_val_smtptr_param<wxColour >(destColour_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxColour const & destColour = *destColour_smtptr;

  boost::shared_ptr<wxPoint > circleCenter_smtptr;
  if (!get_val_smtptr_param<wxPoint >(circleCenter_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & circleCenter = *circleCenter_smtptr;

  this->_objectptr->GetObj()->GradientFillConcentric(rect, initialColour, destColour, circleCenter);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GradientFillLinear(wxRect const & rect, wxColour const & initialColour, wxColour const & destColour, wxDirection nDirection = wxRIGHT)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GradientFillLinear::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'initialColour'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'destColour'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'nDirection' (def:wxRIGHT)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GradientFillLinear::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRect const & rect = *rect_smtptr;

  boost::shared_ptr<wxColour > initialColour_smtptr;
  if (!get_val_smtptr_param<wxColour >(initialColour_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour const & initialColour = *initialColour_smtptr;

  boost::shared_ptr<wxColour > destColour_smtptr;
  if (!get_val_smtptr_param<wxColour >(destColour_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour const & destColour = *destColour_smtptr;

  int nDirection_int = (int) wxRIGHT;;
  if (!get_val_param<int >(nDirection_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDirection nDirection = (wxDirection) nDirection_int;

  this->_objectptr->GetObj()->GradientFillLinear(rect, initialColour, destColour, nDirection);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxDCBase::GetPixel(wxCoord x, wxCoord y, wxColour * col)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetPixel_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'col'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetPixel_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxColour > col_smtptr;
  if (!get_val_smtptr_param<wxColour >(col_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxColour* col = col_smtptr.get();

  bool res =   this->_objectptr->GetObj()->GetPixel(x, y, col);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::GetPixel(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetPixel::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetPixel::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_GetPixel_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_GetPixel_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxDCBase::GetPixel(wxPoint const & pt, wxColour * col)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetPixel_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'col'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetPixel_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  boost::shared_ptr<wxColour > col_smtptr;
  if (!get_val_smtptr_param<wxColour >(col_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxColour* col = col_smtptr.get();

  bool res =   this->_objectptr->GetObj()->GetPixel(pt, col);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawLine(wxCoord x1, wxCoord y1, wxCoord x2, wxCoord y2)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawLine_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawLine_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int x1;
  if (!get_val_param<int >(x1,_p,_n,true,true)) ClassReturnEmptyVar;

  int y1;
  if (!get_val_param<int >(y1,_p,_n,true,true)) ClassReturnEmptyVar;

  int x2;
  if (!get_val_param<int >(x2,_p,_n,true,true)) ClassReturnEmptyVar;

  int y2;
  if (!get_val_param<int >(y2,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawLine(x1, y1, x2, y2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawLine(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawLine::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawLine::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawLine_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawLine_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawLine(wxPoint const & pt1, wxPoint const & pt2)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawLine_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt1'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawLine_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt1_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt1 = *pt1_smtptr;

  boost::shared_ptr<wxPoint > pt2_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt2 = *pt2_smtptr;

  this->_objectptr->GetObj()->DrawLine(pt1, pt2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::CrossHair(wxCoord x, wxCoord y)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_CrossHair_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_CrossHair_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->CrossHair(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::CrossHair(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_CrossHair::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_CrossHair::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_CrossHair_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_CrossHair_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::CrossHair(wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_CrossHair_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_CrossHair_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  this->_objectptr->GetObj()->CrossHair(pt);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawArc(wxCoord x1, wxCoord y1, wxCoord x2, wxCoord y2, wxCoord xc, wxCoord yc)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawArc_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xc'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yc'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawArc_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  int x1;
  if (!get_val_param<int >(x1,_p,_n,true,true)) ClassReturnEmptyVar;

  int y1;
  if (!get_val_param<int >(y1,_p,_n,true,true)) ClassReturnEmptyVar;

  int x2;
  if (!get_val_param<int >(x2,_p,_n,true,true)) ClassReturnEmptyVar;

  int y2;
  if (!get_val_param<int >(y2,_p,_n,true,true)) ClassReturnEmptyVar;

  int xc;
  if (!get_val_param<int >(xc,_p,_n,true,true)) ClassReturnEmptyVar;

  int yc;
  if (!get_val_param<int >(yc,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawArc(x1, y1, x2, y2, xc, yc);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawArc(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawArc::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawArc::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawArc_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawArc_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawArc(wxPoint const & pt1, wxPoint const & pt2, wxPoint const & centre)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawArc_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt1'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt2'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'centre'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawArc_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt1_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt1 = *pt1_smtptr;

  boost::shared_ptr<wxPoint > pt2_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt2 = *pt2_smtptr;

  boost::shared_ptr<wxPoint > centre_smtptr;
  if (!get_val_smtptr_param<wxPoint >(centre_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & centre = *centre_smtptr;

  this->_objectptr->GetObj()->DrawArc(pt1, pt2, centre);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawCheckMark(wxCoord x, wxCoord y, wxCoord width, wxCoord height)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawCheckMark_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawCheckMark_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,true)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawCheckMark(x, y, width, height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawCheckMark(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawCheckMark::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawCheckMark::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawCheckMark_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawCheckMark_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawCheckMark(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawCheckMark_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawCheckMark_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  this->_objectptr->GetObj()->DrawCheckMark(rect);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawEllipticArc(wxCoord x, wxCoord y, wxCoord w, wxCoord h, double sa, double ea)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawEllipticArc_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'sa'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'ea'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawEllipticArc_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  int w;
  if (!get_val_param<int >(w,_p,_n,true,true)) ClassReturnEmptyVar;

  int h;
  if (!get_val_param<int >(h,_p,_n,true,true)) ClassReturnEmptyVar;

  double sa;
  if (!get_val_param<double >(sa,_p,_n,true,true)) ClassReturnEmptyVar;

  double ea;
  if (!get_val_param<double >(ea,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawEllipticArc(x, y, w, h, sa, ea);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawEllipticArc(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawEllipticArc::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawEllipticArc::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawEllipticArc_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawEllipticArc_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawEllipticArc(wxPoint const & pt, wxSize const & sz, double sa, double ea)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawEllipticArc_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'sa'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'ea'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawEllipticArc_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  boost::shared_ptr<wxSize > sz_smtptr;
  if (!get_val_smtptr_param<wxSize >(sz_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & sz = *sz_smtptr;

  double sa;
  if (!get_val_param<double >(sa,_p,_n,true,true)) ClassReturnEmptyVar;

  double ea;
  if (!get_val_param<double >(ea,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawEllipticArc(pt, sz, sa, ea);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawPoint(wxCoord x, wxCoord y)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawPoint(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawPoint(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawPoint(wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  this->_objectptr->GetObj()->DrawPoint(pt);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawLines(int n, wxPoint * points, wxCoord xoffset = 0, wxCoord yoffset = 0)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawLines_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'points'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xoffset' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yoffset' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawLines_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxPoint > points_smtptr;
  if (!get_val_smtptr_param<wxPoint >(points_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint* points = points_smtptr.get();

  int xoffset = 0;
  if (!get_val_param<int >(xoffset,_p,_n,false,true)) ClassReturnEmptyVar;

  int yoffset = 0;
  if (!get_val_param<int >(yoffset,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawLines(n, points, xoffset, yoffset);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawLines(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawLines::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawLines::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawLines_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawLines_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawLines(wxList const * list, wxCoord xoffset = 0, wxCoord yoffset = 0)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawLines_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxList, "parameter named 'list'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xoffset' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yoffset' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawLines_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxList > list_smtptr;
  if (!get_val_smtptr_param<wxList >(list_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxList* list = list_smtptr.get();

  int xoffset = 0;
  if (!get_val_param<int >(xoffset,_p,_n,false,true)) ClassReturnEmptyVar;

  int yoffset = 0;
  if (!get_val_param<int >(yoffset,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawLines(list, xoffset, yoffset);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawPolygon(int n, wxPoint * points, wxCoord xoffset = 0, wxCoord yoffset = 0, int fillStyle = wxODDEVEN_RULE)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawPolygon_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'points'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xoffset' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yoffset' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'fillStyle' (def:wxODDEVEN_RULE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawPolygon_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxPoint > points_smtptr;
  if (!get_val_smtptr_param<wxPoint >(points_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint* points = points_smtptr.get();

  int xoffset = 0;
  if (!get_val_param<int >(xoffset,_p,_n,false,true)) ClassReturnEmptyVar;

  int yoffset = 0;
  if (!get_val_param<int >(yoffset,_p,_n,false,true)) ClassReturnEmptyVar;

  int fillStyle = wxODDEVEN_RULE;
  if (!get_val_param<int >(fillStyle,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawPolygon(n, points, xoffset, yoffset, fillStyle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawPolygon(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawPolygon::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawPolygon::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawPolygon_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawPolygon_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawPolygon(wxList const * list, wxCoord xoffset = 0, wxCoord yoffset = 0, int fillStyle = wxODDEVEN_RULE)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawPolygon_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxList, "parameter named 'list'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xoffset' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yoffset' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'fillStyle' (def:wxODDEVEN_RULE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawPolygon_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxList > list_smtptr;
  if (!get_val_smtptr_param<wxList >(list_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxList* list = list_smtptr.get();

  int xoffset = 0;
  if (!get_val_param<int >(xoffset,_p,_n,false,true)) ClassReturnEmptyVar;

  int yoffset = 0;
  if (!get_val_param<int >(yoffset,_p,_n,false,true)) ClassReturnEmptyVar;

  int fillStyle = wxODDEVEN_RULE;
  if (!get_val_param<int >(fillStyle,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawPolygon(list, xoffset, yoffset, fillStyle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawPolyPolygon(int n, int * count, wxPoint * points, wxCoord xoffset = 0, wxCoord yoffset = 0, int fillStyle = wxODDEVEN_RULE)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawPolyPolygon::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'count'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'points'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xoffset' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yoffset' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'fillStyle' (def:wxODDEVEN_RULE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawPolyPolygon::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<int > count_smtptr;
  if (!get_val_smtptr_param<int >(count_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* count = count_smtptr.get();

  boost::shared_ptr<wxPoint > points_smtptr;
  if (!get_val_smtptr_param<wxPoint >(points_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint* points = points_smtptr.get();

  int xoffset = 0;
  if (!get_val_param<int >(xoffset,_p,_n,false,false)) ClassHelpAndReturn;

  int yoffset = 0;
  if (!get_val_param<int >(yoffset,_p,_n,false,false)) ClassHelpAndReturn;

  int fillStyle = wxODDEVEN_RULE;
  if (!get_val_param<int >(fillStyle,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DrawPolyPolygon(n, count, points, xoffset, yoffset, fillStyle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawRectangle(wxCoord x, wxCoord y, wxCoord width, wxCoord height)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawRectangle_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawRectangle_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,true)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawRectangle(x, y, width, height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawRectangle(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawRectangle::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawRectangle::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawRectangle_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawRectangle_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawRectangle_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawRectangle(wxPoint const & pt, wxSize const & sz)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawRectangle_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawRectangle_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  boost::shared_ptr<wxSize > sz_smtptr;
  if (!get_val_smtptr_param<wxSize >(sz_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & sz = *sz_smtptr;

  this->_objectptr->GetObj()->DrawRectangle(pt, sz);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawRectangle(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawRectangle_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawRectangle_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  this->_objectptr->GetObj()->DrawRectangle(rect);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawRoundedRectangle(wxCoord x, wxCoord y, wxCoord width, wxCoord height, double radius)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawRoundedRectangle_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'radius'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawRoundedRectangle_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,true)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,true)) ClassReturnEmptyVar;

  double radius;
  if (!get_val_param<double >(radius,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawRoundedRectangle(x, y, width, height, radius);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawRoundedRectangle(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawRoundedRectangle::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawRoundedRectangle::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawRoundedRectangle_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawRoundedRectangle_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawRoundedRectangle_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawRoundedRectangle(wxPoint const & pt, wxSize const & sz, double radius)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawRoundedRectangle_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'radius'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawRoundedRectangle_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  boost::shared_ptr<wxSize > sz_smtptr;
  if (!get_val_smtptr_param<wxSize >(sz_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & sz = *sz_smtptr;

  double radius;
  if (!get_val_param<double >(radius,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawRoundedRectangle(pt, sz, radius);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawRoundedRectangle(wxRect const & r, double radius)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawRoundedRectangle_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'radius'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawRoundedRectangle_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > r_smtptr;
  if (!get_val_smtptr_param<wxRect >(r_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & r = *r_smtptr;

  double radius;
  if (!get_val_param<double >(radius,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawRoundedRectangle(r, radius);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawCircle(wxCoord x, wxCoord y, wxCoord radius)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawCircle_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'radius'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawCircle_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  int radius;
  if (!get_val_param<int >(radius,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawCircle(x, y, radius);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawCircle(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawCircle::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawCircle::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawCircle_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawCircle_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawCircle(wxPoint const & pt, wxCoord radius)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawCircle_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'radius'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawCircle_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  int radius;
  if (!get_val_param<int >(radius,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawCircle(pt, radius);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawEllipse(wxCoord x, wxCoord y, wxCoord width, wxCoord height)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawEllipse_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawEllipse_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,true)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawEllipse(x, y, width, height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawEllipse(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawEllipse::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawEllipse::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawEllipse_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawEllipse_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawEllipse_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawEllipse(wxPoint const & pt, wxSize const & sz)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawEllipse_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawEllipse_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  boost::shared_ptr<wxSize > sz_smtptr;
  if (!get_val_smtptr_param<wxSize >(sz_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & sz = *sz_smtptr;

  this->_objectptr->GetObj()->DrawEllipse(pt, sz);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawEllipse(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawEllipse_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawEllipse_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  this->_objectptr->GetObj()->DrawEllipse(rect);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawIcon(wxIcon const & icon, wxCoord x, wxCoord y)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawIcon_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIcon, "parameter named 'icon'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawIcon_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxIcon > icon_smtptr;
  if (!get_val_smtptr_param<wxIcon >(icon_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxIcon const & icon = *icon_smtptr;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawIcon(icon, x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawIcon(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawIcon::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawIcon::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawIcon_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawIcon_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawIcon(wxIcon const & icon, wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawIcon_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIcon, "parameter named 'icon'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawIcon_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxIcon > icon_smtptr;
  if (!get_val_smtptr_param<wxIcon >(icon_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxIcon const & icon = *icon_smtptr;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  this->_objectptr->GetObj()->DrawIcon(icon, pt);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawBitmap(wxBitmap const & bmp, wxCoord x, wxCoord y, bool useMask = false)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawBitmap_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmp'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'useMask' (def:false)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawBitmap_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmap > bmp_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmp_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bmp = *bmp_smtptr;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  bool useMask = false;
  if (!get_val_param<bool >(useMask,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawBitmap(bmp, x, y, useMask);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawBitmap(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawBitmap::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawBitmap::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawBitmap_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawBitmap_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawBitmap(wxBitmap const & bmp, wxPoint const & pt, bool useMask = false)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawBitmap_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmp'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'useMask' (def:false)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawBitmap_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmap > bmp_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmp_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bmp = *bmp_smtptr;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  bool useMask = false;
  if (!get_val_param<bool >(useMask,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawBitmap(bmp, pt, useMask);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawText(wxString const & text, wxCoord x, wxCoord y)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawText_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawText_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & text = *text_smtptr;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawText(text, x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawText(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawText::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawText::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawText_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawText_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawText(wxString const & text, wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawText_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawText_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  this->_objectptr->GetObj()->DrawText(text, pt);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawRotatedText(wxString const & text, wxCoord x, wxCoord y, double angle)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawRotatedText_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawRotatedText_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & text = *text_smtptr;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  double angle;
  if (!get_val_param<double >(angle,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawRotatedText(text, x, y, angle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawRotatedText(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawRotatedText::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawRotatedText::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawRotatedText_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawRotatedText_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawRotatedText(wxString const & text, wxPoint const & pt, double angle)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawRotatedText_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawRotatedText_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  double angle;
  if (!get_val_param<double >(angle,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawRotatedText(text, pt, angle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawLabel(wxString const & text, wxBitmap const & image, wxRect const & rect, int alignment = 0, int indexAccel = -0x00000000000000001, wxRect * rectBounding = 0l)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawLabel_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'image'")
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'alignment' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'indexAccel' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rectBounding' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawLabel_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxBitmap > image_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(image_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & image = *image_smtptr;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  int alignment = 0;
  if (!get_val_param<int >(alignment,_p,_n,false,true)) ClassReturnEmptyVar;

  int indexAccel = -0x00000000000000001;
  if (!get_val_param<int >(indexAccel,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxRect > rectBounding_smtptr;
  if (!get_val_smtptr_param<wxRect >(rectBounding_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect* rectBounding = rectBounding_smtptr.get();

  this->_objectptr->GetObj()->DrawLabel(text, image, rect, alignment, indexAccel, rectBounding);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawLabel(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawLabel::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawLabel::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawLabel_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawLabel_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawLabel(wxString const & text, wxRect const & rect, int alignment = 0, int indexAccel = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawLabel_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'alignment' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'indexAccel' (def:-0x00000000000000001)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawLabel_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  int alignment = 0;
  if (!get_val_param<int >(alignment,_p,_n,false,true)) ClassReturnEmptyVar;

  int indexAccel = -0x00000000000000001;
  if (!get_val_param<int >(indexAccel,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawLabel(text, rect, alignment, indexAccel);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxDCBase::Blit(wxCoord xdest, wxCoord ydest, wxCoord width, wxCoord height, wxDC * source, wxCoord xsrc, wxCoord ysrc, int rop = wxCOPY, bool useMask = false, wxCoord xsrcMask = wxDefaultCoord, wxCoord ysrcMask = wxDefaultCoord)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_Blit_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xdest'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ydest'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( wxDC, "parameter named 'source'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xsrc'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ysrc'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'rop' (def:wxCOPY)")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'useMask' (def:false)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xsrcMask' (def:wxDefaultCoord)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ysrcMask' (def:wxDefaultCoord)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_Blit_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>11) ClassReturnEmptyVar;
  int _n=0;

  int xdest;
  if (!get_val_param<int >(xdest,_p,_n,true,true)) ClassReturnEmptyVar;

  int ydest;
  if (!get_val_param<int >(ydest,_p,_n,true,true)) ClassReturnEmptyVar;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,true)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxDC > source_smtptr;
  if (!get_val_smtptr_param<wxDC >(source_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDC* source = source_smtptr.get();

  int xsrc;
  if (!get_val_param<int >(xsrc,_p,_n,true,true)) ClassReturnEmptyVar;

  int ysrc;
  if (!get_val_param<int >(ysrc,_p,_n,true,true)) ClassReturnEmptyVar;

  int rop = wxCOPY;
  if (!get_val_param<int >(rop,_p,_n,false,true)) ClassReturnEmptyVar;

  bool useMask = false;
  if (!get_val_param<bool >(useMask,_p,_n,false,true)) ClassReturnEmptyVar;

  int xsrcMask = wxDefaultCoord;
  if (!get_val_param<int >(xsrcMask,_p,_n,false,true)) ClassReturnEmptyVar;

  int ysrcMask = wxDefaultCoord;
  if (!get_val_param<int >(ysrcMask,_p,_n,false,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Blit(xdest, ydest, width, height, source, xsrc, ysrc, rop, useMask, xsrcMask, ysrcMask);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::Blit(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_Blit::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_Blit::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_Blit_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_Blit_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxDCBase::Blit(wxPoint const & destPt, wxSize const & sz, wxDC * source, wxPoint const & srcPt, int rop = wxCOPY, bool useMask = false, wxPoint const & srcPtMask = wxDefaultPosition)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_Blit_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'destPt'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( wxDC, "parameter named 'source'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'srcPt'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'rop' (def:wxCOPY)")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'useMask' (def:false)")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'srcPtMask' (def:wxDefaultPosition)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_Blit_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > destPt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(destPt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & destPt = *destPt_smtptr;

  boost::shared_ptr<wxSize > sz_smtptr;
  if (!get_val_smtptr_param<wxSize >(sz_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & sz = *sz_smtptr;

  boost::shared_ptr<wxDC > source_smtptr;
  if (!get_val_smtptr_param<wxDC >(source_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxDC* source = source_smtptr.get();

  boost::shared_ptr<wxPoint > srcPt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(srcPt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & srcPt = *srcPt_smtptr;

  int rop = wxCOPY;
  if (!get_val_param<int >(rop,_p,_n,false,true)) ClassReturnEmptyVar;

  bool useMask = false;
  if (!get_val_param<bool >(useMask,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxPoint > srcPtMask_smtptr;
  if (!get_val_smtptr_param<wxPoint >(srcPtMask_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & srcPtMask = ( srcPtMask_smtptr.get() ? (*srcPtMask_smtptr) : wxDefaultPosition );

  bool res =   this->_objectptr->GetObj()->Blit(destPt, sz, source, srcPt, rop, useMask, srcPtMask);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap wxDCBase::GetAsBitmap(wxRect const * subrect = 0u)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetAsBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'subrect' (def:0u)")
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetAsBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRect > subrect_smtptr;
  if (!get_val_smtptr_param<wxRect >(subrect_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRect* subrect = subrect_smtptr.get();

  wxBitmap res =   this->_objectptr->GetObj()->GetAsBitmap(subrect);
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawSpline(wxCoord x1, wxCoord y1, wxCoord x2, wxCoord y2, wxCoord x3, wxCoord y3)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawSpline_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x3'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawSpline_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  int x1;
  if (!get_val_param<int >(x1,_p,_n,true,true)) ClassReturnEmptyVar;

  int y1;
  if (!get_val_param<int >(y1,_p,_n,true,true)) ClassReturnEmptyVar;

  int x2;
  if (!get_val_param<int >(x2,_p,_n,true,true)) ClassReturnEmptyVar;

  int y2;
  if (!get_val_param<int >(y2,_p,_n,true,true)) ClassReturnEmptyVar;

  int x3;
  if (!get_val_param<int >(x3,_p,_n,true,true)) ClassReturnEmptyVar;

  int y3;
  if (!get_val_param<int >(y3,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DrawSpline(x1, y1, x2, y2, x3, y3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::DrawSpline(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawSpline::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawSpline::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_DrawSpline_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawSpline_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_DrawSpline_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawSpline(int n, wxPoint * points)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawSpline_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'points'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawSpline_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxPoint > points_smtptr;
  if (!get_val_smtptr_param<wxPoint >(points_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint* points = points_smtptr.get();

  this->_objectptr->GetObj()->DrawSpline(n, points);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DrawSpline(wxList * points)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DrawSpline_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxList, "parameter named 'points'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DrawSpline_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxList > points_smtptr;
  if (!get_val_smtptr_param<wxList >(points_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxList* points = points_smtptr.get();

  this->_objectptr->GetObj()->DrawSpline(points);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxDCBase::StartDoc(wxString const & param0)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_StartDoc::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'param0'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_StartDoc::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > param0_smtptr;
  if (!get_val_smtptr_param<wxString >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & param0 = *param0_smtptr;

  bool res =   this->_objectptr->GetObj()->StartDoc(param0);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::EndDoc()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_EndDoc::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_EndDoc::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EndDoc();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::StartPage()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_StartPage::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_StartPage::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StartPage();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::EndPage()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_EndPage::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_EndPage::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EndPage();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::SetClippingRegion(wxCoord x, wxCoord y, wxCoord width, wxCoord height)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_SetClippingRegion_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_SetClippingRegion_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,true)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetClippingRegion(x, y, width, height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::SetClippingRegion(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_SetClippingRegion::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_SetClippingRegion::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_SetClippingRegion_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_SetClippingRegion_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_SetClippingRegion_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_SetClippingRegion_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::SetClippingRegion(wxPoint const & pt, wxSize const & sz)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_SetClippingRegion_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_SetClippingRegion_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  boost::shared_ptr<wxSize > sz_smtptr;
  if (!get_val_smtptr_param<wxSize >(sz_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & sz = *sz_smtptr;

  this->_objectptr->GetObj()->SetClippingRegion(pt, sz);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::SetClippingRegion(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_SetClippingRegion_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_SetClippingRegion_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  this->_objectptr->GetObj()->SetClippingRegion(rect);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::SetClippingRegion(wxRegion const & region)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_SetClippingRegion_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRegion, "parameter named 'region'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_SetClippingRegion_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRegion > region_smtptr;
  if (!get_val_smtptr_param<wxRegion >(region_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRegion const & region = *region_smtptr;

  this->_objectptr->GetObj()->SetClippingRegion(region);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::SetDeviceClippingRegion(wxRegion const & region)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_SetDeviceClippingRegion::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRegion, "parameter named 'region'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_SetDeviceClippingRegion::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRegion > region_smtptr;
  if (!get_val_smtptr_param<wxRegion >(region_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRegion const & region = *region_smtptr;

  this->_objectptr->GetObj()->SetDeviceClippingRegion(region);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::DestroyClippingRegion()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DestroyClippingRegion::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DestroyClippingRegion::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DestroyClippingRegion();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GetClippingBox(wxCoord * x, wxCoord * y, wxCoord * w, wxCoord * h)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetClippingBox_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetClippingBox_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > x_smtptr;
  if (!get_val_smtptr_param<int >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* x = x_smtptr.get();

  boost::shared_ptr<int > y_smtptr;
  if (!get_val_smtptr_param<int >(y_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* y = y_smtptr.get();

  boost::shared_ptr<int > w_smtptr;
  if (!get_val_smtptr_param<int >(w_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* w = w_smtptr.get();

  boost::shared_ptr<int > h_smtptr;
  if (!get_val_smtptr_param<int >(h_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* h = h_smtptr.get();

  this->_objectptr->GetObj()->GetClippingBox(x, y, w, h);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::GetClippingBox(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetClippingBox::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetClippingBox::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_GetClippingBox_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_GetClippingBox_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_GetClippingBox_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GetClippingBox(wxRect & rect)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetClippingBox_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetClippingBox_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect & rect = *rect_smtptr;

  this->_objectptr->GetObj()->GetClippingBox(rect);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GetTextExtent(wxString const & string, wxCoord * x, wxCoord * y, wxCoord * descent = 0l, wxCoord * externalLeading = 0l, wxFont * theFont = 0l)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetTextExtent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'string'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'descent' (def:0l)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'externalLeading' (def:0l)")
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'theFont' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetTextExtent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > string_smtptr;
  if (!get_val_smtptr_param<wxString >(string_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & string = *string_smtptr;

  boost::shared_ptr<int > x_smtptr;
  if (!get_val_smtptr_param<int >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* x = x_smtptr.get();

  boost::shared_ptr<int > y_smtptr;
  if (!get_val_smtptr_param<int >(y_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* y = y_smtptr.get();

  boost::shared_ptr<int > descent_smtptr;
  if (!get_val_smtptr_param<int >(descent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* descent = descent_smtptr.get();

  boost::shared_ptr<int > externalLeading_smtptr;
  if (!get_val_smtptr_param<int >(externalLeading_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* externalLeading = externalLeading_smtptr.get();

  boost::shared_ptr<wxFont > theFont_smtptr;
  if (!get_val_smtptr_param<wxFont >(theFont_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxFont* theFont = theFont_smtptr.get();

  this->_objectptr->GetObj()->GetTextExtent(string, x, y, descent, externalLeading, theFont);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::GetTextExtent(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetTextExtent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetTextExtent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_GetTextExtent_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_GetTextExtent_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_GetTextExtent_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxSize wxDCBase::GetTextExtent(wxString const & string)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetTextExtent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'string'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetTextExtent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > string_smtptr;
  if (!get_val_smtptr_param<wxString >(string_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & string = *string_smtptr;

  wxSize res =   this->_objectptr->GetObj()->GetTextExtent(string);
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GetMultiLineTextExtent(wxString const & string, wxCoord * width, wxCoord * height, wxCoord * heightLine = 0l, wxFont * font = 0l)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetMultiLineTextExtent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'string'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'heightLine' (def:0l)")
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'font' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetMultiLineTextExtent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > string_smtptr;
  if (!get_val_smtptr_param<wxString >(string_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & string = *string_smtptr;

  boost::shared_ptr<int > width_smtptr;
  if (!get_val_smtptr_param<int >(width_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* width = width_smtptr.get();

  boost::shared_ptr<int > height_smtptr;
  if (!get_val_smtptr_param<int >(height_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* height = height_smtptr.get();

  boost::shared_ptr<int > heightLine_smtptr;
  if (!get_val_smtptr_param<int >(heightLine_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* heightLine = heightLine_smtptr.get();

  boost::shared_ptr<wxFont > font_smtptr;
  if (!get_val_smtptr_param<wxFont >(font_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxFont* font = font_smtptr.get();

  this->_objectptr->GetObj()->GetMultiLineTextExtent(string, width, height, heightLine, font);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::GetMultiLineTextExtent(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetMultiLineTextExtent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetMultiLineTextExtent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_GetMultiLineTextExtent_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_GetMultiLineTextExtent_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxSize wxDCBase::GetMultiLineTextExtent(wxString const & string)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetMultiLineTextExtent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'string'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetMultiLineTextExtent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > string_smtptr;
  if (!get_val_smtptr_param<wxString >(string_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & string = *string_smtptr;

  wxSize res =   this->_objectptr->GetObj()->GetMultiLineTextExtent(string);
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDCBase::GetPartialTextExtents(wxString const & text, wxArrayInt & widths)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetPartialTextExtents::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( wxArrayInt, "parameter named 'widths'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetPartialTextExtents::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  boost::shared_ptr<wxArrayInt > widths_smtptr;
  if (!get_val_smtptr_param<wxArrayInt >(widths_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxArrayInt & widths = *widths_smtptr;

  bool res =   this->_objectptr->GetObj()->GetPartialTextExtents(text, widths);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GetSize(int * width, int * height)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetSize_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetSize_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > width_smtptr;
  if (!get_val_smtptr_param<int >(width_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* width = width_smtptr.get();

  boost::shared_ptr<int > height_smtptr;
  if (!get_val_smtptr_param<int >(height_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* height = height_smtptr.get();

  this->_objectptr->GetObj()->GetSize(width, height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::GetSize(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_GetSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_GetSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxSize wxDCBase::GetSize()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetSize_2::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetSize_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxSize res =   this->_objectptr->GetObj()->GetSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GetSizeMM(int * width, int * height)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetSizeMM_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetSizeMM_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > width_smtptr;
  if (!get_val_smtptr_param<int >(width_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* width = width_smtptr.get();

  boost::shared_ptr<int > height_smtptr;
  if (!get_val_smtptr_param<int >(height_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* height = height_smtptr.get();

  this->_objectptr->GetObj()->GetSizeMM(width, height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::GetSizeMM(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetSizeMM::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetSizeMM::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_GetSizeMM_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_GetSizeMM_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxSize wxDCBase::GetSizeMM()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetSizeMM_2::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetSizeMM_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxSize res =   this->_objectptr->GetObj()->GetSizeMM();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxDCBase::DeviceToLogicalX(wxCoord x)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DeviceToLogicalX::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DeviceToLogicalX::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->DeviceToLogicalX(x);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxDCBase::DeviceToLogicalY(wxCoord y)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DeviceToLogicalY::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DeviceToLogicalY::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->DeviceToLogicalY(y);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxDCBase::DeviceToLogicalXRel(wxCoord x)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DeviceToLogicalXRel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DeviceToLogicalXRel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->DeviceToLogicalXRel(x);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxDCBase::DeviceToLogicalYRel(wxCoord y)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_DeviceToLogicalYRel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_DeviceToLogicalYRel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->DeviceToLogicalYRel(y);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxDCBase::LogicalToDeviceX(wxCoord x)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_LogicalToDeviceX::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_LogicalToDeviceX::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->LogicalToDeviceX(x);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxDCBase::LogicalToDeviceY(wxCoord y)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_LogicalToDeviceY::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_LogicalToDeviceY::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->LogicalToDeviceY(y);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxDCBase::LogicalToDeviceXRel(wxCoord x)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_LogicalToDeviceXRel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_LogicalToDeviceXRel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->LogicalToDeviceXRel(x);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxDCBase::LogicalToDeviceYRel(wxCoord y)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_LogicalToDeviceYRel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_LogicalToDeviceYRel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->LogicalToDeviceYRel(y);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDCBase::Ok()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_Ok::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_Ok::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Ok();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDCBase::IsOk()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_IsOk::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_IsOk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOk();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxDCBase::GetBackgroundMode()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetBackgroundMode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetBackgroundMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetBackgroundMode();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBrush const & wxDCBase::GetBackground()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetBackground::SetParametersComments()
{
  return_comments="returning a variable of type wxBrush";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetBackground::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBrush const & res =   this->_objectptr->GetObj()->GetBackground();
  return AMILabType<wxBrush >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBrush const & wxDCBase::GetBrush()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetBrush::SetParametersComments()
{
  return_comments="returning a variable of type wxBrush";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetBrush::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBrush const & res =   this->_objectptr->GetObj()->GetBrush();
  return AMILabType<wxBrush >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxFont const & wxDCBase::GetFont()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetFont::SetParametersComments()
{
  return_comments="returning a variable of type wxFont";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetFont::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxFont const & res =   this->_objectptr->GetObj()->GetFont();
  return AMILabType<wxFont >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPen const & wxDCBase::GetPen()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetPen::SetParametersComments()
{
  return_comments="returning a variable of type wxPen";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetPen::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPen const & res =   this->_objectptr->GetObj()->GetPen();
  return AMILabType<wxPen >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxColour const & wxDCBase::GetTextForeground()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetTextForeground::SetParametersComments()
{
  return_comments="returning a variable of type wxColour";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetTextForeground::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxColour const & res =   this->_objectptr->GetObj()->GetTextForeground();
  return AMILabType<wxColour >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxColour const & wxDCBase::GetTextBackground()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetTextBackground::SetParametersComments()
{
  return_comments="returning a variable of type wxColour";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetTextBackground::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxColour const & res =   this->_objectptr->GetObj()->GetTextBackground();
  return AMILabType<wxColour >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::SetTextForeground(wxColour const & colour)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_SetTextForeground::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'colour'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_SetTextForeground::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > colour_smtptr;
  if (!get_val_smtptr_param<wxColour >(colour_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour const & colour = *colour_smtptr;

  this->_objectptr->GetObj()->SetTextForeground(colour);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::SetTextBackground(wxColour const & colour)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_SetTextBackground::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'colour'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_SetTextBackground::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > colour_smtptr;
  if (!get_val_smtptr_param<wxColour >(colour_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour const & colour = *colour_smtptr;

  this->_objectptr->GetObj()->SetTextBackground(colour);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxDCBase::GetMapMode()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetMapMode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetMapMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMapMode();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GetUserScale(double * x, double * y)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetUserScale::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetUserScale::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* x = x_smtptr.get();

  boost::shared_ptr<double > y_smtptr;
  if (!get_val_smtptr_param<double >(y_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* y = y_smtptr.get();

  this->_objectptr->GetObj()->GetUserScale(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GetLogicalScale(double * x, double * y)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetLogicalScale::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetLogicalScale::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* x = x_smtptr.get();

  boost::shared_ptr<double > y_smtptr;
  if (!get_val_smtptr_param<double >(y_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* y = y_smtptr.get();

  this->_objectptr->GetObj()->GetLogicalScale(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::SetLogicalScale(double x, double y)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_SetLogicalScale::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_SetLogicalScale::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,false)) ClassHelpAndReturn;

  double y;
  if (!get_val_param<double >(y,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetLogicalScale(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GetLogicalOrigin(wxCoord * x, wxCoord * y)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetLogicalOrigin_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetLogicalOrigin_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > x_smtptr;
  if (!get_val_smtptr_param<int >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* x = x_smtptr.get();

  boost::shared_ptr<int > y_smtptr;
  if (!get_val_smtptr_param<int >(y_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* y = y_smtptr.get();

  this->_objectptr->GetObj()->GetLogicalOrigin(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::GetLogicalOrigin(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetLogicalOrigin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetLogicalOrigin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_GetLogicalOrigin_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_GetLogicalOrigin_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_GetLogicalOrigin_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxPoint wxDCBase::GetLogicalOrigin()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetLogicalOrigin_2::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetLogicalOrigin_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxPoint res =   this->_objectptr->GetObj()->GetLogicalOrigin();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GetDeviceOrigin(wxCoord * x, wxCoord * y)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetDeviceOrigin_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetDeviceOrigin_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > x_smtptr;
  if (!get_val_smtptr_param<int >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* x = x_smtptr.get();

  boost::shared_ptr<int > y_smtptr;
  if (!get_val_smtptr_param<int >(y_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* y = y_smtptr.get();

  this->_objectptr->GetObj()->GetDeviceOrigin(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDCBase::GetDeviceOrigin(...)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetDeviceOrigin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetDeviceOrigin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDCBase::wrap_GetDeviceOrigin_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_GetDeviceOrigin_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxDCBase::wrap_GetDeviceOrigin_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxPoint wxDCBase::GetDeviceOrigin()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetDeviceOrigin_2::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetDeviceOrigin_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxPoint res =   this->_objectptr->GetObj()->GetDeviceOrigin();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::ComputeScaleAndOrigin()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_ComputeScaleAndOrigin::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_ComputeScaleAndOrigin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ComputeScaleAndOrigin();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxDCBase::GetLogicalFunction()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetLogicalFunction::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetLogicalFunction::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetLogicalFunction();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::CalcBoundingBox(wxCoord x, wxCoord y)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_CalcBoundingBox::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_CalcBoundingBox::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->CalcBoundingBox(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::ResetBoundingBox()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_ResetBoundingBox::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_ResetBoundingBox::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ResetBoundingBox();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxCoord wxDCBase::MinX()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_MinX::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_MinX::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->MinX();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxDCBase::MaxX()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_MaxX::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_MaxX::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->MaxX();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxDCBase::MinY()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_MinY::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_MinY::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->MinY();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxDCBase::MaxY()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_MaxY::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_MaxY::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->MaxY();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GetTextExtent(wxString const & string, long int * x, long int * y, long int * descent = 0l, long int * externalLeading = 0l, wxFont * theFont = 0l)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetTextExtent_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'string'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'descent' (def:0l)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'externalLeading' (def:0l)")
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'theFont' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetTextExtent_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > string_smtptr;
  if (!get_val_smtptr_param<wxString >(string_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & string = *string_smtptr;

  boost::shared_ptr<long > x_long;
  if (!get_val_smtptr_param<long >(x_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long int x_val = *x_long;
  long int* x = &x_val;

  boost::shared_ptr<long > y_long;
  if (!get_val_smtptr_param<long >(y_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long int y_val = *y_long;
  long int* y = &y_val;

  boost::shared_ptr<long > descent_long;
  if (!get_val_smtptr_param<long >(descent_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long int descent_val = *descent_long;
  long int* descent = &descent_val;

  boost::shared_ptr<long > externalLeading_long;
  if (!get_val_smtptr_param<long >(externalLeading_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long int externalLeading_val = *externalLeading_long;
  long int* externalLeading = &externalLeading_val;

  boost::shared_ptr<wxFont > theFont_smtptr;
  if (!get_val_smtptr_param<wxFont >(theFont_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxFont* theFont = theFont_smtptr.get();

  this->_objectptr->GetObj()->GetTextExtent(string, x, y, descent, externalLeading, theFont);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GetLogicalOrigin(long int * x, long int * y)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetLogicalOrigin_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetLogicalOrigin_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<long > x_long;
  if (!get_val_smtptr_param<long >(x_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long int x_val = *x_long;
  long int* x = &x_val;

  boost::shared_ptr<long > y_long;
  if (!get_val_smtptr_param<long >(y_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long int y_val = *y_long;
  long int* y = &y_val;

  this->_objectptr->GetObj()->GetLogicalOrigin(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GetDeviceOrigin(long int * x, long int * y)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetDeviceOrigin_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetDeviceOrigin_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<long > x_long;
  if (!get_val_smtptr_param<long >(x_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long int x_val = *x_long;
  long int* x = &x_val;

  boost::shared_ptr<long > y_long;
  if (!get_val_smtptr_param<long >(y_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long int y_val = *y_long;
  long int* y = &y_val;

  this->_objectptr->GetObj()->GetDeviceOrigin(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::GetClippingBox(long int * x, long int * y, long int * w, long int * h)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetClippingBox_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'h'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetClippingBox_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<long > x_long;
  if (!get_val_smtptr_param<long >(x_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long int x_val = *x_long;
  long int* x = &x_val;

  boost::shared_ptr<long > y_long;
  if (!get_val_smtptr_param<long >(y_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long int y_val = *y_long;
  long int* y = &y_val;

  boost::shared_ptr<long > w_long;
  if (!get_val_smtptr_param<long >(w_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long int w_val = *w_long;
  long int* w = &w_val;

  boost::shared_ptr<long > h_long;
  if (!get_val_smtptr_param<long >(h_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long int h_val = *h_long;
  long int* h = &h_val;

  this->_objectptr->GetObj()->GetClippingBox(x, y, w, h);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxLayoutDirection wxDCBase::GetLayoutDirection()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetLayoutDirection::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetLayoutDirection::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxLayoutDirection res =   this->_objectptr->GetObj()->GetLayoutDirection();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxDCBase::SetLayoutDirection(wxLayoutDirection param0)
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_SetLayoutDirection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_SetLayoutDirection::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int param0_int;
  if (!get_val_param<int >(param0_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxLayoutDirection param0 = (wxLayoutDirection) param0_int;

  this->_objectptr->GetObj()->SetLayoutDirection(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxDCBase::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxDCBase::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDCBase::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

