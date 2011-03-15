
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
    /// Point Spread Function of the system in pixels for each XYZ coordinate
    double    PSF[3];

  public:
    /// Constructor
    Gradient( InrImage* in, float sig=1, bool norm=false)
    {
      input=in;
      sigma=sig;
      normalize = norm;
      PSF[0] = PSF[1] = PSF[2] = 0;
    }

    /**
     * Sets the Gaussian point spread function standard deviations in voxels for each direction
     * @param psfx Gaussian standard deviation in X direction
     * @param psfy Gaussian standard deviation in Y direction
     * @param psfz Gaussian standard deviation in Z direction
    */
    void SetPSF(const double& psfx, const double& psfy, const double& psfz)
    {
      PSF[0] = psfx;
      PSF[1] = psfy;
      PSF[2] = psfz;
    }

    InrImage::ptr Execute();

};


#endif 
// _Gradient_h_
