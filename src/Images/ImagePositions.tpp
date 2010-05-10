//
// C++ Implementation: ImagePositions
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "AMILabConfig.h"

template<class T>
ImagePositions<T>::ImagePositions( InrImage* im)
{
  _image = im;
  _positions_allocated = false;
  _vdim  = _image->GetVDim();
  InitPositions();
}

template<class T>
ImagePositions<T>::~ImagePositions()
{
  FreePositions();
}


template<class T>
bool ImagePositions<T>::InitPositions( )
//                      -------------
{
  //std::cout << "ImagePositions<T>::InitPositions( )" << std::endl;
  T* data = (T*)_image->GetData();
  int txy = _image->DimX()*_image->DimY();

  int tx = _image->DimX();
  int ty = _image->DimY();
  int tz = _image->DimZ();

  _positions = new T**[tz];
  //std::cout << "new T**" << std::endl;
  for(int z=0;z<tz;z++)
  {
    _positions[z] = new T*[ ty];
    //std::cout << "new T*, z = " << z << std::endl;
    for( int y=0;y<ty;y++) {
      _positions[z][y] = data +_vdim*(z*txy+y*tx);
    }
  }
  _positions_allocated = true;
  return true;

} // InitPositions()


//--------------------------------------------------------------------------
template<class T>
bool ImagePositions<T>::FreePositions( )
//                      -------------
{
  //std::cout << "ImagePositions<T>::FreePositions( )" << std::endl;
  if (!_positions_allocated) return false;

  for(int z=0; z<_image->DimZ();z++) {
    //std::cout << "delete [] _postions[" << z << "]" << std::endl;
    delete [] _positions[z];
  }
  //std::cout << "delete [] _positions" << std::endl;
  delete [] _positions;

  _positions_allocated = false;

  return true;

} // FreePositions()



template<class T>
double ImagePositions<T>::operator()( int x, int y, int z ) 
#ifdef AMI_BUILD_Debug
  throw (std::range_error)
#endif
//         --------
{
  #ifdef AMI_BUILD_Debug
    if (!_image->CoordOK(x,y,z))
    {
      cout << "*" << endl;
      std::string message = (boost::format(" image %s ( %d %d %d )") 
            % (char*) _image->GetName() 
            % x %  y % z).str();
      throw std::range_error( message);
    }
  #endif
  // how to speed for scalar images and avoid _vdim multiplication?
  return (double)(_positions[z][y][_vdim*x]);
}


template<class T>
double ImagePositions<T>::GetValue( int x, int y, int z, int coord)
//         --------
{
  return (double)(_positions[z][y][_vdim*x+coord]);
}

template<class T>
double ImagePositions<T>::operator()( int x, int y, int z, int coord)
{
  return GetValue(x,y,z,coord);
}

template<class T>
T* ImagePositions<T>::GetPos(int x, int y, int z)
{
  return _positions[z][y]+_vdim*x;
}

template<class T>
void* ImagePositions<T>::GetVoidPos(int x, int y, int z)
{
  return (void*) (_positions[z][y]+_vdim*x);
}
