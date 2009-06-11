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
void AddWrapVTK(); 

// Wrapping functions:


InrImage* vtkAnisoGS                  (ParamList*);
Variable::ptr Wrap_vtkSkeleton2Lines  (ParamList* p);
Variable::ptr Wrap_vtkSphere          (ParamList* p);


#endif // _WRAPVTK_H_
