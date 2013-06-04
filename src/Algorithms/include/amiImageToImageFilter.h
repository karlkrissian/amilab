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
#include "amiImageExtent.h"
#include "DefineClass.hpp"
#include <vector>



namespace ami {

// 
// ImageToImageFilterParam
// features needed:
//    - help
//    - gui
//
class ImageToImageFilterParam {

  DEFINE_CLASS(ImageToImageFilterParam)
  
  int NumberOfThreads;
  InrImage::ptr input;
  ImageExtent<int> output_extent;
  
  bool Profile;

public:

  void SetNumberOfThreads(int n)
  {
    NumberOfThreads = n;
  }

  int  GetNumberOfThreads() 
  { 
    return NumberOfThreads;
  }

  void SetProfile(bool p)
  {
    Profile = p;
  }

  bool  GetProfile() 
  { 
    return Profile;
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

  ImageToImageFilterParam() : NumberOfThreads(1), Profile(false) {}

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
  
  bool UseOpenMP;

public:

  ImageToImageFilter() : UseOpenMP(false)  {}
  ~ImageToImageFilter() {}

  void SetParameters( const ImageToImageFilterParam& p)
  {
    params = p;
  }
  
  void SetUseOpenMP(bool uomp)
  {
    UseOpenMP = uomp;
  }

  bool GetUseOpenMP()
  {
    return UseOpenMP;
  }
  
  ImageToImageFilterParam& GetParameters( )
  {
    return params;
  }

  virtual void Init();

  virtual void Process( int threadid = 0) = 0;

  static void  Process_thread_omp(void* threadarg);
  static void* Process_thread(void* threadarg);

  void Run_multithreads();

  virtual void Run();

  virtual void Close() {}

}; // ImageToImageFilter

} // namespace ami

#endif // _ami_ImageToImageFilter_h_
