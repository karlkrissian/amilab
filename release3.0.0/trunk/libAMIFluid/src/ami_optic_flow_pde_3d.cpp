
#include "ami_optic_flow_pde_3d.h"
#include <string.h>

#define Niter_GaussSeidel 10000
#define Niter_GaussSeidel_2D 5000
#define Niter_Scales 100
#define MAX_RELATIVE_ERROR 10



/**
 *  COMPUTATION OF 3D IMAGE GRADIENT 
 */
void ami_compute_grad_3d(float ***image,ami_v3f ***grad_image,int dim_x,int dim_y,int dim_z,const PDEOpticFlowParam& param)
{
  switch(param.GetGradientComputation()) {
    case grad_max:
      ami_grad_3d(image,grad_image,dim_x,dim_y,dim_z);
      break;
    case grad_inv:
      ami_grad_3d_3x3x3(image,grad_image,dim_x,dim_y,dim_z);
      break;
  }
}

/**
 * Warping of a scalar image using a vector field
 */
void ami_warpimage_3df(float ***image,ami_v3f ***u,float ***image_output,int dim_x,int dim_y,int dim_z,const PDEOpticFlowParam& param)
{
printf("ami_warpimage_3df()\n");
  switch(param.GetInterpolationType()) {
    case linear:
        ami_image_interpolation_3df(image,u,image_output,dim_x,dim_y,dim_z);
        break;
    case spline:
            ami_image_splinewarp(image,u,image_output,dim_x,dim_y,dim_z,
                    param.GetSplineDegree());
            printf("ami_image_splinewarp()\n");
        break;
  }
}

/**
 * FUNCTION TO BUILD THE HORN-SHUNCK EQUATION SYSTEM 
 * WE USE AS GRADIENT IMPLEMENTATION AN UPWIND FOLLOWING THE SIGN 
 * OF image_1 AND WARPED image_2 
*/

void ami_horn_schunck_system_computation_v1(
    float ***image_1,/* FIRST IMAGE TO COMPUTE THE FLOW (INPUT DATA) */
    float ***image_2,/* SECOND IMAGE TO COMPUTE THE FLOW (INPUT DATA) */
    ami_v3f ***u,/* CURRENT FLOW (IT HAS TO BE INITIALIZED (INPUT DATA) */
    ami_v3f ***b,/* INDEPENDENT VECTOR OF THE ASSOCIATED LINEAR SYSTEM (OUTPUT DATA) */
    ami_m3x3f ***A,/* MATRIX OF THE ASSOCIATED LINEAR SYSTEM (INPUT DATA) */
    ami_v3f alfa,/* WEIGHT OF REGULARIZATION TERM (INPUT/OUTPUT DATA) (IT IS NORMALIZED USING
    	 THE NORM OF THE GRADIENT OF THE SECOND IMAGE */
    int dim_x,int dim_y,int dim_z, /* IMAGE DIMENSIONS */
    const PDEOpticFlowParam& param)
{
    int i,j,k,l,m,n;
    ami_v3f ***grad_image_2,***grad_image_2_i,***grad_image_1;
    float ***image_2_i,norm,***image_1_p,***image_2_p;
    int image_dimension;
	
    if (dim_z>1) image_dimension=3; else image_dimension=2;
    double** B;
    double** B_1;
    ami_malloc2d(B,double,image_dimension,image_dimension);
    ami_malloc2d(B_1,double,image_dimension,image_dimension);
	    
    /* WE ALLOCATE MEMORY */
    ami_malloc3d(grad_image_2,ami_v3f,dim_x,dim_y,dim_z);
    ami_malloc3d(grad_image_2_i,ami_v3f,dim_x,dim_y,dim_z);
    ami_malloc3d(image_2_i,float,dim_x,dim_y,dim_z);
    ami_malloc3d(grad_image_1,ami_v3f,dim_x,dim_y,dim_z);
    ami_malloc3d(image_2_p,float,dim_x,dim_y,dim_z);
    ami_malloc3d(image_1_p,float,dim_x,dim_y,dim_z);
    /* WE COPY IMAGE 1 AND 2 */
    ami_copy_3d(image_1,image_1_p,dim_x,dim_y,dim_z);
    ami_copy_3d(image_2,image_2_p,dim_x,dim_y,dim_z);
    /* WE FILTER THE IMAGES TO COMPUTE THE GRADIENT */
	{
	float* beta = new float[image_dimension];
    for(l=0;l<image_dimension;l++)  beta[l]=0.25;
    ami_convolution_3d(image_1_p,beta,dim_x,dim_y,dim_z);
    ami_convolution_3d(image_2_p,beta,dim_x,dim_y,dim_z);
	delete [] beta;
	}

    /* WE COMPUTE THE GRADIENT OF CONVOLVED IMAGE 1 AND 2 */
    ami_compute_grad_3d(image_1_p,grad_image_1,dim_x,dim_y,dim_z,param);
    ami_compute_grad_3d(image_2_p,grad_image_2,dim_x,dim_y,dim_z,param);
    
    if (param.GetNormalizeAlpha()) {
      /* WE NORMALIZE THE DIFFUSION WEIGHT */
      norm=ami_norm_2_v3f(grad_image_2,dim_x,dim_y,dim_z);
      for(l=0;l<image_dimension;l++)
          alfa[l]=(alfa[l])*(norm+param.GetAlphaNormEpsilon())
	  *(norm+param.GetAlphaNormEpsilon());
    }
	
    /* WE INTERPOLATE THE GRADIENT AFTER CURRENT FLOW DISPLACEMENT */
    ami_image_interpolation_v3f(grad_image_2,u,grad_image_2_i,dim_x,dim_y,dim_z);
    /* WE INTERPOLATE THE IMAGE 2 AFTER CURRENT FLOW DISPLACEMENT */
    ami_warpimage_3df(image_2,u,image_2_i,dim_x,dim_y,dim_z,param);
    /* WE COMPUTE THE MATRIX AND VECTORS ASSOCIATED TO HORN AND SHUCNK METHOD */
    for(i=0;i<dim_x;i++) {
        for(j=0;j<dim_y;j++) {
            for(k=0;k<dim_z;k++) {
                if((image_1[i][j][k]-image_2_i[i][j][k])>0) {
                    /* WE COMPUTE THE VECTOR b OF HORN-SHUNCK SYSTEM */
                    for(l=0;l<image_dimension;l++)
                        b[i][j][k][l]=(image_1[i][j][k]-image_2_i[i][j][k])*grad_image_2_i[i][j][k][l];
                    /* WE COMPUTE THE MATRIX OF THE HORN-SHUNK SYSTEM */
                    for(m=0;m<image_dimension;m++) {
                        for(n=0;n<image_dimension;n++)
                            B[m][n]=grad_image_2_i[i][j][k][m]*grad_image_2_i[i][j][k][n];
                        B[m][m]+=2*image_dimension*(alfa[m]);
                    }
		    ami_inversa((double**)B,(double**)B_1,image_dimension);
                    for(m=0;m<image_dimension;m++)
                        for(n=0;n<image_dimension;n++)
                            A[i][j][k][m][n]=B_1[m][n];
                } else {
                    /* WE COMPUTE THE VECTOR b OF HORN-SHUNCK SYSTEM */
                    for(l=0;l<image_dimension;l++)
                        b[i][j][k][l]=(image_1[i][j][k]-image_2_i[i][j][k])*grad_image_1[i][j][k][l];
                    /* WE COMPUTE THE MATRIX OF THE HORN-SHUNK SYSTEM */
                    for(m=0;m<image_dimension;m++) {
                        for(n=0;n<image_dimension;n++)
                            B[m][n]=grad_image_1[i][j][k][m]*grad_image_1[i][j][k][n];
                        B[m][m]+=2*image_dimension*(alfa[m]);
                    }
		    ami_inversa((double**)B,(double**)B_1,image_dimension);
                    for(m=0;m<image_dimension;m++)
                        for(n=0;n<image_dimension;n++)
                            A[i][j][k][m][n]=B_1[m][n];

                }
            }
        }
    }
    /* WE FREE THE MEMORY */
    ami_free3d(grad_image_2);
    ami_free3d(grad_image_2_i);
    ami_free3d(image_2_i);
    ami_free3d(grad_image_1);
    ami_free3d(image_2_p);
    ami_free3d(image_1_p);
    
    ami_free2d(B);
    ami_free2d(B_1);
}
/**
* FUNCTION TO BUILD THE HORN-SHUNCK EQUATION SYSTEM 
*/
/* WE USE AS GRADIENT IMPLEMENTATION AN AVERAGE OF image_1 AND WARPED image_2 GRADIENT */
void ami_horn_schunck_system_computation_v2(
    float ***image_1,/* FIRST IMAGE TO COMPUTE THE FLOW (INPUT DATA) */
    float ***image_2,/* SECOND IMAGE TO COMPUTE THE FLOW (INPUT DATA) */
    ami_v3f ***u,/* CURRENT FLOW (IT HAS TO BE INITIALIZED (INPUT DATA) */
    ami_v3f ***b,/* INDEPENDENT VECTOR OF THE ASSOCIATED LINEAR SYSTEM (OUTPUT DATA) */
    ami_m3x3f ***A,/* MATRIX OF THE ASSOCIATED LINEAR SYSTEM (INPUT DATA) */
    ami_v3f alfa,/* WEIGHT OF REGULARIZATION TERM (INPUT/OUTPUT DATA) (IT IS NORMALIZED USING
    	 THE NORM OF THE GRADIENT OF THE SECOND IMAGE */
    int dim_x,int dim_y,int dim_z, /* IMAGE DIMENSIONS */
    const PDEOpticFlowParam& param)
{
    int i,j,k,l,m,n;
    ami_v3f ***grad_image_2,***grad_image_2_i,***grad_image_1;
    float ***image_2_i,norm,***image_1_p,***image_2_p;
    int image_dimension;

    if (dim_z>1)
        image_dimension=3;
    else
        image_dimension=2;
    double** B;
    double** B_1;
    ami_malloc2d(B,  double,image_dimension,image_dimension);
    ami_malloc2d(B_1,double,image_dimension,image_dimension);

    /* WE ALLOCATE MEMORY */
    ami_malloc3d(grad_image_2,ami_v3f,dim_x,dim_y,dim_z);
    ami_malloc3d(grad_image_2_i,ami_v3f,dim_x,dim_y,dim_z);
    ami_malloc3d(image_2_i,float,dim_x,dim_y,dim_z);
    ami_malloc3d(grad_image_1,ami_v3f,dim_x,dim_y,dim_z);
    ami_malloc3d(image_2_p,float,dim_x,dim_y,dim_z);
    ami_malloc3d(image_1_p,float,dim_x,dim_y,dim_z);
    /* WE COPY IMAGE 1 AND 2 */
    ami_copy_3d(image_1,image_1_p,dim_x,dim_y,dim_z);
    ami_copy_3d(image_2,image_2_p,dim_x,dim_y,dim_z);
    /* WE FILTER THE IMAGES TO COMPUTE THE GRADIENT */
	{
        float* beta =new float[image_dimension];
	
        for(l=0;l<image_dimension;l++) beta[l]=0.25;
        ami_convolution_3d(image_1_p,beta,dim_x,dim_y,dim_z);
        ami_convolution_3d(image_2_p,beta,dim_x,dim_y,dim_z);
		delete [] beta;
	}
    /* WE COMPUTE THE GRADIENT OF CONVOLVED IMAGE 1 AND 2 */
    ami_compute_grad_3d(image_1_p,grad_image_1,dim_x,dim_y,dim_z,param);
    ami_compute_grad_3d(image_2_p,grad_image_2,dim_x,dim_y,dim_z,param);
    
    if (param.GetNormalizeAlpha())
    {
      /* WE NORMALIZE THE DIFFUSION WEIGHT */
      norm=ami_norm_2_v3f(grad_image_2,dim_x,dim_y,dim_z);
      for(l=0;l<image_dimension;l++)
          alfa[l]=(alfa[l])*(norm+param.GetAlphaNormEpsilon())*(norm+param.GetAlphaNormEpsilon());
    }
    /* WE INTERPOLATE THE GRADIENT AFTER CURRENT FLOW DISPLACEMENT */
    ami_image_interpolation_v3f(grad_image_2,u,grad_image_2_i,dim_x,dim_y,dim_z);
    /* WE INTERPOLATE THE IMAGE 2 AFTER CURRENT FLOW DISPLACEMENT */
    ami_warpimage_3df(image_2,u,image_2_i,dim_x,dim_y,dim_z,param);
    /* WE COMPUTE THE MATRIX AND VECTORS ASSOCIATED TO HORN AND SHUCNK METHOD */
    for(i=0;i<dim_x;i++) {
        for(j=0;j<dim_y;j++) {
            for(k=0;k<dim_z;k++) {
                /* WE COMPUTE THE VECTOR b OF HORN-SHUNCK SYSTEM */
                for(l=0;l<image_dimension;l++)
                    b[i][j][k][l]=(image_1[i][j][k]-image_2_i[i][j][k])*
                                  0.5*(grad_image_2_i[i][j][k][l]+grad_image_1[i][j][k][l]);
                /* WE COMPUTE THE MATRIX OF THE HORN-SHUNK SYSTEM */
                for(m=0;m<image_dimension;m++) {
                    for(n=0;n<image_dimension;n++)
                        B[m][n]=0.25*(grad_image_2_i[i][j][k][m]+grad_image_1[i][j][k][m])*
                                (grad_image_2_i[i][j][k][n]+grad_image_1[i][j][k][n]);
                    B[m][m]+=2*image_dimension*(alfa[m]);
                }
		
		if (image_dimension==3) ami_inversa3x3((double**)B,(double**)B_1);
		if (image_dimension==2) ami_inversa2x2((double**)B,(double**)B_1);
		for(m=0;m<image_dimension;m++)
                    for(n=0;n<image_dimension;n++)
                        A[i][j][k][m][n]=B_1[m][n];
            }
        }
    }
    /* WE FREE THE MEMORY */
    ami_free3d(grad_image_2);
    ami_free3d(grad_image_2_i);
    ami_free3d(image_2_i);
    ami_free3d(grad_image_1);
    ami_free3d(image_2_p);
    ami_free3d(image_1_p);
    
    ami_free2d(B);
    ami_free2d(B_1);
}

/**
* FUNCTION TO BUILD THE HORN-SHUNCK EQUATION SYSTEM                         
*/
void ami_horn_schunck_system_computation_v0(
    float ***image_1,/* FIRST IMAGE TO COMPUTE THE FLOW (INPUT DATA) */
    float ***image_2,/* SECOND IMAGE TO COMPUTE THE FLOW (INPUT DATA) */
    ami_v3f ***u,/* CURRENT FLOW (IT HAS TO BE INITIALIZED (INPUT DATA) */
    ami_v3f ***b,/* INDEPENDENT VECTOR OF THE ASSOCIATED LINEAR SYSTEM (OUTPUT DATA) */
    ami_m3x3f ***A,/* MATRIX OF THE ASSOCIATED LINEAR SYSTEM (INPUT DATA) */
    ami_v3f alfa,/* WEIGHT OF REGULARIZATION TERM (INPUT/OUTPUT DATA) (IT IS NORMALIZED USING
    	 THE NORM OF THE GRADIENT OF THE SECOND IMAGE */
    int dim_x,int dim_y,int dim_z, /* IMAGE DIMENSIONS */
    const PDEOpticFlowParam& param ) 
{

	printf("ami_horn_schunck_system_computation_v0()\n");
	double sum_A=0;
	double sum_b=0;

	int i,j,k,l,m,n;
	ami_v3f ***b_s; // solenoidal projection of b
	ami_v3f ***grad_image_2;
        ami_v3f ***grad_image_3;
	float ***image_2i,norm;
	int image_dimension;

	if (dim_z>1)
		image_dimension=3;
	else
		image_dimension=2;

	double** B;
	double** B_1;
	ami_malloc2d(B,  double,image_dimension,image_dimension);
	ami_malloc2d(B_1,double,image_dimension,image_dimension);
    
    double div;
    float u_xp=0.0,u_xm=0.0,u_yp=0.0,u_ym=0.0,u_zp=0.0,u_zm=0.0,u_0; // value of u for the current coordinate at the current point and at its direct neighbors
    
    
    /* WE ALLOCATE MEMORY */
    ami_malloc3d(b_s,ami_v3f,dim_x,dim_y,dim_z);
    ami_malloc3d(grad_image_2,ami_v3f,dim_x,dim_y,dim_z);
    ami_malloc3d(grad_image_3,ami_v3f,dim_x,dim_y,dim_z);
    ami_malloc3d(image_2i,float,dim_x,dim_y,dim_z);
    

    if (param.GetGradientComputation()!=grad_spline)
    {
        /* WE COMPUTE THE GRADIENT OF IMAGE 2*/
        if (param.GetSmoothGradient())
        {
            // we use image_2i to store temporary the smoothed images
            ami_copy_3d(image_2,image_2i,dim_x,dim_y,dim_z);
            // WE FILTER THE IMAGES TO COMPUTE THE GRADIENT
			{
	        float* beta =new float[image_dimension];
			for(l=0;l<image_dimension;l++) beta[l]=0.25;
			ami_convolution_3d(image_2i,beta,dim_x,dim_y,dim_z);
			ami_compute_grad_3d(image_2i,grad_image_2,dim_x,dim_y,dim_z,param);
			delete [] beta;
			}
        }
        else
        {
            ami_compute_grad_3d(image_2,grad_image_2,dim_x,dim_y,dim_z,param);
        }
        /* WE INTERPOLATE THE GRADIENT AFTER CURRENT FLOW DISPLACEMENT */
        ami_image_interpolation_v3f(grad_image_2,u,grad_image_3,dim_x,dim_y,dim_z);
    }
    else
    {
        ami_compute_splinegrad_v3f(image_2,u,grad_image_3,dim_x,dim_y,dim_z);
    }

    if (param.GetNormalizeAlpha()) {
      /* WE NORMALIZE THE DIFFUSION WEIGHT */
      norm=ami_norm_2_v3f(grad_image_3,dim_x,dim_y,dim_z);
      printf("norm= %f \n",norm);
	  // printf("** Grad norm = %f\n",norm);
      for(l=0;l<image_dimension;l++)
          alfa[l]=(alfa[l])*(norm+param.GetAlphaNormEpsilon())*(norm+param.GetAlphaNormEpsilon());
    }

    /* WE INTERPOLATE THE IMAGE 2 AFTER CURRENT FLOW DISPLACEMENT */
    ami_warpimage_3df(image_2,u,image_2i,dim_x,dim_y,dim_z,param);
    /* WE COMPUTE THE MATRIX AND VECTORS ASSOCIATED TO HORN AND SHUCNK METHOD */
    for(i=0;i<dim_x;i++) {
        for(j=0;j<dim_y;j++) {
            for(k=0;k<dim_z;k++) {
                /* WE COMPUTE THE VECTOR b OF HORN-SHUNCK SYSTEM */
	      for(l=0;l<image_dimension;l++) {
                    b[i][j][k][l]=(image_1[i][j][k]-image_2i[i][j][k])*grad_image_3[i][j][k][l];
	  // if the smoothing constraint is global, add alfa*div(u)
      //printf("global smoothing = %d\n",param.GetGlobalConstraint());
		    if (param.GetGlobalConstraint()) {
          //fprintf(stderr,"applying global smoothing \n");
		  u_0 =u[i][j][k][l];
		  u_xp=(i<dim_x-1)?u[i+1][j][k][l]:u[dim_x-1][j][k][l];
		  u_xm=(i>0)      ?u[i-1][j][k][l]:u[0]      [j][k][l];
		  u_yp=(j<dim_y-1)?u[i][j+1][k][l]:u[i][dim_y-1][k][l];
		  u_ym=(j>0)      ?u[i][j-1][k][l]:u[i][0]      [k][l];
		  if  (image_dimension==3) {
		    u_zp=(k<dim_z-1)?u[i][j][k+1][l]:u[i][j][dim_z-1][l];
		    u_zm=(k>0)      ?u[i][j][k-1][l]:u[i][j][0      ][l];
		  }
		  switch (param.GetSmoothingFunction()) {
		    case phi_x:
		      div = u_xp+u_xm+u_yp+u_ym-4*u_0;
		      if  (image_dimension==3) 
			div += u_zp+u_zm-2*u_0;
		      b[i][j][k][l] += alfa[l]*div;
		      break;
		    case phi_sqrt_x:
		      printf("standard OF with sqrt as smoothing function not yet available \n");
/*      div  = (u_xp-u_0)*(dp_xp+dp) - (u_0-u_xm)*(dp+dp_xm);
		      div += (u_yp-u_0)*(dp_yp+dp) - (u_0-u_ym)*(dp+dp_ym);
		      if (image_dimension==3)
			div += (u_zp-u_0)*(dp_zp+dp) - (u_0-u_zm)*(dp+dp_zm);
		      div /= 2.0;
		      b[i][j][k][l] += alfa[l]*div;
		      */
		      break;
		  } // switch SmoothingPhi
		} // if global_constraint
                sum_b += b[i][j][k][l]*b[i][j][k][l];
	      } // for l
                /* WE COMPUTE THE MATRIX OF THE HORN-SHUNK SYSTEM */
                for(m=0;m<image_dimension;m++) {
                    for(n=0;n<image_dimension;n++)
                        B[m][n]=grad_image_3[i][j][k][m]*grad_image_3[i][j][k][n];
                    B[m][m]+=2*image_dimension*(alfa[m]);
                }
		ami_inversa((double**)B,(double**)B_1,image_dimension);
                for(m=0;m<image_dimension;m++)
                    for(n=0;n<image_dimension;n++)
                        A[i][j][k][m][n]=B_1[m][n];
                        sum_A+=A[i][j][k][m][n]*A[i][j][k][m][n];
           } // k
        } // j
    } // i

    
    if (param.GetEnergyConstraint())  {
      int scales_solenoidal = 1;
      // replace de gradient of the energy at iteration n
      // (stored in vector b) by its solenoidal projection
      int* zoom_factor=(int*)param.GetZoomFactor();
      // check if 2D, the no zoom in Z
      if (dim_z==1) zoom_factor[2]=1;
      ami_copy_v3f(b,b_s,dim_x,dim_y,dim_z);
      ami_solenoidal_proyeccion_3d(b_s,(float*)param.GetBeta(),zoom_factor,
			5*10e-8,scales_solenoidal,
                        param.GetAEnergyProj(),
                        dim_x,dim_y,dim_z);
      printf("       (solenoidal) scales=%d\n",scales_solenoidal);
      float norm_b  = ami_norm_2_v3f(b,  dim_x,dim_y,dim_z);
      float norm_bs = ami_norm_2_v3f(b_s,dim_x,dim_y,dim_z);
      printf(" norm2(b) = %f \t norm2(b_s) = %f \n",norm_b,norm_bs);
      ami_copy_v3f(b_s,b,dim_x,dim_y,dim_z);
    }

    /* WE FREE THE MEMORY */
    ami_free3d(b_s);
    ami_free3d(grad_image_2);
    ami_free3d(grad_image_3);
    ami_free3d(image_2i);
    
    ami_free2d(B);
    ami_free2d(B_1);

//  printf("sum_b %f sum_A %f \n",sum_b/(1.0*dim_x*dim_y),sum_A/(1.0*dim_x*dim_y));
}


/**
 *  FUNCTION TO BUILD THE HORN-SHUNCK EQUATION SYSTEM
 * including the Hessian matrix
*/
void ami_horn_schunck_system_computation_v3(
    float ***image_1,/* FIRST IMAGE TO COMPUTE THE FLOW (INPUT DATA) */
    float ***image_2,/* SECOND IMAGE TO COMPUTE THE FLOW (INPUT DATA) */
    ami_v3f ***u,/* CURRENT FLOW (IT HAS TO BE INITIALIZED (INPUT DATA) */
    ami_v3f ***b,/* INDEPENDENT VECTOR OF THE ASSOCIATED LINEAR SYSTEM (OUTPUT DATA) */
    ami_m3x3f ***A,/* MATRIX OF THE ASSOCIATED LINEAR SYSTEM (INPUT DATA) */
    ami_v3f alfa,/* WEIGHT OF REGULARIZATION TERM (INPUT/OUTPUT DATA) (IT IS NORMALIZED USING
    THE NORM OF THE GRADIENT OF THE SECOND IMAGE */
    int dim_x,int dim_y,int dim_z, /* IMAGE DIMENSIONS */
    const PDEOpticFlowParam& param)
{
  int i,j,k,l,m,n;
  ami_v3f ***grad_image_2,***grad_image_3;
  float ***image_2i,norm;
  int image_dimension;
  ami_m3x3f *** hessian_image; /* Hessian matrix estimated at x+u */
  ami_m3x3f Hi; /* interpolated Hessian at x+u */
      
  if (dim_z>1)
    image_dimension=3;
  else
    image_dimension=2;
  
  double** B;
  double** B_1;
  ami_malloc2d(B,  double,image_dimension,image_dimension);
  ami_malloc2d(B_1,double,image_dimension,image_dimension);
    
    
  /* WE ALLOCATE MEMORY */
  ami_malloc3d(grad_image_2,ami_v3f,dim_x,dim_y,dim_z);
  ami_malloc3d(grad_image_3,ami_v3f,dim_x,dim_y,dim_z);
  ami_malloc3d(image_2i,float,dim_x,dim_y,dim_z);
  
  ami_malloc3d(hessian_image,ami_m3x3f,dim_x,dim_y,dim_z);
  
  /* WE COMPUTE THE GRADIENT OF IMAGE 2*/
  ami_compute_grad_3d(image_2,grad_image_2,dim_x,dim_y,dim_z,param);
  
  /* WE COMPUTE THE HESSIAN IMAGE 2 */
  ami_hessian_3d(image_2,hessian_image,dim_x,dim_y,dim_z);
  
  if (param.GetNormalizeAlpha()) {
    /* WE NORMALIZE THE DIFFUSION WEIGHT */
    norm=ami_norm_2_v3f(grad_image_2,dim_x,dim_y,dim_z);
    for(l=0;l<image_dimension;l++)
      alfa[l]=(alfa[l])*(norm+param.GetAlphaNormEpsilon())*(norm+param.GetAlphaNormEpsilon());
  }
  /* WE INTERPOLATE THE GRADIENT AFTER CURRENT FLOW DISPLACEMENT */
  ami_image_interpolation_v3f(grad_image_2,u,grad_image_3,dim_x,dim_y,dim_z);
  /* WE INTERPOLATE THE IMAGE 2 AFTER CURRENT FLOW DISPLACEMENT */
  ami_warpimage_3df(image_2,u,image_2i,dim_x,dim_y,dim_z,param);
  /* WE COMPUTE THE MATRIX AND VECTORS ASSOCIATED TO HORN AND SHUCNK METHOD */
  for(i=0;i<dim_x;i++) {
    for(j=0;j<dim_y;j++) {
      for(k=0;k<dim_z;k++) {
	/* WE COMPUTE THE VECTOR b OF HORN-SHUNCK SYSTEM */
	for(l=0;l<image_dimension;l++)
	  b[i][j][k][l]=(image_1[i][j][k]-image_2i[i][j][k])*grad_image_3[i][j][k][l];
	
	/* We compute the Hessian matrix at x+u */
	ami_hessian_interpolation(hessian_image,u,&Hi,i,j,k,dim_x,dim_y,dim_z);
	
        /* WE COMPUTE THE MATRIX OF THE HORN-SHUNK SYSTEM */
	for(m=0;m<image_dimension;m++) {
	  for(n=0;n<image_dimension;n++) {
	    B[m][n] =grad_image_3[i][j][k][m]*grad_image_3[i][j][k][n];
	    B[m][n]-=(image_1[i][j][k]-image_2i[i][j][k])*Hi[m][n];
	  }
	  B[m][m]+=2*image_dimension*(alfa[m]);
	}
	if (ami_inversa((double**)B,(double**)B_1,image_dimension)==-1) {
	  for(m=0;m<image_dimension;m++) {
	    for(n=0;n<image_dimension;n++) {
	      B[m][n] =grad_image_3[i][j][k][m]*grad_image_3[i][j][k][n];
	    }
	    B[m][m]+=2*image_dimension*(alfa[m]);
	  }
	  ami_inversa((double**)B,(double**)B_1,image_dimension);
	}
	for(m=0;m<image_dimension;m++)
	  for(n=0;n<image_dimension;n++)
	    A[i][j][k][m][n]=B_1[m][n];
      }
    }
  }
  /* WE FREE THE MEMORY */
  ami_free3d(grad_image_2);
  ami_free3d(grad_image_3);
  ami_free3d(image_2i);
  ami_free3d(hessian_image);
  
  ami_free2d(B);
  ami_free2d(B_1);
  
}

/**
 *  FUNCTION TO BUILD THE HORN-SHUNCK EQUATION SYSTEM
 *  with the symmetric formulation
 */
void ami_horn_schunck_system_computation_symmetric(
    float ***image_1,/* FIRST IMAGE TO COMPUTE THE FLOW (INPUT DATA) */
    float ***image_2,/* SECOND IMAGE TO COMPUTE THE FLOW (INPUT DATA) */
    ami_v3f ***u,/* CURRENT FLOW (IT HAS TO BE INITIALIZED (INPUT DATA) */
    ami_v3f ***b,/* INDEPENDENT VECTOR OF THE ASSOCIATED LINEAR SYSTEM (OUTPUT DATA) */
    ami_m3x3f ***A,/* MATRIX OF THE ASSOCIATED LINEAR SYSTEM (INPUT DATA) */
    float *** image_der_phi, // image of phi'(|grad(u)|^2), if phi'==1, returns NULL
    ami_v3f alfa,/* WEIGHT OF REGULARIZATION TERM (INPUT/OUTPUT DATA) (IT IS NORMALIZED USING
    THE NORM OF THE GRADIENT OF THE SECOND IMAGE */
    int dim_x,int dim_y,int dim_z, /* IMAGE DIMENSIONS */
    const PDEOpticFlowParam& param) 
{
  int i,j,k,l,m,n;
  ami_v3f ***grad_image_1;
  ami_v3f ***grad_image_2;
  ami_v3f ***grad_image_average;
  ami_v3f ***grad_image_1i;
  ami_v3f ***grad_image_2i;
  float ***image_1i; // interpolated image 1 at x+u
  float ***image_2i; //     ...            2 ...
  float norm;
  int image_dimension;
  float u_xp=0.0,u_xm=0.0,u_yp=0.0,u_ym=0.0,u_zp=0.0,u_zm=0.0,u_0; // value of u for the current coordinate at the current point and at its direct neighbors
  double div,tmp;
  double grad2_u;
  float dp_xp=0.0,dp_xm=0.0,dp_yp=0.0,dp_ym=0.0,dp_zp=0.0,dp_zm=0.0,dp=0.0; // derivative of phi´ at the current point and at its direct neighbors
  
  //  ami_m3x3f *** hessian_image; /* Hessian matrix estimated at x+u */
  //  ami_m3x3f Hi; /* interpolated Hessian at x+u */
      
  if (dim_z>1)
    image_dimension=3;
  else
    image_dimension=2;
  
  double** B;
  double** B_1;
  ami_malloc2d(B,  double,image_dimension,image_dimension);
  ami_malloc2d(B_1,double,image_dimension,image_dimension);
    
  /* WE ALLOCATE MEMORY */
  ami_malloc3d(grad_image_1,ami_v3f,dim_x,dim_y,dim_z);
  ami_malloc3d(grad_image_2,ami_v3f,dim_x,dim_y,dim_z);
  ami_malloc3d(grad_image_1i,ami_v3f,dim_x,dim_y,dim_z);
  ami_malloc3d(grad_image_2i,ami_v3f,dim_x,dim_y,dim_z);
  ami_malloc3d(image_1i,float,dim_x,dim_y,dim_z);
  ami_malloc3d(image_2i,float,dim_x,dim_y,dim_z);
  
//  ami_malloc3d(hessian_image,ami_m3x3f,dim_x,dim_y,dim_z);
  

  if (param.GetGradientComputation()!=grad_spline) {
  /* WE COMPUTE THE GRADIENT OF IMAGE 1 & 2*/
  if (param.GetSmoothGradient()) {
    // we use image_1i and image_2i to store temporary the smoothed images
    ami_copy_3d(image_1,image_1i,dim_x,dim_y,dim_z);
    ami_copy_3d(image_2,image_2i,dim_x,dim_y,dim_z);
    // WE FILTER THE IMAGES TO COMPUTE THE GRADIENT 
	{
    float *beta = new float[image_dimension];
    for(l=0;l<image_dimension;l++) beta[l]=0.25;
    ami_convolution_3d(image_1i,beta,dim_x,dim_y,dim_z);
    ami_convolution_3d(image_2i,beta,dim_x,dim_y,dim_z);
	delete [] beta;
	}
	ami_compute_grad_3d(image_1i,grad_image_1,dim_x,dim_y,dim_z,param);
    ami_compute_grad_3d(image_2i,grad_image_2,dim_x,dim_y,dim_z,param);
  } else {
    ami_compute_grad_3d(image_1,grad_image_1,dim_x,dim_y,dim_z,param);
    ami_compute_grad_3d(image_2,grad_image_2,dim_x,dim_y,dim_z,param);
  }
  }
  
   /* WE COMPUTE THE HESSIAN IMAGE 2 */
//  ami_hessian_3d(image_2,hessian_image,dim_x,dim_y,dim_z);
  

  // divide u by half
  for(i=0;i<dim_x;i++) 
    for(j=0;j<dim_y;j++) 
      for(k=0;k<dim_z;k++)
    for(l=0;l<image_dimension;l++) u[i][j][k][l] /= 2.0;

  /* WE INTERPOLATE THE GRADIENT AFTER CURRENT FLOW DISPLACEMENT */
  if ((param.GetGradientComputation()!=grad_spline)||(dim_z>1)) {
    ami_image_interpolation_v3f(grad_image_2,u,grad_image_2i,dim_x,dim_y,dim_z);
  } else {
    ami_compute_splinegrad_v3f(image_2,u,grad_image_2i,dim_x,dim_y,dim_z);
  }
  /* WE INTERPOLATE THE IMAGE 2 AFTER CURRENT FLOW DISPLACEMENT */
  ami_warpimage_3df(image_2,u,image_2i,dim_x,dim_y,dim_z,param);
  
  // invert u
  for(i=0;i<dim_x;i++) 
    for(j=0;j<dim_y;j++) 
      for(k=0;k<dim_z;k++)
	for(l=0;l<image_dimension;l++) u[i][j][k][l] = - u[i][j][k][l];
  
  
  /* WE INTERPOLATE THE GRADIENT AFTER CURRENT FLOW DISPLACEMENT */
  if ((param.GetGradientComputation()!=grad_spline)||(dim_z>1)) {
    ami_image_interpolation_v3f(grad_image_1,u,grad_image_1i,dim_x,dim_y,dim_z);
  } else {
    ami_compute_splinegrad_v3f(image_1,u,grad_image_1i,dim_x,dim_y,dim_z);
  }
  /* WE INTERPOLATE THE IMAGE 2 AFTER CURRENT FLOW DISPLACEMENT */
  ami_warpimage_3df(image_1,u,image_1i,dim_x,dim_y,dim_z,param);
  
  // we restore the original displacement u
  for(i=0;i<dim_x;i++) 
    for(j=0;j<dim_y;j++) 
      for(k=0;k<dim_z;k++)
	for(l=0;l<image_dimension;l++) u[i][j][k][l] *= - 2.0;
  
  // we store the average of both gradients in grad_image_1i,
  // but call it grad_image_average for clarity
  grad_image_average = grad_image_1i;
  for(i=0;i<dim_x;i++)  
    for(j=0;j<dim_y;j++) 
      for(k=0;k<dim_z;k++)
	for(l=0;l<image_dimension;l++) {
        grad_image_average[i][j][k][l] += grad_image_2i[i][j][k][l];
        grad_image_average[i][j][k][l] /= 2.0;
    }
  
  
  /* WE NORMALIZE THE DIFFUSION WEIGHT */
  if (param.GetNormalizeAlpha()) {
    norm=ami_norm_2_v3f(grad_image_average,dim_x,dim_y,dim_z);
    printf("Alfa is multiplied by (%0.2f+%f)²\n",norm,param.GetAlphaNormEpsilon());
    for(l=0;l<image_dimension;l++)
      alfa[l]=(alfa[l])*(norm+param.GetAlphaNormEpsilon())*(norm+param.GetAlphaNormEpsilon());
  }
  
  // if phi' != 1, pre-compute phi'(norm(grad(u)))
  switch (param.GetSmoothingFunction()) {
    case phi_sqrt_x:
      for(i=0;i<dim_x;i++) 
	for(j=0;j<dim_y;j++) 
	  for(k=0;k<dim_z;k++) {
	    /* WE COMPUTE THE VECTOR b OF HORN-SHUNCK SYSTEM */
	    grad2_u=0;
	    for(l=0;l<image_dimension;l++) {
	      u_xp=(i<dim_x-1)?u[i+1][j][k][l]:u[dim_x-1][j][k][l];
	      u_xm=(i>0)      ?u[i-1][j][k][l]:u[0]      [j][k][l];
	      u_yp=(j<dim_y-1)?u[i][j+1][k][l]:u[i][dim_y-1][k][l];
	      u_ym=(j>0)      ?u[i][j-1][k][l]:u[i][0]      [k][l];
	      grad2_u += (u_xp-u_xm)*(u_xp-u_xm)+(u_yp-u_ym)*(u_yp-u_ym);
	      if (image_dimension==3) {
	        u_zp=(k<dim_z-1)?u[i][j][k+1][l]:u[i][j][dim_z-1][l];
	        u_zm=(k>0)      ?u[i][j][k-1][l]:u[i][j][0      ][l];
	        grad2_u += (u_zp-u_zm)*(u_zp-u_zm);
	      }
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
      for(k=0;k<dim_z;k++) {
	// pre-compute the value of phi' if needed
	if (param.GetSmoothingFunction()!=phi_x) {
	  dp = image_der_phi[i][j][k];
	  dp_xp=(i<dim_x-1)?image_der_phi[i+1][j][k]:image_der_phi[dim_x-1][j][k];
	  dp_xm=(i>0)      ?image_der_phi[i-1][j][k]:image_der_phi[0]      [j][k];
	  dp_yp=(j<dim_y-1)?image_der_phi[i][j+1][k]:image_der_phi[i][dim_y-1][k];
	  dp_ym=(j>0)      ?image_der_phi[i][j-1][k]:image_der_phi[i][0]      [k];
	    if  (image_dimension==3) {
	      dp_zp=(k<dim_z-1)?image_der_phi[i][j][k+1]:image_der_phi[i][j][dim_z-1];
	      dp_zm=(k>0)      ?image_der_phi[i][j][k-1]:image_der_phi[i][j][0      ];
	    }
	}
	/* WE COMPUTE THE VECTOR b OF HORN-SHUNCK SYSTEM */
	for(l=0;l<image_dimension;l++) {
	  b[i][j][k][l]=(image_1i[i][j][k]-image_2i[i][j][k])*(grad_image_average[i][j][k][l]);
	  // if the smoothing constraint is global, add alfa*div(u)
      //printf("global smoothing = %d\n",param.GetGlobalConstraint());
	  if (param.GetGlobalConstraint()) {
       //fprintf(stderr,"Applying global smoothing \n");
	    u_0 =u[i][j][k][l];
	    u_xp=(i<dim_x-1)?u[i+1][j][k][l]:u[dim_x-1][j][k][l];
	    u_xm=(i>0)      ?u[i-1][j][k][l]:u[0]      [j][k][l];
	    u_yp=(j<dim_y-1)?u[i][j+1][k][l]:u[i][dim_y-1][k][l];
	    u_ym=(j>0)      ?u[i][j-1][k][l]:u[i][0]      [k][l];
	    if  (image_dimension==3) {
	      u_zp=(k<dim_z-1)?u[i][j][k+1][l]:u[i][j][dim_z-1][l];
	      u_zm=(k>0)      ?u[i][j][k-1][l]:u[i][j][0      ][l];
	    }
	    switch (param.GetSmoothingFunction()) {
	      case phi_x:
	        div = u_xp+u_xm+u_yp+u_ym-4*u_0;
	        if  (image_dimension==3) 
	          div += u_zp+u_zm+-2*u_0;
		b[i][j][k][l] += alfa[l]*div;
	      break;
	      case phi_sqrt_x:
		div  = (u_xp-u_0)*(dp_xp+dp) - (u_0-u_xm)*(dp+dp_xm);
		div += (u_yp-u_0)*(dp_yp+dp) - (u_0-u_ym)*(dp+dp_ym);
		if (image_dimension==3)
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
	    B[m][n] = grad_image_average[i][j][k][m]*grad_image_average[i][j][k][n];
	  }
	  if (param.GetSmoothingFunction()==phi_x)
	    B[m][m]+=2*image_dimension*(alfa[m]);
	  else {
	    tmp = (dp_xp+dp)+(dp+dp_xm) + (dp_yp+dp)+(dp+dp_ym);
	    if (image_dimension==3)
	      tmp += (dp_zp+dp)+(dp+dp_zm);
	    tmp *=  alfa[m]/2.0;
	    B[m][m]+=tmp;
	  }
	}
	
	ami_inversa((double**)B,(double**)B_1,image_dimension);
	for(m=0;m<image_dimension;m++)
	  for(n=0;n<image_dimension;n++) {
	    A[i][j][k][m][n]=B_1[m][n];
	  }
/*	  if ((i%5==0)&&(j%5==0)) 
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
  ami_free3d(grad_image_1);
  ami_free3d(grad_image_2);
  ami_free3d(grad_image_1i);
  ami_free3d(grad_image_2i);
  ami_free3d(image_1i);
  ami_free3d(image_2i);
  
  ami_free2d(B);
  ami_free2d(B_1);
} // ami_horn_schunck_system_computation_symmetric()
 


inline void ami_matriz_vector_3d(ami_m3x3f A, double x[3], ami_v3f v)
{
  register float* tmp;
  tmp = A[0];
  v[0] = tmp[0]*x[0]+tmp[1]*x[1]+tmp[2]*x[2];
  tmp = A[1];
  v[1] = tmp[0]*x[0]+tmp[1]*x[1]+tmp[2]*x[2];
  tmp = A[2];
  v[2] = tmp[0]*x[0]+tmp[1]*x[1]+tmp[2]*x[2];
}

/**
 * FUNCTION TO SOLVE THE HORN-SHUNCK EQUATION SYSTEM                         
*/
void ami_horn_schunck_system_solution3D(
    ami_v3f ***h,/* CURRENT LOCAL DISPLACEMENT (INPUT/OUTPUT DATA, IT HAS TO BE INITIALIZED) */
    ami_v3f ***b,/* INDEPENDENT VECTOR OF THE ASSOCIATED LINEAR SYSTEM (INPUT DATA)*/
    ami_m3x3f ***A, /* MATRIX ASSOCIATED TO THE LINEAR SYSTEM (INPUT DATA) */
    float*** image_der_phi, // phi'(|grad(u)|) if phi'!=1, NULL otherwise
    ami_v3f alfa,/* WEIGHT OF THE REGULARIZATION TERM */
    float TOL_GaussSeidel,/* CONVERGENCE PARAMETER FOR THE GAUSS-SEIDEL SCHEME */
    int dim_x,int dim_y,int dim_z, /* IMAGE DIMENSIONS */
    const PDEOpticFlowParam& param,
    unsigned char*** border_mask)
{
  int i,j,k,l,iter,kk;
  int dim_x_1=dim_x-1;
  int dim_y_1=dim_y-1;
  int dim_z_1=dim_z-1;
  double b_aux[3];
  int mm,size=dim_x*dim_y*dim_z;
  ami_v3f ***h_2;
  ami_v3f *hp,*h_2p;
  float error_2,relative_error,error_1=100000.;

  register  int stepx=dim_y*dim_z;
  register  int stepy=dim_z;
  register ami_v3f* h_ptr;
  register ami_v3f* b_ptr;
  register float  *h_xp,*h_xm,*h_yp,*h_ym,*h_zp,*h_zm;

printf("ami_horn_schunck_system_solution3D\n");

  /* WE ALLOCATE MEMORY AND COPY THE ORIGINAL DISPLACEMENT h*/
  ami_malloc3d(h_2,ami_v3f,dim_x,dim_y,dim_z);
  
  // copy h in h_2
  ami_copy_v3f(h,h_2,dim_x,dim_y,dim_z);
  h_2p=h_2[0][0];
  hp=h[0][0];

  /* WE DO Niter ITERATIONS TO SOLVE THE HORN-SHUNCK SYSTEM */
  char infostr[100];
  int n1,len=0;
  kk=0;
  for(iter=0;iter<Niter_GaussSeidel;iter++) {
    if (iter%10==0) {
      if (iter==0)    printf("Niter_GaussSeidel it: ");
      else {
        for(n1=0; n1<len; n1++) printf("\b");
      }
      sprintf(infostr, "%4d %5.5f",iter,error_1);
      printf("%s",infostr);
      if ((int)strlen(infostr)<len) {
        for(n1=(int)strlen(infostr); n1<len; n1++) printf(" ");
      }
      else
        len=(int)strlen(infostr);
      fflush(stdout);
    }
    for(i=1;i<dim_x_1;i++) {
      for(j=1;j<dim_y_1;j++) {
	// h_ptr will always point to the position of h[i][j][k]
	// b_ptr will always point to the position of b[i][j][k]
	h_ptr = &h[i][j][1];
	b_ptr = &b[i][j][1]; 
        for(k=1;k<dim_z_1;k++,h_ptr++,b_ptr++) {
	  // h_xp is h[i+1][j][k]  p is for + 
	  // h_xm is h[i-1][j][k]  m is for -
	  // the same for y and z
	  h_xp=h_ptr[ stepx];
	  h_xm=h_ptr[-stepx];
	  h_yp=h_ptr[ stepy];
	  h_ym=h_ptr[-stepy];
	  h_zp=h_ptr[ 1];
	  h_zm=h_ptr[-1];
	  for(l=0;l<3;l++) 
	    b_aux[l]= (*b_ptr)[l]+ alfa[l]*(h_xp[l]+h_xm[l] + 
		                            h_yp[l]+h_ym[l] + 
		                            h_zp[l]+h_zm[l]);
	  ami_matriz_vector_3d(A[i][j][k],b_aux,*h_ptr);
	}
      }
    }

    switch (param.GetBoundaryType()) {
      case boundary_border: 
            ami_boundary_v3f(h,dim_x,dim_y,dim_z); 
            break;
      case boundary_point_outside: 
            ami_boundary_v3f(h,dim_x,dim_y,dim_z); 
            ami_fill_border_mask(h,dim_x,dim_y,dim_z,border_mask);
            break;
    }
    
    /* WE PERFORM THE ITERATION IN THE INVERSE WAY TO EQUILIBRATE */
    for(k=dim_z_1-1;k>0;k--) {
      for(j=dim_y_1-1;j>0;j--) {
	// h_ptr will always point to the position of h[i][j][k]
	// b_ptr will always point to the position of b[i][j][k]
	h_ptr = &h[dim_x_1-1][j][k];
	b_ptr = &b[dim_x_1-1][j][k]; 
	for(i=dim_x_1-1;i>0;i--,h_ptr-=stepx,b_ptr-=stepx) {
	  // h_xp is h[i+1][j][k]  p is for + 
	  // h_xm is h[i-1][j][k]  m is for -
	  // the same for y and z
	  h_xp=h_ptr[ stepx];
	  h_xm=h_ptr[-stepx];
	  h_yp=h_ptr[ stepy];
	  h_ym=h_ptr[-stepy];
	  h_zp=h_ptr[ 1];
	  h_zm=h_ptr[-1];
	  for(l=0;l<3;l++) 
	    b_aux[l]= (*b_ptr)[l]+ alfa[l]*(h_xp[l]+h_xm[l] + 
		                            h_yp[l]+h_ym[l] + 
		                            h_zp[l]+h_zm[l]);
	  ami_matriz_vector_3d(A[i][j][k],b_aux,*h_ptr);
	}
      }
    }

    switch (param.GetBoundaryType()) {
      case boundary_border: 
            ami_boundary_v3f(h,dim_x,dim_y,dim_z); 
            break;
      case boundary_point_outside: 
            ami_boundary_v3f(h,dim_x,dim_y,dim_z); 
            ami_fill_border_mask(h,dim_x,dim_y,dim_z,border_mask);
            break;
    }

    /* WE COMPUTE THE ERROR TO STOP ITERATIONS */
    if((iter+1)%1==0) {
      
      // do h_2 = h_2 - h
      // slows down, must be done differently ...
      register float* h_2_ptr = (float*) h_2[0][0][0];
      register float* h_ptr   = (float*) h[0][0][0];
      register int size2 = size*3;
      for(mm=0;mm<size2;mm++,h_2_ptr++,h_ptr++) {
	(*h_2_ptr)-=(*h_ptr);
      }
      
      error_2=ami_norm_2_v3f(h_2,dim_x,dim_y,dim_z);
            //printf("Error Gauss-Seidel iter=%d : error_1=%1.10f error_2=%1.10f \n",iter,error_1,error_2);
      relative_error=error_2/(error_1+0.0000000000000001);
            //printf("Relative Error Gauss-Seidel iter=%d =%1.15f\n",iter,relative_error);
      
      // Increase kk if the conditions are satisfied
      if(relative_error>(exp((double)-1000.*TOL_GaussSeidel)) || error_2<TOL_GaussSeidel)
	kk++;
      // otherwise come back to kk=0
      else
	kk=0;
     
      // if the conditions were satisfyied 3 times in a row:
      // finish
      if(kk==3) {
	printf("Niter_GaussSeidel = %d \n",iter);
	iter=Niter_GaussSeidel+1;
      } else {
	// otherwise copy h_2 in h
	ami_copy_v3f(h,h_2,dim_x,dim_y,dim_z);
	error_1=error_2;
      }
    } // (iter+1)%1==0
    
  }
  if(kk<3)
    printf("Niter_GaussSeidel = %d \n",iter);
  ami_free3d(h_2);
  
} //ami_horn_schunck_system_solution3D


inline void ami_matriz_vector_2d(ami_m3x3f* A, double* x, ami_v3f v)
{
  register float* tmp;
  
  tmp = (*A)[0];
  v[0] = tmp[0]*x[0]+tmp[1]*x[1];
   
  tmp = (*A)[1];
  v[1] = tmp[0]*x[0]+tmp[1]*x[1];
}


/*****************************************************************************/
/* FUNCTION TO SOLVE THE HORN-SHUNCK EQUATION SYSTEM                         */
void ami_horn_schunck_system_solution2D(
  ami_v3f ***h,/* CURRENT LOCAL DISPLACEMENT (INPUT/OUTPUT DATA, IT HAS TO BE INITIALIZED) */
  ami_v3f ***b,/* INDEPENDENT VECTOR OF THE ASSOCIATED LINEAR SYSTEM (INPUT DATA)*/
  ami_m3x3f ***A, /* MATRIX ASSOCIATED TO THE LINEAR SYSTEM (INPUT DATA) */
  float*** image_der_phi, // phi'(|grad(u)|) if phi'!=1, NULL otherwise
  ami_v3f alfa,/* WEIGHT OF THE REGULARIZATION TERM */
  float TOL_GaussSeidel,/* CONVERGENCE PARAMETER FOR THE GAUSS-SEIDEL SCHEME */
  int dim_x,int dim_y, /* IMAGE DIMENSIONS */
  const PDEOpticFlowParam& param,
  unsigned char*** border_mask)
{
  int i,j,iter,kk;
  int dim_x_1=dim_x-1;
  int dim_y_1=dim_y-1;
  double b_aux[2];
  int mm,size=dim_x*dim_y;
  ami_v3f ***h_2,*h_2p,*hp;
  float error_2,relative_error,error_1=100000.;
  //  int dim_z=1;

  register  int stepx=dim_y;
  //    register  int stepy=1;
  register ami_v3f* h_ptr;
  register ami_v3f* b_ptr;
  register float*   dp_ptr;
  register float    dp_xp,dp_xm,dp_yp,dp_ym;
  register float  *h_xp,*h_xm,*h_yp,*h_ym;

printf("ami_horn_schunck_system_solution2D\n");

  /* WE ALLOCATE MEMORY AND COPY THE ORIGINAL DISPLACEMENT h*/
  ami_malloc3d(h_2,ami_v3f,dim_x,dim_y,1);
  ami_copy_v3f(h,h_2,dim_x,dim_y,1);
  h_2p=h_2[0][0];
  hp=h[0][0];


  //    printf(" ami_horn_schunck_system_solution2D() begin \n");
  /* WE DO Niter ITERATIONS TO SOLVE THE HORN-SHUNCK SYSTEM */
  kk=0;
  for(iter=0;iter<Niter_GaussSeidel_2D;iter++)
  {
    if (iter%10==0)
    {
      if (iter==0)
        printf("Niter_GaussSeidel it: ");
      else
        printf("\b\b\b\b");
      printf("%4d",iter);
      fflush(stdout);
    }

    for(i=1;i<dim_x_1;i++)
    {
      h_ptr = h[i][1];
      b_ptr = b[i][1];
      for(j=1;j<dim_y_1;j++,h_ptr++,b_ptr++)
      {
        // first fast conversion to 2D, to improve ...
        h_xp=h_ptr[ stepx];
        h_xm=h_ptr[-stepx];
        h_yp=h_ptr[ 1];
        h_ym=h_ptr[-1];
        if (param.GetSmoothingFunction()==phi_x)
        {
          // first component
          b_aux[0]= (*b_ptr)[0]+ alfa[0]*(h_xp[0] + h_xm[0] + h_yp[0] + h_ym[0]);
          // second component
          b_aux[1]= (*b_ptr)[1]+ alfa[1]*(h_xp[1] + h_xm[1] + h_yp[1] + h_ym[1]);
        }
        else
        {
          dp_ptr= image_der_phi[i][j];
          dp_xp = dp_ptr[ stepx]+*dp_ptr;
          dp_xm = dp_ptr[-stepx]+*dp_ptr;
          dp_yp = dp_ptr[ 1]+*dp_ptr;
          dp_ym = dp_ptr[-1]+*dp_ptr;
          b_aux[0] = h_xp[0]*dp_xp + h_xm[0]*dp_xm + h_yp[0]*dp_yp + h_ym[0]*dp_ym;
          b_aux[0] *= alfa[0]/2.0;
          b_aux[0] += (*b_ptr)[0];
          // second component
          b_aux[1] = h_xp[1]*dp_xp + h_xm[1]*dp_xm + h_yp[1]*dp_yp + h_ym[1]*dp_ym;
          b_aux[1] *= alfa[1]/2.0;
          b_aux[1] += (*b_ptr)[1];
        }
        ami_matriz_vector_2d(&A[i][j][0],b_aux,*h_ptr);
      }
    }

    switch (param.GetBoundaryType()) {
      case boundary_border: 
            ami_boundary_v3f(h,dim_x,dim_y,1); 
            break;
      case boundary_point_outside: 
            ami_boundary_v3f(h,dim_x,dim_y,1); 
            ami_fill_border_mask(h,dim_x,dim_y,1,border_mask);
            break;
    }
    /* WE PERFORM THE ITERATION IN THE INVERSE WAY TO EQUILIBRATE */

    for(j=dim_y_1-1;j>0;j--)
    {
      h_ptr = h[dim_x_1-1][j];
      b_ptr = b[dim_x_1-1][j];
      for(i=dim_x_1-1;i>0;i--,h_ptr-=stepx,b_ptr-=stepx)
      {
        // first fast conversion to 2D, to improve ...
        h_xp=h_ptr[ stepx];
        h_xm=h_ptr[-stepx];
        h_yp=h_ptr[ 1];
        h_ym=h_ptr[-1];
        if (param.GetSmoothingFunction()==phi_x)
        {
          // first component
          b_aux[0]= (*b_ptr)[0]+ alfa[0]*(h_xp[0] + h_xm[0] + h_yp[0] + h_ym[0]);
          // second component
          b_aux[1]= (*b_ptr)[1]+ alfa[1]*(h_xp[1] + h_xm[1] + h_yp[1] + h_ym[1]);
        }
        else
        {
          dp_ptr= image_der_phi[i][j];
          dp_xp = dp_ptr[ stepx]+*dp_ptr;
          dp_xm = dp_ptr[-stepx]+*dp_ptr;
          dp_yp = dp_ptr[ 1]+*dp_ptr;
          dp_ym = dp_ptr[-1]+*dp_ptr;
          b_aux[0] = h_xp[0]*dp_xp + h_xm[0]*dp_xm + h_yp[0]*dp_yp + h_ym[0]*dp_ym;
          b_aux[0] *= alfa[0]/2.0;
          b_aux[0] += (*b_ptr)[0];
          // second component
          b_aux[1] = h_xp[1]*dp_xp + h_xm[1]*dp_xm + h_yp[1]*dp_yp + h_ym[1]*dp_ym;
          b_aux[1] *= alfa[1]/2.0;
          b_aux[1] += (*b_ptr)[1];
        }
        ami_matriz_vector_2d(&A[i][j][0],b_aux,*h_ptr);
      }
    }

    switch (param.GetBoundaryType()) {
      case boundary_border: 
            ami_boundary_v3f(h,dim_x,dim_y,1); 
            break;
      case boundary_point_outside: 
            ami_boundary_v3f(h,dim_x,dim_y,1); 
            ami_fill_border_mask(h,dim_x,dim_y,1,border_mask);
            break;
    }

    /* WE COMPUTE THE ERROR TO STOP ITERATIONS */
    if((iter+1)%1==0)
    {

      // h2 = h2-h
      register float* h_2_ptr = (float*) h_2[0][0][0];
      register float* h_ptr   = (float*) h[0][0][0];
      register int size2 = size*3;
      for(mm=0;mm<size2;mm++,h_2_ptr++,h_ptr++)
      {
        (*h_2_ptr)-=(*h_ptr);
      }

      error_2=ami_norm_2_v3f(h_2,dim_x,dim_y,1);
      //printf("Error Gauss-Seidel iter=%d : error_1=%1.10f error_2=%1.10f \n",iter,error_1,error_2);
      relative_error=error_2/(error_1+0.0000000000000001);
      //printf("Relative Error Gauss-Seidel iter=%d =%1.15f\n",iter,relative_error);
      if(relative_error>(exp((double)-1000.*TOL_GaussSeidel)) || error_2<TOL_GaussSeidel)
        kk++;
      else
        kk=0;
      if(kk==3)
      {
        //                printf("Niter_GaussSeidel = %d \n",iter);
        iter=Niter_GaussSeidel+1;
      }
      else
      {
        ami_copy_v3f(h,h_2,dim_x,dim_y,1);
        error_1=error_2;
      }
    }
  }
  ami_free3d(h_2);

} //ami_horn_schunck_system_solution2D()


/*****************************************************************************/
/* FUNCTION TO SOLVE THE HORN-SHUNCK EQUATION SYSTEM                         */
void ami_horn_schunck_system_solution(
    ami_v3f ***h,/* CURRENT LOCAL DISPLACEMENT (INPUT/OUTPUT DATA, IT HAS TO BE INITIALIZED) */
    ami_v3f ***b,/* INDEPENDENT VECTOR OF THE ASSOCIATED LINEAR SYSTEM (INPUT DATA)*/
    ami_m3x3f ***A, /* MATRIX ASSOCIATED TO THE LINEAR SYSTEM (INPUT DATA) */
    float*** image_der_phi, // phi'(|grad(u)|) if phi'!=1, NULL otherwise
    ami_v3f alfa,/* WEIGHT OF THE REGULARIZATION TERM */
    float TOL_GaussSeidel,/* CONVERGENCE PARAMETER FOR THE GAUSS-SEIDEL SCHEME */
    int dim_x,int dim_y,int dim_z, /* IMAGE DIMENSIONS */
    const PDEOpticFlowParam& param,
    unsigned char*** border_mask)
{
  if (dim_z>1)
    ami_horn_schunck_system_solution3D(h,b,A,image_der_phi,alfa,TOL_GaussSeidel, dim_x,dim_y,dim_z,param,border_mask);
  else
    ami_horn_schunck_system_solution2D(h,b,A,image_der_phi,alfa,TOL_GaussSeidel, dim_x,dim_y,param,border_mask);
} // ami_horn_schunck_system_solution()




/**
 * FUNCTION TO COMPUTE A 3D OPTIC FLOW USING THE HORN_SHUNCK METHOD          
*/
int ami_horn_schunck_optic_flow_3d(
    float ***image_1,/* FIRST IMAGE TO COMPUTE THE FLOW (INPUT DATA) */
    float ***image_2,/* SECOND IMAGE TO COMPUTE THE FLOW (INPUT DATA) */
    ami_v3f ***u, /* CURRENT FLOW (INPUT/OUTPUT DATA) IT HAS TO BE INITIALIZED */
    const PDEOpticFlowParam& param, // Parameters for the Optical Flow
    int dim_x,int dim_y,int dim_z) /* IMAGE DIMENSIONS, have to be a multiple of zoomfactor[i]^Nscales */
{
    int i,j,k,l,m,dim_x2,dim_y2,dim_z2;
    int mm,kk,kk_i[3];
    ami_m3x3f ***A;
    ami_v3f ***b;
    ami_v3f ***h;
    ami_v3f ***up=NULL,***up_2=NULL;
    float ***image_1p_1,***image_2p_1,***image_1p_2,***image_2p_2;
    float ***image_der_phi=NULL;
    float error_2,relative_error,error_1=100000.;
    ami_v3f alfa2;

    // mask that includes de points which displacement
    // falls inside the image limits
    // values 0 (point not included) or 1 (point included)
    unsigned char ***border_mask=NULL;


    int* zoom_factor=(int*)param.GetZoomFactor();

    //  printf("zoom_factor[2]=%d \n",zoom_factor[2]);
    // check if 2D, the no zoom in Z
    if (dim_z==1)
        zoom_factor[2]=1;
    //intf("zoom_factor[2]=%d \n",zoom_factor[2]);

    // check if dimensions are multiple of zoomfactor[i]^Nscales
    dim_x2=dim_x;
    dim_y2=dim_y;
    dim_z2=dim_z;
    for(l=param.GetNbScales();l>1;l--) {
        if (((dim_x2/zoom_factor[0])*zoom_factor[0] !=dim_x2)||
                ((dim_y2/zoom_factor[1])*zoom_factor[1] !=dim_y2)||
                ((dim_z2/zoom_factor[2])*zoom_factor[2] !=dim_z2)) {
            fprintf(stderr,"ami_horn_schunck_optic_flow_3d() \t each dimension i of the image has to be multiple of zoom_factor[i]^(Nscales-1) ... \n");
            return (1);
        }
        dim_x2/=zoom_factor[0];
        dim_y2/=zoom_factor[1];
        dim_z2/=zoom_factor[2];
    }


    /* WE GO TROUGH PIRAMIDAL SCHEME */
    for(l=param.GetNbScales();l>0;l--) {
        printf("--- Scale %d of %d\n",l,param.GetNbScales());
        /* WE INITIALIZE THE ERROR FOR CONVERGENCE CRITERIUM */
        error_1=1000000;
        /* WE ALLOCATE MEMORY*/
        ami_malloc3d(image_1p_1,float,dim_x,dim_y,dim_z);
        ami_malloc3d(image_2p_1,float,dim_x,dim_y,dim_z);
        ami_copy_3d(image_1,image_1p_1,dim_x,dim_y,dim_z);
        ami_copy_3d(image_2,image_2p_1,dim_x,dim_y,dim_z);
        /* WE ZOOM DOWN THE IMAGES */
        dim_x2=dim_x;
        dim_y2=dim_y;
        dim_z2=dim_z;
        for(m=1;m<l;m++) {
            ami_malloc3d(image_1p_2,float,dim_x2/zoom_factor[0],dim_y2/zoom_factor[1],dim_z2/zoom_factor[2]);
            ami_malloc3d(image_2p_2,float,dim_x2/zoom_factor[0],dim_y2/zoom_factor[1],dim_z2/zoom_factor[2]);
	    if(ami_zoom_down_3d(image_1p_1,image_1p_2,(float*)param.GetBeta(),zoom_factor,
                                dim_x2,dim_y2,dim_z2)!=0)
                return(-1);
	    if(ami_zoom_down_3d(image_2p_1,image_2p_2,(float*)param.GetBeta(),zoom_factor,
                                dim_x2,dim_y2,dim_z2)!=0)
                return(-1);
            ami_free3d(image_1p_1);
            ami_free3d(image_2p_1);
            image_1p_1=image_1p_2;
            image_2p_1=image_2p_2;
            dim_x2/=zoom_factor[0];
            dim_y2/=zoom_factor[1];
            dim_z2/=zoom_factor[2];
        }
        /* WE INITIALIZE THE FLOW */
        if(l==param.GetNbScales()) {
            kk_i[0]=dim_x/dim_x2;
            kk_i[1]=dim_y/dim_y2;
            kk_i[2]=dim_z/dim_z2;
            ami_malloc3d(up,ami_v3f,dim_x2,dim_y2,dim_z2);
            for(i=0;i<dim_x2;i++)
                for(j=0;j<dim_y2;j++)
                    for(k=0;k<dim_z2;k++) {
                        for(m=0;m<3;m++) {
                            up[i][j][k][m]=u[i*kk_i[0]][j*kk_i[1]][k*kk_i[2]][m]/kk_i[m];
                        }
                    }
        }
        /* WE ALLOCATE MEMORY FOR THE OTHER VECTOR WE NEED */
        ami_malloc3d(A,ami_m3x3f,dim_x2,dim_y2,dim_z2);
        ami_malloc3d(b,ami_v3f  ,dim_x2,dim_y2,dim_z2);
        ami_malloc3d(h,ami_v3f  ,dim_x2,dim_y2,dim_z2);
	    if (param.GetSmoothingFunction()!=phi_x)
            ami_malloc3d(image_der_phi,float,dim_x2,dim_y2,dim_z2);
        ami_malloc3d(border_mask,unsigned char,dim_x2,dim_y2,dim_z2);

        /* WE INITIALIZE THE NUMBER OF TRIALS FOR SCALE CONVERGENCE
        	WE STOP THE ITERATIONS AFTER 3 CONSECUTIVE CONVERGENCE VERIFICATION*/
        kk=0;
        /* WE GO TRHOUGH SCALE ITERATIONS */
        for(mm=0;mm<Niter_Scales;mm++) {
            printf("-- scale %d iteration %d \n",l,mm+1);
            /* WE INITIALIZE AN AUXILIARY VARIABLE FOR THE REGULARIZATION TERM WEIGHT */
	        alfa2[0]=param.GetAlpha()[0];
	        alfa2[1]=param.GetAlpha()[1];
	        alfa2[2]=param.GetAlpha()[2];

            // compute the border_mask image
            ami_create_border_mask(border_mask,up,dim_x2,dim_y2,dim_z2,param.GetSymmetric());

            /* WE INITIALIZE TO ZERO THE LOCAL DISPLACEMENT */
            //	    printf("dimensions %d %d %d \n",dim_x2,dim_y2,dim_z2);
			memset(h[0][0],0,dim_x2*dim_y2*dim_z2*sizeof(ami_v3f));
           //bzero(h[0][0],dim_x2*dim_y2*dim_z2*sizeof(ami_v3f));
	    //printf("dimensions %d %d %d \n",dim_x2,dim_y2,dim_z2);
            /* WE SOLVE THE HORN-SHNUCK EQUATION SYSTEM */
            switch (param.GetGradientType()) {
            case 0:
                if (!param.GetSymmetric())
                    ami_horn_schunck_system_computation_v0(image_1p_1,image_2p_1,up,b,A,
                                                           alfa2,dim_x2,dim_y2,dim_z2,param);
                else
                    ami_horn_schunck_system_computation_symmetric(image_1p_1,image_2p_1,
                            up,b,A,image_der_phi,alfa2,
                            dim_x2,dim_y2,dim_z2,param);
                break;
            case 1:
                ami_horn_schunck_system_computation_v1(image_1p_1,image_2p_1,up,b,A,
                                                       alfa2,dim_x2,dim_y2,dim_z2,param);
                break;
            case 2:
                ami_horn_schunck_system_computation_v2(image_1p_1,image_2p_1,up,b,A,
                                                       alfa2,dim_x2,dim_y2,dim_z2,param);
                break;
            case 3:
                ami_horn_schunck_system_computation_v3(image_1p_1,image_2p_1,up,b,A,
                                                       alfa2,dim_x2,dim_y2,dim_z2,param);
                break;
            }
            ami_horn_schunck_system_solution(h,b,A,image_der_phi,alfa2,
                                             param.GetToleranceGaussSeidel(),
                                             dim_x2,dim_y2,dim_z2,
					    param,border_mask);

            /* WE COMPUTE THE ERROR TO STOP ITERATIONS */
            if((mm+1)%1==0) {
                error_2=ami_norm_2_v3f(h,dim_x2,dim_y2,dim_z2);
                //printf("Error Scale Iteration iter =%d : error_1=%1.10f error_2=%1.10f \n",mm,error_1,error_2);
                relative_error=error_2/(error_1+0.0000000000000001);
                //printf("\n Scale=%d iter Scale =%d h_displacement=%1.10f relative error=%1.10f\n",l,mm,error_2,relative_error);
                //scanf("%d",&ii);
                printf("rel err %f max %f, error_2 %f min %f, kk %d \n", relative_error, exp((double) -100.*param.GetToleranceScales()),error_2, param.GetToleranceScales(),kk);
		if(relative_error>(exp((double) -100.*param.GetToleranceScales())) || error_2<param.GetToleranceScales())
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
            
/*
            if (param.GetSolenoidalProjection()) {
                // we search the number of scales we can apply for the solenoidal projection (depends on the actual scale)
                int scales_solenoidal = 5;
		int min_dim = (int)pow(2,scales_solenoidal);
                while (dim_x2 < min_dim || dim_y2 < min_dim || dim_z2 < min_dim) {
                    scales_solenoidal--;
		    min_dim = (int)pow(2,scales_solenoidal);
                }
                for(i=0;i<3;i++)
		  ami_solenoidal_proyeccion_3d(h,(float*)param.GetBeta(),zoom_factor,
					       1*10e-6,scales_solenoidal,dim_x2,dim_y2,dim_z2);
                printf("       (solenoidal) scales=%d\n",scales_solenoidal);
                //printf("           (solenoid) L2 norm of error  = %f\n",ami_norm_2_v3f_error(up,u_o,dim_x2,dim_y2,dim_z2,4));
            }
*/
            /* WE ACTUALIZE up */
            if(kk<3) {
                for(i=0;i<dim_x2;i++)
                    for(j=0;j<dim_y2;j++)
                        for(k=0;k<dim_z2;k++) {
                            for(m=0;m<3;m++)
                                up[i][j][k][m]+=h[i][j][k][m];
                            //if( abs(i-8/kk_i[0])<2 && abs(j-8/kk_i[1])<2 && abs(k-8/kk_i[2])<2 ) printf("point (%d,%d,%d) flow =(%f,%f,%f)\n",
                            //i,j,k,up[i][j][k][0],up[i][j][k][1],up[i][j][k][2]);
                        }
            }
            //{ int oo; scanf("%d",&oo); }
            //printf("                      L2 norm of error  = %f\n",ami_norm_2_v3f_error(up,u_o,dim_x2,dim_y2,dim_z2,4));


            if (param.GetSolenoidalProjection()||param.GetEnergyConstraint()) {
                // we search the number of scales we can apply for the solenoidal projection (depends on the actual scale)
                int scales_solenoidal = 1;
/*		int min_dim = (int)pow(2,scales_solenoidal);
                while (dim_x2 < min_dim || dim_y2 < min_dim || dim_z2 < min_dim) {
                    scales_solenoidal--;
		    min_dim = (int)pow(2,scales_solenoidal);
                }
                for(i=0;i<3;i++)
*/
		  ami_solenoidal_proyeccion_3d(up,(float*)param.GetBeta(),zoom_factor,
					       5*10e-6,scales_solenoidal,
                                               param.GetAFlowProj(),
						dim_x2,dim_y2,dim_z2);
                printf("       (solenoidal) scales=%d\n",scales_solenoidal);
                //printf("           (solenoid) L2 norm of error  = %f\n",ami_norm_2_v3f_error(up,u_o,dim_x2,dim_y2,dim_z2,4));
            }


        }
        /*IF WE HAVE NOT ARRIVED TO THE FINER SCALE WE ZOOM UP up */
        if(l>1) {
            ami_malloc3d(up_2,ami_v3f,
			 zoom_factor[0]*dim_x2,zoom_factor[1]*dim_y2,zoom_factor[2]*dim_z2);
	    ami_zoom_up_v3f_flow(up,up_2,(float*)param.GetBeta(),zoom_factor,dim_x2,dim_y2,dim_z2);
            ami_free3d(up);
            up=up_2;
        }
        /* WE FREE THE MEMORY */
        ami_free3d(A);
        ami_free3d(b);
        ami_free3d(h);
        ami_free3d(image_1p_1);
        ami_free3d(image_2p_1);
	if (param.GetSmoothingFunction()!=phi_x)
            ami_free3d(image_der_phi);
        ami_free3d(border_mask);
    }
    /* WE COPY THE TEMPORAL DISPLACEMENT TO THE MAIN DISPLACEMENT */
    ami_copy_v3f(up,u,dim_x,dim_y,dim_z);
    ami_free3d(up);
    return(0);
} // ami_horn_schunck_optic_flow_3d()




/**
 * FUNCTION TO COMPUTE A 3D(or 2D) OPTIC FLOW USING THE HORN_SHUNCK METHOD WITH EXPLICIT SCHEME
 */
int ami_horn_schunck_optic_flow_explicit(float ***image_1,float ***image_2,ami_v3f ***u,
					 ami_v3f alfa, float total_time, float dt,int dim_x,int dim_y,int dim_z,
  const PDEOpticFlowParam& param 
)
{
  float t;
  ami_v3f ***dE; // - gradient of the Energy 
  float ***image_2i;
  ami_v3f ***grad_image_2,***grad_image_2i;
  int x,y,z,n;
  int image_dimension;
  float diff,norm2,total_diff2;
  register double tmp=0.0,tmp2=0.0;
  
  if (dim_z>1) image_dimension=3; else image_dimension=2;
  
  // allocations
  ami_malloc3d(dE      ,ami_v3f,dim_x,dim_y,dim_z);
  ami_malloc3d(image_2i,float,dim_x,dim_y,dim_z);
  ami_malloc3d(grad_image_2,ami_v3f,dim_x,dim_y,dim_z);
  ami_malloc3d(grad_image_2i,ami_v3f,dim_x,dim_y,dim_z);
  
    /* WE COMPUTE THE GRADIENT OF  IMAGE 2 */
    ami_compute_grad_3d(image_2,grad_image_2,dim_x,dim_y,dim_z,param);
   double norm=ami_norm_2_v3f(grad_image_2,dim_x,dim_y,dim_z);
    for(int l=0;l<image_dimension;l++)
      alfa[l]=(alfa[l])*(norm+param.GetAlphaNormEpsilon())*(norm+param.GetAlphaNormEpsilon());
  
  for(t=0;t<=total_time;t+=dt) {
    // compute the gradient of the energy
    /* WE INTERPOLATE THE GRADIENT AFTER CURRENT FLOW DISPLACEMENT */
    ami_image_interpolation_v3f(grad_image_2,u,grad_image_2i,dim_x,dim_y,dim_z);
    /* WE INTERPOLATE THE IMAGE 2 AFTER CURRENT FLOW DISPLACEMENT */
    ami_warpimage_3df(image_2,u,image_2i,dim_x,dim_y,dim_z,param);


    total_diff2 = 0;
   
    if (image_dimension==3)
    // Calculation of dE
    for(x=1;x<dim_x-1;x++)
      for(y=1;y<dim_y-1;y++) 
	for(z=1;z<dim_z-1;z++)
    {
      diff = image_1[x][y][z]-image_2i[x][y][z];
      total_diff2 += diff*diff;
      for(n=0;n<image_dimension;n++)    
      {
	tmp=0;
      // div(u)
      tmp += u[x+1][y]  [z]  [n]-2*u[x][y][z][n]+u[x-1][y]  [z]  [n];
      tmp += u[x]  [y+1][z]  [n]-2*u[x][y][z][n]+u[x]  [y-1][z]  [n];
      tmp += u[x]  [y]  [z+1][n]-2*u[x][y][z][n]+u[x]  [y]  [z-1][n];
      
      tmp *= alfa[n];

      tmp2 = 0;
      int i1,j1,k1;
      double sum_coeff = 0.0,coeff;
      for (i1=-1;i1<=1;i1++)
      for (j1=-1;j1<=1;j1++)
      for (k1=-1;k1<=1;k1++) {
	coeff = exp(-(i1*i1+j1+j1+k1*k1)/(0.5*0.5));
        sum_coeff += coeff;
        tmp2 += coeff*(image_1[x+i1][y+j1][z+k1]-image_2i[x+i1][y+j1][z+k1])*
                      grad_image_2i[x+i1][y+j1][z+k1][n];
      }
      
      tmp += tmp2/sum_coeff;

	dE[x][y][z][n]=tmp;
      }
    }
    
    if (image_dimension==2)
    // Calculation of dE
    for(x=1;x<dim_x-1;x++)
      for(y=1;y<dim_y-1;y++) 
    {
      diff = image_1[x][y][0]-image_2i[x][y][0];
      total_diff2 += diff*diff;
      for(n=0;n<image_dimension;n++)    
      {
	dE[x][y][0][n]=0;
      // div(u)
      tmp += u[x+1][y]  [0]  [n]-2*u[x][y][0][n]+u[x-1][y]  [0]  [n];
      tmp += u[x]  [y+1][0]  [n]-2*u[x][y][0][n]+u[x]  [y-1][0]  [n];
      
      tmp = alfa[n]*tmp+diff*grad_image_2i[x][y][0][n];
	dE[x][y][0][n]=tmp;
      }
    }

    // new u
    for(x=0;x<dim_x;x++)
      for(y=0;y<dim_y;y++) 
	for(z=0;z<dim_z;z++)       
	  for(n=0;n<image_dimension;n++)    
    {
      u[x][y][z][n] += dt*dE[x][y][z][n];
	}
    ami_boundary_v3f(u,dim_x,dim_y,dim_z);
               
    norm2=ami_norm_2_v3f(u,dim_x,dim_y,dim_z);
    printf("t = %f \t norm2 = %f \n",t,norm2);

    norm2=ami_norm_2_v3f(grad_image_2i,dim_x,dim_y,dim_z);
    printf("t = %f \t norm2(GI2i) = %f \n",t,norm2);

    printf("\t d2 = %f \n",sqrt(total_diff2));

    
  }
  
  ami_free3d(dE);
  ami_free3d(image_2i);
  ami_free3d(grad_image_2);
  ami_free3d(grad_image_2i);
  
  return(0);
} // ami_horn_schunck_optic_flow_explicit()
