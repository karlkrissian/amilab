//
// C++ Interface: wrap_vtkLevelSets
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_vtkLevelSets_h_
#define _wrap_vtkLevelSets_h_

#include "wrapfunction_class.h"
#include "Variable.hpp"
#include "paramlist.h"
#include "vtkLevelSets.h"


class WrapClass_vtkLevelSets : public WrapClassBase
{
  DEFINE_CLASS(WrapClass_vtkLevelSets);

  // for nested classes
  typedef WrapClass_vtkLevelSets::ptr _parentclass_ptr;

  public:
    vtkLevelSets::ptr _vtkLevelSets;

    // Stored vtk images ...
    vtkImageData_ptr image_input;
    vtkImageData_ptr velocity;
    vtkImageData_ptr expansion_image;
    vtkImageData_ptr image_output;
    vtkImageData_ptr initimage;


  ADD_CLASS_METHOD(SetParam,          "Initialize the parameters.");

  ADD_CLASS_METHOD(SetLowTh,          "");
  ADD_CLASS_METHOD(SetHighTh,         "");
  ADD_CLASS_METHOD(SetNumInitPoints,  "");
  ADD_CLASS_METHOD(SetInitPoint,      "");
  ADD_CLASS_METHOD(SetIsoContourBin,  "");

  ADD_CLASS_METHOD(SetMeanCurv,       "Active/Desactivate mean curvature motion.");
  ADD_CLASS_METHOD(SetAffineCurv,     "");
  ADD_CLASS_METHOD(SetCurvWeights,    "");
  ADD_CLASS_METHOD(GetCurvature,      "");

  ADD_CLASS_METHOD(SetVelocity,       "");
  ADD_CLASS_METHOD(GetVelocity,       "");

  ADD_CLASS_METHOD(SetBalloonScheme,  "");
  ADD_CLASS_METHOD(SetExpansionImage, "");
  ADD_CLASS_METHOD(SetExpansion,      "");
  ADD_CLASS_METHOD(GetExpansion,      "");
  ADD_CLASS_METHOD(SetProbThreshold,  "");
  ADD_CLASS_METHOD(SetProbHighTh,     "");
  ADD_CLASS_METHOD(SetNumGaussians,   "");
  ADD_CLASS_METHOD(SetGaussian,       "");

  ADD_CLASS_METHOD(SetAdvectionField, "");
  ADD_CLASS_METHOD(GetAdvection,      "");

  ADD_CLASS_METHOD(SetDistMethod,     "");
  ADD_CLASS_METHOD(SetBandTube,       "");
  ADD_CLASS_METHOD(GetDistMap,        "");
  ADD_CLASS_METHOD(GetSkeleton,       "");
  ADD_CLASS_METHOD(SetThreads,        "");

  ADD_CLASS_METHOD(SaveDistMap,       "");
  ADD_CLASS_METHOD(SaveSecDerGrad,    "");

  ADD_CLASS_METHOD(Iterate,           "");
  ADD_CLASS_METHOD(End,               "");
};

/** function that add wrapping of the Image Drawing window
 */
BasicVariable::ptr wrap_vtkLevelSets( ParamList* p);

#endif
// _wrap_vtkLevelSets_h_
