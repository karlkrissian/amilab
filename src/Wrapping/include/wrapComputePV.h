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
BasicVariable::ptr wrapComputePV(ParamList*);

// Wrapping functions:
BasicVariable::ptr wrapComputePV_subdiv(ParamList*);

//InrImage* wrapComputeAnalyticPV(ParamList* p);
//
//InrImage* wrapComputeAnalyticPS(ParamList* p);

#endif // _wrapComputePV_h_
