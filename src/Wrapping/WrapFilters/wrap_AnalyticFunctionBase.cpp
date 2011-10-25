/*
 *  wrap_AnalyticFunctionBase.cpp
 *  AMILab
 */

#include "wrap_AnalyticFunctionBase.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "AnalyticFunctionBase.h"

//---------------------------------------------------
//AnalyticFunctionBase Wrapping
//---------------------------------------------------

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<AnalyticFunctionBase>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_AnalyticFunctionBase::wrap_AnalyticFunctionBase construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(AnalyticFunctionBase);
AMI_DEFINE_VARFROMSMTPTR(AnalyticFunctionBase);

//AMIObject::ptr AddWrap_AnalyticFunctionBase(WrapClass_AnalyticFunctionBase::ptr& objectptr)
//{
//  // Create a new instance of the class
//  AMIObject::ptr amiobject(new AMIObject);
//  amiobject->SetName("AnalyticFunctionBase");
//  amiobject->SetWrappedObject(objectptr);
//  objectptr->SetAMIObject(amiobject);
//  objectptr->AddMethods(objectptr);
//  return amiobject;
//}
//
////---------------------------------------------------
//Variable<AMIObject>::ptr CreateVar_AnalyticFunctionBase(AnalyticFunctionBase* si)
//{
//  boost::shared_ptr<AnalyticFunctionBase> si_ptr(si);
//  WrapClass_AnalyticFunctionBase::ptr sip(new WrapClass_AnalyticFunctionBase(si_ptr));
//  AMIObject::ptr amiobject(AddWrap_AnalyticFunctionBase(sip));
//  Variable<AMIObject>::ptr varres(
//    new Variable<AMIObject>(amiobject));
//  return varres;
//}


void WrapClass_AnalyticFunctionBase::wrap_AnalyticFunctionBase::SetParametersComments()
{
  return_comments = "A wrapped AnalyticFunctionBase object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticFunctionBase::wrap_AnalyticFunctionBase::CallMember(ParamList* p)
{ 
  return BasicVariable::ptr();
} 
