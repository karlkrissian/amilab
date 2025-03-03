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

#include "wrap_NLmeans.h"

/** function that add the wrapping of different filters
 *  to the AMI language
 */
void AddWrapFilters(AMIObject::ptr& obj);
//void wrap_Filters( ParamList* p);


// Wrapping functions:

InrImage* CurvatureDifference(ParamList*);

InrImage* RampPreservingPeronaMalik1(ParamList*);

InrImage* RampPreservingPeronaMalik2(ParamList*);

InrImage* NSim(ParamList* p);

void NSim2(ParamList* p);

InrImage* NLmeans_fast(ParamList*);

InrImage* NLmeans_MRI(ParamList*);

InrImage* WrapLeastSquares(ParamList*);

BasicVariable::ptr Wrap_EigenDecomp(ParamList*);

BasicVariable::ptr Wrap_SmoothLinesToSplines(ParamList* p);

BasicVariable::ptr Wrap_RegionGrow(ParamList* p);

#endif // _WRAPFILTERS_H_
