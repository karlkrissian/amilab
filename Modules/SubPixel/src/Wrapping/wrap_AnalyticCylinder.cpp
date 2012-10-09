/*
 *  wrap_AnalyticCylinder.cpp
 *  AMILab
 */

#include "wrap_AnalyticCylinder.h"

#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "AnalyticCylinder.h"

//---------------------------------------------------
//AnalyticCylinder Wrapping
//---------------------------------------------------

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<AnalyticCylinder>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_AnalyticCylinder::wrap_AnalyticCylinder construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(AnalyticCylinder);
AMI_DEFINE_VARFROMSMTPTR(AnalyticCylinder);

//---------------------------------------------------
//AnalyticCylinder Constructor
void WrapClass_AnalyticCylinder::wrap_AnalyticCylinder::SetParametersComments()
{
  ADDPARAMCOMMENT("Object of a type that inherit from AnalyticCylinder.");
  return_comments = "A wrapped AnalyticCylinder object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCylinder::
                   wrap_AnalyticCylinder::CallMember(ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  return AMILabType<AnalyticCylinder>::CreateVar(new AnalyticCylinder());
}

//---------------------------------------------------
//setRadius
void WrapClass_AnalyticCylinder::wrap_setRadius::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "The cylinder radius size.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCylinder::
                   wrap_setRadius::CallMember(ParamList* p)
{
  AnalyticCylinder::ptr fd(this->_objectptr->GetObj());
  float r;
  int   n = 0;
  
  if (!get_val_param<float>(r, p, n)) ClassHelpAndReturn;
  
  fd->setRadius(r);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getRadius
void WrapClass_AnalyticCylinder::wrap_getRadius::SetParametersComments()
{
  return_comments = "The cylinder radius size.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCylinder::
                   wrap_getRadius::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->getRadius());
}

//---------------------------------------------------
//setXdir
void WrapClass_AnalyticCylinder::wrap_setXdir::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "The cylinder X direction.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCylinder::
                   wrap_setXdir::CallMember(ParamList* p)
{
  AnalyticCylinder::ptr fd(this->_objectptr->GetObj());
  float xd;
  int   n = 0;
  
  if (!get_val_param<float>(xd, p, n)) ClassHelpAndReturn;
  
  fd->setXdir(xd);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getXdir
void WrapClass_AnalyticCylinder::wrap_getXdir::SetParametersComments()
{
  return_comments = "The cylinder X direction.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCylinder::
                   wrap_getXdir::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->getXdir());
}

//---------------------------------------------------
//setYdir
void WrapClass_AnalyticCylinder::wrap_setYdir::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "The cylinder Y direction.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCylinder::
                   wrap_setYdir::CallMember(ParamList* p)
{
  AnalyticCylinder::ptr fd(this->_objectptr->GetObj());
  float yd;
  int   n = 0;
  
  if (!get_val_param<float>(yd, p, n)) ClassHelpAndReturn;
  
  fd->setYdir(yd);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getYdir
void WrapClass_AnalyticCylinder::wrap_getYdir::SetParametersComments()
{
  return_comments = "The cylinder Y direction.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCylinder::
                   wrap_getYdir::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->getYdir());
}

//---------------------------------------------------
//setZdir
void WrapClass_AnalyticCylinder::wrap_setZdir::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "The cylinder Z direction.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCylinder::
                   wrap_setZdir::CallMember(ParamList* p)
{
  AnalyticCylinder::ptr fd(this->_objectptr->GetObj());
  float zd;
  int   n = 0;
  
  if (!get_val_param<float>(zd, p, n)) ClassHelpAndReturn;
  
  fd->setZdir(zd);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getZdir
void WrapClass_AnalyticCylinder::wrap_getZdir::SetParametersComments()
{
  return_comments = "The cylinder Z direction.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCylinder::
                   wrap_getZdir::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->getZdir());
}
