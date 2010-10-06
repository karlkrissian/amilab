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

#include "ImageCos.h"
#include "imageextent.h"
#include "amilab_messages.h"
#include <iostream>

void ImageCos::Init()
{
  
  InrImage::ptr in = params.GetInput();
  int nt = params.GetNumberOfThreads();

  if (in.get()) {
    extenttype extent(in.get());
#define SPLIT_Z_FIRST
#ifdef SPLIT_Z_FIRST
    // Set which dimension to split
    int splitaxis=2;
    while ( (extent.GetSize(splitaxis)<nt)&&
            (splitaxis>=0))
      splitaxis--;
#else
    // Set which dimension to split
    int splitaxis=0;
    while ( (extent.GetSize(splitaxis)<nt)&&
            (splitaxis<=2))
      splitaxis++;
#endif

    if (extent.GetSize(splitaxis)<nt) {
      // Change the number of threads to the bigger axis size
      splitaxis = 2;
      if (extent.GetSize(splitaxis)<extent.GetSize(1)) 
        splitaxis = 1;
      if (extent.GetSize(splitaxis)<extent.GetSize(0)) 
        splitaxis = 0;
      params.SetNumberOfThreads(extent.GetSize(splitaxis));
    }

    int axis_size   = extent.GetSize(splitaxis);
    double thread_size = ((double) axis_size)/nt;
    for(int i=0;i<nt;i++) {
      int extmin = round(i*thread_size);
      int extmax = round((i+1)*thread_size-1);
      extent.SetMinMax(splitaxis,extmin,extmax);
      extents.push_back(extent);
    }
  }
}

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
    default: CLASS_ERROR(boost::format(" format %1% not available")%in->GetFormat());
  }

}
