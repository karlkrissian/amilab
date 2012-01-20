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
 * $Revision: 1.8 $
 * $Log: DessinImageBase.hpp,v $
 * Revision 1.8  2006/03/09 16:49:07  karl
 * evolving for Fluid tutorial + fixed OpenGL pb with GLw
 *
 * Revision 1.7  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.6  2004/08/03 20:04:02  karl
 * Connected component + lines in vrml
 *
 * Revision 1.5  2004/06/24 23:01:56  karl
 * small modif + RGB textures
 *
 * Revision 1.4  2004/06/24 04:46:19  karl
 * warnings and trying to unify texture and object matrices
 *
 * Revision 1.3  2004/06/21 19:50:34  karl
 * improved Volume Rendering
 *
 * Revision 1.2  2004/06/16 02:00:02  karl
 * Starting Volume Rendering
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.6  2001/03/02 11:49:30  karl
 * *** empty log message ***
 *
 * Revision 1.5  2000/11/08 16:38:54  karl
 * *** empty log message ***
 *
 * Revision 1.4  2000/10/30 13:13:15  karl
 * *** empty log message ***
 *
 * Revision 1.3  2000/10/30 12:56:53  karl
 *
 *
 * Dessin de la vue surfacique d'une coupe 2D
 *
 * Revision 1.2  2000/10/06 22:52:06  karl
 * *** empty log message ***
 *
 * Revision 1.2  2000/09/19 12:19:06  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:09:39  karl
 * Sources code
 *
 *
 ***************************************************************************/

// Visualisation d'inrimage
// fichier DessinImageBase.hpp
//
// Karl KRISSIAN
//
// Sophia Antipolis le 20-10-97
//

#pragma once
#ifndef _DESSIN_IMAGE_BASE_HPP
#define _DESSIN_IMAGE_BASE_HPP

#ifndef basename
#define basename(s) s
#endif

//#include "ParamBox.hpp"
//#include "boutton.hpp"
//#include "palette.hpp"
#include "FenetreDessin.hpp"
#include "inrimage.hpp"
#include <wxParamTypes.hpp>
//#include "BarreDefil.hpp"

//#include "wxParamTypes.hpp"
class wxMenuEnum;

#include "ImageMIP.hpp"
#include "Crest.hpp"

#include "DessinImageParam.hpp"

//#include "HistoPoints.hpp"

#include "Coordonnees.hpp"

//#include "couleur.hpp"
#include "FloatMatrix.hpp"

#include "RGBTransformBase.h"

#include "wx/version.h"
#if ((wxMAJOR_VERSION==2)&&(wxMINOR_VERSION>=9))||(wxMAJOR_VERSION>=3)
  #define PENSTYLE_SOLID wxPENSTYLE_SOLID 
#else
  #define PENSTYLE_SOLID wxSOLID 
#endif


#define ANIM_PLAY              0
#define ANIM_STOP              1

#define TYPE_ANIM_FORWARD      0
#define TYPE_ANIM_BACKWARD     1
#define TYPE_ANIM_AUTOREVERSE  2

#define INTERP_SUB_2   0
#define INTERP_SUB_3   1
#define INTERP_SUB_4   2
#define INTERP_SUB_8   3
#define INTERP_SUB_MAX 4

// Pour swapper entre le francais et l'anglais
#define FrAn(f,a) (char*)((_param->version_anglaise)?(a):(f))
#define StaticFrAn(f,a) (char*)((di->_param->version_anglaise)?(a):(f))

//class CrestView;
//class ListCrestView;

#include "couleur.hpp"

#include "wx/timer.h"

enum
{
    ID_MenuImage = 100,
//    ID_MenuImage_Display,
    ID_MenuImage_Reload,
//    ID_MenuImage_Compare,
    ID_MenuImage_VoxelSize,
//    ID_MenuImage_Save,
//      ID_MenuImage_Save_param,
//      ID_MenuImage_Save_image,
    ID_MenuImage_info,
    ID_MenuImage_close,

    ID_MenuOptions = 200,

    ID_MenuOptions_option,
      ID_MenuOptions_option_slice,
      ID_MenuOptions_option_mip,
      ID_MenuOptions_option_anim,

    ID_MenuOptions_sliceXY,
    ID_MenuOptions_sliceXZ,
    ID_MenuOptions_sliceXY_XZ,
    ID_MenuOptions_sliceZY,
    ID_MenuOptions_sliceXY_ZY,
    ID_MenuOptions_sliceXZ_ZY,
    ID_MenuOptions_sliceXY_XZ_ZY,
    ID_MenuOptions_XYslices,

    ID_MenuOptions_window_size,
    ID_MenuOptions_fixed_size,

    ID_MenuImage_original_size,

    ID_MenuImage_zoom_activated,
    ID_MenuImage_zoom_desactivated,
    ID_MenuImage_unzoom,

    ID_MenuOptions_Interpolation,
    ID_MenuOptions_Interp_Active,
      ID_MenuOptions_interp_sub2,
      ID_MenuOptions_interp_sub3,
      ID_MenuOptions_interp_sub4,
      ID_MenuOptions_interp_sub8,
      ID_MenuOptions_interp_submax,

    ID_MenuOptions_circlefield,
    ID_MenuOptions_voxels3D,
    ID_MenuOptions_OpenGLMIP,
    ID_MenuOptions_VolRen,
    ID_MenuOptions_Sections3D,
    ID_MenuOptions_Colors,

      ID_MenuOptions_linewidth1,
      ID_MenuOptions_linewidth2,
      ID_MenuOptions_linewidth3,
      ID_MenuOptions_linewidth4,

    ID_MenuOptions_display_mask,
    ID_MenuOptions_display_cursor,
    ID_MenuOptions_paramwin,

    ID_MenuMIP_param,
    ID_MenuMIP_minmax,
    ID_MenuMIP_boundingbox,
    ID_MenuMIP_zoombb,

    ID_MenuImage_MIPproj,
      ID_MenuMIP_Proj_morepoints,
      ID_MenuMIP_Proj_interp,
      ID_MenuMIP_Proj_fast,

    ID_MenuMIP_ReadCrest,

    ID_MenuImage_MIPstereo,
      ID_MIPstereo_active,
      ID_MIPstereo_anim,
      ID_MIPstereo_colors,

    ID_MenuCompare,
        ID_MenuCompare_DependIntensity,
        ID_MenuCompare_NormalizeIntensity,
        ID_MenuCompare_DependPosition,
        ID_MenuCompare_UpdateMinMax,
};



class isocontour_info {
public:
    InrImage::wptr image;

    // Use interpolation when images have different domains
    // or resolutions
    unsigned char    visible;
    ClasseCouleur    color;
    float            threshold;
    int              thickness;
    int              style;

    isocontour_info():
        image(InrImage::ptr()),
        visible(0),
        threshold(0),
        thickness(1),
        style(PENSTYLE_SOLID) // LineSolid
        {}

};

class wxImage_info {
public:
  int posx;
  int posy;
  wxMemoryDC_ptr context;
  wxImage_ptr    image;
};

//============================================================================
class DessinImageBase : public FenetreDessin
//     ---------------
{

  DEFINE_CLASS(DessinImageBase)

//  friend class CrestView;
//  friend class ListCrestView;

protected:
//=============


   wxMenuBar*  menuBar;
   wxMenu*     menuImage;
   wxMenu*     menuOptions;
   wxMenu*     menuMIP;
   wxMenu*     menuCompare;
   wxMenuEnum* _wxm_mode;
   wxMenuEnum* _wxm_type_coupe;
   wxMenuEnum* _wxm_type_taille;
   wxMenuEnum* _wxm_zoom;
   wxMenuEnum* _wxm_interp_subdiv;
   wxMenuEnum* _wxm_linewidth;

   ///
   DessinImageParametres Param;

   ///
   DessinParam::ptr   _param;

   ///
   unsigned char _interpole_image;

   ///
   int  _interpole_subdivision;

   ///
// TODO
//   InterpoleLigne* _interpole_ligne;

   ///
   unsigned char           _menu_visible;

   ///
   int  _largeur_lignes;

   ///
   int  _line_style;

   //-----------------------------------------------------
/** @name Fenetre d'affichage de l'image
 */
//@{

    std::string     _status_text;
    int             _intensity_statusid;
    int             _voxelpos_statusid;
    int             _spatialpos_statusid;

//@}

   //-----------------------------------------------------
/**
 @name Gestion de l' "InrImage"
 */
//@{

   // always a pointer to the initial image
   InrImage::ptr    _image_initiale;

  // not needed now
  // unsigned char      _image_initiale_allouee;

   // pointer to the displayed image
   InrImage::ptr    _image;

   float          _val_min;
   float          _val_max;

//@}

/** @name Mask Image
 */
//@{
   Chaine          _mask_image_name;
   /// weak pointer of the mask image
   InrImage::wptr  _mask_image;
   unsigned char   _draw_mask;
   ClasseCouleur   _mask_color;
//@}

/** @name IsoContour
 */

//@{
   std::vector<isocontour_info>  _isocontours;

   unsigned char    _all_contours;
   float            _step_contours;
   float            _contours_winsize;

//@}

/** @name Voxels3D
 */

//@{
   float            _voxels3D_seuilbas;
   float            _voxels3D_seuilhaut;
//@}


/** @name GLMIP
 */

//@{
   float            _GLMIP_seuilbas;
   float            _GLMIP_seuilhaut;
   int          _GLMIP_maxquads;
//@}


/** @name Gestion des images MIP
 */
//@{
   InrImage::ptr  _image_MIP;
   ImageMIP*    _MIP;        // objet permettant de creer une image MIP
   unsigned char      _MIP_rapide; // Test pour accelerer les MIPs
   unsigned char      _MIP_parametres_visibles;
//@}


/** @name Variables pour le dessin de lignes dans les MIP
 */
//@{
   unsigned char         _CREST_charge;
   unsigned char         _CREST_dessine;
   Crest*          _Crest;
//@}

   //-----------------------------------------------------
/** @name Gestion des "XImage"
 */
//@{
/*
Visual*      _visual;
   int       _ximage_octets;
   char*        _ximage_data;
   XImage*      _ximage;
*/
   //------ tableau des images XY, ZY, XZ
   int*       _tab_ximage_pos_x;
   int*       _tab_ximage_pos_y;
/*
#if defined(__MOTIF__)
   char**     _tab_ximage_data;
   XImage**   _tab_ximage;
#endif
   */
    // new way
    std::vector<wxImage_info> _tab_slices;
    wxImage_ptr           _current_slice;

   //------ Memorisation de toutes les images XY (pour accelerer les animations)

int        _nb_images_XY;
   char**        _tab_ximage_XY_data;

 //  XImage**      _tab_ximage_XY;
   unsigned int _largeur_XY;
   unsigned int _hauteur_XY;
   unsigned char*      _image_XY_a_jour;

   unsigned char       _memorise_coupes_XY;
//@}

   int       _distance_coupes; // Espacement entre 2 coupes

   int       _left_margin[3];  // Margins when drawing a slice
   int       _right_margin[3];
   int       _top_margin[3];
   int       _bottom_margin[3];

#if defined(__WXMOTIF__)
   XFontStruct* _new_font;
#endif

   int       _colorbar_width;
   int       _bottom_axe_height;
   int       _right_axe_width;

/** @name facteurs d'aggrandissement en x , y et z
 */
//@{
   float         _size_x;
   float         _size_y;
   float         _size_z;
//@}

   //-----------------------------------------------------

/** @name Intensite
 */
//@{
   float     _intensite_float_min;
   float     _intensite_float_max;

   int       _intensite_entier_min;
   int       _intensite_entier_max;
//@}

/** @name Type de courbe pour l'intensité */
//@{
//  int       _type_courbe;

/** couleur des points en dessous
    du minimum d'intensit�
*/
   unsigned char _couleur_inf;

   /// couleur des points au dessus du max
   unsigned char _couleur_sup;
//@}


   ///
   RGBTransformBase::ptr _rgbtransform;
   
/** @name Variables pour le dessin de la position du curseur
 */
//@{
//   unsigned char      _curseur_ON;
   FloatMatrix* _transf_matrix;
   int            _curseur_x, _curseur_y, _curseur_z;
   ClasseCouleur  _couleur_curseur;
//   int       _type_curseur;

//   unsigned char      _curseur_visible;
//@}

   //-----------------------------------------------------
   //------ Optimisation de l'affichage

   float                    _rapport_intensite;
   std::vector<ClasseCouleur>    _tab_intensite_couleur;

   //----- Couleurs pour le cas RGB
   ClasseCouleur  _couleur_fond;
   ClasseCouleur  _couleur_objet;


/**
  Line Attributes for X11
**/
  int _cap_style; // CapNotLast, CapButt, CapRound, or CapProjecting
  int _join_style; // JoinMiter, JoinRound, or JoinBevel


  unsigned char   _compare_normalize_intensity;
  unsigned char   _compare_depend_position;
  unsigned char   _compare_depend_intensity;

protected:
//=============

/*
///
  XImage* CreeXImage( unsigned int largeur, unsigned int hauteur, char* &data );
  //       ---------
*/

  ///
  void FixeImageCourante( int id_image);
  //   -----------------

  ///
  void CreeImage( int id_image, unsigned int largeur, unsigned int hauteur );
  //   ---------

  ///  Fonction en ligne
  void FastImageRectangle(  rgb_color* image_data,
  //   ------------------
                            const int& width,
                            const int& x_min, const int& y_min,
                            const int& x_max, const int& y_max,
                            const ClasseCouleur& intensite);

  void FastImagePoint(  rgb_color* image_data,
  //   --------------
                        const int& width,
                        const int& x, const int& y,
                        const ClasseCouleur& intensite);

/*
  ///
  void AfficheImage( int pos_x, int pos_y);
  //   ------------
*/

  ///
  void AfficheImage( int id_image);
  //   ------------

  ///
//  void EffaceImage( int id_image);
  //   -----------

  ///
  void InitTabImagesXY( );
  //   ---------------
  // Initialise le tableau des images de toutes les coupes XY
  // tous les pointeurs sur les XImage sont initialises a NULL

  ///
  void LibereTabImagesXY( );
  //   -----------------
  // Libeer le tableau des images de toutes les coupes XY

  ///
  void AlloueImagesXY( unsigned int largeur, unsigned int hauteur);
  //   --------------
  // Alloue les XImages

  ///
  void MAJ_ImagesXY();
  //   ------------
  // toutes les images XY doivent etre mises a jour

  ///
//  void EffaceImagesXY( );
  //   --------------
  // Libere l'espace utilise par les images

  ///
  void UpdateStatusIntensity(int x, int y, int z);
  //   ---------------------
  // writes the intensity value to the corresponding field
  // of the status bar

  ///
  void UpdateStatusPosition(int x, int y, int z);
  //   ---------------------
  // writes the current voxel to the corresponding fields
  // of the status bar (voxel and spatial positions)

  ///
  void InitBuffer( int pos = 0);
  //   ----------

  ///
  void BufferPos( int x, int y, int z);
  //   ---------

  ///
  void IncBuffer( int inc=1);
  //   ---------
  // Fonction en ligne


/*
  ///
  virtual unsigned char FonctionIntensiteBuffer();
  //                      -----------------------
  // Fonction en ligne


  ///
  virtual unsigned char FonctionIntensiteBuffer( float x, float y, float z);
  //                      -----------------------
  // Fonction en ligne
*/

  ///
  virtual unsigned char IntensiteBuffer();
  //                      ---------------
  // Fonction en ligne

  virtual unsigned char IntensiteBuffer(float x, float y, float z);
  /// Interpolation de l'intensit�  virtual unsigned char IntensiteBuffer( float x, float y, float z);
  //                      ---------------
  // Fonction en ligne
  //

  ///
  unsigned char  VerifieMinMax( );
  //       -------------

  ///
  void     InitCouleurs();



  ///
  void     LigneHorizontale( wxDC* dc, int xmin, int xmax, int xcentre, int y);
  //       ----------------
  // Dessine deux lignes d'ordonn� y entre xmin et xcentre - delta
  //                               et entre xcentre + delta et xmax

  ///
  void     LigneVerticale( wxDC* dc, int ymin, int ymax, int ycentre, int x);
  //       --------------
  // Dessine deux lignes d'abscisse y  entre ymin et ycentre - delta
  //                                et entre ycentre + delta et ymax


  ///
  float InterpoleZero( float val1, float val2);
  //   -------------
  // Si val1 et val2 sont de signes opposes,
  // renvoie un coeff qui est le poids (entre 0 et 1)
  // du deuxi�e point
  // Sinon renvoie -1
  // Fonction en ligne

public:

  ///
   DessinImageBase(
          wxWindow* parent,
          const std::string& ATitle,
          int l, int h,
          int type = CREATE_WINDOW);

  ///
  ~DessinImageBase();

  ///
  InrImage::ptr& GetImage() { return _image_initiale;}

  ///
  InrImage::ptr& GetDisplayedImage() { return _image;}

  ///
  DessinImageParametres* GetParam() { return &Param; }

  ///
  float GetMinIntensity()
  {
     switch (  _image->_format ){
       case WT_DOUBLE:
       case WT_FLOAT:
         return _intensite_float_min;
      case WT_UNSIGNED_CHAR:
      case WT_UNSIGNED_SHORT:
      case WT_SIGNED_SHORT:
      case WT_SIGNED_INT:
         return _intensite_entier_min;
      default:
      fprintf(stderr,"DessinImageBase::GetMinIntensity() format not available \n");
    } // end switch
    return 0.0;
  }

  ///
  float GetMaxIntensity()
  {
     switch (  _image->_format ){
       case WT_DOUBLE:
       case WT_FLOAT:
         return _intensite_float_max;
      case WT_UNSIGNED_CHAR:
      case WT_UNSIGNED_SHORT:
      case WT_SIGNED_SHORT:
      case WT_SIGNED_INT:
         return _intensite_entier_max;
      default:
      fprintf(stderr,"DessinImageBase::GetMaxIntensity() format not available \n");
    } // end switch
    return 0.0;
  }

  ///
  void CreateWxMenu();

  //
  void  SetTransformationMatrix( FloatMatrix* m)
  {
    _transf_matrix = m;
  }

  //
  FloatMatrix*  GetTransformationMatrix( )
  {
    return _transf_matrix;
  }

  ///
  virtual unsigned char IntensiteBuffer( float val);
  //                      ---------------
  // Fonction en ligne


  ///
  void InitLookUpTable();

  ///
  virtual unsigned char LookUpTable( const float& val, const WORDTYPE&) const;
  //                    ---------------
  // Fonction en ligne

  ///
  virtual void ColorBuffer( float val, unsigned char& red,
  //             -----------
  // Fonction en ligne
            unsigned char& green,
            unsigned char& blue);

  /**
   * Computes the 3D image position of the window cursor position.
   * The cursor position is given by cursor_x,cursor_y.
   * slice gives the slice number where the cursor position is or -1 if the cursor is out of the current drawn image.
   */
  void CursorToImage( const int cursor_x, const int cursor_y, 
                      int& x, int& y, int& z, int& slice);
  //   --------------
  //  Renvoie la position dans l'image du curseur,
  //  etat vaut -1 s'il y a une erreur
  //               sinon il indique l'image cliquée : IMAGE_XY, IMAGE_XZ ou IMAGE_ZY

  /**
   * Computes the 3D image position of the window cursor position.
   * The cursor position is given by cursor_x,cursor_y.
   * slice gives the slice number where the cursor position is or -1 if the cursor is out of the current drawn image.
   */
  void CursorToImageFloat(  const int cursor_x, const int cursor_y, 
                            float& x, float& y, float& z, int& slice);

  ///
  void     DessineCurseur( int x, int y, int z, int type);
  //       --------------
  //  Dessine la position du curseur sur toutes les coupes

  ///
  void     DessineSpatialCurseur( float x, float y, float z, int type);
  //       --------------
  //  Dessine la position du curseur sur toutes les coupes

  ///
  void MemoriseCoupesXY( unsigned char);
  //   ----------------
  // active ou desactive la memorisation des coupes XY


  /**
   * @brief Intialize mask image
   *
   * @param  mask input mask image
   * @return void
   **/
  void SetMaskImage( InrImage::ptr mask);
  
  ///
  void SetUseMask( unsigned char );
  //   ----------

  /**
   * @brief Set the color of the mask, using the alpha component format
   * opacity
   *
   * @param col input color
   * @return void
   **/
  void SetMaskColor( const wxColour & col);
  //   -----------

  ///
  void InitIsoContour( InrImage::ptr image_isocontour, float seuil, int num=0);
  //   --------------

  ///
  void DrawIsoContour( int num, int value);
  //   --------------

  //
  void SetIsoContourParam( int num, int thickness, int style);

  //
  void SetIsoContourColor( int num, unsigned char r, unsigned char g, unsigned char b);

  // drawing all isocontours (for the isocontour number 0 only)
  void SetDrawAllContours(  unsigned char draw)
  //   ------------------
  {
    _all_contours = draw;
  }

  void AllContoursParam( float step, float bandwidth)
  {
    _step_contours=step;
    _contours_winsize=bandwidth;
  }

  void SetLineAttributes( int capstyle, int joinstyle)
  {
    if ((capstyle>=0)&&(capstyle<=3))
      _cap_style=capstyle; // CapNotLast, CapButt, CapRound, or CapProjecting
    if ((joinstyle>=0)&&(joinstyle<=2))
      _join_style=joinstyle; // JoinMiter, JoinRound, or JoinBevel
  }

/*
  ///
  void DessineIsoContour( int n=0);
  //   -----------------
*/

/*
  ///
  void InitImage( inrimage* image);
  //   ---------
*/

  ///
  virtual void Paint(  unsigned char affiche = true);

  ///
  void ReDimensionne();

  ///
  void DrawAxis(  int orientation,
                  int axis,
                  int Ox, int Oy);

  ///
  void DessineAxesXY();
  ///
  void DessineAxesZY();
  ///
  void DessineAxesXZ();

  ///
  void DrawColorBar();

  
  ///
  void SetRGBTransform( RGBTransformBase::ptr t)
  {
    _rgbtransform = t;
  }
  
  ///
  void DrawSlice( int slice_id );

  ///
  void DessinePlanZ();

  ///
  void DessinePlanY();

  ///
  void DessinePlanX();

  ///
  void DessineCoupes();

  ///
  void DessinePlanMasqueZ();

  ///
  void DessinePlanMasqueY();

  ///
  void DessinePlanMasqueX();

  ///
  void DessineMasqueCoupes();

  ///
  void DessinePlanXIsoContour(
                   InrImage::ptr& image,
                   float threshold);

  ///
  void DessinePlanYIsoContour(
                   InrImage::ptr& image,
                   float threshold);

  ///
  void DessinePlanZIsoContour(
                   InrImage::ptr& image,
                   float threshold);

  ///
  void DessinePlanInterpZ();

  ///
  void DessinePlanInterpY();

  ///
  void DessinePlanInterpX();

  ///
  /// Draw a line in XY slice using (x,y) coordinates as input
  ///
  void DrawLineZ( float x1, float y1, float x2, float y2);
  //   ---------

  ///
  /// Draw a circle in (x,y) coordinates  with radius r - MicronTracker Utility
  ///
  void DrawCircleR( int x, int y, int r);
  //   ---------

  ///
  void InitFenetre();

  int GetImageWidth(int i) {
      if (_tab_slices[i].image.use_count())
        return _tab_slices[i].image->GetWidth();
      else
        return 0;
  }

  int GetImageHeight(int i) {
      if (_tab_slices[i].image.use_count())
        return _tab_slices[i].image->GetHeight();
      else
        return 0;
  }

  ///
  void SetCoupe( int coupe);
  //

  ///
  void IncCoupe();
  //

  ///
  void DecCoupe();
  //

  ///
  void SwapMenuVisible();
  //

  ///
  void ShowHideStatusBar();
  //

  ///
  virtual void OnChar(wxKeyEvent& );

/*
///
  static void CB_aide_HTML( Widget, void* cd, void*);
  //          ------------
*/

  ///
  void CB_interpole( wxCommandEvent& );
  //

  ///
  void CB_curseur_visible( wxCommandEvent& );
  //

}; // DessinImageBase
//============================================================================


//============================================================================
//  Fonctions en ligne
//============================================================================

//----------------------------------------------------------------
// default int inc=1
inline void DessinImageBase :: IncBuffer( int inc)
//                                         ---------
{
  _image->IncBuffer( inc);
} // IncBuffer()


/*
// Momentanee, a enlever plus tard, ne marchera pas pour
// les images comparees
inline unsigned char DessinImageBase :: FonctionIntensiteBuffer()
//                                                  -----------------------
// Fonction en ligne
{


    float valeur;

  valeur = _image->ValeurBuffer();
  return _interpole_ligne->FonctionIntensite(valeur);

} // FonctionIntensiteBuffer()


// Momentanee, a enlever plus tard, ne marchera pas pour
// les images comparees
inline unsigned char DessinImageBase :: FonctionIntensiteBuffer(
    float x, float y, float z)
//                                                  -----------------------
// Fonction en ligne
{


    float valeur;

  valeur = _image->InterpLinIntensite(x,y,z);
  return _interpole_ligne->FonctionIntensite(valeur);

} // FonctionIntensiteBuffer()
*/

//----------------------------------------------------------------
inline unsigned char DessinImageBase::IntensiteBuffer( float valeur)
//                                     ---------------
{


  /* TODO
   Si Param._I._type_courbe == TYPE_COURBE_INTERPOLE AlorsFait
     return _interpole_ligne->FonctionIntensite(valeur);
  */

    switch (  _image->_format ){

      case WT_DOUBLE:
      case WT_FLOAT:
        Si _intensite_float_min < _intensite_float_max Alors
          Si valeur < _intensite_float_min  AlorsRetourne _couleur_inf;
          Si valeur > _intensite_float_max  AlorsRetourne _couleur_sup;
        Sinon
          Si valeur > _intensite_float_min  AlorsRetourne _couleur_inf;
          Si valeur < _intensite_float_max  AlorsRetourne _couleur_sup;
        FinSi
        Si Param._I._type_courbe == TYPE_COURBE_PLATEAU AlorsFait return 255;
        return (unsigned char) ( _rapport_intensite * ( valeur - _intensite_float_min ) );

      case WT_UNSIGNED_CHAR:
      case WT_UNSIGNED_SHORT:
      case WT_SIGNED_SHORT:
      case WT_SIGNED_INT:
      case WT_UNSIGNED_INT:
         Si _intensite_entier_min < _intensite_entier_max Alors
          Si valeur < _intensite_entier_min  AlorsRetourne _couleur_inf;
          Si valeur > _intensite_entier_max  AlorsRetourne _couleur_sup;
        Sinon
          Si valeur > _intensite_entier_min  AlorsRetourne _couleur_inf;
          Si valeur < _intensite_entier_max  AlorsRetourne _couleur_sup;
        FinSi
        Si Param._I._type_courbe == TYPE_COURBE_PLATEAU AlorsFait return 255;
        return  (unsigned char) ( _rapport_intensite * ( valeur   - _intensite_entier_min ) );

      default: fprintf(stderr,"Error \t in switch, type not available \n");

    } // end switch

    return 0;

} // IntensiteBuffer()


//----------------------------------------------------------------
inline unsigned char DessinImageBase::LookUpTable( const float& valeur,
//                                     -----------
                                                    const WORDTYPE& format) const
{
  /* TODO
   Si Param._I._type_courbe == TYPE_COURBE_INTERPOLE AlorsFait
     return _interpole_ligne->FonctionIntensite(valeur);
  */

    switch (  format ){

      case WT_DOUBLE:
      case WT_FLOAT:
        Si _intensite_float_min < _intensite_float_max Alors
          Si valeur < _intensite_float_min  AlorsRetourne _couleur_inf;
          Si valeur > _intensite_float_max  AlorsRetourne _couleur_sup;
        Sinon
          Si valeur > _intensite_float_min  AlorsRetourne _couleur_inf;
          Si valeur < _intensite_float_max  AlorsRetourne _couleur_sup;
        FinSi
        Si Param._I._type_courbe == TYPE_COURBE_PLATEAU AlorsFait return 255;
        return (unsigned char) ( _rapport_intensite * ( valeur - _intensite_float_min ) );

      case WT_UNSIGNED_CHAR:
      case WT_UNSIGNED_SHORT:
      case WT_SIGNED_SHORT:
      case WT_SIGNED_INT:
      case WT_UNSIGNED_INT:
         Si _intensite_entier_min < _intensite_entier_max Alors
          Si valeur < _intensite_entier_min  AlorsRetourne _couleur_inf;
          Si valeur > _intensite_entier_max  AlorsRetourne _couleur_sup;
        Sinon
          Si valeur > _intensite_entier_min  AlorsRetourne _couleur_inf;
          Si valeur < _intensite_entier_max  AlorsRetourne _couleur_sup;
        FinSi
        Si Param._I._type_courbe == TYPE_COURBE_PLATEAU AlorsFait return 255;
        return  (unsigned char) ( _rapport_intensite * ( valeur   - _intensite_entier_min ) );

      default: fprintf(stderr,"Error \t in switch, type not available \n");

    } // end switch

    return 0;

} // LookUpTable()

//----------------------------------------------------------------
inline void DessinImageBase :: ColorBuffer( float valeur,
              unsigned char& red,
              unsigned char& green,
              unsigned char& blue)
//                                         -----------
{
  const ClasseCouleur& couleur =
    _tab_intensite_couleur[ IntensiteBuffer(valeur) ];
  red   = couleur.Red();
  blue  = couleur.Green();
  green = couleur.Blue();
} // ColorBuffer()


//----------------------------------------------------------------
inline unsigned char DessinImageBase::IntensiteBuffer( )
//                                     ---------------
{

  return IntensiteBuffer( _image->ValeurBuffer(Param._pos._v));

} // IntensiteBuffer()


//----------------------------------------------------------------
inline unsigned char DessinImageBase ::
                 IntensiteBuffer( float x, float y, float z)
//               ---------------
{

  return IntensiteBuffer( _image->InterpLinIntensite(x,y,z));

} // IntensiteBuffer()


//----------------------------------------------------------------
inline float DessinImageBase :: InterpoleZero( float val1, float val2)
//                                         -------------
{

//  Si (fabsf(val1) < 1E-4)  AlorsRetourne 0.0;
//  Si (fabsf(val2) < 1E-4)  AlorsRetourne 1.0;

  Si val1 > 0 Alors
    Si val2 < 0 Alors
      return (val1/(val1-val2));
    Sinon
      return -1;
    FinSi
  Sinon
    Si val2 > 0 Alors
      return (-val1/(-val1+val2));
    Sinon
      return -1;
    FinSi
  FinSi

} // InterpoleZero()


#endif // _DESSIN_IMAGE_BASE_HPP
