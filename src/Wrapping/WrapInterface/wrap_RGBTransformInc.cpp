/**
 * C++ Interface: wrap_RGBTransformInc
 *
 * Description: wrapping of RGBTransformComponent
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2011
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_RGBTransformInc.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<RGBTransformInc>::CreateVar( ParamList* p, bool quiet)
{
  WrapClass_RGBTransformInc::wrap_RGBTransformInc construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(RGBTransformInc);
AMI_DEFINE_VARFROMSMTPTR(RGBTransformInc);


//---------------------------------------------------
// Method that adds wrapping of RGBTransformInc
//---------------------------------------------------

void  WrapClass_RGBTransformInc::wrap_RGBTransformInc::SetParametersComments() 
{
  return_comments = "A wrapped RGBTransformComponent object.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_RGBTransformInc::wrap_RGBTransformInc::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  // Create smart pointer with own deleter
  RGBTransformInc::ptr pt_ptr(new RGBTransformInc());
  return AMILabType<RGBTransformInc>::CreateVarFromSmtPtr(pt_ptr);
}



//---------------------------------------------------
//  copy
//---------------------------------------------------
void WrapClass_RGBTransformInc::
      wrap_copy::SetParametersComments() 
{
  return_comments = "Copy of the RGBTransformInc within a new variable.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_RGBTransformInc::
      wrap_copy::CallMember( ParamList* p)
{
  return AMILabType<RGBTransformInc>::CreateVar( new RGBTransformInc(*(_objectptr->_obj)));
}

//---------------------------------------------------
//  assign
//---------------------------------------------------
void WrapClass_RGBTransformInc::
      wrap_assign::SetParametersComments() 
{
  return_comments = "RGBTransformInc assignment operation.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_RGBTransformInc::
      wrap_assign::CallMember( ParamList* p)
{
  int n = 0;
  CLASS_GET_OBJECT_PARAM(RGBTransformInc,var,_obj);

  if (_obj.get()) {
    this->_objectptr->_obj = _obj;
  }
  return BasicVariable::ptr();
}

