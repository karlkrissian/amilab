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

#ifndef _WRAPWII_H_
#define _WRAPWII_H_

#include "inrimage.hpp"
#include "paramlist.h"

/** function that add the wrapping of fluid function
 *  to the AMI language
 */
void AddWrapWII(); 

// Wrapping functions:

#ifdef _USE_WII_

void WII_initcounter(ParamList*);
void WII_printcounter(ParamList*);
void WII_start(ParamList*);
void WII_stop(ParamList*);
void WII_getmotion(ParamList*);
void WII_GetRoll(ParamList*);
void WII_GetPitch(ParamList*);
void WII_GetGForceX(ParamList*);
void WII_GetGForceY(ParamList*);
void WII_GetGForceZ(ParamList*);
void WII_GetButtons(ParamList*);
void WII_eventloop(ParamList*);
void WII_GetEventCounter(ParamList*);
void WII_SetMotionSensing(ParamList*);

#endif

#endif // _WRAPWII_H_
