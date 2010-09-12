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
 * $Revision: 1.7 $
 * $Log: IsoContour2.hpp,v $
 * Revision 1.7  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.6  2005/04/04 05:05:29  karl
 * Improving Skeletonization: better line connextion and avoiding some local loops
 *
 * Revision 1.5  2005/01/29 01:56:36  karl
 * changing sign definition for IsoContour2 and also for Computing Connected Components
 *
 * Revision 1.4  2004/08/03 20:04:01  karl
 * Connected component + lines in vrml
 *
 * Revision 1.3  2004/07/01 15:03:29  karl
 * Added features to Connected Components, Resize with translation, volume rendering
 *
 * Revision 1.2  2004/06/02 22:57:34  karl
 * Connected Components + some bugs fixed
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


#ifndef _ISOCONTOUR2_HPP
#define _ISOCONTOUR2_HPP


#define TOPOLOGY_LINEARINTERPOLATION 0
#define TOPOLOGY_THINNING            1

//#include <WinNt>
#include <iostream>
//#include "style.hpp"
#include "math1.hpp"
#include "chaine.hpp"
#include "inrimage.hpp"
#include "Voxel.hpp"
#include "Coordonnees.hpp"
#include "coord_image.hpp"
#include "gnuplot.hpp"
#include "Crest.hpp"
#include "PropagePoints.hpp"
#include "CalculAireSection.hpp"

#include "PointContour.hpp"
#include "Timing.hpp"

#define EPSILON 1E-2

#ifndef SIGNE
#define SIGNE(val) ((val>0)?1:-1)
#endif

#define EffaceImage(    im) if ( im!= (InrImage*)NULL) { delete im; im = (InrImage*)NULL;}
#define EffaceTabReel(  im) if ( im!= (float*)    NULL) { delete[] im; im = (float*)NULL;}
#define EffaceTabEntier(im) if ( im!= (int*)  NULL) { delete[] im; im = (int*)NULL;}


class ConnectedComponentInfo {

public:

  int number;       // number of the contour as displayed in the image
  int sign;         // Memorise le signe de l'interieur pour chaque contour
  int contenance;   // Memorise a quel contour appartient un contour donne
  int ptsline;      // Memorise le nombre de points de la ligne contenus uniquement dans le contour donne
  int ptsline_total;// Memorise le nombre de points de la ligne contenus dans le contour
  int nbpts;        // Memorise le nombre de fois que le contour est traverse
  float meangrad;   // Memorise la moyenne du gradient le long du contour

  ConnectedComponentInfo() {
    number = 0;
    sign=0;
    contenance=-1;
    ptsline=0;
    ptsline_total=0;
    nbpts=0;
    meangrad=0;
  }
  

};


//======================================================================
///
class IsoContour2
//
{

public:

  /// Exceptions
  //@{
    class OutOfRange
    {
    public:
      OutOfRange() {  cerr << "IsoContour2\t Exception OutOfRange \n"; }
    };

  //@}

private:



   InrImage* _image_ligne;
   InrImage* _input_image;
   InrImage* _image_contours;
   InrImage* _image_num_contour;
   InrImage* _image_un_contour;
   InrImage* _sort_image;
   InrImage* _inclusion_image;
   InrImage* _sign_image;
   InrImage* _size_image;

   int    _max_fond;
   float      _resolution;
   Crest*    _lignes;
   int    _num_ligne;
   int    _nbpts_ligne;

   Chaine    _nom_image_resultat;
   float      _pas_abscisse;
   int    _contour_choisi;


   unsigned char       _sauve;
   unsigned char _verbose;
   unsigned char       _debug;

  int _topology;

  ///
  InrImage* _image;
  ///
  InrImage* _image_contour;

  ///
  Voxel  _voxel;

  // 6 faces, 4 positions par face
  int  _face[6][4];

  /** coordonnees de chaque sommet d'une face 
     Une face a son propre syst�e de coordonn�s,
     le premier point (0,0)
     le 2eme          (1,0)
     le 3eme          (1,1)
     le 4eme          (0,1)
  */
  PtFace  _coord_sommet[4]; 

  int   _nb_contours;

  ConnectedComponentInfo* _tab_ccinfo;
/*
  int*  _tab_contenance;     // Memorise a quel contour appartient un contour donne
  int*  _tab_signe;          // Memorise le signe de l'interieur pour chaque contour
  int*  _tab_ptsligne;       // Memorise le nombre de points de la ligne contenus uniquement 
                                // dans le contour donne
  int*  _tab_ptsligne_total; // Memorise le nombre de points de la ligne contenus dans le contour
  int*  _tab_nbpts;          // Memorise le nombre de fois que le contour est traverse
  float*    _tab_moygrad;        // Memorise la moyenne du gradient le long du contour
*/

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

  ///
  int* _centre_sphere;

  ///
  float   _rayon_sphere;

  ///
  InrImage* _image_gradient;

  ///
  unsigned char _noline;

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
  int contour( const PointContour& p1);
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
 IsoContour2( InrImage* image);
  //

  //--------------------------------------------------
  ///
  ~IsoContour2();
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
  void DefinitInterieur( int signe = -1);
  //

  void SortContours();

  ///
  void CalculAire( );

///
  void SetInputImage(InrImage* im) { _input_image=im;}

  void SetImageLigne(InrImage* im)     {    _image_ligne=im;  }

  void SetImageContours(InrImage* contours, 
			InrImage* num_contours,
			InrImage* un_contour)     
  {    
    _image_contours=contours;
    _image_num_contour=num_contours;
    _image_un_contour=un_contour;
  }

  void SetMaxFond(   int val) { _max_fond   = val; }
  void SetResolution(float val) { _resolution = val; }

  void SetLines(Crest* lines, int line_num)
  { 
    _lignes=lines;
    _num_ligne = line_num;
  }


  void SetPasAbscisse(float p) {_pas_abscisse=p; }

  void SetContourChoisi(int c) { _contour_choisi =c; }
  int GetContourChoisi() { return _contour_choisi; }

void SetNomImageResultat(const Chaine& res) { _nom_image_resultat = res; }
 
  void SetGradImage(InrImage* gradim)  {    _image_gradient=gradim;  }

  void SetSauve(unsigned char s)   { _sauve   = s;}
  void SetVerbose(unsigned char v) { _verbose = v;}
  void SetDebug(unsigned char b)   { _debug   = b;}

  InrImage* GetReorderImage();
  InrImage* GetInclusionImage();
  InrImage* GetSignImage();
  InrImage* GetSizeImage();

  void SetTopology(int t) { _topology=t;}

}; // IsoContour2



#endif // _ISOCONTOUR2_HPP
