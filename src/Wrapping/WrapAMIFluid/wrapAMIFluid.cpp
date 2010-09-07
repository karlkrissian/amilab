//
// C++ Implementation: wrapAMIFluid
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "paramlist.h"
#include "namespace.h"
#include "file_uv.h"

#include "OpticalFlow/inverse/inverse_optic_flow.h"
#include "OpticalFlow/inverse/inverse_optic_flow_3d.h"

typedef float real;
#include "OpticalFlow/Horn_Schunck/horn_schunck.h"
#include "OpticalFlow/Horn_Schunck/horn_schunck_sym.h"
#include "OpticalFlow/io_routines_yosemite.h"

#include "OpticalFlow/simple/optic_flow_video.h"


#include "ami_prototypes.h"
#include "ami_chi2.h"
#include "ami_vorticity_estimation.h"
#include "ami_utilities_3d.h"
#include "ami_lucas_kanade_2d_2o.h"
#include "ami_correlation2D.h"
#include "ami_correlation3D.h"
#include "ami_optic_flow_pde_3d.h"
#include "ami_optic_flow_pde_2d_t.h"

#include "ami_3dflow_sphere.hpp"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp" 
#include "wrapAMIFluid.h"
#include "ami_object.h"
#include "inrimage.hpp"

#include <string>
using namespace std;

extern VarContexts  Vars;

static PDEOpticFlowParam ami_optic_flow_param;



//---------------------------------------------------------
void AddWrapFluid(){

  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("AMIFluid");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

  ADDOBJECTVAR_NAME( C_wrap_procedure, "amiOFCorr3D",            amiOpticFlowCorrelation3D);
  ADDOBJECTVAR_NAME( C_wrap_procedure, "amiOFCorr3DNew",         amiOpticFlowCorrelation3DNew);
  ADDOBJECTVAR_NAME( C_wrap_procedure, "amiOFExtrapol3D",        amiOpticFlowExtrapolationV3f);
  ADDOBJECTVAR_NAME( C_wrap_procedure, "amiOFVar2DZoom",         amiOpticFlowVariational2DZoom);
  
  ADDOBJECTVAR_NAME( C_wrap_procedure, "amiOFExtrapolV3f",       amiOpticFlowExtrapolationV3f);
  
  ADDOBJECTVAR( C_wrap_procedure,  amiOFPDE);
  ADDOBJECTVAR( C_wrap_procedure,  amiOFPDE_Param);
  ADDOBJECTVAR( C_wrap_procedure,  amiOF_2D_T);
      
  ADDOBJECTVAR( C_wrap_procedure,  amiNorm2Vect3DError);
  ADDOBJECTVAR( C_wrap_procedure,  amiNorm1Vect3DError);
  ADDOBJECTVAR( C_wrap_procedure,  amiBoundary3D);
  ADDOBJECTVAR( C_wrap_procedure,  amiBoundaryVect3D);
  ADDOBJECTVAR( C_wrap_procedure,  amiGrad3D);
  ADDOBJECTVAR( C_wrap_procedure,  amiNormMaxVect3D);
  ADDOBJECTVAR( C_wrap_procedure,  amiNorm2Vect3D);
  ADDOBJECTVAR( C_wrap_procedure,  amiInterpolation3D);
  ADDOBJECTVAR( C_wrap_procedure,  amiInterpolationVect3D);
  ADDOBJECTVAR( C_wrap_procedure,  amiCopy3D);
  ADDOBJECTVAR( C_wrap_procedure,  amiCopyVect3D);
  ADDOBJECTVAR( C_wrap_procedure,  amiConvolution3D);
  
  ADDOBJECTVAR( C_wrap_imagefunction,  amiWarpSplines);
  
  ADDOBJECTVAR( C_wrap_imagefunction,  amiZoomDown3D);
  ADDOBJECTVAR( C_wrap_imagefunction,  amiReadUV);
  ADDOBJECTVAR( C_wrap_imagefunction,  amiReadFlow3D);
  ADDOBJECTVAR( C_wrap_imagefunction,  amiReadBarronData);
  ADDOBJECTVAR( C_wrap_imagefunction,  amiInverseFlow);
      
  ADDOBJECTVAR( C_wrap_procedure,  amiZoomUpFilter3D);
  ADDOBJECTVAR( C_wrap_procedure,  amiZoomUpInterpolation3D);
  ADDOBJECTVAR( C_wrap_imagefunction,  amiZoomUpFlow3D);

  ADDOBJECTVAR_NAME( C_wrap_procedure, "amiOFExplicit",            amiHornSchunckOpticFlowExplicit);
  ADDOBJECTVAR_NAME( C_wrap_procedure, "amiSolenoidalProj3D",      amiSolenoidalProjection3D);
  ADDOBJECTVAR_NAME( C_wrap_procedure, "amiOFSetGradient",         amiOFSetGradient);
  ADDOBJECTVAR_NAME( C_wrap_procedure, "amiOFSetSmoothGradient",   amiOFSetSmoothGradient);
  ADDOBJECTVAR_NAME( C_wrap_procedure, "amiPDESetSolenoidal",      amiPDESetSolenoidal);
  ADDOBJECTVAR_NAME( C_wrap_procedure, "amiPDESetEnergyConstraint",      amiPDESetEnergyConstraint);
  ADDOBJECTVAR( C_wrap_procedure,  amiOFSetGlobalConstraint);
  ADDOBJECTVAR( C_wrap_procedure,  amiOFSetBoundaryType);
  ADDOBJECTVAR( C_wrap_procedure,  amiOFSetInterpolation);
  ADDOBJECTVAR( C_wrap_procedure,  amiOFSetSymmetric);
  ADDOBJECTVAR( C_wrap_procedure,  amiOFSetNormalizeAlpha);
  ADDOBJECTVAR( C_wrap_procedure,  amiOFSetAlphaNormEpsilon);
  ADDOBJECTVAR( C_wrap_procedure,  amiJavierHornSchunck);
  ADDOBJECTVAR( C_wrap_procedure,  amiJavierHornSchunckSym);
  ADDOBJECTVAR( C_wrap_procedure,  amiOpticFlow);
  ADDOBJECTVAR( C_wrap_procedure,  amiReadPDEOFParam);
  ADDOBJECTVAR( C_wrap_procedure,  amiWritePDEOFParam);
  
  ADDOBJECTVAR( C_wrap_procedure,  amiVorticity);
  ADDOBJECTVAR( C_wrap_procedure,  amiGradVorticity);
  ADDOBJECTVAR( C_wrap_procedure,  amiVorticityStandard);
  ADDOBJECTVAR( C_wrap_procedure,  amiGenerateSphereFlow);
  ADDOBJECTVAR( C_wrap_procedure,  amiGenerate3DPIV);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  // 3. add the variables to this instance
  Vars.AddVar<AMIObject>( amiobject->GetName().c_str(),  amiobject);
}


/**
 * Adds the AMIFluid wrapping
 * @param p 
 */
void wrap_AMIFluid(ParamList* p)
{
  char functionname[] = "AMIFluid";
  char description[]=" \n\
    Adds wrapping for AMIFLuid library. \n\
          ";
  char parameters[] =" \n\
          ";

  AddWrapFluid();
}

//---------------------------------------------------------
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
) {

    int corrWin[2] = { sizeCorrWinX, sizeCorrWinY };
      
    // get the inputs in the format for processing
    float** image1_pos = im1->create_float_positions_2D();
    float** image2_pos = im2->create_float_positions_2D();

    float** flowX_pos = InputFlowX->create_float_positions_2D();
    float** flowY_pos = InputFlowY->create_float_positions_2D();

    float** corr_pos = corr->create_float_positions_2D();

    float** conf_x_pos = conf_x->create_float_positions_2D();
    float** conf_y_pos = conf_y->create_float_positions_2D();

    ami_qhc_optic_flow_correlation (
        &image1_pos, &image2_pos,
        im1->DimX(),im1->DimY(),
        flowX_pos, flowY_pos, 
        corr_pos,
        conf_x_pos, conf_y_pos,
        xInit,  yInit,
        xIntervalSize,  yIntervalSize,
        corrWin,
        (float) windowDeformation,
        1);

    // save and free results
    im1->free_float_positions_2D(image1_pos);
    im2->free_float_positions_2D(image2_pos);
    InputFlowX->free_float_positions_2D(flowX_pos);
    InputFlowY->free_float_positions_2D(flowY_pos);
    corr->free_float_positions_2D(corr_pos);
    conf_x->free_float_positions_2D(conf_x_pos);
    conf_y->free_float_positions_2D(conf_y_pos);
}


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
  int  Niter)
{

    float** image1_pos = im1->create_float_positions_2D();
    float** image2_pos = im2->create_float_positions_2D();
  
    float** flowX_pos = u->create_float_positions_2D();
    float** flowY_pos = v->create_float_positions_2D();
  
    fprintf(stderr,"calling optic flow ... \n");
  optic_flow( im1->DimX()-2,im1->DimY()-2,im1->VoxSizeX(), im1->VoxSizeY(),
      image1_pos, image2_pos,
      sigma,T,alpha,(long)dtype,quantile,ht,
      flowX_pos,flowY_pos,Niter);
    
  // save and free results
    im1->free_float_positions_2D(image1_pos);
    im2->free_float_positions_2D(image2_pos);
    u->free_float_positions_2D(flowX_pos);
    v->free_float_positions_2D(flowY_pos);
}


void amiOpticFlowVariational2DZoom(ParamList* p)
{
  char functionname[] = "amiOpticFlowVariational2DZoom";
  char description[]=" \n\
      2d optic flow from ami library \n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - First image \n\
      - Second image \n\
      ...\n\
      ";
  
  InrImage* im1  = NULL; 
  InrImage* im2  = NULL;
  float sigma    = 2;
  float T        = 10;
  float alpha    = 1.0;
  int   dtype    = 0;
  float quantile = 1;
  float ht       = 0.1;
  InrImage* u    = NULL;
  InrImage* v    = NULL;
  int  Niter     = 10;
  int  NZoom     = 2;

  int n=0;

  if (!get_val_ptr_param<InrImage>(      im1,      p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(      im2,      p, n)) HelpAndReturn;
  if (!get_val_param<float>(      sigma,    p, n)) HelpAndReturn;
  if (!get_val_param<float>(      T,        p, n)) HelpAndReturn;
  if (!get_val_param<float>(      alpha,    p, n)) HelpAndReturn;
  if (!get_int_param(        dtype,    p, n)) HelpAndReturn;
  if (!get_val_param<float>(      quantile, p, n)) HelpAndReturn;
  if (!get_val_param<float>(      ht,       p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(      u,        p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(      v,        p, n)) HelpAndReturn;
  if (!get_int_param(      Niter,      p, n)) HelpAndReturn;
  if (!get_int_param(      NZoom,      p, n)) HelpAndReturn;

  // Pb: we have to inverse the order because of the way
  // optic_flow_zoom() does the initial copy ... (HEAVY!!!)
  float** image1_pos = im1->create_float_positions_2D(1);
  float** image2_pos = im2->create_float_positions_2D(1);
  
  float** flowX_pos; //= u->create_float_positions_2D();
  float** flowY_pos; //= v->create_float_positions_2D();
  
  fprintf(stderr,"calling optic flow zoom ... \n");
  optic_flow_zoom( 
      im1->DimX(),im1->DimY(),
      im1->VoxSizeX(), im1->VoxSizeY(),
      &image1_pos[0][0], &image2_pos[0][0],
      sigma,T,alpha,(long)dtype,quantile,ht,
      &flowX_pos,
      &flowY_pos,
      Niter,NZoom);
    
  // save and free results
  printf("freeing and copying images \n");
  im1->free_float_positions_2D(image1_pos,1);
  im2->free_float_positions_2D(image2_pos,1);
  //  u->free_float_positions_2D(flowX_pos);
  //  v->free_float_positions_2D(flowY_pos);

  int     i,j,i1,j1;
  printf("copying images \n");
  for(j=0;j<im1->DimY();j++)
    for(i=0;i<im1->DimX();i++) {
      u->BufferPos(i,j,0);
      v->BufferPos(i,j,0);
      
      i1=i;
      if (i<1)             i1=1;
      if (i>im1->DimX()-2) i1=im1->DimX()-2;
      
      j1=j;
      if (j<1)             j1=1;
      if (j>im1->DimY()-2) j1=im1->DimY()-2;
      
      u->FixeValeur(flowX_pos[j1-1][i1-1]);
      v->FixeValeur(flowY_pos[j1-1][i1-1]);
    
    }
  printf("images copied\n");
  ami_free2d(flowX_pos);
  ami_free2d(flowY_pos);

}

/**
 * Wrapping of ami_optic_flow_correlation_3d()
 **/
void amiOpticFlowCorrelation3D( ParamList* p)
{
  char functionname[] = "amiOpticFlowCorrelation3D";
  char description[]=" \n\
      This function calls the 3D optic flow calculated with \n\
      the correlation technique in libamiFluid \n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - First image \n\
      - Second image \n\
      - Displacement field \n\
      - Size of the correlation window: \n\
          should powers of 2 \n\
          default value is (32,32,32) \n\
      - Window deformation \n\
          default is 1 \n\
      - Displacement grid \n\
          default is (4,4,4) \n\
      - Initial point \n\
          default is (0,0,0) \n\
      ";
  
  InrImage* im1 = NULL; 
  InrImage* im2 = NULL;
  InrImage* u   = NULL;
  ami_v3f p_init={0,0,0};
  ami_v3f disp  ={4,4,4}; // displacement
  int     cw[3] ={32,32,32};  // correlation window
  float   windef=1; // window_deformation

  int n=0;
  
  if (!get_val_ptr_param<InrImage>(        im1,    p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(        im2,    p, n)) HelpAndReturn; 
  if (!get_vectimage_param(    u,      p, n)) HelpAndReturn;
  if (!get_several_int_params<3>(   cw,     p, n)) HelpAndReturn;
  if (!get_val_param<float>(        windef, p, n)) HelpAndReturn;
  if (!get_several_params<float,3>( disp,   p, n)) HelpAndReturn;
  if (!get_several_params<float,3>( p_init, p, n)) HelpAndReturn;
  
  float*** image1_pos = im1->create_positions_3D<float>();
  float*** image2_pos = im2->create_positions_3D<float>();
  ami_v3f*** flow_pos = u  ->create_positions_3D<ami_v3f>();
  
  
  ami_optic_flow_correlation_3d(
    image1_pos,
    image2_pos,
    im1->DimX(), im1->DimY(), im1->DimZ(),
    flow_pos,
    p_init,
    disp,
    cw,
    windef);

  // save and free results
  im1->free_positions_3D<float>(image1_pos);
  im2->free_positions_3D<float>(image2_pos);
  u  ->free_positions_3D<ami_v3f>(flow_pos);
}

/**
 * Wrapping of ami_optic_flow_correlation_3d()
 * with downsampled vector field image
 **/
void amiOpticFlowCorrelation3DNew( ParamList* p)
{
  char functionname[] = "amiOpticFlowCorrelation3DNew";
  char description[]=" \n\
      This function calls the 3D optic flow calculated with \n\
      the correlation technique in libamiFluid \n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - First image \n\
      - Second image \n\
      - Displacement field (contains an image with the exact\n\
            number of pixels of the lattice) \n\
      - Size of the correlation window: \n\
          should powers of 2 \n\
          default value is (32,32,32) \n\
      - Displacement grid \n\
          default is (4,4,4) \n\
      - Initial point \n\
          default is (0,0,0) \n\
      - Number of threads (default is 2) \n\
      ";
  
  InrImage* im1 = NULL; 
  InrImage* im2 = NULL;
  InrImage* u   = NULL;
  ami_v3f p_init={0,0,0};
  ami_v3f disp  ={4,4,4}; // displacement
  int     cw[3] ={32,32,32};  // correlation window
//  float   windef=1; // window_deformation
  int     threads=2; // number of threads

  int n=0;
  
  if (!get_val_ptr_param<InrImage>(        im1,     p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(        im2,     p, n)) HelpAndReturn; 
  if (!get_vectimage_param(    u,       p, n)) HelpAndReturn;
  if (!get_several_int_params<3>(   cw,      p, n)) HelpAndReturn;
  if (!get_several_params<float,3>( disp,    p, n)) HelpAndReturn;
  if (!get_several_params<float,3>( p_init,  p, n)) HelpAndReturn;
  if (!get_int_param(          threads, p, n)) HelpAndReturn;
  
  
  if (im1->_format!=im2->_format) {
    fprintf(stderr,"%s() \t input images of different formats \n",functionname);
    return;
  }

  
  if (im1->_format==WT_FLOAT) {
    float*** image1_pos = im1->create_positions_3D<float>();
    float*** image2_pos = im2->create_positions_3D<float>();
    ami_v3f*** flow_pos = u  ->create_positions_3D<ami_v3f>();
    ami_optic_flow_correlation_3d_new<float>(
        image1_pos,
        image2_pos,
        im1->DimX(), im1->DimY(), im1->DimZ(),
        flow_pos,
        p_init,
        disp,
        cw,
        threads);

    // save and free results
    im1->free_positions_3D<float>(image1_pos);
    im2->free_positions_3D<float>(image2_pos);
    u  ->free_positions_3D<ami_v3f>(flow_pos);
  }
  else 
  if (im1->_format==WT_UNSIGNED_CHAR) {
    unsigned char*** image1_pos = im1->create_positions_3D<unsigned char>();
    unsigned char*** image2_pos = im2->create_positions_3D<unsigned char>();
    ami_v3f*** flow_pos = u  ->create_positions_3D<ami_v3f>();
    ami_optic_flow_correlation_3d_new<unsigned char>(
        image1_pos,
        image2_pos,
        im1->DimX(), im1->DimY(), im1->DimZ(),
        flow_pos,
        p_init,
        disp,
        cw,
        threads);

    // save and free results
    im1->free_positions_3D<unsigned char>(image1_pos);
    im2->free_positions_3D<unsigned char>(image2_pos);
    u  ->free_positions_3D<ami_v3f>(flow_pos);
  }
  else 
    fprintf(stderr,"%s() \t input images neither FLOAT not UNSIGNED CHAR \n",functionname);
}


/**
 * Wrapping in amilab of ami_horn_schunck_optic_flow_3d()
 */
void amiOFPDE( ParamList* p)
{
  char functionname[] = "amiOFPDE";
  char description[]=" \n\
      This function computes the optical flow using a variational approach \n\
      ";
  char parameters[] =" \n\
      The parameters with their default values are : \n\
      - IMAGE: first image \n\
      - IMAGE: second image \n\
      - VECTOR IMAGE: input/output displacement\n\
      ";
  
  InrImage* im1;
  InrImage* im2;  
  InrImage* u;
  int n=0;

  if (!get_val_ptr_param<InrImage>(        im1,             p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(        im2,             p, n)) HelpAndReturn;
  if (!get_vectimage_param(    u,               p, n)) HelpAndReturn;
  
  // get the inputs in the format for processing
    float*** image1_pos = im1->create_positions_3D<float>();
    float*** image2_pos = im2->create_positions_3D<float>();
    ami_v3f*** flow_pos = u  ->create_positions_3D<ami_v3f>();
    
    ami_horn_schunck_optic_flow_3d(
        image1_pos,image2_pos,
        flow_pos,
  ami_optic_flow_param,
        im1->DimX(), im1->DimY(), im1->DimZ());
    
    // save and free results
    im1->free_positions_3D<float>(image1_pos);
    im2->free_positions_3D<float>(image2_pos);
    u  ->free_positions_3D<ami_v3f>(flow_pos);
      
}


/**
 * Set different parameters for
 * Wrapping in amilab of ami_horn_schunck_optic_flow_3d()
 */
void amiOFPDE_Param( ParamList* p)
{
  char functionname[] = "amiOFPDE_Param";
  char description[]=" \n\
      Set different parameters for the optical flow using a variational approach \n\
      ";
  char parameters[] =" \n\
      The parameters with their default values are : \n\
      - 3 FLOAT VALUES: beta (def: 0.25,0.25,0.25 )\n\
      - 3 INT   VALUES: zoom_factor (def: 2,2,2 )\n\
      - 3 FLOAT VALUES: alfa        (def: 4,4,4 )\n\
      - FLOAT VALUE   : tolerance for Gauss Seidel scheme (def: 1E-5) \n\
      - INT   VALUE   : number of scale for pyramidal approach (def: 3) \n\
      - FLOAT VALUE   : tolerance for each scale (def: 1E-5) \n\
      - INT   VALUE   : gradient type, with value between 0 and 7: \n\
         0: GRADIENT OF WARPED image_2\n\
         1: UPWIND METHOD FOLLOWING THE SIGN OF (image_1 AND WARPED image_2)\n\
         2: AVERAGE OF THE GRADIENT OF image_1 AND WARPED image_2\n\
         3: Using the hessian matrix\n\
      - INT VALUE      : smoothing function type (def: 0):\n\
          0: standard function phi(x)=x\n\
          1: phi(x) = sqrt(x+epsilon)\n\
      ";
  
  float beta[3] = {0.25,0.25,0.25};
  int zoom_factor[3] = {2,2,2};
  ami_v3f alfa = {4.0,4.0,4.0};
  float TOL_GaussSeidel = 1E-5;
  int Nscales = 3;
  float TOL_Scales = 1E-5;
  int grad_type=2;
  int smoothing_type=0;
  int n=0;

  if (!get_several_params<float,3>( beta,            p, n)) HelpAndReturn;
  if (!get_several_int_params<3>(   zoom_factor,     p, n)) HelpAndReturn;
  if (!get_several_params<float,3>( alfa,            p, n)) HelpAndReturn;
  if (!get_val_param<float>(        TOL_GaussSeidel, p, n)) HelpAndReturn;
  if (!get_int_param(          Nscales,         p, n)) HelpAndReturn;
  if (!get_val_param<float>(        TOL_Scales,      p, n)) HelpAndReturn;
  if (!get_int_param(          grad_type,       p, n)) HelpAndReturn;
  if (!get_int_param(          smoothing_type,  p, n)) HelpAndReturn;
  
                                                                       
    ami_optic_flow_param.SetBeta(beta[0], beta[1], beta[2]);
    ami_optic_flow_param.SetZoomFactor(zoom_factor[0],zoom_factor[1],zoom_factor[2]);
    ami_optic_flow_param.SetAlpha(alfa[0],alfa[1],alfa[2]);
    ami_optic_flow_param.SetToleranceGaussSeidel(TOL_GaussSeidel);
    ami_optic_flow_param.SetNbScales(Nscales);
    ami_optic_flow_param.SetToleranceScales(TOL_Scales);
    ami_optic_flow_param.SetGradientType(grad_type);
    
} // amiOFPDE_Param()


 /** 
 * Optic Flow with temporal smoothing
 */
void amiOF_2D_T( ParamList* p)
{
  char functionname[] = "amiOF_2D_T";
  char description[]=" \n\
      This function computes the optical flow using a variational approach \n\
      ";
  char parameters[] =" \n\
      The parameters with their default values are : \n\
      - IMAGE: image sequence\n\
      - VECTOR IMAGE: input/output displacement\n\
      - 2 FLOAT VALUES: beta (def: 0.25,0.25 )\n\
      - 2 INT   VALUES: zoom_factor (def: 2,2 )\n\
      - 2 FLOAT VALUES: alfa        (def: 4,4 )\n\
      - FLOAT VALUE   : tolerance for Gauss Seidel scheme (def: 1E-5) \n\
      - INT   VALUE   : number of scale for pyramidal approach (def: 3) \n\
      - FLOAT VALUE   : tolerance for each scale (def: 1E-5) \n\
      - INT   VALUE   : gradient type, with value between 0 and 7: \n\
      0: GRADIENT OF WARPED image_2\n\
      1: UPWIND METHOD FOLLOWING THE SIGN OF (image_1 AND WARPED image_2)\n\
      2: AVERAGE OF THE GRADIENT OF image_1 AND WARPED image_2\n\
      3: Using the hessian matrix\n\
      - INT VALUE      : smoothing function type (def: 0):\n\
      0: standard function phi(x)=x\n\
      1: phi(x) = sqrt(x+epsilon)\n\
      - INT   VALUE   : smoothing type (def 0): 0: standard quadratic function, 1: robust square root\n\
      ";
  
  InrImage* im;
  InrImage* u;
  float beta[2] = {0.25,0.25};
  int zoom_factor[2] = {2,2};
  ami_v3f alfa = {4.0,4.0,4.0};
  float TOL_GaussSeidel = 1E-5;
  int Nscales = 3;
  float TOL_Scales = 1E-5;
  int grad_type=2;
  int smoothing_type=0;
  int n=0;

  if (!get_val_ptr_param<InrImage>(        im,             p, n)) HelpAndReturn;
  if (!get_vectimage_param(    u,               p, n)) HelpAndReturn;
  if (!get_several_params<float,2>( beta,            p, n)) HelpAndReturn;
  if (!get_several_int_params<2>(   zoom_factor,     p, n)) HelpAndReturn;
  if (!get_several_params<float,2>( alfa,            p, n)) HelpAndReturn;
  if (!get_val_param<float>(        TOL_GaussSeidel, p, n)) HelpAndReturn;
  if (!get_int_param(          Nscales,         p, n)) HelpAndReturn;
  if (!get_val_param<float>(        TOL_Scales,      p, n)) HelpAndReturn;
  if (!get_int_param(          grad_type,       p, n)) HelpAndReturn;
  if (!get_int_param(          smoothing_type,    p, n)) HelpAndReturn;
  
  // get the inputs in the format for processing
  float*** image_pos = im->create_positions_3D<float>();
  ami_v3f*** flow_pos = u  ->create_positions_3D<ami_v3f>();
  
  ami_optic_flow_param.SetBeta(beta[0],beta[1],0.25);
  ami_optic_flow_param.SetZoomFactor(zoom_factor[0],zoom_factor[1],1);
  ami_optic_flow_param.SetAlpha(alfa[0],alfa[1],alfa[2]);
  ami_optic_flow_param.SetToleranceGaussSeidel(TOL_GaussSeidel);
  ami_optic_flow_param.SetNbScales(Nscales);
  ami_optic_flow_param.SetToleranceScales(TOL_Scales);
  ami_optic_flow_param.SetGradientType(grad_type);
  
  ami_optic_flow_2d_t(image_pos,flow_pos,
          ami_optic_flow_param,
          im->DimX(),im->DimY(),im->DimZ());
  
    // save and free results
  im->free_positions_3D<float>(image_pos);
  u  ->free_positions_3D<ami_v3f>(flow_pos);
  
} // amiOF_2D_T()


/**
 * Wrapping of ami_optic_flow_extrapolation_v3f()
 * parameters are in the following order:
 * u (NULL), disp (4,4,4), init (0,0,0), displacement (0.5)
 */
void amiOpticFlowExtrapolationV3f(ParamList* p)
{
  char functionname[] = "amiOpticFlowExtrapolationV3f";
  char description[]=" \n\
      This function extrapolate a 3D vector field in order \n\
      to make it dense \n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - VECTOR IMAGE: Vector field (input/output) \n\
      - Displacement grid \n\
      deault is (4,4,4) \n\
      - Initial point \n\
      default is (0,0,0) \n\
      - Extrapolation displacement: \n\
      default is 0.5 \n\
      ";
  
  InrImage* u        = NULL;
  ami_v3f p_disp     = {4,4,4};
  ami_v3f p_init     = {0,0,0};
  float displacement = 0.5;

  int n=0;

  // the list starts by the last one in the list
  if (!get_vectimage_param(    u,            p, n)) HelpAndReturn;
  if (!get_several_params<float,3>( p_disp,       p, n)) HelpAndReturn; 
  if (!get_several_params<float,3>( p_init,       p, n)) HelpAndReturn; 
  if (!get_val_param<float>(        displacement, p, n)) HelpAndReturn;
  
  ami_v3f*** flow_pos = u  ->create_positions_3D<ami_v3f>();
  
  ami_optic_flow_extrapolation_v3f(flow_pos,
           p_init,p_disp,
           displacement,
           u->DimX(), u->DimY(), u->DimZ());
  // save and free results
  u  ->free_positions_3D<ami_v3f>(flow_pos);
  
}


 /**   norm 2 for vectors */
void amiNorm2Vect3DError( ParamList* )
{
}

 /**   norm 1 for vectors */
void amiNorm1Vect3DError( ParamList* )
{
}

 /**  fill boundaries for 3D scalar image */
void amiBoundary3D( ParamList* )
{
}

 /**  fill boundaries for 3D vector image */
void amiBoundaryVect3D( ParamList* )
{
}

 /**  gradient vector image */
void amiGrad3D( ParamList* )
{
}

 /** Norm max vector image */
void amiNormMaxVect3D( ParamList* )
{
}

/** Norm 3 vector image */
void amiNorm2Vect3D( ParamList*)
{
}

/** Warping of 3D scalar image using a vector field */
void amiInterpolation3D( ParamList* p)
{
  char functionname[] = "amiInterpolation3D";
  char description[]=" \n\
      This function perfomes a warping of a 3D scalar image \n\
      using a vector field \n\
      ";  
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - IMAGE: input image \n\
      - VECTOR IMAGE: vector field \n\
      - IMAGE: output image \n\
      ";
  
  InrImage* im     = NULL;
  InrImage* u          = NULL;
  InrImage* im_out   = NULL;
  int n=0;

  // the list starts by the last one in the list
  if (!get_val_ptr_param<InrImage>(        im,          p, n)) HelpAndReturn; 
  if (!get_vectimage_param(    u,            p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(        im_out,       p, n)) HelpAndReturn;
    
  float*** im_pos = im    ->create_positions_3D<float>();
  ami_v3f*** u_pos = u      ->create_positions_3D<ami_v3f>();
  float*** im_out_pos = im_out->create_positions_3D<float>();
  
  ami_image_interpolation_3df(im_pos,
                u_pos,
                im_out_pos,
                im->DimX(), im->DimY(), im->DimZ());
                
  // save and free results
  im->free_positions_3D<float>(im_pos);
  u  ->free_positions_3D<ami_v3f>(u_pos); 
  im_out->free_positions_3D<float>(im_out_pos); 
}

/** Warping of 2D images using Splines */
InrImage* amiWarpSplines( ParamList* p)
{
    char functionname[] = "amiWarpSplines";
    char description[]=" \n\
            This function perfomes a warping of a 2D (or 3D) scalar image \n\
            using a vector field and spline interpolation \n\
            ";  
    char parameters[] =" \n\
            the parameters with their default values are : \n\
            - IMAGE: input image \n\
            - VECTOR IMAGE: vector field \n\
            - INTEGER: spline degree (default=2) \n\
            ";
    
    InrImage* im         = NULL;
    InrImage* u          = NULL;
    InrImage* im_out     = NULL;
    int       spline_degree = 2;
    int n=0;

    // the list starts by the last one in the list
    if (!get_val_ptr_param<InrImage>(     im,           p, n)) HelpAndReturnNULL; 
    if (!get_vectimage_param( u,            p, n)) HelpAndReturnNULL;
    if (!get_int_param(       spline_degree,p, n)) HelpAndReturnNULL;
      

    im_out = new InrImage( WT_FLOAT, "imagewarp.ami.gz", im);

    float*** im_pos = im        ->create_positions_3D<float>();
    ami_v3f*** u_pos = u        ->create_positions_3D<ami_v3f>();
    float*** im_out_pos = im_out->create_positions_3D<float>();
  
    ami_image_splinewarp(im_pos,
                         u_pos,
                         im_out_pos,
                         im->DimX(), im->DimY(), im->DimZ(),
                         spline_degree);
                                
  // save and free results
    im->free_positions_3D<float>(im_pos);
    u  ->free_positions_3D<ami_v3f>(u_pos); 
    im_out->free_positions_3D<float>(im_out_pos);   
    return im_out;
}


/** Interpolation of 3D vectorial image */
void amiInterpolationVect3D( ParamList*)
{
}

/** Copy of 3D scalar image */
void amiCopy3D( ParamList*)
{
}

/** Copy of 3D vectorial image */
void amiCopyVect3D( ParamList*)
{
}

/** Convolution of 3D image */
void amiConvolution3D( ParamList* p)
{
  char functionname[] = "amiConvolution3D";
  char description[]=" \n\
      This function runs a Gaussian convolution on the image \n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - IMAGE: image \n\
      - 3 FLOAT VALUES: beta (def: 0.25,0.25,0.25 )\n\
      ";
  
  InrImage* im1 = NULL; 
  float     beta[3]={0.25,0.25,0.25};
  int n=0;
  
  if (!get_val_ptr_param<InrImage>(        im1,    p, n)) HelpAndReturn;
  if (!get_several_params<float,3>( beta,   p, n)) HelpAndReturn;
  
  float*** image1_pos = im1->create_positions_3D<float>();
  ami_convolution_3d(image1_pos, beta, im1->DimX(), im1->DimY(), im1->DimZ());
  // save and free results
  im1->free_positions_3D<float>(image1_pos);
}

/** Zoom down of 3D image */
InrImage* amiZoomDown3D( ParamList* p)
{
  char functionname[] = "amiZoomDown3D";
  char description[]=" \n\
      This function downsample the image \n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - IMAGE: input image \n\
      - 3 FLOAT VALUES: beta (def: 0.25,0.25,0.25 ) are convolution parameters for each dimension\n\
      - 3 INT VALUES (def 2,2,2) are the zoom factors, each dimension will be divided by the corresponding factor\n\
      ";
  
  InrImage* im1 = NULL; 
  InrImage* res = NULL; 
  
  float     beta[3]={0.25,0.25,0.25};
  int       factor[3]={2,2,2};
  int n=0;
  
  if (!get_val_ptr_param<InrImage>(        im1,    p, n)) HelpAndReturnNULL;
  if (!get_several_params<float,3>( beta,   p, n)) HelpAndReturnNULL;
  if (!get_several_int_params<3>(   factor, p, n)) HelpAndReturnNULL;
 
  if (im1->DimX()==1) factor[0]=1;
  if (im1->DimY()==1) factor[1]=1;
  if (im1->DimZ()==1) factor[2]=1;
  
  res = new InrImage((int) im1->DimX()/factor[0],
         (int) im1->DimY()/factor[1],
         (int) im1->DimZ()/factor[2],
         WT_FLOAT);
     
  float*** image1_pos = im1->create_positions_3D<float>();
  float*** res_pos    = res->create_positions_3D<float>();
  ami_zoom_down_3d(image1_pos, res_pos, beta, factor,im1->DimX(), im1->DimY(), im1->DimZ());
  // save and free results
  im1->free_positions_3D<float>(image1_pos);
  res->free_positions_3D<float>(res_pos);
  
  return res;
}

/** Zoom up with filter of 3D image */
void amiZoomUpFilter3D( ParamList*)
{
}

/** Zoom up with interpolation of 3D image */
void amiZoomUpInterpolation3D( ParamList*){
}


/** Zoom up with flow of 3D image */
InrImage* amiZoomUpFlow3D( ParamList* p)
{
  char functionname[] = "amiZoomUpFlow3D";
  char description[]=" \n\
      This function upsample a 3D vector field \n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - IMAGE: input vector field \n\
      - 3 INT VALUES (def 2,2,2) are the zoom factors, each dimension will be multiplied by the corresponding factor\n\
      ";
  
  InrImage* im1 = NULL; 
  InrImage* res = NULL; 
  
  float     beta[3]={0.25,0.25,0.25}; // the function doesn't use this parameter
  int       factor[3]={2,2,2};
  int n=0;
  
  if (!get_vectimage_param(        im1,    p, n)) HelpAndReturnNULL;
  if (!get_several_int_params<3>(   factor, p, n)) HelpAndReturnNULL;
 
  if (im1->DimX()==1) factor[0]=1;
  if (im1->DimY()==1) factor[1]=1;
  if (im1->DimZ()==1) factor[2]=1;
  
  res = new InrImage((int) im1->DimX()*factor[0],
            (int) im1->DimY()*factor[1],
            (int) im1->DimZ()*factor[2],3,
            WT_FLOAT);
     
  ami_v3f*** image1_pos = im1->create_positions_3D<ami_v3f>();
  ami_v3f*** res_pos    = res->create_positions_3D<ami_v3f>();
  ami_zoom_up_v3f_flow(image1_pos, res_pos, beta, factor, im1->DimX(), im1->DimY(), im1->DimZ());
  
  // save and free results
  im1->free_positions_3D<ami_v3f>(image1_pos);
  res->free_positions_3D<ami_v3f>(res_pos);
  
  return res;
  
  
}

/** Explicit Horn Schunck solution */
void amiHornSchunckOpticFlowExplicit( ParamList* p)
{
  char functionname[] = "amiHornSchunckOpticFlowExplicit";
  char description[]=" \n\
      Solution of the Optic Flow using an explicit scheme \n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - IMAGE: image 1\n\
      - IMAGE: image 2\n\
      - VECTOR IMAGE: u, input and output flow\n\
      - 3 FLOAT VALUES: alfa (def: 0.5,0.5,0.5 ) smoothing term factor\n\
      - FLOAT: total evolution time (def 10) \n\
      - FLOAT: evolution time step (def 0.1) \n\
      ";
  
  
  InrImage* im1 = NULL; 
  InrImage* im2 = NULL; 
  InrImage* u   = NULL; 
  
  float     alfa[3]={0.5,0.5,0.5};
  float     total_time = 10;
  float     dt = 0.1;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>(        im1,    p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(        im2,    p, n)) HelpAndReturn;
  if (!get_vectimage_param(    u,      p, n)) HelpAndReturn;
  if (!get_several_params<float,3>( alfa,   p, n)) HelpAndReturn;
  if (!get_val_param<float>(        total_time,   p, n)) HelpAndReturn;
  if (!get_val_param<float>(        dt,           p, n)) HelpAndReturn;
 
  
     
  float***   im1_pos = im1->create_positions_3D<float>();
  float***   im2_pos = im2->create_positions_3D<float>();
  ami_v3f*** u_pos   = u  ->create_positions_3D<ami_v3f>();
  
  ami_horn_schunck_optic_flow_explicit(
      im1_pos,im2_pos,u_pos,
      alfa,total_time,dt,im1->DimX(),im1->DimY(),im1->DimZ(),
  ami_optic_flow_param);
  
  // save and free results
  im1->free_positions_3D<float>(  im1_pos);
  im2->free_positions_3D<float>(  im2_pos);
  u  ->free_positions_3D<ami_v3f>(u_pos);
}


/** Read 2D Vector Field in UV format */
InrImage* amiReadUV( ParamList* p)
{
  char functionname[] = "amiReadUV";
  char description[]=" \n\
      Reads vector field saved by Javier and Agustin \n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - STRING: filename of the vector field\n\
      ";
  
  std::string filename;
  std::string*  filename_param = NULL;
  int nx,ny;
  InrImage* u;
  InrImage* v;
  InrImage* vect = NULL;
  int n=0;
  
  if (!get_val_ptr_param<string>( filename_param, p, n)) HelpAndReturnNULL;

  filename = *filename_param;
  read_size_uv (nx, ny, filename);
  printf("size %d %d \n",nx,ny);
  u = new InrImage(nx,ny,1,WT_FLOAT);
  v = new InrImage(nx,ny,1,WT_FLOAT);
  vect = new InrImage(nx,ny,1,3,WT_FLOAT);
  
  float* ubuf = (float*)u->Buffer();
  float* vbuf = (float*)v->Buffer();
  read_uv<float,float*>(ubuf,vbuf, nx, ny, filename);
  
  u->InitBuffer();
  v->InitBuffer();
  vect->InitBuffer();
  do {
    vect->VectFixeValeurs(u->ValeurBuffer(),v->ValeurBuffer(),0);
    u->IncBuffer();
    v->IncBuffer();
  } while (vect->IncBuffer());

  delete u;
  delete v;
  
  return vect;
} // amiReadUV()


/** Inverse 2D or 3D Vector Field  */
InrImage* amiInverseFlow( ParamList* p)
{
  char functionname[] = "amiInverseFlow";
  char description[]=" \n\
      Computes the inverse of a flow in 2D or 3D\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - VECTOR IMAGE: input flow\n\
      - INTEGER: fillholes 1: activate filling of holes 0: holes have a value of 9999 (def: 1)\n\
      - INTEGER: dimension 0: use image dimension, 2: 2D flow, 3: 3D flow (def:0)\n\
      ";

  InrImage* res=NULL;
  InrImage* u  = NULL; 
  int       fillholes = 1;
  int       dimension = 0;
  int n=0;
  
  if (!get_vectimage_param( u,         p, n)) HelpAndReturnNULL;
  if (!get_int_param(       fillholes, p, n)) HelpAndReturnNULL;
  if (!get_int_param(       dimension, p, n)) HelpAndReturnNULL;
  
  if (dimension==0) {
    if (u->DimZ()>1) dimension=3;
    else dimension=2;
  }
  if ((dimension==3)&&u->DimZ()==1) dimension=2;
  
  InrImage* ux  = new InrImage(WT_FLOAT,"ux",u); 
  InrImage* uy  = new InrImage(WT_FLOAT,"uy",u); 
  InrImage* uz  = NULL;
  
  InrImage* u1x  = new InrImage(WT_FLOAT,"u1x",u); 
  InrImage* u1y  = new InrImage(WT_FLOAT,"u1y",u); 
  InrImage* u1z  = NULL;
  
  if (dimension==3) {
    uz   = new InrImage(WT_FLOAT,"uz" ,u); 
    u1z  = new InrImage(WT_FLOAT,"u1z",u); 
  }
  
  // fill ux and uy
  ux->InitBuffer();
  uy->InitBuffer();
  if (dimension==3) uz->InitBuffer();
  u->InitBuffer();
  do {
    ux->FixeValeur(u->VectValeurBuffer(0));
    uy->FixeValeur(u->VectValeurBuffer(1));
    ux->IncBuffer();
    uy->IncBuffer();
    if (dimension==3) {
      uz->FixeValeur(u->VectValeurBuffer(2));
      uz->IncBuffer();
      }
  } while (u->IncBuffer());

  
  
  float* uxbuf = (float*)  ux->Buffer();
  float* uybuf = (float*)  uy->Buffer();
  float* uzbuf;
  float* u1xbuf = (float*) u1x->Buffer();
  float* u1ybuf = (float*) u1y->Buffer();
  float* u1zbuf;
  
  if (dimension==3) {
    uzbuf  = (float*) uz ->Buffer();
    u1zbuf = (float*) u1z->Buffer();
    
    printf("inverse_optic_flow_3d \n");
    inverse_optic_flow_3d<float> invOF;
    invOF(uxbuf,  uybuf,  uzbuf, 
          u1xbuf, u1ybuf, u1zbuf, 
          u->DimX(),u->DimY(),u->DimZ(),
          fillholes);
          
  } else {  
    NM_AMI_METHOD::inverse_optic_flow<float> invOF;
    invOF(uxbuf,uybuf,
          u1xbuf,u1ybuf,
          u->DimX(),u->DimY());
  }
      
  res  = new InrImage(WT_FLOAT,3,"inv_u",u); 
  
  u1x->InitBuffer();
  u1y->InitBuffer();
  if (dimension==3) u1z->InitBuffer();
  res->InitBuffer();
  do {
    if (dimension==3) 
      res->VectFixeValeurs(u1x->ValeurBuffer(),u1y->ValeurBuffer(),u1z->ValeurBuffer());
    else 
      res->VectFixeValeurs(u1x->ValeurBuffer(),u1y->ValeurBuffer(),0);
    u1x->IncBuffer();
    u1y->IncBuffer();
    if (dimension==3) u1z->IncBuffer();
  } while (res->IncBuffer());
  
  delete ux;
  delete uy;
  delete u1x;
  delete u1y;
  if (dimension==3) {
    delete uz;
    delete u1z;
  }
  
  return res;
  
} // amiInverseFlow()

/**  FUNCTION TO COMPUTE THE SOLENOIDAL PROYECCION OF A FLOW */
void amiSolenoidalProjection3D( ParamList* p)
{
  char functionname[] = "amiSolenoidalProj3D";
  char description[]=" \n\
      Computes the solenoidal projection of a 3D flow\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
    - VECTOR IMAGE: input/outpu flow\n\
      - 3 FLOAT VALUES: beta, smoothing coefficients  ( def: 0.25, 0.25, 0.25)\n\
      - 3 FLOAT VALUES: zoom factor in each dimension ( def: 2,2,2)\n\
      - FLOAT:          Gauss-Seidel Tolerance threshold (def: 5E-6)\n\
      - FLOAT;          A: coefficient for convergence of Laplace equation (def:0.01)\n\
      - INTEGER:        number of scales (def: 3) \n\
      ";

  InrImage* u  = NULL; 
  float beta[3] = {0.25,0.25,0.25};
  int zoom_factor[3] ={2,2,2};
  float TOL_GaussSeidel = 5E-6;
  int Nscales = 3; 
  float A = 0.01;

  int n=0;
  
  if (!get_vectimage_param(    u,               p, n)) HelpAndReturn;
  if (!get_several_params<float,3>( beta,            p, n)) HelpAndReturn;
  if (!get_several_int_params<3>(   zoom_factor,     p, n)) HelpAndReturn;
  if (!get_val_param<float>(        TOL_GaussSeidel, p, n)) HelpAndReturn;
  if (!get_val_param<float>(        A,               p, n)) HelpAndReturn;
  if (!get_int_param(          Nscales,         p, n)) HelpAndReturn;
   
  ami_v3f*** u_pos   = u  ->create_positions_3D<ami_v3f>();
  
  ami_solenoidal_proyeccion_3d(u_pos,beta,zoom_factor, TOL_GaussSeidel,Nscales,
        A,
             u->DimX(),u->DimY(),u->DimZ());

  // save and free results
  u  ->free_positions_3D<ami_v3f>(u_pos);
 
}

/**  FUNCTION TO CHOOSE THE WAY TO COMPUTE THE GRADIENT IN THE PDE OPTICAL FLOW */
void amiOFSetGradient( ParamList* p)
{
  char functionname[] = "amiOFSetGradient";
  char description[]=" \n\
      Choose the way to compute the gradient for the PDE optical flow technique\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - INTEGER:        type of gradient (def: 0) \n\
          0: each component is chosen using the maximal absolute value of the difference \n\
             between the central point and its 2 neighbors in the corresponding direction \n\
          1: for 2D images only, 3x3 mask that tries to be invariant under rotation\n\
          2: gradient computed from 2nd order spline interpolation \n\
      ";

  int gc = 0; 
  int n=0;
  
  if (!get_int_param(          gc,         p, n)) HelpAndReturn;
  
  ami_optic_flow_param.SetGradientComputation(GradientComputation(gc));
  
}

/** Symmetric formulation for Optical Flow */
void amiOFSetSymmetric(ParamList* p)
{
  char functionname[] = "amiOFSetSymmetric";
  char description[]=" \n\
      Symmetric or standard formulation for the Variational Optical Flow\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - INTEGER:        symmetric formulation (def: 0) \n\
      0: standard\n\
      1: symmetric\n\
      ";

  int s = 0; 
  int n=0;
  
  if (!get_int_param(          s,         p, n)) HelpAndReturn;
  
  ami_optic_flow_param.SetSymmetric(s);
  
} // amiOFSetSymmetric()


/** Use Alpha normalization? */
void amiOFSetNormalizeAlpha(ParamList* p)
{
  char functionname[] = "amiOFSetNormalizeAlpha";
  char description[]=" \n\
      Decide if we use a normalization of alpha for the Variational Optical Flow\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - INTEGER:        symmetric formulation (def: 0) \n\
      0: no normalization\n\
      1: normalization\n\
      ";

  int an = 0; 
  int n=0;
  
  if (!get_int_param(          an,         p, n)) HelpAndReturn;
  
  ami_optic_flow_param.SetNormalizeAlpha(an);
  
} // amiOFSetNormalizeAlpha()


/**  FUNCTION TO CHOOSE if the smoothing constraint is global */
void amiOFSetGlobalConstraint( ParamList* p)
{
  char functionname[] = "amiOFSetGlobalConstraint";
  char description[]=" \n\
      Choose if the smoothing constraint is global \n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - INTEGER:        type of gradient (def: 0) \n\
      0: the smoothing only applies to the additional displacement \n\
      1: the smoothing applies to the total displacement\n\
      ";

  int gc = 0; 
  int n=0;
  
  if (!get_int_param(          gc,         p, n)) HelpAndReturn;
  printf("amiOFSetGlobalConstraint %d \n",gc);
  ami_optic_flow_param.SetGlobalConstraint(gc);
  printf("amiOFGetGlobalConstraint %d \n",ami_optic_flow_param.GetGlobalConstraint());
  
} // amiOFSetGlobalConstraint()

/**  FUNCTION TO CHOOSE the way to treat boundary in the variational optical flow technique */
void amiOFSetBoundaryType( ParamList* p)
{
  char functionname[] = "amiOFSetBoundaryType";
  char description[]=" \n\
      Chooses the way to treat boundaries \n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - INTEGER:        type of boundary (def: 0) \n\
      0: uses one pixel(/voxel) margin and extrapole the values after each Gauss-Seidel iteration  \n\
      1: Creates a mask of pixels(/voxels) that point outside the image domain at the current iteration and extrapole their values\n\
      ";

  int bt = 0; 
  int n=0;
  
  if (!get_int_param(          bt,         p, n)) HelpAndReturn;
  ami_optic_flow_param.SetBoundaryType(BoundaryType(bt));
  
} // amiOFSetBoundaryType()

/**  Function to choose the interpolation scheme for warping in Optical Flow */
void amiOFSetInterpolation( ParamList* p)
{
  char functionname[] = "amiOFSetInterpolation";
  char description[]=" \n\
      Sets the type and the parameters of the interpolation used \n\
      for warping in the optical flow technique \n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - INTEGER:        type of interpolation (def: 0) \n\
      0: linear interpolation \n\
      1: spline interpolation\n\
      - INTEGER: spline degree (def: 2) \n\
      ";

  int it = 0; 
  int sd = 2;
  int n=0;
  
  if (!get_int_param(          it,         p, n)) HelpAndReturn;
  if (!get_int_param(          sd,         p, n)) HelpAndReturn;
  
  ami_optic_flow_param.SetInterpolationType((InterpolationType) it);
  ami_optic_flow_param.SetSplineDegree(sd);
  
} // amiOFSetInterpolation()


/**  FUNCTION TO CHOOSE if the gradient is smoothed */
void amiOFSetSmoothGradient( ParamList* p)
{
  char functionname[] = "amiOFSetSmoothGradient";
  char description[]=" \n\
      Use smoothed gradient or not?\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - INTEGER:   smoothed gradient (def: 0) \n\
      0: don't apply \n\
      1: apply \n\
      ";

  int sg = 0; 
  int n=0;
  
  if (!get_int_param(          sg,         p, n)) HelpAndReturn;
  
  ami_optic_flow_param.SetSmoothGradient(sg);
} // amiOFSetSmoothGradient()


/**  FUNCTION TO CHOOSE IF WE APPLY SOLENOIDAL PROJECTION IN THE PDE OPTICAL FLOW */
void amiPDESetSolenoidal( ParamList* p)
{
  char functionname[] = "amiPDESetSolenoidal";
  char description[]=" \n\
      Choose if the PDE optical flow should apply the solenoidal projection \n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - INTEGER:   solenoidal projection (def: 0) \n\
      0: do not apply \n\
      1: apply \n\
      ";

  int sp = 0; 
  int n=0;
  
  if (!get_int_param(          sp,         p, n)) HelpAndReturn;
  
  ami_optic_flow_param.SetSolenoidalProjection(sp);
}

/**  FUNCTION TO enable/disable incompressibility constraint in the energy */
void amiPDESetEnergyConstraint( ParamList* p)
{
  char functionname[] = "amiPDESetEnergyConstraint";
  char description[]=" \n\
      Choose if the PDE optical flow should include an incompressibility constaint \n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - INTEGER:   incompressibility constraint (def: 0) \n\
      0: do not apply \n\
      1: apply \n\
      ";

  int ec = 0; 
  int n=0;
  
  if (!get_int_param(          ec,         p, n)) HelpAndReturn;
  
  ami_optic_flow_param.SetEnergyConstraint(ec);
}


/** Epsilon for normalization of alpha for Optical Flow */
void amiOFSetAlphaNormEpsilon( ParamList* p)
{
  char functionname[] = "amiOFSetAlphaNormEpsilon";
  char description[]=" \n\
      Choose the value of the epsilon used for the normalization of alpha \n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - FLOAT:   epsilon (def: 1E-2) \n\
      ";

  float epsilon_alpha = 1E-2; 
  int n=0;
  
  if (!get_val_param<float>(          epsilon_alpha,         p, n)) HelpAndReturn;
  
  ami_optic_flow_param.SetAlphaNormEpsilon(epsilon_alpha);
}


/**  Javier's version of Horn Schunck Optical Flow */
void amiJavierHornSchunck( ParamList* p)
{
  char functionname[] = "amiJavierHornSchunck";
  char description[]=" \n\
      2D Optical Flow class using Horn Schunck equation, implicit\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - FLOAT IMAGE:        first image\n\
      - FLOAT IMAGE:        second image\n\
      - FLOAT IMAGE:        X component of the flow\n\
      - FLOAT IMAGE:        Y component of the flow\n\
      - FLOAT VALUE:        number of zooms (def 3)\n\
      - FLOAT VALUE:        smoothing term coefficient alpha (def 10) \n\
      - FLOAT VALUE:        Total diffusion time T (def 500) \n\
      - FLOAT VALUE:        Time step dt (def 10) \n\
      - FLOAT VALUE:        Nu (smoothing ?) (def 0.5)\n\
      ";
  
  InrImage* im1;
  InrImage* im2;
  InrImage* flow_x;
  InrImage* flow_y;
  int       zoom=3;
  float     alpha=10;
  float     T=500;
  float     dt=10;
  float     Nu=0.5;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>(    im1,               p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    im2,               p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    flow_x,            p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    flow_y,            p, n)) HelpAndReturn;
  if (!get_int_param(      zoom,              p, n)) HelpAndReturn;
  if (!get_val_param<float>(    alpha,             p, n)) HelpAndReturn;
  if (!get_val_param<float>(    T,                 p, n)) HelpAndReturn;
  if (!get_val_param<float>(    dt,                p, n)) HelpAndReturn;
  if (!get_val_param<float>(    Nu,                p, n)) HelpAndReturn;
  
  // get the inputs in the format for processing
  horn_schunck<float> hs;
  
  float* im1_pos = (float*) im1->Buffer();
  float* im2_pos = (float*) im2->Buffer();
  float* flowx_pos = (float*) flow_x->Buffer();
  float* flowy_pos = (float*) flow_y->Buffer();
  
  hs(im1_pos,im2_pos,flowx_pos,flowy_pos,
     im1->DimX(), im1->DimY(),
     zoom,alpha,T,dt,Nu,std::cout);
  
}

/**  Javier's version of Horn Schunck Symmetric Optical Flow */
void amiJavierHornSchunckSym( ParamList* p)
{
  char functionname[] = "amiJavierHornSchunckSym";
  char description[]=" \n\
      2D Symmetric Optical Flow class using Horn Schunck equation, implicit\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - FLOAT IMAGE:        first image\n\
      - FLOAT IMAGE:        second image\n\
      - FLOAT IMAGE:        X component of the flow\n\
      - FLOAT IMAGE:        Y component of the flow\n\
      - FLOAT VALUE:        number of zooms (def 3)\n\
      - FLOAT VALUE:        smoothing term coefficient alpha (def 10) \n\
      - FLOAT VALUE:        Total diffusion time T (def 500) \n\
      - FLOAT VALUE:        Time step dt (def 10) \n\
      - FLOAT VALUE:        Nu (smoothing ?) (def 0.5)\n\
      ";
  
  InrImage* im1;
  InrImage* im2;
  InrImage* flow_x;
  InrImage* flow_y;
  int       zoom=3;
  float     alpha=10;
  float     T=500;
  float     dt=10;
  float     Nu=0.5;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>(    im1,               p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    im2,               p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    flow_x,            p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    flow_y,            p, n)) HelpAndReturn;
  if (!get_int_param(      zoom,              p, n)) HelpAndReturn;
  if (!get_val_param<float>(    alpha,             p, n)) HelpAndReturn;
  if (!get_val_param<float>(    T,                 p, n)) HelpAndReturn;
  if (!get_val_param<float>(    dt,                p, n)) HelpAndReturn;
  if (!get_val_param<float>(    Nu,                p, n)) HelpAndReturn;
  
  // get the inputs in the format for processing
  horn_schunck_sym<float> hs;
  
  float* im1_pos = (float*) im1->Buffer();
  float* im2_pos = (float*) im2->Buffer();
  float* flowx_pos = (float*) flow_x->Buffer();
  float* flowy_pos = (float*) flow_y->Buffer();
  
  hs(im1_pos,im2_pos,flowx_pos,flowy_pos,
     im1->DimX(), im1->DimY(),
     zoom,alpha,T,dt,Nu,std::cout);
  
}


/**  Javier and Agustin's version of Optical Flow */
void amiOpticFlow( ParamList* p)
{
  char functionname[] = "amiOpticFlow";
  char description[]=" \n\
      2D  Optical Flow class using Nagel Enkelmann\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - FLOAT IMAGE:        image sequence\n\
      - FLOAT IMAGE:        X component of the flow\n\
      - FLOAT IMAGE:        Y component of the flow\n\
      - FLOAT VALUE:        number of zooms (def 3)\n\
      - FLOAT VALUE:        spatial smoothing coefficient alpha (def 0.6) \n\
      - FLOAT VALUE:        temporal smoothing coefficient beta   (def 0.3) \n\
      - FLOAT VALUE:        gamma    (def 1.0) \n\
      - FLOAT VALUE:        Nagel Enkelmann matrix, isotropy (def 0.1) \n\
      - FLOAT VALUE:        Total diffusion time T (def 500) \n\
      - FLOAT VALUE:        Time step dt (def 10) \n\
      - FLOAT VALUE:        Nu scaling factor (def 0.5) \n\
      ";
  
  InrImage* im;
  InrImage* flow_x;
  InrImage* flow_y;
  int       zoom=3;
  float     alpha=0.6;
  float     beta =0.3;
  float     gamma=1.0;
  float     isotropy = 0.1;
  float     T=500;
  float     dt=10;
  float     Nu=0.5;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>(    im,               p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    flow_x,            p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    flow_y,            p, n)) HelpAndReturn;
  if (!get_int_param(      zoom,              p, n)) HelpAndReturn;
  if (!get_val_param<float>(    alpha,             p, n)) HelpAndReturn;
  if (!get_val_param<float>(    beta,              p, n)) HelpAndReturn;
  if (!get_val_param<float>(    gamma,             p, n)) HelpAndReturn;
  if (!get_val_param<float>(    isotropy,          p, n)) HelpAndReturn;
  if (!get_val_param<float>(    T,                 p, n)) HelpAndReturn;
  if (!get_val_param<float>(    dt,                p, n)) HelpAndReturn;
  if (!get_val_param<float>(    Nu,                p, n)) HelpAndReturn;
  
  // get the inputs in the format for processing
  NM_AMI_METHOD::optic_flow_video<float> of;
  
  if ((flow_x->DimZ()!=im->DimZ()-1) || (flow_y->DimZ()!=im->DimZ()-1)) {
    fprintf(stderr,"amiOpticFlow() \t bad image dimensions \n");
    return;
  }
  if (im->_format!=WT_FLOAT) {
    fprintf(stderr,"amiOpticFlow() \t input image sequence not in float \n");
    return;
  }
  if (flow_x->_format!=WT_FLOAT) {
    fprintf(stderr,"amiOpticFlow() \t flow component X not in float \n");
    return;
  }
  if (flow_y->_format!=WT_FLOAT) {
    fprintf(stderr,"amiOpticFlow() \t flow component Y not in float \n");
    return;
  }

  // convert images to vectors
  std::vector<float*> std_im(im->DimZ());
  std::vector<float*> std_flow_x(flow_x->DimZ());
  std::vector<float*> std_flow_y(flow_y->DimZ());
  int k;

  printf("im->DimZ() %d \n",im->DimZ());
  for(k=0;k<im->DimZ(); k++) {
    im->BufferPos(0,0,k);
    std_im[k] = (float*)im->BufferPtr();
  }

  printf("flow_x->DimZ() %d \n",flow_x->DimZ());
  for(k=0;k<flow_x->DimZ(); k++) {
    flow_x->BufferPos(0,0,k);
    flow_y->BufferPos(0,0,k);
    std_flow_x[k]=(float*)flow_x->BufferPtr();
    std_flow_y[k]=(float*)flow_y->BufferPtr();
  }

  printf(" zoom %d alpha %f beta %f gamma %f isotropy %f \n",
    zoom,alpha,beta,gamma,isotropy);  
  of(std_im,std_flow_x,std_flow_y,
     im->DimX(), im->DimY(),
     zoom,alpha,beta,gamma,isotropy,T,dt,Nu,std::cout);
 
}



/** Vorticity estimation **/
void amiVorticity(ParamList* p)
{
  char functionname[] = "amiVorticity";
  char description[]=" \n\
      2D Vorticity estimation\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - FLOAT IMAGE:        first image\n\
      - FLOAT IMAGE:        second image\n\
      - FLOAT IMAGE:        derivative in X of the 2nd image\n\
      - FLOAT IMAGE:        derivative in Y of the 2nd image\n\
      - FLOAT IMAGE:        X component of the flow (input AND output)\n\
      - FLOAT IMAGE:        Y component of the flow (input AND output)\n\
      - INT   VALUE:        grid spacing (def 1)\n\
      - INT   VALUE:        window size  (def 5) \n\
      - FLOAT VALUE:        sigma (def 2.0) \n\
      - FLOAT VALUE:        regularization parameter alpha (def 1.0) \n\
      - FLOAT VALUE:        Convergence parameter (def 0.00001)\n\
      - FLOAT IMAGE:        Vorticity image \n\
      ";
  
  InrImage* im1 = NULL;
  InrImage* im2 = NULL;
  InrImage* im2_x = NULL;
  InrImage* im2_y = NULL;
  InrImage* flow_x = NULL;
  InrImage* flow_y = NULL;
  
  InrImage* im_vorticity       = NULL;
  
  int zoom = 1;        // LATTICE STEP TO COMPUTED THE ZOOMED IMAGE 
  int window_radius=5; //  WINDOW RADIUS TO FIT THE NEIBORHOOD OF (x0,y0) 
  float sigma=2;       // PARAMETER OF THE KERNEL OF THE LUCAS-KANADE ENERGY
  float alpha=10e-0;    // REGULARIZATION PARAMETER FOR SYSTEM MATRIZ (A=A+alfa*Id) 
  float TOL_iter=0.00001; // CONVERGENCE PARAMETER TO STOP ITERATIONS TO SOLVE THE LINEAR SYSTEM
    
  int n=0;
  
  if (!get_val_ptr_param<InrImage>(    im1,                p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    im2,                p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    flow_x,             p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    flow_y,             p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    im2_x,              p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    im2_y,              p, n)) HelpAndReturn;
  if (!get_int_param(      zoom,               p, n)) HelpAndReturn;
  if (!get_int_param(      window_radius,      p, n)) HelpAndReturn;
  if (!get_val_param<float>(    sigma,              p, n)) HelpAndReturn;
  if (!get_val_param<float>(    alpha,              p, n)) HelpAndReturn;
  if (!get_val_param<float>(    TOL_iter,           p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    im_vorticity,       p, n)) HelpAndReturn;
   
  float** im1_pos   = im1  ->create_float_positions_2D();
  float** im2_pos   = im2  ->create_float_positions_2D();
  float** flow_x_pos = flow_x->create_float_positions_2D();
  float** flow_y_pos = flow_y->create_float_positions_2D();
  float** vort_pos   = im_vorticity      ->create_float_positions_2D();
  float** im2_x_pos = im2_x->create_float_positions_2D();
  float** im2_y_pos = im2_y->create_float_positions_2D();

  float u[6];          // LOCAL FLOW IN THE POINT (x0,y0) 
  int i,j;
  
  for(i=2*zoom-1;i<im1->DimX()-3*zoom;i+=zoom){
    for(j=2*zoom-1;j<im1->DimY()-3*zoom;j+=zoom){
      
      ami_optic_flow_lucas_kanade_2d_2o(im1_pos,im2_pos,im2_x_pos,im2_y_pos,u,i,j,
        window_radius,sigma,
        alpha,TOL_iter,
        flow_x_pos,flow_y_pos,im1->DimX(),im1->DimY());
      vort_pos[i/zoom-1][j/zoom-1]=(u[4]-u[3])/1.;
      flow_x_pos[i][j]=u[0];
      flow_y_pos[i][j]=u[1];
    }
  }
  
  im1->free_float_positions_2D(im1_pos);
  im2->free_float_positions_2D(im2_pos);
  im2_x->free_float_positions_2D(im2_x_pos);
  im2_y->free_float_positions_2D(im2_y_pos);
  flow_x->free_float_positions_2D(flow_x_pos);
  flow_y->free_float_positions_2D(flow_y_pos);
  im_vorticity->free_float_positions_2D(vort_pos);
 
  
} // amiVorticity()


/** Vorticity estimation with gradient computation **/
void amiGradVorticity(ParamList* p)
{
  char functionname[] = "amiVorticity";
  char description[]=" \n\
      2D Vorticity estimation\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - FLOAT IMAGE:        first image\n\
      - FLOAT IMAGE:        second image\n\
      - FLOAT IMAGE:        X component of the flow (input AND output)\n\
      - FLOAT IMAGE:        Y component of the flow (input AND output)\n\
      - INT   VALUE:        grid spacing (def 1)\n\
      - INT   VALUE:        window size  (def 5) \n\
      - FLOAT VALUE:        sigma (def 2.0) \n\
      - FLOAT VALUE:        regularization parameter alpha (def 1.0) \n\
      - FLOAT VALUE:        Convergence parameter (def 0.00001)\n\
      - FLOAT IMAGE:        Vorticity image \n\
      ";
  
  InrImage* im1 = NULL;
  InrImage* im2 = NULL;
  InrImage* flow_x = NULL;
  InrImage* flow_y = NULL;
  
  InrImage* im_vorticity       = NULL;
  
  int zoom = 1;        // LATTICE STEP TO COMPUTED THE ZOOMED IMAGE 
  int window_radius=5; //  WINDOW RADIUS TO FIT THE NEIBORHOOD OF (x0,y0) 
  float sigma=2;       // PARAMETER OF THE KERNEL OF THE LUCAS-KANADE ENERGY
  float alpha=10e-0;    // REGULARIZATION PARAMETER FOR SYSTEM MATRIZ (A=A+alfa*Id) 
  float TOL_iter=0.00001; // CONVERGENCE PARAMETER TO STOP ITERATIONS TO SOLVE THE LINEAR SYSTEM
    
  int n=0;
  
  if (!get_val_ptr_param<InrImage>(    im1,                p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    im2,                p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    flow_x,             p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    flow_y,             p, n)) HelpAndReturn;
  if (!get_int_param(      zoom,               p, n)) HelpAndReturn;
  if (!get_int_param(      window_radius,      p, n)) HelpAndReturn;
  if (!get_val_param<float>(    sigma,              p, n)) HelpAndReturn;
  if (!get_val_param<float>(    alpha,              p, n)) HelpAndReturn;
  if (!get_val_param<float>(    TOL_iter,           p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    im_vorticity,       p, n)) HelpAndReturn;
   
  float** im1_pos   =  im1          ->create_float_positions_2D();
  float** im2_pos   =  im2          ->create_float_positions_2D();
  float** flow_x_pos = flow_x       ->create_float_positions_2D();
  float** flow_y_pos = flow_y       ->create_float_positions_2D();
  float** vort_pos   = im_vorticity ->create_float_positions_2D();
  
  float** im2_x_pos; 
  ami_malloc2d(im2_x_pos,float,im1->DimX(),im1->DimY());
  float** im2_y_pos; 
  ami_malloc2d(im2_y_pos,float,im1->DimX(),im1->DimY());
  /* WE COMPUTE THE GRADIENT OF IMAGE 2 */
  printf("Calculando Gradiente\n");
  ami_grad_2df(im2_pos,im2_x_pos,im2_y_pos,im1->DimX(),im1->DimY());

  float u[6];          // LOCAL FLOW IN THE POINT (x0,y0) 
  int i,j;
  
  for(i=2*zoom-1;i<im1->DimX()-3*zoom;i+=zoom){
    for(j=2*zoom-1;j<im1->DimY()-3*zoom;j+=zoom){
      
      ami_optic_flow_lucas_kanade_2d_2o(im1_pos,im2_pos,im2_x_pos,im2_y_pos,u,i,j,
        window_radius,sigma,
        alpha,TOL_iter,
        flow_x_pos,flow_y_pos,im1->DimX(),im1->DimY());
      flow_x_pos[i][j]=u[0];
      flow_y_pos[i][j]=u[1];
      vort_pos[i/zoom-1][j/zoom-1]=(u[4]-u[3])/1.;
    }
  }
  
  ami_free2d(im2_x_pos);
  ami_free2d(im2_y_pos);
  im1->free_float_positions_2D(im1_pos);
  im2->free_float_positions_2D(im2_pos);
  flow_x->free_float_positions_2D(flow_x_pos);
  flow_y->free_float_positions_2D(flow_y_pos);
  im_vorticity->free_float_positions_2D(vort_pos);
 
  
} // amiGradVorticity()


/** Vorticity estimation (standard) **/
void amiVorticityStandard(ParamList* p)
{
  char functionname[] = "amiVorticityStandard";
  char description[]=" \n\
      2D Vorticity estimation with standard techniques\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - FLOAT IMAGE:        X component of the flow (input)\n\
      - FLOAT IMAGE:        Y component of the flow (input)\n\
      - FLOAT IMAGE:        Vorticity image \n\
      - INT   VALUE:        type of vorticity computation \n\
      0: standard  1: chi 2 (def 0)\n\
      ";
  
  InrImage* flow_x = NULL;
  InrImage* flow_y = NULL;
  InrImage* im_vorticity       = NULL;
  int vort_type=0;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>(    flow_x,             p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    flow_y,             p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(    im_vorticity,       p, n)) HelpAndReturn;
  if (!get_int_param(      vort_type,          p, n)) HelpAndReturn;
  
  float** flow_x_pos = flow_x->create_float_positions_2D();
  float** flow_y_pos = flow_y->create_float_positions_2D();
  float** vort_pos       = im_vorticity      ->create_float_positions_2D();
  
  int i,j;
  
  if (vort_type==1) ami_allocate_vorticity_equation();
  
  for(i=1;i<flow_x->DimX()-3;i++){
    for(j=1;j<flow_x->DimY()-3;j++){
      switch (vort_type) {
  case 0:
          // WE COMPUTE THE VORTICITY USING A STANDARD ALGORITHM 
    vort_pos[i-1][j-1]=ami_vorticity_2d_standard(i,j,flow_x_pos,flow_y_pos,flow_x->DimX(),flow_x->DimY());
    break;
  case 1:
    vort_pos[i-1][j-1]=(float)ami_vorticity_2d_chi2_9p_ij(i,j,flow_x_pos,flow_y_pos,flow_x->DimX(),flow_x->DimY());
    break;
      }
      }
  }
  
  if (vort_type==1) ami_free_vorticity_equation();
  
  flow_x->free_float_positions_2D(flow_x_pos);
  flow_y->free_float_positions_2D(flow_y_pos);
  im_vorticity->free_float_positions_2D(vort_pos);

} // amiVorticityStandard()

/** Load PDE OF parameters from file **/
void amiReadPDEOFParam(ParamList * p)
{
  char functionname[] = "amiReadPDEOFParam";
  char description[]=" \n\
      Reads Variational Optical Parameters from file\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - STRING:        filename\n\
      ";

  string*  filename = NULL;
  int n=0;
  
  if (!get_val_ptr_param<string>( filename, p, n)) HelpAndReturn;

  ami_optic_flow_param.load_parameter_file( *filename);
}

/** Write PDE OF parameters to file **/
void amiWritePDEOFParam(ParamList * p)
{
  char functionname[] = "amiWritePDEOFParam";
  char description[]=" \n\
      Writes Variational Optical Parameters to file\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - STRING:        filename\n\
      ";

  string*  filename = NULL;
  int n=0;
  
  if (!get_val_ptr_param<string>( filename, p, n)) HelpAndReturn;

  std::ofstream ofs( filename->c_str() );

  if ( ofs.is_open() )  {

  ami_optic_flow_param.save_parameter_file( ofs );

        ofs.close();
  }
  else
  {
       std::cerr << "Error opening file ...:  " << std::endl;
       return;
  }
}

/** Read Yosemite Ground Truth in Float **/
InrImage* amiReadBarronData(ParamList* p)
{
  char functionname[] = "amiReadBarronData";
  char description[]=" \n\
      Reads floating point Ground Truth for the Yosemite sequence for frames 8-9\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - STRING:        filename\n\
      - INTEGER:       boundary in X (def:0 ) \n\
      - INTEGER:       boundary in Y (def: 0)\n\
      ";

  string*  filename = NULL;
  InrImage* flow_x = NULL;
  InrImage* flow_y = NULL;
  int bx=0;
  int by=0;
  int n=0;
  
  if (!get_val_ptr_param<string>( filename, p, n)) HelpAndReturnNULL;
  flow_x = new InrImage(316,252,1,WT_FLOAT);
  flow_y = new InrImage(316,252,1,WT_FLOAT);

  flow_x->InitImage(0);
  flow_y->InitImage(0);
  
  float** flow_x_buf = (float**) flow_x->create_float_positions_2D();
  float** flow_y_buf = (float**) flow_y->create_float_positions_2D();
  
  read_barron_data<float,int>(filename->c_str(),flow_x_buf,flow_y_buf,316,252,bx,by);
  
  flow_x->free_float_positions_2D(flow_x_buf);
  flow_y->free_float_positions_2D(flow_y_buf);
  
  InrImage* vect = new InrImage(316,252,1,3,WT_FLOAT);
  
  flow_x->InitBuffer();
  flow_y->InitBuffer();
  vect->InitBuffer();
  do {
    vect->VectFixeValeurs(flow_x->ValeurBuffer(),flow_y->ValeurBuffer(),0);
    flow_x->IncBuffer();
    flow_y->IncBuffer();
  } while (vect->IncBuffer());

  delete flow_x;
  delete flow_y;
  
  return vect;
  
} // amiReadBarronData()

/*
float ***image_1,float ***image_2,
ami_v3f center,float radius,float velocity,ami_v3f ***u,
int dim_x,int dim_y,int dim_z
*/

/** Generate synthetic flow aroud a sphere **/
void amiGenerateSphereFlow(ParamList* p) 
{
  char functionname[] = "amiGenerateSphereFlow";
  char description[]=" \n\
      Generate a synthetic 3D fluid flow motion around a sphere\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - IMAGE:           first output image\n\
      - IMAGE:           second output image\n\
      - IMAGE:           generated flow\n\
      - 3 FLOAT VALUES   center of the sphere\n\
      - FLOAT VALUE      radius of the sphere \n\
      - FLOAT VALUE      velocity \n\
      - FLOAT VALUE      density (default 0.01)\n\
      - INTEGER VALUE    symmetric, if true generates both images displacing\n\
                         the particules by half the velocity in each direction (default 0) \n\
      ";

  InrImage* im1 = NULL;
  InrImage* im2 = NULL;
  InrImage* flow = NULL;
  float center[3] = {50,50,50};
  float radius=10;
  float velocity=1; 
  float density=0.01;
  int   symmetric=0;

  int n=0;

  if (!get_val_ptr_param<InrImage>(        im1,      p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(        im2,      p, n)) HelpAndReturn; 
  if (!get_vectimage_param(    flow,     p, n)) HelpAndReturn;
  if (!get_several_params<float,3>( center,   p, n)) HelpAndReturn;
  if (!get_val_param<float>(        radius,   p, n)) HelpAndReturn;
  if (!get_val_param<float>(        velocity, p, n)) HelpAndReturn;
  if (!get_val_param<float>(        density,  p, n)) HelpAndReturn;
  if (!get_int_param(          symmetric,p, n)) HelpAndReturn;
  
  float*** image1_pos = im1 ->create_positions_3D<float>();
  float*** image2_pos = im2 ->create_positions_3D<float>();
  ami_v3f*** flow_pos = flow->create_positions_3D<ami_v3f>();
  
  
  ami_3d_flow_sphere_obstacle_generation(
    image1_pos,image2_pos,
    center,
    radius,
    velocity,
    density,
    flow_pos,
    im1->DimX(),
    im1->DimY(),
    im1->DimZ(),
    symmetric
  );

  // save and free results
  im1  ->free_positions_3D<float>(image1_pos);
  im2  ->free_positions_3D<float>(image2_pos);
  flow ->free_positions_3D<ami_v3f>(flow_pos);

} // amiGenerateSphereFlow()

/** Generate synthetic 3D PIV flow  **/
void amiGenerate3DPIV(ParamList* p) 
{
  char functionname[] = "amiGenerate3DPIV";
  char description[]=" \n\
      Generate a synthetic 3D Particle displacement (PIV) images based on a displacement field and a mask\n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - IMAGE:           first  particle output image\n\
      - IMAGE:           second displaced particle output image\n\
      - IMAGE:           3D displacement \n\
      - IMAGE:           mask (unsigned char image) 0: air 255: solid object \n\
      - FLOAT VALUE      density (default 0.01)\n\
      - INTEGER VALUE    symmetric, if true generates both images displacing\n\
                         the particules by half the velocity in each direction (default 0) \n\
      ";

  InrImage* im1 = NULL;
  InrImage* im2 = NULL;
  InrImage* flow = NULL;
  InrImage* mask = NULL;
  float density=0.01;
  int   symmetric=0;

  int n=0;

  if (!get_val_ptr_param<InrImage>(        im1,      p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(        im2,      p, n)) HelpAndReturn; 
  if (!get_vectimage_param(    flow,     p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(        mask,     p, n)) HelpAndReturn;
  if (!get_val_param<float>(        density,  p, n)) HelpAndReturn;
  if (!get_int_param(          symmetric,p, n)) HelpAndReturn;
  
  float*** image1_pos = im1 ->create_positions_3D<float>();
  float*** image2_pos = im2 ->create_positions_3D<float>();
  ami_v3f*** flow_pos = flow->create_positions_3D<ami_v3f>();
  unsigned char*** mask_pos = mask->create_positions_3D<unsigned char>();
  
  ami_3d_flow_from_displacement(
    image1_pos,
    image2_pos,
    flow_pos,
    density,
    mask_pos,
    im1->DimX(),
    im1->DimY(),
    im1->DimZ(),
    symmetric
  );

  // save and free results
  im1  ->free_positions_3D<float>(image1_pos);
  im2  ->free_positions_3D<float>(image2_pos);
  flow ->free_positions_3D<ami_v3f>(flow_pos);
  mask ->free_positions_3D<unsigned char>(mask_pos);

} // amiGenerateSphereFlow()

/** Read a 3D Flow from an ASCII file **/
InrImage* amiReadFlow3D(ParamList* p)
{
  char functionname[] = "amiReadFlow3D";
  char description[]=" \n\
      Reads a 3D flow from an ASCII file specifying the slice you want from the file.\n\
      Returned image has the exact number of pixels of the lattice \n\
      ";
  char parameters[] =" \n\
      the parameters with their default values are : \n\
      - filename\n\
      - image dimensions (dim_x,dim_y,dim_z)\n\
      - image translation\n\
          default is (0,0,0)\n\
      - field offset (pos_u = pos_ASCII+offset)\n\
          default is (0,0,0)\n\
      - Displacement grid \n\
              deault is (1,1,1) \n\
          - Initial point (respect to translation)\n\
              default is (0,0,0) \n\
      ";

  string*  filename = NULL;
  int dim[3];
  int trans[3]   = {0,0,0};
  int offset[3]  = {0,0,0};
  ami_v3f init = {0,0,0};
    ami_v3f disp = {1,1,1}; // displacement 
  InrImage *u = NULL;
  ami_v3f ***u_pos;
  
  int n=0;
  
  if (!get_val_ptr_param<string>( filename, p, n)) HelpAndReturnNULL;
  if (!get_several_int_params<3>( dim, p, n)) HelpAndReturnNULL;
  if (!get_several_int_params<3>( trans, p, n)) HelpAndReturnNULL;
  if (!get_several_int_params<3>( offset, p, n)) HelpAndReturnNULL;
  if (!get_several_params<float,3>( disp, p, n)) HelpAndReturnNULL;
  if (!get_several_params<float,3>( init, p, n)) HelpAndReturnNULL;
  u = new InrImage((int)ceil((dim[0]-init[0])/disp[0]),
                     (int)ceil((dim[1]-init[1])/disp[1]),
                     (int)ceil((dim[2]-init[2])/disp[2]),3,WT_FLOAT);
  //u->InitImage(0);
  u->SetTranslation(trans[0],trans[1],trans[2]);
  
  u_pos = u->create_positions_3D<ami_v3f>();  
  ami_read_optic_flow_3D(filename->c_str(),u_pos,dim,trans,offset,disp,init); 
  u->free_positions_3D<ami_v3f>(u_pos); 
  
  return u;
  
} // amiReadFlow3D()
