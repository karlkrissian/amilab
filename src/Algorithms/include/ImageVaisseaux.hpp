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
// Description de la classe Vaisseau
// fichier ImageVaisseaux.hpp
//
// Karl KRISSIAN
//
// Sophia Antipolis le 21-05-97
//

#ifndef _IMAGE_VAISSEAUX_HPP
#define _IMAGE_VAISSEAUX_HPP

#include "style.hpp"

#include "AMILabConfig.h"

#ifdef HAVE_MALLOC_H
#include <malloc.h>
#else
#include <stdlib.h>
#endif

#include "Vaisseau.hpp"
#include "inrimage.hpp"


#define MAX_EXTREMITES 500
#define MAX_VAISSEAUX  100

//=============================================================
class ImageVaisseaux
//     --------------
{

  InrImage* _image;

  int    _nb_vaisseaux;
  int    _nb_extremites;

  Point3D   _tab_ext[MAX_EXTREMITES];
  Vaisseau  _tab_vais[MAX_VAISSEAUX];

public:

   ImageVaisseaux( char* nom_image);
  //           --------------

  ~ImageVaisseaux();
  //          --------------

  unsigned char RechercheVaisseau();
  //      -----------------

  void CreeImageCentres();
  //   ----------------

  void CreeImageVaisseaux();
  //   ------------------

}; // ImageVaisseaux


#endif //_IMAGE_VAISSEAUX_HPP
