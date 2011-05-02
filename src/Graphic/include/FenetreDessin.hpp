
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
//  Fichier : FenetreDessin.hpp
//
//  class de base permettant de creer une fenetre de dessin
//  Avec les fonctions de base : dessin de ligne, de polygones, etc ...
//  
//  Karl KRISSIAN   Sophia Antipolis,   le 6-08-96
//


#ifndef _FENETRE_DESSIN_HPP
#define _FENETRE_DESSIN_HPP

//#include <dmalloc.h>

/*#include <X11/Intrinsic.h>
#include <X11/Shell.h>
#include <Xm/Label.h>
#include <Xm/Frame.h>
#include <Xm/Form.h>
#include <Xm/Xm.h>
#include <Xm/Text.h>
#include <Xm/DialogS.h>
#include <Xm/MwmUtil.h>
#include <Xm/DrawingA.h>
#include <Xm/MainW.h>*/
//#include <GL/gl.h>
//#include <GL/glx.h>       /* this includes the necessary X headers */

#include <stdio.h>
//#include <iostream.h>

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "palette.hpp"
#include "chaine.hpp"
#include "DefineClass.hpp"
#include "inrimage.hpp"
#include "wxDrawingArea.h"

#define CREATE_WINDOW           0
#define USE_PARENT_WINDOW       1
#define CREATE_TOPLEVEL_SHELL   3

#include <boost/scoped_ptr.hpp>
using namespace boost;

typedef shared_ptr<wxBitmap>    wxBitmap_ptr;
typedef shared_ptr<wxImage>    wxImage_ptr;
typedef shared_ptr<wxMemoryDC>  wxMemoryDC_ptr;
typedef shared_ptr<wxBrush>     wxBrush_ptr;
typedef shared_ptr<wxPen>       wxPen_ptr;

//=====================================================================
class FenetreDessin:  public wxFrame
//    =============
{

  DEFINE_CLASS(FenetreDessin);

protected:

  static FenetreDessin* _this;  // Utile pour les actions

  Chaine        _name;

  int        _type;

  int _hauteur;
  int _largeur;

  boost::shared_ptr<amilab::CPalette>     _palette;
//s  unsigned char       _palette_allouee;

//  Colormap  _color_map;

  int _pos_x;
  int _pos_y;

  int _souris_x;
  int _souris_y;

//  Display* display;
//  Window   fenetre;
//  GC       contexte;

  /// wx way of drawing
  /// device context in memory
  scoped_ptr<wxMemoryDC> _memory_dc;
  /// device context in memory
  scoped_ptr<wxBitmap>   _bitmap; 
  /// current brush
  scoped_ptr<wxBrush>   _current_brush;
  /// current pen
  scoped_ptr<wxPen>     _current_pen;


  unsigned char _fenetre_affichee;
  
  void*       _buttonpressed_callback;
  void*       _buttonpressed_data;
//  XButtonEvent*   _button_event;

  void*       _keypressed_callback;
  void*       _keypressed_data;
//  XKeyEvent*      _key_event;


/** name variable liee a OpenGL
 */

//   XVisualInfo*    _visual_info;

   void* CloseFunction;
   void* CloseData;

  wxMessageDialog* _message_dialog;


public:

//  Widget  _drawing_area;
  wxWindow*     _drawing_window;

   FenetreDessin( 
    wxWindow* parent, 
    const std::string& titre,
            int hauteur, int largeur, int type=CREATE_WINDOW);

  virtual ~FenetreDessin();

  Chaine& GetName() 
  {
    return _name;
  }

/*
  void AddButton(char* name, char* pixmap_file,
     XtCallbackProc callback,
     void* data);
*/

  void SetButtonPressedCallback(void* cb, void* d)
  {
    _buttonpressed_callback = cb;
    _buttonpressed_data     = d;
  }

  void SetKeyPressedCallback(void* cb, void* d)
  {
    _keypressed_callback = cb;
    _keypressed_data     = d;
  }

  wxWindow* GetDrawingWindow() {
    return _drawing_window;
  }

//  void ManageWidgets();
  virtual void  AfficheFenetre( );

  virtual void CreateDrawingArea();
  virtual void FreeDrawingArea();

  virtual void CreateContext();
  virtual void FreeContext();

  bool UpdateDrawingDimensions() {
    int l = _largeur;
    int h = _hauteur;
    _largeur = _drawing_window->GetClientSize().GetWidth();
    _hauteur = _drawing_window->GetClientSize().GetHeight();
    return ((l!=_largeur)||(h!=_hauteur));
  }

  //
  // Get the displayed image as an inrimage
  //
  InrImage* GetInrImage();
  //        -----------

//  XImage* RecupereImage();
  // Recupere sous la forme d'une XImage l'image du drawing area

  ClasseCouleur& _RGB( unsigned char red,
                      unsigned char green,
                      unsigned char blue);

  void  FixeCouleurFond         ( const ClasseCouleur&);
  void  SetPenColor        ( const wxColour&);
  void  SetTextBg               ( const wxColour&);
  void  SetTextFg               ( const wxColour&);
  void  FixeCouleurRemplissage  ( const ClasseCouleur&);
  void  FixeStyleRemplissage    ( const int& style);
  void  SetLineParameters( unsigned int largeur, int style, int extremites = -1, int intersection = -1);

  void  Recupere_fenetre_dimensions( int* l, int* h);
  void  Fixe_fenetre_dimensions( int l, int h, unsigned char parent=false );

  void  Recupere_fenetre_position( int* pos_x, int* pos_y);
  void  Fixe_fenetre_position( int pos_x, int pos_y);

  void  Fixe_drawing_bg( const wxColor& couleur);
  void  Fixe_drawing_dimensions( int l, int h);

  // Dessiner dans la fenetre ou dans une PIXMAP
  void  DrawingAreaInit( );
  void  DrawingAreaFree();
  void  DrawingAreaDisplay();
  void  DrawingAreaClear();

  // Fonction pour le contexte graphique
  void  FixeFonctionDessin( int fonction);


  void  Ligne( int x1, int y1, int x2, int y2);
  void  Cercle( int x1, int y1, int rayon);

  void  Ellipse( int x1, int y1, int r1, int r2);
  void  RemplitEllipse(int x1, int y1, int r1, int r2);

  void  Rectangle( int x1, int y1, int x2, int y2);
//  void  Polygone( int, XPoint*);
  void  Point( int, int);

  void  Texte( int x, int y,  const Chaine& chaine,
         unsigned char overwrite = false);

//  void  PlaceImage( int pos_x, int pos_y, XImage* ximage);
  void  PutSlice( int pos_x, int pos_y, const wxImage_ptr& slice);

  void  EffaceEcran( unsigned char expose);
  void  EffaceRegion( int h, int g, int b, int d, unsigned char expose);

  void  MoveTo( int x, int y) { _pos_x = x; _pos_y = y;}
  void  LineTo( int x, int y)
  {
    Ligne( _pos_x, _pos_y, x, y);
    _pos_x = x;
    _pos_y = y;
  }

  void SetMousePosition( int x, int y) {
    _souris_x = x;
    _souris_y = y;
  }

  virtual void OnWheel(wxMouseEvent& event) { printf("OnWheel()\n"); }

  virtual void Boutton_Presse()      { printf("boutton 1 presse \n"); }
  virtual void Boutton2_Presse()     { printf("boutton 2 presse \n"); }
  virtual void Boutton3_Presse()     { printf("boutton 3 presse \n"); }

  virtual void Boutton_Relache()     { printf("boutton 1 relache \n");}
  virtual void Boutton2_Relache()    { printf("boutton 2 relache \n");}
  virtual void Boutton3_Relache()    { printf("boutton 3 relache \n");}

  virtual void DeplaceSourisBout1()  { printf("souris 1 deplacee \n");}
  virtual void DeplaceSourisBout2()  { printf("souris 2 deplacee \n");}
  virtual void DeplaceSourisBout3()  { printf("souris 3 deplacee \n");}

  virtual void ShiftBout1_Presse()  { printf("shift+boutton 1 presse \n"); }
  virtual void ShiftBout2_Presse()  { printf("shift+boutton 2 presse \n"); }
  virtual void ShiftBout3_Presse()  { printf("shift+boutton 3 presse \n"); }

  virtual void DeplaceSourisShiftBout1()  { printf("shift souris 1 deplacee \n");}
  virtual void DeplaceSourisShiftBout2()  { printf("shift souris 2 deplacee \n");}
  virtual void DeplaceSourisShiftBout3()  { printf("shift souris 3 deplacee \n");}

  ///
  virtual void OnChar(wxKeyEvent& ) {  }

  ///
  virtual void Message( int) {}
  ///
  virtual void InitFenetre() { }
  ///
  virtual void Paint( unsigned char affiche = true);
  ///
  virtual void ReDimensionne(); 

  void SetCloseFunction( void* function, void* data )
  ///
  { 
     CloseFunction = function;
     CloseData = data;
  }

  void* GetCloseData()
  {
    return CloseData;
  }

  virtual void CloseWindow();
  ///
 
  void OnClose(wxCloseEvent& event);

  DECLARE_EVENT_TABLE()

}; // FenetreDessin
//=====================================================================


#endif // _FENETRE_DESSIN_HPP
