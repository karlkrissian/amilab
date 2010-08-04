//
// C++ Interface: wrap_AnisoGS
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_AnisoGS_h_
#define _wrap_AnisoGS_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include <wx/html/htmlwin.h>

class AnisoGS;

class WrapClass_AnisoGS : public WrapClassBase
{
  DEFINE_CLASS(WrapClass_AnisoGS);

  // for nested classes
  typedef WrapClass_AnisoGS::ptr _parentclass_ptr;
  typedef AnisoGS _obj_type;

  public:
    boost::shared_ptr<_obj_type> _obj;
    const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }

    /// Constructor
    WrapClass_AnisoGS(boost::shared_ptr<AnisoGS> si): _obj(si)
    {}

    ADD_CLASS_METHOD(Init,    "Sets parameters for the anisotropic diffusion algorithm using Gauss-Seidel scheme.");

    ADD_CLASS_METHOD(SetDistMap,        "Set the mode to compute Euclidean Distance Map.");
    ADD_CLASS_METHOD(SetNoiseType,      "Sets the noise type to 0:Gaussian or 1:Speckle, by default Gaussian.");
    ADD_CLASS_METHOD(SetMask,           "Sets the mask image.");
    ADD_CLASS_METHOD(SetSRADROI,        "Sets the region of interest (region of constant tissue in the image) and activates the Oriented Speckle Reducing Anisotropic Diffusion.");
    ADD_CLASS_METHOD(SetRNRADROI,       "Sets the region of interest (region of constant tissue in the image) and activates the Rician Noise Reducing Anisotropic Diffusion used to reduce noise in MRI data.");
    ADD_CLASS_METHOD(SetRNRADROI_NEW,   "Sets the region of interest (region of constant tissue in the image) and  activates the Rician Noise Reducing Anisotropic Diffusion used to reduce noise in MRI data. New version of the filter, using local directional mean and variance for the diffusion matrix. ");
    ADD_CLASS_METHOD(SetLocalStruct,    "Sets the local structure mode.");
    ADD_CLASS_METHOD(SetEigenMode,      "Choose a way to select the diffusion matrix eigenvalues.");
    ADD_CLASS_METHOD(Setdt,             "Sets the time-step value for the PDE.");
    ADD_CLASS_METHOD(Setneighborhood,   "Sets the size of the neighborhood to compute the local statistics.");
    ADD_CLASS_METHOD(setcoeff,          "Sets the diffusion coefficients in the minimal and maximal curvature directions.");
    ADD_CLASS_METHOD(Iterate,           "Runs one iteration of the PDE.");
    ADD_CLASS_METHOD(GetNoiseSD,        "Gets the estimated noise standard deviation.");
    ADD_CLASS_METHOD(SetNoiseSD,        "Sets the estimated noise standard deviation.");
    ADD_CLASS_METHOD(GetDAcoeff,        "Returns estimated Data Attachment coefficient, only for constrained anisotropic diffusion method.");
    ADD_CLASS_METHOD(GetOutput,         "Returns the output image after remove the boundary extension.");
    ADD_CLASS_METHOD(GetDiffCoeff,      "Returns the image of the diffusion coefficients.");
    ADD_CLASS_METHOD(Compute_sigma2_MRI_mode, "Returns the estimated variance of the Rician noise within the selected region of interest");

    void AddMethods(_parentclass_ptr& this_ptr )
    {
      // replace init by Init
      AddVar_Init(            this_ptr);
      AddVar_setcoeff(        this_ptr);
      AddVar_SetDistMap(      this_ptr);
      AddVar_SetNoiseType(    this_ptr);
      AddVar_SetNoiseSD(      this_ptr);
      AddVar_SetMask(         this_ptr);
      AddVar_SetSRADROI(      this_ptr);
      AddVar_SetRNRADROI(     this_ptr);
      AddVar_SetRNRADROI_NEW( this_ptr);
      AddVar_SetLocalStruct(  this_ptr);
      AddVar_SetEigenMode(    this_ptr);
      AddVar_Setdt(           this_ptr);
      AddVar_Setneighborhood( this_ptr);
      AddVar_setcoeff(        this_ptr);
      // replaces iterate by Iterate
      AddVar_Iterate(         this_ptr);
      // end is remove: useless
      //AddVar_end(             this_ptr);
      AddVar_GetNoiseSD(      this_ptr);
      AddVar_SetNoiseSD(      this_ptr);
      AddVar_GetDAcoeff(      this_ptr);
      AddVar_GetOutput(       this_ptr);
      AddVar_GetDiffCoeff(    this_ptr);

      AddVar_Compute_sigma2_MRI_mode( this_ptr);
    }

};

/**
 * Create a Wrapped object around _AnisoGS
 * @param objectptr input smart pointer to a WrapClass_AnisoGS
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_AnisoGS(  WrapClass_AnisoGS::ptr& objectptr);

/**
 * Create a Wrapped object around _AnisoGS
 * @param si_ptr input smart pointer to a _AnisoGS
 * @return smart pointer to an AMIObject class
 */
Variable<AMIObject>::ptr CreateVar_AnisoGS( AnisoGS* si);

/** Method that adds wrapping of AnisoGS 
 */
ADD_CLASS_FUNCTION( AnisoGS, "Wrapping of AnisoGS denoising filter: Anisotropic Diffusion filter with different options and implemented using Gauss-Seidel scheme." );


#endif // _wrap_AnisoGS_h_
