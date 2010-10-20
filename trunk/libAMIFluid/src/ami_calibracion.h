#ifndef AMI_CALIBRACION_H
#define AMI_CALIBRACION_H

#include "ami_types.h"
#include "ami_utilities.h"

/*******************************************/
/* DECLARACION DE TIPOS PARA LAS FUNCIONES */
/*******************************************/
int ami_gauss(double **A,double *b,int N);
   /* SOLUCION DE UN SISTEMA POR EL METODO DE GAUSS */
int ami_gauss3x3(double A[3][3],double b[3]); 
   /* METODO DE GAUSS PARA MATRICES 3x3 */
double *ami_MxV(double **a,double *x, double *v,int dim);
    /* MULTIPLICACION MATRIZ VECTOR */
double ami_VxV(double *x,double *v,int dim);  
     /* MULTIPLICACION ESCALAR VECTOR VECTOR */
double **ami_MxM(double **a,double **as,int dimf,int dimc); 
    /* MULTIPLICACION MATRIZ POR SU TRASPUESTA */
double *ami_proyeccion(double *x,double *d);    
    /* FUNCION QUE PROYECTA UNA DIRECCION EN UN PLANO ORTOGONAL*/
int ami_inversa(double **A,double **A_1,int N);  
    /* CALCULO MATRIZ INVERSA */
int ami_inversa3x3_c(double A[3][3],double A_1[3][3]);
	/* CALCULO MATRIZ INVERSA MATRICES 3x3 */
int ami_autovector_1(double A[3][3],double V[3]); 
    /* CALCULO DEL AUTOVECTOR 1 DE UNA MATRIZ DE ROTACION */
double *ami_rotacion_to_cuaternion(double r[3][3],double *x);  
    /* CALCULO VECTOR (s,l,m,n) A PARTIR DE UNA MATRIZ DE ROTAC. */
int ami_cuaternion_to_rotacion(double *x,double rfinal[3][3]); 
    /* CALCULO DE MATRIZ DE ROTACION A PARTIR DE (S,l,m,n) */
void ami_Tx(double T[3],double Q[3][3]); 
    /* CALCULO DE MATRIZ ASOCIADA A UN PRODUCTO VECTORIAL */
int ami_p1_p2_to_mf(double P1[3][4],double P2[3][4],double F[3][3]); 
    /* CALCULO MATRIZ FUNDAMENTAL A PARTIR DE P1 y P2 */
int ami_punto_interseccion_rectas3d(double **Focos,double **Vdir,double x[3],int N); 
    /* CALCULO PUNTO EQUIDISTANTE A UN CONJUNTO DE RECTAS */
int ami_reconstruccion_punto3D(double ***P,double **m,int N,double x[3]); 
    /*CALCULO PUNTO 3D A PARTIR DE P y CORRESPONDENCIAS */
void ami_intrinsecos_extrinsecos_to_p(double u0,double v0,double au,double av,double t[3],double R[3][3],double P[3][4]); 
    /*CALCULO DE P A PARTIR DE PARAMETROS INTRINSECOS Y EXTR. */
void ami_p_to_intrinsecos_extrinsecos(double *u0,double *v0,double *au,double *av,double t[3],double R[3][3],double P[3][4],int epsilon,int epsilonu,int epsilonv); 
    /* CALCULO DE PARAMETROS INTR. Y EXT. A PARTIR DE P. */
int ami_error_proyeccion_camaras(camara *CAMARA,puntocalibracion *PUNTO,int NPUNTOS,int N,double *error);  
    /* ERROR ASOCIADO A UN SISTEMA DE M CAMARAS Y UN SIST. DE PUNTOS*/
int ami_reconstruccion_punto3d_reproyeccion(camara *CAMARA,puntocalibracion *PUNTO,int N,int ic,int ip,double *px,double *py); 
    /* RECONSTRUCCION DE UN PUNTO 3D Y REPROYECCION */
int ami_autovalor_minimo(double **B,double *v,double *l,int N);  
    /* CALCULA AUTOVECTOR Y AUTOVALOR MINIMO */
int ami_calculo_rotacion(double **p1,double **p2,int N,double R[3][3]); 
    /* CALCULA LA MEJOR ROTACION ENTRE DOS CONJ. DE PUNTOS */
int ami_calculo_rotaciones_traslaciones(double **B,double R[4][3][3],double t[4][3]); 
    /* CALCULA 4 POSIBLES ROTACIONES y TRASL. */
int ami_calculo_rotacion_traslacion_optima(double ***m,double R[3][3],double t[3],int N); 
    /*CALCULA ROTACION Y TRASLACION A PARTIR DE CORRESPONDENCIAS */
void ami_leer_matriz_p(char name[100],double P[3][4]); 
    /* FUNCION PARA LEER UNA MATRIZ DE PROYECCION P DE DISCO */
void ami_escribir_matriz_p(char name[100],double P[3][4]); 
    /* FUNCION PARA ESCRIBIR UNA MATRIZ DE PROYECCION P DE DISCO */
int ami_calibracion_fuerte(double **Puntos,int Npuntos,double P[3][4]); 
    /* CALCULA P A PARTIR DE CORRESPONDENCIAS 3D-2D */
int ami_resolver(double B[12][12],double sol[12]); 
    /* FUNCION AUXILIAR DE CalibracionFuerte */
void ami_construirB_Olivier(double **Puntos,int Npuntos,double B[12][12]); 
    /* FUNCION AUXILIAR DE CalibracionFuerte */
int ami_p_to_foco(double P[3][4],double F[3]);  
    /* CALCULA LAS COORDENADAS DEL FOCO A PARTIR DE UNA MATRIZ P */
int ami_calculo_recta2d(double recta[3],double **Puntos2D,int N); 
    /* CALCULA LA RECTA QUE MEJOR APROXIMA UN CONJUNTO DE PUNTOS 2D */
int ami_punto_interseccion_2_rectas(double recta1[3],double recta2[3],double *x,double *y); 
    /* CALCULA LA INTERSECCION DE DOS RECTAS 2D  */
int ami_MejoraPuntosCalibracionZhang(char *inputname,char *outputname); 
    /* MEJORA LOS PUNTOS PARA LA CALIBRACION DE ZHANG */
int ami_bordes_to_esquina(int *bordes,int width,int height,double *x,double *y,float umbral1,float umbral2); 
    /* CALCULA UNA ESQUINA A PARTIR DE UN MAPA DE BORDES */
int ami_RectaRecursiva(int *bordes,int width,int height,float umbral,int *f,int i0,int j0,double r[3]); 
    /* FUNCION AUXILIAR DE ami_bordes_to_esquina() */
void ami_operador_diferencial_direccional(float *cp,float *dp,int nx,int ny); 
    /* CALCULA u_xx*u_y+u_yy*u_x-2u_xy*u_x*u_y */
int ami_esquina_afin(float *rim,int width,int height,double *x,double *y,float step,int nitermin,float finalscale,float SubScaleSize,float umbral);  
    /* CALCULA LA ESQUINA MAS CONTRASTADA POR EL METODO ALVAREZ MORALEZ */
double ami_F(double x,double y,double c[9]); 
    /* FUNCION AUXILIAR METODO DE NEWTON PARA BUSQUEDA DE MAXIMOS */
void ami_CalculoCoeficientes(double Co[9],double c[9]); 
    /* FUNCION AUXILIAR METODO DE NEWTON PARA BUSQUEDA DE MAXIMOS */
void ami_HF(double x,double y,double c[9],double H[2][2]);  
    /* FUNCION AUXILIAR METODO DE NEWTON PARA BUSQUEDA DE MAXIMOS */
int ami_ResolverSistema(double H[2][2],double b[2],double sol[2]); 
    /* FUNCION AUXILIAR METODO DE NEWTON PARA BUSQUEDA DE MAXIMOS */
void ami_Grad(double x,double y,double c[9],double G[2]); 
    /* FUNCION AUXILIAR METODO DE NEWTON PARA BUSQUEDA DE MAXIMOS */
int ami_Newton(double Co[9],double sol[2],double sol0[2],double *C); 
    /* FUNCION METODO DE NEWTON PARA BUSQUEDA DE MAXIMOS */
float ami_G(float x,float y);  
    /* FUNCION AUXILIAR METODO DE NEWTON PARA BUSQUEDA DE MAXIMOS */
double *ami_producto_vectorial_double(double *u,double *v,double *z); 
    /* CALCULA EL PRODUCTO VECTORIAL DE 2 VECTORES */
int ami_calculo_esquina_afin_img(unsigned char *imgdata,int width,int height,int radio,int coord_x,int coord_y,double *px,double *py); 
    /* FUNCION MEJORAR POSICION ESQUINAS IMG   */
int ami_maximo_3x3(float *c,long m,int width,int *i0,int *j0); 
    /* CALCULO MAXIMO EN UN ENTORNO DE 3x3 DEL VALOR ABSOLUTO*/
void ami_proyeccion_punto_recta2d(double r[3],double x0,double y0,double *x,double *y); 
    /* CALCULA PROYECCION DE UN PUNTO A UNA RECTA NORMALIZADA */
int ami_calculo_recta2d_robusto(double recta[3],double **Puntos2D,int N,float dmax); 
    /* CALCULA RECTA DE FORMA ROBUSTA */ 
void ami_AFIN_CURVATURA(float *rim,float *c,int width,int height,float step);
    /* FUNCION AUXILIAR DE ami_esquina_afin_multiples(); */
int ami_MEJORA_ESQUINA(float *c,int ix,int iy,double *x,double *y,int width,double *Cu);
    /* FUNCION AUXILIAR DE ami_esquina_afin_multiples(); */
int ami_esquina_afin_multiples(float *rim,int width,int height,double **x,double **y,double **le,double **pe,double **curv,float step,float UmbralCurvatura,float UmbralRecta,float initialscale,float finalscale,float SubScaleSize);
    /* FUNCION QUE CALCULA MULTIPLES ESQUINAS SIGUIENDO EL MORPHOLOGICAL CORNER DETECTOR */
int ami_bordes_subpixel_to_esquina(int *bordes,int width,int height,double r1[3],double r2[3],double *x,double *y,float umbral1,float umbral2,double *cx,double *cy);
    /* FUNCION QUE CALCULA LAS ESQUINAS A PARTIR DE UN MAPA DE BORDES. LOS BORDES ESTAN */
    /* CON PRECISION SUBPIXEL */  
int ami_morphological_corner_detector(float *image,int width,int height,float thresholdMalanobis,int radius,char filename[100]);
    /* MORPHOLOGICAL CORNER DETECTOR WITH MAHALANOBIS DISTANCE */
int ami_eje_angulo_to_rotacion(double eje[3],double angulo,double R[3][3]);
    /* CALCULA LA MATRIZ DE ROTACION A PARTIR DE UN EJE Y UN ANGULO DE ROTACION */
int ami_rotacion_vector_to_vector(double v1[3], double v2[3],double R[3][3]);
    /* CALCULA LA ROTACION R[3][3] QUE LLEVA LA DIRECCION DEL VECTOR v1 EN LA DIRECCION DE v2 */
int ami_matrices_rectificacion(double F[3][3], double H1[3][3],double H2[3][3]);
    /* CALCULA LAS HOMOGRAFIAS H1 Y H2 PARA RECTIFICAR LA MATRIZ FUNDAMENTAL F   */
int ami_p1_p2_rectificacion(double P1[3][4], double P2[3][4], double H1[3][3],double H2[3][3]);
    /* CALCULA LAS HOMOGRAFIAS H1 Y H2 PARA RECTIFICAR LAS IMAGENES A PARTIR DE LAS MATRICES DE PROYECCION   */
int ami_calculo_homografia(double *x,double *y,double *xn,double *yn,double H[3][3],int N);
    /* CALCULA UNA HOMOGRAFIA A PARTIR DE UN CONJUNTO DE CORRESPONDENCIAS DE PUNTOS */
double *ami_reprojeccion_calibracion_fuerte(double *x,int Nx,double **Puntos,int Np);
    /* CALCULA LA REPROJECCION DE UN CONJUNTO DE PUNTOS 3D A PARTIR DE UNA MATRIZ P */
int ami_levenberg_marquardt_calibracion_fuerte(double *x,int Nx,double **Puntos,int Np,double umbral);
    /* MEJORA LA MATRIZ DE PROJECCION P UTILIZANDO LEVENBERG MARQUARDT */
double ami_energia_reprojeccion_p(double *p2d,double **Puntos,int Np);
    /* CALCULA LA ENERGIA QUE SE DEBE MINIMIZAR PARA CALCULAR LA MATRIZ DE PROJECCION  */
int ami_calibracion_fuerte_nolineal(double **Puntos,int Npuntos,double P[3][4]); 
    /* CALIBRACION FUERTE CON EL ALGORITMO DE LEVENBERG MARQUARDT */ 
int ami_corregir_rotacion(double R[3][3]);
    /* FUNCION QUE CONVIERTE EN ROTACION EXACTA UNA ROTACION APROXIMADA */
int ami_harris_corner_detector(float *image,int width,int height,float threshold,float sigma,char filename[100],int radius);
    /* FUNCION QUE CALCULA LAS ESQUINAS POR EL METODO DE HARRIS */
void ami_gauss_conv(float sigma,long nx,long ny,float hx,float hy,float precision,long bc,float **f);
    /* FUNCION QUE CALCULA LA CONVOLUCION CON UNA GAUSSIANA DIRECTAMENTE */
void ami_grad(float *image,int width,int height,float *image_x,float *image_y);
     /* FUNCION QUE CALCULA EL GRADIENTE DE UNA IMAGEN */
void ami_autovectores2x2_simetrica(double M[2][2],double A[2][2],double *autovalorminimo,double *autovalormaximo);
     /* FUNCION QUE CALCULA LOS AUTOVALORES Y AUTOVECTORES DE UNA MATRIZ 2X2 SIMETRICA */
int ami_aplicacion_homografia(double H[3][3],float *image_input,float *image_output,int width,int height);
  /* APLICACION DE UNA HOMOGRAFIA SOBRE UNA IMAGEN (IMAGEN RESULTADO MANTIENE EL TAMANO)*/
int ami_aplicacion_homografia_adaptativa(double H[3][3],float *image_input,float **image_output,int width_input,int height_input,int *width_output,int *height_output);
  /* APLICACION DE UNA HOMOGRAFIA SOBRE UNA IMAGEN ADAPTANDO EL TAMA� DE LA NUEVA IMAGEN*/
int ami_jacobi_autovalores(double **A,int N,double );
  /* METODO DE JACOBI PARA CALCULAR AUTOVALORES DE UNA MATRIZ SIMETRICA.
     LOS AUTOVALORES QUEDAN EN LA DIAGONAL DE LA MATRIZ */
int ami_calculo_afinidad(double *x,double *y,double *xn,double *yn,double H[3][3],int N);
  /* CALCULA UNA AFININIDAD A PARTIR DE CORRESPONDENCIAS DE 3 PUNTOS */
int ami_interior_triangulo(double *x,double *y,double cx,double cy);
  /* TEST PARA COMPROBAR SI UN PUNTO ES INTERIOR A UN TRIANGULO */
int ami_correlacion(float *I1,float *I2,float *C,float *X,float *Y,int radio_w,
                    int radio_w_b,int width,int height,float umbral_correlacion);
  /* FUNCION QUE CALCULA LA CORRELACION A VENTANAS */

#endif

