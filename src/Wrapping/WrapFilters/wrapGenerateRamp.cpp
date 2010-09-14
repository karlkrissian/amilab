/*
 *  wrapGenerateRamp.cpp
 */

#include "wrapGenerateRamp.h"
#include <cmath>
#include "inrimage.hpp"
#include "paramlist.h"
#include "wrapfunctions.hpp"
#include <iostream>
using namespace std;

#ifndef M_PI
# define M_PI           3.14159265358979323846  /* pi */
#endif

//Analyzed synthetic object
int OBJETO;
float CENTRO, CENTROX, CENTROY, CENTROZ;
float CONTRASTE;
double RAMPAGX, RAMPAGY;

// //Internal inline function that says if the point is inside the ramp
// inline int insideRamp (float x, float y, float gx, float gy) {
//   float d;
//   static long n = 0;
// 
//   if (fabs(RAMPAGX) < fabs(RAMPAGY)) {
//     d = y - CENTROY + RAMPAGX/RAMPAGY * (x-CENTROX);
//     if (gy<0) d = -d;
//   }
//   else {
//     d = x - CENTROX + RAMPAGY/RAMPAGX * (y-CENTROY);
//     if (gx < 0) d = -d;
//    }
//     
//   //If it's just on ramp, sometimes in other out
//   if (d == 0) return (((float)(++n/2) == (float)n/2)? 0 : 1);
//   return ((d < 0)? 0 : 1);
// }

//Internal inline function. Compute the color for a pixel
inline float CalculaColorPixel (double gx, double gy, double d, double A, double B)
/* dado el vector gradiente y el desplazamiento interior al pixel, y 
los colores a cada lado del borde, calculamos el color que debería tener
el pixel. Solo funciona para el caso gx,gy>0, gx<gy.
Se supone que A es debajo de la curva y B encima */
{
  double m = fabs(gx/gy);	// la ecuación de la recta es y=d-mx;
  double y1, y2, x1, x2;
  double area;
  double resultado;
  
  // calculamos los cortes con los bordes verticales del pixel
  y1 = d + 0.5 * m;
  y2 = d - 0.5 * m;
  
  // la recta pasa por debajo del pixel 
  if (y2 > 0.5) area = 0.0;
	else
    
    // la recta corta el pixel abajo y a la derecha
    if (y1 > 0.5) {
      x1 = (d-0.5) / m;
      area = 0.5 * (0.5-x1) * (0.5-y2);
    }
    else
      
      // la recta corta de izquierda a derecha
      if (y2 > -0.5) {
        area = (0.5-y1) + 0.5 *(y1-y2);
      }
      else
        
        // la recta corta a la izquierda y arriba
        if (y1 > -0.5) {
          x2 = (d+0.5) / m;
          area = 0.5 * (y1+0.5) * (x2+0.5);
          area = 1 - area;
        }
        else
          
          // la recta pasa por arriba
          area = 1.0;
	
  // retornamos el porcentaje de A y B
  //printf ("y1=%f, y2=%f x1=%f x2=%f area=%f\n", y1,y2,x1,x2,area);
  resultado = area*A + (1-area)*B;
  return ((float) resultado);
}

