/*
 *  wrap_AnalyticCircle.h
 *  AMILab
 */

#ifndef _wrap_AnalyticCircle_h_
#define _wrap_AnalyticCircle_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "AnalyticCircle.h"
#include "wrap_AnalyticFunctionBase.h"

#ifndef AnalyticCircle_declared
  #define AnalyticCircle_declared
    AMI_DECLARE_TYPE(AnalyticCircle);
#endif


//---------------------------------------------------
//AnalyticCircle Wrapping

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
  
  ///Constructor const
  WrapClass_AnalyticCircle(boost::shared_ptr<AnalyticCircle const> si, bool):
                            WrapClass<AnalyticCircle>(si,true), 
                            WrapClass_AnalyticFunctionBase(si,true)
  {}

  std::string ObjPointerAsString() { return "AnalyticCircle"; }

  ADD_CLASS_CONSTRUCTOR(AnalyticCircle, "Wrapping of AnalyticCircle.");
                                   
  //Class methods
  ADD_CLASS_METHOD(setCenter, "Set the circle's center.");
  ADD_CLASS_METHOD(getCenter, "Get the circle's center.");
  ADD_CLASS_METHOD(setRadius, "Set the circle's radius.");
  ADD_CLASS_METHOD(getRadius, "Get the circle's radius.");
  
  void AddMethods(WrapClass<AnalyticCircle>::ptr this_ptr);
};

#endif
