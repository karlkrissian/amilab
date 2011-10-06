/**
 * C++ Interface: wrap_ImageViewerBase
 *
 * Description: wrapping of ImageViewerBase
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_ImageViewerBase.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<ImageViewerBase>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_ImageViewerBase::wrap_ImageViewerBase construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(ImageViewerBase);
AMI_DEFINE_VARFROMSMTPTR(ImageViewerBase);


//---------------------------------------------------
// Method that adds wrapping of ImageViewerBase
//---------------------------------------------------

void  WrapClass_ImageViewerBase::wrap_ImageViewerBase::SetParametersComments() 
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ImageViewerBase::wrap_ImageViewerBase::CallMember( ParamList* p)
{
  // Create smart pointer with own deleter
  ImageViewerBase::ptr pt_ptr(new ImageViewerBase());
  return AMILabType<ImageViewerBase>::CreateVarFromSmtPtr(pt_ptr);
}

