
#pragma once
#ifndef _amiFind_h_
#define _amiFind_h_

#include "AlgorithmsConfigure.h"
#include <ostream>

#include "inrimage.hpp"
//#include "amiImageExtent.h"

//class InrImage;

//#include "vtkMinHeap.h"
//#include "style.hpp"
//#include "Coordonnees.hpp"

namespace ami {

class Find 
{
  class PositionClass
  {
  public:
    int _x,_y,_z; 
    PositionClass(int x, int y, int z) : _x(x), _y(y), _z(z)
    {}
  };
  
public:

  /** 
  * Find the positive points in input image and returns an 1D image of the
  * corresponding voxel positions.
  */  
  static InrImage::ptr Run(InrImage::ptr input);
  
  /**
   * @brief Changes voxels values at the positions given by the 1D positions
   * image of positions and by the 1D image of new values.
   *
   * @param input ...
   * @param positions ...
   * @param values ...
   * @return :ptr
   **/
  static InrImage::ptr ApplyValues(   InrImage::ptr input,
                                      InrImage::ptr positions,
                                      InrImage::ptr values);
};

} // end namespace ami

#endif // _amiFind_h_
