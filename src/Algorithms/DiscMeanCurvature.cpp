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

#include "DiscMeanCurvature.h"
#include <boost/format.hpp>

InrImage* Func_DiscMeanCurvature( InrImage* im )
{

  InrImage*       image_res;
  std::string     resname;
  register int    x,y,z;
  double D0x,D0y,D0z;
  long   tx,txy,ty,tz;

  register double  u0,upx,upy,upz,umx,umy,umz;
  register int mx,my,mz,px,py,pz;
  register double delta0;
  double D0xy,D0yz,D0zx;
    register double D_x,Dx,D_y,Dy,D_z,Dz;
    double  dxsq=0,dysq=0,dzsq=0;
  register double Dpmx=0;
  register double Dpmy=0;
  register double Dpmz=0;
  register double meancurv_grad;
    register double dxy, dyz, dxz;
 

  resname = (boost::format("%s.discmeancurv") % im->GetName()).str();
  image_res = new InrImage(WT_FLOAT, resname.c_str() , im);

  image_res->InitImage(0);

  tx  = im->_tx;
  ty  = im->_ty;
  tz  = im->_tz;
  txy = tx*im->_ty;

  mx = -1;   px = 1;
  my = -tx;  py = tx;
  mz = -txy; pz = txy;

  Si im->_tz > 4 Alors

    im       ->InitBuffer();
    image_res->InitBuffer();

    Pour(z,0,im->_tz-1)
    Pour(y,0,im->_ty-1)
    Pour(x,0,im->_tx-1)

      if (x==0)    mx =  1;   else mx = -1;
      if (x==tx-1) px = -1;   else px =  1;
      if (y==0)    my =  tx;  else my = -tx;
      if (y==ty-1) py = -tx;  else py =  tx;
      if (z==0)    mz =  txy; else mz = -txy;
      if (z==tz-1) pz = -txy; else pz =  txy;

      u0 = im->ValeurBuffer();
      umx=im->ValeurBuffer(mx);
      upx=im->ValeurBuffer(px);   
      umy=im->ValeurBuffer(my);
      upy=im->ValeurBuffer(py);   
      umz=im->ValeurBuffer(mz);   
      upz=im->ValeurBuffer(pz);
      


       // isotropic voxels
      Dx = upx-u0;
      Dy = upy-u0;
      Dz = upz-u0;
      
      D_x = u0-umx;
      D_y = u0-umy;
      D_z = u0-umz;
      
      // divide by 2 later
      D0x= (upx-umx)/2;  // /2
      D0y= (upy-umy)/2;  // /2
      D0z= (upz-umz)/2;  // /2
      
      // Second order derivatives
      Dpmx=upx-u0-u0+umx;
      Dpmy=upy-u0-u0+umy;
      Dpmz=upz-u0-u0+umz;
      
      // Crossed derivatives
      // divide by 4 later
      D0xy=(im->ValeurBuffer(px+py)+
        im->ValeurBuffer(mx+my)-
        im->ValeurBuffer(px+my)-
        im->ValeurBuffer(mx+py))/4;  // /4
      D0yz=(im->ValeurBuffer(py+pz)+
        im->ValeurBuffer(my+mz)-
        im->ValeurBuffer(py+mz)-
        im->ValeurBuffer(my+pz))/4;  // /4
      D0zx=(im->ValeurBuffer(pz+px)+
        im->ValeurBuffer(mz+mx)-
        im->ValeurBuffer(pz+mx)-
        im->ValeurBuffer(mz+px))/4;  // /4
    
      //
      dxsq = D0x*D0x;  // /4
      dysq = D0y*D0y;  // /4
      dzsq = D0z*D0z;  // /4

      // multiply by 2 later
      //dxy2 = 2*D0x*D0y; // /2
      //dxz2 = 2*D0x*D0z; // /2
      //dyz2 = 2*D0z*D0y; // /2
      dxy = D0x*D0y; // /2
      dxz = D0x*D0z; // /2
      dyz = D0z*D0y; // /2

      delta0=dxsq+dysq+dzsq;   // (/4)


      if (delta0>.1) {
        meancurv_grad =  ( 0.5*(  (Dpmy+Dpmz)*dxsq 
                    +(Dpmx+Dpmz)*dysq
                    +(Dpmx+Dpmy)*dzsq
                    )
                 -( dxy*D0xy
                    +dxz*D0zx
                    +dyz*D0yz)
           ) /delta0/sqrt(delta0); 
      } else
    meancurv_grad = 0;


      image_res->FixeValeur(meancurv_grad);
      im       ->IncBuffer();
      image_res->IncBuffer();


    FinPour
    FinPour
    FinPour

  Sinon

      fprintf(stderr,"Func_DiscMeanCurvature() only for 3D for the moment \n");

  FinSi

  return image_res;


} //  Func_DiscMeanCurvature()

