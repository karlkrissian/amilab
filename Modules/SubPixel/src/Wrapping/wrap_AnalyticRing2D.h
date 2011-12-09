/*
 *  wrap_AnalyticRing2D.h
 *  AMILab
 */

#ifndef _wrap_AnalyticRing2D_h_
#define _wrap_AnalyticRing2D_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "AnalyticRing2D.h"
#include "wrap_AnalyticFunctionBase.h"

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
  
  std::string ObjPointerAsString() { return "AnalyticRing2D"; }
  
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

#endif
