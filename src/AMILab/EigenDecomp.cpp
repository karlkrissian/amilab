//
// C++ Implementation: EigenDecomp
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//


#include "EigenDecomp.h"
#include "FloatMatrix.hpp"
#include "Eigen.hpp"

//--------------------------------------------------------------------
//  Return a vector of 6 pointers to images including
//  eigenvalues and eigenvectors or empty pointers depending on flags
// input should be a vectorial image of 3 (for symmetric matrices) 
// or 6 components
InrImage::ptr_vector EigenDecomp2D(InrImage* im, 
        int value_flag, 
        int vector_flag,
        InrImage* mask)
{
  // Create resulting images
  InrImage::ptr_vector result;

  return result;
}

//--------------------------------------------------------------------
//  Return a vector of images including
//  eigenvalues and eigenvectors depending on flags
// input should be a vectorial image of 6 (for symmetric matrices) 
// or 9 components
InrImage::ptr_vector EigenDecomp3D(InrImage* im, 
        int value_flag, 
        int vector_flag,
        InrImage* mask)
{
  // Create resulting images
  InrImage::ptr_vector result(6);

  if (im==NULL) {
    cerr << "EigenDecomp3D()\t input image empty " << endl;
    return result;
  }

  int vdim;
  vdim = im->GetVDim();
  if ((vdim!=6)&&(vdim!=9)) {
    cerr << "EigenDecomp3D()\t image must be vectorial with vector dimension 6 or 9 " << endl;
    return result;
  }

  int             x,y,z;
  int             n;
  int             i,j;
  FloatMatrix     matrice(3,3);
  float           vap[3];
  FloatMatrix     vec_propre(3,3);
  unsigned char   Diagonale = false;
  int             niter;
  bool            mask_ok;
  size_t          per,prev_per=0;


  if ( value_flag & GET_FIRST ) {
    result[0] = InrImage::ptr(new InrImage(WT_FLOAT,1,
                              "first_eigenvalue.ami.gz",im));
  }

  if ( value_flag & GET_SECOND ) 
    result[1] = InrImage::ptr(new InrImage(WT_FLOAT,1,
                              "second_eigenvalue.ami.gz",im));

  if ( value_flag & GET_THIRD )
    result[2] = InrImage::ptr(new InrImage(WT_FLOAT,1,
                              "third_eigenvalue.ami.gz",im));

  if ( vector_flag & GET_FIRST )
    result[3] = InrImage::ptr(new InrImage(WT_FLOAT,3,
                              "first_eigenvector.ami.gz",im));

  if ( vector_flag & GET_SECOND )
    result[4] = InrImage::ptr(new InrImage(WT_FLOAT,3,
                              "second_eigenvector.ami.gz",im));

  if ( vector_flag & GET_THIRD )
    result[5] = InrImage::ptr(new InrImage(WT_FLOAT,3,
                              "third_eigenvector.ami.gz",im));

  // initialize images to 0
  for(n=0;n<3;n++)
    if (result[n].use_count()) result[n]->InitImage(0);
  for(n=3;n<6;n++)
    if (result[n].use_count()) result[n]->InitImage(0,0,0);

  n=0;
  im->InitBuffer();
  for(n=0;n<6;n++)
    if (result[n].use_count()) result[n]->InitBuffer();

  for( z=0; z<im->DimZ(); z++)
  for( y=0; y<im->DimY(); y++)
  for( x=0; x<im->DimX(); 
      x++,
      n++,
      im->IncBuffer()) 
  {
    per = (int)((100.0*n)/im->Size());
    if ((int)(per/10) != (int)(prev_per/10)) {
      printf(" %ld %% ",per);
      fflush(stdout);
      prev_per = per;
    }

    mask_ok = (mask==NULL);
    if (!mask_ok)
      mask_ok =  ((*mask)(x,y,z)>=0.5);

    if (mask_ok) {
      // fill the matrix
      n=0;
      for(i=0;i<3;i++)
      for(j=0;j<3;j++) {
        if (vdim==6) {
          if (i<=j) {
            matrice[i][j] = im->VectValeurBuffer(n);
            n++;
          } else
            matrice[i][j] = matrice[j][i];
        }
        if (vdim==9) {
          matrice[i][j] = im->VectValeurBuffer(n);
          n++;
        }
      }
  
      // Calcul des vep et des vap dans les images associees
      // use vnl here?
      Diagonale = jacobi( 
              matrice, 
              3, 
              vap, 
              vec_propre, 
              &niter );
  
      if (Diagonale) {
          eigsrt(vap,  vec_propre, 3);
          if (result[0].use_count()) result[0]->FixeValeur( vap[0]);
          if (result[1].use_count()) result[1]->FixeValeur( vap[1]);
          if (result[2].use_count()) result[2]->FixeValeur( vap[2]);
          if (result[3].use_count())
            result[3]->VectFixeValeurs( vec_propre[0][0], 
                                        vec_propre[1][0], 
                                        vec_propre[2][0]);
          if (result[4].use_count())
            result[4]->VectFixeValeurs( vec_propre[0][1], 
                                        vec_propre[1][1], 
                                        vec_propre[2][1]);
          if (result[5].use_count())
            result[5]->VectFixeValeurs( vec_propre[0][2], 
                                        vec_propre[1][2], 
                                        vec_propre[2][2]);
      }
    } // mask_ok


    for(n=0;n<6;n++)
      if (result[n].use_count()) result[n]->IncBuffer();

  } // for x

  printf("\n");

  return result;

}  // EigenDecomp3D()

//--------------------------------------------------------------------
//  Return a vector of images including
//  eigenvalues and eigenvectors depending on flags
//  use image dimensions to call the 2D or the 3D versions
InrImage::ptr_vector EigenDecomp(InrImage* im, 
        int value_flag, 
        int vector_flag,
        InrImage* mask)
{
  printf("starting EigenDecomp\n");
  InrImage::ptr_vector result;

  if (im==NULL) {
    cerr << "EigenDecomp()\t input image empty " << endl;
    return result;
  }

  if (im->DimZ()==1)
    return EigenDecomp2D(im,value_flag,vector_flag,mask);
  else
    return EigenDecomp3D(im,value_flag,vector_flag,mask);
}


