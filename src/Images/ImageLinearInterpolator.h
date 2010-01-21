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

#include "InrImageIteratorBase.h"
#include "DefineClass.hpp"

// avoid recursive inclusion
//#include "inrimage.hpp"
class InrImage;

class ImageLinearInterpolator
{
  DEFINE_CLASS(ImageLinearInterpolator);

protected:
  // image format
  // pointer to image data
  // extent?

  InrImage* _image;
  // Get the direct access to the lines
  //ImagePositions<T>* _positions;
  InrImageIteratorBase::ptr _Iterator;
//  WORDTYPE  _format;

  /// index of the current position
  long  _pos_buf;

  /// number of scalar components of a pixel/voxel
  int   _tx,_ty,_tz,_txy;
  int   _step_x, _step_y, _step_z;
  int   _vdim;
  long  _imsize;

  /// current coordinate to interpolate
  int   _coord;

public:

  ImageLinearInterpolator( InrImage* im);

  /**
   * Compute 2D linear interpolation along 2 axes, based on the current Iterator position
   * @param dx1 spatial displacement in the first coordinates
   * @param dx2 spatial displacement in the second coordinates
   * @param tx1 increment for the first coordinates
   * @param tx2 increment for the second coordinates
   * @return interpolated value
   */
  double InterpLinIntensite2( double dx1, double dx2, int tx1, int tx2);

  /**
   * 
   * @param x 
   * @param y 
   * @return 
   */
  double InterpLinIntensite( float x, float y);

  /**
   * 
   * @param x 
   * @param y 
   * @param z 
   * @return 
   */
  double InterpLinIntensite( float x, float y, float z);

  /**
   * 
   * @param x 
   * @param y 
   * @param z 
   * @param coord 
   * @return 
   */
  double InterpLinIntensite( float x, float y, float z, int coord);

};


#endif
// _ImageLinearInterpolator_h_
