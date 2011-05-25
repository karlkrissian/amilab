//
// C++ Interface: wrapAMIFluid
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _WRAPVTK_H_
#define _WRAPVTK_H_

#include "paramlist.h"

/** function that add the wrapping of fluid function
 *  to the AMI language
 */
void AddWrapVTK(AMIObject::ptr & obj); 

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


#endif // _WRAPVTK_H_
