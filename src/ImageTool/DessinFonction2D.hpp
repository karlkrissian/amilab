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


#ifndef _DessinFonction2D_HPP
#define _DessinFonction2D_HPP

#include "ParamBox.hpp"
#include "palette.hpp"
#include "FenetreDessin.hpp"
#include "inrimage.hpp"
//#include "BarreDefil.hpp"

#include "fonction2D.hpp"

//============================================================================
class DessinFonction2D : public FenetreDessin
//     -----------
{

   //-----------------------------------------------------
   //------ Fenetre d'affichage de l'image

   Widget       _label_souris;
   XmString     _label_string;
   char    _label_texte[100];

//   CBoutton*    ;

   //-----------------------------------------------------
   //------ Gestion des parametres

   Fonction2D   _fonction;

   float         _xmin;
   float         _xmax;
   float         _ymin;
   float         _ymax;

   unsigned char      _fix_xmin;
   unsigned char      _fix_xmax;
   unsigned char      _fix_ymin;
   unsigned char      _fix_ymax;

   float         _x_stics1;
   float         _x_stics2;

   float         _y_stics1;
   float         _y_stics2;

   // Variables pour le dessin de la position du curseur
   unsigned char      _curseur_ON;
   int       _curseur_x, _curseur_y, _curseur_z; 



private:
//===========


  void     CreeFenetreParametres();
  //       ---------------------

  void     CursorToImage( int* x, int* y, int* z, int* etat);
  //       --------------
  //  Renvoie la position dans l'image du curseur,
  //  etat vaut -1 s'il y a une erreur
  //               sinon il indique l'image cliqu�e : IMAGE_XY, IMAGE_XZ ou IMAGE_ZY


  void     DessineCurseur( int x, int y, int z);
  //       --------------
  //  Dessine la position du curseur sur toutes les coupes


public:
  
   DessinFonction2D( Widget AParent, char* ATitle, 
                            int type = CREATE_WINDOW);

  ~DessinFonction2D();

  void SetFunction(const Fonction2D& func);

  void SetXaxis( int xmin, int xmax, float Stics1, float Stics2);
  void SetYaxis( int ymin, int ymax, float Stics1, float Stics2);

  void FixeLimites( unsigned char fixXmin, unsigned char fixXmax,
		    unsigned char fixYmin, unsigned char fixYmax);

  void Rep2Fen( float xr, float yr, int& xi, int& yi);

  void DessinRepere();

  void Paint( unsigned char affiche = true);

  void ReDimensionne();

  void InitFenetre();


  void Boutton_Presse();
  void Boutton_Relache();
  void DeplaceSourisBout1();

  void Boutton2_Presse();
  void Boutton2_Relache();
  void DeplaceSourisBout2();

  void Boutton3_Presse();
  void Boutton3_Relache() {}
  void DeplaceSourisBout3() {}

  virtual void FermerFenetre() { this->~DessinFonction2D();}
  //             -------------

  static void CB_Fermer( Widget, void* cd, void*)
  //          ---------
  {
    ((DessinFonction2D*) cd)->FermerFenetre();
  }

  static void CB_redessine( void* cd );

  static void CB_a( void*  ) {}
  static void CB_b( void*  ) {}

}; // DessinFonction2D
//============================================================================

#endif // _DessinFonction2D_HPP
