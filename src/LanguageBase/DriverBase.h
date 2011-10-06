#pragma once
#ifndef _DriverBase_h_
#define _DriverBase_h_

#include "LanguageBaseConfigure.h"
#include "DefineClass.hpp"
#include "BasicVariable.h"
#include "ami_function.h"
#include "paramlist.h"

/**
  This class contains the main functionalities of Driver that we want to use from outside
  without including driver.h and all its dependencies.
*/
class LanguageBase_EXPORT DriverBase
{

  DEFINE_CLASS(DriverBase);

protected:
    /** 
     * Check if the current command is from the command line.
     * Kept for transition from C flex-bison code should be removed later
     **/
    bool in_console;

public:
  DriverBase(void);
  ~DriverBase(void);

  /** Write error message and information.
    Including current file, line number, last text parsed.
  */
  virtual void yyiperror(const char *s) {}

  /** Print error message to the output 
    which can be a message dialog.
  */
  virtual int  err_print(const char* st) { return 0;}

  /** Print error message to the output 
    which can be a message dialog.
  */
  virtual int  err_print(const std::string& st) { return 0;}

  /** Returns true if the current command is run from the console.
  */
  bool InConsole() { return in_console; }

  BasicVariable::ptr yyip_call_function( AMIFunction* v, 
    const ParamList::ptr& param = ParamList::ptr() ) { return BasicVariable::ptr(); }

};

#endif //  _DriverBase_h_
