//
// C++ Interface: InrImageConstIterator
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

#ifndef _InrImageConstIterator_h_
#define _InrImageConstIterator_h_

#include "inrimage.hpp"
#include "ImagePositions.h"

#include "InrImageIteratorBase.h"
#include "amilab_messages.h"

template<class T>
class InrImageConstIterator : public InrImageIteratorBase
{

public:
  virtual char const* get_name() const { return "InrImageConstIterator<T>"; }
  typedef InrImageConstIterator<T> ClassType;
  typedef typename boost::shared_ptr<ClassType >    ptr;
  typedef typename boost::weak_ptr<ClassType >      wptr;

protected:
  // image format
  // pointer to image data
  // extent?

  const InrImage* image;
  // Get the direct access to the lines
  ImagePositions<T>* _positions;
  WORDTYPE  _format;

  /// Pointer to the data
  T const *    _data;

  /// Current position within the data
  T*    _datapos;

  /// End position for the current loop
  T*    _endpos;

  /// index of the current position
  long  _pos_buf;

  /// number of scalar components of a pixel/voxel
  int   _tx,_ty,_tz;
  int   _vdim;
  long  _imsize;

public:

  InrImageConstIterator( const InrImage* im);


  /**
    * Init local iterator
    * @param pos 
    */
  void InitBuffer( int pos = 0);
  //             ----------

  /**
   * Sets the pointer to the last loop element + 1
   * @param loop_size 
   */
  void SetEnd( int loop_size)
  {
    _endpos = _datapos+loop_size*_vdim;
  }

  /**
   * 
   * @return if the end of the loop is reached
   */
  bool NotAtEnd() { return _datapos<_endpos; }

  void BufferPos( int x, int y, int z=0);
// throw (DepassementLimites);

  void* PosPointer() { return (void*) _datapos; }

  bool operator ++();
  bool operator ++(int);

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
  void ValueInc( const int& d);

  double GetDoubleValue( int field = 0);

  /**
   * Gets the value at the current position + inc, casted to a double value, and for the given component (field).
   * @param inc 
   * @param field 
   * @return 
   */
  double GetIncDoubleValue( const int& inc, const int& field = 0 ) const;

  /**
   * Gets the value at the current position + inc, stepping by value instead of by pixel/voxel
   * @param inc
   * @return 
   */
  double GetValueIncDoubleValue( const int& inc = 0 ) const;

  const T& GetValue( ) const;

  const T& GetValue( const int& field ) const;

  // TODO: this method should increment _pos_buf ??
  // but it would be slower ...
  void IncScalarBufferFast() {  _datapos++; }

  void SetDoubleValue(const double&)  {
    CLASS_ERROR("Cannot not modify image in a const iterator.");
  }

  void SetDoubleValue(int, const double&)   {
    CLASS_ERROR("Cannot not modify image in a const iterator.");
  }

  void SetDoubleVectorValues(const double&, const double&, const double&)   {
    CLASS_ERROR("Cannot not modify image in a const iterator.");
  }

};

#include "InrImageConstIterator.tpp"

#endif
// _InrImageConstIterator_h_
