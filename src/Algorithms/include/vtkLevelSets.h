/*  ==================================================
    Module : vtkLevelSets
    Authors: Karl Krissian (from initial code by Liana Lorigo and Renaud Keriven)
    Email  : karl@bwh.harvard.edu

    This module implements a Active Contour evolution
    for segmentation of 2D and 3D images.
    It implements a 'codimension 2' levelsets as an
    option for the smoothing term.
    It comes with a Tcl/Tk interface for the '3D Slicer'.
    ==================================================
    Copyright (C) 2003  LMI, Laboratory of Mathematics in Imaging, 
    Brigham and Women's Hospital, Boston MA USA

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    ================================================== 
   The full GNU Lesser General Public License file is in vtkLevelSets/LesserGPL_license.txt
*/



// .NAME vtkLevelSets -  Vessels segmentation method
// .SECTION Description
// Implementation of Liana Lorigo's method to segment automatically
// vessels or cilindrical structures.
// 

#ifndef __vtkLevelSets_h
#define __vtkLevelSets_h

#include <vtkLevelSetsConfigure.h>
#include "vtkImageData.h"
#include "vtkImageAlgorithm.h"

#include "vtkLevelSetFastMarching.h"
#include "vtkImageIsoContourDist.h"
#include "vtkImageFastSignedChamfer.h"
#include "vtkImagePropagateDist2.h"
#include "std_common.h"
#include "vtk_common.h"

#define ADVECTION_UPWIND_VECTORS  0
#define ADVECTION_CENTRAL_VECTORS 1
#define ADVECTION_MORPHO          2

#define BALLOON_BROCKETT_MARAGOS   0
#define BALLOON_VESSELS            1

#define DISTMAP_CURVES       0
#define DISTMAP_FASTMARCHING 1
#define DISTMAP_CHAMFER      2 
#define DISTMAP_SHAPE        3

#define WHITE_STRUCTURE 0
#define BLACK_STRUCTURE 1

class VTK_LEVELSETS_EXPORT vtkLevelSets : public vtkImageAlgorithm
{
public:
  static vtkLevelSets *New();
  vtkTypeMacro(vtkLevelSets,vtkImageAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);
  
  vtkSetMacro(isotropic_voxels,int);
  vtkGetMacro(isotropic_voxels,int);
  vtkBooleanMacro(isotropic_voxels,int);

  // Description
  // Rescale data to 0-255
  vtkSetMacro(RescaleImage,int);
  vtkGetMacro(RescaleImage,int);
  vtkBooleanMacro(RescaleImage,int);
  // Description
  // Input parameters of method: InitThreshold, check_freq,numiters, reinit_freq,
  // converged_thresh, imscale, do_mean and band
  vtkSetMacro(InitThreshold,float);
  vtkGetMacro(InitThreshold,float);

  vtkSetMacro(SquaredGradientEpsilon,double);
  vtkGetMacro(SquaredGradientEpsilon,double);

  //
  vtkSetMacro(UseLowThreshold,int);
  vtkGetMacro(UseLowThreshold,int);
  vtkBooleanMacro(UseLowThreshold,int);

  //
  vtkSetMacro(LowThreshold,float);
  vtkGetMacro(LowThreshold,float);

  //
  vtkSetMacro(UseHighThreshold,int);
  vtkGetMacro(UseHighThreshold,int);
  vtkBooleanMacro(UseHighThreshold,int);

  //
  vtkSetMacro(HighThreshold,float);
  vtkGetMacro(HighThreshold,float);

  //
  vtkSetMacro(ProbabilityHighThreshold,float);
  vtkGetMacro(ProbabilityHighThreshold,float);

  //
  vtkSetMacro(StepDt,float);
  vtkGetMacro(StepDt,float);
  //

  // current iteration number
  //
  vtkSetMacro(step,int);
  vtkGetMacro(step,int);
  //
  vtkSetMacro(CheckFreq,int);
  vtkGetMacro(CheckFreq,int);
  //
  vtkSetMacro(NumIters,int);
  vtkGetMacro(NumIters,int);
  //
  vtkSetMacro(ReinitFreq,int);
  vtkGetMacro(ReinitFreq,int);
  //
  vtkSetMacro(ConvergedThresh,float);
  vtkGetMacro(ConvergedThresh,float);
  //
  vtkSetMacro(AdvectionCoeff,float);
  vtkGetMacro(AdvectionCoeff,float);
  //
  vtkSetMacro(DoMean,int);
  vtkGetMacro(DoMean,int);
  vtkBooleanMacro(DoMean,int);

  //
  vtkSetMacro(AffineCurvature,int);
  vtkGetMacro(AffineCurvature,int);
  vtkBooleanMacro(AffineCurvature,int);

  //
  vtkSetMacro(Band,int);
  vtkGetMacro(Band,int);

  //
  vtkSetMacro(ShapeMinDist,int);
  vtkGetMacro(ShapeMinDist,int);

  //
  vtkSetMacro(Tube,int);
  vtkGetMacro(Tube,int);
  
  // Distance Map algorithm
  // 0: old curve method
  // 1: fast marching method with conservation of the sub-voxel surface position
  // 2: Fast signed Chamfer 
  // 3: Shape-based levelset: propagation Danielsson
  vtkSetMacro(DMmethod,int);
  vtkGetMacro(DMmethod,int);

  //
  vtkSetMacro(EvolveThreads,int);
  vtkGetMacro(EvolveThreads,int);

  //
  vtkSetMacro(savedistmap,int);
  vtkGetMacro(savedistmap,int);
  vtkBooleanMacro(savedistmap,int);

  //
  vtkSetMacro(savesecdergrad,int);
  vtkGetMacro(savesecdergrad,int);
  vtkBooleanMacro(savesecdergrad,int);

  //
  vtkSetMacro(advection_scheme,int);
  vtkGetMacro(advection_scheme,int);
  //  vtkBooleanMacro(advection_scheme,int);


  //
  vtkSetMacro(balloon_scheme,int);
  vtkGetMacro(balloon_scheme,int);


  /*  //
  vtkSetMacro(GeodesicEquation,int);
  vtkGetMacro(GeodesicEquation,int);
  vtkBooleanMacro(GeodesicEquation,int);
  */

  //
  vtkSetMacro(UseCosTerm,int);
  vtkGetMacro(UseCosTerm,int);
  vtkBooleanMacro(UseCosTerm,int);

  //
  vtkSetMacro(IsoContourBin,int);
  vtkGetMacro(IsoContourBin,int);
  vtkBooleanMacro(IsoContourBin,int);

  //
  // Dimension 2 for 2D, 3 for 3D
  //
  vtkSetMacro(Dimension,int);
  vtkGetMacro(Dimension,int);

  // slice number for 2D level set
  vtkSetMacro(SliceNum,int);
  vtkGetMacro(SliceNum,int);

  //
  // Image of velocity vectors
  //
  vtkSetObjectMacro(velocity,vtkImageData);
  vtkGetObjectMacro(velocity,vtkImageData);

  //
  vtkSetMacro(coeff_velocity,float);
  vtkGetMacro(coeff_velocity,float);

  // 0: additive 1: multiplicative
  vtkSetMacro(velocity_type,int);
  vtkGetMacro(velocity_type,int);

  // Balloon expansion force

  // Set Constant expansion
  vtkSetMacro(balloon_coeff,float);
  vtkGetMacro(balloon_coeff,float);

  // Set Image based Expansion 
  vtkSetObjectMacro(balloon_image,vtkImageData);
  vtkGetObjectMacro(balloon_image,vtkImageData);

  /**
   * Use initial image for the level set
   * @param  
   */
  virtual void SetinitImage(vtkImageData*);
  vtkGetObjectMacro(initImage,vtkImageData);

  void SetInitIntensityBright() { InitIntensity=Bright; }
  void SetInitIntensityDark()   { InitIntensity=Dark; }

  // Set/Get Skeleton Image
  virtual void SetSkeletonImage(vtkImageData*);
  vtkGetObjectMacro(SkeletonImage,vtkImageData);

  //
  vtkSetMacro(HistoGradThreshold,float);
  vtkGetMacro(HistoGradThreshold,float);

  //
  vtkSetMacro(coeff_curvature,float);
  vtkGetMacro(coeff_curvature,float);

  //
  vtkSetMacro(ProbabilityThreshold,float);
  vtkGetMacro(ProbabilityThreshold,float);

  //
  vtkSetMacro(verbose,unsigned char);
  vtkGetMacro(verbose,unsigned char);

  void SetNumInitPoints( int n);
  void SetInitPoint(int num, int x, int y, int z, int radius);

  void SetNumGaussians( int n);
  void SetGaussian(int num, float mean, float sd);

  /**
   * Reset the distance map (the old function reinit)
   */
  void DistanceMap();

  /**
   * initial code of curves
   */
  void DistanceMapCurves();

  /**
   * fast marching distance map
   */
  void DistanceMapFMOld();
  void DistanceMapFM();    // use vtkImageIsoContourDist

  /**
   * fast signed Chamfer distance map
   */
  void DistanceMapChamfer();
      
  /**
   * Propagating Danielsson Distance + skeleton and distance to the skeleton
   */
  void DistanceMapShape();
      
  void InitParam(  vtkImageData* in, vtkImageData* out);

  void ResizeBand();

  void InitEvolution();
  int  Iterate();
  void EndEvolution();

  /**
   * Set a curvature weight for the geodesic framework
   * @param CW 
   */
  void SetCurvatureWeights( float* CW)
  //
  {
    curvature_weight = CW;
  }


  //
  void SetAdvectionVectorField( float* DAx, float* DAy, float* DAz)
  {
    advection_scheme = ADVECTION_UPWIND_VECTORS;
    // here make a copy
    if (imsize==0) {
      std::cerr << "SetAdvectionVectorField() \t imsize==0! " << std::endl;
      return;
    }
    data_attach_x = float_vec( DAx, DAx + imsize );
    data_attach_y = float_vec( DAy, DAy + imsize );
    data_attach_z = float_vec( DAz, DAz + imsize );

    // don't call PreComputeDataAttachment() because the pointers are not NULL anymore
  }


  void GetDataAttach( float_vec& DAx, float_vec& DAy, float_vec& DAz)
  {
    switch (advection_scheme) {
    case ADVECTION_UPWIND_VECTORS:
    case ADVECTION_CENTRAL_VECTORS:
      DAx = data_attach_x;
      DAy = data_attach_y;
      DAz = data_attach_z;
      break;

      // In this case, just return the second order derivatives in the gradient direction (normalized)
      // and the norm of the gradient
    case ADVECTION_MORPHO:
      std::cerr << "GetDataAttach() not available with ADVECTION_MORPHO, todo ... " << std::endl;
/* TODO:
      DAx = secdergrad;
      DAy = normgrad;
      DAz = NULL;
*/
      break;
    }
  }

  /**
   * just copy the values when processing the next iteration the array provided MUST be allocated or NULL for cancelling the action.
   * @param data 
   */
  void GetCurvatureTerm(  float* data) { curvature_data = data; }
  void GetAdvectionTerm(  float* data) { advection_data = data; }
  void GetVelocityTerm(   float* data) { velocity_data  = data; }
  void GetBalloonTerm(    float* data) { balloon_data   = data; }
  void GetDistanceMap(    float* data) { distance_data  = data; }

  /**
   * public methods for multithreading
   * @param first 
   * @param last 
   * @param num 
   * @param total 
   * @return 
   */
  int  SplitBand(int& first, int& last, int num, int total);
  void Evolve3D(int first_band, int last_band);

  void PrintParameters();

  /**
   * Updates the resulting image so that it contains the current result
   * @return 
   */
  int UpdateResult();

  /**
   * Compute mean and standard deviation of the intensity
   *  within the initial spheres or disks
   * @param stats[] 
   */
  void InitPointsStatistics(float stats[2]);

  /**
   * Precompute the probability Lookup Table is the image was rescaled to [0,255]
   */
  void ComputeProbabilityLUT();

  /**
   * Probability of the tissue based on the image intensity.
   * @param I 
   * @param compute 
   * @return 
   */
  float ExpansionMap( float I, unsigned char compute=0);

protected:
  vtkLevelSets();
  ~vtkLevelSets();
  //vtkLevelSets(const vtkLevelSets&) {};
  //  void operator=(const vtkLevelSets&) {};
  //

  void          MakeBand( );
  void          MakeBand0( );
  void          ExtractCoords(   int p, short &x, short &y, short &z);


  void          Evolve();
  void          Evolve3D();
  void          Evolve2D();

  unsigned char CheckConvergence();
  void          CheckConvergenceNew();

  void PreComputeDataAttachment();

  void NormalizeSecDerGrad();

  //  void Execute(vtkImageData *inData, vtkImageData *outData);
  void ExecuteData( vtkDataObject *outData);

//BTX
  int   RescaleImage;
  float minu,maxu;

  // Minimal distance computed inside the structure for 
  // searching the skeleton in case of Shape-based level set
  int   ShapeMinDist; 

  int   Band;
  int   Tube;
  int   NumIters;
  int   DoMean;
  int   AffineCurvature;

  // Contour Attachment coeff
  float AdvectionCoeff;

  int   CheckFreq;
  int   ReinitFreq;
  float ConvergedThresh;
  float StepDt;
  float init_dt;
  float HistoGradThreshold;
  float coeff_curvature;

  int   DMmethod; // Distance Map algorithm
    // 0: curves
    // 1: fast marching
    // 2: Fast Signed Chamfer
    // 3: Shape based

  // for testing, create isocontour with 0.5 and -0.5 values
  int   IsoContourBin;

  int   UseCosTerm; // Use the cosinus term of Liana's paper

  int Dimension; // 2 for 2D and 3 for 3D
  int SliceNum; // slice number for 2D level set

  int       tx,ty,tz,txy;
  float_vec::size_type imsize;

  // values of the narrow Band
  float_vec  u[2];
  // current elt used
  int               current;

  //------------------- Narrow Band information
  // should be in a separate class ...
  int_vec           bnd;
  float_vec         bnd_initialvalues;
  uchar_vec         flag;

  int               distmap_count;
  int               band_count;

  unsigned char *stored_seg;
  unsigned char stored_seg_allocated;

  // Save the intermediary distance maps
  unsigned char savedistmap;

  // Save the the second order derivatives of the gradient
  unsigned char savesecdergrad;

  unsigned char advection_scheme;

  unsigned char balloon_scheme;

  // Parameters for the evolution
  // current step
  int step;
  // reinitialize the contour ?
  int reinitcntr;

  int touched; // if the contour touched the outer narrow band

  int EvolveThreads; // number of threads for Evolve()

  unsigned char verbose;


  // Curvature Weight for the geodesic framework
  float*        curvature_weight;

  // Precomputed data attachment vector field  H*DI/|DI|
  float_vec     data_attach_x;
  float_vec     data_attach_y;
  float_vec     data_attach_z;

  float*        secdergrad;
  float*        normgrad;
  float         max_normgrad;
  

  float*  curvature_data;
  float*  advection_data;
  float*  velocity_data;
  float*  balloon_data;
  float*  distance_data;


  // We copy input data to float, just to avoid
  // template function in .cxx
  vtkImageData* inputImage;
  int inputImage_allocated;

  vtkImageData* velocity;
  float         coeff_velocity;
  int           velocity_type;

  // Initialization of the balloon force
  float         balloon_coeff;
  vtkImageData* balloon_image;

  // Number of Gaussians for probability map
  int           NumGaussians;
  float**       Gaussians;
  float*        Probability;
  float         ProbabilityThreshold;
  float         ProbabilityHighThreshold;


  // Initialization Parameters
  vtkImageData* initImage;
  float         InitThreshold;
  double        SquaredGradientEpsilon;
  enum TInitIntensity { Bright, Dark };
  TInitIntensity InitIntensity;

  // Number of seeding points for initialization
  int   NumInitPoints;
  int** InitPoints;

  // High and Low intensity thresholds
  int   UseLowThreshold;
  float LowThreshold;
  int   UseHighThreshold;
  float HighThreshold;


  vtkImageData *outputImage;

  // In case of shape-based levelset
  vtkImageData *SkeletonImage;
  unsigned char SkeletonImage_allocated;

  boost::shared_ptr<vtkLevelSetFastMarching>   fm;
  boost::shared_ptr<vtkImageIsoContourDist>    isodist;
  boost::shared_ptr<vtkImageFastSignedChamfer> chamfer;
  boost::shared_ptr<vtkImagePropagateDist2>    shape;


  // some precomputed values
  // voxel size
  float vx,vy,vz;
  float sqxspacing,sqyspacing,sqzspacing;
  float doubxspacing,doubyspacing,doubzspacing;
  float xyspacing,yzspacing,xzspacing;

  int isotropic_voxels;

  // statistics per iteration
  double mean_curv     ;
  double mean_balloon  ;
  double mean_advection;
  double mean_vel      ;

  // Memory management
  float MemoryAllocated;

//ETX
};

#endif


