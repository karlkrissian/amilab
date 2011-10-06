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
 * $Log: IsoContour2D.hpp,v $
 * Revision 1.2  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:10:15  karl
 * Sources code
 *
 * Revision 1.1  1999/05/31 16:25:49  kkrissia
 * *** empty log message ***
 *
 ***************************************************************************/

// Version 2 de isocontour,
// parcours des regions connexes de meme signe ...
//


#ifndef _ISOCONTOUR_2D_HPP
#define _ISOCONTOUR_2D_HPP


#include "style.hpp"
#include <iostream>
#include "math1.hpp"
#include "chaine.hpp"
#include "GeneralGaussianFilter.h"
//#include "inrimage.hpp"
#include "Voxel.hpp"
#include "Coordonnees.hpp"
#include "coord_image.hpp"
#include "gnuplot.hpp"
#include "Crest.hpp"
#include "PropagePoints.hpp"
#include "CalculAireSection.hpp"
#include "PointContour.hpp"

#define EPSILON 1E-2

#define SIGNE(val) ((val>-EPSILON)?1:-1)

#define EffaceImage(    im) if ( im!= (InrImage*)NULL) { delete im; im = (InrImage*)NULL;}
#define EffaceTabReel(  im) if ( im!= (float*)    NULL) { delete[] im; im = (float*)NULL;}
#define EffaceTabEntier(im) if ( im!= (int*)  NULL) { delete[] im; im = (int*)NULL;}



#include "CommonConfigure.h"
COMMON_VAR_IMPORT unsigned char GB_debug;
COMMON_VAR_IMPORT unsigned char GB_verbose;



//======================================================================
///
class IsoContour2D
//
{

public:

  /// Exceptions
  //@{
    class OutOfRange
    {
    public:
      OutOfRange() {  std::cerr << "IsoContour2D\t Exception OutOfRange \n"; }
    };

  //@}

private:

  ///
  unsigned char   _silencieux;

  ///
  InrImage* _image_initiale;
  ///
  InrImage* _image_contours;
  ///
  InrImage* _image_contour;
  ///
  InrImage* _image_num_contour;
  ///
  InrImage* _image_ref;

  ///
  float      _max_fond;

  ///
  int    _contour_choisi;

  ///
  Chaine    _nom_image_resultat;

  ///
  float      _precision_sigma;

  ///
  unsigned char   _sauve;

  ///
  Voxel  _voxel;

  /** coordonnees de chaque sommet d'une face 
     Une face a son propre syst�me de coordonn�es,
     le premier point (0,0)
     le 2eme          (1,0)
     le 3eme          (1,1)
     le 4eme          (0,1)
  */
  PtFace  _coord_sommet[4]; 

  int   _nb_contours;
  int*  _tab_contenance;     // Memorise a quel contour appartient un contour donne
  int*  _tab_signe;          // Memorise le signe de l'interieur pour chaque contour
  int*  _tab_distance;       // Memorise le nombre de points qui diff�rent par
                                // rapport au contour de reference
                                // dans le contour donnee
  int*  _tab_in;             // Nombre de points du contour dans le contour de ref
  int*  _tab_out;            // Nombre de points du contour hors du contour de ref

  int*  _tab_nbpts;          // Memorise le nombre de fois que le contour est traverse
  float*    _tab_moygrad;        // Memorise la moyenne du gradient le long du contour


  ///
  Vect3D<float> t,v1,v2;

  ///
  InrImage* _image_surfinf;
  ///
  InrImage* _image_surfsup;
  ///
  InrImage* _image_sections;

  /// permet de savoir la taille maximale de la pile dans la propagation des contours
  int    _max_points;

  ///
  CalculAireSection* _calcul_aire;

  ///
  GeneralGaussianFilter*    _filtre;

  ///
  PropagePoints*     _propage;

private:

/**
  Verifie si les coordonnees sont dans le domaine de definition de l'image
 */
  unsigned char CoordOK( int x, int y, int z);
  //



/**
  donne le numero du contour associe au changement de signe entre
  p1 et p2 (points voisins).
 */
  int contour( const PointContour& p1);
  //



  ///
  void InitImagesSurf( int tx, int ty, int tz,
  //
		       float   resolution);


  ///
  void DeleteImagesSurf();
  //

  /// Calcule le nombre total de points de la ligne inclus dans le contour
  void CalculTotalPointsLigne();
  //

  ///
  void  InitFiltre();

  ///
  void  EffaceFiltre();

public:

  //--------------------------------------------------
  ///
   IsoContour2D( InrImage* image_initiale, 
			     const     Chaine& nom_res,
			     unsigned char   sauve);
  //

  //--------------------------------------------------
  ///
  ~IsoContour2D();
  //
 

  //--------------------------------------------------
  ///
  void FixeSilencieux( unsigned char silent)
  //
  {

    _silencieux = silent;

  }

  
  //--------------------------------------------------
  /*
    Fixe la precision de sigma0 pour la correction
  */ 
  void FixePrecisionSigma( float precision_sigma)
  //
  {
   
    _precision_sigma = precision_sigma;

  }


  //--------------------------------------------------
  ///
  void ChangeImage( InrImage* image);
  //


  //--------------------------------------------------
  ///
  void RechercheContours( );
  //


  //--------------------------------------------------
  ///
  void ParcoursContour( int x, int y, int z,  
  //
			int num,  int* taille);

  //--------------------------------------------------
  ///
  void PropageContour( );
  //


  //--------------------------------------------------
  ///
  void ContourReference( InrImage* ref) 
  //
  {
    _image_ref = ref;
  }

  //--------------------------------------------------
  ///
  void FixeMaxFond( float max_fond) 
  //
  {
    _max_fond = max_fond;
  }


  //--------------------------------------------------
    /*  Definit le signe de l'interieur de chaque contour
	ainsi que le contour auquel il appartient.
        le contour englobant l'image est numerote -1.

	utilise image, image_gradient     */
  void DefinitInterieur(  float  max_fond);
  //

  ///
  float CalculAire( float resolution); 

  ///
  void CalculImageContours( float sigma);
  //

  ///
  void MAJContourRef();
  //

  ///
  float EstimeRayon( float sigma, InrImage* image_ref,
		    float resolution
		    );


  ///
  float CorrigeEstimation(
			  InrImage* image2Dref,
			  float rayon_estime,
			  float precision,
			  float resolution
			  );

  ///
  float CorrigeEstimation2(
			  InrImage* image2Dref,
			  float rayon_estime,
			  float precision,
			  float resolution,
			  float& sigma
			  );

}; // IsoContour2D



#endif // _ISOCONTOUR_2D_HPP
