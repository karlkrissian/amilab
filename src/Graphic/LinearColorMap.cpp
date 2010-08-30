//
// C++ Interface: LinearColorMap
//
// Description: Colormap with interpolation between points
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//


#include "LinearColorMap.h"

InrImage::ptr LinearColorMap::CreateColormapImage()
{
    InrImage::ptr res(new InrImage(256,1,1,WT_RGB));

    // need at least 2 points
    if (size()<2)  return InrImage::ptr();

    // sort points
    sort();
    
    // 
    float pmin = GetPoint(0)       .GetPosition();
    float pmax = GetPoint(size()-1).GetPosition();

    // loop over the points and interpolate
    InrImageIteratorBase::ptr it = res->CreateIterator();

    // not optimized, but should be ok
    for(int i=0; i<256; i++) {
      it->BufferPos(i,0,0);
      wxColour c = InterpolateColour(pmin+(pmax-pmin)/255.0*i);
      it->SetDoubleValue(0,c.Red());
      it->SetDoubleValue(1,c.Green());
      it->SetDoubleValue(2,c.Blue());
    }

    return res;
}
