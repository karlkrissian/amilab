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
//ComputePartialVolume Wrapping

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<ComputePartialVolume>::CreateVar( ParamList* p, bool quiet);

AMI_DECLARE_TYPE(ComputePartialVolume);

class WrapClass_ComputePartialVolume : public WrapClass<ComputePartialVolume> {
  
  DEFINE_CLASS(WrapClass_ComputePartialVolume);
  
public:
  //Constructor
  WrapClass_ComputePartialVolume(boost::shared_ptr<ComputePartialVolume> si):
                        WrapClass<ComputePartialVolume>(si)
  {}
  
  //Constructor const
  WrapClass_ComputePartialVolume(boost::shared_ptr<ComputePartialVolume const> si,bool):
                        WrapClass<ComputePartialVolume>(si,true)
  {}
  
  std::string ObjPointerAsString() { return "ComputePartialVolume"; }
  
  ADD_CLASS_CONSTRUCTOR(ComputePartialVolume, "Wrapping of ComputePartialVolume");
  
  ADD_CLASS_METHOD(ComputeAnalyticPartialSurfaceSubdiv,
                   "Compute the partial effect with analytic function on a surface.");
  ADD_CLASS_METHOD(RunAnalyticSubdiv,   
                   "Compute the partial effect with analytic function on a volume.");
  ADD_CLASS_METHOD(Run,                
                   "Compute partial effect with linear interpolation iteratively.");
  ADD_CLASS_METHOD(RunSubdiv,          
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
  
  void AddMethods(WrapClass<ComputePartialVolume>::ptr this_ptr)
  {
    AddVar_ComputeAnalyticPartialSurfaceSubdiv( this_ptr);
    AddVar_RunAnalyticSubdiv(                   this_ptr);
    AddVar_Run(                                 this_ptr);
    AddVar_RunSubdiv(                           this_ptr);
    AddVar_setSubdiv(                           this_ptr);
    AddVar_getSubdiv(                           this_ptr);
    AddVar_setAnalyticFunction(                 this_ptr);
    AddVar_getAnalyticFunction(                 this_ptr);
    AddVar_setInputImage(                       this_ptr);
    AddVar_getInputImage(                       this_ptr);
    AddVar_setResolution(                       this_ptr);
    AddVar_getResolution(                       this_ptr);
  }
};

#endif

