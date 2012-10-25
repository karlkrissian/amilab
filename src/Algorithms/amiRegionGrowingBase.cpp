//
// C++ Implementation: RegionGrowingBase
//
// Description: 
//
//
// Author: Karl Krissian  <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "amiRegionGrowingBase.h"
#include <iostream>

namespace ami {

  RegionGrowingBase::RegionGrowingBase(InrImage::ptr& input, InrImage::ptr& init): _input(input)
  {
    include_border=true;
    
    double val = 0;

    // Create _state image and initialize it
    _state = InrImage::ptr(new InrImage(WT_UNSIGNED_CHAR,"state.ami.gz",_input.get()));

    _state->InitImage(RegionGrowingBase::UNPROCESSED);
    stateit = boost::dynamic_pointer_cast<InrImageIterator<unsigned char> >(
        _state->CreateIterator());

    initit  = init  ->CreateIterator();
    // The images should have the same dimensions
    int x,y,z;
    
    for(z=0;z<_input->DimZ();z++)
    for(y=0;y<_input->DimY();y++)
    {
      stateit->BufferPos(0,y,z);
      initit ->BufferPos(0,y,z);
      for(x=0;x<_input->DimX();x++)
      {
        val = initit->GetDoubleValue();
        if (val>0.5) {
          stateit->SetDoubleValue(RegionGrowingBase::INSIDE);
          // add the point to the growing region
          //_growinglist.push_back(PointType(x,y,z));
          if (_cost.get()) 
            _growinglist += PointType(x,y,z,(*_cost)(x,y,z));
          else 
            _growinglist += PointType(x,y,z);
        }
        ++(*initit);
        ++(*stateit);
      }
    }

  }


  bool RegionGrowingBase::ProcessNextPoint()
  {
    int x0;
    int y0;
    int z0;
    int x;
    int y;
    int z;

    if (_growinglist.Size()==0) return false;

    PointType point = _growinglist.GetMin();
    //_growinglist.pop_front();
    //cout << boost::format("processing (%1%,%2%,%3%) from the list") % point.X() % point.Y() % point.Z() << std::endl;
    // 1. check if the point is accepted
    x0 = point.X();
    y0 = point.Y();
    z0 = point.Z();
    stateit->BufferPos(x0,y0,z0);
    bool accept = (stateit->GetValue()==RegionGrowingBase::INSIDE);
    if (!accept) {
      accept = AcceptPoint(point);
      if (!include_border)
        accept = accept && _input->CoordOK(x0,y0,z0);

      if (accept) 
        // set the point inside
        // should avoid to use buffer pos
        stateit->SetValue(RegionGrowingBase::INSIDE);
      else
        stateit->SetValue(RegionGrowingBase::PROCESSED);
    }
    // 2. potentionally add the neighboors to the growing list
      
    int maxx = _input->DimX()-1;
    int maxy = _input->DimY()-1;
    int maxz = _input->DimZ()-1;

    if (accept) {
    
      if (include_border) {
        #define MACRO_MAX(a,b) ((a)>(b)?(a):(b))
        #define MACRO_MIN(a,b) ((a)<(b)?(a):(b))

        for (z=MACRO_MAX(0,z0-1);z<=MACRO_MIN(z0+1,maxz);z++) 
        for (y=MACRO_MAX(0,y0-1);y<=MACRO_MIN(y0+1,maxy);y++)
        for (x=MACRO_MAX(0,x0-1);x<=MACRO_MIN(x0+1,maxx);x++)
        {
          if ((x!=x0)||(y!=y0)||(z!=z0))
          {
            if ((*_state)(x,y,z)==UNPROCESSED) {
              // Add point to the list
              if (_cost.get()) 
                _growinglist += PointType(x,y,z,(*_cost)(x,y,z));
              else 
                _growinglist += PointType(x,y,z);
              //cout << boost::format("adding (%1%,%2%,%3%) to the list") % x % y % z << std::endl;
              // change the state of the point
              stateit->BufferPos(x,y,z);
              stateit->SetValue(static_cast<unsigned char>(TOBEPROCESSED));
            } // end if
          } // end if
        } // end for x,y,z
      } else {
        for (z=z0-1;z<=z0+1;z++) 
        for (y=y0-1;y<=y0+1;y++) 
        {
          stateit->BufferPos(x0-1,y,z);
          for (x=x0-1;x<=x0+1;x++,(*stateit)++)
          {
            if (stateit->GetValue()==UNPROCESSED) {
              // Add point to the list
              if (_cost.get()) 
                _growinglist += PointType(x,y,z,(*_cost)(x,y,z));
              else 
                _growinglist += PointType(x,y,z);
              //cout << boost::format("adding (%1%,%2%,%3%) to the list") % x % y % z << std::endl;
              // change the state of the point
              stateit->SetValue(static_cast<unsigned char>(TOBEPROCESSED));
            } // end if
          } // end for x
        } // end for y,z
      }
    } // end if accept
    return true;
  }

  void RegionGrowingBase::Evolve()
  {
    int i=0;
    while(_growinglist.Size()>0) {
      if (i%10000==0) 
        std::cout << " Size of growing list = " << _growinglist.Size() 
                  << std::endl;
      ProcessNextPoint();
      i++;
    }
  }

}
