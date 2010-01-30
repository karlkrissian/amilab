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
// Cr�tion d'images en st��
// 2 couleurs (avec lunettes sp�iales)
//
// Karl KRISSIAN 
//
// Sophia Antipolis le 18-05-98


#include "Stereo.hpp"

#ifndef WIN32
#if 0
//-----------------------------------------------------------------------------------
Stereo ::  Stereo( float d_yeux, float d_oeil_ecran, float d_ecran_objet,
//                  ------------
                                         float pixel_cm)
{

  _image1 = _image2 = _image_stereo = NULL;

  _dist_yeux        = d_yeux;
  _dist_oeil_ecran  = d_oeil_ecran;
  _dist_ecran_objet = d_ecran_objet;
  _taille_pixel     = 1.0/pixel_cm;

  _angle = 2*atan( _dist_yeux/2.0/(_dist_oeil_ecran + _dist_ecran_objet));

} // Constructor


//-----------------------------------------------------------------------------------
Stereo :: ~Stereo()
//                  -----------
{

  Si _image_stereo != NULL Alors
     XDestroyImage( _image_stereo);
    _image_stereo = NULL;
    _image_stereo_data = NULL;
  FinSi

} // Destructor


//-----------------------------------------------------------------------------------
void Stereo :: Parametres( float d_yeux, float d_oeil_ecran, float d_ecran_objet,
//                       ----------
                                         float pixel_cm)
{

  _image1 = _image2 = NULL;

  Si _image_stereo != NULL Alors
     XDestroyImage( _image_stereo);
    _image_stereo = NULL;
    _image_stereo_data = NULL;
  FinSi

  _dist_yeux        = d_yeux;
  _dist_oeil_ecran  = d_oeil_ecran;
  _dist_ecran_objet = d_ecran_objet;
  _taille_pixel     = 1.0/pixel_cm;

  _angle = 2*atan( _dist_yeux/2.0/(_dist_oeil_ecran + _dist_ecran_objet));

}


//-----------------------------------------------------------------------------------
void Stereo :: CreeStereo( CPalette* palette, 
//                       ----------
                                     XImage* im1, XImage* im2, XImage** im_stereo)
{

#if defined(__WXMOTIF__)


    int decalage;
    int largeur, hauteur;
    //  int pos_R, pos_G, pos_B;
    int image_octets=0;
    int x,y,pos,pos1; //,pos2;
    int diff_decalage;
    ClasseCouleur intensite;
    unsigned short red,blue;
    unsigned long  redpixel, bluepixel;

  *im_stereo = NULL;

  Si (im1->width  != im2->width ) Ou
     (im1->height != im2->height) Alors
    printf("Stereo::CreeStereo, \t images de diff�entes dimensions\n");
    return;
  FinSi

  _image1 = im1;
  _image1_data = im1->data;

  _image2 = im2;
  _image2_data = im2->data;

  decalage = int( _dist_yeux/(_dist_oeil_ecran+_dist_ecran_objet)*
		     _dist_ecran_objet/_taille_pixel );

  largeur = im1->width  + decalage;
  hauteur = im1->height;

  Si _image_stereo != NULL Alors
    XDestroyImage( _image_stereo);
    _image_stereo = NULL;
  FinSi

  image_octets = 4;

  _image_stereo_data = (char*) malloc( largeur*hauteur* image_octets);

  _image_stereo =  XCreateImage( palette->_display, 
				 palette->_visual,
				 palette->_depth,
				 ZPixmap, 
				 0, 
				 _image_stereo_data,
				 largeur, 
				 hauteur,
				 8*image_octets, 
				 largeur* image_octets );

  Si (_image_stereo_data == NULL) Ou (_image_stereo == NULL) Alors
    printf("Stereo::CreeStereo() \t erreur d'allocation de l'image %d %d \n",
            largeur,hauteur);
    return;
  FinSi

  // On initialise l'image �0
  pos = 0;
  Pour( y, 0, _image_stereo->height-1 )
  Pour( x, 0, _image_stereo->width-1 )

    _image_stereo_data[pos++] = 0; _image_stereo_data[pos++] = 0;
    _image_stereo_data[pos++] = 0; _image_stereo_data[pos++] =  0;

  FinPour // x
  FinPour // y


  // On ecrit l'image 1
  pos1 = 0;
  diff_decalage = decalage*image_octets;

  Pour( y, 0, _image1->height-1 )
    Pour( x, 0, _image1->width-1 )

      Si (x-diff_decalage > 0) Et
         (x-diff_decalage < _image2->width) 
      Alors
        redpixel = XGetPixel(_image2,x-diff_decalage,y);
// TODO: Wrong but the whole color stereo  
// should be removed ...
        red = redpixel;
/*
        red =  (unsigned short) ((redpixel & 
                                   palette->_visual->red_mask
				  ) >> palette->_decalG_rouge);
*/
      Sinon
        red = 0;
      FinSi

      bluepixel = XGetPixel(_image1,x,y);
      // TODO: get rid of color stereo
      blue = bluepixel;
/*
      blue =  (unsigned short) ((bluepixel & 
				 palette->_visual->blue_mask
				 ) >> palette->_decalG_bleu);
*/
      intensite.Set( red, 0, blue);

      XPutPixel(_image_stereo, x, y, intensite.GetPixel());
      pos1+=image_octets;

    FinPour // x
  FinPour // y


  *im_stereo = _image_stereo;

#endif

} // CreeStereo()



//==========================================================

#endif
#endif
