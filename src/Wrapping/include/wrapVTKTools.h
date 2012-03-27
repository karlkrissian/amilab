//
// C++ Interface: wrapVTKTOOLS
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2012
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _WRAPVTKTOOLS_H_
#define _WRAPVTKTOOLS_H_

#include "paramlist.h"

void AddWrapVTKTools(AMIObject::ptr & obj); 

// Wrapping functions:

InrImage* vtkAnisoGS                       (ParamList*);
BasicVariable::ptr Wrap_vtkSkeleton2Lines  (ParamList* p);
BasicVariable::ptr Wrap_vtkSphere          (ParamList* p);
BasicVariable::ptr wrap_vtkGPURayCasting   (ParamList* p);
BasicVariable::ptr wrap_wxVTKMedical3      (ParamList* p);
BasicVariable::ptr wrap_wxVTKFrame         (ParamList* p);
BasicVariable::ptr wrap_ToVtkImageData     (ParamList* p);
BasicVariable::ptr wrap_FromVtkImageData   (ParamList* p);
BasicVariable::ptr wrap_ToVtkPolyData     (ParamList* p);
BasicVariable::ptr wrap_FromVtkPolyData   (ParamList* p);


#endif // _WRAPVTKTOOLS_H_
