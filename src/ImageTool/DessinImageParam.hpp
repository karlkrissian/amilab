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
 * $Revision: 1.2 $
 * $Log: DessinImageParam.hpp,v $
 * Revision 1.2  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2003/08/14 07:16:05  karl
 * Source code
 *
 * Revision 1.4  2001/03/02 11:49:30  karl
 * *** empty log message ***
 *
 * Revision 1.3  2000/10/30 13:13:15  karl
 * *** empty log message ***
 *
 * Revision 1.2  2000/09/19 12:19:06  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:09:34  karl
 * Sources code
 *
 *
 ***************************************************************************/
// Visualisation d'inrimage
// fichier DessinImageParam.hpp
//
// Karl KRISSIAN 
//
// Sophia Antipolis le 18-02-97
//


#ifndef _DESSIN_PARAM_HPP
#define _DESSIN_PARAM_HPP

//#include "palette.hpp"
//#include "ImageMIP.hpp"
class ImageMIP;
#include "style.hpp"
#include "inrimage.hpp"
#include "DefineClass.hpp"

#define OPTION_COUPE 0
#define OPTION_MIP   1
#define OPTION_ANIM  2

#define TYPE_COUPE_XY       0 // 001 - 1
#define TYPE_COUPE_XZ       1 // 010 - 1
#define TYPE_COUPE_XY_XZ    2 // 011 - 1
#define TYPE_COUPE_ZY       3 // 100 - 1
#define TYPE_COUPE_XY_ZY    4 // 101 - 1
#define TYPE_COUPE_XZ_ZY    5 // 110 - 1
#define TYPE_COUPE_XY_XZ_ZY 6 // 111 - 1
#define TYPE_COUPES         7

#define TAILLE_FENETRE 0
#define TAILLE_FACTEUR 1

#define FACTEUR_ENTIER 0
#define FACTEUR_REEL   1

#define EPSILON        1E-5

#define IMAGE_XY        0
#define IMAGE_XZ        1
#define IMAGE_ZY        2
#define IMAGE_COUPES    3
#define IMAGE_MASQUE_XY 4

#define NB_MAX_IMAGES       5

#define FUNC_ZOOM_ACTIVE         0
#define FUNC_ZOOM_DESACTIVE      1
#define FUNC_UNZOOM              2

//#define TYPE_INTENSITE_INTERPOLE 0
//#define TYPE_INTENSITE_MINMAX    1

#define TYPE_COURBE_PENTE      0
#define TYPE_COURBE_PLATEAU    1
#define TYPE_COURBE_PENTE2     2
#define TYPE_COURBE_INTERPOLE  3

#define TYPE_CURSEUR_equiv    0
#define TYPE_CURSEUR_copy     1


#define COLORSPACE_GREY    0
#define COLORSPACE_RAINBOW 1
#define COLORSPACE_USER    2

#define AXES_VOXEL_POS 0
#define AXES_SPACE_POS 1


class DessinParam 
//     ===========
{

  DEFINE_CLASS(DessinParam)

public:

  float    intensite_min;
  float    intensite_max;
  unsigned char int_min_fixee;
  unsigned char int_max_fixee;

  unsigned char version_anglaise;

  float taille_voxel[3];

  Constructeur DessinParam()
  //           -----------
  {
    version_anglaise = true;
    intensite_min = intensite_max = 0;
    int_min_fixee = int_max_fixee = false;

    taille_voxel[0] = taille_voxel[1] = taille_voxel[2] = -1.0;
  }

  Constructeur DessinParam(const DessinParam& p)
  //           -----------
  {
    *this = p;
  }

  virtual ~DessinParam() {}

  void operator=( const DessinParam& p)
  //   -----------
  {
    version_anglaise = p.version_anglaise;
    intensite_min = p.intensite_min;
    intensite_max = p.intensite_max;
    int_min_fixee = p.int_min_fixee;
    int_max_fixee = p.int_max_fixee;

    taille_voxel[0] = p.taille_voxel[0];
    taille_voxel[1] = p.taille_voxel[1];
    taille_voxel[2] = p.taille_voxel[2];
  }

}; // DessinParam



  /* Parametres principaux */

//======================================================================  
/**
 Les mises � jour ...
 */
class ParamMAJ
//     --------
{

public:

  /** @name Mises A Jour
   */
//@{
   unsigned char      _planXY;
   unsigned char      _planZY;
   unsigned char      _planXZ;
   unsigned char      _coupes;
   
   unsigned char      _intensite;
   unsigned char      _positions;
//@}

  ///
  Constructeur ParamMAJ()
  //
  {

    MAJCoupes();
    _intensite = true;
    _positions = true;

  }


  ///
  void MAJCoupes( unsigned char b=true)
  //
  {

    _planXY = _planZY = _planXZ = _coupes = b;

  }

  ///
  void operator=( const ParamMAJ& p)
  //
  {

    _planXY = p._planXY;
    _planZY = p._planZY;
    _planXZ = p._planXZ;

    _coupes    = p._coupes;
    _intensite = p._intensite;
    _positions = p._positions;

  }

}; // ParamMAJ


//======================================================================  
/**
  Parametres pour le Zoom
 */
class ParamZoom
//     ---------
{

public:

  /** Limites de l'image pour le zoom
   */
  //@{
   int       _xmin;
   int       _xmax;
   int       _ymin;
   int       _ymax;
   int       _zmin;
   int       _zmax;
//@}

/** Taille de la sous-image (apres le zoom)
 */
//@{
   int       _dessin_tx;
   int       _dessin_ty;
   int       _dessin_tz;
//@}

  ///
  Constructeur ParamZoom(){}

  ///
  void operator=( const ParamZoom& p)
  //
  {

    _xmin = p._xmin;
    _xmax = p._xmax;
    _ymin = p._ymin;
    _ymax = p._ymax;
    _zmin = p._zmin;
    _zmax = p._zmax;

    ComputeSize();

  }


  ///
  void InitLimites( const InrImage* image)
  //   -----------
  {

    _xmin = _ymin = _zmin = 0;
    _xmax = image->_tx - 1;
    _ymax = image->_ty - 1;
    _zmax = image->_tz - 1;

    ComputeSize();

  }

  ///
  void Check(const InrImage::ptr& image)
  //
  {
    Si _xmin < 0           AlorsFait _xmin = 0;
    Si _xmax >= image->_tx AlorsFait _xmax = image->_tx-1;

    Si _ymin < 0           AlorsFait _ymin = 0;
    Si _ymax >= image->_ty AlorsFait _ymax = image->_ty-1;

    Si _zmin < 0           AlorsFait _zmin = 0;
    Si _zmax >= image->_tz AlorsFait _zmax = image->_tz-1;

    Si _xmin >= _xmax Alors _xmin = 0; _xmax = image->_tx-1; FinSi
    Si _ymin >= _ymax Alors _ymin = 0; _ymax = image->_ty-1; FinSi
    Si _zmin >= _zmax Alors _zmin = 0; _zmax = image->_tz-1; FinSi

    ComputeSize();
  }

  ///
  void ComputeSize()
  //   ----------------
  {
    _dessin_tx = _xmax - _xmin + 1;
    _dessin_ty = _ymax - _ymin + 1;
    _dessin_tz = _zmax - _zmin + 1;

  }


}; // ParamZoom


//======================================================================  
/**
  Parametres pour les MIP
 */
class ParamMIP
//     ---------
{

public:

/** @name Gestion des images MIP
 */
//@{

   InrImage*    _image;

   /// objet permettant de creer une image MIP
   ImageMIP*    _MIP; 

   int       _rot_X;
   int       _rot_Y;
   int       _rot_Z;

   int       _MAJ;

/** option pour prendre en compte les 
  intensites min et max  
  dans le calcul des MIP 
*/
   unsigned char      _min_max; 

/// Dessin ou non d'une bounding box 
   unsigned char  _bounding_box; 

/** @name Pour la st�r�o
 */
//@{ 
   /// Gestion d'une deuxi�me MIP d�call�e
   unsigned char      _stereo;       
   int       _decal_stereo;
//@}

   float         _depth_cue;
//@}

  ///
  Constructeur ParamMIP() 
  //           --------
  {

    _MIP = NULL;
    _image = NULL;
    _rot_X = _rot_Y = _rot_Z = 0;
    _min_max      = false;
    _bounding_box = false;
    _stereo       = false;
    _decal_stereo = 5;
    _depth_cue    = 0.0;

    _MAJ = true;

  }

  ///
  void operator=(const ParamMIP& p)
  //
  {

    _rot_X = p._rot_X;
    _rot_Y = p._rot_Y;
    _rot_Z = p._rot_Z;

    _MAJ = p._MAJ;

    _min_max      = p._min_max;
    _bounding_box = p._bounding_box;

//    _stereo       = p._stereo;
    _decal_stereo = p._decal_stereo;
    _depth_cue    = p._depth_cue;

  }

}; // ParamMIP 


//======================================================================  
/**
  Parametres pour l'intensite
 */
class ParamIntensite
//     --------------
{

public:

  /** @name Intensites min et max de l'image
   */
  //@{
   float          _val_min;
   float          _val_max;
//@}

/** @name Intensite min max
 */
//@{
   float         _float_min; 
   float         _float_max;

   int       _entier_min;
   int       _entier_max;
//@}


   int       _colorspace;

///
//   int       _type_intensite;


/** @name Type de courbe pour l'intensit�
 */
//@{
   int       _type_courbe;

/** couleur des points en dessous 
    du minimum d'intensit� 
*/
   unsigned char _couleur_inf; 

   /// couleur des points au dessus du max
   unsigned char _couleur_sup; 
//@}


  ///
  Constructeur ParamIntensite() 
  {
    _type_courbe = TYPE_COURBE_PENTE;
    _colorspace  = COLORSPACE_GREY;
    //    _type_intensite = TYPE_INTENSITE_MINMAX;
  }

  ///
  void operator=(const ParamIntensite& p)
  //
  {
    
    _float_min = p._float_min;
    _float_max = p._float_max;

    _entier_min = p._entier_min;
    _entier_max = p._entier_max;

    _type_courbe = p._type_courbe;
    _couleur_inf = p._couleur_inf;
    _couleur_sup = p._couleur_sup;

    _colorspace  = p._colorspace;

  }

}; // ParamIntensite


//======================================================================  
/**
  Parametres pour le curseur
 */
class ParamCurseur
//     ------------
{

public:

/** @name Variables pour le dessin de la position du curseur
 */
//@{
   unsigned char      _ON;

   int       _x;
   int       _y;
   int       _z; 

   int       _couleur;
   int       _type;

   unsigned char      _visible;
//@}


  ///
  Constructeur ParamCurseur() 
  //
  {

    _ON      = false;
    _visible = false;

  }

  ///
  void operator=(const ParamCurseur& p)
  //
  {

    _ON = p._ON;

    _x  = p._x;
    _y  = p._y;
    _z  = p._z;

    _couleur = p._couleur;
    _type    = p._type;

    _visible = p._visible;

  }

}; // ParamCurseur



//======================================================================  
/**
  Parametres pour les dimensions
 */
class ParamDimensions
//     ---------------
{

public:

//@{
/// Taille des voxels
   float         _voxel_size_x;
   float         _voxel_size_y;
   float         _voxel_size_z;

//@}

/** @name facteurs d'aggrandissement en x , y et z
 */
//@{
   float         _size_x;
   float         _size_y;
   float         _size_z;
//@}

  ///
  Constructeur ParamDimensions() 
  //
  {
    _voxel_size_x =
    _voxel_size_y =
    _voxel_size_z = 1;
  }

  ///
  void operator=(const ParamDimensions& p)
  //
  {

    _voxel_size_x = p._voxel_size_x;
    _voxel_size_y = p._voxel_size_y;
    _voxel_size_z = p._voxel_size_z;

    _size_x = p._size_x;
    _size_y = p._size_y;
    _size_z = p._size_z;

  }

}; // ParamDimensions


//======================================================================  
/**
  Parametres pour les dimensions
 */
class ParamPosition
//     -------------
{

public:

//@{
/// Position x,y,z
  int  _x;
  int  _y;
  int  _z;
//@}

  ///
  Constructeur ParamPosition() 
  //
  {
    _x = _y = _z = 0;
  }

  void Init( const InrImage* image)
  {
    _z = (int) ( image->_tz / 2.0);
    _y = (int) ( image->_ty / 2.0);
    _x = (int) ( image->_tx / 2.0);
  }

  ///
  void Check( const InrImage::ptr& image)
  //
  {
    Si _x < 0          AlorsFait _x = 0;
    Si _x >= image->_tx AlorsFait _x = image->_tx-1;

    Si _y < 0          AlorsFait _y = 0;
    Si _y >= image->_ty AlorsFait _y = image->_ty-1;

    Si _z < 0          AlorsFait  _z = 0;
    Si _z >= image->_tz AlorsFait _z = image->_tz-1;
  }

  ///
  void operator=(const ParamPosition& p)
  //
  {

    _x = p._x;
    _y = p._y;
    _z = p._z;

  }

}; // ParamPosition


//======================================================================
/**
  Parametres qui determinent l'affichage de l'image
 */
class DessinImageParametres
//
{

public:

  ///
  ParamMAJ        _MAJ;

  ///
  ParamZoom       _Zoom;

  ///
  ParamMIP        _MIP;

  ///
  ParamIntensite  _I;

  ///
  ParamCurseur    _curseur;

  ///
  ParamDimensions _dim;

  ///
  ParamPosition   _pos;

  ///
  unsigned char         _show_axes;

  ///
  int          _axes_info;

  ///
  unsigned char         _show_colorbar;


/** Gestion des parametres
 */
//@{

   // MIP, COUPE ou ANIMATION
   int       _option_traitement; 

   int       _type_coupe;
   int       _ancien_type_coupe;

   int       _fonction_zoom;
   int       _type_taille;

   unsigned char      _parametres_visible;

//@}

  ///
  Constructeur DessinImageParametres( )        
  //
  {

    _type_coupe         = TYPE_COUPE_XY_XZ_ZY;
    
    _fonction_zoom      = FUNC_ZOOM_DESACTIVE;
    _type_taille        = TAILLE_FENETRE;
    _parametres_visible = false;

    _option_traitement  = OPTION_COUPE;

    _show_axes          = true;
    _axes_info          = AXES_VOXEL_POS;
    _show_colorbar      = true;

  }

  ///
  void InitParam( const InrImage* image,
      DessinParam::ptr param) 
  //
  {
    _pos.Init(image);

    Si image->_tz == 1 AlorsFait
      _type_coupe         = TYPE_COUPE_XY;

    Si _option_traitement != OPTION_MIP Alors
      Si param->taille_voxel[0] < 0 Alors
        _dim._voxel_size_x =  image->_size_x;
      Sinon
        _dim._voxel_size_x = param->taille_voxel[0];
      FinSi
 
      Si param->taille_voxel[1] < 0 Alors
        _dim._voxel_size_y = image->_size_y;
      Sinon
        _dim._voxel_size_y = param->taille_voxel[1];
      FinSi

      Si param->taille_voxel[2] < 0 Alors
        _dim._voxel_size_z = image->_size_z;
      Sinon
        _dim._voxel_size_z = param->taille_voxel[2];
      FinSi
    FinSi

    _Zoom.InitLimites( image);

  }

  ///
  void ChangeTypeCoupeMIP()
  //
  {
    _ancien_type_coupe = _type_coupe;
    _type_coupe = TYPE_COUPE_XY;
  }

  ///
  void AncienTypeCoupeMIP()
  //
  {
     _type_coupe = _ancien_type_coupe;
  }


  //
  void CopyPosition(const DessinImageParametres& p)
  //
  {

  } // CopyPosition


  //
  void CheckPosition( const InrImage::ptr& image)
  //
  {
    _Zoom.Check( image);
    _pos.Check(  image);
  } // CheckPosition()


  ///
  void operator=(const DessinImageParametres& p)
  //
  {

    _option_traitement  = p._option_traitement;
    _type_coupe         = p._type_coupe;
    _type_taille        = p._type_taille;

    _parametres_visible = p._parametres_visible;

    _pos           = p._pos;

    _MAJ           = p._MAJ;
    _Zoom          = p._Zoom;
    _MIP           = p._MIP;
    _I             = p._I;
    _curseur       = p._curseur;
    _dim           = p._dim;

    _show_axes     = p._show_axes;
    _axes_info     = p._axes_info;
    _show_colorbar = p._show_colorbar;

  }


}; // DessinImageParametres

#endif // _DESSIN_PARAM_HPP
