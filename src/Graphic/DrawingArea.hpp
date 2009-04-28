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
// fichier DrawingArea.hpp
// 
// Karl KRISSIAN
// Sophia Antipolis	13/03/98
//


#ifndef _DRAWING_AREA_HPP
#define _DRAWING_AREA_HPP

// Fichiers � inclure :
// ====================


#include <X11/Intrinsic.h>
#include <Xm/DrawingA.h>
#include <stdio.h>
#include <Xm/Frame.h>
#include <Xm/Form.h>

#include "widget.hpp"
#include "palette.hpp"

#include <iostream.h>

// TYPES DE DESSIN
//
#define DESSIN_FENETRE 0
#define DESSIN_PIXMAP  1

// =========================================================================
//
class DrawingArea //: public CWidget
//     ===========
{

protected:

  Dimension	_hauteur;
  Dimension	_largeur;

  CPalette*     _palette;

  int	_pos_x;
  int	_pos_y;

  int	_souris_x;
  int	_souris_y;

  Display* display;
  int      screen_num;
  Window   fenetre;
  GC       contexte;

  // Declaration du pixmap
  unsigned char  _pixmap_alloue;
  Pixmap   _pixmap;
  GC       _pixmap_contexte; // pour effacer le pixmap 
  Drawable _ecran_dessin;
  int   _type_dessin; // DESSIN_FENETRE ou DESSIN_PIXMAP

  XtTranslations _trans_table;

  unsigned char  _widget_created;

public:

  Widget        _frame;
  Widget	_drawing_area;

  Constructeur DrawingArea( Widget parent, char* libelle);

  virtual Destructeur DrawingArea();

  unsigned char WidgetCreated() { return _widget_created; }

  void  CreeWidget( CPalette* palette);

  void  FreeWidget( );

  Widget GetDrawingArea() { return _drawing_area;}

  void   Unmanage() ;

  void   Manage() ;

  void  Recupere_dimensions( int* l, int* h);
  void  Fixe_dimensions( int l, int h);
  void  FixeCouleurFond( const ClasseCouleur&);
  void	FixeCouleurTrait( const ClasseCouleur&);
  void  FixeCouleurRemplissage( const ClasseCouleur&);
  void  FixeParametresLigne( unsigned int largeur, int style, int extremites, int intersection);

  void	 Fixe_drawing_bg( const ClasseCouleur&);

  // Dessiner dans la fenetre ou dans une PIXMAP
  void  FixeTypeDessin( int type);
  void  AffichePixmap();
  void  EffacePixmap();
  void  CreePixmap();
  void  DrawingAreaFree();

  // Fonction pour le contexte graphique
  void  FixeFonctionDessin( int fonction);

  void	Ligne( int x1, int y1, int x2, int y2);
  void	Rectangle( int x1, int y1, int x2, int y2);
  void  Polygone( int, XPoint*);
  void  Point( int, int);

  void  PlaceImage( int pos_x, int pos_y, XImage* ximage);
//  void  PutSlice(  int pos_x, int pos_y, const wxBitmap_ptr& slice)

  void  EffaceEcran( unsigned char expose);
  void  EffaceRegion( int h, int g, int b, int d, unsigned char expose);

  void  MoveTo( int x, int y) { _pos_x = x; _pos_y = y;}
  void  LineTo( int x, int y)
  {
    Ligne( _pos_x, _pos_y, x, y);
    _pos_x = x;
    _pos_y = y;
  }

  virtual void Boutton_Presse()      { printf("boutton 1 presse \n"); }
  virtual void Boutton2_Presse()     { printf("boutton 2 presse \n"); }
  virtual void Boutton3_Presse()     { printf("boutton 3 presse \n"); }

  virtual void Boutton_Relache()     { printf("boutton 1 relache \n");}
  virtual void Boutton2_Relache()    { printf("boutton 2 relache \n");}
  virtual void Boutton3_Relache()    { printf("boutton 3 relache \n");}

  virtual void DeplaceSourisBout1()  { printf("souris 1 deplacee \n");}
  virtual void DeplaceSourisBout2()  { printf("souris 2 deplacee \n");}
  virtual void DeplaceSourisBout3()  { printf("souris 3 deplacee \n");}

  virtual void DeplaceSourisShiftBout1()  { printf("shift souris 1 deplacee \n");}
  virtual void DeplaceSourisShiftBout2()  { printf("shift souris 2 deplacee \n");}
  virtual void DeplaceSourisShiftBout3()  { printf("shift souris 3 deplacee \n");}

  virtual void Message( int) { printf("Message()\n"); }
  virtual void InitWidget() {  printf("InitWidget()\n"); }
  virtual void Paint();
  virtual void ReDimensionne();

  static void CB_Expose( 	Widget, void*, void* );
  static void CB_Input( 	Widget, void*, void* );
  static void CB_Resize( 	Widget, void*, void* );


}; // DrawingArea

#endif // _DRAWING_AREA_HPP
