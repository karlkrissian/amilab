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
#include "InrImageIterator.h"

//#include <list>

// use minheap instead of list
#include "MinHeap.hpp"


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
    double value;

  public:
    RG_point() 
    {
      pixelpos[0] = pixelpos[1] = pixelpos[2] = value = 0;
    }
    RG_point(const T& x,const T& y, const T& z, const double& val=0) 
    {
      pixelpos[0] = x;
      pixelpos[1] = y;
      pixelpos[2] = z;
      value = val;
    }

    T& X() { return pixelpos[0]; }
    T& Y() { return pixelpos[1]; }
    T& Z() { return pixelpos[2]; }
    double & Value() { return value; }
    
    RG_point<T>& operator=(const RG_point<T>& p)
    {
        pixelpos[0] = p.pixelpos[0];
        pixelpos[1] = p.pixelpos[1];
        pixelpos[2] = p.pixelpos[2];
        value = p.value;
        return *this;
    }

    friend inline int operator < ( const RG_point<T>& p1, 
                                   const RG_point<T>& p2)
    {
      return (p1.value < p2.value);
    }

    friend inline int operator > ( const RG_point<T>& p1, 
                                   const RG_point<T>& p2)
    {
      return (p1.value > p2.value);
    }

    friend std::ostream& operator << (std::ostream&, const RG_point<T>& p)
    {
      // TODO
    }
    
    
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

    InrImage::ptr       _cost; 
    

    typedef RG_point<unsigned short> PointType;
    MinHeap<PointType> _growinglist;

    InrImageIterator<unsigned char>::ptr stateit;
    InrImageIteratorBase::ptr initit;

    bool include_border;
  public:
    enum point_state {
       UNPROCESSED   =0
      ,TOBEPROCESSED =1
      ,INSIDE        =2
      ,PROCESSED     =3
    };

    /**
     * @brief Region Growing constructor
     *
     * @param input Input image
     * @param init Initial image, points with intensity values > 0.5 will be
     * automatically added to the starting list.
     **/
    RegionGrowingBase(InrImage::ptr& input, InrImage::ptr& init);

    /**
     * @brief Enable/Disable propagation at the image border.
     *
     * @param  ...
     * @return void
     **/
    void SetIncludeBorder(bool ib) { include_border=ib; }
    bool GetIncludeBorder() { return include_border;}
    
    /**
     * can control growing preferences by asigning a cost (between 0 and 1)
     * to each point, the point with the minimal cost will be processed first
     */
    bool SetCostImage(InrImage::ptr c) {
      // only accept 3 components vector fields for the moment
      // should make it more general
      if (  (c->DimX()==_input->DimX())
          &&(c->DimY()==_input->DimY())
          &&(c->DimZ()==_input->DimZ())
         ) {
        _cost = c;
        return true;
      }
      else return false;
        
    }


    bool ProcessNextPoint();

    virtual bool AcceptPoint( PointType& pt) 
    {
      return (*_input)(pt.X(),pt.Y(),pt.Z())>100;
    }
    
    int GetListSize() { return _growinglist.Size(); }

    void Evolve();

    InrImage::ptr& GetStateImage() {
      return _state;
    }

  };
}

#endif // _RegionGrowingBase_h_
