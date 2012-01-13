//
// C++ Interface: amiImageToImageFilter
//
// Description: 
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#pragma once
#ifndef _ami_ImageToImageFilter_h_
#define _ami_ImageToImageFilter_h_

#include "inrimage.hpp"
#include "imageextent.h"

#include <vector>



namespace ami {

// 
// ImageToImageFilterParam
// features needed:
//    - help
//    - gui
//
class ImageToImageFilterParam {

  int NumberOfThreads;
  InrImage::ptr input;
  ImageExtent<int> output_extent;

public:

  void SetNumberOfThreads(int n)
  {
    NumberOfThreads = n;
  }

  int  GetNumberOfThreads() 
  { 
    return NumberOfThreads;
  }

  void SetInput( InrImage::ptr& in)
  {
    input = in;
    // default output extent to all input
    output_extent = ImageExtent<int>(in.get());
  }

  InrImage::ptr& GetInput()
  {
    return input;
  }

  void SetOutputExtent( const ImageExtent<int>& oext)
  {
    output_extent = oext;
  }

  ImageExtent<int>& GetOutputExtent() {
    return output_extent;
  }

  ImageToImageFilterParam() {}

}; // ImageToImageFilterParam;


// ImageToImageFilter
// features needed:
//    - multithreading
//    - progress
//    - timing
//    - help
//
class ImageToImageFilter {

protected:
  ImageToImageFilterParam params;
  typedef ImageExtent<int> extenttype;
  std::vector<extenttype> extents;

public:

  ImageToImageFilter() {}
  ~ImageToImageFilter() {}

  void SetParameters( const ImageToImageFilterParam& p)
  {
    params = p;
  }

  ImageToImageFilterParam& GetParameters( )
  {
    return params;
  }

  virtual void Init();

  virtual void Process( int threadid = 0) = 0;

  static void* Process_thread(void* threadarg);
  void Run_multithreads();

  virtual void Run();

  virtual void Close() {}

}; // ImageToImageFilter

} // namespace ami

#endif // _ami_ImageToImageFilter_h_
