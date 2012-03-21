/*
 *  wrap_AnalyticCircle.cpp
 *  AMILab
 */

#include "wrap_AnalyticCircle.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

#ifndef AnalyticCircle_declared
  #define AnalyticCircle_declared
  AMI_DECLARE_TYPE(AnalyticCircle)
#endif

//----------------------------------------------------------------------
void WrapClass_AnalyticCircle::AddMethods(
  WrapClass<AnalyticCircle>::ptr this_ptr )
{
  AddVar_setCenter(this_ptr);
  AddVar_getCenter(this_ptr);
  AddVar_setRadius(this_ptr);
  AddVar_getRadius(this_ptr);
}

//---------------------------------------------------
//AnalyticCircle Wrapping
//---------------------------------------------------
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<AnalyticCircle>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_AnalyticCircle::wrap_AnalyticCircle construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(AnalyticCircle);
AMI_DEFINE_VARFROMSMTPTR(AnalyticCircle);


//AMIObject::ptr AddWrap_AnalyticCircle(WrapClass_AnalyticCircle::ptr& objectptr)
//{
//  // Create a new instance of the class
//  AMIObject::ptr amiobject(new AMIObject);
//  amiobject->SetName("AnalyticCircle");
//  amiobject->SetWrappedObject(objectptr);
//  objectptr->SetAMIObject(amiobject);
//  objectptr->AddMethods(objectptr);
//  return amiobject;
//}
//
////---------------------------------------------------
//Variable<AMIObject>::ptr CreateVar_AnalyticCircle(AnalyticCircle* si)
//{
//  boost::shared_ptr<AnalyticCircle> si_ptr(si);
//  WrapClass_AnalyticCircle::ptr sip(new WrapClass_AnalyticCircle(si_ptr));
//  AMIObject::ptr amiobject(AddWrap_AnalyticCircle(sip));
//  Variable<AMIObject>::ptr varres(
//    new Variable<AMIObject>(amiobject));
//  return varres;
//}


//---------------------------------------------------
//AnalyticCircle Constructor
void WrapClass_AnalyticCircle::wrap_AnalyticCircle::SetParametersComments()
{
  return_comments = "A wrapped AnalyticCircle object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCircle::
                   wrap_AnalyticCircle::CallMember(ParamList* p)
{ 
  if (!p) ClassHelpAndReturn;
  //return WrapClass_AnalyticCircle::CreateVar(new AnalyticCircle());
  return AMILabType<AnalyticCircle>::CreateVar(new AnalyticCircle());
}
//---------------------------------------------------
//setCenter
void WrapClass_AnalyticCircle::wrap_setCenter::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "X component of circle's center (def:50).");
  ADDPARAMCOMMENT_TYPE(float, "Y component of circle's center (def:50).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCircle::
                   wrap_setCenter::CallMember (ParamList* p)
{
  AnalyticCircle::ptr fd(this->_objectptr->GetObj());
  
  int   n = 0;
  GET_PARAM(float,c1,50)  
  GET_PARAM(float,c2,50)  
  
  fd->setCenter(c1,c2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getCenter
void WrapClass_AnalyticCircle::wrap_getCenter::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "returned X component of circle's center .");
  ADDPARAMCOMMENT_TYPE(float, "returned Y component of circle's center .");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCircle::
                   wrap_getCenter::CallMember (ParamList* p)
{
  AnalyticCircle::ptr fd(this->_objectptr->GetObj());
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
//setRadius
void WrapClass_AnalyticCircle::wrap_setRadius::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "Circle's center size");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCircle::
                   wrap_setRadius::CallMember(ParamList* p)
{
  AnalyticCircle::ptr fd(this->_objectptr->GetObj());
  float r;
  int   n = 0;
  
  if (!get_val_param(r, p, n)) ClassHelpAndReturn;
  
  fd->setRadius(r);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getRadius
void WrapClass_AnalyticCircle::wrap_getRadius::SetParametersComments()
{
  return_comments = "The cicle's radius value.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticCircle::
                   wrap_getRadius::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->getRadius());
}
