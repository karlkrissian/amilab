//
// C++ Interface: InrImageIteratorBase
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

#ifndef _InrImageIteratorBase_h_
#define _InrImageIteratorBase_h_

#include "DefineClass.hpp"


class InrImageIteratorBase 
{

  DEFINE_CLASS(InrImageIteratorBase);

public:

  InrImageIteratorBase( ) {}

  virtual void InitBuffer( int pos = 0)           = 0;
  virtual void BufferPos( int x, int y, int z=0)  = 0;
  virtual void* PosPointer()                      = 0;

  virtual void SetEnd( int loop_size)             = 0;
  virtual bool NotAtEnd()                         = 0;

  /**
   * this is the prefix ++ operator
   * increment the iterator by 1 position, same as prefix operator
   * @return 
   */
  virtual bool operator ++()                      = 0;

  /**
   * this is the postfix ++ operator, 
   * increment the iterator by 1 position, same as postfix operator
   * @return 
   */
  virtual bool operator ++(int)                      = 0;
  virtual bool Inc( const int& d)                 = 0;
  virtual void ValueInc( const int& d)            = 0;
  virtual double GetDoubleValue( int field = 0)   = 0;
  virtual double GetIncDoubleValue( const int& inc, const int& field = 0) const = 0;
  virtual double GetValueIncDoubleValue( const int& inc = 0 ) const = 0;
  virtual void SetDoubleValue( const double& val) = 0;
  virtual void SetDoubleValue( int field, const double& val) = 0;
  virtual void SetDoubleVectorValues( const double& valx, const double& valy, const double& valz) = 0;
  virtual void IncScalarBufferFast()              = 0;
};



#endif
// _InrImageIteratorBase_h_
