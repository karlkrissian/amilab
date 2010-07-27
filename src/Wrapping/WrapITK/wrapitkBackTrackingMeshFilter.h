#ifndef _wrapitkBackTrackingMeshFilter_h_
#define _wrapitkBackTrackingMeshFilter_h_

#include "paramlist.h"
#include "BasicVariable.h"

// Use a ptr to obtain the output mesh
BasicVariable::ptr wrap_itkBackTrackingMeshFilter2D(ParamList*);
BasicVariable::ptr wrap_itkBackTrackingMeshFilter3D(ParamList*);

#endif // _wrapitkBackTrackingMeshFilter_h_