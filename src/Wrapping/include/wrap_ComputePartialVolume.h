/*
 *  wrap_ComputePartialVolume.h
 *  AMILab
 */

#ifndef _wrap_ComputePartialVolume_h_
#define _wrap_ComputePartialVolume_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "ComputePartialVolume.h"

//---------------------------------------------------
//ComputePV Wrapping

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<ComputePV>::CreateVar( ParamList* p, bool quiet);

AMI_DECLARE_TYPE(ComputePV);

class WrapClass_ComputePV : public WrapClass<ComputePV> {
  
  DEFINE_CLASS(WrapClass_ComputePV);
  
public:
  //Constructor
  WrapClass_ComputePV(boost::shared_ptr<ComputePV> si):
                        WrapClass<ComputePV>(si)
  {}
  
  ADD_CLASS_CONSTRUCTOR(ComputePV, "Wrapping of ComputePV");
  
  ADD_CLASS_METHOD(ComputeAnalyticPartialSurfaceSubdiv,
                   "Compute the partial effect with analytic function on a surface.");
  ADD_CLASS_METHOD(ComputeAnalyticPartialVolumeSubdiv,   
                   "Compute the partial effect with analytic function on a volume.");
  ADD_CLASS_METHOD(ComputePartialVolume,                
                   "Compute partial effect with linear interpolation interatively.");
  ADD_CLASS_METHOD(ComputePartialVolumeSubdiv,          
                   "Compute partial effect with linear interpolation.");
  ADD_CLASS_METHOD(setSubdiv,                           
                   "Set the subdivision level.");
  ADD_CLASS_METHOD(getSubdiv,                           
                   "Get the subdivision level.");
  ADD_CLASS_METHOD(setAnalyticFunction,                 
                   "Set an analytic function to calculate the partial effect.");
  ADD_CLASS_METHOD(getAnalyticFunction,                 
                   "Get the analytic function.");
  ADD_CLASS_METHOD(setInputImage,                       
                   "Set the input image to calculate the partial effect.");
  ADD_CLASS_METHOD(getInputImage,                       
                   "Get the input image.");
  ADD_CLASS_METHOD(setResolution,                       
                   "Set the resolution level for ComputePartialVolume method.");
  ADD_CLASS_METHOD(getResolution,                       
                   "Get the resolution level.");
  
  void AddMethods(WrapClass<ComputePV>::ptr this_ptr)
  {
    AddVar_ComputeAnalyticPartialSurfaceSubdiv(this_ptr);
    AddVar_ComputeAnalyticPartialVolumeSubdiv( this_ptr);
    AddVar_ComputePartialVolume(               this_ptr);
    AddVar_ComputePartialVolumeSubdiv(         this_ptr);
    AddVar_setSubdiv(                          this_ptr);
    AddVar_getSubdiv(                          this_ptr);
    AddVar_setAnalyticFunction(                this_ptr);
    AddVar_getAnalyticFunction(                this_ptr);
    AddVar_setInputImage(                      this_ptr);
    AddVar_getInputImage(                      this_ptr);
    AddVar_setResolution(                      this_ptr);
    AddVar_getResolution(                      this_ptr);
  }
};

#endif

