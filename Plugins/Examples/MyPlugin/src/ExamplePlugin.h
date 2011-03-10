//
// C++ File: ExamplePlugin.h
//
// Description: This file contains a class of example that contains methods to
// calculate the factorial of a number and the series of Fibonacci. Also it
// contains methods to create a sequence integers elements and a simple stack.
//
//
// Author: xXx <xXx@xXx.com>, (C) YYYY
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef EXAMPLEPLUGIN_H
#define EXAMPLEPLUGIN_H

#define MAXELEMSEQUENCE 10  /// Maximum size of the sequence.

#include "Foo.h"

/**
 * @brief The ExamplePlugin class contains methods to calculate the factorial 
 *        of a number and the series of Fibonacci. Also it contains methods to
 *        create a sequence integers elements and a simple stack.
 **/
class ExamplePlugin
{
private:
  Foo3<int> _MyStack;  
  Foo<int, MAXELEMSEQUENCE> _MySequence;
  Foo2<int,float,bool> _MyFoo;
public:
  /**
   * Default constructor.
   **/
  ExamplePlugin()
  {
    //TODO
    _MyFoo.Set(1,0.5,true);
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

  /**
   * Adds a value to the sequence of integers (nothing is done if the position
   * is incorrect).
   * @param Position  the position of element
   * @param Value     the value of element
   **/
  void AddSequenceElement(int Position, int Value);

  /**
   * Obtains the element X of the sequence.
   * @param Position  the position of element
   * @return the element X of the sequence (-1 if the position is incorrect)
   **/
  int GetSequenceElement(int Position);

  /**
   * Adds a value to stack.
   * @param Value the value of element
   **/
  void Push(int Value);

  /**
   * Extracts an element of stack.
   * @return the element of stack
   **/
  int Pop(void);
};

#endif // EXAMPLEPLUGIN_H

