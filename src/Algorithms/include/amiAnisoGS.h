//
// C++ Interface: AnisoGS
//
// Description: Denoising filter
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _AnisoGS_h_
#define _AnisoGS_h_

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
  class AnisoGS {

    DEFINE_CLASS(AnisoGS);

  public:

    enum ContourMode {
      CONTOURS_FLUX, /**< Matrix diffusion based on Flux-based anisotropic diffusion paper. */
      CONTOURS_OSRAD, /**< Matrix diffusion based on OSRAD paper */
      CONTOURS_NRAD, /**< Matrix diffusion based on NRAD paper 
                        * new version using directional local statistics 
                        * for the diffusion matrix. */
    };
  
    enum NoiseEstimationModel {
      NOISE_LEE,  /**< Multiplicative Gaussian noise with Lee's estimation (Speckle)*/
      NOISE_KUAN, /**< Multiplicative Gaussian noise with Kuan's estimation (Speckle) */
      NOISE_GAUSSIAN_ADDITIVE,/**< Additive Gaussian noise */
      NOISE_RICIAN /**< Rician noise (MRI)*/
    };

  private:
    
    bool debug_voxel;
    
    /**
    * @name Precomputed pointers to neighborhood
    **/
    //@{ 
    float* I0;
    float* Ixp;
    float* Ixm;
    float* Iyp;
    float* Iym;
    float* Izp;
    float* Izm;
    float* Ixpxp;
    float* Iypyp;
    float* Izpzp;
    float* Ixpyp;
    float* Ixpym;
    float* Ixmyp;
    float* Ixmym;
    float* Ixpzp;
    float* Ixpzm;
    float* Ixmzp;
    float* Ixmzm;
    float* Iypzp;
    float* Iypzm;
    float* Iymzp;
    float* Iymzm;

    float* Ixpypzp;
    float* Ixpypzm;
    float* Ixpymzp;
    float* Ixpymzm;
    float* Ixmypzp;
    float* Ixmypzm;
    float* Ixmymzp;
    float* Ixmymzm; 
    //@}


    float      alpha_x, gamma_x;
    float*     alpha_y;
    float*     gamma_y;
    float**    alpha_z;
    float**    gamma_z;
    
    
    /// Gaussian smoothing filter
    GeneralGaussianFilter*  filtre;
    FiltrageRec*            filtre_rec;
    DeriveesLissees*        DerLiss;
    
    //-------- Parameters
    int             mode; // MODE_2D or MODE_3D
    unsigned char   use_filtre_rec;
    unsigned char   opt_mem;
    float           sigma;


    int     iteration;
    int     loop, max_loop;
    float       k;
    float       epsilon;
    int     tx,ty,tz,txy;

    int ROI_xmin,ROI_xmax;
    int ROI_ymin,ROI_ymax;
    int ROI_zmin,ROI_zmax;

  
    // for structure tensor eigenvectors
    FloatMatrix*     matrice;
    float            vap[3];
    FloatMatrix*     vec_propre;

    unsigned char noise_SD_preset;
    double variance;

    
    /** Get the minimal and maximal intensity of the initial image
      to limit unstabilities
    **/
    float min_intensity;
    float max_intensity;

    //  int       contours_mode;
    //  InrImage* SRAD_ROI;

    // for 2D
    void InitNeighborhood(float* I,int x,int y);
    void Grad2D(float* I,float grad[2]);
    void Grad2DShiftX(float* I, t_3Point& grad);
    void Grad2DShiftY(float* I, t_3Point& grad);

    // for 3D
    void InitNeighborhood(float* I,int x,int y, int z);
    void Grad(float* I,float grad[3]);
    void GradShiftX(float* I,float grad[3]);
    void GradShiftY(float* I,float grad[3]);
    void GradShiftZ(float* I,float grad[3]);
    void Hessian(float* I,float** H);
    void HessianShiftX(float* I,float H[3][3]);
    void HessianShiftY(float* I,float H[3][3]);
    void HessianShiftZ(float* I,float H[3][3]);

    float Norm(float v[3]);
    float ScalarProduct(const t_Gradient v1, const t_3Point v2);

    void PrincipalCurvatures(float grad[3], float H[3][3],  float norm_grad,
                      t_3Point& e0, t_3Point& e1, t_3Point& e2);

    void StructTensor_eigenvectors( int coord, int x, int y, int z, 
                                    t_3Point& e0, t_3Point& e1, t_3Point& e2);

    unsigned char convert_uchar(double val);
    short         convert_short(double val);
    void GetVectors(int coord, int x, int y, int z, t_3Point& e0, t_3Point& e1, 
                    t_3Point& e2);


  protected:
    //-------  Images
    /// original input image
    InrImage::ptr input_image; 
    /// copy for processing
    InrImage::ptr image_entree;

    /// resulting image
    InrImage* result_image;

    /// smoothed version
    InrImage* image_lissee  ;
    InrImage::ptr im_tmp        ;

    /// image of the coefficients for SRAD type filtering
    InrImage* image_c; 

    /**
    * @name StructTensor 
    * Structure Tensor
    **/
    //@{ 
    /// 6 Components of the 3D structure tensor.
    InrImage* tensor_xx;
    InrImage* tensor_xy;
    InrImage* tensor_xz;
    InrImage* tensor_yy;
    InrImage* tensor_yz;
    InrImage* tensor_zz;
    //@}

    /**
    * @name Eigenvectors
    **/
    //@{ 
    InrImage* eigenvect_xp;
    InrImage* eigenvect_yp;
    InrImage* eigenvect_zp;
    //@}
  
  public:


    /// PDE time-step
    AddSetGetVar(dt,float);

    /// Size of the neighborhood
    AddSetGetVar(neighborhood,int);

    /// verbose output
    AddSetGetVar(verbose,bool);

    /// mask image
    AddSetGetVar( mask, InrImage::ptr)

    /// attachment mask image: only apply attachment term to pixel with mask
    /// value > 0.5
    AddSetGetVar( attach_mask, InrImage::ptr)
  
    AddSetGetVar( beta, float)

    /// Coefficient in the tangent direction (direction orthogonal to the gradient, only for 2D images).
    AddSetGetVar(tang_coeff, float)

    /// Coefficient in the maximal curvature direction
    AddSetGetVar(maxcurv_coeff, float)
    /// Coefficient in the minimal curvature direction
    AddSetGetVar(mincurv_coeff, float)

    /// noise Gaussian or Speckle, by default Gaussian
    AddSetGetVar(noise_type, int)
    AddSetGetVar(noise_standard_deviation, float)

    /// estimated data attachment coeff
    AddSetGetVar(estimated_DA_coeff,float);
    
    /** If true, uses the norm of the smoothed gradient
    as parameter of the first diffusion function
    otherwise uses the first order derivative of intensity
    in the direction of the smoothed gradient.
    **/
    AddSetGetVar(SmoothedParam,unsigned char);

    /// Computes Euclidian distance maps
    AddSetGetVar(DistanceMap,unsigned char);

    AddSetGetVar( contours_mode, ContourMode);

    AddSetGetVar( noise_model, NoiseEstimationModel);

    AddSetGetVar( SRAD_ROI,     InrImage::ptr);

    AddSetGetVar( local_structure_mode,  int);

    AddSetGetVar( diffusion_eigenvalues_mode,  int);

    InrImage* Getresult_image() 
    { 
      return this->result_image; 
    };

    InrImage* Getimage_c() 
    { 
      return this->image_c; 
    };

    InrImage::ptr GetOutput();
    
    InrImage* divFim        ;

    double   planstats_sigma;
    double   dirstats_sigma;

    int       boundary_extension_size;
    
    
    /**
    * @brief Run the anisotropic diffusion in one command
    *
    * @param input input image
    * @param sigma standard deviation of the Gaussian smoothing applied to 
    *              compute the local structure orientations.
    * @param k     diffusion parameter that controls the diffusion depending 
    *              on the local gradients.
    * @param beta  data attachment coefficient.
    * @param nbit  number of iterations.
    * @return InrImage:ptr resulting image
    **/
    static InrImage::ptr Run(InrImage::ptr input, float sigma, float k, 
                             float beta, int nbit);
    
    AnisoGS()
      {
        InitParam();
      }

    ~AnisoGS();

    /**
    * Initializes the parameters to default values.
    */
    void InitParam() 
    {
      verbose = false;
	  image_entree.reset();
      this->result_image= NULL;
      this->image_lissee  = NULL;
      this->image_c       = NULL;
      this->tensor_xx     = NULL;
      this->tensor_xy     = NULL;
      this->tensor_xz     = NULL;
      this->tensor_yy     = NULL;
      this->tensor_yz     = NULL;
      this->tensor_zz     = NULL;
      this->eigenvect_xp  = NULL;
      this->eigenvect_yp  = NULL;
      this->eigenvect_zp  = NULL;
  //    mask          = NULL;

      mode          = MODE_2D;

      this->planstats_sigma = 1.0;
      this->dirstats_sigma  = 1.5;

      divFim        = NULL;

      boundary_extension_size = MAX((int)(2*planstats_sigma+1.5),
                                    (int)(2*dirstats_sigma+1.5));

      matrice    = new FloatMatrix(3,3);
      vec_propre = new FloatMatrix(3,3);

      use_filtre_rec = false;
      opt_mem        = false;

      tang_coeff    = 1.0;
      maxcurv_coeff = 0.0;
      mincurv_coeff = 1.0;

      local_structure_mode       = LOCAL_STRUCT_CURV;
      diffusion_eigenvalues_mode = DIFF_MATRIX_EIGEN_SUM;

      noise_type = GAUSSIAN_NOISE;
      noise_standard_deviation = -1;
      noise_SD_preset=0;
      variance = 0;

      epsilon     = 1E-2;

      SmoothedParam = false;

      filtre_rec = NULL;
      filtre     = NULL;

      DistanceMap = 0;

      contours_mode  = CONTOURS_FLUX;
      noise_model    = NOISE_RICIAN;

      neighborhood = 1;
      dt = 0.05;
    }


    void ExtendBoundariesVonNeumann( InrImage::ptr input);
    void CreateBoundariesVonNeumann( InrImage::ptr input);

    void EstimateNoiseStandardDeviation( InrImage* im);

    void InitCoefficients();
    void ResetCoefficients();
    void DeleteCoefficients();


    double Compute_q0_subvol( InrImage* im);
    double function_c_Kuan(double q_2, double q0_2);
    double function_c_Lee(double q_2, double q0_2);

    double Compute_sigma2_MRI(InrImage* im);
    double Compute_sigma2_MRI_mode(     InrImage* im);
    double Compute_sigma2_Gaussian_mode(InrImage* im);
    double function_c_MRI(double sigma2, double vg, double meang);

    void Smooth(InrImage* im, float sigma);
    void ComputeStructureTensor(InrImage* im, float sigma1, float sigma2);
    void ComputeEigenVectors();

    void ComputeImage_c(InrImage*);

    /**
    * Iteration for 2D images.
    * @param im 
    * @return 
    */
    float Itere2D(   InrImage* im );

    /**
    * Iteration for 3D Images.
    * @param im 
    * @return 
    */
    float Itere3D(   InrImage* im );
//    float Itere3D_2( InrImage* im );

    float Itere3D_2_new( InrImage* im );
    float Itere3D_ST_RNRAD( InrImage* im );

    float Itere3D_distance( InrImage* im );
    float Itere3D_distance_flux( InrImage* im );
    float Itere3D_Flux( InrImage* im , InrImage* VectField, float coeff);
    float Itere3D_3( InrImage* im );

    void Init(InrImage::ptr in, float p_sigma, float p_k, float p_beta);

    /**
    * Main iteration method, directs to the appropriate specific method
    * @return 
    */
    float Iterate();

    //float IterateFlux( InrImage* vect, float coeff);

    void InitFlux( t_3Point& e0,t_3Point& e1,t_3Point& e2);



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

  }; // end class AnisoGS

} // end namespace ami

#endif // _AnisoGS_h_
