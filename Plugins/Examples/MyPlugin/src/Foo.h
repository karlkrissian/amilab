//
// C++ File: Foo.h
//
// Description:  A template example.
//
//
// Author: xXx <xXx@xXx.com>, (C) YYYY
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FOO_H
#define FOO_H

#include <vector>

/**
 * @brief Template class example. A sequence generates of N elements of type T.
 **/
template <class T, int N>
class Foo {
  T MemBlock [N];
public:
  /**
   * Adds an element of type T to the sequence.
   * @param x     sequence position
   * @param value the element to add
   **/
  void Set (int x, T value){
    MemBlock[x]=value;
  }

  /**
   * Obtains the element X of the sequence.
   * @param x     sequence position
   * @return the element X of the sequence.
   **/
  T Get (int x) {
    return MemBlock[x];
  }
}; // Foo class

/**
 * @brief Template class example. Three generic values (Set/Get).
 **/
template <class T, class T1, class T2>
class Foo2 {
  T  _Value;
  T1 _Value1;
  T2 _Value2;
public:
  /**
   * Sets the respective values.
   * @param value  the first value
   * @param value1 the second value
   * @param value2 the third value
   **/
  void Set (T value, T1 value1, T2 value2){
    _Value=value;
    _Value1=value1;
    _Value2=value2;
  }

  /**
   * Gets the first value.
   * @return the first value
   **/
  T GetValue (void){
    return _Value;
  }

  /**
   * Gets the second value.
   * @return the second value
   **/
  T1 GetValue1 (void){
    return _Value1;
  }

  /**
   * Gets the third value.
   * @return the third value
   **/
  T2 GetValue2 (void){
    return _Value2;
  }    
}; // Foo2 class

/**
 * @brief Template class example. A simple stack.
 **/
template <typename T, typename CONT = std::vector<T> >
class Foo3 {
private:
  CONT _Elems;
public:
  /**
   * Push element.
   * @param value the value
   **/
  void Push(T const& Value)
  {
    _Elems.push_back(Value);
  } // Push

  /**
   * Pop element
   **/
  void Pop()
  {
    if (!_Elems.empty()) {
      _Elems.pop_back();
    }
  } // Pop

  /**
   * Gets the top element.
   * @return the top element value
   **/
  T Top() const
  {
    return _Elems.back();
  } // Top

  /**
    * Verifies if the stack is empty.
    * @return whether the stack is empty
    **/
  bool empty() const
  {
    return _Elems.empty();
  }
}; // Foo3 class

#endif // FOO_H