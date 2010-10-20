#include <ami_vorticity_estimation.h>
#include "ami_utilities.h"
#include <math.h>

/*************************************************************************************************/
/* FUNCTION TO COMPUTE THE VORTICITY USING AN STANDARD ALGORITHM. IT RETURNS THE VORTICITY VALUE */
float ami_vorticity_2d_standard(
    int i,int j, /* PIXEL COORDINATES OF THE POINT WHERE THE VORTICITY IS GOING TO BE COMPUTED */
    float **ut,float **vt, /* GLOBAL FLOW ESTIMATION */
	int dim_x,int dim_y) /* IMAGE DIMENSIONS */
{
  float vorticity;
  vorticity=ut[i-1][j-1]+2.*ut[i][j-1]+ut[i+1][j-1]-ut[i+1][j+1]-2.*ut[i][j+1]-ut[i-1][j+1]+vt[i+1][j-1]+2.*vt[i+1][j]+vt[i+1][j+1]-vt[i-1][j+1]-2.*vt[i-1][j]-vt[i-1][j-1];

  return(vorticity/8.);
}

/***
Function to normalize image light conditions.
*/

int ami_gaussian_normalization(float sigma, int dim_x, int dim_y, float **image, float media)
{
  float **image_aux;
  long mean_image1;
  int i,j;
  
  ami_calloc2d(image_aux,float,dim_x,dim_y);
  
  for(i=0;i<dim_x;i++) {
    for (j=0;j<dim_y;j++) {
      image_aux[i][j]=image[i][j];
    }
  }
  
  ami_gauss_conv(sigma, dim_x, dim_y, 1,1, 5.0, 1, image_aux);
  
  for(i=0;i<dim_x;i++) {
    for (j=0;j<dim_y;j++) {
      image[i][j]=media+image[i][j]-image_aux[i][j];
    }
  }
  ami_free2d(image_aux);
  return(1);
}


int ami_upsample(float **image_in, int dim_x_in, int dim_y_in, float **image_out, int dim_x_out, int dim_y_out)
{
  int i,j,x2,y2;
  float dx,dy,x,y,hx,hy;
  hx=(float) (dim_x_in-1)/dim_x_out;
  hy=(float) (dim_y_in-1)/dim_y_out;
  
  
  for (i=0;i<dim_x_out;i++) {
    for (j=0;j<dim_y_out;j++) {
      x= i*hx;
      y= j*hy;
      x2=(int) floor(x);
      y2=(int) floor(y);
      if(x2>=(dim_x_in-1)){x2=dim_x_in-2; dx=1;}
      else{dx=x-x2;}
      if(y2>=(dim_y_in-1)){y2=dim_y_in-2; dy=1;}
      else{dy=y-y2;}
      /* WE INTERPOLATE USING BILINEAR ALGORITHM */
      image_out[i][j]=image_in[x2][y2]*(1-dx)*(1-dy) + image_in[x2+1][y2]*(dx)*(1-dy) + image_in[x2][y2+1]*(1-dx)*(dy) + image_in[x2+1][y2+1]*(dx)*(dy);
    }
  }
  
  return(0);

}
