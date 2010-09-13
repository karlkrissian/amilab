//
// C++ Interface: wrapComputePV
//
// Description: 
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrapComputePV_h_
#define _wrapComputePV_h_

#include "inrimage.hpp"
#include "paramlist.h"

// Wrapping functions:
InrImage* wrapComputePV(ParamList*);

// Wrapping functions:
InrImage* wrapComputePV_subdiv(ParamList*);

#endif // _wrapComputePV_h_
