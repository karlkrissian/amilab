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
     * @brief Structure Tensor computation
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
     *
     * Example:
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
    **/
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

    /**
     * Computes and returns the selected eigenvalue of the Hessian matrix for 3D
     * images.
     * @param input   Input image
     * @param name    string used to create the resulting images of 
     *                eigen(values/vectors) of the computed tensor.
     * @param sigma   Gaussian standard deviation for convolution
     * @param gamma   derivatives normalization parameter
     * @param mask    mask image
     * @param index   eigenvalue index between 1 and 3, eigenvalues are sorted
     *                based on their absolute values in descending order.
     * the returned image has the name "%s_Hvap%d" where %s is the name parameter
     * and %d is the index parameter.
     */
    static void HessianEVal(
                            InrImage::ptr input
                            ,
                            std::string   name
                            , 
                            double sigma
                            , 
                            double gamma
                            , 
                            InrImage::ptr mask
                            ,
                            int index
                           );

    /**
     * @brief Computes eigenvalues of the given 3x3 real symmetric matrix field.
     *
     * @param name string for creating output images.
     * @param Mxx 3D scalar image of component 0,0 of the matrix field
     * @param Mxy 3D scalar image of component 0,1 of the matrix field
     * @param Mxz 3D scalar image of component 0,2 of the matrix field
     * @param Myy 3D scalar image of component 1,1 of the matrix field
     * @param Myz 3D scalar image of component 1,2 of the matrix field
     * @param Mzz 3D scalar image of component 2,2 of the matrix field
     * @param mask mask image to speed-up the computation
     * @return void
     * Output images of eigenvalues are in named ${name}_Evap{1,2,3} 
     * and ${name}_Evep{1,2,3} for eigenvectors.
     * Eigenvalues are sorts the eigenvalues into descending order of 
     * their signed values.
     **/
    static void Eigen3D(
                        std::string name
                        ,
                        InrImage::ptr Mxx
                        ,
                        InrImage::ptr Mxy
                        ,
                        InrImage::ptr Mxz
                        ,
                        InrImage::ptr Myy
                        ,
                        InrImage::ptr Myz
                        ,
                        InrImage::ptr Mzz
                        ,
                        InrImage::ptr mask = InrImage::ptr()
                        );
    

    /**
     * @brief Computes eigenvalues of the given 3x3 real symmetric matrix field.
     *
     * @param name string for creating output images.
     * @param Mxx 2D scalar image of component 0,0 of the matrix field
     * @param Mxy 2D scalar image of component 0,1 of the matrix field
     * @param Myy 2D scalar image of component 1,1 of the matrix field
     * @param mask  mask image to speed-up the computation, 
     *              Defaults to InrImage::ptr().
     * @return void
     * Output images of eigenvalues are in named ${name}_Evap{1,2} 
     * and ${name}_Evep{1,2} for eigenvectors.
     * Eigenvalues are sorts the eigenvalues into descending order of 
     * their signed values.
     **/
    static void Eigen2D(
                        std::string name
                        ,
                        InrImage::ptr Mxx
                        ,
                        InrImage::ptr Mxy
                        ,
                        InrImage::ptr Myy
                        ,
                        InrImage::ptr mask = InrImage::ptr()
                        );

  
    /**
     * @brief Computes discrete second order derivatives of the image intensity
     * in the gradient direction.
     *
     * @param input Input image
     * @param Isecder Image of second order derivatives in the gradient direction
     * @param Inormgrad Image of gradient norm. Defaults to InrImage::ptr().
     * @return void
     **/
    static void discsecdergrad(
                                InrImage::ptr input,
                                InrImage::ptr Isecder,
                                InrImage::ptr Inormgrad = InrImage::ptr()
                              );

  /**
   * @brief Image Gradient Norm based on convolution with Gaussian derivatives.
   *
   * @param input Input image
   * @param sigma   Gaussian standard deviation for convolution
   * @param support Gaussian convolution suppport size (number of times the standard deviation: support.sigma) Defaults to 4.
   * @return void
   **/
  static InrImage::ptr normgrad(
                        InrImage::ptr input,
                        double sigma,
                        double support = 4
                      );
    
  /**
   * @brief Discrete gradient norm
   *
   * @param input Input image
   * @return Resulting gradient norm 
   **/
  static InrImage::ptr discnormgrad(
                        InrImage::ptr input
                      );

  /**
   * @brief Discrete mean curvature
   *
   * @param input Input image
   * @return Resulting image of mean curvature
   **/
  static InrImage::ptr DiscMeanCurvature(
                        InrImage::ptr input
                      );
  

  /**
   * @brief Computes a discrete laplacian (sum of second order derivatives),
   *    in 2D or 3D depending on the image dimension.
   * \f[
   * \Delta I = \frac{\partial^2 I}{\partial x^2}+ \frac{\partial^2 I}{\partial y^2}+ %
   *  \frac{\partial^2 I}{\partial z^2}.
   * \f]
   * 
   * @param input Input image.
   * @return Result Laplacian image.
   **/
  static InrImage::ptr Laplacian(
                        InrImage::ptr input
                      );

  /**
   * @brief Computes the second order derivative of the image intensity in the direction of the gradient.
   *
   * Take into account the voxel size, and computes the derivatives by 
   * convolution with the derivatives of a Gaussian of standard deviation given 
   * by the second parameter.
   * 
   * @param input Input image.
   * @param sigma standard deviation of the Gaussian kernel.
   * @return Result image of second order derivatives in the gradient direction.
   * Example(s):
   *  j = secdergrad(&i,1)
   * 
   * @sa filter normgrad secdergrad2
   **/
  static InrImage::ptr secdergrad(
                                  InrImage::ptr input,
                                  double sigma );

  /**
   * @brief Computes the second order derivative of the image intensity in the direction of the gradient.
   *
   * Use a voxel size of 1x1x1, and computes the derivatives by convolution with
   * the derivatives of a Gaussian of standard deviation given by the second parameter.
   * 
   * @param input Input image.
   * @param sigma standard deviation of the Gaussian kernel.
   * @return Result image of second order derivatives in the gradient direction.
   * Example(s):
   *  j = secdergrad(&i,1)
   * 
   * @sa filter normgrad secdergrad
   **/
  static InrImage::ptr secdergrad2(
                                  InrImage::ptr input,
                                  double sigma );
  
  /**
   * @brief Computes the Image gradient (vector field image).
   *
   * 
   * @param input Input image.
   * @param sigma standard deviation of the Gaussian kernel.
   * @return Result image of second order derivatives in the gradient direction.
   * Example(s):
   *  j = gradient(&i,1)
   * 
   * @sa filter normgrad secdergrad secdergrad2
   **/
  static InrImage::ptr gradient(
                                  InrImage::ptr input,
                                  double sigma );


  /**
   * @brief Apply a Gaussian (or its derivatives) convolution to the input image
   * @param im input image
   * @param sigma Gaussian standard deviation
   * @param derx derivation order in X (-1: no convolution, 0: Gaussian smoothing, 1: first order derivative, 2:second order der.)
   * @param dery same in Y
   * @param derz same in Z
   * @return pointer to the resulting image
   *        Example(s):
   *        - Convolution with a Gaussian kernel:
   *        i = Image(FLOAT,10,10,10)
   *        j = filter(&i,1,0,0,0)
   **/
  static InrImage::ptr filter(
                              InrImage::ptr input,
                              double sigma,
                              int derx = 0,
                              int dery = 0,
                              int derz = 0);

};


#endif 
//  _ImageDerivativesClass_h_
