/**
 * C++ Interface: wrap_RGBTransformBase
 *
 * Description: wrapping of RGBTransformBase
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_RGBTransformBase.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<RGBTransformBase>::CreateVar( ParamList* p, bool quiet)
{
  WrapClass_RGBTransformBase::wrap_RGBTransformBase construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(RGBTransformBase);
AMI_DEFINE_VARFROMSMTPTR(RGBTransformBase);


//---------------------------------------------------
// Method that adds wrapping of RGBTransformBase
//---------------------------------------------------

void  WrapClass_RGBTransformBase::wrap_RGBTransformBase::SetParametersComments() 
{
  return_comments = "An empty variable since this class is abstract.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_RGBTransformBase::wrap_RGBTransformBase::CallMember( ParamList* p)
{
  return BasicVariable::ptr();
}



