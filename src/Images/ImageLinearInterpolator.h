//
// C++ Interface: ImageLinearInterpolator
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

#ifndef _ImageLinearInterpolator_h_
#define _ImageLinearInterpolator_h_

#include "inrimage.hpp"
#include "ImagePositions.h"


class ImageLinearInterpolator
{
protected:
  // image format
  // pointer to image data
  // extent?

  InrImage* _image;
  // Get the direct access to the lines
  ImagePositions<T>* _positions;
  InrImageIteratorBase::ptr _Iterator;
  WORDTYPE  _format;

  /// Pointer to the data
  T*    _data;

  /// Current position within the data
  T*    _datapos;

  /// index of the current position
  long  _pos_buf;

  /// number of scalar components of a pixel/voxel
  int   _tx,_ty,_tz;
  int   _vdim;
  long  _imsize;

  /// current coordinate to interpolate
  int   _coord;

public:

  ImageLinearInterpolator( InrImage* im);

  double InterpLinIntensite2( double dx1, double dx2, int tx1, int tx2);

  double InterpLinIntensite( float x, float y);

  double InterpLinIntensite( float x, float y, float z);

  double InterpLinIntensite( float x, float y, float z, int coord);

};


#endif
// _ImageLinearInterpolator_h_
