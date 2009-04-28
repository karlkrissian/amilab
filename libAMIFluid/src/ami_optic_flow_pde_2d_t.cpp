

#include "ami_utilities_3d.h"

#include "ami_optic_flow_pde_2d_t.h"
#include "ami_optic_flow_pde_3d.h"
#include <string.h>

#define Niter_GaussSeidel 10000
#define Niter_GaussSeidel_2D 5000
#define Niter_Scales 100
#define MAX_RELATIVE_ERROR 10
 

inline void ami_matriz_vector_2d(ami_m3x3f* A, double* x, ami_v3f v)
{
  register float* tmp;
  
  tmp = (*A)[0];
  v[0] = tmp[0]*x[0]+tmp[1]*x[1];
   
  tmp = (*A)[1];
  v[1] = tmp[0]*x[0]+tmp[1]*x[1];
}



/**
 *  COMPUTATION OF 2D+T IMAGE GRADIENT 
 */
void ami_compute_grad_2d_t(float ***image,ami_v3f ***grad_image,int dim_x,int dim_y,int dim_t, const PDEOpticFlowParam& param)
{
  switch(param.GetGradientComputation()) {
    case grad_max:
      ami_grad_2d_t(image,grad_image,dim_x,dim_y,dim_t);
      break;
/*    case grad_inv:
      ami_grad_3d_3x3x3(image,grad_image,dim_x,dim_y,dim_t);
      break;
      */
    default:
      fprintf(stderr,"ami_compute_grad_2d_t() \t gradient mode not available \n");
  }
}


/**
 * FUNCTION TO COMPUTE A 2D+T OPTIC FLOW
 */
void ami_optic_flow_system_computation_v0_temporal(
    float ***image,/* IMAGE SEQUENCE TO COMPUTE THE FLOW (INPUT DATA) */
    ami_v3f ***u,/* CURRENT FLOW (IT HAS TO BE INITIALIZED (INPUT DATA) */
    ami_v3f ***b,/* INDEPENDENT VECTOR OF THE ASSOCIATED LINEAR SYSTEM (OUTPUT DATA) */
    ami_m3x3f ***A,/* MATRIX OF THE ASSOCIATED LINEAR SYSTEM (INPUT DATA) */
    ami_v3f alfa,/* WEIGHT OF REGULARIZATION TERM (INPUT/OUTPUT DATA) (IT IS NORMALIZED USING
    THE NORM OF THE GRADIENT OF THE SECOND IMAGE */
    float* temporal_alpha, /* weight for the temporal regularization */
    int dim_x,int dim_y, /* IMAGE DIMENSIONS */
    int dim_t,  // number of images in the sequence
    const PDEOpticFlowParam& param)
{
  
  int i,j,k,l,m,n;
  ami_v3f ***grad_image,***grad_image_2i;
  float ***image_2i;
  float ***image_i;
  float norm;
  int dim_p = dim_t-1;
  int image_dimension=2;
  double** B;
  double** B_1;
  ami_malloc2d(B,  double,image_dimension,image_dimension);
  ami_malloc2d(B_1,double,image_dimension,image_dimension);
  
  float u_xp=0.0,u_xm=0.0,u_yp=0.0,u_ym=0.0,u_zp=0.0,u_zm=0.0,u_0; // value of u for the current coordinate at the current point and at its direct neighbors
  double div;
  int interpolation_type=0;

  switch (param.GetInterpolationType()) {
    case linear: interpolation_type=0;
    break;
    case spline: interpolation_type=1;
    break;
  }
    
  
  printf("Running ami_optic_flow_system_computation_v0_temporal()\n");
  /* WE ALLOCATE MEMORY */
  ami_malloc3d(grad_image,   ami_v3f,dim_x,dim_y,dim_t);
  ami_malloc3d(grad_image_2i,ami_v3f,dim_x,dim_y,dim_p);
  ami_malloc3d(image_2i,     float,  dim_x,dim_y,dim_p);
    
  /* WE COMPUTE THE GRADIENT OF IMAGE 2*/
  if (param.GetSmoothGradient()) {
     //printf("Computing smoothed gradient \n");
    ami_malloc3d(image_i,float,dim_x,dim_y,dim_t);
     // we use image_2i to store temporary the smoothed images
    ami_copy_3d(image,image_i,dim_x,dim_y,dim_t);
      // WE FILTER THE IMAGES TO COMPUTE THE GRADIENT 
	{
    float *beta = new float[image_dimension];
    for(l=0;l<image_dimension;l++) beta[l]=0.25;
    ami_convolution_2d_t(image_i,beta,dim_x,dim_y,dim_t);
	delete [] beta;
	}

	ami_compute_grad_2d_t(image_i,grad_image,dim_x,dim_y,dim_t,param);
    //printf(" Freeing image_i\n");
    ami_free3d(image_i);
  } else
    ami_compute_grad_2d_t(image,grad_image,dim_x,dim_y,dim_t,param);
    
    
    /* WE NORMALIZE THE DIFFUSION WEIGHT */
    norm=ami_norm_2_vect_2d_t(grad_image,dim_x,dim_y,dim_p);
    printf("** Grad norm = %f\n",norm);
    for(l=0;l<image_dimension;l++)
      alfa[l]=(alfa[l])*(norm+param.GetAlphaNormEpsilon())*(norm+param.GetAlphaNormEpsilon());
    *temporal_alpha  *= (norm+param.GetAlphaNormEpsilon()) * norm+param.GetAlphaNormEpsilon();
printf("alpha %f %f %f \n",alfa[0],alfa[1], *temporal_alpha);
      
    /* WE INTERPOLATE THE GRADIENT AFTER CURRENT FLOW DISPLACEMENT */
    ami_image_interpolation_vect_2d_t_pos(grad_image,u,grad_image_2i,dim_x,dim_y,dim_t);
    /* WE INTERPOLATE THE IMAGE 2 AFTER CURRENT FLOW DISPLACEMENT */
    ami_image_interpolation_scal_2d_t_pos(image,u,image_2i,dim_x,dim_y,dim_t,
                                          interpolation_type);
    /* WE COMPUTE THE MATRIX AND VECTORS ASSOCIATED TO HORN AND SHUCNK METHOD */
    for(i=0;i<dim_x;i++) {
      for(j=0;j<dim_y;j++) {
	for(k=0;k<dim_p;k++) {
	  /* WE COMPUTE THE VECTOR b OF HORN-SHUNCK SYSTEM */
	  for(l=0;l<image_dimension;l++) {
	    b[i][j][k][l]=(image[i][j][k]-image_2i[i][j][k])*grad_image_2i[i][j][k][l];
  	    // if the smoothing constraint is global, add alfa*div(u)
	    if (param.GetGlobalConstraint()) {
	      u_0 =u[i][j][k][l];
	      u_xp=(i<dim_x-1)?u[i+1][j][k][l]:u[dim_x-1][j][k][l];
	      u_xm=(i>0)      ?u[i-1][j][k][l]:u[0]      [j][k][l];
	      u_yp=(j<dim_y-1)?u[i][j+1][k][l]:u[i][dim_y-1][k][l];
	      u_ym=(j>0)      ?u[i][j-1][k][l]:u[i][0]      [k][l];
	      u_zp=(k<dim_p-1)?u[i][j][k+1][l]:u[i][j][dim_p-1][l];
	      u_zm=(k>0)      ?u[i][j][k-1][l]:u[i][j][0      ][l];
	      div = u_xp+u_xm+u_yp+u_ym-4*u_0;
          b[i][j][k][l] += alfa[l]*div;
	      div = u_zp+u_zm+-2*u_0; 
          b[i][j][k][l] += *temporal_alpha*div;
	    } // if global_constraint
	  }
	  
	  /* WE COMPUTE THE MATRIX OF THE HORN-SHUNK SYSTEM */
	  for(m=0;m<image_dimension;m++) {
	    for(n=0;n<image_dimension;n++)
	      B[m][n]=grad_image_2i[i][j][k][m]*grad_image_2i[i][j][k][n];
	    //if (OF2DT_SmoothingPhi==phi_x)
	      // for smoothing, we use 3 dimensions ...
	      B[m][m]+=2*image_dimension*alfa[m]+2* (*temporal_alpha);
/*	    else {
	      tmp = (dp_xp+dp)+(dp+dp_xm) + (dp_yp+dp)+(dp+dp_ym)+ (dp_zp+dp)+(dp+dp_zm);
	      tmp *=  alfa[m]/2.0;
	      B[m][m]+=tmp;
	    }
	    */
	  }
	  ami_inversa((double**)B,(double**)B_1,image_dimension);
	  for(m=0;m<image_dimension;m++)
	    for(n=0;n<image_dimension;n++)
	      A[i][j][k][m][n]=B_1[m][n];
	}
      }
    }
    /* WE FREE THE MEMORY */
    ami_free3d(grad_image);
    ami_free3d(grad_image_2i);
    ami_free3d(image_2i);

    ami_free2d(B);
    ami_free2d(B_1);
    
} // ami_optic_flow_system_computation_v0_temporal()


/**
 *  FUNCTION TO BUILD THE OPTICAL FLOW EQUATION SYSTEM
 *  with the symmetric formulation and temporal smoothing
 */
void ami_optic_flow_system_computation_symmetric_temporal(
    float ***image,/* IMAGE SEQUENCE TO COMPUTE THE FLOW (INPUT DATA) */
    ami_v3f ***u,/* CURRENT FLOW (IT HAS TO BE INITIALIZED (INPUT DATA) */
    ami_v3f ***b,/* INDEPENDENT VECTOR OF THE ASSOCIATED LINEAR SYSTEM (OUTPUT DATA) */
    ami_m3x3f ***A,/* MATRIX OF THE ASSOCIATED LINEAR SYSTEM (INPUT DATA) */
    float *** image_der_phi, // image of phi'(|grad(u)|^2), if phi'==1, returns NULL
    ami_v3f alfa,/* WEIGHT OF REGULARIZATION TERM (INPUT/OUTPUT DATA) (IT IS NORMALIZED USING
    THE NORM OF THE GRADIENT OF THE SECOND IMAGE */
    float* temporal_alpha, /* weight for the temporal regularization */
    int dim_x,int dim_y, /* IMAGE DIMENSIONS */
    int dim_t, // number of images in the sequence
    const PDEOpticFlowParam& param
    )
{
  int i,j,k,l,m,n;
  ami_v3f ***grad_image;
  ami_v3f ***grad_image_sum;
  ami_v3f ***grad_image_1i;
  ami_v3f ***grad_image_2i;
  float ***image_i; // interpolated image at x+u
  float ***image_1i; // interpolated image at x+u
  float ***image_2i; // interpolated image at x-u
  float norm;
  int image_dimension = 2;
  int dim_p = dim_t-1;
  float u_xp=0.0,u_xm=0.0,u_yp=0.0,u_ym=0.0,u_zp=0.0,u_zm=0.0,u_0; // value of u for the current coordinate at the current point and at its direct neighbors
  double div,tmp;
  double grad2_u;
  float dp_xp=0.0,dp_xm=0.0,dp_yp=0.0,dp_ym=0.0,dp_zp=0.0,dp_zm=0.0,dp=0.0; // derivative of phi´ at the current point and at its direct neighbors
  int interpolation_type = 0;
  
  double** B;
  double** B_1;
  ami_malloc2d(B,  double,image_dimension,image_dimension);
  ami_malloc2d(B_1,double,image_dimension,image_dimension);
  
  switch (param.GetInterpolationType()) {
    case linear: interpolation_type=0;
    break;
    case spline: interpolation_type=1;
    break;
  }

  /* WE ALLOCATE MEMORY */
  ami_malloc3d(grad_image,ami_v3f,dim_x,dim_y,dim_t);
   
  if (param.GetGradientComputation()!=grad_spline) {
  /* WE COMPUTE THE GRADIENT OF IMAGE 1 & 2*/
  if (param.GetSmoothGradient()) {
    //printf("Computing smoothed gradient \n");
    ami_malloc3d(image_i,float,dim_x,dim_y,dim_t);
    // we use image_i to store temporary the smoothed images
    ami_copy_3d(image,image_i,dim_x,dim_y,dim_t);
    // WE FILTER THE IMAGES TO COMPUTE THE GRADIENT 

	{
    float *beta = new float[image_dimension];
    for(l=0;l<image_dimension;l++) beta[l]=0.25;
    ami_convolution_2d_t(image_i,beta,dim_x,dim_y,dim_t);
	delete [] beta;
	}

    //printf("Gradient computation \n");
    ami_compute_grad_2d_t(image_i,grad_image,dim_x,dim_y,dim_t,param);
    //printf(" Freeing image_i\n");
    ami_free3d(image_i);
  } else {
    //printf("Computing standard gradient \n");
    ami_compute_grad_2d_t(image,grad_image,dim_x,dim_y,dim_t,param);
  }
  }

  //printf("Allocating warped images   \n");
  ami_malloc3d(grad_image_1i,ami_v3f,dim_x,dim_y,dim_p);
  ami_malloc3d(grad_image_2i,ami_v3f,dim_x,dim_y,dim_p);
  ami_malloc3d(image_1i,float,dim_x,dim_y,dim_p);
  ami_malloc3d(image_2i,float,dim_x,dim_y,dim_p);
  
  /* WE COMPUTE THE HESSIAN IMAGE 2 */
//  ami_hessian_3d(image_2,hessian_image,dim_x,dim_y,dim_z);

// new symmetric half
  // divide u by half
  for(i=0;i<dim_x;i++) 
    for(j=0;j<dim_y;j++) 
      for(k=0;k<dim_p;k++)
    for(l=0;l<image_dimension;l++) u[i][j][k][l] /= 2.0;


  printf("Computing warped images   \n");
  /* WE INTERPOLATE THE GRADIENT AFTER CURRENT FLOW DISPLACEMENT */
  if ((param.GetGradientComputation()!=grad_spline)) {
    ami_image_interpolation_vect_2d_t_neg(grad_image,u,grad_image_1i,dim_x,dim_y,dim_t);
  } else {
    ami_compute_splinegrad_2d_t_neg(image,u,grad_image_1i,dim_x,dim_y,dim_t);
  }

  /* WE INTERPOLATE THE IMAGE 2 AFTER CURRENT FLOW DISPLACEMENT */
  ami_image_interpolation_scal_2d_t_neg(image,u,image_1i,dim_x,dim_y,dim_t,
                                        interpolation_type);

  /* WE INTERPOLATE THE GRADIENT AFTER CURRENT FLOW DISPLACEMENT */
  if ((param.GetGradientComputation()!=grad_spline)) {
    ami_image_interpolation_vect_2d_t_pos(grad_image,u,grad_image_2i,dim_x,dim_y,dim_t);
  } else {
    ami_compute_splinegrad_2d_t_pos(image,u,grad_image_2i,dim_x,dim_y,dim_t);
  }
  /* WE INTERPOLATE THE IMAGE 2 AFTER CURRENT FLOW DISPLACEMENT */
  ami_image_interpolation_scal_2d_t_pos(image,u,image_2i,dim_x,dim_y,dim_t,
                                        interpolation_type);
  
// new symmetric half
  // we restore the original displacement u
  for(i=0;i<dim_x;i++) 
    for(j=0;j<dim_y;j++) 
      for(k=0;k<dim_p;k++)
    for(l=0;l<image_dimension;l++) u[i][j][k][l] *=  2.0;


  // we store the sum of both gradients in grad_image_1i,
  // but call it grad_image_sum for clarity
  grad_image_sum = grad_image_1i;
  for(i=0;i<dim_x;i++) 
    for(j=0;j<dim_y;j++) 
      for(k=0;k<dim_p;k++) {
	for(l=0;l<image_dimension;l++) { 
        grad_image_sum[i][j][k][l] += grad_image_2i[i][j][k][l];
// new symmetric half
        grad_image_sum[i][j][k][l] /= 2.0;

      }
	grad_image_sum[i][j][k][2] = 0;
//	printf("grad sum (%d %d %d) =  %f %f\n",i,j,k,
//	       grad_image_sum[i][j][k][0], grad_image_sum[i][j][k][1]);
      }
  
  
//  printf("Normalizing alpha\n");
  /* WE NORMALIZE THE DIFFUSION WEIGHT */
  norm=ami_norm_2_vect_2d_t(grad_image_sum,dim_x,dim_y,dim_p);
//  norm=1;
  printf("Alfa is multiplied by (%0.2f+%0.2f)²\n",norm,param.GetAlphaNormEpsilon());
  for(l=0;l<image_dimension;l++)
      alfa[l]=(alfa[l])*(norm+param.GetAlphaNormEpsilon())*(norm+param.GetAlphaNormEpsilon());
  *temporal_alpha  *= (norm+param.GetAlphaNormEpsilon()) * norm+param.GetAlphaNormEpsilon();
  
  // if phi' != 1, pre-compute phi'(norm(grad(u)))
  switch (param.GetSmoothingFunction()) {
    case phi_sqrt_x:
      for(i=0;i<dim_x;i++) 
	for(j=0;j<dim_y;j++) 

	  for(k=0;k<dim_p;k++) {
	/* WE COMPUTE THE VECTOR b OF HORN-SHUNCK SYSTEM */
	grad2_u=0;
	for(l=0;l<image_dimension;l++) {
	  u_xp=(i<dim_x-1)?u[i+1][j][k][l]:u[dim_x-1][j][k][l];
	  u_xm=(i>0)      ?u[i-1][j][k][l]:u[0]      [j][k][l];
	  u_yp=(j<dim_y-1)?u[i][j+1][k][l]:u[i][dim_y-1][k][l];
	  u_ym=(j>0)      ?u[i][j-1][k][l]:u[i][0]      [k][l];
	  grad2_u += (u_xp-u_xm)*(u_xp-u_xm)+(u_yp-u_ym)*(u_yp-u_ym);
	  u_zp=(k<dim_p-1)?u[i][j][k+1][l]:u[i][j][dim_p-1][l];
	  u_zm=(k>0)      ?u[i][j][k-1][l]:u[i][j][0      ][l];
	  grad2_u += (u_zp-u_zm)*(u_zp-u_zm);
	  grad2_u/=4.0;
	}
	image_der_phi[i][j][k] = 0.5/sqrt(grad2_u+1E-6);
	  }
	  break;
    default:
      break;
  }
  
  /* WE COMPUTE THE MATRIX AND VECTORS ASSOCIATED TO HORN AND SHUCNK METHOD */
  for(i=0;i<dim_x;i++) {
    for(j=0;j<dim_y;j++) {
      for(k=0;k<dim_p;k++) {
	// pre-compute the value of phi' if needed
	if (param.GetSmoothingFunction()!=phi_x) {
	  dp = image_der_phi[i][j][k];
	  dp_xp=(i<dim_x-1)?image_der_phi[i+1][j][k]:image_der_phi[dim_x-1][j][k];
	  dp_xm=(i>0)      ?image_der_phi[i-1][j][k]:image_der_phi[0]      [j][k];
	  dp_yp=(j<dim_y-1)?image_der_phi[i][j+1][k]:image_der_phi[i][dim_y-1][k];
	  dp_ym=(j>0)      ?image_der_phi[i][j-1][k]:image_der_phi[i][0]      [k];
	  dp_zp=(k<dim_p-1)?image_der_phi[i][j][k+1]:image_der_phi[i][j][dim_p-1];
	  dp_zm=(k>0)      ?image_der_phi[i][j][k-1]:image_der_phi[i][j][0      ];
	}
	/* WE COMPUTE THE VECTOR b OF HORN-SHUNCK SYSTEM */
	for(l=0;l<image_dimension;l++) {
	  b[i][j][k][l]=(image_1i[i][j][k]-image_2i[i][j][k])*(grad_image_sum[i][j][k][l]);
	  // if the smoothing constraint is global, add alfa*div(u)
	  if (param.GetGlobalConstraint()) {
	    u_0 =u[i][j][k][l];
	    u_xp=(i<dim_x-1)?u[i+1][j][k][l]:u[dim_x-1][j][k][l];
	    u_xm=(i>0)      ?u[i-1][j][k][l]:u[0]      [j][k][l];
	    u_yp=(j<dim_y-1)?u[i][j+1][k][l]:u[i][dim_y-1][k][l];
	    u_ym=(j>0)      ?u[i][j-1][k][l]:u[i][0]      [k][l];
	    u_zp=(k<dim_p-1)?u[i][j][k+1][l]:u[i][j][dim_p-1][l];
	    u_zm=(k>0)      ?u[i][j][k-1][l]:u[i][j][0      ][l];
	    switch (param.GetSmoothingFunction()) {
	      case phi_x:

		div = u_xp+u_xm+u_yp+u_ym-4*u_0;
        b[i][j][k][l] += alfa[l]*div;
        div = u_zp+u_zm+-2*u_0; 
        b[i][j][k][l] += *temporal_alpha*div;

		break;
	      case phi_sqrt_x:
		div  = (u_xp-u_0)*(dp_xp+dp) - (u_0-u_xm)*(dp+dp_xm);
		div += (u_yp-u_0)*(dp_yp+dp) - (u_0-u_ym)*(dp+dp_ym);
		div += (u_zp-u_0)*(dp_zp+dp) - (u_0-u_zm)*(dp+dp_zm);
		div /= 2.0;
		b[i][j][k][l] += alfa[l]*div;
		break;
	    } // switch SmoothingPhi
	  } // if global_constraint
	}
	
	/* WE COMPUTE THE MATRIX OF THE HORN-SHUNK SYSTEM */
	for(m=0;m<image_dimension;m++) {
	  for(n=0;n<image_dimension;n++) {
	    B[m][n] = grad_image_sum[i][j][k][m]*grad_image_sum[i][j][k][n];
	  }
	  if (param.GetSmoothingFunction()==phi_x)
	    // for smoothing, we use 3 dimensions ...
        B[m][m]+=2*image_dimension*alfa[m]+2* (*temporal_alpha);
	  else {
	    tmp = (dp_xp+dp)+(dp+dp_xm) + (dp_yp+dp)+(dp+dp_ym)+ (dp_zp+dp)+(dp+dp_zm);
	    tmp *=  alfa[m]/2.0;
	    B[m][m]+=tmp;
	  }
	}
	
	ami_inversa((double**)B,(double**)B_1,image_dimension);
	for(m=0;m<image_dimension;m++)
	  for(n=0;n<image_dimension;n++) {
	  A[i][j][k][m][n]=B_1[m][n];
	  }
/*
	  if ((i%5==0)&&(j%5==0)) 
	    printf("%d %d %d , A= (%f %f %f %f), b = (%f %f) \n",i,j,k,
		   (float) A[i][j][k][0][0],
		   (float) A[i][j][k][0][1], 
		   (float) A[i][j][k][1][0],
		   (float) A[i][j][k][1][1],
		   (float) b[i][j][k][0],
		   (float) b[i][j][k][1]
		  );
	  */
      }
    }
  }
  /* WE FREE THE MEMORY */
  ami_free3d(grad_image);
  ami_free3d(grad_image_1i);
  ami_free3d(grad_image_2i);
  ami_free3d(image_1i);
  ami_free3d(image_2i);
  
  ami_free2d(B);
  ami_free2d(B_1);
  
} // ami_optic_flow_system_computation_symmetric_temporal()
 





/*****************************************************************************/
/* FUNCTION TO SOLVE THE HORN-SHUNCK EQUATION SYSTEM                         */
void ami_optic_flow_system_solution_temporal(
    ami_v3f ***h,/* CURRENT LOCAL DISPLACEMENT (INPUT/OUTPUT DATA, IT HAS TO BE INITIALIZED) */
    ami_v3f ***b,/* INDEPENDENT VECTOR OF THE ASSOCIATED LINEAR SYSTEM (INPUT DATA)*/
    ami_m3x3f ***A, /* MATRIX ASSOCIATED TO THE LINEAR SYSTEM (INPUT DATA) */
    float*** image_der_phi, // phi'(|grad(u)|) if phi'!=1, NULL otherwise
    ami_v3f alfa,/* WEIGHT OF THE REGULARIZATION TERM */
    float temporal_alpha, /* weight for the temporal regularization */
    float TOL_GaussSeidel,/* CONVERGENCE PARAMETER FOR THE GAUSS-SEIDEL SCHEME */
    int dim_x,int dim_y, /* IMAGE DIMENSIONS */
    int dim_p, // number of pairs in the sequence (number of images - 1)
    const PDEOpticFlowParam& param,
    unsigned char*** border_mask // mask of the points which displacement falls inside the image
    )
{
  int i,j,k,iter,kk;
  int dim_x_1=dim_x-1;
  int dim_y_1=dim_y-1;
  double b_aux[2];
  int mm,size=dim_x*dim_y*dim_p;
  ami_v3f ***h_2,*h_2p,*hp;
  float error_2,relative_error,error_1=100000.;
    //  int dim_z=1;

  register  int stepx=dim_y*dim_p;
  register  int stepy=dim_p;
  register ami_v3f* h_ptr;
  register ami_v3f* b_ptr;
  register float*   dp_ptr;
  register float    dp_xp,dp_xm,dp_yp,dp_ym,dp_zp,dp_zm;
  register float  *h_xp,*h_xm,*h_yp,*h_ym,*h_zp,*h_zm;


  /* WE ALLOCATE MEMORY AND COPY THE ORIGINAL DISPLACEMENT h*/
  ami_malloc3d(h_2,ami_v3f,dim_x,dim_y,dim_p);
  ami_copy_v3f(h,h_2,dim_x,dim_y,dim_p);
  h_2p=h_2[0][0];
  hp=h[0][0];


//    printf(" ami_horn_schunck_system_solution2D() begin \n");
  /* WE DO Niter ITERATIONS TO SOLVE THE HORN-SHUNCK SYSTEM */
  kk=0;
  for(iter=0;iter<Niter_GaussSeidel_2D;iter++) {
    if (iter%10==0) {
      if (iter==0)
	printf("Niter_GaussSeidel it: ");
      else
	printf("\b\b\b\b");
      printf("%4d",iter);
      fflush(stdout);
    }

    //    printf("%d %d \n",dim_x_1,dim_y_1);
    for(i=1;i<dim_x_1;i++) {
    for(j=1;j<dim_y_1;j++) {
      h_ptr = &h[i][j][0];
      b_ptr = &b[i][j][0];
      for(k=0;k<dim_p;k++,h_ptr++,b_ptr++) {
                // first fast conversion to 2D, to improve ...
	h_xp=h_ptr[ stepx];
	h_xm=h_ptr[-stepx];
	h_yp=h_ptr[ stepy];
	h_ym=h_ptr[-stepy];
	if (k==dim_p-1) h_zp=h_ptr[0];  else h_zp=h_ptr[1];
	if (k==0)       h_zm=h_ptr[0];  else h_zm=h_ptr[-1];
	if (param.GetSmoothingFunction()==phi_x) {
                  // first component
	  b_aux[0]= (*b_ptr)[0]+ alfa[0]*(h_xp[0] + h_xm[0] + h_yp[0] + h_ym[0]) + temporal_alpha * (h_zp[0] + h_zm[0]);
                  // second component
	  b_aux[1]= (*b_ptr)[1]+ alfa[1]*(h_xp[1] + h_xm[1] + h_yp[1] + h_ym[1]) + temporal_alpha * (h_zp[1] + h_zm[1]);
	} else {
	  dp_ptr= &image_der_phi[i][j][k];
	  dp_xp = dp_ptr[ stepx]+*dp_ptr;
	  dp_xm = dp_ptr[-stepx]+*dp_ptr;
	  dp_yp = dp_ptr[ stepy]+*dp_ptr;
	  dp_ym = dp_ptr[-stepy]+*dp_ptr;
	  if (k==dim_p-1) dp_zp = dp_ptr[0]+*dp_ptr; else dp_zp = dp_ptr[1]+*dp_ptr;
	  if (k==0)       dp_zm = dp_ptr[0]+*dp_ptr; else dp_zm = dp_ptr[-1]+*dp_ptr;
	  b_aux[0] = h_xp[0]*dp_xp + h_xm[0]*dp_xm +  h_yp[0]*dp_yp + h_ym[0]*dp_ym +
	      h_zp[0]*dp_zp + h_zm[0]*dp_zm;
	  b_aux[0] *= alfa[0]/2.0;
	  b_aux[0] += (*b_ptr)[0];
                  // second component
	  b_aux[1] = h_xp[1]*dp_xp + h_xm[1]*dp_xm + h_yp[1]*dp_yp + h_ym[1]*dp_ym +
	      h_zp[1]*dp_zp + h_zm[1]*dp_zm;
	  b_aux[1] *= alfa[1]/2.0;
	  b_aux[1] += (*b_ptr)[1];
	}
	ami_matriz_vector_2d(&A[i][j][k],b_aux,*h_ptr);
      } // k
    } // j
    } // i

    switch (param.GetBoundaryType()) {
      case boundary_border: 
            ami_boundary_vect_2d_t(h,dim_x,dim_y,dim_p); // pb with this boundary ???
            break;
      case boundary_point_outside: 
            ami_boundary_vect_2d_t(h,dim_x,dim_y,dim_p); // pb with this boundary ???
            ami_fill_border_mask_2d_t(h,dim_x,dim_y,dim_p,border_mask);
            break;
    }
    
    /* WE PERFORM THE ITERATION IN THE INVERSE WAY TO EQUILIBRATE */


    for(k=dim_p-1;k>=0;k--) {
    for(j=dim_y_1-1;j>0;j--) {
      h_ptr = &h[dim_x_1-1][j][k];
      b_ptr = &b[dim_x_1-1][j][k];
      for(i=dim_x_1-1;i>0;i--,h_ptr-=stepx,b_ptr-=stepx) {
                // first fast conversion to 2D, to improve ...
	h_xp=h_ptr[ stepx];
	h_xm=h_ptr[-stepx];
	h_yp=h_ptr[ stepy];
	h_ym=h_ptr[-stepy];
	if (k==dim_p-1) h_zp=h_ptr[0];  else h_zp=h_ptr[1];
	if (k==0)       h_zm=h_ptr[0];  else h_zm=h_ptr[-1];
	if (param.GetSmoothingFunction()==phi_x) {
                  // first component
	  b_aux[0]= (*b_ptr)[0]+ alfa[0]*(h_xp[0] + h_xm[0] + h_yp[0] +h_ym[0]) + temporal_alpha * ( h_zp[0] + h_zm[0]);
                  // second component
	  b_aux[1]= (*b_ptr)[1]+ alfa[1]*(h_xp[1] + h_xm[1] + h_yp[1] + h_ym[1]) + temporal_alpha *  (h_zp[1] + h_zm[1]);
	} else {
	  dp_ptr= &image_der_phi[i][j][k];
	  dp_xp = dp_ptr[ stepx]+*dp_ptr;
	  dp_xm = dp_ptr[-stepx]+*dp_ptr;
	  dp_yp = dp_ptr[ stepy]+*dp_ptr;
	  dp_ym = dp_ptr[-stepy]+*dp_ptr;
	  if (k==dim_p-1) dp_zp = dp_ptr[0]+*dp_ptr; else dp_zp = dp_ptr[1]+*dp_ptr;
	  if (k==0)       dp_zm = dp_ptr[0]+*dp_ptr; else dp_zm = dp_ptr[-1]+*dp_ptr;
	  b_aux[0] = h_xp[0]*dp_xp + h_xm[0]*dp_xm +  h_yp[0]*dp_yp + h_ym[0]*dp_ym;
      b_aux[0] *= alfa[0]/2.0;
      b_aux[0] += (h_zp[0]*dp_zp + h_zm[0]*dp_zm)*temporal_alpha/2.0;
	  b_aux[0] += (*b_ptr)[0];
                  // second component
	  b_aux[1] = h_xp[1]*dp_xp + h_xm[1]*dp_xm + h_yp[1]*dp_yp + h_ym[1]*dp_ym;
      b_aux[1] *= alfa[1]/2.0;
      b_aux[1] += (h_zp[1]*dp_zp + h_zm[1]*dp_zm)*temporal_alpha/2.0;
	  b_aux[1] += (*b_ptr)[1];
	}
	ami_matriz_vector_2d(&A[i][j][k],b_aux,*h_ptr);
      } // i
    } // j
    } // k

    switch (param.GetBoundaryType()) {
      case boundary_border: 
            ami_boundary_vect_2d_t(h,dim_x,dim_y,dim_p);
            break;
      case boundary_point_outside: 
            ami_boundary_vect_2d_t(h,dim_x,dim_y,dim_p);
            ami_fill_border_mask_2d_t(h,dim_x,dim_y,dim_p,border_mask);
            break;
    }

    /* WE COMPUTE THE ERROR TO STOP ITERATIONS */
    if((iter+1)%1==0) {

            // h2 = h2-h
      register float* h_2_ptr = (float*) h_2[0][0][0];
      register float* h_ptr   = (float*) h[0][0][0];
      register int size2 = size*3;
      for(mm=0;mm<size2;mm++,h_2_ptr++,h_ptr++) {
	(*h_2_ptr)-=(*h_ptr);
//	printf("h_2[%d] %f \n",mm,(*h_2_ptr));
      }

      error_2=ami_norm_2_vect_2d_t(h_2,dim_x,dim_y,dim_p);
            //printf("Error Gauss-Seidel iter=%d : error_1=%1.10f error_2=%1.10f \n",iter,error_1,error_2);
      relative_error=error_2/(error_1+0.0000000000000001);
            //printf("Relative Error Gauss-Seidel iter=%d =%1.15f\n",iter,relative_error);
      if(relative_error>(exp((double)-1000.*TOL_GaussSeidel)) || error_2<TOL_GaussSeidel)
	kk++;
      else
	kk=0;
      if(kk==3) {
//                printf("Niter_GaussSeidel = %d \n",iter);
	iter=Niter_GaussSeidel+1;
      } else {
	ami_copy_v3f(h,h_2,dim_x,dim_y,dim_p);
	error_1=error_2;
      }
    }
  }
  ami_free3d(h_2);

} //ami_optic_flow_system_solution_temporal()



/**
 * FUNCTION TO COMPUTE A 2D OPTIC FLOW FOR A SEQUENCE OF IMAGES USING TEMPORAL SMOOTHING
 */
int ami_optic_flow_2d_t(float ***image,ami_v3f ***u,
	                const PDEOpticFlowParam& param,
			int dim_x,int dim_y,int dim_t)
{
  int i,j,k,l,m,dim_x2,dim_y2;
  int mm,kk,kk_i[2];
  ami_m3x3f ***A;
  ami_v3f ***b;
  ami_v3f ***h;
  ami_v3f ***up=NULL,***up_2=NULL;
  float ***image_p_1,***image_p_2;
  float ***image_der_phi=NULL;

  // mask that includes de points which displacement
  // falls inside the image limits
  // values 0 (point not included) or 1 (point included)
  unsigned char ***border_mask=NULL;

  float error_2,relative_error,error_1=100000.;
  ami_v3f alfa2;
  float temporal_alpha;
  int dim_p = dim_t-1; // number of image pairs to associate (dim_t-1)

  const int* zoom_factor=param.GetZoomFactor();
  
  // No temporal zoom
  // check if dimensions are multiple of zoomfactor[i]^Nscales
  dim_x2=dim_x;
  dim_y2=dim_y;
  for(l=param.GetNbScales();l>1;l--) {
    if (((dim_x2/zoom_factor[0])*zoom_factor[0] !=dim_x2)||
        ((dim_y2/zoom_factor[1])*zoom_factor[1] !=dim_y2))
    {
      fprintf(stderr,"ami_horn_schunck_optic_flow_2d_t() \t each dimension i of the image has to be multiple of zoom_factor[i]^(Nscales-1) ... \n");
      return (1);
    }
    dim_x2/=zoom_factor[0];
    dim_y2/=zoom_factor[1];
  }
    
    
  /* WE GO TROUGH PIRAMIDAL SCHEME */
  for(l=param.GetNbScales();l>0;l--) {
    printf("--- Scale %d of %d\n",l,param.GetNbScales());
    /* WE INITIALIZE THE ERROR FOR CONVERGENCE CRITERIUM */
    error_1=1000000;
    /* WE ALLOCATE MEMORY*/
    ami_malloc3d(image_p_1,float,dim_x,dim_y,dim_t);
    ami_copy_3d(image,image_p_1, dim_x,dim_y,dim_t);
    /* WE ZOOM DOWN THE IMAGES */
    dim_x2=dim_x;
    dim_y2=dim_y;
    for(m=1;m<l;m++) {
      ami_malloc3d(image_p_2,float,dim_x2/zoom_factor[0],dim_y2/zoom_factor[1],dim_t);
      if(ami_zoom_down_2d_t(image_p_1,image_p_2,(float*)param.GetBeta(),(int*)zoom_factor,dim_x2,dim_y2,dim_t)!=0)
	return(-1);
      ami_free3d(image_p_1);
      image_p_1=image_p_2;
      dim_x2/=zoom_factor[0];
      dim_y2/=zoom_factor[1];
    }
    /* WE INITIALIZE THE FLOW */
    if(l==param.GetNbScales()) {
      kk_i[0]=dim_x/dim_x2;
      kk_i[1]=dim_y/dim_y2;
      ami_malloc3d(up,ami_v3f,dim_x2,dim_y2,dim_p);
      for(i=0;i<dim_x2;i++)
	for(j=0;j<dim_y2;j++)
	  for(k=0;k<dim_p;k++) {
	for(m=0;m<=2;m++) {
	  up[i][j][k][m]=u[i*kk_i[0]][j*kk_i[1]][k][m]/kk_i[m];
	}
	  }
    }
    /* WE ALLOCATE MEMORY FOR THE OTHER VECTOR WE NEED */
    ami_malloc3d(A,ami_m3x3f,dim_x2,dim_y2,dim_p);
    ami_malloc3d(b,ami_v3f  ,dim_x2,dim_y2,dim_p);
    printf(" allocation of h %d %d %d \n",dim_x2,dim_y2,dim_p);
    ami_malloc3d(h,ami_v3f  ,dim_x2,dim_y2,dim_p);
    if (param.GetSmoothingFunction()!=phi_x) ami_malloc3d(image_der_phi,float,dim_x2,dim_y2,dim_p);
    ami_malloc3d(border_mask,unsigned char,dim_x2,dim_y2,dim_p);

    // WE INITIALIZE THE NUMBER OF TRIALS FOR SCALE CONVERGENCE
    //   WE STOP THE ITERATIONS AFTER 3 CONSECUTIVE CONVERGENCE VERIFICATION
    kk=0;
    /* WE GO TRHOUGH SCALE ITERATIONS */
    for(mm=0;mm<Niter_Scales;mm++) {
      printf("-- iteration %d \n",mm+1);
      /* WE INITIALIZE AN AUXILIARY VARIABLE FOR THE REGULARIZATION TERM WEIGHT */
      alfa2[0]=param.GetAlpha()[0];
      alfa2[1]=param.GetAlpha()[1];
      temporal_alpha = param.GetTemporalAlpha();
 
      // compute the border_mask image
      ami_create_border_mask_2d_t(border_mask,up,dim_x2,dim_y2,dim_p,param.GetSymmetric());
/*
      float x1,y1;
      float margin=1.0;
      for(i=0;i<dim_x2;i++) 
        for(j=0;j<dim_y2;j++) 
          for(k=0;k<dim_p;k++) {
        x1 = (float) i + up[i][j][k][0];
        y1 = (float) j + up[i][j][k][1];
        border_mask[i][j][k] = (x1>margin)&&(y1>margin)&&(x1<=dim_x-1-margin)&&(y1<dim_y-1-margin);
      }
*/
     /* WE INITIALIZE TO ZERO THE LOCAL DISPLACEMENT */
      //	    printf("dimensions %d %d %d \n",dim_x2,dim_y2,dim_z2);
      //printf("setting h to 0 \n");
      //bzero(h[0][0],dim_x2*dim_y2*dim_p*sizeof(ami_v3f));
      memset(h[0][0],0,dim_x2*dim_y2*dim_p*sizeof(ami_v3f));
/*    for(i=0;i<dim_x2;i++)
	  for(j=0;j<dim_y2;j++)
	  for(k=0;k<dim_p;k++)
	    for(m=0;m<2;m++)
	      h[i][j][k][m]=0;
*/
      /* WE SOLVE THE HORN-SHNUCK EQUATION SYSTEM */
      //printf("\ngradient_type = %d \n",gradient_type);
      switch (param.GetGradientType()) {
	case 0:
	  if (!param.GetSymmetric())	  
	  ami_optic_flow_system_computation_v0_temporal(image_p_1,up,b,A,alfa2,&temporal_alpha,dim_x2,dim_y2,dim_t,param);
	  else
  	  ami_optic_flow_system_computation_symmetric_temporal(image_p_1,up,b,A,image_der_phi,alfa2,&temporal_alpha,dim_x2,dim_y2,dim_t,param);
	  break;
	default:
	  fprintf(stderr,"No temporal version for this gradient type \n");
      }
//      printf("Resolving the system \n");
      ami_optic_flow_system_solution_temporal(h,b,A,image_der_phi,alfa2,temporal_alpha,
					      param.GetToleranceGaussSeidel(),
					      dim_x2,dim_y2,dim_p,
					     param, border_mask);

      /* WE COMPUTE THE ERROR TO STOP ITERATIONS */
      if((mm+1)%1==0) {
	error_2=ami_norm_2_vect_2d_t(h,dim_x2,dim_y2,dim_p);
                //printf("Error Scale Iteration iter =%d : error_1=%1.10f error_2=%1.10f \n",mm,error_1,error_2);
	relative_error=error_2/(error_1+0.0000000000000001);
	printf("\n Scale=%d iter Scale =%d h_displacement=%1.10f relative error=%1.10f\n",l,mm,error_2,relative_error);
                //scanf("%d",&ii);
	if(relative_error>(exp((double) -100.*param.GetToleranceScales())) || 
		  error_2<param.GetToleranceScales())
	  kk++;
	else
	  kk=0;
	if(relative_error>MAX_RELATIVE_ERROR)
	  kk=3;
	if(kk==3) {
	  mm=Niter_Scales+1;
	} else {
	  error_1=error_2;
	}
      }
      /* WE ACTUALIZE up */
      if(kk<3) {
	for(i=0;i<dim_x2;i++)
	  for(j=0;j<dim_y2;j++)
	    for(k=0;k<dim_p;k++) {
	  for(m=0;m<=2;m++)
	    up[i][j][k][m]+=h[i][j][k][m];
 	    }
      }
   //   mm=Niter_Scales+1;

    }

    /*IF WE HAVE NOT ARRIVED TO THE FINER SCALE WE ZOOM UP up */
    if(l>1) {
      ami_malloc3d(up_2,ami_v3f,zoom_factor[0]*dim_x2,zoom_factor[1]*dim_y2,dim_p);
      ami_zoom_up_vect_2d_t_flow(up,up_2,(float*)param.GetBeta(),(int*)zoom_factor,dim_x2,dim_y2,dim_p);
      ami_free3d(up);
      up=up_2;
    }
    /* WE FREE THE MEMORY */
    ami_free3d(A);
    ami_free3d(b);
    ami_free3d(h);
    ami_free3d(image_p_1);
    if (param.GetSmoothingFunction()!=phi_x) ami_free3d(image_der_phi);
    ami_free3d(border_mask);
  }
  /* WE COPY THE TEMPORAL DISPLACEMENT TO THE MAIN DISPLACEMENT */
  ami_copy_v3f(up,u,dim_x,dim_y,dim_p);
  ami_free3d(up);
  return(0);
  
} // ami_optic_flow_2d_t()



