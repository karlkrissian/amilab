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

//class AnalyticFunctionBase;
//class AnalyticCircle : public AnalyticFunctionBase;
//class AnalyticLine;
//class AnalyticSphere;
//class AnalyticTorus;
//class ComputePV;


//---------------------------------------------------
//AnalyticFunctionBase Wrapping
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<AnalyticFunctionBase>::CreateVar( ParamList* p);

AMI_DECLARE_TYPE(AnalyticFunctionBase);

class WrapClass_AnalyticFunctionBase : public WrapClass<AnalyticFunctionBase> {
  DEFINE_CLASS(WrapClass_AnalyticFunctionBase);
  
public:
    
  //  ADD_CLASS_METHOD(call, "Parenthesis operator");
  WrapClass_AnalyticFunctionBase(boost::shared_ptr<AnalyticFunctionBase> si):
                                  WrapClass<AnalyticFunctionBase>(si)
  {}
  
  ADD_CLASS_CONSTRUCTOR(AnalyticFunctionBase, "Wrapping of AnalyticFunctionBase." )
  
  void AddMethods(WrapClass<AnalyticFunctionBase>::ptr this_ptr)
  {
    //  AddVar_call(this_ptr);
  }
};


//---------------------------------------------------
//AnalyticCircle Wrapping
//template <> AMI_DLLEXPORT
//BasicVariable::ptr WrapClass<AnalyticCircle>::CreateVar( ParamList* p);

AMI_DECLARE_TYPE(AnalyticCircle);

class WrapClass_AnalyticCircle : public WrapClass<AnalyticCircle>, 
                                 public WrapClass_AnalyticFunctionBase {
  
  DEFINE_CLASS(WrapClass_AnalyticCircle);
  
protected:
  // needed to resolve ambiguity from multiple inheritance
  typedef boost::shared_ptr<WrapClass<AnalyticCircle> > _parentclass_ptr;
  typedef AnalyticCircle ObjectType;
                                   
public:
  
  ///Constructor
  WrapClass_AnalyticCircle(boost::shared_ptr<AnalyticCircle> si):
                            WrapClass<AnalyticCircle>(si), 
                            WrapClass_AnalyticFunctionBase(si)
  {}
  
  ADD_CLASS_CONSTRUCTOR(AnalyticCircle, "Wrapping of AnalyticCircle.");
                                   
  //Class methods
  ADD_CLASS_METHOD(setCenter, "Set the circle's center.");
  ADD_CLASS_METHOD(getCenter, "Get the circle's center.");
  ADD_CLASS_METHOD(setRadius, "Set the circle's radius.");
  ADD_CLASS_METHOD(getRadius, "Get the circle's radius.");
  
  void AddMethods(WrapClass<AnalyticCircle>::ptr this_ptr)
  {
    AddVar_setCenter(this_ptr);
    AddVar_getCenter(this_ptr);
    AddVar_setRadius(this_ptr);
    AddVar_getRadius(this_ptr);
  }
};


//---------------------------------------------------
//AnalyticLine Wrapping
//template <> AMI_DLLEXPORT
//BasicVariable::ptr WrapClass<AnalyticLine>::CreateVar( ParamList* p);

AMI_DECLARE_TYPE(AnalyticLine);

class WrapClass_AnalyticLine : public WrapClass<AnalyticLine>, 
                               public WrapClass_AnalyticFunctionBase {
  
  DEFINE_CLASS(WrapClass_AnalyticLine);
  
protected:
  //needed to resolve ambiguity from multiple inheritance
  typedef boost::shared_ptr<WrapClass<AnalyticLine> > _parentclass_ptr;
  typedef AnalyticLine ObjectType;
  
public:
  //Constructor
  WrapClass_AnalyticLine(boost::shared_ptr<AnalyticLine> si):
                          WrapClass<AnalyticLine>(si), 
                          WrapClass_AnalyticFunctionBase(si)
  {}
  
  ADD_CLASS_CONSTRUCTOR(AnalyticLine, "Wrapping of AnalyticLine.");
  
  ADD_CLASS_METHOD(setAngle,  "Set line's angle.");
  ADD_CLASS_METHOD(getAngle,  "Get line's angle.");
  ADD_CLASS_METHOD(set_n,     "Set y axis cut point.");
  ADD_CLASS_METHOD(get_n,     "Get y axis cut point.");
  
  void AddMethods(WrapClass<AnalyticLine>::ptr this_ptr)
  {
    AddVar_setAngle( this_ptr);
    AddVar_getAngle( this_ptr);
    AddVar_set_n(this_ptr);
    AddVar_get_n(this_ptr);
  }
};


//---------------------------------------------------
//AnalyticStraightVessel2D Wrapping

AMI_DECLARE_TYPE(AnalyticStraightVessel2D);

class WrapClass_AnalyticStraightVessel2D : public WrapClass<AnalyticStraightVessel2D>,
                                           public WrapClass_AnalyticFunctionBase {
  
  DEFINE_CLASS(WrapClass_AnalyticStraightVessel2D);
  
protected:
  //needed to resolve ambiguity from multiple inheritance
  typedef boost::shared_ptr<WrapClass<AnalyticStraightVessel2D> > _parentclass_ptr;
  typedef AnalyticStraightVessel2D ObjectType;
  
public:
  //Constructor
  WrapClass_AnalyticStraightVessel2D(boost::shared_ptr<AnalyticStraightVessel2D> si):
                                        WrapClass<AnalyticStraightVessel2D>(si), 
                                        WrapClass_AnalyticFunctionBase(si)
  {}
  
  ADD_CLASS_CONSTRUCTOR(AnalyticStraightVessel2D, "Wrapping of AnalyticStraightVessel");
  
  ADD_CLASS_METHOD(getCenter,    "Get vessel center.");
  ADD_CLASS_METHOD(setCenter,    "Set vessel center.");
  ADD_CLASS_METHOD(getThickness, "Get vessel thickness.");
  ADD_CLASS_METHOD(setThickness, "Set vessel thickness.");
  ADD_CLASS_METHOD(getAngle,     "Get vessel angle.");
  ADD_CLASS_METHOD(setAngle,     "Set vessel angle.");
  
  void AddMethods(WrapClass<AnalyticStraightVessel2D>::ptr this_ptr)
  {
    AddVar_getCenter(   this_ptr);
    AddVar_setCenter(   this_ptr);
    AddVar_getThickness(this_ptr);
    AddVar_setThickness(this_ptr);
    AddVar_getAngle(    this_ptr);
    AddVar_setAngle(    this_ptr);
  }
};


//---------------------------------------------------
//AnalyticRing2D Wrapping

AMI_DECLARE_TYPE(AnalyticRing2D);

class WrapClass_AnalyticRing2D : public WrapClass<AnalyticRing2D>,
                                 public WrapClass_AnalyticFunctionBase{
  
  DEFINE_CLASS(WrapClass_AnalyticRing2D);
  
protected:
  //needed to resolve ambiguity from multiple inheritance
  typedef boost::shared_ptr<WrapClass<AnalyticRing2D> > _parentclass_ptr;
  typedef AnalyticRing2D ObjectType;
  
public:
  //Constructor
  WrapClass_AnalyticRing2D(boost::shared_ptr<AnalyticRing2D> si):
                              WrapClass<AnalyticRing2D>(si), 
                              WrapClass_AnalyticFunctionBase(si)
  {}
  
  ADD_CLASS_CONSTRUCTOR(AnalyticRing2D, "Wrapping of AnalyticRing2D");
  
  ADD_CLASS_METHOD(getCenter,    "Get ring center.");
  ADD_CLASS_METHOD(setCenter,    "Set ring center.");
  ADD_CLASS_METHOD(getRadius,    "Get ring radius.");
  ADD_CLASS_METHOD(setRadius,    "Set ring radius.");
  ADD_CLASS_METHOD(getThickness, "Get ring thickness.");
  ADD_CLASS_METHOD(setThickness, "Set ring thickness.");
  
  void AddMethods(WrapClass<AnalyticRing2D>::ptr this_ptr)
  {
    AddVar_getCenter(   this_ptr);
    AddVar_setCenter(   this_ptr);
    AddVar_getRadius(   this_ptr);
    AddVar_setRadius(   this_ptr);
    AddVar_getThickness(this_ptr);
    AddVar_setThickness(this_ptr);
  }
};


//---------------------------------------------------
//AnalyticSphere Wrapping

AMI_DECLARE_TYPE(AnalyticSphere);

class WrapClass_AnalyticSphere : public WrapClass<AnalyticSphere>,
                                 public WrapClass_AnalyticFunctionBase {
  
  DEFINE_CLASS(WrapClass_AnalyticSphere);
  
protected:
  //needed to resolve ambiguity from multiple inheritance
  typedef boost::shared_ptr<WrapClass<AnalyticSphere> > _parentclass_ptr;
  typedef AnalyticSphere ObjectType;
  
public:
  //Constructor
  WrapClass_AnalyticSphere(boost::shared_ptr<AnalyticSphere> si):
                            WrapClass<AnalyticSphere>(si), 
                            WrapClass_AnalyticFunctionBase(si)
  {}
  
  ADD_CLASS_CONSTRUCTOR(AnalyticSphere, "Wrapping of AnalyticSphere");
  
  ADD_CLASS_METHOD(setCenter, "Set sphere's center.");
  ADD_CLASS_METHOD(getCenter, "Get sphere's center.");
  ADD_CLASS_METHOD(setRadius, "Set sphere's radius.");
  ADD_CLASS_METHOD(getRadius, "Get sphere's radius.");
  
  void AddMethods(WrapClass<AnalyticSphere>::ptr this_ptr)
  {
    AddVar_setCenter(this_ptr);
    AddVar_getCenter(this_ptr);
    AddVar_setRadius(this_ptr);
    AddVar_getRadius(this_ptr);
  }
};


//---------------------------------------------------
//AnalyticTorus Wrapping

AMI_DECLARE_TYPE(AnalyticTorus);

class WrapClass_AnalyticTorus : public WrapClass<AnalyticTorus>,
                                public WrapClass_AnalyticFunctionBase {
  
  DEFINE_CLASS(WrapClass_AnalyticTorus);
  
protected:
  //needed to resolve ambiguity from multiple inheritance
  typedef boost::shared_ptr<WrapClass<AnalyticTorus> > _parentclass_ptr;
  typedef AnalyticTorus ObjectType;
  
public:
  //Constructor
  WrapClass_AnalyticTorus(boost::shared_ptr<AnalyticTorus> si):
                            WrapClass<AnalyticTorus>(si), 
                            WrapClass_AnalyticFunctionBase(si)
  {}
  
  ADD_CLASS_CONSTRUCTOR(AnalyticTorus, "Wrapping of AnalyticTorus");
  
  ADD_CLASS_METHOD(setCenter, "Set torus' center.");
  ADD_CLASS_METHOD(getCenter, "Get torus' center.");
  ADD_CLASS_METHOD(set_rmin,  "Set torus' minimum radius.");
  ADD_CLASS_METHOD(get_rmin,  "Get torus' minimum radius.");
  ADD_CLASS_METHOD(set_rmax,  "Set torus' maximum radius.");
  ADD_CLASS_METHOD(get_rmax,  "Get torus' maximum radius.");
  
  void AddMethods(WrapClass<AnalyticTorus>::ptr this_ptr)
  {
    AddVar_setCenter(this_ptr);
    AddVar_getCenter(this_ptr);
    AddVar_set_rmin( this_ptr);
    AddVar_get_rmin( this_ptr);
    AddVar_set_rmax( this_ptr);
    AddVar_get_rmax( this_ptr);
  }
};


//---------------------------------------------------
//ComputePV Wrapping

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<ComputePV>::CreateVar( ParamList* p);

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

