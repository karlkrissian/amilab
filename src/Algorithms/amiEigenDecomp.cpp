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
#include "FloatMatrix.hpp"
#include <boost/scoped_array.hpp>
#include "dsyevj3.h"
#include "dsyevq3.h"
#include "dsyevh3.h"

namespace ami {


//------------------------------------------------------------------------------
template <class T>
void EigenDecomp::FillMatrix( FloatMatrix & matrix, T* in_ptr, int vdim)
{
  // fill the matrix
  int i,j;
  int n=0;
  for(i=0;i<3;i++)
  for(j=0;j<3;j++) {
    if (vdim==6) {
      if (i<=j) {
        matrix[i][j] = in_ptr[n];
        n++;
      } else {
        matrix[i][j] = matrix[j][i];
      }
    }
    if (vdim==9) {
      matrix[i][j] = in_ptr[n];
      n++;
    }
  }
}
  
//------------------------------------------------------------------------------
void EigenDecomp::FillMatrix(FloatMatrix & matrix, float* in_ptr, int vdim)
{
  // fill the matrix
  int i,j;
  int n=0;
  for(i=0;i<3;i++)
  for(j=0;j<3;j++) {
    if (vdim==6) {
      if (i<=j) {
        matrix[i][j] = in_ptr[n];
        n++;
      } else {
        matrix[i][j] = matrix[j][i];
      }
    }
    if (vdim==9) {
      matrix[i][j] = in_ptr[n];
      n++;
    }
  }
}

//------------------------------------------------------------------------------
// T is the input voxel type
// U is the eigenvectors voxel type
//
template <class T, class U>
void EigenDecomp::TemplateProcess( int threadid)
{
  // Get input extent
  InrImage::ptr   in = params.GetInput();
  extenttype      extent = extents[threadid];
  int             niter; //,n;
  bool            mask_ok;
//  int             i,j;
  FloatMatrix     matrix(3,3);
  unsigned char   Diagonal;
  int             success;
  float           vap[3];
  FloatMatrix     vec_propre(3,3);
  double          mat_d[3][3];
  double          vap_d[3];
  double          vep_d[3][3];
  // temporary vector for jacobi eigen decomposition
  boost::scoped_array<float> tmp_b (new float[4]);
  boost::scoped_array<float> tmp_z (new float[4]);
  int vdim = in->GetVDim();
  int x,y,z;
  // Warning: many should be long int ...
  int inc;

  T* in_data  = (T*) in->GetData();
  T* in_ptr;

  // input image increments
  int input_incx,input_incy,input_incz;
  in->GetBufferIncrements(input_incx,input_incy,input_incz);

  // scalar image increments
  int scalar_incx,scalar_incy,scalar_incz;
  scalar_incx = 1;
  scalar_incy = in->DimX();
  scalar_incz = scalar_incy*in->DimY();
  

  // vector image increments
  int vect_incx,vect_incy,vect_incz;
  vect_incx = 3;
  vect_incy = vect_incx*in->DimX();
  vect_incz = vect_incy*in->DimY();

  float* eval1_data;
  float* eval1_ptr;
  if (eigenvalue1.get()) eval1_data = (float*) eigenvalue1->GetData();
  
  float* eval2_data;
  float* eval2_ptr;
  if (eigenvalue2.get()) eval2_data = (float*) eigenvalue2->GetData();

  float* eval3_data;
  float* eval3_ptr;
  if (eigenvalue3.get()) eval3_data = (float*) eigenvalue3->GetData();

  U* evect1_data;
  U* evect1_ptr;
  if (eigenvector1.get()) evect1_data = (U*) eigenvector1->GetData();

  U* evect2_data;
  U* evect2_ptr;
  if (eigenvector2.get()) evect2_data = (U*) eigenvector2->GetData();

  U* evect3_data;
  U* evect3_ptr;
  if (eigenvector3.get()) evect3_data = (U*) eigenvector3->GetData();
  
  for(z=extent.GetMin(2);z<=extent.GetMax(2); z++)
  {
    for(y=extent.GetMin(1);y<=extent.GetMax(1); y++)
    {
      inc = extent.GetMin(0)*input_incx + y*input_incy + z*input_incz;
      in_ptr    = in_data    + inc;

      inc = extent.GetMin(0) + y*scalar_incy + z*scalar_incz;
      if (eigenvalue1.get()) eval1_ptr = eval1_data + inc;
      if (eigenvalue2.get()) eval2_ptr = eval2_data + inc;
      if (eigenvalue3.get()) eval3_ptr = eval3_data + inc;

      inc = extent.GetMin(0)*vect_incx + y*vect_incy + z*vect_incz;
      if (eigenvector1.get()) evect1_ptr = evect1_data + inc;
      if (eigenvector2.get()) evect2_ptr = evect2_data + inc;
      if (eigenvector3.get()) evect3_ptr = evect3_data + inc;
      
      for(x=extent.GetMin(0);x<=extent.GetMax(0); x++)
      {

        mask_ok = (!mask.get());
        if (!mask_ok)
          mask_ok =  ((*mask)(x,y,z)>=0.5);

        if (mask_ok) {
          FillMatrix( matrix, in_ptr, vdim);

          switch(diag_algorithm) {
            case JACOBI_INITIAL:
              // Calcul des vep et des vap dans les images associees
              // use vnl here?
              Diagonal = jacobi2( 
                                  matrix, 
                                  3, 
                                  vap, 
                                  vec_propre, 
                                  &niter,
                                  tmp_b.get(),
                                  tmp_z.get() );
              break;
            case KOPP_JACOBI:
              for(int i=0;i<3;i++) 
                for(int j=0;j<3;j++)
                  mat_d[i][j] = matrix[i][j];
              success = dsyevj3(  mat_d, 
                                  vep_d, 
                                  vap_d);
              for(int i=0;i<3;i++) {
                vap[i] = vap_d[i];
                for(int j=0;j<3;j++)
                  vec_propre[i][j] = vep_d[i][j];
              }
              Diagonal = (success==0);
              if (!Diagonal) std::cout << "Error" << std::endl;
              break;
            case KOPP_QL:
              for(int i=0;i<3;i++) 
                for(int j=0;j<3;j++)
                  mat_d[i][j] = matrix[i][j];
              success = dsyevq3(  mat_d, 
                                  vep_d, 
                                  vap_d);
              for(int i=0;i<3;i++) {
                vap[i] = vap_d[i];
                for(int j=0;j<3;j++)
                  vec_propre[i][j] = vep_d[i][j];
              }
              Diagonal = (success==0);
              if (!Diagonal) std::cout << "Error" << std::endl;
              break;
            case KOPP_HYBRID:
              for(int i=0;i<3;i++) 
                for(int j=0;j<3;j++)
                  mat_d[i][j] = matrix[i][j];
              success = dsyevh3(  mat_d, 
                                  vep_d, 
                                  vap_d);
              for(int i=0;i<3;i++) {
                vap[i] = vap_d[i];
                for(int j=0;j<3;j++)
                  vec_propre[i][j] = vep_d[i][j];
              }
              Diagonal = (success==0);
              if (!Diagonal) std::cout << "Error" << std::endl;
              break;
            default: 
              std::cout << "diagonalization algo not implemented" << std::endl;
          }

          if (Diagonal) {
            eigsrt(vap,  vec_propre, 3);
            if (eigenvalue1.get()) *eval1_ptr =  vap[0];
            if (eigenvalue2.get()) *eval2_ptr =  vap[1];
            if (eigenvalue3.get()) *eval3_ptr =  vap[2];
            if (eigenvector1.get()) {
              evect1_ptr[0] = vec_propre[0][0];
              evect1_ptr[1] = vec_propre[1][0];
              evect1_ptr[2] = vec_propre[2][0];
              if (evect1_ptr[0]!=evect1_ptr[0]) {
                std::cout << "EigenDecomp::TemplateProcess() \t "
                          << "Numerical Problem with evect1"
                          << std::endl;
                matrix.PrintSelf();
              }
            }
            if (eigenvector2.get()) {
              evect2_ptr[0] = vec_propre[0][1];
              evect2_ptr[1] = vec_propre[1][1];
              evect2_ptr[2] = vec_propre[2][1];
              if (evect2_ptr[0]!=evect2_ptr[0]) {
                std::cout << "EigenDecomp::TemplateProcess() \t "
                          << "Numerical Problem with evect2"
                          << std::endl;
                matrix.PrintSelf();
              }
            }
            
            if (eigenvector3.get()) {
              evect3_ptr[0] = vec_propre[0][2];
              evect3_ptr[1] = vec_propre[1][2];
              evect3_ptr[2] = vec_propre[2][2];
              if (evect3_ptr[0]!=evect3_ptr[0]) {
                std::cout << "EigenDecomp::TemplateProcess() \t "
                          << "Numerical Problem with evect3"
                          << std::endl;
              }
            }
          } else // Diagonal
          {
            if (eigenvalue1.get()) *eval1_ptr =  1;
            if (eigenvalue2.get()) *eval2_ptr =  1;
            if (eigenvalue3.get()) *eval3_ptr =  1;
            if (eigenvector1.get()) {
              evect1_ptr[0] = 1;
              evect1_ptr[1] = 0;
              evect1_ptr[2] = 0;
            }
            if (eigenvector2.get()) {
              evect2_ptr[0] = 0;
              evect2_ptr[1] = 1;
              evect2_ptr[2] = 0;
            }
            
            if (eigenvector3.get()) {
              evect3_ptr[0] = 0;
              evect3_ptr[1] = 0;
              evect3_ptr[2] = 1;
            }
          }
        } // mask_ok
        in_ptr += input_incx;
        if (eigenvalue1.get()) eval1_ptr++;
        if (eigenvalue2.get()) eval2_ptr++;
        if (eigenvalue3.get()) eval3_ptr++;
        if (eigenvector1.get()) evect1_ptr+=vect_incx;
        if (eigenvector2.get()) evect2_ptr+=vect_incx;
        if (eigenvector3.get()) evect3_ptr+=vect_incx;
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
    case WT_FLOAT:   TemplateProcess<float,float>   (threadid); break;
    case WT_DOUBLE:  TemplateProcess<double,float>  (threadid); break;
    default: CLASS_ERROR((boost::format(" format %1% not available")%
                                    in->GetFormat()).str().c_str());
  }

}

//------------------------------------------------------------------------------
bool EigenDecomp::check_eigenvalue_image(InrImage::ptr im) 
{
  if (!im.get()) return false;
  InrImage::ptr in = params.GetInput();
  return  (  (im->DimX()==in->DimX())
           &&(im->DimY()==in->DimY())
           &&(im->DimZ()==in->DimZ())
           &&(im->GetVDim()==1)
           &&(im->_format==WT_FLOAT));
}

//------------------------------------------------------------------------------
bool EigenDecomp::check_eigenvector_image(InrImage::ptr im) 
{
  if (!im.get()) return false;
  InrImage::ptr in = params.GetInput();
  return  (  (im->DimX()==in->DimX())
           &&(im->DimY()==in->DimY())
           &&(im->DimZ()==in->DimZ())
           &&(im->GetVDim()==3)
           &&((im->_format==WT_FLOAT)||(im->_format==WT_SIGNED_SHORT)));
}

//------------------------------------------------------------------------------
void EigenDecomp::Run() 
{
  InrImage::ptr in = params.GetInput();
  
  // Create output images
  if ((enable_eigenvalue1)&&(!check_eigenvalue_image(eigenvalue1))) {
    eigenvalue1 = InrImage::ptr(new InrImage(WT_FLOAT,1,"eigenval1.ami.gz",
                                             in.get()));
    eigenvalue1->InitZero();
  }
  if ((enable_eigenvalue2)&&(!check_eigenvalue_image(eigenvalue2))) {
    eigenvalue2 = InrImage::ptr(new InrImage(WT_FLOAT,1,"eigenval2.ami.gz",
                                             in.get()));
    eigenvalue2->InitZero();
  }
  if ((enable_eigenvalue3)&&(!check_eigenvalue_image(eigenvalue3))) {
    eigenvalue3 = InrImage::ptr(new InrImage(WT_FLOAT,1,"eigenval3.ami.gz",
                                             in.get()));
    eigenvalue3->InitZero();
  }

  if ((enable_eigenvector1)&&(!check_eigenvector_image(eigenvector1))) {
    eigenvector1 = InrImage::ptr(new InrImage(WT_FLOAT,3,"eigenvect1.ami.gz",
                                             in.get()));
    eigenvector1->InitZero();
  }
  if ((enable_eigenvector2)&&(!check_eigenvector_image(eigenvector2))) {
    eigenvector2 = InrImage::ptr(new InrImage(WT_FLOAT,3,"eigenvect2.ami.gz",
                                             in.get()));
    eigenvector2->InitZero();
  }
  if ((enable_eigenvector3)&&(!check_eigenvector_image(eigenvector3))) {
    eigenvector3 = InrImage::ptr(new InrImage(WT_FLOAT,3,"eigenvect3.ami.gz",
                                             in.get()));
    eigenvector3->InitZero();
  }
  
  ImageToImageFilter::Run();
}

} // end namespace ami
