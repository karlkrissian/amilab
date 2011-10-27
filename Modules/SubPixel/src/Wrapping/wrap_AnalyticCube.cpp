/*
 *  wrap_AnalyticCube.cpp
 *  AMILab
 */

#include "wrap_AnalyticCube.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "AnalyticCube.h"

//---------------------------------------------------
//AnalyticCube Wrapping
//---------------------------------------------------

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<AnalyticCube>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_AnalyticCube::wrap_AnalyticCube construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(AnalyticCube);
AMI_DEFINE_VARFROMSMTPTR(AnalyticCube);

//---------------------------------------------------
//AnalyticCube Constructor
void WrapClass_AnalyticCube::wrap_AnalyticCube::SetParametersComments()
{
  ADDPARAMCOMMENT("Object of a type that inherit from AnalyticCube.");
  return_comments = "A wrapped AnalyticCube object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCube::
                   wrap_AnalyticCube::CallMember(ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  return AMILabType<AnalyticCube>::CreateVar(new AnalyticCube());
}

//---------------------------------------------------
//setDimX
void WrapClass_AnalyticCube::wrap_setDimX::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "The size on X dimension.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCube::
                   wrap_setDimX::CallMember(ParamList* p)
{
  AnalyticCube::ptr fd(this->_objectptr->GetObj());
  float dx;
  int   n = 0;
  
  if (!get_val_param<float>(dx, p, n)) ClassHelpAndReturn;
  
  fd->setDimX(dx);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getDimX
void WrapClass_AnalyticCube::wrap_getDimX::SetParametersComments()
{
  return_comments = "The X dimension size.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCube::
                   wrap_getDimX::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->getDimX());
}

//---------------------------------------------------
//setDimY
void WrapClass_AnalyticCube::wrap_setDimY::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "The size on Y dimension.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCube::
                   wrap_setDimY::CallMember(ParamList* p)
{
  AnalyticCube::ptr fd(this->_objectptr->GetObj());
  float dy;
  int   n = 0;
  
  if (!get_val_param<float>(dy, p, n)) ClassHelpAndReturn;
  
  fd->setDimY(dy);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getDimY
void WrapClass_AnalyticCube::wrap_getDimY::SetParametersComments()
{
  return_comments = "The Y dimension size.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCube::
                   wrap_getDimY::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->getDimY());
}

//---------------------------------------------------
//setDimZ
void WrapClass_AnalyticCube::wrap_setDimZ::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "The size on Z dimension.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCube::
                   wrap_setDimZ::CallMember(ParamList* p)
{
  AnalyticCube::ptr fd(this->_objectptr->GetObj());
  float dz;
  int   n = 0;
  
  if (!get_val_param<float>(dz, p, n)) ClassHelpAndReturn;
  
  fd->setDimZ(dz);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getDimZ
void WrapClass_AnalyticCube::wrap_getDimZ::SetParametersComments()
{
  return_comments = "The Z dimension size.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCube::
                   wrap_getDimZ::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->getDimZ());
}

//---------------------------------------------------
//setCenter
void WrapClass_AnalyticCube::wrap_setCenter::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "The x component of the center.");
  ADDPARAMCOMMENT_TYPE(float, "The y component of the center.");
  ADDPARAMCOMMENT_TYPE(float, "The z component of the center.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCube::
                   wrap_setCenter::CallMember(ParamList* p)
{
  AnalyticCube::ptr fd(this->_objectptr->GetObj());
  float xc, yc, zc;
  int n = 0;
  if (!get_val_param<float>(xc, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(yc, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(zc, p, n)) ClassHelpAndReturn;
  
  fd->setCenter(xc,yc,zc);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getCenter
void WrapClass_AnalyticCube::wrap_getCenter::SetParametersComments()
{
  return_comments = "The center of the cube.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCube::
                   wrap_getCenter::CallMember(ParamList* p)
{
  AnalyticCube::ptr fd(this->_objectptr->GetObj());
  int n=0;
  Variable<float>::ptr varc1;
  Variable<float>::ptr varc2;
  Variable<float>::ptr varc3;
  
  if (!get_var_param<float>(varc1,p,n)) ClassHelpAndReturn;
  if (!get_var_param<float>(varc2,p,n)) ClassHelpAndReturn;
  if (!get_var_param<float>(varc3,p,n)) ClassHelpAndReturn;
  if (!varc1->Pointer().get()) ClassHelpAndReturn;
  if (!varc2->Pointer().get()) ClassHelpAndReturn;
  if (!varc3->Pointer().get()) ClassHelpAndReturn;
  
  (*varc1->Pointer()) = fd->getCenter()[0];
  (*varc2->Pointer()) = fd->getCenter()[1];
  (*varc3->Pointer()) = fd->getCenter()[2];
  return BasicVariable::ptr();
}
