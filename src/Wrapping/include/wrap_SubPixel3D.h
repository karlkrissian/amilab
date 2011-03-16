/*
 *  wrap_SubPixel3D.h
 *  AMILab
 */

#ifndef _wrap_subpixel3D_h_
#define _wrap_subpixel3D_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "SubPixel3D.h"

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<SubPixel3D>::CreateVar( ParamList* p);

AMI_DECLARE_TYPE(SubPixel3D)

//---------------------------------------------------
//SubPixel3D Wrapping
class WrapClass_SubPixel3D : public WrapClass<SubPixel3D> {
  
  DEFINE_CLASS(WrapClass_SubPixel3D);
  
public:

  
  //Constructor
  WrapClass_SubPixel3D(boost::shared_ptr<SubPixel3D> si):
                        WrapClass<SubPixel3D>(si)
  {}
  
  ADD_CLASS_CONSTRUCTOR(SubPixel3D, "Wrapping of SubPixel3D." )
  
  //Class methods
  ADD_CLASS_METHOD(GradienteCurvo3D, 
                   "Compute 2nd order subpixel method in a 3D image.");
  
  void AddMethods(WrapClass<SubPixel3D>::ptr this_ptr)
  {
    AddVar_GradienteCurvo3D(         this_ptr);
  }
};


#endif // _wrap_subpixel3D_h_
