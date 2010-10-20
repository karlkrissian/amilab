#ifndef AMI_LUCAS_KANADE_2D_2O_H
#define AMI_LUCAS_KANADE_2D_2O_H
/**************************************************************************************
              BEGIN OF FUNCTION PROTOTYPES OF LUCAS-KANADE GENERALIZED METHOD        */
/************************************************************************************/
#define NITER_LUCAS_KANADE 200

int ami_lucas_kanade_2d_2o_init(float **ut,float **vt,float *u,float x0,float y0,int window_radius, float sigma,int dim_x,int dim_y);
/** 
 * FUNCTION TO COMPUTE A SECOND ORDER WARPING 
*/
float ami_image_warping_2d_2o(float **image,float *u,float x0,float y0,float x,float y,int dim_x,int dim_y);

/** 
 * FUNCTION TO COMPUTE AUXILIAR VECTOR OF LUCAS-KANADE 2 ORDER METHOD 
*/
void ami_lucas_kanade_2d_2o_v6f(float **image_x,float **image_y,float *u,float x0,float y0,float x,float y,float *I,int dim_x,int dim_y);

/** 
 * FUNCTION TO COMPUTE THE 6x6 LUCAS AND KANADE 2D 2 ORDER SYSTEM. IT RETURN THE ENERGY 
*/
float ami_lucas_kanade_2d_20_system(float **image_1,float **image_2,float **image_2_x,float **image_2_y,float *u,float x0,float y0,int window_radius,
                                   float sigma,float alfa,double *b,double **A,int dim_x,int dim_y);
/** 
 * FUNCTION TO COMPUTE 2D OPTIC FLOW IN A POINT USING SECOND ORDER LUCAS-KANADE TECHNIQUE. IT RETURNS THE ENRGY ERROR 
*/
double ami_optic_flow_lucas_kanade_2d_2o(float **image_1,float **image_2,float **image_2_x,float **image_2_y,float *u,float x0,float y0,int window_radius,float sigma,float alfa,float TOL_iter,float **ut,float **vt,int dim_x,int dim_y);

/**************************************************************************************
              END OF FUNCTION PROTOTYPES OF LUCAS-KANADE GENERALIZED METHOD        */
/************************************************************************************/
#endif
