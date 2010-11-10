/**
 * C++ Interface: wrap_wxPoint
 *
 * Description: wrapping wxPoint
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_wxPoint.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxPoint.h"
#include "wrap_wxSize.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxPoint>::CreateVar( ParamList* p)
{
  WrapClass_wxPoint::wrap_wxPoint construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxPoint);

//
// static member for creating a variable from a pointer to wxPoint
//
Variable<AMIObject>::ptr WrapClass_wxPoint::CreateVar( wxPoint* sp)
{
  boost::shared_ptr<wxPoint> di_ptr(
    sp,
    wxwindow_nodeleter<wxPoint>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxPoint>::CreateVar(
      new WrapClass_wxPoint(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor wxPoint::wxPoint(wxPoint & param0)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_wxPoint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_wxPoint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxPoint* param0_ptr;
  if (!get_val_ptr_param<wxPoint>(param0_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& param0 = *param0_ptr;
  wxPoint* _newobj = new wxPoint(param0);
  BasicVariable::ptr res = WrapClass_wxPoint::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxPoint::wxPoint()
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_wxPoint1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_wxPoint1::CallMember( ParamList* _p)
{
  wxPoint* _newobj = new wxPoint();
  BasicVariable::ptr res = WrapClass_wxPoint::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxPoint::wxPoint(int xx, int yy)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_wxPoint2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_wxPoint2::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int xx;
  if (!get_val_param<int>(xx,_p,_n)) ClassHelpAndReturn;
  int yy;
  if (!get_val_param<int>(yy,_p,_n)) ClassHelpAndReturn;
  wxPoint* _newobj = new wxPoint(xx, yy);
  BasicVariable::ptr res = WrapClass_wxPoint::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxPoint & wxPoint::=(wxPoint & param0)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_assign::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'param0'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_assign::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxPoint* param0_ptr;
  if (!get_val_ptr_param<wxPoint>(param0_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& param0 = *param0_ptr;
  wxPoint & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxPoint>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxPoint::==(wxPoint & p)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_equal::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_equal::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxPoint* p_ptr;
  if (!get_val_ptr_param<wxPoint>(p_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& p = *p_ptr;
  bool res =   (*this->_objectptr->GetObj()) == (p);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxPoint::!=(wxPoint & p)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_not_equal::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_not_equal::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxPoint* p_ptr;
  if (!get_val_ptr_param<wxPoint>(p_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& p = *p_ptr;
  bool res =   (*this->_objectptr->GetObj()) != (p);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxPoint::+(wxPoint & p)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_add::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_add::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxPoint* p_ptr;
  if (!get_val_ptr_param<wxPoint>(p_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& p = *p_ptr;
  wxPoint res =   (*this->_objectptr->GetObj()) + (p);
  return AMILabType<wxPoint>::CreateVar(res);
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxPoint wxPoint::-(wxPoint & p)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxPoint* p_ptr;
  if (!get_val_ptr_param<wxPoint>(p_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& p = *p_ptr;
  wxPoint res =   this->_objectptr->GetObj()->-(p);
  return AMILabType<wxPoint>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxPoint & wxPoint::+=(wxPoint & p)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_add_assign::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_add_assign::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxPoint* p_ptr;
  if (!get_val_ptr_param<wxPoint>(p_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& p = *p_ptr;
  wxPoint & res =   (*this->_objectptr->GetObj()) += (p);
  return AMILabType<wxPoint>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint & wxPoint::-=(wxPoint & p)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_sub_assign::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_sub_assign::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxPoint* p_ptr;
  if (!get_val_ptr_param<wxPoint>(p_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& p = *p_ptr;
  wxPoint & res =   (*this->_objectptr->GetObj()) -= (p);
  return AMILabType<wxPoint>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint & wxPoint::+=(wxSize & s)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_add_assign1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 's'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_add_assign1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxSize* s_ptr;
  if (!get_val_ptr_param<wxSize>(s_ptr,_p,_n)) ClassHelpAndReturn;
  wxSize& s = *s_ptr;
  wxPoint & res =   (*this->_objectptr->GetObj()) += (s);
  return AMILabType<wxPoint>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint & wxPoint::-=(wxSize & s)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_sub_assign1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 's'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_sub_assign1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxSize* s_ptr;
  if (!get_val_ptr_param<wxSize>(s_ptr,_p,_n)) ClassHelpAndReturn;
  wxSize& s = *s_ptr;
  wxPoint & res =   (*this->_objectptr->GetObj()) -= (s);
  return AMILabType<wxPoint>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxPoint::+(wxSize & s)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_add1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 's'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_add1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxSize* s_ptr;
  if (!get_val_ptr_param<wxSize>(s_ptr,_p,_n)) ClassHelpAndReturn;
  wxSize& s = *s_ptr;
  wxPoint res =   (*this->_objectptr->GetObj()) + (s);
  return AMILabType<wxPoint>::CreateVar(res);
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxPoint wxPoint::-(wxSize & s)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 's'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxSize* s_ptr;
  if (!get_val_ptr_param<wxSize>(s_ptr,_p,_n)) ClassHelpAndReturn;
  wxSize& s = *s_ptr;
  wxPoint res =   this->_objectptr->GetObj()->-(s);
  return AMILabType<wxPoint>::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxPoint wxPoint::-()
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_operator not available::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_operator not available::CallMember( ParamList* _p)
{
  wxPoint res =   this->_objectptr->GetObj()->-();
  return AMILabType<wxPoint>::CreateVar(res);
}
*/

