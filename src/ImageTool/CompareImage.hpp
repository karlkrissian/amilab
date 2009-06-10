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
// Visualisation d'inrimage
// fichier CompareImage.hpp
//
// Karl KRISSIAN 
//
// Sophia Antipolis le 21-01-97
//

#ifndef _COMPARE_IMAGE_HPP
#define _COMPARE_IMAGE_HPP

#include "ParamBox.hpp"
//#include "BarreDefil.hpp"
#include "DessinImage.hpp"

//============================================================================
class CompareImage : public DessinImage
//     -----------
{


//  friend class DessinImage;

//------------------------------------
   DessinImage* _dessin_image;

   // num�ro de cet objet dans le tableau des comparaison
   // de _dessin_image
   int       _numero_fenetre;

   // Cette variable permet de forcer le dessin des
   // 3 coupes au lancement de l'objet
   unsigned char      _premier_affichage;


   // Intensite

   // Si true, normalise l'intensite min et max de l'image
   // copmaree par rapport a l'image de reference
   unsigned char   _normalise_intensite;
   unsigned char   _depend_position;
   unsigned char   _depend_intensite;

private:
//===========

  void     InitMinMax( );
  //       ----------

public:
  
  Constructeur CompareImage( wxWindow* parent,
                            char* ATitle, InrImage::ptr image, 
                            DessinImage* dessin_image, int l=650, int h=400);

  Destructeur CompareImage();

  const char*  NomImage() { return _image_initiale->Nom();}

  void NumeroFenetre( int num) { _numero_fenetre = num;}

  void FixeTableCouleurs( unsigned char* tab);

  void FixeDecalStereo( int angle); // angle en degr�s

  void MAJ_label( int x, int y, int z, int trouve);

  void RecupereParametres();

  void Paint( unsigned char esclave=false);

  void DessineAnimation( int planZ);

  void ReDimensionne();

/*
  void Boutton_Presse() {}
  void Boutton_Relache() {}
  void DeplaceSourisBout1() {}

  void Boutton2_Presse() {}
  void Boutton2_Relache() {}
  void DeplaceSourisBout2() {}
*/

  virtual void FermerFenetre();
  //             -------------

  static void CB_Normalise( void* cd);
  //          ------------

}; // CompareImage
//============================================================================

#endif // _COMPARE_IMAGE_HPP
