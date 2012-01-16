//
// C++ Implementation: ImageAddScalar
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

#include "amiImageAddScalar.h"
#include "amiImageExtent.h"
#include "InrImageIteratorBase.h"
#include "InrImageIterator.h"
#include "amilab_messages.h"

namespace ami {

template <class T>
void ImageAddScalar::TemplateProcess( int threadid)
{

  CLASS_MESSAGE((boost::format("mode = %1%") % _mode).str().c_str());

//  int nt = params.GetNumberOfThreads();
  extenttype extent = extents[threadid];
  int x,y,z;
  InrImage::ptr in = params.GetInput();

  if (_mode == 1) {
   std::cout << "version 1" << std::endl;
    // Version 1
    InrImageIteratorBase::ptr iter = in->CreateIterator();
    InrImageIterator<T>* iter1 = (InrImageIterator<T>*) iter.get();

    for(z=extent.GetMin(2);z<=extent.GetMax(2); z++)
    for(y=extent.GetMin(1);y<=extent.GetMax(1); y++)
    {
      iter1->BufferPos(extent.GetMin(0),y,z);
      iter1->SetEnd(extent.GetSize(0));
      while (iter1->NotAtEnd())
      {
        iter1->AddValue(scalar);
        iter1->IncScalarBufferFast();
      }
    }
  }

  // Version 2
  if (_mode==2) {
   std::cout << "version 2" << std::endl;
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
        //*in_data1 = (sin(*in_data1)+scalar)/2.3+10.3;
        *in_data1 += scalar;
        in_data1++;
      }
    }
  }
}


void ImageAddScalar::Process( int threadid)
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
