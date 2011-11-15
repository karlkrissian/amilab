//
// C++ Interface: RGBTransformGamma.h
// Description: Apply Gamma correction to the image.
// Author: Luis Mª González Medina - Rubén Domínguez Falcón  <>, (C) 2011
// Copyright: See COPYING file that comes with this distribution
//

#ifndef _RGBTransform003_h_
#define _RGBTransform003_h_

#include "RGBTransformBase.h"
#include "DefineClass.hpp"

/**
 * @brief Apply Gamma transform (correction) to the image intensity.
 *  Gamma is limiting within the range [0.1,10].
 **/
class RGBTransformGamma : public RGBTransformBase
{
  DEFINE_CLASS(RGBTransformGamma);
   
  float gamma;

  public:
    RGBTransformGamma() {
	gamma=1.0;
    }


    void Setgamma(float g)
    {
      if (g<=0) g=0.1;
      if (g>10) g=10;
      gamma = g;
    }

    float Getgamma() { return gamma;}

    
    void Apply(unsigned char R, unsigned char G, unsigned char B, 
               unsigned char & R1, unsigned char & G1, unsigned char& B1);
};


#endif //  _RGBTransformGamma_h_
