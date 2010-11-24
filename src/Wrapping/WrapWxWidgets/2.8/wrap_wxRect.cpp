/**
 * C++ Interface: wrap_wxRect
 *
 * Description: wrapping wxRect
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
#include "wrap_wxRect.h"
#include "wrap_wxPoint.h"
#include "wrap_wxSize.h"


#include "wrap_wxRect.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxRect>::CreateVar( ParamList* p)
{
  WrapClass_wxRect::wrap_wxRect construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxRect);
AMI_DEFINE_VARFROMSMTPTR(wxRect);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxRect
//
Variable<AMIObject>::ptr WrapClass_wxRect::CreateVar( wxRect* sp)
{
  boost::shared_ptr<wxRect> di_ptr(
    sp,
    wxwindow_nodeleter<wxRect>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxRect>::CreateVar(
      new WrapClass_wxRect(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxRect::AddMethods(WrapClass<wxRect>::ptr this_ptr )
{
  


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_GetX( this_ptr);
      AddVar_SetX( this_ptr);
      AddVar_GetY( this_ptr);
      AddVar_SetY( this_ptr);
      AddVar_GetWidth( this_ptr);
      AddVar_SetWidth( this_ptr);
      AddVar_GetHeight( this_ptr);
      AddVar_SetHeight( this_ptr);
      AddVar_GetPosition( this_ptr);
      AddVar_SetPosition( this_ptr);
      AddVar_GetSize( this_ptr);
      AddVar_SetSize( this_ptr);
      AddVar_IsEmpty( this_ptr);
      AddVar_GetLeft( this_ptr);
      AddVar_GetTop( this_ptr);
      AddVar_GetBottom( this_ptr);
      AddVar_GetRight( this_ptr);
      AddVar_SetLeft( this_ptr);
      AddVar_SetRight( this_ptr);
      AddVar_SetTop( this_ptr);
      AddVar_SetBottom( this_ptr);
      AddVar_GetTopLeft( this_ptr);
      AddVar_GetLeftTop( this_ptr);
      AddVar_SetTopLeft( this_ptr);
      AddVar_SetLeftTop( this_ptr);
      AddVar_GetBottomRight( this_ptr);
      AddVar_GetRightBottom( this_ptr);
      AddVar_SetBottomRight( this_ptr);
      AddVar_SetRightBottom( this_ptr);
      AddVar_GetTopRight( this_ptr);
      AddVar_GetRightTop( this_ptr);
      AddVar_SetTopRight( this_ptr);
      AddVar_SetRightTop( this_ptr);
      AddVar_GetBottomLeft( this_ptr);
      AddVar_GetLeftBottom( this_ptr);
      AddVar_SetBottomLeft( this_ptr);
      AddVar_SetLeftBottom( this_ptr);
      AddVar_Inflate_1( this_ptr);
      AddVar_Inflate( this_ptr);
      AddVar_Inflate_2( this_ptr);
      AddVar_Inflate_3( this_ptr);
      AddVar_Inflate_4( this_ptr);
      AddVar_Deflate_1( this_ptr);
      AddVar_Deflate( this_ptr);
      AddVar_Deflate_2( this_ptr);
      AddVar_Deflate_3( this_ptr);
      AddVar_Deflate_4( this_ptr);
      AddVar_Offset_1( this_ptr);
      AddVar_Offset( this_ptr);
      AddVar_Offset_2( this_ptr);
      AddVar_Intersect_1( this_ptr);
      AddVar_Intersect( this_ptr);
      AddVar_Intersect_2( this_ptr);
      AddVar_Union_1( this_ptr);
      AddVar_Union( this_ptr);
      AddVar_Union_2( this_ptr);
      AddVar_Contains_1( this_ptr);
      AddVar_Contains( this_ptr);
      AddVar_Contains_2( this_ptr);
      AddVar_Contains_3( this_ptr);
      AddVar_Intersects( this_ptr);
      AddVar_CentreIn( this_ptr);
      AddVar_CenterIn( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);
      AddVar___equal__( this_ptr);
      AddVar___not_equal__( this_ptr);
      AddVar___add__( this_ptr);
      AddVar___add_assign__( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      // Adding public member x
      boost::shared_ptr<int > var_x_ptr(&GetObj()->x, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_x = AMILabType<int >::CreateVarFromSmtPtr(var_x_ptr);
      if (var_x.get()) {
        var_x->Rename("x");
        context->AddVar(var_x,context);
      }
      
      // Adding public member y
      boost::shared_ptr<int > var_y_ptr(&GetObj()->y, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_y = AMILabType<int >::CreateVarFromSmtPtr(var_y_ptr);
      if (var_y.get()) {
        var_y->Rename("y");
        context->AddVar(var_y,context);
      }
      
      // Adding public member width
      boost::shared_ptr<int > var_width_ptr(&GetObj()->width, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_width = AMILabType<int >::CreateVarFromSmtPtr(var_width_ptr);
      if (var_width.get()) {
        var_width->Rename("width");
        context->AddVar(var_width,context);
      }
      
      // Adding public member height
      boost::shared_ptr<int > var_height_ptr(&GetObj()->height, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_height = AMILabType<int >::CreateVarFromSmtPtr(var_height_ptr);
      if (var_height.get()) {
        var_height->Rename("height");
        context->AddVar(var_height,context);
      }

};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxRect::wxRect(wxRect const & param0)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_wxRect_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_wxRect_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > param0_smtptr;
  if (!get_val_smtptr_param<wxRect >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxRect const & param0 = *param0_smtptr;

  wxRect* _newobj = new wxRect(param0);
  BasicVariable::ptr res = WrapClass_wxRect::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxRect::wxRect(...)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_wxRect::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_wxRect::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxRect::wrap_wxRect_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxRect::wrap_wxRect_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxRect::wrap_wxRect_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxRect::wrap_wxRect_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxRect::wrap_wxRect_5 m5;
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxRect::wrap_wxRect_6 m6;
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxRect::wxRect()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_wxRect_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_wxRect_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxRect* _newobj = new wxRect();
  BasicVariable::ptr res = WrapClass_wxRect::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxRect::wxRect(int xx, int yy, int ww, int hh)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_wxRect_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yy'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ww'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'hh'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_wxRect_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int xx;
  if (!get_val_param<int >(xx,_p,_n,true,true)) ClassReturnEmptyVar;

  int yy;
  if (!get_val_param<int >(yy,_p,_n,true,true)) ClassReturnEmptyVar;

  int ww;
  if (!get_val_param<int >(ww,_p,_n,true,true)) ClassReturnEmptyVar;

  int hh;
  if (!get_val_param<int >(hh,_p,_n,true,true)) ClassReturnEmptyVar;

  wxRect* _newobj = new wxRect(xx, yy, ww, hh);
  BasicVariable::ptr res = WrapClass_wxRect::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxRect::wxRect(wxPoint const & topLeft, wxPoint const & bottomRight)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_wxRect_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'topLeft'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'bottomRight'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_wxRect_4::CallMember( ParamList* _p)
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

  wxRect* _newobj = new wxRect(topLeft, bottomRight);
  BasicVariable::ptr res = WrapClass_wxRect::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxRect::wxRect(wxPoint const & pt, wxSize const & size)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_wxRect_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_wxRect_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  wxRect* _newobj = new wxRect(pt, size);
  BasicVariable::ptr res = WrapClass_wxRect::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxRect::wxRect(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_wxRect_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_wxRect_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  wxRect* _newobj = new wxRect(size);
  BasicVariable::ptr res = WrapClass_wxRect::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxRect.
//---------------------------------------------------
void WrapClass_wxRect::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxRect object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxRect >::CreateVar( new wxRect(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of int wxRect::GetX()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetX::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetX::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetX();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetX(int xx)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetX::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xx'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetX::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int xx;
  if (!get_val_param<int >(xx,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetX(xx);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxRect::GetY()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetY::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetY::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetY();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetY(int yy)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetY::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetY::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int yy;
  if (!get_val_param<int >(yy,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetY(yy);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxRect::GetWidth()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetWidth::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetWidth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetWidth();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetWidth(int w)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetWidth::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetWidth::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int w;
  if (!get_val_param<int >(w,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetWidth(w);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxRect::GetHeight()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetHeight::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetHeight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetHeight();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetHeight(int h)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetHeight::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetHeight::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int h;
  if (!get_val_param<int >(h,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetHeight(h);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxPoint wxRect::GetPosition()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetPosition::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetPosition::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint res =   this->_objectptr->GetObj()->GetPosition();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetPosition(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetPosition::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetPosition::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > p_smtptr;
  if (!get_val_smtptr_param<wxPoint >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & p = *p_smtptr;

  this->_objectptr->GetObj()->SetPosition(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxRect::GetSize()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetSize(wxSize const & s)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSize > s_smtptr;
  if (!get_val_smtptr_param<wxSize >(s_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSize const & s = *s_smtptr;

  this->_objectptr->GetObj()->SetSize(s);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxRect::IsEmpty()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_IsEmpty::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_IsEmpty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsEmpty();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of int wxRect::GetLeft()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetLeft::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetLeft::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetLeft();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxRect::GetTop()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetTop::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetTop::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetTop();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxRect::GetBottom()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetBottom::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetBottom::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetBottom();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxRect::GetRight()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetRight::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetRight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetRight();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetLeft(int left)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetLeft::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'left'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetLeft::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int left;
  if (!get_val_param<int >(left,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetLeft(left);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetRight(int right)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetRight::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'right'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetRight::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int right;
  if (!get_val_param<int >(right,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRight(right);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetTop(int top)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetTop::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'top'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetTop::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int top;
  if (!get_val_param<int >(top,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetTop(top);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetBottom(int bottom)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetBottom::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bottom'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetBottom::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int bottom;
  if (!get_val_param<int >(bottom,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetBottom(bottom);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxPoint wxRect::GetTopLeft()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetTopLeft::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetTopLeft::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint res =   this->_objectptr->GetObj()->GetTopLeft();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxRect::GetLeftTop()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetLeftTop::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetLeftTop::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint res =   this->_objectptr->GetObj()->GetLeftTop();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetTopLeft(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetTopLeft::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetTopLeft::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > p_smtptr;
  if (!get_val_smtptr_param<wxPoint >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & p = *p_smtptr;

  this->_objectptr->GetObj()->SetTopLeft(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetLeftTop(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetLeftTop::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetLeftTop::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > p_smtptr;
  if (!get_val_smtptr_param<wxPoint >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & p = *p_smtptr;

  this->_objectptr->GetObj()->SetLeftTop(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxPoint wxRect::GetBottomRight()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetBottomRight::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetBottomRight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint res =   this->_objectptr->GetObj()->GetBottomRight();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxRect::GetRightBottom()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetRightBottom::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetRightBottom::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint res =   this->_objectptr->GetObj()->GetRightBottom();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetBottomRight(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetBottomRight::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetBottomRight::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > p_smtptr;
  if (!get_val_smtptr_param<wxPoint >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & p = *p_smtptr;

  this->_objectptr->GetObj()->SetBottomRight(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetRightBottom(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetRightBottom::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetRightBottom::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > p_smtptr;
  if (!get_val_smtptr_param<wxPoint >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & p = *p_smtptr;

  this->_objectptr->GetObj()->SetRightBottom(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxPoint wxRect::GetTopRight()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetTopRight::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetTopRight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint res =   this->_objectptr->GetObj()->GetTopRight();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxRect::GetRightTop()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetRightTop::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetRightTop::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint res =   this->_objectptr->GetObj()->GetRightTop();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetTopRight(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetTopRight::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetTopRight::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > p_smtptr;
  if (!get_val_smtptr_param<wxPoint >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & p = *p_smtptr;

  this->_objectptr->GetObj()->SetTopRight(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetRightTop(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetRightTop::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetRightTop::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > p_smtptr;
  if (!get_val_smtptr_param<wxPoint >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & p = *p_smtptr;

  this->_objectptr->GetObj()->SetRightTop(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxPoint wxRect::GetBottomLeft()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetBottomLeft::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetBottomLeft::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint res =   this->_objectptr->GetObj()->GetBottomLeft();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxRect::GetLeftBottom()
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_GetLeftBottom::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_GetLeftBottom::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint res =   this->_objectptr->GetObj()->GetLeftBottom();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetBottomLeft(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetBottomLeft::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetBottomLeft::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > p_smtptr;
  if (!get_val_smtptr_param<wxPoint >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & p = *p_smtptr;

  this->_objectptr->GetObj()->SetBottomLeft(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxRect::SetLeftBottom(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_SetLeftBottom::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_SetLeftBottom::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > p_smtptr;
  if (!get_val_smtptr_param<wxPoint >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & p = *p_smtptr;

  this->_objectptr->GetObj()->SetLeftBottom(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxRect & wxRect::Inflate(wxCoord dx, wxCoord dy)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Inflate_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dy'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Inflate_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int dx;
  if (!get_val_param<int >(dx,_p,_n,true,true)) ClassReturnEmptyVar;

  int dy;
  if (!get_val_param<int >(dy,_p,_n,true,true)) ClassReturnEmptyVar;

  wxRect & res =   this->_objectptr->GetObj()->Inflate(dx, dy);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxRect::Inflate(...)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Inflate::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Inflate::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxRect::wrap_Inflate_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxRect::wrap_Inflate_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxRect::wrap_Inflate_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxRect::wrap_Inflate_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxRect & wxRect::Inflate(wxSize const & d)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Inflate_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'd'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Inflate_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > d_smtptr;
  if (!get_val_smtptr_param<wxSize >(d_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & d = *d_smtptr;

  wxRect & res =   this->_objectptr->GetObj()->Inflate(d);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRect & wxRect::Inflate(wxCoord d)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Inflate_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'd'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Inflate_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int d;
  if (!get_val_param<int >(d,_p,_n,true,true)) ClassReturnEmptyVar;

  wxRect & res =   this->_objectptr->GetObj()->Inflate(d);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRect wxRect::Inflate(wxCoord dx, wxCoord dy)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Inflate_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dy'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Inflate_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int dx;
  if (!get_val_param<int >(dx,_p,_n,true,true)) ClassReturnEmptyVar;

  int dy;
  if (!get_val_param<int >(dy,_p,_n,true,true)) ClassReturnEmptyVar;

  wxRect res =   this->_objectptr->GetObj()->Inflate(dx, dy);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRect & wxRect::Deflate(wxCoord dx, wxCoord dy)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Deflate_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dy'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Deflate_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int dx;
  if (!get_val_param<int >(dx,_p,_n,true,true)) ClassReturnEmptyVar;

  int dy;
  if (!get_val_param<int >(dy,_p,_n,true,true)) ClassReturnEmptyVar;

  wxRect & res =   this->_objectptr->GetObj()->Deflate(dx, dy);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxRect::Deflate(...)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Deflate::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Deflate::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxRect::wrap_Deflate_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxRect::wrap_Deflate_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxRect::wrap_Deflate_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxRect::wrap_Deflate_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxRect & wxRect::Deflate(wxSize const & d)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Deflate_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'd'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Deflate_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > d_smtptr;
  if (!get_val_smtptr_param<wxSize >(d_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & d = *d_smtptr;

  wxRect & res =   this->_objectptr->GetObj()->Deflate(d);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRect & wxRect::Deflate(wxCoord d)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Deflate_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'd'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Deflate_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int d;
  if (!get_val_param<int >(d,_p,_n,true,true)) ClassReturnEmptyVar;

  wxRect & res =   this->_objectptr->GetObj()->Deflate(d);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRect wxRect::Deflate(wxCoord dx, wxCoord dy)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Deflate_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dy'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Deflate_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int dx;
  if (!get_val_param<int >(dx,_p,_n,true,true)) ClassReturnEmptyVar;

  int dy;
  if (!get_val_param<int >(dy,_p,_n,true,true)) ClassReturnEmptyVar;

  wxRect res =   this->_objectptr->GetObj()->Deflate(dx, dy);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxRect::Offset(wxCoord dx, wxCoord dy)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Offset_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Offset_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int dx;
  if (!get_val_param<int >(dx,_p,_n,true,true)) ClassReturnEmptyVar;

  int dy;
  if (!get_val_param<int >(dy,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Offset(dx, dy);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxRect::Offset(...)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Offset::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Offset::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxRect::wrap_Offset_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxRect::wrap_Offset_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxRect::Offset(wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Offset_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Offset_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  this->_objectptr->GetObj()->Offset(pt);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxRect & wxRect::Intersect(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Intersect_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Intersect_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  wxRect & res =   this->_objectptr->GetObj()->Intersect(rect);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxRect::Intersect(...)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Intersect::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Intersect::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxRect::wrap_Intersect_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxRect::wrap_Intersect_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxRect wxRect::Intersect(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Intersect_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Intersect_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  wxRect res =   this->_objectptr->GetObj()->Intersect(rect);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRect & wxRect::Union(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Union_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Union_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  wxRect & res =   this->_objectptr->GetObj()->Union(rect);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxRect::Union(...)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Union::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Union::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxRect::wrap_Union_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxRect::wrap_Union_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxRect wxRect::Union(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Union_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Union_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  wxRect res =   this->_objectptr->GetObj()->Union(rect);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRect::Contains(int x, int y)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Contains_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Contains_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Contains(x, y);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxRect::Contains(...)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Contains::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Contains::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxRect::wrap_Contains_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxRect::wrap_Contains_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxRect::wrap_Contains_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxRect::Contains(wxPoint const & pt)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Contains_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pt'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Contains_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > pt_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pt_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & pt = *pt_smtptr;

  bool res =   this->_objectptr->GetObj()->Contains(pt);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxRect::Contains(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Contains_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Contains_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  bool res =   this->_objectptr->GetObj()->Contains(rect);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxRect::Intersects(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_Intersects::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_Intersects::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRect const & rect = *rect_smtptr;

  bool res =   this->_objectptr->GetObj()->Intersects(rect);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxRect wxRect::CentreIn(wxRect const & r, int dir = wxBOTH)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_CentreIn::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dir' (def:wxBOTH)")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_CentreIn::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRect > r_smtptr;
  if (!get_val_smtptr_param<wxRect >(r_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRect const & r = *r_smtptr;

  int dir = wxBOTH;
  if (!get_val_param<int >(dir,_p,_n,false,false)) ClassHelpAndReturn;

  wxRect res =   this->_objectptr->GetObj()->CentreIn(r, dir);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRect wxRect::CenterIn(wxRect const & r, int dir = wxBOTH)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap_CenterIn::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dir' (def:wxBOTH)")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap_CenterIn::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRect > r_smtptr;
  if (!get_val_smtptr_param<wxRect >(r_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRect const & r = *r_smtptr;

  int dir = wxBOTH;
  if (!get_val_param<int >(dir,_p,_n,false,false)) ClassHelpAndReturn;

  wxRect res =   this->_objectptr->GetObj()->CenterIn(r, dir);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRect & wxRect::operator =(wxRect const & param0)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'param0'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRect > param0_smtptr;
  if (!get_val_smtptr_param<wxRect >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRect const & param0 = *param0_smtptr;

  wxRect & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxRect::operator ==(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap___equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap___equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRect const & rect = *rect_smtptr;

  bool res =   (*this->_objectptr->GetObj()) == (rect);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxRect::operator !=(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap___not_equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap___not_equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRect const & rect = *rect_smtptr;

  bool res =   (*this->_objectptr->GetObj()) != (rect);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxRect wxRect::operator +(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap___add__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap___add__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRect const & rect = *rect_smtptr;

  wxRect res =   (*this->_objectptr->GetObj()) + (rect);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRect & wxRect::operator +=(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxRect::
    wrap___add_assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxRect::
    wrap___add_assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRect const & rect = *rect_smtptr;

  wxRect & res =   (*this->_objectptr->GetObj()) += (rect);
  return AMILabType<wxRect >::CreateVar(res);
}

