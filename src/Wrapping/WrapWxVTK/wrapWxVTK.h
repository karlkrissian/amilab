//
// C++ Interface: wrapWxVTK
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _WRAPWXVTK_H_
#define _WRAPWXVTK_H_

#include "paramlist.h"

/** function that add the wrapping of wxVTK
 *  to the AMI language
 */
void AddWrapWxVTK(AMIObject::ptr & obj); 

BasicVariable::ptr wrap_wxVTKMedical3      (ParamList* p);
BasicVariable::ptr wrap_wxVTKFrame         (ParamList* p);

#endif // _WRAPWXVTK_H_
