/*
*  C Implementation: ami_correlation3D
*
* Description: 
*
*
* Author:  <>, (C) 2006
*
* Copyright: See COPYING file that comes with this distribution
*
*/

#include "ami_correlation3D.h"

/******************************************************************************************************
  FUNCTION TO COMPUTE 3D OPTIC FLOW USING A CORRELATION TECHNIQUE WITHOUT USING A DISPLACEMENT TO CENTER
  THE WINDOW AROUND THE POINT
*******************************************************************************************************/
void ami_optic_flow_correlation_3d(
    float ***image_1,float ***image_2,/* IMAGE PAIR (INPUT DATA) */
    int dim_x,int dim_y,int dim_z,/* IMAGE DIMENSIONS (INPUT DATA) */
    ami_v3f ***u, /* COMPUTED FLOW (OUTPUT FLOW) */
    ami_v3f p_init, /* INITIAL POINT OF THE LATTICE */
    ami_v3f p_disp, /* DISPLACEMENT TO COMPUTE THE LATTICE */
    int size_correlation_window[3],/* SIZE OF THE CORRELATION WINDOW */
    float window_deformation) /* WINDOW PARAMETER TO CONTROL THE WARPING IN THE CORRELATION WINDOW
	                              window_deformation=0 : image_2 IS WARPED USING FLOW IN ALL POINTS OF THE WINDOW
								  window_deformation=1 : image_2 IS WARPED USING FLOW IN THE CENTRAL POINT OF THE WINDOW */
{
    float ***da1_c,***da2_c,correlation,paso,x,y,z,dx,dy,dz;
    int i2,j2,i1,j1,i,j,k,k2,k1,i3,j3=0,k3=0,i4,j4,k4,Np;
//    long m;
    int scw[3];
    int di1,di2,dj1,dj2,dk1,dk2,l;
	ami_v3f ***u_p, disp, disp_d;
    float *x_m;
    double ln_1,ln_2,ln_3,den;
    /* WE COPY size_correlation_window[3] IN THE AUXILIARY VARIABLE scw[3] */
    for(l=0;l<3;l++)
        scw[l]=size_correlation_window[l];
    /* WE ALLOCATE MEMORY */
    ami_malloc3d(da1_c,float,size_correlation_window[0],size_correlation_window[1],size_correlation_window[2]);
    ami_malloc3d(da2_c,float,size_correlation_window[0],size_correlation_window[1],size_correlation_window[2]);
    ami_malloc3d(u_p,ami_v3f,dim_x,dim_y,dim_z);
    ami_malloc1d(x_m,float,7);
	/* WE COPY THE CURRENT FLOW TO HAVE A COPY WITHOUT UPDATES (FOR DEFORMATION)*/
    ami_copy_v3f(u,u_p,dim_x,dim_y,dim_z);
    /* WE COMPUTE THE CORRELATION IN EACH POINT ON THE LATTICE */
    for(i=(int)p_init[0];i<dim_x;i+=(int)p_disp[0]) {
        printf("Corr3D i= %d / %d \n",i,dim_x);
        for(j=(int)p_init[1];j<dim_y;j+=(int)p_disp[1]) {
            for(k=(int)p_init[2];k<dim_z;k+=(int)p_disp[2]) {
                /* WE COMPUTE EACH SUBWINDOW */
                for(i3=0, i2=i-size_correlation_window[0]/2;i2<(i+size_correlation_window[0]/2);i2++,i3++) {
                    for(j3=0,j2=j-size_correlation_window[1]/2;j2<(j+size_correlation_window[1]/2);j2++,j3++) {
                        for(k3=0,k2=k-size_correlation_window[2]/2;k2<(k+size_correlation_window[2]/2);k2++,k3++) {
                            i1=i2<0?0:(i2<dim_x?i2:dim_x-1);
                            j1=j2<0?0:(j2<dim_y?j2:dim_y-1);
                            k1=k2<0?0:(k2<dim_z?k2:dim_z-1);
                            da1_c[i3][j3][k3]=image_1[i1][j1][k1];
                            x=i1+(1.-window_deformation)*u_p[i1][j1][k1][0]+window_deformation*u[i][j][k][0];
                            y=j1+(1.-window_deformation)*u_p[i1][j1][k1][1]+window_deformation*u[i][j][k][1];
                            z=k1+(1.-window_deformation)*u_p[i1][j1][k1][2]+window_deformation*u[i][j][k][2];
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
                            da2_c[i3][j3][k3]=(1-dx)*(1-dy)*(1-dz)*image_2[i4][j4][k4]+
                                              (dx)*(1-dy)*(1-dz)*image_2[i4+1][j4][k4]+
                                              (dx)*(dy)*(1-dz)*image_2[i4+1][j4+1][k4]+
                                              (dx)*(dy)*(dz)*image_2[i4+1][j4+1][k4+1]+
                                              (dx)*(1-dy)*(dz)*image_2[i4+1][j4][k4+1]+
                                              (1-dx)*(dy)*(1-dz)*image_2[i4][j4+1][k4]+
                                              (1-dx)*(dy)*(dz)*image_2[i4][j4+1][k4+1]+
                                              (1-dx)*(1-dy)*(dz)*image_2[i4][j4][k4+1];
                        }
                    }
                }
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
                /* WE COMPUTE THE CORRELATION MAXIMUM WITH SUBPIXEL PRECISION USING A POLINOMIAL */
                //printf("(%d,%d,%d) \n",i3,j3,k3);
                /*di1=i3>0?-1:scw-1-i3; di2=(i3<(scw-1))?1:-i3;
                dj1=j3>0?-1:scw-1-j3; dj2=(j3<(scw-1))?1:-j3;
                dk1=k3>0?-1:scw-1-k3; dk2=(k3<(scw-1))?1:-k3;
                den=2.*(da1_c[i3+di1][j3][k3]+da1_c[i3+di2][j3][k3])-4.*da1_c[i3][j3][k3];
                paso=(den==0)?i3:i3+1.*(da1_c[i3+di1][j3][k3]-da1_c[i3+di2][j3][k3])/den;
                u[i][j][k][0]+=(paso<scw/2)?paso:paso-scw;

                den=2.*(da1_c[i3][j3+dj1][k3]+da1_c[i3][j3+dj2][k3])-4.*da1_c[i3][j3][k3];
                paso=(den==0)?j3:j3+1.*(da1_c[i3][j3+dj1][k3]-da1_c[i3][j3+dj2][k3])/den;
                u[i][j][k][1]+=(paso<scw/2)?paso:paso-scw;

                den=2.*(da1_c[i3][j3][k3+dk1]+da1_c[i3][j3][k3+dk2])-4.*da1_c[i3][j3][k3];
                paso=(den==0)?k3:k3+1.*(da1_c[i3][j3][k3+dk1]-da1_c[i3][j3][k3+dk2])/den;
                u[i][j][k][2]+=(paso<scw/2)?paso:paso-scw; */

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
				if (window_deformation == 0) {
					/* WE HAVE TO WARP THE POINT FIRST */
					ami_point_interpolation_v3f(u_p,i,j,k,disp,disp_d,dim_x,dim_y,dim_z);
					//printf(" %f %f %f \t %f %f %f\t %f %f %f \n",
					//	   u[i][j][k][0],u[i][j][k][1],u[i][j][k][2],
					//	   disp[0],disp[1],disp[2],
					//	   disp_d[0],disp_d[1],disp_d[2]
					//	  );
					u[i][j][k][0] = disp[0] + disp_d[0];
					u[i][j][k][1] = disp[1] + disp_d[1];
					u[i][j][k][2] = disp[2] + disp_d[2];
				}
				else {
					u[i][j][k][0] += disp[0];
					u[i][j][k][1] += disp[1];
					u[i][j][k][2] += disp[2];
				}
				
            }
        }
    }	
	
    /* WE REGULARIZE THE RESULT USING A MEDIAN FILTER */
	ami_copy_v3f(u,u_p,dim_x,dim_y,dim_z);
	for(i=(int)p_init[0];i<dim_x;i+=(int)p_disp[0]) {
		for(j=(int)p_init[1];j<dim_y;j+=(int)p_disp[1]) {
			for(k=(int)p_init[2];k<dim_z;k+=(int)p_disp[2]) {
				for(l=0;l<3;l++) {
					Np=0;
					x_m[Np]=u_p[i][j][k][l];
					Np++;
					if(i>p_init[0]) {
						x_m[Np]=u_p[i-(int)p_disp[0]][j][k][l];
						Np++;
					}
                    if ((i+p_disp[0])<dim_x){
						x_m[Np]=u_p[i+(int)p_disp[0]][j][k][l];
						Np++;
					}
					if(j>p_init[1]) {
						x_m[Np]=u_p[i][j-(int)p_disp[1]][k][l];
						Np++;
					}
                    if ((j+p_disp[1])<dim_y){
						x_m[Np]=u_p[i][j+(int)p_disp[1]][k][l];
						Np++;
					}
					if(k>p_init[2]) {
						x_m[Np]=u_p[i][j][k-(int)p_disp[2]][l];
						Np++;
					} 
                    if ((k+p_disp[2])<dim_z){
						x_m[Np]=u_p[i][j][k+(int)p_disp[2]][l];
						Np++;
					}
					paso=ami_mediana_float(Np/2,Np,x_m);
					if(fabs(paso-u[i][j][k][l])>(0.5*p_disp[l]))
						u[i][j][k][l]=paso;
					//if(i==8 && j==8 && (k==0 || k==8)) {for(m=0;m<Np;m++) printf("%1.2f ",x_m[m]); printf("k=%d    %f\n",k,u[i][j][k][l]);}
	
				}
			}
		}
	}

    /* WE FREE THE MEMORY */
    ami_free3d(da1_c);
    ami_free3d(da2_c);
    free(x_m);
    ami_free3d(u_p);
}




/******************************************************************************************************
  FUNCTION TO COMPUTE 3D OPTIC FLOW USING A CORRELATION TECHNIQUE USING A DISPLACEMENT TO CENTER THE
  WINDOW AROUND THE POINT
*******************************************************************************************************/
void ami_optic_flow_correlation_3d_old(
    float ***image_1,float ***image_2,/* IMAGE PAIR (INPUT DATA) */
    int dim_x,int dim_y,int dim_z,/* IMAGE DIMENSIONS (INPUT DATA) */
    ami_v3f ***u, /* COMPUTED FLOW (OUTPUT FLOW) */
    ami_v3f p_init, /* INITIAL POINT OF THE LATTICE */
    ami_v3f p_disp, /* DISPLACEMENT TO COMPUTE THE LATTICE */
    int size_correlation_window,/* SIZE OF THE CORRELATION WINDOW */
    float window_deformation) /* WINDOW PARAMETER TO CONTROL THE WARPING IN THE CORRELATION WINDOW
	                              window_deformation=0 : image_2 IS WARPED USING FLOW IN ALL POINTS OF THE WINDOW
								  window_deformation=1 : image_2 IS WARPED USING FLOW IN THE CENTRAL POINT OF THE WINDOW */
{
    float ***da1_c,***da2_c,correlation,paso,x,y,z,dx,dy,dz;
    int i2,j2,i1,j1,i,j,k,k2,k1,i3,j3=0,k3=0,i4,j4,k4,Np;
//    long m;
    int scw=size_correlation_window;
    int di1,di2,dj1,dj2,dk1,dk2,l;
    ami_v3f ***u_p;
    float *x_m;
    double ln_1,ln_2,ln_3,den;
    /* WE ALLOCATE MEMORY */
    ami_malloc3d(da1_c,float,size_correlation_window,size_correlation_window,size_correlation_window);
    ami_malloc3d(da2_c,float,size_correlation_window,size_correlation_window,size_correlation_window);
    ami_malloc3d(u_p,ami_v3f,dim_x,dim_y,dim_z);
    ami_malloc1d(x_m,float,7);
    /* WE COPY THE CURRENT FLOW */
    ami_copy_v3f(u,u_p,dim_x,dim_y,dim_z);
    /* WE COMPUTE THE CORRELATION IN EACH POINT ON THE LATTICE */
    for(i=(int)p_init[0];i<dim_x;i+=(int)p_disp[0]) {
        for(j=(int)p_init[1];j<dim_y;j+=(int)p_disp[1]) {
            for(k=(int)p_init[2];k<dim_z;k+=(int)p_disp[2]) {
                /* WE COMPUTE EACH SUBWINDOW */
                for(i3=0, i2=i-size_correlation_window/2;i2<(i+size_correlation_window/2);i2++,i3++) {
                    for(j3=0,j2=j-size_correlation_window/2;j2<(j+size_correlation_window/2);j2++,j3++) {
                        for(k3=0,k2=k-size_correlation_window/2;k2<(k+size_correlation_window/2);k2++,k3++) {
                            i1=i2<0?0:(i2<dim_x?i2:dim_x-1);
                            j1=j2<0?0:(j2<dim_y?j2:dim_y-1);
                            k1=k2<0?0:(k2<dim_z?k2:dim_z-1);
                            da1_c[i3][j3][k3]=image_1[i1][j1][k1];
                            x=i1+0.5;
                            y=j1+0.5;
                            z=k1+0.5;
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
                            da1_c[i3][j3][k3]=(1-dx)*(1-dy)*(1-dz)*image_1[i4][j4][k4]+
                                              (dx)*(1-dy)*(1-dz)*image_1[i4+1][j4][k4]+
                                              (dx)*(dy)*(1-dz)*image_1[i4+1][j4+1][k4]+
                                              (dx)*(dy)*(dz)*image_1[i4+1][j4+1][k4+1]+
                                              (dx)*(1-dy)*(dz)*image_1[i4+1][j4][k4+1]+
                                              (1-dx)*(dy)*(1-dz)*image_1[i4][j4+1][k4]+
                                              (1-dx)*(dy)*(dz)*image_1[i4][j4+1][k4+1]+
                                              (1-dx)*(1-dy)*(dz)*image_1[i4][j4][k4+1];
                            x=i1+(1.-window_deformation)*u_p[i1][j1][k1][0]+window_deformation*u[i][j][k][0]+0.5;
                            y=j1+(1.-window_deformation)*u_p[i1][j1][k1][1]+window_deformation*u[i][j][k][1]+0.5;
                            z=k1+(1.-window_deformation)*u_p[i1][j1][k1][2]+window_deformation*u[i][j][k][2]+0.5;
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
                            da2_c[i3][j3][k3]=(1-dx)*(1-dy)*(1-dz)*image_2[i4][j4][k4]+
                                              (dx)*(1-dy)*(1-dz)*image_2[i4+1][j4][k4]+
                                              (dx)*(dy)*(1-dz)*image_2[i4+1][j4+1][k4]+
                                              (dx)*(dy)*(dz)*image_2[i4+1][j4+1][k4+1]+
                                              (dx)*(1-dy)*(dz)*image_2[i4+1][j4][k4+1]+
                                              (1-dx)*(dy)*(1-dz)*image_2[i4][j4+1][k4]+
                                              (1-dx)*(dy)*(dz)*image_2[i4][j4+1][k4+1]+
                                              (1-dx)*(1-dy)*(dz)*image_2[i4][j4][k4+1];
                        }
                    }
                }
                /* WE COMPUTE THE CORRELATION */
                ami_fft_correlation(da1_c,da2_c, (long) size_correlation_window, (long) size_correlation_window, (long) size_correlation_window);

                /* WE COMPUTE THE MAXIMUN OF THE CORRELATION TO ESTIMATE THE FLOW TAKING INTO ACCOUNT THE PERIODICITY OF THE SIGNAL */
                correlation=-10e+10;
                for(i2=0;i2<size_correlation_window;i2++) {
                    for(j2=0;j2<size_correlation_window;j2++) {
                        for(k2=0;k2<size_correlation_window;k2++) {
                            if(da1_c[i2][j2][k2]>correlation) {
                                correlation=da1_c[i2][j2][k2];
                                i3=i2;
                                j3=j2;
                                k3=k2;
                            }
                        }
                    }
                }
                /* WE COMPUTE THE CORRELATION MAXIMUM WITH SUBPIXEL PRECISION USING A POLINOMIAL */
                //printf("(%d,%d,%d) \n",i3,j3,k3);
                /*di1=i3>0?-1:scw-1-i3; di2=(i3<(scw-1))?1:-i3;
                dj1=j3>0?-1:scw-1-j3; dj2=(j3<(scw-1))?1:-j3;
                dk1=k3>0?-1:scw-1-k3; dk2=(k3<(scw-1))?1:-k3;
                den=2.*(da1_c[i3+di1][j3][k3]+da1_c[i3+di2][j3][k3])-4.*da1_c[i3][j3][k3];
                paso=(den==0)?i3:i3+1.*(da1_c[i3+di1][j3][k3]-da1_c[i3+di2][j3][k3])/den;
                u[i][j][k][0]+=(paso<scw/2)?paso:paso-scw;

                den=2.*(da1_c[i3][j3+dj1][k3]+da1_c[i3][j3+dj2][k3])-4.*da1_c[i3][j3][k3];
                paso=(den==0)?j3:j3+1.*(da1_c[i3][j3+dj1][k3]-da1_c[i3][j3+dj2][k3])/den;
                u[i][j][k][1]+=(paso<scw/2)?paso:paso-scw;

                den=2.*(da1_c[i3][j3][k3+dk1]+da1_c[i3][j3][k3+dk2])-4.*da1_c[i3][j3][k3];
                paso=(den==0)?k3:k3+1.*(da1_c[i3][j3][k3+dk1]-da1_c[i3][j3][k3+dk2])/den;
                u[i][j][k][2]+=(paso<scw/2)?paso:paso-scw; */

                /* WE COMPUTE THE CORRELATION MAXIMUM WITH SUBPIXEL PRECISION USING A GAUSSIAN*/
                di1=i3>0?-1:scw-1-i3;
                di2=(i3<(scw-1))?1:-i3;
                dj1=j3>0?-1:scw-1-j3;
                dj2=(j3<(scw-1))?1:-j3;
                dk1=k3>0?-1:scw-1-k3;
                dk2=(k3<(scw-1))?1:-k3;

                ln_1=da1_c[i3+di1][j3][k3];
                ln_2=da1_c[i3][j3][k3];
                ln_3=da1_c[i3+di2][j3][k3];
                if(ln_1<=0 || ln_2<=0 || ln_3<=0) {
                    u[i][j][k][0]=i3;
                } else {
                    ln_1=log(ln_1);
                    ln_2=log(ln_2);
                    ln_3=log(ln_3);
                    den=2.*(ln_1-2.*ln_2+ln_3);
                    if(den==0) {
                        u[i][j][k][0]=i3;
                    } else {
                        paso=i3+(ln_1-ln_3)/den;
                        u[i][j][k][0]+=(paso<scw/2)?paso:paso-scw;
                    }
                }

                ln_1=da1_c[i3][j3+dj1][k3];
                ln_2=da1_c[i3][j3][k3];
                ln_3=da1_c[i3][j3+dj2][k3];
                if(ln_1<=0 || ln_2<=0 || ln_3<=0) {
                    u[i][j][k][1]=j3;
                } else {
                    ln_1=log(ln_1);
                    ln_2=log(ln_2);
                    ln_3=log(ln_3);
                    den=2.*(ln_1-2.*ln_2+ln_3);
                    if(den==0) {
                        u[i][j][k][1]=j3;
                    } else {
                        paso=j3+(ln_1-ln_3)/den;
                        u[i][j][k][1]+=(paso<scw/2)?paso:paso-scw;
                    }
                }

                ln_1=da1_c[i3][j3][k3+dk1];
                ln_2=da1_c[i3][j3][k3];
                ln_3=da1_c[i3][j3][k3+dk2];
                if(ln_1<=0 || ln_2<=0 || ln_3<=0) {
                    u[i][j][k][2]=k3;
                } else {
                    ln_1=log(ln_1);
                    ln_2=log(ln_2);
                    ln_3=log(ln_3);
                    den=2.*(ln_1-2.*ln_2+ln_3);
                    if(den==0) {
                        u[i][j][k][2]=k3;
                    } else {
                        paso=k3+(ln_1-ln_3)/den;
                        u[i][j][k][2]+=(paso<scw/2)?paso:paso-scw;
                    }
                }

            }
        }
    }
    /* WE REGULARIZE THE RESULT USING A MEDIAN FILTER */
    ami_copy_v3f(u,u_p,dim_x,dim_y,dim_z);
    for(i=(int)p_init[0];i<dim_x;i+=(int)p_disp[0]) {
        for(j=(int)p_init[1];j<dim_y;j+=(int)p_disp[1]) {
            for(k=(int)p_init[2];k<dim_z;k+=(int)p_disp[2]) {
                for(l=0;l<3;l++) {
                    Np=0;
                    x_m[Np]=u_p[i][j][k][l];
                    Np++;
                    if(i>p_init[0]) {
                        x_m[Np]=u_p[i-(int)p_disp[0]][j][k][l];
                        Np++;
                    } else {
                        x_m[Np]=u_p[i+(int)p_disp[0]][j][k][l];
                        Np++;
                    }
                    if((i+p_disp[0])<dim_x) {
                        x_m[Np]=u_p[i+(int)p_disp[0]][j][k][l];
                        Np++;
                    } else {
                        x_m[Np]=u_p[i-(int)p_disp[0]][j][k][l];
                        Np++;
                    }
                    if(j>p_init[1]) {
                        x_m[Np]=u_p[i][j-(int)p_disp[1]][k][l];
                        Np++;
                    } else {
                        x_m[Np]=u_p[i][j+(int)p_disp[1]][k][l];
                        Np++;
                    }
                    if((j+p_disp[1])<dim_y) {
                        x_m[Np]=u_p[i][j+(int)p_disp[1]][k][l];
                        Np++;
                    } else {
                        x_m[Np]=u_p[i][j-(int)p_disp[1]][k][l];
                        Np++;
                    }
                    if(k>p_init[2]) {
                        x_m[Np]=u_p[i][j][k-(int)p_disp[2]][l];
                        Np++;
                    } else {
                        x_m[Np]=u_p[i][j][k+(int)p_disp[2]][l];
                        Np++;
                    }
                    if((k+p_disp[1])<dim_z) {
                        x_m[Np]=u_p[i][j][k+(int)p_disp[2]][l];
                        Np++;
                    } else {
                        x_m[Np]=u_p[i][j][k-(int)p_disp[2]][l];
                        Np++;
                    }
                    paso=ami_mediana_float(Np/2,Np,x_m);
                    if(fabs(paso-u[i][j][k][l])>(0.5*p_disp[l]))
                        u[i][j][k][l]=paso;
                    //if(i==8 && j==8 && (k==0 || k==8)) {for(m=0;m<Np;m++) printf("%1.2f ",x_m[m]); printf("k=%d    %f\n",k,u[i][j][k][l]);}

                }
            }
        }
    }

    /* WE FREE THE MEMORY */
    ami_free3d(da1_c);
    ami_free3d(da2_c);
    free(x_m);
    ami_free3d(u_p);
}

/****************************************************************************/
/* FUNCTION TO EXTRAPOLATE THE 3D OPTIC FLOW TO POINTS WHERE IS NOT DEFINED */
void ami_optic_flow_extrapolation_v3f(
    ami_v3f ***u,/* FLOW TO EXTRAPOLATE */
    ami_v3f p_init, /* INITIAL POINT OF THE LATTICE */
    ami_v3f p_disp, /* POINT DISPLACEMENT IN THE LATTICE */
    float displacement,/* WARPING DISPLACEMENT TO CONTROL THAT CORRELATION WINDO IS NOT CENTERED IN THE POINT */
    int dim_x,int dim_y,int dim_z) /* IMAGE DIMENSIONS */
{
    int i,j,k,l,i2,j2,k2;
    float dx,dy,dz;
    for(i=0;i<dim_x;i++) {
        for(j=0;j<dim_y;j++) {
            for(k=0;k<dim_z;k++) {
				if (p_init[0]+p_disp[0]>=dim_x && p_init[1]+p_disp[1]>=dim_y && p_init[2]+p_disp[2]>=dim_z) {
					// THERE IS ONLY ONE POINT ON THE GRID (REPLICATION)
					for(l=0;l<3;l++) {						
						u[i][j][k][l] = u[(int)p_init[0]][(int)p_init[1]][(int)p_init[2]][l];
					}
				}
				else {
					if(i<p_init[0]) {
						// REPLICATION OF THE FIRST GRID POINT:
						i2=(int)p_init[0];
						dx=displacement;
					} else {
						i2=(int)(p_init[0]+((int)((i-p_init[0])/p_disp[0]))*p_disp[0]);					
						if( (i2+p_disp[0])>=dim_x ) {
							// REPLICATION OF THE LAST GRID POINT
							i2-=(int)p_disp[0], dx=p_disp[0];
						} else {
							dx=i-i2+displacement;
						}
					}
					
					if(j<p_init[1]) {
						// REPLICATION OF THE FIRST GRID POINT:
						j2=(int)p_init[1];
						dy=displacement;
					} else {
						j2=(int)(p_init[1]+((int)((j-p_init[1])/p_disp[1]))*p_disp[1]);					
						if( (j2+p_disp[1])>=dim_y ) {
							// REPLICATION OF THE LAST GRID POINT
							j2-=(int)p_disp[1], dy=p_disp[1];
						} else {
							dy=j-j2+displacement;
						}
					}
					
					if(k<p_init[2]) {
						// REPLICATION OF THE FIRST GRID POINT:
						k2=(int)p_init[2];
						dz=displacement;
					} else {
						k2=(int)(p_init[2]+((int)((k-p_init[2])/p_disp[2]))*p_disp[2]);					
						if( (k2+p_disp[2])>=dim_z ) {
							// REPLICATION OF THE LAST GRID POINT
							k2-=(int)p_disp[2], dz=(int)p_disp[2];
						} else {
							dz=k-k2+displacement;
						}
					}
					
					for(l=0;l<3;l++) {
						u[i][j][k][l]=(p_disp[0]-dx)*(p_disp[1]-dy)*(p_disp[2]-dz)*u[i2][j2][k2][l]+
									(dx)*(p_disp[1]-dy)*(p_disp[2]-dz)*u[i2+(int)p_disp[0]][j2][k2][l]+
									(dx)*(dy)*(p_disp[2]-dz)*u[i2+(int)p_disp[0]][j2+(int)p_disp[1]][k2][l]+
									(dx)*(dy)*(dz)*u[i2+(int)p_disp[0]][j2+(int)p_disp[1]][k2+(int)p_disp[2]][l]+
									(dx)*(p_disp[1]-dy)*(dz)*u[i2+(int)p_disp[0]][j2][k2+(int)p_disp[2]][l]+
									(p_disp[0]-dx)*(dy)*(p_disp[2]-dz)*u[i2][j2+(int)p_disp[1]][k2][l]+
									(p_disp[0]-dx)*(dy)*(dz)*u[i2][j2+(int)p_disp[1]][k2+(int)p_disp[2]][l]+
									(p_disp[0]-dx)*(p_disp[1]-dy)*(dz)*u[i2][j2][k2+(int)p_disp[2]][l];
						u[i][j][k][l]/=(p_disp[0]*p_disp[1]*p_disp[2]);
                	}
				}
            }
        }
    }
}



