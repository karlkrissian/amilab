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
//  fichier GeneralGaussianFilter.h
//
//  Karl Krissian    Sophia Antipolis, le 17-07-98
//


#ifndef _FILTRE_REC_HPP
#define _FILTRE_REC_HPP

#include "style.hpp"

extern "C" {
#include <stdio.h>
//#include <epidaure.h>
//#include <epidaure.ee>
}

#include "Coordonnees.hpp"
#include "inrimage.hpp"
#include "GaussianFilter.h"

#include "chaine.hpp"
#include "DefineClass.hpp"

#ifndef MODE_1D
#define MODE_1D 1
#define MODE_2D 2
#define MODE_3D 3
#endif

/**
 */
//@{
///
#define DIM_X      0
///
#define DIM_Y      1
///
#define DIM_Z      2
//@}


/**
 */
//@{
///
#define IM_sigma   0
///
#define IMx_sigma  1
///
#define IMy_sigma  2
///
#define IMz_sigma  3
///
#define IMxx_sigma 4
///
#define IMxy_sigma 5
///
#define IMyy_sigma 6

///
#define IMzx_sigma 7
///
#define IMxz_sigma 7

///
#define IMzy_sigma 8
///
#define IMyz_sigma 8

///
#define IMzz_sigma 9
//@}

#define NB_IMAGES  10

//#define MODE_2D 0
//#define MODE_3D 1

/**
@name Type de filtre
*/
//@{
///
#define FILTRE_REC  1
///
#define FILTRE_CONV 2
///
#define MY_FILTRE_CONV 3
//@}


typedef enum {
  PIXEL_SPACE,
  REAL_SPACE
} scale_unit;

//class GeneralGaussianFilter;
//typedef boost::shared_ptr<GeneralGaussianFilter> FiltreRecursif_ptr;

//===========================================================
/** 
 * Computation of image derivatives or smoothing up to second order by Gaussian convolution. 
 * This class is called general since it could call different type of implementations.
 */
class GeneralGaussianFilter
//    ==============
{
  DEFINE_CLASS(GeneralGaussianFilter);

public:

  class GradientNotComputed {};
  class HessianNotComputed {};

protected:

  /// Pour ne rien ecrire ...
  unsigned char _silencieux;

  ///
//  e_ParamRecFil _param_filtre;

  ///
//  e_SepFilterPar _param_filtre_conv;

  ///
//  PTRINRIMAGE _image_initiale;

  ///
  InrImage*  _InrImage_initiale;

  ///
  unsigned char    _utilise_Image_sigma[NB_IMAGES];
  ///
  int     _derivees[NB_IMAGES][3];

  ///
  int     _dim;

  ///
  InrImage* _InrImage_sigma[NB_IMAGES];

  ///
  Chaine    _ImageNom[NB_IMAGES];

  ///
  int    _type;


  ///
  unsigned char   _coeff_int_gauss;

  ///
  unsigned char   _gamma_normalisation;
  ///
  double    _gamma;

/**
@name voxel size
 */
//@{
  ///
  double    _vx;
  ///
  double    _vy;
  ///
  double    _vz;
//@}

/**
@name standard deviation of the Gaussian filter for each coordinate
 */
//@{
  ///
  double    _sigmax;
  ///
  double    _sigmay;
  ///
  double    _sigmaz;
//@}

  scale_unit _sigma_unit;

/**
@name gamma-normalisation of first order derivative in each direction
 */
//@{
  ///
  double    _normx;
  ///
  double    _normy;
  ///
  double    _normz;
//@}

  /// Memorisation du dernier sigma utilise
  double  _sigma;

  /**
   Optimisation du filtrage pour le multi-echelles
   en utilisant l'image filtree precedemment
  */  
  unsigned char     _OptFiltrage;

  unsigned char     _masque;
  InrImage*   _image_masque;

  unsigned char     _masque_gradient;
  InrImage*   _image_masque_gradient;

  // Pour le filtrage de type MY_FILTRE_CONV
  InrImage*   _image_tmp;

  // Pour le filtrage avec compression des images
  InrImage*   _image_tmp1;
  InrImage*   _image_tmp2;

  //
  GaussianFilter    _filtre_x;
  GaussianFilter    _filtre_y;
  GaussianFilter    _filtre_z;

  GaussianFilter    _filtre;

public:


  ///
  unsigned char  _utilise_image;

  ///
  unsigned char  _utilise_gradient;

  /// 
  unsigned char  _utilise_hessien;

  ///
  unsigned char  _derivees_compressees;



private:

  /// Facteur du support du filtre pour le type MY_FILTRE_CONV
  int    _facteur_support;

  void InitNomDerivees();
  //   ---------------

  void InitCoeffDerivees();
  //   -----------------


public:

  ///
//  Constructor GeneralGaussianFilter( PTRINRIMAGE image, int dim = MODE_3D);

  ///
   GeneralGaussianFilter( InrImage* image, int dim = MODE_3D);

  static GeneralGaussianFilter::ptr New(InrImage* image, int dim = MODE_3D)
  {
    return GeneralGaussianFilter::ptr(new GeneralGaussianFilter(image,dim));
  }

  ///
  virtual ~GeneralGaussianFilter();


  ///
  void DontUseVoxelSize()
  {
    _vx = _vy = _vz = 1;
  }

  //
  void SetScaleUnit( scale_unit s) { _sigma_unit = s; }

  ///
  void FixeSilencieux( unsigned char silent)
  //
  {

    _silencieux = silent;

  }


  ///
  void SetSupportSize( int facteur)
  //
  {
    _facteur_support = facteur;
  }


  ///
  void CalculCoeffIntegration( )
  //
  {
    _coeff_int_gauss = true;
  }


  ///
  void UtiliseGradient( unsigned char utilise)
  //   ---------------
  {
    _utilise_gradient = utilise;
  }

  ///
  void Utilise_Image( unsigned char utilise)
  //   -------------
  {
    _utilise_image = utilise;
  }

  ///
  void UtiliseHessien( unsigned char utilise)
  //   --------------
  {
    _utilise_hessien  = utilise;
  }

  ///
  void InitFiltre( float sigma, int type=MY_FILTRE_CONV);
  //   ----------

  ///
  void OptFiltrage( unsigned char optimise)
  //   -----------
  {
    Si Non(_silencieux) AlorsFait 
      cout << "_utilise_image = " << _utilise_image << endl;
    Si  _utilise_image Alors
      _OptFiltrage = optimise;
    Sinon
      _OptFiltrage = false;
      Si Non(_silencieux) AlorsFait 
        cerr << "Pas d'optimisation "
             << "si  _utilise_image = false ...\n";
    FinSi
  }
 
  ///
  void FixeMasque( InrImage* masque)
  //
  { _masque = true; _image_masque = masque; }

  ///
  void FixeMasqueGradient( InrImage* masque)
  //
  { _masque_gradient = true; _image_masque_gradient = masque; }


  ///
  void MyFiltre( InrImage* im, InrImage* res, 
  //   --------
               int der_x, int der_y, int der_z,
         InrImage* ImMasque=(InrImage*)NULL);

  ///
  void MyFiltre1D( InrImage* entree, InrImage* sortie, InrImage* masque,
  //   --------
     direction_filtre dir, double sigma, int ordre);

  ///
  void GammaNormalise( unsigned char norm) 
  //
  { _gamma_normalisation = norm; }
  
  ///
  void FixeGamma( double gamma) 
  //
  { 
    _gamma = gamma; 

    Si _gamma_normalisation Alors
      _normx = pow(_sigmax,_gamma);
      _normy = pow(_sigmay,_gamma);
      _normz = pow(_sigmaz,_gamma);
    FinSi

  }
  
  ///
  void InitDerivees();
  //   ------------

  ///
//  void InitDeriveesCompressees( InrImage* masque, int nb_points);
  //   -----------------------

  ///
  void LibereDerivees();
  //   --------------


  ///
  void CalculMyFiltres2D( InrImage* image_depart);
  //   -----------------

  ///
  void CalculMyFiltres( InrImage* image_depart);
  //   ---------------

  ///
//  void CalculMyFiltresCompressees( InrImage* image_depart);
  //   --------------------------

  ///
  void CalculFiltres( InrImage* mask = NULL  );
  //   -------------

  /*
    Calcul des Filtres A partir de l'image
    lissee deja obtenue, et non pas de l'image initiale,
    
  */
  void CalculFiltresSuivants();
  //   ---------------------

  ///
  unsigned char UtiliseImage( int i)
  //      ------------
  {
    Si i<0 Ou i>= NB_IMAGES AlorsFait return false;
    return _utilise_Image_sigma[i];
  }

  ///
  InrImage* operator () ( int i)
  //        -----------
  {
    Si i<0 Ou i>= NB_IMAGES AlorsFait return (InrImage*)NULL;
    return _InrImage_sigma[i];
  }

  ///
  Vect3D<double>  Gradient( int x, int y, int z)
  //              --------
    throw (GradientNotComputed);

  ///
  Vect2D<double>  Gradient( int x, int y)
  //              --------
    throw (GradientNotComputed);

  /// trilinear interpolation
  Vect3D<double>  Gradient( const double& x, const double& y, 
                            const double& z) 
    throw (GradientNotComputed);

  ///
  void InitHessienDepuisGrad();
  
  /**
    Les images du gradient etant pre-calculees,
    estime le hessien en 1 point (x,y,z)
   */
  void HessienDepuisGrad( 
  //   -----------------
    double* hessien, int x, int y, int z )
    throw (GradientNotComputed);

  ///
  void  Hessien2D( double* hessien, int x, int y )
  //    ---------
    throw (HessianNotComputed);

  ///
  void  Hessien( double* hessien, int x, int y, int z)
  //    -------
    throw (HessianNotComputed);

}; // GeneralGaussianFilter


#endif // _FILTRE_REC_HPP
