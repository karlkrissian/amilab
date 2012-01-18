//
// C++ Interface: amiIntensityBasedRegionGrowing
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _amiIntensityBasedRegionGrowing_h_
#define _amiIntensityBasedRegionGrowing_h_

#if defined(WIN32)
  #ifndef NOMINMAX
    #define NOMINMAX
  #endif
  #include <limits>
  #include <windows.h>
#else
  #include <limits>
#endif

#include "inrimage.hpp"
#include "DefineClass.hpp"
#include <list>

#include "amiRegionGrowingBase.h"

namespace ami {

  /**
  * Intensity based region growing, set the allowing intensity range
  **/
  class IntensityBasedRegionGrowing : public RegionGrowingBase
  {
    DEFINE_CLASS(IntensityBasedRegionGrowing);
  protected:
    /// minimal allowed intensity, lowest double value by default
    double min_intensity;
    /// maximal allowed intensity, highest double value by default
    double max_intensity;
  public:
    IntensityBasedRegionGrowing(InrImage::ptr& input, InrImage::ptr& init)
      :RegionGrowingBase(input,init) 
    {
      min_intensity = std::numeric_limits<double>::min();
      max_intensity = std::numeric_limits<double>::max();
    }

    void SetMin(double min) { min_intensity = min; }
    void SetMax(double max) { max_intensity = max; }

    virtual bool AcceptPoint( PointType& pt) 
    {
      double val =  (*_input)(pt.X(),pt.Y(),pt.Z());
      return (val>=min_intensity)&&(val<=max_intensity);
    }

  };
}

#endif // _amiIntensityBasedRegionGrowing_h_
