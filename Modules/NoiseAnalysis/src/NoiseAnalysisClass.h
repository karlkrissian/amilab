#pragma once
#ifndef _NoiseAnalysis_h_
#define _NoiseAnalysis_h_

#include "inrimage.hpp"
// deal with EXPORT...

class NoiseAnalysis {

protected:
  // Private constructor to avoid wrapping
  NoiseAnalysis() {}
  ~NoiseAnalysis() {}
  
private:
  NoiseAnalysis(const NoiseAnalysis&);  // Not implemented.
  void operator=(const NoiseAnalysis&);  // Not implemented.

public:
  /**
   * Calcula la media local de la intensidad de la imagen.
   * @param input Input image
   * @param size tamaña de la ventana sera (2*size+1)^n
   * @return la imagen promediada
   **/
  static InrImage::ptr medialocal( InrImage::ptr input, int size);
};


#endif 
//  _NoiseAnalysis_h_
