/*
 *  wrap_AnalyticRing2D.cpp
 *  AMILab
 */

#include "wrap_AnalyticRing2D.h"

#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "AnalyticRing2D.h"

//---------------------------------------------------
//AnalyticRing2D Wrapping
//---------------------------------------------------

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<AnalyticRing2D>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_AnalyticRing2D::wrap_AnalyticRing2D construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(AnalyticRing2D);
AMI_DEFINE_VARFROMSMTPTR(AnalyticRing2D);

//AMIObject::ptr AddWrap_AnalyticRing2D(WrapClass_AnalyticRing2D::ptr& objectptr)
//{
//  // Create a new instance of the class
//  AMIObject::ptr amiobject(new AMIObject);
//  amiobject->SetName("AnalyticRing2D");
//  amiobject->SetWrappedObject(objectptr);
//  objectptr->SetAMIObject(amiobject);
//  objectptr->AddMethods(objectptr);
//  return amiobject;
//}
//
////---------------------------------------------------
//Variable<AMIObject>::ptr CreateVar_AnalyticRing2D(AnalyticRing2D* si)
//{
//  boost::shared_ptr<AnalyticRing2D> si_ptr(si);
//  WrapClass_AnalyticRing2D::ptr sip(new WrapClass_AnalyticRing2D(si_ptr));
//  AMIObject::ptr amiobject(AddWrap_AnalyticRing2D(sip));
//  Variable<AMIObject>::ptr varres(
//    new Variable<AMIObject>(amiobject));
//  return varres;
//}

//---------------------------------------------------
//AnalyticRing2D Constructor
void WrapClass_AnalyticRing2D::wrap_AnalyticRing2D::SetParametersComments()
{
  ADDPARAMCOMMENT("Object of a type that inherit from AnalyticRing2D.");
  return_comments = "A wrapped AnalyticRing2D object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticRing2D::
                   wrap_AnalyticRing2D::CallMember(ParamList* p)
{ 
  if (!p) ClassHelpAndReturn;
  return AMILabType<AnalyticRing2D>::CreateVar(new AnalyticRing2D());
}

//---------------------------------------------------
//getCenter
void WrapClass_AnalyticRing2D::wrap_getCenter::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "X component of ring center.");
  ADDPARAMCOMMENT_TYPE(float, "Y component of ring center.");
  return_comments = "Returns the center of the analytic ring 2D.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticRing2D::
                   wrap_getCenter::CallMember (ParamList* p)
{
  AnalyticRing2D::ptr fd(this->_objectptr->GetObj());
  int n=0;
  Variable<float>::ptr varc1;
  Variable<float>::ptr varc2;
  if (!get_var_param<float>(varc1,p,n)) ClassHelpAndReturn;
  if (!get_var_param<float>(varc2,p,n)) ClassHelpAndReturn;
  if (!varc1->Pointer().get()) ClassHelpAndReturn;
  if (!varc2->Pointer().get()) ClassHelpAndReturn;
  (*varc1->Pointer()) = fd->getCenter()[0];
  (*varc2->Pointer()) = fd->getCenter()[1];
  return BasicVariable::ptr();
}

//---------------------------------------------------
//setCenter
void WrapClass_AnalyticRing2D::wrap_setCenter::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "X component of ring center.");
  ADDPARAMCOMMENT_TYPE(float, "Y component of ring center.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticRing2D::
                   wrap_setCenter::CallMember (ParamList* p)
{
  AnalyticRing2D::ptr fd(this->_objectptr->GetObj());
  
  float c1;
  float c2;
  int   n = 0;
  
  if (!get_val_param<float>(c1, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(c2, p, n)) ClassHelpAndReturn;
  
  fd->setCenter(c1,c2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getRadius
void WrapClass_AnalyticRing2D::wrap_getRadius::SetParametersComments()
{
  return_comments = "The ring radius.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticRing2D::
                   wrap_getRadius::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->getRadius());
}

//---------------------------------------------------
//setRadius
void WrapClass_AnalyticRing2D::wrap_setRadius::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "Ring radius.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticRing2D::
                   wrap_setRadius::CallMember(ParamList* p)
{
  AnalyticRing2D::ptr fd(this->_objectptr->GetObj());
  float r;
  int   n = 0;
  
  if (!get_val_param<float>(r, p, n)) ClassHelpAndReturn;
  
  fd->setRadius(r);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getThickness
void WrapClass_AnalyticRing2D::wrap_getThickness::SetParametersComments()
{
  return_comments = "The ring thickness.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticRing2D::
                   wrap_getThickness::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->getThickness());
}

//---------------------------------------------------
//setThickness
void WrapClass_AnalyticRing2D::wrap_setThickness::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "Ring thickness.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticRing2D::
                   wrap_setThickness::CallMember(ParamList* p)
{
  AnalyticRing2D::ptr fd(this->_objectptr->GetObj());
  float g;
  int   n = 0;
  
  if (!get_val_param<float>(g, p, n)) ClassHelpAndReturn;
  
  fd->setThickness(g);
  return BasicVariable::ptr();
}
