/*
 *  wrap_AnalyticPlane.cpp
 *  AMILab
 */

#include "wrap_AnalyticPlane.h"

#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "AnalyticPlane.h"

//---------------------------------------------------
//AnalyticPlane Wrapping
//---------------------------------------------------

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<AnalyticPlane>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_AnalyticPlane::wrap_AnalyticPlane construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(AnalyticPlane);
AMI_DEFINE_VARFROMSMTPTR(AnalyticPlane);

//---------------------------------------------------
//AnalyticCylinder Constructor
void WrapClass_AnalyticPlane::wrap_AnalyticPlane::SetParametersComments()
{
  ADDPARAMCOMMENT("Object of a type that inherit from AnalyticPlane.");
  return_comments = "A wrapped AnalyticPlane object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticPlane::
                   wrap_AnalyticPlane::CallMember(ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  return AMILabType<AnalyticPlane>::CreateVar(new AnalyticPlane());
}

//---------------------------------------------------
//setP1
void WrapClass_AnalyticPlane::wrap_setP1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "X component of the point.");
  ADDPARAMCOMMENT_TYPE(float, "Y component of the point.");
  ADDPARAMCOMMENT_TYPE(float, "Z component of the point");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticPlane::
                   wrap_setP1::CallMember(ParamList* p)
{
  AnalyticPlane::ptr fd(this->_objectptr->GetObj());
  float x, y, z;
  int   n = 0;
  
  if (!get_val_param<float>(x, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(y, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(z, p, n)) ClassHelpAndReturn;
  
  fd->setP1(x,y,z);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//setP2
void WrapClass_AnalyticPlane::wrap_setP2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "X component of the point.");
  ADDPARAMCOMMENT_TYPE(float, "Y component of the point.");
  ADDPARAMCOMMENT_TYPE(float, "Z component of the point");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticPlane::
                   wrap_setP2::CallMember(ParamList* p)
{
  AnalyticPlane::ptr fd(this->_objectptr->GetObj());
  float x, y, z;
  int   n = 0;
  
  if (!get_val_param<float>(x, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(y, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(z, p, n)) ClassHelpAndReturn;
  
  fd->setP2(x,y,z);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//setP3
void WrapClass_AnalyticPlane::wrap_setP3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "X component of the point.");
  ADDPARAMCOMMENT_TYPE(float, "Y component of the point.");
  ADDPARAMCOMMENT_TYPE(float, "Z component of the point");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticPlane::
                   wrap_setP3::CallMember(ParamList* p)
{
  AnalyticPlane::ptr fd(this->_objectptr->GetObj());
  float x, y, z;
  int   n = 0;
  
  if (!get_val_param<float>(x, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(y, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(z, p, n)) ClassHelpAndReturn;
  
  fd->setP3(x,y,z);
  return BasicVariable::ptr();
}
