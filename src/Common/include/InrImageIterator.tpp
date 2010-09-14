//
// C++ Implementation: InrImageIterator
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
InrImageIterator<T>::InrImageIterator( InrImage* im)
{
  image    = im;
  _format  = im->GetFormat();
  _data = _datapos = (T*) im->GetData();
  _pos_buf = 0;
  _tx      = im->DimX();
  _ty      = im->DimY();
  _tz      = im->DimZ();
  _vdim    = im->GetVDim();
  _imsize  = im->Size();

  _positions = (ImagePositions<T>*) im->GetPositions();
}


template<class T>
void InrImageIterator<T>::InitBuffer( int pos)
{
  _pos_buf = pos;
  _datapos = (T*) _data + _vdim*pos;
}


template<class T>
inline void InrImageIterator<T>::BufferPos( int x, int y, int z) 
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
inline bool InrImageIterator<T>::operator++()
{
  if  (++_pos_buf >= _imsize) return false;
  _datapos += _vdim;
  return true;
}

template<class T>
inline bool InrImageIterator<T>::operator++(int)
{
  if  (++_pos_buf >= _imsize) return false;
  _datapos += _vdim;
  return true;
}

template<class T>
inline bool InrImageIterator<T>::Inc( const int& inc)
{
  _pos_buf +=inc;
  if  (_pos_buf >= _imsize) return false;
  _datapos += _vdim*inc;
  return true;
}

template<class T>
inline void InrImageIterator<T>::ValueInc( const int& inc)
{
  _datapos += inc;
}

template<class T>
inline double InrImageIterator<T>::GetDoubleValue( int field )
{
  return (double) _datapos[field];
}

template<class T>
inline double InrImageIterator<T>::GetIncDoubleValue( const int& inc, const int& field ) const
{
  return (double) _datapos[_vdim*inc+field];
}

template<class T>
inline double InrImageIterator<T>::GetValueIncDoubleValue( const int& inc  ) const
{
  return (double) _datapos[inc];
}

template<class T>
inline void InrImageIterator<T>::SetDoubleValue( const double& val)
{
  *_datapos = (T) val;
  if (_vdim>1) {
    for(int i=1;i<_vdim;i++)
      _datapos[i] = (T) val;
  }
}


template<class T>
inline const T& InrImageIterator<T>::GetValue(  ) const
{
  return *_datapos;
}

template<class T>
inline const T& InrImageIterator<T>::GetValue( const int& field ) const
{
  return _datapos[field];
}

template<class T>
inline void InrImageIterator<T>::SetValue( const T& val)
{
  *_datapos = val;
}

template<class T>
inline void InrImageIterator<T>::AddValue( const T& val)
{
  *_datapos += val;
}


template<class T>
inline void InrImageIterator<T>::SetDoubleValue( int field, const double& val)
{
 // TODO: should use round to convert a double to an integer value ?
  _datapos[field] = (T) val;
}

template<class T>
inline void InrImageIterator<T>::SetDoubleVectorValues( const double& valx, const double& valy, const double& valz)
{
  if (_vdim==3) {
    _datapos[0]   = (T) valx;
    _datapos[1]   = (T) valy;
    _datapos[2]   = (T) valz;
  }
  else std::cerr <<  "InrImageIterator<T>::SetDoubleVectorValues()  _vdim!=3 \n";
}

template<class T>
inline void InrImageIterator<T>::SetValue( int field, const T& val)
{
  _datapos[field] = val;
}

