/****************************************************************************
**
**  Arrows.h:  Fichero que implementa la funcin que genera una im�enes 
**             de flechas a partir de U, V.
**
*****************************************************************************/

#ifndef H_ARROWS_H
#define H_ARROWS_H


#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

#define ArrowsMax(a, b) ((a>b)?(a):(b))
#define ArrowsMin(a, b) ((a>b)?(b):(a))


//typedef float real;


/// ...........................................................................
/// ...........................................................................


template <class Function>
void DrawLine(Function &I, int posx, int posy, int bx, int by){

  int difx = (bx - posx);
  int dify = (by - posy);
  int dd;

  if(abs(difx) > abs(dify)) dd = abs(difx);
  else dd = abs(dify);

  const real incX = ((real) difx/dd);
  const real incY = ((real) dify/dd);

  real x = posx;
  real y = posy;

  for ( int i = 0; i < dd; i++){

    //I((int) (x+0.5), (int) (y+0.5)) = 0;
    I[(int) (y+0.5)][(int) (x+0.5)] = 0;
    x += incX;
    y += incY;

  }

}

/*

template <class Function>
void DrawLine(Function &I, int posx, int posy, int bx, int by){

  int difx = (bx - posx);
  int dify = (by - posy);
  int dd;

  if(abs(difx) > abs(dify)) dd = abs(difx);
  else dd = abs(dify);

  const real incX = ((real) difx/dd);
  const real incY = ((real) dify/dd);

  real x = posx;
  real y = posy;

  for ( int i = 0; i < dd; i++){

    I((int) (x+0.5), (int) (y+0.5)) = 0;
    x += incX;
    y += incY;

  }

}

*/




/*******************************************************************************/
/****	FUNCION PARA RELLENAR UN TRIANGULO CUYOS VERTICES SON cxi, cyi	    ****/
/*******************************************************************************/
template <class Function>
void Rellenar(Function &I, real cx1, real cy1, real cx2, real cy2, 
	      real cx3, real cy3)
{
    real maxX, maxY;
    real minX, minY;
    real i,j;

    /* obtenemos el cuadro que engloba al triangulo */
    maxX=ArrowsMax(cx1, ArrowsMax(cx2, cx3));
    minX=ArrowsMax(cx1, ArrowsMax(cx2, cx3));
    maxY=ArrowsMax(cy1, ArrowsMax(cy2, cy3));
    minY=ArrowsMax(cy1, ArrowsMax(cy2, cy3));
    
    /* empezamos a rellenar */
    for(j = minY; j <= maxY; j+=1)
      for(i = minX; i <= maxX; i+=1)
	    if((((i-cx2)*(cy1-cy2)-(cx1-cx2)*(j-cy2))* \
		((i-cx3)*(cy2-cy3)-(cx2-cx3)*(j-cy3)))>=0){
		    if(((i-cx1)*(cy3-cy1)-(cx3-cx1)*(j-cy1))>=0){

			//I((int)(i+0.5), (int)(j+0.5)) = 0;
			I[(int)(j+0.5)][(int)(i+0.5)] = 0;
		    }
		}
}


/*

template <class Function>
void Rellenar(Function &I, real cx1, real cy1, real cx2, real cy2, 
	      real cx3, real cy3)
{
    real maxX, maxY;
    real minX, minY;
    real i,j;

    // obtenemos el cuadro que engloba al triangulo
    maxX=ArrowsMax(cx1, ArrowsMax(cx2, cx3));
    minX=ArrowsMax(cx1, ArrowsMax(cx2, cx3));
    maxY=ArrowsMax(cy1, ArrowsMax(cy2, cy3));
    minY=ArrowsMax(cy1, ArrowsMax(cy2, cy3));
    
    // empezamos a rellenar
    for(j = minY; j <= maxY; j+=1)
      for(i = minX; i <= maxX; i+=1)
	    if((((i-cx2)*(cy1-cy2)-(cx1-cx2)*(j-cy2))* \
		((i-cx3)*(cy2-cy3)-(cx2-cx3)*(j-cy3)))>=0){
		    if(((i-cx1)*(cy3-cy1)-(cx3-cx1)*(j-cy1))>=0){

			I((int)(i+0.5), (int)(j+0.5)) = 0;
		    }
		}
}

*/


/*******************************************************************************/
/****	FUNCION PARA DIBUJAR UN VECTOR EN LA posx, posy EN LA IMAGEN	    ****/
/****	imgDestino, CON UNA VELOCIDAD DE valx, valy			    ****/
/*******************************************************************************/

template <class Function>
void DibujarFlecha(Function &I, int width, int height, int posx, int posy, real valx, real valy,
		   real Umbral, real angCabeza, real lonCab, 
		   real magFlecha)
{
  real bx=(real)posx, by=(real)posy;	/* punto final de la flecha */
  real ax, ay;	        /* desplazamiento del origen con respecto al final */
  real cx, cy;		/* variables para calcular los puntos de la cabeza */
  real cx1, cy1;	/* variables para calcular los puntos de la cabeza */
  real ax1, ax2, ay1, ay2; /* variables intermedias para el calculo de la cabeza */
  real modulo, lonTronco;
  real lonCabeza;

/*
#if (0)
  int width  = I.GetXd();
  int height = I.GetYd();
#else
  int width  = I.width();
  int height = I.height();
#endif  
*/
  
  /* modificacion para que las flechas salgan en valor logaritmico */
  /*   ax=-(valx>0?log( 1.+10.*valx):-log( 1.-10.*valx) ); 
       ay=-(valy>0?log( 1.+10.*valy):-log( 1.-10.*valy) );*/

  ax=-valx;
  ay=-valy;
  lonTronco=fabs(ax)>fabs(ay)?fabs(ax):fabs(ay);
  ax=(ax>0)?5.*magFlecha*ax/(1+0.5*ax):5.*magFlecha*ax/(1-0.5*ax);
  ay=(ay>0)?5.*magFlecha*ay/(1+0.5*ay):5.*magFlecha*ay/(1-0.5*ay);
  
  bx-=ax;
  by-=ay;
  
  /* comprobamos que haya movimiento en el punto */

  if(lonTronco > Umbral){

    lonTronco = sqrt(ax*ax+ay*ay);

    /* dibujamos el tronco de la flecha */
    if(bx < 0)      bx = 0;
    if(bx > width)  bx = width - 1;
    if(by < 0)      by = 0;
    if(by > height) by = height - 1;

    DrawLine(I, posx, posy, (int)(bx+0.5), (int)(by+0.5)); 
    
    /* vamos a dibujar la cabeza */

    ax1 = ax*cos(angCabeza) + ay*sin(angCabeza); 
    /* rotacion para el primer palo */

    ay1 = -ax*sin(angCabeza) + ay*cos(angCabeza);
    ax2 = ax*cos(angCabeza) - ay*sin(angCabeza);
    /* rotacion para el segundo palo */

    ay2 = ax*sin(angCabeza) + ay*cos(angCabeza);
    modulo = sqrt(ax1*ax1 + ay1*ay1);
    
    lonCabeza = lonCab*lonTronco;// tamao de la cabeza proporcional a la del tronco

    if(modulo>0.000001){

      /* dibujamos el primer palo de la cabeza */
      cx = ax1/modulo*lonCabeza+bx;
      cy = ay1/modulo*lonCabeza+by;

      if(cx < 0)      cx = 0;
      if(cx > width)  cx = width - 1;
      if(cy < 0)      cy = 0;
      if(cy > height) cy = height - 1;
      //DrawLine(I, (int)(cx+0.5), (int)(cy+0.5), (int)(bx+0.5), (int)(by+0.5));
	   
      /* dibujamos el segundo palo de la cabeza */
      cx1 = ax2 / modulo * lonCabeza + bx;
      cy1 = ay2 / modulo * lonCabeza + by;

      if(cx1 < 0)      cx1 = 0;
      if(cx1 > width)  cx1 = width - 1;
      if(cy1 < 0)      cy1  = 0;
      if(cy1 > height) cy1 = height - 1;
      //DrawLine(I, (int)(cx1+0.5), (int)(cy1+0.5), (int)(bx+0.5), (int)(by+0.5));
 
      Rellenar(I, cx, cy, cx1, cy1, bx, by);
    }
  }    
}


/*

template <class Function>
void DibujarFlecha(Function &I, int posx, int posy, real valx, real valy,

		   real Umbral, real angCabeza, real lonCab, 
		   real magFlecha)
{
  real bx=(real)posx, by=(real)posy;	// punto final de la flecha
  real ax, ay;	        // desplazamiento del origen con respecto al final
  real cx, cy;		// variables para calcular los puntos de la cabeza
  real cx1, cy1;	// variables para calcular los puntos de la cabeza 
  real ax1, ax2, ay1, ay2; // variables intermedias para el calculo de la cabeza 
  real modulo, lonTronco;
  real lonCabeza;

#if (0)
  int width  = I.GetXd();
  int height = I.GetYd();
#else
  int width  = I.width();
  int height = I.height();
#endif  
  
  // modificacion para que las flechas salgan en valor logaritmico 
  //   ax=-(valx>0?log( 1.+10.*valx):-log( 1.-10.*valx) ); 
  //     ay=-(valy>0?log( 1.+10.*valy):-log( 1.-10.*valy) );

  ax=-valx;
  ay=-valy;
  lonTronco=fabs(ax)>fabs(ay)?fabs(ax):fabs(ay);
  ax=(ax>0)?5.*magFlecha*ax/(1+0.5*ax):5.*magFlecha*ax/(1-0.5*ax);
  ay=(ay>0)?5.*magFlecha*ay/(1+0.5*ay):5.*magFlecha*ay/(1-0.5*ay);
  
  bx-=ax;
  by-=ay;
  
  // comprobamos que haya movimiento en el punto

  if(lonTronco > Umbral){

    lonTronco = sqrt(ax*ax+ay*ay);

    // dibujamos el tronco de la flecha
    if(bx < 0)      bx = 0;
    if(bx > width)  bx = width - 1;
    if(by < 0)      by = 0;
    if(by > height) by = height - 1;

    DrawLine(I, posx, posy, (int)(bx+0.5), (int)(by+0.5)); 
    
    // vamos a dibujar la cabeza

    ax1 = ax*cos(angCabeza) + ay*sin(angCabeza); 
    // rotacion para el primer palo

    ay1 = -ax*sin(angCabeza) + ay*cos(angCabeza);
    ax2 = ax*cos(angCabeza) - ay*sin(angCabeza);
    // rotacion para el segundo palo

    ay2 = ax*sin(angCabeza) + ay*cos(angCabeza);
    modulo = sqrt(ax1*ax1 + ay1*ay1);
    
    lonCabeza = lonCab*lonTronco;// tamao de la cabeza proporcional a la del tronco

    if(modulo>0.000001){

      // dibujamos el primer palo de la cabeza
      cx = ax1/modulo*lonCabeza+bx;
      cy = ay1/modulo*lonCabeza+by;

      if(cx < 0)      cx = 0;
      if(cx > width)  cx = width - 1;
      if(cy < 0)      cy = 0;
      if(cy > height) cy = height - 1;
      //DrawLine(I, (int)(cx+0.5), (int)(cy+0.5), (int)(bx+0.5), (int)(by+0.5));
	   
      // dibujamos el segundo palo de la cabeza
      cx1 = ax2 / modulo * lonCabeza + bx;
      cy1 = ay2 / modulo * lonCabeza + by;

      if(cx1 < 0)      cx1 = 0;
      if(cx1 > width)  cx1 = width - 1;
      if(cy1 < 0)      cy1  = 0;
      if(cy1 > height) cy1 = height - 1;
      //DrawLine(I, (int)(cx1+0.5), (int)(cy1+0.5), (int)(bx+0.5), (int)(by+0.5));
 
      Rellenar(I, cx, cy, cx1, cy1, bx, by);
    }
  }    
}

*/


/// ...........................................................................
/// ...........................................................................


/*******************************************************************************/
/****	FUNCION PRINCIPAL PARA CREAR UNA IMAGEN DE VECTORES DE VELOCIDAD    ****/
/*******************************************************************************/

template <class Image, class ImageOut> //, class real>
int create_arrows_image( const Image &U, const Image &V, ImageOut &Arrows, int width, int height,
                         int ampliacion=1, int intervalo=5, real umbral=0.0, int angFlecha=25,
                         real lonFlecha=0.5, real magFlecha=1.0 ) {

    //int height = U.height();
    //int width  = U.width();
    int i, j;


    for(j = intervalo; j < height - intervalo + 1; j += intervalo)
      for(i = intervalo; i < width - intervalo + 1; i += intervalo)

          DibujarFlecha(Arrows, width, height, i*ampliacion, j*ampliacion, U[j*width +i],
		                    V[j*width +i], umbral, angFlecha*3.141592653/180,
		                    lonFlecha, magFlecha);

    return 0;
}


/*
template <class Image> //, class real>
int create_arrows_image( const Image &U, const Image &V, Image &Arrows, int width, int height,
                         int ampliacion=1, int intervalo=5, real umbral=0.0, int angFlecha=25,
                         real lonFlecha=0.5, real magFlecha=1.0 ) {

    //int height = U.height();
    //int width  = U.width();
    int i, j;

    for(j = intervalo; j < height - intervalo + 1; j += intervalo)
      for(i = intervalo; i < width - intervalo + 1; i += intervalo)

          DibujarFlecha(Arrows, i*ampliacion, j*ampliacion, U(i, j),
		                    V(i, j), umbral, angFlecha*3.141592653/180,
		                    lonFlecha, magFlecha);

    return 0;
}
*/


#endif


// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
