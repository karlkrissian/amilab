#include "RGBTransformHSV.h"
#include "stdio.h"


float MIN (float a, float b, float c){
  if (a<b)
    if (a<c)
      return a;
    else
      return c;
  else
    if (b<c)
      return b;
    else
      return c;
}

float MAX (float a, float b, float c){
  if (a>c)
    if (a>b)
      return a;
    else
      return b;
  else
    if (c>b)
      return c;
    else
      return b;
}



// r,g,b values are from 0 to 1
// h = [0,360], s = [0,1], v = [0,1]
//		if s == 0, then h = 0 (undefined)

void rgb2hsv ( unsigned char R, unsigned char G, unsigned char B, float &h, float &s, float &v )
{
  float min, max, delta;
  float r,g,b;
  r= (float)R/(float)255;
  g= (float)G/(float)255;
  b= (float)B/(float)255;

  min = MIN( r, g, b );
  max = MAX( r, g, b );
  v = max;		// v

  delta = max - min;

  if( max != 0 )
    s = delta / max;		// s
  else {
    // r = g = b = 0		// s = 0, v is undefined
    s = 0;
    h = 0; //h=-1
    return;
  }

  if( r == max )
    h = ( g - b ) / delta;		// between yellow & magenta
  else if( g == max )
    h = 2 + ( b - r ) / delta;	// between cyan & yellow
  else
    h = 4 + ( r - g ) / delta;	// between magenta & cyan

  h *= 60;				// degrees
  if( h < 0 )
    h += 360;
}


void hsv2rgb ( unsigned char &R, unsigned char &G, unsigned char &B, float h, float s, float v )
{
  int i;
  float f, p, q, t, r, g ,b;

  if( s == 0 ) {
    // achromatic (grey)
    r = g = b = v;
    R=r*255;
    G=g*255;
    B=b*255;
    return;
  }

  h /= 60;			// sector 0 to 5
  i =  h ;
  f = h - i;			// factorial part of h
  p = v * ( 1 - s );
  q = v * ( 1 - s * f );
  t = v * ( 1 - s * ( 1 - f ) );

  switch( i ) {
    case 0:
      r = v;
      g = t;
      b = p;
      break;
    case 1:
      r = q;
      g = v;
      b = p;
      break;
    case 2:
      r = p;
      g = v;
      b = t;
      break;
    case 3:
      r = p;
      g = q;
      b = v;
      break;
    case 4:
      r = t;
      g = p;
      b = v;
      break;
    default:		// case 5:
      r = v;
      g = p;
      b = q;
      break;
  }

  R=r*255;
  G=g*255;
  B=b*255;

}


void RGBTransformHSV::Apply(unsigned char R, unsigned char G, unsigned char B, 
  unsigned char & R1, unsigned char & G1, unsigned char& B1)
{
  float h, s,v;	
  rgb2hsv(R,G,B,h,s,v);

  h+=H;
  s*=  1.0 + S/100.0;
  v*=  1.0 + V/100.0;
  if (s<0) s=0;
        if (s>1) s=1;
  if (v<0) v=0;
        if (v>1) v=1;
  if (h<0) h+=360;
        if (h>360) h-=360;

  hsv2rgb(R1,G1,B1,h,s,v);
  //G1=G;
  //B1=B;
}

