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

#include "inrimage.hpp"
#include "ImageLinearInterpolator.h"

ImageLinearInterpolator::ImageLinearInterpolator( InrImage* im)
{
  _image = im;
  _coord = 0;
  _tx = im->DimX();
  _ty = im->DimY();
  _tz = im->DimZ();
  _txy = _tx*_ty;
  _vdim = im->GetVDim();
  _step_x = _vdim;
  _step_y = _tx*_vdim;
  _step_z = _txy*_vdim;
  _Iterator = im->CreateIterator();
}

double ImageLinearInterpolator::InterpLinIntensite2( double dx1, double dx2, int tx1, int tx2)
{
  register double coeff00,coeff01,coeff10,coeff11;
  register int    tx12;
  register double res = 0;

  coeff00 = 1.0 - dx1;
  coeff10 = dx1;

  coeff01 = coeff00 * dx2;
  coeff11 = coeff10 * dx2;

  coeff00 -= coeff01;
  coeff10 -= coeff11;

  tx12 = tx1+tx2;

  _Iterator->ValueInc(_coord); 
  res  =  coeff00* _Iterator->GetDoubleValue() + 
          coeff10* _Iterator->GetValueIncDoubleValue(tx1); 
  res +=  coeff01* _Iterator->GetValueIncDoubleValue(tx2) + 
          coeff11* _Iterator->GetValueIncDoubleValue(tx12); 

  return res;
}

double ImageLinearInterpolator::InterpLinIntensite( float x, float y)
{
  if ((x < 0) || ( x >= _tx-1) ||
      (y < 0) || ( y >= _ty-1))
  {
    int x1=(int)(x+0.5),y1=(int)(y+0.5);
    if (x<0)      x1 = 0;
    if (x>=_tx-1) x1 = _tx-1;
    if (y<0)      y1=0;
    if (y>=_ty-1) y1 = _ty-1;
    if (_image->ScalarFormat())
      return (*_image)(x1,y1);
    else
      return (*_image)(x1,y1,0,_coord);
  }

  _Iterator->BufferPos( (int) x, (int) y, 0);
  return InterpLinIntensite2( (x-(int)x),
                (y-(int)y),
                _step_x,_step_y);
}

double ImageLinearInterpolator::InterpLinIntensite( float x, float y, float z)
{

  if ((z==0)||(_tz == 1)) return InterpLinIntensite(x,y);

  register int     xi,yi,zi;
  register double dx,dy,dz;
  register double res = 0;
  register double coeff000,coeff010,coeff100,coeff110;
  register double coeff001,coeff011,coeff101,coeff111;

  if (x < 0)       x= (float) 0.0;
  if (y < 0)       y= (float) 0.0;
  if (z < 0)       z= (float) 0.0;
  if ( x > _tx-1)  x= (float) _tx-1;
  if ( y > _ty-1)  y= (float) _ty-1;
  if ( z > _tz-1)  z= (float) _tz-1;

  xi = (int) x;
  yi = (int) y;
  zi = (int) z;

  dx = x - (double)xi;
  dy = y - (double)yi;
  dz = z - (double)zi;

  if (xi == _tx-1) {  xi = _tx-2;   dx = 1.0;  }
  if (yi == _ty-1) {  yi = _ty-2;   dy = 1.0;  }
  if (zi == _tz-1) {  zi = _tz-2;   dz = 1.0;  }

  if (dx < 1E-10) {
    _Iterator->BufferPos(xi,yi,zi);
    return  InterpLinIntensite2(dy,dz,_step_y,_step_z);
  }

  if (dy < 1E-10) {
    _Iterator->BufferPos(xi,yi,zi);
    return InterpLinIntensite2(dx,dz,_step_x,_step_z);
  }

  if (dz < 1E-10) {
    _Iterator->BufferPos(xi,yi,zi);
    return InterpLinIntensite2(dx,dy,_step_x,_step_y);
  }

  /*--- calcul des poids associés à chaque point ---*/
  // 16 multiplication, 12 additions, 8 affectations
  // coeff000 = (1.0 - dx) * (1.0 - dy) * (1.0 - dz);
  // coeff100 = dx         * (1.0 - dy) * (1.0 - dz);
  // coeff010 = (1.0 - dx) * dy         * (1.0 - dz);
  // coeff110 = dx         * dy         * (1.0 - dz);
  // coeff001= (1.0 - dx) * (1.0 - dy)  * dz;
  // coeff101 = dx         * (1.0 - dy) * dz;
  // coeff011 = (1.0 - dx) * dy         * dz;
  // coeff111 = dx         * dy         * dz;


  // 6 multiplication, 7 additions, 14 affectations
  coeff000 = 1.0 - dx;
  coeff100 = dx;

  coeff010 = coeff000 * dy;
  coeff110 = coeff100 * dy;

  coeff000 -= coeff010;
  coeff100 -= coeff110;

  coeff001 = coeff000*dz;
  coeff101 = coeff100*dz;
  coeff011 = coeff010*dz;
  coeff111 = coeff110*dz;

  coeff000 -= coeff001;
  coeff100 -= coeff101;
  coeff010 -= coeff011;
  coeff110 -= coeff111;

  _Iterator->BufferPos(xi,yi,zi);
  _Iterator->ValueInc(_coord);

  res  =  coeff000* _Iterator->GetDoubleValue() + 
          coeff100* _Iterator->GetValueIncDoubleValue(_step_x);
  res +=  coeff010* _Iterator->GetValueIncDoubleValue(_step_y) +
          coeff110* _Iterator->GetValueIncDoubleValue(_step_y+_step_x); 
  res +=  coeff001* _Iterator->GetValueIncDoubleValue(_step_z ) + 
          coeff101* _Iterator->GetValueIncDoubleValue(_step_z+_step_x); 
  res +=  coeff011* _Iterator->GetValueIncDoubleValue(_step_z+_step_y) + 
          coeff111* _Iterator->GetValueIncDoubleValue(_step_z+_step_y+_step_x); 

  return res;
}

double ImageLinearInterpolator::InterpLinIntensite( float x, float y, float z, int coord)
{
  _coord = coord;
  return this->InterpLinIntensite(x,y,z);
}


