#pragma once
#ifndef _ImageDerivativesClass_h_
#define _ImageDerivativesClass_h_

#include "inrimage.hpp"
// deal with EXPORT...

class ImageDerivativesClass {

protected:
  // Private constructor to avoid wrapping
  ImageDerivativesClass() {}
  ~ImageDerivativesClass() {}
  
private:
  ImageDerivativesClass(const ImageDerivativesClass&);  // Not implemented.
  void operator=(const ImageDerivativesClass&);  // Not implemented.

public:
    /**
    *  Structure Tensor computation
    *   This function computes the structure tensor of the image I, defined by:
    * \f[
    * T_{\sigma, \rho}(I) = G_\rho * {\nabla_{\sigma} I  {\nabla_{\sigma} I}^t}
    * \f]
    * 
    *   which is the convolution with a Gaussian kernel of standard deviation 
    * \f$\rho\f$ of the matrix defined by the cross-product of the smoothed gradient of 
    * the image (smoothed with a Gaussian convolution of standard deviation 
    * sigma). 
    * The function then computes the eigenvalues and the eigenvectors
    * of this matrix, and saves them in the following  variables, in the case of
    * 3D images:
    * - imagename_STvep1: normalized eigenvector associated with the  maximal 
    *                     eigenvalue
    * - imagename_STvep2:
    * - imagename_STvep3: normalized eigenvector associated with the minimal 
    *                     eigenvalue
    * - imagename_STvap1: maximal eigenvalue
    * - imagename_STvap2:
    * - imagename_STvap3: minimal eigenvalue
    * where imagename is the name of the image variable given by  the first 
    * parameter.
    * 
    * @param input  input scalar image (2D or 3D)
    * @param name      string used to create the resulting images of 
    *                  eigen(values/vectors) of the computed structure tensor.
    * @param sigma  first Gaussian convolution
    * @param rho    second Gaussian convolution
    * @param mask   mask of the places to compute the tensor.

    * \example:
    * [AMILab] i = Image "tore.inr.gz"
    *  [AMILab] StructTensor(i,1,2)
    * [AMILab] Show vars
    * VARIABLES:
    * 0           i         image
    * 1    i_STvep1         image
    * 2    i_STvep2         image
    * 3    i_STvep3         image
    * 4    i_STvap1         image
    * 5    i_STvap2         image
    * 6    i_STvap3         image
    * [AMILab] show i
    * [AMILab] i_draw.setvector(1,&i_STvep1)
    * [AMILab] i_draw.setvector(2,&i_STvep2)
    * [AMILab] i_draw.setvector(3,&i_STvep3)
    */
    static void StructTensor(
                              InrImage::ptr input
                              ,
                             std::string    name
                             ,
                             double         sigma
                             ,
                             double         rho
                             ,
                             InrImage::ptr  mask=InrImage::ptr()
                            );

    /**
      * Computes the Structure Tensor with a combination of 
      * the standard gradient based structure tensor and the square
      * of the Hessian matrix.
      * @param input     input image.
      * @param name      string used to create the resulting images of 
      *                  eigen(values/vectors) of the computed structure tensor.
      * @param sigma     inner Gaussian convolution standard deviation.
      * @param beta      coefficient for the Hessian matrix weight.
      * @param mask      mask of the places to compute the tensor.
      * @param grad_save boolean for saving the gradient vector.
      * @see StructTensor() HessianMatrix
      * @return Create several image outputs in the current context 
      * Computes eigenvalues and eigenvectors of the tensor and saves them 
      * in images:
      * i_STHvap1, i_STHvap2, i_STHvap3
      * i_STHvep1, i_STHvep2, i_STHvep3
      */
    static void StructTensorH(
                              InrImage::ptr input
                              ,
                              std::string   name
                              ,
                              double        sigma
                              ,
                              double        beta
                              ,
                              InrImage::ptr mask=InrImage::ptr()
                              ,
                              bool          grad_save = false
                            );

    /**
      * Computes the Hessian Matrix in 3D
      * Computes eigenvalues and eigenvectors of the Hessian and saves 
      * them in images:
      * i_Hvap1, i_Hvap2, i_Hvap3,
      * i_Hvep1, i_Hvep2, i_Hvep3,
      * i_Hgrad
      * @param input     input image.
      * @param name      string used to create the resulting images of 
      *                  eigen(values/vectors) of the computed tensor.
      * @param sigma     inner Gaussian convolution standard deviation.
      * @param gamma     derivative normalization parameter.
      * @param mask      mask of the places to compute the tensor.
      * @see StructTensor StructTensorH
      * @return Create several image outputs in the current context 
      * Computes eigenvalues and eigenvectors of the matrix and saves them 
      * in images:
      * i_Hvap1, i_Hvap2, i_Hvap3,
      * i_Hvep1, i_Hvep2, i_Hvep3,
      * i_Hgrad
      */
    static void HessianMatrix(InrImage::ptr input
                              ,
                              std::string   name
                              ,
                              double        sigma
                              ,
                              double        gamma = 0
                              ,
                              InrImage::ptr mask=InrImage::ptr()
                             );

    /**
     * Get first and second order derivatives,
     * for the second order derivatives, give selected
     * eigenvalues and/or eigenvectors. 
      * @param input  input image.
      * @param name   string used to create the resulting images of 
      *               eigen(values/vectors) of the computed tensor.
      * @param sigma  inner Gaussian convolution standard deviation.
      * @param gamma  derivative normalization parameter.
      * @param mask   mask of the places to compute the tensor.
     *  @param H1     1st eigenvector or eigenvalue of the Hessian matrix
     *  @param H2     2nd eigenvector or eigenvalue of the Hessian matrix
     *  @param H3     3rd eigenvector or eigenvalue of the Hessian matrix
     *  @param G      gradient vector
     * values: 0 do not save
     *         1 save the eigenvector (or vector)
     *         2 save the eigenvalue
     *         3 save both
     */

    static void Derivatives(InrImage::ptr input
                              ,
                              std::string   name
                              ,
                              double        sigma
                              ,
                              double        gamma
                              ,
                              int           H1
                              ,
                              int           H2
                              ,
                              int           H3
                              ,
                              bool          G
                              ,
                              InrImage::ptr mask=InrImage::ptr()
                             );

/*    Func_Derivatives(im.get(),
               varim->Name().c_str(),
               $5,   // sigma
               $7,   // gamma
               NULL,
               (int)$9,   // 1st eigenvalue | eigenvector?
               (int)$11,  // 2nd eigenvalue | eigenvector?
               (int)$13,  // 3rd eigenvalue | eigenvector?
               (int)$15  // Gradient vector?
               );*/
};


#endif 
//  _ImageDerivativesClass_h_
