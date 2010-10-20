
#ifndef _AMI_CORNER_H
#define _AMI_CORNER_H

/**
 * FUNCION QUE CALCULA LAS ESQUINAS POR EL METODO DE HARRIS         
 *
 * \param image  INPUT IMAGE 
 * \param width,height  IMAGE SIZE 
 * \param threshold  TRESHOLD FOR HARRIS CRITERIUM 
 * \param sigma  STANDARD DEVIATION OF THE GAUSSIAN 
 * \param filename  FILE NAME FOR THE ESTIMATED CORNERS 
 * \param radius  MINIMUM DISTANCE ALLOWED BETWEEN CORNERS
 */
int ami_harris_corner_detector(float *image, /*INPUT IMAGE */
				int width ,int height,/*IMAGE SIZE */
				float threshold, /* TRESHOLD FOR HARRIS CRITERIUM */
				float sigma, /* STANDARD DEVIATION OF THE GAUSSIAN */
				char filename[100], /* FILE NAME FOR THE ESTIMATED CORNERS */
			       int radius /* MINIMUM DISTANCE ALLOWED BETWEEN CORNERS */);

/**
 * CALCULA LA ECUACION DE AFIN Y LA CURVATURA SIMULTANEAMENTE          
 *
 * \param rim IMAGEN DE ENTRADA 
 * \param c  CURVATURA 
 * \param width,height  DIMENSIONES DE LA IMAGEN 
 * \param step  PASO DE DISCRETIZACION DE LA ECUACION 
 */
void ami_AFIN_CURVATURA(float *rim,float *c,int width,int height,float step);

/**
 * MEJORA LA POSICION DE UNA ESQUINA CON PRECISION SUBPIXEL
 *
 * \param c  MAPA DE CURVATURAS DE LA IMAGEN 
 * \param ix,iy  POSICION DE LA ESQUINA EN COORDENADAS PIXELS 
 * \param x,y  POSICION DE LA ESQUINA MEJORADA 
 * \param width  ANCHO DE LA IMAGEN 
 * \param Cu  DEVUELVE LA CURVATURA DE LA ESQUINA EN VALOR ABSOLUTO
 */
int ami_MEJORA_ESQUINA(float *c,int ix,int iy,double *x,double *y,int width,double *Cu);

/**
 * CALCULO LA POSICICION DEL MAXIMO DE UNA FUNCION EN VALOR ABSOLUTO EN UNA VECINDAD 3x3                  
 *
 * \param c  FUNCION A LA QUE SE CALCULA EL MAXIMO 
 * \param m  PUNTO A PARTIR DEL CUAL SE CALCULA EL MAXIMO 
 * \param i0,j0  POSICION RELATIVA DEL MAXIMO 
 * \param width  ANCHO DE LA VENTANA 
 *
 * \return DEVUELVE 0 SI EL MAXIMO ESTA EN m y -1 SI EL MAXIMO ESTA EN UN VECINO
 */
int ami_maximo_3x3(float *c,long m,int width,int *i0,int *j0);

/**
 * FUNCION QUE CALCULA LA PROYECCION DE UN PUNTO 2D A UNA RECTA 2D 
 *
 * \param r  ECUACION DE LA RECTA NORMALIZADA 
 * \param x0,y0  PUNTO QUE HAY QUE PROYECTAR 
 * \param x,y  RESULTADO DE LA PROYECCION 
 */
void ami_proyeccion_punto_recta2d(double r[3],double x0,double y0,double *x,double *y);

/**
 *    FUNCION PARA MEJORAR LAS POSICIONES DE LAS ESQUINAS PARA UNA IMAGEN IMG    
 *
 * \param imgdata  PUNTERO A LA IMAGEN ORIGINAL 
 * \param width  ANCHO DE LA IMAGEN ORIGINAL 
 * \param height  ALTO IMAGEN ORIGINAL        
 * \param radio  RADIO VENTANA SUBIMAGEN PARA REFINAR EL CALCULO DE LA ESQUINA 
 * \param coord_x,coord_y  COORDENADAS EN PIXEL DE LA ESQUINA INICIAL 
 * \param px,py  COORDENADAS DE LA ESQUINA MEJORADA
 */
int ami_calculo_esquina_afin_img(unsigned char *imgdata,int width,int height,int radio,int coord_x,int coord_y,double *px,double *py);


/**
 * FUNCION AUXILIAR METODO DE NEWTON PARA BUSQUEDA DE MAXIMOS 
 */
double ami_F(double x,double y,double c[9]);

/**
 * FUNCION AUXILIAR METODO DE NEWTON PARA BUSQUEDA DE MAXIMOS.
 *
 * CALCULAR VECTOR DE COEFICIENTES c[9] A PARTIR DE LOS VALORES DE LA
 * CORRELACION DADOS EN EL VECTOR Co[9] (9 VALORES QUE RECORREN LA VECINDAD
 * DEL PUNTO DE IZQUIERDA A DERECHA Y DE ABAJO A ARRIBA.	
 */
void ami_CalculoCoeficientes(double Co[9],double c[9]);


/**
 * FUNCION AUXILIAR METODO DE NEWTON PARA BUSQUEDA DE MAXIMOS.
 *
 * CALCULO DE LA MATRIZ HESSIANA 
 */
void ami_HF(double x,double y,double c[9],double H[2][2]);

/**
 * FUNCION AUXILIAR METODO DE NEWTON PARA BUSQUEDA DE MAXIMOS.
 *
 * RESUELVO SISTEMA CON EL HESSIANO. 
 *
 * \return DEVUELVE 0 SI HA TERMINADO CORRECTAMENTE 
 */ 
int ami_ResolverSistema(double H[2][2],double b[2],double sol[2]);


/**
 * FUNCION AUXILIAR METODO DE NEWTON PARA BUSQUEDA DE MAXIMOS.
 *
 * CALCULO DEL GRADIENTE DE LA FUNCION  ami_F(x,y) 
 */
void ami_Grad(double x,double y,double c[9],double G[2]);

/**
 * FUNCION METODO DE NEWTON PARA BUSQUEDA DE MAXIMOS.          
 *
 * CALCULO EL MAXIMO POR EL METODO DE NEWTON.
 *
 * \return DEVUELVO -1 SI TERMINO INCORRECTAMENTE. SI NO DEVUELVO EL NUMERO DE ITERACIONES
 */
int ami_Newton(double Co[9],double sol[2],double sol0[2],double *C);


/**
 * FUNCION METODO DE NEWTON PARA BUSQUEDA DE MAXIMOS.          
 *
 * CALCULO EL MAXIMO POR EL METODO DE NEWTON.
 *
 * \return DEVUELVO -1 SI TERMINO INCORRECTAMENTE. SI NO DEVUELVO EL NUMERO DE ITERACIONES
 */
int ami_NewtonOld(double Co[9],double sol[2],double sol0[2],double *C);

/**
 * FUNCION AUXILIAR METODO DE NEWTON PARA BUSQUEDA DE MAXIMOS 
 */
float ami_G(float x,float y);


/**
 * CALCULA u_xx*u_y²+u_yy*u_x²-2u_xy*u_x*u_y               
 *
 * \param cp  Imagen input u(n) 
 * \param dp  Imagen output u(n+1) 
 * \param nx,ny  Dimensiones de la imagen 
 */
void ami_operador_diferencial_direccional(float *cp,float *dp,int nx,int ny);


/**
 * CALCULA LA MEJOR ESQUINA POR EL METODO DE ALVAREZ-MORALES  
 *
 * \param rim  Flat para indicar los bordes de la imagen 
 * \param width,height  Dimensiones de la imagen 
 * \param x,y  (salida) Coordenadas de la esquina 
 * \param step  PASO DISCRETIZACION ECUACION AFIN 
 * \param nitermin  NUMERO DE ITERACIONES PREVIAS 
 * \param finalscale  ESCALA FINAL PARA PARAR 
 * \param SubScaleSize  DETERMINA LA DISCRETIZACION DE LA ESCALA 
 * \param umbral  UMBRAL PARA LAS DISTANCIAS DE RECTA A PUNTO 
 */
int ami_esquina_afin(float *rim,int width,int height,double *x,double *y,float step,int nitermin,float finalscale,float SubScaleSize,float umbral);


/**
 * CALCULO DE LA ESQUINA PREDOMINANTE EN UNA IMAGEN   
 * bordes[m]=0 indica que el punto pertenece a los bordes de    
 * la imagen bordes[m]=-1 indica que el pixel es del fondo      
 *
 * \param bordes  Flat para indicar los bordes de la imagen 
 * \param width,height  Dimensiones de la imagen 
 * \param x,y  (salida) Coordenadas de la esquina 
 * \param umbral1  Umbral de distancia para decidir si un punto está en una recta                           
 * \param umbral2  Umbral para refinar las rectas y eliminar los outliders 
 */
int ami_bordes_to_esquina(int *bordes,int width,int height,double *x,double *y,float umbral1,float umbral2);

/**
 * CALCULO RECURSIVO DE LA RECTA DEL BORDE ASOCIADA A UN PUNTO          
 *
 * \param bordes  Flat para indicar los bordes de la imagen 
 * \param width,height  Dimensiones de la imagen 
 * \param umbral  Umbral de distancia para decidir si un punto está en una recta                            
 * \param f  Flat para controlar si ya hemos pasado por el punto 
 * \param i0,j0  Posicion del punto a analizar 
 * \param r  (salida) Recta del borde que pasa por el punto 
 * \param cx,cy
 */
int ami_RectaRecursivaAgustin(int *bordes,int width,int height,float umbral,int *f,int i0,int j0,double r[3], double *cx,double *cy);


/**
 * CALCULO DE LA ESQUINA PREDOMINANTE EN UNA IMAGEN PARA METODO AGUSTIN 
 * bordes[m]=0 indica que el punto pertenece a los bordes de                       
 * la imagen bordes[m]=-1 indica que el pixel es del fondo                         
 *
 * \param bordes  Flat para indicar los bordes de la imagen 
 * \param cx,cy  Coordenadas del borde con precisión subpixel 
 * \param width,height  Dimensiones de la imagen 
 * \param x,y  (salida) Coordenadas de la esquina 
 * \param umbral1  Umbral de distancia para decidir si un punto está en una recta                            
 * \param umbral2  Umbral para refinar las rectas y eliminar los outliders 
 * \param r1,r2  Resultado de las dos rectas predominantes 
 */
int ami_bordes_subpixel_to_esquina(int *bordes,int width,int height,double r1[3],double r2[3],double *x,double *y,float umbral1,float umbral2,double *cx,double *cy);

/**
 * CALCULO RECURSIVO DE LA RECTA DEL BORDE ASOCIADA A UN PUNTO          
 *
 * \param bordes  Flat para indicar los bordes de la imagen 
 * \param width,height  Dimensiones de la imagen 
 * \param umbral  Umbral de distancia para decidir si un punto está en una recta                            
 * \param f  Flat para controlar si ya hemos pasado por el punto 
 * \param i0,j0  Posicion del punto a analizar 
 * \param r  (salida) Recta del borde que pasa por el punto 
 */
int ami_RectaRecursiva(int *bordes,int width,int height,float umbral,int *f,int i0,int j0,double r[3]);

/**
 * MEJORA LOS PUNTOS PARA LA CALIBRACION DE ZHANG           
 * CALCULA LAS RECTAS POR LAS QUE DEBEN PASAR LOS PUNTOS Y      
 * Y RECALCULA LOS PUNTOS COMO INTERCECCION DE LAS RECTAS       
 *
 * \param inputname  NOMBRE DEL ARCHIVO DONDE SE ENCUENTRAN LOS PUNTOS INICIALES 
 * \param outputname  NOMBRE DEL ARCHIVO CON EL QUE SE SALVA EN DISCO LOS PUNTOS MEJORADOS 
 */
int ami_MejoraPuntosCalibracionZhang(char *inputname,char *outputname);

/**
 * MORPHOLOGICAL CORNER DETECTOR FOR MULTIPLE CORNERS VERSION WITH         
 * 2 MAIN PARAMETERS:                                                     
 *       treshold: TRESHOLD FOR THE CORNERS PARAMETERS THE DEFAULT VALUE IS  
 *       1, BIGGER IS THE TRESHOLD LESS NUMBER OF CORNERS ARE ALLOWED        
 *       radius: MINIMUMU DISTANCE ALLOWED BETWEEN CORNERS                                   
 *
 * \param image  Pointer to the image grey-level values in float precicion 
 * \param width,height  Size of the image 
 * \param threshold  Threshold for corner parameters 
 * \param radius  Minimum distance allowed bettween corners 
 * \param filename  Name of the output file containing the corner information
 *
 * \return THE FUNCTION RETURN THE NUMBER OF CORNERS RECOVERED
 */
int ami_morphological_corner_detector(float *image,int width,int height,float threshold,int radius,char filename[100]);

/**
 * MORPHOLOGICAL CORNER DETECTOR FOR MULTIPLE CORNERS VERSION ami       
 *
 * \param rim  NIVEL DE GRIS DE LA IMAGEN
 * \param width,height  DIMENSIONES DE LA IMAGEN 
 * \param x,y  COORDENADAS DE LAS ESQUINAS ENCONTRADAS 
 * \param le  LONGITUD DE LA ESQUINA ENCONTRADA 
 * \param pe  PORCENTAJE DE PUNTOS OCUPADOS POR LA ESQUINA 
 * \param curv  VALOR ACUMULADO DEL OPERADOR DE LA CURVATURA A TRAVES DE LAS ESCALAS 
 * \param step  PASO DISCRETIZACION ECUACION AFIN 
 * \param UmbralCurvatura  UMBRAL SOBRE EL OPERADOR DE CURVATURA PARA DEFINIR LAS ESQUINAS 
 * \param UmbralRecta  UMBRAL PARA DISTANCIA RECTAS EN CALCULO DE RECTAS ROBUSTO 
 * \param initialscale  NUMERO DE ITERACIONES PREVIAS 
 * \param finalscale  ESCALA FINAL 
 * \param SubScaleSize  DISCRETIZACION DE LA ESCALA
 *
 * \return DEVOLVEMOS EL NUMERO DE ESQUINAS ENCONTRADAS
 */
int ami_esquina_afin_multiples(float *rim,int width,int height,double **x,double **y,double **le,double **pe,double **curv,float step,float UmbralCurvatura,float UmbralRecta,float initialscale,float finalscale,float SubScaleSize);





#endif
