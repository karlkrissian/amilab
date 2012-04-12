#pragma once
#ifndef _PruebaClass_h_
#define _PruebaClass_h_

#include "inrimage.hpp"

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
  
};


#endif 
//  _PruebaClass_h_
