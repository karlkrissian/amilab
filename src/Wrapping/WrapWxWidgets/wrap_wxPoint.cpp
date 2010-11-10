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


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxPoint);
AMI_DEFINE_VARFROMSMTPTR(wxPoint);


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
//  Wrapping of Constructor wxPoint::wxPoint(wxPoint const & param0)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_wxPoint1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_wxPoint1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  wxPoint* param0_ptr;
  if (!get_val_ptr_param<wxPoint>(param0_ptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxPoint& param0 = *param0_ptr;
  wxPoint* _newobj = new wxPoint(param0);
  BasicVariable::ptr res = WrapClass_wxPoint::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxPoint::wxPoint(...)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_wxPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_wxPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxPoint::wrap_wxPoint1 m1;
  res = m1.CallMember(_p);
  if (res.get()) return res;
  WrapClass_wxPoint::wrap_wxPoint2 m2;
  res = m2.CallMember(_p);
  if (res.get()) return res;
  WrapClass_wxPoint::wrap_wxPoint3 m3;
  res = m3.CallMember(_p);
  if (res.get()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxPoint::wxPoint()
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_wxPoint2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_wxPoint2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;
  wxPoint* _newobj = new wxPoint();
  BasicVariable::ptr res = WrapClass_wxPoint::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxPoint::wxPoint(int xx, int yy)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_wxPoint3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_wxPoint3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;
  int xx;
  if (!get_val_param<int>(xx,_p,_n)) ClassReturnEmptyVar;
  int yy;
  if (!get_val_param<int>(yy,_p,_n)) ClassReturnEmptyVar;
  wxPoint* _newobj = new wxPoint(xx, yy);
  BasicVariable::ptr res = WrapClass_wxPoint::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxPoint & wxPoint::=(wxPoint const & param0)
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  wxPoint* param0_ptr;
  if (!get_val_ptr_param<wxPoint>(param0_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& param0 = *param0_ptr;
  wxPoint & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxPoint>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxPoint::==(wxPoint const & p)
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  wxPoint* p_ptr;
  if (!get_val_ptr_param<wxPoint>(p_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& p = *p_ptr;
  bool res =   (*this->_objectptr->GetObj()) == (p);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxPoint::!=(wxPoint const & p)
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  wxPoint* p_ptr;
  if (!get_val_ptr_param<wxPoint>(p_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& p = *p_ptr;
  bool res =   (*this->_objectptr->GetObj()) != (p);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxPoint::+(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_add1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_add1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  wxPoint* p_ptr;
  if (!get_val_ptr_param<wxPoint>(p_ptr,_p,_n)) ClassReturnEmptyVar;
  wxPoint& p = *p_ptr;
  wxPoint res =   (*this->_objectptr->GetObj()) + (p);
  return AMILabType<wxPoint>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxPoint::-(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_op_substract1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_op_substract1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  wxPoint* p_ptr;
  if (!get_val_ptr_param<wxPoint>(p_ptr,_p,_n)) ClassReturnEmptyVar;
  wxPoint& p = *p_ptr;
  wxPoint res =   (*this->_objectptr->GetObj()) - (p);
  return AMILabType<wxPoint>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint & wxPoint::+=(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_add_assign1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_add_assign1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  wxPoint* p_ptr;
  if (!get_val_ptr_param<wxPoint>(p_ptr,_p,_n)) ClassReturnEmptyVar;
  wxPoint& p = *p_ptr;
  wxPoint & res =   (*this->_objectptr->GetObj()) += (p);
  return AMILabType<wxPoint>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint & wxPoint::-=(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_sub_assign1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_sub_assign1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  wxPoint* p_ptr;
  if (!get_val_ptr_param<wxPoint>(p_ptr,_p,_n)) ClassReturnEmptyVar;
  wxPoint& p = *p_ptr;
  wxPoint & res =   (*this->_objectptr->GetObj()) -= (p);
  return AMILabType<wxPoint>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxPoint::+=(...)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_add_assign::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_add_assign::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxPoint::wrap_add_assign1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (res.get()) return res;
  WrapClass_wxPoint::wrap_add_assign2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (res.get()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxPoint & wxPoint::+=(wxSize const & s)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_add_assign2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 's'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_add_assign2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  wxSize* s_ptr;
  if (!get_val_ptr_param<wxSize>(s_ptr,_p,_n)) ClassReturnEmptyVar;
  wxSize& s = *s_ptr;
  wxPoint & res =   (*this->_objectptr->GetObj()) += (s);
  return AMILabType<wxPoint>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxPoint::-=(...)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_sub_assign::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_sub_assign::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxPoint::wrap_sub_assign1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (res.get()) return res;
  WrapClass_wxPoint::wrap_sub_assign2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (res.get()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxPoint & wxPoint::-=(wxSize const & s)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_sub_assign2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 's'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_sub_assign2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  wxSize* s_ptr;
  if (!get_val_ptr_param<wxSize>(s_ptr,_p,_n)) ClassReturnEmptyVar;
  wxSize& s = *s_ptr;
  wxPoint & res =   (*this->_objectptr->GetObj()) -= (s);
  return AMILabType<wxPoint>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxPoint::+(...)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_add::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_add::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxPoint::wrap_add1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (res.get()) return res;
  WrapClass_wxPoint::wrap_add2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (res.get()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxPoint wxPoint::+(wxSize const & s)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_add2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 's'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_add2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  wxSize* s_ptr;
  if (!get_val_ptr_param<wxSize>(s_ptr,_p,_n)) ClassReturnEmptyVar;
  wxSize& s = *s_ptr;
  wxPoint res =   (*this->_objectptr->GetObj()) + (s);
  return AMILabType<wxPoint>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxPoint::-(...)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_op_substract::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_op_substract::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxPoint::wrap_op_substract1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (res.get()) return res;
  WrapClass_wxPoint::wrap_op_substract2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (res.get()) return res;
  WrapClass_wxPoint::wrap_op_substract3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (res.get()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxPoint wxPoint::-(wxSize const & s)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_op_substract2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 's'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_op_substract2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  wxSize* s_ptr;
  if (!get_val_ptr_param<wxSize>(s_ptr,_p,_n)) ClassReturnEmptyVar;
  wxSize& s = *s_ptr;
  wxPoint res =   (*this->_objectptr->GetObj()) - (s);
  return AMILabType<wxPoint>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxPoint::-()
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_op_substract3::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_op_substract3::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;
  wxPoint res =  - (*this->_objectptr->GetObj());
  return AMILabType<wxPoint>::CreateVar(res);
}

