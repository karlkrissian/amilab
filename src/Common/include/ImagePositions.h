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
#include "DefineClass.hpp"
#include <exception>
#include <stdexcept> 

template<class T>
class ImagePositions : public ImagePositionsBase
{

  //  DEFINE_CLASS(ImagePositions)
public:
  virtual char const* get_name() const { return "ImagePositions<T>"; }  
  typedef ImagePositions<T> ClassType; 
  typedef typename boost::shared_ptr<ImagePositions<T> >    ptr; 
  typedef typename boost::weak_ptr<ImagePositions<T> >      wptr; 

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


public:

  ImagePositions( InrImage* im);

  ~ImagePositions();

  bool InitPositions( );

  bool FreePositions( );

  double operator()( int x, int y, int z = 0) const
    #ifdef AMI_BUILD_Debug
      throw (std::range_error)
    #endif
    ;

  double operator()( int x, int y, int z, int coord) const;

  double GetValue( int x, int y, int z, int coord) const;

  T* GetPos(int x, int y, int z=0);

  void* GetVoidPos(int x,int y, int z=0);

};

#include "ImagePositions.tpp"

#endif
// _ImagePositions_h_
