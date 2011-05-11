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
//  
//  fichier DeriveesLissees
//
//  Karl Krissian    Las Palmas 10 07 2000
//



#ifndef _DERIVEES_LISSEES_HPP
#define _DERIVEES_LISSEES_HPP


#include "style.hpp"

#include "GeneralGaussianFilter.h"

//------------------------------------------------------------------------
// Creation d'un objet pour obtenir les derivees lissees en chaque point
// de l'image

class DeriveesLissees
//
{

protected:

  ///
  GeneralGaussianFilter* filtre;

  ///
  InrImage* _image;

  ///
  float _sigma;

  ///
  int _dimension;

  ///
  int _dx, _dxy;

  ///
  int _taille_x, _taille_y, _taille_z;

  /// Images en 3D : Espace
  InrImage *Exx0;
  ///
  InrImage *Exx1;
  ///
  InrImage *E002; 

  /// Images en 2D : Plan
  InrImage *Px00, *Px10, *P020, *Px01, *P011; 

  /// Images en 1D : Ligne
  InrImage *L100, *L200, *L010, *L110, *L001, *L101;

  /// Mask
  InrImage* _mask;

public:

   DeriveesLissees( InrImage* image_entree, float sigma,
				int dimension);

  ~DeriveesLissees();

  void SetMask(InrImage* mask)
  {
    if (mask->_format != WT_UNSIGNED_CHAR) return;
    if (mask->_tx != _image->_tx) return;
    if (mask->_ty != _image->_ty) return;
    if (mask->_tz != _image->_tz) return;

    _mask = mask;
  }

  unsigned char InitImagesDeriveesLissees();

  void    LibereImagesDeriveesLissees();

  void Filtre( InrImage* im, InrImage* res,
               int der_x, int der_y, int der_z);


  void InitImagePlan( InrImage* in, InrImage* res, int z);

  void InitImageLigne( InrImage* in, InrImage* res, int y);

  void CalculFonction2D( InrImage* image_entree, 
		       void* fonction, void* data);

  void CalculFonction2D_disc( InrImage* image_entree,  
			void* fonction, void* data);

  
  template< class DerivativesFunctor>
  void CalculFonction3D(  InrImage* image_entree, DerivativesFunctor df);

  void CalculFonction3D_disc( InrImage* image_entree,  
			void* fonction, void* data);

  void CalculFonction3D_luis( InrImage* image_entree,  
			void* fonction, void* data);

}; // DeriveesLissees


//------------------------------------------------------
template< class DerivativesFunctor>
void  DeriveesLissees :: CalculFonction3D( InrImage* image_entree, DerivativesFunctor df)
//                       ----------------
{ 
    int x,y,z;
    register float    *gx, *gy, *gz;
    register float    *Hxx, *Hyy, *Hzz, *Hxy, *Hxz, *Hyz; 
    InrImage         im_aux;
    float gradient[3];
    float hessien[3][3];
    float vx,vy,vz;
    unsigned char mask_OK;

  vx = image_entree->_size_x;
  vy = image_entree->_size_y;
  vz = image_entree->_size_z;

  printf("DeriveesLissees::CalculFonction3D() voxsize = %f %f %f\n",
   vx,vy,vz);

  Filtre( image_entree, Exx0, -1, -1, 0);
  Filtre( image_entree, Exx1, -1, -1, 1);
  Filtre( image_entree, E002,  0,  0, 2);
  Hzz = (float*) E002->Buffer();

  //--- Calcul de la nouvelle image  ---
  Pour( z, 0, _taille_z -1)

      Si z==0 Alors
        printf(" z = ");
      Sinon
        printf("\b\b\b");  
      FinSi
      printf("%3d",z); fflush(stdout);
      Si z==_taille_z-1 AlorsFait printf("\b\b\b\b\b\b\b");

    InitImagePlan( Exx0, &im_aux, z);
    Filtre( &im_aux, Px00, -1, 0, -1);
    Filtre( &im_aux, Px10, -1, 1, -1);
    Filtre( &im_aux, P020, -1, 2, -1);
    Filtre( P020,    P020,  0,-1, -1);

    Hyy = (float*) P020->Buffer();

    InitImagePlan( Exx1, &im_aux, z);
    Filtre( &im_aux, Px01, -1, 0, -1);
    Filtre( &im_aux, P011,  0, 1, -1);

    Hyz = (float*) P011->Buffer();

    Pour( y, 0, _taille_y -1)

      InitImageLigne( Px00, &im_aux, y);
      Filtre( &im_aux, L100,  1, -1, -1);
      Filtre( &im_aux, L200,  2, -1, -1);

      gx  = (float*) L100->Buffer();
      Hxx = (float*) L200->Buffer();

      InitImageLigne( Px10, &im_aux, y);
      Filtre( &im_aux, L010,  0, -1, -1);
      Filtre( &im_aux, L110,  1, -1, -1);

      gy  = (float*) L010->Buffer();
      Hxy = (float*) L110->Buffer();

      InitImageLigne( Px01, &im_aux, y);
      Filtre( &im_aux, L001,  0, -1, -1);
      Filtre( &im_aux, L101,  1, -1, -1);

      gz  = (float*) L001->Buffer();
      Hxz = (float*) L101->Buffer();

      Pour( x, 0, _taille_x-1)
        mask_OK = ((_mask==NULL)Ou ((_mask!=NULL) Et ((*_mask)(x,y,z)>0.5)));

        gradient[0] = *gx / vx;
        gradient[1] = *gy / vy;
        gradient[2] = *gz / vz;

        hessien[0][0] = *Hxx /vx/vx;
        hessien[1][0] = hessien[0][1] = *Hxy /vx/vy;
        hessien[2][0] = hessien[0][2] = *Hxz /vx/vz;
        hessien[1][1] = *Hyy /vy/vy;
        hessien[1][2] = hessien[2][1] = *Hyz /vy/vz;
        hessien[2][2] = *Hzz /vz/vz;

        df(gradient,  hessien,  (void*) &mask_OK);

        Hxx++; Hyy++; Hzz++;
        Hxy++; Hxz++; Hyz++;
        gx++;  gy++;  gz++;
 
      FinPour // x
    FinPour // y
  FinPour // z

} // CalculFonction3D()


#endif // _DERIVEES_LISSEES_HPP
