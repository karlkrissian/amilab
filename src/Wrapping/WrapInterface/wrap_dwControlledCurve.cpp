/**
 * C++ Interface: wrap_dwControlledCurve
 *
 * Description: wrapping of dwControlledCurve
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_dwControlledCurve.h"

#ifdef _AMIPREC_
  #include "WrapInterface_header.h"
#else
  #include "VarContexts.hpp"
  #include "wrapfunctions.hpp"
  #include "ami_class.h"
  #include "ami_object.h"
  #include "ami_function.h"
#endif

//#include "wrap_wxColour.h"
#include "wrap_stdvector.h"



//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<dwControlledCurve>::CreateVar( ParamList* p)
{
  WrapClass_dwControlledCurve::wrap_dwControlledCurve construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(dwControlledCurve);
AMI_DEFINE_VARFROMSMTPTR(dwControlledCurve);

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(std::vector<dwControlledCurve>);
AMI_DEFINE_VARFROMSMTPTR_TEMPLATE(std::vector,StdVector,dwControlledCurve);

//
// static member for creating a variable from a ParamList
// need to instanciate for each type ...
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<std::vector<dwControlledCurve> >::CreateVar( ParamList* p)
{
  WrapClass_StdVector<dwControlledCurve>::wrap_StdVector construct;
  return construct.CallMember(p);
}

//---------------------------------------------------
// Method that adds wrapping of dwControlledCurve
//---------------------------------------------------

void  WrapClass_dwControlledCurve::wrap_dwControlledCurve::SetParametersComments() 
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlledCurve::wrap_dwControlledCurve::CallMember( ParamList* p)
{
  // Create smart pointer with own deleter
  dwControlledCurve::ptr pt_ptr(new dwControlledCurve());
  return WrapClass<dwControlledCurve>::CreateVar(new WrapClass_dwControlledCurve(pt_ptr));
}


//---------------------------------------------------
//  GetControlPoints
//---------------------------------------------------
void WrapClass_dwControlledCurve::
      wrap_GetControlPoints::SetParametersComments() 
{
  return_comments = "The std::vector of dwControlPoints.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlledCurve::
      wrap_GetControlPoints::CallMember( ParamList* p)
{
  boost::shared_ptr<std::vector<dwControlPoint> > obj_ptr = _objectptr->GetObj()->GetControlPoints();
  return AMILabType<std::vector<dwControlPoint> >::CreateVarFromSmtPtr(obj_ptr);
}

//---------------------------------------------------
//  copy
//---------------------------------------------------
void WrapClass_dwControlledCurve::
      wrap_copy::SetParametersComments() 
{
  return_comments = "Copy of the dwControlledCurve within a new variable.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlledCurve::
      wrap_copy::CallMember( ParamList* p)
{
  return AMILabType<dwControlledCurve>::CreateVar( new dwControlledCurve(*(_objectptr->_obj)));
}

//---------------------------------------------------
//  assign
//---------------------------------------------------
void WrapClass_dwControlledCurve::
      wrap_assign::SetParametersComments() 
{
  return_comments = "dwControlledCurve assignment operation.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_dwControlledCurve::
      wrap_assign::CallMember( ParamList* p)
{
  int n = 0;
  CLASS_GET_OBJECT_PARAM(dwControlledCurve,var,_obj);

  if (_obj.get()) {
    this->_objectptr->_obj = _obj;
  }
  return BasicVariable::ptr();
}

