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
//#include "convolve.h"

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
      _use_fastconvolve   = false;
      _fast_convolve_mode = NAIVE;
      _first_call         = true;
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
    
    int fast_convolve_float(  float* in, float* out, int length,
                              float* kernel, int kernel_length);

//     switch(_fast_convolve_mode) {
//       case NAIVE:
//         return convolve_naive();
//       case SSE_SIMPLE:
//       #ifdef SSE3
//         return convolve_sse_simple(in,(float*)out,length,kernel,kernel_length);
//       #else
//         return false;
//       #endif
//       case SSE_PARTIAL_UNROLL:
//         break;
//       case SSE_IN_ALIGNED:
//         break;
//       }
//       return true;
  private:
    bool _first_call;
    
  }; // ImageConvolution1D

} // end namespace ami

#endif // _ImageConvolution1D_h_

