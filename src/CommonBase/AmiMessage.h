#pragma once
#ifndef _AmiMessage_h_
#define _AmiMessage_h_

#include "CommonBaseConfigure.h"
#include <iostream>
#include <string>

/**
 * Simple class to display error messages in the application. The main application can
 * pass the displaying function as a parameter. 
 */
class CommonBase_EXPORT AmiMessage
{
public:
  //-----------------------------------------
  AmiMessage(): ErrorFunction(NULL) {}

  //-----------------------------------------
  int Error(char* message);

  //-----------------------------------------
  int  Error(const std::string& st);

  //-----------------------------------------
  void SetErrorFunction(int (*ErrFunc)(char*));

  //-----------------------------------------
  void IncCommand(const std::string& cmd);

  //-----------------------------------------
  void SetIncCommandFunction(void (*IncCommandFunction)(const std::string&));
  
private:
  int  (*ErrorFunction)(char*);
  void (*IncCommandFunction)(const std::string&);
};

#endif // _AmiMessage_h_
