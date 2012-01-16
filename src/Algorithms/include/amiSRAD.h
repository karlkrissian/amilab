
#pragma once
#ifndef _amiSRAD_h_
#define _amiSRAD_h_

#include "AlgorithmsConfigure.h"
#include "inrimage.hpp"
#include "amiImageExtent.h"

namespace ami {

/**
 * Class containing modified versions of the 
 * Speckle Reducing Anisotropic Diffusion
 * (SRAD) denoising filter
 */
class Algorithms_EXPORT SRAD 
{
public:

  /* deprecated macros
  #define MODE_LEE       0
  #define MODE_KUAN      1
  #define MODE_ADDITIVE  2
  #define MODE_MRI       3
  #define MODE_MRI_NEW   4
  */
  enum EquationType {
    MODE_LEE,      //! multiplicative noise for speckle reduction, Lee equation
    MODE_KUAN,     //! multiplicative noise for speckle reduction Kuan equation
    MODE_ADDITIVE, //! additive noise for speckle reduction
    MODE_MRI,      //! MRI Rician noise model
    MODE_MRI_NEW,  //! MRI Rician noise model, new version of the equation
  };

  
  enum NoiseEstimationMode {
    MODE_AUTO, //! default estimation mode, depending on the equation type
    MODE_HISTOMODE, //! using the mode of the local variance histogram
  };
  
  static NoiseEstimationMode noise_estimation_mode;
  
private:

  static double Cmad(InrImage* im);

  static double Compute_q0_subvol(InrImage* im, 
                                  int mode, 
                                  ami::ImageExtent<float>* extent);

  static double Compute_q0_2(InrImage* im, int mode, 
                             ami::ImageExtent<float>* extent);

  static double Compute_sigma2_MRI( InrImage* im, 
                                    ami::ImageExtent<float>* extent);

  
  static double Compute_sigma2_MRI_mode(  InrImage* im, 
                                          ami::ImageExtent<float>* extent, 
                                          bool square_root = true);

  static double Compute_q0_2( InrImage* im, 
                              InrImage* meanI, 
                              InrImage* meanI2, 
                              int mode, 
                              int neighborhood);


  static double function_c     (    double q_2, double q0_2);
  static double function_c_Kuan(    double q_2, double q0_2);
  static double function_c_MRI(     double sigma2, double vg, double meang);
  static double function_c_additive(double q_2, double q0_2);

  static double function_q2(double dI_I_2, double d2I_I);
  static double function_q0(double t, double rho, double q0);
  
  static void Compute_q_coeff(InrImage* image_in, InrImage* image_q );

  static void Compute_d_coeff(  InrImage* image_res,
                                InrImage* image_c,
                                InrImage* image_d, 
                                double& dt1, 
                                int mode, 
                                int neighborhood, 
                                ami::ImageExtent<float>* extent);

  static void UpdateResult2(InrImage* image_res,
                            float dt, 
                            InrImage* image_c, 
                            InrImage* image_d, 
                            int neighborhood, 
                            SRAD::EquationType mode, 
                            ami::ImageExtent<float>* extent) ;
  
  
public:

  /**
   * The way to estimate the image noise standard deviation
   * depends on the equation mode:
   *   - if Lee or Kuan, it is estimated globally within the ROI
   *   - if Additive, ... 
   *   - if MRI, ...
   */
  static void SetNoiseEstimationMode( SRAD::NoiseEstimationMode m) 
  { 
    noise_estimation_mode = m;
  }
  
  static SRAD::NoiseEstimationMode GetNoiseEstimationMode() {
    return noise_estimation_mode;
  }
  
  //----------- SRAD --------------
  //
  static InrImage::ptr qcoeff( InrImage* input);

  /**
   * Explicit numerical scheme
   * @param input input image to denoise
   * @param dt equation time step
   * @param numit number of iterations
   * @param mode equation mode
   *      0: initial Lee 2+2(+2 in 3D) neighboors
   *      1: 3x3(x3) neighboors
   *      n>0: (2n+1)x(2n+1)[x(2n+1)] neighboors
   * @param neighborhood size of neighborhood to compute the local statistics
   * @param extent image extent to process
   */
  static InrImage::ptr SRAD_ver1(  InrImage* input, float dt, int numit, 
                          EquationType mode, int neighborhood,
                          ImageExtent<float>* extent = NULL);

  /**
   * Semi-implicit numerical scheme
   *  Runs a noise reducing anisotropic diffusion, Lee and Kuan's mode are
   *    for speckle noise in ultrasound images, additive mode is for additive
   *    stationary noise and MRI is for MRI style noise. In the case of MRI,
   *    the filter is designed to run on the square of the image intensity.
   * 
   * @param input input image to denoise
   * @param dt equation time step
   * @param numit number of iterations
   * @param mode equation mode
   * @param neighborhood size of neighborhood to compute the local statistics
   *      0: initial Lee 2+2(+2 in 3D) neighboors
   *      1: 3x3(x3) neighboors
   *      n>0: neighborhood is (2n+1)^N, where N is the dimension of the 
   *            image domain
   * @param extent image extent: area of interest to calculate the noise
   *               standard deviation, usually a constant area, 
   *               for MRI denoising: background area
   */
  

  static InrImage::ptr SRAD_ver2( InrImage* input, float dt,  int numit, 
                                  EquationType mode, int neighborhood,
                                  ImageExtent<float>* extent = NULL);

  /**
   * Like SRAD_ver1 but forcing equation mode to Kuan
   * compatibility function based on previous grammar rule
   */
  static InrImage::ptr AnisoDPAD( InrImage* input, 
                                  float dt, 
                                  int numit, 
                                  int neighborhood,
                                  ami::ImageExtent<float>* extent);

  /**
   * Like SRAD_ver2 but forcing equation mode to Kuan
   * compatibility function based on previous grammar rule
   */
  static InrImage::ptr AnisoDPAD2( InrImage* input, 
                                   float dt, 
                                   int numit, 
                                   int neighborhood,
                                   ami::ImageExtent<float>* extent);
  
  /**
   * Like SRAD_ver2 
   * compatibility function based on previous grammar rule
   * warning: notice the change of the order of the parameters
   */
  static InrImage::ptr AnisoNRAD( InrImage* input, 
                                  EquationType mode, 
                                  float dt,  
                                  int numit, 
                                  int neighborhood,
                                  ImageExtent<float>* extent = NULL);
  

  /**
   * Calling SRAD_ver2 with 
   *  Additive mode and Yu neighborhood (0)
   * compatibility function based on previous grammar rule
   */
  static InrImage::ptr AnisoLeeAdd2(  InrImage* input, float dt, int numit,
                                      ami::ImageExtent<float>* extent);

  
}; // end class SRAD

} // end namespace ami

#endif // _amiSRAD_h_
