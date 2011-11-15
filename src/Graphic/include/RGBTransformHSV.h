//
// C++ Interface: RGBTransform001.h
// Description: RGB transformation to keep only one component R, G or B.
// Author: Luis Mª González Medina - Rubén Domínguez Falcón  <>, (C) 2011
// Copyright: See COPYING file that comes with this distribution
//
#pragma once
#ifndef _RGBTransformHSV_h_
#define _RGBTransformHSV_h_

#include "RGBTransformBase.h"
#include "DefineClass.hpp"

/**
 * @brief Apply color transform in HSV space.
 **/
class RGBTransformHSV : public RGBTransformBase
{
  DEFINE_CLASS(RGBTransformHSV);
   
  float H;
  float S;
  float V;

  public:
    RGBTransformHSV() {
      H=0;
      S=V=0;
    }

    void SetH(float h)
    {
      if (h<-360) H=-360;
      if (h>360) H=360;
      H = h;
    }

    float GetH() { return H;}

    void SetS(float s)
    {
      S = s;
    }

    float GetS() { return S;}

    void SetV(float v)
    {
      V = v;
    }

    float GetV() { return V;}

    void Apply(unsigned char R, unsigned char G, unsigned char B, 
               unsigned char & R1, unsigned char & G1, unsigned char& B1);
};


#endif //  _RGBTransformHSV_h_
