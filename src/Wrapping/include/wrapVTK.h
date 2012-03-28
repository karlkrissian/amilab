//
// C++ Interface: wrapVTK
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
#include "WrapVTKConfigure.h"
#include "ami_object.h"

/** function that add the wrapping of vtk library
 *  to the AMI language
 */
WrapVTK_EXPORT void __cdecl AddWrapVTK(AMIObject::ptr & ); 


#endif // _WRAPVTK_H_
