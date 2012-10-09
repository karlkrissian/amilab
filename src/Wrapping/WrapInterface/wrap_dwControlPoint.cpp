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

#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "wrap_wxColour.h"
#include "wrap_stdvector.h"



//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<dwControlPoint>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_dwControlPoint::wrap_dwControlPoint construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(dwControlPoint);
AMI_DEFINE_VARFROMSMTPTR(dwControlPoint);

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(std::vector<dwControlPoint>);
AMI_DEFINE_VARFROMSMTPTR_TEMPLATE(std::vector,StdVector,dwControlPoint);

//
// static member for creating a variable from a ParamList
// need to instanciate for each type ...
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<std::vector<dwControlPoint> >::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_StdVector<dwControlPoint>::wrap_StdVector construct;
  return construct.CallMember(p);
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
  dwControlPoint::ptr pt_ptr(new dwControlPoint(dwPoint2D(xpos,ypos)));
  return WrapClass<dwControlPoint>::CreateVar(new WrapClass_dwControlPoint(pt_ptr));
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
  return AMILabType<wxColour>::CreateVar(c);
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
  CLASS_GET_OBJECT_PARAM(wxColour,var,varobj);
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
  return AMILabType<dwControlPoint>::CreateVar( new dwControlPoint(*(_objectptr->_obj)));
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
  CLASS_GET_OBJECT_PARAM(dwControlPoint,var,_obj);

  if (_obj.get()) {
    this->_objectptr->_obj = _obj;
  }
  return BasicVariable::ptr();
}

