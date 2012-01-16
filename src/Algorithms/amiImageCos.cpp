//
// C++ Implementation: ImageCos
//
// Description: 
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#include "amiImageCos.h"
#include "amiImageExtent.h"
#include "amilab_messages.h"
#include <iostream>

namespace ami {

template <class T>
void ImageCos::TemplateProcess( int threadid)
{
  // process using precomputed extent number threadid
//  int nt = params.GetNumberOfThreads();

  extenttype extent = extents[threadid];
  int x,y,z;
  InrImage::ptr in = params.GetInput();

  int incx,incy,incz;
  in->GetBufferIncrements(incx,incy,incz);
  T* in_data = (T*) in->GetData();
  for(z=extent.GetMin(2);z<=extent.GetMax(2); z++)
  for(y=extent.GetMin(1);y<=extent.GetMax(1); y++)
  {
    T* in_data1 = in_data + z*incz + y*incy +
                        extent.GetMin(0)*incx;
    for(x=extent.GetMin(0);x<=extent.GetMax(0); x++)
    {
      *in_data1 = cos((double)*in_data1);
      in_data1++;
    }
  }

}


void ImageCos::Process( int threadid)
{
  // process using precomputed extent number threadid
  InrImage::ptr in = params.GetInput();

  switch (in->GetFormat()) {
    case WT_UNSIGNED_CHAR:  TemplateProcess<unsigned char>  (threadid); break;
    case WT_UNSIGNED_SHORT: TemplateProcess<unsigned short> (threadid); break;
    case WT_SIGNED_SHORT:   TemplateProcess<short>          (threadid); break;
    case WT_UNSIGNED_INT:   TemplateProcess<unsigned int>   (threadid); break;
    case WT_SIGNED_INT:     TemplateProcess<int>            (threadid); break;
    case WT_FLOAT:          TemplateProcess<float>          (threadid); break;
    case WT_DOUBLE:         TemplateProcess<double>         (threadid); break;
    default: CLASS_ERROR((boost::format(" format %1% not available")%in->GetFormat()).str().c_str());
  }

}

} // end namespace ami
