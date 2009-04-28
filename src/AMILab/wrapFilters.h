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

#ifndef _WRAPFILTERS_H_
#define _WRAPFILTERS_H_

#include "inrimage.hpp"
#include "EigenDecomp.h"
#include "paramlist.h"
#include "Variable.hpp"

/** function that add the wrapping of different filters
 *  to the AMI language
 */
void AddWrapFilters();


// Wrapping functions:

InrImage* CurvatureDifference(ParamList*);

InrImage* RampPreservingPeronaMalik1(ParamList*);

InrImage* RampPreservingPeronaMalik2(ParamList*);

InrImage* NSim(ParamList* p);

void NSim2(ParamList* p);

InrImage* NLmeans(ParamList*);

InrImage* NLmeans_fast(ParamList*);

InrImage* NLmeans_MRI(ParamList*);

InrImage* WrapLeastSquares(ParamList*);

Variable::ptr Wrap_EigenDecomp(ParamList*);

Variable::ptr Wrap_SmoothLinesToSplines(ParamList* p);

#endif // _WRAPFILTERS_H_
