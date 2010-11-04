/*
 *  wrapSubPixel2D.h
 */

#ifndef _wrap_subpixel2D_h_
#define _wrap_subpixel2D_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "SubPixel2D.h"

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<SubPixel2D>::CreateVar( ParamList* p);

AMI_DECLARE_TYPE(SubPixel2D)

//---------------------------------------------------
//AnalyticFunctionBase Wrapping
class WrapClass_SubPixel2D : public WrapClass<SubPixel2D> {
  
  DEFINE_CLASS(WrapClass_SubPixel2D);
  
public:

  
  //Constructor
  WrapClass_SubPixel2D(boost::shared_ptr<SubPixel2D> si):
                        WrapClass<SubPixel2D>(si)
  {}
  
  ADD_CLASS_CONSTRUCTOR(SubPixel2D, "Wrapping of SubPixel2D." )
  
  //Class methods
  ADD_CLASS_METHOD(SuperGradienteCurvo, 
                   "Compute subpixel method in a 2D image.");
  ADD_CLASS_METHOD(SuperGradienteGaussianoCurvo,
                   "Compute subpixel method in a 2D noisy image.");
  ADD_CLASS_METHOD(DenoisingGus,
                   "Compute subpixel method for near-edge images (2D).");
  ADD_CLASS_METHOD(SubpixelDenoising,
                   "Compute the image restoration (2D).");
  ADD_CLASS_METHOD(drawBorder,
                   "Draw the subpixel border.");
  
  void AddMethods(WrapClass<SubPixel2D>::ptr this_ptr)
  {
    AddVar_SuperGradienteCurvo(         this_ptr);
    AddVar_SuperGradienteGaussianoCurvo(this_ptr);
    AddVar_DenoisingGus(                this_ptr);
    AddVar_SubpixelDenoising(           this_ptr);
    AddVar_drawBorder(                  this_ptr);
  }
};


#endif
