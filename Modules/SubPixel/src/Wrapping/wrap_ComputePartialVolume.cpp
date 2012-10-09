/*
 *  wrap_ComputePartialVolume.cpp
 *  AMILab
 */

#include "wrap_ComputePartialVolume.h"
//#include "wrap_AnalyticFunctionBase.h"

#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "ComputePartialVolume.h"

#ifndef AnalyticFunctionBase_declared
  #define AnalyticFunctionBase_declared
  AMI_DECLARE_TYPE(AnalyticFunctionBase)
#endif

//---------------------------------------------------
//ComputePartialVolume Wrapping
//---------------------------------------------------

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<ComputePartialVolume>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_ComputePartialVolume::wrap_ComputePartialVolume construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(ComputePartialVolume);
AMI_DEFINE_VARFROMSMTPTR(ComputePartialVolume);

//AMIObject::ptr AddWrap_ComputePartialVolume(WrapClass_ComputePartialVolume::ptr& objectptr)
//{
//  // Create a new instance of the class
//  AMIObject::ptr amiobject(new AMIObject);
//  amiobject->SetName("ComputePartialVolume");
//  amiobject->SetWrappedObject(objectptr);
//  objectptr->SetAMIObject(amiobject);
//  objectptr->AddMethods(objectptr);
//  return amiobject;
//}
//
////---------------------------------------------------
//Variable<AMIObject>::ptr CreateVar_ComputePartialVolume(ComputePartialVolume* si)
//{
//  boost::shared_ptr<ComputePartialVolume> si_ptr(si);
//  WrapClass_ComputePartialVolume::ptr sip(new WrapClass_ComputePartialVolume(si_ptr));
//  AMIObject::ptr amiobject(AddWrap_ComputePartialVolume(sip));
//  Variable<AMIObject>::ptr varres(
//    new Variable<AMIObject>(amiobject));
//  return varres;
//}

//---------------------------------------------------
//ComputePartialVolume Constructor
void WrapClass_ComputePartialVolume::wrap_ComputePartialVolume::SetParametersComments()
{
  return_comments = "A wrapped ComputePartialVolume object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePartialVolume::wrap_ComputePartialVolume::CallMember(ParamList* p)
{
  return AMILabType<ComputePartialVolume>::CreateVar(new ComputePartialVolume());
}

//---------------------------------------------------
//ComputeAnalyticPartialSurfaceSubdiv
void WrapClass_ComputePartialVolume::wrap_ComputeAnalyticPartialSurfaceSubdiv
                        ::SetParametersComments()
{
  return_comments = "Returns the 2D image create with partial effect";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePartialVolume::wrap_ComputeAnalyticPartialSurfaceSubdiv
                                      ::CallMember (ParamList* p)
{
  float A;
  float B;
  int   n = 0;
  
  if (!get_val_param<float>(A, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(B, p, n)) ClassHelpAndReturn;
  InrImage::ptr res (_objectptr->_obj->ComputeAnalyticPartialSurfaceSubdiv(A,B));
  return Variable<InrImage>::ptr( new Variable<InrImage>(res));
}

//---------------------------------------------------
//RunAnalyticSubdiv
void WrapClass_ComputePartialVolume::wrap_RunAnalyticSubdiv
                        ::SetParametersComments()
{
  return_comments = "Returns the 3D image create with partial effect";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePartialVolume::wrap_RunAnalyticSubdiv
                                      ::CallMember (ParamList* p)
{
  float A;
  float B;
  int   n = 0;
  
  if (!get_val_param<float>(A, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(B, p, n)) ClassHelpAndReturn;
  InrImage::ptr res (_objectptr->_obj->RunAnalyticSubdiv(A,B));
  return Variable<InrImage>::ptr( new Variable<InrImage>(res));
}

//---------------------------------------------------
//ComputePartialVolume
void WrapClass_ComputePartialVolume::wrap_Run::SetParametersComments()
{
  return_comments = "Return the 3D image create with linear interpolation and iteratively";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePartialVolume::wrap_Run
                                      ::CallMember(ParamList* p)
{
  InrImage::ptr res (_objectptr->_obj->Run());
  return Variable<InrImage>::ptr( new Variable<InrImage>(res));
}

//---------------------------------------------------
//RunSubDiv
void WrapClass_ComputePartialVolume::wrap_RunSubdiv::SetParametersComments()
{
  return_comments = "Return the 3D image create with linear interpolation recursively";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePartialVolume::wrap_RunSubdiv
                                      ::CallMember(ParamList* p)
{
  InrImage::ptr res (_objectptr->_obj->RunSubdiv());
  return Variable<InrImage>::ptr( new Variable<InrImage>(res));
}

//---------------------------------------------------
//setSubdiv
void WrapClass_ComputePartialVolume::wrap_setSubdiv::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(int, "Subdivision level.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePartialVolume::wrap_setSubdiv::CallMember(ParamList* p)
{
  ComputePartialVolume::ptr fd(this->_objectptr->GetObj());
  int subdiv;
  int   n = 0;
  
  if (!get_val_param<int>(subdiv, p, n)) ClassHelpAndReturn;
  
  fd->setSubdiv(subdiv);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getSubdiv
void WrapClass_ComputePartialVolume::wrap_getSubdiv::SetParametersComments()
{
  return_comments = "Return the subdivision level";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePartialVolume::wrap_getSubdiv::CallMember(ParamList* p)
{
  RETURN_VAR(int, _objectptr->_obj->getSubdiv());
}

//---------------------------------------------------
//setAnalyticFunction
void WrapClass_ComputePartialVolume::wrap_setAnalyticFunction::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(AnalyticFunctionBase, "A pointer to an analytic function");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePartialVolume::wrap_setAnalyticFunction
                                      ::CallMember(ParamList* p)
{
  ComputePartialVolume::ptr fd(this->_objectptr->GetObj());
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
void WrapClass_ComputePartialVolume::wrap_getAnalyticFunction::SetParametersComments()
{
  return_comments = "The analytic function.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePartialVolume::wrap_getAnalyticFunction
                                      ::CallMember(ParamList* p)
{
  AnalyticFunctionBase::ptr si_ptr(_objectptr->_obj->getAnalyticFunction().lock());
//  WrapClass_AnalyticFunctionBase::ptr sip(new WrapClass_AnalyticFunctionBase(si_ptr));
//  AMIObject::ptr amiobject(AddWrap_AnalyticFunctionBase(sip));
//  Variable<AMIObject>::ptr varres(
//    new Variable<AMIObject>(amiobject));
//  return varres;
  return AMILabType<AnalyticFunctionBase>::CreateVarFromSmtPtr(si_ptr);
}

//---------------------------------------------------
//setInputImage
void WrapClass_ComputePartialVolume::wrap_setInputImage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(InrImage*, "The input image");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePartialVolume::wrap_setInputImage
                                      ::CallMember(ParamList* p)
{
  ComputePartialVolume::ptr fd(this->_objectptr->GetObj());
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
void WrapClass_ComputePartialVolume::wrap_getInputImage::SetParametersComments()
{
  return_comments = "The input image.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePartialVolume::wrap_getInputImage
                                      ::CallMember(ParamList* p)
{
  return Variable<InrImage>::ptr (
    new Variable<InrImage>(_objectptr->_obj->getInputImage().lock()));
  
}

//---------------------------------------------------
//setResolution
void WrapClass_ComputePartialVolume::wrap_setResolution::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(int, "The resolution level");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePartialVolume::wrap_setResolution
                                      ::CallMember(ParamList* p)
{
  ComputePartialVolume::ptr fd(this->_objectptr->GetObj());
  int resolution;
  int   n = 0;
  
  if (!get_val_param<int>(resolution, p, n)) ClassHelpAndReturn;
  
  fd->setResolution(resolution);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//getResolution
void WrapClass_ComputePartialVolume::wrap_getResolution::SetParametersComments()
{
  return_comments = "The resolution level.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePartialVolume::wrap_getResolution
                                      ::CallMember(ParamList* p)
{
  RETURN_VAR(int, _objectptr->_obj->getResolution());
}
