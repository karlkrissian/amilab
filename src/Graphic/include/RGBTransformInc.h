//
// C++ Interface: RGBTransformInc.h
// Description: RGB transformation to keep only one component R, G or B.
// Author: Luis Mª González Medina - Rubén Domínguez Falcón  <>, (C) 2011
// Copyright: See COPYING file that comes with this distribution
//

#ifndef _RGBTransformInc_h_
#define _RGBTransformInc_h_

#include "RGBTransformBase.h"
#include "DefineClass.hpp"

/**
 * @brief Add a increment (R,G and B) to each color.
 **/
class RGBTransformInc : public RGBTransformBase
{
  DEFINE_CLASS(RGBTransformInc);
   
  int R;
  int G;
  int B;

  public:
    RGBTransformInc() {
      R=G=B=0;
    }

    void SetR(int r)
    {
      if (r<-255) r=-255;
      if (r>255) r=255;
      R = r;
    }

    float GetR() { return R;}

    void SetG(int g)
    {
      if (g<-255) G=-255;
      if (g>255) G=255;
      G = g;
    }

    float GetG() { return G;}

    void SetB(int b)
    {
      if (b<-255) B=-255;
      if (b>255) B=255;
      B = b;
    }

    float GetB() { return B;}
    
    void Apply(unsigned char r, unsigned char g, unsigned char b, 
               unsigned char & R1, unsigned char & G1, unsigned char& B1);
};


#endif //  _RGBTransformInc_h_
