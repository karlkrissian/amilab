
#include "ImageDerivativesClass.h"
#include "StructureTensor.h"
#include "HessianMatrix.h"
#include "Eigen3D.h"
#include "DiscSecDerGrad.h"
#include "NormGrad.h"
#include "DiscNormGrad.h"
#include "DiscMeanCurvature.h"
#include "ImageDerivatives.h"

//------------------------------------------------------------------------------
void ImageDerivativesClass::StructTensor(InrImage::ptr input, std::string name, 
                                         double sigma, double rho, 
                                         InrImage::ptr mask)
{
  Func_StructureTensor( input.get(), name.c_str(), sigma, rho, mask.get());
}


//------------------------------------------------------------------------------
void ImageDerivativesClass::StructTensorH(InrImage::ptr input, std::string name, 
                                          double sigma, double beta, 
                                          InrImage::ptr mask, bool grad_save )
{
  Func_StructureTensorHessian(  input.get(),
                                name.c_str(),
                                sigma,
                                beta,
                                mask.get(),
                                grad_save
                             );
}

//------------------------------------------------------------------------------
void ImageDerivativesClass::HessianMatrix(InrImage::ptr input
                                          ,
                                          std::string   name
                                          ,
                                          double        sigma
                                          ,
                                          double        gamma
                                          ,
                                          InrImage::ptr mask
                                        )
{
  Func_HessianMatrix( input.get(),
                      name.c_str(),
                      sigma,
                      gamma,
                      mask.get()  // mask
                    );
}


//------------------------------------------------------------------------------
void ImageDerivativesClass::Derivatives(InrImage::ptr input
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
                              InrImage::ptr mask
                             )
{
    Func_Derivatives( input.get(),
                      name.c_str(),
                      sigma,
                      gamma,
                      mask.get(),
                      H1,   // 1st eigenvalue | eigenvector?
                      H2,  // 2nd eigenvalue | eigenvector?
                      H3,  // 3rd eigenvalue | eigenvector?
                      G  // Gradient vector?
                    );
}

//------------------------------------------------------------------------------
void ImageDerivativesClass::HessianEVal(
                                          InrImage::ptr input
                                          ,
                                          std::string name
                                          ,
                                          double sigma
                                          , 
                                          double gamma
                                          , 
                                          InrImage::ptr mask
                                          ,
                                          int index
                                        )
{
  Func_HessianVap(
                  input.get(),
                  name.c_str(),
                  sigma,
                  gamma,
                  mask.get(),
                  index
      );
}

//------------------------------------------------------------------------------
void ImageDerivativesClass::Eigen3D(
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
                                    InrImage::ptr mask 
                                    )
{
    Func_Eigen3D(
                  name.c_str(),
                  Mxx.get(),
                  Mxy.get(),
                  Mxz.get(),
                  Myy.get(),
                  Myz.get(),
                  Mzz.get(),
                  mask.get()
                  );
}

//------------------------------------------------------------------------------
void ImageDerivativesClass::Eigen2D(
                                    std::string name
                                    ,
                                    InrImage::ptr Mxx
                                    ,
                                    InrImage::ptr Mxy
                                    ,
                                    InrImage::ptr Myy
                                    ,
                                    InrImage::ptr mask
                                    )
{
    Func_Eigen2D(
                  name.c_str(),
                  Mxx.get(),
                  Mxy.get(),
                  Myy.get(),
                  mask.get()
                  );
}

//------------------------------------------------------------------------------
void ImageDerivativesClass::discsecdergrad(
                            InrImage::ptr input,
                            InrImage::ptr Isecder,
                            InrImage::ptr Inormgrad 
                          )
{
  Func_DiscSecDerGrad(input.get(),Isecder.get(),Inormgrad.get());
}

//------------------------------------------------------------------------------
InrImage::ptr ImageDerivativesClass::normgrad(
                        InrImage::ptr input,
                        double sigma,
                        double support
                      )
{
  InrImage::ptr res ( Func_NormGrad( input.get(), sigma, support));
  return res;
}

//------------------------------------------------------------------------------
InrImage::ptr ImageDerivativesClass::discnormgrad(  InrImage::ptr input )
{
  InrImage::ptr res (Func_DiscNormGrad( input.get()));
  return res;
}

//------------------------------------------------------------------------------
InrImage::ptr ImageDerivativesClass::DiscMeanCurvature( InrImage::ptr input )
{
  InrImage::ptr res (Func_DiscMeanCurvature( input.get()));
  return res;
}


//------------------------------------------------------------------------------
InrImage::ptr ImageDerivativesClass:: Laplacian( InrImage::ptr input )
{
  InrImage::ptr res ( Func_Laplacian(input.get()));
  return res;
}

//------------------------------------------------------------------------------
InrImage::ptr ImageDerivativesClass::secdergrad(
                                                InrImage::ptr input,
                                                double sigma )
{
  InrImage::ptr res (Func_SecDerGrad( input.get(), sigma));
  return res;
}

//------------------------------------------------------------------------------
InrImage::ptr ImageDerivativesClass::secdergrad2(
                                                InrImage::ptr input,
                                                double sigma )
{
  InrImage::ptr res (Func_SecDerGrad2( input.get(), sigma));
  return res;
}

//------------------------------------------------------------------------------
InrImage::ptr ImageDerivativesClass::gradient(
                                                InrImage::ptr input,
                                                double sigma )
{
  InrImage::ptr res (Func_Gradient( input.get(), sigma));
  return res;
}

//------------------------------------------------------------------------------
InrImage::ptr ImageDerivativesClass::filter(
                      InrImage::ptr input,
                      double sigma,
                      int derx,
                      int dery,
                      int derz)
{
  InrImage::ptr res( Func_Filter( input.get(), sigma, derx, dery, derz));
  return res;
}
