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

#ifndef _wrapSystem_h_
#define _wrapSystem_h_

#include "inrimage.hpp"
#include "EigenDecomp.h"
#include "paramlist.h"
#include "Variable.hpp"


/** function that add the wrapping of system information
 *  to the AMI language
 */
void AddWrapSystem();
void wrap_System(ParamList* p);

BasicVariable::ptr wrap_GetFreeMemory(   ParamList* p);
BasicVariable::ptr wrap_GetFullHostName( ParamList* p);
BasicVariable::ptr wrap_GetHomeDir(      ParamList* p);
BasicVariable::ptr wrap_GetHostName(     ParamList* p);
BasicVariable::ptr wrap_GetUserHome(     ParamList* p);
BasicVariable::ptr wrap_GetUserId(       ParamList* p);
BasicVariable::ptr wrap_GetUserName(     ParamList* p);

Variable::ptr wrap_GetCurrentScriptDir( ParamList* p);

#endif // _wrapSystem_h_
