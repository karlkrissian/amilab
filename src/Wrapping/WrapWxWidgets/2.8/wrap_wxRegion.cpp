/**
 * C++ Interface: wrap_wxRegion
 *
 * Description: wrapping wxRegion
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
#include "wrap_wxPoint.h"
#include "wrap_wxRect.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxBitmap.h"
#include "wrap_wxColour.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxRegion.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxRegion>::CreateVar( ParamList* p)
{
  WrapClass_wxRegion::wrap_wxRegion construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxRegion);
AMI_DEFINE_VARFROMSMTPTR(wxRegion);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxRegion
//
Variable<AMIObject>::ptr WrapClass_wxRegion::CreateVar( wxRegion* sp)
{
  boost::shared_ptr<wxRegion> di_ptr(
    sp,
    wxwindow_nodeleter<wxRegion>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxRegion>::CreateVar(
      new WrapClass_wxRegion(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxRegion::AddMethods(WrapClass<wxRegion>::ptr this_ptr )
{
  
      // Add members from wxRegionBase
      WrapClass_wxRegionBase::ptr parent_wxRegionBase(        boost::dynamic_pointer_cast<WrapClass_wxRegionBase >(this_ptr));
      parent_wxRegionBase->AddMethods(parent_wxRegionBase);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Clear( this_ptr);
      AddVar_IsEmpty( this_ptr);
/* The following types are missing: _GdkRegion
      AddVar_GetRegion( this_ptr);
*/
      AddVar_GetClassInfo( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxRegion::wxRegion(wxRegion const & param0)
//---------------------------------------------------
void WrapClass_wxRegion::
    wrap_wxRegion_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRegion, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegion::
    wrap_wxRegion_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRegion > param0_smtptr;
  if (!get_val_smtptr_param<wxRegion >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxRegion const & param0 = *param0_smtptr;

  wxRegion* _newobj = new wxRegion(param0);
  BasicVariable::ptr res = WrapClass_wxRegion::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxRegion::wxRegion(...)
//---------------------------------------------------
void WrapClass_wxRegion::
    wrap_wxRegion::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegion::
    wrap_wxRegion::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxRegion::wrap_wxRegion_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxRegion::wrap_wxRegion_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxRegion::wrap_wxRegion_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxRegion::wrap_wxRegion_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxRegion::wrap_wxRegion_5 m5;
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxRegion::wrap_wxRegion_6 m6;
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxRegion::wrap_wxRegion_7 m7;
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxRegion::wrap_wxRegion_8 m8;
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxRegion::wxRegion()
//---------------------------------------------------
void WrapClass_wxRegion::
    wrap_wxRegion_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegion::
    wrap_wxRegion_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxRegion* _newobj = new wxRegion();
  BasicVariable::ptr res = WrapClass_wxRegion::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxRegion::wxRegion(wxCoord x, wxCoord y, wxCoord w, wxCoord h)
//---------------------------------------------------
void WrapClass_wxRegion::
    wrap_wxRegion_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegion::
    wrap_wxRegion_3::CallMember( ParamList* _p)
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

  wxRegion* _newobj = new wxRegion(x, y, w, h);
  BasicVariable::ptr res = WrapClass_wxRegion::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxRegion::wxRegion(wxPoint const & topLeft, wxPoint const & bottomRight)
//---------------------------------------------------
void WrapClass_wxRegion::
    wrap_wxRegion_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'topLeft'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'bottomRight'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegion::
    wrap_wxRegion_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > topLeft_smtptr;
  if (!get_val_smtptr_param<wxPoint >(topLeft_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & topLeft = *topLeft_smtptr;

  boost::shared_ptr<wxPoint > bottomRight_smtptr;
  if (!get_val_smtptr_param<wxPoint >(bottomRight_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & bottomRight = *bottomRight_smtptr;

  wxRegion* _newobj = new wxRegion(topLeft, bottomRight);
  BasicVariable::ptr res = WrapClass_wxRegion::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxRegion::wxRegion(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxRegion::
    wrap_wxRegion_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegion::
    wrap_wxRegion_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  wxRegion* _newobj = new wxRegion(rect);
  BasicVariable::ptr res = WrapClass_wxRegion::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxRegion::wxRegion(size_t n, wxPoint const * points, int fillStyle = wxODDEVEN_RULE)
//---------------------------------------------------
void WrapClass_wxRegion::
    wrap_wxRegion_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'points'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'fillStyle' (def:wxODDEVEN_RULE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegion::
    wrap_wxRegion_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<wxPoint > points_smtptr;
  if (!get_val_smtptr_param<wxPoint >(points_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint* points = points_smtptr.get();

  int fillStyle = wxODDEVEN_RULE;
  if (!get_val_param<int >(fillStyle,_p,_n,false,true)) ClassReturnEmptyVar;

  wxRegion* _newobj = new wxRegion(n, points, fillStyle);
  BasicVariable::ptr res = WrapClass_wxRegion::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxRegion::wxRegion(wxBitmap const & bmp)
//---------------------------------------------------
void WrapClass_wxRegion::
    wrap_wxRegion_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegion::
    wrap_wxRegion_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmap > bmp_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmp_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bmp = *bmp_smtptr;

  wxRegion* _newobj = new wxRegion(bmp);
  BasicVariable::ptr res = WrapClass_wxRegion::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxRegion::wxRegion(wxBitmap const & bmp, wxColour const & transColour, int tolerance = 0)
//---------------------------------------------------
void WrapClass_wxRegion::
    wrap_wxRegion_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmp'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'transColour'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tolerance' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegion::
    wrap_wxRegion_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmap > bmp_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmp_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bmp = *bmp_smtptr;

  boost::shared_ptr<wxColour > transColour_smtptr;
  if (!get_val_smtptr_param<wxColour >(transColour_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxColour const & transColour = *transColour_smtptr;

  int tolerance = 0;
  if (!get_val_param<int >(tolerance,_p,_n,false,true)) ClassReturnEmptyVar;

  wxRegion* _newobj = new wxRegion(bmp, transColour, tolerance);
  BasicVariable::ptr res = WrapClass_wxRegion::CreateVar(_newobj);
  return res;
}
/* The following types are missing: _GdkRegion

//---------------------------------------------------
//  Wrapping of Constructor wxRegion::wxRegion(GdkRegion * region)
//---------------------------------------------------
void WrapClass_wxRegion::
    wrap_wxRegion_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GdkRegion, "parameter named 'region'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegion::
    wrap_wxRegion_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<_GdkRegion > region_smtptr;
  if (!get_val_smtptr_param<_GdkRegion >(region_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  _GdkRegion* region = region_smtptr.get();

  wxRegion* _newobj = new wxRegion(region);
  BasicVariable::ptr res = WrapClass_wxRegion::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of 'copy' method for wxRegion.
//---------------------------------------------------
void WrapClass_wxRegion::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxRegion object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegion::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxRegion >::CreateVar( new wxRegion(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxRegion::Clear()
//---------------------------------------------------
void WrapClass_wxRegion::
    wrap_Clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegion::
    wrap_Clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxRegion::IsEmpty()
//---------------------------------------------------
void WrapClass_wxRegion::
    wrap_IsEmpty::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegion::
    wrap_IsEmpty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsEmpty();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
/* The following types are missing: _GdkRegion

//---------------------------------------------------
//  Wrapping of GdkRegion * wxRegion::GetRegion()
//---------------------------------------------------
void WrapClass_wxRegion::
    wrap_GetRegion::SetParametersComments()
{
  return_comments="returning a variable of type _GdkRegion";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegion::
    wrap_GetRegion::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  GdkRegion * res =   this->_objectptr->GetObj()->GetRegion();
  return AMILabType<_GdkRegion >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxRegion::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxRegion::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegion::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxRegion & wxRegion::operator =(wxRegion const & param0)
//---------------------------------------------------
void WrapClass_wxRegion::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRegion, "parameter named 'param0'")
  return_comments="returning a variable of type wxRegion";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRegion::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRegion > param0_smtptr;
  if (!get_val_smtptr_param<wxRegion >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRegion const & param0 = *param0_smtptr;

  wxRegion & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxRegion >::CreateVar(res);
}

