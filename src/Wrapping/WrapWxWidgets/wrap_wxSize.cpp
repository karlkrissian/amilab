/**
 * C++ Interface: wrap_wxSize
 *
 * Description: wrapping wxSize
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_wxSize.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxSize.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxSize>::CreateVar( ParamList* p)
{
  WrapClass_wxSize::wrap_wxSize construct;
  return construct.CallMember(p);
}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxSize);
AMI_DEFINE_VARFROMSMTPTR(wxSize);


//
// static member for creating a variable from a pointer to wxSize
//
Variable<AMIObject>::ptr WrapClass_wxSize::CreateVar( wxSize* sp)
{
  boost::shared_ptr<wxSize> di_ptr(
    sp,
    wxwindow_nodeleter<wxSize>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxSize>::CreateVar(
      new WrapClass_wxSize(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor wxSize::wxSize(wxSize const & param0)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_wxSize1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_wxSize1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  boost::shared_ptr<wxSize> param0_smtptr;
  if (!get_val_smtptr_param<wxSize>(param0_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxSize& param0 = *param0_smtptr;
  wxSize* _newobj = new wxSize(param0);
  BasicVariable::ptr res = WrapClass_wxSize::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxSize::wxSize(...)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_wxSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_wxSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSize::wrap_wxSize1 m1;
  res = m1.CallMember(_p);
  if (res.get()) return res;
  WrapClass_wxSize::wrap_wxSize2 m2;
  res = m2.CallMember(_p);
  if (res.get()) return res;
  WrapClass_wxSize::wrap_wxSize3 m3;
  res = m3.CallMember(_p);
  if (res.get()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxSize::wxSize()
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_wxSize2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_wxSize2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;
  wxSize* _newobj = new wxSize();
  BasicVariable::ptr res = WrapClass_wxSize::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxSize::wxSize(int xx, int yy)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_wxSize3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_wxSize3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;
  int xx;
  if (!get_val_param<int>(xx,_p,_n)) ClassReturnEmptyVar;
  int yy;
  if (!get_val_param<int>(yy,_p,_n)) ClassReturnEmptyVar;
  wxSize* _newobj = new wxSize(xx, yy);
  BasicVariable::ptr res = WrapClass_wxSize::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxSize.
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_copy::SetParametersComments()
{
  return_comments="A copy of the wxSize object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_copy::CallMember( ParamList* _p)
{
    return AMILabType<wxSize>::CreateVar( new wxSize(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxSize::IncTo(wxSize const & sz)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_IncTo::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_IncTo::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  boost::shared_ptr<wxSize> sz_smtptr;
  if (!get_val_smtptr_param<wxSize>(sz_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize& sz = *sz_smtptr;
  this->_objectptr->GetObj()->IncTo(sz);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSize::DecTo(wxSize const & sz)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_DecTo::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_DecTo::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  boost::shared_ptr<wxSize> sz_smtptr;
  if (!get_val_smtptr_param<wxSize>(sz_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize& sz = *sz_smtptr;
  this->_objectptr->GetObj()->DecTo(sz);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSize::IncBy(int dx, int dy)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_IncBy1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_IncBy1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;
  int dx;
  if (!get_val_param<int>(dx,_p,_n)) ClassReturnEmptyVar;
  int dy;
  if (!get_val_param<int>(dy,_p,_n)) ClassReturnEmptyVar;
  this->_objectptr->GetObj()->IncBy(dx, dy);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSize::IncBy(...)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_IncBy::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_IncBy::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSize::wrap_IncBy1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (res.get()) return res;
  WrapClass_wxSize::wrap_IncBy2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (res.get()) return res;
  WrapClass_wxSize::wrap_IncBy3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (res.get()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxSize::IncBy(wxSize const & sz)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_IncBy2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_IncBy2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  boost::shared_ptr<wxSize> sz_smtptr;
  if (!get_val_smtptr_param<wxSize>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSize& sz = *sz_smtptr;
  this->_objectptr->GetObj()->IncBy(sz);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSize::IncBy(int d)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_IncBy3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'd'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_IncBy3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  int d;
  if (!get_val_param<int>(d,_p,_n)) ClassReturnEmptyVar;
  this->_objectptr->GetObj()->IncBy(d);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSize::DecBy(int dx, int dy)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_DecBy1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_DecBy1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;
  int dx;
  if (!get_val_param<int>(dx,_p,_n)) ClassReturnEmptyVar;
  int dy;
  if (!get_val_param<int>(dy,_p,_n)) ClassReturnEmptyVar;
  this->_objectptr->GetObj()->DecBy(dx, dy);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSize::DecBy(...)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_DecBy::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_DecBy::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSize::wrap_DecBy1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (res.get()) return res;
  WrapClass_wxSize::wrap_DecBy2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (res.get()) return res;
  WrapClass_wxSize::wrap_DecBy3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (res.get()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxSize::DecBy(wxSize const & sz)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_DecBy2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_DecBy2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  boost::shared_ptr<wxSize> sz_smtptr;
  if (!get_val_smtptr_param<wxSize>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSize& sz = *sz_smtptr;
  this->_objectptr->GetObj()->DecBy(sz);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSize::DecBy(int d)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_DecBy3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'd'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_DecBy3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  int d;
  if (!get_val_param<int>(d,_p,_n)) ClassReturnEmptyVar;
  this->_objectptr->GetObj()->DecBy(d);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize & wxSize::Scale(float xscale, float yscale)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_Scale::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'xscale'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'yscale'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_Scale::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;
  float xscale;
  if (!get_val_param<float>(xscale,_p,_n)) ClassHelpAndReturn;
  float yscale;
  if (!get_val_param<float>(yscale,_p,_n)) ClassHelpAndReturn;
  wxSize & res =   this->_objectptr->GetObj()->Scale(xscale, yscale);
  return AMILabType<wxSize>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxSize::Set(int xx, int yy)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_Set::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_Set::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;
  int xx;
  if (!get_val_param<int>(xx,_p,_n)) ClassHelpAndReturn;
  int yy;
  if (!get_val_param<int>(yy,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->Set(xx, yy);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSize::SetWidth(int w)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_SetWidth::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_SetWidth::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  int w;
  if (!get_val_param<int>(w,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetWidth(w);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSize::SetHeight(int h)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_SetHeight::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_SetHeight::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  int h;
  if (!get_val_param<int>(h,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetHeight(h);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxSize::GetWidth()
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_GetWidth::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_GetWidth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  int res =   this->_objectptr->GetObj()->GetWidth();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxSize::GetHeight()
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_GetHeight::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_GetHeight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  int res =   this->_objectptr->GetObj()->GetHeight();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxSize::IsFullySpecified()
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_IsFullySpecified::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_IsFullySpecified::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  bool res =   this->_objectptr->GetObj()->IsFullySpecified();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxSize::SetDefaults(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_SetDefaults::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_SetDefaults::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  boost::shared_ptr<wxSize> size_smtptr;
  if (!get_val_smtptr_param<wxSize>(size_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize& size = *size_smtptr;
  this->_objectptr->GetObj()->SetDefaults(size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxSize::GetX()
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_GetX::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_GetX::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  int res =   this->_objectptr->GetObj()->GetX();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxSize::GetY()
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_GetY::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_GetY::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  int res =   this->_objectptr->GetObj()->GetY();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSize & wxSize::=(wxSize const & param0)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_assign::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'param0'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_assign::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  boost::shared_ptr<wxSize> param0_smtptr;
  if (!get_val_smtptr_param<wxSize>(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize& param0 = *param0_smtptr;
  wxSize & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxSize>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxSize::==(wxSize const & sz)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_equal::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_equal::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  boost::shared_ptr<wxSize> sz_smtptr;
  if (!get_val_smtptr_param<wxSize>(sz_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize& sz = *sz_smtptr;
  bool res =   (*this->_objectptr->GetObj()) == (sz);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxSize::!=(wxSize const & sz)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_not_equal::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_not_equal::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  boost::shared_ptr<wxSize> sz_smtptr;
  if (!get_val_smtptr_param<wxSize>(sz_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize& sz = *sz_smtptr;
  bool res =   (*this->_objectptr->GetObj()) != (sz);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxSize wxSize::+(wxSize const & sz)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_add::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_add::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  boost::shared_ptr<wxSize> sz_smtptr;
  if (!get_val_smtptr_param<wxSize>(sz_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize& sz = *sz_smtptr;
  wxSize res =   (*this->_objectptr->GetObj()) + (sz);
  return AMILabType<wxSize>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSize wxSize::-(wxSize const & sz)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_op_substract::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_op_substract::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  boost::shared_ptr<wxSize> sz_smtptr;
  if (!get_val_smtptr_param<wxSize>(sz_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize& sz = *sz_smtptr;
  wxSize res =   (*this->_objectptr->GetObj()) - (sz);
  return AMILabType<wxSize>::CreateVar(res);
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxSize wxSize::/(int i)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  int i;
  if (!get_val_param<int>(i,_p,_n)) ClassHelpAndReturn;
  wxSize res =   this->_objectptr->GetObj()->/(i);
  return AMILabType<wxSize>::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxSize wxSize::*(int i)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  int i;
  if (!get_val_param<int>(i,_p,_n)) ClassHelpAndReturn;
  wxSize res =   this->_objectptr->GetObj()->*(i);
  return AMILabType<wxSize>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxSize & wxSize::+=(wxSize const & sz)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_add_assign::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_add_assign::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  boost::shared_ptr<wxSize> sz_smtptr;
  if (!get_val_smtptr_param<wxSize>(sz_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize& sz = *sz_smtptr;
  wxSize & res =   (*this->_objectptr->GetObj()) += (sz);
  return AMILabType<wxSize>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSize & wxSize::-=(wxSize const & sz)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_sub_assign::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'sz'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_sub_assign::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  boost::shared_ptr<wxSize> sz_smtptr;
  if (!get_val_smtptr_param<wxSize>(sz_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize& sz = *sz_smtptr;
  wxSize & res =   (*this->_objectptr->GetObj()) -= (sz);
  return AMILabType<wxSize>::CreateVar(res);
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxSize & wxSize::/=(int const i)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  int i;
  if (!get_val_param<int>(i,_p,_n)) ClassHelpAndReturn;
  wxSize & res =   this->_objectptr->GetObj()->/=(i);
  return AMILabType<wxSize>::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxSize & wxSize::*=(int const i)
//---------------------------------------------------
void WrapClass_wxSize::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  int i;
  if (!get_val_param<int>(i,_p,_n)) ClassHelpAndReturn;
  wxSize & res =   this->_objectptr->GetObj()->*=(i);
  return AMILabType<wxSize>::CreateVar(res);
}
*/

