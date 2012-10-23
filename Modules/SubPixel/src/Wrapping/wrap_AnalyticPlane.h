/*
 *  wrap_AnalyticPlane.h
 *  AMILab
 */

#ifndef _wrap_AnalyticPlane_h_
#define _wrap_AnalyticPlane_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "AnalyticPlane.h"
#include "wrap_AnalyticFunctionBase.h"

//---------------------------------------------------
//AnalyticCylinder Wrapping

AMI_DECLARE_TYPE(AnalyticPlane);

class WrapClass_AnalyticPlane : public WrapClass<AnalyticPlane>,
                                public WrapClass_AnalyticFunctionBase {
  
  DEFINE_CLASS(WrapClass_AnalyticPlane);
  
protected:
  //needed to resolve ambiguity from multiple inheritance
  typedef boost::shared_ptr<WrapClass<AnalyticPlane> > _parentclass_ptr;
  typedef AnalyticPlane ObjectType;
  
public:
  //Constructor
  WrapClass_AnalyticPlane(boost::shared_ptr<AnalyticPlane> si):
                            WrapClass<AnalyticPlane>(si), 
                            WrapClass_AnalyticFunctionBase(si)
  {}
  
  //Constructor const
  WrapClass_AnalyticPlane(boost::shared_ptr<AnalyticPlane const> si, bool):
                            WrapClass<AnalyticPlane>(si,true), 
                            WrapClass_AnalyticFunctionBase(si,true)
  {}
  
  std::string ObjPointerAsString() { return "AnalyticPlane"; }

  
  ADD_CLASS_CONSTRUCTOR(AnalyticPlane, "Wrapping of AnalyticPlane");
  
  
  ADD_CLASS_METHOD(setP1, "Set the first point coordinates.");
  ADD_CLASS_METHOD(setP2, "Set the second point coordinates.");
  ADD_CLASS_METHOD(setP3, "Set the third point coordinates.");
                                  
  void AddMethods(WrapClass<AnalyticPlane>::ptr this_ptr)
  {
    AddVar_setP1(this_ptr);
    AddVar_setP2(this_ptr);
    AddVar_setP3(this_ptr);
  }
};

#endif
