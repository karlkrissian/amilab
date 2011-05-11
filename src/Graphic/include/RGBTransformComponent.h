//
// C++ Interface: RGBTransformComponent.h
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef _RGBTransformComponent_h_
#define _RGBTransformComponent_h_

#include "RGBTransformBase.h"
#include "DefineClass.hpp"

class RGBTransformComponent : public RGBTransformBase
{
  DEFINE_CLASS(RGBTransformComponent)
  
  /// component number (0,1,or 2)
  int component; 

  public:
    RGBTransformComponent(): component(0) {}
    void Setcomponent(int c)
    {
      if (c<0) c=0;
      if (c>2) c=2;
      component = c;
    }

    int Getcomponent() { return component;}
    
    void Apply(unsigned char R, unsigned char G, unsigned char B, unsigned char & R1, unsigned char & G1, unsigned char& B1)
    {
      if (component==0) R1=G1=B1=R;
      if (component==1) R1=G1=B1=G;
      if (component==2) R1=G1=B1=B;
    }
};


#endif //  _RGBTransformComponent_h_
