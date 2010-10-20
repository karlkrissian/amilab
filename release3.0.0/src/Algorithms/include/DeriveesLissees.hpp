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

  void CalculFonction3D( InrImage* image_entree, 
		       void* fonction, void* data);

  void CalculFonction3D_disc( InrImage* image_entree,  
			void* fonction, void* data);

  void CalculFonction3D_luis( InrImage* image_entree,  
			void* fonction, void* data);

}; // DeriveesLissees

#endif // _DERIVEES_LISSEES_HPP
