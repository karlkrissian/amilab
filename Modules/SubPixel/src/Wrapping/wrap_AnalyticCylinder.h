/*
 *  wrap_AnalyticCylinder.h
 *  AMILab
 */

#ifndef _wrap_AnalyticCylinder_h_
#define _wrap_AnalyticCylinder_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "AnalyticCylinder.h"
#include "wrap_AnalyticFunctionBase.h"

//---------------------------------------------------
//AnalyticCylinder Wrapping

AMI_DECLARE_TYPE(AnalyticCylinder);

class WrapClass_AnalyticCylinder : public WrapClass<AnalyticCylinder>,
                                 public WrapClass_AnalyticFunctionBase {
  
  DEFINE_CLASS(WrapClass_AnalyticCylinder);
  
protected:
  //needed to resolve ambiguity from multiple inheritance
  typedef boost::shared_ptr<WrapClass<AnalyticCylinder> > _parentclass_ptr;
  typedef AnalyticCylinder ObjectType;
  
public:
  //Constructor
  WrapClass_AnalyticCylinder(boost::shared_ptr<AnalyticCylinder> si):
                            WrapClass<AnalyticCylinder>(si), 
                            WrapClass_AnalyticFunctionBase(si)
  {}
  
  ADD_CLASS_CONSTRUCTOR(AnalyticCylinder, "Wrapping of AnalyticCylinder");
  
  
  ADD_CLASS_METHOD(setRadius, "Set the cylinder radius");
  ADD_CLASS_METHOD(getRadius, "Get the cylinder radius");
  ADD_CLASS_METHOD(setXdir,   "Set the cylinder x direction");
  ADD_CLASS_METHOD(getXdir,   "Get the cylinder x direction");
  ADD_CLASS_METHOD(setYdir,   "Set the cylinder y direction");
  ADD_CLASS_METHOD(getYdir,   "Get the cylinder y direction");
  ADD_CLASS_METHOD(setZdir,   "Set the cylinder z direction");
  ADD_CLASS_METHOD(getZdir,   "Get the cylinder z direction");
  
  void AddMethods(WrapClass<AnalyticCylinder>::ptr this_ptr)
  {
    AddVar_setRadius(this_ptr);
    AddVar_getRadius(this_ptr);
    AddVar_setXdir  (this_ptr);
    AddVar_getXdir  (this_ptr);
    AddVar_setYdir  (this_ptr);
    AddVar_getYdir  (this_ptr);
    AddVar_setZdir  (this_ptr);
    AddVar_getZdir  (this_ptr);
  }
};

#endif
