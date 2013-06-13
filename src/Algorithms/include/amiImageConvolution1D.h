//
// C++ Interface: ImageConvolution1D
//
// Description: Add a scalar value to each pixel/voxel of the image
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _ImageConvolution1D_h_
#define _ImageConvolution1D_h_

#include "inrimage.hpp"
#include "amiImageExtent.h"
#include "amiImageToImageFilter.h"
#include <vector>
#include "DefineClass.hpp"
#include "../FastConvolution/convolve.h"
#include <iostream>
#include <xmmintrin.h>

namespace ami {

  
  #define AddSetGetVar( name, type) \
    type  name; \
    void Set##name( type _arg) \
    { \
      this->name = _arg; \
    };  \
    type Get##name() \
    { \
      return this->name; \
    };

  class ImageConvolution1D : public ImageToImageFilter 
  {
    DEFINE_CLASS(ImageConvolution1D);

    InrImage::ptr output;

  public:
    
    ImageConvolution1D() 
    {
      _kernel_radius      = 0;
      _kernel_support     = 4;
      _dir                = DIR_X;
      _symmetry           = NONE;
      _sigma              = 1;
      _order              = 0;

      // Setup fast default values
      _use_fastconvolve   = true;
      _fast_convolve_mode = SSE_PARTIAL_UNROLL;
      _first_call         = true;
      _diry_version       = 1;
      _dirz_version       = 3;
    }
    
    /** @name ConvOrientation
    */
    enum ConvOrientation
    {
      DIR_X= 0,
      DIR_Y,
      DIR_Z
    };

    /**
    * Kernel symmetry
    */
    enum Symmetry
    {
      EVEN,
      ODD,
      NONE
    };
    
    enum FastConvolveMode
    {
      NAIVE = 0,
      SSE_SIMPLE,
      SSE_PARTIAL_UNROLL,
      SSE_IN_ALIGNED,
    };
    
    /// kernel coefficients
    std::vector<double> _kernel_coeff;
    /// size of kernel support will be 2*_kernel_radius+1
    AddSetGetVar( _kernel_radius, int)

    /// Kernel symmetry
    AddSetGetVar( _symmetry, Symmetry)

    /// Kernel support (real kernel radius will be _kernel_support*sigma)
    AddSetGetVar( _kernel_support, int)
    
    /// Convolution orientation
    AddSetGetVar( _dir, ConvOrientation)

    /// Gaussian Standard Deviation
    AddSetGetVar( _sigma, double)
    
    /// Gaussian derivation order
    AddSetGetVar( _order, int)

    /// Mask Image
    AddSetGetVar( _mask, InrImage::ptr)
    
    /// SSE speed-up
    AddSetGetVar( _use_fastconvolve, bool)

    /// Fast Convolution mode
    AddSetGetVar( _fast_convolve_mode, FastConvolveMode)

    /// Fast Convolution mode in Y
    AddSetGetVar( _diry_version, int)

    /// Fast Convolution mode in Z
    AddSetGetVar( _dirz_version, int)

    ///
    double GaussianFunction( double x, double sigma,  int orden=0);

    ///
    void InitGaussianKernel( );

    
    ///
    template <class T>
    double ConvolveDirX(  T* input, 
                          const int& x, const int& tx, 
                          const T& minval, 
                          const T& maxval);
    ///
    template <class T>
    double ConvolveDirY(  T* input, 
                          const int& y, const int& ty, const int& incy,
                          const T& minval, 
                          const T& maxval);
    ///
    template <class T>
    double ConvolveDirZ(  T* input, 
                          const int& z, const int& tz, const int& incz,
                          const T& minval, 
                          const T& maxval);
    /**
    * Process part of the image
    * @param threadid 
    */
    template <class T>
    void TemplateProcess( int threadid = 0);

    /**
    * Process part of the image
    * @param threadid 
    */
    void Process( int threadid = 0);

    //--------------------------------------------------------------------------
    void Run();

    //--------------------------------------------------------------------------
    void SetOutputImage(InrImage::ptr o)
    {
      output = o;
    }

    //--------------------------------------------------------------------------
    InrImage::ptr& GetOutput()
    {
      return output;
    }
    
    //--------------------------------------------------------------------------
    template <class T>
    int fast_convolve(  float* in, T* out, int length,
                        float* kernel, int kernel_length)
    {
      if (typeid(T)!=typeid(float))
        return false;
      
      return fast_convolve_float(in,(float*)out,length,kernel,kernel_length);
    }
    
    
    //--------------------------------------------------------------------------
    //inline 
    int fast_convolve_float(  float* in, float* out, int length,
                              float* kernel, int kernel_length)
    {
      switch(_fast_convolve_mode) {
        case NAIVE:
          if ((_first_call)&&params.GetProfile()) {
            std::cout << "running convolve_naive" << std::endl;
            _first_call = false;
          }
          return convolve_naive(in,out,length,kernel,kernel_length);
        #ifdef SSE3
        case SSE_SIMPLE:
          if ((_first_call)&&params.GetProfile()) {
            std::cout << "running convolve_sse_simple" << std::endl;
            _first_call = false;
          }
          return convolve_sse_simple(in,out,length,kernel,kernel_length);
        case SSE_PARTIAL_UNROLL:
          if ((_first_call)&&params.GetProfile()) {
            std::cout << "running convolve_sse_partial_unroll" << std::endl;
            _first_call = false;
          }
          return convolve_sse_partial_unroll(in,out,length,kernel,kernel_length);
          break;
        case SSE_IN_ALIGNED:
          if ((_first_call)&&params.GetProfile()) {
            std::cout << "running convolve_sse_in_aligned" << std::endl;
            _first_call = false;
          }
          return convolve_sse_in_aligned(in,out,length,kernel,kernel_length);
          break;
        #endif
      }
      return false;
    }



  private:
    bool _first_call;
    
    //--------------------------------------------------------------------------
    template <class T>
    int fast_convolve_prepared( float* in, T* out, int length,
                                __m128* kernel, int kernel_length)
    {
      if (typeid(T)!=typeid(float))
        return false;
      
      return fast_convolve_float_prepared(in,(float*)out,length,
                                          kernel,kernel_length);
    }

    //--------------------------------------------------------------------------
    //inline 
    int fast_convolve_float_prepared(  float* in, float* out, int length,
                                              __m128* kernel, int kernel_length)
    {
      switch(_fast_convolve_mode) {
        case NAIVE:
          return false;
        #ifdef SSE3
        case SSE_SIMPLE:
          if ((_first_call)&&params.GetProfile()) {
            std::cout << "running convolve_sse_simple_prepared" << std::endl;
            _first_call = false;
          }
          return convolve_sse_simple_prepared(in,out,length,kernel,kernel_length);
        case SSE_PARTIAL_UNROLL:
          if ((_first_call)&&params.GetProfile()) {
            std::cout << "running convolve_sse_partial_unroll_prepared" << std::endl;
            _first_call = false;
          }
          return convolve_sse_partial_unroll_prepared(in,out,length,kernel,kernel_length);
        case SSE_IN_ALIGNED:
          return false;
        #endif
      }
      return false;
    }
    
  }; // ImageConvolution1D

} // end namespace ami

#endif // _ImageConvolution1D_h_

