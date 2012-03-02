//
// C++ Interface: AnisoGS_NRAD
//
// Description: Denoising filter
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _AnisoGS_NRAD_h_
#define _AnisoGS_NRAD_h_


#include "amiAnisoGSBase.h"

#include "style.hpp"
#include "DefineClass.hpp"
#include "inrimage.hpp"
#include "math1.hpp"
//#include "DeriveesLissees.hpp"
//#include "filtrage_rec.hpp"
#include "DirPrincipales.hpp"
#include "FloatMatrix.hpp"

class DeriveesLissees;
class FiltrageRec;
#include "GeneralGaussianFilter.h"


namespace ami {

  #define DER_DISCR 1
  #define DER_GAUSS 2

  #define MODE_2D 2
  #define MODE_3D 3

  #define GAUSSIAN_NOISE 0
  #define SPECKLE_NOISE  1



  #define IMPLICIT 1

  #define LOCAL_STRUCT_CURV   0 // use gradient and princ. curv. for the
                                // description of the local structure
  #define LOCAL_STRUCT_TENSOR 1 // Use the structure tensor

  #define DIFF_MATRIX_EIGEN_SUM 0 // version of the eigenvalues of the diffusion matrix using a sum of the local diffusion coefficients 
  #define DIFF_MATRIX_EIGEN_MAX 1 // version using the maximum

  #define MAX(a,b) ((a)>(b)?(a):(b))
  #define MIN(a,b) ((a)<(b)?(a):(b))

  #define AddSetGetVar( name, type) \
    type  name; \
    void Set##name( type _arg) \
    { \
      this->name = _arg; \
    };  \
    type Get##name() \
    { \
      return this->name; \
    };


  /**
   * This class contains several denoising filters based on Partial Differential
   * Equations, and usually implemented using a Gauss-Seidel scheme.
   */
  class AnisoGS_NRAD : public AnisoGSBase {

    DEFINE_CLASS(AnisoGS_NRAD);

  private:
    bool debug_voxel;
    
    // estimated noise variance
    double sigma2;
  
    
    struct IterationInfo {
      unsigned long   outoflimits;
      // Sum over all the points
      float           sum_divF;
      long int        nb_calculated_points;
      float           sum_divF2;
      long int        nb_calculated_points2;
      //
      int             nb_points_instables;
      //
      double          diff;
    };
    
    IterationInfo iteration_info;
    
  public:

    enum direction {
      DIR_X,
      DIR_Y,
      DIR_Z
    };

    AnisoGS_NRAD()
      {
        InitParam();
      }

    ~AnisoGS_NRAD();


    float Itere3D_ST_RNRAD( InrImage* im );

    void ComputeImage_c(InrImage*, double sigma2);
    
//    void Init(InrImage* in, float p_sigma, float p_k, float p_beta);

    /**
     * @brief Computes alpha and gamma coefficient at the current voxel
     * displaced by half in the given direction
     *
     * @param in pointer to the current voxel position
     * @param x current x position
     * @param y current y position
     * @param z current z position
     * @param xp increment in x
     * @param yp increment in y
     * @param zp increment in z
     * @param dir displacement direction
     * @param alpha resulting alpha coefficient
     * @param gamma resulting gamma coefficient
     * @return void
     **/
    void ComputeEquationCoefficient(  float* in, 
                                      int x, int y, int z,
                                      int xp, int yp, int zp,
                                      direction dir,
                                      double& alpha,
                                      double& gamma);

    virtual void  Process( int threadid = 0);
    virtual void  Run();

    /**
    * Main iteration method, directs to the appropriate specific method
    * @return 
    */
    float Iterate();

    /**
    * Compute the local  mean and standard deviation within a plan,
    *  using a Gaussian of standard deviation sd
    * @param im 
    * @param x 
    * @param y 
    * @param z 
    * @param d1 
    * @param d2 
    * @param sd 
    * @param mean 
    * @param var 
    */
    void ComputeLocalPlanStats(InrImage* im, float x, float y, float z, 
      t_3Point d1,t_3Point d2,
      float sd, double& mean, double& var);

    /**
    * Computes the local directional mean and standard deviation,
    * using a Gaussian of standard deviation sd
    * @param im input image
    * @param x 3D position
    * @param y  ..
    * @param z  ..
    * @param e 
    * @param sd 
    * @param mean returning mean value
    * @param var  returning variance value
    */
    void ComputeLocalDirStats(InrImage* im, float x, float y, float z, t_3Point e,
      float sd, double& mean, double& var);

  }; // end class AnisoGS_NRAD

} // end namespace ami

#endif // _AnisoGS_NRAD_h_
