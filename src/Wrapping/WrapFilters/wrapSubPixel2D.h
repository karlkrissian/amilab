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

//---------------------------------------------------
//AnalyticFunctionBase Wrapping
class WrapClass_SubPixel2D : public WrapClassBase {
  DEFINE_CLASS(WrapClass_SubPixel2D);
  
  //for nested classes
  typedef WrapClass_SubPixel2D::ptr _parentclass_ptr;
  typedef SubPixel2D _obj_type;
  
public:
  boost::shared_ptr<_obj_type> _obj;
  const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }
  
  //Constructor
  WrapClass_SubPixel2D(boost::shared_ptr<SubPixel2D> si):
                        WrapClassBase(), _obj(si)
  {}
  
  //Class methods
  ADD_CLASS_METHOD(SuperGradienteCurvo, 
                   "Compute subpixel method in a 2D image.");
  ADD_CLASS_METHOD(SuperGradienteGaussianoCurvo,
                   "Compute subpixel method in a 2D noisy image.");
  ADD_CLASS_METHOD(drawBorder,
                   "Draw the subpixel border.");
  
  void AddMethods(_parentclass_ptr& this_ptr)
  {
    AddVar_SuperGradienteCurvo(         this_ptr);
    AddVar_SuperGradienteGaussianoCurvo(this_ptr);
    AddVar_drawBorder(                  this_ptr);
  }
};

AMIObject::ptr AddWrap_SubPixel2D(WrapClass_SubPixel2D::ptr& objectptr);

Variable<AMIObject>::ptr CreateVar_SubPixel2D(SubPixel2D *si);

ADD_CLASS_FUNCTION(SubPixel2D, "Wrapping of subpixel2D.");


#endif
