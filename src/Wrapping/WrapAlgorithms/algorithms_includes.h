

#include "GeneralGaussianFilter.h"
#include "CalculRepCercle.hpp"
#include "CircleBoundaries3D.h"
#include "vtkLevelSetFastMarching.h"
#include "vtkFastMarching_nD_plus.h"
#include "Gradient.h"
#include "amiShortestPathClass.h"
#include "amiBackgroundComponents.h"

#include "Curvatures.h"

#include "amiComputePositiveArea.hpp"

#include "amiImageAddScalar.h"
#include "amiGrayscaleMorpho.h"
#include "amiIntensityBasedRegionGrowing.h"
#include "amiThinning.h"
#include "amiImageConvolution1D.h"
#include "amiRecursiveGaussianConvolution1D.h"

#include "amiFind.h"
#include "amivtkFastMarchingFunctions.h"
#include "amiFieldOrientationRegionGrowing.h"

//#include "amiImageExtent.h"

#include "amiEigenDecomp.h"
#include "amiAnisoGS.h"
#include "amiAnisoGS_NRAD.h"
#include "AddImageNoise.h"

#include "amiLineRecons.h"

#include "ImageLinearInterpolator.h"

#include "func_globalstats.h"
#include "localstats.h"
#include "fonctions.h"

#include "StructureTensor.h"
#include "ImageDerivatives.h"

#ifdef __GCCXML__
  template class ami::ImageExtent<float>;
#endif // __GCCXML__

#include "amiSRAD.h"
#include "gnuplot.hpp"
#include "ContinuousMorphology.h"
#include "func_imagebasictools.h"

#ifdef __GCCXML__
  template amimage::operator unsigned short*();
  template amimage::operator unsigned char* ();
  template amimage::operator short*         ();
  template amimage::operator float*         ();
  template amimage::operator double*        ();
#endif // __GCCXML__
  
  
// why do I need this include ??
//#include "vcl_config_compiler.h"
//#define vcl_generic_complex_STD 
//#define vcl_generic_iosfwd_STD
//#include "vcl_complex.h"
//#include "vnl/vnl_matrix.h"

/*
 * #include "vcl_limits.h"
// trying vnl_matrix ...
#include "vnl/vnl_matrix.h"
#include "vnl/vnl_vector.h"
#include "vnl/algo/vnl_symmetric_eigensystem.h"

#ifdef __GCCXML__
  template class vnl_matrix<double>;
  template class vnl_vector<double>;
  template class vnl_symmetric_eigensystem<double>;
#endif // __GCCXML__

#include "vnl/vnl_vector_fixed.h"

#ifdef __GCCXML__
  template class vnl_vector_fixed<double,3>;
#endif // __GCCXML__
*/
/*
// trying itk
#include <itkImage.h>
#include <itkSmartPointer.h>

#ifdef __GCCXML__
  template class itk::Image<float,2>;
  template class itk::SmartPointer<itk::Image<float, 2u> >;
#endif // __GCCXML__

#include <itkDefaultPixelAccessor.h>
#ifdef __GCCXML__
  template class itk::DefaultPixelAccessor<float>;
#endif // __GCCXML__

#include <itkImageRegion.h>
#ifdef __GCCXML__
  template class itk::ImageRegion<2u>;
#endif // __GCCXML__


// trying std
#include <list>
#ifdef __GCCXML__
  template class std::list<int, std::allocator<int> >;
  std::list<int>::iterator __t;
  std::list<int>::const_iterator __t1;
  //template class std::list<int>::iterator;
  //template class std::list<int>::const_iterator;
#endif // __GCCXML__
*/
// trying iostream
#include <iostream>
#include <sstream>
#include <string>

#ifdef __GCCXML__
  
#endif // __GCCXML__
