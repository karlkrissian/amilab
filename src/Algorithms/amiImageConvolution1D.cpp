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
#include <xmmintrin.h>

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
  bool use_sse = _use_fastconvolve && (typeid(T)==typeid(float));

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
  __m128* sse_kernel_prepared;
  int xmin  = extent.GetMin(0);
  int xmax  = extent.GetMax(0);
  int xsize = extent.GetSize(0);
  int ymin  = extent.GetMin(1);
  int ymax  = extent.GetMax(1);
  int ysize = extent.GetSize(1);
  int zmin  = extent.GetMin(2);
  int zmax  = extent.GetMax(2);
  int zsize = extent.GetSize(2);
  int kernel_size = 2*_kernel_radius+1;
  int sse_kernel_size;
  
  if (use_sse) {
    // prepare for SSE convolution
    // allocate input
    int size = extent.GetSize((int)_dir)+2*_kernel_radius;
    sse_input = (float*)_mm_malloc(sizeof(float)*size,16);
    // allocate and set kernel
    sse_kernel = new float[kernel_size];
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
    sse_kernel_prepared = sse_prepare_kernel_reverse(sse_kernel,kernel_size);
  }
  
  if (_dir==DIR_X) {

    for(z=zmin;z<=zmax; z++)
    for(y=ymin;y<=ymax; y++)
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
            
          switch(_fast_convolve_mode) {
            case NAIVE:
            case SSE_IN_ALIGNED:
                fast_convolve(sse_input,
                              out_data1,   xsize+2*_kernel_radius,
                              sse_kernel,  kernel_size);
                break;

            case SSE_SIMPLE:
            case SSE_PARTIAL_UNROLL:
                fast_convolve_prepared(sse_input,
                              out_data1,   xsize+2*_kernel_radius,
                              sse_kernel_prepared, kernel_size);
                break;
          }
          
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
  }
  if (_dir==DIR_Y) {
    switch(_diry_version) 
    { 
      case 0:
        for(z=zmin;z<=zmax; z++)
        for(y=ymin;y<=ymax; y++)
        {
          T* in_data1  = in_data + z*incz + y*incy +
                              extent.GetMin(0)*incx;
          T* out_data1 = out_data + z*incz + y*incy +
                              extent.GetMin(0)*incx;
          if (has_mask) {
            for(x=xmin;x<=xmax; x++)
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
            for(x=xmin;x<=xmax; x++)
            {
              tmp = in_data+z*incz+x*incx;
              minval = *(tmp);
              maxval = *(tmp+(ty-1)*incy);
              *out_data1 = ConvolveDirY<T>(in_data1,y,ty,incy,minval,maxval);
              in_data1++;
              out_data1++;
            }
          }
        } // end for
        break;
      case 1:
        {
          T* in1 = new T[ty];
          T* in1_ptr;
          T* out1 = new T[ty];
          T* out1_ptr;
          for(z=zmin;z<=zmax; z++)
          for(x=xmin;x<=xmax; x++)
          {
            int pos = z*incz + ymin*incy + x*incx;
            T* in_data1  = in_data  + pos;
            T* out_data1 = out_data + pos;
            // 1. copy in1
            tmp = in_data+z*incz+x*incx;
            for(y=0;y<ty;y++) { in1[y] = *tmp; tmp+=incy; }
            minval = in1[0];
            maxval = in1[ty-1];
            in1_ptr  = in1+ymin;
            out1_ptr = out1+ymin;
            if (use_sse) {
              // prepare sse_input:  1 memcpy
              int minpos = macro_max(0,    ymin-_kernel_radius);
              int maxpos = macro_min(ty-1, ymax+_kernel_radius);
              int pos=0;
              for(y=ymin-_kernel_radius;y<minpos;y++) {
                sse_input[pos] = minval;
                pos++;
              }
              memcpy(&sse_input[pos],
                      in1_ptr-_kernel_radius+pos,
                      sizeof(float)*(maxpos-minpos+1) );
              pos += maxpos-minpos+1;
              for(y=maxpos+1;y<=ymax+_kernel_radius;y++) {
                sse_input[pos] = maxval;
                pos++;
              }
                
              switch(_fast_convolve_mode) {
                case NAIVE:
                case SSE_IN_ALIGNED:
                    fast_convolve(sse_input,
                                  out1_ptr,   ysize+2*_kernel_radius,
                                  sse_kernel,  kernel_size);
                    break;

                case SSE_SIMPLE:
                case SSE_PARTIAL_UNROLL:
                    fast_convolve_prepared(sse_input,
                                  out1_ptr,   ysize+2*_kernel_radius,
                                  sse_kernel_prepared, kernel_size);
                    break;
              }
              
            } else {
              for(y=ymin;y<=ymax; y++) {
                out1[y] = ConvolveDirX<T>(in1_ptr,y,ty,minval,maxval);
                in1_ptr++;
              }
            }
              
            for(y=ymin;y<=ymax; y++) {
              *out_data1 = out1[y];
              out_data1 += incy;
            }
          }
          delete [] in1;
          delete [] out1;
        }
        break;
      case 3: // process 4 lines in parallel
      case 4: // process 4 lines in parallel with symmetry
        {
          if (use_sse) {
            int size = extent.GetSize((int)_dir)+2*_kernel_radius;
            __m128* in_x4  = (__m128*) _mm_malloc(sizeof(__m128)*size,16);
            __m128* out_x4 = (__m128*) _mm_malloc(
                                sizeof(__m128)*extent.GetSize((int)_dir),16);
            __m128 minvalues;
            __m128 maxvalues;
            float values[4] __attribute__ ((aligned (16)));;

            for(z=zmin;z<=zmax; z++)
            {
              // step 4 by 4 in x
              for(x=xmin;x<=xmax; x+=4)
              {
                int pos0 = z*incz + x*incx;
                //int pos = zmin*incz + pos0;

                float* in_data1  = (float*)in_data  + pos0;
                if (x>xmax-3) {
                  bzero(values,4*sizeof(float));
                  memcpy(values,
                         in_data1,
                         (xmax-x+1)*sizeof(float));
                  minvalues =  _mm_load_ps(values);
                  memcpy(values,
                         (in_data1+(ty-1)*incy),
                         (xmax-x+1)*sizeof(float));
                  maxvalues =  _mm_load_ps(values);
                } else {
                  minvalues = _mm_loadu_ps(in_data1);
                  maxvalues = _mm_loadu_ps(in_data1+(ty-1)*incy);
                }

                // prepare in_x4
                int minpos = macro_max(0,    ymin-_kernel_radius);
                int maxpos = macro_min(ty-1, ymax+_kernel_radius);
                int pos=0;
                for(y=ymin-_kernel_radius;y<minpos;y++) {
                  in_x4[pos] = minvalues;
                  pos++;
                }
                in_data1  = (float*)in_data  + pos0 + minpos*incy;
                // special case is not multiple of 4
                if (x>xmax-3) {
                  for(y=minpos;y<=maxpos;y++) {
                    bzero(values,4*sizeof(float));
                    memcpy(values,in_data1,(xmax-x+1)*sizeof(float));
                    // data not necessary aligned in the original image
                    in_x4[pos] =  _mm_load_ps(values);
                    in_data1+=incy;
                    pos++;
                  }
                } else {
                  for(y=minpos;y<=maxpos;y++) {
                    // data not necessary aligned in the original image
                    in_x4[pos] =  _mm_loadu_ps(in_data1);
                    in_data1+=incy;
                    pos++;
                  }
                }
                for(y=maxpos+1;y<=ymax+_kernel_radius;y++) {
                  in_x4[pos] = maxvalues;
                  pos++;
                }
                  
                if (_dirz_version==4) {
                  if (_symmetry==EVEN)
                    convolve_sse_x4_prepared_sym( in_x4,
                                                  out_x4,
                                                  ysize+2*_kernel_radius,
                                                  sse_kernel_prepared,
                                                  _kernel_radius);
                  else
                    convolve_sse_x4_prepared_asym( in_x4,
                                                   out_x4,
                                                   ysize+2*_kernel_radius,
                                                   sse_kernel_prepared,  
                                                   _kernel_radius);
                }
                else
                  convolve_sse_x4_prepared( in_x4,
                                            out_x4,   ysize+2*_kernel_radius,
                                            sse_kernel_prepared,  kernel_size);
                
                // copy back the results
                float* out_data1 = (float*)out_data + ymin*incy + pos0;

                if (x>xmax-3) {
                  for(y=0;y<extent.GetSize(2); y++) {
                    _mm_store_ps(values,out_x4[y]);
                    memcpy(out_data1,values,(xmax-x+1)*sizeof(float));
                    out_data1 += incy;
                  }
                } else
                  for(y=0;y<extent.GetSize(2); y++) {
                    _mm_storeu_ps(out_data1, out_x4[y]);
                    out_data1 += incy;
                  }
              } // for x
              
            } // for z
            _mm_free( in_x4);
            _mm_free( out_x4);
          }
        }
        break;
    } // end switch
  } // end if 
  if (_dir==DIR_Z) {
    switch(_dirz_version) 
    { 
      case 0: // call ConvolveDirZ, loop z,y,x
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
        break;
      case 1:  // call ConvolveDirZ, loop y,x,z
          for(y=ymin;y<=ymax; y++)
          for(x=xmin;x<=xmax; x++)
          {
            T* in_data1  = in_data  + zmin*incz + y*incy + x*incx;
            T* out_data1 = out_data + zmin*incz + y*incy + x*incx;
            tmp = in_data+y*incy+x*incx;
            minval = *(tmp);
            maxval = *(tmp+(tz-1)*incz);
            if (has_mask) {
              for(z=zmin;z<=zmax; z++)
              {
                if ((*_mask)(x,y,z)>0.5) {
                  *out_data1 = ConvolveDirZ<T>(in_data1,z,tz,incz,minval,maxval);
                }
                in_data1  += incz;
                out_data1 += incz;
              }
            } else {
              for(z=zmin;z<=zmax; z++)
              {
                *out_data1 = ConvolveDirZ<T>(in_data1,z,tz,incz,minval,maxval);
                in_data1  += incz;
                out_data1 += incz;
              }
            }
          }
        break;
      case 2: // call ConvolveDirX, loop y,x,z
        {
          T* in1 = new T[tz];
          T* in1_ptr;
          T* out1 = new T[tz];
          T* out1_ptr;
          for(y=ymin;y<=ymax; y++)
          for(x=xmin;x<=xmax; x++)
          {
            int pos = zmin*incz + y*incy + x*incx;
            T* in_data1  = in_data  + pos;
            T* out_data1 = out_data + pos;
            // 1. copy in1
            tmp = in_data+y*incy+x*incx;
            for(z=0;z<tz;z++) { in1[z] = *tmp; tmp+=incz; }
            minval = in1[0];
            maxval = in1[tz-1];
            in1_ptr  = in1+zmin;
            out1_ptr = out1+zmin;
            if (use_sse) {
              // prepare sse_input:  1 memcpy
              int minpos = macro_max(0,    zmin-_kernel_radius);
              int maxpos = macro_min(tz-1, zmax+_kernel_radius);
              int pos=0;
              for(z=zmin-_kernel_radius;z<minpos;z++) {
                sse_input[pos] = minval;
                pos++;
              }
              memcpy(&sse_input[pos],
                      in1_ptr-_kernel_radius+pos,
                      sizeof(float)*(maxpos-minpos+1) );
              pos += maxpos-minpos+1;
              for(z=maxpos+1;z<=zmax+_kernel_radius;z++) {
                sse_input[pos] = maxval;
                pos++;
              }
                
              switch(_fast_convolve_mode) {
                case NAIVE:
                case SSE_IN_ALIGNED:
                    fast_convolve(sse_input,
                                  out1_ptr,   zsize+2*_kernel_radius,
                                  sse_kernel,  kernel_size);
                    break;

                case SSE_SIMPLE:
                case SSE_PARTIAL_UNROLL:
                    fast_convolve_prepared(sse_input,
                                  out1_ptr,   zsize+2*_kernel_radius,
                                  sse_kernel_prepared, kernel_size);
                    break;
              }
              
            } else {
              for(z=zmin;z<=zmax; z++) {
                out1[z] = ConvolveDirX<T>(in1_ptr,z,tz,minval,maxval);
                in1_ptr++;
              }
            }
              
            for(z=zmin;z<=zmax; z++) {
              *out_data1 = out1[z];
              out_data1 += incz;
            }
          }
          delete [] in1;
          delete [] out1;
        }
        break;
        
      case 3: // process 4 lines in parallel
      case 4: // process 4 lines in parallel with symmetry
        {
          if (use_sse) {
            int size = extent.GetSize((int)_dir)+2*_kernel_radius;
            __m128* in_x4  = (__m128*) _mm_malloc(sizeof(__m128)*size,16);
            __m128* out_x4 = (__m128*) _mm_malloc(
                                sizeof(__m128)*extent.GetSize((int)_dir),16);
            __m128 minvalues;
            __m128 maxvalues;
            float values[4] __attribute__ ((aligned (16)));;

            for(y=ymin;y<=ymax; y++)
            {
              // step 4 by 4 in x
              for(x=xmin;x<=xmax; x+=4)
              {
                int pos0 = y*incy + x*incx;
                //int pos = zmin*incz + pos0;

                float* in_data1  = (float*)in_data  + pos0;
                if (x>xmax-3) {
                  bzero(values,4*sizeof(float));
                  memcpy(values,
                         in_data1,
                         (xmax-x+1)*sizeof(float));
                  minvalues =  _mm_load_ps(values);
                  memcpy(values,
                         (in_data1+(tz-1)*incz),
                         (xmax-x+1)*sizeof(float));
                  maxvalues =  _mm_load_ps(values);
                } else {
                  minvalues = _mm_loadu_ps(in_data1);
                  maxvalues = _mm_loadu_ps(in_data1+(tz-1)*incz);
                }

                // prepare in_x4
                int minpos = macro_max(0,    zmin-_kernel_radius);
                int maxpos = macro_min(tz-1, zmax+_kernel_radius);
                int pos=0;
                for(z=zmin-_kernel_radius;z<minpos;z++) {
                  in_x4[pos] = minvalues;
                  pos++;
                }
                in_data1  = (float*)in_data  + pos0 + minpos*incz;
                // special case is not multiple of 4
                if (x>xmax-3) {
                  for(z=minpos;z<=maxpos;z++) {
                    bzero(values,4*sizeof(float));
                    memcpy(values,in_data1,(xmax-x+1)*sizeof(float));
                    // data not necessary aligned in the original image
                    in_x4[pos] =  _mm_load_ps(values);
                    in_data1+=incz;
                    pos++;
                  }
                } else {
                  for(z=minpos;z<=maxpos;z++) {
                    // data not necessary aligned in the original image
                    in_x4[pos] =  _mm_loadu_ps(in_data1);
                    in_data1+=incz;
                    pos++;
                  }
                }
                for(z=maxpos+1;z<=zmax+_kernel_radius;z++) {
                  in_x4[pos] = maxvalues;
                  pos++;
                }
                  
                if (_dirz_version==4) {
                  if (_symmetry==EVEN)
                    convolve_sse_x4_prepared_sym( in_x4,
                                                  out_x4,
                                                  zsize+2*_kernel_radius,
                                                  sse_kernel_prepared,
                                                  _kernel_radius);
                  else
                    convolve_sse_x4_prepared_asym( in_x4,
                                                   out_x4,
                                                   zsize+2*_kernel_radius,
                                                   sse_kernel_prepared,  
                                                   _kernel_radius);
                }
                else
                  convolve_sse_x4_prepared( in_x4,
                                            out_x4,   zsize+2*_kernel_radius,
                                            sse_kernel_prepared,  kernel_size);
                
                // copy back the results
                float* out_data1 = (float*)out_data + zmin*incz + pos0;

                if (x>xmax-3) {
                  for(z=0;z<extent.GetSize(2); z++) {
                    _mm_store_ps(values,out_x4[z]);
                    memcpy(out_data1,values,(xmax-x+1)*sizeof(float));
                    out_data1 += incz;
                  }
                } else
                  for(z=0;z<extent.GetSize(2); z++) {
                    _mm_storeu_ps(out_data1, out_x4[z]);
                    out_data1 += incz;
                  }
              } // for x
              // should compute the remaining lines ...
              
            } // for y
            _mm_free( in_x4);
            _mm_free( out_x4);
          }
        }
        break;
    }
  }
 
  if (use_sse) {
    // free allocated arrays
    _mm_free(sse_input);
    delete [] sse_kernel;
    sse_free_kernel(sse_kernel_prepared);
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
  std::cout << t 
            << ", kernel radius " << _kernel_radius 
            << ", time per billion voxels /kernelsize " 
            << t.GetDurationMilliSec()/(2*_kernel_radius+1)/in->Size()*100000000
            << " millisec"
            << std::endl;
  //std::cout << "ImageConvolution1D::Run() End" << std::endl;
}



} // end namespace ami

