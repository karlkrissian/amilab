//
// C++ Interface: RegionGrowingBase
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _RegionGrowingBase_h_
#define _RegionGrowingBase_h_


#include "inrimage.hpp"
#include "DefineClass.hpp"
#include <list>


namespace ami 
{


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
  class RegionGrowingBase
  {
    DEFINE_CLASS(RegionGrowingBase);

  protected:
    InrImage::ptr       _input;
    InrImage::ptr       _state;

    typedef RG_point<unsigned short> PointType;
    std::list<PointType> _growinglist;

    InrImageIteratorBase::ptr stateit;
    InrImageIteratorBase::ptr initit;

    enum point_state {
       UNPROCESSED   =0
      ,TOBEPROCESSED =1
      ,INSIDE        =2
      ,PROCESSED     =3
    };

  public:

    RegionGrowingBase(InrImage::ptr& input, InrImage::ptr& init);

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
}

#endif // _RegionGrowingBase_h_
