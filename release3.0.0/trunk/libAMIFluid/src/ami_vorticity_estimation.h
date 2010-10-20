#ifndef AMI_VORTICITY_ESTIMATION_H
#define AMI_VORTICITY_ESTIMATION_H

#define LAMB_OSEEN 1
#define VORTEX 2
#define CONSTANT 3

#define GAMMAo 0.05*1000000.
#define FOUR_NU_T 1./(6.*6.)*1000000.
#define AMPLITUD 3.
#define P_VALUE 1.

/**
 * FUNCTION TO NORMALIZE THE IMAGES
*/
int ami_gaussian_normalization(float sigma, int dim_x, int dim_y, float **image, float media);

/** 
 * FUNCTION TO COMPUTE THE VORTICITY USING AN STANDARD ALGORITHM. IT RETURNS THE VORTICITY VALUE 
*/
float ami_vorticity_2d_standard(
    int i,int j, /* PIXEL COORDINATES OF THE POINT WHERE THE VORTICITY IS GOING TO BE COMPUTED */
    float **u,float **v, /* GLOBAL FLOW ESTIMATION */
	int dim_x,int dim_y); /* IMAGE DIMENSIONS */

/** FUNCTION TO COMPUTE DIFFERENT SYNTHETIC FLOWS: 
    method={LAMB_OSEEN, VORTEX, CONSTANT}
 */
int ami_synthetic_flow(	float **image_in /*2nd image of the sequence */, 
			int dim_x, int dim_y, /*Image dimensions */
			int zoom, /*Zoom */
			int method, /*Type of flow: LAMB_OSEEN, VORTEX, CONSTANT*/
			float **image_out, float **ut, float **vt /*output arguments: First image of the sequence, U,V Flow components*/);

/** FUNCTION TO COMPUTE THE VORTICITY USING THE ANALYTIC EXPRESSION OF THE FLOWS DEFINED IN ami_synthetic_flow
 */
float ami_synthetic_vorticity(int method, int i, int j, int dim_x, int dim_y);

int ami_upsample(float **image_in, int dim_x_in, int dim_y_in, float **image_out, int dim_x_out, int dim_y_out);

#endif
