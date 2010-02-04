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

#ifndef _ImagePositionsBase_h_
#define _ImagePositionsBase_h_

#include "inrimage.hpp"


class ImagePositionsBase
{

public:

  ImagePositionsBase( ) {}
  virtual ~ImagePositionsBase() {};

  virtual bool InitPositions( ) = 0;

  virtual bool FreePositions( ) = 0;

  virtual double operator()( int x, int y, int z = 0) = 0;

  virtual double operator()( int x, int y, int z, int coord) = 0;

  virtual double GetValue( int x, int y, int z, int coord) = 0;

  virtual void* GetVoidPos(int x,int y, int z=0) = 0;

};


#endif
// _ImagePositionsBase_h_
