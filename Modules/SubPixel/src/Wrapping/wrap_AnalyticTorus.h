/*
 *  wrap_AnalyticTorus.h
 *  AMILab
 */

#ifndef _wrap_AnalyticTorus_h_
#define _wrap_AnalyticTorus_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "AnalyticTorus.h"
#include "wrap_AnalyticFunctionBase.h"

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
  
  //Constructor const
  WrapClass_AnalyticTorus(boost::shared_ptr<AnalyticTorus const> si,bool):
                            WrapClass<AnalyticTorus>(si,true), 
                            WrapClass_AnalyticFunctionBase(si,true)
  {}
  
  std::string ObjPointerAsString() { return "AnalyticTorus"; }
  
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

#endif
