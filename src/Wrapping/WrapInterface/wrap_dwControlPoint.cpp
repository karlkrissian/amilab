/**
 * C++ Interface: wrap_dwControlPoint
 *
 * Description: wrapping of dwControlPoint
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_dwControlPoint.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "wrap_wxColour.h"

//
// static member for creating a variable from a pointer to dwControlPoint
//
Variable<AMIObject>::ptr WrapClass_dwControlPoint::CreateVar( dwControlPoint* sp)
{
  return 
    WrapClass<dwControlPoint>::CreateVar(
      new WrapClass_dwControlPoint(dwControlPoint::ptr(sp)));
}



//---------------------------------------------------
// Method that adds wrapping of dwControlPoint
//---------------------------------------------------

void  WrapClass_dwControlPoint::wrap_dwControlPoint::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(float,"X position (def:0).");
  ADDPARAMCOMMENT_TYPE(float,"Y position (def:0).");
  return_comments = "A wrapped dwControlPoint object.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlPoint::wrap_dwControlPoint::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(float,xpos,0);
  GET_PARAM(float,ypos,0);

  // Create smart pointer with own deleter
  dwControlPoint::ptr pt_ptr(new dwControlPoint(dw_Point2D(xpos,ypos)));

  return WrapClass<dwControlPoint>::CreateVar(new WrapClass_dwControlPoint(pt_ptr));
}

//---------------------------------------------------
//  GetX
//---------------------------------------------------
void WrapClass_dwControlPoint::
      wrap_GetX::SetParametersComments() 
{
  return_comments = "X position of the point";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlPoint::
      wrap_GetX::CallMember( ParamList* p)
{
  float xpos = this->_objectptr->GetObj()->GetX();
  RETURN_VAR(float,xpos);
}

//---------------------------------------------------
//  SetX
//---------------------------------------------------
void WrapClass_dwControlPoint::
      wrap_SetX::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(float,"X position (def:0).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlPoint::
      wrap_SetX::CallMember( ParamList* p)
{
  int n=0;
  GET_PARAM(float,xpos,0);
  this->_objectptr->GetObj()->SetX(xpos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetY
//---------------------------------------------------
void WrapClass_dwControlPoint::
      wrap_GetY::SetParametersComments() 
{
  return_comments = "Y position of the point";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlPoint::
      wrap_GetY::CallMember( ParamList* p)
{
  float ypos = this->_objectptr->GetObj()->GetY();
  RETURN_VAR(float,ypos);
}

//---------------------------------------------------
//  SetY
//---------------------------------------------------
void WrapClass_dwControlPoint::
      wrap_SetY::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(float,"Y position (def:0).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlPoint::
      wrap_SetY::CallMember( ParamList* p)
{
  int n=0;
  GET_PARAM(float,ypos,0);
  this->_objectptr->GetObj()->SetY(ypos);
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  GetHorizontalLine
//---------------------------------------------------
void WrapClass_dwControlPoint::
      wrap_GetHorizontalLine::SetParametersComments() 
{
  return_comments = "If horizontal line is enabled.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlPoint::
      wrap_GetHorizontalLine::CallMember( ParamList* p)
{
  bool hline = this->_objectptr->GetObj()->GetHorizontalLine();
  RETURN_VAR(unsigned char,hline);
}

//---------------------------------------------------
//  SetHorizontalLine
//---------------------------------------------------
void WrapClass_dwControlPoint::
      wrap_SetHorizontalLine::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(unsigned char,"Enable/Disable Horizontal line (def:1).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlPoint::
      wrap_SetHorizontalLine::CallMember( ParamList* p)
{
  int n=0;
  GET_PARAM(unsigned char,hline,0);
  this->_objectptr->GetObj()->SetHorizontalLine(hline);
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  GetVerticalLine
//---------------------------------------------------
void WrapClass_dwControlPoint::
      wrap_GetVerticalLine::SetParametersComments() 
{
  return_comments = "If Vertical line is enabled.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlPoint::
      wrap_GetVerticalLine::CallMember( ParamList* p)
{
  bool vline = this->_objectptr->GetObj()->GetVerticalLine();
  RETURN_VAR(unsigned char,vline);
}

//---------------------------------------------------
//  SetVerticalLine
//---------------------------------------------------
void WrapClass_dwControlPoint::
      wrap_SetVerticalLine::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(unsigned char,"Enable/Disable Vertical line (def:1).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlPoint::
      wrap_SetVerticalLine::CallMember( ParamList* p)
{
  int n=0;
  GET_PARAM(unsigned char,vline,0);
  this->_objectptr->GetObj()->SetVerticalLine(vline);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetType
//---------------------------------------------------
void WrapClass_dwControlPoint::
      wrap_GetType::SetParametersComments() 
{
  return_comments = "The point type 0: normal_point 1: colormap point.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlPoint::
      wrap_GetType::CallMember( ParamList* p)
{
  int ptype = this->_objectptr->GetObj()->GetType();
  RETURN_VAR(int,ptype);
}

//---------------------------------------------------
//  SetType
//---------------------------------------------------
void WrapClass_dwControlPoint::
      wrap_SetType::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"point type 0: normal_point 1: colormap_point (def:0).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlPoint::
      wrap_SetType::CallMember( ParamList* p)
{
  int n=0;
  GET_PARAM(int,ptype,0);
  this->_objectptr->GetObj()->SetType((ControlPointType) ptype);
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  GetColour
//---------------------------------------------------
void WrapClass_dwControlPoint::
      wrap_GetColour::SetParametersComments() 
{
  return_comments = "Colour of the point as a wxColour object";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlPoint::
      wrap_GetColour::CallMember( ParamList* p)
{
  wxColour* c = new wxColour(this->_objectptr->GetObj()->GetColour());
  return WrapClass_wxColour::CreateVar(c);
}

//---------------------------------------------------
//  SetColour
//---------------------------------------------------
void WrapClass_dwControlPoint::
      wrap_SetColour::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(wxColour,"New colour of the point.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlPoint::
      wrap_SetColour::CallMember( ParamList* p)
{
  int n=0;
  CLASS_GET_OBJECT_PARAM2(wxColour,var,varobj);
  if (varobj.get()) {
    this->_objectptr->GetObj()->SetColour( *varobj);
  }
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  copy
//---------------------------------------------------
void WrapClass_dwControlPoint::
      wrap_copy::SetParametersComments() 
{
  return_comments = "Copy of the dwControlPoint within a new variable.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlPoint::
      wrap_copy::CallMember( ParamList* p)
{
  return WrapClass_dwControlPoint::CreateVar( new dwControlPoint(*(_objectptr->_obj)));
}

//---------------------------------------------------
//  assign
//---------------------------------------------------
void WrapClass_dwControlPoint::
      wrap_assign::SetParametersComments() 
{
  return_comments = "dwControlPoint assignment operation.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlPoint::
      wrap_assign::CallMember( ParamList* p)
{
  int n = 0;
  CLASS_GET_OBJECT_PARAM2(dwControlPoint,var,_obj);

  if (_obj.get()) {
    this->_objectptr->_obj = _obj;
  }
  return BasicVariable::ptr();
}

