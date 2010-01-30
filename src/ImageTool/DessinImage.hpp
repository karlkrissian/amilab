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
/***************************************************************************
 * $Author: karl $
 * $Revision: 1.14 $
 * $Log: DessinImage.hpp,v $
 * Revision 1.14  2006/03/09 16:49:07  karl
 * evolving for Fluid tutorial + fixed OpenGL pb with GLw
 *
 * Revision 1.13  2006/02/21 18:26:18  karl
 * many changes
 *
 * Revision 1.12  2006/01/13 14:00:21  karl
 * proportional vectors in slices
 *
 * Revision 1.11  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.10  2004/08/27 23:21:18  karl
 * all for automatic grab of results for Book Chapter
 *
 * Revision 1.9  2004/08/26 22:05:35  karl
 * adding control of imagedraw into amilab
 *
 * Revision 1.8  2004/08/25 22:37:38  karl
 * displaying vector field from amilab + read vtk vector field
 *
 * Revision 1.7  2004/08/24 22:14:43  karl
 * Saving IMAGEDRAW content
 *
 * Revision 1.6  2004/07/01 15:03:30  karl
 * Added features to Connected Components, Resize with translation, volume rendering
 *
 * Revision 1.5  2004/06/24 05:18:53  karl
 * warnings and trying to unify texture and object matrices
 *
 * Revision 1.4  2004/06/16 21:47:01  karl
 * Volume Rendering starting to work
 *
 * Revision 1.3  2004/06/16 02:00:02  karl
 * Starting Volume Rendering
 *
 * Revision 1.2  2004/04/30 20:10:15  karl
 * several improcements
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.7  2001/03/02 11:49:30  karl
 * *** empty log message ***
 *
 * Revision 1.6  2000/11/08 16:38:54  karl
 * *** empty log message ***
 *
 * Revision 1.5  2000/10/30 13:13:15  karl
 * *** empty log message ***
 *
 * Revision 1.4  2000/10/30 12:56:53  karl
 *
 *
 * Dessin de la vue surfacique d'une coupe 2D
 *
 * Revision 1.2  2000/10/06 22:52:06  karl
 * *** empty log message ***
 *
 * Revision 1.3  2000/10/02 16:57:17  karl
 * *** empty log message ***
 *
 * Revision 1.2  2000/09/19 12:19:06  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:09:35  karl
 * Sources code
 *
 *
 ***************************************************************************/
// Visualisation d'inrimage
// fichier DessinImage.hpp
//
// Karl KRISSIAN 
//
// Sophia Antipolis le 08-12-96
//

#ifndef _DESSIN_IMAGE_HPP
#define _DESSIN_IMAGE_HPP

//#include <sys/types.h>
//#include <time.h>

#define  SAUVE_INRIMAGE   0
#define  SAUVE_PS_GRIS    1
#define  SAUVE_PS_COULEUR 2


#include "ParamBox.hpp"
#include "DessinImageBase.hpp"
//#include "BarreDefil.hpp"

#include "DessinImageParam.hpp"
//#include <X11/cursorfont.h>
#include <math.h>

#include "ImageMIP.hpp"
#include "Crest.hpp"
//#include "DessinHisto.hpp"
//#include "HistoPoints.hpp"
//#include "Stereo.hpp"
//#include "saveps.hpp"
//#include "CrestView.hpp"

#include "DefineClass.hpp"

#include <iostream>
using namespace std;

#ifndef _NO_GL_
#include "Viewer3D.hpp"
#endif

#define VECTEUR_FLECHE      0
#define VECTEUR_DIRECTION   1
#define VECTEUR_FLECHE_PROP 2 // fleche proportionnelle

#define VECTOR_IMAGE_PIXELS    0
#define VECTOR_SCREEN_PIXELS   1

#include <list>

class CompareImage;

class compare_info; // defined at the end ...


class vectorfield_info {
public:
    // comparison window
    InrImage::wptr vector;

    // Use interpolation when images have different domains
    // or resolutions
    unsigned char      interpolate;
    unsigned char      visible;
    ClasseCouleur      color;

    // for the interface ...
    int       _id_affiche_vecteur;
    int       _id_couleur_vecteur;

    vectorfield_info(): 
        interpolate(0),
        visible(1) {}

    vectorfield_info(InrImage::wptr v): 
        vector(v), 
        interpolate(0),
        visible(1) {}

};

//============================================================================
/**
 */
class DessinImage : public DessinImageBase
//     -----------
{

  DEFINE_CLASS(DessinImage)

  //  friend class CrestView;
  friend class CompareImage;

  // Own way to create and delete allowing call to wxwidgets Destroy() member for deletion
/*
  class deleter;
  friend class deleter;
*/
public:
  class deleter  
  {
    public: 
      void operator()(DessinImage * p) 
      { 
        // no need to destroy, destroyed by parent ???
        p->Destroy();
      }  
  };


protected:

/** @name Gestion des Animations
 */
//@{
   int             _ANIM_etat;   // PLAY ou STOP
   int             _type_animation;   
   int             _ANIM_vitesse;
   bool            _ANIM_forward; // pour l'autoreverse
   wxTimer         m_timer;
//@}


/** @name objet permettant la comparaison avec une autre image 
*/
//@{
   ///
   CompareImage** _tab_compare_image;
   ///
   int          _compare_max;
   ///
   int          _nombre_comparaisons;
//@}

/** @name objet permettant la comparaison avec une autre image 
          utilisant le meme objet DessinImage
*/

//@{
   ///
   std::list<compare_info> _tab_compare2_image;
   bool _comparison_lock;

//   std::list<InrImage::ptr>    _tab_compare2_displacement;

/*  not needed anymore
   ///
   int          _compare2_max;
   ///
   int          _nombre_comparaisons2;
*/
//@}

/** @name Memorisation de la position de la souris pour les
    rotations des MIP
*/
//@{
  
   ///
   int _souris_position_initiale_x;
   ///
   int _souris_position_initiale_y;
   ///
   int       _MIP_rot_X_initiale;
   ///
   int       _MIP_rot_Y_initiale;
   ///
   int       _MIP_rot_Z_initiale;
//@}

/** @name Variables pour la st��
*/
//@{
   /// num�o de l'image st�� dans le tableau des images compar�s
   int       _MIP_num_stereo; 

   ///
   unsigned char      _MIP_stereo_lunettes;

   ///
//   Stereo*      _MIP_OBJ_stereo;

   ///
   float   _distance_yeux;
   ///
   float   _distance_oeil_ecran;
   ///
   float   _distance_ecran_objet;
   ///
   float   _pixel_cm;
//@}

/** @name    Variables pour le dessin de lignes dans les MIP
*/
//@{
   ///
//   ListCrestView* _crest_view;

   ClasseCouleur  _couleur_lignes;
//@}

/** @name   Gestion des parametres
*/
//@{

   int       _type_facteur;

   int       _facteur_entier;
   float         _facteur_reel;


   int       _zoom_x1, _zoom_y1, _zoom_x2, _zoom_y2;
   int       _zoom_coupe;
   unsigned char      _shift_zoom;
   int       _xmin_initial, _xmax_initial;
   int       _ymin_initial, _ymax_initial;
   int       _zmin_initial, _zmax_initial;

   unsigned char      _shift_deplace;

//@}

/** @name    Variables pour le dessin des vecteurs
*/

//@{
//  std::size_t size=3;
   std::vector<vectorfield_info>  _vector_fields;
//   Cursor               _vecteur_curseur;
   unsigned char        _vecteur_ON;
   int                  _vector_distance_unit;
   float                _taille_vecteur;
   int                  _espacement_vecteur;
   int                  _vecteur_type; // vecteur ou direction ?
   unsigned char        _display_vectors;

//@}

/** @name    Variables pour le dessin des cercles
*/
//@{
   unsigned char      _circles_ON;
   float         _circles_min_radius;
   float         _circles_max_radius;

   unsigned char        _circles_fill;
   ClasseCouleur  _circles_positive_color;
   ClasseCouleur  _circles_negative_color;
   
//@}


/** @name    Variables pour le dessin des cercles
*/
//@{

//   ClasseCouleur   _couleur_cercles1;
//   ClasseCouleur   _couleur_cercles2;

//@}

/** @name User define colormap
 */
  InrImage* _user_colormap; // must be RGB image of 256x1x1
  float     _colormap_center; // intensity value for 127
  float     _colormap_extent; // extent of the colormap: center-/+extent =0/255

/** @name  Dessin des isosurfaces
*/
//@{

#ifndef _NO_GL_
  // pointer to the window if created inside
  Viewer3D_ptr       _GLWindow0;

  // weak pointer is the window comes from SetGLWindow
  // we don't want to prevent the deletion
  Viewer3D_wptr       _GLWindow;
#endif
//@}

/** @name  Gestion de la fenetre de parametres
*/
//@{

   ParamBox* _param_dialog;

//   DessinHisto* _dessin_histo;

   int       _id_show_axes; 
   int       _id_axes_info;
   int         _id_voxel_pos;
   int         _id_space_pos;

   int       _id_planX, _id_planY, _id_planZ;
// TODO   int       _id_interpole;

   int       _id_show_colorbar;
   int       _id_colorspace;
   int         _id_colorspace_grey;
   int         _id_colorspace_rainbow;
   int         _id_colorspace_user;

   int       _id_min, _id_max;

   int       _id_type_courbe;
   int          _id_courbe_pente;
   int          _id_courbe_plateau;
   int          _id_courbe_pente2;
   int          _id_courbe_plateau2;
   int          _id_courbe_interpole;


   int       _id_boutton_fermer;

   int       _etat;

//@}

/** @name     Taille Voxel
*/
//@{
   ParamBox* _param_voxel;

   int _etat_voxel;

   int _id_voxel_size_x;
   int _id_voxel_size_y;
   int _id_voxel_size_z;

//@}

/** @name     Champ de vecteurs
*/
//@{
//   ParamBox* _param_vecteurs;

   int _etat_vecteurs;

   int        _id_display_vectors;
   int       _id_print_vectors;

   int       _id_vector_distance_unit;
   int         _id_vector_screen_pixels;
   int         _id_vector_image_pixels;
   
   int       _id_vecteurs_taille;
   int       _id_vecteurs_espacement;

   int       _id_vecteur_type;
   int         _id_vecteur_fleche;
   int         _id_vecteur_direction;
   int         _id_vecteur_fleche_prop;


//@}

/** @name     Champ de cercles
*/
//@{
   ParamBox* _param_circles;

   int _state_circles;

   int    _id_circles_ON;
   int    _id_circles_min_radius;
   int    _id_circles_max_radius;
   int    _id_circles_fill;
   int    _id_circles_positive_color;
   int    _id_circles_negative_color;

//@}

/** @name     Param�res affichage des coupes XY
*/
//@{
   ParamBox* _param_CoupesXY;

   int _etat_CoupesXY;

   int    _id_zmin;
   int    _id_zmax;

//@}

/** @name     Param�res de traitement des MIP
*/
//@{
   ParamBox* _param_MIP;

   int _etat_MIP;

   int _id_boutton_XY;
   int _id_boutton_XZ;
   int _id_boutton_YZ;

   int    _id_decal_stereo;

   int    _id_rot_X;
   int    _id_rot_Y;
   int    _id_rot_Z;

   int    _id_depth_cue;

   int    _id_boutton_fermer_MIP;

//@}

/** @name     Param�res de traitement des MIP en stereo
*/
//@{
   ParamBox* _param_MIP_stereo;

   int _etat_MIP_stereo;

   int _id_distance_yeux;
   int _id_distance_oeil_ecran;
   int _id_distance_ecran_objet;
   int _id_pixel_cm;

//@}

/** @name     Param�res de traitement des Animations
 */
//@{
   ParamBox* _param_Animation;

   int _etat_Animation;

   int    _id_play_button;
   int    _id_stop_button;

   int    _id_type_animation;
   int      _id_forward;
   int      _id_backward;
   int      _id_autoreverse;

   int    _id_vitesse;

//@}

/** @name     Param�res des IsoContours
 */
//@{
//   ParamBox* _param_IsoContour;

    wxPanel* _panel_isocontours;
   int _etat_IsoContour;

  // to do: fix these variables using a std::vector ??
   int _id_dessine_contour[3];
   int _id_seuil_contour  [3];
   int _id_couleur_contour[3];

   int _id_all_contours;
   int _id_step_contours;
   int _id_contours_winsize;

   int _id_isosurface;
   int _id_use_compareimage_colors;

   int _id_close_isocontour;
//@}


/** @name     Param�res des ImageSurface
 */
   int _id_imsurf_zscale;

   int _id_imagesurface;

  float _imsurf_zscale;


/** @name     Param�res Voxels3D
 */
//@{
   ParamBox* _param_Voxels3D;

   int _etat_Voxels3D;

   int _id_voxels_seuilbas;
   int _id_voxels_seuilhaut;

   int _id_dessine_voxels3D;

//@}

/** @name     Param�res GLMIP
 */
//@{
   ParamBox* _param_GLMIP;

   int _etat_GLMIP;

   int _id_glmip_seuilbas;
   int _id_glmip_seuilhaut;

   int _id_glmip_maxquads;

   int _id_dessine_GLMIP;

//@}

/** @name     Param�res VOLREN
 */
//@{
   ParamBox* _param_VOLREN;

   int _etat_VOLREN;

   int _id_volren_mode;
   int   _id_volren_RGBA;
   int   _id_volren_Intensity;
   int   _id_volren_IntensityAlpha;
   int _id_volren_planes;

   int _id_volren_texture;
   int _id_volren_power2dim;
   int _id_dessine_VOLREN;

//@}

  int _volren_mode;
  int _volren_planes;

  unsigned char _volren_texture;
  unsigned char _volren_power2dim;

  InrImage* _volren_opacity;

/** @name     Param�res Sections3D
 */
//@{
   ParamBox* _param_Sections3D;

   int _etat_Sections3D;

   int _id_sectionXY_visible;
   int _id_sectionXZ_visible;
   int _id_sectionYZ_visible;

//@}

  unsigned char _sectionXY_visible;
  unsigned char _sectionXZ_visible;
  unsigned char _sectionYZ_visible;

/** @name     Param�res de Zoom Facteur
*/
//@{
   ParamBox* _param_ZoomFacteur;

   int _etat_ZoomFacteur;

   int       _id_type_facteur;
   int         _id_facteur_reel;
   int         _id_facteur_entier;

   int       _id_facteur_valreel;
   int       _id_facteur_valentier;

//@}


/** @name      Param�res de choix de couleurs
 */
//@{
   ParamBox* _param_couleurs;

   int _etat_couleurs;

   int _id_couleur_fond;
   int _id_couleur_objet;
   int _id_couleur_lignes;

//@}

/** @name     Saisie d'une image
 */
//@{
   ParamBox*  _param_nom_image;
   int        _id_nom_image;
   string_ptr _nom_nouvelle_image;

//@}

/** @name    Sauvegarde d'une image
 */
//@{
   ///
   ParamBox* _param_sauve_image;

   ///
   int      _id_sauve_image;

   /// type sauvegarde
   int               _id_type_sauvegarde;
   ///  type sauvegarde param
//@{
   ///
   int                 _id_inrimage;
   ///
   int                 _id_postscript_gris;
   ///
   int                 _id_postscript_couleur;
//@}

   ///
   int               _id_image_format;
//@{
   ///
   int                 _id_format_uchar;
   ///
   int                 _id_format_ushort;
   ///
   int                 _id_format_sshort;
   ///
   int                 _id_format_uint;
   ///
   int                 _id_format_sint;
   ///
   int                 _id_format_ulong;
   ///
   int                 _id_format_slong;
   ///
   int                 _id_format_float;
   ///
   int                 _id_format_double;
//@}

   ///
   string_ptr        _nom_sauve_image;
   ///
   int               _format_image;
   ///
   int               _type_sauvegarde;

//@}


 /** @name    Image Information
  */
 //@{
    ///
    ParamBox*    _param_image_info;
    ///
    int     _id_info_name;
    /// 
    int               _id_info_format;
    /// 
    int               _id_info_dim;
    /// 
    int               _id_info_voxelsize;
    /// 
    int               _id_info_stat;
    ///
    int               _id_info_numpoints;
    /// 
    int               _id_info_min_max;
    /// 
    int               _id_info_mean;
    /// Standard Deviation
    int               _id_info_sd;
    /// SD/Mean
    int               _id_info_sd_mean;
 //@}


/** @name  Saisie du fichier de parametres
 */
//@{
   ParamBox*  _param_nom_fichier;
   int        _id_nom_fichier;
   string_ptr _nom_fichier;

//@}

/** @name  Saisie de la table de couleurs
 */
//@{
   ParamBox*  _param_nom_tc;
   int        _id_nom_tc;
   string_ptr _nom_tc;
//@}



  // Callback for the Paint method
  void* _paint_callback;
  void* _paint_callback_data;

  // avoid the Paint() member to execute several times at the same time
  unsigned char _in_paint;




private:
//===========

  ///
  void     InitMinMax( InrImage::ptr&);
  //       ----------

  ///
  void     CheckMinMax();
  //       -----------

  ///
  void     ComputeBasicSizes();
  //       -----------------

  ///
  void     InitVoxelSize();
  //       -------------

  ///
  void     InitPositionImages();
  //       ------------------


  ///
  void     CreeParametresVoxel();
  //       -------------------

  ///
  void     CreeParametresVecteurs(ParamBox* pb);
  //       ----------------------

  ///
  void     CreeParametresIsoContour(ParamBox* pb);
  //       ------------------------

  ///
  void     CreeParametresCircles();
  //       ---------------------

  ///
  void     CreeParametresMIP();
  //       -----------------

  ///
  void     CreeParametresMIP_stereo();
  //       ------------------------

  ///
  void     CreeParametresCoupesXY();
  //       ----------------------

  ///
  void     CreeParametresAnimation();
  //       -----------------------

  ///
  void     CreeParametresImageSurface(ParamBox* pb);
  //       --------------------------

  ///
  void     CreeParametresVoxels3D();
  //       ----------------------

  ///
  void     CreeParametresGLMIP();
  //       -------------------

  ///
  void     CreeParametresVOLREN();
  //       -------------------

  ///
  void     CreeParametresSections3D();
  //       ----------------------

  ///
  void     CreeParametresZoomFacteur();
  //       -------------------------

  ///
  void     CreeParametresCouleurs();
  //       ----------------------

  ///
  void     CreeFenetreParametres(ParamBox* pb);
  //       ---------------------

  ///
  void     CreeSauveParametres();
  //       -------------------

  ///
  void     CreeParametresInfo();
  //       ------------------


  ///  Cree toutes les boites de parametres ne dependant pas de la palette
  void     CreeBoitesParametres();
  //       --------------------
  //

  ///  Creeles boites de parametres dependant de la palette
  void     CreeBoitesParametres2();
  //       --------------------
  //

  ///
  void     DessineCurseurs( int x, int y, int z);
  //       ---------------
  //  Dessine la position du curseur sur toutes les coupes
  //  et sur les images de comparaison


  ///
  void     DessineScrollBar( int image);
  //       ----------------
  // Dessine deux ScrollBar dans la drawing area pour l'image 'image' 
  // (IMAGE_XY ou IMAGE_XZ ou IMAGE_ZY),
  // en tenant compte du zoom effectue: _xmin,_xmax,_ymin,...

  ///
  void     ProjetteVecteur( int x, int y, float vx, float vy);
  //       ---------------

  //
  void     DrawVector( int vect_id, int x, int y, int z, int type=-1);

  //
  void     DrawVectors( int x, int y, int z, int type=-1);
  //       --------------
  //  Dessine la valeur du vecteur du champ de vecteurs donn�  // au point (x,y,z)  sur toutes les coupes

  ///
  void     DessineChampVecteurs();
  //       --------------------
  //  Dessine le champ de vecteur
  //  sur toutes les coupes visibles

  ///
  void     DessineLigneDansMIP( const Point_3D<int>& p1, 
  //       -------------------
                const Point_3D<int>& p2,
                unsigned char pointilles = false);
  //  Dessine une Ligne dans la  MIP

  void     DessineBoundingBox( );
  //       ------------------
  //  Dessine une bounding box dans la projection MIP

  void     DessineStereo();
  //       -------------

  void     MAJ_Image();
  //       ---------
  // Met �jour tous les param�res de l'image "_image"
  // et affiche l'image
  
  void    InitComparaisons();
  //      ----------------

  void    Comparaisons_UpdateStatusInfo( const Point_3D<int>& imagepos, int trouve);
  //      -----------------------------

  //----------------------------------------------------
  // Met a jour les informations relatives au curseur
  // et les affiche.
  // Si on est en mode MIP, image3Dpos contient les coordonnees du point projete
  // sinon il est egal a imagepos
  void     UpdateStatusInfo( const Point_3D<int>& imagepos, int trouve);
  //       ----------------

  void    Comparaisons_Paint();
  //      ------------------

  void    Comparaisons_DessineCurseur(int x, int y, int z);
  //      ---------------------------

  void    Comparaisons_EffaceEcran( unsigned char expose);
  //      ------------------------

  void    Comparaisons_MAJ_taille( );
  //      -----------------------

  void    Comparaisons_MemoriseCoupesXY(  unsigned char activation );
  //      -----------------------------

  void LoadNewFont();

  ///
  unsigned char CheckGLWindow();
  //

protected:


public:

  ///
   DessinImage(  
      wxWindow* parent,
      const std::string& ATitle, 
      InrImage::ptr image,
      DessinParam::ptr param, 
      int l, int h, int type = CREATE_WINDOW);

  static DessinImage::ptr Create_ptr(
        wxWindow* parent,
        const std::string& ATitle, 
        InrImage::ptr image,
        DessinParam::ptr param, 
        int l, int h, int type = CREATE_WINDOW)
    {
        DessinImage::ptr px(new 
            DessinImage(parent,ATitle,image,param,l,h,type),
            DessinImage::deleter());
        return px;
    }

  ~DessinImage();

  //
  void     SetVolRenOpacity(InrImage* volren_opacity)
  {
    _volren_opacity = volren_opacity;
  }

   wxColour GetLineColor() { return _couleur_lignes; }

  int      ComparisonNumber() { return _nombre_comparaisons;}


  CompareImage*   GetCompareWindow(int i=0) 
  {
    Si (i>=0)Et(i<_nombre_comparaisons) Alors
      return _tab_compare_image[i];
    Sinon
      return NULL;
    FinSi
  }

  void InitPalette();
  
  void InitParametres();

  /** Cette methode permet de creer un "clone"
     de l'image de dessin avec une autre image de memes dimensions 
     et donc de comparer deux images
     return -1 si erreur, sinon retourne le numero de l'image cree
     dans le tableau _tab_compare_image[]
  */
  int CreeCompareImage( char* titre, char* nom_image);
  //     ----------------

  int CreeCompareImage( char* titre, InrImage::ptr image, 
  //     ----------------
               bool allocated_image=false);

  int CreeCompare2Image( DessinImage::ptr image);
  //     -----------------

  void SetCompareDisplacement( DessinImage::ptr compare_win, InrImage::ptr displ);

  void   LibereCompareImage( int num, unsigned char delete_window=1);
  //     ------------------

  ///
  void     UpDateMinMax();
  //       ------------

  ///
  void     SetMinMax( float min, float max);
  //       ---------

  ///
  void SetVectorVisible( int vectnum, int draw)
  {
    if ((vectnum>=0)&&(vectnum<(int)_vector_fields.size())) 
      _vector_fields[vectnum].visible = draw;
    else
      fprintf(stderr,"DessinImage::SetVectorVisible() wrong vector field number \n");
  }


  ///
  void SetVectParam( float size, int spacing)
  {
    _taille_vecteur = size;
    _espacement_vecteur = spacing;
  }

  ///
  void SetVectType( int type)
  {
    _vecteur_type = type;
  }

  ///
  void SetVectColor( int vectid, unsigned char red, unsigned char green, unsigned char blue)
  {
    size_t id = vectid-1;
    if ((id>=0)&&(id<_vector_fields.size())) 
      _vector_fields[id].color.FixeValeur(red,green,blue);
    else
      fprintf(stderr,"DessinImage::SetVectColor() wrong vector field number \n");
  }

  ///
  void SetLineThickness( int lt)
  {
    _largeur_lignes = lt;
  }


  ///
  void     GetPosition( int& x, int& y, int& z)
  {
    x = Param._pos._x;
    y = Param._pos._y;
    z = Param._pos._z;
  }

  ///
  void     GetZoom( int& xmin, int& ymin, int& zmin,
            int& xmax, int& ymax, int& zmax)
  {
    xmin = Param._Zoom._xmin;
    ymin = Param._Zoom._ymin;
    zmin = Param._Zoom._zmin;
    xmax = Param._Zoom._xmax;
    ymax = Param._Zoom._ymax;
    zmax = Param._Zoom._zmax;
  }


  ///
  void     SetZoom( int xmin, int ymin, int zmin,
            int xmax, int ymax, int zmax)
  {
    Param._Zoom._xmin = xmin;
    Param._Zoom._xmax = xmax;
    Param._Zoom._ymin = ymin;
    Param._Zoom._ymax = ymax;
    Param._Zoom._zmin = zmin;
    Param._Zoom._zmax = zmax;
    Param._Zoom.Check(_image);
    Param._pos.Check(_image);
    Param._MAJ.MAJCoupes();
    EffaceTousLesEcrans(false);
    Paint();
  }



  /** change l'image traitee, ce qui oblige a mettre a jour un
     certain nombre de parametres
     Cette procedure est utilisee pour permettre l'affichage des
     images MIP, mais il risque d'y avoir pas mal de problemes:
     - La taille de l'image peut etre modifiee...
        - MAJ des barres de defilement 
           ( solution MIP: action differente du boutton 2 pour les MIP )
        - MAJ du zoom ( _xmin, _xmax, _dessin_tx, ...),
           ( solution re-initialisation des valeurs )
        - MAJ de la position du curseur (_planX, ...)
           ( solution re-initialisation des valeurs )
     - Mise a jour des intensites min et max (pas dans le cas des MIP).
     - Reaffichage de tous les ecrans, ( les images comparees 
        doivent pouvoir reagir de la meme facon).
  */
  void ChangeImage( InrImage::ptr image, unsigned char Efface=true);
  //   -----------

  /** Cree une boite de dialogue permettant de
     selectionner la couleur donnee
     attent que l'utilisation selectionne
     et retourne l'etat de sortie de la boite de dialogue
     qui depend du boutton appuye : Cancel ou OK
  */
  int ChoixCouleur( ClasseCouleur*);
  //     ------------

  unsigned char LitFichierParametres( char* nom_fic);
  //      --------------------
  // Lecture d'un fichier de parametres
  //

  void SauveFichierParametres( char* nom_fic);
  //   ----------------------
  // Sauvegarde des parametres
  //

  void SauveImage( char* nom_image);
  //   ----------
  // Sauvegarde de l'image
  //

  void SauveImagePS( const char* nom_image);
  //   ------------
  // Sauvegarde de l'image XY de l'ecran en postscript
  //


/*
  unsigned char ChargeImageVecteur(int index, char* nom);
  //      -------------------
  // chargement d'un champ de vecteurs
*/

  unsigned char LoadVectImage( int num, InrImage::ptr im);
  //      -------------
  // chargement d'un champ de vecteurs
  // num est le numero du champ de vecteurs dans (1..3)

  ///
  void     DessineCercle( int x, int y, int z, ClasseCouleur& c);
  //       -------------
  //  Dessine un cercle de rayon l'intensite de l'image
  // au point (x,y,z)  sur toutes les coupes

  ///
  void     DessineChampCercles();
  //       -------------------

  ///
  void     SetCirclesON() { _circles_ON = true; }
  //       ------------

  ///
  void     SetCirclesOFF() { _circles_ON = false; }
  //       -------------


  //
  void  SetUserColormap(InrImage* image, float center, float extent)
  //    ---------------
  {
    if ((image->_format==WT_RGB)&&
    (image->DimX()==256)&&(image->DimY()==1)&&(image->DimZ()==1)) {
      _user_colormap = image;
      _colormap_center = center;
      _colormap_extent = extent;
      Param._I._colorspace = COLORSPACE_USER;
    }
  }


  //
  void DrawContour( int i, int size=-1, int style=-1);
  //   -----------

  //
  void DrawAllContours();
  //   ---------------

  //
  void CreateGLWindow();
  //

  ///
  void SetGLWindow( Viewer3D_ptr& glwin);
  //   -----------

  void Paint( unsigned char affiche = true );
 
  void SetPaintCallback( void* paint_cb, void* paint_cb_data) {
    this->_paint_callback = paint_cb;
    this->_paint_callback_data = paint_cb_data;
  }

  void PlayAnimation();
  void UpdateAnimation();

  void LanceAnimation();

  void LancePetiteAnimationStereo( int n);

  void EffaceTousLesEcrans( unsigned char expose);
  //  Permet d'effacer aussi les ecrans des images compar�s

  /// Fixe le type de dessin pour toutes les images
  void InitDrawingAreaAll( );
  //

  //
  void SetImageSize();
  //   ------------


  void ReDimensionne();

  void OnWheel(wxMouseEvent& event);

  void Boutton_Presse();
  void Boutton_Relache();
  void DeplaceSourisBout1();
  void DeplaceSourisShiftBout1();

  void Boutton2_Presse();
  void Boutton2_Relache();
  void DeplaceSourisBout2();
  void DeplaceSourisShiftBout2();

  void Boutton3_Presse();
  void Boutton3_Relache();
  void DeplaceSourisBout3();


/** @name CallBacks: Divers
 */
//@{

  ///
  void CB_Close( wxCommandEvent&);
  //   --------

  //===== Fermer Boite Parametres

  ///
  void CB_parametres_visibles( wxCommandEvent& );
  //   ----------------------

  ///
//  static void CB_voxel( Widget, void* cd, void*);
  void CB_voxel( wxCommandEvent&);
  //   --------

  ///
  void CB_relire( wxCommandEvent&);
  //   ---------

  ///
  void CB_comparer( wxCommandEvent&);
  //   -----------

  ///
  void CB_sauver_param( wxCommandEvent&);
  //   ---------------

  ///
  void CB_sauver_image(wxCommandEvent&);
  //   ---------------

//  static void CB_image_info( Widget, void* cd, void*);
  //          -------------
  void CB_image_info( wxCommandEvent&);
  //   -------------


  ///
  static void CB_info_stat( void* cd);
  //          ------------

  ///
  static void CB_imagesurface( void* cd);
  //          ---------------

  ///
  static void CB_isosurface( void* cd);
  //          -------------

  ///
  static void CB_UseCompareColors( void* cd);
  //          -------------------

  /// Lancement du dessin des voxels depuis le menu
  //
  void CB_voxels3D( wxCommandEvent&);
  //   --------------

  //
  void CB_GLMIP( wxCommandEvent&);
  //   --------

  //
  void CB_VOLREN( wxCommandEvent&);
  //   ---------

  //
  void CB_sections3D( wxCommandEvent&);
  //   -------------

  //===== Voxels3D
  // MAJ des voxels affiches
  //
  static void CB_DessineVoxels3D( void* cd);
  //          ------------------

  //===== GLMIP
  // 
  //
  static void CB_DessineGLMIP( void* cd);
  //          ---------------

  //
  static void CB_DessineVOLREN( void* cd);
  //          ----------------

  //
  static void CB_ResetVOLREN( void* cd);
  //          --------------

  static void CB_DessineSections3D( void* cd);
  //          ------------------

  //===== IsoContour
  //
  static void CB_DessineIsoContour( void* cd);
  //          --------------------

  //
  static void CB_IsoContourVisible( void* cd);
  //          --------------------

  ///
  static void CB_CloseGL( void* cd );
  //          ----------

  //===== Masque Visible ou Invisible
  void CB_MasqueVisible( wxCommandEvent&);
  //   ----------------

  ///
  static void CB_PlanX(  void* cd );

  ///
  static void CB_PlanY(  void* cd );

  ///
  static void CB_PlanZ(  void* cd );

  //===== Coupes XY
  //
  static void CB_CoupesXY( void* cd);
  //          -----------

  ///
  static void CB_redessine( void* cd );

  ///
  void CB_redraw( wxCommandEvent& );

  ///
  static void CB_voxel_size( void* cd );

  ///
  void CB_option_traitement( wxCommandEvent& );


  ///
  void CB_UpdateComparison( wxCommandEvent& event);

  ///
  void CB_UpdateMinMax( wxCommandEvent& event);

  ///
  static void CB_facteur( void* cd);

  ///
  void CB_fonction_zoom( wxCommandEvent& );

  ///
  void CB_type_taille( wxCommandEvent&);

  ///
  void CB_image_size(  wxCommandEvent&);

  ///
  void CB_largeur_lignes( wxCommandEvent& );

//@}

/** @name CallBacks: Vecteurs
 */
//@{


  ///
  static void CB_AfficheChampVect( void* cd, void*);
  //          -------------------


  ///
  static void CB_AfficheVecteurs( void* cd);
  //          -------------------

  ///
  static void CB_type_vecteur( void* cd);
  //          ----------------

  ///
  static void CB_taille_vecteurs( void* cd );

//@}

/** @name CallBacks: Circles
 */
//@{
  ///
  void CB_circles( wxCommandEvent&);
  //          -----------

//@}

/** @name CallBacks: Choix des Couleurs
 */
//@{
  ///
  void CB_couleurs( wxCommandEvent&);
  //   -----------

  ///
  static void CB_maj_couleurs( void* cd);
  //          ---------------

  ///
  static void CB_maj_couleur_lignes(  void* cd);
  //          ---------------------
//@}

/** @name CallBacks: projections MIP
 */
//@{

  ///
  static void CB_projette_XY( void*);
  //          --------------

  ///
  static void CB_projette_YZ( void*);
  //          --------------

  ///
  static void CB_projette_XZ( void*);
  //          --------------

  ///
  void CB_MIP_min_max( wxCommandEvent& event);
  //   --------------

  ///
  void CB_MIP_rapide( wxCommandEvent&);
  //    -------------

  ///
  void CB_MIP_bounding_box( wxCommandEvent&);
  //          -------------------

  ///
  void CB_MIP_zoom_bounding_box(  wxCommandEvent&);
  //   -------------------------

  ///
  void CB_MIP_precise( wxCommandEvent&);
  //    --------------

  ///
  void CB_MIP_lin_interp( wxCommandEvent&);
  //   -----------------
  // interpolation lin�ire

  ///
  void CB_fichier_crest( wxCommandEvent&);
  //   ----------------


  ///
  void CB_MIP_stereo( wxCommandEvent&);
  //          -------------

  ///
  void CB_MIP_anim_stereo( wxCommandEvent&);
  //          ------------------

  ///
  void CB_MIP_stereo_lunettes( wxCommandEvent&);
  //          ----------------------

  ///
  static void CB_MIP_stereo_param( void* cd);
  //          -------------------

  ///
  static void CB_MIP_decal_stereo( void* cd);
  //          -------------------

  ///
  static void CB_projette_MIP( void* cd );
  //          ---------------

  ///
  static void CB_MIP_depth_cue( void* cd );
  //          ----------------

  ///
  void CB_parametresMIP_visibles( wxCommandEvent&);
  //   -------------------------

  ///
  static void CB_Fermer_parametresMIP(void* cd);
  //          -----------------------

//@}


/** @name  CallBacks Animation
 */
//@{

  ///
  static void CB_Anim_Play( void*);
  //          ------------

  ///
  static void CB_Anim_Stop( void*);
  //          ------------

  ///
  static void CB_Anim_vitesse( void* cd );
  //          ---------------

  ///
  static void CB_type_animation( void* cd );
  //          -----------------

  ///
  void OnTimer(wxTimerEvent& WXUNUSED(event)) { 
  //   -------
    PlayAnimation(); 
  }


//@}

/** @name  CallBacks Intensite
 */
//@{

  ///
  static void CB_fonction_intensite( void* cd);

  ///
  static void CB_barre_min( void* cd );

  ///
  static void CB_barre_max( void* cd );

  ///
  static void CB_type_courbe( void* cd);

  ///
  static void CB_colorspace( void* cd);
//@}


/** @name   Fonctions de R�up�ation des param�res du dessin
    pour l'objet CompareImage
*/
//@{

  ///
  void RecupereOptionTraitement( int* option) 
  //   ------------------------
  { *option = Param._option_traitement; }

  ///
  void RecupereTypeCoupe( int* type_coupe) 
  //   -----------------
  { *type_coupe = Param._type_coupe; }

  ///
  void RecupereMAJ( DessinImageParametres& param)
  {
    param._MAJ    = Param._MAJ;
  }

  ///
  void RecuperePosition( DessinImageParametres& param)
  //   ----------------
  {
    param._pos = Param._pos;
  }

  ///
  void RecupereLimites( DessinImageParametres& param)
  //   ---------------
                        
  {
    param._Zoom = Param._Zoom;
  }

/*
///
  void RecupereImagePos( int id_image, int* pos_x, int* pos_y)
  //   ----------------
  { *pos_x = _tab_ximage_pos_x[id_image];
    *pos_y = _tab_ximage_pos_y[id_image];  }
*/
  ///
  void RecupereFacteurs( float* x, float* y, float* z)
  //   ----------------
  {
    *x = _size_x; 
    *y = _size_y; 
    *z = _size_z; }

  ///
  void RecupereVoxelSize( DessinImageParametres& param)
  //   -----------------
  {
    param._dim = Param._dim;
  }

  ///
  void RecupereMinMax( float* min, float* max)
  //   --------------
  { 
    *min = _val_min; 
    *max = _val_max; }

  ///
  void RecupereTypeCourbe( int* type)
  //   ------------------
  { *type = Param._I._type_courbe; }

  ///
  void RecupereTypeCurseur( int* type_curseur)
  //   -------------------
  { *type_curseur = Param._curseur._type; }


  ///
  void RecupereIntervalleIntensite( float* float_min, float* float_max,
  //   ---------------------------
                                    int* entier_min, int* entier_max)
  {
    switch ( _image->_format ){
      case WT_FLOAT:
      case WT_DOUBLE:
        *float_min  = _intensite_float_min; 
        *float_max  = _intensite_float_max;
        *entier_min = (int) _intensite_float_min; 
        *entier_max = (int) _intensite_float_max;
      break;

      case WT_UNSIGNED_CHAR: 
      case WT_UNSIGNED_SHORT: 
      case WT_SIGNED_SHORT:
      case WT_UNSIGNED_INT: 
      case WT_SIGNED_INT:
        *float_min  = _intensite_entier_min;
        *float_max  = _intensite_entier_max;
        *entier_min = _intensite_entier_min;
        *entier_max = _intensite_entier_max; 
      break;

    default: ;
    //fprintf(stderr,"Erreur \t dans switch, valeur non gere \n");

    } // end switch
  }

  ///
  void RecupereIntervalleIntensiteNormalise( float* pos_min, float* pos_max)
  //   ------------------------------------
  {
    switch (  _image->_format ){
      case WT_FLOAT:
      case WT_DOUBLE:
        *pos_min  = (_intensite_float_min - _val_min)/(_val_max - _val_min); 
        *pos_max  = (_intensite_float_max - _val_min)/(_val_max - _val_min); 
      break;

      case WT_UNSIGNED_CHAR: 
      case WT_UNSIGNED_SHORT: 
      case WT_SIGNED_SHORT:
      case WT_UNSIGNED_INT: 
      case WT_SIGNED_INT:
        *pos_min  = (_intensite_entier_min - _val_min)/(_val_max - _val_min); 
        *pos_max  = (_intensite_entier_max - _val_min)/(_val_max - _val_min); 
      break;

    default: ; // fprintf(stderr,"Erreur \t dans switch, valeur non g�� \n");
    } // end switch
  }

  ///
  void RecupereMIP(  DessinImageParametres& param)
  //   -----------
  {
    param._MIP = Param._MIP;
  }

  ///
  void RecupereAnimation( unsigned char* memorise_coupes)
  //   -----------------
  {
    *memorise_coupes = _memorise_coupes_XY;
  }

//@}

private:
    DECLARE_EVENT_TABLE()

}; // DessinImage
//============================================================================


class compare_info {
public:
    // comparison window
    DessinImage::wptr di;
    // displacement to apply to the cursor position
    // for each of the comparing window
    InrImage::wptr    displ;

  compare_info(DessinImage::wptr& _di, InrImage::wptr _displ): di(_di), displ(_displ) {}

};


#endif // _DESSIN_IMAGE_HPP
