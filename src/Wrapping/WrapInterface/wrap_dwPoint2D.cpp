/**
 * C++ Interface: wrap_dwPoint2D
 *
 * Description: wrapping of dwPoint2D
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_dwPoint2D.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<dwPoint2D>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_dwPoint2D::wrap_dwPoint2D construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(dwPoint2D);
AMI_DEFINE_VARFROMSMTPTR(dwPoint2D);


//---------------------------------------------------
// Method that adds wrapping of dwPoint2D
//---------------------------------------------------

void  WrapClass_dwPoint2D::wrap_dwPoint2D::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(double,"X position (def:0).");
  ADDPARAMCOMMENT_TYPE(double,"Y position (def:0).");
  return_comments = "A wrapped dwPoint2D object.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_dwPoint2D::wrap_dwPoint2D::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(double,xpos,0);
  GET_PARAM(double,ypos,0);

  // Create smart pointer with own deleter
  dwPoint2D::ptr pt_ptr(new dwPoint2D(dwPoint2D(xpos,ypos)));
  return AMILabType<dwPoint2D>::CreateVarFromSmtPtr(pt_ptr);
}



//---------------------------------------------------
//  copy
//---------------------------------------------------
void WrapClass_dwPoint2D::
      wrap_copy::SetParametersComments() 
{
  return_comments = "Copy of the dwPoint2D within a new variable.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwPoint2D::
      wrap_copy::CallMember( ParamList* p)
{
  return AMILabType<dwPoint2D>::CreateVar( new dwPoint2D(*(_objectptr->_obj)));
}

//---------------------------------------------------
//  assign
//---------------------------------------------------
void WrapClass_dwPoint2D::
      wrap_assign::SetParametersComments() 
{
  return_comments = "dwPoint2D assignment operation.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwPoint2D::
      wrap_assign::CallMember( ParamList* p)
{
  int n = 0;
  CLASS_GET_OBJECT_PARAM(dwPoint2D,var,_obj);

  if (_obj.get()) {
    this->_objectptr->_obj = _obj;
  }
  return BasicVariable::ptr();
}

