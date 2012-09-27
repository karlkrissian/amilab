#pragma once
#ifndef _PruebaClass_h_
#define _PruebaClass_h_

#include "inrimage.hpp"

class PruebaClass;
typedef PruebaClass PruebaClasstd;

// deal with EXPORT...

class PruebaClass {

protected:
  // Private constructor to avoid wrapping
  PruebaClass() {}
  ~PruebaClass() {}
  
private:
  PruebaClass(const PruebaClass&);  // Not implemented.
  void operator=(const PruebaClass&);  // Not implemented.

public:

  /**
   * @brief Suma de 2 imagenes punto a punto.
   *
   * @param i1 primera imagen
   * @param i2 segunda imagen
   * @return resultado
   **/
  static InrImage::ptr Suma(InrImage::ptr i1, InrImage::ptr i2);
  
  /**
   * @brief Calcula una media local 3x3
   *
   * @param i imagen de entrada
   * @return resultado
   **/
  static InrImage::ptr MediaLocal3x3(InrImage::ptr i);

  
  /**
   * @brief Calcula una mediana local
   *
   * @param i imagen de entrada
   * @param n vecindario (2n+1)^dim
   * @return resultado
   **/
  static InrImage::ptr MedianaLocal(InrImage::ptr i, int n);
  
  
};


#endif 
//  _PruebaClass_h_
