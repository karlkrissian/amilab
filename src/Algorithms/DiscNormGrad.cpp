/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/

#include "DiscNormGrad.h"
#include <boost/format.hpp>

InrImage* Func_DiscNormGrad( InrImage* im )
{

  InrImage*       image_res;
  std::string     resname;
  register int    x,y,z;
  register double dx,dy,dz;
  unsigned long   tx,txy;



  resname = (boost::format("%s.discnormgrad") % im->GetName()).str();
  image_res = new InrImage(WT_FLOAT, resname.c_str() , im);

  image_res->InitImage(0);

  tx  = im->_tx;
  txy = tx*im->_ty;

  Si im->_tz > 4 Alors

    im       ->InitBuffer();
    image_res->InitBuffer();

    Pour(z,0,im->_tz-1)
    Pour(y,0,im->_ty-1)
    Pour(x,0,im->_tx-1)

      if (x==0)
        dx = im->ValeurBuffer(1)  -im->ValeurBuffer(0);
      else
      if (x==im->_tx-1)
        dx = im->ValeurBuffer(0)  -im->ValeurBuffer(-1);
      else  
        dx = im->ValeurBuffer(1)  -im->ValeurBuffer(-1);

      if (y==0)
        dy = im->ValeurBuffer(tx)  -im->ValeurBuffer(0);
      else
      if (y==im->_ty-1)
        dy = im->ValeurBuffer(0)  -im->ValeurBuffer(-(int)tx);
      else  
        dy = im->ValeurBuffer(tx)  -im->ValeurBuffer(-(int)tx);

      if (z==0)
        dz = im->ValeurBuffer(txy)  -im->ValeurBuffer(0);
      else
      if (z==im->_tz-1)
        dz = im->ValeurBuffer(0)  -im->ValeurBuffer(-(int)txy);
      else  
        dz = im->ValeurBuffer(txy)  -im->ValeurBuffer(-(int)txy);

      image_res->FixeValeur(0.5*sqrt(dx*dx+dy*dy+dz*dz));
      im       ->IncBuffer();
      image_res->IncBuffer();


    FinPour
    FinPour
    FinPour

  Sinon

    im       ->InitBuffer();
    image_res->InitBuffer();

    Pour(y,0,im->_ty-1)
    Pour(x,0,im->_tx-1)

      if (x==0)
        dx = im->ValeurBuffer(1)  -im->ValeurBuffer(0);
      else
      if (x==im->_tx-1)
        dx = im->ValeurBuffer(0)  -im->ValeurBuffer(-1);
      else  
        dx = im->ValeurBuffer(1)  -im->ValeurBuffer(-1);

      if (y==0)
        dy = im->ValeurBuffer(tx)  -im->ValeurBuffer(0);
      else
      if (y==im->_ty-1)
        dy = im->ValeurBuffer(0)  -im->ValeurBuffer(-(int)tx);
      else  
        dy = im->ValeurBuffer(tx)  - im->ValeurBuffer(-(int)tx);

      image_res->FixeValeur(0.5*sqrt(dx*dx+dy*dy));
      im       ->IncBuffer();
      image_res->IncBuffer();

    FinPour
    FinPour

  FinSi

  return image_res;

} //  Func_DiscNormGrad()

