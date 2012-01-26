//
// C++ Interface: amiFieldOrientationRegionGrowing
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _amiFieldOrientationRegionGrowing_h_
#define _amiFieldOrientationRegionGrowing_h_

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
#include <iostream>

#include "amiRegionGrowingBase.h"

namespace ami {

  /**
  * Intensity based region growing, set the allowing intensity range
  **/
  class FieldOrientationRegionGrowing : public RegionGrowingBase
  {
    DEFINE_CLASS(FieldOrientationRegionGrowing);
  protected:
    /// minimal allowed intensity, lowest double value by default
    double min_intensity;
    /// maximal allowed intensity, highest double value by default
    double max_intensity;
    
    /// Vector field image 
    InrImage::ptr field;
    
    /// Orientation Image, should be 1 or -1 if the reorientation
    /// succeeds
    InrImage::ptr orientation;
    
  public:
    FieldOrientationRegionGrowing(InrImage::ptr& input, InrImage::ptr& init)
      :RegionGrowingBase(input,init) 
    {
      min_intensity = std::numeric_limits<double>::min();
      max_intensity = std::numeric_limits<double>::max();
      orientation = InrImage::ptr(new InrImage(WT_SIGNED_SHORT
                                               ,"orient.ami.gz"
                                               ,input.get()
                                              ));
      orientation->InitImage(0);
      // set orientation to one for all elements accepted
      // ideally one should start with only 1 pixel/voxel
      // we should check the conherent orientation inside the already
      // accepted pixels(/voxels)
      if (_growinglist.Size()>0) {
        for(int i=1; i<=_growinglist.Size();i++) {
          int x = _growinglist[i].X();
          int y = _growinglist[i].Y();
          int z = _growinglist[i].Z();
          std::cout << "setting orientation to 1 at " <<  x << ", " 
                    << y << ", " << z << std::endl;
          orientation->BufferPos(_growinglist[i].X(),
                                 _growinglist[i].Y(),
                                 _growinglist[i].Z());
          orientation->FixeValeur(1);
        }
        /*
        std::list<PointType>::iterator list_it;
        for(list_it = _growinglist.begin(); 
            list_it != _growinglist.end(); 
            list_it++) {
          
          int x = list_it->X();
          int y = list_it->Y();
          int z = list_it->Z();
          std::cout << "setting orientation to 1 at " <<  x << ", " << y << ", " << z << std::endl;
          orientation->BufferPos(list_it->X(),list_it->Y(),list_it->Z());
          orientation->FixeValeur(1);
        }
        */
      } else 
        std::cerr << "Empty growing list in constructor " << std::endl;
    }

    void SetMin(double min) { min_intensity = min; }
    void SetMax(double max) { max_intensity = max; }
    
    void SetVectorFieldImage(InrImage::ptr f) {
      // only accept 3 components vector fields for the moment
      // should make it more general
      if (  (f->DimX()==_input->DimX())
          &&(f->DimY()==_input->DimY())
          &&(f->DimZ()==_input->DimZ())
          &&(f->GetVDim()==3)
         )
        field = f;
    }

    InrImage::ptr GetOrientation() {
      return orientation;
    }

    virtual bool AcceptPoint( PointType& pt) 
    {
      
      double val =  (*_input)(pt.X(),pt.Y(),pt.Z());
      bool accept =(val>=min_intensity)&&(val<=max_intensity);
      double sum_pos = 0;
      double sum_neg = 0;
      
      if ((accept)&&(field.get())) {
        // check for neighbors to fill the orientation image
        int x0 = pt.X();
        int y0 = pt.Y();
        int z0 = pt.Z();
        double vx0 = (*field)(x0,y0,z0,0);
        double vy0 = (*field)(x0,y0,z0,1);
        double vz0 = (*field)(x0,y0,z0,2);
      
        int pos_orient=0;
        int neg_orient=0;
        for (int z=z0-1;z<=z0+1;z++)
        for (int y=y0-1;y<=y0+1;y++)
        for (int x=x0-1;x<=x0+1;x++)
        {
          if ((x!=x0)||(y!=y0)||(z!=z0))
          {
            if (_input->CoordOK(x,y,z)) {
              if (((*_state)(x,y,z)==INSIDE)&&((*orientation)(x,y,z)!=0)) {
                // Compute the sign of the scalar product
                // between the vector of the neighbor and the vector at the 
                // current point
                double vx = (*field)(x,y,z,0);
                double vy = (*field)(x,y,z,1);
                double vz = (*field)(x,y,z,2);
                double sp = vx0*vx+vy0*vy+vz0*vz;
                double orient = sp*(*orientation)(x,y,z);
                if (orient>0) {
                  pos_orient++;
                  sum_pos += orient;
                } 
                if (orient<0) {
                  neg_orient++;
                  sum_neg += -orient;
                } 
              } // end if
            } // end if
          } // end if
        } // end for x,y,z
          std::cerr << " At "
              << x0 << ", " << y0 << ", " << z0 
              << ": " << "+:" << pos_orient << " -:" << neg_orient
              << std::endl;
        if ((pos_orient>0)&&(neg_orient==0)) {
          orientation->BufferPos(x0,y0,z0);
          orientation->FixeValeur(1);
        } else 
        if ((neg_orient>0)&&(pos_orient==0)) {
          orientation->BufferPos(x0,y0,z0);
          orientation->FixeValeur(-1);
        } else {
          std::cerr << "Incoherent orientations for voxel "
              << x0 << ", " << y0 << ", " << z0 << std::endl;
          std::cerr << "sum_pos" << sum_pos 
                    << ", sum_new" << sum_neg << std::endl; 
          if (sum_neg>sum_pos) {
            orientation->BufferPos(x0,y0,z0);
            orientation->FixeValeur(-1);
          } else {
            orientation->BufferPos(x0,y0,z0);
            orientation->FixeValeur(1);
          }
          if ((sum_pos<0.05)&&(sum_neg<0.05)) {
            std::cerr << "very low confidence !!!" << std::endl;
            // we set the point as processed and try to continue
            // with taking it into account
            _state->BufferPos(x0,y0,z0);
            _state->FixeValeur(RegionGrowingBase::PROCESSED);
          }
        }
      }
      return accept;
    }

  };  // end class
} // end namespace

#endif // _amiFieldOrientationRegionGrowing_h_
