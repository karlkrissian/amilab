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
// Creation de projection MIP d'inrimage
// fichier ImageMIP.hpp
//
// Karl KRISSIAN 
//
// Sophia Antipolis le 09-07-97
//

// Objectif de cet objet:
//   A partir d'un pointeur sur une inrimage de format quelconque,
//   generer une inrimage de la projection MIP, 
//   a l'aide de la matrice de projection
//

// On va definir un objet "matrice de projection"
// qui va contenir des methodes permettant
// differentes rotations

#ifndef _IMAGEMIP_HPP
#define _IMAGEMIP_HPP

#include "style.hpp"
#include "inrimage.hpp"
#include "math1.hpp"
#include "Coordonnees.hpp"

//============================================================================
/**
 */
class ImageMIP
//     --------
{

  ///
  InrImage* _image;

  ///
  InrImage::ptr _imageMIP;

  /** l'image MIP est une image 2D de dimensions
      _taille_MIP par _taille_MIP
  */
  int    _taille_MIP; 

  /** @name Position du voxel projette 
   */
//@{
  ///
  InrImage::ptr _imageMIP_posX;
  ///
  InrImage::ptr _imageMIP_posY;
  ///
  InrImage::ptr _imageMIP_posZ;
//@}


  /// Image permettant de gerer un masque en accelerant le processus
  InrImage* _image_masque;

  /// matrice de rotation
  double _mat_rot[3][3]; 
  ///
  float       _val_min;
  ///
  float       _val_max;

  ///
  unsigned char    _Rapide;

  ///
  unsigned char    _DepthCueing;
  ///
  float       _DepthCueingFactor;

  ///
  float       _voxel_size_x, _voxel_size_y, _voxel_size_z;

  //--------- Parametres pour la stereo
  // Toutes les distances sont en voxels
  //
  ///
  float       _d_oeil_ecran;
  ///
  float       _d_yeux; // distance entre les 2 yeux
  ///
  float       _d_oeil; // distance entre le centre des yeux et l'oeil
                      // pour lequel on projette:
                      // oeil gauche: -_d_yeux/2
                      // oeil droit :  _d_yeux/2
  ///
  float       _d_ecran_objet;
  ///
  unsigned char    _stereo;

  /// Variables pour l'interpolation lin�ire
  float***    _Voisins;
  ///
  float**     _Iyz[2];
  ///
  float       _delta_y;
  ///
  float*      _delta_z;
  ///
  float**     _delta_yz;
  ///
  int     _nbx,_nby,_nbz;

  ///
  int     _xmin,_xmax,_ymin,_ymax,_zmin,_zmax;


private:

  ///
  void InitInterpolLineaire();
  //   --------------------

  ///
  void FinInterpolLineaire();
  //   -------------------

  ///
  void InterpolePlanX( int pos);
  //   --------------
  // pos = 0 ou pos = 1

  ///
  void InitMatriceId() // initialise la rotation a la matrice identite
  //   -------------
  {
     _mat_rot[0][0] = 1.0;  _mat_rot[0][1] = 0.0;  _mat_rot[0][2] = 0.0;
     _mat_rot[1][0] = 0.0;  _mat_rot[1][1] = 1.0;  _mat_rot[1][2] = 0.0;
     _mat_rot[2][0] = 0.0;  _mat_rot[2][1] = 0.0;  _mat_rot[2][2] = 1.0;
  }

  ///
  void AppliqueRotation( const float x, const float y, const float z, float* x1, float* y1, float* z1);
  //   ----------------

  ///
  void AppliqueRotation( double x, double y, double z, double* x1, double* y1, double* z1);
  //   ----------------

  ///
  void  AppliqueRotation( const Vect3D<float> & v1, Vect3D<float>& v2);
  //                        ----------------

  ///
  void AlloueImage();
  //   -----------

  ///
  void AlloueImageMasque();
  //   -----------------

  ///
  void ReAlloueImage();
  //   -------------

  ///
  void InitImage0();
  //   ----------

public:

  ///
  Constructeur ImageMIP( InrImage* image ); 
  //           --------

  ///
  Destructeur ImageMIP()
  //
  {
  }  


  ///
  void MIPRapide( unsigned char rapide) { _Rapide = rapide; }
  //   ---------

  ///
  void ActiveStereo( float d_yeux, float d_oeil_ecran, float d_ecran_objet);
  //   ------------

  ///
  void DesActiveStereo( ) {_stereo = false; }
  //   ---------------

  ///
  void StereoOeilGauche() { _d_oeil = -0.5*_d_yeux; }
  //   ----------------

  ///
  void StereoOeilDroit()  { _d_oeil  =  0.5*_d_yeux; }
  //   ---------------

  ///
  void FixeVoxelSize( float, float, float);
  //   -------------

  ///
  void FixeLimites( float min = 0, float max = 1E20);
  //   -----------

  ///
  void InitMasque( );
  //   ----------

  ///
  void FixeDepthCue( unsigned char dephtcue, float facteur);
  //   ------------

  ///
  void FixeRotation( float rX, float rY, float rZ);
  //   ------------
  // Fixe la matrice de rotation

  InrImage::ptr CreeMIP( float rX, float rY, float rZ);
  //        -------
  // rX, rY, rZ definissent les rotations successives
  // par rapport aux axes des X, des Y, et des Z.

  ///
  void FixeLimites( int xmin, int xmax, int ymin, int ymax,
		    int zmin, int zmax)
  {
    _xmin = xmin;
    _xmax = xmax;
    _ymin = ymin;
    _ymax = ymax;
    _zmin = zmin;
    _zmax = zmax;
  }  

  ///
  InrImage::ptr CreeMIPRapide( );
  //        -------------
  // utilise la matrice courante de rotation

  ///
  InrImage::ptr CreeMIP( );
  //        -------
  // utilise la matrice courante de rotation

  ///
  InrImage::ptr CreeMIP2( );
  //        --------
  // Optimisation de la projection, en ajoutant la
  // projection d'un vecteur unitaire a la projection precedente
  // utilise la matrice courante de rotation

  ///
  InrImage::ptr CreeMIP_precise( );
  //        ---------------
  // Cree une image en projetant 8 points par voxel

  ///
  InrImage::ptr CreeMIP_interpol_lineaire( );
  //        -------------------------
  // Interpolation lin�ire de l'intensit�  // Cree une image en projetant 8 points par voxel

  ///
  InrImage::ptr CreeMIP_interpol_lineaire2( );
  //        --------------------------
  // Optimisation de l'interpolation lin�ire
  // En remplacant les multiplications par des additions
  // Interpolation lin�ire de l'intensit�  // Cree une image en projetant 8 points par voxel

  ///
  InrImage::ptr CreeMIP_interpol_lineaire3( );
  //        --------------------------
  // Optimisation en m�orisant tous les coefficients
  // Interpolation lin�ire de l'intensit�  // Cree une image en projetant 8 points par voxel

  ///
  void RotationX( double angle);
  //   ---------

  ///
  void RotationY( double angle);
  //   ---------

  ///
  void RotationZ( double angle);
  //   ---------

  ///
  void DetecteRotations( int *rot_x, int *rot_y, int *rot_z);
  //   ----------------

  ///
  void Projection( float x, float y, float z, float* x1, float* y1, float* z3);
  //   ----------

  ///
  void Projection( double x, double y, double z, double* x1, double* y1, double* z3);
  //   ----------

  ///
  void Projection2( float x, float y, float z, float* x1, float* y1, float* z3);
  //   -----------

  ///
  float ValDepthCue( float x, float y, float z);
  //   -----------
  // return le facteur multiplicatif pour le depthcueing au point (x,y,z)


  /// Position dans l'image 3D du point projete
  void PosPoint( int x, int y, int& posx, int& posy, int& posz);
  //   --------

  ///
  Vect3D<float> ProjetteVecteur( const Vect3D<float>& vect);

}; // ImageMIP


#endif // _IMAGEMIP_HPP
