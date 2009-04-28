/* THIS PROGRAM COMPUTES DE OPTIC FLOW IN A SINGLE POINT USING A SECOND ORDER
   GENERALIZATION OF LUCAS-KANADE METHOD. IN A POINT (x0,y0) WE MINIMIZE
   E(u)=\int_{(x,y)\in  Window}(I_1(x,y)-I_2((x,y)+(u[0],u[1])+
   (u[3]*(x-x0)+u[4]*(y-y0),u[5]*(x-x0)+u[6]*(y-y0)) */
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stddef.h>
//#include <fcntl.h>

#if defined(_MSC_VER)
#define _USE_MATH_DEFINES
#include <math.h>
#endif

#include "ami_prototypes.h"
#include "ami_lucas_kanade_2d_2o.h"
//#include <time.h>
//#include "..\ami_all_libraries\ami_prototypes.h"
//#include "..\ami_all_libraries\ami_utilities.c"
////#include "..\ami_all_libraries\ami_calibracion.c"
////#include "..\ami_all_libraries\ami_corner.c"
//#include "..\ami_all_libraries\ami_image_file.c"
//#include "..\ami_all_libraries\ami_optic_flow.c"
////#include "..\ami_all_libraries\ami_snake.c"
//#include "..\ami_all_libraries\ami_fft.c"




/**************************************************************************************/
/* FUNCTION TO INITIALIZE THE FLOW FOR LUCAS KANADE 2D 2 ORDER METHOD */
int ami_lucas_kanade_2d_2o_init(float **ut,float **vt,/* ORIGINAL APPROXIMATION OF THE IMAGE FLOW (INPUT DATA) */
    float *u,/* APPROXIMATION OF THE LOCAL FLOW IN THE POINT (x0,y0) (OUTPUT DATA) */
	float x0,float y0,/* POINT WHERE THE LOCAL FLOW IS EVALUATED (INPUT DATA) */
	int window_radius, /* WINDOW RADIUS DEFINING THE NEIGHBORHOOD OF (x0,y0) USED TO COMPUTE THE LOCAL FLOW u (INPUT DATA) */
	float sigma,/* PARAMETER OF THE KERNEL IN THE LUCAS-KANADE ENERGY (CURRENTLY THIS PARAMETER IS NOT USED IN THIS FUNCTION */
    int dim_x,int dim_y) /* IMAGE DIMENSIONS */
{
  int i,j,N;
  //long m,size=dim_x*dim_y;
  double *x,*y,*xn,*yn,H[3][3];
  /* WE COMPUTE THE NUMBER OF POINTS OF THE WINDOW */
  N=(2*window_radius+1)*(2*window_radius+1);
  /* WE ALLOCATE MEMORY */
  ami_malloc1d(x,double,N);
  ami_malloc1d(y,double,N);
  ami_malloc1d(xn,double,N);
  ami_malloc1d(yn,double,N);
  /* WE COMPUTE THE POINTS COORDINATES */
  N=0;
  for(i=x0-window_radius;i<=(x0+window_radius);i++){
	for(j=y0-window_radius;j<=(y0+window_radius);j++){
      if(0<=i && i<dim_x && 0<=j && j<dim_y){
		  x[N]=i-x0; y[N]=j-y0; xn[N]=x[N]+ut[i][j]; yn[N]=y[N]+vt[i][j];
		 N++;

	  }
	}
  }
  /* WE COMPUTE THE AFFINITY AND FILL VECTOR u*/
  if(ami_calculo_afinidad(x,y,xn,yn,H,N)!=0){ free(x); free(y); free(xn); free(yn);  return(-1);}
  u[0]=H[0][2]; u[1]=H[1][2]; u[2]=H[0][0]-1.; u[3]=H[0][1]; u[4]=H[1][0]; u[5]=H[1][1]-1.;
  /* WE FREE THE MEMORY AND RETURN */
  free(x); free(y); free(xn); free(yn);
  return(0);
}
/**************************************************************************************/
/* FUNCTION TO COMPUTE A SECOND ORDER WARPING (IT RETURNS THE INTERPOLATED VALUE)*/
float ami_image_warping_2d_2o(float **image,/* ORIGINAL IMAGE (INPUT DATA)*/
    float *u,/* LOCAL FLOW USED TO COMPUTE IMAGE DISPLACEMENT (INPUT DATA) */
	float x0,float y0, /* POINT WHERE THE DISPLACEMENT IS CENTERED (INPUT DATA)*/
	float x,float y, /* POINT TO BE DISPLACED BY THE LOCAL FLOW (INPUT DATA) */
	int dim_x,int dim_y) /* IMAGE DIMENSIONS (INPUT DATA) */
{
  int i,j;
  float x2,y2,dx,dy,value;
  /* WE COMPUTE THE DISPLACEMENT */
  x2=x+u[0]+u[2]*(x-x0)+u[3]*(y-y0);
  y2=y+u[1]+u[4]*(x-x0)+u[5]*(y-y0);
  if(x2<0){ i=0; dx=0;}
  else if(x2>=(dim_x-1)){i=dim_x-2; dx=1;}
  else{i=x2; dx=x2-i;}
  if(y2<0){ j=0; dy=0;}
  else if(y2>=(dim_y-1)){j=dim_y-2; dy=1;}
  else{j=y2; dy=y2-j;}
  /* WE INTERPOLATE USING BILINEAR ALGORITHM */
  value=image[i][j]*(1-dx)*(1-dy)+
        image[i+1][j]*(dx)*(1-dy)+
		image[i][j+1]*(1-dx)*(dy)+
		image[i+1][j+1]*(dx)*(dy);
  return(value);
}
/**************************************************************************************/
/* FUNCTION TO COMPUTE AUXILIAR VECTOR OF LUCAS-KANADE 2 ORDER METHOD */
void ami_lucas_kanade_2d_2o_v6f(
    float **image_x,float **image_y,/* GRADIENT OF IMAGE 2 IN THE SEQUENCE (INPUT DATA)*/
	float *u,/* LOCAL FLOW IN THE POINT (x0,y0) (INPUT DATA)*/
    float x0,float y0,/* POINT WHERE THE LOCAL FLOW IS CENTERED (INPUT DATA)*/
	float x,float y, /* POINT TO BE DISPLACED WHERE THE AUXILIAR VECTOR IS EVALUATED (INPUT DATA)*/
	float *I,/* AUXILIAR VECTOR OF THE LUCAS-KANADE GENERALIZED METHOD (OUTPUT DATA)*/
	int dim_x,int dim_y) /* IMAGE DIMENSIONS */
{
  float i2_x=ami_image_warping_2d_2o(image_x,u,x0,y0,x,y,dim_x,dim_y);
  float i2_y=ami_image_warping_2d_2o(image_y,u,x0,y0,x,y,dim_x,dim_y);
  I[0]=i2_x; I[1]=i2_y; I[2]=(x-x0)*i2_x; I[3]=(y-y0)*i2_x; I[4]=(x-x0)*i2_y; I[5]=(y-y0)*i2_y;
}
/*******************************************************************************************************/
/* FUNCTION TO COMPUTE THE 6x6 LUCAS AND KANADE 2D 2 ORDER SYSTEM IT RETURN THE ENERGY TO BE MINIMIZED */
float ami_lucas_kanade_2d_20_system(
    float **image_1,float **image_2,/* TO CONSECUTIVE IMAGE FRAMES WHERE THE FLOW IS COMPUTED (INPUT DATA)*/
	float **image_2_x,float **image_2_y,/* GRADIENT OF IMAGE 2 (INPUT DATA) */
	float *u,/* LOCAL FLOW IN THE POINT (x0,y0) (INPUT DATA)*/
	float x0,float y0,/* POINT WHERE THE LOCAL FLOW IS CENTERED (INPUT DATA) */
	int window_radius, /* WINDOW RADIUS TO FIT THE NEIBORHOOD OF (x0,y0) TO COMPUTE THE LOCAL FLOW (INPUT DATA) */
    float sigma,/* PARAMETER OF THE KERNEL OF THE LUCAS-KANADE ENERGY (INPUT DATA) */
	float alfa,/* REGULARIZATION PARAMETER FOR SYSTEM MATRIZ (A=A+alfa*Id) (INPUT DATA) */
    double *b, /* INDEPENDENT VECTOR OF THE ASSOCIATED LINEAR SYSTEM (OUTPUT DATA) */
	double **A,/* MATRIZ OF THE ASSOCIATED LINEAR SYSTEM (OUTPUT DATA) */
	int dim_x,int dim_y) /* IMAGE DIMENSIONS */
{
  int i,j,m,n;
  float *I,kernel,I_2,norm,energy=0;
  
  //double sigma_2=1./(2.*sigma*sigma);
  /* WE ALLOCATE MEMORY */
  ami_malloc1d(I,float,6);
  /* WE INITIALIZE THE SYSTEM */
  for(i=0;i<6;i++){b[i]=0.; for(j=0;j<6;j++){ A[i][j]=0.;}}
  /* NORMALIZATION TO AVOID IRREGULAR ILUMINATION EFFECTS */
  /*for(i=x0-window_radius;i<=(x0+window_radius);i++){
	for(j=y0-window_radius;j<=(y0+window_radius);j++){
	if(0<=i && i<dim_x && 0<=j && j<dim_y){
	  media1+=image_1[i][j];
	  media2+=ami_image_warping_2d_2o(image_2,u,x0,y0,(float) i,(float) j,dim_x,dim_y);
	}
	}
  }
  media1=media1/((2*window_radius + 1)*(2*window_radius + 1));
  media2=media2/((2*window_radius + 1)*(2*window_radius + 1));
  for(i=x0-window_radius;i<=(x0+window_radius);i++){
	for(j=y0-window_radius;j<=(y0+window_radius);j++){
	if(0<=i && i<dim_x && 0<=j && j<dim_y){
	  std1+=(image_1[i][j]-media1)*(image_1[i][j]-media1);
	  std2+=(ami_image_warping_2d_2o(image_2,u,x0,y0,(float) i,(float) j,dim_x,dim_y)-media2)* (ami_image_warping_2d_2o(image_2,u,x0,y0,(float) i,(float) j,dim_x,dim_y)-media2);
	}
	}
  }
  std1=(float)sqrt((double)(std1/((2*window_radius + 1)*(2*window_radius + 1))));
  std2=(float)sqrt((double)(std2/((2*window_radius + 1)*(2*window_radius + 1))));*/
  
  /* WE COMPUTE THE SYSTEM */
  for(i=x0-window_radius;i<=(x0+window_radius);i++){
	for(j=y0-window_radius;j<=(y0+window_radius);j++){
      if(0<=i && i<dim_x && 0<=j && j<dim_y){
		ami_lucas_kanade_2d_2o_v6f(image_2_x,image_2_y,u,x0,y0,(float) i,(float) j,I,dim_x,dim_y);
		ami_norma_vector(I,norm,6);
		kernel=(sigma/M_PI)*exp((double) -sigma*((i-x0)*(i-x0)+(j-y0)*(j-y0)));
		//I_2=((ami_image_warping_2d_2o(image_2,u,x0,y0,(float) i,(float) j,dim_x,dim_y)-media2)/std2)*std1 + media1;
		I_2=ami_image_warping_2d_2o(image_2,u,x0,y0,(float) i,(float) j,dim_x,dim_y);
		energy+=kernel*(image_1[i][j]-I_2)*(image_1[i][j]-I_2);
		for(m=0;m<6;m++){
		  b[m]+=kernel*(image_1[i][j]-I_2)*I[m];
		    for(n=0;n<6;n++){
		      A[m][n]+=kernel*I[m]*I[n];
		  }
		}
	  }
	}
  }
  /* WE ADD (alfa * Id) TO A TO AVOID SINGULAR MATRIX */
  for(m=0;m<6;m++) A[m][m]+=alfa;
  /* WE FREE THE MEMORY */
  free(I);
  return(energy);
}
/**************************************************************************************/
/* FUNCTION TO COMPUTE 2D OPTIC FLOW IN A POINT USING SECOND ORDER LUCAS-KANADE TECHNIQUE */
double ami_optic_flow_lucas_kanade_2d_2o(
    float **image_1,float **image_2, /* TO CONSECUTIVE IMAGE FRAMES WHERE THE FLOW IS COMPUTED (INPUT DATA)*/
	float **image_2_x,float **image_2_y, /* GRADIENT OF IMAGE 2 (INPUT DATA) */
	float *u, /* LOCAL FLOW IN THE POINT (x0,y0) (OUTPUT DATA)*/
	float x0,float y0, /* POINT WHERE THE LOCAL FLOW IS CENTERED (INPUT DATA) */
	int window_radius, /* WINDOW RADIUS TO FIT THE NEIBORHOOD OF (x0,y0) TO COMPUTE THE LOCAL FLOW (INPUT DATA) */
    float sigma, /* PARAMETER OF THE KERNEL OF THE LUCAS-KANADE ENERGY (INPUT DATA) */
	float alfa, /* REGULARIZATION PARAMETER FOR SYSTEM MATRIZ (A=A+alfa*Id) (INPUT DATA) */
	float TOL_iter, /* CONVERGENCE PARAMETER TO STOP ITERATIONS TO SOLVE THE LINEAR SYSTEM (INPUT DATA) */
	float **ut,float **vt, /* ORIGINAL APPROXIMATION OF THE IMAGE FLOW (INPUT DATA) */
	int dim_x,int dim_y) /* IMAGE DIMENSIONS */
{
  printf("ami_optic_flow_lucas_kanade_2d_2o(x0=%02.2f,y0=%02.2f,%d,%02.2f,%02.2f,%f,%d,%d) \n",
         x0,y0,window_radius,sigma,alfa,TOL_iter,dim_x,dim_y);

// int i,j,l,m,n,mm,nn,kk=0;
 int l,m,kk=0;
 double **A;
 double *b;
 float *up,*up2;
 double error_2,error_1=1000000.,error_0=0.0,error_end=0.0;
 /* WE ALLOCATE MEMORY */
 ami_malloc2d(A,double,6,6);
 ami_malloc1d(b,double,6);
 ami_malloc1d(up,float,6);
 ami_malloc1d(up2,float,6);
 /* WE INITIALIZE THE FLOW u(FINAL) up(CURRENT ITERATION) up2(BEST ONE) */
 if(ami_lucas_kanade_2d_2o_init(ut,vt,up,x0,y0,window_radius,sigma,dim_x,dim_y)!=0) { ami_free2d(A); free(b); free(up); free(up2); return((double) -1.);}
 for(m=0;m<6;m++) u[m]=up2[m]=up[m];
 /* WE GO TROUGH ITERATIONS */
 for(l=0;l<NITER_LUCAS_KANADE;l++){
	/* WE COMPUTE THE SYSTEM */
   error_2=ami_lucas_kanade_2d_20_system(image_1,image_2,image_2_x,image_2_y,up,x0,y0,window_radius,sigma,alfa,b,A,dim_x,dim_y);
   /* WE INITIALIZE THE ENERGY ERROR IN THE FIRST ITERATION */
   if(l==0) error_0=error_end=error_2;
   /* WE SOLVE THE SYSTEM */
   if(ami_gauss(A,b,6)!=0){ami_free2d(A); free(b); free(up); free(up2); return((double) -1.);}
   /* WE CHECK FOR CONVERGENCE CRITERIUM */
   if(error_2<TOL_iter || (error_2/(error_1+10e-30))>exp((double) -TOL_iter*1000.) ){ kk++;}
   else {kk=0;}
//   printf("it=%d,  E2=%1.2e, RE=%1.3f\n",l,error_2,(error_2/(error_1+10e-30)));
   error_1=error_2;
   /* WE ACTUALIZE THE BEST FLOW up2 AND alfa*/
   if(error_2<error_end){ for(m=0;m<6;m++) up2[m]=up[m]; error_end=error_2; /*alfa*=0.1;*/}
   //else{ alfa*=10;}
   /* WE ACTUALIZE THE CURRENT FLOW */
   for(m=0;m<6;m++) up[m]+=b[m];
   /* IF THE CONVERGENCE CRITERIUM HOLD 5 CONSECUTIVE TIMES WE STOP */
   if(kk==5){
	 if(error_end<error_0){
	   for(m=0;m<6;m++) u[m]=up2[m];
	   ami_free2d(A); free(b); free(up); free(up2);
	   return(error_end);
	 }
	 else{
	   ami_free2d(A); free(b); free(up); free(up2);
	   return(error_0);
	 }
   }
 }
  printf("Iters finalizadas\n");
  /*WE TEST IF THE INITIAL ENERGY HAS BEEN REDUCED AND RETURN */
  if(error_end<error_0){
	for(m=0;m<6;m++) u[m]=up2[m];
	  ami_free2d(A); free(b); free(up); free(up2);
	  return(error_end);
  }
  else{
	ami_free2d(A); free(b); free(up);
	return(error_0);
  }
}


/**************************************************************************************/
/*        MAIN PROGRAM  */
//int main(int argc,char *argv[])
//{
//  int i,j,k,n,l,i2,j2;
//  float grey_color; /* COLOR TO BUILD SYNTHETIC IMAGES */
//  float **image_1, **image_2; /* IMAGES TO COMPUTE THE FLOW */
//  float **image_2_x,**image_2_y; /* GRADIENT OF IMAGE 2 */
//  float **ut,**vt; /* ORIGINAL APPROXIMATION OF THE IMAGE FLOW */
//  float *u; /* LOCAL FLOW IN THE POINT (x0,y0) (MAIN UNKNOWN GIVEN BY A VECTOR OF DIMENSION 6)*/
//  float x,y; /* POINT TO INTEGRATE IN THE LUCAS-KANADE WINDOWS */
//  long size,m;
//  int dim_x=16;
//  int dim_y=16; /* IMAGE DIMENSIONS */
//  float alfa=10e-0; /* REGULARIZATION PARAMETER FOR SYSTEM MATRIZ (A=A+alfa*Id) */
//  float sigma=6; /* PARAMETER OF THE KERNEL OF THE LUCAS-KANADE ENERGY  */
//  float TOL_iter=0.00001; /* CONVERGENCE PARAMETER TO STOP ITERATIONS TO SOLVE THE LINEAR SYSTEM */
//  float x0=8;
//  float y0=8; /* POINT COORDINATES WHERE THE SECOND ORDER FLOW IS GOING TO BE COMPUTED */
//  int window_radius=2; /*  WINDOW RADIUS TO FIT THE NEIBORHOOD OF (x0,y0) TO COMPUTE THE LOCAL FLOW */
//  time_t timer; /* VARIABLE TO INITIALIZE RANDOM */
//  float cercle_radius=2*2+1; /* RADIUS POWER 2 OF CERCLES TO GENERATE SYNTHETIC IMAGE */
// int Ncercles=3000; /* NUMBER OF CERCLES TO BUILD THE IAMGE */
//  double energy;

  /* WE ALLOCATE MEMORY */
//  ami_calloc2d(image_1,float,dim_x,dim_y);
//  ami_calloc2d(image_2,float,dim_x,dim_y);
//  ami_calloc2d(image_2_x,float,dim_x,dim_y);
//  ami_calloc2d(image_2_y,float,dim_x,dim_y);
//  ami_calloc2d(ut,float,dim_x,dim_y);
//  ami_calloc2d(vt,float,dim_x,dim_y);
//  ami_calloc1d(u,float,6);
  /* RANDOM NUMBER INITIALIZATION */
//  srand((unsigned int) time(&timer));
  /* WE DEFINE THE IMAGE 2 USING RANDOM CERCLES  */
//  for(k=0;k<Ncercles;k++){
//	x=(double) (dim_x-1)* ((double) rand()/RAND_MAX);
//	y=(double) (dim_y-1)* ((double) rand()/RAND_MAX);
//	grey_color=255.*((double) rand()/RAND_MAX);
//    for(i=-4;i<=4;i++){
//	  for(j=-4;j<=4;j++){
//	    i2=x+i; j2=y+j;
//		if(i2>=0 && i2<dim_x && j2>=0 && j2<dim_y){
//		  if( ((x-i2)*(x-i2)+(y-j2)*(y-j2))<cercle_radius ) image_2[i2][j2]=grey_color;
//		}
//	  }
//    }
//  }
  /* WE INITIALIZE u TO BUILD THE FIRST IMAGE */
//  u[0]=1; u[1]=2; u[2]=1.4; u[3]=-1.5; u[4]=1.6; u[5]=1.7;
  /* WE DEFINE image_1 BY TRANSFORMING image_2 */
//  for(i=0;i<dim_x;i++)
//	for(j=0;j<dim_y;j++)
//		image_1[i][j]=ami_image_warping_2d_2o(image_2,u,x0,y0,(float) i,(float) j,dim_x,dim_y);
  /* WE INITIALIZE THE GLOBAL FLOW  AND WE ADD NOISE */
//  for(i=0;i<dim_x;i++){
//	for(j=0;j<dim_y;j++){
//	  ut[i][j]=u[0]+u[2]*(i-x0)+u[3]*(j-y0);
//      vt[i][j]=u[1]+u[4]*(i-x0)+u[5]*(j-y0);
//	  ut[i][j]+=(-0.5+(double) rand()/RAND_MAX)*ut[i][j]*0.1;
//	  vt[i][j]+=(-0.5+(double) rand()/RAND_MAX)*vt[i][j]*0.1;
//	}
//  }
  /* WE COMPUTE THE GRADIENT OF IMAGE 2 */
//  ami_grad_2df(image_2,image_2_x,image_2_y,dim_x,dim_y);
  /* WE COMPUTE THE LOCAL SECOND ORDER FLOW IN (x0,y0) */
// if(ami_optic_flow_lucas_kanade_2d_2o(image_1,image_2,image_2_x,image_2_y,u,x0,y0,window_radius,sigma,alfa,TOL_iter,ut,vt,dim_x,dim_y)>=0){
//   printf("NEW FLOW HAS BEEN FOUND CORRECTLY WITH LUCAS KANADE \n");
//    ami_printf1d("u",u,6);
//  }
//  else{
//	printf("LUCAS KANADE CAN NOT FIND A LOCAL FLOW ESTIMATION \n");
//    ami_printf1d("u",u,6);
//  }
  /* WE FREE THE MEMORY */
//  ami_free2d(image_1);
//  ami_free2d(image_2);
//  ami_free2d(image_2_x);
//  ami_free2d(image_2_y);
//  ami_free2d(ut);
//  ami_free2d(vt);
//  free(u);

// return 0;
//}














