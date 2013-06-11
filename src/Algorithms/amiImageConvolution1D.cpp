//
// C++ Implementation: ImageConvolution1D
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

#include "amiImageConvolution1D.h"
#include "amiImageExtent.h"
#include "amilab_messages.h"
#include <iostream>
#include "Timing.hpp"
#include <typeinfo>
#include "convolve.h"

#ifndef M_PI
# define M_PI           3.14159265358979323846  /* pi */
#endif

#ifndef macro_max
  #define macro_max(a,b) (((a)>(b))?(a):(b))
#endif
#ifndef macro_min
  #define macro_min(a,b) (((a)<(b))?(a):(b))
#endif

namespace ami {

  
//------------------------------------------------------------------------------
double ImageConvolution1D::GaussianFunction( double x, double sigma, 
                                             int orden)
{
  double gauss,sigma2;

  gauss  = 1.0/sqrt(2.0*M_PI)/sigma*exp( -0.5*(x/sigma)*(x/sigma));
  sigma2 = sigma*sigma;

  switch ( orden ){
    case 0: return gauss;
    case 1: return gauss*(-1.0*x/sigma2);
    case 2: return gauss*((x/sigma2)*(x/sigma2)-1/sigma2);
    default  : 
      std::cerr << "ImageConvolution1D::GaussianFunction\t orden not available"
                << std::endl;
  } // end switch

  return 0;
} // GaussianFunction()
  
  
//------------------------------------------------------------------------------
void ImageConvolution1D::InitGaussianKernel( )
{
  int i;
  double sum_coeff = 0;

  _kernel_radius = (int) (_sigma*_kernel_support);
  //Si t == 0 AlorsFait t = 1;

  _kernel_coeff.resize(_kernel_radius + 1);

  if (_order == 0) sum_coeff = 0.0;
  for( i=0;i<=_kernel_radius;i++) {
    _kernel_coeff[i] = GaussianFunction( -i, _sigma, _order);
    if (_order == 0) {
      if (i==0)
        sum_coeff += _kernel_coeff[i];
      else
        sum_coeff += 2*_kernel_coeff[i];
    }
  }

  if (_order == 0)
    for( i=0;i<=_kernel_radius;i++)
        _kernel_coeff[i] /= sum_coeff;

  if (_order%2==0) 
    _symmetry = EVEN;
  else
    _symmetry = ODD;
} // InitGaussianKernel()
  

//------------------------------------------------------------------------------
template <class T>
double ImageConvolution1D::ConvolveDirX(  T* input, 
                                          const int& x, const int& tx, 
                                          const T& minval, 
                                          const T& maxval)
{
  
  register T*       input1;
  register T*       input2;
  register int      i;
  register int      x1;
  register int      x2;
  register double   val,res;

  res = (*input) * _kernel_coeff[0];

  input1 = input + _kernel_radius;
  input2 = input - _kernel_radius;
  x1 = x+_kernel_radius;
  x2 = x-_kernel_radius;

  if ((x1>=tx)||(x2<0)) {
    if (_symmetry==EVEN) {
      for(i = _kernel_radius ;  i >= 1 ;  i--)
      {
        if (x+i >= tx)  val  = maxval; else val  = *input1;
        if (x-i <  0 )  val += minval; else val += *input2;
        res += val*_kernel_coeff[i];
        input1--;
        input2++;
      } // end for
    } else {
      for(i = _kernel_radius ;  i >= 1 ;  i--)
      {
        if (x+i >= tx)  val  = maxval; else val  = *input1;
        if (x-i <  0 )  val -= minval; else val -= *input2;
        res += val*_kernel_coeff[i];
        input1--;
        input2++;
      } // end for
    }
  } else {
    if (_symmetry==EVEN) {
      for(i = _kernel_radius ;  i >= 1 ;  i--)
      {
        res += (*input1 + *input2)*_kernel_coeff[i];
        input1--;
        input2++;
      } // end for
    } else {
      for(i = _kernel_radius ;  i >= 1 ;  i--)
      {
        res += (*input1 - *input2)*_kernel_coeff[i];
        input1--;
        input2++;
      } // end for
    }
  }

  return res;

} // ConvolveDirX

//------------------------------------------------------------------------------
template <class T>
double ImageConvolution1D::ConvolveDirY(  T* input, 
                                          const int& y, const int& ty, 
                                          const int& incy,
                                          const T& minval, 
                                          const T& maxval)
{
  register T*       input1;
  register T*       input2;
  register int      i;
  register int      y1;
  register int      y2;
  register double   val,res;

  res = (*input) * _kernel_coeff[0];

  input1 = input + _kernel_radius*incy;
  input2 = input - _kernel_radius*incy;
  y1 = y+_kernel_radius;
  y2 = y-_kernel_radius;

  if ((y1>=ty)||(y2<0)) {
    if (_symmetry==EVEN) {
      for(i = _kernel_radius ;  i >= 1 ;  i--)
      {
        if (y+i >= ty)  val  = maxval; else val  = *input1;
        if (y-i <  0 )  val += minval; else val += *input2;
        res += val*_kernel_coeff[i];
        input1-=incy;
        input2+=incy;
      } // end for
    } else {
      for(i = _kernel_radius ;  i >= 1 ;  i--)
      {
        if (y+i >= ty)  val  = maxval; else val  = *input1;
        if (y-i <  0 )  val -= minval; else val -= *input2;
        res += val*_kernel_coeff[i];
        input1-=incy;
        input2+=incy;
      } // end for
    }
  } else {
    if (_symmetry==EVEN) {
      for(i = _kernel_radius ;  i >= 1 ;  i--)
      {
        res += (*input1 + *input2)*_kernel_coeff[i];
        input1-=incy;
        input2+=incy;
      } // end for
    } else {
      for(i = _kernel_radius ;  i >= 1 ;  i--)
      {
        res += (*input1 - *input2)*_kernel_coeff[i];
        input1-=incy;
        input2+=incy;
      } // end for
    }
  }

  return res;

} // ConvolveDirY

//------------------------------------------------------------------------------
template <class T>
double ImageConvolution1D::ConvolveDirZ(  T* input, 
                                          const int& z, const int& tz, 
                                          const int& incz,
                                          const T& minval, 
                                          const T& maxval)
{
  register T*       input1;
  register T*       input2;
  register int      i;
  register int      z1;
  register int      z2;
  register double   val,res;

  res = (*input) * _kernel_coeff[0];

  input1 = input + _kernel_radius*incz;
  input2 = input - _kernel_radius*incz;
  z1 = z+_kernel_radius;
  z2 = z-_kernel_radius;

  if ((z1>=tz)||(z2<0)) {
    if (_symmetry==EVEN) {
      for(i = _kernel_radius ;  i >= 1 ;  i--)
      {
        if (z+i >= tz)  val  = maxval; else val  = *input1;
        if (z-i <  0 )  val += minval; else val += *input2;
        res += val*_kernel_coeff[i];
        input1-=incz;
        input2+=incz;
      } // end for
    } else {
      for(i = _kernel_radius ;  i >= 1 ;  i--)
      {
        if (z+i >= tz)  val  = maxval; else val  = *input1;
        if (z-i <  0 )  val -= minval; else val -= *input2;
        res += val*_kernel_coeff[i];
        input1-=incz;
        input2+=incz;
      } // end for
    }
  } else {
    if (_symmetry==EVEN) {
      for(i = _kernel_radius ;  i >= 1 ;  i--)
      {
        res += (*input1 + *input2)*_kernel_coeff[i];
        input1-=incz;
        input2+=incz;
      } // end for
    } else {
      for(i = _kernel_radius ;  i >= 1 ;  i--)
      {
        res += (*input1 - *input2)*_kernel_coeff[i];
        input1-=incz;
        input2+=incz;
      } // end for
    }
  }

  return res;

} // ConvolveDirZ

//------------------------------------------------------------------------------
template <class T>
void ImageConvolution1D::TemplateProcess( int threadid)
{
  // process using precomputed extent number threadid
//  int nt = params.GetNumberOfThreads();

  extenttype extent = extents[threadid];
  int x,y,z;
  InrImage::ptr in = params.GetInput();

  int tx = in->DimX();
  int ty = in->DimY();
  int tz = in->DimZ();
  int incx,incy,incz;
  in->GetBufferIncrements(incx,incy,incz);
  if (incx!=1) {
    CLASS_ERROR("incx should be equal to one !!!");
  }
  T* in_data  = (T*) in     ->GetData();
  T* out_data = (T*) output ->GetData();
  T* tmp;
  T minval;
  T maxval;

  bool has_mask = _mask.get();

  // use SSE only with float for the moment
  bool use_sse = _use_fastconvolve && (typeid(T)==typeid(float)) && (!has_mask);

  if (params.GetProfile()) {
    std::cout << "ImageConvolution1D::TemplateProcess()" << std::endl;
    std::cout << "tx=" << tx <<", ty=" << ty << ",tz=" << tz << std::endl;
    std::cout << "extent = " 
                << extent.GetMin(0) << "-" << extent.GetMax(0) << "; "
                << extent.GetMin(1) << "-" << extent.GetMax(1) << "; "
                << extent.GetMin(2) << "-" << extent.GetMax(2) << std::endl;
    std::cout << "dir :" <<  _dir << std::endl;
    std::cout << "kernel radius :" <<  _kernel_radius << std::endl;
    //std::cout << "_use_fastconvolve : " << _use_fastconvolve << std::endl;
    //std::cout << "typeid(T) : " << typeid(T).name() << std::endl;
    //std::cout << "has_mask : "          << has_mask << std::endl;
    std::cout << "use_sse :  "          << use_sse << std::endl;
    std::cout << "has SSE3 :";
#ifdef SSE3
    std::cout << "yes" << std::endl;
#else
    std::cout << "no" << std::endl;
#endif
  }

  
  float* sse_input;
  float* sse_kernel;
  int xmin  = extent.GetMin(0);
  int xmax  = extent.GetMax(0);
  int xsize = extent.GetSize(0);
  
  
  if (_dir==DIR_X) {
    if (use_sse) {
      // prepare for SSE convolution
      // allocate input
      sse_input = new float[extent.GetSize(0)+2*_kernel_radius];
      // allocate and set kernel
      sse_kernel = new float[2*_kernel_radius+1];
      sse_kernel[_kernel_radius] = _kernel_coeff[0];
      for(int i=1; i<=_kernel_radius;i++)
        if (_symmetry==EVEN) 
          sse_kernel[_kernel_radius-i] = 
          sse_kernel[_kernel_radius+i] = _kernel_coeff[i];
        else {
          // re-invert kernel
          sse_kernel[_kernel_radius-i] =  _kernel_coeff[i];
          sse_kernel[_kernel_radius+i] = -_kernel_coeff[i];
        }
    }

    for(z=extent.GetMin(2);z<=extent.GetMax(2); z++)
    for(y=extent.GetMin(1);y<=extent.GetMax(1); y++)
    {
      T* in_data1  = in_data  + z*incz + y*incy + xmin*incx;
      T* out_data1 = out_data + z*incz + y*incy + xmin*incx;
      if (has_mask) {
        tmp = in_data+z*incz+y*incy;
        minval = *(tmp);
        maxval = *(tmp+(tx-1)*incx);
        for(x=xmin;x<=xmax; x++)
        {
          if ((*_mask)(x,y,z)>0.5) {
            *out_data1 = ConvolveDirX<T>(in_data1,x,tx,minval,maxval);
          }
          in_data1++;
          out_data1++;
        }
      } else {
        tmp = in_data+z*incz+y*incy;
        minval = *(tmp);
        maxval = *(tmp+(tx-1)*incx);
        if (use_sse) {
          // Prepare for the convolution function
          // need an input array of size extent.size in X + kernel size
          // need an output array of size extent.size: is out_data1
          // need the kernel array
          // all in float ...
          // 1. if everything fits 
//           if ((xmin-_kernel_radius>0)&&(xmax+_kernel_radius<tx)) {
//             fast_convolve(in_data1-_kernel_radius,
//                      out_data1,   xsize,
//                      sse_kernel,  2*_kernel_radius+1
//                     );
//           } else {
            // prepare sse_input:  1 memcpy
            int minpos = macro_max(0,    xmin-_kernel_radius);
            int maxpos = macro_min(tx-1, xmax+_kernel_radius);
            int pos=0;
            for(x=xmin-_kernel_radius;x<minpos;x++) {
              sse_input[pos] = minval;
              pos++;
            }
            memcpy(&sse_input[pos],
                   in_data1-_kernel_radius+pos,
                   sizeof(float)*(maxpos-minpos+1) );
            pos += maxpos-minpos+1;
            for(x=maxpos+1;x<=xmax+_kernel_radius;x++) {
              sse_input[pos] = maxval;
              pos++;
            }
            fast_convolve(sse_input,
                          out_data1,   xsize+2*_kernel_radius,
                          sse_kernel,  2*_kernel_radius+1);
//           }
          
        } else {
          for(x=xmin;x<=xmax; x++)
          {
            *out_data1 = ConvolveDirX<T>(in_data1,x,tx,minval,maxval);
            in_data1++;
            out_data1++;
          }
        }
      }
    }
    if (use_sse) {
      // prepare for SSE convolution
      // allocate input
      delete [] sse_input;
      delete [] sse_kernel;
    }
  }
  if (_dir==DIR_Y) {
    for(z=extent.GetMin(2);z<=extent.GetMax(2); z++)
    for(y=extent.GetMin(1);y<=extent.GetMax(1); y++)
    {
      T* in_data1  = in_data + z*incz + y*incy +
                          extent.GetMin(0)*incx;
      T* out_data1 = out_data + z*incz + y*incy +
                          extent.GetMin(0)*incx;
      if (has_mask) {
        for(x=extent.GetMin(0);x<=extent.GetMax(0); x++)
        {
          if ((*_mask)(x,y,z)>0.5) {
            tmp = in_data+z*incz+x*incx;
            minval = *(tmp);
            maxval = *(tmp+(ty-1)*incy);
            *out_data1 = ConvolveDirY<T>(in_data1,y,ty,incy,minval,maxval);
          }
          in_data1++;
          out_data1++;
        }
      } else {
        for(x=extent.GetMin(0);x<=extent.GetMax(0); x++)
        {
          tmp = in_data+z*incz+x*incx;
          minval = *(tmp);
          maxval = *(tmp+(ty-1)*incy);
          *out_data1 = ConvolveDirY<T>(in_data1,y,ty,incy,minval,maxval);
          in_data1++;
          out_data1++;
        }
      }
    }
  }
  if (_dir==DIR_Z) {
#define ZVER1
#ifdef ZVER1
    for(z=extent.GetMin(2);z<=extent.GetMax(2); z++)
    for(y=extent.GetMin(1);y<=extent.GetMax(1); y++)
    {
      T* in_data1  = in_data + z*incz + y*incy +
                          extent.GetMin(0)*incx;
      T* out_data1 = out_data + z*incz + y*incy +
                          extent.GetMin(0)*incx;
      if (has_mask) {
        for(x=extent.GetMin(0);x<=extent.GetMax(0); x++)
        {
          if ((*_mask)(x,y,z)>0.5) {
            tmp = in_data+y*incy+x*incx;
            minval = *(tmp);
            maxval = *(tmp+(tz-1)*incz);
            *out_data1 = ConvolveDirZ<T>(in_data1,z,tz,incz,minval,maxval);
          }
          in_data1++;
          out_data1++;
        }
      } else {
        for(x=extent.GetMin(0);x<=extent.GetMax(0); x++)
        {
          tmp = in_data+y*incy+x*incx;
          minval = *(tmp);
          maxval = *(tmp+(tz-1)*incz);
          *out_data1 = ConvolveDirZ<T>(in_data1,z,tz,incz,minval,maxval);
          in_data1++;
          out_data1++;
        }
      }
    }
#endif
#ifdef ZVER2
    for(y=extent.GetMin(1);y<=extent.GetMax(1); y++)
    for(x=extent.GetMin(0);x<=extent.GetMax(0); x++)
    {
      T* in_data1  = in_data  + extent.GetMin(0)*incz + y*incy + x*incx;
      T* out_data1 = out_data + extent.GetMin(0)*incz + y*incy + x*incx;
      if (has_mask) {
        for(z=extent.GetMin(2);z<=extent.GetMax(2); z++)
        {
          if ((*_mask)(x,y,z)>0.5) {
            tmp = in_data+y*incy+x*incx;
            minval = *(tmp);
            maxval = *(tmp+(tz-1)*incz);
            *out_data1 = ConvolveDirZ<T>(in_data1,z,tz,incz,minval,maxval);
          }
          in_data1  += incz;
          out_data1 += incz;
        }
      } else {
        for(z=extent.GetMin(2);z<=extent.GetMax(2); z++)
        {
          tmp = in_data+y*incy+x*incx;
          minval = *(tmp);
          maxval = *(tmp+(tz-1)*incz);
          *out_data1 = ConvolveDirZ<T>(in_data1,z,tz,incz,minval,maxval);
          in_data1  += incz;
          out_data1 += incz;
        }
      }
    }
#endif
#ifdef ZVER3
    T in1 [tz];
    T out1[tz];
    for(y=extent.GetMin(1);y<=extent.GetMax(1); y++)
    for(x=extent.GetMin(0);x<=extent.GetMax(0); x++)
    {
      int pos = extent.GetMin(0)*incz + y*incy + x*incx;
      T* in_data1  = in_data  + pos;
      T* out_data1 = out_data + pos;
      // 1. copy in1
      tmp = in_data+y*incy+x*incx;
      for(z=0;z<tz;z++) { in1[z] = *tmp; tmp+=incz; }
      minval = in1[0];
      maxval = in1[tz-1];
      if (has_mask) {
        for(z=extent.GetMin(2);z<=extent.GetMax(2); z++)
          if ((*_mask)(x,y,z)>0.5)
            out1[z] = ConvolveDirX<T>(in1,z,tz,minval,maxval);
      } else {
        for(z=extent.GetMin(2);z<=extent.GetMax(2); z++)
          out1[z] = ConvolveDirX<T>(in1,z,tz,minval,maxval);
      }
      for(z=extent.GetMin(2);z<=extent.GetMax(2); z++) {
        *out_data = out1[z];
        out_data1 += incz;
      }
    }
#endif
  }
  

}


//------------------------------------------------------------------------------
void ImageConvolution1D::Process( int threadid)
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
    default: CLASS_ERROR((boost::format(" format %1% not available")%
                                in->GetFormat()).str().c_str());
  }

}

//------------------------------------------------------------------------------
void ImageConvolution1D::Run()
{
  //std::cout << "ImageConvolution1D::Run() Begin" << std::endl;
  
  Timing t((boost::format("ImageConvolution1D::Run() %1%") % _dir).str());
  
  t.Debut();
  InrImage::ptr in = params.GetInput();
  bool output_ok = false;
  if (output.get()) {
    if ((output->DimX()==in->DimX())&&(output->DimY()==in->DimY())
        &&(output->DimZ()==in->DimZ())
        &&(in->GetFormat()==output->GetFormat()))
    {
      output_ok = true;
    }
  }
  if (!output_ok) {
    output = InrImage::ptr(new InrImage(in->GetFormat(),
                                        "convolution_res.ami.gz",
                                        in.get()));
  }
  
  InitGaussianKernel();
  ImageToImageFilter::Run();
  t.Fin();
  std::cout << t << std::endl;
  //std::cout << "ImageConvolution1D::Run() End" << std::endl;
}


//------------------------------------------------------------------------------
int ImageConvolution1D::fast_convolve_float(  float* in, float* out, int length,
                                              float* kernel, int kernel_length)
{
    switch(_fast_convolve_mode) {
      case NAIVE:
        if (_first_call) {
          std::cout << "running convolve_naive" << std::endl;
          _first_call = false;
        }
        return convolve_naive(in,out,length,kernel,kernel_length);
      #ifdef SSE3
      case SSE_SIMPLE:
        if (_first_call) {
          std::cout << "running convolve_sse_simple" << std::endl;
          _first_call = false;
        }
        return convolve_sse_simple(in,out,length,kernel,kernel_length);
      case SSE_PARTIAL_UNROLL:
        if (_first_call) {
          std::cout << "running convolve_sse_partial_unroll" << std::endl;
          _first_call = false;
        }
        return convolve_sse_partial_unroll(in,out,length,kernel,kernel_length);
        break;
      case SSE_IN_ALIGNED:
        if (_first_call) {
          std::cout << "running convolve_sse_in_aligned" << std::endl;
          _first_call = false;
        }
        return convolve_sse_in_aligned(in,out,length,kernel,kernel_length);
        break;
      #endif
      }
      return false;
}

} // end namespace ami

