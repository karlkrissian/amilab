
#ifndef _CircleBoundaries3D_h_
#define _CircleBoundaries3D_h_

#include "inrimage.hpp"
#include "reponse_cercle.hpp"

class CircleBoundaries3D
{
 
  protected:
    // Parameters
    InrImage* vep0;
    InrImage* vep1;
    float     radius;
    InrImage* mask;
    /// Class that deal with the circle integration
    CalculRepCercle* rep;
    
  public:
    /// Constructor
    CircleBoundaries3D()
    {
      vep0=vep1=mask=NULL;
      rep = NULL;
    }
    
    
    void SetBoundaryComputationClass( CalculRepCercle* crc)
    {
      rep = crc;
    }
    
    void SetOrientations( InrImage* v0, InrImage* v1)
    {
      vep0 = v0;
      vep1 = v1;
    }
  
    void SetMask( InrImage* m)
    {
      mask = m;
    }
    
    void Execute(InrImage* res);

};

#endif
// _CircleBoundaries3D_h_
