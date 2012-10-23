/*
 *  wrap_AnalyticCube.h
 *  AMILab
 */

#ifndef _wrap_AnalyticCube_h_
#define _wrap_AnalyticCube_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "AnalyticCube.h"
#include "wrap_AnalyticFunctionBase.h"

//---------------------------------------------------
//AnalyticCube Wrapping

AMI_DECLARE_TYPE(AnalyticCube);

class WrapClass_AnalyticCube : public WrapClass<AnalyticCube>,
                               public WrapClass_AnalyticFunctionBase {
  
  DEFINE_CLASS(WrapClass_AnalyticCube);
  
protected:
  //needed to resolve ambiguity from multiple inheritance
  typedef boost::shared_ptr<WrapClass<AnalyticCube> > _parentclass_ptr;
  typedef AnalyticCube ObjectType;
  
public:
  //Constructor
  WrapClass_AnalyticCube(boost::shared_ptr<AnalyticCube> si):
                         WrapClass<AnalyticCube>(si), 
                         WrapClass_AnalyticFunctionBase(si)
  {}
  
  //Constructor const
  WrapClass_AnalyticCube(boost::shared_ptr<AnalyticCube const> si, bool):
                         WrapClass<AnalyticCube>(si,true), 
                         WrapClass_AnalyticFunctionBase(si,true)
  {}

  std::string ObjPointerAsString() { return "AnalyticCube"; }

  ADD_CLASS_CONSTRUCTOR(AnalyticCube, "Wrapping of AnalyticCube");
  
  
  ADD_CLASS_METHOD(setDimX,   "Set the size on X dimension");
  ADD_CLASS_METHOD(getDimX,   "Get the size on X dimension");
  ADD_CLASS_METHOD(setDimY,   "Set the size on Y dimension");
  ADD_CLASS_METHOD(getDimY,   "Get the size on Y dimension");
  ADD_CLASS_METHOD(setDimZ,   "Set the size on Z dimension");
  ADD_CLASS_METHOD(getDimZ,   "Get the size on Z dimension");
  ADD_CLASS_METHOD(setCenter, "Set the center of the cube");
  ADD_CLASS_METHOD(getCenter, "Get the center of the cube");
  
  void AddMethods(WrapClass<AnalyticCube>::ptr this_ptr);
};

#endif
