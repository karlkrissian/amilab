/*
 *  wrap_AnalyticSphere.cpp
 *  AMILab
 */

#include "wrap_AnalyticSphere.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "AnalyticSphere.h"

//---------------------------------------------------
//AnalyticSphere Wrapping
//---------------------------------------------------

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<AnalyticSphere>::CreateVar( ParamList* p )
{
  WrapClass_AnalyticSphere::wrap_AnalyticSphere construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(AnalyticSphere);
AMI_DEFINE_VARFROMSMTPTR(AnalyticSphere);

//AMIObject::ptr AddWrap_AnalyticSphere(WrapClass_AnalyticSphere::ptr& objectptr)
//{
//  // Create a new instance of the class
//  AMIObject::ptr amiobject(new AMIObject);
//  amiobject->SetName("AnalyticSphere");
//  amiobject->SetWrappedObject(objectptr);
//  objectptr->SetAMIObject(amiobject);
//  objectptr->AddMethods(objectptr);
//  return amiobject;
//}
//
////---------------------------------------------------
//Variable<AMIObject>::ptr CreateVar_AnalyticSphere(AnalyticSphere* si)
//{
//  boost::shared_ptr<AnalyticSphere> si_ptr(si);
//  WrapClass_AnalyticSphere::ptr sip(new WrapClass_AnalyticSphere(si_ptr));
//  AMIObject::ptr amiobject(AddWrap_AnalyticSphere(sip));
//  Variable<AMIObject>::ptr varres(
//    new Variable<AMIObject>(amiobject));
//  return varres;
//}

//---------------------------------------------------
//AnalyticSphere Constructor
void WrapClass_AnalyticSphere::wrap_AnalyticSphere::SetParametersComments()
{
  ADDPARAMCOMMENT("Object of a type that inherit from AnalyticSphere.");
  return_comments = "A wrapped AnalyticSphere object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticSphere::
                   wrap_AnalyticSphere::CallMember(ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  return AMILabType<AnalyticSphere>::CreateVar(new AnalyticSphere());
}
//---------------------------------------------------
//setCenter
void WrapClass_AnalyticSphere::wrap_setCenter::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "X component of sphere's center.");
  ADDPARAMCOMMENT_TYPE(float, "Y component of sphere's center.");
  ADDPARAMCOMMENT_TYPE(float, "Z component of sphere's center.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticSphere::
                   wrap_setCenter::CallMember (ParamList* p)
{
  AnalyticSphere::ptr fd(this->_objectptr->GetObj());
  
  float c1;
  float c2;
  float c3;
  int   n = 0;
  
  if (!get_val_param<float>(c1, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(c2, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(c3, p, n)) ClassHelpAndReturn;
  
  fd->setCenter(c1,c2,c3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getCenter
void WrapClass_AnalyticSphere::wrap_getCenter::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "returned X component of sphere's center .");
  ADDPARAMCOMMENT_TYPE(float, "returned Y component of sphere's center .");
  ADDPARAMCOMMENT_TYPE(float, "returned Z component of sphere's center .");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticSphere::
                   wrap_getCenter::CallMember (ParamList* p)
{
  AnalyticSphere::ptr fd(this->_objectptr->GetObj());
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

//---------------------------------------------------
//setRadius
void WrapClass_AnalyticSphere::wrap_setRadius::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "The sphere's radius size.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticSphere::
                   wrap_setRadius::CallMember(ParamList* p)
{
  AnalyticSphere::ptr fd(this->_objectptr->GetObj());
  float r;
  int   n = 0;
  
  if (!get_val_param<float>(r, p, n)) ClassHelpAndReturn;
  
  fd->setRadius(r);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getRadius
void WrapClass_AnalyticSphere::wrap_getRadius::SetParametersComments()
{
  return_comments = "The Spere's radius size.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticSphere::
                   wrap_getRadius::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->getRadius());
}
