/*
 *  wrap_AnalyticFunctionBase.h
 *  AMILab
 */

#ifndef _wrap_AnalyticFunctionBase_h_
#define _wrap_AnalyticFunctionBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "AnalyticFunctionBase.h"

//---------------------------------------------------
//AnalyticFunctionBase Wrapping
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<AnalyticFunctionBase>::CreateVar( ParamList* p);

AMI_DECLARE_TYPE(AnalyticFunctionBase);

class WrapClass_AnalyticFunctionBase : public WrapClass<AnalyticFunctionBase> {
  DEFINE_CLASS(WrapClass_AnalyticFunctionBase);
  
public:
    
  //  ADD_CLASS_METHOD(call, "Parenthesis operator");
  WrapClass_AnalyticFunctionBase(boost::shared_ptr<AnalyticFunctionBase> si):
                                  WrapClass<AnalyticFunctionBase>(si)
  {}
  
  ADD_CLASS_CONSTRUCTOR(AnalyticFunctionBase, "Wrapping of AnalyticFunctionBase." )
  
  void AddMethods(WrapClass<AnalyticFunctionBase>::ptr this_ptr)
  {
    //  AddVar_call(this_ptr);
  }
};

#endif
