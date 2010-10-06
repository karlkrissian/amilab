//
// C++ Implementation: LeastSquares
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "AMILabConfig.h"

#include "LeastSquares.h"
#include <vnl/algo/vnl_matrix_inverse.h>
#include <vector>
#include <iostream>
using namespace std;

//--------------------------------------------------
//
// inputs:
// 1. input image to fit locally
// 2. input vectorial image, the size of the vector is the 
//    number of parameters and the values are the parameters to fit
//    for example the position in Y, X and 1
// 3. weights image, smaller image representing the weights for the
//    Least Square minimization, its size is the local fitting size
//
InrImage*     Func_LeastSquares(  InrImage* input, 
                                  InrImage* basis,
                                  InrImage* weights,
                                  InrImage* mask,
                                  bool process_border )
{
  int x,y,z,i,n;
  int x1,y1,z1;
  int posx,posy,posz;

  int vdim = basis->GetVDim();
  InrImage* result;
  vector<double> initzeros(vdim);


  // Check that all images have the same dimensions ! ...
  // basis and weights should have the same X,Y,Z dimensions
  if ((basis->DimX()!=weights->DimX()) ||
      (basis->DimY()!=weights->DimY()) ||
      (basis->DimZ()!=weights->DimZ()) )
  {
    fprintf(stderr,"Error in Func_LeastSquares() \n basis and weights of different dimensions");
    return NULL;
  }

  // Check that all images have the same dimensions ! ...
  // input and mask should have the same X,Y,Z dimensions
  if (mask!=NULL)
  if ((input->DimX()!=mask->DimX()) ||
      (input->DimY()!=mask->DimY()) ||
      (input->DimZ()!=mask->DimZ()) )
  {
    fprintf(stderr,"Error in Func_LeastSquares() \n input and mask of different dimensions");
    return NULL;
  }

  result = new InrImage(WT_FLOAT,vdim,"LeastSquareResult.ami.gz",input);
  printf("result vdim = %d \n",result->GetVDim());
  for (n=0;n<vdim;n++) initzeros[n]=0.0;
  result->InitImage(&(initzeros.front()),vdim);

  // Precompute M = (X^T W X)^-1
  vnl_matrix<double> X(basis->Size(),vdim);
  vnl_matrix<double> W(basis->Size(),basis->Size(),0.0);
  vnl_matrix<double> W1(basis->Size(),basis->Size(),0.0);
  vnl_matrix<double> M(vdim,vdim);
  vnl_matrix<double> M1(vdim,vdim);
  M.fill(0.0);

  // fill X and W
  basis  ->InitBuffer();
  weights->InitBuffer();
  
  for(i=0;i<basis->Size();i++) {
    for(n=0;n<vdim;n++)
        X(i,n) = basis->VectValeurBuffer(n);
    W(i,i) = weights->ValeurBuffer();
    basis  ->IncBuffer();
    weights->IncBuffer();
  }

  M = X.transpose() * W * X;
  M = vnl_matrix_inverse<double>(M);

  vnl_matrix<double> WY(basis->Size(),1);
  vnl_matrix<double> C(vdim,1);

  int center_x,center_y,center_z;
  center_x = weights->DimX()/2;
  center_y = weights->DimY()/2;
  center_z = weights->DimZ()/2;

  int percent=0,percent_new=0,pos=0;
  for(z=0;z<input->DimZ();z++)
  for(y=0;y<input->DimY();y++)
  for(x=0;x<input->DimX();x++,pos++) {
    if ((mask==NULL)||((*mask)(x,y,z)>0.5)) {

        percent_new = (int) 100.0*pos/(1.0*input->Size());
        if (percent_new>=percent+5) {
          percent=percent_new;
          std::cout << "done "<< percent << "%" << std::endl;
        }
        bool missingpoints = false;
        // get the WY matrix
        WY.fill(0.0);
        W1 = W;
        i=0;
        for(z1=0;z1<weights->DimZ();z1++) 
        for(y1=0;y1<weights->DimY();y1++)
        for(x1=0;x1<weights->DimX();x1++,i++)
        {
            posx = x+x1-center_x;
            posy = y+y1-center_y;
            posz = z+z1-center_z;
            if (input->CoordOK(posx,posy,posz)) {
                WY(i,0) = (*input)(posx,posy,posz)*W(i,i);
            } else {
              W1(i,i) = 0;
              missingpoints = true;
            }
        }
        // compute and save the result
        C = (X.transpose()*WY);
        if (missingpoints && process_border) {
          // recompute matrix inversion
          M1.fill(0.0);
          M1 = X.transpose() * W1 * X;
          M1 = vnl_matrix_inverse<double>(M1);
          C = M1 * C;
        } else
          C = M * C;
        result->BufferPos(x,y,z);
        for(n=0;n<vdim;n++)
            result->VectFixeValeur(n,C(n,0));
    }
  }

  return result;
}
