
#include "DistanceTransformClass.h"
#include "Chamfer.h"
#include "DistanceTransforms.h"

//------------------------------------------------------------------------------
InrImage::ptr DistanceTransformClass::BorgeforsDT(InrImage::ptr input, 
                                                  float maxdist)
{

  InrImage::ptr res ( Func_Chamfer2( input.get(),
                                     0.92644f, 1.34065f, 1.65849f,
                                     maxdist));
  return res;
}


//------------------------------------------------------------------------------
InrImage::ptr DistanceTransformClass::BorgeforsSDT( InrImage::ptr input, 
                                                    float maxdist)
{
  
  InrImage::ptr res ( Func_Chamfer2Signed(input.get(),
                                          0.92644f, 1.34065f, 1.65849f,
                                          maxdist));
  return res;
}

//------------------------------------------------------------------------------
InrImage::ptr DistanceTransformClass::ChamferDT( InrImage::ptr input, 
                                                 float a, 
                                                 float b, 
                                                 float c)
{
  InrImage::ptr res ( Func_Chamfer(input.get(), a, b, c));
  return res;
}

//------------------------------------------------------------------------------
InrImage::ptr DistanceTransformClass::Chamfer2DT( InrImage::ptr input, 
                                                 float a, 
                                                 float b, 
                                                 float c,
                                                 float maxdist
                                               )
{
  InrImage::ptr res ( Func_Chamfer2(input.get(), a, b, c, maxdist));
  return res;
}

// //------------------------------------------------------------------------------
// InrImage::ptr DistanceTransformClass::vtkSignedBorgefors( InrImage::ptr input, 
//                                                           float maxdist)
// {
//   InrImage::ptr res ( Func_vtkSignedBorgefors(input.get(),
//                                               maxdist));
// }

//------------------------------------------------------------------------------
InrImage::ptr DistanceTransformClass::PropagationDist( InrImage::ptr input, 
                                                       float maxdist)
{
  InrImage::ptr res ( Func_PropagationDistance( input.get(),
                                                maxdist));
  return res;
}

