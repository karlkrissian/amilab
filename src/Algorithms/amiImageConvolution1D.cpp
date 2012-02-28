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

  for(z=extent.GetMin(2);z<=extent.GetMax(2); z++)
  for(y=extent.GetMin(1);y<=extent.GetMax(1); y++)
  {
    T* in_data1  = in_data + z*incz + y*incy +
                        extent.GetMin(0)*incx;
    T* out_data1 = out_data + z*incz + y*incy +
                        extent.GetMin(0)*incx;
    for(x=extent.GetMin(0);x<=extent.GetMax(0); x++)
    {
      if (_dir==DIR_X) {
        tmp = in_data+z*incz+y*incy;
        minval = *(tmp);
        maxval = *(tmp+(tx-1)*incx);
        *out_data1 = ConvolveDirX<T>(in_data1,x,tx,minval,maxval);
      } else
      if (_dir==DIR_Y) {
        tmp = in_data+z*incz+x*incx;
        minval = *(tmp);
        maxval = *(tmp+(ty-1)*incy);
        *out_data1 = ConvolveDirY<T>(in_data1,y,ty,incy,minval,maxval);
      } else
      if (_dir==DIR_Z) {
        tmp = in_data+y*incy+x*incx;
        minval = *(tmp);
        maxval = *(tmp+(tz-1)*incz);
        *out_data1 = ConvolveDirZ<T>(in_data1,z,tz,incz,minval,maxval);
      } 

      in_data1++;
      out_data1++;
    }
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
  //std::cout << "ImageConvolution1D::Run() End" << std::endl;
}

} // end namespace ami
