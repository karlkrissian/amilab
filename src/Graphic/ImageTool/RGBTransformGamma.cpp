#include "RGBTransformGamma.h"
#include <math.h>


void RGBTransformGamma::Apply(unsigned char R, unsigned char G, unsigned char B, 
  unsigned char & R1, unsigned char & G1, unsigned char& B1)
{  
  int RF,GF,BF;

  RF=255.0 * pow((((float)R)/255.0), (1.0/gamma));  
  if (RF>255)
    RF=255;
  if (RF<0)
    RF=0;
  GF=255.0 * pow((((float)G)/255.0), (1.0/gamma));
  if (GF>255)
    GF=255;
  if (GF<0)
    GF=0;
  BF=255.0 * pow((((float)B)/255.0), (1.0/gamma));
  if (BF>255)
    BF=255;
  if (BF<0)
    BF=0;

  R1=RF;
  G1=GF;
  B1=BF;

}

