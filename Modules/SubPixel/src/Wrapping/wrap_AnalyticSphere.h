/*
 *  wrap_AnalyticSphere.h
 *  AMILab
 */

#ifndef _wrap_AnalyticSphere_h_
#define _wrap_AnalyticSphere_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "AnalyticSphere.h"
#include "wrap_AnalyticFunctionBase.h"

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
  
  //Constructor const
  WrapClass_AnalyticSphere(boost::shared_ptr<AnalyticSphere const> si, bool):
                            WrapClass<AnalyticSphere>(si,true), 
                            WrapClass_AnalyticFunctionBase(si,true)
  {}
  
  std::string ObjPointerAsString() { return "AnalyticSphere"; }
  
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

#endif
