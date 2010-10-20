
#ifndef _AMI_OPTIC_FLOW_H_
#define _AMI_OPTIC_FLOW_H_

#include "ami_types.h"

/**
	FUNCTION TO CONVERT A 1D FLOAT IMAGE IN A 3D STRUCTURE TENSOR IMAGE
*/
void ami_convert_image_1d_float_to_3d_unsigned_char(float *image,int width,int height, unsigned char *red,
          unsigned char *green, unsigned char *blue,
		  float center, /**< center of displacement of the float image value */
		  float zoom); /**< zoom to apply to the float image value */


/**
	FUNCION PARA DIBUJAR UN VECTOR EN LA posx, posy EN LA IMAGEN
    imgDestino, CON UNA VELOCIDAD DE valx, valy			    
*/

void ami_draw_arrow(unsigned char *red,unsigned char *green,unsigned char *blue,int width,int height,
                   unsigned char red_arrow,unsigned char green_arrow,unsigned char blue_arrow,
                   int posy, int posx, float valx, float valy,
		    float Umbral, float angCabeza, float lonCab, float magFlecha);


/**
	FUNCTION TO DRAW THE OPTIC FLOW ARROW IMAGE
*/
void ami_draw_optic_flow_arrow(
    unsigned char *red,unsigned char *green,unsigned char *blue, /* pointer to the output image */
    int width,int height,  /* image dimension */
    unsigned char red_arrow,unsigned char green_arrow,unsigned char blue_arrow, /* color for the arrow */
    float Umbral, /* minimum size of the arrow to be drawn */
	float angCabeza, /* head arrow angle */
	float lonCab,  /* factor of amplitud for head arrow size */
	float magFlecha, /* factor of magnitud for arrow size */
	float **u,float **v, /* flow to be drawn in the image */
	int x_init, int y_init, /* coordinates of the initial point to draw the first arrow */
	int x_interval_size, int y_interval_size, /* displacement between consecutives arrows */
	int median_filter_radius); /* median filter to apply to the flow (u,v) before drawing the arrow */


/**
	FUNCTION TO DRAW THE OPTIC FLOW ARROW IMAGE
*/
void ami_draw_optic_flow_arrow_v2(
    unsigned char *red,unsigned char *green,unsigned char *blue, /* pointer to the output image */
    int width,int height,  /* image dimension */
    unsigned char red_arrow,unsigned char green_arrow,unsigned char blue_arrow, /* color for the arrow */
    float Umbral, /* minimum size of the arrow to be drawn */
	float angCabeza, /* head arrow angle */
	float lonCab,  /* factor of amplitud for head arrow size */
	float magFlecha, /* factor of magnitud for arrow size */
	float *u,float *v, /* flow to be drawn in the image */
	int x_init, int y_init, /* coordinates of the initial point to draw the first arrow */
	int x_interval_size, int y_interval_size, /* displacement between consecutives arrows */
	int median_filter_radius); /* median filter to apply to the flow (u,v) before drawing the arrow */


/**
	FUNCION QUE DIBUJA UN SEGMENTO EN COLOR
*/
void ami_draw_segment(
   unsigned char *red,unsigned char *green,unsigned char *blue,int width,int height,
              unsigned char red_arrow,unsigned char green_arrow,unsigned char blue_arrow,
   int x0, int y0, /* COORDENADAS 1 PUNTO DEL SEGMENTO */
   int x1, int y1);  /* COORDENADAS 2 PUNTO DEL SEGMENTO */

/**
  FUNCION TO WRITE AN ARROW BMP FILE WITH THE INFORMATION OF THE OPTIC FLOW (u,v)
*/
int ami_write_bmp_arrow_file(char name[200],unsigned char *red,unsigned char *green,unsigned char *blue,int width,int height,
                   unsigned char red_arrow,unsigned char green_arrow,unsigned char blue_arrow,
		           float Umbral, float angCabeza, float lonCab, float magFlecha,
			     float **u,float **v,int x_init, int y_init, int x_interval_size, int y_interval_size, int median_filter_radius, int zoom);


/**
	FUNCTION TO DRAW THE OPTIC FLOW ARROW FIELD SAME FUNCTION THAT ABOVE BUT INCLUDING 
	A zoom FACTOR TO ZOOM DOWN THE IMAGE BEFORE DRAWING THE ARROWS  
*/
void ami_draw_optic_flow_arrow_zoom(unsigned char **red,unsigned char **green,unsigned char **blue,int *width,int *height,
                   unsigned char red_arrow,unsigned char green_arrow,unsigned char blue_arrow,
		           float Umbral, float angCabeza, float lonCab, float magFlecha,
				    float **u,float **v,int x_init, int y_init, int x_interval_size, int y_interval_size, int median_filter_radius, int zoom);

/**
	FUNCTION TO EXTEND THE BOUNDARY OF AN IMAGE BY MIRRORING 

	\param v image matrix 
	\param height size in x direction 
	\param width size in y direction 
*/
void dummies

(float **v,        /* image matrix */
 long  height,     /* size in x direction */
 long  width);     /* size in y direction */

/*
	\param sigma standard deviation of Gaussian 
	\param height image dimension in x direction 
	\param width image dimension in y direction 
	\param hx pixel size in x direction 
	\param hy pixel size in y direction 
	\param precision cutoff at precision * sigma 
	\param bc type of boundary condition (0=Dirichlet, 1=reflecing, 2=periodic)
	\param f input: original image ;  output: smoothed
*/
void gauss_conv

(float    sigma,     /* standard deviation of Gaussian */
 long     height,        /* image dimension in x direction */
 long     width,        /* image dimension in y direction */
 float    hx,        /* pixel size in x direction */
 float    hy,        /* pixel size in y direction */
 float    precision, /* cutoff at precision * sigma */
 long     bc,        /* type of boundary condition */
 /* 0=Dirichlet, 1=reflecing, 2=periodic */
 float    **f);       /* input: original image ;  output: smoothed */


/*
	\param dtype type of smoothness term 
	\param fx x derivative of image, unchanged 
	\param fy y derivative of image, unchanged 
	\param uv x component of flow, unchanged 
	\param height image dimension in x direction 
	\param width image dimension in y direction 
	\param hx pixel size in x direction 
	\param hy pixel size in y direction 
	\param lambda contrast parameter 
	\param d11 component [1,1] of diffusion tensor, output 
	\param d12 component [1,2] of diffusion tensor, output 
	\param d22 component [2,2] of diffusion tensor, output 
*/
void diffusion_tensor

     (long     dtype,       /* type of smoothness term */
      float    **fx,        /* x derivative of image, unchanged */
      float    **fy,        /* y derivative of image, unchanged */
      float    **uv,         /* x component of flow, unchanged */
      long     height,          /* image dimension in x direction */
      long     width,          /* image dimension in y direction */
      float    hx,          /* pixel size in x direction */
      float    hy,          /* pixel size in y direction */
      float    lambda,      /* contrast parameter */
      float    **d11,       /* component [1,1] of diffusion tensor, output */
      float    **d12,       /* component [1,2] of diffusion tensor, output */
      float    **d22);       /* component [2,2] of diffusion tensor, output */

/*
	\param f image, unchanged 
	\param u x component of optic flow, unchanged 
	\param v v component of optic flow, unchanged 
	\param height image dimension in x direction 
	\param width image dimension in y direction 
	\param fs f shifted by (u,v) and interpolated, output 
*/
void interpolation

     (float    **f,         /* image, unchanged */
      float    **u,         /* x component of optic flow, unchanged */
      float    **v,         /* v component of optic flow, unchanged */
      long     height,          /* image dimension in x direction */
      long     width,          /* image dimension in y direction */
      float    **fs);        /* f shifted by (u,v) and interpolated, output */


/*
	\param ht time step size, 0 < ht <= 0.25 
	\param height image dimension in x direction 
	\param width image dimension in y direction 
	\param hx pixel size in x direction 
	\param hy pixel size in y direction 
	\param f1 f1 image, unchanged 
	\param f2s f2 image shifted by flow, unchanged 
	\param f2xs x derivative of f2, shifted by flow, unchanged 
	\param f2ys y derivative of f2, shifted by flow, unchanged 
	\param dxx diffusion tensor element [1,1], unchanged 
	\param dxy diffusion tensor element [1,2], unchanged 
	\param dyy diffusion tensor element [2,2], unchanged 
	\param alpha smoothness weight 
	\param u x component of optic flow, changed 
	\param v v component of optic flow, changed 
	\param Niter Number of iterations for Gauss-Seidel 
	\param f1x Image derivative 
	\param f1y Image derivatice 
*/
int relax_2

     (float    ht,          /* time step size, 0 < ht <= 0.25 */
      long     height,          /* image dimension in x direction */
      long     width,          /* image dimension in y direction */
      float    hx,          /* pixel size in x direction */
      float    hy,          /* pixel size in y direction */
      float    **f1,        /* f1 image, unchanged */
      float    **f2s,       /* f2 image shifted by flow, unchanged */
      float    **f2xs,      /* x derivative of f2, shifted by flow, unchanged */
      float    **f2ys,      /* y derivative of f2, shifted by flow, unchanged */
      float    **dxx,       /* diffusion tensor element [1,1], unchanged */
      float    **dxy,       /* diffusion tensor element [1,2], unchanged */
      float    **dyy,       /* diffusion tensor element [2,2], unchanged */
      float    alpha,       /* smoothness weight */
      float    **u,         /* x component of optic flow, changed */
      float    **v,         /* v component of optic flow, changed */
      int Niter,            /* Number of iterations for Gauss-Seidel */
      float **f1x,          /* Image derivative */
      float **f1y);          /* Image derivatice */


/*
	\param height image dimension in x direction 
	\param width image dimension in y direction 
	\param hx pixel size in x direction 
	\param hy pixel size in y direction 
	\param f1 f2 image, unchanged 
	\param f2s f2 image shifted by flow, unchanged 
	\param f2xs x derivative of f2, shifted by flow, unchanged 
	\param f2ys y derivative of f2, shifted by flow, unchanged 
	\param dxx diffusion tensor element [1,1], unchanged 
	\param dxy diffusion tensor element [1,2], unchanged 
	\param dyy diffusion tensor element [2,2], unchanged 
	\param alpha smoothness weight 
	\param u x component of optic flow, unchanged 
	\param v v component of optic flow, unchanged 
	\param err L2 norm of residue, output
*/
void L2_residue

     (long     height,          /* image dimension in x direction */
      long     width,          /* image dimension in y direction */
      float    hx,          /* pixel size in x direction */
      float    hy,          /* pixel size in y direction */
      float    **f1,        /* f2 image, unchanged */
      float    **f2s,       /* f2 image shifted by flow, unchanged */
      float    **f2xs,      /* x derivative of f2, shifted by flow, unchanged */
      float    **f2ys,      /* y derivative of f2, shifted by flow, unchanged */
      float    **dxx,       /* diffusion tensor element [1,1], unchanged */
      float    **dxy,       /* diffusion tensor element [1,2], unchanged */
      float    **dyy,       /* diffusion tensor element [2,2], unchanged */
      float    alpha,       /* smoothness weight */
      float    **u,         /* x component of optic flow, unchanged */
      float    **v,         /* v component of optic flow, unchanged */
      float    *err);        /* L2 norm of residue, output */

/*--------------------------------------------------------------------------*/

/*
	\param u image, unchanged 
	\param height pixel number in x direction 
	\param width pixel number in x direction 
	\param min minimum, output 
	\param max maximum, output 
	\param mean mean, output 
	\param vari variance, output 
*/
void analyse

     (float   **u,         /* image, unchanged */
      long    height,          /* pixel number in x direction */
      long    width,          /* pixel number in x direction */
      float   *min,        /* minimum, output */
      float   *max,        /* maximum, output */
      float   *mean,       /* mean, output */
      float   *vari);       /* variance, output */

/**
	\param k k-th smallest value 
	\param n size of R: 1..n 
	\param arr array, changed on output 
*/
float select2

     (unsigned long   k,         /* k-th smallest value */
      unsigned long   n,         /* size of R: 1..n */
      float           *arr);      /* array, changed on output */


/**
	\param fx image derivative, unchanged 
	\param fy image derivative, unchanged 
	\param height pixel number in x direction 
	\param width pixel number in y direction 
	\param hx pixel size in x direction 
	\param hy pixel size in y direction 
	\param quantile fraction of gradients <= lambda 
	\param check verbose mode for check==1 
	\param lambda contrast parameter, output 
*/
void find_lambda

     (float  **fx,      /* image derivative, unchanged */
      float  **fy,      /* image derivative, unchanged */
      long   height,        /* pixel number in x direction */
      long   width,        /* pixel number in y direction */
      float  hx,        /* pixel size in x direction */
      float  hy,        /* pixel size in y direction */
      float  quantile,  /* fraction of gradients <= lambda */
      long   check,     /* verbose mode for check==1 */
      float  *lambda);   /* contrast parameter, output */


/** 
	\param height image dimension in x direction 
	\param width image dimension in y direction 
	\param hx pixel size in x direction 
	\param hy pixel size in y direction 
	\param ff1 first image, unchanged 
	\param ff2 second image, unchanged 
	\param sigma Gaussian scale smoothing image data 
	\param T stopping time 
	\param alpha smoothness weight 
	\param dtype type of smoothness term 
	\param quantile isotropy fraction 
	\param ht convergence bound for relative residue 
	\param u x component of optic flow, changed 
	\param v y component of optic flow, changed 
	\param Niter Number of Iterations for Gauss-Seidel 
*/
void optic_flow

     (long     height,          /* image dimension in x direction */
      long     width,          /* image dimension in y direction */
      float    hx,          /* pixel size in x direction */
      float    hy,          /* pixel size in y direction */
      float    **ff1,       /* first image, unchanged */
      float    **ff2,       /* second image, unchanged */
      float    sigma,       /* Gaussian scale smoothing image data */
      float    T,           /* stopping time */
      float    alpha,       /* smoothness weight */
      long     dtype,       /* type of smoothness term */
      float    quantile,    /* isotropy fraction */
      float    ht,          /* convergence bound for relative residue */
      float    **u,         /* x component of optic flow, changed */
      float    **v,         /* y component of optic flow, changed */
      int Niter);            /* Number of Iterations for Gauss-Seidel */

/**
 This procedures
 - determines a heuristic upper bound for the step size ht
 - iterates as long as the L2 norm of the residue is decreasing
   and above a specified fraction of the L2 norm of the initial
   residue
 - creates the following outputs:
   if precision reached: new flow estimates
   if nonconvergent:     initial flow
   convergence behaviour is described in variable "converged"
*/

/**
	\param height image dimension in x direction 
	\param width image dimension in y direction 
	\param hx pixel size in x direction 
	\param hy pixel size in y direction 
	\param ff1 first image, unchanged 
	\param ff2 second image, unchanged 
	\param sigma Gaussian scale smoothing image data 
	\param T stopping time 
	\param alpha smoothness weight 
	\param dtype type of smoothness term 
	\param quantile isotropy fraction 
	\param ht time step size 
	\param u x component of optic flow, changed 
	\param v y component of optic flow, changed 
	\param Niter Number of Iterations for Gauss-Seidel 
	\param Nzoom Number of zooms to apply in the piramidal approach 
*/
void optic_flow_zoom

     (long     height,          /* image dimension in x direction */
      long     width,          /* image dimension in y direction */
      float    hx,          /* pixel size in x direction */
      float    hy,          /* pixel size in y direction */
      float    *ff1,        /* first image, unchanged */
      float    *ff2,        /* second image, unchanged */
      float    sigma,       /* Gaussian scale smoothing image data */
      float    T,           /* stopping time */
      float    alpha,       /* smoothness weight */
      long     dtype,       /* type of smoothness term */
      float    quantile,    /* isotropy fraction */
      float    ht,          /* time step size */
      float    ***u,         /* x component of optic flow, changed */
      float    ***v,         /* y component of optic flow, changed */
      int Niter,            /* Number of Iterations for Gauss-Seidel */
	  long Nzoom);            /* Number of zooms to apply in the piramidal approach */



/**	FUNCI� PARA CALCULAR M�IMOS */
int ami_max(int a, int b);


/**	FUNCI� PARA CALCULAR M�IMOS */
int ami_min(int a, int b);


/**
	FUNCION PARA RELLENAR UN TRIANGULO CUYOS VERTICES SON cxi, cyi	    
*/

void ami_fill_triangle(unsigned char *red,unsigned char *green,unsigned char *blue,int width,int height,
              unsigned char red_arrow,unsigned char green_arrow,unsigned char blue_arrow,
		       int cx1, int cy1, int cx2, int cy2, int cx3, int cy3 );

/**
  FUNCTION TO COMPUTE THE OPTIC FLOW USING A CORRELATION TECHNIQUE

  \param image1,image2 input images 
  \param width,height dimension of the images 
  \param u,v output computed flow 
  \param x_init,y_init initial coordinate point to compute the correlation 
  \param x_interval_size,y_interval_size displacement between points for computing the correlation
  \param size_correlation_window size of correlation window. it has to be a power of 2 
*/
void optic_flow_correlation(
  float **image1,float **image2, /* input images */
  int width,int height, /* dimension of the images */
  float ***u,float ***v, /* output computed flow */
  int x_init,int y_init, /* initial coordinate point to compute the correlation */
  int x_interval_size, int y_interval_size, /* displacement between points for computing the correlation */
  int size_correlation_window); /* size of correlation window. it has to be a power of 2 */


/**
	FUNCTION WHICH COMPUTES THE TENSOR STRUCTURE INFORMATION AT A GIVEN SCALE            

	\param image INPUT IMAGE  
	\param width IMAGE WIDTH 
	\param height IMAGE HEIGHT 
	\param sigma STANDARD DEVIATION OF THE GAUSSIAN 
	\param convolved_image IMAGE CONVOLVED WITH THE GAUSSIAN 
	\param eigenvalue_min MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR 
	\param eigenvalue_max MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR 
	\param eigenvector_max_x X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE 
	\param eigenvector_max_y Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE 
*/
int ami_structure_tensor_information(float *image, /* INPUT IMAGE  */
                               int width, /* IMAGE WIDTH */
                               int height, /* IMAGE HEIGHT */
			       float sigma, /* STANDARD DEVIATION OF THE GAUSSIAN */
			       float *convolved_image, /* IMAGE CONVOLVED WITH THE GAUSSIAN */
			       float *eigenvalue_min, /* MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR */
				   float *eigenvalue_max, /* MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR */
				   float *eigenvector_max_x, /* X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE */
				   float *eigenvector_max_y); /* Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE */


/**
	THIS FUNCTION USES THE STRUCTURE TENSOR INFORMATION AT DIFFERENT SCALES TO ESTIMATE THE OPTIC FLOW BETWEEN IMAGE PAIRS 
	
	\param width IMAGE WIDTH 
	\param height IMAGE HEIGHT 
	\param Nscales NUMBER OF SCALES 
	\param sigma_1 STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES 
    \param convolved_image_1 IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES 
	\param eigenvalue_min_1 MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvalue_max_1 MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvector_max_x_1 X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param eigenvector_max_y_1 Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param sigma_2 STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES 
	\param convolved_image_2 IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES 
	\param eigenvalue_min_2 MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvalue_max_2 MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvector_max_x_2 X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param eigenvector_max_y_2 Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param window_radius WINDOWS RADIUS FOR SEARCHING IN THE OTHER IMAGE 
	\param weigth WEIGHT FOR THE DIFFERENT PARAMETERS (THE DIMENSION OF WEIGHTS IS Nscales X 4
	\param eigenvalue_max_1_treshold MINIMUM VALUE OF (max eigenvalue_max_1[i]) FOR OPTIC FLOW COMPUTATION
	\param x DISPLACEMENT OBTAINED IN THE x DIRECTION 
	\param y DISPLACEMENT OBTAINED IN THE x DIRECTION 
	\param width_xy SIZE OF THE X AND Y IMAGE 
	\param height_xy SIZE OF THE X AND Y IMAGE 
	\param energy_error 
*/
int ami_optic_flow_structure_tensor_scales(
					   int width, /* IMAGE WIDTH */
					   int height, /* IMAGE HEIGHT */
					   int Nscales, /* NUMBER OF SCALES */
					   float *sigma_1, /* STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES */
					   float **convolved_image_1, /* IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES */
					   float **eigenvalue_min_1, /* MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
					   float **eigenvalue_max_1, /* MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
					   float **eigenvector_max_x_1, /* X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
					   float **eigenvector_max_y_1, /* Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
					   float *sigma_2, /* STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES */
					   float **convolved_image_2, /* IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES */
					   float **eigenvalue_min_2, /* MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
					   float **eigenvalue_max_2, /* MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
					   float **eigenvector_max_x_2, /* X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
					   float **eigenvector_max_y_2, /* Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
					   ami_window window_radius, /* WINDOWS RADIUS FOR SEARCHING IN THE OTHER IMAGE */
					   float **weigth, /* WEIGHT FOR THE DIFFERENT PARAMETERS (THE DIMENSION OF WEIGHTS IS Nscales X 4*/
					   float eigenvalue_max_1_treshold, /* MINIMUM VALUE OF (max eigenvalue_max_1[i]) FOR OPTIC FLOW COMPUTATION */
					   float *x, /* DISPLACEMENT OBTAINED IN THE x DIRECTION */
					   float *y, /* DISPLACEMENT OBTAINED IN THE x DIRECTION */
					   int width_xy, /* SIZE OF THE X AND Y IMAGE */
					   int height_xy, /* SIZE OF THE X AND Y IMAGE */
					   float *energy_error);

/**
	FUNCION QUE CALCULA EL TENSOR DE ESTRUCTURA Y TODA LA INFORMACION ASOCIADA SIMULTANEAMENTE EN VARIAS ESCALAS  

	\param image INPUT IMAGE  
	\param width IMAGE WIDTH 
	\param height IMAGE HEIGHT 
	\param Nscales NUMBER OF SCALES 
	\param sigma STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES 
	\param convolved_image IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES 
	\param eigenvalue_min MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvalue_max MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvector_max_x X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param eigenvector_max_y Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
*/
int ami_structure_tensor_information_scales(
					    float *image, /* INPUT IMAGE  */
					    int width, /* IMAGE WIDTH */
					    int height, /* IMAGE HEIGHT */
					    int Nscales, /* NUMBER OF SCALES */
					    float *sigma, /* STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES */
					    float **convolved_image, /* IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES */
					    float **eigenvalue_min, /* MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
					    float **eigenvalue_max, /* MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
					    float **eigenvector_max_x, /* X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
					    float **eigenvector_max_y); /* Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/

/**
	FUNCTION TO COMPUTE THE OPTIC FLOW BETWEEN 2 IMAGES USING THE STRUCTURE TENSOR INFORMATION

	\param image_1,image_2 input images
	\param width,height image dimensions 
	\param u,v output flow estimated 
	\param parameter_file file name with the parameters of the function 	
*/
int optic_flow_structure_tensor(
				float *image_1,float *image_2, /* input images */
				int width,int height, /* image dimensions */
				float ***u,float ***v, /* output flow estimated */
				char parameter_file[200]); /* file name with the parameters of the function */

/**
	FUNCTION  TO SAVE MULTISCALE STRUCTURE TENSOR OPTIC FLOW ESTIMATION METHOD PARAMETER
*/
int ami_save_parameter_file_optic_flow_structure_tensor(char name[200],int Nscales,float *sigma,float eigenvalue_max_1_treshold,
							ami_window window_radius,int zoom_factor,int local_window_search_radius,int radius_window_median_filter,float **weigth );

/**
	FUNCTION TO SAVE IN ASCII FORMAT ALL THE INFORMATION OF THE OPTIC FLOW WITH 2 DIGIT FLOAT PRECISION
*/
 int ami_save_optic_flow_information(char name[200],float *x,float *y,float *energy_error,float *disparity_symmetry_error,int width,int height);

/**
	FUNCTION TO SAVE IN ASCII FORMAT THE DISPLACEMENT OF THE OPTIC FLOW WITH 2 DIGIT FLOAT PRECISION 
*/
 int ami_save_displacement(char name[200],float *d,int width,int height);


/**
	THIS FUNCTION USES THE STRUCTURE TENSOR INFORMATION AT DIFFERENT SCALES TO ESTIMATE THE OPTIC FLOW BETWEEN IMAGE PAIRS
	IT USES THE OPTIC FLOW INFORMATION IN A HIGHER ZOOM LEVEL TO SPEED UP THE ALGORITHM                                    
	
	\param width IMAGE WIDTH 
	\param height IMAGE HEIGHT
	\param Nscales NUMBER OF SCALES
	\param sigma_1 STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES
	\param convolved_image_1 IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES
	\param eigenvalue_min_1 MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvalue_max_1 MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvector_max_x_1 X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param eigenvector_max_y_1 Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param sigma_2 STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES
	\param convolved_image_2 IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES 
	\param eigenvalue_min_2 MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvalue_max_2 MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvector_max_x_2 X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param eigenvector_max_y_2 Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param window_radius WINDOWS RADIUS FOR SEARCHING IN THE OTHER IMAGE 
	\param weigth WEIGHT FOR THE DIFFERENT PARAMETERS (THE DIMENSION OF WEIGHTS IS Nscales X 4
	\param eigenvalue_max_1_treshold MINIMUM VALUE OF (max eigenvalue_max_1[i]) FOR OPTIC FLOW COMPUTATION 
	\param x_1 DISPLACEMENT OBTAINED IN THE x DIRECTION INPUT
	\param y_1 DISPLACEMENT OBTAINED IN THE x DIRECTION INPUT
	\param width_xy_1 SIZE OF THE X AND Y IMAGE INPUT
	\param height_xy_1 SIZE OF THE X AND Y IMAGE INPUT
	\param x_2 DISPLACEMENT OBTAINED IN THE x DIRECTION INPUT
	\param y_2 DISPLACEMENT OBTAINED IN THE x DIRECTION INPUT
	\param width_xy_2 SIZE OF THE X AND Y IMAGE INPUT
	\param height_xy_2 SIZE OF THE X AND Y IMAGE INPUT
	\param energy_error
*/
int ami_optic_flow_structure_tensor_scales_zoom_up(
						   int width, /* IMAGE WIDTH */
						   int height, /* IMAGE HEIGHT */
						   int Nscales, /* NUMBER OF SCALES */
						   float *sigma_1, /* STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES */
						   float **convolved_image_1, /* IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES */
						   float **eigenvalue_min_1, /* MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
						   float **eigenvalue_max_1, /* MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
						   float **eigenvector_max_x_1, /* X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
						   float **eigenvector_max_y_1, /* Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
						   float *sigma_2, /* STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES */
						   float **convolved_image_2, /* IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES */
						   float **eigenvalue_min_2, /* MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
						   float **eigenvalue_max_2, /* MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
						   float **eigenvector_max_x_2, /* X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
						   float **eigenvector_max_y_2, /* Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
						   int window_radius, /* WINDOWS RADIUS FOR SEARCHING IN THE OTHER IMAGE */
						   float **weigth, /* WEIGHT FOR THE DIFFERENT PARAMETERS (THE DIMENSION OF WEIGHTS IS Nscales X 4*/
						   float eigenvalue_max_1_treshold, /* MINIMUM VALUE OF (max eigenvalue_max_1[i]) FOR OPTIC FLOW COMPUTATION */
						   float *x_1, /* DISPLACEMENT OBTAINED IN THE x DIRECTION INPUT*/
						   float *y_1, /* DISPLACEMENT OBTAINED IN THE x DIRECTION INPUT*/
						   int width_xy_1, /* SIZE OF THE X AND Y IMAGE INPUT*/
						   int height_xy_1, /* SIZE OF THE X AND Y IMAGE INPUT*/
						   float *x_2, /* DISPLACEMENT OBTAINED IN THE x DIRECTION INPUT*/
						   float *y_2, /* DISPLACEMENT OBTAINED IN THE x DIRECTION INPUT*/
						   int width_xy_2, /* SIZE OF THE X AND Y IMAGE INPUT*/
						   int height_xy_2, /* SIZE OF THE X AND Y IMAGE INPUT*/
						   float *energy_error);

/**
	THIS FUNCTION USES THE STRUCTURE TENSOR INFORMATION AT DIFFERENT SCALES TO ESTIMATE THE OPTIC FLOW BETWEEN IMAGE PAIRS
    USING A ZOOM TO SPEED UP THE ALGORITHM

	\param width IMAGE WIDTH
	\param height IMAGE HEIGHT
	\param Nscales NUMBER OF SCALES
	\param sigma_1 STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES
	\param convolved_image_1 IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES
	\param eigenvalue_min_1 MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES
	\param eigenvalue_max_1 MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES
	\param eigenvector_max_x_1 X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param eigenvector_max_y_1 Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param sigma_2 STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES
	\param convolved_image_2 IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES
	\param eigenvalue_min_2 MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES
	\param eigenvalue_max_2 MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES
	\param eigenvector_max_x_2 X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param eigenvector_max_y_2 Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param window_radius WINDOWS RADIUS FOR SEARCHING IN THE OTHER IMAGE
	\param weigth WEIGHT FOR THE DIFFERENT PARAMETERS (THE DIMENSION OF WEIGHTS IS Nscales X 4
	\param eigenvalue_max_1_treshold MINIMUM VALUE OF (max eigenvalue_max_1[i]) FOR OPTIC FLOW COMPUTATION
	\param x DISPLACEMENT OBTAINED IN THE x DIRECTION 
	\param y DISPLACEMENT OBTAINED IN THE x DIRECTION
	\param zoom_factor ZOOM FACTOR TO SPEED UP THE ALGORITHM (REPRESENTS THE NUMBER OS ZOOM WE APPLY)
	\param local_window_search_radius RADIUS OF THE SEARCH LOCAL WINDOW
	\param radius_window_median_filter RADIUS OF THE WINDOW TO APPLY A MEDIAN FILTER
	\param energy_error
*/
int ami_optic_flow_structure_tensor_scales_zoom(
						int width, /* IMAGE WIDTH */
						int height, /* IMAGE HEIGHT */
						int Nscales, /* NUMBER OF SCALES */
						float *sigma_1, /* STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES */
						float **convolved_image_1, /* IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES */
						float **eigenvalue_min_1, /* MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
						float **eigenvalue_max_1, /* MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
						float **eigenvector_max_x_1, /* X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
						float **eigenvector_max_y_1, /* Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
						float *sigma_2, /* STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES */
						float **convolved_image_2, /* IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES */
						float **eigenvalue_min_2, /* MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
						float **eigenvalue_max_2, /* MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
						float **eigenvector_max_x_2, /* X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
						float **eigenvector_max_y_2, /* Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
						ami_window window_radius, /* WINDOWS RADIUS FOR SEARCHING IN THE OTHER IMAGE */
						float **weigth, /* WEIGHT FOR THE DIFFERENT PARAMETERS (THE DIMENSION OF WEIGHTS IS Nscales X 4*/
						float eigenvalue_max_1_treshold, /* MINIMUM VALUE OF (max eigenvalue_max_1[i]) FOR OPTIC FLOW COMPUTATION */
						float *x, /* DISPLACEMENT OBTAINED IN THE x DIRECTION */
						float *y, /* DISPLACEMENT OBTAINED IN THE x DIRECTION */
						int zoom_factor, /* ZOOM FACTOR TO SPEED UP THE ALGORITHM (REPRESENTS THE NUMBER OS ZOOM WE APPLY) */
						int local_window_search_radius, /* RADIUS OF THE SEARCH LOCAL WINDOW */
						int radius_window_median_filter, /* RADIUS OF THE WINDOW TO APPLY A MEDIAN FILTER */
						float *energy_error);


/**
 *
 *	FUNCTION TO READ AN ASCCI FILE WITH THE OPTIC FLOW INFORMATION
 *   IMPORTANT: WE INVERSE THE ROW ORDER
 * 
 */
int ami_read_optic_flow(
  char name[200],/* name of the input flow file */
  float ***u,float ***v,/* output flow matrix */
  int *width,int *height); /* image dimensions */


/**
 *
 *	FUNCTION TO READ AN ASCCI FILE WITH THE OPTIC FLOW INFORMATION
 *   IMPORTANT: WE INVERSE THE ROW ORDER (U, V images have 1d)
 * 
 */
int ami_read_optic_flow_v2(
  char name[200], /** name of the input flow file */
  float **u, float **v, /** output flow matrix */ 
  int *width, int *height, char tag[50]); /** image dimensions */


/**
	FUNCTION TO WRITE AN ASCCI FILE WITH THE OPTIC FLOW INFORMATION INCLUDING PARAMETERS
    IMPORTANT: WE INVERSE THE ROW ORDER 

	\param name name of the outpput flow file
	\param parameter_file name of the parameter file to be included in the header of the flow file
	\param u,v flow matrix
	\param width,height dimension of the images
	\param x_init
	\param y_init
	\param x_interval_size
	\param y_interval_size  
*/
int ami_write_optic_flow(
			 char name[200],/* name of the outpput flow file */
			 char parameter_file[200],/* name of the parameter file to be included in the header of the flow file */
			 float **u,float **v, /* flow matrix */
			 int width,int height, /* dimension of the images */
			 int x_init, int y_init,int x_interval_size, int y_interval_size);


/**
	FUNCTION TO WRITE AN ASCCI FILE WITH THE OPTIC FLOW INFORMATION INCLUDING PARAMETERS
    IMPORTANT: WE INVERSE THE ROW ORDER

	\param name name of the outpput flow file
	\param parameter_file name of the parameter file to be included in the header of the flow file
	\param u,v flow matrix
	\param width,height dimension of the images
	\param x_init
	\param y_init
	\param x_interval_size
	\param y_interval_size
*/
int ami_write_optic_flow_v2(
			    const char name[200],/* name of the outpput flow file */
			    const char parameter_file[200],/* name of the parameter file to be included in the header of the flow file */
			    float *u,float *v, /* flow matrix */
			    int width,int height, /* dimension of the images */
			    int x_init, int y_init,int x_interval_size, int y_interval_size);


/**
	FUNCTION  TO SAVE MULTISCALE STRUCTURE TENSOR OPTIC FLOW ESTIMATION METHOD PARAMETER
*/
int ami_write_parameters_optic_flow_structure_tensor(char name[200],int Nscales,float *sigma,float eigenvalue_max_1_treshold,
						     ami_window window_radius,int zoom_factor,int local_window_search_radius,int radius_window_median_filter,float **weigth );


/**
	FUNCTION TO WRITE IN DISK THE PARAMETERS OF THE AMI CORRELATION OPTIC FLOW METHOD

	\param name name for the parameter file 
	\param x_init,y_init initial coordinate point to compute the correlation 
	\param x_interval_size,y_interval_size displacement between points for computing the correlation
	\param size_correlation_window size of correlation window. it has to be a power of 2
 */
int ami_write_parameters_optic_flow_correlation(
						char name[200], /* name for the parameter file */
						int x_init,int y_init, /* initial coordinate point to compute the correlation */
						int x_interval_size, int y_interval_size, /* displacement between points for computing the correlation */
						int size_correlation_window); /* size of correlation window. it has to be a power of 2 */

 /**
	FUNCTION TO READ  MULTISCALE STRUCTURE TENSOR OPTIC FLOW ESTIMATION METHOD PARAMETER
*/
int ami_read_parameters_optic_flow_structure_tensor(char name[200],int *Nscales,float **sigma,float *eigenvalue_max_1_treshold,
						    ami_window window_radius,int *zoom_factor,int *local_window_search_radius,
						    int *radius_window_median_filter,float ***weigth );

/**
	FUNCTION TO READ FROM DISK THE PARAMETERS OF THE AMI CORRELATION OPTIC FLOW METHOD

	\param name name for the parameter file
	\param x_init,y_init initial coordinate point to compute the correlation
	\param x_interval_size,y_interval_size displacement between points for computing the correlation
	\param size_correlation_window size of correlation window. it has to be a power of 2
 */
int ami_read_parameters_optic_flow_correlation(
					       char name[200], /* name for the parameter file */
					       int *x_init,int *y_init, /* initial coordinate point to compute the correlation */
					       int *x_interval_size, int *y_interval_size, /* displacement between points for computing the correlation */
					       int *size_correlation_window); /* size of correlation window. it has to be a power of 2 */

/**
	FUNCTION TO WRITE IN DISK THE PARAMETERS OF THE AMI PDE OPTIC FLOW METHOD
	
	\param name
	\param hx pixel size in x direction 
	\param hy pixel size in y direction
	\param sigma Gaussian scale smoothing image data
	\param T stopping time
	\param alpha smoothness weight
	\param dtype type of smoothness term
	\param quantile isotropy fraction 
	\param ht time step size 
	\param Niter Number of Iterations for Gauss-Seidel 
	\param Nzoom Number of zooms to apply in the piramidal approach
 */
int ami_write_parameters_optic_flow_pde(
					char name[200],
					float    hx,          /* pixel size in x direction */
					float    hy,          /* pixel size in y direction */
					float    sigma,       /* Gaussian scale smoothing image data */
					float    T,           /* stopping time */
					float    alpha,       /* smoothness weight */
					long     dtype,       /* type of smoothness term */
					float    quantile,    /* isotropy fraction */
					float    ht,          /* time step size */
					int Niter,            /* Number of Iterations for Gauss-Seidel */
					long Nzoom);           /* Number of zooms to apply in the piramidal approach */

/**
     FUNCTION TO READ FROM DISK THE PARAMETERS OF THE AMI PDE OPTIC FLOW METHOD

     \param name
     \param hx pixel size in x direction
	 \param hy pixel size in y direction
	 \param sigma Gaussian scale smoothing image data
	 \param T stopping time
	 \param alpha smoothness weight
	 \param dtype type of smoothness term
	 \param quantile isotropy fraction
	 \param ht time step size
	 \param Niter Number of Iterations for Gauss-Seidel
	 \param Nzoom Number of zooms to apply in the piramidal approach
  */  
int ami_read_parameters_optic_flow_pde(
				       char name[200],
				       float    *hx,          /* pixel size in x direction */
				       float    *hy,          /* pixel size in y direction */
				       float    *sigma,       /* Gaussian scale smoothing image data */
				       float    *T,           /* stopping time */
				       float    *alpha,       /* smoothness weight */
				       long     *dtype,       /* type of smoothness term */
				       float    *quantile,    /* isotropy fraction */
				       float    *ht,          /* time step size */
				       int *Niter,            /* Number of Iterations for Gauss-Seidel */
				       long *Nzoom);            /* Number of zooms to apply in the piramidal approach */

#endif // _AMI_OPTIC_FLOW_H_
