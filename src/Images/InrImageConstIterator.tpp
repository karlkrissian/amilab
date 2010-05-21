//
// C++ Implementation: InrImageConstIterator
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

template<class T>
InrImageConstIterator<T>::InrImageConstIterator( const InrImage* im)
{
  image    = im;
  _format  = im->GetFormat();
  _data = (T const*) im->GetConstData();
  _datapos = (T*) _data;
  _pos_buf = 0;
  _tx      = im->DimX();
  _ty      = im->DimY();
  _tz      = im->DimZ();
  _vdim    = im->GetVDim();
  _imsize  = im->Size();

  _positions = (ImagePositions<T>* const) im->GetPositionsConst();
}


template<class T>
void InrImageConstIterator<T>::InitBuffer( int pos)
{
  _pos_buf = pos;
  _datapos = (T*) _data + _vdim*pos;
}


template<class T>
inline void InrImageConstIterator<T>::BufferPos( int x, int y, int z) 
//throw (DepassementLimites);
{
  /*
  #ifdef _debug_
      Si x<0 Ou x>=_tx Ou y<0 Ou y>=_ty Ou z<0 Ou z>=_tz Alors
        char message[100];
        sprintf(message, " image %s ( %d %d %d )", (char*)_nom, x, y, z);
        throw DepassementLimites( message);
      FinSi
  #endif
  */
  _datapos  = _positions->GetPos(x,y,z);
  _pos_buf = ((unsigned long) z*_ty + y)* _tx + x;
}

template<class T>
inline bool InrImageConstIterator<T>::operator++()
{
  if  (++_pos_buf >= _imsize) return false;
  _datapos += _vdim;
  return true;
}

template<class T>
inline bool InrImageConstIterator<T>::operator++(int)
{
  if  (++_pos_buf >= _imsize) return false;
  _datapos += _vdim;
  return true;
}

template<class T>
inline bool InrImageConstIterator<T>::Inc( const int& inc)
{
  _pos_buf +=inc;
  if  (_pos_buf >= _imsize) return false;
  _datapos += _vdim*inc;
  return true;
}

template<class T>
inline void InrImageConstIterator<T>::ValueInc( const int& inc)
{
  _datapos += inc;
}

template<class T>
inline double InrImageConstIterator<T>::GetDoubleValue( int field )
{
  return (double) _datapos[field];
}

template<class T>
inline double InrImageConstIterator<T>::GetIncDoubleValue( const int& inc, const int& field ) const
{
  return (double) _datapos[_vdim*inc+field];
}

template<class T>
inline double InrImageConstIterator<T>::GetValueIncDoubleValue( const int& inc  ) const
{
  return (double) _datapos[inc];
}


template<class T>
inline const T& InrImageConstIterator<T>::GetValue(  ) const
{
  return *_datapos;
}

template<class T>
inline const T& InrImageConstIterator<T>::GetValue( const int& field ) const
{
  return _datapos[field];
}




