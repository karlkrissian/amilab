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
class WrapClass_AnalyticFunctionBase : public WrapClassBase {
  DEFINE_CLASS(WrapClass_AnalyticFunctionBase);
  
  // for nested classes
  typedef WrapClass_AnalyticFunctionBase::ptr _parentclass_ptr;
  typedef AnalyticFunctionBase _obj_type;
  
public:
  boost::shared_ptr<_obj_type> _obj;
  const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }
    
  //  ADD_CLASS_METHOD(call, "Parenthesis operator");
  WrapClass_AnalyticFunctionBase(boost::shared_ptr<AnalyticFunctionBase> si):_obj(si)
  {}
  
  void AddMethods(_parentclass_ptr& this_ptr)
  {
    //  AddVar_call(this_ptr);
  }
};

AMIObject::ptr AddWrap_AnalyticFunctionBase(WrapClass_AnalyticFunctionBase::ptr& objectptr);

Variable<AMIObject>::ptr CreateVar_AnalyticFunctionBase(AnalyticFunctionBase* si);

ADD_CLASS_FUNCTION(AnalyticFunctionBase, "Wrapping of AnalyticFunctionBase.");

//---------------------------------------------------
//AnalyticCircle Wrapping
class WrapClass_AnalyticCircle : public WrapClass_AnalyticFunctionBase {
  DEFINE_CLASS(WrapClass_AnalyticCircle);
  
  // for nested classes
  typedef WrapClass_AnalyticCircle::ptr _parentclass_ptr;
  typedef AnalyticCircle _obj_type;
  
public:
  boost::shared_ptr<_obj_type> _obj;
  const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }
  
  ///Constructor
  WrapClass_AnalyticCircle(boost::shared_ptr<AnalyticCircle> si):
                            WrapClass_AnalyticFunctionBase(si), _obj(si)
  {}
  
  ADD_CLASS_METHOD(setCenter, "Set the circle's center.");
  ADD_CLASS_METHOD(getCenter, "Get the circle's center.");
  ADD_CLASS_METHOD(setRadius, "Set the circle's radius.");
  ADD_CLASS_METHOD(getRadius, "Get the circle's radius.");
  
  void AddMethods(_parentclass_ptr& this_ptr)
  {
    AddVar_setCenter(this_ptr);
    AddVar_getCenter(this_ptr);
    AddVar_setRadius(this_ptr);
    AddVar_getRadius(this_ptr);
  }
};

AMIObject::ptr AddWrap_AnalyticCircle(WrapClass_AnalyticCircle::ptr& objectptr);

Variable<AMIObject>::ptr CreateVar_AnalyticCircle(AnalyticCircle* si);

ADD_CLASS_FUNCTION(AnalyticCircle, "Wrapping of AnalyticCircle.");


//---------------------------------------------------
//AnalyticLine Wrapping
class WrapClass_AnalyticLine : public WrapClass_AnalyticFunctionBase {
  DEFINE_CLASS(WrapClass_AnalyticLine);
  
  // for nested classes
  typedef WrapClass_AnalyticLine::ptr _parentclass_ptr;
  typedef AnalyticLine _obj_type;
  
public:
  boost::shared_ptr<_obj_type> _obj;
  const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }
  
  //Constructor
  WrapClass_AnalyticLine(boost::shared_ptr<AnalyticLine> si):
                          WrapClass_AnalyticFunctionBase(si), _obj(si)
  {}
  
  ADD_CLASS_METHOD(setAngle,  "Set line's angle.");
  ADD_CLASS_METHOD(getAngle,  "Get line's angle.");
  ADD_CLASS_METHOD(set_n,     "Set y axis cut point.");
  ADD_CLASS_METHOD(get_n,     "Get y axis cut point.");
  
  void AddMethods(_parentclass_ptr& this_ptr)
  {
    AddVar_setAngle( this_ptr);
    AddVar_getAngle( this_ptr);
    AddVar_set_n(this_ptr);
    AddVar_get_n(this_ptr);
  }
};

AMIObject::ptr AddWrap_AnalyticLine(WrapClass_AnalyticLine::ptr& objectptr);

Variable<AMIObject>::ptr CreateVar_AnalyticLine(AnalyticLine* si);

ADD_CLASS_FUNCTION(AnalyticLine, "Wrapping of AnalyticLine.");


//---------------------------------------------------
//AnalyticStraightVessel2D Wrapping
class WrapClass_AnalyticStraightVessel2D : public WrapClass_AnalyticFunctionBase {
  DEFINE_CLASS(WrapClass_AnalyticStraightVessel2D);
  
  // for nested classes
  typedef WrapClass_AnalyticStraightVessel2D::ptr _parentclass_ptr;
  typedef AnalyticStraightVessel2D _obj_type;
  
public:
  boost::shared_ptr<_obj_type> _obj;
  const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }
  
  //Constructor
  WrapClass_AnalyticStraightVessel2D(boost::shared_ptr<AnalyticStraightVessel2D> si):
                          WrapClass_AnalyticFunctionBase(si), _obj(si)
  {}
  
  ADD_CLASS_METHOD(getCenter,    "Get vessel center.");
  ADD_CLASS_METHOD(setCenter,    "Set vessel center.");
  ADD_CLASS_METHOD(getThickness, "Get vessel thickness.");
  ADD_CLASS_METHOD(setThickness, "Set vessel thickness.");
  ADD_CLASS_METHOD(getAngle,     "Get vessel angle.");
  ADD_CLASS_METHOD(setAngle,     "Set vessel angle.");
  
  void AddMethods(_parentclass_ptr& this_ptr)
  {
    AddVar_getCenter(   this_ptr);
    AddVar_setCenter(   this_ptr);
    AddVar_getThickness(this_ptr);
    AddVar_setThickness(this_ptr);
    AddVar_getAngle(    this_ptr);
    AddVar_setAngle(    this_ptr);
  }
};

AMIObject::ptr AddWrap_AnalyticStraightVessel2D(WrapClass_AnalyticStraightVessel2D::ptr& objectptr);

Variable<AMIObject>::ptr CreateVar_AnalyticStraightVessel2D(AnalyticStraightVessel2D* si);

ADD_CLASS_FUNCTION(AnalyticStraightVessel2D, "Wrapping of AnalyticStraightVessel2D.");

//---------------------------------------------------
//AnalyticRing2D Wrapping
class WrapClass_AnalyticRing2D : public WrapClass_AnalyticFunctionBase {
  DEFINE_CLASS(WrapClass_AnalyticRing2D);
  
  // for nested classes
  typedef WrapClass_AnalyticRing2D::ptr _parentclass_ptr;
  typedef AnalyticRing2D _obj_type;
  
public:
  boost::shared_ptr<_obj_type> _obj;
  const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }
  
  //Constructor
  WrapClass_AnalyticRing2D(boost::shared_ptr<AnalyticRing2D> si):
                          WrapClass_AnalyticFunctionBase(si), _obj(si)
  {}
  
  ADD_CLASS_METHOD(getCenter,    "Get ring center.");
  ADD_CLASS_METHOD(setCenter,    "Set ring center.");
  ADD_CLASS_METHOD(getRadius,    "Get ring radius.");
  ADD_CLASS_METHOD(setRadius,    "Set ring radius.");
  ADD_CLASS_METHOD(getThickness, "Get ring thickness.");
  ADD_CLASS_METHOD(setThickness, "Set ring thickness.");
  
  void AddMethods(_parentclass_ptr& this_ptr)
  {
    AddVar_getCenter(   this_ptr);
    AddVar_setCenter(   this_ptr);
    AddVar_getRadius(   this_ptr);
    AddVar_setRadius(   this_ptr);
    AddVar_getThickness(this_ptr);
    AddVar_setThickness(this_ptr);
  }
};

AMIObject::ptr AddWrap_AnalyticRing2D(WrapClass_AnalyticRing2D::ptr& objectptr);

Variable<AMIObject>::ptr CreateVar_AnalyticRing2D(AnalyticRing2D* si);

ADD_CLASS_FUNCTION(AnalyticRing2D, "Wrapping of AnalyticRing2D.");

//---------------------------------------------------
//AnalyticSphere Wrapping
class WrapClass_AnalyticSphere : public WrapClass_AnalyticFunctionBase {
  DEFINE_CLASS(WrapClass_AnalyticSphere);
  
  // for nested classes
  typedef WrapClass_AnalyticSphere::ptr _parentclass_ptr;
  typedef AnalyticSphere _obj_type;
  
public:
  boost::shared_ptr<_obj_type> _obj;
  const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }
  
  //Constructor
  WrapClass_AnalyticSphere(boost::shared_ptr<AnalyticSphere> si):
                            WrapClass_AnalyticFunctionBase(si), _obj(si)
  {}
  
  ADD_CLASS_METHOD(setCenter, "Set sphere's center.");
  ADD_CLASS_METHOD(getCenter, "Get sphere's center.");
  ADD_CLASS_METHOD(setRadius, "Set sphere's radius.");
  ADD_CLASS_METHOD(getRadius, "Get sphere's radius.");
  
  void AddMethods(_parentclass_ptr& this_ptr)
  {
    AddVar_setCenter(this_ptr);
    AddVar_getCenter(this_ptr);
    AddVar_setRadius(this_ptr);
    AddVar_getRadius(this_ptr);
  }
};

AMIObject::ptr AddWrap_AnalyticSphere(WrapClass_AnalyticSphere::ptr& objectptr);

Variable<AMIObject>::ptr CreateVar_AnalyticSphere(AnalyticSphere* si);

ADD_CLASS_FUNCTION(AnalyticSphere, "Wrapping of AnalyticSphere.");


//---------------------------------------------------
//AnalyticTorus Wrapping
class WrapClass_AnalyticTorus : public WrapClass_AnalyticFunctionBase {
  DEFINE_CLASS(WrapClass_AnalyticTorus);
  
  // for nested classes
  typedef WrapClass_AnalyticTorus::ptr _parentclass_ptr;
  typedef AnalyticTorus _obj_type;
  
public:
  boost::shared_ptr<_obj_type> _obj;
  const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }
  
  //Constructor
  WrapClass_AnalyticTorus(boost::shared_ptr<AnalyticTorus> si):
                            WrapClass_AnalyticFunctionBase(si), _obj(si)
  {}
  
  ADD_CLASS_METHOD(setCenter, "Set torus' center.");
  ADD_CLASS_METHOD(getCenter, "Get torus' center.");
  ADD_CLASS_METHOD(set_rmin,  "Set torus' minimum radius.");
  ADD_CLASS_METHOD(get_rmin,  "Get torus' minimum radius.");
  ADD_CLASS_METHOD(set_rmax,  "Set torus' maximum radius.");
  ADD_CLASS_METHOD(get_rmax,  "Get torus' maximum radius.");
  
  void AddMethods(_parentclass_ptr& this_ptr)
  {
    AddVar_setCenter(this_ptr);
    AddVar_getCenter(this_ptr);
    AddVar_set_rmin( this_ptr);
    AddVar_get_rmin( this_ptr);
    AddVar_set_rmax( this_ptr);
    AddVar_get_rmax( this_ptr);
  }
};

AMIObject::ptr AddWrap_AnalyticTorus(WrapClass_AnalyticTorus::ptr& objectptr);

Variable<AMIObject>::ptr CreateVar_AnalyticTorus(AnalyticTorus *si);

ADD_CLASS_FUNCTION(AnalyticTorus, "Wrapping of AnalyticTorus.");


//---------------------------------------------------
//ComputePV Wrapping
class WrapClass_ComputePV : public WrapClassBase {
  DEFINE_CLASS(WrapClass_ComputePV);
  
  //for nested classes
  typedef WrapClass_ComputePV::ptr _parentclass_ptr;
  typedef ComputePV _obj_type;
  
public:
  boost::shared_ptr<_obj_type> _obj;
  const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }
  
  //Constructor
  WrapClass_ComputePV(boost::shared_ptr<ComputePV> si):
                        WrapClassBase(), _obj(si)
  {}
  
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
  
  void AddMethods(_parentclass_ptr& this_ptr)
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

AMIObject::ptr AddWrap_ComputePV(WrapClass_ComputePV::ptr& objectptr);

Variable<AMIObject>::ptr CreateVar_ComputePV(ComputePV *si);

ADD_CLASS_FUNCTION(ComputePV, "Wrapping of ComputePV.");

#endif

