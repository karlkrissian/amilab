
#include "ImageDerivativesClass.h"

static void ImageDerivativesClass::StructTensor(InrImage::ptr input, std::string name, double sigma, double rho, InrImage::ptr mask)
{
  Func_StructureTensor( im.get(), name.c_str(), sigma, rho, mask.get());
}


