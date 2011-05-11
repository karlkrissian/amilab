
#ifndef _Curvatures_h_
#define _Curvatures_h_

#include "inrimage.hpp"

// forward declaration
class Curvatures;

class CurvaturesFunctor
{
  private:
    Curvatures* _curv;
  public:
    CurvaturesFunctor(Curvatures* curv)
    {
      _curv = curv;
    }
    void operator()(float gradient[3], float hessien[3][3], void* data);
};

class Curvatures 
{

  // make as friend to access private images
  friend class CurvaturesFunctor;
  
  private:
    InrImage::ptr        im_graddir;
    InrImage::ptr        im_gradnorm;

    InrImage::ptr        im_maxcurv;
    InrImage::ptr        im_mincurv;

    InrImage::ptr        imdir_maxcurv;
    InrImage::ptr        imdir_mincurv;

    void EstimeCourbures( float gradient[3], float hessien[3][3], void* data);

    ///  true to compute the directions, false otherwise
    bool compute_directions;

public:
    ///
    void  ComputeCurvatures( InrImage* image_initiale,
          float sigma);

    void set_compute_directions( bool b) { compute_directions = b; }
    bool get_compute_directions( ) { return compute_directions; }
    
    InrImage::ptr GetGradDir()    { return im_graddir;    }
    InrImage::ptr GetGradNorm()   { return im_gradnorm;   }
    InrImage::ptr GetMaxCurv()    { return im_maxcurv;    }
    InrImage::ptr GetMinCurv()    { return im_mincurv;    }
    InrImage::ptr GetMaxCurvDir() { return imdir_maxcurv; }
    InrImage::ptr GetMinCurvDir() { return imdir_mincurv; }
  
};

#endif
// _Curvatures_h_
