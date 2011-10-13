
#include "ImageDerivativesClass.h"
#include "StructureTensor.h"
#include "HessianMatrix.h"

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
                                          double        gamma = 0
                                          ,
                                          InrImage::ptr mask=InrImage::ptr()
                                        )
{
  Func_HessianMatrix( input.get(),
                      name().c_str(),
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
                              InrImage::ptr mask=InrImage::ptr()
                             )
{
    Func_Derivatives( im.get(),
                      varim->Name().c_str(),
                      sigma,
                      gamma,
                      mask.get(),
                      H1,   // 1st eigenvalue | eigenvector?
                      H2,  // 2nd eigenvalue | eigenvector?
                      H3,  // 3rd eigenvalue | eigenvector?
                      G  // Gradient vector?
                    );
}

