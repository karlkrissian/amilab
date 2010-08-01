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

//Internal inline function that says if the point is inside the ramp
inline int insideRamp (float x, float y, float gx, float gy) {
  float d;
  static long n = 0;

  if (fabs(RAMPAGX) < fabs(RAMPAGY)) {
    d = y - CENTROY + RAMPAGX/RAMPAGY * (x-CENTROX);
    if (gy<0) d = -d;
  }
  else {
    d = x - CENTROX + RAMPAGY/RAMPAGX * (y-CENTROY);
    if (gx < 0) d = -d;
   }
    
  //If it's just on ramp, sometimes in other out
  if (d == 0) return (((float)(++n/2) == (float)n/2)? 0 : 1);
  return ((d < 0)? 0 : 1);
}

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

InrImage* wrapSintheticRamp (ParamList* p) {
  //Information
	char functionname[] = "wrapSintheticRamp";
    char description[]=" \n\
	Generates a sinthetic ramp for tests \n\
	\n\
	";
    char parameters[] =" \n\
	Parameters:\n\
	angle: The angle of the ramp\n\
	meshing: Detail level for meshing inside ramp pixel\n\
	opt: Perfect edge or not\n\
  A: Gray level under ramp\n\
  B: Gray level over ramp\n\
  disp: Displacement in the y-axis\n\
	";
  
  //GraphicWindow *gw;
  InrImage* ramp;
  int npar = 0;
  float angle;
  int meshing;
  int opt;
  float disp;
  int s, ss;
  float A;
  float B;
  int z = 0;
  
  //Create the image
  ramp = new InrImage(100, 100, 1, WT_FLOAT, "Sinthetic ramp");
  
  //Get params
  if (!get_val_param<float>(angle, p, npar)) HelpAndReturnNULL;
  if (!get_int_param(meshing, p , npar)) HelpAndReturnNULL;
  if (!get_int_param(opt, p, npar)) HelpAndReturnNULL;
  if (!get_val_param<float>(A, p, npar)) HelpAndReturnNULL;
  if (!get_val_param<float>(B, p, npar)) HelpAndReturnNULL;
  if (!get_val_param<float>(disp, p, npar)) HelpAndReturnNULL;

  OBJETO = 5;
  CENTROX = CENTRO = 50;
  CENTROY = 50 + disp;
  CONTRASTE = A - B;
  
  float m = (float) meshing;
  float m2 = m*m;
  
  // miramos los valores de la normal
  if (angle < 45) {
    RAMPAGX = tan(angle*M_PI/180);
    RAMPAGY = 1.0;
  }
  else
    if (angle < 90) {
      RAMPAGY = tan((90-angle)*M_PI/180);
      RAMPAGX = 1.0;
    }
    else
      if (angle < 135) {
        RAMPAGY = -tan((angle-90)*M_PI/180);
        RAMPAGX = 1.0;
      }
      else
        if (angle < 180) {
          RAMPAGX = tan((180-angle)*M_PI/180);
          RAMPAGY = -1.0;
        }
        else
          if (angle < 225) {
            RAMPAGX = -tan((angle-180)*M_PI/180);
            RAMPAGY = -1.0;
          }
          else
            if (angle < 270) {
              RAMPAGY = -tan((270-angle)*M_PI/180);
              RAMPAGX = -1.0;
            }
            else
              if (angle < 315) {
                RAMPAGY = tan((angle-270)*M_PI/180);
                RAMPAGX = -1.0;
              }
              else {
                RAMPAGX = -tan((360-angle)*M_PI/180);
                RAMPAGY = 1.0;
              }
  
  // creamos la imagen
  //gw = CreateImage ("rampa sintetico", RIM, 100, 100, "");
  cout << "Ramp generate. Angle = " << angle << " G = (" << RAMPAGX << ", " << RAMPAGY << "). Center = (" << CENTROX << ", " << CENTROY << ")" << endl; 
  //printf ("rampa generada. angle=%.2f. G=(%.2f,%.2f). Centro=(%.2f,%.2f)\n", angle, RAMPAGX, RAMPAGY, CENTROX, CENTROY);
  
  for (int y = 0; y < ramp->DimY(); y++) {
    for (int x = 0; x < ramp->DimX(); x++) {
      s  = 0;
      s += insideRamp ((float)x-0.5, (float)y-0.5, RAMPAGX, RAMPAGY);
      s += insideRamp ((float)x+0.5, (float)y-0.5, RAMPAGX, RAMPAGY);
      s += insideRamp ((float)x+0.5, (float)y+0.5, RAMPAGX, RAMPAGY);
      s += insideRamp ((float)x-0.5, (float)y+0.5, RAMPAGX, RAMPAGY);
      
      ramp->BufferPos(x, y, z);
      switch (s) {
        case 0:
          ramp->FixeValeur(B);
          break;
        
        case 4:
          ramp->FixeValeur(A);
          break;

        default:
          if (opt) { // si es perfecto....
                        // lo generamos analíticamente usando la ecuación
            if (fabs(RAMPAGX) < fabs(RAMPAGY)) 
              ramp->FixeValeur (CalculaColorPixel (RAMPAGX, fabs(RAMPAGY), CENTROY-RAMPAGX/RAMPAGY*(x-CENTROX)-y, (RAMPAGY>0)?A:B, (RAMPAGY>0)?B:A));	
            else
              ramp->FixeValeur (CalculaColorPixel (RAMPAGY, fabs(RAMPAGX), CENTROX+RAMPAGY/RAMPAGX*(CENTROY-y)-x, (RAMPAGX>0)?A:B, (RAMPAGX>0)?B:A));
          }
          else {
            ss=0;
            // hay que contar los subpixels
            for (int j = 0; j < meshing; j++) for (int i = 0; i < meshing; i++) 
              ss += insideRamp ((float)x-0.5+i/(m-1), (float)y-0.5+j/(m-1), RAMPAGX, RAMPAGY);
            ramp->FixeValeur (B + (A-B)*ss / m2);
          }
          break;
      }
    }
  }
  
  
  // iteramos para cada pixel
  /*for (y=0,n=0; y<100; y++) for (x=0; x<100; x++,n++,s=0) {
    s += insideRamp ((float)x-0.5, (float)y-0.5, RAMPAGX, RAMPAGY);
    s += insideRamp ((float)x+0.5, (float)y-0.5, RAMPAGX, RAMPAGY);
    s += insideRamp ((float)x+0.5, (float)y+0.5, RAMPAGX, RAMPAGY);
    s += insideRamp ((float)x-0.5, (float)y+0.5, RAMPAGX, RAMPAGY);
    switch (s) {
      case 0: gw->RIMdata[n] = B;
        break;
        
      case 4: gw->RIMdata[n] = A;
        break;
        
      default: if (opt[0]) { // si es perfecto....
                             // lo generamos analíticamente usando la ecuación
				float CalculaColorPixel (double gx, double gy, 
                                 double d, double A, double B);
				if (fabs(RAMPAGX)<fabs(RAMPAGY)) 
				 	gw->RIMdata[n] = CalculaColorPixel (
                                              RAMPAGX, fabs(RAMPAGY), 
                                              CENTROY-RAMPAGX/RAMPAGY*(x-CENTROX)-y, 
                                              (RAMPAGY>0)?A:B, (RAMPAGY>0)?B:A);	
        else
				 	gw->RIMdata[n] = CalculaColorPixel (
                                              RAMPAGY, fabs(RAMPAGX), 
                                              CENTROX+RAMPAGY/RAMPAGX*(CENTROY-y)-x, 
                                              (RAMPAGX>0)?A:B, (RAMPAGX>0)?B:A);			 
      } else {
        // hay que contar los subpixels
				for (j=0,ss=0; j<meshing; j++) for (i=0; i<meshing; i++) 
					ss += DentroRampa ((float)x-0.5+i/(m-1),
                             (float)y-0.5+j/(m-1),
                             RAMPAGX, RAMPAGY);
			 	gw->RIMdata[n] = B + (A-B)*ss / m2;
      }
    }
  }*/
  
  //ShowImage (gw);
  return ramp;
}

