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

#ifndef _WRAPITK_H_
#define _WRAPITK_H_

#include "paramlist.h"


/** function that add the wrapping from ITK library
 *  to the AMI language
 */
void AddWrapITK(); 
void wrap_ITK(ParamList* p);

#endif // _WRAPITK_H_
