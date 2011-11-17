//
// C++ Interface: wrap_ultrasound
//
// Description: Wrapping of some mt camera functionalities
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _USWRAP_H
#define _USWRAP_H

#include "paramlist.h"

/** function that add the wrapping of especific ultrasound functions
 *  to the AMI language
 */
void AddWrapUS(); 

// Wrapping functions:


BasicVariable::ptr Initialize(ParamList* p);



#endif // _USWRAP_H

