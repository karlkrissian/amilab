#include "RGBTransformInc.h"


void RGBTransformInc::Apply(unsigned char r, unsigned char g, unsigned char b, 
  unsigned char & R1, unsigned char & G1, unsigned char& B1)
{  
  int RF,GF,BF;
  
  RF=R+(int)r;
  if (RF>255)
    RF=255;
  if (RF<0)
    RF=0;
  GF=G+(int)g;
  if (GF>255)
    GF=255;
  if (GF<0)
    GF=0;
  BF=B+(int)b;  
  if (BF>255)
    BF=255;
  if (BF<0)
    BF=0;

  R1=RF;
  G1=GF;
  B1=BF;
}


