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
// Cr�ation d'images en st�r�o
// 2 couleurs (avec lunettes sp�ciales)
//
// Karl KRISSIAN
//
// Sophia Antipolis le 18-05-98

#ifndef _STEREO_HPP
#define _STEREO_HPP

#include "palette.hpp"

//#include <X11/Intrinsic.h>
//#include <X11/Shell.h>
#include <math.h>
#include <stdio.h>

#include "AMILabConfig.h"

#ifdef HAVE_MALLOC_H
#include <malloc.h>
#else
#include <stdlib.h>
#endif

//==========================================================
//
// Pour l'instant: Cr�ation d'une XImage St�r�o
// � partir de deux XImages
//
class Stereo
//     ======
{

#ifndef WIN32
#if 0
XImage* _image1;
  char*   _image1_data;

  XImage* _image2;
  char*   _image2_data;

  XImage* _image_stereo;
  char*   _image_stereo_data;

  float    _dist_yeux;        // distance entre les 2 yeux en cm
  float    _dist_oeil_ecran;  // distance centre des 2 yeux <--> objet
  float    _dist_ecran_objet;   // distance centre des 2 yeux <--> plan de projection

  float    _angle;

  float    _taille_pixel;     // taille en cm d'un pixel

public:

   Stereo( float d_yeux, float d_oeil_ecran, float d_ecran_objet,
                       float pixel_cm);

  ~Stereo();

  void Parametres( float d_yeux, float d_oeil_ecran, float d_ecran_objet,
                       float pixel_cm);

  void CreeStereo( CPalette* palette,
                   XImage* im1, XImage* im2, XImage** im_stereo);
#endif
#endif

}; // Stereo


//==========================================================


#endif // _STEREO_HPP
