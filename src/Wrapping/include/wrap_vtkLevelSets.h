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

AMI_DECLARE_TYPE(vtkLevelSets);

class WrapClass_vtkLevelSets : public WrapClass<vtkLevelSets>
{
  DEFINE_CLASS(WrapClass_vtkLevelSets);
  // for nested classes
  typedef WrapClass<vtkLevelSets>::ptr _parentclass_ptr;

  public:
    boost::shared_ptr<vtkLevelSets> _vtkLevelSets;

    // Stored vtk images ...
    vtkImageData_ptr image_input;
    vtkImageData_ptr velocity;
    vtkImageData_ptr expansion_image;
    vtkImageData_ptr image_output;
    vtkImageData_ptr initimage;


    /// Constructor
    WrapClass_vtkLevelSets(boost::shared_ptr<vtkLevelSets> w):WrapClass<vtkLevelSets>(w)
    {}

    /// Constructor const
    WrapClass_vtkLevelSets(boost::shared_ptr<vtkLevelSets const> w, bool):
      WrapClass<vtkLevelSets>(w, true)
    {}

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkLevelSets, "Wrapping of vtkLevelSets." );

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

    void AddMethods(WrapClass<vtkLevelSets>::ptr this_ptr )
    {
       AddVar_SetParam(           this_ptr);
       AddVar_InitWithImage(      this_ptr);
       AddVar_InitWithThreshold(  this_ptr);
 
       AddVar_SetILowTh(          this_ptr);
       AddVar_SetIHighTh(         this_ptr);
       AddVar_SetNumInitPoints(   this_ptr);
       AddVar_SetInitPoint(       this_ptr);
       AddVar_SetIsoContourBin(   this_ptr);
       AddVar_SetMeanCurv(        this_ptr);
       AddVar_SetAffineCurv(      this_ptr);
       AddVar_SetCurvWeights(     this_ptr);
       AddVar_GetCurvature(       this_ptr);
       AddVar_SetVelocity(        this_ptr);
       AddVar_GetVelocity(        this_ptr);
       AddVar_SetBalloonScheme(   this_ptr);
       AddVar_SetExpansionImage(  this_ptr);
       AddVar_SetExpansion(       this_ptr);
       AddVar_GetExpansion(       this_ptr);
       AddVar_SetProbThreshold(   this_ptr);
       AddVar_SetProbHighTh(      this_ptr);
       AddVar_SetNumGaussians(    this_ptr);
       AddVar_SetGaussian(        this_ptr);
       AddVar_SetAdvectionField(  this_ptr);
       AddVar_GetAdvection(       this_ptr);
       AddVar_SetDistMethod(      this_ptr);
       AddVar_SetBandTube(        this_ptr);
       AddVar_GetDistMap(         this_ptr);
       AddVar_GetSkeleton(        this_ptr);

       AddVar_SetThreads(         this_ptr);
       AddVar_SaveDistMap(        this_ptr);
       AddVar_SaveSecDerGrad(     this_ptr);
       AddVar_Iterate(            this_ptr);
       AddVar_UpdateResult(       this_ptr);
       AddVar_GetOutputImage(     this_ptr);
       AddVar_GetAttachVect(      this_ptr);
       AddVar_End(                this_ptr);
    }

};


#endif
// _wrap_vtkLevelSets_h_
