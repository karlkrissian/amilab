#ifndef AMI_SNAKE_H
#define AMI_SNAKE_H

/********************************************************************************************************
FUNCTION TO EXTRACT THE SNAKE CONTOUR FROM THE LEVEL SET
********************************************************************************************************/
void ami_extract_snake_contour(
  unsigned char *imagen_level_set, /* IMAGEN CON EL CONJUNTO DE NIVEL INICIAL Y DONDE SE DEVUELVE EL CONJUNTO DE NIVEL FINAL.
                                     SE ENTIENDE QUE TODOS LOS PIXELS DONDE ESTA IMAGEN SEA MAYOR QUE 128 PERTENECE AL CONJUNTO DE NIVEL */
  int width,int height,  /* DIMENSIONES DE LAS IMAGENES */
  int **i_snake, /* vertical coordinate of the snake point */
  int **j_snake, /* horizontal coordinate of the snake point */
  int *Npoints); /* number of points */

/**********************************************************************/
/* FUNCION QUE CALCULA LOS SNAKES GEODESICOS A PARTIR DE UN LEVEL SET */
/**********************************************************************/
int ami_snake_level_set(
  float *imagen, /* IMAGEN ORIGINAL DONDE SE ENCUENTRA EL SNAKE (unchanged) */
  unsigned char *imagen_level_set, /* IMAGEN CON EL CONJUNTO DE NIVEL INICIAL Y DONDE SE DEVUELVE EL CONJUNTO DE NIVEL FINAL.
                                     SE ENTIENDE QUE TODOS LOS PIXELS DONDE ESTA IMAGEN SEA MAYOR QUE 128 PERTENECE AL CONJUNTO DE NIVEL */
  int width,int height,  /* DIMENSIONES DE LAS IMAGENE */
  int borde,             /* BORDE DE SEPARACION DE LA SUBVENTANA DE TRABAJO RESPECTO AL CONJUNTO DE NIVEL INICIAL */
  float alfa,            /* PARAMETRO FUNCION g = 1/sqrt(1+alfa*grad(I)^2) */
  float lambda,          /* PARAMETRO DE BALANCE ENTRE TERMINOS DE REGULARIDAD Y ATRACCION */
  float sigma,           /* DESVIACION ESTANDARD DE LA GAUSSIANA PARA CALCULAR IMAGEN g */
  int Nescalas,          /* NUMERO DE ESCALAS DIFERENTES UTILIZADAS EN TODO EL PROCESO */
  int Niter);                /* NUMERO DE ITERACIONES MAXIMO EN CADA ESCALA */


/************************************************************************/
/* FUNCION QUE CALCULA UNA ITERACION EN EL PROCEDIMIENTO DE ami_snake() */
/************************************************************************/
void ami_snake_iteracion(
  float *imagen_level_set, /* IMAGEN DEL CONJUNTO DE NIVEL */
  float *imagen_level_set_x, /* DERIVADA EN X DE LA IMAGEN DEL CONJUNTO DE NIVEL */
  float *imagen_level_set_y, /* DERIVADA EN y DE LA IMAGEN DE CONJUNTO DE NIVEL */
  float *imagen_g,           /* IMAGEN g = 1/sqrt(1+alfa*grad(I)^2) */
  float *imagen_g_x,         /* DERIVADA EN X DE LA IMAGEN g */
  float *imagen_g_y,         /* DERIVADA EN Y DE LA IMAGEN g */
  int width2,int height2,    /* DIMENSIONES IMAGEN QUE CONTIENE AL POLIGONO */
  float lambda,              /* PARAMETRO DE BALANCE ENTRE TERMINOS DE REGULARIDAD Y ATRACCION */
  float *error,              /* INCREMENTO MAXIMO DEL VALOR DE LA IMAGEN CONJUNTO DE NIVEL EN 1 ITER */
  float max_grad_g);          /* MAXIMO GRADIENTE IMAGEN g PARA CALCULAR EL dt A UTILIZAR */

/*********************************************************************/
/* FUNCION QUE CALCULA LOS SNAKES GEODESICOS A PARTIR DE UN POLIGONO */
/*********************************************************************/
int ami_snake(
  unsigned char *imagen, /* IMAGEN DONDE SE ENCUENTRA EL SNAKE */
  int width,int height,  /* DIMENSIONES DE LA IMAGEN */
  int *x,int *y,         /* COORDENADAS DEL POLIGONO */
  int Np,                /* NUMERO DE PUNTOS DEL POLIGONO */
  int borde,             /* BORDE DE SEPARACION DEL POLIGONO PARA CONSTRUIR LA IMAGEN DE CONJUNTO DE NIVEL */
  int *xd,int *yd,       /* DESPLAZAMIENTO DE LAS COORDENADAS DEL POLIGONO EN LA IMAGEN CONJUNTO DE NIVEL */
  float alfa,            /* PARAMETRO FUNCION g = 1/sqrt(1+alfa*grad(I)^2) */
  float lambda,          /* PARAMETRO DE BALANCE ENTRE TERMINOS DE REGULARIDAD Y ATRACCION */
  float sigma,           /* DESVIACION ESTANDARD DE LA GAUSSIANA PARA CALCULAR IMAGEN g */
  int Nescalas,          /* NUMERO DE ESCALAS DIFERENTES UTILIZADAS EN TODO EL PROCESO */
  float **imagen_level_set_r, /* IMAGEN DE CONJUNTO DE NIVEL RESULTADO (SU FRONTERA CORRESPONDE AL SNAKE) */
  int *width_g,int *height_g, /* DIMENSIONES IMAGEN CONJUNTO DE NIVEL */
  int Niter);                 /* NUMERO DE ITERACIONES MAXIMO EN CADA ESCALA */

/*******************************************************/
/* FUNCION CONSTRUYE UNA IMAGEN RELLENANDO UN POLIGONO */
/*******************************************************/
/* DEVUELVE -1 SI ALGO VA MAL y 0 SI TERMINA BIEN */
int ami_rellenar_poligono(
   float **imagen,  /* IMAGEN QUE SE VA A RELLENAR */
   int *x,int *y,   /* COORDENADAS POLIGONO */
   int Np,          /* NUMERO DE PUNTOS DEL POLIGONO */
   float nivel1,     /* NIVEL EXTERIOR CON EL QUE SE RELLENA */
   float nivel2,    /* NIVEL INTERIOR CON EL QUE SE RELLENA */
   int borde,       /* MARGEN QUE SE DEJA DE LA IMAGEN AL POLIGONO */
   int *width,int *height, /* DIMENSIONES DE LA IMAGEN CREADA */
   int *xd,int *yd);  /* DESPLAZAMIENTO REALIZADO DE LAS COORDENADAS DE LOS POLIGONOS */

#endif
