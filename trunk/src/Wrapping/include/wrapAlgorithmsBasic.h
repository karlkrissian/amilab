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

#ifndef _wrapAlgorithmsBasic_h_
#define _wrapAlgorithmsBasic_h_

#include "inrimage.hpp"
#include "EigenDecomp.h"
#include "paramlist.h"
#include "Variable.hpp"


/** function that adds the wrapping of different filters
 *  to the AMILab language
 */
void wrapAlgorithmsBasic();


// Wrapping functions:
InrImage* wrapFastLocalSumDir(ParamList*);

InrImage* wrapFastLocalSumDir2(ParamList*);


#endif // _wrapAlgorithmsBasic_h_
