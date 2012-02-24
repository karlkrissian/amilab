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
                                             int orden=0)
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
void ImageConvolution1D::InitGaussianKernel(  float sigma, int support_coeff, 
                                              int orden)
{
  int i;
  double sum_coeff = 0;

  _kernel_radius = (int) (sigma*facteur_support);
  Si t == 0 AlorsFait t = 1;

  _kernel_coeff.resize(_kernel_radius + 1);

  if (orden == 0) sum_coeff = 0.0;
  for( i=0;i<=_kernel_radius;i++) {
    _kernel_coeff[i] = GaussianFunction( -i, sigma, orden);
    if (orden == 0) {
      if (i==0)
        sum_coeff += _kernel_coeff[i];
      else
        sum_coeff += 2*_kernel_coeff[i];
    }
  }

  if (orden == 0)
    for( i=0;i<=_kernel_radius;i++)
        _kernel_coeff[i] /= sum_coeff;

  if (orden%2==0) 
    _symmetry = EVEN;
  else
    _symmetry = ODD;
} // InitGaussianKernel()
  

//------------------------------------------------------------------------------
template <class T>
void ImageConvolution1D::TemplateProcess( int threadid)
{
  // process using precomputed extent number threadid
//  int nt = params.GetNumberOfThreads();

  extenttype extent = extents[threadid];
  int x,y,z;
  InrImage::ptr in = params.GetInput();

  int incx,incy,incz;
  in->GetBufferIncrements(incx,incy,incz);
  T* in_data  = (T*) in     ->GetData();
  T* out_data = (T*) output ->GetData();

  for(z=extent.GetMin(2);z<=extent.GetMax(2); z++)
  for(y=extent.GetMin(1);y<=extent.GetMax(1); y++)
  {
    T* in_data1  = in_data + z*incz + y*incy +
                        extent.GetMin(0)*incx;
    T* out_data1 = out_data + z*incz + y*incy +
                        extent.GetMin(0)*incx;
    for(x=extent.GetMin(0);x<=extent.GetMax(0); x++)
    {

      *in_data1 = cos((double)*in_data1);
      in_data1++;
      out_data1++
    }
  }

}


//------------------------------------------------------------------------------
void ImageConvolution1D::Process( int threadid)
{
  // process using precomputed extent number threadid
  InrImage::ptr in = params.GetInput();
  bool output_ok = false
  if output.get() {
    if ((output->DimX()==in->DimX())&&(output->DimY()==in->DimY())
        &&(output->DimZ()==in->DimZ())
        &&(in->GetFormat()==output->GetFormat()))
    {
      output_ok = true;
    }
  }
  if (!output_ok) {
    output = InrImage::ptr(new InrImage(in->DimX(),in->DimY(),in->DimZ(),
                                        1, in->GetFormat()));
  }

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

} // end namespace ami
