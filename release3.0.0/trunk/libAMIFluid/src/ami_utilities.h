#ifndef AMI_UTILITIES_H
#define AMI_UTILITIES_H

#include "ami_prototypes.h"

/**
 * FUNCION QUE DIBUJA UN SEGMENTO 
 *
 * \param data  IMAGEN DONDE SE VA A DIBUJAR EL SEGMENTO
 * \param width,height  DIMENSIONES DE LA IMAGEN
 * \param x0,y0  COORDENADAS 1 PUNTO DEL SEGMENTO 
 * \param x1,y1  COORDENADAS 2 PUNTO DEL SEGMENTO 
 * \param color  COLOR CON EL QUE SE RELLENA EL SEGMENTO 
 */
void ami_dibujar_segmento(
   float *data, /* IMAGEN DONDE SE VA A DIBUJAR EL SEGMENTO */
   int width, int height, /* DIMENSIONES DE LA IMAGEN */
   int x0, int y0, /* COORDENADAS 1 PUNTO DEL SEGMENTO */
   int x1, int y1,  /* COORDENADAS 2 PUNTO DEL SEGMENTO */
   float color);     /* COLOR CON EL QUE SE RELLENA EL SEGMENTO */


/**
 * ALGORITMO DE SEMILLA PARA RELLENAR LA IMAGEN A PARTIR DE UN NIVEL CON OTRO NIVEL
 *
 * \param m  POSICION DEL PUNTO ACTUAL 
 * \param imagen  IMAGEN DE ENTRADA 
 * \param width  ANCHO DE LA IMAGEN
 * \param size  TAMANO DE LA IMAGEN 
 * \param nivel1  NIVEL QUE SE VA MODIFICAR
 * \param nivel2  NIVEL CON EL QUE SE RELLENA
 */
void ami_semilla(
   long m /* POSICION DEL PUNTO ACTUAL */,
   float *imagen /* IMAGEN DE ENTRADA */ ,
   unsigned short width /* ANCHO DE LA IMAGEN*/ ,
   long size/* TAMANO DE LA IMAGEN */ ,
   float nivel1 /* NIVEL QUE SE VA MODIFICAR */,
   float nivel2 /* NIVEL CON EL QUE SE RELLENA*/);


/**
 * Convol:								
 * It returns the result in the same image.		
 */
void Convol(float **image, int nx, int ny, float **mask, int mx, int my);


/**
 * EZoom:								    
 * This function makes a zoom by reducing the size of the "input" 	    
 * image in a "scale" factor.
 * We create a new image ("output") and modify the initial dimensions.
 */
float **EZoom(float **input, long *nx, long *ny, long scale);

/**
 * DZoom:								    
 * This function realizes the opposite to the previous one	and 	    
 * multiply the input by scale to keep the correspondence.	    
 */
float **DZoom(float **input, long maxx, long maxy, long nx, long ny, long scale);


/**
 *	ZoomSerie:							     
 *	This procedure computes several zooms for a given image.	    
 *	It applies a
 */
long ZoomSerie(float **f, float ****fout, long nx, long ny, long Nitera);

/**
 * FUNCTION TO CREATE A 1024 X 1024 HISTOGRAM OF AN IMAGE AND TO SAVE IT AS A BMP FILE 
 */
int ami_histogram_1024_1024_16b_unsigned_short(char name[200],unsigned short *image,float **histograme);


/**
 * FUNCTION TO NORMALIZE THE HISTOGRAM OF image_2 TO FIT THE HISTOGRAM OF image_1 
 * WE IMPOSE THAT SUM_{k=0,..i}h_1[k] + uniform_distribution_weight * SUM_{k=0,..i}u_1[k] =
 * SUM_{k=0,..j}h_2[k] + uniform_distribution_weight * SUM_{k=0,..j}u_2[k], where u_1[] and
 * u_2[] are uniform distribution with the same mean and standard deviation than h_1 and h_2 
 */
void ami_histogram_normalization(float *image_1,float *image_2,long size_1,long size_2,float uniform_distribution_weight);


/**
 * WINDOW MEDIAN FILTER                                                                       
 */
void ami_window_median_filter(float *image,int width,int height,int window_radius);

/**
 * CALCULA UNA AFININIDAD A PARTIR DE UN CONJUNTO DE CORRESPONDENCIAS DE 3 PUNTOS
 *
 * \param x,y  COORDINATES IN THE FIRST IMAGE 
 * \param xn,yn  COORDINATES IN THE SECOND IMAGE
 * \param H  OUTPUT AFFINITY
 * \param N  NUMBER OF CORRESPONDING POINTS (N=3)
 */
int ami_calculo_afinidad_3p(double *x,double *y /* COORDINATES IN THE FIRST IMAGE */,
                           double *xn,double *yn /* COORDINATES IN THE SECOND IMAGE */ ,
			   double H[3][3] /* OUTPUT AFFINITY*/,
			   int N /* NUMBER OF CORRESPONDING POINTS (N=3)*/);


/**
 * FUNCION QUE CALCULA LA DISTANCIA DE UN PUNTO A UN SEGMENTO 
 *
 * \param x0,y0,x1,y1  COORDENADAS DEL SEGMENTO
 * \param x,y  COORDENADAS DEL PUNTO 
 *
 * \return DEVOLVEMOS EL MAXIMO ENTRE LA DISTANCIA A LA RECTA Y LA DISTANCIA DE LA PROYECCION AL SEGMENTO
 */
float ami_distancia_punto_segmento(
        int x0,int y0,int x1,int y1, /* COORDENADAS DEL SEGMENTO */
		int x,int y);  /* COORDENADAS DEL PUNTO */

/**
 * FUNCION QUE DETERMINA SI UN PUNTO CAE DENTRO DE UN RECTANGULO DEFORMADO. 
 *
 * \param x0,y0,x1,y1,x2,y2,x3,y3  COORDENADAS PUNTOS TETRAEDRO 
 * \param x,y  COORDENADAS PUNTO 
 *
 * \return DEVUELVE 0 SI EL PUNTO ESTA DENTRO Y -1 EN CASO CONTRARIO.
 */
int ami_test_interior_rectangulo(
   int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3, /* COORDENADAS PUNTOS TETRAEDRO */
   int x,int y); /* COORDENADAS PUNTO */

/**
 * FUNCION QUE EVALUA LOS SPLINES EN UN PUNTO.
 *  
 * \param x  COORDENADAS PUNTOS INTERPOLANTES 
 * \param N  NUMERO DE PUNTOS INTERPOLANTES 
 * \param s  COEFICIENTES DE LOS POLINOMIOS SPLINES 
 * \param z  COORDENADA DEL PUNTO DONDE SE VA A INTERPOLAR 
 *
 * \return RETORNA EL VALOR INTERPOLADO
 */
float ami_evaluar_splines(
float *x, /* COORDENADAS PUNTOS INTERPOLANTES */
int N, /* NUMERO DE PUNTOS INTERPOLANTES */
float **s, /* COEFICIENTES DE LOS POLINOMIOS SPLINES */
float z); /* COORDENADA DEL PUNTO DONDE SE VA A INTERPOLAR */

/**
 * FUNCION QUE CREA LOS SPLINES CUBICOS. 
 *
 * \param x  COORDENADAS PUNTOS INTERPOLANTES 
 * \param y  VALORES INTERPOLACION 
 * \param N  NUMERO DE PUNTOS A INTERPOLAR 
 * \param s  MATRIZ DONDE SE GUARDAN LOS POLINOMIOS SPLINES DE GRADO 3.
 *           ESTA MATRIZ TIENE DIMENSION Nx4 (AUNQUE LOS POLINOMIOS DE
 *			 INTERES SON N-1).
 *
 * \return RETORNA 0 SI TERMINA BIEN
 ********************************************************/
int ami_crear_splines(
float *x, /* COORDENADAS PUNTOS INTERPOLANTES */
float *y, /* VALORES INTERPOLACION */
int N,    /* NUMERO DE PUNTOS A INTERPOLAR */
float **s); /* MATRIZ DONDE SE GUARDAN LOS POLINOMIOS SPLINES DE GRADO 3.
              ESTA MATRIZ TIENE DIMENSION Nx4 (AUNQUE LOS POLINOMIOS DE
			  INTERES SON N-1 */


/**
 * FUNCION QUE CALCULA EL VALOR DE UN VECTOR QUE DEJA k ELEMENTOS A LA IZQUIERDA EN PRECISION UNSIGNED CHAR
 */
unsigned char ami_mediana_unsigned_char(int k, int n, unsigned char *x);

/**
 * FUNCION QUE CALCULA EL VALOR DE UN VECTOR QUE DEJA k ELEMENTOS A LA IZQUIERDA EN PRECISION INT 
 */
int ami_mediana_int(int k, int n, int *x);

/**
 * FUNCION QUE CALCULA EL VALOR DE UN VECTOR QUE DEJA k ELEMENTOS A LA IZQUIERDA EN PRECISION FLOAT 
 * SI n IMPAR LA MEDIANA CORRESPONDE A k= (TRUNCACION) n/2                                          
 */
float ami_mediana_float(int k, int n, float *x);

/**
 * APPROXIMATION TO GAUSSIAN FILTER USING ALVAREZ-MAZORRA ALGORITHM
 *
 * \param rim  Original picture and output picture
 * \param sigma_x  Standard deviation of the gaussian in the horizontal axis direction
 * \param sigma_y  Standard deviation of the gaussian in the vertical axis direction 
 * \param precision  Non-negative number to indicate the precisin of the convolution 
 * \param width,height  Image dimensions 
 */
void ami_gauss_conv_alma(
float *rim,  /* Original picture and output picture*/
float sigma_x,    /* standard deviation of the gaussian in the horizontal axis direction*/
float sigma_y,    /* standard deviation of the gaussian in the vertical axis direction */
float precision,  /* non-negative number to indicate the precisin of the convolution */
int width,int height); /* image dimensions */

/**
 * FUNCION QUE CALCULA LAS ORIENTACIONES Y LA NORMA CUADRADO DEL GRADIENTE DE CADA PIXEL
 *
 * \param image  INPUT IMAGE  
 * \param width  IMAGE WIDTH 
 * \param height  IMAGE HEIGHT 
 * \param sigma  STANDARD DEVIATION OF THE GAUSSIAN 
 * \param alpha  ORIENTATION OUTPUT 
 * \param norma_gradiente  GRADIENT NORM OUTPUT 
 */
int ami_orientation_estimation(float *image, /* INPUT IMAGE  */
                               int width, /* IMAGE WIDTH */
                               int height, /* IMAGE HEIGHT */
			       float sigma, /* STANDARD DEVIATION OF THE GAUSSIAN */
			       float *alpha, /* ORIENTATION OUTPUT */
			       float *norma_gradiente); /* GRADIENT NORM OUTPUT */


/**
 * ECUACION DE LA RECTA QUE PASA POR LOS PUNTOS v0 v1 EVALUADA EN EL PUNTO v            
 */
float ami_recta2d(ami_punto2d v0,ami_punto2d v1,ami_punto2d v);

/**
 * FUNCION RECURSIVA PARA IR CALCULANDO LOS PUNTOS INTERIORES DE UN TRIANGULO POR
 * ALGORITMO DE SEMILLA.                                                                
 */
void ami_introducir_punto2d_triangulo(int i,int j,ami_punto2d v0,ami_punto2d v1,ami_punto2d v2,
     int **A,int xmin,int ymin,int xmax,int ymax,int **mx,int **my,int *Np);

/**
 * FUNCION QUE CALCULA LOS PUNTOS INTERIORES DE UN TRIANGULO EN 2D EN COORDENADAS
 * FLOTANTES. LOS PUNTOS INTERIORES SE DEVUELVEN EN COORDENADAS ENTERAS EN LOS PUNTEROS
 * mx Y my. EL NUMERO DE PUNTOS INTERIORES SE DEVUELVE EN EL PUNTERO Np                  
 */
void ami_rellenar_triangulo2d(double x0,double y0,double x1,double y1,double x2,
                     double y2, int **mx,int **my,int *Np);

/**
 * METODO DE JACOBI PARA CALCULAR AUTOVALORES Y AUTOVECTORES DE UNA MATRIZ SIMETRICA.
 * LA MATRIZ A Y B PUEDEN SER LA MISMA 
 *
 * \param A  MATRIZ SIMETRICA 
 * \param x  VECTOR DE AUTOVALORES 
 * \param B  MATRIZ DE AUTOVECTORES 
 * \param N  DIMENSION MATRIZ 
 * \param _TOL  TOLERANCIA PARA LA CONVERGENCIA 
 */
int ami_jacobi_autovalores_autovectores(double **A /* MATRIZ SIMETRICA */
                           ,double *x  /* VECTOR DE AUTOVALORES */
                           ,double **B /* MATRIZ DE AUTOVECTORES */
                           ,int N /* DIMENSION MATRIZ */
                           ,double _TOL /* TOLERANCIA PARA LA CONVERGENCIA */);

/**
   FUNCION QUE CALCULA LA INTERSECCION DE UNA RECTA Y UN TRIANGULO. X0,X1,X2 REPRESENTAN LOS
   VERTICES DEL TRIANGULO 3D. F EL FOCO (PUNTO POR DONDE PASA EL VECTOR DIRECTOR DE LA RECTA)
   Y D EL VECTOR DIRECTOR DE LA RECTA.
   LA FUNCION DEVUELVE 3 VALORES EN X. SI EL VECTOR DIRECTOR D ESTA NORMALIZADO,
   EL PRIMER VALOR X[0] REPRESENTA LA DISTANCIA DEL PUNTO DE INTERSECCION CON EL FOCO F. LOS OTROS
   DOS VALORES X[1],X[2]. INDICAN QUE EL PUNTO DE INTERSECCION X SE EXPRESA COMO
   X=(1-X[1]-X[2])*X0+X[1]*X1+X[2]*X2. EL PUNTO INTERSECCION CAE DENTRO DEL TRIANGULO SI
   SE CUMPLE QUE (1-X[1]-X[2]),X[1],X[2] son todos positivos. 
 */
int ami_recta_triangulo(p3D X0,p3D X1,p3D X2,p3D F,p3D D,p3D X);

/**
 * FUNCION QUE CALCULA LA CORRELACION A VENTANAS 
 * OJO ESTA FUNCION NO FUNCIONA HAY QUE CAMBIAR EL XMW_average 
 *
 * \param I1,I2  IMAGENES DE ENTRADA 
 * \param C  CORRELACION MAXIMA 
 * \param X,Y  DESPLAZAMIENTOS EN X E Y 
 * \param radio_w  RADIO DE LA VENTANA DE COMPARACION 
 * \param radio_w_b  RADIO VENTANA BUSQUEDA EN LA SEGUNAD IMAGEN 
 * \param width,height  TAMAÑO DE LA IMAGEN
 * \param umbral_correlacion  VALOR MINIMO CORRELACION PARA MOVER EL PUNTO
 */
int ami_correlacion(float *I1,float *I2,/* IMAGENES DE ENTRADA */
                    float *C, /* CORRELACION MAXIMA */
                    float *X,
                    float *Y, /*  DESPLAZAMIENTOS EN X E Y */
                    int radio_w, /* RADIO DE LA VENTANA DE COMPARACION */
                    int radio_w_b, /* RADIO VENTANA BUSQUEDA EN LA SEGUNAD IMAGEN */
                    int width,
                    int height, /* TAMA� DE LA IMAGEN */
                    float umbral_correlacion); /* VALOR MINIMO CORRELACION PARA MOVER EL
                                                 PUNTO */

/**
 * TEST PARA COMPROBAR SI UN PUNTO ES INTERIOR A UN TRIANGULO.
 *
 * \param x,y  COORDENADAS TRIANGULO 
 * \param cx,cy  COORDENADAS PUNTO
 *
 * \return DEVUELVE 0 SI EL PUNTO ES INTERIOR Y -1 SI EL PUNTO ES EXTERIOR.
 */
int ami_interior_triangulo(double *x,double *y,/* COORDENADAS TRIANGULO */
                           double cx,double cy); /* COORDENADAS PUNTO)  */


/**
 * CALCULA UNA AFININIDAD A PARTIR DE UN CONJUNTO DE CORRESPONDENCIAS DE 3 PUNTOS 
 *
 * \param x,y  COORDINATES IN THE FIRST IMAGE 
 * \param xn,yn  COORDINATES IN THE SECOND IMAGE 
 * \param H  OUTPUT AFFINITY
 * \param N  NUMBER OF CORRESPONDING POINTS (N=3)
*********************************************************************************/
int ami_calculo_afinidad(double *x,double *y /* COORDINATES IN THE FIRST IMAGE */,
                           double *xn,double *yn /* COORDINATES IN THE SECOND IMAGE */ ,
			   double H[3][3] /* OUTPUT AFFINITY*/,
			   int N /* NUMBER OF CORRESPONDING POINTS (N=3)*/);


/**
 * METODO DE JACOBI PARA CALCULAR AUTOVALORES DE UNA MATRIZ SIMETRICA.
 * LOS AUTOVALORES QUEDAN EN LA DIAGONAL DE LA MATRIZ.
 *
 * \param A  MATRIZ SIMETRICA 
 * \param N  DIMENSION MATRIZ 
 * \param _TOL  TOLERANCIA PARA LA CONVERGENCIA 
 */
int ami_jacobi_autovalores(double **A /* MATRIZ SIMETRICA */
                           ,int N /* DIMENSION MATRIZ */
                           ,double _TOL /* TOLERANCIA PARA LA CONVERGENCIA */);

/**
 * APLICACION DE UNA HOMOGRAFIA SOBRE UNA IMAGEN ADAPTANDO EL TAMA� DE LA NUEVA IMAGEN
 *
 * \param H  Matriz de homografia
 * \param image_input  Imagen de entrada 
 * \param image_output  Puntero imagen de salida 
 * \param width_input,height_input  Dimensiones imagen original 
 * \param width_output,height_output  PUNTEROS TAMANO NUEVA IMAGEN
 */
int ami_aplicacion_homografia_adaptativa(
			  double H[3][3], /* Matriz de homografia */
			  float *image_input, /* imagen de entrada */
			  float **image_output, /* puntero imagen de salida */
			  int width_input,      /* Dimensiones imagen original */
			  int height_input,
			  int *width_output,   /* PUNTEROS TAMANO NUEVA IMAGEN */
			  int *height_output
			  );

/**
 * APLICACION DE UNA HOMOGRAFIA SOBRE UNA IMAGEN (IMAGEN RESULTADO MANTIENE EL TAMANO)
 *
 * \param H  Matriz de homografia
 * \param image_input  Imagen de entrada 
 * \param image_output  Imagen de salida 
 * \param width,height 
 */
int ami_aplicacion_homografia(
			  double H[3][3], /* Matriz de homografia */
			  float *image_input, /* imagen de entrada */
			  float *image_output, /* imagen de salida */
			  int width,
			  int height
			  );


/**
 * FUNCION QUE CALCULA LOS AUTOVALORES Y AUTOVECTORES DE UNA MATRIZ 2X2 SIMETRICA 
 *
 * \param M  MATRIZ DE ENTRADA 
 * \param A  MATRIZ DE AUTOVECTORES POR FILAS ORDENADOS DE MENOR A MAYOR 
 * \param autovalorminimo  AUTOVALOR MINIMO 
 * \param autovalormaximo  AUTOVALOR MAXIMO 
 */
void ami_autovectores2x2_simetrica(double M[2][2] /* MATRIZ DE ENTRADA */,
				   double A[2][2] /* MATRIZ DE AUTOVECTORES POR FILAS ORDENADOS
						     DE MENOR A MAYOR */,
				   double *autovalorminimo /* AUTOVALOR MINIMO */,
				   double *autovalormaximo /* AUTOVALOR MAXIMO */);

/**
 * FUNCION QUE CALCULA EL GRADIENTE DE UNA IMAGEN 
 *
 * \param image  ORIGINAL IMAGE 
 * \param width,height  IMAGE SIZE 
 * \param image_x,image_y  OUTPUT GRADIENT
 */
void ami_grad(float *image,/* ORIGINAL IMAGE */
	      int width,int height,/* IMAGE SIZE */
	      float *image_x,float *image_y /* OUTPUT GRADIENT */);


/**
 * FUNCION QUE CALCULA LA CONVOLUCION CON UNA GAUSSIANA             
 *
 * \param sigma  Standard deviation of Gaussian 
 * \param nx  Image dimension in x direction
 * \param ny  Image dimension in y direction 
 * \param hx  Pixel size in x direction 
 * \param hy  Pixel size in y direction 
 * \param precision  Cutoff at precision * sigma 
 * \param bc  Type of boundary condition (0=Dirichlet, 1=reflecing, 2=periodic)
 * \param f  Input: original image ;  output: smoothed 
 */
void ami_gauss_conv
     (float    sigma,     /* standard deviation of Gaussian */
      long     nx,        /* image dimension in x direction */
      long     ny,        /* image dimension in y direction */
      float    hx,        /* pixel size in x direction */
      float    hy,        /* pixel size in y direction */
      float    precision, /* cutoff at precision * sigma */
      long     bc,        /* type of boundary condition */
                          /* 0=Dirichlet, 1=reflecing, 2=periodic */
      float    **f);       /* input: original image ;  output: smoothed */


/**
 Gaussian convolution.
*/




/**
 * CALCULA UNA HOMOGRAFIA A PARTIR DE UN CONJUNTO DE CORRESPONDENCIAS DE PUNTOS
 *
 * \param x,y  COORDINATES IN THE FIRST IMAGE 
 * \param xn,yn  COORDINATES IN THE SECON IMAGE 
 * \param H  OUTPUT HOMOGRAFY
 * \param N  NUMBER OF CORRESPONDING POINTS 
 */
int ami_calculo_homografia(double *x,double *y /* COORDINATES IN THE FIRST IMAGE */,
                           double *xn,double *yn /* COORDINATES IN THE SECON IMAGE */ ,
			   double H[3][3] /* OUTPUT HOMOGRAFY*/,
			   int N /* NUMBER OF CORRESPONDING POINTS */);


/**
 * CALCULA LA INTERSECCION DE 2 RECTAS 2D                   
 *
 * \param recta1,recta2  Coeficientes que determinan las dos rectas 
 * \param x,y  SALIDA punto de interseccion de las rectas
 */
int ami_punto_interseccion_2_rectas(double recta1[3],double recta2[3],double *x,double *y);
     /* double recta1[3],recta2[3]; Coeficientes que determinan las dos rectas */
     /* double *x,*y; SALIDA punto de interseccion de las rectas */

/**
 * CALCULA LA RECTA QUE MEJOR APROXIMA UN CONJUNTO DE PUNTOS 2D
 *
 * \param recta  COEFICIENTES DE LA RECTA 2D (SALIDA)
 * \param Puntos2D  COORDENADAS DE LOS PUNTOS 2D 
 * \param N  NUMERO DE PUNTOS
 */
int ami_calculo_recta2d(double recta[3],double **Puntos2D,int N) ;    



/**
 * CALCULA LA RECTA QUE MEJOR APROXIMA UN CONJUNTO DE PUNTOS 2D  
 * DE FORMA ROBUSTA.                          
 *
 * \param recta  COEFICIENTES DE LA RECTA 2D (SALIDA) 
 * \param Puntos2D  COORDENADAS DE LOS PUNTOS 2D 
 * \param N  NUMERO DE PUNTOS 
 * \param dmax  DISTANCIA MAXIMA ADMITIDA ENTRE UN PUNTO Y LA RECTA 
 *
 * \return DEVUELVE EL NUMERO DE PUNTOS UTILIZADOS PARA EL CALCULO DE LA RECTA ROBUSTA
 */
int ami_calculo_recta2d_robusto(double recta[3],double **Puntos2D,int N,float dmax) ;    

/**
 * FUNCION QUE CALCULA AUTOVALOR Y AUTOVECTOR MINIMO MATRIZ     
 * VALE PARA MATRICES SIMETRICAS Y SEMIDEFINIDA POSITIVAS       
 *
 * \param B  MATRIZ DE ENTRADA 
 * \param v  AUTOVECTOR CALCULADO DE AUTOVALOR MINIMO 
 * \param l  AUTOVALOR MINIMO 
 * \param N  DIMENSION MATRIZ 
 */
int ami_autovalor_minimo_old(double **B,double *v,double *l,int N);

/**
 * FUNCION QUE CALCULA AUTOVALOR Y AUTOVECTOR MINIMO MATRIZ      
 * VALE PARA MATRICES SIMETRICAS Y SEMIDEFINIDA POSITIVAS   
 *
 * \param B  MATRIZ DE ENTRADA 
 * \param v  AUTOVECTOR CALCULADO DE AUTOVALOR MINIMO 
 * \param l  AUTOVALOR MINIMO 
 * \param N  DIMENSION MATRIZ 
 */
int ami_autovalor_minimo(double **B,double *v,double *l,int N);


/**
 * METODO DE GAUSS PARA RESOLVER SISTEMAS DE ECUACIONES DE 3x3
 *
 * \return DEVUELVE LA SOLUCION EN EL VECTOR b.
 */
int ami_gauss3x3(double A[3][3],double b[3]);
/* double A[3][3],b[3]; */


/**
 * CALCULO DE LA MATRIZ INVERSA POR EL METODO DE GAUSS-JORDAN MATRICES 3x3 
 */
int ami_inversa3x3(double** A,double** A_1);
     /* double A[3][3],A_1[3][3]; */

/**
 * CALCULO DE LA MATRIZ INVERSA  MATRICES 2x2
 */
int ami_inversa2x2(double** A,double** A_1);

/**
 * METODO DE GAUSS PARA RESOLVER SISTEMAS DE ECUACIONES
 *
 * \return DEVUELVE LA SOLUCION EN EL VECTOR b 
 */
int ami_gauss(double **A,double *b,int N);
     /*double **A,*b; int N; */


/**
 * FUNCION PARA MULTIPLICAR MATRIZ Y VECTOR
 *
 * \param a  Matriz de entrada
 * \param x  Vector de entrada 
 * \param v  Vector de salida 
 * \param dim  Dimension de la matriz y vector 
 */
double *ami_MxV(double **a,double *x, double *v,int dim);

/**
 * FUNCION PARA MULTIPLICAR VECTOR Y VECTOR                  
 *
 * \param x  Vector de entrada 
 * \param v  Vector de entrada 
 * \param dim  Dimension de los vectores 
 */
double ami_VxV(double *x,double *v,int dim);

/**
 * FUNCION PARA MULTIPLICAR  UNA MATRIZ Y SU TRASPUESTA     
 *
 * \param a  Matriz de entrada 
 * \param as  Matriz de salida 
 * \param dimf  N filas matriz a 
 * \param dimc  N columnas matriz a 
 */
double **ami_MxM(double **a,double **as,int dimf,int dimc);


/**
 * CALCULO DE LA MATRIZ INVERSA POR EL METODO DE GAUSS-JORDAN
 */
int ami_inversa(double **A,double **A_1,int N);
     /* double **A,**A_1; int N; */

/** FUNCTION TO COMPUTE A GRADIENT OF A 2D IMAGE USING A 3x3 MASK 
 *
 */
void ami_grad_2df_3x3(float **image,float **image_x,float **image_y,int dim_x,int dim_y);

/**
 * FUNCTION TO COMPUTE A BASIC GRADIENT OF A 2D IMAGE
 */
void ami_grad_2df(float **image,float **image_x,float **image_y,int dim_x,int dim_y);

/** 
 * FUNCTION TO REMOVE NOISE USING A MEDIAN FILTER IN A NEIGBORHOOD 
 */
void ami_noise_median_filter_2df(float **image,int dim_x,int dim_y,int window_radius,float percentage,int Niter);


#endif
