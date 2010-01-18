//
// C++ Interface: InrImageIterator
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

#ifndef _InrImageIterator_h_
#define _InrImageIterator_h_

#include "inrimage.hpp"
#include "ImagePositions.h"

#include "InrImageIteratorBase.h"

template<class T>
class InrImageIterator : public InrImageIteratorBase
{
protected:
  // image format
  // pointer to image data
  // extent?

  InrImage* image;
  // Get the direct access to the lines
  ImagePositions<T>* _positions;
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

public:

  InrImageIterator( InrImage* im);


  /**
    * Init local iterator
    * @param pos 
    */
  void InitBuffer( int pos = 0);
  //             ----------
  void BufferPos( int x, int y, int z=0);
// throw (DepassementLimites);

  void* PosPointer() { return (void*) _datapos; }

  bool operator ++();

  /**
   * Increments the current position of d pixels
   * @param d 
   * @return 
   */
  bool Inc( const int& d);

  /**
   * Increments the current position of d values,
   * for example if the image is vectorial d=1 will get to 
   * the next vectorial component of the first component of 
   * the next pixel.
   * @param d 
   * @return 
   */
  bool ValueInc( const int& d);

  double GetDoubleValue( int field = 0);

  /**
   * Gets the value at the current position + inc, casted to a double value, and for the given component (field).
   * @param inc 
   * @param field 
   * @return 
   */
  double GetIncDoubleValue( const int& inc, const int& field = 0 ) const;

  void SetDoubleValue( const double& val);

  T GetValue( int field = 0) const;

  void SetValue( const T& val);

  void SetDoubleValue( int field, const double& val);

  void SetValue( int field, const T& val);

  // TODO: this method should increment _pos_buf ??
  // but it would be slower ...
  void IncScalarBufferFast() {  _datapos++; }

};

#include "InrImageIterator.tpp"

#endif
// _InrImageIterator_h_
