//
// C++ Implementation: CallBackAMIFunction
//
// Description: 
//
//
// Author:  <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "CallBackAMIFunction.h"
#include "driver.h"

extern yyip::Driver GB_driver;

bool CallBackAMIFunction::operator()()
{
  if (AMIFunction::ptr f = wfunc.lock()) {
    GB_driver.yyip_call_function(f.get());
    return true;
  }
  else {
    GB_driver.err_print("Trying to call a non-existing AMIFunction !");
    return false;
  }
}
