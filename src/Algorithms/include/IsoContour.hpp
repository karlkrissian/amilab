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
 * $Log: IsoContour.hpp,v $
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


#ifndef _ISOCONTOUR_HPP
#define _ISOCONTOUR_HPP


#include "style.hpp"
#include <iosfwd>
#include "math1.hpp"
#include "chaine.hpp"

#include "IsoContour2D.hpp"
#include "Voxel.hpp"
#include "Coordonnees.hpp"
#include "coord_image.hpp"
#include "gnuplot.hpp"
#include "Crest.hpp"
#include "PropagePoints.hpp"
#include "CalculAireSection.hpp"

#include "PointContour.hpp"


#define EffaceImage(    im) if ( im!= (InrImage*)NULL) { delete im; im = (InrImage*)NULL;}
#define EffaceTabReel(  im) if ( im!= (float*)    NULL) { delete[] im; im = (float*)NULL;}
#define EffaceTabEntier(im) if ( im!= (int*)  NULL) { delete[] im; im = (int*)NULL;}

extern InrImage* image_ligne;
extern InrImage* image;
extern InrImage* image_contours;
extern InrImage* image_gradient;
extern InrImage* image_num_contour;
extern InrImage* image_un_contour;

extern int    max_fond;
extern float      resolution;
extern Crest*    lignes;
extern int    num_ligne;
extern int    nbpts_ligne;
extern unsigned char   Sauve;
extern unsigned char   corrige;
extern float      precision_sigma;
extern Chaine    nom_image_resultat;
extern float      pas_abscisse;
extern int    contour_choisi;

#include "CommonConfigure.h"
COMMON_VAR_IMPORT unsigned char GB_verbose;
COMMON_VAR_IMPORT unsigned char GB_debug;



//======================================================================
///
class IsoContour
//
{

public:

  /// Exceptions
  //@{
    class OutOfRange
    {
    public:
      OutOfRange() {  std::cerr << "IsoContour\t Exception OutOfRange \n"; }
    };

  //@}

private:

  ///
  InrImage* _image;
  ///
  InrImage* _image_contour;

  ///
  Voxel  _voxel;

  // 6 faces, 4 positions par face
  int  _face[6][4];

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

  int*  _tab_ptsligne;       // Memorise le nombre de points de la ligne contenus uniquement 
                                // dans le contour donnee
  int*  _tab_ptsligne_total; // Memorise le nombre de points de la ligne contenus dans le contour

  int*  _tab_nbpts;          // Memorise le nombre de fois que le contour est traverse
  float*    _tab_moygrad;        // Memorise la moyenne du gradient le long du contour

  ///
  CoordImage*    coord_image;

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


  /// section pour la correction 2D
  InrImage* _section;
 
  /// image de reference pour la correction 2D
  InrImage* _contour_ref;

  ///
  IsoContour2D* _isocontour2D;

  ///
  int* _centre_sphere;

  ///
  float   _rayon_sphere;

  ///
  float   _sigma_correction;

private:

/**
  Verifie si les coordonnees sont dans le domaine de definition de l'image
 */
  unsigned char CoordOK( int x, int y, int z);
  //


/**
  Initialisation des 4 positions des sommets de la face
*/
  void InitFace( int num, int s1, int s2, int s3, int s4);
  //


/**
  Si signe vaut +1 ou -1 et que le signe de valeur est different 
  retourne true
  sinon retourne false
 */
  unsigned char   PassageParZero( int& signe,   double valeur);
  //							    

/**
  cherche un changement de signe dans le cube
  ( x+{0,1}, y+{0,1}, z+{0,1} )
 */
  unsigned char ExisteContour( int x, int y, int z) 
  //
    throw ( OutOfRange);


/**
  donne le numero du contour associe au changement de signe entre
  p1 et p2 (points voisins).
 */
  int contour( const PointContour& p1, const PointContour& p2 );
  //



  ///
  void InitImagesSurf( int tx, int ty, int tz);
  //

  ///
  void DeleteImagesSurf();
  //

  /// Calcule le nombre total de points de la ligne inclus dans le contour
  void CalculTotalPointsLigne();
  //

public:

  //--------------------------------------------------
  ///
   IsoContour( InrImage* image);
  //

  //--------------------------------------------------
  ///
  ~IsoContour();
  //
 

  ///
  void FixeSphere( int* centre, float rayon)
  //
  {

    _centre_sphere = centre;
    _rayon_sphere  = rayon;

  } // FixeSphere()
  

  //--------------------------------------------------
  ///
  void RechercheContours( InrImage* image);
  //


  //--------------------------------------------------
  ///
  void ParcoursContour( int x, int y, int z,  
  //
			int num,  int* taille);

  //--------------------------------------------------
  ///
  void PropageContour( InrImage* image_contour, 
  //
		       int num_contour);


  //--------------------------------------------------
    /*  Definit le signe de l'interieur de chaque contour
	ainsi que le contour auquel il appartient.
        le contour englobant l'image est numerote -1.

	utilise image, image_contours, image_gradient, image_ligne
     */
  void DefinitInterieur( );
  //

  ///
  /*
     Calcul de l'aire
   */
  void CalculAire( float taille_voxels = 1.0 );


  ///
  void CreeImagesCorrection();


  ///
  void EffaceImagesCorrection();


  /*
    Correction en 2D de l'estimation 3D, a partir du modele
    - z correspond au numero de la section
    - rayon est le rayon estim� en 3D
    - sigma0 est l'ecart-type de la PSF trouve
    - la valeur de retour est le rayon estime apres correction
   */
  float AppliqueCorrection( int z, float rayon, float& sigma0);

}; // IsoContour



#endif // _ISOCONTOUR_HPP
