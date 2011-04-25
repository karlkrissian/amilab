
#include "GeneralGaussianFilter.h"
#include "reponse_cercle.hpp"
#include "CircleBoundaries3D.h"
#include "vtkLevelSetFastMarching.h"
#include "vtkFastMarching_nD_plus.h"
#include "Gradient.h"
#include "ShortestPathClass.h"
#include "Curvatures.h"

// trying vnl_matrix ...
#include "vnl/vnl_matrix.h"
#include "vnl/vnl_vector.h"
#include "vnl/algo/vnl_symmetric_eigensystem.h"

template class vnl_matrix<double>;
template class vnl_vector<double>;
template class vnl_symmetric_eigensystem<double>;

#include "vnl/vnl_vector_fixed.h"
template class vnl_vector_fixed<double,3>;

// trying itk
#include <itkImage.h>
#include <itkSmartPointer.h>

template class itk::Image<float,2>;
template class itk::SmartPointer<itk::Image<float, 2u> >;

#include <itkDefaultPixelAccessor.h>
template class itk::DefaultPixelAccessor<float>;

#include <itkImageRegion.h>
template class itk::ImageRegion<2u>;
