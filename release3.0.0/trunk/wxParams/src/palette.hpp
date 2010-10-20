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
//  Fichier : palette.hpp
//
//  
//  Karl KRISSIAN   Sophia Antipolis,   le 9-11-96
//

#ifndef _PALETTE_HPP

#define _PALETTE_HPP

/*
#include <Xm/Xm.h>
*/

#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

//#include "style.hpp"
//#include <X11/Intrinsic.h>
//#include <X11/Shell.h>

#define PALETTE_RGB  1
#define PALETTE_TC   2

#include "couleur.hpp"

//===============================================================================
class CPalette
//     --------
{

public:

  int        _type_palette;

  //Display*      _display;
  //Window        _window;

  //Visual*       _visual;
  int        _depth;

  int          _screen_num;

  int _taille_palette;
  float   _pas_couleur;
  float          _pas_R, _pas_G, _pas_B;


  // Tableau de la table de couleurs : de taille 256*3
  // les 256 premieres valeurs: Rouge puis les 256 suivantes: Bleu puis Vert
  unsigned char _TC_RGB[768]; // 256 * 3

  unsigned long* _cells;


  int         _nb_coul_conservees; 
  // Nombre de couleurs parmis les premieres couleurs de la palette par
  // defaut qui sont conservees

  // Gestion du truecolor rgb,
  // a partir des masques rouge vert bleu

/*
  // decalage a droite
  int _decalD_rouge;
  int _decalD_vert;
  int _decalD_bleu;

  // decalage a gauche
  int _decalG_rouge;
  int _decalG_vert;
  int _decalG_bleu;
*/

  int _id_fgcolor;
  int _id_bgcolor;
  int _id_topshadowcolor;
  int _id_botshadowcolor;
  int _id_highlightcolor;
  int _id_bordercolor;
  int _id_selectcolor;

public:

//   CPalette( Display* display, int num=5);

  CPalette( wxWindow* window,  int num=5 );

  ~CPalette();

//  int Class() { return _visual->c_class; }

//  void InitDecalages();

  ClasseCouleur TC(   unsigned char val);

  void ChangeTypePalette(int nouveau_type);

  void TypePaletteRGB(int prec_R, int prec_G, int prec_B);
  void TypePaletteTC( unsigned char* tab_couleurs);
  //   -------------
  // Chargement d'une palette de couleurs

}; // CPalette
//===============================================================================




#endif //  _PALETTE_HPP
