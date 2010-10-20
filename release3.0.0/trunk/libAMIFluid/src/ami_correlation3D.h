//
// C++ Interface: ami_correlation3D
//
// Description:
//
//
// Author:  <>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef AMI_CORRELATION3D_H
#define AMI_CORRELATION3D_H

#include "ami_prototypes.h"

/**
 * FUNCTION TO COMPUTE 3D OPTIC FLOW USING A CORRELATION TECHNIQUE
 *
 * the vectorial image is exactly of the size of the stored value
 * to avoid using too much memory
 **/
template <class T>
void ami_optic_flow_correlation_3d_new(
   T ***image_1,T ***image_2,int dim_x,
   int dim_y,int dim_z,ami_v3f ***u, ami_v3f p_init,ami_v3f p_disp,
   int size_correlation_window[3],
   int num_threads);

/**
 * FUNCTION TO COMPUTE 3D OPTIC FLOW USING A CORRELATION TECHNIQUE          
 **/
void ami_optic_flow_correlation_3d(float ***image_1,float ***image_2,int dim_x,
                                   int dim_y,int dim_z,ami_v3f ***u, ami_v3f p_init,ami_v3f p_disp,
                                   int size_correlation_window[3],float window_deformation);


/** 
 * FUNCTION TO EXTRAPOLATE THE 3D OPTIC FLOW TO POINTS WHERE IS NOT DEFINED 
 */
void ami_optic_flow_extrapolation_v3f(ami_v3f ***u,ami_v3f p_init,ami_v3f p_disp,
                                      float displacement,int dim_x,int dim_y,int dim_z);



// here put the template code

#include <pthread.h>

template <class T>
void ami_subwindow(    
    T ***image_1,/* IMAGE PAIR (INPUT DATA) */
    T ***image_2,/* IMAGE PAIR (INPUT DATA) */
    float ***da1_c, // 1st subwindow result
    float ***da2_c, // 2nd subwindow result
    int i, int j, int k, // voxel position of window center in image_1
    int ui, int uj, int uk, // corresponding position in the vector field image
    int dim_x,int dim_y,int dim_z,/* IMAGE DIMENSIONS (INPUT DATA) */
    ami_v3f ***u, /* COMPUTED FLOW (OUTPUT FLOW) of reduced dimensions*/
    int size_correlation_window[3])/* SIZE OF THE CORRELATION WINDOW */ 
{
    register int i1,j1,k1;
    register int i2,j2,k2;
    register int i4,j4,k4;
    register double dx,dy,dz;
    double x,y,z;
    register T* image2_ptr;
    register T* image1_ptr;
    ami_v3f* vect;
    int corr_size_x2, corr_size_y2, corr_size_z2;
    register float* da1_c_ptr;
    register float* da2_c_ptr;

    register int n0,n1,n2,n3,n4,n5,n6,n7;

    corr_size_x2 = size_correlation_window[0]/2;
    corr_size_y2 = size_correlation_window[1]/2;
    corr_size_z2 = size_correlation_window[2]/2;

    // precompute step to neighbors
    n0=0;
    n1=1;
    n2=dim_z;
    n3=dim_z+1;
    n4=dim_y*dim_z;
    n5=dim_y*dim_z+1;
    n6=dim_y*dim_z+dim_z;
    n7=dim_y*dim_z+dim_z+1;


    da1_c_ptr = da1_c[0][0];
    da2_c_ptr = da2_c[0][0];

    vect = &u[ui][uj][uk];
    float vx=(*vect)[0];
    float vy=(*vect)[1];
    float vz=(*vect)[2];


    int in_limits;
    register int i_min = i-corr_size_x2;
    register int i_max = i+corr_size_x2;
    register int j_min = j-corr_size_y2;
    register int j_max = j+corr_size_y2;
    register int k_min = k-corr_size_z2;
    register int k_max = k+corr_size_z2;
    // check all limits
    in_limits = (i_min>=0)       && (i_min+vx>=0)       && // x min
                (i_max<=dim_x-1) && (i_max+vx<=dim_x-1) && // x max
                (j_min>=0)       && (j_min+vy>=0)       && // y min
                (j_max<=dim_y-1) && (j_max+vy<=dim_y-1) && // y max
                (k_min>=0)       && (k_min+vz>=0)       && // z min
                (k_max<=dim_z-1) && (k_max+vz<=dim_z-1);   // z max

  if (in_limits) {

   // no boundary checks
   int vx_int,vy_int,vz_int;
   vx_int = (int) floor(vx);
   vy_int = (int) floor(vy);
   vz_int = (int) floor(vz);

   dx = vx-vx_int;
   dy = vy-vy_int;
   dz = vz-vz_int;

   register double dx1,dy1,dz1;
   register double c0,c1,c2,c3,c4,c5,c6,c7;

   dx1=1-dx;
   dy1=1-dy;
   dz1=1-dz;

   c0=dx1*dy1*dz1;
   c1=dx1*dy1*dz ;
   c2=dx1*dy *dz1;
   c3=dx1*dy *dz ;
   c4=dx *dy1*dz1;
   c5=dx *dy1*dz ;
   c6=dx *dy *dz1;
   c7=dx *dy *dz ;


    /* WE COMPUTE EACH SUBWINDOW */
    for(i1=i_min;i1<i_max;i1++) {
        for(j1=j_min;j1<j_max;j1++) {
            image1_ptr = &image_1[i1][j1][k_min];
            image2_ptr = &image_2[i1+vx_int][j1+vy_int][k_min+vz_int];
            for(k1=k_min;k1<k_max;k1++) {
                *da1_c_ptr=*image1_ptr;
                *da2_c_ptr=
                            c7*image2_ptr[n7]+
                            c6*image2_ptr[n6]+
                            c5*image2_ptr[n5]+
                            c4*image2_ptr[n4]+
                            c3*image2_ptr[n3]+
                            c2*image2_ptr[n2]+
                            c1*image2_ptr[n1]+
                            c0*image2_ptr[n0] ;
            da1_c_ptr++;
            da2_c_ptr++;
            image1_ptr++;
            image2_ptr++;
            }
        }
    }


  } else {

    /* WE COMPUTE EACH SUBWINDOW */
    for(i2=i_min;i2<i_max;i2++) {
        for(j2=j_min;j2<j_max;j2++) {
            for(k2=k_min;k2<k_max;k2++) {
                i1=i2<0?0:(i2<dim_x?i2:dim_x-1);
                j1=j2<0?0:(j2<dim_y?j2:dim_y-1);
                k1=k2<0?0:(k2<dim_z?k2:dim_z-1);
                *da1_c_ptr=image_1[i1][j1][k1];
                x=i1+vx;
                y=j1+vy;
                z=k1+vz;
                if(x<0) {
                    i4=0;
                    dx=0.;
                } else if(x>=(dim_x-1)) {
                    i4=dim_x-2;
                    dx=1.;
                } else {
                    i4=(int)x;
                    dx=x-i4;
                }
                if(y<0) {
                    j4=0;
                    dy=0.;
                } else if(y>=(dim_y-1)) {
                    j4=dim_y-2;
                    dy=1.;
                } else {
                    j4=(int)y;
                    dy=y-j4;
                }
                if(z<0) {
                    k4=0;
                    dz=0.;
                } else if(z>=(dim_z-1)) {
                    k4=dim_z-2;
                    dz=1.;
                } else {
                    k4=(int)z;
                    dz=z-k4;
                }
                image2_ptr = &image_2[i4][j4][k4];
                *da2_c_ptr=
                                  dx  *(dy  *(dz  *image2_ptr[n7]+
                                              (1-dz)*image2_ptr[n6]
                                             )+
                                        (1-dy)*(dz  *image2_ptr[n5]+
                                                (1-dz)*image2_ptr[n4]
                                               )
                                       )+
                                  (1-dx)*( dy  *(dz  *image2_ptr[n3]+
                                                 (1-dz)*image2_ptr[n2]
                                                )+
                                           (1-dy)*(dz  *image2_ptr[n1]+
                                                   (1-dz)*image2_ptr[n0]
                                                  )
                                         )
                                   ;
            da1_c_ptr++;
            da2_c_ptr++;
            }
        }
    }
  }
} //ami_subwindow()


template <class T>
struct thread_correlation_info {
    int  thread_id;                 /* number of current thread */
    int  total_threads;             /* number of threads */
    T ***image_1;               /* IMAGE PAIR (INPUT DATA) */
    T ***image_2;               /* IMAGE PAIR (INPUT DATA) */
    int dim_x,dim_y,dim_z;          /* IMAGE DIMENSIONS (INPUT DATA) */
    ami_v3f ***u;                   /* COMPUTED FLOW (OUTPUT FLOW) of reduced dimensions*/
    ami_v3f p_init;                 /* INITIAL POINT OF THE LATTICE */
    ami_v3f p_disp;                 /* DISPLACEMENT TO COMPUTE THE LATTICE */
    int size_correlation_window[3]; /* SIZE OF THE CORRELATION WINDOW */
};

/**
 * FUNCTION TO COMPUTE 3D OPTIC FLOW USING A CORRELATION TECHNIQUE
 *
 * the vectorial image is exactly of the size of the stored value
 * to avoid using too much memory
 **/
template <class T>
void* ami_thread_optic_flow_correlation_3d_new( void* threadarg)
{
    // loading arguments
    thread_correlation_info<T>* args = (thread_correlation_info<T>*) threadarg;
    T ***image_1 = args->image_1; /* IMAGE PAIR (INPUT DATA) */
    T ***image_2 = args->image_2; /* IMAGE PAIR (INPUT DATA) */
    int dim_x = args->dim_x;
    int dim_y = args->dim_y;
    int dim_z = args->dim_z;
    ami_v3f ***u = args->u; /* COMPUTED FLOW (OUTPUT FLOW) of reduced dimensions*/
    ami_v3f p_init;
    p_init[0] = args->p_init[0];
    p_init[1] = args->p_init[1];
    p_init[2] = args->p_init[2];
    ami_v3f p_disp;
    p_disp[0] = args->p_disp[0];
    p_disp[1] = args->p_disp[1];
    p_disp[2] = args->p_disp[2];
    int size_correlation_window[3];
    size_correlation_window[0] = args->size_correlation_window[0];
    size_correlation_window[1] = args->size_correlation_window[1];
    size_correlation_window[2] = args->size_correlation_window[2];

    float ***da1_c,***da2_c,correlation,paso;
    int i2,j2,i,j,k,k2,i3=0,j3=0,k3=0;
    int ui,uj,uk;
//    long m;
    int scw[3];
    int di1,di2,dj1,dj2,dk1,dk2,l;
    ami_v3f disp;
    double ln_1,ln_2,ln_3,den;
    int dim1_x,dim1_y,dim1_z;
    long point_index;

    printf("Thread %d / %d \n",args->thread_id+1,args->total_threads);

    /* WE COPY size_correlation_window[3] IN THE AUXILIARY VARIABLE scw[3] */
    for(l=0;l<3;l++)
        scw[l]=size_correlation_window[l];
    /* WE ALLOCATE MEMORY */
    ami_malloc3d(da1_c,float,size_correlation_window[0],size_correlation_window[1],size_correlation_window[2]);
    ami_malloc3d(da2_c,float,size_correlation_window[0],size_correlation_window[1],size_correlation_window[2]);

    // computing the size of the displacement image
    dim1_x = 1+(int)((1.0*(dim_x-1)-p_init[0])/((float)((int)p_disp[0])));
    dim1_y = 1+(int)((1.0*(dim_y-1)-p_init[1])/((float)((int)p_disp[1])));
    dim1_z = 1+(int)((1.0*(dim_z-1)-p_init[2])/((float)((int)p_disp[2])));

    point_index = 0;
    /* WE COMPUTE THE CORRELATION IN EACH POINT ON THE LATTICE */
    for(i=(int)p_init[0],ui=0;i<dim_x;i+=(int)p_disp[0],ui++) {
        //printf("Corr3DNew i= %d / %d \n",i,dim_x);
        for(j=(int)p_init[1],uj=0;j<dim_y;j+=(int)p_disp[1],uj++) {
            for(k=(int)p_init[2],uk=0;k<dim_z;k+=(int)p_disp[2],uk++,point_index++) {
                //printf("%d %d %d \n",i,j,k);

                // Computes the n^th point of every num_thread points
                if (point_index%args->total_threads != args->thread_id) 
                    continue;

                /* WE COMPUTE EACH SUBWINDOW */
                ami_subwindow<T>(image_1,image_2,da1_c,da2_c,i,j,k,ui,uj,uk,dim_x,dim_y,dim_z,u,size_correlation_window);
                /* WE COMPUTE THE CORRELATION */
                ami_fft_correlation(da1_c,da2_c, (long) size_correlation_window[0], (long) size_correlation_window[1], (long) size_correlation_window[2]);

                /* WE COMPUTE THE MAXIMUN OF THE CORRELATION TO ESTIMATE THE FLOW TAKING INTO ACCOUNT THE PERIODICITY OF THE SIGNAL */
                correlation=-10e+10;
                for(i2=0;i2<size_correlation_window[0];i2++) {
                    for(j2=0;j2<size_correlation_window[1];j2++) {
                        for(k2=0;k2<size_correlation_window[2];k2++) {
                            if(da1_c[i2][j2][k2]>correlation) {
                                correlation=da1_c[i2][j2][k2];
                                i3=i2;
                                j3=j2;
                                k3=k2;
                            }
                        }
                    }
                }

                /* WE COMPUTE THE CORRELATION MAXIMUM WITH SUBPIXEL PRECISION USING A GAUSSIAN*/
                di1=i3>0?-1:scw[0]-1-i3;
                di2=(i3<(scw[0]-1))?1:-i3;
                dj1=j3>0?-1:scw[1]-1-j3;
                dj2=(j3<(scw[1]-1))?1:-j3;
                dk1=k3>0?-1:scw[2]-1-k3;
                dk2=(k3<(scw[2]-1))?1:-k3;

                ln_1=da1_c[i3+di1][j3][k3];
                ln_2=da1_c[i3][j3][k3];
                ln_3=da1_c[i3+di2][j3][k3];
                if(ln_1<=0 || ln_2<=0 || ln_3<=0) {
                    paso=i3;
                } else {
                    ln_1=log(ln_1);
                    ln_2=log(ln_2);
                    ln_3=log(ln_3);
                    den=2.*(ln_1-2.*ln_2+ln_3);
                    if(den==0) {
                        paso=i3;
                    } else {
                        paso=i3+(ln_1-ln_3)/den;
                    }
                }
                //u[i][j][k][0]+=(paso<scw[0]/2)?paso:paso-scw[0];
                disp[0] = (paso<scw[0]/2)?paso:paso-scw[0];

                ln_1=da1_c[i3][j3+dj1][k3];
                ln_2=da1_c[i3][j3][k3];
                ln_3=da1_c[i3][j3+dj2][k3];
                if(ln_1<=0 || ln_2<=0 || ln_3<=0) {
                    paso=j3;
                } else {
                    ln_1=log(ln_1);
                    ln_2=log(ln_2);
                    ln_3=log(ln_3);
                    den=2.*(ln_1-2.*ln_2+ln_3);
                    if(den==0) {
                        paso=j3;
                    } else {
                        paso=j3+(ln_1-ln_3)/den;
                    }
                }
                //u[i][j][k][1]+=(paso<scw[1]/2)?paso:paso-scw[1];
                disp[1] = (paso<scw[1]/2)?paso:paso-scw[1];

                ln_1=da1_c[i3][j3][k3+dk1];
                ln_2=da1_c[i3][j3][k3];
                ln_3=da1_c[i3][j3][k3+dk2];
                if(ln_1<=0 || ln_2<=0 || ln_3<=0) {
                    paso=k3;
                } else {
                    ln_1=log(ln_1);
                    ln_2=log(ln_2);
                    ln_3=log(ln_3);
                    den=2.*(ln_1-2.*ln_2+ln_3);
                    if(den==0) {
                        paso=k3;
                    } else {
                        paso=k3+(ln_1-ln_3)/den;
                    }
                }
                //u[i][j][k][2]+=(paso<scw[2]/2)?paso:paso-scw[2];
                disp[2] = (paso<scw[2]/2)?paso:paso-scw[2];
                
                /* WE UPDATE THE VECTOR FIELD AT i,j,k */
                u[ui][uj][uk][0] += disp[0];
                u[ui][uj][uk][1] += disp[1];
                u[ui][uj][uk][2] += disp[2];
            }
        }
    }   

    /* WE FREE THE MEMORY */
    ami_free3d(da1_c);
    ami_free3d(da2_c);

   pthread_exit(NULL);
   return NULL;
}

/******************************************************************************************************/
template <class T>
void ami_optic_flow_correlation_3d_new(
    T ***image_1,                /* IMAGE PAIR (INPUT DATA) */
    T ***image_2,                /* IMAGE PAIR (INPUT DATA) */
    int dim_x,int dim_y,int dim_z,   /* IMAGE DIMENSIONS (INPUT DATA) */
    ami_v3f ***u,                    /* COMPUTED FLOW (OUTPUT FLOW) of reduced dimensions*/
    ami_v3f p_init,                  /* INITIAL POINT OF THE LATTICE */
    ami_v3f p_disp,                  /* DISPLACEMENT TO COMPUTE THE LATTICE */
    int size_correlation_window[3],  /* SIZE OF THE CORRELATION WINDOW */
    int num_threads)
{
    int dim1_x,dim1_y,dim1_z;
    ami_v3f ***u_p;
    float *x_m;
    int ui,uj,uk,Np;
    double paso;

    thread_correlation_info<T>* thread_info;
    int i,j,l;
    pthread_t* threads;
    pthread_attr_t attr;
    int rc,status;

    // computing the size of the displacement image
    dim1_x = 1+(int)((1.0*(dim_x-1)-p_init[0])/((float)((int)p_disp[0])));
    dim1_y = 1+(int)((1.0*(dim_y-1)-p_init[1])/((float)((int)p_disp[1])));
    dim1_z = 1+(int)((1.0*(dim_z-1)-p_init[2])/((float)((int)p_disp[2])));
    printf("displ image size = %d %d %d\n",dim1_x,dim1_y,dim1_z);

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    thread_info = (thread_correlation_info<T>*) malloc(num_threads*sizeof(thread_correlation_info<T>));
    threads = (pthread_t*) malloc(num_threads*sizeof(pthread_t));

    for (i=0;i<num_threads;i++) {
      thread_info[i].thread_id = i;
      thread_info[i].total_threads = num_threads;
      thread_info[i].image_1 = image_1;
      thread_info[i].image_2 = image_2;
      thread_info[i].dim_x = dim_x;
      thread_info[i].dim_y = dim_y;
      thread_info[i].dim_z = dim_z;
      thread_info[i].u = u;
      for (j=0;j<3;j++) {
        thread_info[i].p_init[j] = p_init[j];
        thread_info[i].p_disp[j] = p_disp[j];
        thread_info[i].size_correlation_window[j] = size_correlation_window[j];
      }
      rc = pthread_create(&threads[i], &attr, ami_thread_optic_flow_correlation_3d_new<T>, (void *) &thread_info[i]);
      if (rc) {
        printf("ami_optic_flow_correlation_3d_new() \t ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
      }
   }

   /* Free attribute and wait for the other threads */
   pthread_attr_destroy(&attr);
   for(i=0; i<num_threads; i++)
   {
      rc = (int) pthread_join((pthread_t)threads[i], (void **)&status);
      if (rc)
      {
         printf("ami_optic_flow_correlation_3d_new() \t ERROR; return code from pthread_join()  is %d\n", rc);
      }
      printf("Completed join with thread %d status= %d\n",i, status);
   }

    printf("starts median filter regularization \n");
    /* WE REGULARIZE THE RESULT USING A MEDIAN FILTER */
    ami_malloc1d(x_m,float,7);
    ami_malloc3d(u_p,ami_v3f,dim1_x,dim1_y,dim1_z);
    ami_copy_v3f(u,u_p,dim1_x,dim1_y,dim1_z);
    for(ui=0;ui<dim1_x;ui++) {
//        printf("ui = %d \n",ui);
        for(uj=0;uj<dim1_y;uj++) {
            for(uk=0;uk<dim1_z;uk++) {
                for(l=0;l<3;l++) {
                    Np=0;
                    x_m[Np]=u_p[ui][uj][uk][l];
                    Np++;
                    if(ui-1>0) {
                        x_m[Np]=u_p[ui-1][uj][uk][l];
                        Np++;
                    }
                    if(ui+1<dim1_x) {
                        x_m[Np]=u_p[ui+1][uj][uk][l];
                        Np++;
                    }
                    if(uj-1>0) {
                        x_m[Np]=u_p[ui][uj-1][uk][l];
                        Np++;
                    }
                    if ((uj+1)<dim1_y){
                        x_m[Np]=u_p[ui][uj+1][uk][l];
                        Np++;
                    }
                    if(uk-1>0) {
                        x_m[Np]=u_p[ui][uj][uk-1][l];
                        Np++;
                    }
                    if ((uk+1)<dim1_z){
                        x_m[Np]=u_p[ui][uj][uk+1][l];
                        Np++;
                    }
                    paso=ami_mediana_float(Np/2,Np,x_m);
                    if(fabs(paso-u[ui][uj][uk][l])>(0.5*p_disp[l]))
                        u[ui][uj][uk][l]=paso;
                }
            }
        }
    }

    /* WE FREE THE MEMORY */
    free(x_m);
    free(thread_info);
    free(threads);
    ami_free3d(u_p);

}

#endif
