/*
 *  wrap_SubVoxel3D.h
 *  AMILab
 */

#ifndef _wrap_SubVoxel3D_h_
#define _wrap_SubVoxel3D_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "SubVoxel3D.h"

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<SubVoxel3D>::CreateVar( ParamList* p, bool quiet);

AMI_DECLARE_TYPE(SubVoxel3D)

//---------------------------------------------------
//SubVoxel3D Wrapping
class WrapClass_SubVoxel3D : public WrapClass<SubVoxel3D> {
  
  DEFINE_CLASS(WrapClass_SubVoxel3D);
  
public:

  
  //Constructor
  WrapClass_SubVoxel3D(boost::shared_ptr<SubVoxel3D> si):
                        WrapClass<SubVoxel3D>(si)
  {}
  
  //Constructor const
  WrapClass_SubVoxel3D(boost::shared_ptr<SubVoxel3D const> si, bool):
                        WrapClass<SubVoxel3D>(si,true)
  {}
  
  ADD_CLASS_CONSTRUCTOR(SubVoxel3D, "Wrapping of SubVoxel3D." )

  std::string ObjPointerAsString() { return "SubVoxel3D"; }
  
  //Class methods
  ADD_CLASS_METHOD(GradienteCurvo3D, 
                   "Compute 2nd order subpixel method in a 3D image.");
  
  void AddMethods(WrapClass<SubVoxel3D>::ptr this_ptr)
  {
    AddVar_GradienteCurvo3D(         this_ptr);
  }
};


#endif // _wrap_SubVoxel3D_h_
