//
// C++ Interface: RGBTransformBase.h
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef _RGBTransformBase_h_
#define _RGBTransformBase_h_

#include "DefineClass.hpp"

class RGBTransformBase
{
  DEFINE_CLASS(RGBTransformBase)
  
  public:
    virtual void Apply(unsigned char R, unsigned char G, unsigned char B, unsigned char & R1, unsigned char & G1, unsigned char& B1) = 0;
};


#endif //  _RGBTransformBase_h_
