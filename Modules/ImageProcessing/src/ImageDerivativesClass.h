#pragma once
#ifndef _ImageDerivativesClass_h_
#define _ImageDerivativesClass_h_

// deal with EXPORT...

class ImageDerivativesClass {

public:
  /**
       Structure Tensor computation
       
  parameter(s):
    #1 VAR_IMAGE: input scalar image (2D or 3D)
    #2 expr: sigma, first Gaussian convolution
    #3 expr: rho, second Gaussian convolution

  description(s):
  This function computes the structure tensor of the image I,
  defined by 

    T_{\sigma, \rho}(I) = \G_\rho * {\nabla_{\sigma} I  {\nabla_{\sigma} I}^t}

  which is the convolution with a Gaussian kernel of
  standard deviation rho of the matrix defined by the cross-product
  of the smoothed gradient of the image (smoothed with a Gaussian
  convolution of standard deviation sigma).
  The function then computes the eigenvalues and the eigenvectors
  of this matrix, and saves them in the following 
  variables, in the case of 3D images:
  - imagename_STvep1: normalized eigenvector associated with the 
        maximal eigenvalue
  - imagename_STvep2:
  - imagename_STvep3: normalized eigenvector associated with the 
        minimal eigenvalue
  - imagename_STvap1: maximal eigenvalue
  - imagename_STvap2:
  - imagename_STvap3: minimal eigenvalue
  where imagename is the name of the image variable given by
  the first parameter.

  Example(s):
  [AMILab] i = Image "tore.inr.gz"
  [AMILab] StructTensor(i,1,2)
  [AMILab] Show vars
  VARIABLES:
    0           i         image    
    1    i_STvep1         image    
    2    i_STvep2         image    
    3    i_STvep3         image    
    4    i_STvap1         image    
    5    i_STvap2         image    
    6    i_STvap3         image    
  [AMILab] Show i
  [AMILab] i_draw.setvector(1,i_STvep1)
  [AMILab] i_draw.setvector(2,i_STvep2)
  [AMILab] i_draw.setvector(3,i_STvep3)
  */
  static void StructTensor(InrImage::ptr input, std::string name, double sigma, double rho, InrImage::ptr mask=InrImage::ptr());

  
}


#endif 
//  _ImageDerivativesClass_h_
