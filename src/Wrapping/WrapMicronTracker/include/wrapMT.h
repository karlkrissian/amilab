//
// C++ Interface: mtwrap
//
// Description: Wrapping of some mt camera functionalities
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _MTWRAP_H
#define _MTWRAP_H

#include "paramlist.h"

/** function that add the wrapping of fluid function
 *  to the AMI language
 */
void AddWrapMT(); 

// Wrapping functions:


BasicVariable::ptr GetImageMT(ParamList* p);
BasicVariable::ptr GetStoreXpointMT(ParamList* p);
BasicVariable::ptr Get2DXpointMT(ParamList* p);


#endif // _MTWRAP_H
