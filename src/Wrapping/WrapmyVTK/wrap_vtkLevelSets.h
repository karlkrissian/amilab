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

//#include "vtkLevelSets.h"
class vtkLevelSets;

class WrapClass_vtkLevelSets : public WrapClassBase
{
  DEFINE_CLASS(WrapClass_vtkLevelSets);

  // for nested classes
  typedef WrapClass_vtkLevelSets::ptr _parentclass_ptr;

  public:
    boost::shared_ptr<vtkLevelSets> _vtkLevelSets;

    // Stored vtk images ...
    vtkImageData_ptr image_input;
    vtkImageData_ptr velocity;
    vtkImageData_ptr expansion_image;
    vtkImageData_ptr image_output;
    vtkImageData_ptr initimage;


  ADD_CLASS_METHOD(SetParam,          "Initialize the parameters.");
  ADD_CLASS_METHOD(InitWithImage,     "Sets the input image and the initial contour image.");
  ADD_CLASS_METHOD(InitWithThreshold, "Sets the input image and a threshold value as initial contour.");


  ADD_CLASS_METHOD(SetILowTh,         "");
  ADD_CLASS_METHOD(SetIHighTh,        "");
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
  ADD_CLASS_METHOD(SetExpansionImage, " Set the expansion to be the given image instead of a combination of Gaussian functions. The expansion will then be multiplied by the expansion coefficient during the evolution.");

  ADD_CLASS_METHOD(SetExpansion,      "");
  ADD_CLASS_METHOD(GetExpansion,      "");
  ADD_CLASS_METHOD(SetProbThreshold,  "");
  ADD_CLASS_METHOD(SetProbHighTh,     "");
  ADD_CLASS_METHOD(SetNumGaussians,   "");
  ADD_CLASS_METHOD(SetGaussian,       "");

  ADD_CLASS_METHOD(SetAdvectionField, "");
  ADD_CLASS_METHOD(GetAdvection,      "just copy the values when processing the next iteration the array provided MUST be allocated or NULL for cancelling the action.");

  ADD_CLASS_METHOD(SetDistMethod,     "");
  ADD_CLASS_METHOD(SetBandTube,       "");
  ADD_CLASS_METHOD(GetDistMap,        "");
  ADD_CLASS_METHOD(GetSkeleton,       "");
  ADD_CLASS_METHOD(SetThreads,        "Sets the number of threads for the PDE evolution within the narrow band.");

  ADD_CLASS_METHOD(SaveDistMap,       "");
  ADD_CLASS_METHOD(SaveSecDerGrad,    "");

  ADD_CLASS_METHOD(Iterate,           "Runs one iteration.");
  ADD_CLASS_METHOD(UpdateResult,      "Updates the resulting image so that it contains the current result.");
  ADD_CLASS_METHOD(GetOutputImage,    "Returns the image of the current contour.");
  ADD_CLASS_METHOD(GetAttachVect,     "Returns the advection vector field if advection mode is ADVECTION_UPWIND_VECTORS or ADVECTION_CENTRAL_VECTORS, or a scalar image if advection mode is ADVECTION_MORPHO.");
  ADD_CLASS_METHOD(End,               "Finishes the current segmentation.");
};

/** function that add wrapping of the Image Drawing window
 */
BasicVariable::ptr wrap_vtkLevelSets( ParamList* p);

#endif
// _wrap_vtkLevelSets_h_
