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

#include "ImageDerivatives.h"
#include "GeneralGaussianFilter.h"
#include <boost/format.hpp>

//------------------------------------------------------------------------------
InrImage* Func_Laplacian( InrImage* im )
//        ----------------------
{

  InrImage*       image_res;
  std::string     resname;
  register int    x,y,z;
  int txy,px,mx,py,my,pz,mz;
  double u0,umx,upx,umy,upy,umz,upz;
  double laplacian;
 

  resname = (boost::format("%s.laplacian") % im->GetName()).str();
  image_res = new InrImage(WT_FLOAT, resname.c_str() , im);

  image_res->InitImage(0);


  mx = -1;   
  px = 1;
  my = -im->DimX();  
  py = -my;
  txy = im->DimX()*im->DimY();
  mz = -txy; 
  pz = -mz;

  im       ->InitBuffer();
  image_res->InitBuffer();

  Pour(z,0,im->_tz-1)
  Pour(y,0,im->_ty-1)
  Pour(x,0,im->_tx-1)

      if (x==0)    mx =  1;   else mx = -1;
      if (x==im->DimX()-1) px = -1;   else px =  1;
      if (y==0)    my =  im->DimX();  else my = -im->DimX();
      if (y==im->DimY()-1) py = -im->DimX();  else py =  im->DimX();
      if (z==0)    mz =  txy; else mz = -txy;
      if (z==im->DimZ()-1) pz = -txy; else pz =  txy;

      u0 = im->ValeurBuffer();
      umx=im->ValeurBuffer(mx);
      upx=im->ValeurBuffer(px);
      umy=im->ValeurBuffer(my);
      upy=im->ValeurBuffer(py);

      laplacian  = upx-u0-u0+umx;
      laplacian += upy-u0-u0+umy;
      if (im->DimZ()>3) {
        umz=im->ValeurBuffer(mz);
        upz=im->ValeurBuffer(pz);
        laplacian += upz-u0-u0+umz;
      }

      image_res->FixeValeur(laplacian);
      im       ->IncBuffer();
      image_res->IncBuffer();

  FinPour
  FinPour
  FinPour
  return image_res;

} //  Func_Laplacian()


//------------------------------------------------------------------------------
// 
// 
//
InrImage* Func_SecDerGrad( InrImage* im, float sigma )
{
  
    InrImage*       image_entree;
    InrImage*       image_res;
    GeneralGaussianFilter* filtre;
    int             mode;
    std::string     resname;
    int           x,y,z;
    Vect3D<double>   Grad;
    double           hessien[9];
    double           H[3][3];
    double           res;
    double           normgrad2;

  Si (im->_format == WT_FLOAT) Alors
    image_entree = im;
  Sinon
    // conversion de l'image initiale en float
    image_entree = new InrImage( WT_FLOAT, "image_reel.inr.gz", 
                 im);
    (*image_entree) = (*im);
  FinSi

  Si image_entree->_tz > 1 Alors
    mode = MODE_3D; 
  Sinon
    mode = MODE_2D; 
  FinSi

  filtre = new GeneralGaussianFilter(image_entree,  mode);

  filtre->Utilise_Image(   false);
  filtre->UtiliseHessien(  true);
  filtre->UtiliseGradient( true);

  filtre->InitDerivees();
  filtre->GammaNormalise(false);

  filtre->InitFiltre( sigma, MY_FILTRE_CONV );  
  filtre->CalculFiltres( );

  resname = (boost::format("%s.d2grad") % image_entree->GetName()).str();
  image_res = new InrImage(WT_FLOAT, resname.c_str() , image_entree);
  image_res->InitImage(0.0);

  image_res->InitBuffer();
  Pour( z, 0, image_res->_tz - 1)
  Pour( y, 0, image_res->_ty - 1)
  Pour( x, 0, image_res->_tx - 1)

    Grad = filtre->Gradient(x,y,z);
    filtre->Hessien( hessien, x,y,z);

    H[0][0] = hessien[0];
    H[0][1] = hessien[1];
    H[0][2] = hessien[2];
    H[1][0] = hessien[3];
    H[1][1] = hessien[4];
    H[1][2] = hessien[5];
    H[2][0] = hessien[6];
    H[2][1] = hessien[7];
    H[2][2] = hessien[8];


    res = Grad.x*(    H[0][0]*Grad.x+
         2*H[1][0]*Grad.y+
             2*H[2][0]*Grad.z) +
          Grad.y*(    H[1][1]*Grad.y+
                 2*H[2][1]*Grad.z) +
          Grad.z*     H[2][2]*Grad.z;

    normgrad2 = Grad.x*Grad.x+Grad.y*Grad.y+Grad.z*Grad.z;
    if (normgrad2>1E-5)  res /= normgrad2;

    image_res->FixeValeur(res);

    image_res->IncBuffer();

  FinPour
  FinPour
  FinPour

  delete filtre;
  Si image_entree!=im AlorsFait delete image_entree;

  return image_res;

} // Func_SecDerGrad()


//------------------------------------------------------------------------------
// 
// Don't use voxel size
//
InrImage* Func_SecDerGrad2( InrImage* im, float sigma )
{
  
    InrImage*       image_entree;
    InrImage*       image_res;
    GeneralGaussianFilter* filtre;
    int             mode;
    std::string     resname;
    int           x,y,z;
    Vect3D<double>   Grad;
    double           hessien[9];
    double           H[3][3];
    double           res;
    double           normgrad2;

  Si (im->_format == WT_FLOAT) Alors
    image_entree = im;
  Sinon
    // conversion de l'image initiale en float
    image_entree = new InrImage( WT_FLOAT, "image_reel.inr.gz", 
                 im);
    (*image_entree) = (*im);
  FinSi

  Si image_entree->_tz > 1 Alors
    mode = MODE_3D; 
  Sinon
    mode = MODE_2D; 
  FinSi

  filtre = new GeneralGaussianFilter(image_entree,  mode);

  filtre->DontUseVoxelSize();
  filtre->Utilise_Image(   false);
  filtre->UtiliseHessien(  true);
  filtre->UtiliseGradient( true);

  filtre->InitDerivees();
  filtre->GammaNormalise(false);

  filtre->InitFiltre( sigma, MY_FILTRE_CONV );  
  filtre->CalculFiltres( );

  resname = (boost::format("%s.d2grad") % image_entree->GetName()).str();
  image_res = new InrImage(WT_FLOAT, resname.c_str() , image_entree);
  image_res->InitImage(0.0);

  image_res->InitBuffer();
  Pour( z, 0, image_res->_tz - 1)
  Pour( y, 0, image_res->_ty - 1)
  Pour( x, 0, image_res->_tx - 1)

    Grad = filtre->Gradient(x,y,z);
    filtre->Hessien( hessien, x,y,z);

    H[0][0] = hessien[0];
    H[0][1] = hessien[1];
    H[0][2] = hessien[2];
    H[1][0] = hessien[3];
    H[1][1] = hessien[4];
    H[1][2] = hessien[5];
    H[2][0] = hessien[6];
    H[2][1] = hessien[7];
    H[2][2] = hessien[8];

    res = Grad.x*(    H[0][0]*Grad.x+
         2*H[1][0]*Grad.y+
             2*H[2][0]*Grad.z) +
          Grad.y*(    H[1][1]*Grad.y+
                 2*H[2][1]*Grad.z) +
          Grad.z*     H[2][2]*Grad.z;

    normgrad2 = Grad.x*Grad.x+Grad.y*Grad.y+Grad.z*Grad.z;
    if (normgrad2>1E-5)  res /= normgrad2;

    image_res->FixeValeur(res);

    image_res->IncBuffer();

  FinPour
  FinPour
  FinPour

  delete filtre;
  Si image_entree!=im AlorsFait delete image_entree;

  return image_res;

} // Func_SecDerGrad2()


//------------------------------------------------------------------------------
InrImage* Func_Gradient( InrImage* im, float sigma )
{

  InrImage*       image_entree;
  InrImage*       image_der;
  InrImage*       image_res;
  GeneralGaussianFilter* filtre;
  std::string     resname;
  int             mode;

  resname = (boost::format("%1%.normgrad") % im->GetName()).str();

  Si (im->_format == WT_FLOAT) Alors
    image_entree = im;
  Sinon
    // conversion de l'image initiale en float
    image_entree = new InrImage( WT_FLOAT, "image_reel.inr.gz", 
                 im);
    (*image_entree) = (*im);
  FinSi

  Si image_entree->_tz > 1 Alors
    mode = MODE_3D; 
    image_res = new InrImage(WT_FLOAT, 3,resname.c_str(), im);
  Sinon
    mode = MODE_2D; 
    image_res = new InrImage(WT_FLOAT, 2,resname.c_str(), im);
  FinSi

  resname = (boost::format("%1%.filter") % im->GetName()).str();

  image_der = new InrImage(WT_FLOAT, resname.c_str() , im);


  filtre = new GeneralGaussianFilter( image_entree,  mode);

  filtre->GammaNormalise(false);
  filtre->InitFiltre( sigma, MY_FILTRE_CONV );  


  Si mode == MODE_2D Alors

    filtre->MyFiltre( image_entree, image_der, 1, 0, -1);

    image_res->InitBuffer();
    image_der->InitBuffer();
    Repeter
      image_res->VectFixeValeur(0, image_der->ValeurBuffer()
                   /im->_size_x);
      image_der->IncBuffer();
    JusquA Non(image_res->IncBuffer()) FinRepeter

    filtre->MyFiltre( image_entree, image_der, 0, 1, -1);

    image_res->InitBuffer();
    image_der->InitBuffer();
    Repeter
      image_res->VectFixeValeur(1, image_der->ValeurBuffer()
                   /im->_size_y);
      image_der->IncBuffer();
    JusquA Non(image_res->IncBuffer()) FinRepeter

  Autrement
  Si mode == MODE_3D Alors

    filtre->MyFiltre( image_entree, image_der, 1, 0, 0);

    image_res->InitBuffer();
    image_der->InitBuffer();
    Repeter
      image_res->VectFixeValeur(0, image_der->ValeurBuffer()
                   /im->_size_x);
      image_der->IncBuffer();
    JusquA Non(image_res->IncBuffer()) FinRepeter

    filtre->MyFiltre( image_entree, image_der, 0, 1, 0);

    image_res->InitBuffer();
    image_der->InitBuffer();
    Repeter
      image_res->VectFixeValeur(1, image_der->ValeurBuffer()
                   /im->_size_y);
      image_der->IncBuffer();
    JusquA Non(image_res->IncBuffer()) FinRepeter

    filtre->MyFiltre( image_entree, image_der, 0, 0, 1);
 
    image_res->InitBuffer();
    image_der->InitBuffer();
    Repeter
      image_res->VectFixeValeur(2, image_der->ValeurBuffer()
                   /im->_size_z);
      image_der->IncBuffer();
    JusquA Non(image_res->IncBuffer()) FinRepeter
  FinSi
  
  Si image_entree!=im AlorsFait delete image_entree;
  delete filtre;
  delete image_der;

  return image_res;

}

//------------------------------------------------------------------------------
InrImage* Func_Filter( InrImage* im, float sigma, 
               int der_x, int der_y, int der_z)
{

  InrImage*       image_entree;
  InrImage*       image_res;
  GeneralGaussianFilter* filtre;
  std::string     resname;
  int             mode;

  Si (im->_format == WT_FLOAT) Alors
    image_entree = im;
  Sinon
    // conversion de l'image initiale en float
    image_entree = new InrImage( WT_FLOAT, "image_reel.inr.gz", 
                 im);
    (*image_entree) = (*im);
  FinSi

  resname = (boost::format("%s.filter") % im->GetName()).str();
  image_res = new InrImage(WT_FLOAT, resname.c_str() , im);

  Si image_entree->_tz > 1 Alors
    mode = MODE_3D; 
  Sinon
    mode = MODE_2D; 
  FinSi

  filtre = new GeneralGaussianFilter( image_entree,  mode);

  filtre->GammaNormalise(false);
  filtre->InitFiltre( sigma, MY_FILTRE_CONV );  


  filtre->MyFiltre( image_entree, image_res,  der_x, der_y, der_z);

  
  Si image_entree!=im AlorsFait delete image_entree;
  delete filtre;

  return image_res;

}
