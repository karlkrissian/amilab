
#ifndef _Gradient_h_
#define _Gradient_h_

#include "inrimage.hpp"

class Gradient
{
  
  protected:
    // Parameters
    InrImage* input;
    float     sigma;
    bool      normalize;

  public:
    /// Constructor
    Gradient( InrImage* in, float sig=1, bool norm=false)
    {
      input=in;
      sigma=sig;
      normalize = norm;
    }


    InrImage::ptr Execute();

};


#endif 
// _Gradient_h_
