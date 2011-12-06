/**
 * C++ Interface: wrap_RGBTransformGamma
 *
 * Description: wrapping of RGBTransformComponent
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2011
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_RGBTransformGamma.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<RGBTransformGamma>::CreateVar( ParamList* p, 
                                                            bool quiet)
{
  WrapClass_RGBTransformGamma::wrap_RGBTransformGamma construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(RGBTransformGamma);
AMI_DEFINE_VARFROMSMTPTR(RGBTransformGamma);


//---------------------------------------------------
// Method that adds wrapping of RGBTransformGamma
//---------------------------------------------------

void  WrapClass_RGBTransformGamma::wrap_RGBTransformGamma::SetParametersComments() 
{
  return_comments = "A wrapped RGBTransformComponent object.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_RGBTransformGamma::wrap_RGBTransformGamma::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  // Create smart pointer with own deleter
  RGBTransformGamma::ptr pt_ptr(new RGBTransformGamma());
  return AMILabType<RGBTransformGamma>::CreateVarFromSmtPtr(pt_ptr);
}



//---------------------------------------------------
//  copy
//---------------------------------------------------
void WrapClass_RGBTransformGamma::
      wrap_copy::SetParametersComments() 
{
  return_comments = "Copy of the RGBTransformGamma within a new variable.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_RGBTransformGamma::
      wrap_copy::CallMember( ParamList* p)
{
  return AMILabType<RGBTransformGamma>::CreateVar( new RGBTransformGamma(*(_objectptr->_obj)));
}

//---------------------------------------------------
//  assign
//---------------------------------------------------
void WrapClass_RGBTransformGamma::
      wrap_assign::SetParametersComments() 
{
  return_comments = "RGBTransformGamma assignment operation.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_RGBTransformGamma::
      wrap_assign::CallMember( ParamList* p)
{
  int n = 0;
  CLASS_GET_OBJECT_PARAM(RGBTransformGamma,var,_obj);

  if (_obj.get()) {
    this->_objectptr->_obj = _obj;
  }
  return BasicVariable::ptr();
}

