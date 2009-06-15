//
// C++ Interface: ImageToImageFilter
//
// Description: 
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _ImageToImageFilter_h_
#define _ImageToImageFilter_h_

#include "inrimage.hpp"
#include "imageextent.h"

// use amilab namespace here ??

// 
// ImageToImageFilterParam
// features needed:
//    - help
//    - gui
//
class ImageToImageFilterParam {

  int NumberOfThreads;
  InrImage::ptr input;
  InrImage::ptr output;

public:

  void SetNumberOfThreads(int n)
  {
    NumberOfThreads = n;
  }

  int  GetNumberOfThreads() 
  { 
    return NumberOfThreads;
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

  ImageToImageFilterParam params;

public:

  ImageToImageFilter();
  ~ImageToImageFilter();

  virtual void Init();

  virtual void Process( int threadid = 0, int numthreads = 1) = 0;
  virtual static void* Process_thread(void* threadarg);
  void Run_multithreads();

  virtual void Run();

  virtual void Close();

}; // ImageToImageFilter

#endif // _ImageToImageFilter_h_
