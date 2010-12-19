
#include "amilab_messages.h"
#include <iostream>

// Simple IO message functions
void PrintWarning(const char* mess)
{
  std::cout << mess << std::endl;
}
//
void PrintWarning(const ami::format& f)
{
  std::cout << f.GetString() << std::endl;
}
//
void PrintError(const char* mess)
{
  std::cerr << mess << std::endl;
}
//
void PrintError(const ami::format& f)
{
  std::cerr << f.GetString() << std::endl;
}
