/**
 * C++ Interface: wrap_RGBTransformComponent
 *
 * Description: wrapping of RGBTransformComponent
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2011
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_RGBTransformComponent.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<RGBTransformComponent>::CreateVar( ParamList* p)
{
  WrapClass_RGBTransformComponent::wrap_RGBTransformComponent construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(RGBTransformComponent);
AMI_DEFINE_VARFROMSMTPTR(RGBTransformComponent);


//---------------------------------------------------
// Method that adds wrapping of RGBTransformComponent
//---------------------------------------------------

void  WrapClass_RGBTransformComponent::wrap_RGBTransformComponent::SetParametersComments() 
{
  return_comments = "A wrapped RGBTransformComponent object.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_RGBTransformComponent::wrap_RGBTransformComponent::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  // Create smart pointer with own deleter
  RGBTransformComponent::ptr pt_ptr(new RGBTransformComponent());
  return AMILabType<RGBTransformComponent>::CreateVarFromSmtPtr(pt_ptr);
}



//---------------------------------------------------
//  copy
//---------------------------------------------------
void WrapClass_RGBTransformComponent::
      wrap_copy::SetParametersComments() 
{
  return_comments = "Copy of the RGBTransformComponent within a new variable.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_RGBTransformComponent::
      wrap_copy::CallMember( ParamList* p)
{
  return AMILabType<RGBTransformComponent>::CreateVar( new RGBTransformComponent(*(_objectptr->_obj)));
}

//---------------------------------------------------
//  assign
//---------------------------------------------------
void WrapClass_RGBTransformComponent::
      wrap_assign::SetParametersComments() 
{
  return_comments = "RGBTransformComponent assignment operation.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_RGBTransformComponent::
      wrap_assign::CallMember( ParamList* p)
{
  int n = 0;
  CLASS_GET_OBJECT_PARAM(RGBTransformComponent,var,_obj);

  if (_obj.get()) {
    *this->_objectptr->_obj = *_obj;
  }
  return BasicVariable::ptr();
}

