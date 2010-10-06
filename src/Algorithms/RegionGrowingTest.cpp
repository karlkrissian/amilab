//
// C++ Implementation: RegionGrowingTest
//
// Description: 
//
//
// Author: Karl Krissian  <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "RegionGrowingTest.h"
#include <iostream>

RegionGrowingTest::RegionGrowingTest(InrImage::ptr& input, InrImage::ptr& init): _input(input)
{
  double val = 0;

  // Create _state image and initialize it
  _state = InrImage::ptr(new InrImage(WT_UNSIGNED_CHAR,"state.ami.gz",_input.get()));

  _state->InitImage(UNPROCESSED);
  stateit = _state->CreateIterator();
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
        stateit->SetDoubleValue(INSIDE);
        // add the point to the growing region
        _growinglist.push_back(PointType(x,y,z));
      }
      ++(*initit);
      ++(*stateit);
    }
  }

}


void RegionGrowingTest::ProcessNextPoint()
{
  PointType point = _growinglist.front();
  _growinglist.pop_front();
  //cout << boost::format("processing (%1%,%2%,%3%) from the list") % point.X() % point.Y() % point.Z() << std::endl;
  // 1. check if the point is accepted
  stateit->BufferPos(point.X(),point.Y(),point.Z());
  bool accept = AcceptPoint(point);
  if (accept) 
    // set the point inside
    // should avoid to use buffer pos
    stateit->SetDoubleValue(INSIDE);
  else
    stateit->SetDoubleValue(PROCESSED);
  // 2. potentionally add the neighboors to the growing list
  if (accept) {
    int x0 = point.X();
    int y0 = point.Y();
    int z0 = point.Z();
  
    for (int z=z0-1;z<=z0+1;z++)
    for (int y=y0-1;y<=y0+1;y++)
    for (int x=x0-1;x<=x0+1;x++)
    {
      if ((x!=x0)||(y!=y0)||(z!=z0))
      {
        if (_input->CoordOK(x,y,z)) {
          if ((*_state)(x,y,z)==UNPROCESSED) {
            // Add point to the list
            _growinglist.push_back(PointType(x,y,z));
            //cout << boost::format("adding (%1%,%2%,%3%) to the list") % x % y % z << std::endl;
            // change the state of the point
            stateit->BufferPos(x,y,z);
            stateit->SetDoubleValue(TOBEPROCESSED);
          } // end if
        } // end if
      } // end if
    } // end for x,y,z
  } // end if accept
}

void RegionGrowingTest::Evolve()
{
  int i=0;
  while(_growinglist.size()>0) {
    if (i%1000==0) 
      std::cout << " Size of growing list = " << _growinglist.size() << std::endl;
    ProcessNextPoint();
    i++;
  }
}

