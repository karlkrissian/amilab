/*
 *  wrap_AnalyticStraightVessel2D.h
 *  AMILab
 */

#ifndef _wrap_AnalyticStraightVessel2D_h_
#define _wrap_AnalyticStraightVessel2D_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "AnalyticStraightVessel2D.h"
#include "wrap_AnalyticFunctionBase.h"

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
  
  std::string ObjPointerAsString() { return "AnalyticStraightVessel"; }
  
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

#endif
