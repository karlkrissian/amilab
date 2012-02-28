//
// C++ Implementation: EigenDecomp
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

#include "amiEigenDecomp.h"
#include "amiImageExtent.h"
#include "amilab_messages.h"
#include <iostream>
#include <limits.h>
#include <vector>
#include <math.h>
#include "Eigen.hpp"

namespace ami {

//------------------------------------------------------------------------------
template <class T>
void EigenDecomp::TemplateProcess( int threadid)
{
  // Get input extent
  InrImage::ptr in = params.GetInput();
  extenttype in_extent(in.get());

  T* in_data  = (T*) in    ->GetData();

  for(z=extent.GetMin(2);z<=extent.GetMax(2); z++)
  {
    for(y=extent.GetMin(1);y<=extent.GetMax(1); y++)
    {
      for(x=extent.GetMin(0);x<=extent.GetMax(0); x++,out_data1++)
      {

      int niter;
      int Diagonal = jacobi( (float**)(*matrice), 3, 
                          vap, 
                          (float**)(*vec_propre), 
                          &niter );

      if (Diagonal) {


        eigsrt(vap,  *vec_propre, 3);

        e0.x = (*vec_propre)[0][0]; 
        e0.y = (*vec_propre)[1][0]; 
        e0.z = (*vec_propre)[2][0];

        e1.x = (*vec_propre)[0][1]; 
        e1.y = (*vec_propre)[1][1]; 
        e1.z = (*vec_propre)[2][1];

        e2.x = (*vec_propre)[0][2]; 
        e2.y = (*vec_propre)[1][2]; 
        e2.z = (*vec_propre)[2][2];
      }
        
        
      } // end for x
    } // end for y
  } // end for z

}


//------------------------------------------------------------------------------
void EigenDecomp::Process( int threadid)
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

//------------------------------------------------------------------------------
bool EigenDecomp::check_eigenvalue_image(InrImage::ptr im) {
  InrImage::ptr in = params.GetInput();
  return  (  (im->DimX()==in->DimX())
           &&(im->DimY()==in->DimY())
           &&(im->DimZ()==in->DimZ())
           &&(im->GetVDim()==1)
           &&(im->_format==WT_FLOAT));
}

//------------------------------------------------------------------------------
bool EigenDecomp::check_eigenvector_image(InrImage::ptr im) {
  InrImage::ptr in = params.GetInput();
  return  (  (im->DimX()==in->DimX())
           &&(im->DimY()==in->DimY())
           &&(im->DimZ()==in->DimZ())
           &&(im->GetVDim()==3)
           &&(im->_format==WT_FLOAT));
}

//------------------------------------------------------------------------------
void EigenDecomp::Run() 
{
  InrImage::ptr in = params.GetInput();
  
  // Create output images
  if ((enable_eigenvalue1)&&(!check_eigenvalue_image(eigenvalue1))) {
    eigenvalue1 = InrImage::ptr(new InrImage(FLOAT,"eigenval1.ami.gz",
                                             input.get()));
  }
  if ((enable_eigenvalue2)&&(!check_eigenvalue_image(eigenvalue2))) {
    eigenvalue2 = InrImage::ptr(new InrImage(FLOAT,"eigenval2.ami.gz",
                                             input.get()));
  }
  if ((enable_eigenvalue3)&&(!check_eigenvalue_image(eigenvalue3))) {
    eigenvalue3 = InrImage::ptr(new InrImage(FLOAT,"eigenval3.ami.gz",
                                             input.get()));
  }

  if ((enable_eigenvector1)&&(!check_eigenvalue_image(eigenvector1))) {
    eigenvector1 = InrImage::ptr(new InrImage(FLOAT,"eigenvect1.ami.gz",
                                             input.get()));
  }
  if ((enable_eigenvector2)&&(!check_eigenvalue_image(eigenvector2))) {
    eigenvector2 = InrImage::ptr(new InrImage(FLOAT,"eigenvect2.ami.gz",
                                             input.get()));
  }
  if ((enable_eigenvector3)&&(!check_eigenvalue_image(eigenvector3))) {
    eigenvector3 = InrImage::ptr(new InrImage(FLOAT,"eigenvect3.ami.gz",
                                             input.get()));
  }
  
  ImageToImageFilter::Run();
}

} // end namespace ami
