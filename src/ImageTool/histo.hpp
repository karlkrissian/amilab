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
// fichier histo.hpp
//
// Karl KRISSIAN 
//
// Sophia Antipolis le 29-01-97
//

#ifndef _HISTO_HPP
#define _HISTO_HPP

#include "FenetreDessin.hpp"
#include "inrimage.hpp"
//#include "BarreDefil.hpp"
#include "ParamBox.hpp"
#include "math1.hpp"
#include "HistoPoints.hpp"

#define FORMAT_256   unsigned char
#define FORMAT_16B   unsigned short
#define FORMAT_S16B  signed short
#define FORMAT_float float


//============================================================================
class ParametresHisto
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

  Constructeur ParametresHisto() {}
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

}; // ParametresHisto


//============================================================================
class Histogramme : public FenetreDessin
//     -----------
{

   InterpoleLigne* _interpole_ligne;

   //-----------------------------------------------------
   //------ Fenetre d'affichage de l'image

   Widget       _label_souris;
   XmString     _label_string;
   char    _label_texte[100];

   unsigned char      _MAJ_intensite;

   //-----------------------------------------------------
   //
   int       _souris_x_initiale;
   int       _souris_y_initiale;
   int       _IntMin_initial, _IntMax_initial;
   int       _Int_initial;

   int       _affichage_max_initial;

   //-----------------------------------------------------
   //------ Gestion de l' "InrImage"
   InrImage*    _image;

   FORMAT_256*   _buffer_256;
   FORMAT_16B*   _buffer_16B;
   FORMAT_S16B*  _buffer_S16B;
   FORMAT_FLOAT* _buffer_FLOAT;

   float          _val_min;
   float          _val_max;

   //-----------------------------------------------------
   //------ Gestion des parametres

   unsigned char      _logarithme;

   float         _Imin,_Imax; // intensite min et intensite max
   int       _intervalle_min, _intervalle_max;

   int       _nb_pts_max;
   int       _affichage_max;
   int       _nb_pts_cumul;
   int       _nb_intervalles;
   float         _pas_intervalle;
   int       _nb_pts_taille;
   int*      _nb_pts;      // nombre de points par intervalle
   float         _moy_grad_max;
   float*        _moy_grad;    // moyenne de la norme du gradient
   float*        _log2_nb_pts; // histogramme du log

   // Variables pour le dessin de la position du curseur
   unsigned char      _curseur_ON;
   int       _curseur_x, _curseur_y, _curseur_z; 

   //-----------------------------------------------------
   //------ Gestion de la fenetre de parametres

   ParamBox* _param_dialog;

   int       _id_log2;
   int       _id_affichage_max;
   int       _id_nb_intervalles;
   int       _id_pas_intervalle;

   int       _id_min;
   int       _id_max;

   int       _etat;

   //-----------------------------------------------------


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

  void     InitMinMax( InrImage*);
  //       ----------

  unsigned char  VerifieMinMax( );
  //       -------------

  void     InitCouleurs();
  //       ------------

  void     CreeFenetreParametres();
  //       ---------------------

  void     CurseurToImage( int* x, int* y, int* z, int* etat);
  //       --------------
  //  Renvoie la position dans l'image du curseur,
  //  etat vaut -1 s'il y a une erreur
  //               sinon il indique l'image cliqu�e : IMAGE_XY, IMAGE_XZ ou IMAGE_ZY

  void     DessineCurseur( int x, int y, int z);
  //       --------------
  //  Dessine la position du curseur sur toutes les coupes


public:
  
  Constructeur Histogramme( Widget AParent, char* ATitle, char* nom_image, 
                            int type = CREATE_WINDOW);

  Constructeur Histogramme( Widget AParent, char* ATitle, InrImage* image, 
                            int type = CREATE_WINDOW);

  Destructeur Histogramme();

  void Paint( unsigned char affiche = true);

  void ReDimensionne();

  void FixeValeurs( ParametresHisto* par);

  void InitFenetre();

  void Boutton_Presse();
  void Boutton_Relache();
  void DeplaceSourisBout1();

  void Boutton2_Presse();
  void Boutton2_Relache();
  void DeplaceSourisBout2();

  virtual void FermerFenetre() { this->~Histogramme();}
  //             -------------

  static void CB_Fermer( Widget, void* cd, void*)
  //          ---------
  {
    ((Histogramme*) cd)->FermerFenetre();
  }

  static void CB_redessine( void* cd );

  static void CB_nb_intervalles( void* cd );

  static void CB_pas_intervalle( void* cd );

  static void CB_minmax( void* cd );

  static void CB_recalcule( void* cd );

  static void CB_log2(  void* cd);
  //          -------

}; // Histogramme
//============================================================================

#endif // _HISTO_HPP
