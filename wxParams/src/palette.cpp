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
//  Fichier : palette.cpp
//
//  
//  Karl KRISSIAN   Sophia Antipolis,   le 9-11-96
//

//
// Voila les fonctions de X11 pour les couleurs :
//
// ColorCell functions
// ===================
// BlackPixel, WhitePixel, XAllocColor, XAllocColorCells, XAllocColorPlanes,
// XAllocNamedColor, XFreeColors, XLookupColor, XParseColor, XQueryColor,
// XQueryColors, XStoreColor, XStoreColors, XStoreNamedColor.
//
// Colormap Functions
// ==================
// DefaultColormap, DisplayCells, XCopyColormapAndFree, XCreateColormap,
// XFreeColormap, XGetStandardColormap, XInstallColormap, XListInstalledColormap,
// XSetWindowColormap, XUninstallColormap
//
//
//#include "style.hpp"

#include "palette.hpp"
//#include <Xm/Xm.h>
//#include <Xm/ToggleB.h>
#include "wx/window.h"

#if defined(__WXX11__)
#include "wx/x11/private.h"
#endif

#include <stdio.h>

//extern unsigned char      GB_debug;
//#define aff_err(a) if (GB_debug)  fprintf(stderr,a);

//----------------------------------------------------------------------------
// Defaut int num=5
CPalette::CPalette( wxWindow* window, int num )
//                                 --------
{
    char    nom_classe[6][20];

//    XWindowAttributes w_attrib;

  //aff_err("  CPalette() Debut\n");

/*
  _id_fgcolor = -1;
  _id_bgcolor = -1;
  _id_topshadowcolor       = -1;
  _id_botshadowcolor       = -1;
  _id_highlightcolor       = -1;
  _id_bordercolor          = -1;
  _id_selectcolor          = -1;

  strcpy(nom_classe[PseudoColor],"PseudoColor");
  strcpy(nom_classe[GrayScale],  "GrayScale");
  strcpy(nom_classe[DirectColor],"DirectColor");
  strcpy(nom_classe[TrueColor],  "TrueColor");
  strcpy(nom_classe[StaticColor],"StaticColor");
  strcpy(nom_classe[StaticGray], "StaticGray");

#if defined(__WXMOTIF__)
  _display     = (Display*) window->GetXDisplay();
  _window      = (Window) window->GetClientXWindow();
  _screen_num  = DefaultScreen  ( _display);
#elif defined(__WXX11__)
  _display     = (Display*) wxGlobalDisplay();
  _window      = (Window) window->GetMainWindow();
  _screen_num  = DefaultScreen  ( _display);
#endif


  //----- Quelques variables de base
//  _display     = XtDisplay(top_level);
//  _screen_num  = XtScreen(top_level);

//  _toplevel   = top_level;


  aff_err("  CPalette() 0.1 \n");
  //----- Recuperation du type visuel 
  XGetWindowAttributes( _display, _window, &w_attrib);
  aff_err("  CPalette() 0.2 \n");

//  XGetWindowAttributes( _display, DefaultRootWindow(_display), &w_attrib);
  _visual = w_attrib.visual;
  _depth  = w_attrib.depth;
  if (GB_debug )  
    fprintf(stderr,"window attributes : visual class %s\n",
      nom_classe[w_attrib.visual->c_class]);

  aff_err("  CPalette() 1 \n");
*/
    _type_palette        = PALETTE_RGB;

//    InitDecalages();


   //aff_err("  CPalette() Fin \n");
   return;



} // 


//-------------------------------------------------------------------------------
CPalette ::~CPalette()
//                                --------
{

} // ~

/*
//--------------------------------------------------------------------------------
void CPalette :: InitDecalages()
//
{ 
    unsigned long mask;
    int   i;

  // Valeurs par defaut
  _decalG_rouge = 0;
  _decalG_vert  = 8;
  _decalG_bleu  = 16;

  _decalD_rouge = 0;
  _decalD_vert  = 0;
  _decalD_bleu  = 0;

  
  // Rouge
  mask = _visual->red_mask;
  i = 0;
  TantQue mask % 2 == 0 Faire
    i++;
    mask = mask >> 1;
  FinTantQue

  _decalG_rouge = i;

  i = 0;
  TantQue mask % 2 == 1 Faire
    i++;
    mask = mask >> 1;
  FinTantQue
  
  if (i>8) {
    _decalG_rouge += i-8;
  Sinon
    _decalD_rouge = 8-i;
  } // end if

  // Vert
  mask = _visual->green_mask;
  i = 0;
  TantQue mask % 2 == 0 Faire
    i++;
    mask = mask >> 1;
  FinTantQue

  _decalG_vert = i;

  i = 0;
  TantQue mask % 2 == 1 Faire
    i++;
    mask = mask >> 1;
  FinTantQue
  
  if (i>8) {
    _decalG_vert += i-8;
  Sinon
    _decalD_vert = 8-i;
  } // end if

  // Bleu
  mask = _visual->blue_mask;
  i = 0;
  TantQue mask % 2 == 0 Faire
    i++;
    mask = mask >> 1;
  FinTantQue

  _decalG_bleu = i;

  i = 0;
  TantQue mask % 2 == 1 Faire
    i++;
    mask = mask >> 1;
  FinTantQue
  
  if (i>8) {
    _decalG_bleu += i-8;
  Sinon
    _decalD_bleu = 8-i;
  } // end if

} // InitDecalages()
*/


//---------------------------------------------------------------------
ClasseCouleur CPalette::TC( unsigned char val) 
//                       --
{
    if (_type_palette != PALETTE_TC)
    return ClasseCouleur(0,0,0);

    return ClasseCouleur( _TC_RGB[val],
                          _TC_RGB[val+256],
                          _TC_RGB[val+512]);

} //TC()


//---------------------------------------------------------------------
void CPalette :: ChangeTypePalette(int nouveau_type)
//                         -----------------
{
  _type_palette = nouveau_type;
} // ChangeTypePalette()



//---------------------------------------------------------------------
void CPalette :: TypePaletteRGB( int prec_R, int prec_G, int prec_B)
//                         --------------
{
  _type_palette = PALETTE_RGB;
} // TypePaletteRGB()


//---------------------------------------------------------------------
void CPalette :: TypePaletteTC(  unsigned char* tab_couleurs)
//                         -------------
// Chargement d'une palette de couleurs
{
    int i;

  for( i=0;i<=767;i++)
    _TC_RGB[i] = tab_couleurs[i];

  _type_palette = PALETTE_TC;
  return;
} // TypePaletteTC()


