#include "ami_utilities_3d.h"
#include "ami_spline.h"

#include <string.h>
#include <stdio.h>

#define Niter_GaussSeidel 10000
//#define Niter_GaussSeidel 100
#define MAX_RELATIVE_ERROR 10

/**
 * FUNCION TO COMPUTE THE NORM MAX OF A 3D IMAGE VECTOR
 * IT RETURNS THE NORM VALUE            
*/
float ami_norm_max_v3f(ami_v3f ***grad_image,int dim_x,int dim_y,int dim_z) {
    long m,size=dim_x*dim_y*dim_z;
    ami_v3f *p;
    float norm=0,max=0;
    p=grad_image[0][0];
    if (dim_z>1)
        for(m=0;m<size;m++) {
            norm=p[m][0]*p[m][0]+p[m][1]*p[m][1]+p[m][2]*p[m][2];
            if(norm>max)
                max=norm;
        }
    else
        for(m=0;m<size;m++) {
            norm=p[m][0]*p[m][0]+p[m][1]*p[m][1];
            if(norm>max)
                max=norm;
        }
    norm=sqrt((double) norm);
    return(norm);
}

/**
 * FUNCION TO COMPUTE THE NORM 2 OF A 3D IMAGE VECTOR IT RETURNS THE NORM VALUE  
*/
float ami_norm_2_v3f(ami_v3f ***grad_image,int dim_x,int dim_y,int dim_z) {
    long m,size=dim_x*dim_y*dim_z;
    ami_v3f *p;
    register float* v;
    register double norm=0;
    p=grad_image[0][0];
    if (dim_z>1)
        for(m=0;m<size;m++) {
            norm+=p[m][0]*p[m][0]+p[m][1]*p[m][1]+p[m][2]*p[m][2];
        }
    else
        for(m=0;m<size;m++,p++) {
            v=*p;
            norm+=v[0]*v[0]+v[1]*v[1];
        }

    norm=sqrt((double) (norm/size));
    return((float) norm);
}


/**
 * FUNCION TO COMPUTE THE NORM 2 OF A 2D+T IMAGE VECTOR SEQUENCE
 */
float ami_norm_2_vect_2d_t(ami_v3f ***grad_image,int dim_x,int dim_y,int dim_t)
{
  long m,size=dim_x*dim_y*dim_t;
  ami_v3f *p;
   float* v;
   double norm=0;
  p=grad_image[0][0];
 // printf("size = %d (%d %d %d)\n",size,dim_x,dim_y,dim_t);
  for(m=0;m<size;m++,p++) {
      v=*p;
      norm+=v[0]*v[0]+v[1]*v[1];
//      printf("%d, %f \n",(int)m,(float)norm);
  }
//  printf("norm = %g \n",norm);

  norm=sqrt((double) (norm/size));
  return((float) norm);
} // ami_norm_2_vect_2d_t()


/**
 * FUNCION TO COMPUTE THE L^1 DISTANCE BETWEEN TWO 3D IMAGE VECTOR IT RETURNS THE ERROR VALUE 
*/
float ami_norm_1_v3f_error(
		ami_v3f ***grad_image_1,ami_v3f ***grad_image_2,/* 3D IMAGE VECTORS TO COMPARE */
	/* WHEN grad_image_2==NULL grad_image_1 IS COMPARED WITH 0*/
	int dim_x,int dim_y,int dim_z, /* IMAGE DIMENSIONS */
	int borde) /* SIZE OF IMAGE BORDER TO EXCLUDE FROM THE ERROR COMPUTATION */
{
	long size=(dim_x-2*borde)*(dim_y-2*borde)*(dim_z-2*borde);
	double long norm=0;
	int i,j,k,l;
	if(grad_image_2==NULL){
		for(i=borde;i<(dim_x-borde);i++){
			for(j=borde;j<(dim_y-borde);j++){
				for(k=borde;k<(dim_z-borde);k++){
					for(l=0;l<3;l++)
						norm+=fabs(grad_image_1[i][j][k][l]);
				}
			}
		}
	}
	else{
		for(i=borde;i<(dim_x-borde);i++){
			for(j=borde;j<(dim_y-borde);j++){
				for(k=borde;k<(dim_z-borde);k++){
					for(l=0;l<3;l++)
						norm+=fabs(grad_image_1[i][j][k][l]-grad_image_2[i][j][k][l]);
				}
			}
		}
	}
	norm/=(3*size);
	return((float) norm);
}

/**
 * FUNCION TO COMPUTE THE L^2 DISTANCE BETWEEN TWO 3D IMAGE VECTOR IT RETURNS THE ERROR VALUE 
*/
float ami_norm_2_v3f_error(
		ami_v3f ***grad_image_1,ami_v3f ***grad_image_2,/* 3D IMAGE VECTORS TO COMPARE */
	/* WHEN grad_image_2==NULL grad_image_1 IS COMPARED WITH 0*/
	int dim_x,int dim_y,int dim_z, /* IMAGE DIMENSIONS */
	int borde) /* SIZE OF IMAGE BORDER TO EXCLUDE FROM THE ERROR COMPUTATION */
{
	long size=(dim_x-2*borde)*(dim_y-2*borde)*(dim_z-2*borde);
	double long norm=0;
	double error;
	int i,j,k,l;
	if(grad_image_2==NULL){
		for(i=borde;i<(dim_x-borde);i++){
			for(j=borde;j<(dim_y-borde);j++){
				for(k=borde;k<(dim_z-borde);k++){
					error=0.;
					for(l=0;l<3;l++)
						error+=grad_image_1[i][j][k][l]*grad_image_1[i][j][k][l];
					norm+=sqrt(error);
				}
			}
		}
	}
	else{
		for(i=borde;i<(dim_x-borde);i++){
			for(j=borde;j<(dim_y-borde);j++){
				for(k=borde;k<(dim_z-borde);k++){
					error=0.;
					for(l=0;l<3;l++)
						error+=(grad_image_1[i][j][k][l]-grad_image_2[i][j][k][l])*(grad_image_1[i][j][k][l]-grad_image_2[i][j][k][l]);
					norm+=sqrt(error);
				}
			}
		}
	}
	norm/=size;
	return((float) norm);
}


/**
 * computes index and increment in one direction from floating point position
 * for linear interpolation
 */
void GetLinearCoefficients( float pos, int dim, int* index, float* incr)
{
  if(pos<0)
  {
    *index=0;
    *incr=0.;
  }
  else if(pos>=(dim-1))
  {
    *index=dim-2;
    *incr=1.;
  }
  else
  {
    *index=(int)pos;
    *incr=pos-*index;
  }
}

/**
 * 3D IMAGE INTERPOLATION (BILINEAR METHOD)
 */
 
void ami_image_interpolation_3df(
    float ***image,/* ORIGINAL IMAGE */
    ami_v3f ***u,/* PIXEL DISPLACEMENT TO APPLY TO THE ORIGINAL IMAGE */
    float ***image_output,/* IMAGE OUTPUT (image + u ) */
    int dim_x,int dim_y,int dim_z) /* IMAGE DIMENSIONS */
{
    int i,j,k,i2,j2,k2;
    float x,y,z,dx,dy,dz;
    for(i=0;i<dim_x;i++) {
        for(j=0;j<dim_y;j++) {
            for(k=0;k<dim_z;k++) {
                x=i+u[i][j][k][0];
                y=j+u[i][j][k][1];
                z=k+u[i][j][k][2];
                GetLinearCoefficients(x,dim_x,&i2,&dx);
                GetLinearCoefficients(y,dim_y,&j2,&dy);

                if (dim_z>1) {
                  GetLinearCoefficients(z,dim_z,&k2,&dz);
                    image_output[i][j][k]=
                        (1-dx)*(1-dy)*(1-dz)*image[i2][j2][k2]+
                        (dx)*(1-dy)*(1-dz)*image[i2+1][j2][k2]+
                        (dx)*(dy)*(1-dz)*image[i2+1][j2+1][k2]+
                        (dx)*(dy)*(dz)*image[i2+1][j2+1][k2+1]+
                        (dx)*(1-dy)*(dz)*image[i2+1][j2][k2+1]+
                        (1-dx)*(dy)*(1-dz)*image[i2][j2+1][k2]+
                        (1-dx)*(dy)*(dz)*image[i2][j2+1][k2+1]+
                        (1-dx)*(1-dy)*(dz)*image[i2][j2][k2+1];
                        }
                else
                    image_output[i][j][k]=
                        (1-dx)*(1-dy)*image[i2  ][j2  ][0]+
                        (  dx)*(1-dy)*image[i2+1][j2  ][0]+
                        (  dx)*(dy)  *image[i2+1][j2+1][0]+
                        (1-dx)*(dy)  *image[i2  ][j2+1][0];

            }
        }
    }
}

/**
 *  IMAGE WARPING using SPLINES (only 2D for the moment)
 */
void ami_image_splinewarp(float ***image,ami_v3f ***u,float ***image_output,int dim_x,int dim_y, int dim_z, int spline_degree) 
{
    int i,j,k;
    float x,y,z;
    float *** image_coeff;

   if (dim_z==1) {
    // make a copy of the image for the spline coefficients
    ami_malloc3d(image_coeff,float,dim_x,dim_y,dim_z);
    ami_copy_3d(image,image_coeff,dim_x,dim_y,dim_z);
    ami_spline_SamplesToCoefficients2D(image_coeff,dim_x,dim_y,spline_degree);

    for(i=0;i<dim_x;i++) {
        for(j=0;j<dim_y;j++) {
            x=i+u[i][j][0][0];
            y=j+u[i][j][0][1];
            
            if(x<0) x=0;
            else if(x>dim_x-1) x=dim_x-1;
            if(y<0) y=0;
            else if(y>dim_y-1) y=dim_y-1;
            
            image_output[i][j][0] = ami_spline_InterpolatedValue2D(image_coeff,dim_x,dim_y,x,y,spline_degree);
        }
    }
  } else {
    // 3D interpolation
    // make a copy of the image for the spline coefficients
    ami_malloc3d(image_coeff,float,dim_x,dim_y,dim_z);
    ami_copy_3d(image,image_coeff,dim_x,dim_y,dim_z);
    ami_spline_SamplesToCoefficients3D(image_coeff,dim_x,dim_y,dim_z,spline_degree);

    for(i=0;i<dim_x;i++) {
        for(j=0;j<dim_y;j++) {
        for(k=0;k<dim_z;k++) {
            x=i+u[i][j][k][0];
            y=j+u[i][j][k][1];
            z=k+u[i][j][k][2];
            
            if(x<0) x=0;
            else if(x>dim_x-1) x=dim_x-1;
            if(y<0) y=0;
            else if(y>dim_y-1) y=dim_y-1;
            if(z<0) z=0;
            else if(z>dim_z-1) z=dim_z-1;
            
            image_output[i][j][k] = ami_spline_InterpolatedValue3D(image_coeff,dim_x,dim_y,dim_z,x,y,z,spline_degree);
        }
        }
    }
  }
  ami_free3d(image_coeff);
}


/**
 * 2D+T IMAGE INTERPOLATION (LINEAR METHOD)
 * positive version  
 * image_output(x,t)=image(x+u(x,t),t+1)
 */
void ami_image_interpolation_scal_2d_t_pos(float ***image,ami_v3f ***u,float ***image_output,int dim_x,int dim_y,int dim_t, int interpolation)
{
  int i,j,k,i2,j2;
  int i1,j1;
  float x,y,dx,dy;
  float *** image_coeff;
  int spline_degree=2;

  if (interpolation==1)
    ami_malloc3d(image_coeff,float,dim_x,dim_y,1);

  for(k=0;k<dim_t-1;k++)
  {
    if (interpolation==1) {
      // copy image at position k+1
      for(i1=0;i1<dim_x;i1++) 
      for(j1=0;j1<dim_y;j1++) 
        image_coeff[i1][j1][0] = image[i1][j1][k+1];
      ami_spline_SamplesToCoefficients2D(image_coeff,dim_x,dim_y,spline_degree);
    }
    for(i=0;i<dim_x;i++)
    {
      for(j=0;j<dim_y;j++)
      {
        x=i+u[i][j][k][0];
        y=j+u[i][j][k][1];

        if (interpolation==0)
        {
          GetLinearCoefficients(x,dim_x,&i2,&dx);
          GetLinearCoefficients(y,dim_y,&j2,&dy);
          image_output[i][j][k]=
            (1-dx)*(1-dy)*image[i2  ][j2  ][k+1]+
            (  dx)*(1-dy)*image[i2+1][j2  ][k+1]+
            (  dx)*(dy)  *image[i2+1][j2+1][k+1]+
            (1-dx)*(dy)  *image[i2  ][j2+1][k+1];
        }
        else
          if (interpolation==1)
          {
            if(x<0) x=0; else if(x>dim_x-1) x=dim_x-1;
            if(y<0) y=0; else if(y>dim_y-1) y=dim_y-1;

            image_output[i][j][k] = ami_spline_InterpolatedValue2D(image_coeff,dim_x,dim_y,x,y,spline_degree);
          }

      }
    }
  }

  if (interpolation==1)
    ami_free3d(image_coeff);

} // ami_image_interpolation_scal_2d_t_pos()

/**
 * 2D+T IMAGE INTERPOLATION (LINEAR METHOD)
 * negative version (for symmetric optical flow)
 * image_output(x,t)=image(x-u(x,t),t)
 */
void ami_image_interpolation_scal_2d_t_neg(float ***image,ami_v3f ***u,float ***image_output,int dim_x,int dim_y,int dim_t, int interpolation)
{
  int i,j,k,i2,j2,i1,j1;
  float x,y,dx,dy;
  float *** image_coeff;
  int spline_degree=2;

  if (interpolation==1)
    ami_malloc3d(image_coeff,float,dim_x,dim_y,1);

  for(k=0;k<dim_t-1;k++)
  {
    if (interpolation==1) {
      // copy image at position k
      for(i1=0;i1<dim_x;i1++) 
      for(j1=0;j1<dim_y;j1++) 
        image_coeff[i1][j1][0] = image[i1][j1][k];
      ami_spline_SamplesToCoefficients2D(image_coeff,dim_x,dim_y,spline_degree);
    }
    for(i=0;i<dim_x;i++)
    {
      for(j=0;j<dim_y;j++)
      {
        x=i-u[i][j][k][0];
        y=j-u[i][j][k][1];

        if (interpolation==0)
        {
          GetLinearCoefficients(x,dim_x,&i2,&dx);
          GetLinearCoefficients(y,dim_y,&j2,&dy);

          image_output[i][j][k]=
            (1-dx)*(1-dy)*image[i2  ][j2  ][k]+
            (  dx)*(1-dy)*image[i2+1][j2  ][k]+
            (  dx)*(dy)  *image[i2+1][j2+1][k]+
            (1-dx)*(dy)  *image[i2  ][j2+1][k];
        }
        else
          if (interpolation==1)
          {
            if(x<0) x=0; else if(x>dim_x-1) x=dim_x-1;
            if(y<0) y=0; else if(y>dim_y-1) y=dim_y-1;

            image_output[i][j][k] = ami_spline_InterpolatedValue2D(image_coeff,dim_x,dim_y,x,y,spline_degree);
          }

      }
    }
  }

  if (interpolation==1)
    ami_free3d(image_coeff);
} // ami_image_interpolation_scal_2d_t_neg()

/**
 *    3D IMAGE VECTOR POINT INTERPOLATION (BILINEAR METHOD)
 */
void ami_point_interpolation_v3f(
	ami_v3f ***image, /* ORIGINAL 3D IMAGE VECTOR */
	int i, int j, int k, /* POINT WHERE WE WANT TO APPLY THE INTERPOLATION */
    ami_v3f u,/* PIXEL DISPLACEMENT TO APPLY TO THE POINT OF THE ORIGINAL IMAGE VECTOR */
	ami_v3f v_out, /* VECTOR OUTPUT (at point+u) */
	int dim_x,int dim_y,int dim_z) /* IMAGE DIMENSIONS */
{
  //  printf("ami_image_interpolation_v3f %d %d %d \n",dim_x,dim_y,dim_z);
  int l,i2,j2,k2;
  float x,y,z,dx,dy,dz;

  x=i+u[0];
  y=j+u[1];
  z=k+u[2];
  GetLinearCoefficients(x,dim_x,&i2,&dx);
  GetLinearCoefficients(y,dim_y,&j2,&dy);

  if (dim_z>1)
  {
    GetLinearCoefficients(z,dim_z,&k2,&dz);
    for(l=0;l<3;l++)
    {
      v_out[l]=
        (1-dx)*(1-dy)*(1-dz)*image[i2  ][j2  ][k2  ][l]+
        (  dx)*(1-dy)*(1-dz)*image[i2+1][j2  ][k2  ][l]+
        (  dx)*(  dy)*(1-dz)*image[i2+1][j2+1][k2  ][l]+
        (  dx)*(  dy)*(  dz)*image[i2+1][j2+1][k2+1][l]+
        (  dx)*(1-dy)*(  dz)*image[i2+1][j2  ][k2+1][l]+
        (1-dx)*(  dy)*(1-dz)*image[i2  ][j2+1][k2  ][l]+
        (1-dx)*(  dy)*(  dz)*image[i2  ][j2+1][k2+1][l]+
        (1-dx)*(1-dy)*(  dz)*image[i2  ][j2  ][k2+1][l];
    }
  }
  else
  {
    for(l=0;l<2;l++)
    {
      v_out[l]=
        (1-dx)*(1-dy)*image[i2  ][j2  ][0][l]+
        (  dx)*(1-dy)*image[i2+1][j2  ][0][l]+
        (  dx)*(dy)  *image[i2+1][j2+1][0][l]+
        (1-dx)*(dy)  *image[i2  ][j2+1][0][l];
    }
    v_out[2]= 0;
  }
}


/****************************************************************************/
/*    3D IMAGE VECTOR INTERPOLATION (BILINEAR METHOD)                       */
void ami_image_interpolation_v3f(
    ami_v3f ***image, /* ORIGINAL 3D IMAGE VECTOR */
    ami_v3f ***u,/* PIXEL DISPLACEMENT TO APPLY TO THE ORIGINAL IMAGE VECTOR */
    ami_v3f ***image_output, /* IMAGE VECTOR OUTPUT (image+u) */
    int dim_x,int dim_y,int dim_z) /* IMAGE DIMENSIONS */
{

  //  printf("ami_image_interpolation_v3f %d %d %d \n",dim_x,dim_y,dim_z);
  int i,j,k,l,i2,j2,k2;
  float x,y,z,dx,dy,dz;
  for(i=0;i<dim_x;i++)
  {
    for(j=0;j<dim_y;j++)
    {
      for(k=0;k<dim_z;k++)
      {
        x=i+u[i][j][k][0];
        y=j+u[i][j][k][1];
        z=k+u[i][j][k][2];
        GetLinearCoefficients(x,dim_x,&i2,&dx);
        GetLinearCoefficients(y,dim_y,&j2,&dy);

        //      printf(" %d %d %d %f %f %f\n",i2,j2,k2,dx,dy,dz);
        if (dim_z>1)
        {
          GetLinearCoefficients(z,dim_z,&k2,&dz);
          for(l=0;l<3;l++)
          {
            image_output[i][j][k][l]=
              (1-dx)*(1-dy)*(1-dz)*image[i2  ][j2  ][k2  ][l]+
              (  dx)*(1-dy)*(1-dz)*image[i2+1][j2  ][k2  ][l]+
              (  dx)*(  dy)*(1-dz)*image[i2+1][j2+1][k2  ][l]+
              (  dx)*(  dy)*(  dz)*image[i2+1][j2+1][k2+1][l]+
              (  dx)*(1-dy)*(  dz)*image[i2+1][j2  ][k2+1][l]+
              (1-dx)*(  dy)*(1-dz)*image[i2  ][j2+1][k2  ][l]+
              (1-dx)*(  dy)*(  dz)*image[i2  ][j2+1][k2+1][l]+
              (1-dx)*(1-dy)*(  dz)*image[i2  ][j2  ][k2+1][l];
          }
        }
        else
        {
          for(l=0;l<2;l++)
          {
            image_output[i][j][k][l]=
              (1-dx)*(1-dy)*image[i2  ][j2  ][0][l]+
              (  dx)*(1-dy)*image[i2+1][j2  ][0][l]+
              (  dx)*(dy)  *image[i2+1][j2+1][0][l]+
              (1-dx)*(dy)  *image[i2  ][j2+1][0][l];
          }
          image_output[i][j][k][2]= 0;
        }
      }
    }
  }
  
  //    printf("ami_image_interpolation_v3f end\n");

}


/**
 *    Compute the image gradient at the position x+u, using spline interpolation 
 */
void ami_compute_splinegrad_v3f(float ***image,ami_v3f ***u,ami_v3f ***grad,int dim_x,int dim_y,int dim_z)
{
    int i,j,k;
    float x,y,z;
    float *** image_coeff;
    int spline_degree=2;
    float step=0.01;

    printf("ami_compute_splinegrad_v3f() \n");

   if (dim_z==1) {

    // make a copy of the image for the spline coefficients
    ami_malloc3d(image_coeff,float,dim_x,dim_y,dim_z);
    ami_copy_3d(image,image_coeff,dim_x,dim_y,dim_z);
    ami_spline_SamplesToCoefficients2D(image_coeff,dim_x,dim_y,spline_degree);

    for(i=0;i<dim_x;i++) {
        for(j=0;j<dim_y;j++) {
            x=i+u[i][j][0][0];
            y=j+u[i][j][0][1];
            
            if(x<0) x=0;
            else if(x>dim_x-1) x=dim_x-1;
            if(y<0) y=0;
            else if(y>dim_y-1) y=dim_y-1;
            if(z<0) z=0;
            else if(z>dim_z-1) z=dim_z-1;
            
            grad[i][j][k][0] = ami_spline_InterpolatedValue2D(image_coeff,dim_x,dim_y,x+step,y,spline_degree)-
                               ami_spline_InterpolatedValue2D(image_coeff,dim_x,dim_y,x-step,y,spline_degree);
            grad[i][j][k][1] = ami_spline_InterpolatedValue2D(image_coeff,dim_x,dim_y,x,y+step,spline_degree)-
                               ami_spline_InterpolatedValue2D(image_coeff,dim_x,dim_y,x,y-step,spline_degree);
            grad[i][j][k][0] = grad[i][j][0][0] / (2.0*step);
            grad[i][j][k][1] = grad[i][j][0][1] / (2.0*step);
            grad[i][j][k][2] = 0.0;
        }
    }
  } else {

  // 3D interpolation
    // make a copy of the image for the spline coefficients
    ami_malloc3d(image_coeff,float,dim_x,dim_y,dim_z);
    ami_copy_3d(image,image_coeff,dim_x,dim_y,dim_z);
    ami_spline_SamplesToCoefficients3D(image_coeff,dim_x,dim_y,dim_z,spline_degree);

    for(i=0;i<dim_x;i++) {
        for(j=0;j<dim_y;j++) {
          for(k=0;k<dim_z;k++) {
            x=i+u[i][j][k][0];
            y=j+u[i][j][k][1];
            z=k+u[i][j][k][1];
            
            if(x<0) x=0;
            else if(x>dim_x-1) x=dim_x-1;
            if(y<0) y=0;
            else if(y>dim_y-1) y=dim_y-1;
            if(z<0) z=0;
            else if(z>dim_z-1) z=dim_z-1;
            
            grad[i][j][k][0] = ami_spline_InterpolatedValue3D(image_coeff,dim_x,dim_y,dim_z,x+step,y,z,spline_degree)-
                               ami_spline_InterpolatedValue3D(image_coeff,dim_x,dim_y,dim_z,x-step,y,z,spline_degree);
            grad[i][j][k][1] = ami_spline_InterpolatedValue3D(image_coeff,dim_x,dim_y,dim_z,x,y+step,z,spline_degree)-
                               ami_spline_InterpolatedValue3D(image_coeff,dim_x,dim_y,dim_z,x,y-step,z,spline_degree);
            grad[i][j][k][2] = ami_spline_InterpolatedValue3D(image_coeff,dim_x,dim_y,dim_z,x,y,z+step,spline_degree)-
                               ami_spline_InterpolatedValue3D(image_coeff,dim_x,dim_y,dim_z,x,y,z-step,spline_degree);
            grad[i][j][k][0] = grad[i][j][k][0] / (2.0*step);
            grad[i][j][k][1] = grad[i][j][k][1] / (2.0*step);
            grad[i][j][k][2] = grad[i][j][k][2] / (2.0*step);
        }
    }
    }

  }
  
  ami_free3d(image_coeff);
} // ami_compute_splinegrad_v3f()


/**
 * 2D+T IMAGE VECTOR INTERPOLATION (LINEAR METHOD)
 * positive version  
 * image_output(x,t)=image(x+u(x,t),t+1)
 */
void ami_image_interpolation_vect_2d_t_pos(ami_v3f ***image,ami_v3f ***u,ami_v3f ***image_output,int dim_x,int dim_y,int dim_t)
{
  int i,j,k,l,i2,j2;
  float x,y,dx,dy;
  for(i=0;i<dim_x;i++)
  {
    for(j=0;j<dim_y;j++)
    {
      for(k=0;k<dim_t-1;k++)
      {
        x=i+u[i][j][k][0];
        y=j+u[i][j][k][1];
        GetLinearCoefficients(x,dim_x,&i2,&dx);
        GetLinearCoefficients(y,dim_y,&j2,&dy);

        for(l=0;l<2;l++)
        {
          image_output[i][j][k][l]=
            (1-dx)*(1-dy)*image[i2  ][j2  ][k+1][l]+
            (  dx)*(1-dy)*image[i2+1][j2  ][k+1][l]+
            (  dx)*(dy)  *image[i2+1][j2+1][k+1][l]+
            (1-dx)*(dy)  *image[i2  ][j2+1][k+1][l];
        }
        image_output[i][j][k][2]= 0;
      }
    }
  }
} // ami_image_interpolation_vect_2d_t_pos()

/**
 * 2D+T IMAGE VECTOR INTERPOLATION (LINEAR METHOD)
 * negative version (for symmetric optical flow)
 * image_output(x,t)=image(x-u(x,t),t)
 */
void ami_image_interpolation_vect_2d_t_neg(ami_v3f ***image,ami_v3f ***u,ami_v3f ***image_output,int dim_x,int dim_y,int dim_t)
{
  int i,j,k,l,i2,j2;
  float x,y,dx,dy;
  for(i=0;i<dim_x;i++)
  {
    for(j=0;j<dim_y;j++)
    {
      for(k=0;k<dim_t-1;k++)
      {
        x=i-u[i][j][k][0];
        y=j-u[i][j][k][1];
        GetLinearCoefficients(x,dim_x,&i2,&dx);
        GetLinearCoefficients(y,dim_y,&j2,&dy);

        for(l=0;l<2;l++)
        {
          image_output[i][j][k][l]=
            (1-dx)*(1-dy)*image[i2  ][j2  ][k][l]+
            (  dx)*(1-dy)*image[i2+1][j2  ][k][l]+
            (  dx)*(dy)  *image[i2+1][j2+1][k][l]+
            (1-dx)*(dy)  *image[i2  ][j2+1][k][l];
        }
        image_output[i][j][k][2]= 0;
      }
    }
  }
} // ami_image_interpolation_vect_2d_t_neg()


/**
 *    Compute the image gradient at the position x+u, using spline interpolation 
 *    at (x+u(x,t),t+1)
 */
void ami_compute_splinegrad_2d_t_pos(float ***image,ami_v3f ***u,ami_v3f ***grad,int dim_x,int dim_y,int dim_t)
{
  int i,j,k,i1,j1;
  float x,y;
  float *** image_coeff;
  int spline_degree=2;
  float step=0.01;

  printf("ami_compute_splinegrad_2d_t_pos() \n");

  // make a copy of the image for the spline coefficients
  ami_malloc3d(image_coeff,float,dim_x,dim_y,1);

  for(k=0;k<dim_t-1;k++)
  {
    // copy image at position k+1
    for(i1=0;i1<dim_x;i1++)
      for(j1=0;j1<dim_y;j1++)
        image_coeff[i1][j1][0] = image[i1][j1][k+1];
    ami_spline_SamplesToCoefficients2D(image_coeff,dim_x,dim_y,spline_degree);

    for(i=0;i<dim_x;i++)
    {
      for(j=0;j<dim_y;j++)
      {
        x=i+u[i][j][k][0];
        y=j+u[i][j][k][1];

        if(x<0) x=0;
        else if(x>dim_x-1) x=dim_x-1;
        if(y<0) y=0;
        else if(y>dim_y-1) y=dim_y-1;

        grad[i][j][k][0] = ami_spline_InterpolatedValue2D(image_coeff,dim_x,dim_y,x+step,y,spline_degree)-
                           ami_spline_InterpolatedValue2D(image_coeff,dim_x,dim_y,x-step,y,spline_degree);
        grad[i][j][k][1] = ami_spline_InterpolatedValue2D(image_coeff,dim_x,dim_y,x,y+step,spline_degree)-
                           ami_spline_InterpolatedValue2D(image_coeff,dim_x,dim_y,x,y-step,spline_degree);
        grad[i][j][k][0] = grad[i][j][k][0] / (2.0*step);
        grad[i][j][k][1] = grad[i][j][k][1] / (2.0*step);
        grad[i][j][k][2] = 0.0;
      } // for j
    } // for i
  } // for k

    ami_free3d(image_coeff);

}
  
/**
 *    Compute the image gradient at the position x+u, using spline interpolation 
 *    at (x-u(x,t),t)
 */
void ami_compute_splinegrad_2d_t_neg(float ***image,ami_v3f ***u,ami_v3f ***grad,int dim_x,int dim_y,int dim_t)
{
  int i,j,k,i1,j1;
  float x,y;
  float *** image_coeff;
  int spline_degree=2;
  float step=0.01;

  printf("ami_compute_splinegrad_2d_t_neg() \n");

  // make a copy of the image for the spline coefficients
  ami_malloc3d(image_coeff,float,dim_x,dim_y,1);

  for(k=0;k<dim_t-1;k++)
  {
    // copy image at position k+1
    for(i1=0;i1<dim_x;i1++)
      for(j1=0;j1<dim_y;j1++)
        image_coeff[i1][j1][0] = image[i1][j1][k];
    ami_spline_SamplesToCoefficients2D(image_coeff,dim_x,dim_y,spline_degree);

    for(i=0;i<dim_x;i++)
    {
      for(j=0;j<dim_y;j++)
      {
        x=i-u[i][j][k][0];
        y=j-u[i][j][k][1];

        if(x<0) x=0;
        else if(x>dim_x-1) x=dim_x-1;
        if(y<0) y=0;
        else if(y>dim_y-1) y=dim_y-1;

        grad[i][j][k][0] = ami_spline_InterpolatedValue2D(image_coeff,dim_x,dim_y,x+step,y,spline_degree)-
                           ami_spline_InterpolatedValue2D(image_coeff,dim_x,dim_y,x-step,y,spline_degree);
        grad[i][j][k][1] = ami_spline_InterpolatedValue2D(image_coeff,dim_x,dim_y,x,y+step,spline_degree)-
                           ami_spline_InterpolatedValue2D(image_coeff,dim_x,dim_y,x,y-step,spline_degree);
        grad[i][j][k][0] = grad[i][j][k][0] / (2.0*step);
        grad[i][j][k][1] = grad[i][j][k][1] / (2.0*step);
        grad[i][j][k][2] = 0.0;
      } // for j
    } // for i
  } // for k

    ami_free3d(image_coeff);

}


/**
 * 3D HESSIAN INTERPOLATION (LINEAR METHOD)
 * at the point (x,y,z)+ u(z,y,z)
 * image: hessian image
 * u       : displacement field
 * res     : interpolated hessian matrix at u+(x,y,z)
 * (x,y,z) : current position
 * (dim_x,dim_y,dim_z) : image dimension
 */
void ami_hessian_interpolation(ami_m3x3f ***image,ami_v3f ***u,ami_m3x3f* res,int x, int y, int z, int dim_x,int dim_y,int dim_z)
{
  float x1,y1,z1; // displaced point : (x,y,z)+u
  float dx,dy,dz;
  int xi,yi,zi;
  int i,j;
  
  
  x1=x+u[x][y][z][0];
  y1=y+u[x][y][z][1];
  z1=z+u[x][y][z][2];
  
  dx=dy=dz=0.0;
  xi = (int) x1;
  yi = (int) y1;
  zi = (int) z1;
  
  if(x1<0) xi=0; else  if (x1>=(dim_x-1)) {xi=dim_x-2;dx=1.0;} else dx=x1-xi;
  
  if(y1<0)  yi=0; else if (y1>=(dim_y-1)) {yi=dim_y-2;dy=1.0;} else dy=y1-yi;

  if(z1<0)  zi=0; else if (z1>=(dim_z-1)) {zi=dim_z-2;dz=1.0;} else dz=z1-xi;
  
  if (dim_z>1) {
    for(i=0;i<3;i++) 
    for(j=i;j<3;j++) {
      (*res)[i][j]=
	(1-dx)*(1-dy)*(1-dz)*image[xi  ][yi  ][zi  ][i][j]+
	(  dx)*(1-dy)*(1-dz)*image[xi+1][yi  ][zi  ][i][j]+
	(  dx)*(  dy)*(1-dz)*image[xi+1][yi+1][zi  ][i][j]+
	(  dx)*(  dy)*(  dz)*image[xi+1][yi+1][zi+1][i][j]+
	(  dx)*(1-dy)*(  dz)*image[xi+1][yi  ][zi+1][i][j]+
	(1-dx)*(  dy)*(1-dz)*image[xi  ][yi+1][zi  ][i][j]+
	(1-dx)*(  dy)*(  dz)*image[xi  ][yi+1][zi+1][i][j]+
	(1-dx)*(1-dy)*(  dz)*image[xi  ][yi  ][zi+1][i][j];
      if (i!=j) (*res)[j][i]=(*res)[i][j];
    }
  } else {
      for(i=0;i<2;i++) 
      for(j=i;j<2;j++) {
	(*res)[i][j] =
	    (1-dx)*(1-dy)*image[xi  ][yi  ][0][i][j]+
	    (  dx)*(1-dy)*image[xi+1][yi  ][0][i][j]+
	    (  dx)*(dy)  *image[xi+1][yi+1][0][i][j]+
	    (1-dx)*(dy)  *image[xi  ][yi+1][0][i][j];
	if (i!=j) (*res)[j][i]=(*res)[i][j];
      }
  }


}

/**
 * FUNCTION TO FILL THE BOUNDARY VALUES OF A 3D VECTOR IMAGE
 * THE BOUNDARY VALUE IS ASSIGNED TO BE EQUAL TO THE NEAREST INTERIOR PIXEL VALUE 
 */
void ami_boundary_v3f(ami_v3f ***grad_image,int dim_x,int dim_y,int dim_z) {
    int i,j,k;

    for(j=0;j<dim_y;j++) {
        for(k=0;k<dim_z;k++) {
            grad_image[0][j][k][0]=grad_image[1][j][k][0];
            grad_image[0][j][k][1]=grad_image[1][j][k][1];
            grad_image[0][j][k][2]=grad_image[1][j][k][2];
            grad_image[dim_x-1][j][k][0]=grad_image[dim_x-2][j][k][0];
            grad_image[dim_x-1][j][k][1]=grad_image[dim_x-2][j][k][1];
            grad_image[dim_x-1][j][k][2]=grad_image[dim_x-2][j][k][2];
        }
    }
    for(i=0;i<dim_x;i++) {
        for(k=0;k<dim_z;k++) {
            grad_image[i][0][k][0]=grad_image[i][1][k][0];
            grad_image[i][0][k][1]=grad_image[i][1][k][1];
            grad_image[i][0][k][2]=grad_image[i][1][k][2];
            grad_image[i][dim_y-1][k][0]=grad_image[i][dim_y-2][k][0];
            grad_image[i][dim_y-1][k][1]=grad_image[i][dim_y-2][k][1];
            grad_image[i][dim_y-1][k][2]=grad_image[i][dim_y-2][k][2];
        }
    }
    
    if (dim_z>1) {
      for(j=0;j<dim_y;j++) {
          for(i=0;i<dim_x;i++) {
              grad_image[i][j][0][0]=grad_image[i][j][1][0];
              grad_image[i][j][0][1]=grad_image[i][j][1][1];
              grad_image[i][j][0][2]=grad_image[i][j][1][2];
              grad_image[i][j][dim_z-1][0]=grad_image[i][j][dim_z-2][0];
              grad_image[i][j][dim_z-1][1]=grad_image[i][j][dim_z-2][1];
              grad_image[i][j][dim_z-1][2]=grad_image[i][j][dim_z-2][2];
          } 
      }
    }
}

/**
 * FUNCTION TO FILL THE BOUNDARY VALUES OF A 2D+T VECTOR IMAGE
 * THE BOUNDARY VALUE IS ASSIGNED TO BE EQUAL TO THE NEAREST INTERIOR PIXEL VALUE 
 */
void ami_boundary_vect_2d_t(ami_v3f ***grad_image,int dim_x,int dim_y,int dim_t) {
  int i,j,k;

  for(j=0;j<dim_y;j++) {
    for(k=0;k<dim_t;k++) {
      grad_image[0][j][k][0]=grad_image[1][j][k][0];
      grad_image[0][j][k][1]=grad_image[1][j][k][1];
      grad_image[0][j][k][2]=grad_image[1][j][k][2];
      grad_image[dim_x-1][j][k][0]=grad_image[dim_x-2][j][k][0];
      grad_image[dim_x-1][j][k][1]=grad_image[dim_x-2][j][k][1];
      grad_image[dim_x-1][j][k][2]=grad_image[dim_x-2][j][k][2];
    }
  }
  for(i=0;i<dim_x;i++) {
    for(k=0;k<dim_t;k++) {
      grad_image[i][0][k][0]=grad_image[i][1][k][0];
      grad_image[i][0][k][1]=grad_image[i][1][k][1];
      grad_image[i][0][k][2]=grad_image[i][1][k][2];
      grad_image[i][dim_y-1][k][0]=grad_image[i][dim_y-2][k][0];
      grad_image[i][dim_y-1][k][1]=grad_image[i][dim_y-2][k][1];
      grad_image[i][dim_y-1][k][2]=grad_image[i][dim_y-2][k][2];
    }
  }
} //ami_boundary_vect_2d_t()

/**
 * FUNCTION TO FILL THE DISPLACEMENT VALUES OF A 2D+T VECTOR IMAGE AT PIXELS
 * WHICH FALL OUTSIDE THE IMAGE
 */
void ami_fill_border_mask_2d_t(ami_v3f ***h,int dim_x,int dim_y,int dim_p,unsigned char ***border_mask)
{
  unsigned char*** mask1;
  unsigned char* mask1_buf;
  unsigned char*** mask2;
  int nb_borderpoints;
  int nb_neighbors;
  int i,j,k,i1,j1;
  int im,ip,jm,jp;
  double valx,valy;

  ami_malloc3d(mask1,unsigned char,dim_x,dim_y,dim_p);
  ami_malloc3d(mask2,unsigned char,dim_x,dim_y,dim_p);

  memcpy(mask1[0][0],border_mask[0][0],dim_x*dim_y*dim_p);
  memcpy(mask2[0][0],border_mask[0][0],dim_x*dim_y*dim_p); 


  do {
    nb_borderpoints=0;
    mask1_buf = mask1[0][0];
    for(i=0;i<dim_x;i++) {
        if (i==0)       im=0; else im=i-1;
        if (i==dim_x-1) ip = dim_x-1; else ip = i+1;
        for(j=0;j<dim_y;j++) {
            if (j==0)       jm=0; else jm=j-1;
            if (j==dim_y-1) jp = dim_y-1; else jp = j+1;
            for(k=0;k<dim_p;k++,mask1_buf++) {
                if (*mask1_buf==0) {
                    // check neighbors
                    nb_neighbors=0;
                    valx=valy=0.0;
                    for(i1=im;i1<=ip;i1++)
                    for(j1=jm;j1<=jp;j1++) {
                        if (mask1[i1][j1][k]>0) {
                            // found a neighbor within the mask
                            nb_neighbors++;
                            valx += h[i1][j1][k][0];
                            valy += h[i1][j1][k][1];
                        }
                    }
                    if (nb_neighbors>0) {
                        h[i][j][k][0] = valx / (1.0*nb_neighbors);
                        h[i][j][k][1] = valy / (1.0*nb_neighbors);
                        mask2[i][j][k] = 1;
                        //printf("%d %d %d \t %f %f \n",i,j,k,h[i][j][k][0],h[i][j][k][1]);
                    } else 
                        nb_borderpoints++;
                }
            } // for k
        }
    }
    memcpy(mask1[0][0],mask2[0][0],dim_x*dim_y*dim_p);
    //printf("nb_borderpoints %d \n",nb_borderpoints);
  } while (nb_borderpoints>0);


  ami_free3d(mask1);
  ami_free3d(mask2);
} // ami_fill_border_mask_2d_t()



/**
* CREATES A MASK IMAGE WITH VALUE 1 for pixels (or voxels) which vector 
* points inside the domain
*/
void ami_create_border_mask_2d_t( unsigned char ***border_mask, ami_v3f ***up,int dim_x2, int dim_y2, int dim_p, unsigned char symmetric)

{
  // compute the border_mask image
  int i,j,k;
  float x1,y1;
  float margin=1.0;
  for(i=0;i<dim_x2;i++)
    for(j=0;j<dim_y2;j++)
      for(k=0;k<dim_p;k++)
      {
        if (!symmetric)
        {
          x1 = (float) i + up[i][j][k][0];
          y1 = (float) j + up[i][j][k][1];
          border_mask[i][j][k] = (x1>margin)&&(y1>margin)&&(x1<=dim_x2-1-margin)&&(y1<dim_y2-1-margin);
        }
        else
        {
          x1 = (float) i + up[i][j][k][0]/2.0;
          y1 = (float) j + up[i][j][k][1]/2.0;
          border_mask[i][j][k] = (x1>margin) && (y1>margin) && (x1<=dim_x2-1-margin) && (y1<dim_y2-1-margin);
          x1 = (float) i - up[i][j][k][0]/2.0;
          y1 = (float) j - up[i][j][k][1]/2.0;
          border_mask[i][j][k] = border_mask[i][j][k] && (x1>margin) && (y1>margin) && (x1<=dim_x2-1-margin) && (y1<dim_y2-1-margin);
        }
      }
} // ami_create_border_mask_2d_t()


/**
* CREATES A MASK IMAGE WITH VALUE 1 for pixels (or voxels) which vector 
* points inside the domain
*/
void ami_create_border_mask( unsigned char ***border_mask, ami_v3f ***up,int dim_x2, int dim_y2, int dim_z2, unsigned char symmetric)

{
  // compute the border_mask image
  int i,j,k;
  float x1,y1,z1;
  float margin=1.0;
  for(i=0;i<dim_x2;i++)
    for(j=0;j<dim_y2;j++)
      for(k=0;k<dim_z2;k++)
      {
        if (!symmetric)
        {
          x1 = (float) i + up[i][j][k][0];
          y1 = (float) j + up[i][j][k][1];
          z1 = (float) k + up[i][j][k][2];
          border_mask[i][j][k] = (x1>margin)&&(y1>margin)&&(x1<=dim_x2-1-margin)&&(y1<dim_y2-1-margin);
          if (dim_z2>2*margin)
            border_mask[i][j][k] = border_mask[i][j][k] && (z1>margin) && (z1<dim_z2-1-margin);
        }
        else
        {
          x1 = (float) i + up[i][j][k][0]/2.0;
          y1 = (float) j + up[i][j][k][1]/2.0;
          z1 = (float) k + up[i][j][k][2]/2.0;
          border_mask[i][j][k] = (x1>margin) && (y1>margin) && (x1<=dim_x2-1-margin) && (y1<dim_y2-1-margin);
          if (dim_z2>2*margin)
            border_mask[i][j][k] = border_mask[i][j][k] && (z1>margin) && (z1<dim_z2-1-margin);
          x1 = (float) i - up[i][j][k][0]/2.0;
          y1 = (float) j - up[i][j][k][1]/2.0;
          z1 = (float) k - up[i][j][k][2]/2.0;
          border_mask[i][j][k] = border_mask[i][j][k] && (x1>margin) && (y1>margin) && (x1<=dim_x2-1-margin) && (y1<dim_y2-1-margin);
          if (dim_z2>2*margin)
            border_mask[i][j][k] = border_mask[i][j][k] && (z1>margin) && (z1<dim_z2-1-margin);
        }
      }
} // ami_create_border_mask()

/**
 * FUNCTION TO FILL THE DISPLACEMENT VALUES OF A 2D or 3D VECTOR IMAGE AT PIXELS
 * WHICH FALL OUTSIDE THE IMAGE
 */
void ami_fill_border_mask(ami_v3f ***h,int dim_x,int dim_y, int dim_z,unsigned char ***border_mask)
{
  unsigned char*** mask1;
  unsigned char* mask1_buf;
  unsigned char*** mask2;
  int nb_borderpoints;
  int nb_neighbors;
  int i,j,k,i1,j1,k1;
  int im,ip,jm,jp,km,kp;
  double valx,valy,valz;

  ami_malloc3d(mask1,unsigned char,dim_x,dim_y,dim_z);
  ami_malloc3d(mask2,unsigned char,dim_x,dim_y,dim_z);

  memcpy(mask1[0][0],border_mask[0][0],dim_x*dim_y*dim_z);
  memcpy(mask2[0][0],border_mask[0][0],dim_x*dim_y*dim_z); 


  do {
    nb_borderpoints=0;
    mask1_buf = mask1[0][0];
    for(i=0;i<dim_x;i++) {
        if (i==0)       im=0; else im=i-1;
        if (i==dim_x-1) ip = dim_x-1; else ip = i+1;
        for(j=0;j<dim_y;j++) {
            if (j==0)       jm=0; else jm=j-1;
            if (j==dim_y-1) jp = dim_y-1; else jp = j+1;
            for(k=0;k<dim_z;k++,mask1_buf++) {
              if (k==0)       km=0; else km=k-1;
              if (k==dim_z-1) kp = dim_z-1; else kp = k+1;
                if (*mask1_buf==0) {
                    // check neighbors
                    nb_neighbors=0;
                    valx=valy=valz=0.0;
                    for(i1=im;i1<=ip;i1++)
                    for(j1=jm;j1<=jp;j1++) 
                    for(k1=km;k1<=kp;k1++) {
                        if (mask1[i1][j1][k1]>0) {
                            // found a neighbor within the mask
                            nb_neighbors++;
                            valx += h[i1][j1][k1][0];
                            valy += h[i1][j1][k1][1];
                            valz += h[i1][j1][k1][2];
                        }
                    }
                    if (nb_neighbors>0) {
                        h[i][j][k][0] = valx / (1.0*nb_neighbors);
                        h[i][j][k][1] = valy / (1.0*nb_neighbors);
                        h[i][j][k][2] = valz / (1.0*nb_neighbors);
                        mask2[i][j][k] = 1;
                        //printf("%d %d %d \t %f %f \n",i,j,k,h[i][j][k][0],h[i][j][k][1]);
                    } else 
                        nb_borderpoints++;
                }
            } // for k
        }
    }
    memcpy(mask1[0][0],mask2[0][0],dim_x*dim_y*dim_z);
    //printf("nb_borderpoints %d \n",nb_borderpoints);
  } while (nb_borderpoints>0);


  ami_free3d(mask1);
  ami_free3d(mask2);
} // ami_fill_border_mask()


/**
 *  m1 = m2
 */
void ami_copy_m3x3f(ami_m3x3f* m1, ami_m3x3f* m2)
{
  int i,j;
  
  for (i=0;i<3;i++) for (j=0;j<3;j++) (*m1)[i][j] = (*m2)[i][j];
}

/**
 * FUNCTION TO FILL THE BOUNDARY VALUES OF A 3D MATRIX IMAGE
 */
void ami_boundary_m3x3f(ami_m3x3f ***mat_image,int dim_x,int dim_y,int dim_z)
{
  int i,j,k;

  for(j=0;j<dim_y;j++) {
    for(k=0;k<dim_z;k++) {
      ami_copy_m3x3f(&mat_image[0]      [j][k],&mat_image[1]      [j][k]);
      ami_copy_m3x3f(&mat_image[dim_x-1][j][k],&mat_image[dim_x-2][j][k]);
    }
  }
  for(i=0;i<dim_x;i++) {
    for(k=0;k<dim_z;k++) {
      ami_copy_m3x3f(&mat_image[i][0]      [k],&mat_image[i][1]      [k]);
      ami_copy_m3x3f(&mat_image[i][dim_y-1][k],&mat_image[i][dim_y-2][k]);
    }
  }
    
  if (dim_z>1) {
    for(j=0;j<dim_y;j++) {
      for(i=0;i<dim_x;i++) {
	ami_copy_m3x3f(&mat_image[i][j][0],      &mat_image[i][j][1]      );
	ami_copy_m3x3f(&mat_image[i][j][dim_z-1],&mat_image[i][j][dim_z-2]);
      }
    }
  }
} // ami_boundary_m3x3f()


/****************************************************************************/
/* FUNCTION TO FILL THE BOUNDARY VALUES OF A 3D IMAGE
   THE BOUNDARY VALUE IS ASSIGNED TO BE EQUAL TO THE NEAREST INTERIOR PIXEL VALUE */
void ami_boundary_3df(float ***image,int dim_x,int dim_y,int dim_z)
{
	int i,j,k;
	for(j=0;j<dim_y;j++){
		for(k=0;k<dim_z;k++){
			image[0][j][k]=image[1][j][k];
			image[dim_x-1][j][k]=image[dim_x-2][j][k];
		}
	}
	for(i=0;i<dim_x;i++){
		for(k=0;k<dim_z;k++){
			image[i][0][k]=image[i][1][k];
			image[i][dim_y-1][k]=image[i][dim_y-2][k];
		}
	}
	for(j=0;j<dim_y;j++){
		for(i=0;i<dim_x;i++){
			image[i][j][0]=image[i][j][1];
			image[i][j][dim_z-1]=image[i][j][dim_z-2];
		}
	}
}

/**
* BASIC COMPUTATION OF 3D IMAGE GRADIENT 
*/
void ami_grad_3d(
    float ***image,/* ORIGINAL IMAGE */
    ami_v3f ***grad_image,/* OUTPUT 3D IMAGE GRADIENT VECTOR */
    int dim_x,int dim_y,int dim_z) /* IMAGE DIMENSIONS */
{
    int i,j,k;
    int dim_x_1=dim_x-1;
    int dim_y_1=dim_y-1;
    int dim_z_1=dim_z-1;
    float d1,d2;

    //    printf("ami_grad_3d \n");

    if (dim_z>1) {
      for(i=1;i<dim_x_1;i++) {
         for(j=1;j<dim_y_1;j++) {
            for(k=1;k<dim_z_1;k++) {
                    d1=image[i+1][j][k]-image[i][j][k];
                    d2=image[i][j][k]-image[i-1][j][k];
                    grad_image[i][j][k][0]=(fabs(d1)>fabs(d2))?d1:d2;
                    d1=image[i][j+1][k]-image[i][j][k];
                    d2=image[i][j][k]-image[i][j-1][k];
                    grad_image[i][j][k][1]=(fabs(d1)>fabs(d2))?d1:d2;
                    d1=image[i][j][k+1]-image[i][j][k];
                    d2=image[i][j][k]-image[i][j][k-1];
                    grad_image[i][j][k][2]=(fabs(d1)>fabs(d2))?d1:d2;
               }
            }
        }
    } else
        for(i=1;i<dim_x_1;i++) {
            for(j=1;j<dim_y_1;j++) {
                // x
                d1=image[i+1][j][0]-image[i][j][0];
                d2=image[i][j][0]-image[i-1][j][0];
                grad_image[i][j][0][0]=(fabs(d1)>fabs(d2))?d1:d2;
                // y
                d1=image[i][j+1][0]-image[i][j][0];
                d2=image[i][j][0]-image[i][j-1][0];
                grad_image[i][j][0][1]=(fabs(d1)>fabs(d2))?d1:d2;
                // z
                grad_image[i][j][0][2]=0;
            }
        }

    /* BOUNDARY DEFINITION */
    ami_boundary_v3f(grad_image,dim_x,dim_y,dim_z);
}
 
/**
* BASIC COMPUTATION OF 2D+T IMAGE GRADIENT 
*/
 void ami_grad_2d_t(
    float ***image,/* ORIGINAL IMAGE */
    ami_v3f ***grad_image,/* OUTPUT 3D IMAGE GRADIENT VECTOR */
    int dim_x,int dim_y,int dim_t) /* IMAGE DIMENSIONS */
{
  int i,j,k;
  int dim_x_1=dim_x-1;
  int dim_y_1=dim_y-1;
  float d1,d2;

    for(i=1;i<dim_x_1;i++) {
      for(j=1;j<dim_y_1;j++) {
	for(k=0;k<dim_t;k++) {
	  d1=image[i+1][j][k]-image[i][j][k];
	  d2=image[i][j][k]-image[i-1][j][k];
	  grad_image[i][j][k][0]=(fabs(d1)>fabs(d2))?d1:d2;
	  d1=image[i][j+1][k]-image[i][j][k];
	  d2=image[i][j][k]-image[i][j-1][k];
	  grad_image[i][j][k][1]=(fabs(d1)>fabs(d2))?d1:d2;
	  grad_image[i][j][k][2]=0;
//	  printf("grad_2d_t: (%d %d %d)  %f %f\n",i,j,k,grad_image[i][j][k][0],
//		grad_image[i][j][k][1]); 
	}
      }
    }

    /* BOUNDARY DEFINITION */
    ami_boundary_vect_2d_t(grad_image,dim_x,dim_y,dim_t);
} // ami_grad_2d_t()
 

/**
 * COMPUTATION OF 3D IMAGE GRADIENT  3x3x3 mask
 */
void ami_grad_3d_3x3x3(float ***image,ami_v3f ***grad_image,int dim_x,int dim_y,int dim_z)
{
  // 3D version not yet available
  if (dim_z>1) 
    ami_grad_3d(image,grad_image,dim_x,dim_y,dim_z);
  else {
    int i,j;
    double coef1,coef2;
    coef1=sqrt((double) 2.);
    coef2=0.25*(2.-coef1);
    coef1=0.5*(coef1-1);
    /* WE COMPUTE THE DERIVATIVES */
    for(i=1;i<(dim_x-1);i++){
      for(j=1;j<(dim_y-1);j++){
	grad_image[i][j][0][0]=coef1*(image[i+1][j][0]-image[i-1][j][0])+
	    coef2*(image[i+1][j+1][0]-image[i-1][j+1][0]+image[i+1][j-1][0]-image[i-1][j-1][0]);        ;
	grad_image[i][j][0][1]=coef1*(image[i][j+1][0]-image[i][j-1][0])+
	    coef2*(image[i+1][j+1][0]-image[i+1][j-1][0]+image[i-1][j+1][0]-image[i-1][j-1][0]);
	grad_image[i][j][0][2]=0.0;
      }
    }
    /* BOUNDARY DEFINITION */
    ami_boundary_v3f(grad_image,dim_x,dim_y,dim_z);
  }
}


/**
 * BASIC COMPUTATION OF 3D HESSIAN IMAGE 
 */
void ami_hessian_3d(float ***image,ami_m3x3f ***h_image,int dim_x,int dim_y,int dim_z)
{
  int i,j,k;
  int dim_x_1=dim_x-1;
  int dim_y_1=dim_y-1;
  int dim_z_1=dim_z-1;
  float tmp;

  if (dim_z>1) {
    for(i=1;i<dim_x_1;i++) {
      for(j=1;j<dim_y_1;j++) {
	for(k=1;k<dim_z_1;k++) {
	  tmp = 2*image[i][j][k];
	  // diagonal first:
	  h_image[i][j][k][0][0]=image[i+1][j  ][k  ]-tmp+image[i-1][j  ][k  ];
	  h_image[i][j][k][1][1]=image[i  ][j+1][k  ]-tmp+image[i  ][j-1][k  ];
	  h_image[i][j][k][2][2]=image[i  ][j  ][k+1]-tmp+image[i  ][j  ][k-1];
	  // other elements:
	  h_image[i][j][k][0][1]=0.25*((image[i+1][j+1][k  ]-image[i+1][j-1][k  ]) -
	                               (image[i-1][j+1][k  ]-image[i-1][j-1][k  ]));
	  h_image[i][j][k][1][0]= h_image[i][j][k][0][1];
	  
	  h_image[i][j][k][0][2]=0.25*((image[i+1][j][k+1]-image[i+1][j][k-1]) -
	                               (image[i-1][j][k+1]-image[i-1][j][k-1]));
	  h_image[i][j][k][2][0]= h_image[i][j][k][0][2];
	  
	  h_image[i][j][k][1][2]=0.25*((image[i][j+1][k+1]-image[i][j+1][k-1]) -
	                               (image[i][j-1][k+1]-image[i][j-1][k-1]));
	  h_image[i][j][k][2][1]= h_image[i][j][k][1][2];
	}
      }
    }
  } else
    /* 2D version */
    for(i=1;i<dim_x_1;i++) {
      for(j=1;j<dim_y_1;j++) {
	tmp = 2*image[i][j][0];
	// diagonal first:
	h_image[i][j][0][0][0]=image[i+1][j  ][0]-tmp+image[i-1][j  ][0];
	h_image[i][j][0][1][1]=image[i  ][j+1][0]-tmp+image[i  ][j-1][0];
	  // other elements:
	h_image[i][j][0][0][1]=0.25*((image[i+1][j+1][0]-image[i+1][j-1][0]) -
	    (image[i-1][j+1][0]-image[i-1][j-1][0]));
	h_image[i][j][0][1][0]= h_image[i][j][0][0][1];
	  
	h_image[i][j][0][2][2]=0;
	h_image[i][j][0][0][2]=
	h_image[i][j][0][2][0]=
	h_image[i][j][0][1][2]=
        h_image[i][j][0][2][1]= 0;
      }
    }

    /* BOUNDARY DEFINITION */
    ami_boundary_m3x3f(h_image,dim_x,dim_y,dim_z);

} // ami_hessian_3d()

/**
 * FUNCTION TO COPY A 3D IMAGE
 */
void ami_copy_3d(
    float ***image_1, /* ORIGINAL IMAGE */
    float ***image_2, /* OUTPUT IMAGE */
    int dim_x,int dim_y,int dim_z) /* IMAGE DIMENSIONS */
{

    memcpy(image_2[0][0],image_1[0][0],(long)dim_x*dim_y*dim_z*sizeof(float));

}


/**
 * FUNCTION TO COPY A 3D IMAGE VECTOR
 */
void ami_copy_v3f(
    ami_v3f ***image_grad_1,/* ORIGINAL 3D IMAGE VECTOR */
    ami_v3f ***image_grad_2,/* OUTPUT 3D IMAGE VECTOR */
    int dim_x,int dim_y,int dim_z) /* IMAGE DIMENSIONS */
{
  memcpy(image_grad_2[0][0],image_grad_1[0][0],(long)dim_x*dim_y*dim_z*sizeof(ami_v3f));
  
}


/**
 * BASIC CONVOLUTION OF A 3D IMAGE
 */
void ami_convolution_3d(
    float ***image,/* ORIGINAL AND OUTPUT IMAGE */
    float beta[3], /* CONVOLUTION PARAMETER  beta*(image[i+1]+image[i-1]+(1-2*beta)*image[i])
        	WE COMPUTE ITERATIVELY THE CONVOLUTIONIN THE 3 AXES */
    int dim_x,int dim_y,int dim_z) /* IMAGE DIMENSIONS */
{
    int dim_x_1=dim_x-1;
    int dim_y_1=dim_y-1;
    int dim_z_1=dim_z-1;
    int i,j,k,l;
    float ***image_paso;
    double a_0[3],a_1[3];
    /* WE DEFINE WEIGHTS FOR THE CONVOLUTION */
    for(l=0;l<3;l++) {
        a_0[l]=(1.-2*beta[l]);
        a_1[l]=beta[l];
    }
    /* WE ALLOCATE MEMORY */
    ami_malloc3d(image_paso,float,dim_x,dim_y,dim_z);
    /* WE COPY THE ORIGINAL IMAGE TO image_paso */
    ami_copy_3d(image,image_paso,dim_x,dim_y,dim_z);
    /* WE CONVOLVE THE IMAGE IN AN ITERATIVE WAY ON THE AXES */
    /* WE CONVOLVE IN THE x DIRECTION */
    for(i=1;i<dim_x_1;i++)
        for(j=0;j<dim_y;j++)
            for(k=0;k<dim_z;k++)
                image[i][j][k]=a_1[0]*(image_paso[i+1][j][k]+image_paso[i-1][j][k])+a_0[0]*image_paso[i][j][k];
    /* WE FILL THE BOUNDARY VALUES */
    for(j=0;j<dim_y;j++)
        for(k=0;k<dim_z;k++) {
            image[0][j][k]=a_1[0]*(image_paso[1][j][k]+image_paso[0][j][k])+a_0[0]*image_paso[0][j][k];
            image[dim_x-1][j][k]=a_1[0]*(image_paso[dim_x-2][j][k]+image_paso[dim_x-1][j][k])+a_0[0]*image_paso[dim_x-1][j][k];
        }
    /* WE CONVOLVE IN THE y DIRECTION */
    for(i=0;i<dim_x;i++)
        for(j=1;j<dim_y_1;j++)
            for(k=0;k<dim_z;k++)
                image_paso[i][j][k]=a_1[1]*(image[i][j+1][k]+image[i][j-1][k])+a_0[1]*image[i][j][k];
    /* WE FILL THE BOUNDARY VALUES */
    for(i=0;i<dim_x;i++)
        for(k=0;k<dim_z;k++) {
            image_paso[i][0][k]=a_1[1]*(image[i][1][k]+image[i][0][k])+a_0[1]*image[i][0][k];
            image_paso[i][dim_y-1][k]=a_1[1]*(image[i][dim_y-2][k]+image[i][dim_y-1][k])+a_0[1]*image[i][dim_y-1][k];
        }

    // We allow 2D images with dim_z==1
    if (dim_z>1) {
        /* WE CONVOLVE IN THE z DIRECTION */
        for(i=0;i<dim_x;i++)
            for(j=0;j<dim_y;j++)
                for(k=1;k<dim_z_1;k++)
                    image[i][j][k]=a_1[2]*(image_paso[i][j][k+1]+image_paso[i][j][k-1])+a_0[2]*image_paso[i][j][k];
        /* WE FILL THE BOUNDARY VALUES */
        for(i=0;i<dim_x;i++)
            for(j=0;j<dim_y;j++) {
                image[i][j][0]=a_1[2]*(image_paso[i][j][1]+image_paso[i][j][0])+a_0[2]*image_paso[i][j][0];
                image[i][j][dim_z-1]=a_1[2]*(image_paso[i][j][dim_z-2]+image_paso[i][j][dim_z-1])+a_0[2]*image_paso[i][j][dim_z-1];
            }
    } else
      ami_copy_3d(image_paso,image,dim_x,dim_y,dim_z);

    /* WE FREE THE MEMORY */
    ami_free3d(image_paso);
}

/**
 * BASIC CONVOLUTION OF A 2D+t IMAGE 
 */
void ami_convolution_2d_t(float ***image,float beta[2],int dim_x,int dim_y,int dim_t)
{
    int dim_x_1=dim_x-1;
    int dim_y_1=dim_y-1;
    int i,j,k,l;
    float ***image_paso;
    double a_0[2],a_1[2];
    /* WE DEFINE WEIGHTS FOR THE CONVOLUTION */
    for(l=0;l<2;l++) {
        a_0[l]=(1.-2*beta[l]);
        a_1[l]=beta[l];
    }
    /* WE ALLOCATE MEMORY */
    ami_malloc3d(image_paso,float,dim_x,dim_y,dim_t);
    /* WE COPY THE ORIGINAL IMAGE TO image_paso */
    ami_copy_3d(image,image_paso,dim_x,dim_y,dim_t);
    /* WE CONVOLVE THE IMAGE IN AN ITERATIVE WAY ON THE AXES */
    /* WE CONVOLVE IN THE x DIRECTION */
    for(i=1;i<dim_x_1;i++)
        for(j=0;j<dim_y;j++)
            for(k=0;k<dim_t;k++)
                image[i][j][k]=a_1[0]*(image_paso[i+1][j][k]+image_paso[i-1][j][k])+a_0[0]*image_paso[i][j][k];
    /* WE FILL THE BOUNDARY VALUES */
    for(j=0;j<dim_y;j++)
        for(k=0;k<dim_t;k++) {
            image[0][j][k]=a_1[0]*(image_paso[1][j][k]+image_paso[0][j][k])+a_0[0]*image_paso[0][j][k];
            image[dim_x-1][j][k]=a_1[0]*(image_paso[dim_x-2][j][k]+image_paso[dim_x-1][j][k])+a_0[0]*image_paso[dim_x-1][j][k];
        }
    /* WE CONVOLVE IN THE y DIRECTION */
    for(i=0;i<dim_x;i++)
        for(j=1;j<dim_y_1;j++)
            for(k=0;k<dim_t;k++)
                image_paso[i][j][k]=a_1[1]*(image[i][j+1][k]+image[i][j-1][k])+a_0[1]*image[i][j][k];
    /* WE FILL THE BOUNDARY VALUES */
    for(i=0;i<dim_x;i++)
        for(k=0;k<dim_t;k++) {
            image_paso[i][0][k]=a_1[1]*(image[i][1][k]+image[i][0][k])+a_0[1]*image[i][0][k];
            image_paso[i][dim_y-1][k]=a_1[1]*(image[i][dim_y-2][k]+image[i][dim_y-1][k])+a_0[1]*image[i][dim_y-1][k];
        }

    ami_copy_3d(image_paso,image,dim_x,dim_y,dim_t);

    /* WE FREE THE MEMORY */
    ami_free3d(image_paso);

} // ami_convolution_2d_t()

/**
 * 3D IMAGE ZOOM DOWN 
 */
int ami_zoom_down_3d(
    float ***image,/* ORIGINAL 3D IMAGE */
    float ***image_zoom,/* OUTPUP IMAGE OF SIZE HALF OF THE ORIGINAL IMAGE */
    float beta[3], /* CONVOLUTION PARAMETER */
    int zoom_factor[3], /* ZOOM FACTOR IN EACH DIMENSION IT HAS TO BE 1 OR 2 */
    int dim_x,int dim_y,int dim_z) /* DIMENSION OF ORIGINAL IMAGE */
{
    int i,j,k;
    float ***image_paso;
    for(i=0;i<3;i++)
        if(zoom_factor[i]!=1 && zoom_factor[i]!=2) {
            printf("error in ami_zoom_down_3d() function: zoom_factor[%d]=%d is not 1 or 2\n",i,zoom_factor[i]);
            return(-1);
        }
    /* WE ALLOCATE MEMORY */
    ami_malloc3d(image_paso,float,dim_x,dim_y,dim_z);
    /* WE COPY THE ORIGINAL IMAGE TO image_paso */
    ami_copy_3d(image,image_paso,dim_x,dim_y,dim_z);
    /* WE CONVOLVE THE IMAGE BEFORE SAMPLING */
    ami_convolution_3d(image_paso,beta,dim_x,dim_y,dim_z);
    /* WE SAMPLE THE IMAGE */

    for(i=0;i<(dim_x/zoom_factor[0]);i++)
        for(j=0;j<(dim_y/zoom_factor[1]);j++)
            for(k=0;k<(dim_z/zoom_factor[2]);k++) {
                image_zoom[i][j][k]=image_paso[zoom_factor[0]*i][zoom_factor[1]*j][zoom_factor[2]*k];

		}

    /* WE FREE THE MEMORY */
    ami_free3d(image_paso);
    return(0);
} // ami_zoom_down_3d


/**
 * 2D+T IMAGE ZOOM DOWN 
 */
int ami_zoom_down_2d_t(float ***image,float ***image_zoom,float beta[2],int zoom_factor[2],int dim_x,int dim_y,int dim_t)
{
    int i,j,k;
    float ***image_paso;
    for(i=0;i<2;i++)
      if(zoom_factor[i]!=1 && zoom_factor[i]!=2) {
      printf("error in ami_zoom_down_3d() function: zoom_factor[%d]=%d is not 1 or 2\n",i,zoom_factor[i]);
      return(-1);
      }
      /* WE ALLOCATE MEMORY */
      ami_malloc3d(image_paso,float,dim_x,dim_y,dim_t);
      /* WE COPY THE ORIGINAL IMAGE TO image_paso */
      ami_copy_3d(image,image_paso,dim_x,dim_y,dim_t);
      /* WE CONVOLVE THE IMAGE BEFORE SAMPLING */
      ami_convolution_2d_t(image_paso,beta,dim_x,dim_y,dim_t);
      /* WE SAMPLE THE IMAGE */
      for(i=0;i<(dim_x/zoom_factor[0]);i++)
	for(j=0;j<(dim_y/zoom_factor[1]);j++)
	  for(k=0;k<dim_t;k++)
	    image_zoom[i][j][k]=image_paso[zoom_factor[0]*i][zoom_factor[1]*j][k];
      /* WE FREE THE MEMORY */
      ami_free3d(image_paso);
      return(0);
  } // ami_zoom_down_2d_t()


/****************************/
/* 3D IMAGE ZOOM UP */
int ami_zoom_up_3d_filter(
		float ***image,/* ORIGINAL IMAGE */
	float ***image_zoom,/* OUTPUT IMAGE OF DOUBLE SIZE OF THE ORIGINAL IMAGE */
	float beta[3], /* CONVOLUTION PARAMETER */
	int zoom_factor[3], /* ZOOM FACTOR IN EACH DIMENSION IT HAS TO BE 1 OR 2 */
	int dim_x,int dim_y,int dim_z) /* DIMENSION OF ORIGINAL IMAGE */
{
	int i,j,k;
	for(i=0;i<3;i++) if(zoom_factor[i]!=1 && zoom_factor[i]!=2){
		printf("error in ami_zoom_up_3d() function: zoom_factor[%d]=%d is not 1 or 2\n",i,zoom_factor[i]); return(-1);
	}
	/* WE EXTRAPOLATE THE IMAGE */
	for(i=0;i<(zoom_factor[0]*dim_x);i++)
		for(j=0;j<(zoom_factor[1]*dim_y);j++)
			for(k=0;k<(zoom_factor[2]*dim_z);k++)
				image_zoom[i][j][k]=image[i/zoom_factor[0]][j/zoom_factor[1]][k/zoom_factor[2]];
	/* WE CONVOLVE THE IMAGE AFTER ZOMMING UP */
	ami_convolution_3d(image_zoom,beta,dim_x,dim_y,dim_z);
	return(0);
}

/****************************/
/* 3D IMAGE ZOOM UP */
int ami_zoom_up_3d_interpolation(
    float ***image,/* ORIGINAL IMAGE */
    float ***image_zoom,/* OUTPUT IMAGE OF DOUBLE SIZE OF THE ORIGINAL IMAGE */
    int zoom_factor[3], /* ZOOM FACTOR IN EACH DIMENSION IT HAS TO BE 1 OR 2 */
    int dim_x,int dim_y,int dim_z) /* DIMENSION OF ORIGINAL IMAGE */
{
    int i,j,k,i2,j2,k2;
    float dx,dy,dz,x,y,z;
    for(i=0;i<3;i++)
        if(zoom_factor[i]!=1 && zoom_factor[i]!=2) {
            printf("error in ami_zoom_up_3d() function: zoom_factor[%d]=%d is not 1 or 2\n",i,zoom_factor[i]);
            return(-1);
        }
    /* WE EXTRAPOLATE THE IMAGE */
    for(i=0;i<(zoom_factor[0]*dim_x);i++) {
        for(j=0;j<(zoom_factor[1]*dim_y);j++) {
            for(k=0;k<(zoom_factor[2]*dim_z);k++) {
                //image_zoom[i][j][k]=image[i/zoom_factor[0]][j/zoom_factor[1]][k/zoom_factor[2]];
                x=((float) i)/zoom_factor[0];
                y=((float) j)/zoom_factor[1];
                z=((float) k)/zoom_factor[2];
                if(x>=(dim_x-1)) {
                    i2=dim_x-2;
                    dx=1.;
                } else {
                    i2=(int)x;
                    dx=x-i2;
                }
                if(y>=(dim_y-1)) {
                    j2=dim_y-2;
                    dy=1.;
                } else {
                    j2=(int)y;
                    dy=y-j2;
                }

		if ((dim_z==1)||(z<0)) {
		  k2=0;
		  dz=0.;
		} else if(z>=(dim_z-1)) {
		  k2=dim_z-2;
		  dz=1.;
		} else {
		  k2=(int)z;
		  dz=z-k2;
		}
                
		if (dim_z>1) 
		  image_zoom[i][j][k]=(1-dx)*(1-dy)*(1-dz)*image[i2][j2][k2]+
                                    (dx)*(1-dy)*(1-dz)*image[i2+1][j2][k2]+
                                    (dx)*(dy)*(1-dz)*image[i2+1][j2+1][k2]+
                                    (dx)*(dy)*(dz)*image[i2+1][j2+1][k2+1]+
                                    (dx)*(1-dy)*(dz)*image[i2+1][j2][k2+1]+
                                    (1-dx)*(dy)*(1-dz)*image[i2][j2+1][k2]+
                                    (1-dx)*(dy)*(dz)*image[i2][j2+1][k2+1]+
                                    (1-dx)*(1-dy)*(dz)*image[i2][j2][k2+1];
		else
		  image_zoom[i][j][k]=
		      (1-dx)*(1-dy)*image[i2  ][j2  ][0]+
		      (  dx)*(1-dy)*image[i2+1][j2  ][0]+
		      (  dx)*(dy)  *image[i2+1][j2+1][0]+
		      (1-dx)*(dy)  *image[i2  ][j2+1][0];
	    }
        }
    }

    return(0);
} // ami_zoom_up_3d_interpolation


/**
 * 2D+T IMAGE ZOOM UP USING BILINEAR INTERPOLATION 
 */
int ami_zoom_up_2d_t_interpolation(float ***image,float ***image_zoom,int zoom_factor[2],int dim_x,int dim_y,int dim_p)
{
  int i,j,k,i2,j2;
  float dx,dy,x,y;
  for(i=0;i<2;i++)
    if(zoom_factor[i]!=1 && zoom_factor[i]!=2) {
    printf("error in ami_zoom_up_2d_t_interpolation() function: zoom_factor[%d]=%d is not 1 or 2\n",i,zoom_factor[i]);
    return(-1);
    }
    /* WE EXTRAPOLATE THE IMAGE */
    for(i=0;i<(zoom_factor[0]*dim_x);i++) {
      for(j=0;j<(zoom_factor[1]*dim_y);j++) {
	for(k=0;k<dim_p;k++) {
                //image_zoom[i][j][k]=image[i/zoom_factor[0]][j/zoom_factor[1]][k/zoom_factor[2]];
	  x=((float) i)/zoom_factor[0];
	  y=((float) j)/zoom_factor[1];
	  if(x>=(dim_x-1)) {
	    i2=dim_x-2;
	    dx=1.;
	  } else {
	    i2=(int)x;
	    dx=x-i2;
	  }
	  if(y>=(dim_y-1)) {
	    j2=dim_y-2;
	    dy=1.;
	  } else {
	    j2=(int)y;
	    dy=y-j2;
	  }
	    
	  image_zoom[i][j][k]=
		(1-dx)*(1-dy)*image[i2  ][j2  ][k]+
		(  dx)*(1-dy)*image[i2+1][j2  ][k]+
		(  dx)*(dy)  *image[i2+1][j2+1][k]+
		(1-dx)*(dy)  *image[i2  ][j2+1][k];
	}
      }
    }

    return(0);
}  // ami_zoom_up_2d_t_interpolation()


/****************************/
/* 3D IMAGE VECTOR ZOOM UP */
int ami_zoom_up_v3f_flow(
		ami_v3f ***image_grad,/* ORIGINAL 3D IMAGE VECTOR */
	ami_v3f ***image_grad_zoom,/* OUTPUT 3D IMAGE VECTOR OF DOUBLE SIZE OF THE ORIGINAL IMAGE*/
	float beta[3], /* CONVOLUTION PARAMETER */
	int zoom_factor[3], /* ZOOM FACTOR IN EACH DIMENSION IT HAS TO BE 1 OR 2 */
	int dim_x,int dim_y,int dim_z) /* ORIGINAL IMAGE DIMENSION */
{
	int i,j,k,l;
	int dim_x_2=dim_x*zoom_factor[0];
	int dim_y_2=dim_y*zoom_factor[1];
	int dim_z_2=dim_z*zoom_factor[2];
	float ***image,***image_zoom;
	for(i=0;i<3;i++) if(zoom_factor[i]!=1 && zoom_factor[i]!=2){
		printf("error in ami_zoom_up_v3f_flow() function: zoom_factor[%d]=%d is not 1 or 2\n",i,zoom_factor[i]); return(-1);
	}
	/* WE ALLOCATE MEMORY */
	ami_malloc3d(image,float,dim_x,dim_y,dim_z);
	ami_malloc3d(image_zoom,float,dim_x*zoom_factor[0],dim_y*zoom_factor[1],dim_z*zoom_factor[2]);
	/* WE SAMPLE THE VECTOR IMAGE */
	for(l=0;l<3;l++){
		for(i=0;i<dim_x;i++)
			for(j=0;j<dim_y;j++)
				for(k=0;k<dim_z;k++)
					image[i][j][k]=image_grad[i][j][k][l];
		ami_zoom_up_3d_interpolation(image,image_zoom,zoom_factor,dim_x,dim_y,dim_z);
		for(i=0;i<dim_x_2;i++)
			for(j=0;j<dim_y_2;j++)
				for(k=0;k<dim_z_2;k++)
					image_grad_zoom[i][j][k][l]=zoom_factor[l]*image_zoom[i][j][k];

	}
	/* WE FREE THE MEMORY */
	ami_free3d(image); ami_free3d(image_zoom);
	return(0);
}

/**
 * 2D+T IMAGE VECTOR ZOOM UP 
 */
int ami_zoom_up_vect_2d_t_flow(ami_v3f ***image_grad,ami_v3f ***image_grad_zoom,float beta[2],int zoom_factor[2],int dim_x,int dim_y,int dim_p)
{
  int i,j,k,l;
  int dim_x_2=dim_x*zoom_factor[0];
  int dim_y_2=dim_y*zoom_factor[1];
  float ***image,***image_zoom;
  for(i=0;i<2;i++) if(zoom_factor[i]!=1  && zoom_factor[i]!=2){
    printf("error in ami_zoom_up_vect_2d_t_flow() function: zoom_factor[%d]=%d is not 1 or 2\n",i,zoom_factor[i]); return(-1);
  }
  /* WE ALLOCATE MEMORY */
  ami_malloc3d(image,float,dim_x,dim_y,dim_p);
  ami_malloc3d(image_zoom,float,dim_x*zoom_factor[0],dim_y*zoom_factor[1],dim_p);
  /* WE SAMPLE THE VECTOR IMAGE */
  for(l=0;l<3;l++){
    for(i=0;i<dim_x;i++)
      for(j=0;j<dim_y;j++)
	for(k=0;k<dim_p;k++)
	  image[i][j][k]=image_grad[i][j][k][l];
    ami_zoom_up_2d_t_interpolation(image,image_zoom,zoom_factor,dim_x,dim_y,dim_p);
    for(i=0;i<dim_x_2;i++)
      for(j=0;j<dim_y_2;j++)
	for(k=0;k<dim_p;k++)
	  image_grad_zoom[i][j][k][l]=zoom_factor[l]*image_zoom[i][j][k];

  }
  /* WE FREE THE MEMORY */
  ami_free3d(image); ami_free3d(image_zoom);
  return(0);
} // ami_zoom_up_vect_2D_T_flow()



/*****************************************************************************/
/* FUNCTION TO COMPUTE THE LAPLACE PROBLEM WITH DIRICHLET CONDITION
   WE SOLVE divergence(pot)= div */
int ami_laplace_3d(
  float ****pot, /* POTENCIAL FLOW (OUTPUT DATA) */
  float ***div, /* DIVERGENCE (INPUT DATA) */
  float beta[3],/* CONVOLUTION PARAMETER FOR ZOOMING DOWN */
  int zoom_factor[3], /* ZOOM FACTOR IN EACH DIMENSION IT HAS TO BE 1 OR 2 */
  float TOL_GaussSeidel,/* CONVERGENCE PARAMETER OF GAUSS SEIDEL SCHEME */
  int Nscales,/* NUMBER OF RESOLUTIONS IN THE PYRAMIDAL APPROACH */
  double A, /* coefficient to help the equation converge */
  int dim_x,int dim_y,int dim_z) /* IMAGE DIMENSIONS */
{
	int i,j,k,l,m,dim_x2,dim_y2,dim_z2,mm,kk;
	float ***div_o,***div_p,***pot_p,paso,***pot_2=NULL,***pot_o;
	float error_2,relative_error,error_1=100000.;
	double pot_error;
	int use_Jacobi = 1;
/*
float* div_o_buf;
	float* pot_o_buf;
	double div2_o = 0;
*/

  /* WE COPY THE ORIGINAL DIVERGENCE IN div_o */
  ami_malloc3d(div_o,float,dim_x,dim_y,dim_z);
  ami_copy_3d(div,div_o,dim_x,dim_y,dim_z);
  /* WE GO TROUGH PIRAMIDAL SCHEME */
  for(l=Nscales;l>0;l--)
  {
    /* WE INITIALIZE THE ERROR FOR CONVERGENCE CRITERIUM */
    error_1=1000000;
    /* WE UPDATE  THE ORIGINAL DIVERGENCE OF THE FLOW */
    if(l<Nscales)
    {
      ami_free3d(div_o);
      ami_malloc3d(div_o,float,dim_x,dim_y,dim_z);
      ami_copy_3d(div,div_o,dim_x,dim_y,dim_z);
    }
    /* WE ZOOM DOWN THE div */
    dim_x2=dim_x; dim_y2=dim_y; dim_z2=dim_z;
    for(m=1;m<l;m++)
    {
      ami_malloc3d(div_p,float,dim_x2/zoom_factor[0],dim_y2/zoom_factor[1],dim_z2/zoom_factor[2]);
      if(ami_zoom_down_3d(div_o,div_p,beta,zoom_factor,dim_x2,dim_y2,dim_z2)!=0) return(-1);
      ami_free3d(div_o);
      div_o=div_p;
      dim_x2/=zoom_factor[0]; dim_y2/=zoom_factor[1]; dim_z2/=zoom_factor[2];
    }
    /* WE INITIALIZE THE POTENCIAL AND DIVERGENCE FOR THE RESIDUAL PROBLEM */
    if(l==Nscales)
    {
      ami_calloc3d(pot_2,float,dim_x2,dim_y2,dim_z2);
      ami_calloc3d(pot_o,float,dim_x2,dim_y2,dim_z2);
    }
    else
    {
      ami_calloc3d(pot_p,float,dim_x2,dim_y2,dim_z2);
      ami_calloc3d(pot_o,float,dim_x2,dim_y2,dim_z2);
      ami_zoom_up_3d_interpolation(pot_2,pot_p,zoom_factor,dim_x2/2,dim_y2/2,dim_z2/2);
      ami_free3d(pot_2);
      pot_2=pot_p;
      for(i=0;i<dim_x2;i++)
        for(j=0;j<dim_y2;j++)
          for(k=0;k<dim_z2;k++)
          {
            if(i==0 || j==0 || k==0 || i==dim_x2-1 || j==dim_y2-1 || k==dim_z2-1)
            {
              pot_2[i][j][k]=0;
            }
            else
            {
              pot_2[i][j][k]*=4.05;
            }
          };

    float* div_o_buf;
	float* pot_o_buf;
	double div2_o = 0;
      /* WE COPY THE POTENCIAL */
      ami_copy_3d(pot_2,pot_o,dim_x2,dim_y2,dim_z2);
      /* WE COMPUTE THE RESIDUAL DIVERGENCE */
      for(i=1;i<dim_x2-1;i++)
      {
        for(j=1;j<dim_y2-1;j++)
        {
          div_o_buf = div_o[i][j]+1;
          pot_o_buf = pot_o[i][j]+1;
          for(k=1;k<dim_z2-1;k++)
          {
            *div_o_buf-=-6.*(*pot_o_buf)+pot_o[i+1][j][k]+pot_o[i-1][j][k]+
                        pot_o_buf[dim_z2]+pot_o_buf[-dim_z2]+
                        pot_o_buf[1]+pot_o_buf[-1];
            div2_o += *div_o_buf* *div_o_buf;
            div_o_buf++;
            pot_o_buf++;
          }
        }
      }
      printf("scale %d, norm residual divergence = %f \n",l, sqrt(div2_o/dim_x2/dim_y2/dim_z2));
    }
    /* WE INITIALIZE TO ZERO pot_2 FOR ITERATIONS IN THE RESIDUAL PROBLEM */
    for(i=0;i<dim_x2;i++) for(j=0;j<dim_y2;j++) for(k=0;k<dim_z2;k++) pot_2[i][j][k]=0;
    //printf("pot(center) initial: %f\n",(pot_2[dim_x2/2][dim_y2/2][dim_z2/2]+pot_o[dim_x2/2][dim_y2/2][dim_z2/2]));
    /* WE INITIALIZE THE NUMBER OF TRIALS FOR SCALE CONVERGENCE
    	WE STOP THE ITERATIONS AFTER 3 CONSECUTIVE CONVERGENCE VERIFICATION */
    kk=0;
    /* WE GO TRHOUGH SCALE ITERATIONS */
    for(mm=0;mm<Niter_GaussSeidel;mm++)
    {
      if ((mm%10==0)&&(mm>0))
      {
/*
        if (mm==0)    printf("Niter_GaussSeidel it: ");
        else
          printf("\b\b\b\b\b\b");
        printf("%6d",mm);
        fflush(stdout);
*/
      }
      pot_error=0;
      if (use_Jacobi==0) {
	float* div_o_buf;
	float* pot_2_buf;
	for(i=1;i<dim_x2-1;i++)
	{
		for(j=1;j<dim_y2-1;j++)
		{
		div_o_buf = &div_o[i][j][1];
		pot_2_buf = &pot_2[i][j][1];
		for(k=1;k<dim_z2-1;k++)
		{
		paso=(-*div_o_buf+
			pot_2[i+1][j][k]+pot_2[i-1][j][k]+
			pot_2_buf[dim_z2]+pot_2_buf[-dim_z2]+
			pot_2_buf[1]     +pot_2_buf[-1]      )/(6.+A);
		pot_error+=fabs(paso-*pot_2_buf);
		*pot_2_buf=paso;
		div_o_buf++;
		pot_2_buf++;
		}
		}
	}
	ami_boundary_3df(pot_2,dim_x2,dim_y2,dim_z2);
	for(i=dim_x2-2;i>0;i--)
	{
		for(j=dim_y2-2;j>0;j--)
		{
		for(k=dim_z2-2;k>0;k--)
		{
		paso=(-div_o[i][j][k]+pot_2[i+1][j][k]+pot_2[i-1][j][k]+
			pot_2[i][j+1][k]+pot_2[i][j-1][k]+
			pot_2[i][j][k+1]+pot_2[i][j][k-1])/(6.+A);
		pot_error+=fabs(paso-pot_2[i][j][k]);
		pot_2[i][j][k]=paso;
		}
		}
	}
	ami_boundary_3df(pot_2,dim_x2,dim_y2,dim_z2);
	if (mm%50==0)
         printf("scale %d it %d\t error %f \n",l,mm,
                 pot_error);
      } else {
	float* div_o_buf;
	float* pot_2_buf;
	float* pot_2bis_buf;
    float*** pot_2bis;
	ami_calloc3d(pot_2bis,float,dim_x2,dim_y2,dim_z2);
	ami_copy_3d(pot_2,pot_2bis,dim_x2,dim_y2,dim_z2);
	float pot_min=0, pot_max=0;

	for(i=1;i<dim_x2-1;i++)
	{ 
		for(j=1;j<dim_y2-1;j++)
		{
		div_o_buf    = &div_o   [i][j][1];
		pot_2_buf    = &pot_2   [i][j][1];
		pot_2bis_buf = &pot_2bis[i][j][1];
		for(k=1;k<dim_z2-1;k++)
			{
			paso=(-*div_o_buf+
				pot_2[i+1][j][k]+pot_2[i-1][j][k]+
				pot_2_buf[dim_z2]+pot_2_buf[-dim_z2]+
				pot_2_buf[1]     +pot_2_buf[-1]      )/(6.+A);
			*pot_2bis_buf=paso;
			if (paso<pot_min) pot_min = paso;
			if (paso>pot_max) pot_max = paso;
			pot_error+=fabs(paso-*pot_2_buf);
			div_o_buf++;
			pot_2_buf++;
			pot_2bis_buf++;
			}
		}
	}
        ami_boundary_3df(pot_2bis,dim_x2,dim_y2,dim_z2);
	ami_copy_3d(pot_2bis,pot_2,dim_x2,dim_y2,dim_z2);
        ami_free3d(pot_2bis);
	if (mm%50==0)
         printf("scale %d it %d\t min pot:%f \t max pot:%f, error %f \n",l,mm,pot_min,pot_max,
                 pot_error);
      }
      //ami_boundary_3df(pot,dim_x2,dim_y2,dim_z2);
      /* WE COMPUTE THE L^1 NORM OF THE ERROR TO STOP ITERATIONS */
      error_2=pot_error/(dim_x2*dim_y2*dim_z2);
      relative_error=error_2/(error_1+0.0000000000000001);
      /*if(mm%20==0){
      printf("Scale=%d iter Scale =%d h_displacement=%1.10f relative error=%1.10f\n",l,mm,error_2,relative_error);
      printf("pot(center): %f\n",pot_2[dim_x2/2][dim_y2/2][dim_z2/2]);
      }*/
      if(relative_error>(exp((double) -100.*(TOL_GaussSeidel/(l*l)))) || error_2<(TOL_GaussSeidel/(l*l))) kk++; else kk=0;
      //printf("kk=%d\n",kk); scanf("%f",&paso);
      if(relative_error>MAX_RELATIVE_ERROR) kk=3;
      if(kk==3)
      {
        //printf("\nScale=%d iter Scale =%d h_displacement=%1.10f relative error=%1.10f\n",l,mm,error_2,relative_error);
        mm=Niter_GaussSeidel+1;
      }
      else {error_1=error_2;}
    }
    //printf("pot(center)=%f\n",pot_2[dim_x2/2][dim_y2/2][dim_z2/2]+pot_o[dim_x2/2][dim_y2/2][dim_z2/2]);
    /* WE UPDATE p_2 */
    for(i=0;i<dim_x2;i++) for(j=0;j<dim_y2;j++) for(k=0;k<dim_z2;k++) pot_2[i][j][k]+=pot_o[i][j][k];

    ami_free3d(pot_o);
  }
      float* div_o_buf;
      float* pot_2_buf;
      double div2_o = 0;
      /* WE COMPUTE THE RESIDUAL DIVERGENCE */
      for(i=1;i<dim_x2-1;i++)
      {
        for(j=1;j<dim_y2-1;j++)
        {
          div_o_buf = div_o[i][j]+1;
          pot_2_buf = pot_2[i][j]+1;
          for(k=1;k<dim_z2-1;k++)
          {
            *div_o_buf-=-6.*(*pot_2_buf)+pot_2[i+1][j][k]+pot_2[i-1][j][k]+
                        pot_2_buf[dim_z2]+pot_2_buf[-dim_z2]+
                        pot_2_buf[1]+pot_2_buf[-1];
            div2_o += *div_o_buf* *div_o_buf;
            div_o_buf++;
            pot_2_buf++;
          }
        }
      }
      printf("scale %d, norm residual divergence = %f \n",l, sqrt(div2_o/dim_x2/dim_y2/dim_z2));

  ami_free3d(div_o);
  *pot=pot_2;
  return(0);
}
/*****************************************************************************/
/* FUNCTION TO COMPUTE THE SOLENOIDAL PROYECCION OF A FLOW                  */
int ami_solenoidal_proyeccion_3d(
  ami_v3f ***u, /* CURRENT FLOW (INPUT/OUTPUT DATA). THE OUTPUT IS THE SOLENOIDAL PROYECCION OF THE FLOW */
  float beta[3],/* CONVOLUTION PARAMETER FOR ZOOMING */
  int zoom_factor[3], /* ZOOM FACTOR IN EACH DIMENSION IT HAS TO BE 1 OR 2 */
  float TOL_GaussSeidel,/* CONVERGENCE PARAMETER OF GAUSS SEIDEL SCHEME */
  int Nscales,/* NUMBER OF RESOLUTIONS IN THE PYRAMIDAL APPROACH */
  double A,/* coefficient for convergence of laplace equation */
  int dim_x,int dim_y,int dim_z) /* IMAGE DIMENSIONS */
{
  int i,j,k,l;
  float ***div,***pot;
  double pot_error;
  /* WE COMPUTE THE DIVERGENCE */
  ami_malloc3d(div,float,dim_x,dim_y,dim_z);
  for(i=1;i<dim_x-1;i++)
  {
    for(j=1;j<dim_y-1;j++)
    {
      for(k=1;k<dim_z-1;k++)
      {
        div[i][j][k]=(u[i+1][j][k][0]-u[i][j][k][0]+
                      u[i][j+1][k][1]-u[i][j][k][1]+
                      u[i][j][k+1][2]-u[i][j][k][2]);
      }
    }
  }
  /* WE FILL THE BOUNDARY VALUES */
  ami_boundary_3df(div,dim_x,dim_y,dim_z);
  /* WE COMPUTE THE AVERAGE VALUE OF fabs(div) BEFORE SOLENOIDAL PROJECTION  */
  /*	for(i=1;i<dim_x-1;i++)
            for(j=1;j<dim_y-1;j++) 
              for(k=1;k<dim_z-1;k++){ average+=fabs((double) div[i][j][k]); }
  //printf("div(center)=%e\n",div[dim_x/2][dim_y/2][dim_z/2]);
  printf("initial average fabs(div)=%e\t",average/((dim_x-2)*(dim_y-2)*(dim_z-2)));
  */
  /* WE SOLVE THE LAPLACE EQUATION  */
  ami_laplace_3d(&pot,div,beta,zoom_factor,TOL_GaussSeidel,Nscales,A,dim_x,dim_y,dim_z);

  /* WE COMPUTE THE SOLENOIDAL PROYECCION */
  pot_error=0;
  float*   pot_buf;
  ami_v3f* u_buf;
  for(i=1;i<dim_x;i++)
  {
    for(j=1;j<dim_y;j++)
    {
      u_buf   = &u[i][j][1];
      pot_buf = &pot[i][j][1];
      for(k=1;k<dim_z;k++)
      {
        (*u_buf)[0]-=*pot_buf-pot[i-1][j][k];
        //pot_error+=fabs(pot[i][j][k]-pot[i-1][j][k]);
        (*u_buf)[1]-=*pot_buf-pot[i][j-1][k];
        //pot_error+=fabs(pot[i][j][k]-pot[i][j-1][k]);
        (*u_buf)[2]-=*pot_buf-pot[i][j][k-1];
        //pot_error+=fabs(pot[i][j][k]-pot[i][j][k-1]);
        u_buf++;
        pot_buf++;
      }
    }
  }
  /* WE FILL BOUNDARY CONDITIONS */
  for(j=0;j<dim_y;j++) for(k=0;k<dim_z;k++) for(l=0;l<3;l++) u[0][j][k][l]=u[1][j][k][l];
  for(i=0;i<dim_x;i++) for(k=0;k<dim_z;k++) for(l=0;l<3;l++) u[i][0][k][l]=u[i][1][k][l];
  for(j=0;j<dim_y;j++) for(i=0;i<dim_x;i++) for(l=0;l<3;l++) u[i][j][0][l]=u[i][j][1][l];

  //	printf("average change flow =%e\n",pot_error/(3.*(dim_x-1)*(dim_y-1)*(dim_z-1)));
  /* WE FREE THE MEMORY */
  ami_free3d(div); ami_free3d(pot);
  return(0);
}


/*****************************************************************************/
/* FUNCTION TO READ AN ASCII FILE WITH THE 3D OPTIC FLOW INFORMATION         */
int ami_read_optic_flow_3D(
		const char* name, /** name of the input flow file */
  		ami_v3f ***u, /** output flow matrix (only lattice points) */ 
		int dim[3], /** image dimensions */
		int trans[3], /** image translation */
		int offset[3], /** vector field offset (pos_u = pos_ASCII+offset) */
		ami_v3f disp, /** lattice displacement */
		ami_v3f init) /** initial point of the lattice (respect to translation) */
{
	int c;
	FILE *fptr;
	char paso[200];
	float x,y,z;
	float vx,vy,vz;
	int dim_x = ceil((dim[0]-init[0])/disp[0]);
	int dim_y = ceil((dim[1]-init[1])/disp[1]);
	int dim_z = ceil((dim[2]-init[2])/disp[2]);

  // Open file
	if ((fptr = fopen(name,"r")) == NULL) {
		fprintf(stderr,"Unable to open  file \"%s\"\n",name);
		return(-2);
	}

// ...................

  // WE SKIP THE COMMENT HEAD PART OF THE FILE
	fscanf(fptr, "%s",paso);
	while(paso[0]=='#' ) {		
		while( (c=getc(fptr)) != '\n' );
		fscanf(fptr, "%s",paso);		
//	printf("paso : %s\n",paso);
	}

// ...................

  
  // Init images with a NULL value (0.0)
	for (x=0; x<dim_x; x++)
		for (y=0; y<dim_y; y++)
			for (z=0; z<dim_z; z++)
	{
		u[(int)x][(int)y][(int)z][0] = 0.;
		u[(int)x][(int)y][(int)z][1] = 0.;
		u[(int)x][(int)y][(int)z][2] = 0.;
	}

	
  // WE FILL THE FLOW MATRIX WITH THE FILE INFORMATION:	
	x = atof(paso);
	fscanf(fptr,"%f %f %f %f %f\n",&y,&z,&vx,&vy,&vz);
	int xmin = 999999, ymin = 999999, zmin = 999999;
	do {	
	  	// WE ADD THE ASCII OFFSET AND SUBSTRACT THE TRANSLATION:
		x += offset[0]-trans[0];
		y += offset[1]-trans[1];
		z += offset[2]-trans[2];

		// WE LOOK IF THIS IS A VALID POINT:
		int in_image = (x >= 0 && x<dim[0] &&
				  		y >= 0 && y<dim[1] &&
				  		z >= 0 && z<dim[2]);
		int in_grid = (abs(((x-init[0])/disp[0])-floor((x-init[0])/disp[0])) < 0.0000001 &&
					   abs(((y-init[1])/disp[1])-floor((y-init[1])/disp[1])) < 0.0000001 &&
					   abs(((z-init[2])/disp[2])-floor((z-init[2])/disp[2])) < 0.0000001);
		if (in_image && in_grid) 
		{			
			int pos_x = (int)((x-init[0])/disp[0]);
			int pos_y = (int)((y-init[1])/disp[1]);
			int pos_z = (int)((z-init[2])/disp[2]);
			u[pos_x][pos_y][pos_z][0] = vx;
			u[pos_x][pos_y][pos_z][1] = vy;
			u[pos_x][pos_y][pos_z][2] = vz;
			/*printf("(%d,%d,%d)->(%d,%d,%d): (%f,%f,%f)\n",(int)x,(int)y,(int)z,
				   										  (int)(x-t_x),(int)(y-t_y),(int)(z-t_z),
			vx,vy,vz);*/
			if (x < xmin) xmin = x;
			if (y < ymin) ymin = y;
			if (z < zmin) zmin = z;
		}
	} while(fscanf(fptr,"%f %f %f %f %f %f\n",&x,&y,&z,&vx,&vy,&vz)!=EOF);
	printf("Begining filled point: (%d,%d,%d)\n",xmin,ymin,zmin);
	fclose(fptr);
	return(0);
}

