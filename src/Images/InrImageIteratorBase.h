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

  InrImageIteratorBase( );

  virtual void InitBuffer( int pos = 0)           = 0;
  virtual void BufferPos( int x, int y, int z=0)  = 0;
  virtual void* PosPointer()                      = 0;
  virtual bool operator ++()                      = 0;
  virtual bool Inc( const int& d)                 = 0;
  virtual bool ValueInc( const int& d)            = 0;
  virtual double GetDoubleValue( int field = 0)   = 0;
  virtual double GetIncDoubleValue( const int& inc, const int& field = 0) const = 0;
  virtual void SetDoubleValue( const double& val) = 0;
  virtual void SetDoubleValue( int field, const double& val) = 0;
  virtual void IncScalarBufferFast()              = 0;
};



#endif
// _InrImageIteratorBase_h_
