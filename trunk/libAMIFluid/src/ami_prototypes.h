#ifndef AMI_PROTOTYPES_H
#define AMI_PROTOTYPES_H

#if defined(_MSC_VER)
#define _USE_MATH_DEFINES
#endif
#include <math.h>

#include "ami_types.h"

#include "TIFF.h"
#include "ami.h"
#include "ami_fft.h"
#include "ami_corner.h"
#include "ami_image_file.h"
#include "ami_optic_flow.h"
#include "ami_utilities.h"
#include "ami_utilities_3d.h"
#include "ami_calibracion.h"



// Define la posicion del origen de coordenadas en la imagen UV (esquina superior izquierda o esquina inferior izquierda)
//#define TOP_LEFT_ORIGIN

// Define si los resultados del flujo optico se van a escribir con "1" o "2" pixeles de precision
#define PX_2PRECISION


void ami_extract_snake_contour(unsigned char *imagen_level_set,int width,int height,int **i_snake,int **j_snake,int *Npoints);
/* FUNCTION TO EXTRACT THE SNAKE CONTOUR FROM THE LEVEL SET */
int ami_snake_level_set(float *imagen,unsigned char *imagen_level_set,int width,int height,int borde,
  float alfa,float lambda,float sigma,int Nescalas,int Niter);
/* FUNCION QUE CALCULA LOS SNAKES GEODESICOS A PARTIR DE UN LEVEL SET */
    /* START OF OLD ami_snake.h */
void ami_semilla(long m,float *imagen,unsigned short width,long size, float nivel1,float nivel2);
/* ALGORITMO DE SEMILLA PARA RELLENAR LA IMAGEN A PARTIR DE UN NIVEL CON OTRO NIVEL */
int ami_rellenar_poligono(float **imagen,int *x,int *y,int Np,float nivel1,float nivel2,
                          int borde,int *width,int *height,int *xd,int *yd);
/* FUNCION QUE CONSTRUYE UNA IMAGEN RELLENANDO UN POLIGONO */
int ami_snake(unsigned char *imagen,int width,int height,int *x,int *y,int Np,int borde,int *xd,int *yd,
              float alfa,float lambda,float sigma,int Nescalas,float **imagen_level_set_r,int *width_g,int *height_g,int Niter);
/* FUNCION QUE CALCULA LOS SNAKES GEODESICOS A PARTIR DE UN POLIGONO */
void ami_snake_iteracion(float *imagen_level_set,float *imagen_level_set_x,float *imagen_level_set_y,
                    float *imagen_g,float *imagen_g_x, float *imagen_g_y,int width2,int height2,
                    float lambda,float *error,float max_grad_g);
/* FUNCION QUE CALCULA UNA ITERACION EN EL PROCEDIMIENTO DE ami_snake() */
void ami_dibujar_segmento(float *data,int width,int height,int x0,int y0,int x1,int y1,float color);
/* FUNCION QUE DIBUJA UN SEGMENTO */
    /* END OF OLD ami_snake.h */

    /* START OF OLD Convolution.h */
void Convol(float **image, int nx, int ny, float **mask, int mx, int my);
/* FUNCTION TO CONVOLVE AN IMAGE WITH A MASK */
    /* END OF OLD C0nvolution.h */

    /* START OF OLD opticzoom.h */

float **EZoom(float **input, long *nx, long *ny, long scale);
float **DZoom(float **input, long maxx, long maxy, long nx, long ny, long scale);
long ZoomSerie(float **f, float ****fout, long nx, long ny, long Nitera);

	/* END OF OLD opticzoom.h */

   /* START OF OLD ami.h */

#define ami_abs(x) ((x)>0?(x):(-(x)))
#define ami_max_vector(x,pos,max,dim) {int ml; pos=0; max=x[0]; \
          for(ml=1;ml<dim;ml++) if(x[ml]>max) {max=x[ml]; pos=ml;} \
        }
#define ami_min_vector(x,pos,min,dim) {int ml; pos=0; min=x[0]; \
          for(ml=1;ml<dim;ml++) if(x[ml]<min) {min=x[ml]; pos=ml;} \
        }
#define ami_media_vector(x,alh,dim) {int ml; alh=0; \
          for(ml=0;ml<dim;ml++) alh+=x[ml]; \
          alh=alh/dim; \
        }
#define ami_desviacion_standard_vector(x,alh,dim,media) {int ml; alh=0; \
          for(ml=0;ml<dim;ml++) alh+=(x[ml]-media)*(x[ml]-media); \
          alh=sqrt((double) alh/dim); \
        }
#define ami_normalizar_vector(x,dim) {int ml; double alh=0; \
          for(ml=0;ml<dim;ml++) alh+=x[ml]*x[ml]; \
          if(alh>0){\
            alh=sqrt(alh); \
            for(ml=0;ml<dim;ml++) x[ml]/=alh;}\
        }
#define ami_norma_vector(x,norma,dim) {int ml; norma=0; \
          for(ml=0;ml<dim;ml++) norma+=x[ml]*x[ml]; \
          if(norma>0) norma=sqrt((double) norma); \
        }
#define ami_producto_vectorial(v,u,z) {\
          z[0]=v[1]*u[2]-u[1]*v[2];\
          z[1]=v[2]*u[0]-v[0]*u[2];\
          z[2]=v[0]*u[1]-u[0]*v[1];\
        }
#define ami_matriz_vector(A,x,v,Nfil,Ncol) {int ml,mk;\
          for(ml=0;ml<Nfil;ml++){ v[ml]=A[ml][0]*x[0]; \
            for(mk=1;mk<Ncol;mk++) v[ml]+=A[ml][mk]*x[mk];}\
        }
#define ami_matriz_traspuesta_vector(A,x,v,Nfil,Ncol) {int ml,mk;\
          for(ml=0;ml<Nfil;ml++){ v[ml]=A[0][ml]*x[0]; \
            for(mk=1;mk<Ncol;mk++) v[ml]+=A[mk][ml]*x[mk];}\
        }
#define ami_matriz_traspuesta(A,At,NfilA,NcolA) {int ml,mk;\
          for(ml=0;ml<NfilA;ml++){ \
            for(mk=0;mk<NcolA;mk++) At[mk][ml]=A[ml][mk];}\
        }
#define ami_matriz_copia(A,B,NfilA,NcolA) {int ml,mk;\
          for(ml=0;ml<NfilA;ml++){ \
            for(mk=0;mk<NcolA;mk++) B[ml][mk]=A[ml][mk];}\
        }
#define ami_escalar_matriz(l,A,B,NfilA,NcolA) {int ml,mk;\
          for(ml=0;ml<NfilA;ml++){ \
            for(mk=0;mk<NcolA;mk++) B[ml][mk]=l*A[ml][mk];}\
        }
#define ami_vector_copia(u,v,N) {int ml;\
          for(ml=0;ml<N;ml++){ \
            v[ml]=u[ml];}\
        }
#define ami_vector_vector(x,v,a,dim) {int ml; a=x[0]*v[0];\
          for(ml=1;ml<dim;ml++) a+=x[ml]*v[ml];\
        }
#define ami_vector_resta_vector(x,v,a,dim) {int ml; a=x[0]-v[0];\
          for(ml=1;ml<dim;ml++) a+=x[ml]-v[ml];\
        }
#define ami_vector_suma_vector(x,v,a,dim) {int ml; a=x[0]+v[0];\
          for(ml=1;ml<dim;ml++) a+=x[ml]+v[ml];\
        }
#define ami_escalar_vector(x,a,v,dim) {int ml; \
          for(ml=0;ml<dim;ml++) v[ml]=x[ml]*a;\
        }
#define ami_matriz_matriz(A,B,C,NfilA,NcolA,NcolB) {int ml,mk,mu;\
          for(mu=0;mu<NfilA;mu++) \
            for(mk=0;mk<NcolB;mk++){\
              C[mu][mk]=A[mu][0]*B[0][mk];\
              for(ml=1;ml<NcolA;ml++) C[mu][mk]+=A[mu][ml]*B[ml][mk];}\
        }
#define ami_matriz_traspuesta_matriz(A,B,C,NfilA,NcolA,NcolB) {int ml,mk,mu;\
          for(mu=0;mu<NfilA;mu++) \
            for(mk=0;mk<NcolB;mk++){\
              C[mu][mk]=A[0][mu]*B[0][mk];\
              for(ml=1;ml<NcolA;ml++) C[mu][mk]+=A[ml][mu]*B[ml][mk];}\
        }
#define ami_calloc2d(direccion,tipo,height,width) {int ml,mk; \
          direccion=(tipo **) malloc(sizeof(tipo *)*(height)); \
          direccion[0]=(tipo *)malloc(sizeof(tipo)*(width)*(height)); \
          for(ml=1;ml<(height);ml++) direccion[ml]=&(direccion[0][ml*(width)]); \
          for(ml=0;ml<height;ml++) for(mk=0;mk<width;mk++) direccion[ml][mk]=0; \
        }
#define ami_calloc2d_init(direccion,tipo,height,width,init_value) {int ml,mk; \
          direccion=(tipo **) malloc(sizeof(tipo *)*(height)); \
          direccion[0]=(tipo *)malloc(sizeof(tipo)*(width)*(height)); \
          for(ml=0;ml<(height);ml++) direccion[ml]=&(direccion[0][ml*(width)]); \
          for(ml=0;ml<height;ml++) for(mk=0;mk<width;mk++) direccion[ml][mk]=init_value; \
        }
#define ami_malloc2d(direccion,tipo,height,width) {int ml; \
          direccion=(tipo **) malloc(sizeof(tipo *)*(height)); \
          direccion[0]=(tipo *)malloc(sizeof(tipo)*(width)*(height)); \
          for(ml=0;ml<(height);ml++) direccion[ml]=&(direccion[0][ml*(width)]);\
        }
#define ami_malloc2d_punteros(direccion,puntero_simple,tipo,height,width) {int ml; \
          direccion=(tipo **) malloc(sizeof(tipo *)*(height)); \
          direccion[0]=(tipo *) puntero_simple; \
          for(ml=0;ml<(height);ml++) direccion[ml]=&(direccion[0][ml*(width)]);\
        }
#define ami_free2d(direccion) { free(direccion[0]); free(direccion); }
#define ami_free2d_punteros(direccion) { free(direccion); }
#define ami_calloc3d(direccion,tipo,depth,height,width) {int ml,mk,mu; \
          direccion=(tipo ***) malloc(sizeof(tipo **)*(depth)); \
          direccion[0]=(tipo **)malloc(sizeof(tipo *)*(depth)*(height)); \
          direccion[0][0]=(tipo *)malloc(sizeof(tipo)*(depth)*(height)*(width)); \
          for(mu=0;mu<depth;mu++){ \
            for(ml=0;ml<(height);ml++) \
              direccion[0][ml+mu*(height)]=&(direccion[0][0][ml*(width)+mu*(width)*(height)]); \
            direccion[mu]=&(direccion[0][mu*(height)]);}\
          for(mu=0;mu<depth;mu++) for(ml=0;ml<height;ml++) for(mk=0;mk<width;mk++) direccion[mu][ml][mk]=0; \
        }
#define ami_malloc3d(direccion,tipo,depth,height,width) {int ml,mu; \
          direccion=(tipo ***) malloc(sizeof(tipo **)*(depth)); \
          direccion[0]=(tipo **)malloc(sizeof(tipo *)*(depth)*(height)); \
          direccion[0][0]=(tipo *)malloc(sizeof(tipo)*(depth)*(height)*(width)); \
          for(mu=0;mu<depth;mu++){ \
            for(ml=0;ml<(height);ml++) \
              direccion[0][ml+mu*(height)]=&(direccion[0][0][ml*(width)+mu*(width)*(height)]); \
            direccion[mu]=&(direccion[0][mu*(height)]);}\
        }
#define ami_malloc3d_punteros(direccion,puntero_simple,tipo,depth,height,width) {int ml,mk,mu; \
          direccion=(tipo ***) malloc(sizeof(tipo **)*(depth)); \
          direccion[0]=(tipo **)malloc(sizeof(tipo *)*(depth)*(height)); \
          direccion[0][0]=(tipo *) puntero_simple; \
          for(mu=0;mu<depth;mu++){ \
            for(ml=0;ml<(height);ml++) \
              direccion[0][ml+mu*(height)]=&(direccion[0][0][ml*(width)+mu*(width)*(height)]); \
            direccion[mu]=&(direccion[0][mu*(height)]);}\
        }
#define ami_free3d(direccion) { free(direccion[0][0]); free(direccion[0]); free(direccion); }
#define ami_free3d_punteros(direccion) { free(direccion[0]); free(direccion); }

/* 1D allocation and freeing of memory */
#define ami_malloc1d(direccion,tipo,size) {direccion=(tipo *) malloc(sizeof(tipo)*(size));}
#define ami_calloc1d(direccion,tipo,size) {int ml; direccion=(tipo *) malloc(sizeof(tipo)*(size)); \
          for(ml=0;ml<size;ml++) direccion[ml]=0;\
        }
#define ami_free1d(direccion) { free(direccion); }

#define ami_printf2d(comentario,direccion,height,width) {int ml,mk;  \
          for(ml=0;ml<height;ml++){\
            for(mk=0;mk<width;mk++) \
              printf("%s[%d][%d]=%e ",comentario,ml,mk,(double) direccion[ml][mk]); \
            printf("\n"); }printf("\n");\
        }
#define ami_printf2d_int(comentario,direccion,height,width) {int ml,mk;  \
          for(ml=0;ml<height;ml++){\
            for(mk=0;mk<width;mk++) \
              printf("%s[%d][%d]=%d ",comentario,ml,mk,(int) direccion[ml][mk]); \
            printf("\n");}\
          printf("\n");\
        }
#define ami_printf1d(comentario,direccion,size){ int ml; \
          for(ml=0;ml<size;ml++) printf("%s[%d]=%e \n",comentario,ml,(double) direccion[ml]); \
          printf("\n");\
        }
#define ami_printf1d_int(comentario,direccion,size){ int ml; \
          for(ml=0;ml<size;ml++) printf("%s[%d]=%d ",comentario,ml,(int) direccion[ml]); \
          printf("\n");\
        }
#define ami_printf(comentario,valor) printf("%s=%e\n",comentario,(double) valor);
#define ami_printf_int(comentario,valor) printf("%s=%d\n",comentario,(int) valor);
#define ami_printf3d(comentario,direccion,depth,height,width) {int ml,mk,mu; \
          for(mu=0;mu<depth;mu++){ for(ml=0;ml<height;ml++){ for(mk=0;mk<width;mk++) \
              printf("%s[%d][%d][%d]=%e ",comentario,mu,ml,mk,(double) direccion[mu][ml][mk]); \
              printf("\n");} printf("\n");} \
        }
#define ami_printf3d_int(comentario,direccion,depth,height,width) {int ml,mk,mu; \
          for(mu=0;mu<depth;mu++){ for(ml=0;ml<height;ml++){ for(mk=0;mk<width;mk++) \
              printf("%s[%d][%d][%d]=%d ",comentario,mu,ml,mk,(int) direccion[mu][ml][mk]); \
              printf("\n");} printf("\n");} \
        }





   /* END OF OLD ami.h */

  /* START PROTOTYPES OF THE OLD calibration.h */


  #define ami_max_iter 1000
#define ami_tol 0.0000001

#define ami_swap(a,b) {double llm=(a);(a)=(b);(b)=llm;}
#define ami_swap_uchar(a,b) {unsigned char llm=(a);(a)=(b);(b)=llm;}
#define ami_swap_int(a,b) {int           llm=(a);(a)=(b);(b)=llm;}



#define ami_proyeccion_3d(P,x,m) {double mlx;\
          m[0]=P[0][0]*x[0]+P[0][1]*x[1]+P[0][2]*x[2]+P[0][3]; \
	  m[1]=P[1][0]*x[0]+P[1][1]*x[1]+P[1][2]*x[2]+P[1][3]; \
	  mlx=P[2][0]*x[0]+P[2][1]*x[1]+P[2][2]*x[2]+P[2][3]; \
	  m[0]/=mlx; m[1]/=mlx; \
        }



/* FUNCTION TO READ A 24 bits COLOR BMP FORMAT IMAGE  (RETURN 0 IF FINISH PROPERLY -1 OTHERWISE) */

/* END OF PROTOTYPES OLD ami_bmp.h */

/* START OF PROTOTYPES OLD ami_fft.h */

#define SWAP(a,b) tempr=(a);(a)=(b);(b)=tempr


/* END OF PROTOTYPES OLD opticzoom.h */

/* START OF PROTOTYPES OLD ami_ami_glow_flow_zoom.h */
//#ifndef _GLOBFLOW_
//#define _GLOBFLOW_
#define PI 3.1415927

#ifdef ABS
#undef ABS
#endif
#define ABS(x) (((x)>0)?(x):-(x))
#define Normalizar(x) ((x)<0?0:((x)>255?255:x))
#define Max(a,b) ((a>b)?a:b)

#define UV_NULL_VALUE 10000
//const float UV_NULL_VALUE = 10000;


#endif
