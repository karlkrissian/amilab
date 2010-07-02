/*
 *  wrap_ComputePartialVolume.cpp
 *  AMILab
 */

#include "wrap_ComputePartialVolume.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "ComputePartialVolume.h"

#define GET_PARAM(type,varname,defaultval) \
  type varname = defaultval; \
  if (!get_val_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

#define GET_SMTPTR_PARAM(type,varname) \
  boost::shared_ptr<type> varname; \
  if (!get_val_smtptr_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

#define RETURN_VARPTR(type,  value) \
  boost::shared_ptr<type> newval(new type(value)); \
  return Variable<type>::ptr( new Variable<type>(newval));

//---------------------------------------------------
//AnalyticFunctionBase Wrapping
//---------------------------------------------------
AMIObject::ptr AddWrap_AnalyticFunctionBase(WrapClass_AnalyticFunctionBase::ptr& objectptr)
{
  // Create a new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("AnalyticFunctionBase");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods(objectptr);
  return amiobject;
}

//---------------------------------------------------
Variable<AMIObject>::ptr CreateVar_AnalyticFunctionBase(AnalyticFunctionBase* si)
{
  boost::shared_ptr<AnalyticFunctionBase> si_ptr(si);
  WrapClass_AnalyticFunctionBase::ptr sip(new WrapClass_AnalyticFunctionBase(si_ptr));
  AMIObject::ptr amiobject(AddWrap_AnalyticFunctionBase(sip));
  Variable<AMIObject>::ptr varres(
    new Variable<AMIObject>(amiobject));
  return varres;
}


void wrap_AnalyticFunctionBase::SetParametersComments()
{
  return_comments = "A wrapped AnalyticFunctionBase object.";
}
//---------------------------------------------------
BasicVariable::ptr wrap_AnalyticFunctionBase::CallMember(ParamList* p)
{ 
  
} 


// TODO: Constructor y operador ()
//No sé como hacer lo del constructor aquí porque no tiene. Tampoco sé hacer el
//operador (), que además tampoco está añadido en el .h


//---------------------------------------------------
//AnalyticCircle Wrapping
//---------------------------------------------------
AMIObject::ptr AddWrap_AnalyticCircle(WrapClass_AnalyticCircle::ptr& objectptr)
{
  // Create a new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("AnalyticCircle");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods(objectptr);
  return amiobject;
}

//---------------------------------------------------
Variable<AMIObject>::ptr CreateVar_AnalyticCircle(AnalyticCircle* si)
{
  boost::shared_ptr<AnalyticCircle> si_ptr(si);
  WrapClass_AnalyticCircle::ptr sip(new WrapClass_AnalyticCircle(si_ptr));
  AMIObject::ptr amiobject(AddWrap_AnalyticCircle(sip));
  Variable<AMIObject>::ptr varres(
    new Variable<AMIObject>(amiobject));
  return varres;
}

//---------------------------------------------------
//AnalyticCircle Constructor
void wrap_AnalyticCircle::SetParametersComments()
{
  return_comments = "A wrapped AnalyticCircle object.";
}
//---------------------------------------------------
BasicVariable::ptr wrap_AnalyticCircle::CallMember(ParamList* p)
{ //Puede que venga vacío o puede que se indiquen el centro y el radio
  if (!p) ClassHelpAndReturn;
  return CreateVar_AnalyticCircle((new AnalyticCircle()));
}
// TODO: operador ()
//---------------------------------------------------
//operator () ????

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

//---------------------------------------------------
//AnalyticLine Wrapping
//---------------------------------------------------
AMIObject::ptr AddWrap_AnalyticLine(WrapClass_AnalyticLine::ptr& objectptr)
{
  // Create a new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("AnalyticLine");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods(objectptr);
  return amiobject;
}

//---------------------------------------------------
Variable<AMIObject>::ptr CreateVar_AnalyticLine(AnalyticLine* si)
{
  boost::shared_ptr<AnalyticLine> si_ptr(si);
  WrapClass_AnalyticLine::ptr sip(new WrapClass_AnalyticLine(si_ptr));
  AMIObject::ptr amiobject(AddWrap_AnalyticLine(sip));
  Variable<AMIObject>::ptr varres(
    new Variable<AMIObject>(amiobject));
  return varres;
}

//---------------------------------------------------
//AnalyticLine Constructor
void wrap_AnalyticLine::SetParametersComments()
{
  ADDPARAMCOMMENT("Object of a type that inherit from AnalyticLine.");
  return_comments = "A wrapped AnalyticLine object.";
}
//---------------------------------------------------
BasicVariable::ptr wrap_AnalyticLine::CallMember(ParamList* p)
{ //Pasa igual que en el círculo, tiene valores por defecto el constructor
  if (!p) ClassHelpAndReturn;
  return CreateVar_AnalyticLine((new AnalyticLine()));
}
// TODO: operador ()
//---------------------------------------------------
//operator () ????

//---------------------------------------------------
//setM
void WrapClass_AnalyticLine::wrap_setM::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "X component of line's normal.");
  ADDPARAMCOMMENT_TYPE(float, "Y component of line's normal.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticLine::
                   wrap_setM::CallMember (ParamList* p)
{
  AnalyticLine::ptr fd(this->_objectptr->GetObj());
  
  float m1;
  float m2;
  int   n = 0;
  
  if (!get_val_param<float>(m1, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(m2, p, n)) ClassHelpAndReturn;
  
  fd->setM(m1,m2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getM
void WrapClass_AnalyticLine::wrap_getM::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "X component of line's normal.");
  ADDPARAMCOMMENT_TYPE(float, "Y component of line's normal.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticLine::
                   wrap_getM::CallMember (ParamList* p)
{
  AnalyticLine::ptr fd(this->_objectptr->GetObj());
  int n=0;
  Variable<float>::ptr varc1;
  Variable<float>::ptr varc2;
  if (!get_var_param<float>(varc1,p,n)) ClassHelpAndReturn;
  if (!get_var_param<float>(varc2,p,n)) ClassHelpAndReturn;
  if (!varc1->Pointer().get()) ClassHelpAndReturn;
  if (!varc2->Pointer().get()) ClassHelpAndReturn;
  (*varc1->Pointer()) = fd->getM()[0];
  (*varc2->Pointer()) = fd->getM()[1];
  return BasicVariable::ptr();
}

//---------------------------------------------------
//set_n
void WrapClass_AnalyticLine::wrap_set_n::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(float, "Cut point on 'y' axis");
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
  return_comments = "The line's y axis cut point.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnalyticLine::
                   wrap_get_n::CallMember(ParamList* p)
{
  RETURN_VAR(float, _objectptr->_obj->get_n());
}

//---------------------------------------------------
//AnalyticSphere Wrapping
//---------------------------------------------------
AMIObject::ptr AddWrap_AnalyticSphere(WrapClass_AnalyticSphere::ptr& objectptr)
{
  // Create a new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("AnalyticSphere");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods(objectptr);
  return amiobject;
}

//---------------------------------------------------
Variable<AMIObject>::ptr CreateVar_AnalyticSphere(AnalyticSphere* si)
{
  boost::shared_ptr<AnalyticSphere> si_ptr(si);
  WrapClass_AnalyticSphere::ptr sip(new WrapClass_AnalyticSphere(si_ptr));
  AMIObject::ptr amiobject(AddWrap_AnalyticSphere(sip));
  Variable<AMIObject>::ptr varres(
    new Variable<AMIObject>(amiobject));
  return varres;
}

//---------------------------------------------------
//AnalyticSphere Constructor
void wrap_AnalyticSphere::SetParametersComments()
{
  ADDPARAMCOMMENT("Object of a type that inherit from AnalyticSphere.");
  return_comments = "A wrapped AnalyticSphere object.";
}
//---------------------------------------------------
BasicVariable::ptr wrap_AnalyticSphere::CallMember(ParamList* p)
{ //Pasa igual que en el círculo, tiene valores por defecto el constructor
  if (!p) ClassHelpAndReturn;
  return CreateVar_AnalyticSphere((new AnalyticSphere()));
}
// TODO: operador ()
//---------------------------------------------------
//operator () ????

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

//---------------------------------------------------
//AnalyticTorus Wrapping
//---------------------------------------------------
AMIObject::ptr AddWrap_AnalyticTorus(WrapClass_AnalyticTorus::ptr& objectptr)
{
  // Create a new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("AnalyticTorus");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods(objectptr);
  return amiobject;
}

//---------------------------------------------------
Variable<AMIObject>::ptr CreateVar_AnalyticTorus(AnalyticTorus* si)
{
  boost::shared_ptr<AnalyticTorus> si_ptr(si);
  WrapClass_AnalyticTorus::ptr sip(new WrapClass_AnalyticTorus(si_ptr));
  AMIObject::ptr amiobject(AddWrap_AnalyticTorus(sip));
  Variable<AMIObject>::ptr varres(
    new Variable<AMIObject>(amiobject));
  return varres;
}

//---------------------------------------------------
//AnalyticTorus Constructor
void wrap_AnalyticTorus::SetParametersComments()
{
  ADDPARAMCOMMENT("Object of a type that inherit from AnalyticTorus.");
  return_comments = "A wrapped AnalyticTorus object.";
}
//---------------------------------------------------
BasicVariable::ptr wrap_AnalyticTorus::CallMember(ParamList* p)
{ //Pasa igual que en el círculo, tiene valores por defecto el constructor
  if (!p) ClassHelpAndReturn;
  return CreateVar_AnalyticTorus((new AnalyticTorus()));
}
// TODO: operador ()
//---------------------------------------------------
//operator () ????

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
  
  fd->set_rmin(rmax);
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
//---------------------------------------------------
//ComputePV Wrapping
//---------------------------------------------------
AMIObject::ptr AddWrap_ComputePV(WrapClass_ComputePV::ptr& objectptr)
{
  // Create a new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("ComputePV");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods(objectptr);
  return amiobject;
}

//---------------------------------------------------
Variable<AMIObject>::ptr CreateVar_ComputePV(ComputePV* si)
{
  boost::shared_ptr<ComputePV> si_ptr(si);
  WrapClass_ComputePV::ptr sip(new WrapClass_ComputePV(si_ptr));
  AMIObject::ptr amiobject(AddWrap_ComputePV(sip));
  Variable<AMIObject>::ptr varres(
    new Variable<AMIObject>(amiobject));
  return varres;
}

//---------------------------------------------------
//ComputePV Constructor
void wrap_ComputePV::SetParametersComments()
{
  return_comments = "A wrapped ComputePV object.";
}
//---------------------------------------------------
BasicVariable::ptr wrap_ComputePV::CallMember(ParamList* p)
{
  return CreateVar_ComputePV(new ComputePV());
}

//---------------------------------------------------
//ComputeAnalyticPartialSurfaceSubdiv
void WrapClass_ComputePV::wrap_ComputeAnalyticPartialSurfaceSubdiv
                        ::SetParametersComments()
{
  return_comments = "Returns the 2D image create with partial effect";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePV::wrap_ComputeAnalyticPartialSurfaceSubdiv
                                      ::CallMember (ParamList* p)
{
  InrImage::ptr res (_objectptr->_obj->ComputeAnalyticPartialSurfaceSubdiv());
  return Variable<InrImage>::ptr( new Variable<InrImage>(res));
}

//---------------------------------------------------
//ComputeAnalyticPartialVolumeSubdiv
void WrapClass_ComputePV::wrap_ComputeAnalyticPartialVolumeSubdiv
                        ::SetParametersComments()
{
  return_comments = "Returns the 3D image create with partial effect";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePV::wrap_ComputeAnalyticPartialVolumeSubdiv
                                      ::CallMember (ParamList* p)
{
  InrImage::ptr res (_objectptr->_obj->ComputeAnalyticPartialVolumeSubdiv());
  return Variable<InrImage>::ptr( new Variable<InrImage>(res));
}

//---------------------------------------------------
//ComputePartialVolume
void WrapClass_ComputePV::wrap_ComputePartialVolume::SetParametersComments()
{
  return_comments = "Return the 3D image create with linear interpolation and iteratively";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePV::wrap_ComputePartialVolume
                                      ::CallMember(ParamList* p)
{
  InrImage::ptr res (_objectptr->_obj->ComputePartialVolume());
  return Variable<InrImage>::ptr( new Variable<InrImage>(res));
}

//---------------------------------------------------
//ComputePartialVolumeSubdiv
void WrapClass_ComputePV::wrap_ComputePartialVolumeSubdiv::SetParametersComments()
{
  return_comments = "Return the 3D image create with linear interpolation recursively";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePV::wrap_ComputePartialVolumeSubdiv
                                      ::CallMember(ParamList* p)
{
  InrImage::ptr res (_objectptr->_obj->ComputePartialVolumeSubdiv());
  return Variable<InrImage>::ptr( new Variable<InrImage>(res));
}

//---------------------------------------------------
//setSubdiv
void WrapClass_ComputePV::wrap_setSubdiv::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(int, "Subdivision level.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePV::wrap_setSubdiv::CallMember(ParamList* p)
{
  ComputePV::ptr fd(this->_objectptr->GetObj());
  int subdiv;
  int   n = 0;
  
  if (!get_val_param<int>(subdiv, p, n)) ClassHelpAndReturn;
  
  fd->setSubdiv(subdiv);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getSubdiv
void WrapClass_ComputePV::wrap_getSubdiv::SetParametersComments()
{
  return_comments = "Return the subdivision level";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePV::wrap_getSubdiv::CallMember(ParamList* p)
{
  RETURN_VAR(int, _objectptr->_obj->getSubdiv());
}

//---------------------------------------------------
//setAnalyticFunction
void WrapClass_ComputePV::wrap_setAnalyticFunction::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(AnalyticFunctionBase, "A pointer to an analytic function");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePV::wrap_setAnalyticFunction
                                      ::CallMember(ParamList* p)
{
  ComputePV::ptr fd(this->_objectptr->GetObj());
  int n=0;
  CLASS_GET_OBJECT_PARAM(AnalyticFunctionBase, var, analyticfunc );
  if (analyticfunc.get()) {
    fd->setAnalyticFunction(analyticfunc);
  }
  else
    ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//getAnalyticFunction
void WrapClass_ComputePV::wrap_getAnalyticFunction::SetParametersComments()
{
  return_comments = "The analytic function.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePV::wrap_getAnalyticFunction
                                      ::CallMember(ParamList* p)
{
  AnalyticFunctionBase::ptr si_ptr(_objectptr->_obj->getAnalyticFunction().lock());
  WrapClass_AnalyticFunctionBase::ptr sip(new WrapClass_AnalyticFunctionBase(si_ptr));
  AMIObject::ptr amiobject(AddWrap_AnalyticFunctionBase(sip));
  Variable<AMIObject>::ptr varres(
    new Variable<AMIObject>(amiobject));
  return varres;

}

//---------------------------------------------------
//setInputImage
void WrapClass_ComputePV::wrap_setInputImage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(InrImage*, "The input image");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePV::wrap_setInputImage
                                      ::CallMember(ParamList* p)
{
  ComputePV::ptr fd(this->_objectptr->GetObj());
  Variable<InrImage>::ptr varim;
  int   n = 0;
  if (!get_var_param<InrImage>(varim,p,n)) ClassHelpAndReturn;
  InrImage::ptr input(varim->Pointer());
  if (!input.get()) ClassHelpAndReturn;
 

  if (input.get()) {
    fd->setInputImage(input);
  }
  
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getInputImage
void WrapClass_ComputePV::wrap_getInputImage::SetParametersComments()
{
  return_comments = "The input image.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePV::wrap_getInputImage
                                      ::CallMember(ParamList* p)
{
  return Variable<InrImage>::ptr (
    new Variable<InrImage>(_objectptr->_obj->getInputImage().lock()));
  
}

//---------------------------------------------------
//setResolution
void WrapClass_ComputePV::wrap_setResolution::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(int, "The resolution level");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePV::wrap_setResolution
                                      ::CallMember(ParamList* p)
{
  ComputePV::ptr fd(this->_objectptr->GetObj());
  int resolution;
  int   n = 0;
  
  if (!get_val_param<int>(resolution, p, n)) ClassHelpAndReturn;
  
  fd->setResolution(resolution);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getResolution
void WrapClass_ComputePV::wrap_getResolution::SetParametersComments()
{
  return_comments = "The resolution level.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePV::wrap_getResolution
                                      ::CallMember(ParamList* p)
{
  RETURN_VAR(int, _objectptr->_obj->getResolution());
}
