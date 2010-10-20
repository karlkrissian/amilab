#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ami_prototypes.h"
#include "ami_utilities.h"
#include "ami_chi2.h"

float basefunction(int i,float x, float y) 
{
  float value=0.0;
  
  switch (i) {
    case 0:
      value=1.;
      break;
    case 1:
      value=x;
      break;
    case 2:
      value=x*x;
      break;
    case 3:
      value=y;
      break;
    case 4:
      value=y*y;
      break;
    case 5:
      value=x*y;
      break;
    case 6:
      value=x*x*y;
      break;
    case 7:
      value=x*y*y;
      break;
    case 8:
      value=x*x*y*y;
      break;
  }
  return (value);
}

float partial_x_basefunction(int i,float x, float y) 
{
  float value=0.0;
  
  switch (i) {
    case 0:
      value=0.;
      break;
    case 1:
      value=1;
      break;
    case 2:
      value=2*x;
      break;
    case 3:
      value=0;
      break;
    case 4:
      value=0;
      break;
    case 5:
      value=y;
      break;
    case 6:
      value=2*x*y;
      break;
    case 7:
      value=y*y;
      break;
    case 8:
      value=2*x*y*y;
      break;
  }
  return (value);
}
float partial_y_basefunction(int i,float x, float y) 
{
  float value=0.0;
  
  switch (i) {
    case 0:
      value=0;
      break;
    case 1:
      value=0;
      break;
    case 2:
      value=0;
      break;
    case 3:
      value=1;
      break;
    case 4:
      value=2*y;
      break;
    case 5:
      value=y;
      break;
    case 6:
      value=x*x;
      break;
    case 7:
      value=x*y*2;
      break;
    case 8:
      value=x*x*y*2;
      break;
  }
  return (value);
}

static double** A_system_matrix_vorticity;
static double*  b_u_chi2_resolve;
static double*  b_v_chi2_resolve;

void ami_allocate_vorticity_equation()
{
  ami_calloc2d(A_system_matrix_vorticity,double,MBASE_FUN,MBASE_FUN);
  ami_calloc1d(b_u_chi2_resolve,double,MBASE_FUN);
  ami_calloc1d(b_v_chi2_resolve,double,MBASE_FUN);
}

void ami_init_vorticity_equation()
{
  
  memset(A_system_matrix_vorticity[0],0, sizeof(double)*MBASE_FUN*MBASE_FUN);
  memset(b_u_chi2_resolve,0,sizeof(double)*MBASE_FUN);
  memset(b_v_chi2_resolve,0,sizeof(double)*MBASE_FUN);
}

void ami_free_vorticity_equation()
{
  ami_free2d(A_system_matrix_vorticity); 
  free(b_u_chi2_resolve);
  free(b_v_chi2_resolve);
}

float ami_vorticity_2d_chi2_9p_ij(int i0,int j0, float **uf, float **vf,int dim_x, int dim_y)
{
  int i_rel[NPOINTS_CHI2]={-1,-1,-1,0,0,0,1,1,1};
  int j_rel[NPOINTS_CHI2]={-1,0,1,-1,0,1,-1,0,1};
  int i_k[NPOINTS_CHI2],j_k[NPOINTS_CHI2];
  float u_k[NPOINTS_CHI2];
  float v_k[NPOINTS_CHI2];
  int i,j,k;
  float localvorticity=0.;
  
  ami_init_vorticity_equation();
  
  //WE INITIALIZE ALL THE VARIABLES TO COMPUTE THE VORTICITY AT POSITION (X0,Y0)
  for (i=0;i<NPOINTS_CHI2;i++) {
    i_k[i]=i0+i_rel[i];
    j_k[i]=j0+j_rel[i];
  }

  for (i=0;i<NPOINTS_CHI2;i++) {
    if (i_k[i]<0) i_k[i]=0;
    if (j_k[i]<0) j_k[i]=0;
    if (i_k[i]>dim_x-1) i_k[i]=dim_x-1;
    if (j_k[i]>dim_y-1) j_k[i]=dim_y-1;
    
    u_k[i]=uf[i_k[i]][j_k[i]];
    v_k[i]=vf[i_k[i]][j_k[i]];
    //printf("(%d,%d) flow: %e --- %e\n",i_k[i],j_k[i],uf[i_k[i]][j_k[i]],vf[i_k[i]][j_k[i]]);
  }
  
  //WE COMPUTE THE MATRIX OF THE SYSTEM OF EQUATIONS
  //unsigned char pb;
  for (k=0;k<NPOINTS_CHI2;k++) {
        //printf("%d --- %d\n",i_k[k],j_k[k]);
        //pb=((i_k[0]==0)&&(j_k[0]==7));
        //if (pb) {
        //	printf("break here\n");
        //}
    for (i=0;i<MBASE_FUN;i++) {
      //printf("base function: %f\n",basefunction(i,(float)x_rel[k],(float)y_rel[k]));
      float a=basefunction(i,(float)i_rel[k],(float)j_rel[k]);
      for (j=0;j<MBASE_FUN;j++) {
        //if (pb) printf("k=%d: A[%d][%d]: %e\n",k,i,j,A[i][j]);
        A_system_matrix_vorticity[i][j]+=(double)(a*basefunction(j,(float)i_rel[k],(float)j_rel[k]));
        //if (pb) printf("k=%d (%e,%e): basefunction(%d): %e\n",k,(float)i_rel[k],(float)j_rel[k],i,a);
        //if (pb) printf("k=%d (%e,%e): basefunction(%d): %e\n",k,(float)i_rel[k],(float)j_rel[k],j,b);
        //if (pb) 
        //printf("k=%d: A[%d][%d]: %e\n",k,i,j,A[i][j]);
      }
      b_u_chi2_resolve[i]+=(double)(u_k[k]*a);
      b_v_chi2_resolve[i]+=(double)(v_k[k]*a);
    }
  }
  //ami_printf2d("A",A,9,9);
  //ami_printf1d("b_Au",b_u,9);
  //ami_printf1d("b_Av",b_v,9);
  //WE SOLVE THE SYSTEMS
  if(ami_gauss(A_system_matrix_vorticity,b_u_chi2_resolve,NPOINTS_CHI2)!=0)
  {	
//  	ami_free2d(A); free(b_u);free(b_v); 
  	printf("Error: Unable to solve the system of Equations\n");
  	return((float) -1.);
  }
  if(ami_gauss(A_system_matrix_vorticity,b_v_chi2_resolve,NPOINTS_CHI2)!=0)
  {
//  	ami_free2d(A); free(b_u);free(b_v); 
  	printf("Error: Unable to solve the system of Equations\n");
  	return((float) -1.);
  }
  
  //ami_printf1d("b_u",b_u,MBASE_FUN);
  //ami_printf1d("b_v",b_v,MBASE_FUN);
  
  //WE COMPUTE THE VORTICITY AT VALUE (x0,y0)
  for (i=0;i<MBASE_FUN;i++) {
    localvorticity+=((float)b_v_chi2_resolve[i])*partial_x_basefunction(i,0.,0.)-((float)b_u_chi2_resolve[i])*partial_y_basefunction(i,0.,0.);
  }
  
  //if (i0%50==0) printf("Dentro:  %e\n",localvorticity);
  return (localvorticity);
}

/*
float ami_vorticity_2d_chi2_9p(int x0,int y0, float **u, float **v,int dim_x, int dim_y)
{
  int x_rel[NPOINTS_CHI2]={-1,0,1,-1,0,1,-1,0,1};
  int y_rel[NPOINTS_CHI2]={1,1,1,0,0,0,-1,-1,-1};
  int x_k[NPOINTS_CHI2],y_k[NPOINTS_CHI2];
  float u_k[NPOINTS_CHI2];
  float v_k[NPOINTS_CHI2];
  int i,j,k;
  char updated=0;
  //double **A,*b_u,*b_v;
  float vorticity=0;
  
  ami_calloc2d(A,double,MBASE_FUN,MBASE_FUN);
  ami_calloc1d(b_u,double,MBASE_FUN);
  ami_calloc1d(b_v,double,MBASE_FUN);
  
  //WE INITIALIZE ALL THE VARIABLES TO COMPUTE THE VORTICITY AT POSITION (X0,Y0)
  for (i=0;i<NPOINTS_CHI2;i++) {
    x_k[i]=x0+x_rel[i];
    y_k[i]=y0+y_rel[i];
  }

  for (i=0;i<NPOINTS_CHI2;i++) {
    //updated=0;
    if (x_k[i]<0 && y_k[i]<0) {
      u_k[i]=u[dim_y-1][0];
      v_k[i]=v[dim_y-1][0];
    }
    else if (x_k[i]>dim_x-1 && y_k[i]<0) {
      u_k[i]=u[dim_y-1][dim_x-1];
      v_k[i]=v[dim_y-1][dim_x-1];
    }
    else if (x_k[i]<0 && y_k[i]>dim_y-1) {
      u_k[i]=u[0][0];
      v_k[i]=u[0][0];
    }
    else if (x_k[i]>dim_x-1 && y_k[i]>dim_y-1) {
      u_k[i]=u[0][dim_x-1];
      v_k[i]=v[0][dim_x-1];
    }
    else if (x_k[i]<0 && updated==0) {
      u_k[i]=u[dim_y-1-y_k[i]][0];
      v_k[i]=v[dim_y-1-y_k[i]][0];
      //updated=1;
    }
    else if (x_k[i]>dim_x-1) {
      u_k[i]=u[dim_y-1-y_k[i]][dim_x-1];
      v_k[i]=v[dim_y-1-y_k[i]][dim_x-1];
      //updated=1;
    }
    else if (y_k[i]<0) {
      u_k[i]=u[dim_y-1][x_k[i]];
      v_k[i]=v[dim_y-1][x_k[i]];
      //updated=1;
    }
    else if (y_k[i]>dim_y-1) {
      u_k[i]=u[0][x_k[i]];
      v_k[i]=v[0][x_k[i]];
      //updated=1;
    }
    else {
      u_k[i]=u[dim_y-1-y_k[i]][x_k[i]];
      v_k[i]=v[dim_y-1-y_k[i]][x_k[i]];
    }
  }
  //WE COMPUTE THE MATRIX OF THE SYSTEM OF EQUATIONS
  //ami_printf1d("u_k",u_k,9);*/
  
  /*for (i=0;i<MBASE_FUN;i++) {
    for (j=0;j<MBASE_FUN;j++) {
      for (k=0;k<NPOINTS_CHI2;k++) {
         A[i][j]+=basefunction(i,(float)x_rel[k],(float)y_rel[k])*basefunction(j,(float)x_rel[k],(float)y_rel[k]);
         b_u[i]+=u_k[k]*basefunction(i,(float)x_rel[k],(float)y_rel[k]);
         b_v[i]+=v_k[k]*basefunction(i,(float)x_rel[k],(float)y_rel[k]);
      }
    }
  }*/
  
  /*for (k=0;k<NPOINTS_CHI2;k++) {
    for (i=0;i<MBASE_FUN;i++) {
      //printf("base function: %f\n",basefunction(i,(float)x_rel[k],(float)y_rel[k]));
      for (j=0;j<MBASE_FUN;j++) {
        A[i][j]+=basefunction(i,(float)x_rel[k],(float)y_rel[k])*basefunction(j,(float)x_rel[k],(float)y_rel[k]);
      }
      b_u[i]+=u_k[k]*basefunction(i,(float)x_rel[k],(float)y_rel[k]);
      b_v[i]+=v_k[k]*basefunction(i,(float)x_rel[k],(float)y_rel[k]);
    }
  }
  //ami_printf2d("A",A,9,9);
  //ami_printf1d("b_Au",b_u,9);
  //ami_printf1d("b_Av",b_v,9);
  //WE SOLVE THE SYSTEMS
  if(ami_gauss(A,b_u,NPOINTS_CHI2)!=0){ami_free2d(A); free(b_u); return((float) -1.);}
  if(ami_gauss(A,b_v,NPOINTS_CHI2)!=0){ami_free2d(A); free(b_v); return((float) -1.);}
  
  //ami_printf1d("b_u",b_u,MBASE_FUN);
  //ami_printf1d("b_v",b_v,MBASE_FUN);
  
  //WE COMPUTE THE VORTICITY AT VALUE (x0,y0)
  for (i=0;i<MBASE_FUN;i++) {
    vorticity+=b_v[i]*partial_x_basefunction(i,0.,0.)-b_u[i]*partial_y_basefunction(i,0.,0.);
  }
  
  ami_free2d(A); 
  free(b_u);
  free(b_v);
  
  return (vorticity);
}
*/
