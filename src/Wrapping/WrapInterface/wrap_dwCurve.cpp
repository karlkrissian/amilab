/**
 * C++ Interface: wrap_dwCurve
 *
 * Description: wrapping of dwCurve
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_dwCurve.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "wrap_stdvector.h"

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<dwCurve>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_dwCurve::wrap_dwCurve construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(dwCurve);
AMI_DEFINE_VARFROMSMTPTR(dwCurve);

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(std::vector<dwCurve>);
AMI_DEFINE_VARFROMSMTPTR_TEMPLATE(std::vector,StdVector,dwCurve);

//
// static member for creating a variable from a ParamList
// need to instanciate for each type ...
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<std::vector<dwCurve> >::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_StdVector<dwCurve>::wrap_StdVector construct;
  return construct.CallMember(p);
}

//---------------------------------------------------
// Method that adds wrapping of dwCurve
//---------------------------------------------------

void  WrapClass_dwCurve::wrap_dwCurve::SetParametersComments() 
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_dwCurve::wrap_dwCurve::CallMember( ParamList* p)
{
  dwCurve::ptr pt_ptr(new dwCurve(dwCurve()));
  return AMILabType<dwCurve>::CreateVarFromSmtPtr(pt_ptr);
}



//---------------------------------------------------
//  copy
//---------------------------------------------------
void WrapClass_dwCurve::
      wrap_copy::SetParametersComments() 
{
  return_comments = "Copy of the dwCurve within a new variable.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwCurve::
      wrap_copy::CallMember( ParamList* p)
{
  return AMILabType<dwCurve>::CreateVar( new dwCurve(*(_objectptr->_obj)));
}

//---------------------------------------------------
//  assign
//---------------------------------------------------
void WrapClass_dwCurve::
      wrap_assign::SetParametersComments() 
{
  return_comments = "dwCurve assignment operation.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwCurve::
      wrap_assign::CallMember( ParamList* p)
{
  int n = 0;
  CLASS_GET_OBJECT_PARAM(dwCurve,var,_obj);

  if (_obj.get()) {
    this->_objectptr->_obj = _obj;
  }
  return BasicVariable::ptr();
}

