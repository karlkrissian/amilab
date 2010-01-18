//
// C++ Interface: ImagePositions
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
//=========================================================================

#ifndef _ImagePositions_h_
#define _ImagePositions_h_

#include "ImagePositionsBase.h"
#include "inrimage.hpp"


template<class T>
class ImagePositions : public ImagePositionsBase
{
protected:
  // image format
  // pointer to image data
  // extent?

  /// Input Image
  InrImage* _image;

  /// Pointers to the beginning of each line
  T***       _positions;
  bool       _positions_allocated;
  int        _vdim;

public:

  ImagePositions( InrImage* im);

  ~ImagePositions();

  bool InitPositions( );

  bool FreePositions( );

  double operator()( int x, int y, int z = 0);

  double operator()( int x, int y, int z, int coord);

  double GetValue( int x, int y, int z, int coord);

  T* GetPos(int x, int y, int z=0);

  void* GetVoidPos(int x,int y, int z=0);

};

#include "ImagePositions.tpp"

#endif
// _ImagePositions_h_
