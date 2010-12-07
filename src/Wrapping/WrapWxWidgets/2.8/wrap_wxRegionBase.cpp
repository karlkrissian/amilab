/**
 * C++ Interface: wrap_wxRegionBase
 *
 * Description: wrapping wxRegionBase
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
#include "wrap_wxRegion.h"
#include "wrap_wxRect.h"
#include "wrap_wxPoint.h"
#include "wrap_wxBitmap.h"
#include "wrap_wxColour.h"
#include "wrap_wxRegionBase.h"


#include "wrap_wxRegionBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxRegionBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxRegionBase);
AMI_DEFINE_VARFROMSMTPTR(wxRegionBase);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxRegionBase
//
Variable<AMIObject>::ptr WrapClass_wxRegionBase::CreateVar( wxRegionBase* sp)
{
  boost::shared_ptr<wxRegionBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxRegionBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxRegionBase>::CreateVar(
      new WrapClass_wxRegionBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxRegionBase::AddMethods(WrapClass<wxRegionBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding standard methods 
      AddVar_Ok( this_ptr);
      AddVar_IsOk( this_ptr);
      AddVar_Empty( this_ptr);
      AddVar_IsEqual( this_ptr);
      AddVar_GetBox_1( this_ptr);
      AddVar_GetBox( this_ptr);
      AddVar_GetBox_2( this_ptr);
      AddVar_Contains_1( this_ptr);
      AddVar_Contains( this_ptr);
      AddVar_Contains_2( this_ptr);
      AddVar_Contains_3( this_ptr);
      AddVar_Contains_4( this_ptr);
      AddVar_Offset_1( this_ptr);
      AddVar_Offset( this_ptr);
      AddVar_Offset_2( this_ptr);
      AddVar_Union_1( this_ptr);
      AddVar_Union( this_ptr);
      AddVar_Union_2( this_ptr);
      AddVar_Union_3( this_ptr);
      AddVar_Union_4( this_ptr);
      AddVar_Union_5( this_ptr);
      AddVar_Intersect_1( this_ptr);
      AddVar_Intersect( this_ptr);
      AddVar_Intersect_2( this_ptr);
      AddVar_Intersect_3( this_ptr);
      AddVar_Subtract_1( this_ptr);
      AddVar_Subtract( this_ptr);
      AddVar_Subtract_2( this_ptr);
      AddVar_Subtract_3( this_ptr);
      AddVar_Xor_1( this_ptr);
      AddVar_Xor( this_ptr);
      AddVar_Xor_2( this_ptr);
      AddVar_Xor_3( this_ptr);
      AddVar_ConvertToBitmap( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);
      AddVar___equal__( this_ptr);
      AddVar___not_equal__( this_ptr);



  

  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxGDIObject
  boost::shared_ptr<wxGDIObject > parent_wxGDIObject(  boost::dynamic_pointer_cast<wxGDIObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxGDIObject = AMILabType<wxGDIObject >::CreateVarFromSmtPtr(parent_wxGDIObject);
  context->AddVar("wxGDIObject",var_wxGDIObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxGDIObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxGDIObject);
  context->AddDefault(obj_wxGDIObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxRegionBase::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxRegionBase");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Ok()
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Ok::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Ok::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Ok();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::IsOk()
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_IsOk::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_IsOk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOk();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Empty()
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Empty::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Empty();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::IsEqual(wxRegion const & region)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_IsEqual::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRegion, "parameter named 'region'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_IsEqual::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRegion > region_smtptr;
  if (!get_val_smtptr_param<wxRegion >(region_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRegion const & region = *region_smtptr;

  bool res =   this->_objectptr->GetObj()->IsEqual(region);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::GetBox(wxCoord & x, wxCoord & y, wxCoord & w, wxCoord & h)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_GetBox_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_GetBox_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > x_smtptr;
  if (!get_val_smtptr_param<int >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxCoord & x = *x_smtptr;

  boost::shared_ptr<int > y_smtptr;
  if (!get_val_smtptr_param<int >(y_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxCoord & y = *y_smtptr;

  boost::shared_ptr<int > w_smtptr;
  if (!get_val_smtptr_param<int >(w_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxCoord & w = *w_smtptr;

  boost::shared_ptr<int > h_smtptr;
  if (!get_val_smtptr_param<int >(h_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxCoord & h = *h_smtptr;

  bool res =   this->_objectptr->GetObj()->GetBox(x, y, w, h);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxRegionBase::GetBox(...)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_GetBox::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_GetBox::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxRegionBase::wrap_GetBox_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxRegionBase::wrap_GetBox_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxRect wxRegionBase::GetBox()
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_GetBox_2::SetParametersComments()
{
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_GetBox_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxRect res =   this->_objectptr->GetObj()->GetBox();
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRegionContain wxRegionBase::Contains(wxCoord x, wxCoord y)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Contains_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Contains_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  wxRegionContain res =   this->_objectptr->GetObj()->Contains(x, y);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxRegionBase::Contains(...)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Contains::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Contains::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxRegionBase::wrap_Contains_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxRegionBase::wrap_Contains_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxRegionBase::wrap_Contains_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxRegionBase::wrap_Contains_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxRegionContain wxRegionBase::Contains(wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Contains_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Contains_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  wxRegionContain res =   this->_objectptr->GetObj()->Contains(pt);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxRegionContain wxRegionBase::Contains(wxCoord x, wxCoord y, wxCoord w, wxCoord h)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Contains_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Contains_3::CallMember( ParamList* _p)
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

  wxRegionContain res =   this->_objectptr->GetObj()->Contains(x, y, w, h);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxRegionContain wxRegionBase::Contains(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Contains_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Contains_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  wxRegionContain res =   this->_objectptr->GetObj()->Contains(rect);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Offset(wxCoord x, wxCoord y)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Offset_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Offset_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Offset(x, y);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxRegionBase::Offset(...)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Offset::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Offset::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxRegionBase::wrap_Offset_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxRegionBase::wrap_Offset_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Offset(wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Offset_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Offset_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  bool res =   this->_objectptr->GetObj()->Offset(pt);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Union(wxCoord x, wxCoord y, wxCoord w, wxCoord h)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Union_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Union_1::CallMember( ParamList* _p)
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

  bool res =   this->_objectptr->GetObj()->Union(x, y, w, h);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxRegionBase::Union(...)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Union::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Union::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxRegionBase::wrap_Union_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxRegionBase::wrap_Union_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxRegionBase::wrap_Union_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxRegionBase::wrap_Union_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxRegionBase::wrap_Union_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Union(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Union_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Union_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  bool res =   this->_objectptr->GetObj()->Union(rect);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Union(wxRegion const & region)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Union_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRegion, "parameter named 'region'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Union_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRegion > region_smtptr;
  if (!get_val_smtptr_param<wxRegion >(region_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRegion const & region = *region_smtptr;

  bool res =   this->_objectptr->GetObj()->Union(region);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Union(wxBitmap const & bmp)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Union_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmp'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Union_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmap > bmp_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmp_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bmp = *bmp_smtptr;

  bool res =   this->_objectptr->GetObj()->Union(bmp);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Union(wxBitmap const & bmp, wxColour const & transp, int tolerance = 0)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Union_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmp'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'transp'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tolerance' (def:0)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Union_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmap > bmp_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmp_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bmp = *bmp_smtptr;

  boost::shared_ptr<wxColour > transp_smtptr;
  if (!get_val_smtptr_param<wxColour >(transp_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxColour const & transp = *transp_smtptr;

  int tolerance = 0;
  if (!get_val_param<int >(tolerance,_p,_n,false,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Union(bmp, transp, tolerance);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Intersect(wxCoord x, wxCoord y, wxCoord w, wxCoord h)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Intersect_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Intersect_1::CallMember( ParamList* _p)
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

  bool res =   this->_objectptr->GetObj()->Intersect(x, y, w, h);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxRegionBase::Intersect(...)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Intersect::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Intersect::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxRegionBase::wrap_Intersect_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxRegionBase::wrap_Intersect_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxRegionBase::wrap_Intersect_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Intersect(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Intersect_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Intersect_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  bool res =   this->_objectptr->GetObj()->Intersect(rect);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Intersect(wxRegion const & region)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Intersect_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRegion, "parameter named 'region'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Intersect_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRegion > region_smtptr;
  if (!get_val_smtptr_param<wxRegion >(region_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRegion const & region = *region_smtptr;

  bool res =   this->_objectptr->GetObj()->Intersect(region);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Subtract(wxCoord x, wxCoord y, wxCoord w, wxCoord h)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Subtract_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Subtract_1::CallMember( ParamList* _p)
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

  bool res =   this->_objectptr->GetObj()->Subtract(x, y, w, h);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxRegionBase::Subtract(...)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Subtract::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Subtract::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxRegionBase::wrap_Subtract_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxRegionBase::wrap_Subtract_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxRegionBase::wrap_Subtract_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Subtract(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Subtract_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Subtract_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  bool res =   this->_objectptr->GetObj()->Subtract(rect);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Subtract(wxRegion const & region)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Subtract_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRegion, "parameter named 'region'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Subtract_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRegion > region_smtptr;
  if (!get_val_smtptr_param<wxRegion >(region_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRegion const & region = *region_smtptr;

  bool res =   this->_objectptr->GetObj()->Subtract(region);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Xor(wxCoord x, wxCoord y, wxCoord w, wxCoord h)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Xor_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Xor_1::CallMember( ParamList* _p)
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

  bool res =   this->_objectptr->GetObj()->Xor(x, y, w, h);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxRegionBase::Xor(...)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Xor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Xor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxRegionBase::wrap_Xor_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxRegionBase::wrap_Xor_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxRegionBase::wrap_Xor_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Xor(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Xor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Xor_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  bool res =   this->_objectptr->GetObj()->Xor(rect);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::Xor(wxRegion const & region)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_Xor_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRegion, "parameter named 'region'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_Xor_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRegion > region_smtptr;
  if (!get_val_smtptr_param<wxRegion >(region_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRegion const & region = *region_smtptr;

  bool res =   this->_objectptr->GetObj()->Xor(region);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap wxRegionBase::ConvertToBitmap()
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap_ConvertToBitmap::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap_ConvertToBitmap::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap res =   this->_objectptr->GetObj()->ConvertToBitmap();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRegionBase & wxRegionBase::operator =(wxRegionBase const & param0)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRegionBase, "parameter named 'param0'")
  return_comments="returning a variable of type wxRegionBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRegionBase > param0_smtptr;
  if (!get_val_smtptr_param<wxRegionBase >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRegionBase const & param0 = *param0_smtptr;

  wxRegionBase & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxRegionBase >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::operator ==(wxRegion const & region)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap___equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRegion, "parameter named 'region'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap___equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRegion > region_smtptr;
  if (!get_val_smtptr_param<wxRegion >(region_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRegion const & region = *region_smtptr;

  bool res =   (*this->_objectptr->GetObj()) == (region);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRegionBase::operator !=(wxRegion const & region)
//---------------------------------------------------
void WrapClass_wxRegionBase::
    wrap___not_equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRegion, "parameter named 'region'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegionBase::
    wrap___not_equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRegion > region_smtptr;
  if (!get_val_smtptr_param<wxRegion >(region_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRegion const & region = *region_smtptr;

  bool res =   (*this->_objectptr->GetObj()) != (region);
  return AMILabType<bool >::CreateVar(res);
}

