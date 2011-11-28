/**
 * C++ Interface: wrap_RGBTransformHSV
 *
 * Description: wrapping of RGBTransformComponent
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2011
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_RGBTransformHSV.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<RGBTransformHSV>::CreateVar( ParamList* p, bool quiet)
{
  WrapClass_RGBTransformHSV::wrap_RGBTransformHSV construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(RGBTransformHSV);
AMI_DEFINE_VARFROMSMTPTR(RGBTransformHSV);


//---------------------------------------------------
// Method that adds wrapping of RGBTransformHSV
//---------------------------------------------------

void  WrapClass_RGBTransformHSV::wrap_RGBTransformHSV::SetParametersComments() 
{
  return_comments = "A wrapped RGBTransformComponent object.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_RGBTransformHSV::wrap_RGBTransformHSV::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  // Create smart pointer with own deleter
  RGBTransformHSV::ptr pt_ptr(new RGBTransformHSV());
  return AMILabType<RGBTransformHSV>::CreateVarFromSmtPtr(pt_ptr);
}



//---------------------------------------------------
//  copy
//---------------------------------------------------
void WrapClass_RGBTransformHSV::
      wrap_copy::SetParametersComments() 
{
  return_comments = "Copy of the RGBTransformHSV within a new variable.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_RGBTransformHSV::
      wrap_copy::CallMember( ParamList* p)
{
  return AMILabType<RGBTransformHSV>::CreateVar( new RGBTransformHSV(*(_objectptr->_obj)));
}

//---------------------------------------------------
//  assign
//---------------------------------------------------
void WrapClass_RGBTransformHSV::
      wrap_assign::SetParametersComments() 
{
  return_comments = "RGBTransformHSV assignment operation.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_RGBTransformHSV::
      wrap_assign::CallMember( ParamList* p)
{
  int n = 0;
  CLASS_GET_OBJECT_PARAM(RGBTransformHSV,var,_obj);

  if (_obj.get()) {
    this->_objectptr->_obj = _obj;
  }
  return BasicVariable::ptr();
}

