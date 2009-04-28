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
// Visualisation d'histogramme
// fichier DessinHisto.hpp
//
// Karl KRISSIAN 
//
// Sophia Antipolis le 15-03-98
//

#ifndef _DESSIN_HISTO_HPP
#define _DESSIN_HISTO_HPP


#include "DrawingArea.hpp"
#include "palette.hpp"
#include "inrimage.hpp"
#include "math1.hpp"

//============================================================================
class ParamDessinHisto
//     ---------------
{

public:

  // Savoir si la valeur a ete precisee en argument
  // au lancement du programme
  unsigned char min_arg;
  unsigned char max_arg;
  unsigned char ni_arg;
  unsigned char ptmax_arg;

  float    min,max;
  int  ni,ptmax;

  Constructeur ParamDessinHisto() {}
  //           ---------------

  void Initialise()
  //   ----------
  {
    min_arg = false;
    max_arg = false;
    ni_arg = false;
    ptmax_arg = false;
    min   = -10;
    max   =  10;
    ni    = 255;
    ptmax = 1000;
  }

}; // ParamDessinHisto

//=========================================================================
class DessinHisto : public DrawingArea
//     -----------
{

protected:

   InrImage*    _image;

   //-----------------------------------------------------
   //
   int       _souris_x_initiale;
   int       _souris_y_initiale;
   int       _IntMin_initial, _IntMax_initial;
   int       _Int_initial;

   int       _affichage_max_initial;

   //-----------------------------------------------------
   //------ Gestion des parametres

   unsigned char      _logarithme;

   float         _Imin,_Imax; // intensite min et intensite max
   int       _intervalle_min, _intervalle_max;

   int       _nb_pts_max;
   int       _affichage_max;
   int       _nb_pts_cumul;
   int       _nb_intervalles;
   double   _pas_intervalle;
   int       _nb_pts_taille;
   int*      _nb_pts;      // nombre de points par intervalle
   float*        _log2_nb_pts; // histogramme du log

   // Variables pour le dessin de la position du curseur
   unsigned char      _curseur_ON;
   int       _curseur_x, _curseur_y, _curseur_z; 

private:
//===========

  int Intervalle( float intensite);
  //     ----------
  // Fonction en ligne  

  int IntervalleBuffer();
  //     ----------------
  // Fonction en ligne  

  void CalculePointsParIntervalle();
  //   --------------------------

  unsigned char  VerifieMinMax( );
  //       -------------

  void     InitCouleurs();
  //       ------------

public:

  Constructeur DessinHisto(Widget parent, char* libelle, InrImage* image, 
  //           -----------
                           CPalette* palette, float min, float max);

//  Destructeur DessinHisto();


  void Paint();
  //   -----

  void ReDimensionne();

  void FixeValeurs( ParamDessinHisto* par);

  virtual void InitWidget();

  void Boutton_Presse();
  void Boutton_Relache();
  void DeplaceSourisBout1();

  void Boutton2_Presse();
  void Boutton2_Relache();
  void DeplaceSourisBout2();

  virtual void FermerFenetre() { this->~DessinHisto();}
  //             -------------

  static void CB_Fermer( Widget, void* cd, void*)
  //          ---------
  {
    ((DessinHisto*) cd)->FermerFenetre();
  }

  static void CB_redessine( void* cd );

  static void CB_nb_intervalles( void* cd );

  static void CB_pas_intervalle( void* cd );

  static void CB_recalcule( void* cd );

  static void CB_log2( Widget, void* cd, void*);
  //          -------

}; // DessinHisto

#endif // DESSIN_HISTO_HPP
