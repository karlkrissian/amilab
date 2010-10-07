/*
 *  wrap_AnalyticLine.cpp
 *  AMILab
 */

#include "wrap_AnalyticLine.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "AnalyticLine.h"

//---------------------------------------------------
//AnalyticLine Wrapping
//---------------------------------------------------

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<AnalyticLine>::CreateVar( ParamList* p )
{
  WrapClass_AnalyticLine::wrap_AnalyticLine construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(AnalyticLine);
AMI_DEFINE_VARFROMSMTPTR(AnalyticLine);

//AMIObject::ptr AddWrap_AnalyticLine(WrapClass_AnalyticLine::ptr& objectptr)
//{
//  // Create a new instance of the class
//  AMIObject::ptr amiobject(new AMIObject);
//  amiobject->SetName("AnalyticLine");
//  amiobject->SetWrappedObject(objectptr);
//  objectptr->SetAMIObject(amiobject);
//  objectptr->AddMethods(objectptr);
//  return amiobject;
//}
//
////---------------------------------------------------
//Variable<AMIObject>::ptr CreateVar_AnalyticLine(AnalyticLine* si)
//{
//  boost::shared_ptr<AnalyticLine> si_ptr(si);
//  WrapClass_AnalyticLine::ptr sip(new WrapClass_AnalyticLine(si_ptr));
//  AMIObject::ptr amiobject(AddWrap_AnalyticLine(sip));
//  Variable<AMIObject>::ptr varres(
//    new Variable<AMIObject>(amiobject));
//  return varres;
//}

//---------------------------------------------------
//AnalyticLine Constructor
void WrapClass_AnalyticLine::wrap_AnalyticLine::SetParametersComments()
{
  ADDPARAMCOMMENT("Object of a type that inherit from AnalyticLine.");
  return_comments = "A wrapped AnalyticLine object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticLine::
                   wrap_AnalyticLine::CallMember(ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  return AMILabType<AnalyticLine>::CreateVar(new AnalyticLine());
}
//---------------------------------------------------
//setAngle
void WrapClass_AnalyticLine::wrap_setAngle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "The angle of the line.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticLine::
                   wrap_setAngle::CallMember (ParamList* p)
{
  AnalyticLine::ptr fd(this->_objectptr->GetObj());
  
  float alpha;
  int   n = 0;
  
  if (!get_val_param<float>(alpha, p, n)) ClassHelpAndReturn;
  
  fd->setAngle(alpha);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getAngle
void WrapClass_AnalyticLine::wrap_getAngle::SetParametersComments()
{
  return_comments = "The angle of the line.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticLine::
                   wrap_getAngle::CallMember (ParamList* p)
{
  AnalyticLine::ptr fd(this->_objectptr->GetObj());
  RETURN_VAR(float, fd->getAngle());
}

//---------------------------------------------------
//set_n
void WrapClass_AnalyticLine::wrap_set_n::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "Cut point on the Y axis");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticLine::
                   wrap_set_n::CallMember(ParamList* p)
{
  AnalyticLine::ptr fd(this->_objectptr->GetObj());
  float _n;
  int   n = 0;
  
  if (!get_val_param<float>(_n, p, n)) ClassHelpAndReturn;
  
  fd->set_n(_n);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//get_n
void WrapClass_AnalyticLine::wrap_get_n::SetParametersComments()
{
  return_comments = "The value of the cut point on the Y axis.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticLine::
                   wrap_get_n::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->get_n());
}

