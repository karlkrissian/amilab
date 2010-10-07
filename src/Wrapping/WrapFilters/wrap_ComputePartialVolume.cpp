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

//---------------------------------------------------
//ComputePV Wrapping
//---------------------------------------------------

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<ComputePV>::CreateVar( ParamList* p )
{
  WrapClass_ComputePV::wrap_ComputePV construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(ComputePV);
AMI_DEFINE_VARFROMSMTPTR(ComputePV);

//AMIObject::ptr AddWrap_ComputePV(WrapClass_ComputePV::ptr& objectptr)
//{
//  // Create a new instance of the class
//  AMIObject::ptr amiobject(new AMIObject);
//  amiobject->SetName("ComputePV");
//  amiobject->SetWrappedObject(objectptr);
//  objectptr->SetAMIObject(amiobject);
//  objectptr->AddMethods(objectptr);
//  return amiobject;
//}
//
////---------------------------------------------------
//Variable<AMIObject>::ptr CreateVar_ComputePV(ComputePV* si)
//{
//  boost::shared_ptr<ComputePV> si_ptr(si);
//  WrapClass_ComputePV::ptr sip(new WrapClass_ComputePV(si_ptr));
//  AMIObject::ptr amiobject(AddWrap_ComputePV(sip));
//  Variable<AMIObject>::ptr varres(
//    new Variable<AMIObject>(amiobject));
//  return varres;
//}

//---------------------------------------------------
//ComputePV Constructor
void WrapClass_ComputePV::wrap_ComputePV::SetParametersComments()
{
  return_comments = "A wrapped ComputePV object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ComputePV::wrap_ComputePV::CallMember(ParamList* p)
{
  return AMILabType<ComputePV>::CreateVar(new ComputePV());
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
  float A;
  float B;
  int   n = 0;
  
  if (!get_val_param<float>(A, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(B, p, n)) ClassHelpAndReturn;
  InrImage::ptr res (_objectptr->_obj->ComputeAnalyticPartialSurfaceSubdiv(A,B));
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
  float A;
  float B;
  int   n = 0;
  
  if (!get_val_param<float>(A, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(B, p, n)) ClassHelpAndReturn;
  InrImage::ptr res (_objectptr->_obj->ComputeAnalyticPartialVolumeSubdiv(A,B));
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
//  WrapClass_AnalyticFunctionBase::ptr sip(new WrapClass_AnalyticFunctionBase(si_ptr));
//  AMIObject::ptr amiobject(AddWrap_AnalyticFunctionBase(sip));
//  Variable<AMIObject>::ptr varres(
//    new Variable<AMIObject>(amiobject));
//  return varres;
  return AMILabType<AnalyticFunctionBase>::CreateVarFromSmtPtr(si_ptr);
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
