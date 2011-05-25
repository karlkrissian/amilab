//
// C++ Interface: wrapAMIFluid
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _WRAPAMIFLUID_H_
#define _WRAPAMIFLUID_H_

#include "paramlist.h"

/** function that add the wrapping of fluid function
 *  to the AMI language
 */
void AddWrapFluid(AMIObject::ptr&); 

// Wrapping functions:

// 2D correlation:
/* Function to compute 2D optif flow using a correlation technique */

void amiOpticFlowCorrelation2D(
    //
    InrImage* im1, InrImage* im2,
    InrImage* InputFlowX, InrImage* InputFlowY,
    InrImage* corr,
    InrImage* conf_x, InrImage* conf_y,
    int xInit, int yInit, /* Initial coordenate point to compute the correlation */
    int xIntervalSize, int yIntervalSize, /* Displacement between points for computing the correlation */
    int sizeCorrWinX, int sizeCorrWinY, /* Size of correlation window (it can be different in each axe) and it has to be a power of 2 */
    int windowDeformation /* Window parameter to control the warping in the correlation window;
        windowDeformation = 0 -> image2 is warped using flow in all points of the window,  
        windowDedormation = 1 -> image2 is warped using flow in the central point of the window */
);

void amiOpticFlowVariational2D(
  InrImage* im1,
  InrImage* im2,
  float sigma,
  float T,
  float alpha,
  int   dtype,
  float quantile,
  float ht,
  InrImage* u,
  InrImage* v,
  int Niter);

void amiOpticFlowVariational2DZoom(ParamList* p);

typedef float ami_v3f[3];

/**
 * FUNCTION TO COMPUTE 3D OPTIC FLOW USING A CORRELATION TECHNIQUE          
  * parameters:
 *  InrImage* image_1,
 *  InrImage* image_2,
 *  InrImage* u, 
 *  ami_v3f p_init,
 *  ami_v3f p_disp,
 *  int size_correlation_window[3],
 *  float window_deformation);
 */
void amiOpticFlowCorrelation3D( ParamList* params);

/**
  allows to use a downsampled vector field image
**/
void amiOpticFlowCorrelation3DNew( ParamList* params);
 
 /**
  *  Parameters:
   * FIRST IMAGE TO COMPUTE THE FLOW (INPUT DATA)
   * SECOND IMAGE TO COMPUTE THE FLOW (INPUT DATA) 
   * ZOOM FACTOR IN EACH DIMENSION IT HAS TO BE 1 OR 2
   * WEIGHT OF THE REGULARIZATION TERM 
   * CONVERGENCE PARAMETER OF GAUSS SEIDEL SCHEME 
   * NUMBER OF RESOLUTIONS IN THE PYRAMIDAL APPROACH 
   * CONVERGENCE PARAMETER FOR THE SCALE ITERATION
   * RADIENT IMPLEMENTATION TYPE USED
   *   gradient_type=0 : GRADIENT OF WARPED image_2
   *   gradient_type=1 : UPWIND METHOD FOLLOWING THE SIGN OF (image_1 AND WARPED image_2)
   *   gradient_type=2 : AVERAGE OF THE GRADIENT OF image_1 AND WARPED image_2 
   * 
  */
void amiOFPDE( ParamList* params);
 

 /**
   * Set different parameters for the Variational Optical Flow technique
   * 
  */
void amiOFPDE_Param( ParamList* params);

 /** 
  * Optic Flow with temporal smoothing
  */
void amiOF_2D_T( ParamList* params);
 

/** 
 * FUNCTION TO EXTRAPOLATE THE 3D OPTIC FLOW TO POINTS WHERE IS NOT DEFINED 
 */
void amiOpticFlowExtrapolationV3f( ParamList* );
 /**   norm 2 for vectors */
void amiNorm2Vect3DError( ParamList* );

 /**   norm 1 for vectors */
void amiNorm1Vect3DError( ParamList* );

 /**  fill boundaries for 3D scalar image */
void amiBoundary3D( ParamList* );

 /**  fill boundaries for 3D vector image */
void amiBoundaryVect3D( ParamList* );

 /**  gradient vector image */
void amiGrad3D( ParamList* );

 /** Norm max vector image */
void amiNormMaxVect3D( ParamList* );

/** Norm 3 vector image */
void amiNorm2Vect3D( ParamList*);

/** Interpolation of 3D scalar image */
void amiInterpolation3D( ParamList*);

/** Warping of 2D images using Splines */
InrImage* amiWarpSplines( ParamList*);

/** Interpolation of 3D vectorial image */
void amiInterpolationVect3D( ParamList*);

/** Copy of 3D scalar image */
void amiCopy3D( ParamList*);

/** Copy of 3D vectorial image */
void amiCopyVect3D( ParamList*);

/** Convolution of 3D image */
void amiConvolution3D( ParamList*);

/** Zoom down of 3D image */
InrImage* amiZoomDown3D( ParamList*);

/** Zoom up with filter of 3D image */
void amiZoomUpFilter3D( ParamList*);

/** Zoom up with interpolation of 3D image */
void amiZoomUpInterpolation3D( ParamList*);

/** Zoom up with flow of 3D image */
InrImage* amiZoomUpFlow3D( ParamList*);

/** Explicit Horn Schunck solution */
void amiHornSchunckOpticFlowExplicit( ParamList*);

/** Read 2D Vector Field in UV format */
InrImage* amiReadUV( ParamList*);

/** Inverse 2D Vector Field  */
InrImage* amiInverseFlow( ParamList*);

/**  FUNCTION TO COMPUTE THE SOLENOIDAL PROYECCION OF A FLOW */
void amiSolenoidalProjection3D( ParamList*);

/**  FUNCTION TO CHOOSE THE WAY TO COMPUTE THE GRADIENT IN THE PDE OPTICAL FLOW */
void amiOFSetGradient( ParamList*);

/**  FUNCTION TO CHOOSE IF WE APPLY SOLENOIDAL PROJECTION IN THE PDE OPTICAL FLOW */
void amiPDESetSolenoidal( ParamList*);

/**  FUNCTION TO enable/disable incompressibility constraint in the energy */
void amiPDESetEnergyConstraint( ParamList*);

/**  FUNCTION TO CHOOSE if the gradient is smoothed */
void amiOFSetSmoothGradient( ParamList*);

/**  FUNCTION TO CHOOSE if the smoothing constraint is global */
void amiOFSetGlobalConstraint( ParamList*);

/**  Function to choose the interpolation scheme for warping in Optical Flow */
void amiOFSetInterpolation( ParamList*);

/** Symmetric formulation for Optical Flow */
void amiOFSetSymmetric(ParamList*);

/** Symmetric formulation for Optical Flow */
void amiOFSetBoundaryType( ParamList* p);

/** Use alpha normalization? */
void amiOFSetNormalizeAlpha(ParamList*);

/** Epsilon for normalization of alpha for Optical Flow */
void amiOFSetAlphaNormEpsilon(ParamList*);

/**  Javier's version of Horn Schunck Optical Flow */
void amiJavierHornSchunck( ParamList*);

/**  Javier's version of Horn Schunck Symmetric Optical Flow */
void amiJavierHornSchunckSym( ParamList*);

/**  Javier and Agustin's version of Optical Flow */
void amiOpticFlow( ParamList*);

/** Vorticity estimation using Lucas-Kanade **/
void amiVorticity(ParamList*);

/** Vorticity estimation using Lucas-Kanade with Gradient computation **/
void amiGradVorticity(ParamList*);

/** Vorticity estimation (standard) **/
void amiVorticityStandard(ParamList*);

/** Load PDE OF parameters from file **/
void amiReadPDEOFParam(ParamList *);

/** Write PDE OF parameters to file **/
void amiWritePDEOFParam(ParamList *);

/** Read Yosemite Ground Truth in Float **/
InrImage* amiReadBarronData(ParamList*);

/** Generate synthetic flow aroud a sphere **/
void amiGenerateSphereFlow(ParamList*);

/** Generate synthetic 3D PIV flow based on a displacement field and a mask **/
void amiGenerate3DPIV(ParamList*);

/** Read a 3D Flow from an ASCII file **/
InrImage* amiReadFlow3D(ParamList*);


#endif // _WRAPAMIFLUID_H_
