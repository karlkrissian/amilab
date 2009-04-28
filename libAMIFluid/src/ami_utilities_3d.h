#ifndef AMI_UTILITIES_3D_H
#define AMI_UTILITIES_3D_H

#include "ami_prototypes.h"

typedef float ami_m3x3f[3][3];

/**   
 * FUNCION TO COMPUTE THE L^2 DISTANCE BETWEEN TWO 3D IMAGE VECTOR IT RETURNS THE ERROR VALUE 
 */
float ami_norm_2_v3f_error(ami_v3f ***grad_image_1,ami_v3f ***grad_image_2,int dim_x,int dim_y,int dim_z,int borde);

/** 
 * FUNCION TO COMPUTE THE L^1 DISTANCE BETWEEN TWO 3D IMAGE VECTOR IT RETURNS THE ERROR VALUE      
 */
float ami_norm_1_v3f_error(ami_v3f ***grad_image_1,ami_v3f ***grad_image_2,int dim_x,int dim_y,int dim_z,int borde);

/**
 * FUNCTION TO FILL THE BOUNDARY VALUES OF A 3D VECTOR IMAGE
*/
void ami_boundary_v3f(ami_v3f ***grad_image,int dim_x,int dim_y,int dim_z);

/**
 * FUNCTION TO FILL THE BOUNDARY VALUES OF A 2D+T VECTOR IMAGE
 */
void ami_boundary_vect_2d_t(ami_v3f ***grad_image,int dim_x,int dim_y,int dim_z);

/**
 * FUNCTION TO FILL THE DISPLACEMENT VALUES OF A 2D+T VECTOR IMAGE AT PIXELS
 * WHICH FALL OUTSIDE THE IMAGE
 */
void ami_fill_border_mask_2d_t(ami_v3f ***h,int dim_x,int dim_y,int dim_p,unsigned char ***border_mask);

/**
* CREATES A MASK IMAGE WITH VALUE 1 for pixels (or voxels) which vector 
* points inside the domain
*/
void ami_create_border_mask_2d_t( unsigned char ***border_mask, ami_v3f ***up,int dim_x2, int dim_y2, int dim_p, unsigned char symmetric);


/**
* CREATES A MASK IMAGE WITH VALUE 1 for pixels (or voxels) which vector 
* points inside the domain
*/
void ami_create_border_mask( unsigned char ***border_mask, ami_v3f ***up,int dim_x2, int dim_y2, int dim_z2, unsigned char symmetric);

/**
 * FUNCTION TO FILL THE DISPLACEMENT VALUES OF THE VECTORIAL IMAGE AT PIXELS
 * WHICH FALL OUTSIDE THE IMAGE
 */
void ami_fill_border_mask(ami_v3f ***h,int dim_x,int dim_y, int dim_z,unsigned char ***border_mask);

/**
 * FUNCTION TO FILL THE BOUNDARY VALUES OF A 3D MATRIX IMAGE
 */
void ami_boundary_m3x3f(ami_m3x3f ***grad_image,int dim_x,int dim_y,int dim_z);

/**
 * FUNCTION TO FILL THE BOUNDARY VALUES OF A 3D IMAGE
*/
void ami_boundary_3df(float ***image,int dim_x,int dim_y,int dim_z);

/**
 * BASIC COMPUTATION OF 3D IMAGE GRADIENT 
 */
void ami_grad_3d(float ***image,ami_v3f ***grad_image,int dim_x,int dim_y,int dim_z);

/**
 * BASIC COMPUTATION OF 3D IMAGE GRADIENT 
 */
void ami_grad_2d_t(float ***image,ami_v3f ***grad_image,int dim_x,int dim_y,int dim_t);

/**
 * COMPUTATION OF 3D IMAGE GRADIENT  3x3x3 mask
 */
void ami_grad_3d_3x3x3(float ***image,ami_v3f ***grad_image,int dim_x,int dim_y,int dim_z);

/**
 * BASIC COMPUTATION OF 3D HESSIAN IMAGE 
 */
void ami_hessian_3d(float ***image,ami_m3x3f ***grad_image,int dim_x,int dim_y,int dim_z);

/**   
 * FUNCION TO COMPUTE THE NORM MAX OF A 3D IMAGE VECTOR                
 */
float ami_norm_max_v3f(ami_v3f ***grad_image,int dim_x,int dim_y,int dim_z);

/**
 * FUNCION TO COMPUTE THE NORM 2 OF A 3D IMAGE VECTOR                  
 */
float ami_norm_2_v3f(ami_v3f ***grad_image,int dim_x,int dim_y,int dim_z);

/**
 * FUNCION TO COMPUTE THE NORM 2 OF A 2D+T IMAGE VECTOR SEQUENCE                   
 */
float ami_norm_2_vect_2d_t(ami_v3f ***grad_image,int dim_x,int dim_y,int dim_z);

/**
 * 3D IMAGE INTERPOLATION (LINEAR METHOD)
 */
void ami_image_interpolation_3df(float ***image,ami_v3f ***u,float ***image_output,int dim_x,int dim_y,int dim_z);

/**
 *  IMAGE WARPING using SPLINES (only 2D for the moment)
 */
void ami_image_splinewarp(float ***image,ami_v3f ***u,float ***image_output,int dim_x,int dim_y, int dim_z, int spline_degree);

/**
 * 2D+T IMAGE INTERPOLATION 
 * positive version  
 * image_output(x,t)=image(x+u(x,t),t+1)
 * interpolation: 0 for linear, 1 for splines
 */
void ami_image_interpolation_scal_2d_t_pos(float ***image,ami_v3f ***u,float*** image_output,
                                           int dim_x,int dim_y,int dim_t, int interpolation);

/**
 * 2D+T IMAGE INTERPOLATION 
 * negative version (for symmetric optical flow)
 * image_output(x,t)=image(x-u(x,t),t)
 * interpolation: 0 for linear, 1 for splines
 */
void ami_image_interpolation_scal_2d_t_neg(float ***image,ami_v3f ***u,float ***image_output,
                                           int dim_x,int dim_y,int dim_t, int interpolation);


/**
 *    3D IMAGE VECTOR POINT INTERPOLATION (BILINEAR METHOD)
 */
void ami_point_interpolation_v3f(ami_v3f ***image,int i, int j, int k,ami_v3f u,ami_v3f v_out,
                                 int dim_x,int dim_y,int dim_z);


/**
 *    Compute the image gradient at the position x+u, using spline interpolation 
 */
void ami_compute_splinegrad_v3f(float ***image,ami_v3f ***u,ami_v3f ***grad,int dim_x,int dim_y,int dim_z);

/**
 * 3D IMAGE VECTOR INTERPOLATION (LINEAR METHOD)
 */
void ami_image_interpolation_v3f(ami_v3f ***image,ami_v3f ***u,ami_v3f ***image_output,int dim_x,int dim_y,int dim_z);

/**
 * 2D+T IMAGE VECTOR INTERPOLATION (LINEAR METHOD)
 * positive version  
 * image_output(x,t)=image(x+u(x,t),t+1)
 */
void ami_image_interpolation_vect_2d_t_pos(ami_v3f ***image,ami_v3f ***u,ami_v3f ***image_output,int dim_x,int dim_y,int dim_t);

/**
 * 2D+T IMAGE VECTOR INTERPOLATION (LINEAR METHOD)
 * negative version (for symmetric optical flow)
 * image_output(x,t)=image(x-u(x,t),t)
 */
void ami_image_interpolation_vect_2d_t_neg(ami_v3f ***image,ami_v3f ***u,ami_v3f ***image_output,int dim_x,int dim_y,int dim_t);

/**
 *    Compute the image gradient at the position x+u, using spline interpolation 
 *    at (x+u(x,t),t+1)
 */
void ami_compute_splinegrad_2d_t_pos(float ***image,ami_v3f ***u,ami_v3f ***grad,int dim_x,int dim_y,int dim_t);

/**
 *    Compute the image gradient at the position x+u, using spline interpolation 
 *    at (x-u(x,t),t)
 */
void ami_compute_splinegrad_2d_t_neg(float ***image,ami_v3f ***u,ami_v3f ***grad,int dim_x,int dim_y,int dim_t);

/**
 * 3D HESSIAN INTERPOLATION (LINEAR METHOD)
 * at the point (x,y,z)+ u(z,y,z)
 * image: hessian image
 * u       : displacement field
 * res     : interpolated hessian matrix at u+(x,y,z)
 * (x,y,z) : current position
 * (dim_x,dim_y,dim_z) : image dimension
 */
void ami_hessian_interpolation(ami_m3x3f ***image,ami_v3f ***u,ami_m3x3f* res,int x, int y, int z, int dim_x,int dim_y,int dim_z);

/**
 * FUNCTION TO COPY A 3D IMAGE 
*/
void ami_copy_3d(float ***image_1,float ***image_2,int dim_x,int dim_y,int dim_z);

/** 
 * FUNCTION TO COPY A 3D IMAGE VECTOR 
 */
void ami_copy_v3f( ami_v3f ***image_grad_1,ami_v3f ***image_grad_2,int dim_x,int dim_y,int dim_z);

/**
 * BASIC CONVOLUTION OF A 3D IMAGE 
 */
void ami_convolution_3d(float ***image,float beta[3],int dim_x,int dim_y,int dim_z);

/**
 * BASIC CONVOLUTION OF A 2D+t IMAGE 
 */
void ami_convolution_2d_t(float ***image,float beta[3],int dim_x,int dim_y,int dim_t);

/**
 * 3D IMAGE ZOOM DOWN 
 */
int ami_zoom_down_3d(float ***image,float ***image_zoom,float beta[3],int zoom_factor[3],int dim_x,int dim_y,int dim_z);

/**
 * 2D+T IMAGE ZOOM DOWN 
 */
int ami_zoom_down_2d_t(float ***image,float ***image_zoom,float beta[2],int zoom_factor[2],int dim_x,int dim_y,int dim_t);

/**
 * 3D IMAGE ZOOM UP USING A CONVOLUTION FILTER FOR IMAGE REGULARIZATION 
 */
int ami_zoom_up_3d_filter(float ***image,float ***image_zoom,float beta[3],int zoom_factor[3],int dim_x,int dim_y,int dim_z);

/**
 * 3D IMAGE ZOOM UP USING BILINEAR INTERPOLATION 
 */
int ami_zoom_up_3d_interpolation(float ***image,float ***image_zoom,int zoom_factor[3],int dim_x,int dim_y,int dim_z);

/**
 * 2D+T IMAGE ZOOM UP USING BILINEAR INTERPOLATION 
 */
int ami_zoom_up_2d_t_interpolation(float ***image,float ***image_zoom,int zoom_factor[2],int dim_x,int dim_y,int dim_p);

/**
 * 3D IMAGE VECTOR ZOOM UP 
 */
int ami_zoom_up_v3f_flow(ami_v3f ***image_grad,ami_v3f ***image_grad_zoom,float beta[3],int zoom_factor[3],int dim_x,int dim_y,int dim_z);

/**
 * 2D+T IMAGE VECTOR ZOOM UP 
 */
int ami_zoom_up_vect_2d_t_flow(ami_v3f ***image_grad,ami_v3f ***image_grad_zoom,float beta[2],int zoom_factor[2],int dim_x,int dim_y,int dim_p);

/**
 * FUNCTION TO SOLVE THE LAPLACE PROBLEM WITH DIRICHLET CONDITION WE SOLVE
 * divergence(pot)= div 
 */
int ami_laplace_3d(float ****pot, float ***div,float beta[3],int zoom_factor[3], float TOL_GaussSeidel,int Nscales,double A, int dim_x,int dim_y,int dim_z);

/** 
 * FUNCTION TO COMPUTE THE SOLENOIDAL PROYECCION OF A FLOW 
 */
int ami_solenoidal_proyeccion_3d(ami_v3f ***u,float beta[3],int zoom_factor[3], float TOL_GaussSeidel,int Nscales,double A, int dim_x,int dim_y,int dim_z);

/**
 * FUNCTION TO READ AN ASCII FILE WITH THE 3D OPTIC FLOW INFORMATION
 */
int ami_read_optic_flow_3D(const char* name, ami_v3f ***u, int dim[3], int translation[3], int offset[3], ami_v3f disp, ami_v3f init);

#endif // AMI_UTILITIES_3D_H
