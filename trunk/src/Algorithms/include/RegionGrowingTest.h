//
// C++ Interface: RegionGrowingTest
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _RegionGrowingTest_h_
#define _RegionGrowingTest_h_

#if defined(WIN32)
  #define NOMINMAX
  #include <limits>
  #include <windows.h>
#else
  #include <limits>
#endif

#include "inrimage.hpp"
#include "DefineClass.hpp"
#include <list>


#define UNPROCESSED   0
#define TOBEPROCESSED 1
#define INSIDE        2
#define PROCESSED     3


// use minheap ???

/**
 * voxel position for 2D/3D images
**/
template<class T>
class RG_point
{
protected:
  /// unsigned short is normally enough for each dimension
  T pixelpos[3];
public:
  RG_point() {}
  RG_point(const T& x,const T& y, const T& z) 
  {
    pixelpos[0] = x;
    pixelpos[1] = y;
    pixelpos[2] = z;
  }

  T& X() { return pixelpos[0]; }
  T& Y() { return pixelpos[1]; }
  T& Z() { return pixelpos[2]; }
};

/**
  An experimental class to region growing segmentation
**/
class RegionGrowingTest
{
  DEFINE_CLASS(RegionGrowingTest);

protected:
  InrImage::ptr       _input;
  InrImage::ptr       _state;

  typedef RG_point<unsigned short> PointType;
  std::list<PointType> _growinglist;

  InrImageIteratorBase::ptr stateit;
  InrImageIteratorBase::ptr initit;

public:

  RegionGrowingTest(InrImage::ptr& input, InrImage::ptr& init);

  void ProcessNextPoint();

  virtual bool AcceptPoint( PointType& pt) 
  {
    return (*_input)(pt.X(),pt.Y(),pt.Z())>100;
  }

  void Evolve();

  InrImage::ptr& GetStateImage() {
    return _state;
  }

};

/**
 * Intensity based region growing, set the allowing intensity range
 **/
class IntensityBasedRegionGrowing : public RegionGrowingTest
{
  DEFINE_CLASS(IntensityBasedRegionGrowing);
protected:
  /// minimal allowed intensity, lowest double value by default
  double min_intensity;
  /// maximal allowed intensity, highest double value by default
  double max_intensity;
public:
  IntensityBasedRegionGrowing(InrImage::ptr& input, InrImage::ptr& init)
    :RegionGrowingTest(input,init) 
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

#endif // _RegionGrowingTest_h_
