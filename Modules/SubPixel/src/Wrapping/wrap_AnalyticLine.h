/*
 *  wrap_AnalyticLine.h
 *  AMILab
 */

#ifndef _wrap_AnalyticLine_h_
#define _wrap_AnalyticLine_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "AnalyticLine.h"
#include "wrap_AnalyticFunctionBase.h"

//---------------------------------------------------
//AnalyticLine Wrapping

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
  
  //Constructor const
  WrapClass_AnalyticLine(boost::shared_ptr<AnalyticLine const> si, bool):
                          WrapClass<AnalyticLine>(si,true), 
                          WrapClass_AnalyticFunctionBase(si,true)
  {}

  std::string ObjPointerAsString() { return "AnalyticLine"; }

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

#endif
