/*
 *  wrap_AnalyticTorus.cpp
 *  AMILab
 */

#include "wrap_AnalyticTorus.h"

#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "AnalyticTorus.h"

//---------------------------------------------------
//AnalyticTorus Wrapping
//---------------------------------------------------

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<AnalyticTorus>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_AnalyticTorus::wrap_AnalyticTorus construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(AnalyticTorus);
AMI_DEFINE_VARFROMSMTPTR(AnalyticTorus);

//AMIObject::ptr AddWrap_AnalyticTorus(WrapClass_AnalyticTorus::ptr& objectptr)
//{
//  // Create a new instance of the class
//  AMIObject::ptr amiobject(new AMIObject);
//  amiobject->SetName("AnalyticTorus");
//  amiobject->SetWrappedObject(objectptr);
//  objectptr->SetAMIObject(amiobject);
//  objectptr->AddMethods(objectptr);
//  return amiobject;
//}
//
////---------------------------------------------------
//Variable<AMIObject>::ptr CreateVar_AnalyticTorus(AnalyticTorus* si)
//{
//  boost::shared_ptr<AnalyticTorus> si_ptr(si);
//  WrapClass_AnalyticTorus::ptr sip(new WrapClass_AnalyticTorus(si_ptr));
//  AMIObject::ptr amiobject(AddWrap_AnalyticTorus(sip));
//  Variable<AMIObject>::ptr varres(
//    new Variable<AMIObject>(amiobject));
//  return varres;
//}

//---------------------------------------------------
//AnalyticTorus Constructor
void WrapClass_AnalyticTorus::wrap_AnalyticTorus::SetParametersComments()
{
  ADDPARAMCOMMENT("Object of a type that inherit from AnalyticTorus.");
  return_comments = "A wrapped AnalyticTorus object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticTorus::
                   wrap_AnalyticTorus::CallMember(ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  return AMILabType<AnalyticTorus>::CreateVar(new AnalyticTorus());
}
//---------------------------------------------------
//setCenter
void WrapClass_AnalyticTorus::wrap_setCenter::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "X component of torus' center.");
  ADDPARAMCOMMENT_TYPE(float, "Y component of torus' center.");
  ADDPARAMCOMMENT_TYPE(float, "Z component of torus' center.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticTorus::
                   wrap_setCenter::CallMember (ParamList* p)
{
  AnalyticTorus::ptr fd(this->_objectptr->GetObj());
  
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
void WrapClass_AnalyticTorus::wrap_getCenter::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "returned X component of torus' center .");
  ADDPARAMCOMMENT_TYPE(float, "returned Y component of torus' center .");
  ADDPARAMCOMMENT_TYPE(float, "returned Z component of torus' center .");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticTorus::
                   wrap_getCenter::CallMember (ParamList* p)
{
  AnalyticTorus::ptr fd(this->_objectptr->GetObj());
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
//set_rmin
void WrapClass_AnalyticTorus::wrap_set_rmin::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "The torus' minimum radius size.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticTorus::
                   wrap_set_rmin::CallMember(ParamList* p)
{
  AnalyticTorus::ptr fd(this->_objectptr->GetObj());
  float rmin;
  int   n = 0;
  
  if (!get_val_param<float>(rmin, p, n)) ClassHelpAndReturn;
  
  fd->set_rmin(rmin);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//get_rmin
void WrapClass_AnalyticTorus::wrap_get_rmin::SetParametersComments()
{
  return_comments = "The minimum tours' radius size.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticTorus::
                   wrap_get_rmin::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->get_rmin());
}

//---------------------------------------------------
//set_rmax
void WrapClass_AnalyticTorus::wrap_set_rmax::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "The torus' maximum radius size.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticTorus::
                   wrap_set_rmax::CallMember(ParamList* p)
{
  AnalyticTorus::ptr fd(this->_objectptr->GetObj());
  float rmax;
  int   n = 0;
  
  if (!get_val_param<float>(rmax, p, n)) ClassHelpAndReturn;
  
  fd->set_rmax(rmax);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//get_rmax
void WrapClass_AnalyticTorus::wrap_get_rmax::SetParametersComments()
{
  return_comments = "The torus' maximum radius size.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticTorus::
                   wrap_get_rmax::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->get_rmax());
}
