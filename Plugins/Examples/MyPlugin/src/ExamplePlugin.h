//
// C++ File: ExamplePlugin.h
//
// Description: This file contains a class of example that contains methods to
// calculate the factorial of a number and the series of Fibonacci.
//
//
// Author: xXx <xXx@xXx.com>, (C) YYYY
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef EXAMPLEPLUGIN_H
#define EXAMPLEPLUGIN_H

/**
 * @brief The ExamplePlugin class contains methods to calculate the factorial 
 *        of a number and the series of Fibonacci.
 **/
class ExamplePlugin
{
public:
  /**
   * Default constructor.
   **/
  ExamplePlugin()
  {
    //TODO
  };

  /**
   * Destructor.
   **/
  ~ExamplePlugin()
  {
    //TODO
  };

  /**
   * Calculates the factorial of a number.
   * @param Number  the value to calculating 
   * @return the product of all positive integers less than or equal to Number parameter
   **/  
  int Factorial(int Number);

  /**
   * Shows the element of the Fibonacci numbers corresponding to the N position.
   * @param N  the position of element
   * @return the element of the Fibonacci numbers corresponding to the N position
   **/  
  int Fibonacci(int N);

};

#endif // EXAMPLEPLUGIN_H

