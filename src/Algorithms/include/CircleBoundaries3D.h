
#ifndef _CircleBoundaries3D_h_
#define _CircleBoundaries3D_h_

#include "inrimage.hpp"
#include "CalculRepCercle.hpp"
#include "amiImageToImageFilter.h"

/** Computes the responses to the boundaries integration over a circle
 *  for each voxel within a given mask.
 * The circle plane is defined by two vectors using two vector field images.
 * The parameters for the integration over the circle are defined in the CalculRepCercle object.
 */

class CircleBoundaries3D : public ami::ImageToImageFilter 
{
 
  protected:
    // Parameters
    /** \addtogroup CircleOrientation
      *  @{
      */
    /// First Vector field to define the circle plane
    InrImage* vep0;
    /// Second Vector field to define the circle plane
    InrImage* vep1;
    /** @} */
    /// Mask scalar image, the integration is computed only for voxels with intensity
    /// higher than 0.5.
    InrImage* mask;
    /// Class that deal with the circle integration
    CalculRepCercle* rep;
    
    InrImage* output;
    
  public:
    /// Constructor, sets pointers to NULL
    CircleBoundaries3D()
    {
      vep0=vep1=mask=output=NULL;
      rep = NULL;
    }
    
    /// Sets the boundary computation object, of type CalculRepCercle
    void SetBoundaryComputationClass( CalculRepCercle* crc)
    {
      rep = crc;
    }
    
    /// Sets the circle plane orientations with 2 vector field images
    void SetOrientations( InrImage* v0, InrImage* v1)
    {
      vep0 = v0;
      vep1 = v1;
    }
  
    /// Sets the mask image
    void SetMask( InrImage* m)
    {
      mask = m;
    }
    
    /**
    * Process part of the image
    * @param threadid 
    */
    void Process( int threadid = 0);

    /// Execute the computation, res is the resulting image.
    void Execute(InrImage* res);

    void Execute_old(InrImage* res);

};

#endif
// _CircleBoundaries3D_h_

