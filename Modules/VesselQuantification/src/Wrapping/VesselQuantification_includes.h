
#pragma once

#include "PruebaClass.h"
#include "vtkContourFilter.h"
#include "vtkImageShiftScale.h"
#include "vtkParametricSpline.h"
#include "vtkParametricFunctionSource.h"
#include "vtkImagePlaneWidget.h"
#include "vtkTransformPolyDataFilter.h"
#include "vtkPlaneWidget.h"

#include "funcion1.h"

#ifdef __GCCXML__
 
  //----------------------------------------------------------------------------
  // std::vector of basic types
  template class std::vector<VesselQuantif::Point3D>;

  // short names
  typedef std::vector<VesselQuantif::Point3D>       vector_Point3D;
  
  // instanciate iterators
  vector_Point3D::iterator vpi;

#endif __GCCXML__
  