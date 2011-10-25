/*
 *  wrap_AnalyticStraightVessel2D.cpp
 *  AMILab
 */

#include "wrap_AnalyticStraightVessel2D.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "AnalyticStraightVessel2D.h"

//---------------------------------------------------
//AnalyticStraightVessel2D Wrapping
//---------------------------------------------------

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<AnalyticStraightVessel2D>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_AnalyticStraightVessel2D::wrap_AnalyticStraightVessel2D construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(AnalyticStraightVessel2D);
AMI_DEFINE_VARFROMSMTPTR(AnalyticStraightVessel2D);

//AMIObject::ptr AddWrap_AnalyticStraightVessel2D(WrapClass_AnalyticStraightVessel2D::ptr& objectptr)
//{
//  // Create a new instance of the class
//  AMIObject::ptr amiobject(new AMIObject);
//  amiobject->SetName("AnalyticStraightVessel2D");
//  amiobject->SetWrappedObject(objectptr);
//  objectptr->SetAMIObject(amiobject);
//  objectptr->AddMethods(objectptr);
//  return amiobject;
//}
//
////---------------------------------------------------
//Variable<AMIObject>::ptr CreateVar_AnalyticStraightVessel2D(AnalyticStraightVessel2D* si)
//{
//  boost::shared_ptr<AnalyticStraightVessel2D> si_ptr(si);
//  WrapClass_AnalyticStraightVessel2D::ptr sip(new WrapClass_AnalyticStraightVessel2D(si_ptr));
//  AMIObject::ptr amiobject(AddWrap_AnalyticStraightVessel2D(sip));
//  Variable<AMIObject>::ptr varres(
//    new Variable<AMIObject>(amiobject));
//  return varres;
//}

//---------------------------------------------------
//AnalyticStraightVessel2D Constructor
void WrapClass_AnalyticStraightVessel2D::
     wrap_AnalyticStraightVessel2D::SetParametersComments()
{
  ADDPARAMCOMMENT("Object of a type that inherit from AnalyticStraightVessel2D.");
  return_comments = "A wrapped AnalyticStraightVessel2D object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticStraightVessel2D::
                   wrap_AnalyticStraightVessel2D::CallMember(ParamList* p)
{ 
  if (!p) ClassHelpAndReturn;
  return AMILabType<AnalyticStraightVessel2D>::
         CreateVar(new AnalyticStraightVessel2D());
}


//---------------------------------------------------
//getCenter
void WrapClass_AnalyticStraightVessel2D::wrap_getCenter::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "X component of vessel center.");
  ADDPARAMCOMMENT_TYPE(float, "Y component of vessel center.");
  return_comments = "Returns the center of the analytic straight vessel 2D.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticStraightVessel2D::
                   wrap_getCenter::CallMember (ParamList* p)
{
  AnalyticStraightVessel2D::ptr fd(this->_objectptr->GetObj());
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
void WrapClass_AnalyticStraightVessel2D::wrap_setCenter::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "X component of vessel center.");
  ADDPARAMCOMMENT_TYPE(float, "Y component of vessel center.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticStraightVessel2D::
                   wrap_setCenter::CallMember (ParamList* p)
{
  AnalyticStraightVessel2D::ptr fd(this->_objectptr->GetObj());
  
  float c1;
  float c2;
  int   n = 0;
  
  if (!get_val_param<float>(c1, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(c2, p, n)) ClassHelpAndReturn;
  
  fd->setCenter(c1,c2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getThickness
void WrapClass_AnalyticStraightVessel2D::wrap_getThickness::SetParametersComments()
{
  return_comments = "The vessel thickness.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticStraightVessel2D::
                   wrap_getThickness::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->getThickness());
}

//---------------------------------------------------
//setThickness
void WrapClass_AnalyticStraightVessel2D::wrap_setThickness::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "Vessel thickness.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticStraightVessel2D::
                   wrap_setThickness::CallMember(ParamList* p)
{
  AnalyticStraightVessel2D::ptr fd(this->_objectptr->GetObj());
  float g;
  int   n = 0;
  
  if (!get_val_param<float>(g, p, n)) ClassHelpAndReturn;
  
  fd->setThickness(g);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getAngle
void WrapClass_AnalyticStraightVessel2D::wrap_getAngle::SetParametersComments()
{
  return_comments = "The vessel angle.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticStraightVessel2D::
                   wrap_getAngle::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->getAngle());
}

//---------------------------------------------------
//setAngle
void WrapClass_AnalyticStraightVessel2D::wrap_setAngle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "Vessel angle.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticStraightVessel2D::
                   wrap_setAngle::CallMember(ParamList* p)
{
  AnalyticStraightVessel2D::ptr fd(this->_objectptr->GetObj());
  float alpha;
  int   n = 0;
  
  if (!get_val_param<float>(alpha, p, n)) ClassHelpAndReturn;
  
  fd->setAngle(alpha);
  return BasicVariable::ptr();
}
