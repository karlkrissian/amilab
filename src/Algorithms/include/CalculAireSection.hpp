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
 * $Log: CalculAireSection.hpp,v $
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


#ifndef _CALCUL_AIRE_SECTION_HPP
#define _CALCUL_AIRE_SECTION_HPP

#if defined(WIN32)
  #include <windows.h>
#endif

#include "style.hpp"
#include <iostream>
#include "math1.hpp"
#include "chaine.hpp"
#include "inrimage.hpp"
#include "Voxel.hpp"
#include "Coordonnees.hpp"
#include "coord_image.hpp"
#include "gnuplot.hpp"
#include "PropagePoints.hpp"

#ifdef EPSILON
#undef EPSILON
#endif
#define EPSILON 1E-2

#define SIGNE(val) ((val>-EPSILON)?1:-1)

#define EffaceImage(    im) if ( im!= (InrImage*)NULL) { delete im; im = (InrImage*)NULL;}
#define EffaceTabReel(  im) if ( im!= (float*)    NULL) { delete[] im; im = (float*)NULL;}
#define EffaceTabEntier(im) if ( im!= (int*)  NULL) { delete[] im; im = (int*)NULL;}

#include "CommonConfigure.h"
COMMON_VAR_IMPORT unsigned char GB_debug;
COMMON_VAR_IMPORT unsigned char GB_verbose;



#define GSigne(i,j)     _grille_signe     [i-_min_i][j-_min_j]
#define GDansListe(i,j) _grille_dans_liste[i-_min_i][j-_min_j]
#define GParcours(i,j)  _grille_parcours  [i-_min_i][j-_min_j]
#define GValeurs(i,j)   _grille_valeurs   [i-_min_i][j-_min_j]


//======================================================================

class CalculAireSection
//
{

public:

  // Exceptions
  class LimitesAtteintes
  {
  public:
    LimitesAtteintes(Chaine message)
      {
	std::cerr << " On touche le bord de l'image \t";
        std::cerr << message << std::endl;
      }
  };

protected:


  ///
  float     _resolution;

  ///
  float     _surf_carre;

  ///
  int   _min_i,_max_i;
  ///
  int   _min_j,_max_j;
  ///
  int** _grille_signe;
  ///
  int** _grille_parcours;

  /// Dis si le point a deja ete dans la liste des points a parcourir
  /// pour eviter de mettre 2 fois le meme point dans la liste
  int** _grille_dans_liste;

  /// vaut 1 si le point est deja parcouru, 0 sinon
  float**   _grille_valeurs;

  ///
  Vect3D<float> t,v1,v2;

  ///
  CoordImage*    _coord_image;

  ///
  int   _positifs;
  ///
  int   _negatifs;

  ///
  InrImage* _image_contour;

  ///
  InrImage* _image_surfinf;
  ///
  InrImage* _image_surfsup;
  ///
  InrImage* _image_sections;
  ///
  InrImage* _image_initiale;

  ///
  PropagePoints*  _propage;


private:

  /**
     return la distance entre le point M1 d'intensite val1 et le point null sur
     le segment (M1,M2) de longueur 1, avec M2 d'intensite val2.
   */
  float InterpoleZero( float val1, float val2);


  /**
    calcul de l'aire du triangle positif, 
    le signe de l'element i est different de celui
    de son successeur ainsi que de celui de son predecesseur
   */
  float SurfaceTriangle( float* val, int i);


  /**
    calcul de l'aire du trapeze
    le deux valeurs negatives de val sont i et (i+1)%4
   */
  float SurfaceTrapeze( float* val, int i);


  /**
    Calcul de la surface negative d'un carre
    val est un tableau de 5 valeurs qui correspond aux valeurs d'intensites sur les
    4  sommet d'un carre et la 5 valeur correspond a l'intensite au milieu 
    lorsqu'on est dans un ambiguite ( 2 sommets negatifs non consecutifs)
   */
  float InterpoleSurface( float* val);


  ///
  int Signe( float val);
  //

  ///
  void CreeGrille();
  //

  ///
  void InitGrille();
  //

  ///
  void DeleteGrille();
  //

  /// Ajoute un point dans la liste des points a propager
  void AjoutePropage( int i, int j) throw (LimitesAtteintes);
  //


public:

  ///
   CalculAireSection( InrImage* image, float resolution);
  //

  ///
  ~CalculAireSection();
  //

  ///
  void ChangeImage( InrImage* image);
  //

  ///
  int TailleX();
  //

  ///
  int TailleY();
  //

  /**
    Dans la base (point,v1,v2) revoie le signe du point
    point+i*v1+j*v2 dont la valeur est obtenue par interpolation trilineaire
    val contient la valeur du point
   */
  int CalculSigne( int i, int j, int p, const Point3D point, float& val);
  //

  /**
    Calcul de signe de la valeur interpolee au milieu du carre
   */
  int CalculSigneMilieu( int i, int j, const Point3D point, float& val);


  /**
   */
  void InitImagesSurf( InrImage* imsurfinf, InrImage* imsurfsup, 
  //
		       InrImage* imsections, InrImage* iminitiale);

  //--------------------------------------------------  
  /*
   */
  void RemplitSection( int p, const Point3D point );
  //

  /**
     parameter 'p' number of the xy slice for stacking the resuts
   */
  float Aire(int p, Point3D point, 
	    Vect3D<float> v1, Vect3D<float> v2,
	    float* surf_inf, float* surf_sup, float* surf_interp);

}; // CalculAireSection



#endif // _CALCUL_AIRE_SECTION_HPP
