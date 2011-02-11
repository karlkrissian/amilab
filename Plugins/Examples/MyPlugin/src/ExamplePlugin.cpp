//
// C++ File: ExamplePlugin.cpp
//
// Description: This file contains a class of example that contains methods to
// calculate the factorial of a number and the series of Fibonacci.
//
//
// Author: xXx <xXx@xXx.com>, (C) YYYY
//
// Copyright: See COPYING file that comes with this distribution
//

#include "ExamplePlugin.h"

int ExamplePlugin::Factorial(int Number)
{
  int Prod=1;
  for (int i=2;i<=Number;i++) {
    Prod*=i;
  }
  return Prod;
} // Factorial

int ExamplePlugin::Fibonacci(int N)
{
  int i=1;
  int j=0;
  int t=0;

  for (int k=1;k<=N;k++) {
    t=i+j;
    i=j;
    j=t;
  }
  return j;
} // Fibonacci

